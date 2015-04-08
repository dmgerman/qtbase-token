begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// TransformFeedbackD3D.cpp is a no-op implementation for both the D3D9 and D3D11 renderers.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/TransformFeedbackD3D.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|TransformFeedbackD3D
name|TransformFeedbackD3D
operator|::
name|TransformFeedbackD3D
parameter_list|()
block|{ }
DECL|function|~TransformFeedbackD3D
name|TransformFeedbackD3D
operator|::
name|~
name|TransformFeedbackD3D
parameter_list|()
block|{ }
DECL|function|begin
name|void
name|TransformFeedbackD3D
operator|::
name|begin
parameter_list|(
name|GLenum
name|primitiveMode
parameter_list|)
block|{ }
DECL|function|end
name|void
name|TransformFeedbackD3D
operator|::
name|end
parameter_list|()
block|{ }
DECL|function|pause
name|void
name|TransformFeedbackD3D
operator|::
name|pause
parameter_list|()
block|{ }
DECL|function|resume
name|void
name|TransformFeedbackD3D
operator|::
name|resume
parameter_list|()
block|{ }
block|}
end_namespace
end_unit
