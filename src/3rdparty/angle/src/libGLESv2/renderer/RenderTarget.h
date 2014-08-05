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
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
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
name|mDepth
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
argument_list|()
specifier|const
block|{
return|return
name|mWidth
return|;
block|}
name|GLsizei
name|getHeight
argument_list|()
specifier|const
block|{
return|return
name|mHeight
return|;
block|}
name|GLsizei
name|getDepth
argument_list|()
specifier|const
block|{
return|return
name|mDepth
return|;
block|}
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
block|{
return|return
name|mInternalFormat
return|;
block|}
name|GLenum
name|getActualFormat
argument_list|()
specifier|const
block|{
return|return
name|mActualFormat
return|;
block|}
name|GLsizei
name|getSamples
argument_list|()
specifier|const
block|{
return|return
name|mSamples
return|;
block|}
name|gl
operator|::
name|Extents
name|getExtents
argument_list|()
specifier|const
block|{
return|return
name|gl
operator|::
name|Extents
argument_list|(
name|mWidth
argument_list|,
name|mHeight
argument_list|,
name|mDepth
argument_list|)
return|;
block|}
name|virtual
name|void
name|invalidate
parameter_list|(
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
init|=
literal|0
function_decl|;
struct|struct
name|Desc
block|{
name|GLsizei
name|width
decl_stmt|;
name|GLsizei
name|height
decl_stmt|;
name|GLsizei
name|depth
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
name|GLsizei
name|mDepth
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
