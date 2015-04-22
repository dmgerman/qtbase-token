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
comment|// FenceSyncImpl.h: Defines the rx::FenceSyncImpl class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_FENCESYNCIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_FENCESYNCIMPL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_FENCESYNCIMPL_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|FenceSyncImpl
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|FenceSyncImpl
argument_list|()
block|{ }
block|;
name|virtual
operator|~
name|FenceSyncImpl
argument_list|()
block|{ }
block|;
name|virtual
name|gl
operator|::
name|Error
name|set
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|clientWait
argument_list|(
argument|GLbitfield flags
argument_list|,
argument|GLuint64 timeout
argument_list|,
argument|GLenum *outResult
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|serverWait
argument_list|(
argument|GLbitfield flags
argument_list|,
argument|GLuint64 timeout
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|getStatus
argument_list|(
name|GLint
operator|*
name|outResult
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
comment|// LIBANGLE_RENDERER_FENCESYNCIMPL_H_
end_comment
end_unit
