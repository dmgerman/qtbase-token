begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
argument_list|if
operator|(
name|QPlatformInputContext
operator|*
name|ret
operator|=
name|qLoadPlugin1
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
operator|)
return|return
name|ret
return|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
literal|0
return|;
end_return
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
name|QPlatformInputContext
operator|*
name|ic
operator|=
literal|0
block|;
name|QString
name|icString
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_IM_MODULE"
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|icString
operator|==
name|QLatin1String
argument_list|(
literal|"none"
argument_list|)
condition|)
return|return
literal|0
return|;
name|ic
operator|=
name|create
argument_list|(
name|icString
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
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
end_if
begin_expr_stmt
operator|delete
name|ic
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|ic
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QStringList
name|k
init|=
name|keys
argument_list|()
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|k
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|k
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|icString
condition|)
continue|continue;
name|ic
operator|=
name|create
argument_list|(
name|k
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
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
expr_stmt|;
name|ic
operator|=
literal|0
expr_stmt|;
block|}
end_for
begin_return
return|return
literal|0
return|;
end_return
unit|}   QT_END_NAMESPACE
end_unit
