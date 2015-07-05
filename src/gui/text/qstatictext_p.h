begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTATICTEXT_P_H
end_ifndef
begin_define
DECL|macro|QSTATICTEXT_P_H
define|#
directive|define
name|QSTATICTEXT_P_H
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
comment|// of internal files.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|"qstatictext.h"
end_include
begin_include
include|#
directive|include
file|<private/qtextureglyphcache_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// ### Qt 6: Unexport again, if QOpenGLStaticTextUserData (the one from QtOpenGL) is gone by then
name|class
name|Q_GUI_EXPORT
name|QStaticTextUserData
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|NoUserData
block|,
name|OpenGLUserData
block|}
enum|;
name|QStaticTextUserData
argument_list|(
argument|Type t
argument_list|)
block|:
name|ref
argument_list|(
literal|0
argument_list|)
operator|,
name|type
argument_list|(
argument|t
argument_list|)
block|{}
name|virtual
operator|~
name|QStaticTextUserData
argument_list|()
expr_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|Type
name|type
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QStaticTextItem
block|{
name|public
label|:
name|QStaticTextItem
argument_list|()
operator|:
name|useBackendOptimizations
argument_list|(
name|false
argument_list|)
operator|,
name|userDataNeedsUpdate
argument_list|(
literal|0
argument_list|)
operator|,
name|usesRawFont
argument_list|(
literal|0
argument_list|)
operator|,
name|m_fontEngine
argument_list|(
literal|0
argument_list|)
operator|,
name|m_userData
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|setUserData
argument_list|(
argument|QStaticTextUserData *newUserData
argument_list|)
block|{
name|m_userData
operator|=
name|newUserData
block|;     }
name|QStaticTextUserData
operator|*
name|userData
argument_list|()
specifier|const
block|{
return|return
name|m_userData
operator|.
name|data
argument_list|()
return|;
block|}
name|void
name|setFontEngine
parameter_list|(
name|QFontEngine
modifier|*
name|fe
parameter_list|)
block|{
name|m_fontEngine
operator|=
name|fe
expr_stmt|;
block|}
name|QFontEngine
operator|*
name|fontEngine
argument_list|()
specifier|const
block|{
return|return
name|m_fontEngine
operator|.
name|data
argument_list|()
return|;
block|}
union|union
block|{
name|QFixedPoint
modifier|*
name|glyphPositions
decl_stmt|;
comment|// 8 bytes per glyph
name|int
name|positionOffset
decl_stmt|;
block|}
union|;
union|union
block|{
name|glyph_t
modifier|*
name|glyphs
decl_stmt|;
comment|// 4 bytes per glyph
name|int
name|glyphOffset
decl_stmt|;
block|}
union|;
comment|// =================
comment|// 12 bytes per glyph
comment|// 8 bytes for pointers
name|int
name|numGlyphs
decl_stmt|;
comment|// 4 bytes per item
name|QFont
name|font
decl_stmt|;
comment|// 8 bytes per item
name|QColor
name|color
decl_stmt|;
comment|// 10 bytes per item
name|char
name|useBackendOptimizations
range|:
literal|1
decl_stmt|;
comment|// 1 byte per item
name|char
name|userDataNeedsUpdate
range|:
literal|1
decl_stmt|;
comment|//
name|char
name|usesRawFont
range|:
literal|1
decl_stmt|;
comment|//
name|private
label|:
comment|// private to avoid abuse
name|QExplicitlySharedDataPointer
operator|<
name|QFontEngine
operator|>
name|m_fontEngine
expr_stmt|;
comment|// 4 bytes per item
name|QExplicitlySharedDataPointer
operator|<
name|QStaticTextUserData
operator|>
name|m_userData
expr_stmt|;
comment|// 8 bytes per item
comment|// ================
comment|// 43 bytes per item
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QStaticTextItem
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QStaticText
name|class
name|QStaticText
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QStaticTextPrivate
block|{
name|public
label|:
name|QStaticTextPrivate
argument_list|()
expr_stmt|;
name|QStaticTextPrivate
argument_list|(
specifier|const
name|QStaticTextPrivate
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QStaticTextPrivate
argument_list|()
expr_stmt|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|paintText
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|pos
parameter_list|,
name|QPainter
modifier|*
name|p
parameter_list|)
function_decl|;
name|void
name|invalidate
parameter_list|()
block|{
name|needsRelayout
operator|=
name|true
expr_stmt|;
block|}
name|QAtomicInt
name|ref
decl_stmt|;
comment|// 4 bytes per text
name|QString
name|text
decl_stmt|;
comment|// 4 bytes per text
name|QFont
name|font
decl_stmt|;
comment|// 8 bytes per text
name|qreal
name|textWidth
decl_stmt|;
comment|// 8 bytes per text
name|QSizeF
name|actualSize
decl_stmt|;
comment|// 16 bytes per text
name|QPointF
name|position
decl_stmt|;
comment|// 16 bytes per text
name|QTransform
name|matrix
decl_stmt|;
comment|// 80 bytes per text
name|QStaticTextItem
modifier|*
name|items
decl_stmt|;
comment|// 4 bytes per text
name|int
name|itemCount
decl_stmt|;
comment|// 4 bytes per text
name|glyph_t
modifier|*
name|glyphPool
decl_stmt|;
comment|// 4 bytes per text
name|QFixedPoint
modifier|*
name|positionPool
decl_stmt|;
comment|// 4 bytes per text
name|QTextOption
name|textOption
decl_stmt|;
comment|// 28 bytes per text
name|unsigned
name|char
name|needsRelayout
range|:
literal|1
decl_stmt|;
comment|// 1 byte per text
name|unsigned
name|char
name|useBackendOptimizations
range|:
literal|1
decl_stmt|;
name|unsigned
name|char
name|textFormat
range|:
literal|2
decl_stmt|;
name|unsigned
name|char
name|untransformedCoordinates
range|:
literal|1
decl_stmt|;
comment|// ================
comment|// 191 bytes per text
specifier|static
name|QStaticTextPrivate
modifier|*
name|get
parameter_list|(
specifier|const
name|QStaticText
modifier|*
name|q
parameter_list|)
function_decl|;
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
comment|// QSTATICTEXT_P_H
end_comment
end_unit
