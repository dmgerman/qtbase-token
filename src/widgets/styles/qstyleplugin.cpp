begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstyleplugin.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QStylePlugin     \brief The QStylePlugin class provides an abstract base for custom QStyle plugins.      \ingroup plugins     \inmodule QtWidgets      QStylePlugin is a simple plugin interface that makes it easy     to create custom styles that can be loaded dynamically into     applications using the QStyleFactory class.      Writing a style plugin is achieved by subclassing this base class,     reimplementing the pure virtual create() function, and     exporting the class using the Q_PLUGIN_METADATA() macro. See \l     {How to Create Qt Plugins} for details.      The json metadata file for the plugin needs to contain information     about the names of the styles the plugins supports as follows:      \code     { "Keys": [ "mystyle" ] }     \endcode      \sa QStyleFactory, QStyle */
end_comment
begin_comment
comment|/*!     \fn QStyle *QStylePlugin::create(const QString& key)      Creates and returns a QStyle object for the given style \a key.     If a plugin cannot create a style, it should return 0 instead.      The style key is usually the class name of the required     style. Note that the keys are case insensitive. For example:      \snippet qstyleplugin/main.cpp 0     \codeline     \snippet qstyleplugin/main.cpp 1     \snippet qstyleplugin/main.cpp 2      \sa keys() */
end_comment
begin_comment
comment|/*!     Constructs a style plugin with the given \a parent.      Note that this constructor is invoked automatically by the     Q_EXPORT_PLUGIN2() macro, so there is no need for calling it     explicitly. */
end_comment
begin_constructor
DECL|function|QStylePlugin
name|QStylePlugin
operator|::
name|QStylePlugin
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
comment|/*!     Destroys the style plugin.      Note that Qt destroys a plugin automatically when it is no longer     used, so there is no need for calling the destructor explicitly. */
end_comment
begin_destructor
DECL|function|~QStylePlugin
name|QStylePlugin
operator|::
name|~
name|QStylePlugin
parameter_list|()
block|{ }
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
