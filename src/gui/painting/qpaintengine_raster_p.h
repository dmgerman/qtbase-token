begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_RASTER_P_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_RASTER_P_H
define|#
directive|define
name|QPAINTENGINE_RASTER_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"private/qpaintengineex_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainterpath.h"
end_include
begin_include
include|#
directive|include
file|"private/qdatabuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qdrawhelper_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpaintengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qrasterizer_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qstroker_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpainter_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtextureglyphcache_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qoutlinemapper_p.h"
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOutlineMapper
name|class
name|QOutlineMapper
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRasterPaintEnginePrivate
name|class
name|QRasterPaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRasterBuffer
name|class
name|QRasterBuffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QClipData
name|class
name|QClipData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QRasterPaintEngineState
range|:
name|public
name|QPainterState
block|{
name|public
operator|:
name|QRasterPaintEngineState
argument_list|(
name|QRasterPaintEngineState
operator|&
name|other
argument_list|)
block|;
name|QRasterPaintEngineState
argument_list|()
block|;
operator|~
name|QRasterPaintEngineState
argument_list|()
block|;
name|QPen
name|lastPen
block|;
name|QSpanData
name|penData
block|;
name|QStrokerOps
operator|*
name|stroker
block|;
name|uint
name|strokeFlags
block|;
name|QBrush
name|lastBrush
block|;
name|QSpanData
name|brushData
block|;
name|uint
name|fillFlags
block|;
name|uint
name|pixmapFlags
block|;
name|int
name|intOpacity
block|;
name|qreal
name|txscale
block|;
name|QClipData
operator|*
name|clip
block|;
comment|//     QRect clipRect;
comment|//     QRegion clipRegion;
comment|//     QPainter::RenderHints hints;
comment|//     QPainter::CompositionMode compositionMode;
name|uint
name|dirty
block|;      struct
name|Flags
block|{
name|uint
name|has_clip_ownership
operator|:
literal|1
block|;
comment|// should delete the clip member..
name|uint
name|fast_pen
operator|:
literal|1
block|;
comment|// cosmetic 1-width pens, using midpoint drawlines
name|uint
name|non_complex_pen
operator|:
literal|1
block|;
comment|// can use rasterizer, rather than stroker
name|uint
name|antialiased
operator|:
literal|1
block|;
name|uint
name|bilinear
operator|:
literal|1
block|;
name|uint
name|legacy_rounding
operator|:
literal|1
block|;
name|uint
name|fast_text
operator|:
literal|1
block|;
name|uint
name|int_xform
operator|:
literal|1
block|;
name|uint
name|tx_noshear
operator|:
literal|1
block|;
name|uint
name|fast_images
operator|:
literal|1
block|;     }
block|;
expr|union
block|{
name|Flags
name|flags
block|;
name|uint
name|flag_bits
block|;     }
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*******************************************************************************  * QRasterPaintEngine  */
end_comment
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRasterPaintEngine
range|:
name|public
name|QPaintEngineEx
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QRasterPaintEngine
argument_list|)
name|public
operator|:
name|QRasterPaintEngine
argument_list|(
name|QPaintDevice
operator|*
name|device
argument_list|)
block|;
operator|~
name|QRasterPaintEngine
argument_list|()
block|;
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|device
argument_list|)
block|;
name|bool
name|end
argument_list|()
block|;
name|void
name|penChanged
argument_list|()
block|;
name|void
name|brushChanged
argument_list|()
block|;
name|void
name|brushOriginChanged
argument_list|()
block|;
name|void
name|opacityChanged
argument_list|()
block|;
name|void
name|compositionModeChanged
argument_list|()
block|;
name|void
name|renderHintsChanged
argument_list|()
block|;
name|void
name|transformChanged
argument_list|()
block|;
name|void
name|clipEnabledChanged
argument_list|()
block|;
name|void
name|setState
argument_list|(
name|QPainterState
operator|*
name|s
argument_list|)
block|;
name|QPainterState
operator|*
name|createState
argument_list|(
argument|QPainterState *orig
argument_list|)
specifier|const
block|;
specifier|inline
name|QRasterPaintEngineState
operator|*
name|state
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|QRasterPaintEngineState
operator|*
operator|>
operator|(
name|QPaintEngineEx
operator|::
name|state
argument_list|()
operator|)
return|;
block|}
specifier|inline
specifier|const
name|QRasterPaintEngineState
operator|*
name|state
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|QRasterPaintEngineState
operator|*
operator|>
operator|(
name|QPaintEngineEx
operator|::
name|state
argument_list|()
operator|)
return|;
block|}
name|void
name|updateBrush
argument_list|(
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|void
name|updatePen
argument_list|(
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
name|void
name|updateMatrix
argument_list|(
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|)
block|;
name|void
name|drawPolygon
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
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
block|;
name|void
name|fillPath
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|,
name|QSpanData
operator|*
name|fillData
argument_list|)
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
block|;
name|void
name|drawEllipse
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|void
name|fillRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|void
name|fillRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|drawRects
argument_list|(
argument|const QRect  *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|void
name|drawRects
argument_list|(
argument|const QRectF *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|)
block|;
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|)
block|;
name|void
name|drawImage
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QImage
operator|&
name|img
argument_list|)
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
block|;
name|void
name|drawTiledPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|,
specifier|const
name|QPointF
operator|&
name|sr
argument_list|)
block|;
name|void
name|drawTextItem
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QTextItem
operator|&
name|textItem
argument_list|)
block|;
name|void
name|drawLines
argument_list|(
argument|const QLine *line
argument_list|,
argument|int lineCount
argument_list|)
block|;
name|void
name|drawLines
argument_list|(
argument|const QLineF *line
argument_list|,
argument|int lineCount
argument_list|)
block|;
name|void
name|drawPoints
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|void
name|drawPoints
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|void
name|stroke
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
name|void
name|fill
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|void
name|clip
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|void
name|clip
argument_list|(
argument|const QRect&rect
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|void
name|clip
argument_list|(
argument|const QRegion&region
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
specifier|inline
specifier|const
name|QClipData
operator|*
name|clipData
argument_list|()
specifier|const
block|;
name|void
name|drawStaticTextItem
argument_list|(
name|QStaticTextItem
operator|*
name|textItem
argument_list|)
block|;
name|virtual
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
block|;      enum
name|ClipType
block|{
name|RectClip
block|,
name|ComplexClip
block|}
block|;
name|ClipType
name|clipType
argument_list|()
specifier|const
block|;
name|QRect
name|clipBoundingRect
argument_list|()
specifier|const
block|;
name|void
name|releaseBuffer
argument_list|()
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|void
name|saveBuffer
argument_list|(
argument|const QString&s
argument_list|)
specifier|const
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|void
name|setDC
argument_list|(
argument|HDC hdc
argument_list|)
block|;
name|HDC
name|getDC
argument_list|()
specifier|const
block|;
name|void
name|releaseDC
argument_list|(
argument|HDC hdc
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|clearTypeFontsEnabled
argument_list|()
block|;
endif|#
directive|endif
name|QRasterBuffer
operator|*
name|rasterBuffer
argument_list|()
block|;
name|void
name|alphaPenBlt
argument_list|(
argument|const void* src
argument_list|,
argument|int bpl
argument_list|,
argument|int depth
argument_list|,
argument|int rx
argument_list|,
argument|int ry
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|Raster
return|;
block|}
name|QPoint
name|coordinateOffset
argument_list|()
specifier|const
block|;
name|bool
name|requiresPretransformedGlyphPositions
argument_list|(
argument|QFontEngine *fontEngine
argument_list|,
argument|const QTransform&m
argument_list|)
specifier|const
block|;
name|bool
name|shouldDrawCachedGlyphs
argument_list|(
argument|QFontEngine *fontEngine
argument_list|,
argument|const QTransform&m
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QRasterPaintEngine
argument_list|(
name|QRasterPaintEnginePrivate
operator|&
name|d
argument_list|,
name|QPaintDevice
operator|*
argument_list|)
block|;
name|private
operator|:
name|friend
expr|struct
name|QSpanData
block|;
name|friend
name|class
name|QBlitterPaintEngine
block|;
name|friend
name|class
name|QBlitterPaintEnginePrivate
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|fillRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
name|QSpanData
operator|*
name|data
argument_list|)
block|;
name|void
name|drawBitmap
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
specifier|const
name|QImage
operator|&
name|image
argument_list|,
name|QSpanData
operator|*
name|fill
argument_list|)
block|;
name|bool
name|setClipRectInDeviceCoords
argument_list|(
argument|const QRect&r
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|QRect
name|toNormalizedFillRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
specifier|inline
name|void
name|ensureBrush
argument_list|(
argument|const QBrush&brush
argument_list|)
block|{
if|if
condition|(
operator|!
name|qbrush_fast_equals
argument_list|(
name|state
argument_list|()
operator|->
name|lastBrush
argument_list|,
name|brush
argument_list|)
operator|||
name|state
argument_list|()
operator|->
name|fillFlags
condition|)
name|updateBrush
argument_list|(
name|brush
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|ensureBrush
argument_list|()
block|{
name|ensureBrush
argument_list|(
name|state
argument_list|()
operator|->
name|brush
argument_list|)
block|; }
specifier|inline
name|void
name|ensurePen
argument_list|(
argument|const QPen&pen
argument_list|)
block|{
if|if
condition|(
operator|!
name|qpen_fast_equals
argument_list|(
name|state
argument_list|()
operator|->
name|lastPen
argument_list|,
name|pen
argument_list|)
operator|||
operator|(
name|pen
operator|.
name|style
argument_list|()
operator|!=
name|Qt
operator|::
name|NoPen
operator|&&
name|state
argument_list|()
operator|->
name|strokeFlags
operator|)
condition|)
name|updatePen
argument_list|(
name|pen
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|ensurePen
argument_list|()
block|{
name|ensurePen
argument_list|(
name|state
argument_list|()
operator|->
name|pen
argument_list|)
block|; }
name|void
name|updateOutlineMapper
argument_list|()
block|;
specifier|inline
name|void
name|ensureOutlineMapper
argument_list|()
block|;
name|void
name|updateRasterState
argument_list|()
block|;
specifier|inline
name|void
name|ensureRasterState
argument_list|()
block|{
if|if
condition|(
name|state
argument_list|()
operator|->
name|dirty
condition|)
name|updateRasterState
argument_list|()
expr_stmt|;
block|}
expr|}
block|;
comment|/*******************************************************************************  * QRasterPaintEnginePrivate  */
name|class
name|QRasterPaintEnginePrivate
operator|:
name|public
name|QPaintEngineExPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QRasterPaintEngine
argument_list|)
name|public
operator|:
name|QRasterPaintEnginePrivate
argument_list|()
block|;
name|void
name|rasterizeLine_dashed
argument_list|(
argument|QLineF line
argument_list|,
argument|qreal width
argument_list|,
argument|int *dashIndex
argument_list|,
argument|qreal *dashOffset
argument_list|,
argument|bool *inDash
argument_list|)
block|;
name|void
name|rasterize
argument_list|(
argument|QT_FT_Outline *outline
argument_list|,
argument|ProcessSpans callback
argument_list|,
argument|QSpanData *spanData
argument_list|,
argument|QRasterBuffer *rasterBuffer
argument_list|)
block|;
name|void
name|rasterize
argument_list|(
argument|QT_FT_Outline *outline
argument_list|,
argument|ProcessSpans callback
argument_list|,
argument|void *userData
argument_list|,
argument|QRasterBuffer *rasterBuffer
argument_list|)
block|;
name|void
name|updateMatrixData
argument_list|(
name|QSpanData
operator|*
name|spanData
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
argument_list|,
specifier|const
name|QTransform
operator|&
name|brushMatrix
argument_list|)
block|;
name|void
name|systemStateChanged
argument_list|()
block|;
name|void
name|drawImage
argument_list|(
argument|const QPointF&pt
argument_list|,
argument|const QImage&img
argument_list|,
argument|SrcOverBlendFunc func
argument_list|,
argument|const QRect&clip
argument_list|,
argument|int alpha
argument_list|,
argument|const QRect&sr = QRect()
argument_list|)
block|;
name|QTransform
name|brushMatrix
argument_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QRasterPaintEngine
argument_list|)
block|;
specifier|const
name|QRasterPaintEngineState
operator|*
name|s
operator|=
name|q
operator|->
name|state
argument_list|()
block|;
name|QTransform
name|m
argument_list|(
name|s
operator|->
name|matrix
argument_list|)
block|;
name|m
operator|.
name|translate
argument_list|(
name|s
operator|->
name|brushOrigin
operator|.
name|x
argument_list|()
argument_list|,
name|s
operator|->
name|brushOrigin
operator|.
name|y
argument_list|()
argument_list|)
block|;
return|return
name|m
return|;
block|}
name|bool
name|isUnclipped_normalized
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|bool
name|isUnclipped
argument_list|(
argument|const QRect&rect
argument_list|,
argument|int penWidth
argument_list|)
specifier|const
block|;
name|bool
name|isUnclipped
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|int penWidth
argument_list|)
specifier|const
block|;
name|ProcessSpans
name|getPenFunc
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|const QSpanData *data
argument_list|)
specifier|const
block|;
name|ProcessSpans
name|getBrushFunc
argument_list|(
argument|const QRect&rect
argument_list|,
argument|const QSpanData *data
argument_list|)
specifier|const
block|;
name|ProcessSpans
name|getBrushFunc
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|const QSpanData *data
argument_list|)
specifier|const
block|;
specifier|inline
specifier|const
name|QClipData
operator|*
name|clip
argument_list|()
specifier|const
block|;
name|void
name|initializeRasterizer
argument_list|(
name|QSpanData
operator|*
name|data
argument_list|)
block|;
name|void
name|recalculateFastImages
argument_list|()
block|;
name|bool
name|canUseFastImageBlending
argument_list|(
argument|QPainter::CompositionMode mode
argument_list|,
argument|const QImage&image
argument_list|)
specifier|const
block|;
name|QPaintDevice
operator|*
name|device
block|;
name|QScopedPointer
operator|<
name|QOutlineMapper
operator|>
name|outlineMapper
block|;
name|QScopedPointer
operator|<
name|QRasterBuffer
operator|>
name|rasterBuffer
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|HDC
name|hdc
block|;
endif|#
directive|endif
name|QRect
name|deviceRect
block|;
name|QRect
name|deviceRectUnclipped
block|;
name|QStroker
name|basicStroker
block|;
name|QScopedPointer
operator|<
name|QDashStroker
operator|>
name|dashStroker
block|;
name|QScopedPointer
operator|<
name|QT_FT_Raster
operator|>
name|grayRaster
block|;
name|QDataBuffer
operator|<
name|QLineF
operator|>
name|cachedLines
block|;
name|QSpanData
name|image_filler
block|;
name|QSpanData
name|image_filler_xform
block|;
name|QSpanData
name|solid_color_filler
block|;
name|QFontEngine
operator|::
name|GlyphFormat
name|glyphCacheFormat
block|;
name|QScopedPointer
operator|<
name|QClipData
operator|>
name|baseClip
block|;
name|int
name|deviceDepth
block|;
name|uint
name|mono_surface
operator|:
literal|1
block|;
name|uint
name|outlinemapper_xform_dirty
operator|:
literal|1
block|;
name|QScopedPointer
operator|<
name|QRasterizer
operator|>
name|rasterizer
block|; }
block|;
name|class
name|QClipData
block|{
name|public
operator|:
name|QClipData
argument_list|(
argument|int height
argument_list|)
block|;
operator|~
name|QClipData
argument_list|()
block|;
name|int
name|clipSpanHeight
block|;     struct
name|ClipLine
block|{
name|int
name|count
block|;
name|QSpan
operator|*
name|spans
block|;     }
operator|*
name|m_clipLines
block|;
name|void
name|initialize
argument_list|()
block|;
specifier|inline
name|ClipLine
operator|*
name|clipLines
argument_list|()
block|{
if|if
condition|(
operator|!
name|m_clipLines
condition|)
name|initialize
argument_list|()
expr_stmt|;
return|return
name|m_clipLines
return|;
block|}
specifier|inline
name|QSpan
operator|*
name|spans
argument_list|()
block|{
if|if
condition|(
operator|!
name|m_spans
condition|)
name|initialize
argument_list|()
expr_stmt|;
return|return
name|m_spans
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|int
name|allocated
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSpan
modifier|*
name|m_spans
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|xmin
decl_stmt|,
name|xmax
decl_stmt|,
name|ymin
decl_stmt|,
name|ymax
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|clipRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRegion
name|clipRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|enabled
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|hasRectClip
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|hasRegionClip
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|appendSpan
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|coverage
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|appendSpans
parameter_list|(
specifier|const
name|QSpan
modifier|*
name|s
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### Should optimize and actually kill the QSpans if the rect is
end_comment
begin_comment
comment|// ### a subset of The current region. Thus the "fast" clipspan
end_comment
begin_comment
comment|// ### callback can be used
end_comment
begin_function_decl
name|void
name|setClipRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setClipRegion
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|fixup
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
DECL|function|appendSpan
specifier|inline
name|void
name|QClipData
operator|::
name|appendSpan
argument_list|(
argument|int x
argument_list|,
argument|int length
argument_list|,
argument|int y
argument_list|,
argument|int coverage
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|m_spans
argument_list|)
block|;
comment|// initialize() has to be called prior to adding spans..
if|if
condition|(
name|count
operator|==
name|allocated
condition|)
block|{
name|allocated
operator|*=
literal|2
expr_stmt|;
name|m_spans
operator|=
operator|(
name|QSpan
operator|*
operator|)
name|realloc
argument_list|(
name|m_spans
argument_list|,
name|allocated
operator|*
sizeof|sizeof
argument_list|(
name|QSpan
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|m_spans
index|[
name|count
index|]
operator|.
name|x
operator|=
name|x
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_spans
index|[
name|count
index|]
operator|.
name|len
operator|=
name|length
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_spans
index|[
name|count
index|]
operator|.
name|y
operator|=
name|y
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_spans
index|[
name|count
index|]
operator|.
name|coverage
operator|=
name|coverage
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|++
name|count
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  inline
DECL|function|appendSpans
name|void
name|QClipData
operator|::
name|appendSpans
argument_list|(
argument|const QSpan *s
argument_list|,
argument|int num
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|m_spans
argument_list|)
block|;
if|if
condition|(
name|count
operator|+
name|num
operator|>
name|allocated
condition|)
block|{
do|do
block|{
name|allocated
operator|*=
literal|2
expr_stmt|;
block|}
end_expr_stmt
begin_while
while|while
condition|(
name|count
operator|+
name|num
operator|>
name|allocated
condition|)
empty_stmt|;
end_while
begin_expr_stmt
name|m_spans
operator|=
operator|(
name|QSpan
operator|*
operator|)
name|realloc
argument_list|(
name|m_spans
argument_list|,
name|allocated
operator|*
sizeof|sizeof
argument_list|(
name|QSpan
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}     memcpy
operator|(
name|m_spans
operator|+
name|count
operator|,
name|s
operator|,
name|num
operator|*
sizeof|sizeof
argument_list|(
name|QSpan
argument_list|)
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|count
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|/*******************************************************************************  * QRasterBuffer  */
end_comment
begin_macro
unit|class
name|QRasterBuffer
end_macro
begin_block
block|{
name|public
label|:
name|QRasterBuffer
argument_list|()
operator|:
name|m_width
argument_list|(
literal|0
argument_list|)
operator|,
name|m_height
argument_list|(
literal|0
argument_list|)
operator|,
name|m_buffer
argument_list|(
literal|0
argument_list|)
block|{
name|init
argument_list|()
block|; }
operator|~
name|QRasterBuffer
argument_list|()
expr_stmt|;
name|void
name|init
parameter_list|()
function_decl|;
name|QImage
operator|::
name|Format
name|prepare
argument_list|(
name|QImage
operator|*
name|image
argument_list|)
expr_stmt|;
name|QImage
operator|::
name|Format
name|prepare
argument_list|(
name|QPixmap
operator|*
name|pix
argument_list|)
expr_stmt|;
name|void
name|prepare
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
function_decl|;
name|void
name|prepareBuffer
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
function_decl|;
name|void
name|resetBuffer
parameter_list|(
name|int
name|val
init|=
literal|0
parameter_list|)
function_decl|;
name|uchar
modifier|*
name|scanLine
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|y
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|y
operator|<
name|m_height
argument_list|)
expr_stmt|;
return|return
name|m_buffer
operator|+
name|y
operator|*
name|bytes_per_line
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|QImage
name|bufferImage
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|void
name|flushToARGBImage
argument_list|(
name|QImage
operator|*
name|image
argument_list|)
decl|const
decl_stmt|;
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|m_width
return|;
block|}
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|m_height
return|;
block|}
name|int
name|bytesPerLine
argument_list|()
specifier|const
block|{
return|return
name|bytes_per_line
return|;
block|}
name|int
name|bytesPerPixel
argument_list|()
specifier|const
block|{
return|return
name|bytes_per_pixel
return|;
block|}
name|uchar
operator|*
name|buffer
argument_list|()
specifier|const
block|{
return|return
name|m_buffer
return|;
block|}
name|bool
name|monoDestinationWithClut
decl_stmt|;
name|QRgb
name|destColor0
decl_stmt|;
name|QRgb
name|destColor1
decl_stmt|;
name|QPainter
operator|::
name|CompositionMode
name|compositionMode
expr_stmt|;
name|QImage
operator|::
name|Format
name|format
expr_stmt|;
name|DrawHelper
modifier|*
name|drawHelper
decl_stmt|;
name|QImage
name|colorizeBitmap
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
name|private
label|:
name|int
name|m_width
decl_stmt|;
name|int
name|m_height
decl_stmt|;
name|int
name|bytes_per_line
decl_stmt|;
name|int
name|bytes_per_pixel
decl_stmt|;
name|uchar
modifier|*
name|m_buffer
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|ensureOutlineMapper
specifier|inline
name|void
name|QRasterPaintEngine
operator|::
name|ensureOutlineMapper
argument_list|()
block|{
if|if
condition|(
name|d_func
argument_list|()
operator|->
name|outlinemapper_xform_dirty
condition|)
name|updateOutlineMapper
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|clip
specifier|inline
specifier|const
name|QClipData
operator|*
name|QRasterPaintEnginePrivate
operator|::
name|clip
argument_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QRasterPaintEngine
argument_list|)
block|;
if|if
condition|(
name|q
operator|->
name|state
argument_list|()
operator|&&
name|q
operator|->
name|state
argument_list|()
operator|->
name|clip
operator|&&
name|q
operator|->
name|state
argument_list|()
operator|->
name|clip
operator|->
name|enabled
condition|)
return|return
name|q
operator|->
name|state
argument_list|()
operator|->
name|clip
return|;
end_expr_stmt
begin_return
return|return
name|baseClip
operator|.
name|data
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|clipData
specifier|const
name|QClipData
operator|*
name|QRasterPaintEngine
operator|::
name|clipData
argument_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QRasterPaintEngine
argument_list|)
block|;
if|if
condition|(
name|state
argument_list|()
operator|&&
name|state
argument_list|()
operator|->
name|clip
operator|&&
name|state
argument_list|()
operator|->
name|clip
operator|->
name|enabled
condition|)
return|return
name|state
argument_list|()
operator|->
name|clip
return|;
end_expr_stmt
begin_return
return|return
name|d
operator|->
name|baseClip
operator|.
name|data
argument_list|()
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTENGINE_RASTER_P_H
end_comment
end_unit
