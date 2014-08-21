begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixelformat.h>
end_include
begin_class
DECL|class|tst_QPixelFormat
class|class
name|tst_QPixelFormat
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testOperators
parameter_list|()
function_decl|;
name|void
name|testQVectorOfFormats
parameter_list|()
function_decl|;
name|void
name|testRGB
parameter_list|()
function_decl|;
name|void
name|testCMYK
parameter_list|()
function_decl|;
name|void
name|testHSLandHSV
parameter_list|()
function_decl|;
name|void
name|testYUV_data
parameter_list|()
function_decl|;
name|void
name|testYUV
parameter_list|()
function_decl|;
name|void
name|testEnums
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testOperators
name|void
name|tst_QPixelFormat
operator|::
name|testOperators
parameter_list|()
block|{
name|QPixelFormat
name|first
init|=
name|qPixelFormatRgba
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|QPixelFormat
operator|::
name|UsesAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|Premultiplied
argument_list|)
decl_stmt|;
name|QPixelFormat
name|second
init|=
name|qPixelFormatRgba
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|QPixelFormat
operator|::
name|UsesAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|Premultiplied
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|first
operator|==
name|second
argument_list|)
expr_stmt|;
name|QPixelFormat
name|third
init|=
name|qPixelFormatRgba
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|QPixelFormat
operator|::
name|UsesAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtEnd
argument_list|,
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|first
operator|!=
name|third
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testQVectorOfFormats
name|void
name|tst_QPixelFormat
operator|::
name|testQVectorOfFormats
parameter_list|()
block|{
name|QVector
argument_list|<
name|QPixelFormat
argument_list|>
name|reallocedVector
decl_stmt|;
name|QVector
argument_list|<
name|QPixelFormat
argument_list|>
name|reservedVector
decl_stmt|;
name|reservedVector
operator|.
name|reserve
argument_list|(
name|QImage
operator|::
name|NImageFormats
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
operator|<
name|QImage
operator|::
name|NImageFormats
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|==
literal|0
operator|||
name|i
operator|==
literal|2
condition|)
comment|// skip invalid and monolsb
continue|continue;
name|QImage
operator|::
name|Format
name|image_format
init|=
cast|static_cast
argument_list|<
name|QImage
operator|::
name|Format
argument_list|>
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QPixelFormat
name|format
init|=
name|QImage
operator|::
name|toPixelFormat
argument_list|(
name|image_format
argument_list|)
decl_stmt|;
name|reallocedVector
operator|.
name|append
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|reservedVector
operator|.
name|append
argument_list|(
name|format
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|reallocedVector
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QCOMPARE
argument_list|(
name|reallocedVector
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|reservedVector
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|testRGB
name|void
name|tst_QPixelFormat
operator|::
name|testRGB
parameter_list|()
block|{
name|QPixelFormat
name|argb8888
init|=
name|qPixelFormatRgba
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|QPixelFormat
operator|::
name|UsesAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|Premultiplied
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|argb8888
operator|.
name|redSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|argb8888
operator|.
name|greenSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|argb8888
operator|.
name|blueSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|argb8888
operator|.
name|alphaSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|QPixelFormat
name|rgb565
init|=
name|qPixelFormatRgba
argument_list|(
literal|5
argument_list|,
literal|6
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|rgb565
operator|.
name|redSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rgb565
operator|.
name|greenSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rgb565
operator|.
name|blueSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rgb565
operator|.
name|alphaSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rgb565
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|16
argument_list|)
argument_list|)
expr_stmt|;
name|QPixelFormat
name|rgba1235
init|=
name|qPixelFormatRgba
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|,
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtEnd
argument_list|,
name|QPixelFormat
operator|::
name|Premultiplied
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|rgba1235
operator|.
name|redSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rgba1235
operator|.
name|greenSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rgba1235
operator|.
name|blueSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rgba1235
operator|.
name|alphaSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rgba1235
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|1
operator|+
literal|2
operator|+
literal|3
operator|+
literal|5
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testCMYK
name|void
name|tst_QPixelFormat
operator|::
name|testCMYK
parameter_list|()
block|{
name|QPixelFormat
name|cmyk6
init|=
name|qPixelFormatCmyk
argument_list|(
literal|6
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|cmyk6
operator|.
name|cyanSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cmyk6
operator|.
name|magentaSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cmyk6
operator|.
name|yellowSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cmyk6
operator|.
name|blackSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cmyk6
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|6
operator|*
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|QPixelFormat
name|cmykWithAlpha
init|=
name|qPixelFormatCmyk
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|cmykWithAlpha
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|8
operator|*
literal|5
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testHSLandHSV
name|void
name|tst_QPixelFormat
operator|::
name|testHSLandHSV
parameter_list|()
block|{
name|QPixelFormat
name|hsl
init|=
name|qPixelFormatHsl
argument_list|(
literal|3
argument_list|,
literal|5
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|hsl
operator|.
name|hueSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hsl
operator|.
name|saturationSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hsl
operator|.
name|lightnessSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hsl
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|3
operator|*
literal|3
operator|+
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QPixelFormat
name|hsv
init|=
name|qPixelFormatHsv
argument_list|(
literal|5
argument_list|,
literal|7
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|hsv
operator|.
name|hueSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hsv
operator|.
name|saturationSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hsv
operator|.
name|brightnessSize
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hsv
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|5
operator|*
literal|3
operator|+
literal|7
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QPixelFormat::YUVLayout
argument_list|)
end_macro
begin_function
DECL|function|testYUV_data
name|void
name|tst_QPixelFormat
operator|::
name|testYUV_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPixelFormat
operator|::
name|YUVLayout
argument_list|>
argument_list|(
literal|"yuv_layout"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout YUV444"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|YUV444
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout YUV422"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|YUV422
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout YUV411"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|YUV411
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout YUV420P"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|YUV420P
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout YUV420SP"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|YUV420SP
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout YV12"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|YV12
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout UYVY"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|UYVY
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout YUYV"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|YUYV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout NV12"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|NV12
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout NV21"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|NV21
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout IMC1"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|IMC1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout IMC2"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|IMC2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout IMC3"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|IMC3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout IMC4"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|IMC4
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout Y8"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|Y8
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"YUV Layout Y16"
argument_list|)
operator|<<
name|QPixelFormat
operator|::
name|Y16
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testYUV
name|void
name|tst_QPixelFormat
operator|::
name|testYUV
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPixelFormat
operator|::
name|YUVLayout
argument_list|,
name|yuv_layout
argument_list|)
expr_stmt|;
name|QPixelFormat
name|format
init|=
name|qPixelFormatYuv
argument_list|(
name|yuv_layout
argument_list|,
literal|0
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|yuv_layout
condition|)
block|{
case|case
name|QPixelFormat
operator|::
name|YUV444
case|:
name|QCOMPARE
argument_list|(
name|format
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|24
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|YUV422
case|:
name|QCOMPARE
argument_list|(
name|format
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|16
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|YUV411
case|:
case|case
name|QPixelFormat
operator|::
name|YUV420P
case|:
case|case
name|QPixelFormat
operator|::
name|YUV420SP
case|:
case|case
name|QPixelFormat
operator|::
name|YV12
case|:
name|QCOMPARE
argument_list|(
name|format
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|12
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|UYVY
case|:
case|case
name|QPixelFormat
operator|::
name|YUYV
case|:
name|QCOMPARE
argument_list|(
name|format
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|16
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|NV12
case|:
case|case
name|QPixelFormat
operator|::
name|NV21
case|:
name|QCOMPARE
argument_list|(
name|format
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|12
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|IMC1
case|:
case|case
name|QPixelFormat
operator|::
name|IMC2
case|:
case|case
name|QPixelFormat
operator|::
name|IMC3
case|:
case|case
name|QPixelFormat
operator|::
name|IMC4
case|:
name|QCOMPARE
argument_list|(
name|format
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|12
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|Y8
case|:
name|QCOMPARE
argument_list|(
name|format
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|8
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|Y16
case|:
name|QCOMPARE
argument_list|(
name|format
operator|.
name|bitsPerPixel
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|16
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|QVERIFY
argument_list|(
operator|!
literal|"the value stored for the yuvLayout is wrong!"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|testEnums
name|void
name|tst_QPixelFormat
operator|::
name|testEnums
parameter_list|()
block|{
name|QPixelFormat
name|allSet
init|=
name|QPixelFormat
argument_list|(
name|QPixelFormat
operator|::
name|BGR
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
name|QPixelFormat
operator|::
name|UsesAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtEnd
argument_list|,
name|QPixelFormat
operator|::
name|Premultiplied
argument_list|,
name|QPixelFormat
operator|::
name|FloatingPoint
argument_list|,
name|QPixelFormat
operator|::
name|BigEndian
argument_list|,
operator|(
literal|1
operator|<<
literal|6
operator|)
operator|-
literal|1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|allSet
operator|.
name|alphaUsage
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|UsesAlpha
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|allSet
operator|.
name|alphaPosition
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|AtEnd
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|allSet
operator|.
name|premultiplied
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|Premultiplied
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|allSet
operator|.
name|byteOrder
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|BigEndian
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|allSet
operator|.
name|typeInterpretation
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|FloatingPoint
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|allSet
operator|.
name|byteOrder
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|BigEndian
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|allSet
operator|.
name|subEnum
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|63
argument_list|)
argument_list|)
expr_stmt|;
name|QPixelFormat
name|nonSet
init|=
name|QPixelFormat
argument_list|(
name|QPixelFormat
operator|::
name|RGB
argument_list|,
literal|6
argument_list|,
literal|5
argument_list|,
literal|4
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|,
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|,
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|,
name|QPixelFormat
operator|::
name|UnsignedInteger
argument_list|,
name|QPixelFormat
operator|::
name|LittleEndian
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nonSet
operator|.
name|alphaUsage
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|IgnoresAlpha
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nonSet
operator|.
name|alphaPosition
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|AtBeginning
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nonSet
operator|.
name|premultiplied
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|NotPremultiplied
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nonSet
operator|.
name|byteOrder
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|LittleEndian
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nonSet
operator|.
name|typeInterpretation
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|UnsignedInteger
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nonSet
operator|.
name|byteOrder
argument_list|()
argument_list|,
name|QPixelFormat
operator|::
name|LittleEndian
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nonSet
operator|.
name|subEnum
argument_list|()
argument_list|,
name|uchar
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|<tst_qpixelformat.moc>
end_include
begin_expr_stmt
DECL|variable|tst_QPixelFormat
name|QTEST_MAIN
argument_list|(
name|tst_QPixelFormat
argument_list|)
expr_stmt|;
end_expr_stmt
end_unit
