begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINE_X11_P_H
end_ifndef
begin_define
DECL|macro|QFONTENGINE_X11_P_H
define|#
directive|define
name|QFONTENGINE_X11_P_H
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
file|<private/qt_x11_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_ft_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFreetypeFace
name|class
name|QFreetypeFace
decl_stmt|;
end_decl_stmt
begin_comment
comment|// --------------------------------------------------------------------------
end_comment
begin_decl_stmt
name|class
name|QFontEngineMultiXLFD
range|:
name|public
name|QFontEngineMulti
block|{
name|public
operator|:
name|QFontEngineMultiXLFD
argument_list|(
argument|const QFontDef&r
argument_list|,
argument|const QList<int>&l
argument_list|,
argument|int s
argument_list|)
block|;
operator|~
name|QFontEngineMultiXLFD
argument_list|()
block|;
name|void
name|loadEngine
argument_list|(
argument|int at
argument_list|)
block|;
name|private
operator|:
name|QList
operator|<
name|int
operator|>
name|encodings
block|;
name|int
name|screen
block|;
name|QFontDef
name|request
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/**  * \internal The font engine for X Logical Font Description (XLFD) fonts, which is for X11 systems without freetype.  */
end_comment
begin_decl_stmt
name|class
name|QFontEngineXLFD
range|:
name|public
name|QFontEngine
block|{
name|public
operator|:
name|QFontEngineXLFD
argument_list|(
argument|XFontStruct *f
argument_list|,
argument|const QByteArray&name
argument_list|,
argument|int mib
argument_list|)
block|;
operator|~
name|QFontEngineXLFD
argument_list|()
block|;
name|virtual
name|QFontEngine
operator|::
name|FaceId
name|faceId
argument_list|()
specifier|const
block|;
name|QFontEngine
operator|::
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
argument|QTextItem::RenderFlags
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
name|QImage
name|alphaMapForGlyph
argument_list|(
name|glyph_t
argument_list|)
block|;
name|virtual
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|QFontEngine
operator|::
name|XLFD
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
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|;
specifier|inline
name|XFontStruct
operator|*
name|fontStruct
argument_list|()
specifier|const
block|{
return|return
name|_fs
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_FREETYPE
name|FT_Face
name|non_locked_face
argument_list|()
specifier|const
block|;
name|glyph_t
name|glyphIndexToFreetypeGlyphIndex
argument_list|(
argument|glyph_t g
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|uint
name|toUnicode
argument_list|(
argument|glyph_t g
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QBitmap
name|bitmapForGlyphs
argument_list|(
argument|const QGlyphLayout&glyphs
argument_list|,
argument|const glyph_metrics_t&metrics
argument_list|,
argument|QTextItem::RenderFlags flags =
literal|0
argument_list|)
block|;
name|XFontStruct
operator|*
name|_fs
block|;
name|QByteArray
name|_name
block|;
name|QTextCodec
operator|*
name|_codec
block|;
name|int
name|_cmap
block|;
name|int
name|lbearing
block|,
name|rbearing
block|;
name|mutable
name|QFontEngine
operator|::
name|FaceId
name|face_id
block|;
name|mutable
name|QFreetypeFace
operator|*
name|freetype
block|;
name|mutable
name|int
name|synth
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FONTCONFIG
end_ifndef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngineMultiFT
range|:
name|public
name|QFontEngineMulti
block|{
name|public
operator|:
name|QFontEngineMultiFT
argument_list|(
argument|QFontEngine *fe
argument_list|,
argument|FcPattern *firstEnginePattern
argument_list|,
argument|FcPattern *p
argument_list|,
argument|int s
argument_list|,
argument|const QFontDef&request
argument_list|)
block|;
operator|~
name|QFontEngineMultiFT
argument_list|()
block|;
name|void
name|loadEngine
argument_list|(
argument|int at
argument_list|)
block|;
name|private
operator|:
name|QFontDef
name|request
block|;
name|FcPattern
operator|*
name|pattern
block|;
name|FcPattern
operator|*
name|firstEnginePattern
block|;
name|FcFontSet
operator|*
name|fontSet
block|;
name|int
name|screen
block|;
name|int
name|firstFontIndex
block|;
comment|// first font in fontset
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngineX11FT
range|:
name|public
name|QFontEngineFT
block|{
name|public
operator|:
name|explicit
name|QFontEngineX11FT
argument_list|(
specifier|const
name|QFontDef
operator|&
name|fontDef
argument_list|)
operator|:
name|QFontEngineFT
argument_list|(
argument|fontDef
argument_list|)
block|{}
name|explicit
name|QFontEngineX11FT
argument_list|(
argument|FcPattern *pattern
argument_list|,
argument|const QFontDef&fd
argument_list|,
argument|int screen
argument_list|)
block|;
operator|~
name|QFontEngineX11FT
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_XRENDER
name|int
name|xglyph_format
block|;
endif|#
directive|endif
name|protected
operator|:
name|virtual
name|bool
name|uploadGlyphToServer
argument_list|(
argument|QGlyphSet *set
argument_list|,
argument|uint glyphid
argument_list|,
argument|Glyph *g
argument_list|,
argument|GlyphInfo *info
argument_list|,
argument|int glyphDataSize
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|long
name|allocateServerGlyphSet
argument_list|()
block|;
name|virtual
name|void
name|freeServerGlyphSet
argument_list|(
argument|unsigned long id
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FONTCONFIG
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTENGINE_X11_P_H
end_comment
end_unit
