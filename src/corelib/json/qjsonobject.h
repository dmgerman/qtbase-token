begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QJSONOBJECT_H
end_ifndef
begin_define
DECL|macro|QJSONOBJECT_H
define|#
directive|define
name|QJSONOBJECT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qjsonvalue.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qiterator.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<initializer_list>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QMap
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QMap
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QString
DECL|typedef|QVariantMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QVariant
operator|>
name|QVariantMap
expr_stmt|;
end_typedef
begin_expr_stmt
DECL|variable|Key
DECL|variable|QHash
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QHash
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QString
DECL|typedef|QVariantHash
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|QVariant
operator|>
name|QVariantHash
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QJsonObject
block|{
name|public
label|:
name|QJsonObject
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_INITIALIZER_LISTS
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QJsonObject
argument_list|(
argument|std::initializer_list<QPair<QString
argument_list|,
argument|QJsonValue>> args
argument_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
for|for
control|(
name|std
operator|::
name|initializer_list
operator|<
name|QPair
operator|<
name|QString
operator|,
name|QJsonValue
operator|>
expr|>
operator|::
name|const_iterator
name|i
operator|=
name|args
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|args
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
name|insert
argument_list|(
name|i
operator|->
name|first
argument_list|,
name|i
operator|->
name|second
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
operator|~
name|QJsonObject
argument_list|()
expr_stmt|;
name|QJsonObject
argument_list|(
specifier|const
name|QJsonObject
operator|&
name|other
argument_list|)
expr_stmt|;
name|QJsonObject
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QJsonObject
operator|&
name|other
operator|)
decl_stmt|;
specifier|static
name|QJsonObject
name|fromVariantMap
parameter_list|(
specifier|const
name|QVariantMap
modifier|&
name|map
parameter_list|)
function_decl|;
name|QVariantMap
name|toVariantMap
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QJsonObject
name|fromVariantHash
parameter_list|(
specifier|const
name|QVariantHash
modifier|&
name|map
parameter_list|)
function_decl|;
name|QVariantHash
name|toVariantHash
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|keys
argument_list|()
specifier|const
expr_stmt|;
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
return|;
block|}
specifier|inline
name|int
name|length
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|QJsonValue
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
name|QJsonValue
name|operator
index|[]
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
name|QJsonValueRef
name|operator
function_decl|[]
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
name|QJsonValue
name|take
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
name|bool
name|contains
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJsonObject
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJsonObject
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|class
name|const_iterator
decl_stmt|;
name|class
name|iterator
block|{
name|friend
name|class
name|const_iterator
decl_stmt|;
name|friend
name|class
name|QJsonObject
decl_stmt|;
name|QJsonObject
modifier|*
name|o
decl_stmt|;
name|int
name|i
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|random_access_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|int
name|difference_type
typedef|;
typedef|typedef
name|QJsonValue
name|value_type
typedef|;
typedef|typedef
name|QJsonValueRef
name|reference
typedef|;
typedef|typedef
name|QJsonValuePtr
name|pointer
typedef|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|iterator
argument_list|()
operator|:
name|o
argument_list|(
name|Q_NULLPTR
argument_list|)
operator|,
name|i
argument_list|(
literal|0
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|iterator
argument_list|(
argument|QJsonObject *obj
argument_list|,
argument|int index
argument_list|)
operator|:
name|o
argument_list|(
name|obj
argument_list|)
operator|,
name|i
argument_list|(
argument|index
argument_list|)
block|{}
specifier|inline
name|QString
name|key
argument_list|()
specifier|const
block|{
return|return
name|o
operator|->
name|keyAt
argument_list|(
name|i
argument_list|)
return|;
block|}
specifier|inline
name|QJsonValueRef
name|value
argument_list|()
specifier|const
block|{
return|return
name|QJsonValueRef
argument_list|(
name|o
argument_list|,
name|i
argument_list|)
return|;
block|}
specifier|inline
name|QJsonValueRef
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|QJsonValueRef
argument_list|(
name|o
argument_list|,
name|i
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|Q_QDOC
specifier|inline
name|QJsonValueRef
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
else|#
directive|else
specifier|inline
name|QJsonValueRefPtr
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|QJsonValueRefPtr
argument_list|(
name|o
argument_list|,
name|i
argument_list|)
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|other
operator|.
name|i
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
name|iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|r
operator|=
operator|*
name|this
block|;
operator|++
name|i
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|iterator
name|r
operator|=
operator|*
name|this
block|;
operator|--
name|i
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|+
operator|(
name|int
name|j
operator|)
specifier|const
block|{
name|iterator
name|r
operator|=
operator|*
name|this
block|;
name|r
operator|.
name|i
operator|+=
name|j
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|-
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|operator
operator|+
operator|(
operator|-
name|j
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|+=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|+=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|-=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|-=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_label
name|public
label|:
end_label
begin_expr_stmt
specifier|inline
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
name|i
operator|==
name|other
operator|.
name|i
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
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
name|friend
name|class
name|iterator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|const_iterator
block|{
name|friend
name|class
name|iterator
decl_stmt|;
specifier|const
name|QJsonObject
modifier|*
name|o
decl_stmt|;
name|int
name|i
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|random_access_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|int
name|difference_type
typedef|;
typedef|typedef
name|QJsonValue
name|value_type
typedef|;
typedef|typedef
name|QJsonValue
name|reference
typedef|;
typedef|typedef
name|QJsonValuePtr
name|pointer
typedef|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|const_iterator
argument_list|()
operator|:
name|o
argument_list|(
name|Q_NULLPTR
argument_list|)
operator|,
name|i
argument_list|(
literal|0
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|const_iterator
argument_list|(
argument|const QJsonObject *obj
argument_list|,
argument|int index
argument_list|)
operator|:
name|o
argument_list|(
name|obj
argument_list|)
operator|,
name|i
argument_list|(
argument|index
argument_list|)
block|{}
specifier|inline
name|const_iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|other
argument_list|)
operator|:
name|o
argument_list|(
name|other
operator|.
name|o
argument_list|)
operator|,
name|i
argument_list|(
argument|other.i
argument_list|)
block|{}
specifier|inline
name|QString
name|key
argument_list|()
specifier|const
block|{
return|return
name|o
operator|->
name|keyAt
argument_list|(
name|i
argument_list|)
return|;
block|}
specifier|inline
name|QJsonValue
name|value
argument_list|()
specifier|const
block|{
return|return
name|o
operator|->
name|valueAt
argument_list|(
name|i
argument_list|)
return|;
block|}
specifier|inline
name|QJsonValue
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|o
operator|->
name|valueAt
argument_list|(
name|i
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|Q_QDOC
specifier|inline
name|QJsonValue
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
specifier|inline
name|QJsonValuePtr
name|operator
operator|->
expr|(
end_expr_stmt
begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|QJsonValuePtr
argument_list|(
name|o
operator|->
name|valueAt
argument_list|(
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
specifier|inline
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
name|i
operator|==
name|other
operator|.
name|i
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
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|const_iterator
name|r
operator|=
operator|*
name|this
block|;
operator|++
name|i
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|const_iterator
name|r
operator|=
operator|*
name|this
block|;
operator|--
name|i
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|+
operator|(
name|int
name|j
operator|)
specifier|const
block|{
name|const_iterator
name|r
operator|=
operator|*
name|this
block|;
name|r
operator|.
name|i
operator|+=
name|j
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|-
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|operator
operator|+
operator|(
operator|-
name|j
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|+=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|+=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|-=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|-=
name|j
block|;
return|return
operator|*
name|this
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
name|iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|other
operator|.
name|i
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
name|iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
name|friend
name|class
name|const_iterator
decl_stmt|;
end_decl_stmt
begin_comment
comment|// STL style
end_comment
begin_function
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|constBegin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|constEnd
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function_decl
name|iterator
name|erase
parameter_list|(
name|iterator
name|it
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// more Qt
end_comment
begin_typedef
typedef|typedef
name|iterator
name|Iterator
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|const_iterator
name|ConstIterator
typedef|;
end_typedef
begin_function_decl
name|iterator
name|find
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|const_iterator
name|find
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
block|{
return|return
name|constFind
argument_list|(
name|key
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|const_iterator
name|constFind
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|iterator
name|insert
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QJsonValue
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// STL compatibility
end_comment
begin_typedef
typedef|typedef
name|QJsonValue
name|mapped_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|QString
name|key_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|size_type
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|friend
name|class
name|QJsonPrivate
operator|::
name|Data
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|friend
name|class
name|QJsonValue
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QJsonDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QJsonValueRef
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|friend
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QJsonObject
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QJsonObject
argument_list|(
name|QJsonPrivate
operator|::
name|Data
operator|*
name|data
argument_list|,
name|QJsonPrivate
operator|::
name|Object
operator|*
name|object
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|initialize
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|detach
parameter_list|(
name|uint
name|reserve
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|compact
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QString
name|keyAt
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QJsonValue
name|valueAt
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setValueAt
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|QJsonValue
modifier|&
name|val
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QJsonPrivate
operator|::
name|Data
operator|*
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QJsonPrivate
operator|::
name|Object
operator|*
name|o
expr_stmt|;
end_expr_stmt
begin_if
unit|};
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_JSON_READONLY
argument_list|)
end_if
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QJsonObject
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QJSONOBJECT_H
end_comment
end_unit
