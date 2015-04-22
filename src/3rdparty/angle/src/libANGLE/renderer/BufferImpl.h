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
name|LIBANGLE_RENDERER_BUFFERIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_BUFFERIMPL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_BUFFERIMPL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Buffer.h"
end_include
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|BufferImpl
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
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
block|;
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
block|;
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
block|;
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
block|;
name|virtual
name|gl
operator|::
name|Error
name|unmap
argument_list|()
operator|=
literal|0
block|;
comment|// This method may not have a corresponding GL-backed function. It is necessary
comment|// for validation, for certain indexed draw calls.
name|virtual
name|gl
operator|::
name|Error
name|getData
argument_list|(
specifier|const
name|uint8_t
operator|*
operator|*
name|outData
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_BUFFERIMPL_H_
end_comment
end_unit
