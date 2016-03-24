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
comment|// DynamicHLSL.h: Interface for link and run-time HLSL generation
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_DYNAMICHLSL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_DYNAMICHLSL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_DYNAMICHLSL_H_
end_define
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Constants.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Program.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/formatutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RendererD3D.h"
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
struct_decl|struct
name|Attribute
struct_decl|;
struct_decl|struct
name|ShaderVariable
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|InfoLog
decl_stmt|;
struct_decl|struct
name|VariableLocation
struct_decl|;
struct_decl|struct
name|VertexAttribute
struct_decl|;
struct_decl|struct
name|Data
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
struct_decl|struct
name|PackedVarying
struct_decl|;
name|class
name|ProgramD3DMetadata
decl_stmt|;
name|class
name|ShaderD3D
decl_stmt|;
name|class
name|VaryingPacking
decl_stmt|;
struct|struct
name|PixelShaderOutputVariable
block|{
name|GLenum
name|type
decl_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
name|std
operator|::
name|string
name|source
expr_stmt|;
name|size_t
name|outputIndex
decl_stmt|;
block|}
struct|;
name|class
name|DynamicHLSL
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|explicit
name|DynamicHLSL
argument_list|(
name|RendererD3D
operator|*
specifier|const
name|renderer
argument_list|)
block|;
name|std
operator|::
name|string
name|generateVertexShaderForInputLayout
argument_list|(
argument|const std::string&sourceShader
argument_list|,
argument|const gl::InputLayout&inputLayout
argument_list|,
argument|const std::vector<sh::Attribute>&shaderAttributes
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|generatePixelShaderForOutputSignature
argument_list|(
argument|const std::string&sourceShader
argument_list|,
argument|const std::vector<PixelShaderOutputVariable>&outputVariables
argument_list|,
argument|bool usesFragDepth
argument_list|,
argument|const std::vector<GLenum>&outputLayout
argument_list|)
specifier|const
block|;
name|bool
name|generateShaderLinkHLSL
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|const gl::Program::Data&programData
argument_list|,
argument|const ProgramD3DMetadata&programMetadata
argument_list|,
argument|const VaryingPacking&varyingPacking
argument_list|,
argument|std::string *pixelHLSL
argument_list|,
argument|std::string *vertexHLSL
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|generateGeometryShaderPreamble
argument_list|(
argument|const VaryingPacking&varyingPacking
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|generateGeometryShaderHLSL
argument_list|(
argument|gl::PrimitiveType primitiveType
argument_list|,
argument|const gl::Data&data
argument_list|,
argument|const gl::Program::Data&programData
argument_list|,
argument|const bool useViewScale
argument_list|,
argument|const std::string&preambleString
argument_list|)
specifier|const
block|;
name|void
name|getPixelShaderOutputKey
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|,
specifier|const
name|gl
operator|::
name|Program
operator|::
name|Data
operator|&
name|programData
argument_list|,
specifier|const
name|ProgramD3DMetadata
operator|&
name|metadata
argument_list|,
name|std
operator|::
name|vector
operator|<
name|PixelShaderOutputVariable
operator|>
operator|*
name|outPixelShaderKey
argument_list|)
block|;
name|private
operator|:
name|RendererD3D
operator|*
specifier|const
name|mRenderer
block|;
name|void
name|generateVaryingLinkHLSL
argument_list|(
argument|ShaderType shaderType
argument_list|,
argument|const VaryingPacking&varyingPacking
argument_list|,
argument|std::stringstream&linkStream
argument_list|)
specifier|const
block|;
name|void
name|generateVaryingHLSL
argument_list|(
argument|const VaryingPacking&varyingPacking
argument_list|,
argument|std::stringstream&hlslStream
argument_list|)
specifier|const
block|;
comment|// Prepend an underscore
specifier|static
name|std
operator|::
name|string
name|decorateVariable
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
block|;
name|std
operator|::
name|string
name|generateAttributeConversionHLSL
argument_list|(
argument|gl::VertexFormatType vertexFormatType
argument_list|,
argument|const sh::ShaderVariable&shaderAttrib
argument_list|)
specifier|const
block|; }
decl_stmt|;
name|std
operator|::
name|string
name|GetVaryingSemantic
argument_list|(
argument|int majorShaderModel
argument_list|,
argument|bool programUsesPointSize
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_DYNAMICHLSL_H_
end_comment
end_unit
