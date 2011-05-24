begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMARGINS_H
end_ifndef
begin_define
DECL|macro|QMARGINS_H
define|#
directive|define
name|QMARGINS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QMargins
decl_stmt|{ public:     QMargins(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_macro
name|QMargins
argument_list|(
argument|int left
argument_list|,
argument|int top
argument_list|,
argument|int right
argument_list|,
argument|int bottom
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|left
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|top
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|right
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|bottom
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setLeft
parameter_list|(
name|int
name|left
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setTop
parameter_list|(
name|int
name|top
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setRight
parameter_list|(
name|int
name|right
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setBottom
parameter_list|(
name|int
name|bottom
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|int
name|m_left
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_top
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_right
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_bottom
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|friend
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMargins
operator|&
operator|,
specifier|const
name|QMargins
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMargins
operator|&
operator|,
specifier|const
name|QMargins
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMargins
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*****************************************************************************   QMargins inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
DECL|function|QMargins
specifier|inline
name|QMargins
operator|::
name|QMargins
argument_list|()
block|{
name|m_top
operator|=
name|m_bottom
operator|=
name|m_left
operator|=
name|m_right
operator|=
literal|0
block|; }
DECL|function|QMargins
specifier|inline
name|QMargins
operator|::
name|QMargins
argument_list|(
argument|int aleft
argument_list|,
argument|int atop
argument_list|,
argument|int aright
argument_list|,
argument|int abottom
argument_list|)
operator|:
name|m_left
argument_list|(
name|aleft
argument_list|)
operator|,
name|m_top
argument_list|(
name|atop
argument_list|)
operator|,
name|m_right
argument_list|(
name|aright
argument_list|)
operator|,
name|m_bottom
argument_list|(
argument|abottom
argument_list|)
block|{}
DECL|function|isNull
specifier|inline
name|bool
name|QMargins
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|m_left
operator|==
literal|0
operator|&&
name|m_top
operator|==
literal|0
operator|&&
name|m_right
operator|==
literal|0
operator|&&
name|m_bottom
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|left
specifier|inline
name|int
name|QMargins
operator|::
name|left
argument_list|()
specifier|const
block|{
return|return
name|m_left
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|top
specifier|inline
name|int
name|QMargins
operator|::
name|top
argument_list|()
specifier|const
block|{
return|return
name|m_top
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|right
specifier|inline
name|int
name|QMargins
operator|::
name|right
argument_list|()
specifier|const
block|{
return|return
name|m_right
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|bottom
specifier|inline
name|int
name|QMargins
operator|::
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|m_bottom
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setLeft
specifier|inline
name|void
name|QMargins
operator|::
name|setLeft
argument_list|(
argument|int aleft
argument_list|)
block|{
name|m_left
operator|=
name|aleft
block|; }
DECL|function|setTop
specifier|inline
name|void
name|QMargins
operator|::
name|setTop
argument_list|(
argument|int atop
argument_list|)
block|{
name|m_top
operator|=
name|atop
block|; }
DECL|function|setRight
specifier|inline
name|void
name|QMargins
operator|::
name|setRight
argument_list|(
argument|int aright
argument_list|)
block|{
name|m_right
operator|=
name|aright
block|; }
DECL|function|setBottom
specifier|inline
name|void
name|QMargins
operator|::
name|setBottom
argument_list|(
argument|int abottom
argument_list|)
block|{
name|m_bottom
operator|=
name|abottom
block|; }
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMargins
operator|&
name|m1
operator|,
specifier|const
name|QMargins
operator|&
name|m2
operator|)
block|{
return|return
name|m1
operator|.
name|m_left
operator|==
name|m2
operator|.
name|m_left
operator|&&
name|m1
operator|.
name|m_top
operator|==
name|m2
operator|.
name|m_top
operator|&&
name|m1
operator|.
name|m_right
operator|==
name|m2
operator|.
name|m_right
operator|&&
name|m1
operator|.
name|m_bottom
operator|==
name|m2
operator|.
name|m_bottom
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMargins
operator|&
name|m1
operator|,
specifier|const
name|QMargins
operator|&
name|m2
operator|)
block|{
return|return
name|m1
operator|.
name|m_left
operator|!=
name|m2
operator|.
name|m_left
operator|||
name|m1
operator|.
name|m_top
operator|!=
name|m2
operator|.
name|m_top
operator|||
name|m1
operator|.
name|m_right
operator|!=
name|m2
operator|.
name|m_right
operator|||
name|m1
operator|.
name|m_bottom
operator|!=
name|m2
operator|.
name|m_bottom
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QMargins
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMARGINS_H
end_comment
end_unit
