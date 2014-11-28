begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*     This file was originally created by qdbusxml2cpp version 0.8     Command line was:     qdbusxml2cpp -a statusnotifieritem ../../3rdparty/dbus-ifaces/org.kde.StatusNotifierItem.xml      However it is maintained manually.      It is also not part of the public API. This header file may change from     version to version without notice, or even be removed. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTATUSNOTIFIERITEMADAPTER_P_H
end_ifndef
begin_define
DECL|macro|QSTATUSNOTIFIERITEMADAPTER_P_H
define|#
directive|define
name|QSTATUSNOTIFIERITEMADAPTER_P_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
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
file|"qdbustraytypes_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusTrayIcon
name|class
name|QDBusTrayIcon
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*     Adaptor class for interface org.kde.StatusNotifierItem     see http://www.freedesktop.org/wiki/Specifications/StatusNotifierItem/     (also http://www.notmart.org/misc/statusnotifieritem/) */
end_comment
begin_decl_stmt
name|class
name|QStatusNotifierItemAdaptor
range|:
name|public
name|QDBusAbstractAdaptor
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.kde.StatusNotifierItem"
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Introspection"
argument_list|,
literal|""
literal|"<interface name=\"org.kde.StatusNotifierItem\">\n"
literal|"<property access=\"read\" type=\"s\" name=\"Category\"/>\n"
literal|"<property access=\"read\" type=\"s\" name=\"Id\"/>\n"
literal|"<property access=\"read\" type=\"s\" name=\"Title\"/>\n"
literal|"<property access=\"read\" type=\"s\" name=\"Status\"/>\n"
literal|"<property access=\"read\" type=\"i\" name=\"WindowId\"/>\n"
literal|"<property access=\"read\" type=\"s\" name=\"IconThemePath\"/>\n"
literal|"<property access=\"read\" type=\"o\" name=\"Menu\"/>\n"
literal|"<property access=\"read\" type=\"b\" name=\"ItemIsMenu\"/>\n"
literal|"<property access=\"read\" type=\"s\" name=\"IconName\"/>\n"
literal|"<property access=\"read\" type=\"(iiay)\" name=\"IconPixmap\">\n"
literal|"<annotation value=\"QXdgDBusImageVector\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
literal|"</property>\n"
literal|"<property access=\"read\" type=\"s\" name=\"OverlayIconName\"/>\n"
literal|"<property access=\"read\" type=\"(iiay)\" name=\"OverlayIconPixmap\">\n"
literal|"<annotation value=\"QXdgDBusImageVector\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
literal|"</property>\n"
literal|"<property access=\"read\" type=\"s\" name=\"AttentionIconName\"/>\n"
literal|"<property access=\"read\" type=\"(iiay)\" name=\"AttentionIconPixmap\">\n"
literal|"<annotation value=\"QXdgDBusImageVector\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
literal|"</property>\n"
literal|"<property access=\"read\" type=\"s\" name=\"AttentionMovieName\"/>\n"
literal|"<property access=\"read\" type=\"(s(iiay)ss)\" name=\"ToolTip\">\n"
literal|"<annotation value=\"QXdgDBusToolTipStruct\" name=\"org.qtproject.QtDBus.QtTypeName\"/>\n"
literal|"</property>\n"
literal|"<method name=\"ContextMenu\">\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"x\"/>\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"y\"/>\n"
literal|"</method>\n"
literal|"<method name=\"Activate\">\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"x\"/>\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"y\"/>\n"
literal|"</method>\n"
literal|"<method name=\"SecondaryActivate\">\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"x\"/>\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"y\"/>\n"
literal|"</method>\n"
literal|"<method name=\"Scroll\">\n"
literal|"<arg direction=\"in\" type=\"i\" name=\"delta\"/>\n"
literal|"<arg direction=\"in\" type=\"s\" name=\"orientation\"/>\n"
literal|"</method>\n"
literal|"<signal name=\"NewTitle\"/>\n"
literal|"<signal name=\"NewIcon\"/>\n"
literal|"<signal name=\"NewAttentionIcon\"/>\n"
literal|"<signal name=\"NewOverlayIcon\"/>\n"
literal|"<signal name=\"NewToolTip\"/>\n"
literal|"<signal name=\"NewStatus\">\n"
literal|"<arg type=\"s\" name=\"status\"/>\n"
literal|"</signal>\n"
literal|"</interface>\n"
literal|""
argument_list|)
name|public
operator|:
name|QStatusNotifierItemAdaptor
argument_list|(
name|QDBusTrayIcon
operator|*
name|parent
argument_list|)
block|;
name|virtual
operator|~
name|QStatusNotifierItemAdaptor
argument_list|()
block|;
name|public
operator|:
comment|// PROPERTIES
name|Q_PROPERTY
argument_list|(
argument|QString AttentionIconName READ attentionIconName
argument_list|)
name|QString
name|attentionIconName
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QXdgDBusImageVector AttentionIconPixmap READ attentionIconPixmap
argument_list|)
name|QXdgDBusImageVector
name|attentionIconPixmap
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QString AttentionMovieName READ attentionMovieName
argument_list|)
name|QString
name|attentionMovieName
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QString Category READ category
argument_list|)
name|QString
name|category
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QString IconName READ iconName
argument_list|)
name|QString
name|iconName
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QXdgDBusImageVector IconPixmap READ iconPixmap
argument_list|)
name|QXdgDBusImageVector
name|iconPixmap
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QString Id READ id
argument_list|)
name|QString
name|id
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|bool ItemIsMenu READ itemIsMenu
argument_list|)
name|bool
name|itemIsMenu
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QDBusObjectPath Menu READ menu
argument_list|)
name|QDBusObjectPath
name|menu
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QString OverlayIconName READ overlayIconName
argument_list|)
name|QString
name|overlayIconName
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QXdgDBusImageVector OverlayIconPixmap READ overlayIconPixmap
argument_list|)
name|QXdgDBusImageVector
name|overlayIconPixmap
argument_list|()
specifier|const
block|;
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
argument|QString Title READ title
argument_list|)
name|QString
name|title
argument_list|()
specifier|const
block|;
name|Q_PROPERTY
argument_list|(
argument|QXdgDBusToolTipStruct ToolTip READ toolTip
argument_list|)
name|QXdgDBusToolTipStruct
name|toolTip
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
comment|// METHODS
name|void
name|Activate
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|void
name|ContextMenu
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|void
name|Scroll
argument_list|(
argument|int delta
argument_list|,
argument|const QString&orientation
argument_list|)
block|;
name|void
name|SecondaryActivate
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|Q_SIGNALS
operator|:
comment|// SIGNALS
name|void
name|NewAttentionIcon
argument_list|()
block|;
name|void
name|NewIcon
argument_list|()
block|;
name|void
name|NewOverlayIcon
argument_list|()
block|;
name|void
name|NewStatus
argument_list|(
specifier|const
name|QString
operator|&
name|status
argument_list|)
block|;
name|void
name|NewTitle
argument_list|()
block|;
name|void
name|NewToolTip
argument_list|()
block|;
name|private
operator|:
name|QDBusTrayIcon
operator|*
name|m_trayIcon
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
comment|// QT_NO_SYSTEMTRAYICON
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTATUSNOTIFIERITEMADAPTER_P_H
end_comment
end_unit
