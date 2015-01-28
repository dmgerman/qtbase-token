begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QImage::Format
argument_list|)
end_macro
begin_class
DECL|class|tst_QImageConversion
class|class
name|tst_QImageConversion
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|convertRgb888ToRgb32_data
parameter_list|()
function_decl|;
name|void
name|convertRgb888ToRgb32
parameter_list|()
function_decl|;
name|void
name|convertRgb32ToRgb888_data
parameter_list|()
function_decl|;
name|void
name|convertRgb32ToRgb888
parameter_list|()
function_decl|;
name|void
name|convertGeneric_data
parameter_list|()
function_decl|;
name|void
name|convertGeneric
parameter_list|()
function_decl|;
private|private:
name|QImage
name|generateImageRgb888
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
name|QImage
name|generateImageRgb16
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
name|QImage
name|generateImageRgb32
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
name|QImage
name|generateImageArgb32
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|convertRgb888ToRgb32_data
name|void
name|tst_QImageConversion
operator|::
name|convertRgb888ToRgb32_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QImage
argument_list|>
argument_list|(
literal|"inputImage"
argument_list|)
expr_stmt|;
comment|// height = 5000 to get interesting timing.
comment|// 3 pixels wide -> smaller than regular vector of 128bits
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 3px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb888
argument_list|(
literal|3
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
comment|// 8 pixels wide -> potential for 2 vectors
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 8px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb888
argument_list|(
literal|8
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
comment|// 16 pixels, minimum for the SSSE3 implementation
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 16px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb888
argument_list|(
literal|16
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
comment|// 50 pixels, more realistic use case
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 50px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb888
argument_list|(
literal|50
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
comment|// 2000 pixels -> typical values for pictures
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 2000px; height: 2000px;"
argument_list|)
operator|<<
name|generateImageRgb888
argument_list|(
literal|2000
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|convertRgb888ToRgb32
name|void
name|tst_QImageConversion
operator|::
name|convertRgb888ToRgb32
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QImage
argument_list|,
name|inputImage
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
specifier|volatile
name|QImage
name|output
init|=
name|inputImage
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
comment|// we need the volatile and the following to make sure the compiler does not do
comment|// anything stupid :)
operator|(
name|void
operator|)
name|output
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|convertRgb32ToRgb888_data
name|void
name|tst_QImageConversion
operator|::
name|convertRgb32ToRgb888_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QImage
argument_list|>
argument_list|(
literal|"inputImage"
argument_list|)
expr_stmt|;
comment|// height = 5000 to get interesting timing.
comment|// 3 pixels wide -> smaller than regular vector of 128bits
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 3px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb32
argument_list|(
literal|3
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
comment|// 8 pixels wide -> potential for 2 vectors
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 8px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb32
argument_list|(
literal|8
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
comment|// 16 pixels, minimum for the SSSE3 implementation
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 16px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb32
argument_list|(
literal|16
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
comment|// 50 pixels, more realistic use case
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 50px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb32
argument_list|(
literal|50
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
comment|// 2000 pixels -> typical values for pictures
name|QTest
operator|::
name|newRow
argument_list|(
literal|"width: 2000px; height: 2000px;"
argument_list|)
operator|<<
name|generateImageRgb32
argument_list|(
literal|2000
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|convertRgb32ToRgb888
name|void
name|tst_QImageConversion
operator|::
name|convertRgb32ToRgb888
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QImage
argument_list|,
name|inputImage
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
specifier|volatile
name|QImage
name|output
init|=
name|inputImage
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB888
argument_list|)
decl_stmt|;
comment|// we need the volatile and the following to make sure the compiler does not do
comment|// anything stupid :)
operator|(
name|void
operator|)
name|output
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|convertGeneric_data
name|void
name|tst_QImageConversion
operator|::
name|convertGeneric_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QImage
argument_list|>
argument_list|(
literal|"inputImage"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QImage
operator|::
name|Format
argument_list|>
argument_list|(
literal|"outputFormat"
argument_list|)
expr_stmt|;
name|QImage
name|rgb16
init|=
name|generateImageRgb16
argument_list|(
literal|1000
argument_list|,
literal|1000
argument_list|)
decl_stmt|;
name|QImage
name|rgb32
init|=
name|generateImageRgb32
argument_list|(
literal|1000
argument_list|,
literal|1000
argument_list|)
decl_stmt|;
name|QImage
name|argb32
init|=
name|generateImageArgb32
argument_list|(
literal|1000
argument_list|,
literal|1000
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rgb16 -> rgb32"
argument_list|)
operator|<<
name|rgb16
operator|<<
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rgb16 -> rgb888"
argument_list|)
operator|<<
name|rgb16
operator|<<
name|QImage
operator|::
name|Format_RGB888
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rgb16 -> rgb666"
argument_list|)
operator|<<
name|rgb16
operator|<<
name|QImage
operator|::
name|Format_RGB666
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rgb16 -> rgb555"
argument_list|)
operator|<<
name|rgb16
operator|<<
name|QImage
operator|::
name|Format_RGB555
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rgb32 -> rgb16"
argument_list|)
operator|<<
name|rgb32
operator|<<
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rgb32 -> rgb888"
argument_list|)
operator|<<
name|rgb32
operator|<<
name|QImage
operator|::
name|Format_RGB888
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rgb32 -> rgb666"
argument_list|)
operator|<<
name|rgb32
operator|<<
name|QImage
operator|::
name|Format_RGB666
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rgb32 -> rgb555"
argument_list|)
operator|<<
name|rgb32
operator|<<
name|QImage
operator|::
name|Format_RGB555
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"argb32 -> rgba8888"
argument_list|)
operator|<<
name|argb32
operator|<<
name|QImage
operator|::
name|Format_RGBA8888
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"argb32 -> rgb888"
argument_list|)
operator|<<
name|argb32
operator|<<
name|QImage
operator|::
name|Format_RGB888
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"argb32 -> rgb666"
argument_list|)
operator|<<
name|argb32
operator|<<
name|QImage
operator|::
name|Format_RGB666
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"argb32 -> argb8565pm"
argument_list|)
operator|<<
name|argb32
operator|<<
name|QImage
operator|::
name|Format_ARGB8565_Premultiplied
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"argb32 -> argb4444pm"
argument_list|)
operator|<<
name|argb32
operator|<<
name|QImage
operator|::
name|Format_ARGB4444_Premultiplied
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"argb32 -> argb32pm"
argument_list|)
operator|<<
name|argb32
operator|<<
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"argb32 -> rgba8888pm"
argument_list|)
operator|<<
name|argb32
operator|<<
name|QImage
operator|::
name|Format_RGBA8888_Premultiplied
expr_stmt|;
block|}
end_function
begin_function
DECL|function|convertGeneric
name|void
name|tst_QImageConversion
operator|::
name|convertGeneric
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QImage
argument_list|,
name|inputImage
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QImage
operator|::
name|Format
argument_list|,
name|outputFormat
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QImage
name|output
init|=
name|inputImage
operator|.
name|convertToFormat
argument_list|(
name|outputFormat
argument_list|)
decl_stmt|;
name|output
operator|.
name|constBits
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*  Fill a RGB888 image with "random" pixel values.  */
end_comment
begin_function
DECL|function|generateImageRgb888
name|QImage
name|tst_QImageConversion
operator|::
name|generateImageRgb888
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QImage
name|image
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|QImage
operator|::
name|Format_RGB888
argument_list|)
decl_stmt|;
specifier|const
name|int
name|byteWidth
init|=
name|width
operator|*
literal|3
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
name|image
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|scanline
init|=
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|byteWidth
condition|;
operator|++
name|x
control|)
name|scanline
index|[
name|x
index|]
operator|=
name|x
operator|^
name|y
expr_stmt|;
block|}
return|return
name|image
return|;
block|}
end_function
begin_comment
comment|/*  Fill a RGB16 image with "random" pixel values.  */
end_comment
begin_function
DECL|function|generateImageRgb16
name|QImage
name|tst_QImageConversion
operator|::
name|generateImageRgb16
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QImage
name|image
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|QImage
operator|::
name|Format_RGB16
argument_list|)
decl_stmt|;
specifier|const
name|int
name|byteWidth
init|=
name|width
operator|*
literal|2
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
name|image
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|scanline
init|=
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|byteWidth
condition|;
operator|++
name|x
control|)
name|scanline
index|[
name|x
index|]
operator|=
name|x
operator|^
name|y
expr_stmt|;
block|}
return|return
name|image
return|;
block|}
end_function
begin_comment
comment|/*  Fill a RGB32 image with "random" pixel values.  */
end_comment
begin_function
DECL|function|generateImageRgb32
name|QImage
name|tst_QImageConversion
operator|::
name|generateImageRgb32
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QImage
name|image
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
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
name|image
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
name|QRgb
modifier|*
name|scanline
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
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|width
condition|;
operator|++
name|x
control|)
name|scanline
index|[
name|x
index|]
operator|=
name|qRgb
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|x
operator|^
name|y
argument_list|)
expr_stmt|;
block|}
return|return
name|image
return|;
block|}
end_function
begin_comment
comment|/*  Fill a ARGB32 image with "random" pixel values.  */
end_comment
begin_function
DECL|function|generateImageArgb32
name|QImage
name|tst_QImageConversion
operator|::
name|generateImageArgb32
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QImage
name|image
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
specifier|const
name|int
name|byteWidth
init|=
name|width
operator|*
literal|4
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
name|image
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|scanline
init|=
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|byteWidth
condition|;
operator|++
name|x
control|)
name|scanline
index|[
name|x
index|]
operator|=
name|x
operator|^
name|y
expr_stmt|;
block|}
return|return
name|image
return|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QImageConversion
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qimageconversion.moc"
end_include
end_unit
