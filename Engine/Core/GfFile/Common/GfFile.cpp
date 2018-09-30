////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2018/09/30
//	File: 	GfFile.cpp
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
// Includes

#include "GfFile/Common/GfFile.h"

////////////////////////////////////////////////////////////////////////////////

GfFileHandle::GfFileHandle()
	: GfFileHandle_Platform(*this)
{
}

////////////////////////////////////////////////////////////////////////////////
// EOF