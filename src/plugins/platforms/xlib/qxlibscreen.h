begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTLITESCREEN_H
end_ifndef
begin_define
DECL|macro|QTESTLITESCREEN_H
define|#
directive|define
name|QTESTLITESCREEN_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_include
include|#
directive|include
file|"qxlibintegration.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXlibCursor
name|class
name|QXlibCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXlibKeyboard
name|class
name|QXlibKeyboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXlibDisplay
name|class
name|QXlibDisplay
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QXlibScreen
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformScreen
block|{
name|Q_OBJECT
name|public
range|:
name|QXlibScreen
argument_list|()
decl_stmt|;
operator|~
name|QXlibScreen
argument_list|()
expr_stmt|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|{
return|return
name|mGeometry
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|mDepth
return|;
block|}
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|{
return|return
name|mFormat
return|;
block|}
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|{
return|return
name|mPhysicalSize
return|;
block|}
name|Window
name|rootWindow
parameter_list|()
function_decl|;
name|unsigned
name|long
name|blackPixel
parameter_list|()
function_decl|;
name|unsigned
name|long
name|whitePixel
parameter_list|()
function_decl|;
name|bool
name|handleEvent
parameter_list|(
name|XEvent
modifier|*
name|xe
parameter_list|)
function_decl|;
name|bool
name|waitForClipboardEvent
parameter_list|(
name|Window
name|win
parameter_list|,
name|int
name|type
parameter_list|,
name|XEvent
modifier|*
name|event
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
name|QImage
name|grabWindow
parameter_list|(
name|Window
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
function_decl|;
specifier|static
name|QXlibScreen
modifier|*
name|testLiteScreenForWidget
parameter_list|(
name|QWindow
modifier|*
name|widget
parameter_list|)
function_decl|;
name|QXlibDisplay
operator|*
name|display
argument_list|()
specifier|const
expr_stmt|;
name|int
name|xScreenNumber
argument_list|()
specifier|const
expr_stmt|;
name|Visual
operator|*
name|defaultVisual
argument_list|()
specifier|const
expr_stmt|;
name|QXlibKeyboard
operator|*
name|keyboard
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
name|void
operator|*
name|eglDisplay
argument_list|()
specifier|const
block|{
return|return
name|mEGLDisplay
return|;
block|}
name|void
name|setEglDisplay
parameter_list|(
name|void
modifier|*
name|display
parameter_list|)
block|{
name|mEGLDisplay
operator|=
name|display
expr_stmt|;
block|}
endif|#
directive|endif
name|public
name|slots
range|:
name|void
name|eventDispatcher
argument_list|()
decl_stmt|;
name|private
label|:
name|void
name|handleSelectionRequest
parameter_list|(
name|XEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|QRect
name|mGeometry
decl_stmt|;
name|QSizeF
name|mPhysicalSize
decl_stmt|;
name|int
name|mDepth
decl_stmt|;
name|QImage
operator|::
name|Format
name|mFormat
expr_stmt|;
name|QXlibCursor
modifier|*
name|mCursor
decl_stmt|;
name|QXlibKeyboard
modifier|*
name|mKeyboard
decl_stmt|;
name|QXlibDisplay
modifier|*
name|mDisplay
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
name|void
modifier|*
name|mEGLDisplay
decl_stmt|;
endif|#
directive|endif
name|int
name|mScreen
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTESTLITESCREEN_H
end_comment
end_unit
