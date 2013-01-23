begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSPENDINGREPLY_H
end_ifndef
begin_define
DECL|macro|QDBUSPENDINGREPLY_H
define|#
directive|define
name|QDBUSPENDINGREPLY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusargument.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbuspendingcall.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|Q_DBUS_EXPORT
name|QDBusPendingReplyData
range|:
name|public
name|QDBusPendingCall
block|{
name|protected
operator|:
name|QDBusPendingReplyData
argument_list|()
block|;
operator|~
name|QDBusPendingReplyData
argument_list|()
block|;
name|void
name|assign
argument_list|(
specifier|const
name|QDBusPendingCall
operator|&
name|call
argument_list|)
block|;
name|void
name|assign
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|)
block|;
name|QVariant
name|argumentAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setMetaTypes
argument_list|(
argument|int count
argument_list|,
argument|const int *metaTypes
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QDBusPendingReplyTypes
block|{
name|template
operator|<
name|int
name|Index
operator|,
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|,
name|typename
name|T7
operator|,
name|typename
name|T8
operator|>
expr|struct
name|Select
block|{
typedef|typedef
name|Select
operator|<
name|Index
operator|-
literal|1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|,
name|T6
operator|,
name|T7
operator|,
name|T8
operator|,
name|void
operator|>
name|Next
expr_stmt|;
typedef|typedef
name|typename
name|Next
operator|::
name|Type
name|Type
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|,
name|typename
name|T7
operator|,
name|typename
name|T8
operator|>
expr|struct
name|Select
operator|<
literal|0
operator|,
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|,
name|T6
operator|,
name|T7
operator|,
name|T8
operator|>
block|{
typedef|typedef
name|T1
name|Type
typedef|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|>
specifier|inline
name|int
name|metaTypeFor
argument_list|(
argument|T1 * =
literal|0
argument_list|)
block|{
return|return
name|qMetaTypeId
operator|<
name|T1
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// specialize for QVariant, allowing it to be used in place of QDBusVariant
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|int
name|metaTypeFor
operator|<
name|QVariant
operator|>
operator|(
name|QVariant
operator|*
operator|)
block|{
return|return
name|qMetaTypeId
operator|<
name|QDBusVariant
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|,
name|typename
name|T7
operator|,
name|typename
name|T8
operator|>
expr|struct
name|ForEach
block|{
typedef|typedef
name|ForEach
operator|<
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|,
name|T6
operator|,
name|T7
operator|,
name|T8
operator|,
name|void
operator|>
name|Next
expr_stmt|;
block|enum
block|{
name|Total
operator|=
name|Next
operator|::
name|Total
operator|+
literal|1
block|}
expr_stmt|;
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|void
name|fillMetaTypes
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
name|metaTypeFor
operator|<
name|T1
operator|>
operator|(
literal|0
operator|)
expr_stmt|;
name|Next
operator|::
name|fillMetaTypes
argument_list|(
operator|++
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|ForEach
operator|<
name|void
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|>
block|{         enum
block|{
name|Total
operator|=
literal|0
block|}
block|;
specifier|static
specifier|inline
name|void
name|fillMetaTypes
argument_list|(
argument|int *
argument_list|)
block|{ }
block|}
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|// namespace QDBusPendingReplyTypes
end_comment
begin_expr_stmt
unit|template
DECL|variable|T1
DECL|variable|T2
DECL|variable|T3
DECL|variable|T4
operator|<
name|typename
name|T1
operator|=
name|void
operator|,
name|typename
name|T2
operator|=
name|void
operator|,
name|typename
name|T3
operator|=
name|void
operator|,
name|typename
name|T4
operator|=
name|void
operator|,
DECL|variable|T5
DECL|variable|T6
DECL|variable|T7
DECL|variable|T8
name|typename
name|T5
operator|=
name|void
operator|,
name|typename
name|T6
operator|=
name|void
operator|,
name|typename
name|T7
operator|=
name|void
operator|,
name|typename
name|T8
operator|=
name|void
operator|>
name|class
name|QDBusPendingReply
operator|:
ifdef|#
directive|ifdef
name|Q_QDOC
name|public
name|QDBusPendingCall
else|#
directive|else
name|public
name|QDBusPendingReplyData
endif|#
directive|endif
block|{
typedef|typedef
name|QDBusPendingReplyTypes
operator|::
name|ForEach
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|,
name|T6
operator|,
name|T7
operator|,
name|T8
operator|>
name|ForEach
expr_stmt|;
name|template
operator|<
name|int
name|Index
operator|>
block|struct
name|Select
operator|:
name|QDBusPendingReplyTypes
operator|::
name|Select
operator|<
name|Index
operator|,
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|,
name|T6
operator|,
name|T7
operator|,
name|T8
operator|>
block|{     }
expr_stmt|;
end_expr_stmt
begin_label
name|public
label|:
end_label
begin_enum
enum|enum
block|{
name|Count
init|=
name|ForEach
operator|::
name|Total
block|}
enum|;
end_enum
begin_expr_stmt
specifier|inline
name|QDBusPendingReply
argument_list|()
block|{ }
specifier|inline
name|QDBusPendingReply
argument_list|(
specifier|const
name|QDBusPendingReply
operator|&
name|other
argument_list|)
operator|:
name|QDBusPendingReplyData
argument_list|(
argument|other
argument_list|)
block|{ }
specifier|inline
comment|/*implicit*/
name|QDBusPendingReply
argument_list|(
argument|const QDBusPendingCall&call
argument_list|)
comment|// required by qdbusxml2cpp-generated code
block|{
operator|*
name|this
operator|=
name|call
block|; }
specifier|inline
comment|/*implicit*/
name|QDBusPendingReply
argument_list|(
argument|const QDBusMessage&message
argument_list|)
block|{
operator|*
name|this
operator|=
name|message
block|; }
specifier|inline
name|QDBusPendingReply
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QDBusPendingReply
operator|&
name|other
operator|)
block|{
name|assign
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|QDBusPendingReply
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusPendingCall
operator|&
name|call
operator|)
block|{
name|assign
argument_list|(
name|call
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QDBusPendingReply
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusMessage
operator|&
name|message
operator|)
block|{
name|assign
argument_list|(
name|message
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|Count
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_NO_USING_KEYWORD
argument_list|)
end_if
begin_decl_stmt
specifier|inline
name|QVariant
name|argumentAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|QDBusPendingReplyData
operator|::
name|argumentAt
argument_list|(
name|index
argument_list|)
return|;
block|}
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|using
name|QDBusPendingReplyData
operator|::
name|argumentAt
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
end_if
begin_expr_stmt
name|bool
name|isFinished
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|waitForFinished
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isError
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDBusError
name|error
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDBusMessage
name|reply
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|int
name|Index
operator|>
specifier|inline
name|Type
name|argumentAt
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|T1
name|value
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|operator
name|T1
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|template
operator|<
name|int
name|Index
operator|>
specifier|inline
specifier|const
name|typename
name|Select
operator|<
name|Index
operator|>
operator|::
name|Type
name|argumentAt
argument_list|()
specifier|const
block|{
name|Q_STATIC_ASSERT_X
argument_list|(
name|Index
operator|>=
literal|0
operator|&&
name|Index
operator|<
name|Count
argument_list|,
literal|"Index out of bounds"
argument_list|)
block|;
typedef|typedef
name|typename
name|Select
operator|<
name|Index
operator|>
operator|::
name|Type
name|ResultType
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|qdbus_cast
operator|<
name|ResultType
operator|>
operator|(
name|argumentAt
argument_list|(
name|Index
argument_list|)
operator|,
literal|0
operator|)
return|;
end_return
begin_expr_stmt
unit|}      inline
name|typename
name|Select
operator|<
literal|0
operator|>
operator|::
name|Type
name|value
argument_list|()
specifier|const
block|{
return|return
name|argumentAt
operator|<
literal|0
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|operator
name|typename
name|Select
operator|<
literal|0
operator|>
operator|::
name|Type
argument_list|()
specifier|const
block|{
return|return
name|argumentAt
operator|<
literal|0
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_function
specifier|inline
name|void
name|calculateMetaTypes
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return;
name|int
name|typeIds
index|[
name|Count
operator|>
literal|0
condition|?
name|Count
else|:
literal|1
index|]
decl_stmt|;
comment|// use at least one since zero-sized arrays aren't valid
name|ForEach
operator|::
name|fillMetaTypes
argument_list|(
name|typeIds
argument_list|)
expr_stmt|;
name|setMetaTypes
argument_list|(
name|Count
argument_list|,
name|typeIds
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|assign
parameter_list|(
specifier|const
name|QDBusPendingCall
modifier|&
name|call
parameter_list|)
block|{
name|QDBusPendingReplyData
operator|::
name|assign
argument_list|(
name|call
argument_list|)
expr_stmt|;
name|calculateMetaTypes
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|assign
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
block|{
name|QDBusPendingReplyData
operator|::
name|assign
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|calculateMetaTypes
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
