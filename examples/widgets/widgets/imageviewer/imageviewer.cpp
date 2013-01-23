begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|<QPrintDialog>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"imageviewer.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ImageViewer
name|ImageViewer
operator|::
name|ImageViewer
parameter_list|()
block|{
name|imageLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|imageLabel
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
name|imageLabel
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
name|imageLabel
operator|->
name|setScaledContents
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|=
operator|new
name|QScrollArea
expr_stmt|;
name|scrollArea
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
expr_stmt|;
name|scrollArea
operator|->
name|setWidget
argument_list|(
name|imageLabel
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|scrollArea
argument_list|)
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Image Viewer"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|500
argument_list|,
literal|400
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|open
name|void
name|ImageViewer
operator|::
name|open
parameter_list|()
comment|//! [1] //! [2]
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open File"
argument_list|)
argument_list|,
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QImage
name|image
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Image Viewer"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot load %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|//! [2] //! [3]
name|imageLabel
operator|->
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
comment|//! [3] //! [4]
name|scaleFactor
operator|=
literal|1.0
expr_stmt|;
name|printAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|updateActions
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
condition|)
name|imageLabel
operator|->
name|adjustSize
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|print
name|void
name|ImageViewer
operator|::
name|print
parameter_list|()
comment|//! [5] //! [6]
block|{
name|Q_ASSERT
argument_list|(
name|imageLabel
operator|->
name|pixmap
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
comment|//! [6] //! [7]
name|QPrintDialog
name|dialog
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
comment|//! [7] //! [8]
if|if
condition|(
name|dialog
operator|.
name|exec
argument_list|()
condition|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|printer
argument_list|)
decl_stmt|;
name|QRect
name|rect
init|=
name|painter
operator|.
name|viewport
argument_list|()
decl_stmt|;
name|QSize
name|size
init|=
name|imageLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|size
argument_list|()
decl_stmt|;
name|size
operator|.
name|scale
argument_list|(
name|rect
operator|.
name|size
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setViewport
argument_list|(
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
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
expr_stmt|;
name|painter
operator|.
name|setWindow
argument_list|(
name|imageLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|*
name|imageLabel
operator|->
name|pixmap
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|zoomIn
name|void
name|ImageViewer
operator|::
name|zoomIn
parameter_list|()
comment|//! [9] //! [10]
block|{
name|scaleImage
argument_list|(
literal|1.25
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|zoomOut
name|void
name|ImageViewer
operator|::
name|zoomOut
parameter_list|()
block|{
name|scaleImage
argument_list|(
literal|0.8
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10] //! [11]
end_comment
begin_function
DECL|function|normalSize
name|void
name|ImageViewer
operator|::
name|normalSize
parameter_list|()
comment|//! [11] //! [12]
block|{
name|imageLabel
operator|->
name|adjustSize
argument_list|()
expr_stmt|;
name|scaleFactor
operator|=
literal|1.0
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|fitToWindow
name|void
name|ImageViewer
operator|::
name|fitToWindow
parameter_list|()
comment|//! [13] //! [14]
block|{
name|bool
name|fitToWindow
init|=
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
decl_stmt|;
name|scrollArea
operator|->
name|setWidgetResizable
argument_list|(
name|fitToWindow
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|fitToWindow
condition|)
block|{
name|normalSize
argument_list|()
expr_stmt|;
block|}
name|updateActions
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|about
name|void
name|ImageViewer
operator|::
name|about
parameter_list|()
comment|//! [15] //! [16]
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Image Viewer"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"<p>The<b>Image Viewer</b> example shows how to combine QLabel "
literal|"and QScrollArea to display an image. QLabel is typically used "
literal|"for displaying a text, but it can also display an image. "
literal|"QScrollArea provides a scrolling view around another widget. "
literal|"If the child widget exceeds the size of the frame, QScrollArea "
literal|"automatically provides scroll bars.</p><p>The example "
literal|"demonstrates how QLabel's ability to scale its contents "
literal|"(QLabel::scaledContents), and QScrollArea's ability to "
literal|"automatically resize its contents "
literal|"(QScrollArea::widgetResizable), can be used to implement "
literal|"zooming and scaling features.</p><p>In addition the example "
literal|"shows how to use QPainter to print an image.</p>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|createActions
name|void
name|ImageViewer
operator|::
name|createActions
parameter_list|()
comment|//! [17] //! [18]
block|{
name|openAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|openAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+O"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openAct
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
name|open
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|printAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Print..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|printAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+P"
argument_list|)
argument_list|)
expr_stmt|;
name|printAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|printAct
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
name|print
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
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|)
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
name|zoomInAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Zoom&In (25%)"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|zoomInAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl++"
argument_list|)
argument_list|)
expr_stmt|;
name|zoomInAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|zoomInAct
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
name|zoomIn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Zoom&Out (25%)"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+-"
argument_list|)
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|zoomOutAct
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
name|zoomOut
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|normalSizeAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Normal Size"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|normalSizeAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+S"
argument_list|)
argument_list|)
expr_stmt|;
name|normalSizeAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|normalSizeAct
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
name|normalSize
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Fit to Window"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+F"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fitToWindowAct
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
name|fitToWindow
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
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_function
DECL|function|createMenus
name|void
name|ImageViewer
operator|::
name|createMenus
parameter_list|()
comment|//! [19] //! [20]
block|{
name|fileMenu
operator|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|printAct
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
name|viewMenu
operator|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&View"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
name|zoomInAct
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
name|zoomOutAct
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
name|normalSizeAct
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|viewMenu
operator|->
name|addAction
argument_list|(
name|fitToWindowAct
argument_list|)
expr_stmt|;
name|helpMenu
operator|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|,
name|this
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
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|viewMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|helpMenu
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_function
DECL|function|updateActions
name|void
name|ImageViewer
operator|::
name|updateActions
parameter_list|()
comment|//! [21] //! [22]
block|{
name|zoomInAct
operator|->
name|setEnabled
argument_list|(
operator|!
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|->
name|setEnabled
argument_list|(
operator|!
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|normalSizeAct
operator|->
name|setEnabled
argument_list|(
operator|!
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_function
DECL|function|scaleImage
name|void
name|ImageViewer
operator|::
name|scaleImage
parameter_list|(
name|double
name|factor
parameter_list|)
comment|//! [23] //! [24]
block|{
name|Q_ASSERT
argument_list|(
name|imageLabel
operator|->
name|pixmap
argument_list|()
argument_list|)
expr_stmt|;
name|scaleFactor
operator|*=
name|factor
expr_stmt|;
name|imageLabel
operator|->
name|resize
argument_list|(
name|scaleFactor
operator|*
name|imageLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|adjustScrollBar
argument_list|(
name|scrollArea
operator|->
name|horizontalScrollBar
argument_list|()
argument_list|,
name|factor
argument_list|)
expr_stmt|;
name|adjustScrollBar
argument_list|(
name|scrollArea
operator|->
name|verticalScrollBar
argument_list|()
argument_list|,
name|factor
argument_list|)
expr_stmt|;
name|zoomInAct
operator|->
name|setEnabled
argument_list|(
name|scaleFactor
operator|<
literal|3.0
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|->
name|setEnabled
argument_list|(
name|scaleFactor
operator|>
literal|0.333
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_function
DECL|function|adjustScrollBar
name|void
name|ImageViewer
operator|::
name|adjustScrollBar
parameter_list|(
name|QScrollBar
modifier|*
name|scrollBar
parameter_list|,
name|double
name|factor
parameter_list|)
comment|//! [25] //! [26]
block|{
name|scrollBar
operator|->
name|setValue
argument_list|(
name|int
argument_list|(
name|factor
operator|*
name|scrollBar
operator|->
name|value
argument_list|()
operator|+
operator|(
operator|(
name|factor
operator|-
literal|1
operator|)
operator|*
name|scrollBar
operator|->
name|pageStep
argument_list|()
operator|/
literal|2
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [26]
end_comment
end_unit
