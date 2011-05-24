begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmousedriverplugin_qws.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_include
include|#
directive|include
file|"qmouse_qws.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QMouseDriverPlugin     \ingroup plugins     \ingroup qws      \brief The QMouseDriverPlugin class is an abstract base class for     mouse driver plugins in Qt for Embedded Linux.      Note that this class is only available in \l{Qt for Embedded Linux}.      \l{Qt for Embedded Linux} provides ready-made drivers for several mouse     protocols, see the \l{Qt for Embedded Linux Pointer Handling}{pointer     handling} documentation for details. Custom mouse drivers can be     implemented by subclassing the QWSMouseHandler class and creating     a mouse driver plugin.      A mouse driver plugin can be created by subclassing     QMouseDriverPlugin and reimplementing the pure virtual keys() and     create() functions. By exporting the derived class using the     Q_EXPORT_PLUGIN2() macro, The default implementation of the     QMouseDriverFactory class will automatically detect the plugin and     load the driver into the server application at run-time. See \l     {How to Create Qt Plugins} for details.      \sa QWSMouseHandler, QMouseDriverFactory */
end_comment
begin_comment
comment|/*!     \fn QStringList QMouseDriverPlugin::keys() const      Implement this function to return the list of valid keys, i.e. the     mouse drivers supported by this plugin.      \l{Qt for Embedded Linux} provides ready-made drivers for several mouse     protocols, see the \l {Qt for Embedded Linux Pointer Handling}{pointer     handling} documentation for details.      \sa create() */
end_comment
begin_comment
comment|/*!     Constructs a mouse driver plugin with the given \a parent.      Note that this constructor is invoked automatically by the     Q_EXPORT_PLUGIN2() macro, so there is no need for calling it     explicitly. */
end_comment
begin_constructor
DECL|function|QMouseDriverPlugin
name|QMouseDriverPlugin
operator|::
name|QMouseDriverPlugin
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the mouse driver plugin.      Note that Qt destroys a plugin automatically when it is no longer     used, so there is no need for calling the destructor explicitly. */
end_comment
begin_destructor
DECL|function|~QMouseDriverPlugin
name|QMouseDriverPlugin
operator|::
name|~
name|QMouseDriverPlugin
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn QScreen* QMouseDriverPlugin::create(const QString&key, const QString& device)      Implement this function to create a driver matching the type     specified by the given \a key and \a device parameters. Note that     keys are case-insensitive.      \sa keys() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
end_unit
