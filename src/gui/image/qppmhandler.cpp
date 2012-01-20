begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"private/qppmhandler_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_PPM
end_ifndef
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*****************************************************************************   PBM/PGM/PPM (ASCII and RAW) image read/write functions  *****************************************************************************/
DECL|function|read_pbm_int
specifier|static
name|int
name|read_pbm_int
parameter_list|(
name|QIODevice
modifier|*
name|d
parameter_list|)
block|{
name|char
name|c
decl_stmt|;
name|int
name|val
init|=
operator|-
literal|1
decl_stmt|;
name|bool
name|digit
decl_stmt|;
specifier|const
name|int
name|buflen
init|=
literal|100
decl_stmt|;
name|char
name|buf
index|[
name|buflen
index|]
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|getChar
argument_list|(
operator|&
name|c
argument_list|)
condition|)
comment|// end of file
break|break;
name|digit
operator|=
name|isdigit
argument_list|(
operator|(
name|uchar
operator|)
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|digit
condition|)
block|{
name|val
operator|=
literal|10
operator|*
name|val
operator|+
name|c
operator|-
literal|'0'
expr_stmt|;
continue|continue;
block|}
else|else
block|{
if|if
condition|(
name|c
operator|==
literal|'#'
condition|)
comment|// comment
name|d
operator|->
name|readLine
argument_list|(
name|buf
argument_list|,
name|buflen
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|digit
condition|)
comment|// first digit
name|val
operator|=
name|c
operator|-
literal|'0'
expr_stmt|;
elseif|else
if|if
condition|(
name|isspace
argument_list|(
operator|(
name|uchar
operator|)
name|c
argument_list|)
condition|)
continue|continue;
elseif|else
if|if
condition|(
name|c
operator|==
literal|'#'
condition|)
operator|(
name|void
operator|)
name|d
operator|->
name|readLine
argument_list|(
name|buf
argument_list|,
name|buflen
argument_list|)
expr_stmt|;
else|else
break|break;
block|}
return|return
name|val
return|;
block|}
end_function
begin_function
DECL|function|read_pbm_header
specifier|static
name|bool
name|read_pbm_header
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
name|char
modifier|&
name|type
parameter_list|,
name|int
modifier|&
name|w
parameter_list|,
name|int
modifier|&
name|h
parameter_list|,
name|int
modifier|&
name|mcc
parameter_list|)
block|{
name|char
name|buf
index|[
literal|3
index|]
decl_stmt|;
if|if
condition|(
name|device
operator|->
name|read
argument_list|(
name|buf
argument_list|,
literal|3
argument_list|)
operator|!=
literal|3
condition|)
comment|// read P[1-6]<white-space>
return|return
literal|false
return|;
if|if
condition|(
operator|!
operator|(
name|buf
index|[
literal|0
index|]
operator|==
literal|'P'
operator|&&
name|isdigit
argument_list|(
operator|(
name|uchar
operator|)
name|buf
index|[
literal|1
index|]
argument_list|)
operator|&&
name|isspace
argument_list|(
operator|(
name|uchar
operator|)
name|buf
index|[
literal|2
index|]
argument_list|)
operator|)
condition|)
return|return
literal|false
return|;
name|type
operator|=
name|buf
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|type
argument_list|<
literal|'1'
operator|||
name|type
argument_list|>
literal|'6'
condition|)
return|return
literal|false
return|;
name|w
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
expr_stmt|;
comment|// get image width
name|h
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
expr_stmt|;
comment|// get image height
if|if
condition|(
name|type
operator|==
literal|'1'
operator|||
name|type
operator|==
literal|'4'
condition|)
name|mcc
operator|=
literal|1
expr_stmt|;
comment|// ignore max color component
else|else
name|mcc
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
expr_stmt|;
comment|// get max color component
if|if
condition|(
name|w
operator|<=
literal|0
operator|||
name|w
operator|>
literal|32767
operator|||
name|h
operator|<=
literal|0
operator|||
name|h
operator|>
literal|32767
operator|||
name|mcc
operator|<=
literal|0
condition|)
return|return
literal|false
return|;
comment|// weird P.M image
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|read_pbm_body
specifier|static
name|bool
name|read_pbm_body
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
name|char
name|type
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|mcc
parameter_list|,
name|QImage
modifier|*
name|outImage
parameter_list|)
block|{
name|int
name|nbits
decl_stmt|,
name|y
decl_stmt|;
name|int
name|pbm_bpl
decl_stmt|;
name|bool
name|raw
decl_stmt|;
name|QImage
operator|::
name|Format
name|format
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
literal|'1'
case|:
comment|// ascii PBM
case|case
literal|'4'
case|:
comment|// raw PBM
name|nbits
operator|=
literal|1
expr_stmt|;
name|format
operator|=
name|QImage
operator|::
name|Format_Mono
expr_stmt|;
break|break;
case|case
literal|'2'
case|:
comment|// ascii PGM
case|case
literal|'5'
case|:
comment|// raw PGM
name|nbits
operator|=
literal|8
expr_stmt|;
name|format
operator|=
name|QImage
operator|::
name|Format_Indexed8
expr_stmt|;
break|break;
case|case
literal|'3'
case|:
comment|// ascii PPM
case|case
literal|'6'
case|:
comment|// raw PPM
name|nbits
operator|=
literal|32
expr_stmt|;
name|format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
break|break;
default|default:
return|return
literal|false
return|;
block|}
name|raw
operator|=
name|type
operator|>=
literal|'4'
expr_stmt|;
name|int
name|maxc
init|=
name|mcc
decl_stmt|;
if|if
condition|(
name|maxc
operator|>
literal|255
condition|)
name|maxc
operator|=
literal|255
expr_stmt|;
if|if
condition|(
name|outImage
operator|->
name|size
argument_list|()
operator|!=
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
operator|||
name|outImage
operator|->
name|format
argument_list|()
operator|!=
name|format
condition|)
block|{
operator|*
name|outImage
operator|=
name|QImage
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
name|outImage
operator|->
name|isNull
argument_list|()
condition|)
return|return
literal|false
return|;
block|}
name|pbm_bpl
operator|=
operator|(
name|nbits
operator|*
name|w
operator|+
literal|7
operator|)
operator|/
literal|8
expr_stmt|;
comment|// bytes per scanline in PBM
if|if
condition|(
name|raw
condition|)
block|{
comment|// read raw data
if|if
condition|(
name|nbits
operator|==
literal|32
condition|)
block|{
comment|// type 6
name|pbm_bpl
operator|=
name|mcc
operator|<
literal|256
condition|?
literal|3
operator|*
name|w
else|:
literal|6
operator|*
name|w
expr_stmt|;
name|uchar
modifier|*
name|buf24
init|=
operator|new
name|uchar
index|[
name|pbm_bpl
index|]
decl_stmt|,
modifier|*
name|b
decl_stmt|;
name|QRgb
modifier|*
name|p
decl_stmt|;
name|QRgb
modifier|*
name|end
decl_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
name|y
operator|++
control|)
block|{
if|if
condition|(
name|device
operator|->
name|read
argument_list|(
operator|(
name|char
operator|*
operator|)
name|buf24
argument_list|,
name|pbm_bpl
argument_list|)
operator|!=
name|pbm_bpl
condition|)
block|{
operator|delete
index|[]
name|buf24
expr_stmt|;
return|return
literal|false
return|;
block|}
name|p
operator|=
operator|(
name|QRgb
operator|*
operator|)
name|outImage
operator|->
name|scanLine
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|end
operator|=
name|p
operator|+
name|w
expr_stmt|;
name|b
operator|=
name|buf24
expr_stmt|;
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
if|if
condition|(
name|mcc
operator|<
literal|256
condition|)
block|{
operator|*
name|p
operator|++
operator|=
name|qRgb
argument_list|(
name|b
index|[
literal|0
index|]
argument_list|,
name|b
index|[
literal|1
index|]
argument_list|,
name|b
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|b
operator|+=
literal|3
expr_stmt|;
block|}
else|else
block|{
operator|*
name|p
operator|++
operator|=
name|qRgb
argument_list|(
operator|(
operator|(
name|int
argument_list|(
name|b
index|[
literal|0
index|]
argument_list|)
operator|*
literal|256
operator|+
name|int
argument_list|(
name|b
index|[
literal|1
index|]
argument_list|)
operator|+
literal|1
operator|)
operator|*
literal|256
operator|)
operator|/
operator|(
name|mcc
operator|+
literal|1
operator|)
operator|-
literal|1
argument_list|,
operator|(
operator|(
name|int
argument_list|(
name|b
index|[
literal|2
index|]
argument_list|)
operator|*
literal|256
operator|+
name|int
argument_list|(
name|b
index|[
literal|3
index|]
argument_list|)
operator|+
literal|1
operator|)
operator|*
literal|256
operator|)
operator|/
operator|(
name|mcc
operator|+
literal|1
operator|)
operator|-
literal|1
argument_list|,
operator|(
operator|(
name|int
argument_list|(
name|b
index|[
literal|4
index|]
argument_list|)
operator|*
literal|256
operator|+
name|int
argument_list|(
name|b
index|[
literal|5
index|]
argument_list|)
operator|+
literal|1
operator|)
operator|*
literal|256
operator|)
operator|/
operator|(
name|mcc
operator|+
literal|1
operator|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|b
operator|+=
literal|6
expr_stmt|;
block|}
block|}
block|}
operator|delete
index|[]
name|buf24
expr_stmt|;
block|}
else|else
block|{
comment|// type 4,5
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
name|y
operator|++
control|)
block|{
if|if
condition|(
name|device
operator|->
name|read
argument_list|(
operator|(
name|char
operator|*
operator|)
name|outImage
operator|->
name|scanLine
argument_list|(
name|y
argument_list|)
argument_list|,
name|pbm_bpl
argument_list|)
operator|!=
name|pbm_bpl
condition|)
return|return
literal|false
return|;
block|}
block|}
block|}
else|else
block|{
comment|// read ascii data
specifier|register
name|uchar
modifier|*
name|p
decl_stmt|;
name|int
name|n
decl_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
name|y
operator|++
control|)
block|{
name|p
operator|=
name|outImage
operator|->
name|scanLine
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|n
operator|=
name|pbm_bpl
expr_stmt|;
if|if
condition|(
name|nbits
operator|==
literal|1
condition|)
block|{
name|int
name|b
decl_stmt|;
name|int
name|bitsLeft
init|=
name|w
decl_stmt|;
while|while
condition|(
name|n
operator|--
condition|)
block|{
name|b
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|<
name|bitsLeft
condition|)
name|b
operator|=
operator|(
name|b
operator|<<
literal|1
operator|)
operator||
operator|(
name|read_pbm_int
argument_list|(
name|device
argument_list|)
operator|&
literal|1
operator|)
expr_stmt|;
else|else
name|b
operator|=
operator|(
name|b
operator|<<
literal|1
operator|)
operator||
operator|(
literal|0
operator|&
literal|1
operator|)
expr_stmt|;
comment|// pad it our self if we need to
block|}
name|bitsLeft
operator|-=
literal|8
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|b
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|nbits
operator|==
literal|8
condition|)
block|{
if|if
condition|(
name|mcc
operator|==
name|maxc
condition|)
block|{
while|while
condition|(
name|n
operator|--
condition|)
block|{
operator|*
name|p
operator|++
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
while|while
condition|(
name|n
operator|--
condition|)
block|{
operator|*
name|p
operator|++
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
operator|*
name|maxc
operator|/
name|mcc
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|// 32 bits
name|n
operator|/=
literal|4
expr_stmt|;
name|int
name|r
decl_stmt|,
name|g
decl_stmt|,
name|b
decl_stmt|;
if|if
condition|(
name|mcc
operator|==
name|maxc
condition|)
block|{
while|while
condition|(
name|n
operator|--
condition|)
block|{
name|r
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
expr_stmt|;
name|g
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
expr_stmt|;
name|b
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
expr_stmt|;
operator|*
operator|(
operator|(
name|QRgb
operator|*
operator|)
name|p
operator|)
operator|=
name|qRgb
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|p
operator|+=
literal|4
expr_stmt|;
block|}
block|}
else|else
block|{
while|while
condition|(
name|n
operator|--
condition|)
block|{
name|r
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
operator|*
name|maxc
operator|/
name|mcc
expr_stmt|;
name|g
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
operator|*
name|maxc
operator|/
name|mcc
expr_stmt|;
name|b
operator|=
name|read_pbm_int
argument_list|(
name|device
argument_list|)
operator|*
name|maxc
operator|/
name|mcc
expr_stmt|;
operator|*
operator|(
operator|(
name|QRgb
operator|*
operator|)
name|p
operator|)
operator|=
name|qRgb
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|p
operator|+=
literal|4
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
if|if
condition|(
name|nbits
operator|==
literal|1
condition|)
block|{
comment|// bitmap
name|outImage
operator|->
name|setColorCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|outImage
operator|->
name|setColor
argument_list|(
literal|0
argument_list|,
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
comment|// white
name|outImage
operator|->
name|setColor
argument_list|(
literal|1
argument_list|,
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// black
block|}
elseif|else
if|if
condition|(
name|nbits
operator|==
literal|8
condition|)
block|{
comment|// graymap
name|outImage
operator|->
name|setColorCount
argument_list|(
name|maxc
operator|+
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|maxc
condition|;
name|i
operator|++
control|)
name|outImage
operator|->
name|setColor
argument_list|(
name|i
argument_list|,
name|qRgb
argument_list|(
name|i
operator|*
literal|255
operator|/
name|maxc
argument_list|,
name|i
operator|*
literal|255
operator|/
name|maxc
argument_list|,
name|i
operator|*
literal|255
operator|/
name|maxc
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|write_pbm_image
specifier|static
name|bool
name|write_pbm_image
parameter_list|(
name|QIODevice
modifier|*
name|out
parameter_list|,
specifier|const
name|QImage
modifier|&
name|sourceImage
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|sourceFormat
parameter_list|)
block|{
name|QByteArray
name|str
decl_stmt|;
name|QImage
name|image
init|=
name|sourceImage
decl_stmt|;
name|QByteArray
name|format
init|=
name|sourceFormat
decl_stmt|;
name|format
operator|=
name|format
operator|.
name|left
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|// ignore RAW part
name|bool
name|gray
init|=
name|format
operator|==
literal|"pgm"
decl_stmt|;
if|if
condition|(
name|format
operator|==
literal|"pbm"
condition|)
block|{
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_Mono
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|image
operator|.
name|depth
argument_list|()
operator|==
literal|1
condition|)
block|{
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_Indexed8
argument_list|)
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
name|image
operator|.
name|format
argument_list|()
condition|)
block|{
case|case
name|QImage
operator|::
name|Format_RGB16
case|:
case|case
name|QImage
operator|::
name|Format_RGB666
case|:
case|case
name|QImage
operator|::
name|Format_RGB555
case|:
case|case
name|QImage
operator|::
name|Format_RGB888
case|:
case|case
name|QImage
operator|::
name|Format_RGB444
case|:
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_ARGB8565_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB6666_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB8555_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB4444_Premultiplied
case|:
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
if|if
condition|(
name|image
operator|.
name|depth
argument_list|()
operator|==
literal|1
operator|&&
name|image
operator|.
name|colorCount
argument_list|()
operator|==
literal|2
condition|)
block|{
if|if
condition|(
name|qGray
argument_list|(
name|image
operator|.
name|color
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<
name|qGray
argument_list|(
name|image
operator|.
name|color
argument_list|(
literal|1
argument_list|)
argument_list|)
condition|)
block|{
comment|// 0=dark/black, 1=light/white - invert
name|image
operator|.
name|detach
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|image
operator|.
name|height
argument_list|()
condition|;
name|y
operator|++
control|)
block|{
name|uchar
modifier|*
name|p
init|=
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|end
init|=
name|p
operator|+
name|image
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|<
name|end
condition|)
operator|*
name|p
operator|++
operator|^=
literal|0xff
expr_stmt|;
block|}
block|}
block|}
name|uint
name|w
init|=
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
name|uint
name|h
init|=
name|image
operator|.
name|height
argument_list|()
decl_stmt|;
name|str
operator|=
literal|"P\n"
expr_stmt|;
name|str
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|' '
expr_stmt|;
name|str
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|h
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|'\n'
expr_stmt|;
switch|switch
condition|(
name|image
operator|.
name|depth
argument_list|()
condition|)
block|{
case|case
literal|1
case|:
block|{
name|str
operator|.
name|insert
argument_list|(
literal|1
argument_list|,
literal|'4'
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
operator|->
name|write
argument_list|(
name|str
argument_list|,
name|str
operator|.
name|length
argument_list|()
argument_list|)
operator|!=
name|str
operator|.
name|length
argument_list|()
condition|)
return|return
literal|false
return|;
name|w
operator|=
operator|(
name|w
operator|+
literal|7
operator|)
operator|/
literal|8
expr_stmt|;
for|for
control|(
name|uint
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
name|y
operator|++
control|)
block|{
name|uchar
modifier|*
name|line
init|=
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
if|if
condition|(
name|w
operator|!=
operator|(
name|uint
operator|)
name|out
operator|->
name|write
argument_list|(
operator|(
name|char
operator|*
operator|)
name|line
argument_list|,
name|w
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
block|}
break|break;
case|case
literal|8
case|:
block|{
name|str
operator|.
name|insert
argument_list|(
literal|1
argument_list|,
name|gray
condition|?
literal|'5'
else|:
literal|'6'
argument_list|)
expr_stmt|;
name|str
operator|.
name|append
argument_list|(
literal|"255\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
operator|->
name|write
argument_list|(
name|str
argument_list|,
name|str
operator|.
name|length
argument_list|()
argument_list|)
operator|!=
name|str
operator|.
name|length
argument_list|()
condition|)
return|return
literal|false
return|;
name|QVector
argument_list|<
name|QRgb
argument_list|>
name|color
init|=
name|image
operator|.
name|colorTable
argument_list|()
decl_stmt|;
name|uint
name|bpl
init|=
name|w
operator|*
operator|(
name|gray
condition|?
literal|1
else|:
literal|3
operator|)
decl_stmt|;
name|uchar
modifier|*
name|buf
init|=
operator|new
name|uchar
index|[
name|bpl
index|]
decl_stmt|;
for|for
control|(
name|uint
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
name|y
operator|++
control|)
block|{
name|uchar
modifier|*
name|b
init|=
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|uchar
modifier|*
name|end
init|=
name|buf
operator|+
name|bpl
decl_stmt|;
if|if
condition|(
name|gray
condition|)
block|{
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
name|uchar
name|g
init|=
operator|(
name|uchar
operator|)
name|qGray
argument_list|(
name|color
index|[
operator|*
name|b
operator|++
index|]
argument_list|)
decl_stmt|;
operator|*
name|p
operator|++
operator|=
name|g
expr_stmt|;
block|}
block|}
else|else
block|{
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
name|QRgb
name|rgb
init|=
name|color
index|[
operator|*
name|b
operator|++
index|]
decl_stmt|;
operator|*
name|p
operator|++
operator|=
name|qRed
argument_list|(
name|rgb
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|qGreen
argument_list|(
name|rgb
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|qBlue
argument_list|(
name|rgb
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|bpl
operator|!=
operator|(
name|uint
operator|)
name|out
operator|->
name|write
argument_list|(
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
name|bpl
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
operator|delete
index|[]
name|buf
expr_stmt|;
block|}
break|break;
case|case
literal|32
case|:
block|{
name|str
operator|.
name|insert
argument_list|(
literal|1
argument_list|,
name|gray
condition|?
literal|'5'
else|:
literal|'6'
argument_list|)
expr_stmt|;
name|str
operator|.
name|append
argument_list|(
literal|"255\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
operator|->
name|write
argument_list|(
name|str
argument_list|,
name|str
operator|.
name|length
argument_list|()
argument_list|)
operator|!=
name|str
operator|.
name|length
argument_list|()
condition|)
return|return
literal|false
return|;
name|uint
name|bpl
init|=
name|w
operator|*
operator|(
name|gray
condition|?
literal|1
else|:
literal|3
operator|)
decl_stmt|;
name|uchar
modifier|*
name|buf
init|=
operator|new
name|uchar
index|[
name|bpl
index|]
decl_stmt|;
for|for
control|(
name|uint
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
name|y
operator|++
control|)
block|{
name|QRgb
modifier|*
name|b
init|=
operator|(
name|QRgb
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|uchar
modifier|*
name|end
init|=
name|buf
operator|+
name|bpl
decl_stmt|;
if|if
condition|(
name|gray
condition|)
block|{
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
name|uchar
name|g
init|=
operator|(
name|uchar
operator|)
name|qGray
argument_list|(
operator|*
name|b
operator|++
argument_list|)
decl_stmt|;
operator|*
name|p
operator|++
operator|=
name|g
expr_stmt|;
block|}
block|}
else|else
block|{
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
name|QRgb
name|rgb
init|=
operator|*
name|b
operator|++
decl_stmt|;
operator|*
name|p
operator|++
operator|=
name|qRed
argument_list|(
name|rgb
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|qGreen
argument_list|(
name|rgb
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|qBlue
argument_list|(
name|rgb
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|bpl
operator|!=
operator|(
name|uint
operator|)
name|out
operator|->
name|write
argument_list|(
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
name|bpl
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
operator|delete
index|[]
name|buf
expr_stmt|;
block|}
break|break;
default|default:
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_constructor
DECL|function|QPpmHandler
name|QPpmHandler
operator|::
name|QPpmHandler
parameter_list|()
member_init_list|:
name|state
argument_list|(
name|Ready
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|readHeader
name|bool
name|QPpmHandler
operator|::
name|readHeader
parameter_list|()
block|{
name|state
operator|=
name|Error
expr_stmt|;
if|if
condition|(
operator|!
name|read_pbm_header
argument_list|(
name|device
argument_list|()
argument_list|,
name|type
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|mcc
argument_list|)
condition|)
return|return
literal|false
return|;
name|state
operator|=
name|ReadHeader
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|canRead
name|bool
name|QPpmHandler
operator|::
name|canRead
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|state
operator|==
name|Ready
operator|&&
operator|!
name|canRead
argument_list|(
name|device
argument_list|()
argument_list|,
operator|&
name|subType
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|state
operator|!=
name|Error
condition|)
block|{
name|setFormat
argument_list|(
name|subType
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|canRead
name|bool
name|QPpmHandler
operator|::
name|canRead
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
name|QByteArray
modifier|*
name|subType
parameter_list|)
block|{
if|if
condition|(
operator|!
name|device
condition|)
block|{
name|qWarning
argument_list|(
literal|"QPpmHandler::canRead() called with no device"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|char
name|head
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|device
operator|->
name|peek
argument_list|(
name|head
argument_list|,
sizeof|sizeof
argument_list|(
name|head
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|head
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|head
index|[
literal|0
index|]
operator|!=
literal|'P'
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|head
index|[
literal|1
index|]
operator|==
literal|'1'
operator|||
name|head
index|[
literal|1
index|]
operator|==
literal|'4'
condition|)
block|{
if|if
condition|(
name|subType
condition|)
operator|*
name|subType
operator|=
literal|"pbm"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|head
index|[
literal|1
index|]
operator|==
literal|'2'
operator|||
name|head
index|[
literal|1
index|]
operator|==
literal|'5'
condition|)
block|{
if|if
condition|(
name|subType
condition|)
operator|*
name|subType
operator|=
literal|"pgm"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|head
index|[
literal|1
index|]
operator|==
literal|'3'
operator|||
name|head
index|[
literal|1
index|]
operator|==
literal|'6'
condition|)
block|{
if|if
condition|(
name|subType
condition|)
operator|*
name|subType
operator|=
literal|"ppm"
expr_stmt|;
block|}
else|else
block|{
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|read
name|bool
name|QPpmHandler
operator|::
name|read
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|)
block|{
if|if
condition|(
name|state
operator|==
name|Error
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|state
operator|==
name|Ready
operator|&&
operator|!
name|readHeader
argument_list|()
condition|)
block|{
name|state
operator|=
name|Error
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|read_pbm_body
argument_list|(
name|device
argument_list|()
argument_list|,
name|type
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|mcc
argument_list|,
name|image
argument_list|)
condition|)
block|{
name|state
operator|=
name|Error
expr_stmt|;
return|return
literal|false
return|;
block|}
name|state
operator|=
name|Ready
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|write
name|bool
name|QPpmHandler
operator|::
name|write
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
return|return
name|write_pbm_image
argument_list|(
name|device
argument_list|()
argument_list|,
name|image
argument_list|,
name|subType
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportsOption
name|bool
name|QPpmHandler
operator|::
name|supportsOption
parameter_list|(
name|ImageOption
name|option
parameter_list|)
specifier|const
block|{
return|return
name|option
operator|==
name|SubType
operator|||
name|option
operator|==
name|Size
operator|||
name|option
operator|==
name|ImageFormat
return|;
block|}
end_function
begin_function
DECL|function|option
name|QVariant
name|QPpmHandler
operator|::
name|option
parameter_list|(
name|ImageOption
name|option
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|option
operator|==
name|SubType
condition|)
block|{
return|return
name|subType
return|;
block|}
elseif|else
if|if
condition|(
name|option
operator|==
name|Size
condition|)
block|{
if|if
condition|(
name|state
operator|==
name|Error
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|state
operator|==
name|Ready
operator|&&
operator|!
cast|const_cast
argument_list|<
name|QPpmHandler
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|readHeader
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
return|return
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|option
operator|==
name|ImageFormat
condition|)
block|{
if|if
condition|(
name|state
operator|==
name|Error
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|state
operator|==
name|Ready
operator|&&
operator|!
cast|const_cast
argument_list|<
name|QPpmHandler
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|readHeader
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
name|QImage
operator|::
name|Format
name|format
init|=
name|QImage
operator|::
name|Format_Invalid
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
literal|'1'
case|:
comment|// ascii PBM
case|case
literal|'4'
case|:
comment|// raw PBM
name|format
operator|=
name|QImage
operator|::
name|Format_Mono
expr_stmt|;
break|break;
case|case
literal|'2'
case|:
comment|// ascii PGM
case|case
literal|'5'
case|:
comment|// raw PGM
name|format
operator|=
name|QImage
operator|::
name|Format_Indexed8
expr_stmt|;
break|break;
case|case
literal|'3'
case|:
comment|// ascii PPM
case|case
literal|'6'
case|:
comment|// raw PPM
name|format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|format
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setOption
name|void
name|QPpmHandler
operator|::
name|setOption
parameter_list|(
name|ImageOption
name|option
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|option
operator|==
name|SubType
condition|)
name|subType
operator|=
name|value
operator|.
name|toByteArray
argument_list|()
operator|.
name|toLower
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|name
name|QByteArray
name|QPpmHandler
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|subType
operator|.
name|isEmpty
argument_list|()
condition|?
name|QByteArray
argument_list|(
literal|"ppm"
argument_list|)
else|:
name|subType
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_IMAGEFORMAT_PPM
end_comment
end_unit
