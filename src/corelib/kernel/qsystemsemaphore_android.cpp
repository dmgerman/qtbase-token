begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Collabora Ltd, author<robin.burchell@collabora.co.uk> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QSystemSemaphorePrivate
name|QSystemSemaphorePrivate
operator|::
name|QSystemSemaphorePrivate
parameter_list|()
member_init_list|:
name|unix_key
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|semaphore
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|createdFile
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|createdSemaphore
argument_list|(
literal|false
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
name|Q_UNUSED
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Not yet implemented on Android"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handle
name|key_t
name|QSystemSemaphorePrivate
operator|::
name|handle
parameter_list|(
name|QSystemSemaphore
operator|::
name|AccessMode
name|mode
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Not yet implemented on Android"
expr_stmt|;
return|return
operator|-
literal|1
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
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Not yet implemented on Android"
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
name|Q_UNUSED
argument_list|(
name|count
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Not yet implemented on Android"
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMSEMAPHORE
end_comment
end_unit
