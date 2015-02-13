begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* viewer.cpp  Provides a main window for displaying a user-specified original image with three color separations in a grid layout.  A main menu provides entries for selecting files, and adjusting the brightness of the separations. */
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
begin_include
include|#
directive|include
file|"screenwidget.h"
end_include
begin_include
include|#
directive|include
file|"viewer.h"
end_include
begin_comment
comment|/*     Constructor: initializes a default value for the brightness, creates     the main menu entries, and constructs a central widget that contains     enough space for images to be displayed. */
end_comment
begin_constructor
DECL|function|Viewer
name|Viewer
operator|::
name|Viewer
parameter_list|()
block|{
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"QImage Color Separations"
argument_list|)
argument_list|)
expr_stmt|;
name|brightness
operator|=
literal|255
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|setCentralWidget
argument_list|(
name|createCentralWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*     Creates a main menu with two entries: a File menu, to allow the image     to be selected, and a Brightness menu to allow the brightness of the     separations to be changed.      Initially, the Brightness menu items are disabled, but the first entry in     the menu is checked to reflect the default brightness. */
end_comment
begin_function
DECL|function|createMenus
name|void
name|Viewer
operator|::
name|createMenus
parameter_list|()
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
name|brightnessMenu
operator|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Brightness"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|openAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|)
decl_stmt|;
name|openAction
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
literal|"Ctrl+O"
argument_list|)
argument_list|)
expr_stmt|;
name|saveAction
operator|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Save..."
argument_list|)
argument_list|)
expr_stmt|;
name|saveAction
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
literal|"Ctrl+S"
argument_list|)
argument_list|)
expr_stmt|;
name|saveAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|quitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
literal|"Ctrl+Q"
argument_list|)
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|noBrightness
init|=
name|brightnessMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&0%"
argument_list|)
argument_list|)
decl_stmt|;
name|noBrightness
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|quarterBrightness
init|=
name|brightnessMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&25%"
argument_list|)
argument_list|)
decl_stmt|;
name|quarterBrightness
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|halfBrightness
init|=
name|brightnessMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&50%"
argument_list|)
argument_list|)
decl_stmt|;
name|halfBrightness
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|threeQuartersBrightness
init|=
name|brightnessMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&75%"
argument_list|)
argument_list|)
decl_stmt|;
name|threeQuartersBrightness
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|fullBrightness
init|=
name|brightnessMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&100%"
argument_list|)
argument_list|)
decl_stmt|;
name|fullBrightness
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|menuMap
index|[
name|noBrightness
index|]
operator|=
name|None
expr_stmt|;
name|menuMap
index|[
name|quarterBrightness
index|]
operator|=
name|Quarter
expr_stmt|;
name|menuMap
index|[
name|halfBrightness
index|]
operator|=
name|Half
expr_stmt|;
name|menuMap
index|[
name|threeQuartersBrightness
index|]
operator|=
name|ThreeQuarters
expr_stmt|;
name|menuMap
index|[
name|fullBrightness
index|]
operator|=
name|Full
expr_stmt|;
name|currentBrightness
operator|=
name|fullBrightness
expr_stmt|;
name|currentBrightness
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|brightnessMenu
operator|->
name|setEnabled
argument_list|(
literal|false
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
name|brightnessMenu
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openAction
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
name|chooseFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAction
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
name|saveImage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitAction
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
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|brightnessMenu
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setBrightness
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Constructs a central widget for the window consisting of a two-by-two     grid of labels, each of which will contain an image. We restrict the     size of the labels to 256 pixels, and ensure that the window cannot     be resized. */
end_comment
begin_function
DECL|function|createCentralWidget
name|QFrame
modifier|*
name|Viewer
operator|::
name|createCentralWidget
parameter_list|()
block|{
name|QFrame
modifier|*
name|frame
init|=
operator|new
name|QFrame
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|grid
operator|=
operator|new
name|QGridLayout
argument_list|(
name|frame
argument_list|)
expr_stmt|;
name|grid
operator|->
name|setSpacing
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|grid
operator|->
name|setMargin
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|layout
argument_list|()
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetFixedSize
argument_list|)
expr_stmt|;
name|QSize
name|labelSize
argument_list|(
literal|256
argument_list|,
literal|256
argument_list|)
decl_stmt|;
name|finalWidget
operator|=
operator|new
name|FinalWidget
argument_list|(
name|frame
argument_list|,
name|tr
argument_list|(
literal|"Final image"
argument_list|)
argument_list|,
name|labelSize
argument_list|)
expr_stmt|;
name|cyanWidget
operator|=
operator|new
name|ScreenWidget
argument_list|(
name|frame
argument_list|,
name|Qt
operator|::
name|cyan
argument_list|,
name|tr
argument_list|(
literal|"Cyan"
argument_list|)
argument_list|,
name|ScreenWidget
operator|::
name|Cyan
argument_list|,
name|labelSize
argument_list|)
expr_stmt|;
name|magentaWidget
operator|=
operator|new
name|ScreenWidget
argument_list|(
name|frame
argument_list|,
name|Qt
operator|::
name|magenta
argument_list|,
name|tr
argument_list|(
literal|"Magenta"
argument_list|)
argument_list|,
name|ScreenWidget
operator|::
name|Magenta
argument_list|,
name|labelSize
argument_list|)
expr_stmt|;
name|yellowWidget
operator|=
operator|new
name|ScreenWidget
argument_list|(
name|frame
argument_list|,
name|Qt
operator|::
name|yellow
argument_list|,
name|tr
argument_list|(
literal|"Yellow"
argument_list|)
argument_list|,
name|ScreenWidget
operator|::
name|Yellow
argument_list|,
name|labelSize
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cyanWidget
argument_list|,
name|SIGNAL
argument_list|(
name|imageChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|createImage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|magentaWidget
argument_list|,
name|SIGNAL
argument_list|(
name|imageChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|createImage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|yellowWidget
argument_list|,
name|SIGNAL
argument_list|(
name|imageChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|createImage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|finalWidget
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignTop
operator||
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|cyanWidget
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignTop
operator||
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|magentaWidget
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignTop
operator||
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|yellowWidget
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignTop
operator||
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
return|return
name|frame
return|;
block|}
end_function
begin_comment
comment|/*     Provides a dialog window to allow the user to specify an image file.     If a file is selected, the appropriate function is called to process     and display it. */
end_comment
begin_function
DECL|function|chooseFile
name|void
name|Viewer
operator|::
name|chooseFile
parameter_list|()
block|{
name|QString
name|imageFile
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Choose an image file to open"
argument_list|)
argument_list|,
name|path
argument_list|,
name|tr
argument_list|(
literal|"Images (*.*)"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|imageFile
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|openImageFile
argument_list|(
name|imageFile
argument_list|)
expr_stmt|;
name|path
operator|=
name|imageFile
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*     Changes the value of the brightness according to the entry selected in the     Brightness menu. The selected entry is checked, and the previously selected     entry is unchecked.      The color separations are updated to use the new value for the brightness. */
end_comment
begin_function
DECL|function|setBrightness
name|void
name|Viewer
operator|::
name|setBrightness
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
block|{
if|if
condition|(
operator|!
name|menuMap
operator|.
name|contains
argument_list|(
name|action
argument_list|)
operator|||
name|scaledImage
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|Brightness
name|amount
init|=
name|menuMap
index|[
name|action
index|]
decl_stmt|;
switch|switch
condition|(
name|amount
condition|)
block|{
case|case
name|None
case|:
name|brightness
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|Quarter
case|:
name|brightness
operator|=
literal|64
expr_stmt|;
break|break;
case|case
name|Half
case|:
name|brightness
operator|=
literal|128
expr_stmt|;
break|break;
case|case
name|ThreeQuarters
case|:
name|brightness
operator|=
literal|191
expr_stmt|;
break|break;
case|case
name|Full
case|:
name|brightness
operator|=
literal|255
expr_stmt|;
break|break;
default|default:
return|return;
block|}
name|currentBrightness
operator|->
name|setChecked
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|currentBrightness
operator|=
name|action
expr_stmt|;
name|currentBrightness
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|createImage
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Load the image from the file given, and create four pixmaps based     on the original image.      The window caption is set, and the Brightness menu enabled if the image file     can be loaded. */
end_comment
begin_function
DECL|function|openImageFile
name|void
name|Viewer
operator|::
name|openImageFile
parameter_list|(
name|QString
modifier|&
name|imageFile
parameter_list|)
block|{
name|QImage
name|originalImage
decl_stmt|;
if|if
condition|(
name|originalImage
operator|.
name|load
argument_list|(
name|imageFile
argument_list|)
condition|)
block|{
name|setWindowTitle
argument_list|(
name|imageFile
argument_list|)
expr_stmt|;
comment|//menuBar()->setItemEnabled(brightnessMenuId, true);
name|saveAction
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|brightnessMenu
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|/* Note: the ScaleMin value may be different for Qt 4. */
name|scaledImage
operator|=
name|originalImage
operator|.
name|scaled
argument_list|(
literal|256
argument_list|,
literal|256
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|cyanWidget
operator|->
name|setImage
argument_list|(
name|scaledImage
argument_list|)
expr_stmt|;
name|magentaWidget
operator|->
name|setImage
argument_list|(
name|scaledImage
argument_list|)
expr_stmt|;
name|yellowWidget
operator|->
name|setImage
argument_list|(
name|scaledImage
argument_list|)
expr_stmt|;
name|createImage
argument_list|()
expr_stmt|;
block|}
else|else
operator|(
name|void
operator|)
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Cannot open file"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The selected file could not be opened."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Creates an image by combining the contents of the three screens     to present a page preview.      The image associated with each screen is separated into cyan,     magenta, and yellow components. We add up the values for each     component from the three screen images, and subtract the totals     from the maximum value for each corresponding primary color. */
end_comment
begin_function
DECL|function|createImage
name|void
name|Viewer
operator|::
name|createImage
parameter_list|()
block|{
name|QImage
name|newImage
init|=
name|scaledImage
operator|.
name|copy
argument_list|()
decl_stmt|;
name|QImage
modifier|*
name|image1
init|=
name|cyanWidget
operator|->
name|image
argument_list|()
decl_stmt|;
name|QImage
modifier|*
name|image2
init|=
name|magentaWidget
operator|->
name|image
argument_list|()
decl_stmt|;
name|QImage
modifier|*
name|image3
init|=
name|yellowWidget
operator|->
name|image
argument_list|()
decl_stmt|;
name|int
name|darkness
init|=
literal|255
operator|-
name|brightness
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|newImage
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|newImage
operator|.
name|width
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
comment|// Create three screens, using the quantities of the source
comment|// CMY components to determine how much of each of the
comment|// inks are to be put on each screen.
name|QRgb
name|p1
argument_list|(
name|image1
operator|->
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
decl_stmt|;
name|float
name|cyan1
init|=
literal|255
operator|-
name|qRed
argument_list|(
name|p1
argument_list|)
decl_stmt|;
name|float
name|magenta1
init|=
literal|255
operator|-
name|qGreen
argument_list|(
name|p1
argument_list|)
decl_stmt|;
name|float
name|yellow1
init|=
literal|255
operator|-
name|qBlue
argument_list|(
name|p1
argument_list|)
decl_stmt|;
name|QRgb
name|p2
argument_list|(
name|image2
operator|->
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
decl_stmt|;
name|float
name|cyan2
init|=
literal|255
operator|-
name|qRed
argument_list|(
name|p2
argument_list|)
decl_stmt|;
name|float
name|magenta2
init|=
literal|255
operator|-
name|qGreen
argument_list|(
name|p2
argument_list|)
decl_stmt|;
name|float
name|yellow2
init|=
literal|255
operator|-
name|qBlue
argument_list|(
name|p2
argument_list|)
decl_stmt|;
name|QRgb
name|p3
argument_list|(
name|image3
operator|->
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
decl_stmt|;
name|float
name|cyan3
init|=
literal|255
operator|-
name|qRed
argument_list|(
name|p3
argument_list|)
decl_stmt|;
name|float
name|magenta3
init|=
literal|255
operator|-
name|qGreen
argument_list|(
name|p3
argument_list|)
decl_stmt|;
name|float
name|yellow3
init|=
literal|255
operator|-
name|qBlue
argument_list|(
name|p3
argument_list|)
decl_stmt|;
name|QColor
name|newColor
argument_list|(
name|qMax
argument_list|(
literal|255
operator|-
name|int
argument_list|(
name|cyan1
operator|+
name|cyan2
operator|+
name|cyan3
argument_list|)
operator|-
name|darkness
argument_list|,
literal|0
argument_list|)
argument_list|,
name|qMax
argument_list|(
literal|255
operator|-
name|int
argument_list|(
name|magenta1
operator|+
name|magenta2
operator|+
name|magenta3
argument_list|)
operator|-
name|darkness
argument_list|,
literal|0
argument_list|)
argument_list|,
name|qMax
argument_list|(
literal|255
operator|-
name|int
argument_list|(
name|yellow1
operator|+
name|yellow2
operator|+
name|yellow3
argument_list|)
operator|-
name|darkness
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|newImage
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|newColor
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|finalWidget
operator|->
name|setPixmap
argument_list|(
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|newImage
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Provides a dialog window to allow the user to save the image file. */
end_comment
begin_function
DECL|function|saveImage
name|void
name|Viewer
operator|::
name|saveImage
parameter_list|()
block|{
name|QString
name|imageFile
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Choose a filename to save the image"
argument_list|)
argument_list|,
literal|""
argument_list|,
name|tr
argument_list|(
literal|"Images (*.png)"
argument_list|)
argument_list|)
decl_stmt|;
name|QFileInfo
name|info
argument_list|(
name|imageFile
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|info
operator|.
name|baseName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|newImageFile
init|=
name|QFileInfo
argument_list|(
name|info
operator|.
name|absoluteDir
argument_list|()
argument_list|,
name|info
operator|.
name|baseName
argument_list|()
operator|+
literal|".png"
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|finalWidget
operator|->
name|pixmap
argument_list|()
operator|->
name|save
argument_list|(
name|newImageFile
argument_list|,
literal|"PNG"
argument_list|)
condition|)
operator|(
name|void
operator|)
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Cannot save file"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The file could not be saved."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|)
expr_stmt|;
block|}
else|else
operator|(
name|void
operator|)
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Cannot save file"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Please enter a valid filename."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
