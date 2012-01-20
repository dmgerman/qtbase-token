begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSMETATYPE_P_H
end_ifndef
begin_define
DECL|macro|QDBUSMETATYPE_P_H
define|#
directive|define
name|QDBUSMETATYPE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qdbusmetatype.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QDBusMetaTypeId
struct|struct
name|QDBusMetaTypeId
block|{
DECL|member|message
specifier|static
name|int
name|message
decl_stmt|;
comment|// QDBusMessage
DECL|member|argument
specifier|static
name|int
name|argument
decl_stmt|;
comment|// QDBusArgument
DECL|member|variant
specifier|static
name|int
name|variant
decl_stmt|;
comment|// QDBusVariant
DECL|member|objectpath
specifier|static
name|int
name|objectpath
decl_stmt|;
comment|// QDBusObjectPath
DECL|member|signature
specifier|static
name|int
name|signature
decl_stmt|;
comment|// QDBusSignature
DECL|member|error
specifier|static
name|int
name|error
decl_stmt|;
comment|// QDBusError
DECL|member|unixfd
specifier|static
name|int
name|unixfd
decl_stmt|;
comment|// QDBusUnixFileDescriptor
specifier|static
name|void
name|init
parameter_list|()
function_decl|;
block|}
struct|;
end_struct
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
