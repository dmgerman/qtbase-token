begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// angletypes.h: Workarounds for driver bugs and other issues.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_WORKAROUNDS_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_WORKAROUNDS_H_
define|#
directive|define
name|LIBANGLE_RENDERER_WORKAROUNDS_H_
end_define
begin_comment
comment|// TODO(jmadill,zmo,geofflang): make a workarounds library that can operate
end_comment
begin_comment
comment|// independent of ANGLE's renderer. Workarounds should also be accessible
end_comment
begin_comment
comment|// outside of the Renderer.
end_comment
begin_decl_stmt
name|namespace
name|rx
block|{
name|struct
name|D3DCompilerWorkarounds
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|D3DCompilerWorkarounds
argument_list|()
operator|:
name|skipOptimization
argument_list|(
name|false
argument_list|)
block|,
name|useMaxOptimization
argument_list|(
name|false
argument_list|)
block|,
name|enableIEEEStrictness
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|reset
argument_list|()
block|{
name|skipOptimization
operator|=
name|false
block|;
name|useMaxOptimization
operator|=
name|false
block|;
name|enableIEEEStrictness
operator|=
name|false
block|;     }
name|bool
name|skipOptimization
block|;
name|bool
name|useMaxOptimization
block|;
comment|// IEEE strictness needs to be enabled for NANs to work.
name|bool
name|enableIEEEStrictness
block|; }
decl_stmt|;
struct|struct
name|Workarounds
block|{
name|Workarounds
argument_list|()
operator|:
name|mrtPerfWorkaround
argument_list|(
name|false
argument_list|)
operator|,
name|setDataFasterThanImageUpload
argument_list|(
name|false
argument_list|)
operator|,
name|zeroMaxLodWorkaround
argument_list|(
name|false
argument_list|)
operator|,
name|useInstancedPointSpriteEmulation
argument_list|(
argument|false
argument_list|)
block|{}
comment|// On some systems, having extra rendertargets than necessary slows down the shader.
comment|// We can fix this by optimizing those out of the shader. At the same time, we can
comment|// work around a bug on some nVidia drivers that they ignore "null" render targets
comment|// in D3D11, by compacting the active color attachments list to omit null entries.
name|bool
name|mrtPerfWorkaround
expr_stmt|;
name|bool
name|setDataFasterThanImageUpload
decl_stmt|;
comment|// Some renderers can't disable mipmaps on a mipmapped texture (i.e. solely sample from level zero, and ignore the other levels).
comment|// D3D11 Feature Level 10+ does this by setting MaxLOD to 0.0f in the Sampler state. D3D9 sets D3DSAMP_MIPFILTER to D3DTEXF_NONE.
comment|// There is no equivalent to this in D3D11 Feature Level 9_3.
comment|// This causes problems when (for example) an application creates a mipmapped texture2D, but sets GL_TEXTURE_MIN_FILTER to GL_NEAREST (i.e disables mipmaps).
comment|// To work around this, D3D11 FL9_3 has to create two copies of the texture. The textures' level zeros are identical, but only one texture has mips.
name|bool
name|zeroMaxLodWorkaround
decl_stmt|;
comment|// Some renderers do not support Geometry Shaders so the Geometry Shader-based
comment|// PointSprite emulation will not work.
comment|// To work around this, D3D11 FL9_3 has to use a different pointsprite
comment|// emulation that is implemented using instanced quads.
name|bool
name|useInstancedPointSpriteEmulation
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_WORKAROUNDS_H_
end_comment
end_unit
