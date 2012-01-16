begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSMETATYPE_H
end_ifndef
begin_define
DECL|macro|QDBUSMETATYPE_H
define|#
directive|define
name|QDBUSMETATYPE_H
end_define
begin_include
include|#
directive|include
file|"QtCore/qmetatype.h"
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusargument.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|DBus
parameter_list|)
name|class
name|Q_DBUS_EXPORT
name|QDBusMetaType
decl_stmt|{ public:     typedef void (*MarshallFunction
end_function
begin_expr_stmt
unit|)
operator|(
name|QDBusArgument
operator|&
operator|,
specifier|const
name|void
operator|*
operator|)
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|DemarshallFunction
function_decl|)
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
specifier|static
name|void
name|registerMarshallOperators
parameter_list|(
name|int
name|typeId
parameter_list|,
name|MarshallFunction
parameter_list|,
name|DemarshallFunction
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|marshall
parameter_list|(
name|QDBusArgument
modifier|&
parameter_list|,
name|int
name|id
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|demarshall
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
parameter_list|,
name|int
name|id
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|signatureToType
parameter_list|(
specifier|const
name|char
modifier|*
name|signature
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|typeToSignature
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qDBusMarshallHelper
name|void
name|qDBusMarshallHelper
argument_list|(
argument|QDBusArgument&arg
argument_list|,
argument|const T *t
argument_list|)
block|{
name|arg
operator|<<
operator|*
name|t
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qDBusDemarshallHelper
name|void
name|qDBusDemarshallHelper
argument_list|(
argument|const QDBusArgument&arg
argument_list|,
argument|T *t
argument_list|)
block|{
name|arg
operator|>>
operator|*
name|t
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qDBusRegisterMetaType
name|int
name|qDBusRegisterMetaType
argument_list|(
ifndef|#
directive|ifndef
name|qdoc
argument|T *
comment|/* dummy */
argument|=
literal|0
endif|#
directive|endif
argument_list|)
block|{
name|void
argument_list|(
operator|*
name|mf
argument_list|)
argument_list|(
name|QDBusArgument
operator|&
argument_list|,
specifier|const
name|T
operator|*
argument_list|)
operator|=
name|qDBusMarshallHelper
operator|<
name|T
operator|>
block|;
name|void
argument_list|(
operator|*
name|df
argument_list|)
argument_list|(
specifier|const
name|QDBusArgument
operator|&
argument_list|,
name|T
operator|*
argument_list|)
operator|=
name|qDBusDemarshallHelper
operator|<
name|T
operator|>
block|;
name|int
name|id
operator|=
name|qRegisterMetaType
operator|<
name|T
operator|>
operator|(
operator|)
block|;
comment|// make sure it's registered
name|QDBusMetaType
operator|::
name|registerMarshallOperators
argument_list|(
name|id
argument_list|,
name|reinterpret_cast
operator|<
name|QDBusMetaType
operator|::
name|MarshallFunction
operator|>
operator|(
name|mf
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QDBusMetaType
operator|::
name|DemarshallFunction
operator|>
operator|(
name|df
operator|)
argument_list|)
block|;
return|return
name|id
return|;
block|}
end_expr_stmt
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
