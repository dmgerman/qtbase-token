begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_function
DECL|function|paint
name|void
name|paint
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|device
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|device
operator|->
name|width
argument_list|()
argument_list|,
name|device
operator|->
name|height
argument_list|()
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QLinearGradient
name|g
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
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
decl_stmt|;
comment|//    g.setCoordinateMode(QGradient::ObjectBoundingMode);
name|g
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|magenta
argument_list|)
expr_stmt|;
name|g
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
comment|//    p.setOpacity(0.8);
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|g
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|setOpacity
argument_list|(
literal|0.9
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawEllipse
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|device
operator|->
name|width
argument_list|()
argument_list|,
name|device
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|compositionModes
name|QLatin1String
name|compositionModes
index|[]
init|=
block|{
name|QLatin1String
argument_list|(
literal|"SourceOver"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"DestinationOver"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Clear"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Source"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Destination"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"SourceIn"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"DestinationIn"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"SourceOut"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"DestinationOut"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"SourceAtop"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"DestinationAtop"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Xor"
argument_list|)
block|,
comment|//svg 1.2 blend modes
name|QLatin1String
argument_list|(
literal|"Plus"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Multiply"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Screen"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Overlay"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Darken"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Lighten"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"ColorDodge"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"ColorBurn"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"HardLight"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"SoftLight"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Difference"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"Exclusion"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_enum
DECL|enum|BrushType
DECL|enumerator|ImageBrush
DECL|enumerator|SolidBrush
enum|enum
name|BrushType
block|{
name|ImageBrush
block|,
name|SolidBrush
block|}
enum|;
end_enum
begin_decl_stmt
DECL|variable|brushTypes
name|QLatin1String
name|brushTypes
index|[]
init|=
block|{
name|QLatin1String
argument_list|(
literal|"ImageBrush"
argument_list|)
block|,
name|QLatin1String
argument_list|(
literal|"SolidBrush"
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|BlendBench
class|class
name|BlendBench
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|blendBench_data
parameter_list|()
function_decl|;
name|void
name|blendBench
parameter_list|()
function_decl|;
name|void
name|blendBenchAlpha_data
parameter_list|()
function_decl|;
name|void
name|blendBenchAlpha
parameter_list|()
function_decl|;
name|void
name|unalignedBlendArgb32_data
parameter_list|()
function_decl|;
name|void
name|unalignedBlendArgb32
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|blendBench_data
name|void
name|BlendBench
operator|::
name|blendBench_data
parameter_list|()
block|{
name|int
name|first
init|=
literal|0
decl_stmt|;
name|int
name|limit
init|=
literal|12
decl_stmt|;
if|if
condition|(
name|qApp
operator|->
name|arguments
argument_list|()
operator|.
name|contains
argument_list|(
literal|"--extended"
argument_list|)
condition|)
block|{
name|first
operator|=
literal|12
expr_stmt|;
name|limit
operator|=
literal|24
expr_stmt|;
block|}
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"brushType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"compositionMode"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|brush
init|=
name|ImageBrush
init|;
name|brush
operator|<=
name|SolidBrush
condition|;
operator|++
name|brush
control|)
for|for
control|(
name|int
name|mode
init|=
name|first
init|;
name|mode
operator|<
name|limit
condition|;
operator|++
name|mode
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|QString
argument_list|(
literal|"brush=%1; mode=%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|brushTypes
index|[
name|brush
index|]
argument_list|)
operator|.
name|arg
argument_list|(
name|compositionModes
index|[
name|mode
index|]
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
operator|<<
name|brush
operator|<<
name|mode
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blendBench
name|void
name|BlendBench
operator|::
name|blendBench
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|brushType
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|compositionMode
argument_list|)
expr_stmt|;
name|QImage
name|img
argument_list|(
literal|512
argument_list|,
literal|512
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|QImage
name|src
argument_list|(
literal|512
argument_list|,
literal|512
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|paint
argument_list|(
operator|&
name|src
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode
argument_list|(
name|compositionMode
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|brushType
operator|==
name|ImageBrush
condition|)
block|{
name|p
operator|.
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|src
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|brushType
operator|==
name|SolidBrush
condition|)
block|{
name|p
operator|.
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|127
argument_list|,
literal|127
argument_list|,
literal|127
argument_list|,
literal|127
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QBENCHMARK
block|{
name|p
operator|.
name|drawRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|512
argument_list|,
literal|512
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|blendBenchAlpha_data
name|void
name|BlendBench
operator|::
name|blendBenchAlpha_data
parameter_list|()
block|{
name|blendBench_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blendBenchAlpha
name|void
name|BlendBench
operator|::
name|blendBenchAlpha
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|brushType
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|compositionMode
argument_list|)
expr_stmt|;
name|QImage
name|img
argument_list|(
literal|512
argument_list|,
literal|512
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|QImage
name|src
argument_list|(
literal|512
argument_list|,
literal|512
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|paint
argument_list|(
operator|&
name|src
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode
argument_list|(
name|compositionMode
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|brushType
operator|==
name|ImageBrush
condition|)
block|{
name|p
operator|.
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|src
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|brushType
operator|==
name|SolidBrush
condition|)
block|{
name|p
operator|.
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|127
argument_list|,
literal|127
argument_list|,
literal|127
argument_list|,
literal|127
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|p
operator|.
name|setOpacity
argument_list|(
literal|0.7f
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|p
operator|.
name|drawRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|512
argument_list|,
literal|512
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|unalignedBlendArgb32_data
name|void
name|BlendBench
operator|::
name|unalignedBlendArgb32_data
parameter_list|()
block|{
comment|// The performance of blending can depend of the alignment of the data
comment|// on 16 bytes. Some SIMD instruction set have significantly better
comment|// memory access when the memory is aligned on 16 bytes boundary.
comment|// offset in 32 bits words
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"offset"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"aligned on 16 bytes"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unaligned by 4 bytes"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unaligned by 8 bytes"
argument_list|)
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unaligned by 12 bytes"
argument_list|)
operator|<<
literal|3
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unalignedBlendArgb32
name|void
name|BlendBench
operator|::
name|unalignedBlendArgb32
parameter_list|()
block|{
specifier|const
name|int
name|dimension
init|=
literal|1024
decl_stmt|;
comment|// We use dst aligned by design. We don't want to test all the combination of alignemnt for src and dst.
comment|// Moreover, it make sense for us to align dst in the implementation because it is accessed more often.
name|uchar
modifier|*
name|dstMemory
init|=
cast|static_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|qMallocAligned
argument_list|(
operator|(
name|dimension
operator|*
name|dimension
operator|*
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
operator|)
argument_list|,
literal|16
argument_list|)
argument_list|)
decl_stmt|;
name|QImage
name|destination
argument_list|(
name|dstMemory
argument_list|,
name|dimension
argument_list|,
name|dimension
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|destination
operator|.
name|fill
argument_list|(
literal|0x12345678
argument_list|)
expr_stmt|;
comment|// avoid special cases of alpha
name|uchar
modifier|*
name|srcMemory
init|=
cast|static_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|qMallocAligned
argument_list|(
operator|(
name|dimension
operator|*
name|dimension
operator|*
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
operator|)
operator|+
literal|16
argument_list|,
literal|16
argument_list|)
argument_list|)
decl_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|offset
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|imageSrcMemory
init|=
name|srcMemory
operator|+
operator|(
name|offset
operator|*
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
operator|)
decl_stmt|;
name|QImage
name|src
argument_list|(
name|imageSrcMemory
argument_list|,
name|dimension
argument_list|,
name|dimension
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|src
operator|.
name|fill
argument_list|(
literal|0x87654321
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|destination
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|painter
operator|.
name|drawImage
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|src
argument_list|)
expr_stmt|;
block|}
name|qFreeAligned
argument_list|(
name|srcMemory
argument_list|)
expr_stmt|;
name|qFreeAligned
argument_list|(
name|dstMemory
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|BlendBench
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
