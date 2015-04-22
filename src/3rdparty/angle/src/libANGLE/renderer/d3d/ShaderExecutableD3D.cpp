begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2015 The ANGLE Project Authors. All rights reserved.
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
comment|// ShaderExecutable.cpp: Implements a class to contain D3D shader executable
end_comment
begin_comment
comment|// implementation details.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/ShaderExecutableD3D.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|ShaderExecutableD3D
name|ShaderExecutableD3D
operator|::
name|ShaderExecutableD3D
parameter_list|(
specifier|const
name|void
modifier|*
name|function
parameter_list|,
name|size_t
name|length
parameter_list|)
member_init_list|:
name|mFunctionBuffer
argument_list|(
name|length
argument_list|)
block|{
name|memcpy
argument_list|(
name|mFunctionBuffer
operator|.
name|data
argument_list|()
argument_list|,
name|function
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
DECL|function|~ShaderExecutableD3D
name|ShaderExecutableD3D
operator|::
name|~
name|ShaderExecutableD3D
parameter_list|()
block|{ }
DECL|function|getFunction
specifier|const
name|uint8_t
modifier|*
name|ShaderExecutableD3D
operator|::
name|getFunction
parameter_list|()
specifier|const
block|{
return|return
name|mFunctionBuffer
operator|.
name|data
argument_list|()
return|;
block|}
DECL|function|getLength
name|size_t
name|ShaderExecutableD3D
operator|::
name|getLength
parameter_list|()
specifier|const
block|{
return|return
name|mFunctionBuffer
operator|.
name|size
argument_list|()
return|;
block|}
DECL|function|getDebugInfo
specifier|const
name|std
operator|::
name|string
modifier|&
name|ShaderExecutableD3D
operator|::
name|getDebugInfo
parameter_list|()
specifier|const
block|{
return|return
name|mDebugInfo
return|;
block|}
DECL|function|appendDebugInfo
name|void
name|ShaderExecutableD3D
operator|::
name|appendDebugInfo
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|info
parameter_list|)
block|{
name|mDebugInfo
operator|+=
name|info
expr_stmt|;
block|}
DECL|function|UniformStorageD3D
name|UniformStorageD3D
operator|::
name|UniformStorageD3D
parameter_list|(
name|size_t
name|initialSize
parameter_list|)
member_init_list|:
name|mSize
argument_list|(
name|initialSize
argument_list|)
block|{ }
DECL|function|~UniformStorageD3D
name|UniformStorageD3D
operator|::
name|~
name|UniformStorageD3D
parameter_list|()
block|{ }
DECL|function|size
name|size_t
name|UniformStorageD3D
operator|::
name|size
parameter_list|()
specifier|const
block|{
return|return
name|mSize
return|;
block|}
block|}
end_namespace
end_unit
