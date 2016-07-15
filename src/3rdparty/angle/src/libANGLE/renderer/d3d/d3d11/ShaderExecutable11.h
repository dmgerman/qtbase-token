begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// ShaderExecutable11.h: Defines a D3D11-specific class to contain shader
end_comment
begin_comment
comment|// executable implementation details.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D11_SHADEREXECUTABLE11_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_SHADEREXECUTABLE11_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_SHADEREXECUTABLE11_H_
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
name|Renderer11
decl_stmt|;
name|class
name|UniformStorage11
decl_stmt|;
name|class
name|ShaderExecutable11
range|:
name|public
name|ShaderExecutableD3D
block|{
name|public
operator|:
name|ShaderExecutable11
argument_list|(
argument|const void *function
argument_list|,
argument|size_t length
argument_list|,
argument|ID3D11PixelShader *executable
argument_list|)
block|;
name|ShaderExecutable11
argument_list|(
argument|const void *function
argument_list|,
argument|size_t length
argument_list|,
argument|ID3D11VertexShader *executable
argument_list|,
argument|ID3D11GeometryShader *streamOut
argument_list|)
block|;
name|ShaderExecutable11
argument_list|(
argument|const void *function
argument_list|,
argument|size_t length
argument_list|,
argument|ID3D11GeometryShader *executable
argument_list|)
block|;
name|virtual
operator|~
name|ShaderExecutable11
argument_list|()
block|;
specifier|static
name|ShaderExecutable11
operator|*
name|makeShaderExecutable11
argument_list|(
name|ShaderExecutableD3D
operator|*
name|executable
argument_list|)
block|;
name|ID3D11PixelShader
operator|*
name|getPixelShader
argument_list|()
specifier|const
block|;
name|ID3D11VertexShader
operator|*
name|getVertexShader
argument_list|()
specifier|const
block|;
name|ID3D11GeometryShader
operator|*
name|getGeometryShader
argument_list|()
specifier|const
block|;
name|ID3D11GeometryShader
operator|*
name|getStreamOutShader
argument_list|()
specifier|const
block|;
name|private
operator|:
name|ID3D11PixelShader
operator|*
name|mPixelExecutable
block|;
name|ID3D11VertexShader
operator|*
name|mVertexExecutable
block|;
name|ID3D11GeometryShader
operator|*
name|mGeometryExecutable
block|;
name|ID3D11GeometryShader
operator|*
name|mStreamOutExecutable
block|; }
decl_stmt|;
name|class
name|UniformStorage11
range|:
name|public
name|UniformStorageD3D
block|{
name|public
operator|:
name|UniformStorage11
argument_list|(
argument|Renderer11 *renderer
argument_list|,
argument|size_t initialSize
argument_list|)
block|;
name|virtual
operator|~
name|UniformStorage11
argument_list|()
block|;
specifier|static
specifier|const
name|UniformStorage11
operator|*
name|makeUniformStorage11
argument_list|(
specifier|const
name|UniformStorageD3D
operator|*
name|uniformStorage
argument_list|)
block|;
name|ID3D11Buffer
operator|*
name|getConstantBuffer
argument_list|()
specifier|const
block|{
return|return
name|mConstantBuffer
return|;
block|}
name|private
operator|:
name|ID3D11Buffer
operator|*
name|mConstantBuffer
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D11_SHADEREXECUTABLE11_H_
end_comment
end_unit
