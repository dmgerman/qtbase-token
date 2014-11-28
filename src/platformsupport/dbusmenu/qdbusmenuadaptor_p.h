begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*     This file was originally created by qdbusxml2cpp version 0.8     Command line was:     qdbusxml2cpp -a dbusmenu ../../3rdparty/dbus-ifaces/dbus-menu.xml      However it is maintained manually.      It is also not part of the public API. This header file may change from     version to version without notice, or even be removed. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DBUSMENUADAPTOR_H
end_ifndef
begin_define
DECL|macro|DBUSMENUADAPTOR_H
define|#
directive|define
name|DBUSMENUADAPTOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|"qdbusmenutypes_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*  * Adaptor class for interface com.canonical.dbusmenu  */
name|class
name|QDBusMenuAdaptor
range|:
name|public
name|QDBusAbstractAdaptor
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"com.canonical.dbusmenu"
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Introspection"
argument_list|,
literal|""
literal|"<interface name=\"com.canonical.dbusmenu\">\n"
literal|"<property access=\"read\" type=\"u\" name=\"Version\">\n"
literal|"</property>\n"
literal|"<property access=\"read\" type=\"s\" name=\"TextDirection\">\n"
literal|"</property>\n"
literal|"<property access=\"read\" type=\"s\" name=\"Status\">\n"
literal|"</property>\n"
literal|"<property access=\"read\" type=\"as\" name=\"IconThemePath\">\n"
literal|"</property>\n"
literal|"<method name=\"GetLayout\">\n"
literal|"<annotation value=\"QDBusMenuLayoutItem\" name=\"org.qtproject.QtDBus.QtTypeName.Out1\"/>\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"parentId\"/>\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"recursionDepth\"/>\n"
literal|"<arg direction=\"in\" type=\"as\" name=\"propertyNames\"/>\n"
literal|"<arg direction=\"out\" type=\"u\" name=\"revision\"/>\n"
literal|"<arg direction=\"out\" type=\"(ia{sv}av)\" name=\"layout\"/>\n"
literal|"</method>\n"
literal|"<method name=\"GetGroupProperties\">\n"
literal|"<annotation value=\"QList&lt;int&gt;\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n"
literal|"<annotation value=\"QDBusMenuItemList\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
literal|"<arg direction=\"in\" type=\"ai\" name=\"ids\"/>\n"
literal|"<arg direction=\"in\" type=\"as\" name=\"propertyNames\"/>\n"
literal|"<arg direction=\"out\" type=\"a(ia{sv})\" name=\"properties\"/>\n"
literal|"</method>\n"
literal|"<method name=\"GetProperty\">\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"id\"/>\n"
literal|"<arg direction=\"in\" type=\"s\" name=\"name\"/>\n"
literal|"<arg direction=\"out\" type=\"v\" name=\"value\"/>\n"
literal|"</method>\n"
literal|"<method name=\"Event\">\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"id\"/>\n"
literal|"<arg direction=\"in\" type=\"s\" name=\"eventId\"/>\n"
literal|"<arg direction=\"in\" type=\"v\" name=\"data\"/>\n"
literal|"<arg direction=\"in\" type=\"u\" name=\"timestamp\"/>\n"
literal|"</method>\n"
literal|"<method name=\"EventGroup\">\n"
literal|"<annotation value=\"QList&lt;QDBusMenuEvent&gt;\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n"
literal|"<annotation value=\"QList&lt;int&gt;\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
literal|"<arg direction=\"in\" type=\"a(isvu)\" name=\"events\"/>\n"
literal|"<arg direction=\"out\" type=\"ai\" name=\"idErrors\"/>\n"
literal|"</method>\n"
literal|"<method name=\"AboutToShow\">\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"id\"/>\n"
literal|"<arg direction=\"out\" type=\"b\" name=\"needUpdate\"/>\n"
literal|"</method>\n"
literal|"<method name=\"AboutToShowGroup\">\n"
literal|"<annotation value=\"QList&lt;int&gt;\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n"
literal|"<annotation value=\"QList&lt;int&gt;\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
literal|"<annotation value=\"QList&lt;int&gt;\" name=\"org.qtproject.QtDBus.QtTypeName.Out1\"/>\n"
literal|"<arg direction=\"in\" type=\"ai\" name=\"ids\"/>\n"
literal|"<arg direction=\"out\" type=\"ai\" name=\"updatesNeeded\"/>\n"
literal|"<arg direction=\"out\" type=\"ai\" name=\"idErrors\"/>\n"
literal|"</method>\n"
literal|"<signal name=\"ItemsPropertiesUpdated\">\n"
literal|"<annotation value=\"QDBusMenuItemList\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n"
literal|"<annotation value=\"QDBusMenuItemKeysList\" name=\"org.qtproject.QtDBus.QtTypeName.In1\"/>\n"
literal|"<arg direction=\"out\" type=\"a(ia{sv})\" name=\"updatedProps\"/>\n"
literal|"<arg direction=\"out\" type=\"a(ias)\" name=\"removedProps\"/>\n"
literal|"</signal>\n"
literal|"<signal name=\"LayoutUpdated\">\n"
literal|"<arg direction=\"out\" type=\"u\" name=\"revision\"/>\n"
literal|"<arg direction=\"out\" type=\"i\" name=\"parent\"/>\n"
literal|"</signal>\n"
literal|"<signal name=\"ItemActivationRequested\">\n"
literal|"<arg direction=\"out\" type=\"i\" name=\"id\"/>\n"
literal|"<arg direction=\"out\" type=\"u\" name=\"timestamp\"/>\n"
literal|"</signal>\n"
literal|"</interface>\n"
literal|""
argument_list|)
name|public
operator|:
name|QDBusMenuAdaptor
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|virtual
operator|~
name|QDBusMenuAdaptor
argument_list|()
block|;
name|public
operator|:
comment|// PROPERTIES
name|Q_PROPERTY
argument_list|(
argument|QString Status READ status
argument_list|)
name|QString
name|status
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QString TextDirection READ textDirection
argument_list|)
name|QString
name|textDirection
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|uint Version READ version
argument_list|)
name|uint
name|version
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
comment|// METHODS
name|bool
name|AboutToShow
argument_list|(
argument|int id
argument_list|)
block|;
name|QList
operator|<
name|int
operator|>
name|AboutToShowGroup
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|ids
argument_list|,
name|QList
operator|<
name|int
operator|>
operator|&
name|idErrors
argument_list|)
block|;
name|void
name|Event
argument_list|(
argument|int id
argument_list|,
argument|const QString&eventId
argument_list|,
argument|const QDBusVariant&data
argument_list|,
argument|uint timestamp
argument_list|)
block|;
name|void
name|EventGroup
argument_list|(
specifier|const
name|QDBusMenuEventList
operator|&
name|events
argument_list|)
block|;
name|QDBusMenuItemList
name|GetGroupProperties
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|ids
argument_list|,
specifier|const
name|QStringList
operator|&
name|propertyNames
argument_list|)
block|;
name|uint
name|GetLayout
argument_list|(
argument|int parentId
argument_list|,
argument|int recursionDepth
argument_list|,
argument|const QStringList&propertyNames
argument_list|,
argument|QDBusMenuLayoutItem&layout
argument_list|)
block|;
name|QDBusVariant
name|GetProperty
argument_list|(
argument|int id
argument_list|,
argument|const QString&name
argument_list|)
block|;
name|Q_SIGNALS
operator|:
comment|// SIGNALS
name|void
name|ItemActivationRequested
argument_list|(
argument|int id
argument_list|,
argument|uint timestamp
argument_list|)
block|;
name|void
name|ItemsPropertiesUpdated
argument_list|(
specifier|const
name|QDBusMenuItemList
operator|&
name|updatedProps
argument_list|,
specifier|const
name|QDBusMenuItemKeysList
operator|&
name|removedProps
argument_list|)
block|;
name|void
name|LayoutUpdated
argument_list|(
argument|uint revision
argument_list|,
argument|int parent
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DBUSMENUADAPTOR_H
end_comment
end_unit
