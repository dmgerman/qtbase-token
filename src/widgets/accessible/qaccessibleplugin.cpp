begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessibleplugin.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"qaccessible.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QAccessiblePlugin     \brief The QAccessiblePlugin class provides an abstract base for     accessibility plugins.      \ingroup plugins     \ingroup accessibility      Writing an accessibility plugin is achieved by subclassing this     base class, reimplementing the pure virtual functions keys() and     create(), and exporting the class with the Q_EXPORT_PLUGIN2()     macro.      \sa QAccessibleBridgePlugin, {How to Create Qt Plugins} */
end_comment
begin_comment
comment|/*!     Constructs an accessibility plugin with the given \a parent. This     is invoked automatically by the Q_EXPORT_PLUGIN2() macro. */
end_comment
begin_constructor
DECL|function|QAccessiblePlugin
name|QAccessiblePlugin
operator|::
name|QAccessiblePlugin
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
comment|/*!     Destroys the accessibility plugin.      You never have to call this explicitly. Qt destroys a plugin     automatically when it is no longer used. */
end_comment
begin_destructor
DECL|function|~QAccessiblePlugin
name|QAccessiblePlugin
operator|::
name|~
name|QAccessiblePlugin
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn QStringList QAccessiblePlugin::keys() const      Returns the list of keys this plugin supports.      These keys must be the class names that this plugin provides     an accessibility implementation for.      \sa create() */
end_comment
begin_comment
comment|/*!     \fn QAccessibleInterface *QAccessiblePlugin::create(const QString&key, QObject *object)      Creates and returns a QAccessibleInterface implementation for the     class \a key and the object \a object. Keys are case sensitive.      \sa keys() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
end_unit
