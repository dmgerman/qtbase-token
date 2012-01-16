begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAP_MAC_P_H
end_ifndef
begin_define
DECL|macro|QPIXMAP_MAC_P_H
define|#
directive|define
name|QPIXMAP_MAC_P_H
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
file|<QtGui/qplatformpixmap_qpa.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qplatformpixmapfactory_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qt_mac_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QMacPlatformPixmap
range|:
name|public
name|QPlatformPixmap
block|{
name|public
operator|:
name|QMacPlatformPixmap
argument_list|(
argument|PixelType type
argument_list|)
block|;
operator|~
name|QMacPlatformPixmap
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
name|void
name|fromImage
argument_list|(
argument|const QImage&image
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
name|int
name|metric
argument_list|(
argument|QPaintDevice::PaintDeviceMetric metric
argument_list|)
specifier|const
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
name|mask
argument_list|)
block|;
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
comment|//     QPixmap transformed(const QTransform&matrix,
comment|//                         Qt::TransformationMode mode) const;
name|void
name|setAlphaChannel
argument_list|(
specifier|const
name|QPixmap
operator|&
name|alphaChannel
argument_list|)
block|;
name|QPixmap
name|alphaChannel
argument_list|()
specifier|const
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|private
operator|:
name|uint
name|has_alpha
operator|:
literal|1
block|,
name|has_mask
operator|:
literal|1
block|,
name|uninit
operator|:
literal|1
block|;
name|void
name|macSetHasAlpha
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|macGetAlphaChannel
argument_list|(
argument|QMacPlatformPixmap *
argument_list|,
argument|bool asMask
argument_list|)
specifier|const
block|;
name|void
name|macSetAlphaChannel
argument_list|(
argument|const QMacPlatformPixmap *
argument_list|,
argument|bool asMask
argument_list|)
block|;
name|void
name|macCreateCGImageRef
argument_list|()
block|;
name|void
name|macCreatePixels
argument_list|()
block|;
name|void
name|macReleaseCGImageRef
argument_list|()
block|;
comment|/*         pixels stores the pixmap data. pixelsToFree is either 0 or some memory         block that was bound to a CGImageRef and released, and for which the         release callback has been called. There are two uses to pixelsToFree:          1. If pixels == pixelsToFree, then we know that the CGImageRef is done\            with the data and we can modify pixels without breaking CGImageRef's            mutability invariant.          2. If pixels != pixelsToFree and pixelsToFree != 0, then we can reuse            pixelsToFree later on instead of malloc'ing memory.     */
name|quint32
operator|*
name|pixels
block|;
name|uint
name|pixelsSize
block|;
name|quint32
operator|*
name|pixelsToFree
block|;
name|uint
name|bytesPerRow
block|;
name|QRectF
name|cg_mask_rect
block|;
name|CGImageRef
name|cg_data
block|,
name|cg_dataBeingReleased
block|,
name|cg_mask
block|;
specifier|static
name|QSet
operator|<
name|QMacPlatformPixmap
operator|*
operator|>
name|validDataPointers
block|;
name|QPaintEngine
operator|*
name|pengine
block|;
name|friend
name|class
name|QPixmap
block|;
name|friend
name|class
name|QRasterBuffer
block|;
name|friend
name|class
name|QRasterPaintEngine
block|;
name|friend
name|class
name|QCoreGraphicsPaintEngine
block|;
name|friend
name|CGImageRef
name|qt_mac_create_imagemask
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|,
specifier|const
name|QRectF
operator|&
argument_list|)
block|;
name|friend
name|quint32
operator|*
name|qt_mac_pixmap_get_base
argument_list|(
specifier|const
name|QPixmap
operator|*
argument_list|)
block|;
name|friend
name|int
name|qt_mac_pixmap_get_bytes_per_line
argument_list|(
specifier|const
name|QPixmap
operator|*
argument_list|)
block|;
name|friend
name|void
name|qt_mac_cgimage_data_free
argument_list|(
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|,
name|size_t
argument_list|)
block|;
name|friend
name|IconRef
name|qt_mac_create_iconref
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
name|friend
name|CGContextRef
name|qt_mac_cg_context
argument_list|(
specifier|const
name|QPaintDevice
operator|*
argument_list|)
block|;
name|friend
name|QColor
name|qcolorForThemeTextColor
argument_list|(
argument|ThemeTextColor themeColor
argument_list|)
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
comment|// QPIXMAP_MAC_P_H
end_comment
end_unit
