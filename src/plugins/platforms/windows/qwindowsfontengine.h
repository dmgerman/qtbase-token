begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSFONTENGINE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSFONTENGINE_H
define|#
directive|define
name|QWINDOWSFONTENGINE_H
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
file|<QtGui/private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
end_include
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsNativeImage
name|class
name|QWindowsNativeImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsFontEngineData
name|class
name|QWindowsFontEngineData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsFontEngine
range|:
name|public
name|QFontEngine
block|{
name|friend
name|class
name|QWindowsMultiFontEngine
block|;
name|public
operator|:
name|QWindowsFontEngine
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|HFONT
argument_list|,
name|bool
argument_list|,
name|LOGFONT
argument_list|,
specifier|const
name|QSharedPointer
operator|<
name|QWindowsFontEngineData
operator|>
operator|&
name|fontEngineData
argument_list|)
block|;
operator|~
name|QWindowsFontEngine
argument_list|()
block|;
name|void
name|initFontInfo
argument_list|(
argument|const QFontDef&request
argument_list|,
argument|HDC fontHdc
argument_list|,
argument|int dpi
argument_list|)
block|;
name|QFixed
name|lineThickness
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Properties
name|properties
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|getUnscaledGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|glyph_metrics_t *metrics
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|FaceId
name|faceId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|getSfntTableData
argument_list|(
argument|uint tag
argument_list|,
argument|uchar *buffer
argument_list|,
argument|uint *length
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|synthesized
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|emSquareSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|glyph_t
name|glyphIndex
argument_list|(
argument|uint ucs4
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|stringToCMap
argument_list|(
argument|const QChar *str
argument_list|,
argument|int len
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|int *nglyphs
argument_list|,
argument|ShaperFlags flags
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *glyphs
argument_list|,
argument|ShaperFlags
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|addOutlineToPath
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|const QGlyphLayout&glyphs
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|QTextItem::RenderFlags flags
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|addGlyphsToPath
argument_list|(
argument|glyph_t *glyphs
argument_list|,
argument|QFixedPoint *positions
argument_list|,
argument|int nglyphs
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|QTextItem::RenderFlags flags
argument_list|)
block|;
name|HGDIOBJ
name|selectDesignFont
argument_list|()
specifier|const
block|;
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|const QGlyphLayout&glyphs
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t g
argument_list|)
name|Q_DECL_OVERRIDE
block|{
return|return
name|boundingBox
argument_list|(
name|g
argument_list|,
name|QTransform
argument_list|()
argument_list|)
return|;
block|}
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t g
argument_list|,
argument|const QTransform&t
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|ascent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|descent
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|leading
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|xHeight
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFixed
name|averageCharWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qreal
name|minRightBearing
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t t
argument_list|)
name|Q_DECL_OVERRIDE
block|{
return|return
name|alphaMapForGlyph
argument_list|(
name|t
argument_list|,
name|QTransform
argument_list|()
argument_list|)
return|;
block|}
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t
argument_list|,
argument|const QTransform&xform
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|alphaRGBMapForGlyph
argument_list|(
argument|glyph_t t
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|const QTransform&xform
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|glyph_metrics_t
name|alphaMapBoundingBox
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed
argument_list|,
argument|const QTransform&matrix
argument_list|,
argument|GlyphFormat
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFontEngine
operator|*
name|cloneWithSize
argument_list|(
argument|qreal pixelSize
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|supportsTransformation
argument_list|(
argument|const QTransform&transform
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|Q_CC_MINGW
name|void
name|getGlyphBearings
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|qreal *leftBearing =
literal|0
argument_list|,
argument|qreal *rightBearing =
literal|0
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|bool
name|hasUnreliableGlyphOutline
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|getGlyphIndexes
argument_list|(
argument|const QChar *ch
argument_list|,
argument|int numChars
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|)
specifier|const
block|;
name|void
name|getCMap
argument_list|()
block|;
name|bool
name|getOutlineMetrics
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|const QTransform&t
argument_list|,
argument|glyph_metrics_t *metrics
argument_list|)
specifier|const
block|;
specifier|const
name|QSharedPointer
operator|<
name|QWindowsFontEngineData
operator|>
operator|&
name|fontEngineData
argument_list|()
specifier|const
block|{
return|return
name|m_fontEngineData
return|;
block|}
name|void
name|setUniqueFamilyName
argument_list|(
argument|const QString&newName
argument_list|)
block|{
name|uniqueFamilyName
operator|=
name|newName
block|; }
name|private
operator|:
name|QWindowsNativeImage
operator|*
name|drawGDIGlyph
argument_list|(
argument|HFONT font
argument_list|,
argument|glyph_t
argument_list|,
argument|int margin
argument_list|,
argument|const QTransform&xform
argument_list|,
argument|QImage::Format mask_format
argument_list|)
block|;
name|bool
name|hasCFFTable
argument_list|()
specifier|const
block|;
name|bool
name|hasCMapTable
argument_list|()
specifier|const
block|;
name|bool
name|hasGlyfTable
argument_list|()
specifier|const
block|;
name|bool
name|hasEbdtTable
argument_list|()
specifier|const
block|;
specifier|const
name|QSharedPointer
operator|<
name|QWindowsFontEngineData
operator|>
name|m_fontEngineData
block|;
specifier|const
name|QString
name|_name
block|;
name|QString
name|uniqueFamilyName
block|;
specifier|const
name|HFONT
name|hfont
block|;
specifier|const
name|LOGFONT
name|m_logfont
block|;
name|uint
name|stockFont
operator|:
literal|1
block|;
name|uint
name|ttf
operator|:
literal|1
block|;
name|uint
name|hasOutline
operator|:
literal|1
block|;
name|uint
name|hasUnreliableOutline
operator|:
literal|1
block|;
name|uint
name|cffTable
operator|:
literal|1
block|;
name|TEXTMETRIC
name|tm
block|;
name|int
name|lw
block|;
specifier|const
name|unsigned
name|char
operator|*
name|cmap
block|;
name|QByteArray
name|cmapTable
block|;
name|mutable
name|qreal
name|lbearing
block|;
name|mutable
name|qreal
name|rbearing
block|;
name|QFixed
name|designToDevice
block|;
name|int
name|unitsPerEm
block|;
name|QFixed
name|x_height
block|;
name|FaceId
name|_faceId
block|;
name|mutable
name|int
name|synthesized_flags
block|;
name|mutable
name|QFixed
name|lineWidth
block|;
name|mutable
name|unsigned
name|char
operator|*
name|widthCache
block|;
name|mutable
name|uint
name|widthCacheSize
block|;
name|mutable
name|QFixed
operator|*
name|designAdvances
block|;
name|mutable
name|int
name|designAdvancesSize
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsMultiFontEngine
range|:
name|public
name|QFontEngineMulti
block|{
name|public
operator|:
name|explicit
name|QWindowsMultiFontEngine
argument_list|(
argument|QFontEngine *fe
argument_list|,
argument|int script
argument_list|)
block|;
name|QFontEngine
operator|*
name|loadEngine
argument_list|(
argument|int at
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|HFONT
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|LOGFONT
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSFONTENGINE_H
end_comment
end_unit
