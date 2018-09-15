////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2018/09/15
//	File: 	GFRENDERCONTEXT.cpp
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
// Includes

#include "GfRender/Common/GfRenderContext.h"

////////////////////////////////////////////////////////////////////////////////

GfRenderContext::GfRenderContext()
	: m_kPlatform(*this)
	, m_pWindow(nullptr)
{

}

////////////////////////////////////////////////////////////////////////////////

void GfRenderContext::Init(GfWindow* pWindow)
{
	m_pWindow = pWindow;
	InitInternal();
}

////////////////////////////////////////////////////////////////////////////////

void GfRenderContext::Shutdown()
{

}

////////////////////////////////////////////////////////////////////////////////
// EOF
