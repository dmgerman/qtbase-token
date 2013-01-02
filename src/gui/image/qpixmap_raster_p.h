begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAP_RASTER_P_H
end_ifndef
begin_define
DECL|macro|QPIXMAP_RASTER_P_H
define|#
directive|define
name|QPIXMAP_RASTER_P_H
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
file|<qpa/qplatformpixmap.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QRasterPlatformPixmap
range|:
name|public
name|QPlatformPixmap
block|{
name|public
operator|:
name|QRasterPlatformPixmap
argument_list|(
argument|PixelType type
argument_list|)
block|;
operator|~
name|QRasterPlatformPixmap
argument_list|()
block|;
name|QPlatformPixmap
operator|*
name|createCompatiblePlatformPixmap
argument_list|()
specifier|const
block|;
name|void
name|resize
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|bool
name|fromData
argument_list|(
argument|const uchar *buffer
argument_list|,
argument|uint len
argument_list|,
argument|const char *format
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|void
name|fromImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|void
name|fromImageReader
argument_list|(
argument|QImageReader *imageReader
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|void
name|copy
argument_list|(
specifier|const
name|QPlatformPixmap
operator|*
name|data
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|bool
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|const QRect&rect
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
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
name|QImage
name|toImage
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|QImage
operator|*
name|buffer
argument_list|()
block|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
block|;
name|void
name|setDevicePixelRatio
argument_list|(
argument|qreal scaleFactor
argument_list|)
block|;
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|QPaintDevice::PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|void
name|createPixmapForImage
argument_list|(
argument|QImage&sourceImage
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|,
argument|bool inPlace
argument_list|)
block|;
name|void
name|setImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|QImage
name|image
block|;
name|private
operator|:
name|friend
name|class
name|QPixmap
block|;
name|friend
name|class
name|QBitmap
block|;
name|friend
name|class
name|QPixmapCacheEntry
block|;
name|friend
name|class
name|QRasterPaintEngine
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPIXMAP_RASTER_P_H
end_comment
end_unit
