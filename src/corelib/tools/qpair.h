begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAIR_H
end_ifndef
begin_define
DECL|macro|QPAIR_H
define|#
directive|define
name|QPAIR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
expr|struct
DECL|struct|QPair
name|QPair
block|{
DECL|typedef|first_type
typedef|typedef
name|T1
name|first_type
typedef|;
end_expr_stmt
begin_typedef
DECL|typedef|second_type
typedef|typedef
name|T2
name|second_type
typedef|;
end_typedef
begin_macro
DECL|function|QPair
name|Q_DECL_CONSTEXPR
end_macro
begin_expr_stmt
DECL|function|QPair
name|QPair
argument_list|()
operator|:
name|first
argument_list|()
operator|,
name|second
argument_list|()
block|{}
DECL|function|QPair
name|Q_DECL_CONSTEXPR
name|QPair
argument_list|(
specifier|const
name|T1
operator|&
name|t1
argument_list|,
specifier|const
name|T2
operator|&
name|t2
argument_list|)
operator|:
name|first
argument_list|(
name|t1
argument_list|)
operator|,
name|second
argument_list|(
argument|t2
argument_list|)
block|{}
comment|// compiler-generated copy/move ctor/assignment operators are fine!
DECL|member|TT1
name|template
operator|<
name|typename
name|TT1
operator|,
name|typename
name|TT2
operator|>
DECL|function|QPair
name|Q_DECL_CONSTEXPR
name|QPair
argument_list|(
specifier|const
name|QPair
operator|<
name|TT1
argument_list|,
name|TT2
operator|>
operator|&
name|p
argument_list|)
operator|:
name|first
argument_list|(
name|p
operator|.
name|first
argument_list|)
operator|,
name|second
argument_list|(
argument|p.second
argument_list|)
block|{}
DECL|member|TT1
name|template
operator|<
name|typename
name|TT1
operator|,
name|typename
name|TT2
operator|>
DECL|member|operator
name|Q_DECL_RELAXED_CONSTEXPR
name|QPair
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPair
operator|<
name|TT1
operator|,
name|TT2
operator|>
operator|&
name|p
operator|)
block|{
name|first
operator|=
name|p
operator|.
name|first
block|;
name|second
operator|=
name|p
operator|.
name|second
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_expr_stmt
name|template
operator|<
name|typename
name|TT1
operator|,
name|typename
name|TT2
operator|>
DECL|function|QPair
name|Q_DECL_CONSTEXPR
name|QPair
argument_list|(
name|QPair
operator|<
name|TT1
argument_list|,
name|TT2
operator|>
operator|&&
name|p
argument_list|)
operator|:
name|first
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|p
operator|.
name|first
argument_list|)
argument_list|)
operator|,
name|second
argument_list|(
argument|std::move(p.second)
argument_list|)
block|{}
DECL|member|TT1
name|template
operator|<
name|typename
name|TT1
operator|,
name|typename
name|TT2
operator|>
DECL|member|operator
name|Q_DECL_RELAXED_CONSTEXPR
name|QPair
operator|&
name|operator
operator|=
operator|(
name|QPair
operator|<
name|TT1
operator|,
name|TT2
operator|>
operator|&&
name|p
operator|)
block|{
name|first
operator|=
name|std
operator|::
name|move
argument_list|(
name|p
operator|.
name|first
argument_list|)
block|;
name|second
operator|=
name|std
operator|::
name|move
argument_list|(
name|p
operator|.
name|second
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|Q_DECL_RELAXED_CONSTEXPR
name|void
name|swap
parameter_list|(
name|QPair
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOEXCEPT_EXPR
parameter_list|(
function|noexcept
parameter_list|(
function|qSwap
parameter_list|(
name|other
operator|.
name|first
parameter_list|,
name|other
operator|.
name|first
parameter_list|)
end_function
begin_expr_stmt
unit|)
operator|&&
name|noexcept
argument_list|(
name|qSwap
argument_list|(
name|other
operator|.
name|second
argument_list|,
name|other
operator|.
name|second
argument_list|)
argument_list|)
end_expr_stmt
begin_block
unit|)
block|{
comment|// use qSwap() to pick up ADL swaps automatically:
name|qSwap
argument_list|(
name|first
argument_list|,
name|other
operator|.
name|first
argument_list|)
expr_stmt|;
name|qSwap
argument_list|(
name|second
argument_list|,
name|other
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
end_block
begin_decl_stmt
name|T1
name|first
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|second
name|T2
name|second
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|member|second
unit|};
DECL|variable|T1
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
DECL|function|noexcept
name|void
name|swap
argument_list|(
argument|QPair<T1
argument_list|,
argument|T2>&lhs
argument_list|,
argument|QPair<T1
argument_list|,
argument|T2>&rhs
argument_list|)
name|Q_DECL_NOEXCEPT_EXPR
argument_list|(
argument|noexcept(lhs.swap(rhs))
argument_list|)
block|{
name|lhs
operator|.
name|swap
argument_list|(
name|rhs
argument_list|)
block|; }
comment|// mark QPair<T1,T2> as complex/movable/primitive depending on the
comment|// typeinfos of the constituents:
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|variable|T1
DECL|variable|T1
DECL|variable|T2
DECL|variable|T1
name|class
name|QTypeInfo
operator|<
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
expr|>
operator|:
name|public
name|QTypeInfoMerger
operator|<
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|,
name|T1
operator|,
name|T2
operator|>
block|{}
expr_stmt|;
end_expr_stmt
begin_comment
DECL|variable|T1
DECL|variable|T1
DECL|variable|T2
DECL|variable|T1
comment|// Q_DECLARE_TYPEINFO
end_comment
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_DECL_CONSTEXPR
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|first
operator|==
name|p2
operator|.
name|first
operator|&&
name|p1
operator|.
name|second
operator|==
name|p2
operator|.
name|second
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_DECL_CONSTEXPR
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
operator|!
operator|(
name|p1
operator|==
name|p2
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_DECL_CONSTEXPR
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|first
operator|<
name|p2
operator|.
name|first
operator|||
operator|(
operator|!
operator|(
name|p2
operator|.
name|first
operator|<
name|p1
operator|.
name|first
operator|)
operator|&&
name|p1
operator|.
name|second
operator|<
name|p2
operator|.
name|second
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_DECL_CONSTEXPR
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p2
operator|<
name|p1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|variable|operator
name|Q_DECL_CONSTEXPR
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
operator|!
operator|(
name|p2
operator|<
name|p1
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_DECL_CONSTEXPR
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
operator|!
operator|(
name|p1
operator|<
name|p2
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|variable|T1
DECL|function|qMakePair
name|Q_DECL_CONSTEXPR
name|Q_OUTOFLINE_TEMPLATE
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
name|qMakePair
argument_list|(
argument|const T1&x
argument_list|,
argument|const T2&y
argument_list|)
block|{
return|return
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|(
name|x
operator|,
name|y
operator|)
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAIR_H
end_comment
end_unit
