////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2019/04/16
//	File: 	GfMouse.cpp
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
// Includes

#include "GfInput/Common/GfMouse.h"

////////////////////////////////////////////////////////////////////////////////

GfMouse::GfMouse()
	: m_vMousePosition(0.0f)
	, m_uiButtonsDown(0)
	, m_uiButtonsPressed(0)
{
	m_pWheelDelta[0] = m_pWheelDelta[1] = 0.0f;
}

////////////////////////////////////////////////////////////////////////////////

void GfMouse::Update()
{
	m_uiButtonsPressed = (m_uiButtonsPressed ^ m_uiButtonsDown); // Every button down becomes pressed
	m_uiButtonsDown = 0;
	// delay the delta for one frame just in case
	m_pWheelDelta[0] = m_pWheelDelta[1];
	m_pWheelDelta[1] = 0.0f;
}

////////////////////////////////////////////////////////////////////////////////

bool GfMouse::IsButtonDown(MouseButtons eButton) const
{
	return (m_uiButtonsDown & (1<<eButton)) != 0;
}

////////////////////////////////////////////////////////////////////////////////

bool GfMouse::IsButtonPressed(MouseButtons eButton) const
{
	return (m_uiButtonsPressed & (1 << eButton)) != 0;
}

////////////////////////////////////////////////////////////////////////////////

f32 GfMouse::GetWheelDelta() const
{
	return m_pWheelDelta[0];
}

////////////////////////////////////////////////////////////////////////////////

v2 GfMouse::GetMousePos() const
{
	return m_vMousePosition;
}

////////////////////////////////////////////////////////////////////////////////

void GfMouse::SetMousePos(const v2& vPos)
{
	m_vMousePosition = vPos;
}

////////////////////////////////////////////////////////////////////////////////

void GfMouse::SetWheelDelta(f32 fVal)
{
	m_pWheelDelta[1] = fVal;
}

////////////////////////////////////////////////////////////////////////////////
// EOF