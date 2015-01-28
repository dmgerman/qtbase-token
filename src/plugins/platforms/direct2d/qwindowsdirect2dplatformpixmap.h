begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSDIRECT2DPLATFORMPIXMAP_H
end_ifndef
begin_define
DECL|macro|QWINDOWSDIRECT2DPLATFORMPIXMAP_H
define|#
directive|define
name|QWINDOWSDIRECT2DPLATFORMPIXMAP_H
end_define
begin_include
include|#
directive|include
file|"qwindowsdirect2dpaintengine.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsDirect2DPlatformPixmapPrivate
name|class
name|QWindowsDirect2DPlatformPixmapPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsDirect2DBitmap
name|class
name|QWindowsDirect2DBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsDirect2DPlatformPixmap
range|:
name|public
name|QPlatformPixmap
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWindowsDirect2DPlatformPixmap
argument_list|)
name|public
operator|:
name|QWindowsDirect2DPlatformPixmap
argument_list|(
argument|PixelType pixelType
argument_list|)
block|;
comment|// We do NOT take ownership of the bitmap through this constructor!
name|QWindowsDirect2DPlatformPixmap
argument_list|(
argument|PixelType pixelType
argument_list|,
argument|QWindowsDirect2DPaintEngine::Flags flags
argument_list|,
argument|QWindowsDirect2DBitmap *bitmap
argument_list|)
block|;
operator|~
name|QWindowsDirect2DPlatformPixmap
argument_list|()
block|;
name|void
name|resize
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|fromImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|int
name|metric
argument_list|(
argument|QPaintDevice::PaintDeviceMetric metric
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|fill
argument_list|(
argument|const QColor&color
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|toImage
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setDevicePixelRatio
argument_list|(
argument|qreal scaleFactor
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QWindowsDirect2DBitmap
operator|*
name|bitmap
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QWindowsDirect2DPlatformPixmapPrivate
operator|>
name|d_ptr
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
comment|// QWINDOWSDIRECT2DPLATFORMPIXMAP_H
end_comment
end_unit
