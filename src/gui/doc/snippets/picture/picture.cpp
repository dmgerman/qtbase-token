begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|myProcessing
name|void
name|myProcessing
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|QWidget
name|myWidget
decl_stmt|;
block|{
comment|// RECORD
comment|//! [0]
name|QPicture
name|picture
decl_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|picture
argument_list|)
expr_stmt|;
comment|// paint in picture
name|painter
operator|.
name|drawEllipse
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|80
argument_list|,
literal|70
argument_list|)
expr_stmt|;
comment|// draw an ellipse
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
comment|// painting done
name|picture
operator|.
name|save
argument_list|(
literal|"drawing.pic"
argument_list|)
expr_stmt|;
comment|// save picture
comment|//! [0]
block|}
block|{
comment|// REPLAY
comment|//! [1]
name|QPicture
name|picture
decl_stmt|;
name|picture
operator|.
name|load
argument_list|(
literal|"drawing.pic"
argument_list|)
expr_stmt|;
comment|// load picture
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|myImage
argument_list|)
expr_stmt|;
comment|// paint in myImage
name|painter
operator|.
name|drawPicture
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|picture
argument_list|)
expr_stmt|;
comment|// draw the picture at (0,0)
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
comment|// painting done
comment|//! [1]
block|}
name|QPicture
name|myPicture
decl_stmt|;
block|{
comment|// FORMATS
comment|//! [2]
name|QStringList
name|list
init|=
name|QPicture
operator|::
name|inputFormatList
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|string
decl|,
name|list
control|)
name|myProcessing
argument_list|(
name|string
argument_list|)
expr_stmt|;
comment|//! [2]
block|}
block|{
comment|// OUTPUT
comment|//! [3]
name|QStringList
name|list
init|=
name|QPicture
operator|::
name|outputFormatList
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|string
decl|,
name|list
control|)
name|myProcessing
argument_list|(
name|string
argument_list|)
expr_stmt|;
comment|//! [3]
block|}
block|{
comment|// PIC READ
comment|//! [4]
name|QPictureIO
name|iio
decl_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
name|iio
operator|.
name|setFileName
argument_list|(
literal|"vegeburger.pic"
argument_list|)
expr_stmt|;
if|if
condition|(
name|iio
operator|.
name|read
argument_list|()
condition|)
block|{
comment|// OK
name|QPicture
name|picture
init|=
name|iio
operator|.
name|picture
argument_list|()
decl_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|pixmap
argument_list|)
decl_stmt|;
name|painter
operator|.
name|drawPicture
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|picture
argument_list|)
expr_stmt|;
block|}
comment|//! [4]
block|}
block|{
name|QPixmap
name|pixmap
decl_stmt|;
comment|// PIC WRITE
comment|//! [5]
name|QPictureIO
name|iio
decl_stmt|;
name|QPicture
name|picture
decl_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|picture
argument_list|)
decl_stmt|;
name|painter
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|iio
operator|.
name|setPicture
argument_list|(
name|picture
argument_list|)
expr_stmt|;
name|iio
operator|.
name|setFileName
argument_list|(
literal|"vegeburger.pic"
argument_list|)
expr_stmt|;
name|iio
operator|.
name|setFormat
argument_list|(
literal|"PIC"
argument_list|)
expr_stmt|;
if|if
condition|(
name|iio
operator|.
name|write
argument_list|()
condition|)
return|return
literal|true
return|;
comment|// returned true if written successfully
comment|//! [5]
block|}
block|}
end_function
begin_comment
comment|// SVG READ
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|readSVG
name|void
name|readSVG
parameter_list|(
name|QPictureIO
modifier|*
name|picture
parameter_list|)
block|{
comment|// read the picture using the picture->ioDevice()
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|// SVG WRITE
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|writeSVG
name|void
name|writeSVG
parameter_list|(
name|QPictureIO
modifier|*
name|picture
parameter_list|)
block|{
comment|// write the picture using the picture->ioDevice()
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|// USE SVG
end_comment
begin_function
DECL|function|foo
name|void
name|foo
parameter_list|()
block|{
comment|//! [8]
comment|// add the SVG picture handler
comment|// ...
comment|//! [8]
name|QPictureIO
operator|::
name|defineIOHandler
argument_list|(
literal|"SVG"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|readSVG
argument_list|,
name|writeSVG
argument_list|)
expr_stmt|;
comment|// ...
block|}
end_function
end_unit
