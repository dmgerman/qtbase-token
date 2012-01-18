begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qjsonvalue.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
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
name|bidirectional_iterator_tag
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
comment|//        typedef T *pointer;
typedef|typedef
name|QJsonValueRef
name|reference
typedef|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|iterator
argument_list|()
operator|:
name|o
argument_list|(
literal|0
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
comment|//inline T *operator->() const { return&concrete(i)->value; }
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
name|public
label|:
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
block|}
empty_stmt|;
name|friend
name|class
name|iterator
decl_stmt|;
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
name|bidirectional_iterator_tag
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
name|Q_DECL_CONSTEXPR
specifier|inline
name|const_iterator
argument_list|()
operator|:
name|o
argument_list|(
literal|0
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
comment|//inline const T *operator->() const { return&concrete(i)->value; }
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
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|o
operator|.
name|i
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|o
operator|.
name|i
return|;
block|}
block|}
empty_stmt|;
name|friend
name|class
name|const_iterator
decl_stmt|;
comment|// STL style
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
name|iterator
name|erase
parameter_list|(
name|iterator
name|it
parameter_list|)
function_decl|;
comment|// more Qt
typedef|typedef
name|iterator
name|Iterator
typedef|;
typedef|typedef
name|const_iterator
name|ConstIterator
typedef|;
name|iterator
name|find
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
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
comment|// STL compatibility
typedef|typedef
name|QJsonValue
name|mapped_type
typedef|;
typedef|typedef
name|QString
name|key_type
typedef|;
typedef|typedef
name|int
name|size_type
typedef|;
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
name|private
label|:
name|friend
name|class
name|QJsonPrivate
operator|::
name|Data
expr_stmt|;
name|friend
name|class
name|QJsonValue
decl_stmt|;
name|friend
name|class
name|QJsonDocument
decl_stmt|;
name|friend
name|class
name|QJsonValueRef
decl_stmt|;
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
name|void
name|detach
parameter_list|(
name|uint
name|reserve
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|compact
parameter_list|()
function_decl|;
name|QString
name|keyAt
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QJsonValue
name|valueAt
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
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
name|QJsonPrivate
operator|::
name|Data
operator|*
name|d
expr_stmt|;
name|QJsonPrivate
operator|::
name|Object
operator|*
name|o
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
name|QJsonObject
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
comment|// QJSONOBJECT_H
end_comment
end_unit
