begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsnativeimage.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<private/qhighdpiscaling_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWindowsBackingStore     \brief Backing store for windows.     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsBackingStore
name|QWindowsBackingStore
operator|::
name|QWindowsBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
block|{
name|qCDebug
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|window
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsBackingStore
name|QWindowsBackingStore
operator|::
name|~
name|QWindowsBackingStore
parameter_list|()
block|{
name|qCDebug
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QWindowsBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|&
name|m_image
operator|->
name|image
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWindowsBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
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
name|Q_ASSERT
argument_list|(
name|window
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|br
init|=
name|region
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verbose
operator|>
literal|1
condition|)
name|qCDebug
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|window
operator|<<
name|offset
operator|<<
name|br
expr_stmt|;
name|QWindowsWindow
modifier|*
name|rw
init|=
name|QWindowsWindow
operator|::
name|baseWindowOf
argument_list|(
name|window
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|const
name|bool
name|hasAlpha
init|=
name|rw
operator|->
name|format
argument_list|()
operator|.
name|hasAlpha
argument_list|()
decl_stmt|;
specifier|const
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|window
operator|->
name|flags
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Qt
operator|::
name|FramelessWindowHint
operator|)
operator|&&
name|QWindowsWindow
operator|::
name|setWindowLayered
argument_list|(
name|rw
operator|->
name|handle
argument_list|()
argument_list|,
name|flags
argument_list|,
name|hasAlpha
argument_list|,
name|rw
operator|->
name|opacity
argument_list|()
argument_list|)
operator|&&
name|hasAlpha
condition|)
block|{
comment|// Windows with alpha: Use blend function to update.
name|QRect
name|r
init|=
name|QHighDpi
operator|::
name|toNativePixels
argument_list|(
name|window
operator|->
name|frameGeometry
argument_list|()
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QPoint
name|frameOffset
argument_list|(
name|QHighDpi
operator|::
name|toNativePixels
argument_list|(
name|QPoint
argument_list|(
name|window
operator|->
name|frameMargins
argument_list|()
operator|.
name|left
argument_list|()
argument_list|,
name|window
operator|->
name|frameMargins
argument_list|()
operator|.
name|top
argument_list|()
argument_list|)
argument_list|,
name|window
argument_list|)
argument_list|)
decl_stmt|;
name|QRect
name|dirtyRect
init|=
name|br
operator|.
name|translated
argument_list|(
name|offset
operator|+
name|frameOffset
argument_list|)
decl_stmt|;
name|SIZE
name|size
init|=
block|{
name|r
operator|.
name|width
argument_list|()
block|,
name|r
operator|.
name|height
argument_list|()
block|}
decl_stmt|;
name|POINT
name|ptDst
init|=
block|{
name|r
operator|.
name|x
argument_list|()
block|,
name|r
operator|.
name|y
argument_list|()
block|}
decl_stmt|;
name|POINT
name|ptSrc
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|BLENDFUNCTION
name|blend
init|=
block|{
name|AC_SRC_OVER
block|,
literal|0
block|,
call|(
name|BYTE
call|)
argument_list|(
literal|255.0
operator|*
name|rw
operator|->
name|opacity
argument_list|()
argument_list|)
block|,
name|AC_SRC_ALPHA
block|}
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|updateLayeredWindowIndirect
condition|)
block|{
name|RECT
name|dirty
init|=
block|{
name|dirtyRect
operator|.
name|x
argument_list|()
block|,
name|dirtyRect
operator|.
name|y
argument_list|()
block|,
name|dirtyRect
operator|.
name|x
argument_list|()
operator|+
name|dirtyRect
operator|.
name|width
argument_list|()
block|,
name|dirtyRect
operator|.
name|y
argument_list|()
operator|+
name|dirtyRect
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
name|info
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
name|m_image
operator|->
name|hdc
argument_list|()
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
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|updateLayeredWindowIndirect
argument_list|(
name|rw
operator|->
name|handle
argument_list|()
argument_list|,
operator|&
name|info
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|updateLayeredWindow
argument_list|(
name|rw
operator|->
name|handle
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|ptDst
argument_list|,
operator|&
name|size
argument_list|,
name|m_image
operator|->
name|hdc
argument_list|()
argument_list|,
operator|&
name|ptSrc
argument_list|,
literal|0
argument_list|,
operator|&
name|blend
argument_list|,
name|ULW_ALPHA
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
endif|#
directive|endif
specifier|const
name|HDC
name|dc
init|=
name|rw
operator|->
name|getDC
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|dc
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"%s: GetDC failed"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|BitBlt
argument_list|(
name|dc
argument_list|,
name|br
operator|.
name|x
argument_list|()
argument_list|,
name|br
operator|.
name|y
argument_list|()
argument_list|,
name|br
operator|.
name|width
argument_list|()
argument_list|,
name|br
operator|.
name|height
argument_list|()
argument_list|,
name|m_image
operator|->
name|hdc
argument_list|()
argument_list|,
name|br
operator|.
name|x
argument_list|()
operator|+
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|br
operator|.
name|y
argument_list|()
operator|+
name|offset
operator|.
name|y
argument_list|()
argument_list|,
name|SRCCOPY
argument_list|)
condition|)
block|{
specifier|const
name|DWORD
name|lastError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
comment|// QTBUG-35926, QTBUG-29716: may fail after lock screen.
if|if
condition|(
name|lastError
operator|!=
name|ERROR_SUCCESS
operator|&&
name|lastError
operator|!=
name|ERROR_INVALID_HANDLE
condition|)
name|qErrnoWarning
argument_list|(
name|lastError
argument_list|,
literal|"%s: BitBlt failed"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
block|}
name|rw
operator|->
name|releaseDC
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
block|}
endif|#
directive|endif
comment|// Write image for debug purposes.
if|if
condition|(
name|QWindowsContext
operator|::
name|verbose
operator|>
literal|2
operator|&&
name|lcQpaBackingStore
argument_list|()
operator|.
name|isDebugEnabled
argument_list|()
condition|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
specifier|const
name|QString
name|fileName
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"win%1_%2.png"
argument_list|)
operator|.
name|arg
argument_list|(
name|rw
operator|->
name|winId
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|n
operator|++
argument_list|)
decl_stmt|;
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|save
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
literal|"Wrote "
operator|<<
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
operator|<<
name|fileName
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QWindowsBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
if|if
condition|(
name|m_image
operator|.
name|isNull
argument_list|()
operator|||
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
operator|!=
name|size
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_OUTPUT
if|if
condition|(
name|QWindowsContext
operator|::
name|verbose
operator|&&
name|lcQpaBackingStore
argument_list|()
operator|.
name|isDebugEnabled
argument_list|()
condition|)
block|{
name|qCDebug
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
literal|' '
operator|<<
name|window
argument_list|()
operator|<<
literal|' '
operator|<<
name|size
operator|<<
literal|' '
operator|<<
name|region
operator|<<
literal|" from: "
operator|<<
operator|(
name|m_image
operator|.
name|isNull
argument_list|()
condition|?
name|QSize
argument_list|()
else|:
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
operator|)
expr_stmt|;
block|}
endif|#
directive|endif
specifier|const
name|QImage
operator|::
name|Format
name|format
init|=
name|window
argument_list|()
operator|->
name|format
argument_list|()
operator|.
name|hasAlpha
argument_list|()
condition|?
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
else|:
name|QWindowsNativeImage
operator|::
name|systemFormat
argument_list|()
decl_stmt|;
name|QWindowsNativeImage
modifier|*
name|oldwni
init|=
name|m_image
operator|.
name|data
argument_list|()
decl_stmt|;
name|QWindowsNativeImage
modifier|*
name|newwni
init|=
operator|new
name|QWindowsNativeImage
argument_list|(
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
name|format
argument_list|)
decl_stmt|;
if|if
condition|(
name|oldwni
operator|&&
operator|!
name|region
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QImage
modifier|&
name|oldimg
argument_list|(
name|oldwni
operator|->
name|image
argument_list|()
argument_list|)
decl_stmt|;
name|QImage
modifier|&
name|newimg
argument_list|(
name|newwni
operator|->
name|image
argument_list|()
argument_list|)
decl_stmt|;
name|QRegion
name|staticRegion
argument_list|(
name|region
argument_list|)
decl_stmt|;
name|staticRegion
operator|&=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|oldimg
operator|.
name|width
argument_list|()
argument_list|,
name|oldimg
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|staticRegion
operator|&=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|newimg
operator|.
name|width
argument_list|()
argument_list|,
name|newimg
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|newimg
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|staticRegion
operator|.
name|rects
argument_list|()
control|)
name|painter
operator|.
name|drawImage
argument_list|(
name|rect
argument_list|,
name|oldimg
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
name|m_image
operator|.
name|reset
argument_list|(
name|newwni
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function_decl
name|Q_GUI_EXPORT
name|void
name|qt_scrollRectInImage
parameter_list|(
name|QImage
modifier|&
name|img
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|scroll
name|bool
name|QWindowsBackingStore
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
if|if
condition|(
name|m_image
operator|.
name|isNull
argument_list|()
operator|||
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|false
return|;
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|area
operator|.
name|rects
argument_list|()
decl_stmt|;
specifier|const
name|QPoint
name|offset
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rects
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qt_scrollRectInImage
argument_list|(
name|m_image
operator|->
name|image
argument_list|()
argument_list|,
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|offset
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QWindowsBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verbose
operator|>
literal|1
condition|)
name|qCDebug
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|region
expr_stmt|;
if|if
condition|(
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|hasAlphaChannel
argument_list|()
condition|)
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|m_image
operator|->
name|image
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
specifier|const
name|QColor
name|blank
init|=
name|Qt
operator|::
name|transparent
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|r
decl|,
name|region
operator|.
name|rects
argument_list|()
control|)
name|p
operator|.
name|fillRect
argument_list|(
name|r
argument_list|,
name|blank
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|getDC
name|HDC
name|QWindowsBackingStore
operator|::
name|getDC
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|m_image
operator|->
name|hdc
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_function
DECL|function|toImage
name|QImage
name|QWindowsBackingStore
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_image
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|qCWarning
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
literal|"Image is null."
expr_stmt|;
return|return
name|QImage
argument_list|()
return|;
block|}
return|return
name|m_image
operator|.
name|data
argument_list|()
operator|->
name|image
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_OPENGL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
