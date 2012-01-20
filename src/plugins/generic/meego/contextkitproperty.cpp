begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"contextkitproperty.h"
end_include
begin_include
include|#
directive|include
file|<QDBusReply>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
DECL|function|objectPathForProperty
specifier|static
name|QString
name|objectPathForProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|property
parameter_list|)
block|{
name|QString
name|path
init|=
name|property
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
block|{
name|path
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|,
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
name|path
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"/org/maemo/contextkit/"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|path
return|;
block|}
end_function
begin_constructor
DECL|function|QContextKitProperty
name|QContextKitProperty
operator|::
name|QContextKitProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|,
specifier|const
name|QString
modifier|&
name|propertyName
parameter_list|)
member_init_list|:
name|propertyInterface
argument_list|(
name|serviceName
argument_list|,
name|objectPathForProperty
argument_list|(
name|propertyName
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"org.maemo.contextkit.Property"
argument_list|)
argument_list|,
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
argument_list|)
block|{
name|propertyInterface
operator|.
name|call
argument_list|(
literal|"Subscribe"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|propertyInterface
argument_list|,
name|SIGNAL
argument_list|(
name|ValueChanged
argument_list|(
name|QVariantList
argument_list|,
name|qulonglong
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|cacheValue
argument_list|(
name|QVariantList
argument_list|,
name|qulonglong
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusMessage
name|reply
init|=
name|propertyInterface
operator|.
name|call
argument_list|(
literal|"Get"
argument_list|)
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ReplyMessage
condition|)
name|cachedValue
operator|=
name|qdbus_cast
argument_list|<
name|QList
argument_list|<
name|QVariant
argument_list|>
argument_list|>
argument_list|(
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|value
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|.
name|value
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QContextKitProperty
name|QContextKitProperty
operator|::
name|~
name|QContextKitProperty
parameter_list|()
block|{
name|propertyInterface
operator|.
name|call
argument_list|(
literal|"Unsubscribe"
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|value
name|QVariant
name|QContextKitProperty
operator|::
name|value
parameter_list|()
specifier|const
block|{
return|return
name|cachedValue
return|;
block|}
end_function
begin_function
DECL|function|cacheValue
name|void
name|QContextKitProperty
operator|::
name|cacheValue
parameter_list|(
specifier|const
name|QVariantList
modifier|&
name|values
parameter_list|,
name|qulonglong
parameter_list|)
block|{
name|cachedValue
operator|=
name|values
operator|.
name|value
argument_list|(
literal|0
argument_list|)
expr_stmt|;
emit|emit
name|valueChanged
argument_list|(
name|cachedValue
argument_list|)
emit|;
block|}
end_function
end_unit
