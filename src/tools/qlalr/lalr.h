begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LALR_H
end_ifndef
begin_define
DECL|macro|LALR_H
define|#
directive|define
name|LALR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstack.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlinkedlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<functional>
end_include
begin_decl_stmt
DECL|variable|Rule
name|class
name|Rule
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|State
name|class
name|State
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Grammar
name|class
name|Grammar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Item
name|class
name|Item
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|State
name|class
name|State
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Arrow
name|class
name|Arrow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Automaton
name|class
name|Automaton
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
DECL|variable|_Tp
name|class
name|OrderedSet
operator|:
name|protected
name|QMap
operator|<
name|_Tp
operator|,
name|bool
operator|>
block|{
typedef|typedef
name|QMap
operator|<
name|_Tp
operator|,
name|bool
operator|>
name|_Base
expr_stmt|;
name|public
operator|:
name|class
name|const_iterator
block|{
name|typename
name|_Base
operator|::
name|const_iterator
name|_M_iterator
block|;
name|public
operator|:
name|const_iterator
argument_list|()
block|{}
name|const_iterator
argument_list|(
argument|const typename _Base::const_iterator&it
argument_list|)
operator|:
name|_M_iterator
argument_list|(
argument|it
argument_list|)
block|{}
specifier|const
name|_Tp
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|_M_iterator
operator|.
name|key
argument_list|()
return|;
block|}
specifier|const
name|_Tp
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
operator|&
name|_M_iterator
operator|.
name|key
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|const_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|_M_iterator
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|const_iterator
name|operator
operator|++
operator|(
name|int
operator|)
specifier|const
block|{
name|const_iterator
name|me
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
name|_M_iterator
block|;
return|return
name|me
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|_M_iterator
operator|==
name|other
operator|.
name|_M_iterator
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|_M_iterator
operator|!=
name|other
operator|.
name|_M_iterator
return|;
block|}
end_expr_stmt
begin_typedef
unit|};
typedef|typedef
name|const_iterator
name|iterator
typedef|;
end_typedef
begin_label
name|public
label|:
end_label
begin_macro
name|OrderedSet
argument_list|()
end_macro
begin_block
block|{}
end_block
begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|_Base
operator|::
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|_Base
operator|::
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|_Base
operator|::
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|_Base
operator|::
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|const_iterator
name|find
argument_list|(
specifier|const
name|_Tp
operator|&
name|elt
argument_list|)
decl|const
block|{
return|return
name|const_iterator
argument_list|(
name|_Base
operator|::
name|find
argument_list|(
name|elt
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|QPair
operator|<
name|const_iterator
operator|,
name|bool
operator|>
name|insert
argument_list|(
argument|const _Tp&elt
argument_list|)
block|{
name|int
name|elts
operator|=
name|_Base
operator|::
name|size
argument_list|()
block|;
name|const_iterator
name|it
argument_list|(
name|_Base
operator|::
name|insert
argument_list|(
argument|typename _Base::key_type (elt)
argument_list|,
argument|true
argument_list|)
argument_list|)
block|;
return|return
name|qMakePair
argument_list|(
name|it
argument_list|,
name|elts
operator|!=
name|_Base
operator|::
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QPair
operator|<
name|const_iterator
operator|,
name|bool
operator|>
name|insert
argument_list|(
argument|const_iterator
argument_list|,
argument|const _Tp&elt
argument_list|)
block|{
name|int
name|elts
operator|=
name|_Base
operator|::
name|size
argument_list|()
block|;
name|const_iterator
name|it
argument_list|(
name|_Base
operator|::
name|insert
argument_list|(
argument|typename _Base::key_type (elt)
argument_list|,
argument|true
argument_list|)
argument_list|)
block|;
return|return
name|qMakePair
argument_list|(
name|it
argument_list|,
name|elts
operator|!=
name|_Base
operator|::
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|const
name|_Tp
modifier|&
name|operator
function|[]
parameter_list|(
specifier|const
name|_Tp
modifier|&
name|elt
parameter_list|)
block|{
return|return
operator|*
name|insert
argument_list|(
name|elt
argument_list|)
operator|->
name|first
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|insert
argument_list|(
argument|_InputIterator first
argument_list|,
argument|_InputIterator last
argument_list|)
block|{
for|for
control|(
init|;
name|first
operator|!=
name|last
condition|;
operator|++
name|first
control|)
name|insert
argument_list|(
operator|*
name|first
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_comment
unit|};
comment|// names
end_comment
begin_typedef
DECL|typedef|Name
typedef|typedef
name|QLinkedList
operator|<
name|QString
operator|>
operator|::
name|iterator
name|Name
expr_stmt|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QLinkedList
operator|<
name|QString
operator|>
operator|::
name|iterator
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_typedef
DECL|typedef|NameList
typedef|typedef
name|QLinkedList
operator|<
name|Name
operator|>
name|NameList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|NameSet
typedef|typedef
name|OrderedSet
operator|<
name|Name
operator|>
name|NameSet
expr_stmt|;
end_typedef
begin_comment
comment|// items
end_comment
begin_typedef
DECL|typedef|ItemList
typedef|typedef
name|QLinkedList
operator|<
name|Item
operator|>
name|ItemList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|ItemPointer
typedef|typedef
name|ItemList
operator|::
name|iterator
name|ItemPointer
expr_stmt|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
argument_list|(
name|ItemList
operator|::
name|iterator
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_comment
comment|// rules
end_comment
begin_typedef
DECL|typedef|debug_infot
typedef|typedef
name|QLinkedList
operator|<
name|Rule
operator|>
name|debug_infot
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|RulePointer
typedef|typedef
name|debug_infot
operator|::
name|iterator
name|RulePointer
expr_stmt|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
argument_list|(
name|debug_infot
operator|::
name|iterator
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_typedef
DECL|typedef|Name
DECL|typedef|RuleMap
typedef|typedef
name|QMultiMap
operator|<
name|Name
operator|,
name|RulePointer
operator|>
name|RuleMap
expr_stmt|;
end_typedef
begin_comment
comment|// states
end_comment
begin_typedef
DECL|typedef|StateList
typedef|typedef
name|QLinkedList
operator|<
name|State
operator|>
name|StateList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|StatePointer
typedef|typedef
name|StateList
operator|::
name|iterator
name|StatePointer
expr_stmt|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
argument_list|(
name|StateList
operator|::
name|iterator
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_comment
comment|// arrows
end_comment
begin_typedef
DECL|typedef|Name
DECL|typedef|Bundle
typedef|typedef
name|QMap
operator|<
name|Name
operator|,
name|StatePointer
operator|>
name|Bundle
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Rule
block|{
name|public
label|:
name|void
name|clear
parameter_list|()
block|{
name|lhs
operator|=
name|Name
argument_list|()
expr_stmt|;
name|rhs
operator|.
name|clear
argument_list|()
expr_stmt|;
name|prec
operator|=
name|Name
argument_list|()
expr_stmt|;
block|}
name|public
label|:
name|Name
name|lhs
decl_stmt|;
name|NameList
name|rhs
decl_stmt|;
name|Name
name|prec
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Lookback
block|{
name|public
label|:
name|Lookback
argument_list|(
argument|StatePointer s
argument_list|,
argument|Name n
argument_list|)
block|:
name|state
argument_list|(
name|s
argument_list|)
operator|,
name|nt
argument_list|(
argument|n
argument_list|)
block|{}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Lookback
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|state
operator|==
name|other
operator|.
name|state
operator|&&
name|nt
operator|==
name|other
operator|.
name|nt
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Lookback
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|state
operator|!=
name|other
operator|.
name|state
operator|||
name|nt
operator|!=
name|other
operator|.
name|nt
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Lookback
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|public
label|:
name|StatePointer
name|state
decl_stmt|;
name|Name
name|nt
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Item
block|{
name|public
label|:
specifier|inline
name|NameList
operator|::
name|iterator
name|begin_rhs
argument_list|()
specifier|const
block|{
return|return
name|rule
operator|->
name|rhs
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|NameList
operator|::
name|iterator
name|end_rhs
argument_list|()
specifier|const
block|{
return|return
name|rule
operator|->
name|rhs
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Item
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|rule
operator|==
name|other
operator|.
name|rule
operator|&&
name|dot
operator|==
name|other
operator|.
name|dot
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Item
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|rule
operator|!=
name|other
operator|.
name|rule
operator|||
name|dot
operator|!=
name|other
operator|.
name|dot
return|;
block|}
specifier|inline
name|bool
name|isReduceItem
argument_list|()
specifier|const
block|{
return|return
name|dot
operator|==
name|rule
operator|->
name|rhs
operator|.
name|end
argument_list|()
return|;
block|}
name|Item
name|next
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
name|RulePointer
name|rule
decl_stmt|;
name|NameList
operator|::
name|iterator
name|dot
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|State
block|{
name|public
label|:
name|State
argument_list|(
name|Grammar
operator|*
name|grammar
argument_list|)
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|State
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|kernel
operator|==
name|other
operator|.
name|kernel
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|State
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|kernel
operator|!=
name|other
operator|.
name|kernel
return|;
block|}
name|QPair
operator|<
name|ItemPointer
operator|,
name|bool
operator|>
name|insert
argument_list|(
specifier|const
name|Item
operator|&
name|item
argument_list|)
expr_stmt|;
name|QPair
operator|<
name|ItemPointer
operator|,
name|bool
operator|>
name|insertClosure
argument_list|(
specifier|const
name|Item
operator|&
name|item
argument_list|)
expr_stmt|;
name|public
label|:
comment|// attributes
name|ItemList
name|kernel
decl_stmt|;
name|ItemList
name|closure
decl_stmt|;
name|Bundle
name|bundle
decl_stmt|;
name|QMap
operator|<
name|Name
operator|,
name|NameSet
operator|>
name|reads
expr_stmt|;
name|QMap
operator|<
name|Name
operator|,
name|NameSet
operator|>
name|follows
expr_stmt|;
name|RulePointer
name|defaultReduce
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/////////////////////////////////////////////////////////////
end_comment
begin_comment
comment|// digraph
end_comment
begin_comment
comment|/////////////////////////////////////////////////////////////
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
name|class
name|Node
block|{
name|public
operator|:
typedef|typedef
name|OrderedSet
operator|<
name|Node
operator|<
name|_Tp
operator|>
expr|>
name|Repository
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|typename
name|Repository
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|typename
name|QLinkedList
operator|<
name|iterator
operator|>
operator|::
name|iterator
name|edge_iterator
expr_stmt|;
end_typedef
begin_label
name|public
label|:
end_label
begin_function_decl
specifier|static
name|iterator
name|get
parameter_list|(
name|_Tp
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QPair
operator|<
name|edge_iterator
operator|,
name|bool
operator|>
name|insertEdge
argument_list|(
argument|iterator other
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|edge_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|outs
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|edge_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|outs
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Node
operator|<
name|_Tp
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|data
operator|==
name|other
operator|.
name|data
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Node
operator|<
name|_Tp
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|data
operator|!=
name|other
operator|.
name|data
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Node
operator|<
name|_Tp
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|data
operator|<
name|other
operator|.
name|data
return|;
block|}
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|iterator
name|begin_nodes
parameter_list|()
block|{
return|return
name|repository
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|iterator
name|end_nodes
parameter_list|()
block|{
return|return
name|repository
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|Repository
modifier|&
name|repository
parameter_list|()
block|{
specifier|static
name|Repository
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function
begin_label
name|public
label|:
end_label
begin_comment
comment|// attributes
end_comment
begin_decl_stmt
name|mutable
name|bool
name|root
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|int
name|dfn
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|_Tp
name|data
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|mutable
name|QLinkedList
operator|<
name|iterator
operator|>
name|outs
expr_stmt|;
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
specifier|inline
name|Node
argument_list|()
block|{}
specifier|inline
name|Node
argument_list|(
argument|_Tp d
argument_list|)
operator|:
name|root
argument_list|(
name|true
argument_list|)
operator|,
name|dfn
argument_list|(
literal|0
argument_list|)
operator|,
name|data
argument_list|(
argument|d
argument_list|)
block|{}
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|>
DECL|function|get
name|typename
name|Node
operator|<
name|_Tp
operator|>
operator|::
name|iterator
name|Node
operator|<
name|_Tp
operator|>
operator|::
name|get
argument_list|(
argument|_Tp data
argument_list|)
block|{
name|Node
operator|<
name|_Tp
operator|>
name|tmp
argument_list|(
name|data
argument_list|)
block|;
name|iterator
name|it
operator|=
name|repository
argument_list|()
operator|.
name|find
argument_list|(
name|tmp
argument_list|)
block|;
if|if
condition|(
name|it
operator|!=
name|repository
argument_list|()
operator|.
name|end
argument_list|()
condition|)
return|return
name|it
return|;
end_expr_stmt
begin_return
return|return
name|repository
argument_list|()
operator|.
name|insert
argument_list|(
name|tmp
argument_list|)
operator|.
name|first
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|_Tp
operator|>
DECL|member|iterator
name|QPair
operator|<
name|typename
name|QLinkedList
operator|<
name|typename
name|Node
operator|<
name|_Tp
operator|>
operator|::
name|iterator
operator|>
operator|::
name|iterator
operator|,
name|bool
operator|>
name|Node
operator|<
name|_Tp
operator|>
operator|::
name|insertEdge
argument_list|(
argument|typename Node<_Tp>::iterator other
argument_list|)
specifier|const
block|{
name|edge_iterator
name|it
operator|=
name|std
operator|::
name|find
argument_list|(
name|outs
operator|.
name|begin
argument_list|()
argument_list|,
name|outs
operator|.
name|end
argument_list|()
argument_list|,
name|other
argument_list|)
block|;
if|if
condition|(
name|it
operator|!=
name|outs
operator|.
name|end
argument_list|()
condition|)
return|return
name|qMakePair
argument_list|(
name|it
argument_list|,
name|false
argument_list|)
return|;
name|other
operator|->
name|root
operator|=
name|false
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|qMakePair
argument_list|(
name|outs
operator|.
name|insert
argument_list|(
name|outs
operator|.
name|end
argument_list|()
argument_list|,
name|other
argument_list|)
argument_list|,
name|true
argument_list|)
return|;
end_return
begin_comment
unit|}
comment|/////////////////////////////////////////////////////////////
end_comment
begin_comment
comment|// Grammar
end_comment
begin_comment
comment|/////////////////////////////////////////////////////////////
end_comment
begin_macro
unit|class
name|Grammar
end_macro
begin_block
block|{
name|public
label|:
name|Grammar
argument_list|()
expr_stmt|;
name|Name
name|intern
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isTerminal
argument_list|(
name|Name
name|name
argument_list|)
decl|const
block|{
return|return
name|terminals
operator|.
name|find
argument_list|(
name|name
argument_list|)
operator|!=
name|terminals
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|isNonTerminal
argument_list|(
name|Name
name|name
argument_list|)
decl|const
block|{
return|return
name|non_terminals
operator|.
name|find
argument_list|(
name|name
argument_list|)
operator|!=
name|non_terminals
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|buildRuleMap
parameter_list|()
function_decl|;
name|void
name|buildExtendedGrammar
parameter_list|()
function_decl|;
name|public
label|:
name|QString
name|merged_output
decl_stmt|;
name|QString
name|table_name
decl_stmt|;
name|QString
name|decl_file_name
decl_stmt|;
name|QString
name|impl_file_name
decl_stmt|;
name|QString
name|token_prefix
decl_stmt|;
name|QLinkedList
operator|<
name|QString
operator|>
name|names
expr_stmt|;
name|Name
name|start
decl_stmt|;
name|NameSet
name|terminals
decl_stmt|;
name|NameSet
name|non_terminals
decl_stmt|;
name|QMap
operator|<
name|Name
operator|,
name|QString
operator|>
name|spells
expr_stmt|;
name|debug_infot
name|rules
decl_stmt|;
name|RuleMap
name|rule_map
decl_stmt|;
name|RulePointer
name|goal
decl_stmt|;
name|Name
name|tk_end
decl_stmt|;
name|Name
name|accept_symbol
decl_stmt|;
name|NameSet
name|declared_lhs
decl_stmt|;
name|int
name|expected_shift_reduce
decl_stmt|;
name|int
name|expected_reduce_reduce
decl_stmt|;
enum|enum
name|Assoc
block|{
name|NonAssoc
block|,
name|Left
block|,
name|Right
block|}
enum|;
struct|struct
name|TokenInfo
block|{
name|Assoc
name|assoc
decl_stmt|;
name|int
name|prec
decl_stmt|;
block|}
struct|;
name|QMap
operator|<
name|Name
operator|,
name|TokenInfo
operator|>
name|token_info
expr_stmt|;
name|Assoc
name|current_assoc
decl_stmt|;
name|int
name|current_prec
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Read
block|{
name|public
label|:
specifier|inline
name|Read
argument_list|()
block|{}
specifier|inline
name|Read
argument_list|(
argument|StatePointer s
argument_list|,
argument|Name n
argument_list|)
operator|:
name|state
argument_list|(
name|s
argument_list|)
operator|,
name|nt
argument_list|(
argument|n
argument_list|)
block|{}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Read
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|state
operator|==
name|other
operator|.
name|state
operator|&&
name|nt
operator|==
name|other
operator|.
name|nt
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Read
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|state
operator|!=
name|other
operator|.
name|state
operator|||
name|nt
operator|!=
name|other
operator|.
name|nt
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Read
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|public
label|:
name|StatePointer
name|state
decl_stmt|;
name|Name
name|nt
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
argument_list|(
name|OrderedSet
operator|<
name|Node
operator|<
name|Read
operator|>
expr|>
operator|::
name|const_iterator
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|Include
block|{
name|public
label|:
specifier|inline
name|Include
argument_list|()
block|{}
specifier|inline
name|Include
argument_list|(
argument|StatePointer s
argument_list|,
argument|Name n
argument_list|)
operator|:
name|state
argument_list|(
name|s
argument_list|)
operator|,
name|nt
argument_list|(
argument|n
argument_list|)
block|{}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Include
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|state
operator|==
name|other
operator|.
name|state
operator|&&
name|nt
operator|==
name|other
operator|.
name|nt
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Include
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|state
operator|!=
name|other
operator|.
name|state
operator|||
name|nt
operator|!=
name|other
operator|.
name|nt
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Include
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|public
label|:
name|StatePointer
name|state
decl_stmt|;
name|Name
name|nt
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
argument_list|(
name|OrderedSet
operator|<
name|Node
operator|<
name|Include
operator|>
expr|>
operator|::
name|const_iterator
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|Automaton
block|{
name|public
label|:
name|Automaton
argument_list|(
name|Grammar
operator|*
name|g
argument_list|)
expr_stmt|;
name|QPair
operator|<
name|StatePointer
operator|,
name|bool
operator|>
name|internState
argument_list|(
specifier|const
name|State
operator|&
name|state
argument_list|)
expr_stmt|;
typedef|typedef
name|Node
operator|<
name|Read
operator|>
name|ReadsGraph
expr_stmt|;
typedef|typedef
name|ReadsGraph
operator|::
name|iterator
name|ReadNode
expr_stmt|;
typedef|typedef
name|Node
operator|<
name|Include
operator|>
name|IncludesGraph
expr_stmt|;
typedef|typedef
name|IncludesGraph
operator|::
name|iterator
name|IncludeNode
expr_stmt|;
name|void
name|build
parameter_list|()
function_decl|;
name|void
name|buildNullables
parameter_list|()
function_decl|;
name|void
name|buildLookbackSets
parameter_list|()
function_decl|;
name|void
name|buildDirectReads
parameter_list|()
function_decl|;
name|void
name|buildReadsDigraph
parameter_list|()
function_decl|;
name|void
name|buildReads
parameter_list|()
function_decl|;
name|void
name|visitReadNode
parameter_list|(
name|ReadNode
name|node
parameter_list|)
function_decl|;
name|void
name|buildIncludesAndFollows
parameter_list|()
function_decl|;
name|void
name|buildIncludesDigraph
parameter_list|()
function_decl|;
name|void
name|visitIncludeNode
parameter_list|(
name|IncludeNode
name|node
parameter_list|)
function_decl|;
name|void
name|buildLookaheads
parameter_list|()
function_decl|;
name|void
name|buildDefaultReduceActions
parameter_list|()
function_decl|;
name|void
name|closure
parameter_list|(
name|StatePointer
name|state
parameter_list|)
function_decl|;
name|int
name|id
parameter_list|(
name|RulePointer
name|rule
parameter_list|)
function_decl|;
name|int
name|id
parameter_list|(
name|StatePointer
name|state
parameter_list|)
function_decl|;
name|int
name|id
parameter_list|(
name|Name
name|name
parameter_list|)
function_decl|;
name|void
name|dump
parameter_list|(
name|QTextStream
modifier|&
name|out
parameter_list|,
name|IncludeNode
name|incl
parameter_list|)
function_decl|;
name|void
name|dump
parameter_list|(
name|QTextStream
modifier|&
name|out
parameter_list|,
name|ReadNode
name|rd
parameter_list|)
function_decl|;
name|void
name|dump
parameter_list|(
name|QTextStream
modifier|&
name|out
parameter_list|,
specifier|const
name|Lookback
modifier|&
name|lp
parameter_list|)
function_decl|;
name|public
label|:
comment|// ### private
name|Grammar
modifier|*
name|_M_grammar
decl_stmt|;
name|StateList
name|states
decl_stmt|;
name|StatePointer
name|start
decl_stmt|;
name|NameSet
name|nullables
decl_stmt|;
name|QMultiMap
operator|<
name|ItemPointer
operator|,
name|Lookback
operator|>
name|lookbacks
expr_stmt|;
name|QMap
operator|<
name|ItemPointer
operator|,
name|NameSet
operator|>
name|lookaheads
expr_stmt|;
name|private
label|:
name|QStack
operator|<
name|ReadsGraph
operator|::
name|iterator
operator|>
name|_M_reads_stack
expr_stmt|;
name|int
name|_M_reads_dfn
decl_stmt|;
name|QStack
operator|<
name|IncludesGraph
operator|::
name|iterator
operator|>
name|_M_includes_stack
expr_stmt|;
name|int
name|_M_includes_dfn
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|bool
name|operator
operator|<
operator|(
name|Name
name|a
operator|,
name|Name
name|b
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
name|StatePointer
name|a
operator|,
name|StatePointer
name|b
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
name|ItemPointer
name|a
operator|,
name|ItemPointer
name|b
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|QTextStream
operator|&
name|out
operator|,
specifier|const
name|Name
operator|&
name|n
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|QTextStream
operator|&
name|out
operator|,
specifier|const
name|Rule
operator|&
name|r
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|QTextStream
operator|&
name|out
operator|,
specifier|const
name|Item
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|QTextStream
operator|&
name|out
operator|,
specifier|const
name|NameSet
operator|&
name|ns
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// ... hmm
specifier|extern
name|QTextStream
name|qerr
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|QTextStream
name|qout
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
comment|// LALR_H
end_comment
end_unit
