#include "RenderInterface.h"

namespace fdk
{
namespace Rendering
{
	RenderInterface::RenderInterface() {}

	void RenderInterface::init()
	{
		BaseT::init();
	}

	void RenderInterface::release()
	{
    BaseT::release();
	}

	void RenderInterface::on_resize()
	{
    BaseT::on_resize();
	}

	void RenderInterface::create_buffer(Buffer& rBuffer)
	{
    BaseT::create_buffer(rBuffer);
	}

	void RenderInterface::destroy_buffer(Buffer& rBuffer)
	{
    BaseT::destroy_buffer(rBuffer);
	}

	void RenderInterface::copy_buffer(Buffer& rFrom, const u32 fromOffset, Buffer& rTo, const u32 toOffset, const u32 rangeSize, CommandBuffer& rCmdBuffer)
	{
    BaseT::copy_buffer(rFrom, fromOffset, rTo, toOffset, rangeSize, rCmdBuffer);
	}

	void RenderInterface::send_buffer_memory_to_gpu(Buffer& rBuffer)
	{
    BaseT::send_buffer_memory_to_gpu(rBuffer);
	}

	void RenderInterface::use_mesh(Framework::Mesh& rMesh, CommandBuffer& rCmdBuffer)
	{
    BaseT::use_mesh(rMesh, rCmdBuffer);
	}

	void RenderInterface::bind_material(Material& rMaterial, CommandBuffer& rCmdBuffer)
	{
    BaseT::bind_material(rMaterial, rCmdBuffer);
	}

	void RenderInterface::set_viewport(const Viewport& rViewport, CommandBuffer& rCmdBuffer)
	{
    BaseT::set_viewport(rViewport, rCmdBuffer);
	}

	void RenderInterface::set_scissor(const Scissor& rScissor, CommandBuffer& rCmdBuffer)
	{
    BaseT::set_scissor(rScissor, rCmdBuffer);
	}

	void RenderInterface::draw_indexed(const u32 indexCount, const u32 instanceCount, const u32 indexOffset, const u32 vertexOffset, CommandBuffer& rCmdBuffer)
	{
    BaseT::draw_indexed(indexCount, instanceCount, indexOffset, vertexOffset, rCmdBuffer);
	}

  void RenderInterface::create_command_buffer(CommandBuffer& rCommandBuffer)
	{
    BaseT::create_command_buffer(rCommandBuffer);
	}

  void* RenderInterface::map_buffer_gpu_memory(Buffer& rBuffer, const u32 memoryOffset, const u32 rangeSize)
  {
    return BaseT::map_buffer_gpu_memory(rBuffer, memoryOffset, rangeSize);
  }

  void RenderInterface::unmap_buffer_gpu_memory(Buffer& rBuffer)
  {
    BaseT::unmap_buffer_gpu_memory(rBuffer);
  }

  void RenderInterface::create_fence(Fence& rFence)
  {
    BaseT::create_fence(rFence);
  }

  void RenderInterface::beginFrame()
  {
    BaseT::beginFrame();
  }

  void RenderInterface::endFrame()
  {
    BaseT::endFrame();
  }

}
}
