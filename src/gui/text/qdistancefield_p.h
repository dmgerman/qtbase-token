begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDeclarative module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDISTANCEFIELD_H
end_ifndef
begin_define
DECL|macro|QDISTANCEFIELD_H
define|#
directive|define
name|QDISTANCEFIELD_H
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
file|<qrawfont.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
DECL|macro|QT_DISTANCEFIELD_DEFAULT_BASEFONTSIZE
define|#
directive|define
name|QT_DISTANCEFIELD_DEFAULT_BASEFONTSIZE
value|54
DECL|macro|QT_DISTANCEFIELD_DEFAULT_SCALE
define|#
directive|define
name|QT_DISTANCEFIELD_DEFAULT_SCALE
value|16
DECL|macro|QT_DISTANCEFIELD_DEFAULT_RADIUS
define|#
directive|define
name|QT_DISTANCEFIELD_DEFAULT_RADIUS
value|80
DECL|macro|QT_DISTANCEFIELD_HIGHGLYPHCOUNT
define|#
directive|define
name|QT_DISTANCEFIELD_HIGHGLYPHCOUNT
value|2000
DECL|macro|QT_DISTANCEFIELD_BASEFONTSIZE
define|#
directive|define
name|QT_DISTANCEFIELD_BASEFONTSIZE
parameter_list|(
name|NarrowOutlineFont
parameter_list|)
define|\
value|(NarrowOutlineFont ? QT_DISTANCEFIELD_DEFAULT_BASEFONTSIZE * 2 : \                          QT_DISTANCEFIELD_DEFAULT_BASEFONTSIZE)
DECL|macro|QT_DISTANCEFIELD_SCALE
define|#
directive|define
name|QT_DISTANCEFIELD_SCALE
parameter_list|(
name|NarrowOutlineFont
parameter_list|)
define|\
value|(NarrowOutlineFont ? QT_DISTANCEFIELD_DEFAULT_SCALE / 2 : \                          QT_DISTANCEFIELD_DEFAULT_SCALE)
DECL|macro|QT_DISTANCEFIELD_RADIUS
define|#
directive|define
name|QT_DISTANCEFIELD_RADIUS
parameter_list|(
name|NarrowOutlineFont
parameter_list|)
define|\
value|(NarrowOutlineFont ? QT_DISTANCEFIELD_DEFAULT_RADIUS / 2 : \                          QT_DISTANCEFIELD_DEFAULT_RADIUS)
name|bool
name|Q_GUI_EXPORT
name|qt_fontHasNarrowOutlines
parameter_list|(
specifier|const
name|QRawFont
modifier|&
name|f
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|Q_GUI_EXPORT
name|qt_fontHasNarrowOutlines
parameter_list|(
name|QFontEngine
modifier|*
name|fontEngine
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDistanceFieldData
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QDistanceFieldData
argument_list|()
operator|:
name|glyph
argument_list|(
literal|0
argument_list|)
block|,
name|width
argument_list|(
literal|0
argument_list|)
block|,
name|height
argument_list|(
literal|0
argument_list|)
block|,
name|nbytes
argument_list|(
literal|0
argument_list|)
block|,
name|data
argument_list|(
literal|0
argument_list|)
block|{}
name|QDistanceFieldData
argument_list|(
specifier|const
name|QDistanceFieldData
operator|&
name|other
argument_list|)
block|;
operator|~
name|QDistanceFieldData
argument_list|()
block|;
specifier|static
name|QDistanceFieldData
operator|*
name|create
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
specifier|static
name|QDistanceFieldData
operator|*
name|create
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|bool doubleResolution
argument_list|)
block|;
name|glyph_t
name|glyph
block|;
name|int
name|width
block|;
name|int
name|height
block|;
name|int
name|nbytes
block|;
name|uchar
operator|*
name|data
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDistanceField
block|{
name|public
label|:
name|QDistanceField
argument_list|()
expr_stmt|;
name|QDistanceField
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
empty_stmt|;
name|QDistanceField
argument_list|(
argument|const QRawFont&font
argument_list|,
argument|glyph_t glyph
argument_list|,
argument|bool doubleResolution = false
argument_list|)
empty_stmt|;
name|QDistanceField
argument_list|(
argument|QFontEngine *fontEngine
argument_list|,
argument|glyph_t glyph
argument_list|,
argument|bool doubleResolution = false
argument_list|)
empty_stmt|;
name|QDistanceField
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|glyph_t glyph
argument_list|,
argument|bool doubleResolution = false
argument_list|)
empty_stmt|;
name|QDistanceField
argument_list|(
specifier|const
name|QDistanceField
operator|&
name|other
argument_list|)
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|glyph_t
name|glyph
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setGlyph
parameter_list|(
specifier|const
name|QRawFont
modifier|&
name|font
parameter_list|,
name|glyph_t
name|glyph
parameter_list|,
name|bool
name|doubleResolution
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|setGlyph
parameter_list|(
name|QFontEngine
modifier|*
name|fontEngine
parameter_list|,
name|glyph_t
name|glyph
parameter_list|,
name|bool
name|doubleResolution
init|=
name|false
parameter_list|)
function_decl|;
name|int
name|width
argument_list|()
specifier|const
expr_stmt|;
name|int
name|height
argument_list|()
specifier|const
expr_stmt|;
name|QDistanceField
name|copy
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
operator|=
name|QRect
argument_list|()
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QDistanceField
name|copy
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
name|w
argument_list|,
name|int
name|h
argument_list|)
decl|const
block|{
return|return
name|copy
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
return|;
block|}
name|uchar
modifier|*
name|bits
parameter_list|()
function_decl|;
specifier|const
name|uchar
operator|*
name|bits
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|uchar
operator|*
name|constBits
argument_list|()
specifier|const
expr_stmt|;
name|uchar
modifier|*
name|scanLine
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|const
name|uchar
modifier|*
name|scanLine
argument_list|(
name|int
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|constScanLine
argument_list|(
name|int
argument_list|)
decl|const
decl_stmt|;
name|QImage
name|toImage
argument_list|(
name|QImage
operator|::
name|Format
name|format
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|QDistanceField
argument_list|(
name|QDistanceFieldData
operator|*
name|data
argument_list|)
expr_stmt|;
name|QSharedDataPointer
operator|<
name|QDistanceFieldData
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QDistanceFieldData
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDISTANCEFIELD_H
end_comment
end_unit
