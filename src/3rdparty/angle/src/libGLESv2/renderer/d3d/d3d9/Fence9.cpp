begin_unit
begin_include
include|#
directive|include
file|"precompiled.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
comment|// Fence9.cpp: Defines the rx::Fence9 class.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/Fence9.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/main.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/renderer9_utils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/Renderer9.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|Fence9
name|Fence9
operator|::
name|Fence9
parameter_list|(
name|rx
operator|::
name|Renderer9
modifier|*
name|renderer
parameter_list|)
block|{
name|mRenderer
operator|=
name|renderer
expr_stmt|;
name|mQuery
operator|=
name|NULL
expr_stmt|;
block|}
DECL|function|~Fence9
name|Fence9
operator|::
name|~
name|Fence9
parameter_list|()
block|{
name|SafeRelease
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
block|}
DECL|function|isSet
name|bool
name|Fence9
operator|::
name|isSet
parameter_list|()
specifier|const
block|{
return|return
name|mQuery
operator|!=
name|NULL
return|;
block|}
DECL|function|set
name|void
name|Fence9
operator|::
name|set
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mQuery
condition|)
block|{
name|mQuery
operator|=
name|mRenderer
operator|->
name|allocateEventQuery
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|mQuery
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
return|;
block|}
block|}
name|HRESULT
name|result
init|=
name|mQuery
operator|->
name|Issue
argument_list|(
name|D3DISSUE_END
argument_list|)
decl_stmt|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|test
name|bool
name|Fence9
operator|::
name|test
parameter_list|(
name|bool
name|flushCommandBuffer
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
name|DWORD
name|getDataFlags
init|=
operator|(
name|flushCommandBuffer
condition|?
name|D3DGETDATA_FLUSH
else|:
literal|0
operator|)
decl_stmt|;
name|HRESULT
name|result
init|=
name|mQuery
operator|->
name|GetData
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|getDataFlags
argument_list|)
decl_stmt|;
if|if
condition|(
name|d3d9
operator|::
name|isDeviceLostError
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|mRenderer
operator|->
name|notifyDeviceLost
argument_list|()
expr_stmt|;
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|true
argument_list|)
return|;
block|}
name|ASSERT
argument_list|(
name|result
operator|==
name|S_OK
operator|||
name|result
operator|==
name|S_FALSE
argument_list|)
expr_stmt|;
return|return
operator|(
name|result
operator|==
name|S_OK
operator|)
return|;
block|}
DECL|function|hasError
name|bool
name|Fence9
operator|::
name|hasError
parameter_list|()
specifier|const
block|{
return|return
name|mRenderer
operator|->
name|isDeviceLost
argument_list|()
return|;
block|}
block|}
end_namespace
end_unit
