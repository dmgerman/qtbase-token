begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINEDIRECTWRITE_H
end_ifndef
begin_define
DECL|macro|QFONTENGINEDIRECTWRITE_H
define|#
directive|define
name|QFONTENGINEDIRECTWRITE_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIRECTWRITE
end_ifndef
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
file|"private/qfontengine_p.h"
end_include
begin_struct_decl
struct_decl|struct
name|IDWriteFont
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteFontFace
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteFactory
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteBitmapRenderTarget
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteGdiInterop
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFontEngineDirectWrite
range|:
name|public
name|QFontEngine
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QFontEngineDirectWrite
argument_list|(
argument|IDWriteFactory *directWriteFactory
argument_list|,
argument|IDWriteFontFace *directWriteFontFace
argument_list|,
argument|qreal pixelSize
argument_list|)
block|;
operator|~
name|QFontEngineDirectWrite
argument_list|()
block|;
name|QFixed
name|lineThickness
argument_list|()
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
argument|QTextEngine::ShaperFlags
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
name|boundingBox
argument_list|(
argument|glyph_t g
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
name|QFixed
name|xHeight
argument_list|()
specifier|const
block|;
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|;
name|bool
name|supportsSubPixelPositions
argument_list|()
specifier|const
block|;
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
block|;
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
name|QFontEngine
operator|*
name|cloneWithSize
argument_list|(
argument|qreal pixelSize
argument_list|)
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
name|private
operator|:
name|friend
name|class
name|QRawFontPrivate
block|;
name|QImage
name|imageForGlyph
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
name|void
name|collectMetrics
argument_list|()
block|;
name|IDWriteFontFace
operator|*
name|m_directWriteFontFace
block|;
name|IDWriteFactory
operator|*
name|m_directWriteFactory
block|;
name|IDWriteBitmapRenderTarget
operator|*
name|m_directWriteBitmapRenderTarget
block|;
name|QFixed
name|m_lineThickness
block|;
name|int
name|m_unitsPerEm
block|;
name|QFixed
name|m_ascent
block|;
name|QFixed
name|m_descent
block|;
name|QFixed
name|m_xHeight
block|;
name|QFixed
name|m_lineGap
block|;
name|FaceId
name|m_faceId
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
comment|// QT_NO_DIRECTWRITE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTENGINEDIRECTWRITE_H
end_comment
end_unit
