begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qevdevkeyboardmanager_p.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qinputdevicemanager_p_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcEvdevKey
argument_list|)
DECL|function|QEvdevKeyboardManager
name|QEvdevKeyboardManager
operator|::
name|QEvdevKeyboardManager
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|specification
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
range|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|key
argument_list|)
block|;
name|QString
name|spec
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_QPA_EVDEV_KEYBOARD_PARAMETERS"
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|spec
operator|.
name|isEmpty
argument_list|()
condition|)
name|spec
operator|=
name|specification
expr_stmt|;
name|QStringList
name|args
operator|=
name|spec
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|devices
decl_stmt|;
end_decl_stmt
begin_foreach
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|args
control|)
block|{
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"/dev/"
argument_list|)
argument_list|)
condition|)
block|{
comment|// if device is specified try to use it
name|devices
operator|.
name|append
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|args
operator|.
name|removeAll
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
block|}
end_foreach
begin_comment
comment|// build new specification without /dev/ elements
end_comment
begin_expr_stmt
name|m_spec
operator|=
name|args
operator|.
name|join
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// add all keyboards for devices specified in the argument list
end_comment
begin_foreach
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|device
decl|,
name|devices
control|)
name|addKeyboard
argument_list|(
name|device
argument_list|)
expr_stmt|;
end_foreach
begin_if
if|if
condition|(
name|devices
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEvdevKey
argument_list|)
operator|<<
literal|"evdevkeyboard: Using device discovery"
expr_stmt|;
name|m_deviceDiscovery
operator|=
name|QDeviceDiscovery
operator|::
name|create
argument_list|(
name|QDeviceDiscovery
operator|::
name|Device_Keyboard
argument_list|,
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_deviceDiscovery
condition|)
block|{
comment|// scan and add already connected keyboards
name|QStringList
name|devices
init|=
name|m_deviceDiscovery
operator|->
name|scanConnectedDevices
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|device
decl|,
name|devices
control|)
block|{
name|addKeyboard
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
name|m_deviceDiscovery
argument_list|,
name|SIGNAL
argument_list|(
name|deviceDetected
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addKeyboard
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_deviceDiscovery
argument_list|,
name|SIGNAL
argument_list|(
name|deviceRemoved
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|removeKeyboard
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_if
begin_destructor
unit|}  QEvdevKeyboardManager
DECL|function|~QEvdevKeyboardManager
operator|::
name|~
name|QEvdevKeyboardManager
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|m_keyboards
argument_list|)
expr_stmt|;
name|m_keyboards
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|addKeyboard
name|void
name|QEvdevKeyboardManager
operator|::
name|addKeyboard
parameter_list|(
specifier|const
name|QString
modifier|&
name|deviceNode
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcEvdevKey
argument_list|)
operator|<<
literal|"Adding keyboard at"
operator|<<
name|deviceNode
expr_stmt|;
name|QEvdevKeyboardHandler
modifier|*
name|keyboard
decl_stmt|;
name|keyboard
operator|=
name|QEvdevKeyboardHandler
operator|::
name|create
argument_list|(
name|deviceNode
argument_list|,
name|m_spec
argument_list|,
name|m_defaultKeymapFile
argument_list|)
expr_stmt|;
if|if
condition|(
name|keyboard
condition|)
block|{
name|m_keyboards
operator|.
name|insert
argument_list|(
name|deviceNode
argument_list|,
name|keyboard
argument_list|)
expr_stmt|;
name|QInputDeviceManagerPrivate
operator|::
name|get
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
argument_list|)
operator|->
name|setDeviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypeKeyboard
argument_list|,
name|m_keyboards
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Failed to open keyboard device %s"
argument_list|,
name|qPrintable
argument_list|(
name|deviceNode
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|removeKeyboard
name|void
name|QEvdevKeyboardManager
operator|::
name|removeKeyboard
parameter_list|(
specifier|const
name|QString
modifier|&
name|deviceNode
parameter_list|)
block|{
if|if
condition|(
name|m_keyboards
operator|.
name|contains
argument_list|(
name|deviceNode
argument_list|)
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEvdevKey
argument_list|)
operator|<<
literal|"Removing keyboard at"
operator|<<
name|deviceNode
expr_stmt|;
name|QEvdevKeyboardHandler
modifier|*
name|keyboard
init|=
name|m_keyboards
operator|.
name|value
argument_list|(
name|deviceNode
argument_list|)
decl_stmt|;
name|m_keyboards
operator|.
name|remove
argument_list|(
name|deviceNode
argument_list|)
expr_stmt|;
name|QInputDeviceManagerPrivate
operator|::
name|get
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
argument_list|)
operator|->
name|setDeviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypeKeyboard
argument_list|,
name|m_keyboards
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|keyboard
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|loadKeymap
name|void
name|QEvdevKeyboardManager
operator|::
name|loadKeymap
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
block|{
name|m_defaultKeymapFile
operator|=
name|file
expr_stmt|;
if|if
condition|(
name|file
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Restore the default, which is either the built-in keymap or
comment|// the one given in the plugin spec.
name|QString
name|keymapFromSpec
decl_stmt|;
specifier|const
specifier|auto
name|specs
init|=
name|m_spec
operator|.
name|splitRef
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
specifier|const
name|QStringRef
modifier|&
name|arg
range|:
name|specs
control|)
block|{
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"keymap="
argument_list|)
argument_list|)
condition|)
name|keymapFromSpec
operator|=
name|arg
operator|.
name|mid
argument_list|(
literal|7
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
foreach|foreach
control|(
name|QEvdevKeyboardHandler
modifier|*
name|handler
decl|,
name|m_keyboards
control|)
block|{
if|if
condition|(
name|keymapFromSpec
operator|.
name|isEmpty
argument_list|()
condition|)
name|handler
operator|->
name|unloadKeymap
argument_list|()
expr_stmt|;
else|else
name|handler
operator|->
name|loadKeymap
argument_list|(
name|keymapFromSpec
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
foreach|foreach
control|(
name|QEvdevKeyboardHandler
modifier|*
name|handler
decl|,
name|m_keyboards
control|)
name|handler
operator|->
name|loadKeymap
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
