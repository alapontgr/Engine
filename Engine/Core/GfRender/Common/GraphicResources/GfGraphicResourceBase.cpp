////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2019/02/06
//	File: 	GfGraphicResourceBase.cpp
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
// Includes

#include "GfRender/Common/GraphicResources/GfGraphicResourceBase.h"

////////////////////////////////////////////////////////////////////////////////

GfGraphicsResource::GfGraphicsResource()
	: m_eType(EParamaterSlotType::Invalid)
{
}

////////////////////////////////////////////////////////////////////////////////

GfGraphicsResource::GfGraphicsResource(EParamaterSlotType::Type eType)
	: m_eType(eType)
{
}

////////////////////////////////////////////////////////////////////////////////
// EOF