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
comment|// ShaderExecutable11.cpp: Implements a D3D11-specific class to contain shader
end_comment
begin_comment
comment|// executable implementation details.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/ShaderExecutable11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|ShaderExecutable11
name|ShaderExecutable11
operator|::
name|ShaderExecutable11
parameter_list|(
specifier|const
name|void
modifier|*
name|function
parameter_list|,
name|size_t
name|length
parameter_list|,
name|ID3D11PixelShader
modifier|*
name|executable
parameter_list|)
member_init_list|:
name|ShaderExecutableD3D
argument_list|(
name|function
argument_list|,
name|length
argument_list|)
block|{
name|mPixelExecutable
operator|=
name|executable
expr_stmt|;
name|mVertexExecutable
operator|=
name|NULL
expr_stmt|;
name|mGeometryExecutable
operator|=
name|NULL
expr_stmt|;
name|mStreamOutExecutable
operator|=
name|NULL
expr_stmt|;
block|}
DECL|function|ShaderExecutable11
name|ShaderExecutable11
operator|::
name|ShaderExecutable11
parameter_list|(
specifier|const
name|void
modifier|*
name|function
parameter_list|,
name|size_t
name|length
parameter_list|,
name|ID3D11VertexShader
modifier|*
name|executable
parameter_list|,
name|ID3D11GeometryShader
modifier|*
name|streamOut
parameter_list|)
member_init_list|:
name|ShaderExecutableD3D
argument_list|(
name|function
argument_list|,
name|length
argument_list|)
block|{
name|mVertexExecutable
operator|=
name|executable
expr_stmt|;
name|mPixelExecutable
operator|=
name|NULL
expr_stmt|;
name|mGeometryExecutable
operator|=
name|NULL
expr_stmt|;
name|mStreamOutExecutable
operator|=
name|streamOut
expr_stmt|;
block|}
DECL|function|ShaderExecutable11
name|ShaderExecutable11
operator|::
name|ShaderExecutable11
parameter_list|(
specifier|const
name|void
modifier|*
name|function
parameter_list|,
name|size_t
name|length
parameter_list|,
name|ID3D11GeometryShader
modifier|*
name|executable
parameter_list|)
member_init_list|:
name|ShaderExecutableD3D
argument_list|(
name|function
argument_list|,
name|length
argument_list|)
block|{
name|mGeometryExecutable
operator|=
name|executable
expr_stmt|;
name|mVertexExecutable
operator|=
name|NULL
expr_stmt|;
name|mPixelExecutable
operator|=
name|NULL
expr_stmt|;
name|mStreamOutExecutable
operator|=
name|NULL
expr_stmt|;
block|}
DECL|function|~ShaderExecutable11
name|ShaderExecutable11
operator|::
name|~
name|ShaderExecutable11
parameter_list|()
block|{
name|SafeRelease
argument_list|(
name|mVertexExecutable
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mPixelExecutable
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mGeometryExecutable
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mStreamOutExecutable
argument_list|)
expr_stmt|;
block|}
DECL|function|getVertexShader
name|ID3D11VertexShader
modifier|*
name|ShaderExecutable11
operator|::
name|getVertexShader
parameter_list|()
specifier|const
block|{
return|return
name|mVertexExecutable
return|;
block|}
DECL|function|getPixelShader
name|ID3D11PixelShader
modifier|*
name|ShaderExecutable11
operator|::
name|getPixelShader
parameter_list|()
specifier|const
block|{
return|return
name|mPixelExecutable
return|;
block|}
DECL|function|getGeometryShader
name|ID3D11GeometryShader
modifier|*
name|ShaderExecutable11
operator|::
name|getGeometryShader
parameter_list|()
specifier|const
block|{
return|return
name|mGeometryExecutable
return|;
block|}
DECL|function|getStreamOutShader
name|ID3D11GeometryShader
modifier|*
name|ShaderExecutable11
operator|::
name|getStreamOutShader
parameter_list|()
specifier|const
block|{
return|return
name|mStreamOutExecutable
return|;
block|}
DECL|function|UniformStorage11
name|UniformStorage11
operator|::
name|UniformStorage11
parameter_list|(
name|Renderer11
modifier|*
name|renderer
parameter_list|,
name|size_t
name|initialSize
parameter_list|)
member_init_list|:
name|UniformStorageD3D
argument_list|(
name|initialSize
argument_list|)
member_init_list|,
name|mConstantBuffer
argument_list|(
name|NULL
argument_list|)
block|{
name|ID3D11Device
modifier|*
name|d3d11Device
init|=
name|renderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
if|if
condition|(
name|initialSize
operator|>
literal|0
condition|)
block|{
name|D3D11_BUFFER_DESC
name|constantBufferDescription
init|=
block|{
literal|0
block|}
decl_stmt|;
name|constantBufferDescription
operator|.
name|ByteWidth
operator|=
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|initialSize
argument_list|)
expr_stmt|;
name|constantBufferDescription
operator|.
name|Usage
operator|=
name|D3D11_USAGE_DYNAMIC
expr_stmt|;
name|constantBufferDescription
operator|.
name|BindFlags
operator|=
name|D3D11_BIND_CONSTANT_BUFFER
expr_stmt|;
name|constantBufferDescription
operator|.
name|CPUAccessFlags
operator|=
name|D3D11_CPU_ACCESS_WRITE
expr_stmt|;
name|constantBufferDescription
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
name|constantBufferDescription
operator|.
name|StructureByteStride
operator|=
literal|0
expr_stmt|;
name|HRESULT
name|result
init|=
name|d3d11Device
operator|->
name|CreateBuffer
argument_list|(
operator|&
name|constantBufferDescription
argument_list|,
name|NULL
argument_list|,
operator|&
name|mConstantBuffer
argument_list|)
decl_stmt|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|~UniformStorage11
name|UniformStorage11
operator|::
name|~
name|UniformStorage11
parameter_list|()
block|{
name|SafeRelease
argument_list|(
name|mConstantBuffer
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
end_unit
