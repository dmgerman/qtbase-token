begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcEglDevDebug
argument_list|)
ifdef|#
directive|ifdef
name|EGLFS_PLATFORM_HOOKS
DECL|function|qt_egl_device_integration
name|QEGLDeviceIntegration
modifier|*
name|qt_egl_device_integration
argument_list|()
argument_list|{
specifier|extern
name|QEglFSHooks
operator|*
name|platformHooks
argument_list|;     return
name|platformHooks
argument_list|; }
else|#
directive|else
name|class
name|DeviceIntegration
argument_list|{
specifier|public
operator|:
name|DeviceIntegration
argument_list|()
argument_list|;
operator|~
name|DeviceIntegration
argument_list|()
block|{
operator|delete
name|m_integration
block|; }
name|QEGLDeviceIntegration
operator|*
name|integration
argument_list|()
block|{
return|return
name|m_integration
return|;
block|}
specifier|private
operator|:
name|QEGLDeviceIntegration
operator|*
name|m_integration
argument_list|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|DeviceIntegration
argument_list|,
argument|deviceIntegration
argument_list|)
end_macro
begin_constructor
name|DeviceIntegration
operator|::
name|DeviceIntegration
parameter_list|()
member_init_list|:
name|m_integration
argument_list|(
literal|0
argument_list|)
block|{
name|QStringList
name|pluginKeys
init|=
name|QEGLDeviceIntegrationFactory
operator|::
name|keys
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|pluginKeys
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Some built-in logic: Prioritize either X11 or KMS/DRM.
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"DISPLAY"
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|x11key
init|=
name|QStringLiteral
argument_list|(
literal|"eglfs_x11"
argument_list|)
decl_stmt|;
if|if
condition|(
name|pluginKeys
operator|.
name|contains
argument_list|(
name|x11key
argument_list|)
condition|)
block|{
name|pluginKeys
operator|.
name|removeOne
argument_list|(
name|x11key
argument_list|)
expr_stmt|;
name|pluginKeys
operator|.
name|prepend
argument_list|(
name|x11key
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
specifier|const
name|QString
name|kmskey
init|=
name|QStringLiteral
argument_list|(
literal|"eglfs_kms"
argument_list|)
decl_stmt|;
if|if
condition|(
name|pluginKeys
operator|.
name|contains
argument_list|(
name|kmskey
argument_list|)
condition|)
block|{
name|pluginKeys
operator|.
name|removeOne
argument_list|(
name|kmskey
argument_list|)
expr_stmt|;
name|pluginKeys
operator|.
name|prepend
argument_list|(
name|kmskey
argument_list|)
expr_stmt|;
block|}
block|}
name|QByteArray
name|requested
decl_stmt|;
comment|// The environment variable can override everything.
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_QPA_EGLFS_INTEGRATION"
argument_list|)
condition|)
block|{
name|requested
operator|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_INTEGRATION"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Device-specific makespecs may define a preferred plugin.
ifdef|#
directive|ifdef
name|EGLFS_PREFERRED_PLUGIN
define|#
directive|define
name|DEFAULT_PLUGIN
value|EGLFS_PREFERRED_PLUGIN
define|#
directive|define
name|STR
parameter_list|(
name|s
parameter_list|)
value|#s
define|#
directive|define
name|STRQ
parameter_list|(
name|s
parameter_list|)
value|STR(s)
name|requested
operator|=
name|STRQ
argument_list|(
name|DEFAULT_PLUGIN
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|// Treat "none" as special. There has to be a way to indicate
comment|// that plugins must be ignored when the device is known to be
comment|// functional with the default, non-specialized integration.
if|if
condition|(
name|requested
operator|!=
name|QByteArrayLiteral
argument_list|(
literal|"none"
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|requested
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|reqStr
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|requested
argument_list|)
decl_stmt|;
name|pluginKeys
operator|.
name|removeOne
argument_list|(
name|reqStr
argument_list|)
expr_stmt|;
name|pluginKeys
operator|.
name|prepend
argument_list|(
name|reqStr
argument_list|)
expr_stmt|;
block|}
name|qCDebug
argument_list|(
name|qLcEglDevDebug
argument_list|)
operator|<<
literal|"EGL device integration plugin keys (sorted):"
operator|<<
name|pluginKeys
expr_stmt|;
while|while
condition|(
operator|!
name|m_integration
operator|&&
operator|!
name|pluginKeys
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|key
init|=
name|pluginKeys
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcEglDevDebug
argument_list|)
operator|<<
literal|"Trying to load device EGL integration"
operator|<<
name|key
expr_stmt|;
name|m_integration
operator|=
name|QEGLDeviceIntegrationFactory
operator|::
name|create
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|m_integration
condition|)
block|{
comment|// Use a default, non-specialized device integration when no plugin is available.
comment|// For some systems this is sufficient.
name|qCDebug
argument_list|(
name|qLcEglDevDebug
argument_list|)
operator|<<
literal|"Using base device integration"
expr_stmt|;
name|m_integration
operator|=
operator|new
name|QEGLDeviceIntegration
expr_stmt|;
block|}
block|}
end_constructor
begin_function
name|QEGLDeviceIntegration
modifier|*
name|qt_egl_device_integration
parameter_list|()
block|{
return|return
name|deviceIntegration
argument_list|()
operator|->
name|integration
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// EGLFS_PLATFORM_HOOKS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
