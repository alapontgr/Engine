////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2018/09/16
//	File: 	GFCMDBUFFER.cpp
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
// Includes

#include "Common/GfRender/GfCmdBuffer.h"
#include "Common/GfRender/GfShaderPipeline.h"
#include "Common/GfRender/GfRenderPass.h"

#include <mutex>

////////////////////////////////////////////////////////////////////////////////

class GfCmdBufferCache 
{
public:
	GfCmdBufferCache() {}

	GfCmdBuffer* get(const GfRenderContext* ctx, GfCmdBufferType::Type type, GfRenderContextFamilies::Type queue);

	void returnToCache(GfCmdBuffer* cmdBuffer);

	void shutdown(const GfRenderContext& ctx);

private:

	GfCmdBufferFactory m_factory;
	GfVector<GfUniquePtr<GfCmdBuffer>> m_createdCmdBuffers;
	GfQueue<GfCmdBuffer*> m_avalCmdBuffers;
	std::mutex m_cacheMutex;
};

GfCmdBuffer* GfCmdBufferCache::get(const GfRenderContext* ctx, GfCmdBufferType::Type type, GfRenderContextFamilies::Type queue)
{
	std::lock_guard<std::mutex> lk(m_cacheMutex);
	
	if (!m_factory.isInitialized()) 
	{
		m_factory.init(*ctx, queue);
	}

	if (m_avalCmdBuffers.size() > 0) 
	{
		GfCmdBuffer* buffer = m_avalCmdBuffers.front();
		if (buffer->isReady()) 
		{
			m_avalCmdBuffers.pop();
			buffer->reset();
			return buffer;
		}
	}

	// If no CmdBuffer was found, allocate a new one
	GfUniquePtr<GfCmdBuffer> cmdBuffer = GfUniquePtr<GfCmdBuffer>(new GfCmdBuffer(ctx, this, type, queue));
	m_createdCmdBuffers.push_back(std::move(cmdBuffer));
	GfCmdBuffer* buffer = m_createdCmdBuffers.back().get();
	buffer->reset();
	return buffer;
}

void GfCmdBufferCache::returnToCache(GfCmdBuffer* cmdBuffer) 
{
	GF_ASSERT(m_factory.isInitialized(), "Factory was not initialized, how did this happen?");
	std::lock_guard<std::mutex> lk(m_cacheMutex);
	m_avalCmdBuffers.push(cmdBuffer);
}

void GfCmdBufferCache::shutdown(const GfRenderContext& ctx) 
{
	for (const GfUniquePtr<GfCmdBuffer>& buff : m_createdCmdBuffers) 
	{
		buff->shutdown();
	}
	m_createdCmdBuffers.clear();
	m_factory.shutdown(ctx);
}

////////////////////////////////////////////////////////////////////////////////

GfCmdBufferCache s_cmdBufferCaches[GfRenderContextFamilies::Count];

////////////////////////////////////////////////////////////////////////////////

void GfRenderPipelineState::updateHash() 
{
	struct GfRenderStateHasher 
	{
		u64 renderPassHash;
		u64 vertexFormatHash;
		u64 configHash;
		GfVariantHash variantHash;
	} stateHasher;
	stateHasher.renderPassHash = m_curRenderPass ? m_curRenderPass->getHash() : 0;
	stateHasher.vertexFormatHash = m_curVertexFormat ? m_curVertexFormat->getHash() : 0;
	stateHasher.configHash = GfHash::compute(&m_config, sizeof(GfShaderPipeConfig));
	stateHasher.variantHash = m_curShaderState.m_curPipeline ? m_curShaderState.m_curVariantHash : 0;
	m_pipelineHash = GfHash::compute(&stateHasher, sizeof(GfRenderStateHasher));
}

GfCmdBufferFactory::GfCmdBufferFactory()
	: m_initialized(false)
{
}

void GfCmdBufferFactory::init(const GfRenderContext& kCtx, GfRenderContextFamilies::Type eQueueType)
{
	m_initialized = true;
	m_kPlatform.initRHI(kCtx, eQueueType);
}

void GfCmdBufferFactory::shutdown(const GfRenderContext& ctx)
{
	m_initialized = false;
	m_kPlatform.shutdown(ctx);
}

////////////////////////////////////////////////////////////////////////////////

GfCmdBuffer* GfCmdBuffer::get(const GfRenderContext* ctx, 
		GfCmdBufferType::Type type,
		GfRenderContextFamilies::Type queue)
{
	GfCmdBufferCache& cache = s_cmdBufferCaches[queue];
	GfCmdBuffer* res = cache.get(ctx, type, queue);
	GF_ASSERT(res, "Failed to allocate CmdBuffer");
	return res;
}

GfCmdBuffer::GfCmdBuffer()
	: m_type(GfCmdBufferType::Invalid)
	, m_queue(GfRenderContextFamilies::InvalidIdx)
	, m_ctx(nullptr)
	, m_cache(nullptr)
	, m_linearAllocator(ms_allocatorDefaultMemory)
{
}

GfCmdBuffer::GfCmdBuffer(const GfRenderContext* ctx, GfCmdBufferCache* cache,
	const GfCmdBufferType::Type type, GfRenderContextFamilies::Type queue)
	: m_type(type)
	, m_queue(queue)
	, m_ctx(ctx)
	, m_cache(cache)
	, m_linearAllocator(ms_allocatorDefaultMemory)
{
}

void GfCmdBuffer::reset() 
{
	GF_ASSERT(m_ctx, "Context was not initialized");
	m_curState = GfRenderPipelineState();
	m_linearAllocator.reset();
}

void GfCmdBuffer::shutdown() 
{
	m_linearAllocator.shutdown();
	GF_ASSERT_ALWAYS("TODO: Destroy platform specific");
}

////////////////////////////////////////////////////////////////////////////////

void GfCmdBuffer::setBlendState(const GfBlendState& blendState) 
{
	m_curState.setBlendState(blendState);
}

void GfCmdBuffer::setRasterState(const GfRasterState& rasterState) 
{
	m_curState.setRasterState(rasterState);
}

void GfCmdBuffer::setTopology(PrimitiveTopology::Type topology) 
{
	m_curState.setTopology(topology);
}

void GfCmdBuffer::setMSAAState(const GfMultiSamplingState& msaaState) 
{
	m_curState.setMSAAState(msaaState);
}

void GfCmdBuffer::setVertexFormat(const GfVertexDeclaration* vertexFormat) 
{
	m_curState.setVertexFormat(vertexFormat);
}

void GfCmdBuffer::setDepthState(const GfDepthState& depthState) 
{
	m_curState.setDepthState(depthState);
}

void GfCmdBuffer::setStencilCompareMask(StencilFace::Type targetFace, u32 compareMask) 
{
	GF_ASSERT_ALWAYS("TODO: Implement me!");
}

void GfCmdBuffer::setStencilWriteMask(StencilFace::Type targetFace, u32 writeMask) 
{
	GF_ASSERT_ALWAYS("TODO: Implement me!");
}

void GfCmdBuffer::setStencilReferenceValue(StencilFace::Type targetFace, u32 refVal) 
{
	GF_ASSERT_ALWAYS("TODO: Implement me!");
}

void GfCmdBuffer::beginRenderPass(GfRenderPass* renderPass)
{
	GF_ASSERT(!m_curState.getCurRenderPass(), "Trying to begin a pass before end");
	GF_ASSERT(renderPass->getWidth() != 0 && renderPass->getHeight(), "Resolution was not initialized");

	m_curState.setRenderPass(renderPass);
	m_kPlatform.setViewport(*m_ctx, renderPass->getViewport());
	m_kPlatform.setScissors(*m_ctx, renderPass->getScissor());
	m_kPlatform.beginRenderPass(*m_ctx, renderPass);
}

void GfCmdBuffer::endRenderPass()
{
	GF_ASSERT(m_curState.getCurRenderPass(), "Trying to end an invalid pass");
	m_kPlatform.endRenderPass();
	m_curState.setRenderPass(nullptr);
}

void GfCmdBuffer::bindShaderPipe(const GfShaderVariant& shaderVariant)
{ 
	GfShaderPipeline* pipeline = shaderVariant.getPipeline();
	GfVariantHash variantHash = shaderVariant.getVariantHash();

	GF_ASSERT(pipeline->isCompute() || m_curState.getVertexFormat(), "Invalid active vertex format");
	GF_ASSERT(pipeline->isCompute() || m_curState.getCurRenderPass(), "Invalid active Render Pass");

	m_curState.setShaderPipe(pipeline, variantHash);
}

void GfCmdBuffer::submit(
	const GfWindow& kWindow,
	Bool bLast)
{
	m_kPlatform.submitRHI(*m_ctx, kWindow, m_queue, bLast);
	GF_ASSERT(m_cache, "Invalid cache");
	m_cache->returnToCache(this);
}

void GfCmdBuffer::drawIndexed(u32 uiIdxCount, u32 uiInstanceCount, u32 uiIdxOffset /*= 0*/, u32 uiVertexOffset /*= 0*/, u32 uiFirstInstanceId /*= 0*/)
{
	m_kPlatform.drawIndexedRHI(&m_curState, uiIdxCount, uiInstanceCount, uiIdxOffset, uiVertexOffset, uiFirstInstanceId);
}

void GfCmdBuffer::draw(u32 uiVertexCount, u32 uiInstanceCount, u32 uiFirstVertex /*= 0*/, u32 uiFirstInstance /*= 0*/)
{
	m_kPlatform.drawRHI(&m_curState, uiVertexCount, uiInstanceCount, uiFirstVertex, uiFirstInstance);
}

void GfCmdBuffer::bindVertexBuffers(GfBuffer** vertexBuffers, u32* vertexBufferOffsets, u32 vertexBufferCount) 
{	
	m_kPlatform.bindVertexBuffersRHI(vertexBuffers, vertexBufferOffsets, vertexBufferCount);
}

void GfCmdBuffer::bindIndexBuffer(const GfBuffer& buffer, u32 offset, bool useShort)
{
	m_kPlatform.bindIndexBufferRHI(buffer, offset, useShort);
}

////////////////////////////////////////////////////////////////////////////////
// EOF
