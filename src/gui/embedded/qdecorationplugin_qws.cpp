begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdecorationplugin_qws.h"
end_include
begin_include
include|#
directive|include
file|"qdecoration_qws.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QDecorationPlugin     \ingroup qws     \ingroup plugins      \brief The QDecorationPlugin class is an abstract base class for     window decoration plugins in Qt for Embedded Linux.      Note that this class is only available in \l{Qt for Embedded Linux}.      \l{Qt for Embedded Linux} provides three ready-made decoration styles: \c     Default, \c Styled and \c Windows. Custom decorations can be     implemented by subclassing the QDecoration class and creating a     decoration plugin.      A decoration plugin can be created by subclassing     QDecorationPlugin and implementing the pure virtual keys() and     create() functions. By exporting the derived class using the     Q_EXPORT_PLUGIN2() macro, the default implementation of the     QDecorationFactory class will automatically detect the plugin and     load the driver into the application at run-time. See \l{How to     Create Qt Plugins} for details.      To actually apply a decoration, use the     QApplication::qwsSetDecoration() function.      \sa QDecoration, QDecorationFactory */
end_comment
begin_comment
comment|/*!     \fn QStringList QDecorationPlugin::keys() const      Returns the list of valid keys, i.e., the decorations supported by     this plugin.      \sa create() */
end_comment
begin_comment
comment|/*!     \fn QDecoration *QDecorationPlugin::create(const QString&key)      Creates a decoration matching the given \a key. Note that keys are     case-insensitive.      \sa keys() */
end_comment
begin_comment
comment|/*!     Constructs a decoration plugin with the given \a parent.      Note that this constructor is invoked automatically by the     Q_EXPORT_PLUGIN2() macro, so there is no need for calling it     explicitly. */
end_comment
begin_constructor
DECL|function|QDecorationPlugin
name|QDecorationPlugin
operator|::
name|QDecorationPlugin
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
comment|/*!     Destroys the decoration plugin.      Note that Qt destroys a plugin automatically when it is no longer     used, so there is no need for calling the destructor explicitly. */
end_comment
begin_destructor
DECL|function|~QDecorationPlugin
name|QDecorationPlugin
operator|::
name|~
name|QDecorationPlugin
parameter_list|()
block|{ }
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
