begin_unit
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
comment|// Sampler.h : Defines the Sampler class, which represents a GLES 3
end_comment
begin_comment
comment|// sampler object. Sampler objects store some state needed to sample textures.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_SAMPLER_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_SAMPLER_H_
define|#
directive|define
name|LIBGLESV2_SAMPLER_H_
end_define
begin_include
include|#
directive|include
file|"common/RefCountObject.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
struct_decl|struct
name|SamplerState
struct_decl|;
name|class
name|Sampler
range|:
name|public
name|RefCountObject
block|{
name|public
operator|:
name|Sampler
argument_list|(
argument|GLuint id
argument_list|)
block|;
name|void
name|setMinFilter
argument_list|(
argument|GLenum minFilter
argument_list|)
block|{
name|mMinFilter
operator|=
name|minFilter
block|; }
name|void
name|setMagFilter
argument_list|(
argument|GLenum magFilter
argument_list|)
block|{
name|mMagFilter
operator|=
name|magFilter
block|; }
name|void
name|setWrapS
argument_list|(
argument|GLenum wrapS
argument_list|)
block|{
name|mWrapS
operator|=
name|wrapS
block|; }
name|void
name|setWrapT
argument_list|(
argument|GLenum wrapT
argument_list|)
block|{
name|mWrapT
operator|=
name|wrapT
block|; }
name|void
name|setWrapR
argument_list|(
argument|GLenum wrapR
argument_list|)
block|{
name|mWrapR
operator|=
name|wrapR
block|; }
name|void
name|setMinLod
argument_list|(
argument|GLfloat minLod
argument_list|)
block|{
name|mMinLod
operator|=
name|minLod
block|; }
name|void
name|setMaxLod
argument_list|(
argument|GLfloat maxLod
argument_list|)
block|{
name|mMaxLod
operator|=
name|maxLod
block|; }
name|void
name|setComparisonMode
argument_list|(
argument|GLenum comparisonMode
argument_list|)
block|{
name|mComparisonMode
operator|=
name|comparisonMode
block|; }
name|void
name|setComparisonFunc
argument_list|(
argument|GLenum comparisonFunc
argument_list|)
block|{
name|mComparisonFunc
operator|=
name|comparisonFunc
block|; }
name|GLenum
name|getMinFilter
argument_list|()
specifier|const
block|{
return|return
name|mMinFilter
return|;
block|}
name|GLenum
name|getMagFilter
argument_list|()
specifier|const
block|{
return|return
name|mMagFilter
return|;
block|}
name|GLenum
name|getWrapS
argument_list|()
specifier|const
block|{
return|return
name|mWrapS
return|;
block|}
name|GLenum
name|getWrapT
argument_list|()
specifier|const
block|{
return|return
name|mWrapT
return|;
block|}
name|GLenum
name|getWrapR
argument_list|()
specifier|const
block|{
return|return
name|mWrapR
return|;
block|}
name|GLfloat
name|getMinLod
argument_list|()
specifier|const
block|{
return|return
name|mMinLod
return|;
block|}
name|GLfloat
name|getMaxLod
argument_list|()
specifier|const
block|{
return|return
name|mMaxLod
return|;
block|}
name|GLenum
name|getComparisonMode
argument_list|()
specifier|const
block|{
return|return
name|mComparisonMode
return|;
block|}
name|GLenum
name|getComparisonFunc
argument_list|()
specifier|const
block|{
return|return
name|mComparisonFunc
return|;
block|}
name|void
name|getState
argument_list|(
argument|SamplerState *samplerState
argument_list|)
specifier|const
block|;
name|private
operator|:
name|GLenum
name|mMinFilter
block|;
name|GLenum
name|mMagFilter
block|;
name|GLenum
name|mWrapS
block|;
name|GLenum
name|mWrapT
block|;
name|GLenum
name|mWrapR
block|;
name|GLfloat
name|mMinLod
block|;
name|GLfloat
name|mMaxLod
block|;
name|GLenum
name|mComparisonMode
block|;
name|GLenum
name|mComparisonFunc
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_SAMPLER_H_
end_comment
end_unit
