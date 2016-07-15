begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_comment
comment|// Enable access to HB_Face in harfbuzz includes included by qfontengine_p.h.
end_comment
begin_define
DECL|macro|QT_BUILD_GUI_LIB
define|#
directive|define
name|QT_BUILD_GUI_LIB
end_define
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_p.h>
end_include
begin_undef
DECL|macro|QT_BUILD_GUI_LIB
undef|#
directive|undef
name|QT_BUILD_GUI_LIB
end_undef
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
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsFontEngine
argument_list|)
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
name|QSharedPointer
operator|<
name|QWindowsFontEngineData
operator|>
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
name|virtual
name|QFixed
name|lineThickness
argument_list|()
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
name|FaceId
name|faceId
argument_list|()
specifier|const
block|;
name|virtual
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
block|;
name|virtual
name|int
name|synthesized
argument_list|()
specifier|const
block|;
name|virtual
name|QFixed
name|emSquareSize
argument_list|()
specifier|const
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
name|virtual
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *glyphs
argument_list|,
argument|QTextEngine::ShaperFlags
argument_list|)
specifier|const
block|;
name|virtual
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
argument|glyph_t g
argument_list|)
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
name|virtual
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t g
argument_list|,
argument|const QTransform&t
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
name|QFixed
name|averageCharWidth
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
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
block|;
name|virtual
name|qreal
name|minRightBearing
argument_list|()
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|;
name|bool
name|canRender
argument_list|(
argument|const QChar *string
argument_list|,
argument|int len
argument_list|)
block|;
name|Type
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t t
argument_list|)
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
name|virtual
name|QImage
name|alphaMapForGlyph
argument_list|(
name|glyph_t
argument_list|,
specifier|const
name|QTransform
operator|&
name|xform
argument_list|)
block|;
name|virtual
name|QImage
name|alphaRGBMapForGlyph
argument_list|(
argument|glyph_t t
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|int margin
argument_list|,
argument|const QTransform&xform
argument_list|)
block|;
name|virtual
name|QFontEngine
operator|*
name|cloneWithSize
argument_list|(
argument|qreal pixelSize
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|Q_CC_MINGW
name|virtual
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
block|;
endif|#
directive|endif
name|int
name|getGlyphIndexes
argument_list|(
argument|const QChar *ch
argument_list|,
argument|int numChars
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|bool mirrored
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
specifier|static
name|QFontEngine
operator|*
name|createEngine
argument_list|(
argument|int script
argument_list|,
argument|const QFontDef&request
argument_list|,
argument|HDC fontHdc
argument_list|,
argument|int dpi
argument_list|,
argument|bool rawMode
argument_list|,
argument|const QStringList&family_list
argument_list|,
argument|const QSharedPointer<QWindowsFontEngineData>&data
argument_list|)
block|;
name|QSharedPointer
operator|<
name|QWindowsFontEngineData
operator|>
name|fontEngineData
argument_list|()
specifier|const
block|{
return|return
name|m_fontEngineData
return|;
block|}
name|LOGFONT
name|logfont
argument_list|()
specifier|const
block|{
return|return
name|m_logfont
return|;
block|}
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
name|QWindowsMultiFontEngine
argument_list|(
name|QFontEngine
operator|*
name|first
argument_list|,
specifier|const
name|QStringList
operator|&
name|fallbacks
argument_list|)
block|;
name|virtual
operator|~
name|QWindowsMultiFontEngine
argument_list|()
block|;
name|void
name|loadEngine
argument_list|(
argument|int at
argument_list|)
block|;
name|QStringList
name|fallbacks
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
comment|// QWINDOWSFONTENGINE_H
end_comment
end_unit
