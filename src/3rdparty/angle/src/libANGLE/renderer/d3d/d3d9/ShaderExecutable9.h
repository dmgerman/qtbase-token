begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// ShaderExecutable9.h: Defines a D3D9-specific class to contain shader
end_comment
begin_comment
comment|// executable implementation details.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D9_SHADEREXECUTABLE9_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D9_SHADEREXECUTABLE9_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D9_SHADEREXECUTABLE9_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/ShaderExecutableD3D.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|ShaderExecutable9
range|:
name|public
name|ShaderExecutableD3D
block|{
name|public
operator|:
name|ShaderExecutable9
argument_list|(
argument|const void *function
argument_list|,
argument|size_t length
argument_list|,
argument|IDirect3DPixelShader9 *executable
argument_list|)
block|;
name|ShaderExecutable9
argument_list|(
argument|const void *function
argument_list|,
argument|size_t length
argument_list|,
argument|IDirect3DVertexShader9 *executable
argument_list|)
block|;
name|virtual
operator|~
name|ShaderExecutable9
argument_list|()
block|;
name|IDirect3DPixelShader9
operator|*
name|getPixelShader
argument_list|()
specifier|const
block|;
name|IDirect3DVertexShader9
operator|*
name|getVertexShader
argument_list|()
specifier|const
block|;
name|private
operator|:
name|IDirect3DPixelShader9
operator|*
name|mPixelExecutable
block|;
name|IDirect3DVertexShader9
operator|*
name|mVertexExecutable
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D9_SHADEREXECUTABLE9_H_
end_comment
end_unit
