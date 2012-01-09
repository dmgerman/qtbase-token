begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSREPLY_H
end_ifndef
begin_define
DECL|macro|QDBUSREPLY_H
define|#
directive|define
name|QDBUSREPLY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmessage.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbuserror.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusextratypes.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbuspendingreply.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function_decl
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|Q_DBUS_EXPORT
name|void
name|qDBusReplyFill
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|reply
parameter_list|,
name|QDBusError
modifier|&
name|error
parameter_list|,
name|QVariant
modifier|&
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QDBusReply
block|{
typedef|typedef
name|T
name|Type
typedef|;
name|public
operator|:
specifier|inline
name|QDBusReply
argument_list|(
argument|const QDBusMessage&reply
argument_list|)
block|{
operator|*
name|this
operator|=
name|reply
block|;     }
specifier|inline
name|QDBusReply
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QDBusMessage
operator|&
name|reply
operator|)
block|{
name|QVariant
name|data
argument_list|(
name|qMetaTypeId
argument_list|(
operator|&
name|m_data
argument_list|)
argument_list|,
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
block|;
name|qDBusReplyFill
argument_list|(
name|reply
argument_list|,
name|m_error
argument_list|,
name|data
argument_list|)
block|;
name|m_data
operator|=
name|qvariant_cast
operator|<
name|Type
operator|>
operator|(
name|data
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QDBusReply
argument_list|(
argument|const QDBusPendingCall&pcall
argument_list|)
block|{
operator|*
name|this
operator|=
name|pcall
block|;     }
specifier|inline
name|QDBusReply
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QDBusPendingCall
operator|&
name|pcall
operator|)
block|{
name|QDBusPendingCall
name|other
argument_list|(
name|pcall
argument_list|)
block|;
name|other
operator|.
name|waitForFinished
argument_list|()
block|;
return|return
operator|*
name|this
operator|=
name|other
operator|.
name|reply
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QDBusReply
argument_list|(
argument|const QDBusPendingReply<T>&reply
argument_list|)
block|{
operator|*
name|this
operator|=
name|static_cast
operator|<
name|QDBusPendingCall
operator|>
operator|(
name|reply
operator|)
block|;     }
specifier|inline
name|QDBusReply
argument_list|(
specifier|const
name|QDBusError
operator|&
name|dbusError
operator|=
name|QDBusError
argument_list|()
argument_list|)
operator|:
name|m_error
argument_list|(
name|dbusError
argument_list|)
operator|,
name|m_data
argument_list|(
argument|Type()
argument_list|)
block|{     }
specifier|inline
name|QDBusReply
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QDBusError
operator|&
name|dbusError
operator|)
block|{
name|m_error
operator|=
name|dbusError
block|;
name|m_data
operator|=
name|Type
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|QDBusReply
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusReply
operator|&
name|other
operator|)
block|{
name|m_error
operator|=
name|other
operator|.
name|m_error
block|;
name|m_data
operator|=
name|other
operator|.
name|m_data
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_error
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|()
block|{
return|return
name|m_error
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|Type
name|value
argument_list|()
specifier|const
block|{
return|return
name|m_data
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|operator
name|Type
argument_list|()
specifier|const
block|{
return|return
name|m_data
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QDBusError
name|m_error
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Type
name|m_data
decl_stmt|;
end_decl_stmt
begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|Q_QDOC
end_ifndef
begin_comment
comment|// specialize for QVariant:
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|QDBusReply
operator|<
name|QVariant
operator|>
operator|&
DECL|member|operator
name|QDBusReply
operator|<
name|QVariant
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|QDBusMessage
operator|&
name|reply
operator|)
block|{
name|void
operator|*
name|null
operator|=
literal|0
block|;
name|QVariant
name|data
argument_list|(
name|qMetaTypeId
operator|<
name|QDBusVariant
operator|>
operator|(
operator|)
argument_list|,
name|null
argument_list|)
block|;
name|qDBusReplyFill
argument_list|(
name|reply
argument_list|,
name|m_error
argument_list|,
name|data
argument_list|)
block|;
name|m_data
operator|=
name|qvariant_cast
operator|<
name|QDBusVariant
operator|>
operator|(
name|data
operator|)
operator|.
name|variant
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_comment
comment|// specialize for void:
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|QDBusReply
operator|<
name|void
operator|>
block|{
name|public
operator|:
specifier|inline
name|QDBusReply
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|reply
argument_list|)
operator|:
name|m_error
argument_list|(
argument|reply
argument_list|)
block|{     }
specifier|inline
name|QDBusReply
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QDBusMessage
operator|&
name|reply
operator|)
block|{
name|m_error
operator|=
name|reply
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDBusReply
argument_list|(
specifier|const
name|QDBusError
operator|&
name|dbusError
operator|=
name|QDBusError
argument_list|()
argument_list|)
operator|:
name|m_error
argument_list|(
argument|dbusError
argument_list|)
block|{     }
specifier|inline
name|QDBusReply
argument_list|(
argument|const QDBusPendingCall&pcall
argument_list|)
block|{
operator|*
name|this
operator|=
name|pcall
block|;     }
specifier|inline
name|QDBusReply
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QDBusPendingCall
operator|&
name|pcall
operator|)
block|{
name|QDBusPendingCall
name|other
argument_list|(
name|pcall
argument_list|)
block|;
name|other
operator|.
name|waitForFinished
argument_list|()
block|;
return|return
operator|*
name|this
operator|=
name|other
operator|.
name|reply
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|QDBusReply
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusError
operator|&
name|dbusError
operator|)
block|{
name|m_error
operator|=
name|dbusError
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QDBusReply
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusReply
operator|&
name|other
operator|)
block|{
name|m_error
operator|=
name|other
operator|.
name|m_error
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_error
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|()
block|{
return|return
name|m_error
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QDBusError
name|m_error
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
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
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
