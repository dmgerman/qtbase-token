begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAP_H
end_ifndef
begin_define
DECL|macro|QPIXMAP_H
define|#
directive|define
name|QPIXMAP_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_comment
comment|// char*->QString conversion
end_comment
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QImageWriter
name|class
name|QImageWriter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImageReader
name|class
name|QImageReader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformPixmap
name|class
name|QPlatformPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPixmap
range|:
name|public
name|QPaintDevice
block|{
name|public
operator|:
name|QPixmap
argument_list|()
block|;
name|explicit
name|QPixmap
argument_list|(
name|QPlatformPixmap
operator|*
name|data
argument_list|)
block|;
name|QPixmap
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QPixmap
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
block|;
name|QPixmap
argument_list|(
argument|const QString& fileName
argument_list|,
argument|const char *format =
literal|0
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_XPM
name|QPixmap
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
name|QPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
operator|~
name|QPixmap
argument_list|()
block|;
name|QPixmap
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPixmap
operator|&
operator|)
block|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QPixmap
operator|&
name|operator
operator|=
operator|(
name|QPixmap
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|data
argument_list|,
name|other
operator|.
name|data
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
argument|QPixmap&other
argument_list|)
block|{
name|qSwap
argument_list|(
name|data
argument_list|,
name|other
operator|.
name|data
argument_list|)
block|; }
name|operator
name|QVariant
argument_list|()
specifier|const
block|;
name|bool
name|isNull
argument_list|()
specifier|const
block|;
comment|// ### Qt 5: make inline
name|int
name|devType
argument_list|()
specifier|const
block|;
name|int
name|width
argument_list|()
specifier|const
block|;
comment|// ### Qt 5: make inline
name|int
name|height
argument_list|()
specifier|const
block|;
comment|// ### Qt 5: make inline
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
specifier|static
name|int
name|defaultDepth
argument_list|()
block|;
name|void
name|fill
argument_list|(
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|void
name|fill
argument_list|(
specifier|const
name|QPaintDevice
operator|*
name|device
argument_list|,
specifier|const
name|QPoint
operator|&
name|ofs
argument_list|)
block|;
specifier|inline
name|void
name|fill
argument_list|(
argument|const QPaintDevice *device
argument_list|,
argument|int xofs
argument_list|,
argument|int yofs
argument_list|)
block|{
name|fill
argument_list|(
name|device
argument_list|,
name|QPoint
argument_list|(
name|xofs
argument_list|,
name|yofs
argument_list|)
argument_list|)
block|; }
name|QBitmap
name|mask
argument_list|()
specifier|const
block|;
name|void
name|setMask
argument_list|(
specifier|const
name|QBitmap
operator|&
argument_list|)
block|;
name|bool
name|hasAlpha
argument_list|()
specifier|const
block|;
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGE_HEURISTIC_MASK
name|QBitmap
name|createHeuristicMask
argument_list|(
argument|bool clipTight = true
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|QBitmap
name|createMaskFromColor
argument_list|(
argument|const QColor&maskColor
argument_list|,
argument|Qt::MaskMode mode = Qt::MaskInColor
argument_list|)
specifier|const
block|;
specifier|static
name|QPixmap
name|grabWindow
argument_list|(
argument|WId
argument_list|,
argument|int x=
literal|0
argument_list|,
argument|int y=
literal|0
argument_list|,
argument|int w=-
literal|1
argument_list|,
argument|int h=-
literal|1
argument_list|)
block|;
specifier|static
name|QPixmap
name|grabWidget
argument_list|(
name|QObject
operator|*
name|widget
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
specifier|static
specifier|inline
name|QPixmap
name|grabWidget
argument_list|(
argument|QObject *widget
argument_list|,
argument|int x=
literal|0
argument_list|,
argument|int y=
literal|0
argument_list|,
argument|int w=-
literal|1
argument_list|,
argument|int h=-
literal|1
argument_list|)
block|{
return|return
name|grabWidget
argument_list|(
name|widget
argument_list|,
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
name|QPixmap
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
name|QPixmap
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
name|QPixmap
name|scaledToWidth
argument_list|(
argument|int w
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QPixmap
name|scaledToHeight
argument_list|(
argument|int h
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QPixmap
name|transformed
argument_list|(
argument|const QMatrix&
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
specifier|static
name|QMatrix
name|trueMatrix
argument_list|(
argument|const QMatrix&m
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QPixmap
name|transformed
argument_list|(
argument|const QTransform&
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
specifier|static
name|QTransform
name|trueMatrix
argument_list|(
argument|const QTransform&m
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
specifier|static
name|QPixmap
name|fromImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
specifier|static
name|QPixmap
name|fromImageReader
argument_list|(
argument|QImageReader *imageReader
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|bool
name|load
argument_list|(
argument|const QString& fileName
argument_list|,
argument|const char *format =
literal|0
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|bool
name|loadFromData
argument_list|(
argument|const uchar *buf
argument_list|,
argument|uint len
argument_list|,
argument|const char* format =
literal|0
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
specifier|inline
name|bool
name|loadFromData
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|const char* format =
literal|0
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|bool
name|save
argument_list|(
argument|const QString& fileName
argument_list|,
argument|const char* format =
literal|0
argument_list|,
argument|int quality = -
literal|1
argument_list|)
specifier|const
block|;
name|bool
name|save
argument_list|(
argument|QIODevice* device
argument_list|,
argument|const char* format =
literal|0
argument_list|,
argument|int quality = -
literal|1
argument_list|)
specifier|const
block|;
name|bool
name|convertFromImage
argument_list|(
argument|const QImage&img
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
specifier|inline
name|QPixmap
name|copy
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|)
specifier|const
block|;
name|QPixmap
name|copy
argument_list|(
argument|const QRect&rect = QRect()
argument_list|)
specifier|const
block|;
specifier|inline
name|void
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|QRegion *exposed =
literal|0
argument_list|)
block|;
name|void
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|const QRect&rect
argument_list|,
argument|QRegion *exposed =
literal|0
argument_list|)
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
name|int
name|serialNumber
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|qint64
name|cacheKey
argument_list|()
specifier|const
block|;
name|bool
name|isDetached
argument_list|()
specifier|const
block|;
name|void
name|detach
argument_list|()
block|;
name|bool
name|isQBitmap
argument_list|()
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|isNull
argument_list|()
return|;
block|}
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|QPixmap
name|alphaChannel
argument_list|()
specifier|const
block|;
name|QT_DEPRECATED
specifier|inline
name|void
name|setAlphaChannel
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QExplicitlySharedDataPointer
operator|<
name|QPlatformPixmap
operator|>
name|data
block|;
name|bool
name|doImageIO
argument_list|(
argument|QImageWriter *io
argument_list|,
argument|int quality
argument_list|)
specifier|const
block|;
name|QPixmap
argument_list|(
argument|const QSize&s
argument_list|,
argument|int type
argument_list|)
block|;
name|void
name|doInit
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
block|;
name|Q_DUMMY_COMPARISON_OPERATOR
argument_list|(
argument|QPixmap
argument_list|)
name|friend
name|class
name|QPlatformPixmap
block|;
name|friend
name|class
name|QBitmap
block|;
name|friend
name|class
name|QPaintDevice
block|;
name|friend
name|class
name|QPainter
block|;
name|friend
name|class
name|QOpenGLWidget
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|friend
name|class
name|QRasterBuffer
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DATASTREAM
argument_list|)
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
expr|,
name|QPixmap
operator|&
operator|)
block|;
endif|#
directive|endif
name|public
operator|:
name|QPlatformPixmap
operator|*
name|handle
argument_list|()
specifier|const
block|;
name|public
operator|:
typedef|typedef
name|QExplicitlySharedDataPointer
operator|<
name|QPlatformPixmap
operator|>
name|DataPtr
expr_stmt|;
specifier|inline
name|DataPtr
operator|&
name|data_ptr
argument_list|()
block|{
return|return
name|data
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QPixmap
argument_list|)
end_macro
begin_expr_stmt
specifier|inline
name|QPixmap
name|QPixmap
operator|::
name|copy
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|,
argument|int awidth
argument_list|,
argument|int aheight
argument_list|)
specifier|const
block|{
return|return
name|copy
argument_list|(
name|QRect
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|awidth
argument_list|,
name|aheight
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|scroll
specifier|inline
name|void
name|QPixmap
operator|::
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|int ax
argument_list|,
argument|int ay
argument_list|,
argument|int awidth
argument_list|,
argument|int aheight
argument_list|,
argument|QRegion *exposed
argument_list|)
block|{
name|scroll
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|,
name|QRect
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|awidth
argument_list|,
name|aheight
argument_list|)
argument_list|,
name|exposed
argument_list|)
block|; }
DECL|function|loadFromData
specifier|inline
name|bool
name|QPixmap
operator|::
name|loadFromData
argument_list|(
argument|const QByteArray&buf
argument_list|,
argument|const char *format
argument_list|,
argument|Qt::ImageConversionFlags flags
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
name|buf
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
name|buf
operator|.
name|size
argument_list|()
argument_list|,
name|format
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_expr_stmt
DECL|function|alphaChannel
specifier|inline
name|QPixmap
name|QPixmap
operator|::
name|alphaChannel
argument_list|()
specifier|const
block|{
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|toImage
argument_list|()
operator|.
name|alphaChannel
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setAlphaChannel
specifier|inline
name|void
name|QPixmap
operator|::
name|setAlphaChannel
argument_list|(
argument|const QPixmap&p
argument_list|)
block|{
name|QImage
name|image
operator|=
name|toImage
argument_list|()
block|;
name|image
operator|.
name|setAlphaChannel
argument_list|(
name|p
operator|.
name|toImage
argument_list|()
argument_list|)
block|;
operator|*
name|this
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
block|;  }
endif|#
directive|endif
comment|/*****************************************************************************  QPixmap stream functions *****************************************************************************/
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
name|QPixmap
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
name|QPixmap
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QPixmap
operator|&
operator|)
expr_stmt|;
end_expr_stmt
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
comment|// QPIXMAP_H
end_comment
end_unit
