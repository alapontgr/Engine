////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2019/02/17
//	File: 	GfConstantBuffer.h
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __GFCONSTANTBUFFER_H__
#define __GFCONSTANTBUFFER_H__
////////////////////////////////////////////////////////////////////////////////

#include "GfRender/Common/GraphicResources/GfGraphicResourceBase.h"

////////////////////////////////////////////////////////////////////////////////

class GfConstantBuffer : public GfBufferedResource
{
public:
		
	GfConstantBuffer();

	template <typename T>
	T* MapAs(const GfRenderContext& kCtx);

	void* Map(const GfRenderContext& kCtx);

	void UnMap(const GfRenderContext& kCtx);
	
private:

};

////////////////////////////////////////////////////////////////////////////////

template <typename T>
T* GfConstantBuffer::MapAs(const GfRenderContext& kCtx)
{
	return static_cast<T*>(Map(kCtx));
}

////////////////////////////////////////////////////////////////////////////////
#endif // __GFCONSTANTBUFFER_H__