begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformthemefactory_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformthemeplugin.h>
end_include
begin_include
include|#
directive|include
file|<QDir>
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
file|"qguiapplication.h"
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
name|QPlatformThemeFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/platformthemes"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|directLoader
argument_list|,
operator|(
name|QPlatformThemeFactoryInterface_iid
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
name|QPlatformTheme
modifier|*
name|QPlatformThemeFactory
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
specifier|const
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
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
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
name|QPlatformTheme
modifier|*
name|ret
type|=
name|qLoadPlugin
argument_list|<
name|QPlatformTheme
argument_list|,
name|QPlatformThemePlugin
argument_list|>
type|(
name|directLoader
type|(
condition|)
operator|,
condition|platform
operator|,
condition|paramList))
return|return
name|ret
return|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|platformPluginPath
argument_list|)
argument_list|;
endif|#
directive|endif
argument_list|return
name|qLoadPlugin
argument_list|<
name|QPlatformTheme
argument_list|,
name|QPlatformThemePlugin
argument_list|>
argument_list|(
name|loader
argument_list|()
argument_list|,
name|platform
argument_list|,
name|paramList
argument_list|)
argument_list|; }
comment|/*!     Returns the list of valid keys, i.e. the keys this factory can     create styles for.      \sa create() */
DECL|function|keys
name|QStringList
name|QPlatformThemeFactory
operator|::
name|keys
argument_list|(
specifier|const
name|QString
operator|&
name|platformPluginPath
argument_list|)
argument_list|{
name|QStringList
name|list
argument_list|;
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
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
name|list
operator|+=
name|directLoader
argument_list|()
operator|->
name|keyMap
argument_list|()
operator|.
name|values
argument_list|()
block|;
if|if
condition|(
operator|!
name|list
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|postFix
operator|=
name|QStringLiteral
argument_list|(
literal|" (from "
argument_list|)
operator|+
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|platformPluginPath
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
block|;
specifier|const
name|QStringList
operator|::
name|iterator
name|end
operator|=
name|list
operator|.
name|end
argument_list|()
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|iterator
name|it
type|=
name|list
operator|.
name|begin
type|(
control|)
empty_stmt|;
end_decl_stmt
begin_expr_stmt
name|it
operator|!=
name|end
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|++
name|it
end_expr_stmt
begin_expr_stmt
unit|)
operator|(
operator|*
name|it
operator|)
operator|.
name|append
argument_list|(
name|postFix
argument_list|)
expr_stmt|;
end_expr_stmt
begin_else
unit|}     }
else|#
directive|else
end_else
begin_expr_stmt
name|Q_UNUSED
argument_list|(
name|platformPluginPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|list
operator|+=
name|loader
argument_list|()
operator|->
name|keyMap
argument_list|()
operator|.
name|values
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|list
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
