begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/qgenericplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qevdevtabletmanager_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QEvdevTabletPlugin
class|class
name|QEvdevTabletPlugin
super|:
specifier|public
name|QGenericPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
name|QGenericPluginFactoryInterface_iid
name|FILE
literal|"evdevtablet.json"
argument_list|)
decl|public
range|:
name|QEvdevTabletPlugin
argument_list|()
decl_stmt|;
DECL|member|Q_DECL_OVERRIDE
name|QObject
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QEvdevTabletPlugin
name|QEvdevTabletPlugin
operator|::
name|QEvdevTabletPlugin
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|create
name|QObject
modifier|*
name|QEvdevTabletPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|spec
parameter_list|)
block|{
if|if
condition|(
operator|!
name|key
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"EvdevTablet"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
operator|new
name|QEvdevTabletManager
argument_list|(
name|key
argument_list|,
name|spec
argument_list|)
return|;
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
end_unit
