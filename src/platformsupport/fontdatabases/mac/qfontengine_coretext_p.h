begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINE_CORETEXT_P_H
end_ifndef
begin_define
DECL|macro|QFONTENGINE_CORETEXT_P_H
define|#
directive|define
name|QFONTENGINE_CORETEXT_P_H
end_define
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<ApplicationServices/ApplicationServices.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
operator|||
operator|(
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_5
operator|)
end_if
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QRawFontPrivate
name|class
name|QRawFontPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCoreTextFontEngine
range|:
name|public
name|QFontEngine
block|{
name|public
operator|:
name|QCoreTextFontEngine
argument_list|(
argument|CTFontRef font
argument_list|,
argument|const QFontDef&def
argument_list|)
block|;
name|QCoreTextFontEngine
argument_list|(
argument|CGFontRef font
argument_list|,
argument|const QFontDef&def
argument_list|)
block|;
operator|~
name|QCoreTextFontEngine
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
literal|"QCoreTextFontEngine"
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
name|bool
name|supportsSubPixelPositions
argument_list|()
specifier|const
block|{
return|return
name|true
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
name|bool
name|getSfntTableData
argument_list|(
argument|uint
comment|/*tag*/
argument_list|,
argument|uchar *
comment|/*buffer*/
argument_list|,
argument|uint *
comment|/*length*/
argument_list|)
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
argument|glyph_t
argument_list|,
argument|QFixed subPixelPosition
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
name|virtual
name|qreal
name|minRightBearing
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
name|QFixed
name|emSquareSize
argument_list|()
specifier|const
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
name|private
operator|:
name|friend
name|class
name|QRawFontPrivate
block|;
name|void
name|init
argument_list|()
block|;
name|QImage
name|imageForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|,
argument|int margin
argument_list|,
argument|bool colorful
argument_list|)
block|;
name|CTFontRef
name|ctfont
block|;
name|CGFontRef
name|cgFont
block|;
name|int
name|synthesisFlags
block|;
name|CGAffineTransform
name|transform
block|;
name|QFixed
name|avgCharWidth
block|; }
decl_stmt|;
end_decl_stmt
begin_function_decl
name|CGAffineTransform
name|qt_transform_from_fontdef
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !defined(Q_WS_MAC) || (MAC_OS_X_VERSION_MAX_ALLOWED>= MAC_OS_X_VERSION_10_5)
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTENGINE_CORETEXT_P_H
end_comment
end_unit
