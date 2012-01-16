begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsystemsemaphore.h"
end_include
begin_include
include|#
directive|include
file|"qsystemsemaphore_p.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
end_ifndef
begin_constructor
DECL|function|QSystemSemaphorePrivate
name|QSystemSemaphorePrivate
operator|::
name|QSystemSemaphorePrivate
parameter_list|()
member_init_list|:
name|semaphore
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|error
argument_list|(
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|setErrorString
name|void
name|QSystemSemaphorePrivate
operator|::
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
name|BOOL
name|windowsError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
if|if
condition|(
name|windowsError
operator|==
literal|0
condition|)
return|return;
switch|switch
condition|(
name|windowsError
condition|)
block|{
case|case
name|ERROR_NO_SYSTEM_RESOURCES
case|:
case|case
name|ERROR_NOT_ENOUGH_MEMORY
case|:
name|error
operator|=
name|QSystemSemaphore
operator|::
name|OutOfResources
expr_stmt|;
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: out of resources"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|ERROR_ACCESS_DENIED
case|:
name|error
operator|=
name|QSystemSemaphore
operator|::
name|PermissionDenied
expr_stmt|;
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: permission denied"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
default|default:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: unknown error %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
operator|.
name|arg
argument_list|(
name|windowsError
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|UnknownError
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|errorString
operator|<<
literal|"key"
operator|<<
name|key
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|handle
name|HANDLE
name|QSystemSemaphorePrivate
operator|::
name|handle
parameter_list|(
name|QSystemSemaphore
operator|::
name|AccessMode
parameter_list|)
block|{
comment|// don't allow making handles on empty keys
if|if
condition|(
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
comment|// Create it if it doesn't already exists.
if|if
condition|(
name|semaphore
operator|==
literal|0
condition|)
block|{
name|semaphore
operator|=
name|CreateSemaphore
argument_list|(
literal|0
argument_list|,
name|initialValue
argument_list|,
name|MAXLONG
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|fileName
operator|.
name|utf16
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|semaphore
operator|==
name|NULL
condition|)
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|semaphore
return|;
block|}
end_function
begin_function
DECL|function|cleanHandle
name|void
name|QSystemSemaphorePrivate
operator|::
name|cleanHandle
parameter_list|()
block|{
if|if
condition|(
name|semaphore
operator|&&
operator|!
name|CloseHandle
argument_list|(
name|semaphore
argument_list|)
condition|)
block|{
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphorePrivate::CloseHandle: sem failed"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|semaphore
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|modifySemaphore
name|bool
name|QSystemSemaphorePrivate
operator|::
name|modifySemaphore
parameter_list|(
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
literal|0
operator|==
name|handle
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|count
operator|>
literal|0
condition|)
block|{
if|if
condition|(
literal|0
operator|==
name|ReleaseSemaphore
argument_list|(
name|semaphore
argument_list|,
name|count
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore ReleaseSemaphore failed"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|WAIT_OBJECT_0
operator|!=
name|WaitForSingleObject
argument_list|(
name|semaphore
argument_list|,
name|INFINITE
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore WaitForSingleObject failed"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_SYSTEMSEMAPHORE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
