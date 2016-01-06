begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgenericpluginfactory.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication.h"
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
end_include
begin_include
include|#
directive|include
file|"qgenericplugin.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QGenericPluginFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/generic"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
comment|/*!     \class QGenericPluginFactory     \ingroup plugins     \inmodule QtGui      \brief The QGenericPluginFactory class creates plugin drivers.      \sa QGenericPlugin */
comment|/*!     Creates the driver specified by \a key, using the given \a specification.      Note that the keys are case-insensitive.      \sa keys() */
DECL|function|create
name|QObject
modifier|*
name|QGenericPluginFactory
operator|::
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|specification
argument_list|)
argument_list|{     return
name|qLoadPlugin
argument_list|<
name|QObject
argument_list|,
name|QGenericPlugin
argument_list|>
argument_list|(
name|loader
argument_list|()
argument_list|,
name|key
operator|.
name|toLower
argument_list|()
argument_list|,
name|specification
argument_list|)
argument_list|; }
comment|/*!     Returns the list of valid keys, i.e. the available mouse drivers.      \sa create() */
DECL|function|keys
name|QStringList
name|QGenericPluginFactory
operator|::
name|keys
argument_list|()
argument_list|{
name|QStringList
name|list
argument_list|;      typedef
name|QMultiMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|PluginKeyMap
argument_list|;     typedef
name|PluginKeyMap
operator|::
name|const_iterator
name|PluginKeyMapConstIterator
argument_list|;
specifier|const
name|PluginKeyMap
name|keyMap
operator|=
name|loader
argument_list|()
operator|->
name|keyMap
argument_list|()
argument_list|;
specifier|const
name|PluginKeyMapConstIterator
name|cend
operator|=
name|keyMap
operator|.
name|constEnd
argument_list|()
argument_list|;     for
operator|(
name|PluginKeyMapConstIterator
name|it
operator|=
name|keyMap
operator|.
name|constBegin
argument_list|()
expr|;
name|it
operator|!=
name|cend
expr|;
operator|++
name|it
operator|)
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
condition|)
name|list
operator|+=
name|it
operator|.
name|value
argument_list|()
expr_stmt|;
end_decl_stmt
begin_return
return|return
name|list
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
