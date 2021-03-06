begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontextfactory_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontextplugin_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
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
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QPlatformInputContextFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/platforminputcontexts"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
DECL|function|keys
name|QStringList
name|QPlatformInputContextFactory
operator|::
name|keys
argument_list|()
argument_list|{
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
argument_list|return
name|loader
argument_list|()
operator|->
name|keyMap
argument_list|()
operator|.
name|values
argument_list|()
argument_list|;
else|#
directive|else
argument_list|return
name|QStringList
argument_list|()
argument_list|;
endif|#
directive|endif
argument_list|}
DECL|function|requested
name|QString
name|QPlatformInputContextFactory
operator|::
name|requested
argument_list|()
argument_list|{
name|QByteArray
name|env
operator|=
name|qgetenv
argument_list|(
literal|"QT_IM_MODULE"
argument_list|)
argument_list|;     return
name|env
operator|.
name|isNull
argument_list|()
condition|?
name|QString
argument_list|()
else|:
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|env
argument_list|)
argument_list|; }
DECL|function|create
name|QPlatformInputContext
modifier|*
name|QPlatformInputContextFactory
operator|::
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
argument_list|{
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
argument_list|if
operator|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
operator|)
block|{
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
block|;
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
block|;
name|QPlatformInputContext
operator|*
name|ic
operator|=
name|qLoadPlugin
argument_list|<
name|QPlatformInputContext
argument_list|,
name|QPlatformInputContextPlugin
argument_list|>
argument_list|(
name|loader
argument_list|()
argument_list|,
name|platform
argument_list|,
name|paramList
argument_list|)
block|;
if|if
condition|(
name|ic
operator|&&
name|ic
operator|->
name|isValid
argument_list|()
condition|)
return|return
name|ic
return|;
operator|delete
name|ic
argument_list|;     }
endif|#
directive|endif
decl|return 0
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|}  QPlatformInputContext
DECL|function|create
operator|*
name|QPlatformInputContextFactory
operator|::
name|create
operator|(
operator|)
block|{
return|return
name|create
argument_list|(
name|requested
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
