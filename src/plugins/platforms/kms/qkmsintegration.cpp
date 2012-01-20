begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qkmsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qkmsdevice.h"
end_include
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qkmswindow.h"
end_include
begin_include
include|#
directive|include
file|"qkmsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qkmscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixprintersupport_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QKmsIntegration
name|QKmsIntegration
operator|::
name|QKmsIntegration
parameter_list|()
member_init_list|:
name|QPlatformIntegration
argument_list|()
member_init_list|,
name|m_fontDatabase
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
member_init_list|,
name|m_eventDispatcher
argument_list|(
name|createUnixEventDispatcher
argument_list|()
argument_list|)
block|{
name|QGuiApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|setEventDispatcher
argument_list|(
name|m_eventDispatcher
argument_list|)
expr_stmt|;
name|setenv
argument_list|(
literal|"EGL_PLATFORM"
argument_list|,
literal|"drm"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QStringList
name|drmDevices
init|=
name|findDrmDevices
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QString
name|path
decl|,
name|drmDevices
control|)
block|{
name|m_devices
operator|.
name|append
argument_list|(
operator|new
name|QKmsDevice
argument_list|(
name|path
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QKmsIntegration
name|QKmsIntegration
operator|::
name|~
name|QKmsIntegration
parameter_list|()
block|{
foreach|foreach
control|(
name|QKmsDevice
modifier|*
name|device
decl|,
name|m_devices
control|)
block|{
operator|delete
name|device
expr_stmt|;
block|}
foreach|foreach
control|(
name|QPlatformScreen
modifier|*
name|screen
decl|,
name|m_screens
control|)
block|{
operator|delete
name|screen
expr_stmt|;
block|}
operator|delete
name|m_fontDatabase
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QKmsIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
case|case
name|OpenGL
case|:
return|return
literal|true
return|;
case|case
name|ThreadedOpenGL
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QKmsIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|QKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QKmsScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
operator|new
name|QKmsContext
argument_list|(
name|screen
operator|->
name|device
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QKmsIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QKmsWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QKmsIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QKmsBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QKmsIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_fontDatabase
return|;
block|}
end_function
begin_function
DECL|function|findDrmDevices
name|QStringList
name|QKmsIntegration
operator|::
name|findDrmDevices
parameter_list|()
block|{
comment|//Return a list addresses of DRM supported devices
comment|//Hardcoded now, but could use udev to return a list
comment|//of multiple devices.
return|return
name|QStringList
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/dev/dri/card0"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addScreen
name|void
name|QKmsIntegration
operator|::
name|addScreen
parameter_list|(
name|QKmsScreen
modifier|*
name|screen
parameter_list|)
block|{
name|m_screens
operator|.
name|append
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|screenAdded
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QKmsIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|m_eventDispatcher
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
