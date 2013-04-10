begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// RenderTarget.h: Defines an abstract wrapper class to manage IDirect3DSurface9
end_comment
begin_comment
comment|// and ID3D11View objects belonging to renderbuffers.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_RENDERTARGET_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERTARGET_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERTARGET_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderTarget
block|{
name|public
label|:
name|RenderTarget
argument_list|()
block|{
name|mWidth
operator|=
literal|0
expr_stmt|;
name|mHeight
operator|=
literal|0
expr_stmt|;
name|mInternalFormat
operator|=
name|GL_NONE
expr_stmt|;
name|mActualFormat
operator|=
name|GL_NONE
expr_stmt|;
name|mSamples
operator|=
literal|0
expr_stmt|;
block|}
name|virtual
operator|~
name|RenderTarget
argument_list|()
block|{}
expr_stmt|;
name|GLsizei
name|getWidth
parameter_list|()
block|{
return|return
name|mWidth
return|;
block|}
name|GLsizei
name|getHeight
parameter_list|()
block|{
return|return
name|mHeight
return|;
block|}
name|GLenum
name|getInternalFormat
parameter_list|()
block|{
return|return
name|mInternalFormat
return|;
block|}
name|GLenum
name|getActualFormat
parameter_list|()
block|{
return|return
name|mActualFormat
return|;
block|}
name|GLsizei
name|getSamples
parameter_list|()
block|{
return|return
name|mSamples
return|;
block|}
struct|struct
name|Desc
block|{
name|GLsizei
name|width
decl_stmt|;
name|GLsizei
name|height
decl_stmt|;
name|GLenum
name|format
decl_stmt|;
block|}
struct|;
name|protected
label|:
name|GLsizei
name|mWidth
decl_stmt|;
name|GLsizei
name|mHeight
decl_stmt|;
name|GLenum
name|mInternalFormat
decl_stmt|;
name|GLenum
name|mActualFormat
decl_stmt|;
name|GLsizei
name|mSamples
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RenderTarget
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERTARGET_H_
end_comment
end_unit
