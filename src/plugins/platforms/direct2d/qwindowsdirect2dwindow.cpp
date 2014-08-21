begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsdirect2dcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2ddevicecontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dhelpers.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dplatformpixmap.h"
end_include
begin_include
include|#
directive|include
file|<d3d11.h>
end_include
begin_include
include|#
directive|include
file|<d2d1_1.h>
end_include
begin_using
using|using
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
using|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWindowsDirect2DWindow
name|QWindowsDirect2DWindow
operator|::
name|QWindowsDirect2DWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QWindowsWindowData
modifier|&
name|data
parameter_list|)
member_init_list|:
name|QWindowsWindow
argument_list|(
name|window
argument_list|,
name|data
argument_list|)
member_init_list|,
name|m_needsFullFlush
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|m_directRendering
argument_list|(
operator|!
operator|(
name|data
operator|.
name|flags
operator|&
name|Qt
operator|::
name|FramelessWindowHint
operator|&&
name|window
operator|->
name|format
argument_list|()
operator|.
name|hasAlpha
argument_list|()
operator|)
argument_list|)
block|{
if|if
condition|(
name|window
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
condition|)
return|return;
comment|// No further handling for Qt::Desktop
if|if
condition|(
name|m_directRendering
condition|)
name|setupSwapChain
argument_list|()
expr_stmt|;
name|HRESULT
name|hr
init|=
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d2dDevice
argument_list|()
operator|->
name|CreateDeviceContext
argument_list|(
name|D2D1_DEVICE_CONTEXT_OPTIONS_NONE
argument_list|,
name|m_deviceContext
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"%s: Couldn't create Direct2D Device context: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsDirect2DWindow
name|QWindowsDirect2DWindow
operator|::
name|~
name|QWindowsDirect2DWindow
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|setWindowFlags
name|void
name|QWindowsDirect2DWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|m_directRendering
operator|=
operator|!
operator|(
name|flags
operator|&
name|Qt
operator|::
name|FramelessWindowHint
operator|&&
name|window
argument_list|()
operator|->
name|format
argument_list|()
operator|.
name|hasAlpha
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_directRendering
condition|)
name|m_swapChain
operator|.
name|Reset
argument_list|()
expr_stmt|;
comment|// No need for the swap chain; release from memory
elseif|else
if|if
condition|(
operator|!
name|m_swapChain
condition|)
name|setupSwapChain
argument_list|()
expr_stmt|;
name|QWindowsWindow
operator|::
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pixmap
name|QPixmap
modifier|*
name|QWindowsDirect2DWindow
operator|::
name|pixmap
parameter_list|()
block|{
name|setupBitmap
argument_list|()
expr_stmt|;
return|return
name|m_pixmap
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWindowsDirect2DWindow
operator|::
name|flush
parameter_list|(
name|QWindowsDirect2DBitmap
modifier|*
name|bitmap
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|QSize
name|size
decl_stmt|;
if|if
condition|(
name|m_directRendering
condition|)
block|{
name|DXGI_SWAP_CHAIN_DESC1
name|desc
decl_stmt|;
name|HRESULT
name|hr
init|=
name|m_swapChain
operator|->
name|GetDesc1
argument_list|(
operator|&
name|desc
argument_list|)
decl_stmt|;
name|QRect
name|geom
init|=
name|geometry
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|FAILED
argument_list|(
name|hr
argument_list|)
operator|||
operator|(
name|desc
operator|.
name|Width
operator|!=
name|geom
operator|.
name|width
argument_list|()
operator|)
operator|||
operator|(
name|desc
operator|.
name|Height
operator|!=
name|geom
operator|.
name|height
argument_list|()
operator|)
operator|)
condition|)
block|{
name|resizeSwapChain
argument_list|(
name|geom
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|m_swapChain
operator|->
name|GetDesc1
argument_list|(
operator|&
name|desc
argument_list|)
expr_stmt|;
block|}
name|size
operator|.
name|setWidth
argument_list|(
name|desc
operator|.
name|Width
argument_list|)
expr_stmt|;
name|size
operator|.
name|setHeight
argument_list|(
name|desc
operator|.
name|Height
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|size
operator|=
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
name|setupBitmap
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_bitmap
condition|)
return|return;
if|if
condition|(
name|bitmap
operator|!=
name|m_bitmap
operator|.
name|data
argument_list|()
condition|)
block|{
name|m_bitmap
operator|->
name|deviceContext
argument_list|()
operator|->
name|begin
argument_list|()
expr_stmt|;
name|ID2D1DeviceContext
modifier|*
name|dc
init|=
name|m_bitmap
operator|->
name|deviceContext
argument_list|()
operator|->
name|get
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|m_needsFullFlush
condition|)
block|{
name|QRegion
name|clipped
init|=
name|region
decl_stmt|;
name|clipped
operator|&=
name|QRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|size
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|clipped
operator|.
name|rects
argument_list|()
control|)
block|{
name|QRectF
name|rectF
argument_list|(
name|rect
argument_list|)
decl_stmt|;
name|dc
operator|->
name|DrawBitmap
argument_list|(
name|bitmap
operator|->
name|bitmap
argument_list|()
argument_list|,
name|to_d2d_rect_f
argument_list|(
name|rectF
argument_list|)
argument_list|,
literal|1.0
argument_list|,
name|D2D1_INTERPOLATION_MODE_LINEAR
argument_list|,
name|to_d2d_rect_f
argument_list|(
name|rectF
operator|.
name|translated
argument_list|(
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|offset
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|QRectF
name|rectF
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|dc
operator|->
name|DrawBitmap
argument_list|(
name|bitmap
operator|->
name|bitmap
argument_list|()
argument_list|,
name|to_d2d_rect_f
argument_list|(
name|rectF
argument_list|)
argument_list|,
literal|1.0
argument_list|,
name|D2D1_INTERPOLATION_MODE_LINEAR
argument_list|,
name|to_d2d_rect_f
argument_list|(
name|rectF
operator|.
name|translated
argument_list|(
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|offset
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_needsFullFlush
operator|=
literal|false
expr_stmt|;
block|}
name|m_bitmap
operator|->
name|deviceContext
argument_list|()
operator|->
name|end
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|present
name|void
name|QWindowsDirect2DWindow
operator|::
name|present
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
if|if
condition|(
name|m_directRendering
condition|)
block|{
name|m_swapChain
operator|->
name|Present
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
name|ComPtr
argument_list|<
name|IDXGISurface
argument_list|>
name|bitmapSurface
decl_stmt|;
name|HRESULT
name|hr
init|=
name|m_bitmap
operator|->
name|bitmap
argument_list|()
operator|->
name|GetSurface
argument_list|(
operator|&
name|bitmapSurface
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IDXGISurface1
argument_list|>
name|dxgiSurface
decl_stmt|;
name|hr
operator|=
name|bitmapSurface
operator|.
name|As
argument_list|(
operator|&
name|dxgiSurface
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
argument_list|)
expr_stmt|;
name|HDC
name|hdc
decl_stmt|;
name|hr
operator|=
name|dxgiSurface
operator|->
name|GetDC
argument_list|(
name|FALSE
argument_list|,
operator|&
name|hdc
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to get DC for presenting the surface"
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|QRect
name|bounds
init|=
name|window
argument_list|()
operator|->
name|geometry
argument_list|()
decl_stmt|;
specifier|const
name|SIZE
name|size
init|=
block|{
name|bounds
operator|.
name|width
argument_list|()
block|,
name|bounds
operator|.
name|height
argument_list|()
block|}
decl_stmt|;
specifier|const
name|POINT
name|ptDst
init|=
block|{
name|bounds
operator|.
name|x
argument_list|()
block|,
name|bounds
operator|.
name|y
argument_list|()
block|}
decl_stmt|;
specifier|const
name|POINT
name|ptSrc
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
specifier|const
name|BLENDFUNCTION
name|blend
init|=
block|{
name|AC_SRC_OVER
block|,
literal|0
block|,
literal|255.0
operator|*
name|opacity
argument_list|()
block|,
name|AC_SRC_ALPHA
block|}
decl_stmt|;
specifier|const
name|QRect
name|r
init|=
name|region
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
specifier|const
name|RECT
name|dirty
init|=
block|{
name|r
operator|.
name|left
argument_list|()
block|,
name|r
operator|.
name|top
argument_list|()
block|,
name|r
operator|.
name|left
argument_list|()
operator|+
name|r
operator|.
name|width
argument_list|()
block|,
name|r
operator|.
name|top
argument_list|()
operator|+
name|r
operator|.
name|height
argument_list|()
block|}
decl_stmt|;
name|UPDATELAYEREDWINDOWINFO
name|info
init|=
block|{
sizeof|sizeof
argument_list|(
name|UPDATELAYEREDWINDOWINFO
argument_list|)
block|,
name|NULL
block|,
operator|&
name|ptDst
block|,
operator|&
name|size
block|,
name|hdc
block|,
operator|&
name|ptSrc
block|,
literal|0
block|,
operator|&
name|blend
block|,
name|ULW_ALPHA
block|,
operator|&
name|dirty
block|}
decl_stmt|;
if|if
condition|(
operator|!
name|UpdateLayeredWindowIndirect
argument_list|(
name|handle
argument_list|()
argument_list|,
operator|&
name|info
argument_list|)
condition|)
name|qErrnoWarning
argument_list|(
name|GetLastError
argument_list|()
argument_list|,
literal|"Failed to update the layered window"
argument_list|)
expr_stmt|;
name|hr
operator|=
name|dxgiSurface
operator|->
name|ReleaseDC
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to release the DC for presentation"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupSwapChain
name|void
name|QWindowsDirect2DWindow
operator|::
name|setupSwapChain
parameter_list|()
block|{
name|DXGI_SWAP_CHAIN_DESC1
name|desc
init|=
block|{}
decl_stmt|;
name|desc
operator|.
name|Format
operator|=
name|DXGI_FORMAT_B8G8R8A8_UNORM
expr_stmt|;
name|desc
operator|.
name|SampleDesc
operator|.
name|Count
operator|=
literal|1
expr_stmt|;
name|desc
operator|.
name|BufferUsage
operator|=
name|DXGI_USAGE_RENDER_TARGET_OUTPUT
expr_stmt|;
name|desc
operator|.
name|BufferCount
operator|=
literal|1
expr_stmt|;
name|desc
operator|.
name|SwapEffect
operator|=
name|DXGI_SWAP_EFFECT_SEQUENTIAL
expr_stmt|;
name|HRESULT
name|hr
init|=
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|dxgiFactory
argument_list|()
operator|->
name|CreateSwapChainForHwnd
argument_list|(
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d3dDevice
argument_list|()
argument_list|,
comment|// [in]   IUnknown *pDevice
name|handle
argument_list|()
argument_list|,
comment|// [in]   HWND hWnd
operator|&
name|desc
argument_list|,
comment|// [in]   const DXGI_SWAP_CHAIN_DESC1 *pDesc
name|NULL
argument_list|,
comment|// [in]   const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pFullscreenDesc
name|NULL
argument_list|,
comment|// [in]   IDXGIOutput *pRestrictToOutput
name|m_swapChain
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|)
decl_stmt|;
comment|// [out]  IDXGISwapChain1 **ppSwapChain
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"%s: Could not create swap chain: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
name|m_needsFullFlush
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeSwapChain
name|void
name|QWindowsDirect2DWindow
operator|::
name|resizeSwapChain
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_swapChain
condition|)
return|return;
name|m_pixmap
operator|.
name|reset
argument_list|()
expr_stmt|;
name|m_bitmap
operator|.
name|reset
argument_list|()
expr_stmt|;
name|m_deviceContext
operator|->
name|SetTarget
argument_list|(
name|Q_NULLPTR
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
init|=
name|m_swapChain
operator|->
name|ResizeBuffers
argument_list|(
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|DXGI_FORMAT_UNKNOWN
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"%s: Could not resize swap chain: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
name|m_needsFullFlush
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copyBackBuffer
name|QSharedPointer
argument_list|<
name|QWindowsDirect2DBitmap
argument_list|>
name|QWindowsDirect2DWindow
operator|::
name|copyBackBuffer
parameter_list|()
specifier|const
block|{
specifier|const
name|QSharedPointer
argument_list|<
name|QWindowsDirect2DBitmap
argument_list|>
name|null_result
decl_stmt|;
if|if
condition|(
operator|!
name|m_bitmap
condition|)
return|return
name|null_result
return|;
name|D2D1_PIXEL_FORMAT
name|format
init|=
name|m_bitmap
operator|->
name|bitmap
argument_list|()
operator|->
name|GetPixelFormat
argument_list|()
decl_stmt|;
name|D2D1_SIZE_U
name|size
init|=
name|m_bitmap
operator|->
name|bitmap
argument_list|()
operator|->
name|GetPixelSize
argument_list|()
decl_stmt|;
name|FLOAT
name|dpiX
decl_stmt|,
name|dpiY
decl_stmt|;
name|m_bitmap
operator|->
name|bitmap
argument_list|()
operator|->
name|GetDpi
argument_list|(
operator|&
name|dpiX
argument_list|,
operator|&
name|dpiY
argument_list|)
expr_stmt|;
name|D2D1_BITMAP_PROPERTIES1
name|properties
init|=
block|{
name|format
block|,
comment|// D2D1_PIXEL_FORMAT pixelFormat;
name|dpiX
block|,
comment|// FLOAT dpiX;
name|dpiY
block|,
comment|// FLOAT dpiY;
name|D2D1_BITMAP_OPTIONS_TARGET
block|,
comment|// D2D1_BITMAP_OPTIONS bitmapOptions;
name|Q_NULLPTR
comment|// _Field_size_opt_(1) ID2D1ColorContext *colorContext;
block|}
decl_stmt|;
name|ComPtr
argument_list|<
name|ID2D1Bitmap1
argument_list|>
name|copy
decl_stmt|;
name|HRESULT
name|hr
init|=
name|m_deviceContext
operator|.
name|Get
argument_list|()
operator|->
name|CreateBitmap
argument_list|(
name|size
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|properties
argument_list|,
operator|&
name|copy
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not create staging bitmap: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
name|null_result
return|;
block|}
name|hr
operator|=
name|copy
operator|.
name|Get
argument_list|()
operator|->
name|CopyFromBitmap
argument_list|(
name|NULL
argument_list|,
name|m_bitmap
operator|->
name|bitmap
argument_list|()
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not copy from bitmap! %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
name|null_result
return|;
block|}
return|return
name|QSharedPointer
argument_list|<
name|QWindowsDirect2DBitmap
argument_list|>
argument_list|(
operator|new
name|QWindowsDirect2DBitmap
argument_list|(
name|copy
operator|.
name|Get
argument_list|()
argument_list|,
name|Q_NULLPTR
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setupBitmap
name|void
name|QWindowsDirect2DWindow
operator|::
name|setupBitmap
parameter_list|()
block|{
if|if
condition|(
name|m_bitmap
condition|)
return|return;
if|if
condition|(
operator|!
name|m_deviceContext
condition|)
return|return;
if|if
condition|(
name|m_directRendering
operator|&&
operator|!
name|m_swapChain
condition|)
return|return;
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IDXGISurface1
argument_list|>
name|backBufferSurface
decl_stmt|;
if|if
condition|(
name|m_directRendering
condition|)
block|{
name|hr
operator|=
name|m_swapChain
operator|->
name|GetBuffer
argument_list|(
literal|0
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|backBufferSurface
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not query backbuffer for DXGI Surface: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
else|else
block|{
specifier|const
name|QRect
name|rect
init|=
name|geometry
argument_list|()
decl_stmt|;
name|CD3D11_TEXTURE2D_DESC
name|backBufferDesc
argument_list|(
name|DXGI_FORMAT_B8G8R8A8_UNORM
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|backBufferDesc
operator|.
name|BindFlags
operator|=
name|D3D11_BIND_RENDER_TARGET
expr_stmt|;
name|backBufferDesc
operator|.
name|MiscFlags
operator|=
name|D3D11_RESOURCE_MISC_GDI_COMPATIBLE
expr_stmt|;
name|ComPtr
argument_list|<
name|ID3D11Texture2D
argument_list|>
name|backBufferTexture
decl_stmt|;
name|HRESULT
name|hr
init|=
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d3dDevice
argument_list|()
operator|->
name|CreateTexture2D
argument_list|(
operator|&
name|backBufferDesc
argument_list|,
name|NULL
argument_list|,
operator|&
name|backBufferTexture
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to create backing texture for indirect rendering"
argument_list|)
expr_stmt|;
return|return;
block|}
name|hr
operator|=
name|backBufferTexture
operator|.
name|As
argument_list|(
operator|&
name|backBufferSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to cast back buffer surface to DXGI surface"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|ComPtr
argument_list|<
name|ID2D1Bitmap1
argument_list|>
name|backBufferBitmap
decl_stmt|;
name|hr
operator|=
name|m_deviceContext
operator|->
name|CreateBitmapFromDxgiSurface
argument_list|(
name|backBufferSurface
operator|.
name|Get
argument_list|()
argument_list|,
name|NULL
argument_list|,
name|backBufferBitmap
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not create Direct2D Bitmap from DXGI Surface: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return;
block|}
name|m_bitmap
operator|.
name|reset
argument_list|(
operator|new
name|QWindowsDirect2DBitmap
argument_list|(
name|backBufferBitmap
operator|.
name|Get
argument_list|()
argument_list|,
name|m_deviceContext
operator|.
name|Get
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QWindowsDirect2DPaintEngine
operator|::
name|Flags
name|flags
init|=
name|QWindowsDirect2DPaintEngine
operator|::
name|NoFlag
decl_stmt|;
if|if
condition|(
operator|!
name|m_directRendering
condition|)
name|flags
operator||=
name|QWindowsDirect2DPaintEngine
operator|::
name|TranslucentTopLevelWindow
expr_stmt|;
name|QWindowsDirect2DPlatformPixmap
modifier|*
name|pp
init|=
operator|new
name|QWindowsDirect2DPlatformPixmap
argument_list|(
name|QPlatformPixmap
operator|::
name|PixmapType
argument_list|,
name|flags
argument_list|,
name|m_bitmap
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|m_pixmap
operator|.
name|reset
argument_list|(
operator|new
name|QPixmap
argument_list|(
name|pp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
