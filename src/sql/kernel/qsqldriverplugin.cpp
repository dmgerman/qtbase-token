begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsqldriverplugin.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QSqlDriverPlugin     \brief The QSqlDriverPlugin class provides an abstract base for custom QSqlDriver plugins.      \ingroup plugins     \inmodule QtSql      The SQL driver plugin is a simple plugin interface that makes it     easy to create your own SQL driver plugins that can be loaded     dynamically by Qt.      Writing a SQL plugin is achieved by subclassing this base class,     reimplementing the pure virtual functions keys() and create(), and     exporting the class with the Q_EXPORT_PLUGIN2() macro. See the SQL     plugins that come with Qt for example implementations (in the     \c{plugins/src/sqldrivers} subdirectory of the source     distribution).      \sa {How to Create Qt Plugins} */
end_comment
begin_comment
comment|/*!     \fn QStringList QSqlDriverPlugin::keys() const      Returns the list of drivers (keys) this plugin supports.      These keys are usually the class names of the custom drivers that     are implemented in the plugin.      \sa create() */
end_comment
begin_comment
comment|/*!     \fn QSqlDriver *QSqlDriverPlugin::create(const QString& key)      Creates and returns a QSqlDriver object for the driver called \a     key. The driver key is usually the class name of the required     driver. Keys are case sensitive.      \sa keys() */
end_comment
begin_comment
comment|/*!     Constructs a SQL driver plugin and sets the parent to \a parent.     This is invoked automatically by the Q_EXPORT_PLUGIN2() macro. */
end_comment
begin_constructor
DECL|function|QSqlDriverPlugin
name|QSqlDriverPlugin
operator|::
name|QSqlDriverPlugin
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
comment|/*!     Destroys the SQL driver plugin.      You never have to call this explicitly. Qt destroys a plugin     automatically when it is no longer used. */
end_comment
begin_destructor
DECL|function|~QSqlDriverPlugin
name|QSqlDriverPlugin
operator|::
name|~
name|QSqlDriverPlugin
parameter_list|()
block|{ }
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
