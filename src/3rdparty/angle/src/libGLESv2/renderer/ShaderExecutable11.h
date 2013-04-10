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
comment|// ShaderExecutable11.h: Defines a D3D11-specific class to contain shader
end_comment
begin_comment
comment|// executable implementation details.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_SHADEREXECUTABLE11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_SHADEREXECUTABLE11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_SHADEREXECUTABLE11_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/ShaderExecutable.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|ShaderExecutable11
range|:
name|public
name|ShaderExecutable
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
name|ShaderExecutable
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
name|ID3D11Buffer
operator|*
name|getConstantBuffer
argument_list|(
argument|ID3D11Device *device
argument_list|,
argument|unsigned int registerCount
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ShaderExecutable11
argument_list|)
block|;
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
comment|// LIBGLESV2_RENDERER_SHADEREXECUTABLE11_H_
end_comment
end_unit
