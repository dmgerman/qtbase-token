begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPOINTER_H
end_ifndef
begin_define
DECL|macro|QPOINTER_H
define|#
directive|define
name|QPOINTER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtypeinfo.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QPointer
block|{
name|Q_STATIC_ASSERT_X
argument_list|(
operator|!
name|QtPrivate
operator|::
name|is_pointer
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"QPointer's template type must not be a pointer type"
argument_list|)
block|;
name|template
operator|<
name|typename
name|U
operator|>
expr|struct
name|TypeSelector
block|{
typedef|typedef
name|QObject
name|Type
typedef|;
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
expr|struct
name|TypeSelector
operator|<
specifier|const
name|U
operator|>
block|{
typedef|typedef
specifier|const
name|QObject
name|Type
typedef|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
typedef|typedef
name|typename
name|TypeSelector
operator|<
name|T
operator|>
operator|::
name|Type
name|QObjectType
expr_stmt|;
end_typedef
begin_expr_stmt
name|QWeakPointer
operator|<
name|QObjectType
operator|>
name|wp
expr_stmt|;
end_expr_stmt
begin_label
name|public
label|:
end_label
begin_expr_stmt
specifier|inline
name|QPointer
argument_list|()
block|{ }
specifier|inline
name|QPointer
argument_list|(
name|T
operator|*
name|p
argument_list|)
operator|:
name|wp
argument_list|(
argument|p
argument_list|,
argument|true
argument_list|)
block|{ }
comment|// compiler-generated copy/move ctor/assignment operators are fine!
comment|// compiler-generated dtor is fine!
ifdef|#
directive|ifdef
name|Q_QDOC
comment|// Stop qdoc from complaining about missing function
operator|~
name|QPointer
argument_list|()
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|inline
name|void
name|swap
parameter_list|(
name|QPointer
modifier|&
name|other
parameter_list|)
block|{
name|wp
operator|.
name|swap
argument_list|(
name|other
operator|.
name|wp
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
name|T
operator|*
name|p
operator|)
block|{
name|wp
operator|.
name|assign
argument_list|(
name|static_cast
operator|<
name|QObjectType
operator|*
operator|>
operator|(
name|p
operator|)
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|T
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|wp
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt
begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|operator
name|T
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|wp
operator|.
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|clear
parameter_list|()
block|{
name|wp
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
name|Q_DECLARE_TYPEINFO_BODY
argument_list|(
name|QPointer
operator|<
name|T
operator|>
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|T
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|==
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
specifier|const
name|T
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|==
name|o
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|T
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|==
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
name|T
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|==
name|o
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|operator
operator|->
expr|(
block|)
operator|==
name|p2
operator|.
name|operator
operator|->
block|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|T
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|!=
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
specifier|const
name|T
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|!=
name|o
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|T
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|!=
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
name|T
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|!=
name|o
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|operator
operator|->
expr|(
block|)
operator|!=
name|p2
operator|.
name|operator
operator|->
block|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|QPointer
operator|<
name|T
operator|>
DECL|function|qPointerFromVariant
name|qPointerFromVariant
argument_list|(
argument|const QVariant&variant
argument_list|)
block|{
return|return
name|QPointer
operator|<
name|T
operator|>
operator|(
name|qobject_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QtSharedPointer
operator|::
name|weakPointerFromVariant_internal
argument_list|(
name|variant
argument_list|)
operator|.
name|data
argument_list|()
operator|)
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
comment|// QT_NO_QOBJECT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPOINTER_H
end_comment
end_unit
