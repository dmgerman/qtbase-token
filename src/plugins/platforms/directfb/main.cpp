begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformintegrationplugin.h>
end_include
begin_include
include|#
directive|include
file|"qdirectfbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfb_egl.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|DIRECTFB_GL_EGL
end_ifdef
begin_define
DECL|macro|QT_EGL_BACKEND_STRING
define|#
directive|define
name|QT_EGL_BACKEND_STRING
parameter_list|(
name|list
parameter_list|)
value|list<< "directfbegl";
end_define
begin_define
DECL|macro|QT_EGL_BACKEND_CREATE
define|#
directive|define
name|QT_EGL_BACKEND_CREATE
parameter_list|(
name|list
parameter_list|,
name|out
parameter_list|)
define|\
value|if (list.toLower() == "directfbegl") \         out = new QDirectFbIntegrationEGL;
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|QT_EGL_BACKEND_STRING
parameter_list|(
name|list
parameter_list|)
end_define
begin_define
define|#
directive|define
name|QT_EGL_BACKEND_CREATE
parameter_list|(
name|system
parameter_list|,
name|out
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|QDirectFbIntegrationPlugin
class|class
name|QDirectFbIntegrationPlugin
super|:
specifier|public
name|QPlatformIntegrationPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QPA.QPlatformIntegrationFactoryInterface.5.2"
name|FILE
literal|"directfb.json"
argument_list|)
decl|public
range|:
name|QPlatformIntegration
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QStringList
operator|&
argument_list|)
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|create
name|QPlatformIntegration
modifier|*
name|QDirectFbIntegrationPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|system
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|paramList
argument_list|)
expr_stmt|;
name|QDirectFbIntegration
modifier|*
name|integration
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|system
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"directfb"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
name|integration
operator|=
operator|new
name|QDirectFbIntegration
expr_stmt|;
name|QT_EGL_BACKEND_CREATE
argument_list|(
argument|system
argument_list|,
argument|integration
argument_list|)
if|if
condition|(
operator|!
name|integration
condition|)
return|return
literal|0
return|;
name|integration
operator|->
name|connectToDirectFb
argument_list|()
expr_stmt|;
return|return
name|integration
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
