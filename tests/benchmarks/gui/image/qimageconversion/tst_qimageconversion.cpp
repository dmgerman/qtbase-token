begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
argument|QImage
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
name|convertRgb888ToRGB32_data
parameter_list|()
function_decl|;
name|void
name|convertRgb888ToRGB32
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
block|}
class|;
end_class
begin_function
DECL|function|convertRgb888ToRGB32_data
name|void
name|tst_QImageConversion
operator|::
name|convertRgb888ToRGB32_data
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
literal|3
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
literal|"width: 2000px; height: 5000px;"
argument_list|)
operator|<<
name|generateImageRgb888
argument_list|(
literal|2000
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|convertRgb888ToRGB32
name|void
name|tst_QImageConversion
operator|::
name|convertRgb888ToRGB32
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
