begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QBitmap>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QImageReader>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_raster_p.h>
end_include
begin_class
DECL|class|tst_QPixmap
class|class
name|tst_QPixmap
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QPixmap
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|fill_data
parameter_list|()
function_decl|;
name|void
name|fill
parameter_list|()
function_decl|;
name|void
name|scaled_data
parameter_list|()
function_decl|;
name|void
name|scaled
parameter_list|()
function_decl|;
name|void
name|transformed_data
parameter_list|()
function_decl|;
name|void
name|transformed
parameter_list|()
function_decl|;
name|void
name|mask_data
parameter_list|()
function_decl|;
name|void
name|mask
parameter_list|()
function_decl|;
name|void
name|fromImageReader_data
parameter_list|()
function_decl|;
name|void
name|fromImageReader
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QImage::Format
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::AspectRatioMode
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::TransformationMode
argument_list|)
end_macro
begin_function
DECL|function|rasterPixmap
name|QPixmap
name|rasterPixmap
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QPlatformPixmap
modifier|*
name|data
init|=
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|QPlatformPixmap
operator|::
name|PixmapType
argument_list|)
decl_stmt|;
name|data
operator|->
name|resize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|(
name|data
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|rasterPixmap
name|QPixmap
name|rasterPixmap
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
return|return
name|rasterPixmap
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
return|;
block|}
end_function
begin_function
DECL|function|rasterPixmap
name|QPixmap
name|rasterPixmap
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|QPlatformPixmap
modifier|*
name|data
init|=
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|QPlatformPixmap
operator|::
name|PixmapType
argument_list|)
decl_stmt|;
name|data
operator|->
name|fromImage
argument_list|(
name|image
argument_list|,
name|Qt
operator|::
name|AutoColor
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|(
name|data
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|tst_QPixmap
name|tst_QPixmap
operator|::
name|tst_QPixmap
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|fill_data
name|void
name|tst_QPixmap
operator|::
name|fill_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"opaque"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"width"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"height"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"opaque 16x16"
argument_list|)
operator|<<
literal|true
operator|<<
literal|16
operator|<<
literal|16
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"!opaque 16x16"
argument_list|)
operator|<<
literal|false
operator|<<
literal|16
operator|<<
literal|16
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"opaque 587x128"
argument_list|)
operator|<<
literal|true
operator|<<
literal|587
operator|<<
literal|128
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"!opaque 587x128"
argument_list|)
operator|<<
literal|false
operator|<<
literal|587
operator|<<
literal|128
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fill
name|void
name|tst_QPixmap
operator|::
name|fill
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|opaque
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|width
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|height
argument_list|)
expr_stmt|;
specifier|const
name|QColor
name|color
init|=
name|opaque
condition|?
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
else|:
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|200
argument_list|)
decl_stmt|;
name|QPixmap
name|pixmap
init|=
name|rasterPixmap
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|pixmap
operator|.
name|fill
argument_list|(
name|color
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|scaled_data
name|void
name|tst_QPixmap
operator|::
name|scaled_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"scale"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|AspectRatioMode
argument_list|>
argument_list|(
literal|"ratioMode"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|TransformationMode
argument_list|>
argument_list|(
literal|"transformMode"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16x16 => 32x32"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|)
operator|<<
name|Qt
operator|::
name|IgnoreAspectRatio
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100x100 => 200x200"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
operator|<<
name|Qt
operator|::
name|IgnoreAspectRatio
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100x100 => 200x200"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
operator|<<
name|Qt
operator|::
name|IgnoreAspectRatio
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"80x80 => 200x200"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|137
argument_list|,
literal|137
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
operator|<<
name|Qt
operator|::
name|IgnoreAspectRatio
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scaled
name|void
name|tst_QPixmap
operator|::
name|scaled
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|scale
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|AspectRatioMode
argument_list|,
name|ratioMode
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|TransformationMode
argument_list|,
name|transformMode
argument_list|)
expr_stmt|;
name|QPixmap
name|opaque
init|=
name|rasterPixmap
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QPixmap
name|transparent
init|=
name|rasterPixmap
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|opaque
operator|.
name|fill
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|transparent
operator|.
name|fill
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|QPixmap
name|scaled1
decl_stmt|;
name|QPixmap
name|scaled2
decl_stmt|;
name|QBENCHMARK
block|{
name|scaled1
operator|=
name|opaque
operator|.
name|scaled
argument_list|(
name|scale
argument_list|,
name|ratioMode
argument_list|,
name|transformMode
argument_list|)
expr_stmt|;
name|scaled2
operator|=
name|transparent
operator|.
name|scaled
argument_list|(
name|scale
argument_list|,
name|ratioMode
argument_list|,
name|transformMode
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|transformed_data
name|void
name|tst_QPixmap
operator|::
name|transformed_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QTransform
argument_list|>
argument_list|(
literal|"transform"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|TransformationMode
argument_list|>
argument_list|(
literal|"transformMode"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16x16 rotate(90)"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16x16 rotate(199)"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|199
argument_list|)
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16x16 shear(2,1)"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16x16 rotate(199).shear(2,1)"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|199
argument_list|)
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100x100 rotate(90)"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100x100 rotate(199)"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|199
argument_list|)
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100x100 shear(2,1)"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100x100 shear(2,1) smooth"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|<<
name|Qt
operator|::
name|SmoothTransformation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100x100 rotate(199).shear(2,1)"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|199
argument_list|)
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|<<
name|Qt
operator|::
name|FastTransformation
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transformed
name|void
name|tst_QPixmap
operator|::
name|transformed
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|TransformationMode
argument_list|,
name|transformMode
argument_list|)
expr_stmt|;
name|QPixmap
name|opaque
init|=
name|rasterPixmap
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QPixmap
name|transparent
init|=
name|rasterPixmap
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|opaque
operator|.
name|fill
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|transparent
operator|.
name|fill
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|QPixmap
name|transformed1
decl_stmt|;
name|QPixmap
name|transformed2
decl_stmt|;
name|QBENCHMARK
block|{
name|transformed1
operator|=
name|opaque
operator|.
name|transformed
argument_list|(
name|transform
argument_list|,
name|transformMode
argument_list|)
expr_stmt|;
name|transformed2
operator|=
name|transparent
operator|.
name|transformed
argument_list|(
name|transform
argument_list|,
name|transformMode
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|mask_data
name|void
name|tst_QPixmap
operator|::
name|mask_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1x1"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"9x9"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16x16"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"128x128"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"333x333"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|333
argument_list|,
literal|333
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2048x128"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|2048
argument_list|,
literal|128
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mask
name|void
name|tst_QPixmap
operator|::
name|mask
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QPixmap
name|src
init|=
name|rasterPixmap
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|src
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|src
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|src
operator|.
name|width
argument_list|()
argument_list|,
name|src
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QBENCHMARK
block|{
name|QBitmap
name|bitmap
init|=
name|src
operator|.
name|mask
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|bitmap
operator|.
name|size
argument_list|()
operator|==
name|src
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fromImageReader_data
name|void
name|tst_QPixmap
operator|::
name|fromImageReader_data
parameter_list|()
block|{
specifier|const
name|QString
name|tempDir
init|=
name|QDir
operator|::
name|tempPath
argument_list|()
decl_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filename"
argument_list|)
expr_stmt|;
name|QImage
name|image
argument_list|(
literal|2000
argument_list|,
literal|2000
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
name|image
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|{
comment|// Generate an image with opaque and transparent pixels
comment|// with an interesting distribution.
name|QPainter
name|painter
argument_list|(
operator|&
name|image
argument_list|)
decl_stmt|;
name|QRadialGradient
name|radialGrad
argument_list|(
name|QPointF
argument_list|(
literal|1000
argument_list|,
literal|1000
argument_list|)
argument_list|,
literal|1000
argument_list|)
decl_stmt|;
name|radialGrad
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|radialGrad
operator|.
name|setColorAt
argument_list|(
literal|0.5
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|radialGrad
operator|.
name|setColorAt
argument_list|(
literal|0.9
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|radialGrad
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|image
operator|.
name|rect
argument_list|()
argument_list|,
name|radialGrad
argument_list|)
expr_stmt|;
block|}
name|image
operator|.
name|save
argument_list|(
literal|"test.png"
argument_list|)
expr_stmt|;
comment|// RGB32
specifier|const
name|QString
name|rgb32Path
init|=
name|tempDir
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/rgb32.jpg"
argument_list|)
decl_stmt|;
name|image
operator|.
name|save
argument_list|(
name|rgb32Path
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"gradient RGB32"
argument_list|)
operator|<<
name|rgb32Path
expr_stmt|;
comment|// ARGB32
specifier|const
name|QString
name|argb32Path
init|=
name|tempDir
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/argb32.png"
argument_list|)
decl_stmt|;
name|image
operator|.
name|save
argument_list|(
name|argb32Path
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"gradient ARGB32"
argument_list|)
operator|<<
name|argb32Path
expr_stmt|;
comment|// Indexed 8
specifier|const
name|QString
name|indexed8Path
init|=
name|tempDir
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/indexed8.gif"
argument_list|)
decl_stmt|;
name|image
operator|.
name|save
argument_list|(
name|indexed8Path
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"gradient indexed8"
argument_list|)
operator|<<
name|indexed8Path
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromImageReader
name|void
name|tst_QPixmap
operator|::
name|fromImageReader
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filename
argument_list|)
expr_stmt|;
comment|// warmup
block|{
name|QImageReader
name|imageReader
argument_list|(
name|filename
argument_list|)
decl_stmt|;
name|QPixmap
operator|::
name|fromImageReader
argument_list|(
operator|&
name|imageReader
argument_list|)
expr_stmt|;
block|}
name|QBENCHMARK
block|{
name|QImageReader
name|imageReader
argument_list|(
name|filename
argument_list|)
decl_stmt|;
name|QPixmap
operator|::
name|fromImageReader
argument_list|(
operator|&
name|imageReader
argument_list|)
expr_stmt|;
block|}
name|QFile
operator|::
name|remove
argument_list|(
name|filename
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPixmap
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpixmap.moc"
end_include
end_unit
