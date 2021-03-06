begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Device.cpp: Implements the egl::Device class, representing the abstract
end_comment
begin_comment
comment|// device. Implements EGLDevice.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/Device.h"
end_include
begin_include
include|#
directive|include
file|<iterator>
end_include
begin_include
include|#
directive|include
file|<platform/Platform.h>
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/DeviceImpl.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_ENABLE_D3D11
argument_list|)
end_if
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/DeviceD3D.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_namespace
DECL|namespace|egl
namespace|namespace
name|egl
block|{
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|GenerateExtensionsString
specifier|static
name|std
operator|::
name|string
name|GenerateExtensionsString
parameter_list|(
specifier|const
name|T
modifier|&
name|extensions
parameter_list|)
block|{
name|std
operator|::
name|vector
argument_list|<
name|std
operator|::
name|string
argument_list|>
name|extensionsVector
init|=
name|extensions
operator|.
name|getStrings
argument_list|()
decl_stmt|;
name|std
operator|::
name|ostringstream
name|stream
decl_stmt|;
name|std
operator|::
name|copy
argument_list|(
name|extensionsVector
operator|.
name|begin
argument_list|()
argument_list|,
name|extensionsVector
operator|.
name|end
argument_list|()
argument_list|,
name|std
operator|::
name|ostream_iterator
argument_list|<
name|std
operator|::
name|string
argument_list|>
argument_list|(
name|stream
argument_list|,
literal|" "
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|stream
operator|.
name|str
argument_list|()
return|;
block|}
DECL|typedef|DeviceSet
typedef|typedef
name|std
operator|::
name|set
argument_list|<
name|egl
operator|::
name|Device
operator|*
argument_list|>
name|DeviceSet
typedef|;
DECL|function|GetDeviceSet
specifier|static
name|DeviceSet
modifier|*
name|GetDeviceSet
parameter_list|()
block|{
specifier|static
name|DeviceSet
name|devices
decl_stmt|;
return|return
operator|&
name|devices
return|;
block|}
comment|// Static factory methods
DECL|function|CreateDevice
name|egl
operator|::
name|Error
name|Device
operator|::
name|CreateDevice
parameter_list|(
name|void
modifier|*
name|devicePointer
parameter_list|,
name|EGLint
name|deviceType
parameter_list|,
name|Device
modifier|*
modifier|*
name|outDevice
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_ENABLE_D3D11
argument_list|)
if|if
condition|(
name|deviceType
operator|==
name|EGL_D3D11_DEVICE_ANGLE
condition|)
block|{
name|rx
operator|::
name|DeviceD3D
modifier|*
name|deviceD3D
init|=
operator|new
name|rx
operator|::
name|DeviceD3D
argument_list|()
decl_stmt|;
name|egl
operator|::
name|Error
name|error
init|=
name|deviceD3D
operator|->
name|initialize
argument_list|(
name|devicePointer
argument_list|,
name|deviceType
argument_list|,
name|EGL_TRUE
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
operator|*
name|outDevice
operator|=
literal|nullptr
expr_stmt|;
return|return
name|error
return|;
block|}
operator|*
name|outDevice
operator|=
operator|new
name|Device
argument_list|(
literal|nullptr
argument_list|,
name|deviceD3D
argument_list|)
expr_stmt|;
name|GetDeviceSet
argument_list|()
operator|->
name|insert
argument_list|(
operator|*
name|outDevice
argument_list|)
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// Note that creating an EGL device from inputted D3D9 parameters isn't currently supported
operator|*
name|outDevice
operator|=
literal|nullptr
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
return|;
block|}
DECL|function|CreateDevice
name|egl
operator|::
name|Error
name|Device
operator|::
name|CreateDevice
parameter_list|(
name|Display
modifier|*
name|owningDisplay
parameter_list|,
name|rx
operator|::
name|DeviceImpl
modifier|*
name|impl
parameter_list|,
name|Device
modifier|*
modifier|*
name|outDevice
parameter_list|)
block|{
operator|*
name|outDevice
operator|=
operator|new
name|Device
argument_list|(
name|owningDisplay
argument_list|,
name|impl
argument_list|)
expr_stmt|;
name|GetDeviceSet
argument_list|()
operator|->
name|insert
argument_list|(
operator|*
name|outDevice
argument_list|)
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
DECL|function|IsValidDevice
name|bool
name|Device
operator|::
name|IsValidDevice
parameter_list|(
name|Device
modifier|*
name|device
parameter_list|)
block|{
specifier|const
name|DeviceSet
modifier|*
name|deviceSet
init|=
name|GetDeviceSet
argument_list|()
decl_stmt|;
return|return
name|deviceSet
operator|->
name|find
argument_list|(
name|device
argument_list|)
operator|!=
name|deviceSet
operator|->
name|end
argument_list|()
return|;
block|}
DECL|function|Device
name|Device
operator|::
name|Device
parameter_list|(
name|Display
modifier|*
name|owningDisplay
parameter_list|,
name|rx
operator|::
name|DeviceImpl
modifier|*
name|impl
parameter_list|)
member_init_list|:
name|mOwningDisplay
argument_list|(
name|owningDisplay
argument_list|)
member_init_list|,
name|mImplementation
argument_list|(
name|impl
argument_list|)
block|{
name|initDeviceExtensions
argument_list|()
expr_stmt|;
block|}
DECL|function|~Device
name|Device
operator|::
name|~
name|Device
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|GetDeviceSet
argument_list|()
operator|->
name|find
argument_list|(
name|this
argument_list|)
operator|!=
name|GetDeviceSet
argument_list|()
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|GetDeviceSet
argument_list|()
operator|->
name|erase
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|mImplementation
operator|->
name|deviceExternallySourced
argument_list|()
condition|)
block|{
comment|// If the device isn't externally sourced then it is up to the renderer to delete the impl
name|SafeDelete
argument_list|(
name|mImplementation
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getDevice
name|Error
name|Device
operator|::
name|getDevice
parameter_list|(
name|EGLAttrib
modifier|*
name|value
parameter_list|)
block|{
name|void
modifier|*
name|nativeDevice
init|=
literal|nullptr
decl_stmt|;
name|egl
operator|::
name|Error
name|error
init|=
name|getImplementation
argument_list|()
operator|->
name|getDevice
argument_list|(
operator|&
name|nativeDevice
argument_list|)
decl_stmt|;
operator|*
name|value
operator|=
cast|reinterpret_cast
argument_list|<
name|EGLAttrib
argument_list|>
argument_list|(
name|nativeDevice
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
DECL|function|getType
name|EGLint
name|Device
operator|::
name|getType
parameter_list|()
block|{
return|return
name|getImplementation
argument_list|()
operator|->
name|getType
argument_list|()
return|;
block|}
DECL|function|initDeviceExtensions
name|void
name|Device
operator|::
name|initDeviceExtensions
parameter_list|()
block|{
name|mImplementation
operator|->
name|generateExtensions
argument_list|(
operator|&
name|mDeviceExtensions
argument_list|)
expr_stmt|;
name|mDeviceExtensionString
operator|=
name|GenerateExtensionsString
argument_list|(
name|mDeviceExtensions
argument_list|)
expr_stmt|;
block|}
DECL|function|getExtensions
specifier|const
name|DeviceExtensions
modifier|&
name|Device
operator|::
name|getExtensions
parameter_list|()
specifier|const
block|{
return|return
name|mDeviceExtensions
return|;
block|}
DECL|function|getExtensionString
specifier|const
name|std
operator|::
name|string
modifier|&
name|Device
operator|::
name|getExtensionString
parameter_list|()
specifier|const
block|{
return|return
name|mDeviceExtensionString
return|;
block|}
block|}
end_namespace
end_unit
