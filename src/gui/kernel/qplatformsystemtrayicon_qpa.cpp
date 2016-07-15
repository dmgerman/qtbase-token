begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Copyright (C) 2012 Klaralvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Christoph Schleifenbaum<christoph.schleifenbaum@kdab.com> ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformsystemtrayicon.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformSystemTrayIcon     \brief The QPlatformSystemTrayIcon class abstracts the system tray icon and interaction.      \sa QSystemTray */
comment|/*!     \internal  */
DECL|function|QPlatformSystemTrayIcon
name|QPlatformSystemTrayIcon
operator|::
name|QPlatformSystemTrayIcon
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_destructor
DECL|function|~QPlatformSystemTrayIcon
name|QPlatformSystemTrayIcon
operator|::
name|~
name|QPlatformSystemTrayIcon
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::init()     This method is called to initialize the platform dependent implementation. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::cleanup()     This method is called to cleanup the platform dependent implementation. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::updateIcon(const QIcon&icon)     This method is called when the \a icon did change. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::updateToolTip(const QString&tooltip)     This method is called when the \a tooltip text did change. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::updateMenu(QPlatformMenu *menu)     This method is called when the system tray \a menu did change. */
end_comment
begin_comment
comment|/*!     \fn QRect QPlatformSystemTrayIcon::geometry() const     This method returns the geometry of the platform dependent system tray icon on the screen. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::showMessage(const QString&msg, const QString&title,                                                   const QIcon&icon, MessageIcon iconType, int secs)     Shows a balloon message for the entry with the given \a title, message \msg and \a icon for     the time specified in \secs. \a iconType is used as a hint for the implementing platform.     \sa QSystemTrayIcon::showMessage */
end_comment
begin_comment
comment|/*!     \fn bool QPlatformSystemTrayIcon::isSystemTrayAvailable()     Returns true if the system tray is available on the platform. */
end_comment
begin_comment
comment|/*!     bool QPlatformSystemTrayIcon::supportsMessages()     Returns true if the system tray supports messages on the platform. */
end_comment
begin_comment
comment|/*!     \fn void activated(QPlatformSystemTrayIcon::ActivationReason reason)     This signal is emitted when the user activates the system tray icon.     \a reason specifies the reason for activation.     \sa QSystemTrayIcon::ActivationReason. */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qplatformsystemtrayicon.cpp"
end_include
end_unit
