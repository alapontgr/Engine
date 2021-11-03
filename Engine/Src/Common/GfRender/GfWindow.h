////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2018/09/13
//	File: 	GfWindow.h
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __GFWINDOW_H__
#define __GFWINDOW_H__
////////////////////////////////////////////////////////////////////////////////
// Includes 

#include "Common/GfCore/GfCoreMinimal.h"
#include "Common/GfEntry/GfEntry.h"
#include GF_SOLVE_GFX_API_PATH(GfRender/GfWindow_Platform.h)

#include "Common/GfRender/GraphicResources/GfTexture.h"

////////////////////////////////////////////////////////////////////////////////

struct GfWindowInitParams : public GfWindowInitParams_Platform
{
	GfEntryArgs m_kArguments;
	const char* m_szWindowName;
	u32         m_width;
	u32         m_height;
	bool        m_bFullScreen;
	bool        m_bVSync;
};

////////////////////////////////////////////////////////////////////////////////

struct GfEntryArgs;
class GfWindow
{
	GF_DECLARE_PLATFORM_INTERFACE(GfWindow);
public:

	GfWindow();

	void init(GfWindowInitParams& kInitParams, GfRenderContext& kCtx);

	// returns GF_FALSE when the user wants to close the application
	Bool Tick();

	void Shutdown();

	Bool BeginFrame(const GfRenderContext& kCtx);

	void EndFrame(const GfRenderContext& kCtx);

	u32 GetWidth() const;

	u32 GetHeight() const;

	const char* GetWindowName();

	u32 GetCurrentFrameIdx() const;

	const GfTexture2D* GetBackBuffer(u32 uiIdx) const;

	const GfTexture2D* GetCurrBackBuffer() const;

private:

	void Flip();

	void OnResize();

	const char*			m_szAppName; // Static string
	u32					m_width;
	u32					m_height;
	bool				m_bFullScreen;
	bool				m_bVSync;

	// Used as a cursor for the multi buffering of the resources of the engine
	u32					m_uiCurrentFrameIdx;

	GfVector<GfTexture2D>	m_tSwapchainTextures;
};

////////////////////////////////////////////////////////////////////////////////

GF_FORCEINLINE u32 GfWindow::GetWidth() const
{
	return m_width;
}

////////////////////////////////////////////////////////////////////////////////

GF_FORCEINLINE u32 GfWindow::GetHeight() const
{
	return m_height;
}

////////////////////////////////////////////////////////////////////////////////

GF_FORCEINLINE const char* GfWindow::GetWindowName() 
{
	return m_szAppName;
}

////////////////////////////////////////////////////////////////////////////////

GF_FORCEINLINE u32 GfWindow::GetCurrentFrameIdx() const
{
	return m_uiCurrentFrameIdx;
}

////////////////////////////////////////////////////////////////////////////////

GF_FORCEINLINE const GfTexture2D* GfWindow::GetBackBuffer(u32 uiIdx) const
{
	return &m_tSwapchainTextures[uiIdx];
}

////////////////////////////////////////////////////////////////////////////////

GF_FORCEINLINE const GfTexture2D* GfWindow::GetCurrBackBuffer() const
{
	return &m_tSwapchainTextures[m_uiCurrentFrameIdx];
}

////////////////////////////////////////////////////////////////////////////////
#endif // __GFWINDOW_H__