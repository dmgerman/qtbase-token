begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_ifndef
ifndef|#
directive|ifndef
name|QHARFBUZZ_P_H
end_ifndef
begin_define
DECL|macro|QHARFBUZZ_P_H
define|#
directive|define
name|QHARFBUZZ_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<harfbuzz-shaper.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
comment|// temporary forward until all the textengine code has been moved to QtCore
name|Q_CORE_EXPORT
name|void
name|qGetCharAttributes
parameter_list|(
specifier|const
name|HB_UChar16
modifier|*
name|string
parameter_list|,
name|hb_uint32
name|stringLength
parameter_list|,
specifier|const
name|HB_ScriptItem
modifier|*
name|items
parameter_list|,
name|hb_uint32
name|numItems
parameter_list|,
name|HB_CharAttributes
modifier|*
name|attributes
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|HB_Bool
name|qShapeItem
parameter_list|(
name|HB_ShaperItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### temporary
end_comment
begin_function_decl
name|Q_CORE_EXPORT
name|HB_Face
name|qHBNewFace
parameter_list|(
name|void
modifier|*
name|font
parameter_list|,
name|HB_GetFontTableFunc
name|tableFunc
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qHBFreeFace
parameter_list|(
name|HB_Face
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|HB_GlyphAttributes
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|HB_FixedPoint
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
