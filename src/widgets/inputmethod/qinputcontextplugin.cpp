begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Implementation of QInputContext class ** ** Copyright (C) 2003-2004 immodule for Qt Project.  All rights reserved. ** ** This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own ** license. You may use this file under your Qt license. Following ** description is copied from their original file headers. Contact ** immodule-qt@freedesktop.org if any conditions of this licensing are ** not clear to you. ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qinputcontextplugin.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IM
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QInputContextPlugin     \brief The QInputContextPlugin class provides an abstract base for custom QInputContext plugins.      \reentrant     \ingroup plugins      The input context plugin is a simple plugin interface that makes it     easy to create custom input contexts that can be loaded dynamically     into applications.      To create an input context plugin you subclass this base class,     reimplement the pure virtual functions keys(), create(),     languages(), displayName(), and description(), and export the     class with the Q_EXPORT_PLUGIN2() macro.      \legalese     Copyright (C) 2003-2004 immodule for Qt Project.  All rights reserved.      This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own     license. You may use this file under your Qt license. Following     description is copied from their original file headers. Contact     immodule-qt@freedesktop.org if any conditions of this licensing are     not clear to you.     \endlegalese      \sa QInputContext, {How to Create Qt Plugins} */
end_comment
begin_comment
comment|/*!     \fn QStringList QInputContextPlugin::keys() const      Returns the list of QInputContext keys this plugin provides.      These keys are usually the class names of the custom input context     that are implemented in the plugin. The names are used, for     example, to identify and specify input methods for the input     method switching mechanism.  They have to be consistent with     QInputContext::identifierName(), and may only contain ASCII     characters.      \sa create(), displayName(), QInputContext::identifierName() */
end_comment
begin_comment
comment|/*!     \fn QInputContext* QInputContextPlugin::create( const QString& key )      Creates and returns a QInputContext object for the input context     key \a key.  The input context key is usually the class name of     the required input method.      \sa keys() */
end_comment
begin_comment
comment|/*!     \fn QStringList QInputContextPlugin::languages(const QString&key)      Returns the languages supported by the QInputContext object     specified by \a key.      The languages are expressed as language code (e.g. "zh_CN",     "zh_TW", "zh_HK", "ja", "ko", ...). An input context that supports     multiple languages can return all supported languages as     QStringList. The name has to be consistent with     QInputContext::language().      This information may be used to optimize user interface.      \sa keys(), QInputContext::language(), QLocale */
end_comment
begin_comment
comment|/*!     \fn QString QInputContextPlugin::displayName(const QString&key)      Returns a user friendly internationalized name of the     QInputContext object specified by \a key. You can, for example,     use this name in a menu.      \sa keys(), QInputContext::identifierName() */
end_comment
begin_comment
comment|/*!     \fn QString QInputContextPlugin::description(const QString&key)      Returns an internationalized brief description of the QInputContext     object specified by \a key. You can, for example, use this     description in a user interface.      \sa keys(), displayName() */
end_comment
begin_comment
comment|/*!     Constructs a input context plugin with the given \a parent. This     is invoked automatically by the Q_EXPORT_PLUGIN2() macro. */
end_comment
begin_constructor
DECL|function|QInputContextPlugin
name|QInputContextPlugin
operator|::
name|QInputContextPlugin
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
comment|/*!     Destroys the input context plugin.      You never have to call this explicitly. Qt destroys a plugin     automatically when it's no longer used. */
end_comment
begin_destructor
DECL|function|~QInputContextPlugin
name|QInputContextPlugin
operator|::
name|~
name|QInputContextPlugin
parameter_list|()
block|{ }
end_destructor
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_IM
end_comment
end_unit
