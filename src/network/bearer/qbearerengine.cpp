begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbearerengine_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QBearerEngine
name|QBearerEngine
operator|::
name|QBearerEngine
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|mutex
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QBearerEngine
name|QBearerEngine
operator|::
name|~
name|QBearerEngine
parameter_list|()
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|Iterator
name|it
decl_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|Iterator
name|end
decl_stmt|;
for|for
control|(
name|it
operator|=
name|snapConfigurations
operator|.
name|begin
argument_list|()
operator|,
name|end
operator|=
name|snapConfigurations
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|it
operator|.
name|value
argument_list|()
operator|->
name|isValid
operator|=
literal|false
expr_stmt|;
name|it
operator|.
name|value
argument_list|()
operator|->
name|id
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|snapConfigurations
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|it
operator|=
name|accessPointConfigurations
operator|.
name|begin
argument_list|()
operator|,
name|end
operator|=
name|accessPointConfigurations
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|it
operator|.
name|value
argument_list|()
operator|->
name|isValid
operator|=
literal|false
expr_stmt|;
name|it
operator|.
name|value
argument_list|()
operator|->
name|id
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|accessPointConfigurations
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|it
operator|=
name|userChoiceConfigurations
operator|.
name|begin
argument_list|()
operator|,
name|end
operator|=
name|userChoiceConfigurations
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|it
operator|.
name|value
argument_list|()
operator|->
name|isValid
operator|=
literal|false
expr_stmt|;
name|it
operator|.
name|value
argument_list|()
operator|->
name|id
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|userChoiceConfigurations
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|requiresPolling
name|bool
name|QBearerEngine
operator|::
name|requiresPolling
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*     Returns true if configurations are in use; otherwise returns false.      If configurations are in use and requiresPolling() returns true, polling will be enabled for     this engine. */
end_comment
begin_function
DECL|function|configurationsInUse
name|bool
name|QBearerEngine
operator|::
name|configurationsInUse
parameter_list|()
specifier|const
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|ConstIterator
name|it
decl_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|ConstIterator
name|end
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|it
operator|=
name|accessPointConfigurations
operator|.
name|constBegin
argument_list|()
operator|,
name|end
operator|=
name|accessPointConfigurations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|it
operator|.
name|value
argument_list|()
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|>
literal|1
condition|)
return|return
literal|true
return|;
block|}
for|for
control|(
name|it
operator|=
name|snapConfigurations
operator|.
name|constBegin
argument_list|()
operator|,
name|end
operator|=
name|snapConfigurations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|it
operator|.
name|value
argument_list|()
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|>
literal|1
condition|)
return|return
literal|true
return|;
block|}
for|for
control|(
name|it
operator|=
name|userChoiceConfigurations
operator|.
name|constBegin
argument_list|()
operator|,
name|end
operator|=
name|userChoiceConfigurations
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|it
operator|.
name|value
argument_list|()
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|>
literal|1
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"moc_qbearerengine_p.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
