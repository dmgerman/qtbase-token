begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIMAGE_P_H
end_ifndef
begin_define
DECL|macro|QIMAGE_P_H
define|#
directive|define
name|QIMAGE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QImageWriter
name|class
name|QImageWriter
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QImageData
struct|struct
name|Q_GUI_EXPORT
name|QImageData
block|{
comment|// internal image data
name|QImageData
argument_list|()
expr_stmt|;
operator|~
name|QImageData
argument_list|()
expr_stmt|;
specifier|static
name|QImageData
modifier|*
name|create
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|QImage
operator|::
name|Format
name|format
argument_list|,
name|int
name|numColors
operator|=
literal|0
argument_list|)
decl_stmt|;
specifier|static
name|QImageData
modifier|*
name|create
argument_list|(
name|uchar
operator|*
name|data
argument_list|,
name|int
name|w
argument_list|,
name|int
name|h
argument_list|,
name|int
name|bpl
argument_list|,
name|QImage
operator|::
name|Format
name|format
argument_list|,
name|bool
name|readOnly
argument_list|,
name|QImageCleanupFunction
name|cleanupFunction
operator|=
literal|0
argument_list|,
name|void
operator|*
name|cleanupInfo
operator|=
literal|0
argument_list|)
decl_stmt|;
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|width
name|int
name|width
decl_stmt|;
DECL|member|height
name|int
name|height
decl_stmt|;
DECL|member|depth
name|int
name|depth
decl_stmt|;
DECL|member|nbytes
name|int
name|nbytes
decl_stmt|;
comment|// number of bytes data
DECL|member|devicePixelRatio
name|qreal
name|devicePixelRatio
decl_stmt|;
DECL|member|colortable
name|QVector
operator|<
name|QRgb
operator|>
name|colortable
expr_stmt|;
DECL|member|data
name|uchar
modifier|*
name|data
decl_stmt|;
DECL|member|format
name|QImage
operator|::
name|Format
name|format
expr_stmt|;
DECL|member|bytes_per_line
name|int
name|bytes_per_line
decl_stmt|;
DECL|member|ser_no
name|int
name|ser_no
decl_stmt|;
comment|// serial number
DECL|member|detach_no
name|int
name|detach_no
decl_stmt|;
DECL|member|dpmx
name|qreal
name|dpmx
decl_stmt|;
comment|// dots per meter X (or 0)
DECL|member|dpmy
name|qreal
name|dpmy
decl_stmt|;
comment|// dots per meter Y (or 0)
DECL|member|offset
name|QPoint
name|offset
decl_stmt|;
comment|// offset in pixels
DECL|member|own_data
name|uint
name|own_data
range|:
literal|1
decl_stmt|;
DECL|member|ro_data
name|uint
name|ro_data
range|:
literal|1
decl_stmt|;
DECL|member|has_alpha_clut
name|uint
name|has_alpha_clut
range|:
literal|1
decl_stmt|;
DECL|member|is_cached
name|uint
name|is_cached
range|:
literal|1
decl_stmt|;
DECL|member|is_locked
name|uint
name|is_locked
range|:
literal|1
decl_stmt|;
DECL|member|cleanupFunction
name|QImageCleanupFunction
name|cleanupFunction
decl_stmt|;
DECL|member|cleanupInfo
name|void
modifier|*
name|cleanupInfo
decl_stmt|;
name|bool
name|checkForAlphaPixels
argument_list|()
specifier|const
expr_stmt|;
comment|// Convert the image in-place, minimizing memory reallocation
comment|// Return false if the conversion cannot be done in-place.
name|bool
name|convertInPlace
argument_list|(
name|QImage
operator|::
name|Format
name|newFormat
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
argument_list|)
decl_stmt|;
DECL|member|QString
DECL|member|text
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|text
expr_stmt|;
name|bool
name|doImageIO
argument_list|(
specifier|const
name|QImage
operator|*
name|image
argument_list|,
name|QImageWriter
operator|*
name|io
argument_list|,
name|int
name|quality
argument_list|)
decl|const
decl_stmt|;
DECL|member|paintEngine
name|QPaintEngine
modifier|*
name|paintEngine
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|Image_Converter
typedef|typedef
name|void
argument_list|(
operator|*
name|Image_Converter
argument_list|)
argument_list|(
name|QImageData
operator|*
name|dest
argument_list|,
specifier|const
name|QImageData
operator|*
name|src
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
argument_list|)
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|InPlace_Image_Converter
typedef|typedef
name|bool
argument_list|(
operator|*
name|InPlace_Image_Converter
argument_list|)
argument_list|(
name|QImageData
operator|*
name|data
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
argument_list|)
expr_stmt|;
end_typedef
begin_decl_stmt
specifier|extern
name|Image_Converter
name|qimage_converter_map
index|[
name|QImage
operator|::
name|NImageFormats
index|]
index|[
name|QImage
operator|::
name|NImageFormats
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|InPlace_Image_Converter
name|qimage_inplace_converter_map
index|[
name|QImage
operator|::
name|NImageFormats
index|]
index|[
name|QImage
operator|::
name|NImageFormats
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|convert_generic
argument_list|(
name|QImageData
operator|*
name|dest
argument_list|,
specifier|const
name|QImageData
operator|*
name|src
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|convert_generic_inplace
argument_list|(
name|QImageData
operator|*
name|data
argument_list|,
name|QImage
operator|::
name|Format
name|dst_format
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|dither_to_Mono
argument_list|(
name|QImageData
operator|*
name|dst
argument_list|,
specifier|const
name|QImageData
operator|*
name|src
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
argument_list|,
name|bool
name|fromalpha
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|qInitImageConversions
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|uchar
modifier|*
name|qt_get_bitflip_array
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|void
name|qGamma_correct_back_to_linear_cs
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M_ARM
argument_list|)
end_if
begin_comment
comment|// QTBUG-42038
end_comment
begin_pragma
pragma|#
directive|pragma
name|optimize
name|(
literal|""
name|,
name|off
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|function|qt_depthForFormat
specifier|inline
name|int
name|qt_depthForFormat
argument_list|(
name|QImage
operator|::
name|Format
name|format
argument_list|)
block|{
name|int
name|depth
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|QImage
operator|::
name|Format_Invalid
case|:
case|case
name|QImage
operator|::
name|NImageFormats
case|:
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
case|case
name|QImage
operator|::
name|Format_Mono
case|:
case|case
name|QImage
operator|::
name|Format_MonoLSB
case|:
name|depth
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_Indexed8
case|:
case|case
name|QImage
operator|::
name|Format_Alpha8
case|:
case|case
name|QImage
operator|::
name|Format_Grayscale8
case|:
name|depth
operator|=
literal|8
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_RGB32
case|:
case|case
name|QImage
operator|::
name|Format_ARGB32
case|:
case|case
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_RGBX8888
case|:
case|case
name|QImage
operator|::
name|Format_RGBA8888
case|:
case|case
name|QImage
operator|::
name|Format_RGBA8888_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_BGR30
case|:
case|case
name|QImage
operator|::
name|Format_A2BGR30_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_RGB30
case|:
case|case
name|QImage
operator|::
name|Format_A2RGB30_Premultiplied
case|:
name|depth
operator|=
literal|32
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_RGB555
case|:
case|case
name|QImage
operator|::
name|Format_RGB16
case|:
case|case
name|QImage
operator|::
name|Format_RGB444
case|:
case|case
name|QImage
operator|::
name|Format_ARGB4444_Premultiplied
case|:
name|depth
operator|=
literal|16
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_RGB666
case|:
case|case
name|QImage
operator|::
name|Format_ARGB6666_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB8565_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_ARGB8555_Premultiplied
case|:
case|case
name|QImage
operator|::
name|Format_RGB888
case|:
name|depth
operator|=
literal|24
expr_stmt|;
break|break;
block|}
return|return
name|depth
return|;
block|}
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M_ARM
argument_list|)
end_if
begin_pragma
pragma|#
directive|pragma
name|optimize
name|(
literal|""
name|,
name|on
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIMAGE_P_H
end_comment
end_unit
