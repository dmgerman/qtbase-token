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
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<map>
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
name|LinkedVarying
struct_decl|;
struct_decl|struct
name|VertexAttribute
struct_decl|;
struct_decl|struct
name|VertexFormat
struct_decl|;
struct_decl|struct
name|PackedVarying
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
name|class
name|RendererD3D
decl_stmt|;
name|class
name|ShaderD3D
decl_stmt|;
typedef|typedef
specifier|const
name|gl
operator|::
name|PackedVarying
operator|*
name|VaryingPacking
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_VARYING_VECTORS
index|]
index|[
literal|4
index|]
expr_stmt|;
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
name|int
name|packVaryings
argument_list|(
argument|gl::InfoLog&infoLog
argument_list|,
argument|VaryingPacking packing
argument_list|,
argument|ShaderD3D *fragmentShader
argument_list|,
argument|ShaderD3D *vertexShader
argument_list|,
argument|const std::vector<std::string>& transformFeedbackVaryings
argument_list|)
block|;
name|std
operator|::
name|string
name|generateVertexShaderForInputLayout
argument_list|(
argument|const std::string&sourceShader
argument_list|,
argument|const gl::VertexFormat inputLayout[]
argument_list|,
argument|const sh::Attribute shaderAttributes[]
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
argument|gl::InfoLog&infoLog
argument_list|,
argument|int registers
argument_list|,
argument|const VaryingPacking packing
argument_list|,
argument|std::string&pixelHLSL
argument_list|,
argument|std::string&vertexHLSL
argument_list|,
argument|ShaderD3D *fragmentShader
argument_list|,
argument|ShaderD3D *vertexShader
argument_list|,
argument|const std::vector<std::string>&transformFeedbackVaryings
argument_list|,
argument|std::vector<gl::LinkedVarying> *linkedVaryings
argument_list|,
argument|std::map<int
argument_list|,
argument|gl::VariableLocation> *programOutputVars
argument_list|,
argument|std::vector<PixelShaderOutputVariable> *outPixelShaderKey
argument_list|,
argument|bool *outUsesFragDepth
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|generateGeometryShaderHLSL
argument_list|(
argument|int registers
argument_list|,
argument|ShaderD3D *fragmentShader
argument_list|,
argument|ShaderD3D *vertexShader
argument_list|)
specifier|const
block|;
name|void
name|getInputLayoutSignature
argument_list|(
argument|const gl::VertexFormat inputLayout[]
argument_list|,
argument|GLenum signature[]
argument_list|)
specifier|const
block|;
name|private
operator|:
name|RendererD3D
operator|*
specifier|const
name|mRenderer
block|;      struct
name|SemanticInfo
block|;
name|std
operator|::
name|string
name|getVaryingSemantic
argument_list|(
argument|bool pointSize
argument_list|)
specifier|const
block|;
name|SemanticInfo
name|getSemanticInfo
argument_list|(
argument|int startRegisters
argument_list|,
argument|bool position
argument_list|,
argument|bool fragCoord
argument_list|,
argument|bool pointCoord
argument_list|,
argument|bool pointSize
argument_list|,
argument|bool pixelShader
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|generateVaryingLinkHLSL
argument_list|(
argument|const SemanticInfo&info
argument_list|,
argument|const std::string&varyingHLSL
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|generateVaryingHLSL
argument_list|(
argument|const ShaderD3D *shader
argument_list|)
specifier|const
block|;
name|void
name|storeUserLinkedVaryings
argument_list|(
argument|const ShaderD3D *vertexShader
argument_list|,
argument|std::vector<gl::LinkedVarying> *linkedVaryings
argument_list|)
specifier|const
block|;
name|void
name|storeBuiltinLinkedVaryings
argument_list|(
argument|const SemanticInfo&info
argument_list|,
argument|std::vector<gl::LinkedVarying> *linkedVaryings
argument_list|)
specifier|const
block|;
name|void
name|defineOutputVariables
argument_list|(
argument|ShaderD3D *fragmentShader
argument_list|,
argument|std::map<int
argument_list|,
argument|gl::VariableLocation> *programOutputVars
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|generatePointSpriteHLSL
argument_list|(
argument|int registers
argument_list|,
argument|ShaderD3D *fragmentShader
argument_list|,
argument|ShaderD3D *vertexShader
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
argument|const gl::VertexFormat&vertexFormat
argument_list|,
argument|const sh::ShaderVariable&shaderAttrib
argument_list|)
specifier|const
block|; }
decl_stmt|;
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
