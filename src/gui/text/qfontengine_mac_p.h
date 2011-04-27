begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINE_MAC_P_H
end_ifndef
begin_define
DECL|macro|QFONTENGINE_MAC_P_H
define|#
directive|define
name|QFONTENGINE_MAC_P_H
end_define
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
end_ifndef
begin_decl_stmt
DECL|variable|QFontEngineMacMulti
name|class
name|QFontEngineMacMulti
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFontEngineMac
range|:
name|public
name|QFontEngine
block|{
name|friend
name|class
name|QFontEngineMacMulti
block|;
name|public
operator|:
name|QFontEngineMac
argument_list|(
argument|ATSUStyle baseStyle
argument_list|,
argument|ATSUFontID fontID
argument_list|,
argument|const QFontDef&def
argument_list|,
argument|QFontEngineMacMulti *multiEngine =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QFontEngineMac
argument_list|()
block|;
name|virtual
name|bool
name|stringToCMap
argument_list|(
argument|const QChar *str
argument_list|,
argument|int len
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|int *numGlyphs
argument_list|,
argument|QTextEngine::ShaperFlags flags
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
specifier|const
name|QGlyphLayout
operator|&
name|glyphs
argument_list|)
block|;
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|)
block|;
name|virtual
name|QFixed
name|ascent
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|descent
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|leading
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|xHeight
argument_list|()
specifier|const
block|;
name|virtual
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|averageCharWidth
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|addGlyphsToPath
argument_list|(
argument|glyph_t *glyphs
argument_list|,
argument|QFixedPoint *positions
argument_list|,
argument|int numGlyphs
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|QTextItem::RenderFlags
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
literal|"QFontEngineMac"
return|;
block|}
name|virtual
name|bool
name|canRender
argument_list|(
argument|const QChar *string
argument_list|,
argument|int len
argument_list|)
block|;
name|virtual
name|int
name|synthesized
argument_list|()
specifier|const
block|{
return|return
name|synthesisFlags
return|;
block|}
name|virtual
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|QFontEngine
operator|::
name|Mac
return|;
block|}
name|void
name|draw
argument_list|(
argument|CGContextRef ctx
argument_list|,
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|const QTextItemInt&ti
argument_list|,
argument|int paintDeviceHeight
argument_list|)
block|;
name|virtual
name|FaceId
name|faceId
argument_list|()
specifier|const
block|;
name|virtual
name|QByteArray
name|getSfntTable
argument_list|(
argument|uint tag
argument_list|)
specifier|const
block|;
name|virtual
name|Properties
name|properties
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|getUnscaledGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|glyph_metrics_t *metrics
argument_list|)
block|;
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
name|glyph_t
argument_list|)
block|;
name|virtual
name|QImage
name|alphaRGBMapForGlyph
argument_list|(
argument|glyph_t
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|int margin
argument_list|,
argument|const QTransform&t
argument_list|)
block|;
name|private
operator|:
name|QImage
name|imageForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|int margin
argument_list|,
argument|bool colorful
argument_list|)
block|;
name|ATSUFontID
name|fontID
block|;
name|QCFType
operator|<
name|CGFontRef
operator|>
name|cgFont
block|;
name|ATSUStyle
name|style
block|;
name|int
name|synthesisFlags
block|;
name|mutable
name|QGlyphLayout
name|kashidaGlyph
block|;
name|QFontEngineMacMulti
operator|*
name|multiEngine
block|;
name|mutable
specifier|const
name|unsigned
name|char
operator|*
name|cmap
block|;
name|mutable
name|bool
name|symbolCMap
block|;
name|mutable
name|QByteArray
name|cmapTable
block|;
name|CGAffineTransform
name|transform
block|;
name|QFixed
name|m_ascent
block|;
name|QFixed
name|m_descent
block|;
name|QFixed
name|m_leading
block|;
name|qreal
name|m_maxCharWidth
block|;
name|QFixed
name|m_xHeight
block|;
name|QFixed
name|m_averageCharWidth
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFontEngineMacMulti
range|:
name|public
name|QFontEngineMulti
block|{
name|friend
name|class
name|QFontEngineMac
block|;
name|public
operator|:
comment|// internal
expr|struct
name|ShaperItem
block|{
specifier|inline
name|ShaperItem
argument_list|()
operator|:
name|string
argument_list|(
literal|0
argument_list|)
block|,
name|from
argument_list|(
literal|0
argument_list|)
block|,
name|length
argument_list|(
literal|0
argument_list|)
block|,
name|log_clusters
argument_list|(
literal|0
argument_list|)
block|,
name|charAttributes
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|QChar
operator|*
name|string
block|;
name|int
name|from
block|;
name|int
name|length
block|;
name|QGlyphLayout
name|glyphs
block|;
name|unsigned
name|short
operator|*
name|log_clusters
block|;
specifier|const
name|HB_CharAttributes
operator|*
name|charAttributes
block|;
name|QTextEngine
operator|::
name|ShaperFlags
name|flags
block|;     }
block|;
name|QFontEngineMacMulti
argument_list|(
argument|const ATSFontFamilyRef&atsFamily
argument_list|,
argument|const ATSFontRef&atsFontRef
argument_list|,
argument|const QFontDef&fontDef
argument_list|,
argument|bool kerning
argument_list|)
block|;
name|virtual
operator|~
name|QFontEngineMacMulti
argument_list|()
block|;
name|virtual
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
argument|QTextEngine::ShaperFlags flags
argument_list|)
specifier|const
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
argument|QTextEngine::ShaperFlags flags
argument_list|,
argument|unsigned short *logClusters
argument_list|,
argument|const HB_CharAttributes *charAttributes
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|doKerning
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
literal|"ATSUI"
return|;
block|}
name|virtual
name|bool
name|canRender
argument_list|(
argument|const QChar *string
argument_list|,
argument|int len
argument_list|)
block|;
specifier|inline
name|ATSUFontID
name|macFontID
argument_list|()
specifier|const
block|{
return|return
name|fontID
return|;
block|}
name|protected
operator|:
name|virtual
name|void
name|loadEngine
argument_list|(
argument|int at
argument_list|)
block|;
name|private
operator|:
specifier|inline
specifier|const
name|QFontEngineMac
operator|*
name|engineAt
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|QFontEngineMac
operator|*
operator|>
operator|(
name|engines
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|)
return|;
block|}
name|bool
name|stringToCMapInternal
argument_list|(
argument|const QChar *str
argument_list|,
argument|int len
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|int *nglyphs
argument_list|,
argument|QTextEngine::ShaperFlags flags
argument_list|,
argument|ShaperItem *item
argument_list|)
specifier|const
block|;
name|int
name|fontIndexForFontID
argument_list|(
argument|ATSUFontID id
argument_list|)
specifier|const
block|;
name|ATSUFontID
name|fontID
block|;
name|uint
name|kerning
operator|:
literal|1
block|;
name|mutable
name|ATSUTextLayout
name|textLayout
block|;
name|mutable
name|ATSUStyle
name|style
block|;
name|CGAffineTransform
name|transform
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//!QT_MAC_USE_COCOA
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTENGINE_MAC_P_H
end_comment
end_unit
