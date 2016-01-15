begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE_WM
end_ifdef
begin_include
include|#
directive|include
file|<Ddraw.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_decl_stmt
DECL|variable|g_pDD
specifier|static
name|LPDIRECTDRAW
name|g_pDD
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|g_pDD
comment|// DirectDraw object
end_comment
begin_decl_stmt
DECL|variable|g_pDDSSurface
specifier|static
name|LPDIRECTDRAWSURFACE
name|g_pDDSSurface
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|g_pDDSSurface
comment|// DirectDraw primary surface
end_comment
begin_decl_stmt
DECL|variable|ddsCaps
specifier|static
name|DDSCAPS
name|ddsCaps
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ddsSurfaceDesc
specifier|static
name|DDSURFACEDESC
name|ddsSurfaceDesc
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|buffer
specifier|static
name|void
modifier|*
name|buffer
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|width
specifier|static
name|int
name|width
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|height
specifier|static
name|int
name|height
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|pitch
specifier|static
name|int
name|pitch
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|bitCount
specifier|static
name|int
name|bitCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|windowId
specifier|static
name|int
name|windowId
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|initialized
specifier|static
name|bool
name|initialized
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|locked
specifier|static
name|bool
name|locked
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|q_lock
name|void
name|q_lock
parameter_list|()
block|{
if|if
condition|(
name|locked
condition|)
block|{
name|qWarning
argument_list|(
literal|"Direct Painter already locked (QDirectPainter::lock())"
argument_list|)
expr_stmt|;
return|return;
block|}
name|locked
operator|=
literal|true
expr_stmt|;
name|memset
argument_list|(
operator|&
name|ddsSurfaceDesc
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ddsSurfaceDesc
argument_list|)
argument_list|)
expr_stmt|;
name|ddsSurfaceDesc
operator|.
name|dwSize
operator|=
sizeof|sizeof
argument_list|(
name|ddsSurfaceDesc
argument_list|)
expr_stmt|;
name|HRESULT
name|h
init|=
name|g_pDDSSurface
operator|->
name|Lock
argument_list|(
literal|0
argument_list|,
operator|&
name|ddsSurfaceDesc
argument_list|,
name|DDLOCK_WRITEONLY
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|h
operator|!=
name|DD_OK
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"GetSurfaceDesc failed!"
expr_stmt|;
name|width
operator|=
name|ddsSurfaceDesc
operator|.
name|dwWidth
expr_stmt|;
name|height
operator|=
name|ddsSurfaceDesc
operator|.
name|dwHeight
expr_stmt|;
name|bitCount
operator|=
name|ddsSurfaceDesc
operator|.
name|ddpfPixelFormat
operator|.
name|dwRGBBitCount
expr_stmt|;
name|pitch
operator|=
name|ddsSurfaceDesc
operator|.
name|lPitch
expr_stmt|;
name|buffer
operator|=
name|ddsSurfaceDesc
operator|.
name|lpSurface
expr_stmt|;
block|}
end_function
begin_function
DECL|function|q_unlock
name|void
name|q_unlock
parameter_list|()
block|{
if|if
condition|(
operator|!
name|locked
condition|)
block|{
name|qWarning
argument_list|(
literal|"Direct Painter not locked (QDirectPainter::unlock()"
argument_list|)
expr_stmt|;
return|return;
block|}
name|g_pDDSSurface
operator|->
name|Unlock
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|locked
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|q_initDD
name|void
name|q_initDD
parameter_list|()
block|{
if|if
condition|(
name|initialized
condition|)
return|return;
name|DirectDrawCreate
argument_list|(
name|NULL
argument_list|,
operator|&
name|g_pDD
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|HRESULT
name|h
decl_stmt|;
name|h
operator|=
name|g_pDD
operator|->
name|SetCooperativeLevel
argument_list|(
literal|0
argument_list|,
name|DDSCL_NORMAL
argument_list|)
expr_stmt|;
if|if
condition|(
name|h
operator|!=
name|DD_OK
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"cooperation level failed"
expr_stmt|;
name|h
operator|=
name|g_pDD
operator|->
name|TestCooperativeLevel
argument_list|()
expr_stmt|;
if|if
condition|(
name|h
operator|!=
name|DD_OK
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"cooperation level failed test"
expr_stmt|;
name|DDSURFACEDESC
name|ddsd
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ddsd
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ddsd
argument_list|)
argument_list|)
expr_stmt|;
name|ddsd
operator|.
name|dwSize
operator|=
sizeof|sizeof
argument_list|(
name|ddsd
argument_list|)
expr_stmt|;
name|ddsd
operator|.
name|dwFlags
operator|=
name|DDSD_CAPS
expr_stmt|;
name|ddsd
operator|.
name|ddsCaps
operator|.
name|dwCaps
operator|=
name|DDSCAPS_PRIMARYSURFACE
expr_stmt|;
name|h
operator|=
name|g_pDD
operator|->
name|CreateSurface
argument_list|(
operator|&
name|ddsd
argument_list|,
operator|&
name|g_pDDSSurface
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|h
operator|!=
name|DD_OK
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"CreateSurface failed!"
expr_stmt|;
if|if
condition|(
name|g_pDDSSurface
operator|->
name|GetCaps
argument_list|(
operator|&
name|ddsCaps
argument_list|)
operator|!=
name|DD_OK
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"GetCaps failed"
expr_stmt|;
name|q_lock
argument_list|()
expr_stmt|;
name|q_unlock
argument_list|()
expr_stmt|;
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|q_frameBuffer
name|uchar
modifier|*
name|q_frameBuffer
parameter_list|()
block|{
return|return
operator|(
name|uchar
operator|*
operator|)
name|buffer
return|;
block|}
end_function
begin_function
DECL|function|q_screenDepth
name|int
name|q_screenDepth
parameter_list|()
block|{
return|return
name|bitCount
return|;
block|}
end_function
begin_function
DECL|function|q_screenWidth
name|int
name|q_screenWidth
parameter_list|()
block|{
return|return
name|width
return|;
block|}
end_function
begin_function
DECL|function|q_screenHeight
name|int
name|q_screenHeight
parameter_list|()
block|{
return|return
name|height
return|;
block|}
end_function
begin_function
DECL|function|q_linestep
name|int
name|q_linestep
parameter_list|()
block|{
return|return
name|pitch
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_OS_WINCE_WM
end_comment
end_unit
