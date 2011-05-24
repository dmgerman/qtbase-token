begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwidget.h>
end_include
begin_include
include|#
directive|include
file|"qegl_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglcontext_p.h"
end_include
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|nativeDisplay
name|EGLNativeDisplayType
name|QEgl
operator|::
name|nativeDisplay
parameter_list|()
block|{
name|HDC
name|myDc
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|myDc
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEglContext::nativeDisplay(): WinCE display is not open"
argument_list|)
expr_stmt|;
return|return
name|EGL_DEFAULT_DISPLAY
return|;
block|}
return|return
name|EGLNativeDisplayType
argument_list|(
name|myDc
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativeWindow
name|EGLNativeWindowType
name|QEgl
operator|::
name|nativeWindow
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
return|return
call|(
name|EGLNativeWindowType
call|)
argument_list|(
name|widget
operator|->
name|winId
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativePixmap
name|EGLNativePixmapType
name|QEgl
operator|::
name|nativePixmap
parameter_list|(
name|QPixmap
modifier|*
parameter_list|)
block|{
name|qWarning
argument_list|(
literal|"QEgl: EGL pixmap surfaces not supported on WinCE"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EGLNativePixmapType
operator|)
literal|0
return|;
block|}
end_function
begin_comment
comment|// Set pixel format and other properties based on a paint device.
end_comment
begin_function
DECL|function|setPaintDeviceFormat
name|void
name|QEglProperties
operator|::
name|setPaintDeviceFormat
parameter_list|(
name|QPaintDevice
modifier|*
name|dev
parameter_list|)
block|{
name|int
name|devType
init|=
name|dev
operator|->
name|devType
argument_list|()
decl_stmt|;
if|if
condition|(
name|devType
operator|==
name|QInternal
operator|::
name|Image
condition|)
name|setPixelFormat
argument_list|(
cast|static_cast
argument_list|<
name|QImage
operator|*
argument_list|>
argument_list|(
name|dev
argument_list|)
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|setPixelFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB16
argument_list|)
expr_stmt|;
comment|// XXX
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
