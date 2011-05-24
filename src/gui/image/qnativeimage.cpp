begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qnativeimage_p.h"
end_include
begin_include
include|#
directive|include
file|"qcolormap.h"
end_include
begin_include
include|#
directive|include
file|"private/qpaintengine_raster_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qgraphicssystem_p.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MITSHM
argument_list|)
end_if
begin_include
include|#
directive|include
file|<qx11info_x11.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/shm.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<private/qpaintengine_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|bmiHeader
name|BITMAPINFOHEADER
name|bmiHeader
decl_stmt|;
DECL|member|redMask
name|DWORD
name|redMask
decl_stmt|;
DECL|member|greenMask
name|DWORD
name|greenMask
decl_stmt|;
DECL|member|blueMask
name|DWORD
name|blueMask
decl_stmt|;
block|}
DECL|typedef|BITMAPINFO_MASK
name|BITMAPINFO_MASK
typedef|;
end_typedef
begin_constructor
DECL|function|QNativeImage
name|QNativeImage
operator|::
name|QNativeImage
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|,
name|bool
name|isTextBuffer
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|Q_WS_WINCE
name|Q_UNUSED
argument_list|(
name|isTextBuffer
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|BITMAPINFO_MASK
name|bmi
decl_stmt|;
name|memset
argument_list|(
operator|&
name|bmi
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|bmi
argument_list|)
argument_list|)
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biSize
operator|=
sizeof|sizeof
argument_list|(
name|BITMAPINFOHEADER
argument_list|)
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biWidth
operator|=
name|width
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biHeight
operator|=
operator|-
name|height
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biPlanes
operator|=
literal|1
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biSizeImage
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|format
operator|==
name|QImage
operator|::
name|Format_RGB16
condition|)
block|{
name|bmi
operator|.
name|bmiHeader
operator|.
name|biBitCount
operator|=
literal|16
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE
if|if
condition|(
name|isTextBuffer
condition|)
block|{
name|bmi
operator|.
name|bmiHeader
operator|.
name|biCompression
operator|=
name|BI_RGB
expr_stmt|;
name|bmi
operator|.
name|redMask
operator|=
literal|0
expr_stmt|;
name|bmi
operator|.
name|greenMask
operator|=
literal|0
expr_stmt|;
name|bmi
operator|.
name|blueMask
operator|=
literal|0
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|bmi
operator|.
name|bmiHeader
operator|.
name|biCompression
operator|=
name|BI_BITFIELDS
expr_stmt|;
name|bmi
operator|.
name|redMask
operator|=
literal|0xF800
expr_stmt|;
name|bmi
operator|.
name|greenMask
operator|=
literal|0x07E0
expr_stmt|;
name|bmi
operator|.
name|blueMask
operator|=
literal|0x001F
expr_stmt|;
block|}
block|}
else|else
block|{
name|bmi
operator|.
name|bmiHeader
operator|.
name|biBitCount
operator|=
literal|32
expr_stmt|;
name|bmi
operator|.
name|bmiHeader
operator|.
name|biCompression
operator|=
name|BI_RGB
expr_stmt|;
name|bmi
operator|.
name|redMask
operator|=
literal|0
expr_stmt|;
name|bmi
operator|.
name|greenMask
operator|=
literal|0
expr_stmt|;
name|bmi
operator|.
name|blueMask
operator|=
literal|0
expr_stmt|;
block|}
name|HDC
name|display_dc
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|hdc
operator|=
name|CreateCompatibleDC
argument_list|(
name|display_dc
argument_list|)
expr_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|display_dc
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|bits
init|=
literal|0
decl_stmt|;
name|bitmap
operator|=
name|CreateDIBSection
argument_list|(
name|hdc
argument_list|,
cast|reinterpret_cast
argument_list|<
name|BITMAPINFO
operator|*
argument_list|>
argument_list|(
operator|&
name|bmi
argument_list|)
argument_list|,
name|DIB_RGB_COLORS
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|bits
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|bitmap
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|bits
argument_list|)
expr_stmt|;
name|null_bitmap
operator|=
operator|(
name|HBITMAP
operator|)
name|SelectObject
argument_list|(
name|hdc
argument_list|,
name|bitmap
argument_list|)
expr_stmt|;
name|image
operator|=
name|QImage
argument_list|(
name|bits
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|image
operator|.
name|paintEngine
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|QPaintEngine
operator|::
name|Raster
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
name|QRasterPaintEngine
operator|*
argument_list|>
argument_list|(
name|image
operator|.
name|paintEngine
argument_list|()
argument_list|)
operator|->
name|setDC
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_WS_WINCE
name|GdiFlush
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QNativeImage
name|QNativeImage
operator|::
name|~
name|QNativeImage
parameter_list|()
block|{
if|if
condition|(
name|bitmap
operator|||
name|hdc
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|bitmap
argument_list|)
expr_stmt|;
if|if
condition|(
name|null_bitmap
condition|)
name|SelectObject
argument_list|(
name|hdc
argument_list|,
name|null_bitmap
argument_list|)
expr_stmt|;
name|DeleteDC
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
name|DeleteObject
argument_list|(
name|bitmap
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|systemFormat
name|QImage
operator|::
name|Format
name|QNativeImage
operator|::
name|systemFormat
parameter_list|()
block|{
if|if
condition|(
name|QColormap
operator|::
name|instance
argument_list|()
operator|.
name|depth
argument_list|()
operator|==
literal|16
condition|)
return|return
name|QImage
operator|::
name|Format_RGB16
return|;
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MITSHM
argument_list|)
end_elif
begin_constructor
name|QNativeImage
operator|::
name|QNativeImage
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|,
name|bool
comment|/* isTextBuffer */
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|xshmimg
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|xshmpm
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|X11
operator|->
name|use_mitshm
condition|)
block|{
name|image
operator|=
name|QImage
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|)
expr_stmt|;
comment|// follow good coding practice and set xshminfo attributes, though values not used in this case
name|xshminfo
operator|.
name|readOnly
operator|=
literal|true
expr_stmt|;
name|xshminfo
operator|.
name|shmaddr
operator|=
literal|0
expr_stmt|;
name|xshminfo
operator|.
name|shmid
operator|=
literal|0
expr_stmt|;
name|xshminfo
operator|.
name|shmseg
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|QX11Info
name|info
init|=
name|widget
operator|->
name|x11Info
argument_list|()
decl_stmt|;
name|int
name|dd
init|=
name|info
operator|.
name|depth
argument_list|()
decl_stmt|;
name|Visual
modifier|*
name|vis
init|=
operator|(
name|Visual
operator|*
operator|)
name|info
operator|.
name|visual
argument_list|()
decl_stmt|;
name|xshmimg
operator|=
name|XShmCreateImage
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|vis
argument_list|,
name|dd
argument_list|,
name|ZPixmap
argument_list|,
literal|0
argument_list|,
operator|&
name|xshminfo
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|xshmimg
condition|)
block|{
name|qWarning
argument_list|(
literal|"QNativeImage: Unable to create shared XImage."
argument_list|)
expr_stmt|;
return|return;
block|}
name|bool
name|ok
decl_stmt|;
name|xshminfo
operator|.
name|shmid
operator|=
name|shmget
argument_list|(
name|IPC_PRIVATE
argument_list|,
name|xshmimg
operator|->
name|bytes_per_line
operator|*
name|xshmimg
operator|->
name|height
argument_list|,
name|IPC_CREAT
operator||
literal|0777
argument_list|)
expr_stmt|;
name|ok
operator|=
name|xshminfo
operator|.
name|shmid
operator|!=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
name|xshmimg
operator|->
name|data
operator|=
operator|(
name|char
operator|*
operator|)
name|shmat
argument_list|(
name|xshminfo
operator|.
name|shmid
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xshminfo
operator|.
name|shmaddr
operator|=
name|xshmimg
operator|->
name|data
expr_stmt|;
name|ok
operator|=
operator|(
name|xshminfo
operator|.
name|shmaddr
operator|!=
operator|(
name|char
operator|*
operator|)
operator|-
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|ok
condition|)
name|image
operator|=
name|QImage
argument_list|(
operator|(
name|uchar
operator|*
operator|)
name|xshmimg
operator|->
name|data
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
name|xshminfo
operator|.
name|readOnly
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
name|ok
operator|=
name|XShmAttach
argument_list|(
name|X11
operator|->
name|display
argument_list|,
operator|&
name|xshminfo
argument_list|)
expr_stmt|;
name|XSync
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|False
argument_list|)
expr_stmt|;
if|if
condition|(
name|shmctl
argument_list|(
name|xshminfo
operator|.
name|shmid
argument_list|,
name|IPC_RMID
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"Error while marking the shared memory segment to be destroyed"
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QNativeImage: Unable to attach to shared memory segment."
expr_stmt|;
if|if
condition|(
name|xshmimg
operator|->
name|data
condition|)
block|{
name|free
argument_list|(
name|xshmimg
operator|->
name|data
argument_list|)
expr_stmt|;
name|xshmimg
operator|->
name|data
operator|=
literal|0
expr_stmt|;
block|}
name|XDestroyImage
argument_list|(
name|xshmimg
argument_list|)
expr_stmt|;
name|xshmimg
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|xshminfo
operator|.
name|shmaddr
condition|)
name|shmdt
argument_list|(
name|xshminfo
operator|.
name|shmaddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|xshminfo
operator|.
name|shmid
operator|!=
operator|-
literal|1
condition|)
name|shmctl
argument_list|(
name|xshminfo
operator|.
name|shmid
argument_list|,
name|IPC_RMID
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|X11
operator|->
name|use_mitshm_pixmaps
condition|)
block|{
name|xshmpm
operator|=
name|XShmCreatePixmap
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|DefaultRootWindow
argument_list|(
name|X11
operator|->
name|display
argument_list|)
argument_list|,
name|xshmimg
operator|->
name|data
argument_list|,
operator|&
name|xshminfo
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|dd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|xshmpm
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QNativeImage: Unable to create shared Pixmap."
expr_stmt|;
block|}
block|}
block|}
end_constructor
begin_destructor
name|QNativeImage
operator|::
name|~
name|QNativeImage
parameter_list|()
block|{
if|if
condition|(
operator|!
name|xshmimg
condition|)
return|return;
if|if
condition|(
name|xshmpm
condition|)
block|{
name|XFreePixmap
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|xshmpm
argument_list|)
expr_stmt|;
name|xshmpm
operator|=
literal|0
expr_stmt|;
block|}
name|XShmDetach
argument_list|(
name|X11
operator|->
name|display
argument_list|,
operator|&
name|xshminfo
argument_list|)
expr_stmt|;
name|xshmimg
operator|->
name|data
operator|=
literal|0
expr_stmt|;
name|XDestroyImage
argument_list|(
name|xshmimg
argument_list|)
expr_stmt|;
name|xshmimg
operator|=
literal|0
expr_stmt|;
name|shmdt
argument_list|(
name|xshminfo
operator|.
name|shmaddr
argument_list|)
expr_stmt|;
name|shmctl
argument_list|(
name|xshminfo
operator|.
name|shmid
argument_list|,
name|IPC_RMID
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
name|QImage
operator|::
name|Format
name|QNativeImage
operator|::
name|systemFormat
parameter_list|()
block|{
if|if
condition|(
name|QX11Info
operator|::
name|appDepth
argument_list|()
operator|==
literal|16
condition|)
return|return
name|QImage
operator|::
name|Format_RGB16
return|;
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_elif
begin_constructor
name|QNativeImage
operator|::
name|QNativeImage
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|,
name|bool
comment|/* isTextBuffer */
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|image
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|)
block|{
name|uint
name|cgflags
init|=
name|kCGImageAlphaNoneSkipFirst
decl_stmt|;
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|QImage
operator|::
name|Format_ARGB32
case|:
name|cgflags
operator|=
name|kCGImageAlphaFirst
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB8565_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB6666_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB8555_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB4444_Premultiplied
case|:
name|cgflags
operator|=
name|kCGImageAlphaPremultipliedFirst
expr_stmt|;
break|break;
default|default:
break|break;
block|}
ifdef|#
directive|ifdef
name|kCGBitmapByteOrder32Host
comment|//only needed because CGImage.h added symbols in the minor version
name|cgflags
operator||=
name|kCGBitmapByteOrder32Host
expr_stmt|;
endif|#
directive|endif
name|cg
operator|=
name|CGBitmapContextCreate
argument_list|(
name|image
operator|.
name|bits
argument_list|()
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|8
argument_list|,
name|image
operator|.
name|bytesPerLine
argument_list|()
argument_list|,
name|QCoreGraphicsPaintEngine
operator|::
name|macDisplayColorSpace
argument_list|(
name|widget
argument_list|)
argument_list|,
name|cgflags
argument_list|)
expr_stmt|;
name|CGContextTranslateCTM
argument_list|(
name|cg
argument_list|,
literal|0
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|CGContextScaleCTM
argument_list|(
name|cg
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|image
operator|.
name|paintEngine
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|QPaintEngine
operator|::
name|Raster
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
name|QRasterPaintEngine
operator|*
argument_list|>
argument_list|(
name|image
operator|.
name|paintEngine
argument_list|()
argument_list|)
operator|->
name|setCGContext
argument_list|(
name|cg
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
name|QNativeImage
operator|::
name|~
name|QNativeImage
parameter_list|()
block|{
name|CGContextRelease
argument_list|(
name|cg
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
name|QImage
operator|::
name|Format
name|QNativeImage
operator|::
name|systemFormat
parameter_list|()
block|{
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|// other platforms...
end_comment
begin_constructor
name|QNativeImage
operator|::
name|QNativeImage
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|,
name|bool
comment|/* isTextBuffer */
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
member_init_list|:
name|image
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|)
block|{  }
end_constructor
begin_destructor
name|QNativeImage
operator|::
name|~
name|QNativeImage
parameter_list|()
block|{ }
end_destructor
begin_function
name|QImage
operator|::
name|Format
name|QNativeImage
operator|::
name|systemFormat
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_WS_QPA
return|return
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|screens
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|format
argument_list|()
return|;
else|#
directive|else
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// platforms
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
