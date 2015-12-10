begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_BLITTER_P_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_BLITTER_P_H
define|#
directive|define
name|QPAINTENGINE_BLITTER_P_H
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
file|"private/qpaintengine_raster_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BLITTABLE
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBlitterPaintEnginePrivate
name|class
name|QBlitterPaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBlittablePlatformPixmap
name|class
name|QBlittablePlatformPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBlittable
name|class
name|QBlittable
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QBlitterPaintEngine
range|:
name|public
name|QRasterPaintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
name|QBlitterPaintEngine
argument_list|)
block|;
name|public
operator|:
name|QBlitterPaintEngine
argument_list|(
name|QBlittablePlatformPixmap
operator|*
name|p
argument_list|)
block|;
name|virtual
name|QPaintEngine
operator|::
name|Type
name|type
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|Blitter
return|;
block|}
name|virtual
name|bool
name|begin
argument_list|(
argument|QPaintDevice *pdev
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|end
argument_list|()
name|Q_DECL_OVERRIDE
block|;
comment|// Call down into QBlittable
name|void
name|fill
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|const QBrush&brush
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|fillRect
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|const QBrush&brush
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|fillRect
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|const QColor&color
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawRects
argument_list|(
argument|const QRect *rects
argument_list|,
argument|int rectCount
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawRects
argument_list|(
argument|const QRectF *rects
argument_list|,
argument|int rectCount
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawPixmap
argument_list|(
argument|const QPointF&p
argument_list|,
argument|const QPixmap&pm
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawPixmap
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QPixmap&pm
argument_list|,
argument|const QRectF&sr
argument_list|)
name|Q_DECL_OVERRIDE
block|;
comment|// State tracking
name|void
name|setState
argument_list|(
argument|QPainterState *s
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|clipEnabledChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|penChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|brushChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|opacityChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|compositionModeChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|renderHintsChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|transformChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
comment|// Override to lock the QBlittable before using raster
name|void
name|drawPolygon
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawPolygon
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|fillPath
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|QSpanData *fillData
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|fillPolygon
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawEllipse
argument_list|(
argument|const QRectF&rect
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawImage
argument_list|(
argument|const QPointF&p
argument_list|,
argument|const QImage&img
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawImage
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QImage&pm
argument_list|,
argument|const QRectF&sr
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawTiledPixmap
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QPixmap&pm
argument_list|,
argument|const QPointF&sr
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawTextItem
argument_list|(
argument|const QPointF&p
argument_list|,
argument|const QTextItem&textItem
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawPoints
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawPoints
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|stroke
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|const QPen&pen
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawStaticTextItem
argument_list|(
argument|QStaticTextItem *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|drawCachedGlyphs
argument_list|(
argument|int numGlyphs
argument_list|,
argument|const glyph_t *glyphs
argument_list|,
argument|const QFixedPoint *positions
argument_list|,
argument|QFontEngine *fontEngine
argument_list|)
name|Q_DECL_OVERRIDE
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
comment|//QT_NO_BLITTABLE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTENGINE_BLITTER_P_H
end_comment
end_unit
