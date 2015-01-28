begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*     This file was originally created by qdbusxml2cpp version 0.8     Command line was:     qdbusxml2cpp -a statusnotifieritem ../../3rdparty/dbus-ifaces/org.kde.StatusNotifierItem.xml      However it is maintained manually, because this adapter needs to do     significant interface adaptation, and can do it more efficiently using the     QDBusTrayIcon API directly rather than via QObject::property() and     QMetaObject::invokeMethod(). */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_include
include|#
directive|include
file|"qstatusnotifieritemadaptor_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbustrayicon_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcMenu
argument_list|)
DECL|function|QStatusNotifierItemAdaptor
name|QStatusNotifierItemAdaptor
operator|::
name|QStatusNotifierItemAdaptor
argument_list|(
name|QDBusTrayIcon
operator|*
name|parent
argument_list|)
range|:
name|QDBusAbstractAdaptor
argument_list|(
name|parent
argument_list|)
decl_stmt|,
name|m_trayIcon
argument_list|(
name|parent
argument_list|)
argument_list|{
name|setAutoRelaySignals
argument_list|(
literal|true
argument_list|)
argument_list|; }
DECL|function|~QStatusNotifierItemAdaptor
name|QStatusNotifierItemAdaptor
operator|::
name|~
name|QStatusNotifierItemAdaptor
argument_list|()
argument_list|{ }
DECL|function|attentionIconName
name|QString
name|QStatusNotifierItemAdaptor
operator|::
name|attentionIconName
argument_list|()
decl|const
argument_list|{     return
name|m_trayIcon
operator|->
name|attentionIconName
argument_list|()
argument_list|; }
DECL|function|attentionIconPixmap
name|QXdgDBusImageVector
name|QStatusNotifierItemAdaptor
operator|::
name|attentionIconPixmap
argument_list|()
decl|const
argument_list|{     return
name|iconToQXdgDBusImageVector
argument_list|(
name|m_trayIcon
operator|->
name|attentionIcon
argument_list|()
argument_list|)
argument_list|; }
DECL|function|attentionMovieName
name|QString
name|QStatusNotifierItemAdaptor
operator|::
name|attentionMovieName
argument_list|()
decl|const
argument_list|{     return
name|QString
argument_list|()
argument_list|; }
DECL|function|category
name|QString
name|QStatusNotifierItemAdaptor
operator|::
name|category
argument_list|()
decl|const
argument_list|{     return
name|m_trayIcon
operator|->
name|category
argument_list|()
argument_list|; }
DECL|function|iconName
name|QString
name|QStatusNotifierItemAdaptor
operator|::
name|iconName
argument_list|()
decl|const
argument_list|{     return
name|m_trayIcon
operator|->
name|iconName
argument_list|()
argument_list|; }
DECL|function|iconPixmap
name|QXdgDBusImageVector
name|QStatusNotifierItemAdaptor
operator|::
name|iconPixmap
argument_list|()
decl|const
argument_list|{     return
name|iconToQXdgDBusImageVector
argument_list|(
name|m_trayIcon
operator|->
name|icon
argument_list|()
argument_list|)
argument_list|; }
DECL|function|id
name|QString
name|QStatusNotifierItemAdaptor
operator|::
name|id
argument_list|()
decl|const
argument_list|{
comment|// from the API docs: "a name that should be unique for this application and
comment|// consistent between sessions, such as the application name itself"
argument_list|return
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
argument_list|; }
DECL|function|itemIsMenu
name|bool
name|QStatusNotifierItemAdaptor
operator|::
name|itemIsMenu
argument_list|()
decl|const
argument_list|{
comment|// From KDE docs: if this is true, the item only supports the context menu,
comment|// so the visualization should prefer sending ContextMenu() instead of Activate().
comment|// But QSystemTrayIcon doesn't have such a setting: it will emit activated()
comment|// and the application is free to use it or ignore it; we don't know whether it will.
argument_list|return
literal|false
argument_list|; }
DECL|function|menu
name|QDBusObjectPath
name|QStatusNotifierItemAdaptor
operator|::
name|menu
argument_list|()
decl|const
argument_list|{     return
name|QDBusObjectPath
argument_list|(
name|m_trayIcon
operator|->
name|menu
argument_list|()
condition|?
literal|"/MenuBar"
else|:
literal|"/NO_DBUSMENU"
argument_list|)
argument_list|; }
DECL|function|overlayIconName
name|QString
name|QStatusNotifierItemAdaptor
operator|::
name|overlayIconName
argument_list|()
decl|const
argument_list|{     return
name|QString
argument_list|()
argument_list|; }
DECL|function|overlayIconPixmap
name|QXdgDBusImageVector
name|QStatusNotifierItemAdaptor
operator|::
name|overlayIconPixmap
argument_list|()
decl|const
argument_list|{
name|QXdgDBusImageVector
name|ret
argument_list|;
comment|// empty vector
argument_list|return
name|ret
argument_list|; }
DECL|function|status
name|QString
name|QStatusNotifierItemAdaptor
operator|::
name|status
argument_list|()
decl|const
argument_list|{     return
name|m_trayIcon
operator|->
name|status
argument_list|()
argument_list|; }
DECL|function|title
name|QString
name|QStatusNotifierItemAdaptor
operator|::
name|title
argument_list|()
decl|const
argument_list|{
comment|// Shown e.g. when the icon is hidden, in the popup showing all hidden items.
comment|// Since QSystemTrayIcon doesn't have this property, the application name
comment|// is the best information we have available.
argument_list|return
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
argument_list|; }
DECL|function|toolTip
name|QXdgDBusToolTipStruct
name|QStatusNotifierItemAdaptor
operator|::
name|toolTip
argument_list|()
decl|const
argument_list|{
name|QXdgDBusToolTipStruct
name|ret
argument_list|;     if
operator|(
name|m_trayIcon
operator|->
name|isRequestingAttention
argument_list|()
operator|)
block|{
name|ret
operator|.
name|title
operator|=
name|m_trayIcon
operator|->
name|attentionTitle
argument_list|()
block|;
name|ret
operator|.
name|subTitle
operator|=
name|m_trayIcon
operator|->
name|attentionMessage
argument_list|()
block|;
name|ret
operator|.
name|icon
operator|=
name|m_trayIcon
operator|->
name|attentionIconName
argument_list|()
block|;     }
else|else
block|{
name|ret
operator|.
name|title
operator|=
name|m_trayIcon
operator|->
name|tooltip
argument_list|()
block|;     }
return|return
name|ret
return|;
end_decl_stmt
begin_macro
unit|}  void
DECL|function|Activate
name|QStatusNotifierItemAdaptor
end_macro
begin_expr_stmt
DECL|function|Activate
operator|::
name|Activate
operator|(
name|int
name|x
operator|,
name|int
name|y
operator|)
block|{
name|m_trayIcon
operator|->
name|activate
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
block|; }
DECL|function|ContextMenu
name|void
name|QStatusNotifierItemAdaptor
operator|::
name|ContextMenu
operator|(
name|int
name|x
operator|,
name|int
name|y
operator|)
block|{
name|m_trayIcon
operator|->
name|contextMenu
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
block|; }
DECL|function|Scroll
name|void
name|QStatusNotifierItemAdaptor
operator|::
name|Scroll
operator|(
name|int
operator|,
specifier|const
name|QString
operator|&
operator|)
block|{
comment|// unsupported
block|}
DECL|function|SecondaryActivate
name|void
name|QStatusNotifierItemAdaptor
operator|::
name|SecondaryActivate
operator|(
name|int
operator|,
name|int
operator|)
block|{
comment|// unsupported
block|}
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMTRAYICON
end_comment
end_unit
