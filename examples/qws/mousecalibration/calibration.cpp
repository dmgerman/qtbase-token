begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"calibration.h"
end_include
begin_include
include|#
directive|include
file|<QWSPointerCalibrationData>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QDesktopWidget>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QWSServer>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Calibration
name|Calibration
operator|::
name|Calibration
parameter_list|()
block|{
name|QRect
name|desktop
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|desktop
operator|.
name|moveTo
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|setGeometry
argument_list|(
name|desktop
argument_list|)
expr_stmt|;
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|setFocus
argument_list|()
expr_stmt|;
name|setModal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|int
name|width
init|=
name|qt_screen
operator|->
name|deviceWidth
argument_list|()
decl_stmt|;
name|int
name|height
init|=
name|qt_screen
operator|->
name|deviceHeight
argument_list|()
decl_stmt|;
name|int
name|dx
init|=
name|width
operator|/
literal|10
decl_stmt|;
name|int
name|dy
init|=
name|height
operator|/
literal|10
decl_stmt|;
name|QPoint
modifier|*
name|points
init|=
name|data
operator|.
name|screenPoints
decl_stmt|;
name|points
index|[
name|QWSPointerCalibrationData
operator|::
name|TopLeft
index|]
operator|=
name|QPoint
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
expr_stmt|;
name|points
index|[
name|QWSPointerCalibrationData
operator|::
name|BottomLeft
index|]
operator|=
name|QPoint
argument_list|(
name|dx
argument_list|,
name|height
operator|-
name|dy
argument_list|)
expr_stmt|;
name|points
index|[
name|QWSPointerCalibrationData
operator|::
name|BottomRight
index|]
operator|=
name|QPoint
argument_list|(
name|width
operator|-
name|dx
argument_list|,
name|height
operator|-
name|dy
argument_list|)
expr_stmt|;
name|points
index|[
name|QWSPointerCalibrationData
operator|::
name|TopRight
index|]
operator|=
name|QPoint
argument_list|(
name|width
operator|-
name|dx
argument_list|,
name|dy
argument_list|)
expr_stmt|;
name|points
index|[
name|QWSPointerCalibrationData
operator|::
name|Center
index|]
operator|=
name|QPoint
argument_list|(
name|width
operator|/
literal|2
argument_list|,
name|height
operator|/
literal|2
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|pressCount
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_destructor
DECL|function|~Calibration
name|Calibration
operator|::
name|~
name|Calibration
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|exec
name|int
name|Calibration
operator|::
name|exec
parameter_list|()
block|{
name|QWSServer
operator|::
name|mouseHandler
argument_list|()
operator|->
name|clearCalibration
argument_list|()
expr_stmt|;
name|grabMouse
argument_list|()
expr_stmt|;
name|activateWindow
argument_list|()
expr_stmt|;
name|int
name|ret
init|=
name|QDialog
operator|::
name|exec
argument_list|()
decl_stmt|;
name|releaseMouse
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|Calibration
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
name|p
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|QPoint
name|point
init|=
name|data
operator|.
name|screenPoints
index|[
name|pressCount
index|]
decl_stmt|;
comment|// Map to logical coordinates in case the screen is transformed
name|QSize
name|screenSize
argument_list|(
name|qt_screen
operator|->
name|deviceWidth
argument_list|()
argument_list|,
name|qt_screen
operator|->
name|deviceHeight
argument_list|()
argument_list|)
decl_stmt|;
name|point
operator|=
name|qt_screen
operator|->
name|mapFromDevice
argument_list|(
name|point
argument_list|,
name|screenSize
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|point
operator|.
name|x
argument_list|()
operator|-
literal|6
argument_list|,
name|point
operator|.
name|y
argument_list|()
operator|-
literal|1
argument_list|,
literal|13
argument_list|,
literal|3
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|point
operator|.
name|x
argument_list|()
operator|-
literal|1
argument_list|,
name|point
operator|.
name|y
argument_list|()
operator|-
literal|6
argument_list|,
literal|3
argument_list|,
literal|13
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|Calibration
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
comment|// Map from device coordinates in case the screen is transformed
name|QSize
name|screenSize
argument_list|(
name|qt_screen
operator|->
name|width
argument_list|()
argument_list|,
name|qt_screen
operator|->
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QPoint
name|p
init|=
name|qt_screen
operator|->
name|mapToDevice
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|,
name|screenSize
argument_list|)
decl_stmt|;
name|data
operator|.
name|devPoints
index|[
name|pressCount
index|]
operator|=
name|p
expr_stmt|;
if|if
condition|(
operator|++
name|pressCount
operator|<
literal|5
condition|)
name|repaint
argument_list|()
expr_stmt|;
else|else
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|accept
name|void
name|Calibration
operator|::
name|accept
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|pressCount
operator|==
literal|5
argument_list|)
expr_stmt|;
name|QWSServer
operator|::
name|mouseHandler
argument_list|()
operator|->
name|calibrate
argument_list|(
operator|&
name|data
argument_list|)
expr_stmt|;
name|QDialog
operator|::
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
end_unit
