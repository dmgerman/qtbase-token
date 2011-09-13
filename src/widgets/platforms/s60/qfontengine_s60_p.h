begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINE_S60_P_H
end_ifndef
begin_define
DECL|macro|QFONTENGINE_S60_P_H
define|#
directive|define
name|QFONTENGINE_S60_P_H
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
file|"qconfig.h"
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|"qsize.h"
end_include
begin_include
include|#
directive|include
file|<openfont.h>
end_include
begin_comment
comment|// The glyph outline code is intentionally disabled. It will be reactivated as
end_comment
begin_comment
comment|// soon as the glyph outline API is backported from Symbian(^4) to Symbian(^3).
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_define
define|#
directive|define
name|Q_SYMBIAN_HAS_GLYPHOUTLINE_API
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|CFont
name|class
name|CFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// ..gives us access to truetype tables
name|class
name|QSymbianTypeFaceExtras
block|{
name|public
label|:
name|QSymbianTypeFaceExtras
argument_list|(
name|CFont
operator|*
name|cFont
argument_list|,
name|COpenFont
operator|*
name|openFont
operator|=
literal|0
argument_list|)
expr_stmt|;
operator|~
name|QSymbianTypeFaceExtras
argument_list|()
expr_stmt|;
name|QByteArray
name|getSfntTable
argument_list|(
name|uint
name|tag
argument_list|)
decl|const
decl_stmt|;
name|bool
name|getSfntTableData
argument_list|(
name|uint
name|tag
argument_list|,
name|uchar
operator|*
name|buffer
argument_list|,
name|uint
operator|*
name|length
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|uchar
operator|*
name|cmap
argument_list|()
specifier|const
expr_stmt|;
name|CFont
operator|*
name|fontOwner
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSymbolCMap
argument_list|()
specifier|const
expr_stmt|;
name|QFixed
name|unitsPerEm
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|symbianFontTableApiAvailable
parameter_list|()
function_decl|;
name|private
label|:
name|CFont
modifier|*
name|m_cFont
decl_stmt|;
name|mutable
name|bool
name|m_symbolCMap
decl_stmt|;
name|mutable
name|QByteArray
name|m_cmapTable
decl_stmt|;
name|mutable
name|QFixed
name|m_unitsPerEm
decl_stmt|;
comment|// m_openFont and m_openFont are used if Symbian does not provide
comment|// the Font Table API
name|COpenFont
modifier|*
name|m_openFont
decl_stmt|;
name|mutable
name|MOpenFontTrueTypeExtension
modifier|*
name|m_trueTypeExtension
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QFontEngineS60
range|:
name|public
name|QFontEngine
block|{
name|public
operator|:
name|QFontEngineS60
argument_list|(
specifier|const
name|QFontDef
operator|&
name|fontDef
argument_list|,
specifier|const
name|QSymbianTypeFaceExtras
operator|*
name|extras
argument_list|)
block|;
operator|~
name|QFontEngineS60
argument_list|()
block|;
name|QFixed
name|emSquareSize
argument_list|()
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
argument_list|)
specifier|const
block|;
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *glyphs
argument_list|,
argument|QTextEngine::ShaperFlags flags
argument_list|)
specifier|const
block|;
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
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|)
block|;
name|glyph_metrics_t
name|boundingBox
argument_list|(
specifier|const
name|QGlyphLayout
operator|&
name|glyphs
argument_list|)
block|;
name|glyph_metrics_t
name|boundingBox_const
argument_list|(
argument|glyph_t glyph
argument_list|)
specifier|const
block|;
comment|// Const correctnes quirk.
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|)
block|;
name|QFixed
name|ascent
argument_list|()
specifier|const
block|;
name|QFixed
name|descent
argument_list|()
specifier|const
block|;
name|QFixed
name|leading
argument_list|()
specifier|const
block|;
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
block|;
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|qreal
name|minRightBearing
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|QByteArray
name|getSfntTable
argument_list|(
argument|uint tag
argument_list|)
specifier|const
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
block|;
specifier|static
name|qreal
name|pixelsToPoints
argument_list|(
argument|qreal pixels
argument_list|,
argument|Qt::Orientation orientation = Qt::Horizontal
argument_list|)
block|;
specifier|static
name|qreal
name|pointsToPixels
argument_list|(
argument|qreal points
argument_list|,
argument|Qt::Orientation orientation = Qt::Horizontal
argument_list|)
block|;
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
name|void
name|getCharacterData
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|TOpenFontCharMetrics& metrics
argument_list|,
argument|const TUint8*& bitmap
argument_list|,
argument|TSize& bitmapSize
argument_list|)
specifier|const
block|;
name|void
name|setFontScale
argument_list|(
argument|qreal scale
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QFontPrivate
block|;
name|friend
name|class
name|QSymbianVGFontGlyphCache
block|;
name|QFixed
name|glyphAdvance
argument_list|(
argument|HB_Glyph glyph
argument_list|)
specifier|const
block|;
name|CFont
operator|*
name|fontWithSize
argument_list|(
argument|qreal size
argument_list|)
specifier|const
block|;
specifier|static
name|void
name|releaseFont
argument_list|(
name|CFont
operator|*
operator|&
name|font
argument_list|)
block|;
specifier|const
name|QSymbianTypeFaceExtras
operator|*
name|m_extras
block|;
name|CFont
operator|*
name|m_originalFont
block|;
specifier|const
name|qreal
name|m_originalFontSizeInPixels
block|;
name|CFont
operator|*
name|m_scaledFont
block|;
name|qreal
name|m_scaledFontSizeInPixels
block|;
name|CFont
operator|*
name|m_activeFont
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFontEngineMultiS60
range|:
name|public
name|QFontEngineMulti
block|{
name|public
operator|:
name|QFontEngineMultiS60
argument_list|(
argument|QFontEngine *first
argument_list|,
argument|int script
argument_list|,
argument|const QStringList&fallbackFamilies
argument_list|)
block|;
name|void
name|loadEngine
argument_list|(
argument|int at
argument_list|)
block|;
name|int
name|m_script
block|;
name|QStringList
name|m_fallbackFamilies
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
comment|// QFONTENGINE_S60_P_H
end_comment
end_unit
