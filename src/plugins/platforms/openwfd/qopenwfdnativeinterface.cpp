begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenwfdnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdscreen.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdwindow.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdglcontext.h"
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/qguiglcontext_qpa.h>
end_include
begin_class
DECL|class|QOpenWFDResourceMap
class|class
name|QOpenWFDResourceMap
super|:
specifier|public
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QOpenWFDNativeInterface
operator|::
name|ResourceType
argument_list|>
block|{
public|public:
DECL|function|QOpenWFDResourceMap
name|QOpenWFDResourceMap
parameter_list|()
member_init_list|:
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QOpenWFDNativeInterface
operator|::
name|ResourceType
argument_list|>
argument_list|()
block|{
name|insert
argument_list|(
literal|"wfddevice"
argument_list|,
name|QOpenWFDNativeInterface
operator|::
name|WFDDevice
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"egldisplay"
argument_list|,
name|QOpenWFDNativeInterface
operator|::
name|EglDisplay
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"eglcontext"
argument_list|,
name|QOpenWFDNativeInterface
operator|::
name|EglContext
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"wfdport"
argument_list|,
name|QOpenWFDNativeInterface
operator|::
name|WFDPort
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"wfdpipeline"
argument_list|,
name|QOpenWFDNativeInterface
operator|::
name|WFDPipeline
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QOpenWFDResourceMap
argument_list|,
argument|qOpenWFDResourceMap
argument_list|)
end_macro
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QOpenWFDNativeInterface
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resourceString
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resourceString
operator|.
name|toLower
argument_list|()
decl_stmt|;
name|ResourceType
name|resource
init|=
name|qOpenWFDResourceMap
argument_list|()
operator|->
name|value
argument_list|(
name|lowerCaseResource
argument_list|)
decl_stmt|;
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resource
condition|)
block|{
case|case
name|EglContext
case|:
name|result
operator|=
name|eglContextForContext
argument_list|(
name|context
argument_list|)
expr_stmt|;
break|break;
default|default:
name|result
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QOpenWFDNativeInterface
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resourceString
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resourceString
operator|.
name|toLower
argument_list|()
decl_stmt|;
name|ResourceType
name|resource
init|=
name|qOpenWFDResourceMap
argument_list|()
operator|->
name|value
argument_list|(
name|lowerCaseResource
argument_list|)
decl_stmt|;
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resource
condition|)
block|{
comment|//What should we do for int wfd handles? This is clearly not the solution
case|case
name|WFDDevice
case|:
name|result
operator|=
operator|(
name|void
operator|*
operator|)
name|wfdDeviceForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|WFDPort
case|:
name|result
operator|=
operator|(
name|void
operator|*
operator|)
name|wfdPortForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|WFDPipeline
case|:
name|result
operator|=
operator|(
name|void
operator|*
operator|)
name|wfdPipelineForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|EglDisplay
case|:
name|result
operator|=
name|eglDisplayForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
default|default:
name|result
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|wfdDeviceForWindow
name|WFDHandle
name|QOpenWFDNativeInterface
operator|::
name|wfdDeviceForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QOpenWFDWindow
modifier|*
name|openWFDwindow
init|=
cast|static_cast
argument_list|<
name|QOpenWFDWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|openWFDwindow
operator|->
name|port
argument_list|()
operator|->
name|device
argument_list|()
operator|->
name|handle
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|wfdPortForWindow
name|WFDHandle
name|QOpenWFDNativeInterface
operator|::
name|wfdPortForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QOpenWFDWindow
modifier|*
name|openWFDwindow
init|=
cast|static_cast
argument_list|<
name|QOpenWFDWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|openWFDwindow
operator|->
name|port
argument_list|()
operator|->
name|handle
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|wfdPipelineForWindow
name|WFDHandle
name|QOpenWFDNativeInterface
operator|::
name|wfdPipelineForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QOpenWFDWindow
modifier|*
name|openWFDwindow
init|=
cast|static_cast
argument_list|<
name|QOpenWFDWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|openWFDwindow
operator|->
name|port
argument_list|()
operator|->
name|pipeline
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|eglDisplayForWindow
name|void
modifier|*
name|QOpenWFDNativeInterface
operator|::
name|eglDisplayForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QOpenWFDWindow
modifier|*
name|openWFDwindow
init|=
cast|static_cast
argument_list|<
name|QOpenWFDWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|openWFDwindow
operator|->
name|port
argument_list|()
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|eglContextForContext
name|void
modifier|*
name|QOpenWFDNativeInterface
operator|::
name|eglContextForContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|QOpenWFDGLContext
modifier|*
name|openWFDContext
init|=
cast|static_cast
argument_list|<
name|QOpenWFDGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|openWFDContext
operator|->
name|eglContext
argument_list|()
return|;
block|}
end_function
end_unit
