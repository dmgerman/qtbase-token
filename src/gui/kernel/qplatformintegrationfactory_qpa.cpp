begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformintegrationfactory_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|<QPlatformIntegrationPlugin>
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SETTINGS
argument_list|)
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QPlatformIntegrationFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/platforms"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|directLoader
argument_list|,
operator|(
name|QPlatformIntegrationFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|""
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
DECL|function|create
name|QPlatformIntegration
modifier|*
name|QPlatformIntegrationFactory
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
name|platformPluginPath
argument_list|)
argument_list|{
name|QPlatformIntegration
operator|*
name|ret
operator|=
literal|0
argument_list|;
name|QStringList
name|paramList
operator|=
name|key
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
argument_list|;
name|QString
name|platform
operator|=
name|paramList
operator|.
name|takeFirst
argument_list|()
operator|.
name|toLower
argument_list|()
argument_list|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SETTINGS
argument_list|)
comment|// Try loading the plugin from platformPluginPath first:
argument_list|if
operator|(
operator|!
name|platformPluginPath
operator|.
name|isEmpty
argument_list|()
operator|)
block|{
name|QCoreApplication
operator|::
name|addLibraryPath
argument_list|(
name|platformPluginPath
argument_list|)
block|;
if|if
condition|(
name|QPlatformIntegrationFactoryInterface
modifier|*
name|factory
type|=
name|qobject_cast
argument_list|<
name|QPlatformIntegrationFactoryInterface
operator|*
argument_list|>
type|(
name|directLoader
type|(
condition|)->instance(platform))
argument_list|)
name|ret
init|=
name|factory
operator|->
name|create
argument_list|(
name|key
argument_list|,
name|paramList
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|ret
condition|)
return|return
name|ret
return|;
end_if
begin_expr_stmt
unit|}     if
operator|(
name|QPlatformIntegrationFactoryInterface
operator|*
name|factory
operator|=
name|qobject_cast
argument_list|<
name|QPlatformIntegrationFactoryInterface
operator|*
argument_list|>
argument_list|(
name|loader
argument_list|()
operator|->
name|instance
argument_list|(
name|platform
argument_list|)
argument_list|)
operator|)
name|ret
operator|=
name|factory
operator|->
name|create
argument_list|(
name|platform
argument_list|,
name|paramList
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
name|ret
return|;
end_return
begin_comment
unit|}
comment|/*!     Returns the list of valid keys, i.e. the keys this factory can     create styles for.      \sa create() */
end_comment
begin_macro
unit|QStringList
DECL|function|keys
name|QPlatformIntegrationFactory
end_macro
begin_expr_stmt
DECL|function|keys
operator|::
name|keys
operator|(
specifier|const
name|QString
operator|&
name|platformPluginPath
operator|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SETTINGS
argument_list|)
name|QStringList
name|list
block|;
if|if
condition|(
operator|!
name|platformPluginPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QCoreApplication
operator|::
name|addLibraryPath
argument_list|(
name|platformPluginPath
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|key
decl|,
name|directLoader
argument_list|()
operator|->
name|keys
argument_list|()
control|)
block|{
name|list
operator|+=
name|key
operator|+
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|" (from %1)"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|platformPluginPath
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}      list
operator|+=
name|loader
argument_list|()
operator|->
name|keys
argument_list|()
expr_stmt|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
name|list
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
