begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qscreendriverplugin_qws.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_comment
comment|/*!     \class QScreenDriverPlugin     \ingroup plugins     \ingroup qws      \brief The QScreenDriverPlugin class is an abstract base class for     screen driver plugins in Qt for Embedded Linux.      Note that this class is only available in \l{Qt for Embedded Linux}.      \l{Qt for Embedded Linux} provides ready-made drivers for several screen     protocols, see the \l{Qt for Embedded Linux Display Management}{display     management} documentation for details. Custom screen drivers can be     implemented by subclassing the QScreen class and creating a screen     driver plugin.      A screen driver plugin can be created by subclassing     QScreenDriverPlugin and reimplementing the pure virtual keys() and     create() functions. By exporting the derived class using the     Q_EXPORT_PLUGIN2() macro, The default implementation of the     QScreenDriverFactory class will automatically detect the plugin     and load the driver into the server application at run-time.  See     \l{How to Create Qt Plugins} for details.      \sa QScreen, QScreenDriverFactory */
end_comment
begin_comment
comment|/*!     \fn QStringList QScreenDriverPlugin::keys() const      Implement this function to return the list of valid keys, i.e. the     screen drivers supported by this plugin.      \l{Qt for Embedded Linux} provides ready-made drivers for several screen     protocols, see the \l{Qt for Embedded Linux Display Management}{display     management} documentation for details.      \sa create() */
end_comment
begin_comment
comment|/*!     Constructs a screen driver plugin with the given \a parent.      Note that this constructor is invoked automatically by the     Q_EXPORT_PLUGIN2() macro, so there is no need for calling it     explicitly. */
end_comment
begin_constructor
DECL|function|QScreenDriverPlugin
name|QScreenDriverPlugin
operator|::
name|QScreenDriverPlugin
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
comment|/*!     Destroys this screen driver plugin.      Note that Qt destroys a plugin automatically when it is no longer     used, so there is no need for calling the destructor explicitly. */
end_comment
begin_destructor
DECL|function|~QScreenDriverPlugin
name|QScreenDriverPlugin
operator|::
name|~
name|QScreenDriverPlugin
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn QScreen* QScreenDriverPlugin::create(const QString&key, int displayId)      Implement this function to create a driver matching the type     specified by the given \a key and \a displayId parameters. Note     that keys are case-insensitive.      \sa keys() */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
