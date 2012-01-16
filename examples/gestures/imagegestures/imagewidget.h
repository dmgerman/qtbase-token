begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|IMAGEWIDGET_H
end_ifndef
begin_define
DECL|macro|IMAGEWIDGET_H
define|#
directive|define
name|IMAGEWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGestureEvent
name|class
name|QGestureEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPanGesture
name|class
name|QPanGesture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPinchGesture
name|class
name|QPinchGesture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSwipeGesture
name|class
name|QSwipeGesture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [class definition begin]
name|class
name|ImageWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|ImageWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|openDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|bool
name|gestureEvent
argument_list|(
name|QGestureEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|panTriggered
argument_list|(
name|QPanGesture
operator|*
argument_list|)
block|;
name|void
name|pinchTriggered
argument_list|(
name|QPinchGesture
operator|*
argument_list|)
block|;
name|void
name|swipeTriggered
argument_list|(
name|QSwipeGesture
operator|*
argument_list|)
block|;
comment|//! [class definition begin]
name|void
name|updateImage
argument_list|()
block|;
name|QImage
name|loadImage
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|loadImage
argument_list|()
block|;
name|void
name|goNextImage
argument_list|()
block|;
name|void
name|goPrevImage
argument_list|()
block|;
name|void
name|goToImage
argument_list|(
argument|int index
argument_list|)
block|;
name|QString
name|path
block|;
name|QStringList
name|files
block|;
name|int
name|position
block|;
name|QImage
name|prevImage
block|,
name|nextImage
block|;
name|QImage
name|currentImage
block|;
name|float
name|horizontalOffset
block|;
name|float
name|verticalOffset
block|;
name|float
name|rotationAngle
block|;
name|float
name|scaleFactor
block|;
name|float
name|currentStepScaleFactor
block|;
comment|//! [class definition end]
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [class definition end]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
