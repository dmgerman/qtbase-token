begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#include<QDebug>
end_comment
begin_include
include|#
directive|include
file|"qkmscursor.h"
end_include
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qkmsdevice.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QKmsCursor
name|QKmsCursor
operator|::
name|QKmsCursor
parameter_list|(
name|QKmsScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|QPlatformCursor
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_graphicsBufferManager
argument_list|(
name|screen
operator|->
name|device
argument_list|()
operator|->
name|gbmDevice
argument_list|()
argument_list|)
block|{
name|gbm_bo
modifier|*
name|bo
init|=
name|gbm_bo_create
argument_list|(
name|m_graphicsBufferManager
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|,
name|GBM_BO_FORMAT_ARGB8888
argument_list|,
name|GBM_BO_USE_CURSOR_64X64
operator||
name|GBM_BO_USE_RENDERING
argument_list|)
decl_stmt|;
name|m_eglImage
operator|=
name|eglCreateImageKHR
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
argument_list|,
literal|0
argument_list|,
name|EGL_NATIVE_PIXMAP_KHR
argument_list|,
name|bo
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|gbm_bo_destroy
argument_list|(
name|bo
argument_list|)
expr_stmt|;
name|m_cursorImage
operator|=
operator|new
name|QPlatformCursorImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|pointerEvent
name|void
name|QKmsCursor
operator|::
name|pointerEvent
parameter_list|(
specifier|const
name|QMouseEvent
modifier|&
name|event
parameter_list|)
block|{
name|int
name|status
init|=
name|drmModeMoveCursor
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|m_screen
operator|->
name|crtcId
argument_list|()
argument_list|,
name|event
operator|.
name|globalX
argument_list|()
argument_list|,
name|event
operator|.
name|globalY
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to move cursor: %d"
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|changeCursor
name|void
name|QKmsCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|widgetCursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|window
argument_list|)
if|if
condition|(
name|widgetCursor
operator|->
name|shape
argument_list|()
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
name|m_cursorImage
operator|->
name|set
argument_list|(
name|widgetCursor
operator|->
name|shape
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_cursorImage
operator|->
name|set
argument_list|(
name|widgetCursor
operator|->
name|pixmap
argument_list|()
operator|.
name|toImage
argument_list|()
argument_list|,
name|widgetCursor
operator|->
name|hotSpot
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|widgetCursor
operator|->
name|hotSpot
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|m_cursorImage
operator|->
name|image
argument_list|()
operator|->
name|width
argument_list|()
operator|>
literal|64
operator|)
operator|||
operator|(
name|m_cursorImage
operator|->
name|image
argument_list|()
operator|->
name|width
argument_list|()
operator|>
literal|64
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to set hardware cursor: larger than 64x64."
argument_list|)
expr_stmt|;
return|return;
block|}
name|QImage
name|cursorImage
init|=
name|m_cursorImage
operator|->
name|image
argument_list|()
operator|->
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
comment|//Load cursor image into EGLImage
name|GLuint
name|cursorTexture
decl_stmt|;
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|cursorTexture
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|cursorTexture
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_LINEAR
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_LINEAR
argument_list|)
expr_stmt|;
comment|//TODO: Format may be wrong here, need a color icon to test.
if|if
condition|(
name|m_eglImage
operator|!=
name|EGL_NO_IMAGE_KHR
condition|)
block|{
name|glEGLImageTargetTexture2DOES
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_eglImage
argument_list|)
expr_stmt|;
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|cursorImage
operator|.
name|width
argument_list|()
argument_list|,
name|cursorImage
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|cursorImage
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|cursorImage
operator|.
name|width
argument_list|()
argument_list|,
name|cursorImage
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|cursorImage
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|//EGLImage needs to contain sprite before calling this:
name|gbm_bo
modifier|*
name|bufferObject
init|=
name|gbm_bo_create_from_egl_image
argument_list|(
name|m_graphicsBufferManager
argument_list|,
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|m_eglImage
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|,
name|GBM_BO_USE_CURSOR_64X64
argument_list|)
decl_stmt|;
name|quint32
name|handle
init|=
name|gbm_bo_get_handle
argument_list|(
name|bufferObject
argument_list|)
operator|.
name|u32
decl_stmt|;
name|gbm_bo_destroy
argument_list|(
name|bufferObject
argument_list|)
expr_stmt|;
name|int
name|status
init|=
name|drmModeSetCursor
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|m_screen
operator|->
name|crtcId
argument_list|()
argument_list|,
name|handle
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to set cursor: %d"
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
