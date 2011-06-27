begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandwindowmanagerintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandwindowmanager-client-protocol.h"
end_include
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_decl_stmt
DECL|member|mWindowManagerListener
specifier|const
name|struct
name|wl_windowmanager_listener
name|QWaylandWindowManagerIntegration
operator|::
name|mWindowManagerListener
init|=
block|{
name|QWaylandWindowManagerIntegration
operator|::
name|wlHandleOnScreenVisibilityChange
block|, }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|createIntegration
name|QWaylandWindowManagerIntegration
modifier|*
name|QWaylandWindowManagerIntegration
operator|::
name|createIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDisplay
parameter_list|)
block|{
return|return
operator|new
name|QWaylandWindowManagerIntegration
argument_list|(
name|waylandDisplay
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QWaylandWindowManagerIntegration
name|QWaylandWindowManagerIntegration
operator|::
name|QWaylandWindowManagerIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDisplay
parameter_list|)
member_init_list|:
name|mWaylandDisplay
argument_list|(
name|waylandDisplay
argument_list|)
member_init_list|,
name|mWaylandWindowManager
argument_list|(
literal|0
argument_list|)
block|{
name|wl_display_add_global_listener
argument_list|(
name|mWaylandDisplay
operator|->
name|wl_display
argument_list|()
argument_list|,
name|QWaylandWindowManagerIntegration
operator|::
name|wlHandleListenerGlobal
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandWindowManagerIntegration
name|QWaylandWindowManagerIntegration
operator|::
name|~
name|QWaylandWindowManagerIntegration
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|windowManager
name|struct
name|wl_windowmanager
modifier|*
name|QWaylandWindowManagerIntegration
operator|::
name|windowManager
parameter_list|()
specifier|const
block|{
return|return
name|mWaylandWindowManager
return|;
block|}
end_function
begin_function
DECL|function|wlHandleListenerGlobal
name|void
name|QWaylandWindowManagerIntegration
operator|::
name|wlHandleListenerGlobal
parameter_list|(
name|wl_display
modifier|*
name|display
parameter_list|,
name|uint32_t
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|interface
parameter_list|,
name|uint32_t
name|version
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|interface
argument_list|,
literal|"wl_windowmanager"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|QWaylandWindowManagerIntegration
modifier|*
name|integration
init|=
cast|static_cast
argument_list|<
name|QWaylandWindowManagerIntegration
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|integration
operator|->
name|mWaylandWindowManager
operator|=
name|wl_windowmanager_create
argument_list|(
name|display
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|wl_windowmanager_add_listener
argument_list|(
name|integration
operator|->
name|mWaylandWindowManager
argument_list|,
operator|&
name|mWindowManagerListener
argument_list|,
name|integration
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|mapClientToProcess
name|void
name|QWaylandWindowManagerIntegration
operator|::
name|mapClientToProcess
parameter_list|(
name|long
name|long
name|processId
parameter_list|)
block|{
if|if
condition|(
name|mWaylandWindowManager
condition|)
name|wl_windowmanager_map_client_to_process
argument_list|(
name|mWaylandWindowManager
argument_list|,
operator|(
name|uint32_t
operator|)
name|processId
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|authenticateWithToken
name|void
name|QWaylandWindowManagerIntegration
operator|::
name|authenticateWithToken
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|token
parameter_list|)
block|{
name|QByteArray
name|authToken
init|=
name|token
decl_stmt|;
if|if
condition|(
name|authToken
operator|.
name|isEmpty
argument_list|()
condition|)
name|authToken
operator|=
name|qgetenv
argument_list|(
literal|"WL_AUTHENTICATION_TOKEN"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mWaylandWindowManager
condition|)
name|wl_windowmanager_authenticate_with_token
argument_list|(
name|mWaylandWindowManager
argument_list|,
name|authToken
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wlHandleOnScreenVisibilityChange
name|void
name|QWaylandWindowManagerIntegration
operator|::
name|wlHandleOnScreenVisibilityChange
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_windowmanager
modifier|*
name|wl_windowmanager
parameter_list|,
name|int
name|visible
parameter_list|)
block|{
name|QWaylandWindowManagerIntegration
modifier|*
name|integration
init|=
operator|(
name|QWaylandWindowManagerIntegration
operator|*
operator|)
name|data
decl_stmt|;
name|QEvent
name|evt
argument_list|(
name|visible
operator|!=
literal|0
condition|?
name|QEvent
operator|::
name|ApplicationActivated
else|:
name|QEvent
operator|::
name|ApplicationDeactivated
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|,
operator|&
name|evt
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"OnScreenVisibility"
operator|<<
operator|(
name|visible
operator|!=
literal|0
operator|)
expr_stmt|;
block|}
end_function
end_unit
