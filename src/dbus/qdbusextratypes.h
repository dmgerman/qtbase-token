begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSEXTRATYPES_H
end_ifndef
begin_define
DECL|macro|QDBUSEXTRATYPES_H
define|#
directive|define
name|QDBUSEXTRATYPES_H
end_define
begin_comment
comment|// define some useful types for D-BUS
end_comment
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|5
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qhashfunctions.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_DBUS_EXPORT
name|QDBusObjectPath
block|{
name|QString
name|m_path
decl_stmt|;
name|public
label|:
specifier|inline
name|QDBusObjectPath
argument_list|()
block|{ }
specifier|inline
name|explicit
name|QDBusObjectPath
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
expr_stmt|;
specifier|inline
name|explicit
name|QDBusObjectPath
parameter_list|(
name|QLatin1String
name|path
parameter_list|)
function_decl|;
specifier|inline
name|explicit
name|QDBusObjectPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
specifier|inline
name|QString
name|path
argument_list|()
specifier|const
block|{
return|return
name|m_path
return|;
block|}
name|private
label|:
name|void
name|doCheck
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|QDBusObjectPath
specifier|inline
name|QDBusObjectPath
operator|::
name|QDBusObjectPath
argument_list|(
specifier|const
name|char
operator|*
name|objectPath
argument_list|)
operator|:
name|m_path
argument_list|(
argument|QString::fromLatin1(objectPath)
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|QDBusObjectPath
specifier|inline
name|QDBusObjectPath
operator|::
name|QDBusObjectPath
argument_list|(
argument|QLatin1String objectPath
argument_list|)
operator|:
name|m_path
argument_list|(
argument|objectPath
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|QDBusObjectPath
specifier|inline
name|QDBusObjectPath
operator|::
name|QDBusObjectPath
argument_list|(
specifier|const
name|QString
operator|&
name|objectPath
argument_list|)
operator|:
name|m_path
argument_list|(
argument|objectPath
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|setPath
specifier|inline
name|void
name|QDBusObjectPath
operator|::
name|setPath
argument_list|(
argument|const QString&objectPath
argument_list|)
block|{
name|m_path
operator|=
name|objectPath
block|;
name|doCheck
argument_list|()
block|; }
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDBusObjectPath
operator|&
name|lhs
operator|,
specifier|const
name|QDBusObjectPath
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|path
argument_list|()
operator|==
name|rhs
operator|.
name|path
argument_list|()
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
name|QDBusObjectPath
operator|&
name|lhs
operator|,
specifier|const
name|QDBusObjectPath
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|path
argument_list|()
operator|!=
name|rhs
operator|.
name|path
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QDBusObjectPath
operator|&
name|lhs
operator|,
specifier|const
name|QDBusObjectPath
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|path
argument_list|()
operator|<
name|rhs
operator|.
name|path
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QDBusObjectPath
modifier|&
name|objectPath
parameter_list|,
name|uint
name|seed
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|objectPath
operator|.
name|path
argument_list|()
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusSignature
block|{
name|QString
name|m_signature
decl_stmt|;
name|public
label|:
specifier|inline
name|QDBusSignature
argument_list|()
block|{ }
specifier|inline
name|explicit
name|QDBusSignature
argument_list|(
specifier|const
name|char
operator|*
name|signature
argument_list|)
expr_stmt|;
specifier|inline
name|explicit
name|QDBusSignature
parameter_list|(
name|QLatin1String
name|signature
parameter_list|)
function_decl|;
specifier|inline
name|explicit
name|QDBusSignature
parameter_list|(
specifier|const
name|QString
modifier|&
name|signature
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setSignature
parameter_list|(
specifier|const
name|QString
modifier|&
name|signature
parameter_list|)
function_decl|;
specifier|inline
name|QString
name|signature
argument_list|()
specifier|const
block|{
return|return
name|m_signature
return|;
block|}
name|private
label|:
name|void
name|doCheck
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|QDBusSignature
specifier|inline
name|QDBusSignature
operator|::
name|QDBusSignature
argument_list|(
specifier|const
name|char
operator|*
name|dBusSignature
argument_list|)
operator|:
name|m_signature
argument_list|(
argument|QString::fromLatin1(dBusSignature)
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|QDBusSignature
specifier|inline
name|QDBusSignature
operator|::
name|QDBusSignature
argument_list|(
argument|QLatin1String dBusSignature
argument_list|)
operator|:
name|m_signature
argument_list|(
argument|dBusSignature
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|QDBusSignature
specifier|inline
name|QDBusSignature
operator|::
name|QDBusSignature
argument_list|(
specifier|const
name|QString
operator|&
name|dBusSignature
argument_list|)
operator|:
name|m_signature
argument_list|(
argument|dBusSignature
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|setSignature
specifier|inline
name|void
name|QDBusSignature
operator|::
name|setSignature
argument_list|(
argument|const QString&dBusSignature
argument_list|)
block|{
name|m_signature
operator|=
name|dBusSignature
block|;
name|doCheck
argument_list|()
block|; }
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDBusSignature
operator|&
name|lhs
operator|,
specifier|const
name|QDBusSignature
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|signature
argument_list|()
operator|==
name|rhs
operator|.
name|signature
argument_list|()
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
name|QDBusSignature
operator|&
name|lhs
operator|,
specifier|const
name|QDBusSignature
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|signature
argument_list|()
operator|!=
name|rhs
operator|.
name|signature
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QDBusSignature
operator|&
name|lhs
operator|,
specifier|const
name|QDBusSignature
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|signature
argument_list|()
operator|<
name|rhs
operator|.
name|signature
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QDBusSignature
modifier|&
name|signature
parameter_list|,
name|uint
name|seed
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|signature
operator|.
name|signature
argument_list|()
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|class
name|QDBusVariant
block|{
name|QVariant
name|m_variant
decl_stmt|;
name|public
label|:
specifier|inline
name|QDBusVariant
argument_list|()
block|{ }
specifier|inline
name|explicit
name|QDBusVariant
argument_list|(
specifier|const
name|QVariant
operator|&
name|variant
argument_list|)
expr_stmt|;
specifier|inline
name|void
name|setVariant
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|variant
parameter_list|)
function_decl|;
specifier|inline
name|QVariant
name|variant
argument_list|()
specifier|const
block|{
return|return
name|m_variant
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|QDBusVariant
specifier|inline
name|QDBusVariant
operator|::
name|QDBusVariant
argument_list|(
specifier|const
name|QVariant
operator|&
name|dBusVariant
argument_list|)
operator|:
name|m_variant
argument_list|(
argument|dBusVariant
argument_list|)
block|{ }
DECL|function|setVariant
specifier|inline
name|void
name|QDBusVariant
operator|::
name|setVariant
argument_list|(
argument|const QVariant&dBusVariant
argument_list|)
block|{
name|m_variant
operator|=
name|dBusVariant
block|; }
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDBusVariant
operator|&
name|v1
operator|,
specifier|const
name|QDBusVariant
operator|&
name|v2
operator|)
block|{
return|return
name|v1
operator|.
name|variant
argument_list|()
operator|==
name|v2
operator|.
name|variant
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusVariant
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusObjectPath
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusSignature
argument_list|)
end_decl_stmt
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
