begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|THEPLUGIN_H
end_ifndef
begin_define
DECL|macro|THEPLUGIN_H
define|#
directive|define
name|THEPLUGIN_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QtPlugin>
end_include
begin_include
include|#
directive|include
file|"plugininterface.h"
end_include
begin_decl_stmt
DECL|variable|QObject
name|class
name|ThePlugin
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|PluginInterface
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.autotests.plugininterface"
name|FILE
literal|"../empty.json"
argument_list|)
name|Q_INTERFACES
argument_list|(
name|PluginInterface
argument_list|)
name|public
range|:
name|virtual
name|QString
name|pluginName
argument_list|()
specifier|const
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// THEPLUGIN_H
end_comment
end_unit
