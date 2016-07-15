begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// Image.h: Implements the rx::Image class, an abstract base class for the
end_comment
begin_comment
comment|// renderer-specific classes which will define the interface to the underlying
end_comment
begin_comment
comment|// surfaces or resources.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/ImageD3D.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|ImageD3D
name|ImageD3D
operator|::
name|ImageD3D
parameter_list|()
block|{ }
DECL|function|makeImageD3D
name|ImageD3D
modifier|*
name|ImageD3D
operator|::
name|makeImageD3D
parameter_list|(
name|Image
modifier|*
name|img
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|HAS_DYNAMIC_TYPE
argument_list|(
name|ImageD3D
operator|*
argument_list|,
name|img
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|ImageD3D
operator|*
argument_list|>
argument_list|(
name|img
argument_list|)
return|;
block|}
block|}
end_namespace
end_unit
