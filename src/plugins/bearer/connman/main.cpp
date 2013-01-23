begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qconnmanengine.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork/private/qbearerplugin_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QConnmanEnginePlugin
class|class
name|QConnmanEnginePlugin
super|:
specifier|public
name|QBearerEnginePlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QBearerEngineFactoryInterface"
name|FILE
literal|"connman.json"
argument_list|)
decl|public
range|:
name|QConnmanEnginePlugin
argument_list|()
decl_stmt|;
name|~
name|QConnmanEnginePlugin
parameter_list|()
destructor_decl|;
name|QBearerEngine
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QConnmanEnginePlugin
name|QConnmanEnginePlugin
operator|::
name|QConnmanEnginePlugin
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QConnmanEnginePlugin
name|QConnmanEnginePlugin
operator|::
name|~
name|QConnmanEnginePlugin
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|create
name|QBearerEngine
modifier|*
name|QConnmanEnginePlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|key
operator|==
name|QLatin1String
argument_list|(
literal|"connman"
argument_list|)
condition|)
block|{
name|QConnmanEngine
modifier|*
name|engine
init|=
operator|new
name|QConnmanEngine
decl_stmt|;
if|if
condition|(
name|engine
operator|->
name|connmanAvailable
argument_list|()
condition|)
return|return
name|engine
return|;
else|else
operator|delete
name|engine
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
end_unit
