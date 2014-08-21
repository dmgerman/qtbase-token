begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenwfdport.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdportmode.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_constructor
DECL|function|QOpenWFDPort
name|QOpenWFDPort
operator|::
name|QOpenWFDPort
parameter_list|(
name|QOpenWFDDevice
modifier|*
name|device
parameter_list|,
name|WFDint
name|portEnumeration
parameter_list|)
member_init_list|:
name|mDevice
argument_list|(
name|device
argument_list|)
member_init_list|,
name|mPortId
argument_list|(
name|portEnumeration
argument_list|)
member_init_list|,
name|mAttached
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mPipelineId
argument_list|(
name|WFD_INVALID_PIPELINE_ID
argument_list|)
member_init_list|,
name|mPipeline
argument_list|(
name|WFD_INVALID_HANDLE
argument_list|)
block|{
name|mPort
operator|=
name|wfdCreatePort
argument_list|(
name|device
operator|->
name|handle
argument_list|()
argument_list|,
name|portEnumeration
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|WFDint
name|isPortAttached
init|=
name|wfdGetPortAttribi
argument_list|(
name|device
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|WFD_PORT_ATTACHED
argument_list|)
decl_stmt|;
if|if
condition|(
name|isPortAttached
condition|)
block|{
name|attach
argument_list|()
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QOpenWFDPort
name|QOpenWFDPort
operator|::
name|~
name|QOpenWFDPort
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
name|wfdDestroyPort
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|attach
name|void
name|QOpenWFDPort
operator|::
name|attach
parameter_list|()
block|{
if|if
condition|(
name|mAttached
condition|)
block|{
return|return;
block|}
comment|//just forcing port to be on
name|wfdSetPortAttribi
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|WFD_PORT_POWER_MODE
argument_list|,
name|WFD_POWER_MODE_ON
argument_list|)
expr_stmt|;
name|int
name|numberOfPortModes
init|=
name|wfdGetPortModes
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|WFDPortMode
name|portModes
index|[
name|numberOfPortModes
index|]
decl_stmt|;
name|int
name|actualNumberOfPortModes
init|=
name|wfdGetPortModes
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|portModes
argument_list|,
name|numberOfPortModes
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|actualNumberOfPortModes
operator|==
name|numberOfPortModes
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|actualNumberOfPortModes
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"didn't find any available port modes"
expr_stmt|;
return|return;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actualNumberOfPortModes
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|portModes
index|[
name|i
index|]
operator|!=
name|WFD_INVALID_HANDLE
condition|)
block|{
name|mPortModes
operator|.
name|append
argument_list|(
name|QOpenWFDPortMode
argument_list|(
name|this
argument_list|,
name|portModes
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"PortModeAdded:"
operator|<<
name|mPortModes
operator|.
name|at
argument_list|(
name|mPortModes
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|mPixelSize
operator|=
name|setNativeResolutionMode
argument_list|()
expr_stmt|;
if|if
condition|(
name|mPixelSize
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Could not set native resolution mode in QOpenWFPort"
expr_stmt|;
block|}
name|WFDfloat
name|physicalWFDSize
index|[
literal|2
index|]
decl_stmt|;
name|wfdGetPortAttribfv
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|WFD_PORT_PHYSICAL_SIZE
argument_list|,
literal|2
argument_list|,
name|physicalWFDSize
argument_list|)
expr_stmt|;
name|mPhysicalSize
operator|=
name|QSizeF
argument_list|(
name|physicalWFDSize
index|[
literal|0
index|]
argument_list|,
name|physicalWFDSize
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|WFDint
name|numAvailablePipelines
init|=
name|wfdGetPortAttribi
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|WFD_PORT_PIPELINE_ID_COUNT
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|numAvailablePipelines
condition|)
block|{
name|qFatal
argument_list|(
literal|"Not possible to make screen that is not possible to create WFPort with no pipline"
argument_list|)
expr_stmt|;
block|}
name|WFDint
name|pipeIds
index|[
name|numAvailablePipelines
index|]
decl_stmt|;
name|wfdGetPortAttribiv
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|WFD_PORT_BINDABLE_PIPELINE_IDS
argument_list|,
name|numAvailablePipelines
argument_list|,
name|pipeIds
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numAvailablePipelines
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|pipeIds
index|[
name|i
index|]
operator|!=
name|WFD_INVALID_PIPELINE_ID
operator|&&
operator|!
name|mDevice
operator|->
name|isPipelineUsed
argument_list|(
name|pipeIds
index|[
name|i
index|]
argument_list|)
condition|)
block|{
name|mPipelineId
operator|=
name|pipeIds
index|[
name|i
index|]
expr_stmt|;
name|mDevice
operator|->
name|addToUsedPipelineSet
argument_list|(
name|mPipelineId
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|mPipeline
operator|=
name|wfdCreatePipeline
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPipelineId
argument_list|,
name|WFD_NONE
argument_list|)
expr_stmt|;
if|if
condition|(
name|mPipeline
operator|==
name|WFD_INVALID_HANDLE
condition|)
block|{
name|qFatal
argument_list|(
literal|"Failed to create pipeline for port %p"
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
if|if
condition|(
name|mPipeline
operator|==
name|WFD_INVALID_HANDLE
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to create pipeline and can't bind it to port"
argument_list|)
expr_stmt|;
block|}
name|WFDint
name|geomerty
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
name|mPixelSize
operator|.
name|width
argument_list|()
block|,
name|mPixelSize
operator|.
name|height
argument_list|()
block|}
decl_stmt|;
name|wfdSetPipelineAttribiv
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPipeline
argument_list|,
name|WFD_PIPELINE_SOURCE_RECTANGLE
argument_list|,
literal|4
argument_list|,
name|geomerty
argument_list|)
expr_stmt|;
name|wfdSetPipelineAttribiv
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPipeline
argument_list|,
name|WFD_PIPELINE_DESTINATION_RECTANGLE
argument_list|,
literal|4
argument_list|,
name|geomerty
argument_list|)
expr_stmt|;
name|wfdBindPipelineToPort
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|mPipeline
argument_list|)
expr_stmt|;
name|mScreen
operator|=
operator|new
name|QOpenWFDScreen
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mDevice
operator|->
name|integration
argument_list|()
operator|->
name|addScreen
argument_list|(
name|mScreen
argument_list|)
expr_stmt|;
name|mAttached
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|detach
name|void
name|QOpenWFDPort
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mAttached
condition|)
return|return;
name|mAttached
operator|=
literal|false
expr_stmt|;
name|mOn
operator|=
literal|false
expr_stmt|;
operator|delete
name|mScreen
expr_stmt|;
name|wfdDestroyPipeline
argument_list|(
name|mDevice
operator|->
name|handle
argument_list|()
argument_list|,
name|mPipeline
argument_list|)
expr_stmt|;
name|mPipelineId
operator|=
name|WFD_INVALID_PIPELINE_ID
expr_stmt|;
name|mPipeline
operator|=
name|WFD_INVALID_HANDLE
expr_stmt|;
block|}
end_function
begin_function
DECL|function|attached
name|bool
name|QOpenWFDPort
operator|::
name|attached
parameter_list|()
specifier|const
block|{
return|return
name|mAttached
return|;
block|}
end_function
begin_function
DECL|function|setNativeResolutionMode
name|QSize
name|QOpenWFDPort
operator|::
name|setNativeResolutionMode
parameter_list|()
block|{
name|WFDint
name|nativePixelSize
index|[
literal|2
index|]
decl_stmt|;
name|wfdGetPortAttribiv
argument_list|(
name|device
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|WFD_PORT_NATIVE_RESOLUTION
argument_list|,
literal|2
argument_list|,
name|nativePixelSize
argument_list|)
expr_stmt|;
name|QSize
name|nativeSize
argument_list|(
name|nativePixelSize
index|[
literal|0
index|]
argument_list|,
name|nativePixelSize
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mPortModes
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|QOpenWFDPortMode
modifier|&
name|mode
init|=
name|mPortModes
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|nativeSize
operator|==
name|mode
operator|.
name|size
argument_list|()
condition|)
block|{
name|wfdSetPortMode
argument_list|(
name|device
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|,
name|mPort
argument_list|,
name|mode
operator|.
name|handle
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|nativeSize
return|;
block|}
block|}
return|return
name|QSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|pixelSize
name|QSize
name|QOpenWFDPort
operator|::
name|pixelSize
parameter_list|()
specifier|const
block|{
return|return
name|mPixelSize
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSizeF
name|QOpenWFDPort
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
name|mPhysicalSize
return|;
block|}
end_function
begin_function
DECL|function|device
name|QOpenWFDDevice
modifier|*
name|QOpenWFDPort
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|mDevice
return|;
block|}
end_function
begin_function
DECL|function|handle
name|WFDPort
name|QOpenWFDPort
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
name|mPort
return|;
block|}
end_function
begin_function
DECL|function|portId
name|WFDint
name|QOpenWFDPort
operator|::
name|portId
parameter_list|()
specifier|const
block|{
return|return
name|mPortId
return|;
block|}
end_function
begin_function
DECL|function|pipeline
name|WFDPipeline
name|QOpenWFDPort
operator|::
name|pipeline
parameter_list|()
specifier|const
block|{
return|return
name|mPipeline
return|;
block|}
end_function
begin_function
DECL|function|screen
name|QOpenWFDScreen
modifier|*
name|QOpenWFDPort
operator|::
name|screen
parameter_list|()
specifier|const
block|{
return|return
name|mScreen
return|;
block|}
end_function
end_unit
