begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* finalwidget.cpp  A widget to display an image and a label containing a description. */
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"finalwidget.h"
end_include
begin_constructor
DECL|function|FinalWidget
name|FinalWidget
operator|::
name|FinalWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QSize
modifier|&
name|labelSize
parameter_list|)
member_init_list|:
name|QFrame
argument_list|(
name|parent
argument_list|)
block|{
name|hasImage
operator|=
literal|false
expr_stmt|;
name|imageLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|imageLabel
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|imageLabel
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|StyledPanel
argument_list|)
expr_stmt|;
name|imageLabel
operator|->
name|setMinimumSize
argument_list|(
name|labelSize
argument_list|)
expr_stmt|;
name|nameLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|imageLabel
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|nameLabel
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     If the mouse moves far enough when the left mouse button is held down,     start a drag and drop operation. */
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|FinalWidget
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|event
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
condition|)
return|return;
if|if
condition|(
operator|(
name|event
operator|->
name|pos
argument_list|()
operator|-
name|dragStartPosition
operator|)
operator|.
name|manhattanLength
argument_list|()
operator|<
name|QApplication
operator|::
name|startDragDistance
argument_list|()
condition|)
return|return;
if|if
condition|(
operator|!
name|hasImage
condition|)
return|return;
name|QDrag
modifier|*
name|drag
init|=
operator|new
name|QDrag
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QMimeData
modifier|*
name|mimeData
init|=
operator|new
name|QMimeData
decl_stmt|;
comment|//! [0]
name|QByteArray
name|output
decl_stmt|;
name|QBuffer
name|outputBuffer
argument_list|(
operator|&
name|output
argument_list|)
decl_stmt|;
name|outputBuffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|imageLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|toImage
argument_list|()
operator|.
name|save
argument_list|(
operator|&
name|outputBuffer
argument_list|,
literal|"PNG"
argument_list|)
expr_stmt|;
name|mimeData
operator|->
name|setData
argument_list|(
literal|"image/png"
argument_list|,
name|output
argument_list|)
expr_stmt|;
comment|//! [0]
comment|/* //! [1]     mimeData->setImageData(QVariant(*imageLabel->pixmap())); //! [1] */
name|drag
operator|->
name|setMimeData
argument_list|(
name|mimeData
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setPixmap
argument_list|(
name|imageLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|scaled
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
name|drag
operator|->
name|setHotSpot
argument_list|(
name|QPoint
argument_list|(
name|drag
operator|->
name|pixmap
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|drag
operator|->
name|pixmap
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
name|drag
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Check for left mouse button presses in order to enable drag and drop. */
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|FinalWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
name|dragStartPosition
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pixmap
specifier|const
name|QPixmap
modifier|*
name|FinalWidget
operator|::
name|pixmap
parameter_list|()
specifier|const
block|{
return|return
name|imageLabel
operator|->
name|pixmap
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setPixmap
name|void
name|FinalWidget
operator|::
name|setPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|imageLabel
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|hasImage
operator|=
literal|true
expr_stmt|;
block|}
end_function
end_unit
