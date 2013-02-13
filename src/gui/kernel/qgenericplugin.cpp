begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgenericplugin.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QGenericPlugin     \ingroup plugins     \inmodule QtGui      \brief The QGenericPlugin class is an abstract base class for     plugins.      A mouse plugin can be created by subclassing     QGenericPlugin and reimplementing the pure virtual create()     function. By exporting the derived class using the     Q_PLUGIN_METADATA() macro, The default implementation of the     QGenericPluginFactory class will automatically detect the plugin and     load the driver into the server application at run-time. See \l     {How to Create Qt Plugins} for details.      The json metadata file should contain a list of keys supported by this     plugin.      \sa QGenericPluginFactory */
end_comment
begin_comment
comment|/*!     Constructs a plugin with the given \a parent.      Note that this constructor is invoked automatically by the     moc generated code that exports the plugin, so there is no need for calling it     explicitly. */
end_comment
begin_constructor
DECL|function|QGenericPlugin
name|QGenericPlugin
operator|::
name|QGenericPlugin
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
comment|/*!     Destroys the plugin.      Note that Qt destroys a plugin automatically when it is no longer     used, so there is no need for calling the destructor explicitly. */
end_comment
begin_destructor
DECL|function|~QGenericPlugin
name|QGenericPlugin
operator|::
name|~
name|QGenericPlugin
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn QObject* QGenericPlugin::create(const QString&key, const QString& specification)      Implement this function to create a driver matching the type     specified by the given \a key and \a specification parameters. Note that     keys are case-insensitive.      \sa keys() */
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
