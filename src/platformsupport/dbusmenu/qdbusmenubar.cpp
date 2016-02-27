begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Dmitry Shachnev<mitya57@gmail.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusmenubar_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmenuregistrarproxy_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/* note: do not change these to QStringLiteral;    we are unloaded before QtDBus is done using the strings.  */
end_comment
begin_define
DECL|macro|REGISTRAR_SERVICE
define|#
directive|define
name|REGISTRAR_SERVICE
value|QLatin1String("com.canonical.AppMenu.Registrar")
end_define
begin_define
DECL|macro|REGISTRAR_PATH
define|#
directive|define
name|REGISTRAR_PATH
value|QLatin1String("/com/canonical/AppMenu/Registrar")
end_define
begin_constructor
DECL|function|QDBusMenuBar
name|QDBusMenuBar
operator|::
name|QDBusMenuBar
parameter_list|()
member_init_list|:
name|QPlatformMenuBar
argument_list|()
member_init_list|,
name|m_menu
argument_list|(
operator|new
name|QDBusPlatformMenu
argument_list|()
argument_list|)
member_init_list|,
name|m_menuAdaptor
argument_list|(
operator|new
name|QDBusMenuAdaptor
argument_list|(
name|m_menu
argument_list|)
argument_list|)
member_init_list|,
name|m_windowId
argument_list|(
literal|0
argument_list|)
block|{
name|QDBusMenuItem
operator|::
name|registerDBusTypes
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|m_menu
argument_list|,
operator|&
name|QDBusPlatformMenu
operator|::
name|propertiesUpdated
argument_list|,
name|m_menuAdaptor
argument_list|,
operator|&
name|QDBusMenuAdaptor
operator|::
name|ItemsPropertiesUpdated
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_menu
argument_list|,
operator|&
name|QDBusPlatformMenu
operator|::
name|updated
argument_list|,
name|m_menuAdaptor
argument_list|,
operator|&
name|QDBusMenuAdaptor
operator|::
name|LayoutUpdated
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDBusMenuBar
name|QDBusMenuBar
operator|::
name|~
name|QDBusMenuBar
parameter_list|()
block|{
name|unregisterMenuBar
argument_list|()
expr_stmt|;
operator|delete
name|m_menuAdaptor
expr_stmt|;
operator|delete
name|m_menu
expr_stmt|;
name|qDeleteAll
argument_list|(
name|m_menuItems
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|menuItemForMenu
name|QDBusPlatformMenuItem
modifier|*
name|QDBusMenuBar
operator|::
name|menuItemForMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
if|if
condition|(
operator|!
name|menu
condition|)
return|return
literal|nullptr
return|;
name|quintptr
name|tag
init|=
name|menu
operator|->
name|tag
argument_list|()
decl_stmt|;
specifier|const
specifier|auto
name|it
init|=
name|m_menuItems
operator|.
name|constFind
argument_list|(
name|tag
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|m_menuItems
operator|.
name|cend
argument_list|()
condition|)
block|{
return|return
operator|*
name|it
return|;
block|}
else|else
block|{
name|QDBusPlatformMenuItem
modifier|*
name|item
init|=
operator|new
name|QDBusPlatformMenuItem
decl_stmt|;
name|updateMenuItem
argument_list|(
name|item
argument_list|,
name|menu
argument_list|)
expr_stmt|;
name|m_menuItems
operator|.
name|insert
argument_list|(
name|tag
argument_list|,
name|item
argument_list|)
expr_stmt|;
return|return
name|item
return|;
block|}
block|}
end_function
begin_function
DECL|function|updateMenuItem
name|void
name|QDBusMenuBar
operator|::
name|updateMenuItem
parameter_list|(
name|QDBusPlatformMenuItem
modifier|*
name|item
parameter_list|,
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
specifier|const
name|QDBusPlatformMenu
modifier|*
name|ourMenu
init|=
name|qobject_cast
argument_list|<
specifier|const
name|QDBusPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menu
argument_list|)
decl_stmt|;
name|item
operator|->
name|setText
argument_list|(
name|ourMenu
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setIcon
argument_list|(
name|ourMenu
operator|->
name|icon
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setEnabled
argument_list|(
name|ourMenu
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setVisible
argument_list|(
name|ourMenu
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setMenu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertMenu
name|void
name|QDBusMenuBar
operator|::
name|insertMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|,
name|QPlatformMenu
modifier|*
name|before
parameter_list|)
block|{
name|QDBusPlatformMenuItem
modifier|*
name|menuItem
init|=
name|menuItemForMenu
argument_list|(
name|menu
argument_list|)
decl_stmt|;
name|QDBusPlatformMenuItem
modifier|*
name|beforeItem
init|=
name|menuItemForMenu
argument_list|(
name|before
argument_list|)
decl_stmt|;
name|m_menu
operator|->
name|insertMenuItem
argument_list|(
name|menuItem
argument_list|,
name|beforeItem
argument_list|)
expr_stmt|;
name|m_menu
operator|->
name|emitUpdated
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeMenu
name|void
name|QDBusMenuBar
operator|::
name|removeMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|QDBusPlatformMenuItem
modifier|*
name|menuItem
init|=
name|menuItemForMenu
argument_list|(
name|menu
argument_list|)
decl_stmt|;
name|m_menu
operator|->
name|removeMenuItem
argument_list|(
name|menuItem
argument_list|)
expr_stmt|;
name|m_menu
operator|->
name|emitUpdated
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|syncMenu
name|void
name|QDBusMenuBar
operator|::
name|syncMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|QDBusPlatformMenuItem
modifier|*
name|menuItem
init|=
name|menuItemForMenu
argument_list|(
name|menu
argument_list|)
decl_stmt|;
name|updateMenuItem
argument_list|(
name|menuItem
argument_list|,
name|menu
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleReparent
name|void
name|QDBusMenuBar
operator|::
name|handleReparent
parameter_list|(
name|QWindow
modifier|*
name|newParentWindow
parameter_list|)
block|{
if|if
condition|(
name|newParentWindow
operator|&&
name|newParentWindow
operator|->
name|winId
argument_list|()
operator|!=
name|m_windowId
condition|)
block|{
name|unregisterMenuBar
argument_list|()
expr_stmt|;
name|m_windowId
operator|=
name|newParentWindow
operator|->
name|winId
argument_list|()
expr_stmt|;
name|registerMenuBar
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|menuForTag
name|QPlatformMenu
modifier|*
name|QDBusMenuBar
operator|::
name|menuForTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
specifier|const
block|{
name|QDBusPlatformMenuItem
modifier|*
name|menuItem
init|=
name|m_menuItems
operator|.
name|value
argument_list|(
name|tag
argument_list|)
decl_stmt|;
if|if
condition|(
name|menuItem
condition|)
return|return
cast|const_cast
argument_list|<
name|QPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menuItem
operator|->
name|menu
argument_list|()
argument_list|)
return|;
return|return
literal|nullptr
return|;
block|}
end_function
begin_function
DECL|function|createMenu
name|QPlatformMenu
modifier|*
name|QDBusMenuBar
operator|::
name|createMenu
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QDBusPlatformMenu
return|;
block|}
end_function
begin_function
DECL|function|registerMenuBar
name|void
name|QDBusMenuBar
operator|::
name|registerMenuBar
parameter_list|()
block|{
specifier|static
name|uint
name|menuBarId
init|=
literal|0
decl_stmt|;
name|QDBusConnection
name|connection
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
name|m_objectPath
operator|=
name|QStringLiteral
argument_list|(
literal|"/MenuBar/%1"
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|menuBarId
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|connection
operator|.
name|registerObject
argument_list|(
name|m_objectPath
argument_list|,
name|m_menu
argument_list|)
condition|)
return|return;
name|QDBusMenuRegistrarInterface
name|registrar
argument_list|(
name|REGISTRAR_SERVICE
argument_list|,
name|REGISTRAR_PATH
argument_list|,
name|connection
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QDBusPendingReply
argument_list|<>
name|r
init|=
name|registrar
operator|.
name|RegisterWindow
argument_list|(
name|m_windowId
argument_list|,
name|QDBusObjectPath
argument_list|(
name|m_objectPath
argument_list|)
argument_list|)
decl_stmt|;
name|r
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
if|if
condition|(
name|r
operator|.
name|isError
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to register window menu, reason: %s (\"%s\")"
argument_list|,
name|qUtf8Printable
argument_list|(
name|r
operator|.
name|error
argument_list|()
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|qUtf8Printable
argument_list|(
name|r
operator|.
name|error
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connection
operator|.
name|unregisterObject
argument_list|(
name|m_objectPath
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|unregisterMenuBar
name|void
name|QDBusMenuBar
operator|::
name|unregisterMenuBar
parameter_list|()
block|{
name|QDBusConnection
name|connection
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_windowId
condition|)
block|{
name|QDBusMenuRegistrarInterface
name|registrar
argument_list|(
name|REGISTRAR_SERVICE
argument_list|,
name|REGISTRAR_PATH
argument_list|,
name|connection
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QDBusPendingReply
argument_list|<>
name|r
init|=
name|registrar
operator|.
name|UnregisterWindow
argument_list|(
name|m_windowId
argument_list|)
decl_stmt|;
name|r
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
if|if
condition|(
name|r
operator|.
name|isError
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"Failed to unregister window menu, reason: %s (\"%s\")"
argument_list|,
name|qUtf8Printable
argument_list|(
name|r
operator|.
name|error
argument_list|()
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|qUtf8Printable
argument_list|(
name|r
operator|.
name|error
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_objectPath
operator|.
name|isEmpty
argument_list|()
condition|)
name|connection
operator|.
name|unregisterObject
argument_list|(
name|m_objectPath
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
