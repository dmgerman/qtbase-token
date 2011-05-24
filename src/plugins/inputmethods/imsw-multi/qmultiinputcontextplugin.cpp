begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Implementation of QMultiInputContextPlugin class ** ** Copyright (C) 2004 immodule for Qt Project.  All rights reserved. ** ** This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own ** license. You may use this file under your Qt license. Following ** description is copied from their original file headers. Contact ** immodule-qt@freedesktop.org if any conditions of this licensing are ** not clear to you. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IM
end_ifndef
begin_include
include|#
directive|include
file|"qmultiinputcontext.h"
end_include
begin_include
include|#
directive|include
file|"qmultiinputcontextplugin.h"
end_include
begin_include
include|#
directive|include
file|<qinputcontextplugin.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QMultiInputContextPlugin
name|QMultiInputContextPlugin
operator|::
name|QMultiInputContextPlugin
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~QMultiInputContextPlugin
name|QMultiInputContextPlugin
operator|::
name|~
name|QMultiInputContextPlugin
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|keys
name|QStringList
name|QMultiInputContextPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
comment|// input method switcher should named with "imsw-" prefix to
comment|// prevent to be listed in ordinary input method list.
return|return
name|QStringList
argument_list|(
name|QLatin1String
argument_list|(
literal|"imsw-multi"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|create
name|QInputContext
modifier|*
name|QMultiInputContextPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
if|if
condition|(
name|key
operator|!=
name|QLatin1String
argument_list|(
literal|"imsw-multi"
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
operator|new
name|QMultiInputContext
return|;
block|}
end_function
begin_function
DECL|function|languages
name|QStringList
name|QMultiInputContextPlugin
operator|::
name|languages
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|displayName
name|QString
name|QMultiInputContextPlugin
operator|::
name|displayName
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
if|if
condition|(
name|key
operator|!=
name|QLatin1String
argument_list|(
literal|"imsw-multi"
argument_list|)
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|tr
argument_list|(
literal|"Multiple input method switcher"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|description
name|QString
name|QMultiInputContextPlugin
operator|::
name|description
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
if|if
condition|(
name|key
operator|!=
name|QLatin1String
argument_list|(
literal|"imsw-multi"
argument_list|)
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|tr
argument_list|(
literal|"Multiple input method switcher that uses the context menu of the text widgets"
argument_list|)
return|;
block|}
end_function
begin_macro
name|Q_EXPORT_STATIC_PLUGIN
argument_list|(
argument|QMultiInputContextPlugin
argument_list|)
end_macro
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|qimsw_multi
argument_list|,
argument|QMultiInputContextPlugin
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
