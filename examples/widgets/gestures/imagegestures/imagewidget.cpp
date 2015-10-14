begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"imagewidget.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_macro
name|Q_LOGGING_CATEGORY
argument_list|(
argument|lcExample
argument_list|,
literal|"qt.examples.imagegestures"
argument_list|)
end_macro
begin_comment
comment|//! [constructor]
end_comment
begin_constructor
DECL|function|ImageWidget
name|ImageWidget
operator|::
name|ImageWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|position
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|horizontalOffset
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|verticalOffset
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|rotationAngle
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|scaleFactor
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|currentStepScaleFactor
argument_list|(
literal|1
argument_list|)
block|{
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [constructor]
end_comment
begin_function
DECL|function|grabGestures
name|void
name|ImageWidget
operator|::
name|grabGestures
parameter_list|(
specifier|const
name|QList
argument_list|<
name|Qt
operator|::
name|GestureType
argument_list|>
modifier|&
name|gestures
parameter_list|)
block|{
comment|//! [enable gestures]
foreach|foreach
control|(
name|Qt
operator|::
name|GestureType
name|gesture
decl|,
name|gestures
control|)
name|grabGesture
argument_list|(
name|gesture
argument_list|)
expr_stmt|;
comment|//! [enable gestures]
block|}
end_function
begin_comment
comment|//! [event handler]
end_comment
begin_function
DECL|function|event
name|bool
name|ImageWidget
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Gesture
condition|)
return|return
name|gestureEvent
argument_list|(
cast|static_cast
argument_list|<
name|QGestureEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
return|;
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [event handler]
end_comment
begin_comment
comment|//! [paint method]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|ImageWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
specifier|const
name|qreal
name|iw
init|=
name|currentImage
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|qreal
name|ih
init|=
name|currentImage
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|qreal
name|wh
init|=
name|height
argument_list|()
decl_stmt|;
specifier|const
name|qreal
name|ww
init|=
name|width
argument_list|()
decl_stmt|;
name|p
operator|.
name|translate
argument_list|(
name|ww
operator|/
literal|2
argument_list|,
name|wh
operator|/
literal|2
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
name|horizontalOffset
argument_list|,
name|verticalOffset
argument_list|)
expr_stmt|;
name|p
operator|.
name|rotate
argument_list|(
name|rotationAngle
argument_list|)
expr_stmt|;
name|p
operator|.
name|scale
argument_list|(
name|currentStepScaleFactor
operator|*
name|scaleFactor
argument_list|,
name|currentStepScaleFactor
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
operator|-
name|iw
operator|/
literal|2
argument_list|,
operator|-
name|ih
operator|/
literal|2
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|currentImage
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [paint method]
end_comment
begin_function
DECL|function|mouseDoubleClickEvent
name|void
name|ImageWidget
operator|::
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|rotationAngle
operator|=
literal|0
expr_stmt|;
name|scaleFactor
operator|=
literal|1
expr_stmt|;
name|currentStepScaleFactor
operator|=
literal|1
expr_stmt|;
name|verticalOffset
operator|=
literal|0
expr_stmt|;
name|horizontalOffset
operator|=
literal|0
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|qCDebug
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"reset on mouse double click"
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [gesture event handler]
end_comment
begin_function
DECL|function|gestureEvent
name|bool
name|ImageWidget
operator|::
name|gestureEvent
parameter_list|(
name|QGestureEvent
modifier|*
name|event
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"gestureEvent():"
operator|<<
name|event
expr_stmt|;
if|if
condition|(
name|QGesture
modifier|*
name|swipe
init|=
name|event
operator|->
name|gesture
argument_list|(
name|Qt
operator|::
name|SwipeGesture
argument_list|)
condition|)
name|swipeTriggered
argument_list|(
cast|static_cast
argument_list|<
name|QSwipeGesture
operator|*
argument_list|>
argument_list|(
name|swipe
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|QGesture
modifier|*
name|pan
init|=
name|event
operator|->
name|gesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
condition|)
name|panTriggered
argument_list|(
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|pan
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGesture
modifier|*
name|pinch
init|=
name|event
operator|->
name|gesture
argument_list|(
name|Qt
operator|::
name|PinchGesture
argument_list|)
condition|)
name|pinchTriggered
argument_list|(
cast|static_cast
argument_list|<
name|QPinchGesture
operator|*
argument_list|>
argument_list|(
name|pinch
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [gesture event handler]
end_comment
begin_function
DECL|function|panTriggered
name|void
name|ImageWidget
operator|::
name|panTriggered
parameter_list|(
name|QPanGesture
modifier|*
name|gesture
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
switch|switch
condition|(
name|gesture
operator|->
name|state
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|GestureStarted
case|:
case|case
name|Qt
operator|::
name|GestureUpdated
case|:
name|setCursor
argument_list|(
name|Qt
operator|::
name|SizeAllCursor
argument_list|)
expr_stmt|;
break|break;
default|default:
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|QPointF
name|delta
init|=
name|gesture
operator|->
name|delta
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"panTriggered():"
operator|<<
name|gesture
expr_stmt|;
name|horizontalOffset
operator|+=
name|delta
operator|.
name|x
argument_list|()
expr_stmt|;
name|verticalOffset
operator|+=
name|delta
operator|.
name|y
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [pinch function]
end_comment
begin_function
DECL|function|pinchTriggered
name|void
name|ImageWidget
operator|::
name|pinchTriggered
parameter_list|(
name|QPinchGesture
modifier|*
name|gesture
parameter_list|)
block|{
name|QPinchGesture
operator|::
name|ChangeFlags
name|changeFlags
init|=
name|gesture
operator|->
name|changeFlags
argument_list|()
decl_stmt|;
if|if
condition|(
name|changeFlags
operator|&
name|QPinchGesture
operator|::
name|RotationAngleChanged
condition|)
block|{
name|qreal
name|rotationDelta
init|=
name|gesture
operator|->
name|rotationAngle
argument_list|()
operator|-
name|gesture
operator|->
name|lastRotationAngle
argument_list|()
decl_stmt|;
name|rotationAngle
operator|+=
name|rotationDelta
expr_stmt|;
name|qCDebug
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"pinchTriggered(): rotate by"
operator|<<
name|rotationDelta
operator|<<
literal|"->"
operator|<<
name|rotationAngle
expr_stmt|;
block|}
if|if
condition|(
name|changeFlags
operator|&
name|QPinchGesture
operator|::
name|ScaleFactorChanged
condition|)
block|{
name|currentStepScaleFactor
operator|=
name|gesture
operator|->
name|totalScaleFactor
argument_list|()
expr_stmt|;
name|qCDebug
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"pinchTriggered(): zoom by"
operator|<<
name|gesture
operator|->
name|scaleFactor
argument_list|()
operator|<<
literal|"->"
operator|<<
name|currentStepScaleFactor
expr_stmt|;
block|}
if|if
condition|(
name|gesture
operator|->
name|state
argument_list|()
operator|==
name|Qt
operator|::
name|GestureFinished
condition|)
block|{
name|scaleFactor
operator|*=
name|currentStepScaleFactor
expr_stmt|;
name|currentStepScaleFactor
operator|=
literal|1
expr_stmt|;
block|}
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [pinch function]
end_comment
begin_comment
comment|//! [swipe function]
end_comment
begin_function
DECL|function|swipeTriggered
name|void
name|ImageWidget
operator|::
name|swipeTriggered
parameter_list|(
name|QSwipeGesture
modifier|*
name|gesture
parameter_list|)
block|{
if|if
condition|(
name|gesture
operator|->
name|state
argument_list|()
operator|==
name|Qt
operator|::
name|GestureFinished
condition|)
block|{
if|if
condition|(
name|gesture
operator|->
name|horizontalDirection
argument_list|()
operator|==
name|QSwipeGesture
operator|::
name|Left
operator|||
name|gesture
operator|->
name|verticalDirection
argument_list|()
operator|==
name|QSwipeGesture
operator|::
name|Up
condition|)
block|{
name|qCDebug
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"swipeTriggered(): swipe to previous"
expr_stmt|;
name|goPrevImage
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|qCDebug
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"swipeTriggered(): swipe to next"
expr_stmt|;
name|goNextImage
argument_list|()
expr_stmt|;
block|}
name|update
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [swipe function]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|ImageWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openDirectory
name|void
name|ImageWidget
operator|::
name|openDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|this
operator|->
name|path
operator|=
name|path
expr_stmt|;
name|QDir
name|dir
argument_list|(
name|path
argument_list|)
decl_stmt|;
name|QStringList
name|nameFilters
decl_stmt|;
name|nameFilters
operator|<<
literal|"*.jpg"
operator|<<
literal|"*.png"
expr_stmt|;
name|files
operator|=
name|dir
operator|.
name|entryList
argument_list|(
name|nameFilters
argument_list|,
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Readable
argument_list|,
name|QDir
operator|::
name|Name
argument_list|)
expr_stmt|;
name|position
operator|=
literal|0
expr_stmt|;
name|goToImage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadImage
name|QImage
name|ImageWidget
operator|::
name|loadImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QImageReader
name|reader
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|reader
operator|.
name|setAutoTransform
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"loading"
operator|<<
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
operator|<<
name|position
operator|<<
literal|'/'
operator|<<
name|files
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|reader
operator|.
name|canRead
argument_list|()
condition|)
block|{
name|qCWarning
argument_list|(
name|lcExample
argument_list|)
operator|<<
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
operator|<<
literal|": can't load image"
expr_stmt|;
return|return
name|QImage
argument_list|()
return|;
block|}
name|QImage
name|image
decl_stmt|;
if|if
condition|(
operator|!
name|reader
operator|.
name|read
argument_list|(
operator|&
name|image
argument_list|)
condition|)
block|{
name|qCWarning
argument_list|(
name|lcExample
argument_list|)
operator|<<
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
operator|<<
literal|": corrupted image: "
operator|<<
name|reader
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return
name|QImage
argument_list|()
return|;
block|}
specifier|const
name|QSize
name|maximumSize
argument_list|(
literal|2000
argument_list|,
literal|2000
argument_list|)
decl_stmt|;
comment|// Reduce in case someone has large photo images.
if|if
condition|(
name|image
operator|.
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|>
name|maximumSize
operator|.
name|width
argument_list|()
operator|||
name|image
operator|.
name|height
argument_list|()
operator|>
name|maximumSize
operator|.
name|height
argument_list|()
condition|)
name|image
operator|=
name|image
operator|.
name|scaled
argument_list|(
name|maximumSize
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|,
name|Qt
operator|::
name|SmoothTransformation
argument_list|)
expr_stmt|;
return|return
name|image
return|;
block|}
end_function
begin_function
DECL|function|goNextImage
name|void
name|ImageWidget
operator|::
name|goNextImage
parameter_list|()
block|{
if|if
condition|(
name|files
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
name|position
operator|<
name|files
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|)
block|{
operator|++
name|position
expr_stmt|;
name|prevImage
operator|=
name|currentImage
expr_stmt|;
name|currentImage
operator|=
name|nextImage
expr_stmt|;
if|if
condition|(
name|position
operator|+
literal|1
operator|<
name|files
operator|.
name|size
argument_list|()
condition|)
name|nextImage
operator|=
name|loadImage
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|files
operator|.
name|at
argument_list|(
name|position
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|nextImage
operator|=
name|QImage
argument_list|()
expr_stmt|;
block|}
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|goPrevImage
name|void
name|ImageWidget
operator|::
name|goPrevImage
parameter_list|()
block|{
if|if
condition|(
name|files
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
name|position
operator|>
literal|0
condition|)
block|{
operator|--
name|position
expr_stmt|;
name|nextImage
operator|=
name|currentImage
expr_stmt|;
name|currentImage
operator|=
name|prevImage
expr_stmt|;
if|if
condition|(
name|position
operator|>
literal|0
condition|)
name|prevImage
operator|=
name|loadImage
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|files
operator|.
name|at
argument_list|(
name|position
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|prevImage
operator|=
name|QImage
argument_list|()
expr_stmt|;
block|}
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|goToImage
name|void
name|ImageWidget
operator|::
name|goToImage
parameter_list|(
name|int
name|index
parameter_list|)
block|{
if|if
condition|(
name|files
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
name|index
operator|<
literal|0
operator|||
name|index
operator|>=
name|files
operator|.
name|size
argument_list|()
condition|)
block|{
name|qCWarning
argument_list|(
name|lcExample
argument_list|)
operator|<<
literal|"goToImage: invalid index: "
operator|<<
name|index
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|index
operator|==
name|position
operator|+
literal|1
condition|)
block|{
name|goNextImage
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|position
operator|>
literal|0
operator|&&
name|index
operator|==
name|position
operator|-
literal|1
condition|)
block|{
name|goPrevImage
argument_list|()
expr_stmt|;
return|return;
block|}
name|position
operator|=
name|index
expr_stmt|;
if|if
condition|(
name|index
operator|>
literal|0
condition|)
name|prevImage
operator|=
name|loadImage
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|files
operator|.
name|at
argument_list|(
name|position
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|prevImage
operator|=
name|QImage
argument_list|()
expr_stmt|;
name|currentImage
operator|=
name|loadImage
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|files
operator|.
name|at
argument_list|(
name|position
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|position
operator|+
literal|1
operator|<
name|files
operator|.
name|size
argument_list|()
condition|)
name|nextImage
operator|=
name|loadImage
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|files
operator|.
name|at
argument_list|(
name|position
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|nextImage
operator|=
name|QImage
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
