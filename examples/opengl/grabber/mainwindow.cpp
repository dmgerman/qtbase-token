begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_include
include|#
directive|include
file|"glwidget.h"
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|centralWidget
operator|=
operator|new
name|QWidget
expr_stmt|;
name|setCentralWidget
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|glWidget
operator|=
operator|new
name|GLWidget
expr_stmt|;
name|pixmapLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|glWidgetArea
operator|=
operator|new
name|QScrollArea
expr_stmt|;
name|glWidgetArea
operator|->
name|setWidget
argument_list|(
name|glWidget
argument_list|)
expr_stmt|;
name|glWidgetArea
operator|->
name|setWidgetResizable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|glWidgetArea
operator|->
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|glWidgetArea
operator|->
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|glWidgetArea
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
expr_stmt|;
name|glWidgetArea
operator|->
name|setMinimumSize
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|pixmapLabelArea
operator|=
operator|new
name|QScrollArea
expr_stmt|;
name|pixmapLabelArea
operator|->
name|setWidget
argument_list|(
name|pixmapLabel
argument_list|)
expr_stmt|;
name|pixmapLabelArea
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
expr_stmt|;
name|pixmapLabelArea
operator|->
name|setMinimumSize
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|xSlider
operator|=
name|createSlider
argument_list|(
name|SIGNAL
argument_list|(
name|xRotationChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|setXRotation
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ySlider
operator|=
name|createSlider
argument_list|(
name|SIGNAL
argument_list|(
name|yRotationChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|setYRotation
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|zSlider
operator|=
name|createSlider
argument_list|(
name|SIGNAL
argument_list|(
name|zRotationChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|setZRotation
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|QGridLayout
modifier|*
name|centralLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|centralLayout
operator|->
name|addWidget
argument_list|(
name|glWidgetArea
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|centralLayout
operator|->
name|addWidget
argument_list|(
name|pixmapLabelArea
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|centralLayout
operator|->
name|addWidget
argument_list|(
name|xSlider
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|centralLayout
operator|->
name|addWidget
argument_list|(
name|ySlider
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|centralLayout
operator|->
name|addWidget
argument_list|(
name|zSlider
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|centralWidget
operator|->
name|setLayout
argument_list|(
name|centralLayout
argument_list|)
expr_stmt|;
name|xSlider
operator|->
name|setValue
argument_list|(
literal|15
operator|*
literal|16
argument_list|)
expr_stmt|;
name|ySlider
operator|->
name|setValue
argument_list|(
literal|345
operator|*
literal|16
argument_list|)
expr_stmt|;
name|zSlider
operator|->
name|setValue
argument_list|(
literal|0
operator|*
literal|16
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Grabber"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|renderIntoPixmap
name|void
name|MainWindow
operator|::
name|renderIntoPixmap
parameter_list|()
block|{
name|QSize
name|size
init|=
name|getSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|size
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QPixmap
name|pixmap
init|=
name|glWidget
operator|->
name|renderPixmap
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
argument_list|)
decl_stmt|;
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|grabFrameBuffer
name|void
name|MainWindow
operator|::
name|grabFrameBuffer
parameter_list|()
block|{
name|QImage
name|image
init|=
name|glWidget
operator|->
name|grabFrameBuffer
argument_list|()
decl_stmt|;
name|setPixmap
argument_list|(
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearPixmap
name|void
name|MainWindow
operator|::
name|clearPixmap
parameter_list|()
block|{
name|setPixmap
argument_list|(
name|QPixmap
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Grabber"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>Grabber</b> example demonstrates two approaches for "
literal|"rendering OpenGL into a Qt pixmap."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
block|{
name|renderIntoPixmapAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Render into Pixmap..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|renderIntoPixmapAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+R"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|renderIntoPixmapAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|renderIntoPixmap
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|grabFrameBufferAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Grab Frame Buffer"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|grabFrameBufferAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+G"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|grabFrameBufferAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|grabFrameBuffer
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|clearPixmapAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Clear Pixmap"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|clearPixmapAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+L"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|clearPixmapAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|clearPixmap
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|exitAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|exitAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|about
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutQtAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQtAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
block|{
name|fileMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|renderIntoPixmapAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|grabFrameBufferAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|clearPixmapAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAct
argument_list|)
expr_stmt|;
name|helpMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutAct
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQtAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createSlider
name|QSlider
modifier|*
name|MainWindow
operator|::
name|createSlider
parameter_list|(
specifier|const
name|char
modifier|*
name|changedSignal
parameter_list|,
specifier|const
name|char
modifier|*
name|setterSlot
parameter_list|)
block|{
name|QSlider
modifier|*
name|slider
init|=
operator|new
name|QSlider
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
decl_stmt|;
name|slider
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|360
operator|*
literal|16
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setSingleStep
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setPageStep
argument_list|(
literal|15
operator|*
literal|16
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setTickInterval
argument_list|(
literal|15
operator|*
literal|16
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksRight
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|slider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|glWidget
argument_list|,
name|setterSlot
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|glWidget
argument_list|,
name|changedSignal
argument_list|,
name|slider
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|slider
return|;
block|}
end_function
begin_function
DECL|function|setPixmap
name|void
name|MainWindow
operator|::
name|setPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|pixmapLabel
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|pixmap
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|size
operator|-
name|QSize
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|==
name|pixmapLabelArea
operator|->
name|maximumViewportSize
argument_list|()
condition|)
name|size
operator|-=
name|QSize
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pixmapLabel
operator|->
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getSize
name|QSize
name|MainWindow
operator|::
name|getSize
parameter_list|()
block|{
name|bool
name|ok
decl_stmt|;
name|QString
name|text
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Grabber"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Enter pixmap size:"
argument_list|)
argument_list|,
name|QLineEdit
operator|::
name|Normal
argument_list|,
name|tr
argument_list|(
literal|"%1 x %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|glWidget
operator|->
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|glWidget
operator|->
name|height
argument_list|()
argument_list|)
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return
name|QSize
argument_list|()
return|;
name|QRegExp
name|regExp
argument_list|(
name|tr
argument_list|(
literal|"([0-9]+) *x *([0-9]+)"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|regExp
operator|.
name|exactMatch
argument_list|(
name|text
argument_list|)
condition|)
block|{
name|int
name|width
init|=
name|regExp
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|int
name|height
init|=
name|regExp
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|width
operator|>
literal|0
operator|&&
name|width
argument_list|<
literal|2048
operator|&&
name|height
argument_list|>
literal|0
operator|&&
name|height
operator|<
literal|2048
condition|)
return|return
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
return|;
block|}
return|return
name|glWidget
operator|->
name|size
argument_list|()
return|;
block|}
end_function
end_unit
