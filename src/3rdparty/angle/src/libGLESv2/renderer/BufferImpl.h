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
comment|// BufferImpl.h: Defines the abstract rx::BufferImpl class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_BUFFERIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_BUFFERIMPL_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_BUFFERIMPL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Buffer.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|BufferImpl
block|{
name|public
label|:
name|virtual
operator|~
name|BufferImpl
argument_list|()
block|{ }
name|virtual
name|gl
operator|::
name|Error
name|setData
argument_list|(
argument|const void* data
argument_list|,
argument|size_t size
argument_list|,
argument|GLenum usage
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
modifier|*
name|getData
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|gl
operator|::
name|Error
name|setSubData
argument_list|(
argument|const void* data
argument_list|,
argument|size_t size
argument_list|,
argument|size_t offset
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|copySubData
argument_list|(
argument|BufferImpl* source
argument_list|,
argument|GLintptr sourceOffset
argument_list|,
argument|GLintptr destOffset
argument_list|,
argument|GLsizeiptr size
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|map
argument_list|(
argument|size_t offset
argument_list|,
argument|size_t length
argument_list|,
argument|GLbitfield access
argument_list|,
argument|GLvoid **mapPtr
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|unmap
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|markTransformFeedbackUsage
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_BUFFERIMPL_H_
end_comment
end_unit
