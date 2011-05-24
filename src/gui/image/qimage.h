begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIMAGE_H
end_ifndef
begin_define
DECL|macro|QIMAGE_H
define|#
directive|define
name|QIMAGE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qrgb.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMatrix
name|class
name|QMatrix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTransform
name|class
name|QTransform
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QVector
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QVector
expr_stmt|;
end_expr_stmt
begin_struct_decl
struct_decl|struct
name|QImageData
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QImageDataMisc
name|class
name|QImageDataMisc
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|QImageDataMisc
comment|// internal
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGE_TEXT
end_ifndef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QImageTextKeyLang
block|{
name|public
label|:
name|QImageTextKeyLang
argument_list|(
specifier|const
name|char
operator|*
name|k
argument_list|,
specifier|const
name|char
operator|*
name|l
argument_list|)
operator|:
name|key
argument_list|(
name|k
argument_list|)
operator|,
name|lang
argument_list|(
argument|l
argument_list|)
block|{ }
name|QImageTextKeyLang
argument_list|()
block|{ }
name|QByteArray
name|key
expr_stmt|;
name|QByteArray
name|lang
decl_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QImageTextKeyLang
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|key
operator|<
name|other
operator|.
name|key
operator|||
operator|(
name|key
operator|==
name|other
operator|.
name|key
operator|&&
name|lang
operator|<
name|other
operator|.
name|lang
operator|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QImageTextKeyLang
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|key
operator|==
name|other
operator|.
name|key
operator|&&
name|lang
operator|==
name|other
operator|.
name|lang
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QImageTextKeyLang
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_IMAGE_TEXT
end_comment
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QImage
range|:
name|public
name|QPaintDevice
block|{
name|public
operator|:
expr|enum
name|InvertMode
block|{
name|InvertRgb
block|,
name|InvertRgba
block|}
block|;     enum
name|Format
block|{
name|Format_Invalid
block|,
name|Format_Mono
block|,
name|Format_MonoLSB
block|,
name|Format_Indexed8
block|,
name|Format_RGB32
block|,
name|Format_ARGB32
block|,
name|Format_ARGB32_Premultiplied
block|,
name|Format_RGB16
block|,
name|Format_ARGB8565_Premultiplied
block|,
name|Format_RGB666
block|,
name|Format_ARGB6666_Premultiplied
block|,
name|Format_RGB555
block|,
name|Format_ARGB8555_Premultiplied
block|,
name|Format_RGB888
block|,
name|Format_RGB444
block|,
name|Format_ARGB4444_Premultiplied
block|,
if|#
directive|if
literal|0
comment|// reserved for future use
block|Format_RGB15,         Format_Grayscale16,         Format_Grayscale8,         Format_Grayscale4,         Format_Grayscale4LSB,         Format_Grayscale2,         Format_Grayscale2LSB
endif|#
directive|endif
ifndef|#
directive|ifndef
name|qdoc
name|NImageFormats
endif|#
directive|endif
block|}
block|;
name|QImage
argument_list|()
block|;
name|QImage
argument_list|(
argument|const QSize&size
argument_list|,
argument|Format format
argument_list|)
block|;
name|QImage
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Format format
argument_list|)
block|;
name|QImage
argument_list|(
argument|uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Format format
argument_list|)
block|;
name|QImage
argument_list|(
argument|const uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Format format
argument_list|)
block|;
name|QImage
argument_list|(
argument|uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int bytesPerLine
argument_list|,
argument|Format format
argument_list|)
block|;
name|QImage
argument_list|(
argument|const uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int bytesPerLine
argument_list|,
argument|Format format
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_XPM
name|explicit
name|QImage
argument_list|(
specifier|const
name|char
operator|*
specifier|const
name|xpm
index|[]
argument_list|)
block|;
endif|#
directive|endif
name|explicit
name|QImage
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
name|explicit
name|QImage
argument_list|(
specifier|const
name|char
operator|*
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
literal|0
argument_list|)
block|;
endif|#
directive|endif
name|QImage
argument_list|(
specifier|const
name|QImage
operator|&
argument_list|)
block|;
operator|~
name|QImage
argument_list|()
block|;
name|QImage
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QImage
operator|&
operator|)
block|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QImage
operator|&
name|operator
operator|=
operator|(
name|QImage
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
argument_list|(
argument|QImage&other
argument_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|; }
name|bool
name|isNull
argument_list|()
specifier|const
block|;
name|int
name|devType
argument_list|()
specifier|const
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QImage
operator|&
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QImage
operator|&
operator|)
specifier|const
block|;
name|operator
name|QVariant
argument_list|()
specifier|const
block|;
name|void
name|detach
argument_list|()
block|;
name|bool
name|isDetached
argument_list|()
specifier|const
block|;
name|QImage
name|copy
argument_list|(
argument|const QRect&rect = QRect()
argument_list|)
specifier|const
block|;
specifier|inline
name|QImage
name|copy
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
specifier|const
block|{
return|return
name|copy
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
return|;
block|}
name|Format
name|format
argument_list|()
specifier|const
block|;
name|QImage
name|convertToFormat
argument_list|(
argument|Format f
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|QImage
name|convertToFormat
argument_list|(
argument|Format f
argument_list|,
argument|const QVector<QRgb>&colorTable
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|int
name|width
argument_list|()
specifier|const
block|;
name|int
name|height
argument_list|()
specifier|const
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|QRect
name|rect
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT_DEPRECATED
name|QT_DEPRECATED
name|int
name|numColors
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|int
name|colorCount
argument_list|()
specifier|const
block|;
name|int
name|bitPlaneCount
argument_list|()
specifier|const
block|;
name|QRgb
name|color
argument_list|(
argument|int i
argument_list|)
specifier|const
block|;
name|void
name|setColor
argument_list|(
argument|int i
argument_list|,
argument|QRgb c
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT_DEPRECATED
name|QT_DEPRECATED
name|void
name|setNumColors
argument_list|(
name|int
argument_list|)
block|;
endif|#
directive|endif
name|void
name|setColorCount
argument_list|(
name|int
argument_list|)
block|;
name|bool
name|allGray
argument_list|()
specifier|const
block|;
name|bool
name|isGrayscale
argument_list|()
specifier|const
block|;
name|uchar
operator|*
name|bits
argument_list|()
block|;
specifier|const
name|uchar
operator|*
name|bits
argument_list|()
specifier|const
block|;
specifier|const
name|uchar
operator|*
name|constBits
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT_DEPRECATED
name|QT_DEPRECATED
name|int
name|numBytes
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|int
name|byteCount
argument_list|()
specifier|const
block|;
name|uchar
operator|*
name|scanLine
argument_list|(
name|int
argument_list|)
block|;
specifier|const
name|uchar
operator|*
name|scanLine
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
specifier|const
name|uchar
operator|*
name|constScanLine
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|int
name|bytesPerLine
argument_list|()
specifier|const
block|;
name|bool
name|valid
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|bool
name|valid
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|;
name|int
name|pixelIndex
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|int
name|pixelIndex
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|;
name|QRgb
name|pixel
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QRgb
name|pixel
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|;
name|void
name|setPixel
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|uint index_or_rgb
argument_list|)
block|;
name|void
name|setPixel
argument_list|(
argument|const QPoint&pt
argument_list|,
argument|uint index_or_rgb
argument_list|)
block|;
name|QVector
operator|<
name|QRgb
operator|>
name|colorTable
argument_list|()
specifier|const
block|;
name|void
name|setColorTable
argument_list|(
specifier|const
name|QVector
operator|<
name|QRgb
operator|>
name|colors
argument_list|)
block|;
name|void
name|fill
argument_list|(
argument|uint pixel
argument_list|)
block|;
name|void
name|fill
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|fill
argument_list|(
argument|Qt::GlobalColor color
argument_list|)
block|;
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
name|void
name|setAlphaChannel
argument_list|(
specifier|const
name|QImage
operator|&
name|alphaChannel
argument_list|)
block|;
name|QImage
name|alphaChannel
argument_list|()
specifier|const
block|;
name|QImage
name|createAlphaMask
argument_list|(
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGE_HEURISTIC_MASK
name|QImage
name|createHeuristicMask
argument_list|(
argument|bool clipTight = true
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|QImage
name|createMaskFromColor
argument_list|(
argument|QRgb color
argument_list|,
argument|Qt::MaskMode mode = Qt::MaskInColor
argument_list|)
specifier|const
block|;
specifier|inline
name|QImage
name|scaled
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::AspectRatioMode aspectMode = Qt::IgnoreAspectRatio
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|{
return|return
name|scaled
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|aspectMode
argument_list|,
name|mode
argument_list|)
return|;
block|}
name|QImage
name|scaled
argument_list|(
argument|const QSize&s
argument_list|,
argument|Qt::AspectRatioMode aspectMode = Qt::IgnoreAspectRatio
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QImage
name|scaledToWidth
argument_list|(
argument|int w
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QImage
name|scaledToHeight
argument_list|(
argument|int h
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QImage
name|transformed
argument_list|(
argument|const QMatrix&matrix
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
specifier|static
name|QMatrix
name|trueMatrix
argument_list|(
argument|const QMatrix&
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QImage
name|transformed
argument_list|(
argument|const QTransform&matrix
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
specifier|static
name|QTransform
name|trueMatrix
argument_list|(
argument|const QTransform&
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QImage
name|mirrored
argument_list|(
argument|bool horizontally = false
argument_list|,
argument|bool vertically = true
argument_list|)
specifier|const
block|;
name|QImage
name|rgbSwapped
argument_list|()
specifier|const
block|;
name|void
name|invertPixels
argument_list|(
name|InvertMode
operator|=
name|InvertRgb
argument_list|)
block|;
name|bool
name|load
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|)
block|;
name|bool
name|load
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
literal|0
argument_list|)
block|;
name|bool
name|loadFromData
argument_list|(
argument|const uchar *buf
argument_list|,
argument|int len
argument_list|,
argument|const char *format =
literal|0
argument_list|)
block|;
specifier|inline
name|bool
name|loadFromData
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|const char* aformat=
literal|0
argument_list|)
block|{
return|return
name|loadFromData
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|data
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|aformat
argument_list|)
return|;
block|}
name|bool
name|save
argument_list|(
argument|const QString&fileName
argument_list|,
argument|const char* format=
literal|0
argument_list|,
argument|int quality=-
literal|1
argument_list|)
specifier|const
block|;
name|bool
name|save
argument_list|(
argument|QIODevice *device
argument_list|,
argument|const char* format=
literal|0
argument_list|,
argument|int quality=-
literal|1
argument_list|)
specifier|const
block|;
specifier|static
name|QImage
name|fromData
argument_list|(
argument|const uchar *data
argument_list|,
argument|int size
argument_list|,
argument|const char *format =
literal|0
argument_list|)
block|;
specifier|inline
specifier|static
name|QImage
name|fromData
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|const char *format =
literal|0
argument_list|)
block|{
return|return
name|fromData
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|data
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|format
argument_list|)
return|;
block|}
name|int
name|serialNumber
argument_list|()
specifier|const
block|;
name|qint64
name|cacheKey
argument_list|()
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
comment|// Auxiliary data
name|int
name|dotsPerMeterX
argument_list|()
specifier|const
block|;
name|int
name|dotsPerMeterY
argument_list|()
specifier|const
block|;
name|void
name|setDotsPerMeterX
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setDotsPerMeterY
argument_list|(
name|int
argument_list|)
block|;
name|QPoint
name|offset
argument_list|()
specifier|const
block|;
name|void
name|setOffset
argument_list|(
specifier|const
name|QPoint
operator|&
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGE_TEXT
name|QStringList
name|textKeys
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|const QString&key = QString()
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|)
block|;
comment|// The following functions are obsolete as of 4.1
name|QString
name|text
argument_list|(
argument|const char* key
argument_list|,
argument|const char* lang=
literal|0
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QImageTextKeyLang
operator|>
name|textList
argument_list|()
specifier|const
block|;
name|QStringList
name|textLanguages
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|const QImageTextKeyLang&
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
specifier|const
name|char
operator|*
name|key
argument_list|,
specifier|const
name|char
operator|*
name|lang
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT3_SUPPORT
block|enum
name|Endian
block|{
name|BigEndian
block|,
name|LittleEndian
block|,
name|IgnoreEndian
block|}
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QImage
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int depth
argument_list|,
argument|int numColors=
literal|0
argument_list|,
argument|Endian bitOrder=IgnoreEndian
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QImage
argument_list|(
argument|const QSize&
argument_list|,
argument|int depth
argument_list|,
argument|int numColors=
literal|0
argument_list|,
argument|Endian bitOrder=IgnoreEndian
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QImage
argument_list|(
argument|uchar *data
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|int depth
argument_list|,
argument|const QRgb *colortable
argument_list|,
argument|int numColors
argument_list|,
argument|Endian bitOrder
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_WS_QWS
name|QT3_SUPPORT_CONSTRUCTOR
name|QImage
argument_list|(
argument|uchar *data
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|int depth
argument_list|,
argument|int pbl
argument_list|,
argument|const QRgb *colortable
argument_list|,
argument|int numColors
argument_list|,
argument|Endian bitOrder
argument_list|)
block|;
endif|#
directive|endif
specifier|inline
name|QT3_SUPPORT
name|Endian
name|bitOrder
argument_list|()
specifier|const
block|{
name|Format
name|f
operator|=
name|format
argument_list|()
block|;
return|return
name|f
operator|==
name|Format_Mono
condition|?
name|BigEndian
else|:
operator|(
name|f
operator|==
name|Format_MonoLSB
condition|?
name|LittleEndian
else|:
name|IgnoreEndian
operator|)
return|;
block|}
name|QT3_SUPPORT
name|QImage
name|convertDepth
argument_list|(
argument|int
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
block|;
name|QT3_SUPPORT
name|QImage
name|convertDepthWithPalette
argument_list|(
argument|int
argument_list|,
argument|QRgb* p
argument_list|,
argument|int pc
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
specifier|const
block|;
name|QT3_SUPPORT
name|QImage
name|convertBitOrder
argument_list|(
argument|Endian
argument_list|)
specifier|const
block|;
name|QT3_SUPPORT
name|bool
name|hasAlphaBuffer
argument_list|()
specifier|const
block|;
name|QT3_SUPPORT
name|void
name|setAlphaBuffer
argument_list|(
name|bool
argument_list|)
block|;
name|QT3_SUPPORT
name|uchar
operator|*
operator|*
name|jumpTable
argument_list|()
block|;
name|QT3_SUPPORT
specifier|const
name|uchar
operator|*
specifier|const
operator|*
name|jumpTable
argument_list|()
specifier|const
block|;
specifier|inline
name|QT3_SUPPORT
name|void
name|reset
argument_list|()
block|{
operator|*
name|this
operator|=
name|QImage
argument_list|()
block|; }
specifier|static
specifier|inline
name|QT3_SUPPORT
name|Endian
name|systemByteOrder
argument_list|()
block|{
return|return
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|BigEndian
condition|?
name|BigEndian
else|:
name|LittleEndian
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|QImage
name|swapRGB
argument_list|()
specifier|const
block|{
return|return
name|rgbSwapped
argument_list|()
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|QImage
name|mirror
argument_list|(
argument|bool horizontally = false
argument_list|,
argument|bool vertically = true
argument_list|)
specifier|const
block|{
return|return
name|mirrored
argument_list|(
name|horizontally
argument_list|,
name|vertically
argument_list|)
return|;
block|}
name|QT3_SUPPORT
name|bool
name|create
argument_list|(
argument|const QSize&
argument_list|,
argument|int depth
argument_list|,
argument|int numColors=
literal|0
argument_list|,
argument|Endian bitOrder=IgnoreEndian
argument_list|)
block|;
name|QT3_SUPPORT
name|bool
name|create
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int depth
argument_list|,
argument|int numColors=
literal|0
argument_list|,
argument|Endian bitOrder=IgnoreEndian
argument_list|)
block|;
specifier|inline
name|QT3_SUPPORT
name|QImage
name|xForm
argument_list|(
argument|const QMatrix&matrix
argument_list|)
specifier|const
block|{
return|return
name|transformed
argument_list|(
name|QTransform
argument_list|(
name|matrix
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|QImage
name|smoothScale
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::AspectRatioMode mode = Qt::IgnoreAspectRatio
argument_list|)
specifier|const
block|{
return|return
name|scaled
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|,
name|Qt
operator|::
name|SmoothTransformation
argument_list|)
return|;
block|}
specifier|inline
name|QImage
name|QT3_SUPPORT
name|smoothScale
argument_list|(
argument|const QSize&s
argument_list|,
argument|Qt::AspectRatioMode mode = Qt::IgnoreAspectRatio
argument_list|)
specifier|const
block|{
return|return
name|scaled
argument_list|(
name|s
argument_list|,
name|mode
argument_list|,
name|Qt
operator|::
name|SmoothTransformation
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|QImage
name|scaleWidth
argument_list|(
argument|int w
argument_list|)
specifier|const
block|{
return|return
name|scaledToWidth
argument_list|(
name|w
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|QImage
name|scaleHeight
argument_list|(
argument|int h
argument_list|)
specifier|const
block|{
return|return
name|scaledToHeight
argument_list|(
name|h
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|void
name|invertPixels
argument_list|(
argument|bool invertAlpha
argument_list|)
block|{
name|invertAlpha
condition|?
name|invertPixels
argument_list|(
name|InvertRgba
argument_list|)
else|:
name|invertPixels
argument_list|(
name|InvertRgb
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|QImage
name|copy
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::ImageConversionFlags
argument_list|)
specifier|const
block|{
return|return
name|copy
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|QImage
name|copy
argument_list|(
argument|const QRect&rect
argument_list|,
argument|Qt::ImageConversionFlags
argument_list|)
specifier|const
block|{
return|return
name|copy
argument_list|(
name|rect
argument_list|)
return|;
block|}
specifier|static
name|QT3_SUPPORT
name|Endian
name|systemBitOrder
argument_list|()
block|;
specifier|inline
name|QT3_SUPPORT_CONSTRUCTOR
name|QImage
argument_list|(
argument|const QByteArray&data
argument_list|)
block|{
name|d
operator|=
literal|0
block|;
operator|*
name|this
operator|=
name|QImage
operator|::
name|fromData
argument_list|(
name|data
argument_list|)
block|; }
endif|#
directive|endif
name|protected
operator|:
name|virtual
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|private
operator|:
name|friend
name|class
name|QWSOnScreenSurface
block|;
name|QImageData
operator|*
name|d
block|;
name|friend
name|class
name|QRasterPixmapData
block|;
name|friend
name|class
name|QBlittablePixmapData
block|;
name|friend
name|class
name|QPixmapCacheEntry
block|;
name|friend
name|Q_GUI_EXPORT
name|qint64
name|qt_image_id
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|friend
specifier|const
name|QVector
operator|<
name|QRgb
operator|>
operator|*
name|qt_image_colortable
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|public
operator|:
typedef|typedef
name|QImageData
modifier|*
name|DataPtr
typedef|;
specifier|inline
name|DataPtr
operator|&
name|data_ptr
argument_list|()
block|{
return|return
name|d
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QImage
argument_list|)
end_macro
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QImage
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Inline functions...
end_comment
begin_expr_stmt
name|Q_GUI_EXPORT_INLINE
name|bool
name|QImage
operator|::
name|valid
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|{
return|return
name|valid
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|pixelIndex
name|Q_GUI_EXPORT_INLINE
name|int
name|QImage
operator|::
name|pixelIndex
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|{
return|return
name|pixelIndex
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|pixel
name|Q_GUI_EXPORT_INLINE
name|QRgb
name|QImage
operator|::
name|pixel
argument_list|(
argument|const QPoint&pt
argument_list|)
specifier|const
block|{
return|return
name|pixel
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setPixel
name|Q_GUI_EXPORT_INLINE
name|void
name|QImage
operator|::
name|setPixel
argument_list|(
argument|const QPoint&pt
argument_list|,
argument|uint index_or_rgb
argument_list|)
block|{
name|setPixel
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|,
name|index_or_rgb
argument_list|)
block|; }
comment|// QImage stream functions
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DATASTREAM
argument_list|)
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QImage
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QImage
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_decl_stmt
name|Q_GUI_EXPORT
name|QT3_SUPPORT
name|void
name|bitBlt
argument_list|(
name|QImage
operator|*
name|dst
argument_list|,
name|int
name|dx
argument_list|,
name|int
name|dy
argument_list|,
specifier|const
name|QImage
operator|*
name|src
argument_list|,
name|int
name|sx
operator|=
literal|0
argument_list|,
name|int
name|sy
operator|=
literal|0
argument_list|,
name|int
name|sw
operator|=
operator|-
literal|1
argument_list|,
name|int
name|sh
operator|=
operator|-
literal|1
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
operator|=
name|Qt
operator|::
name|AutoColor
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIMAGE_H
end_comment
end_unit
