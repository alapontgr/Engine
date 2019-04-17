////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2019/04/16
//	File: 	GfInput_Platform.h
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __GFINPUT_PLATFORM_H__
#define __GFINPUT_PLATFORM_H__
////////////////////////////////////////////////////////////////////////////////

#include "GfCore/Common/GfCoreMinimal.h"

////////////////////////////////////////////////////////////////////////////////

class GfInput_Platform 
{
public:

	static void HandleInput(u32 uiMsg, u64 ulParam, s64 slParam);

	static bool IsMousePresent();

	static bool IsKeyBoardPresent();
};

////////////////////////////////////////////////////////////////////////////////
#endif // __GFINPUT_PLATFORM_H__