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
name|LIBGLESV2_DYNAMIC_HLSL_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_DYNAMIC_HLSL_H_
define|#
directive|define
name|LIBGLESV2_DYNAMIC_HLSL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/constants.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer
decl_stmt|;
block|}
end_decl_stmt
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
name|class
name|FragmentShader
decl_stmt|;
name|class
name|VertexShader
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
typedef|typedef
specifier|const
name|PackedVarying
modifier|*
name|VaryingPacking
index|[
name|IMPLEMENTATION_MAX_VARYING_VECTORS
index|]
index|[
literal|4
index|]
typedef|;
struct|struct
name|PixelShaderOuputVariable
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
block|{
name|public
label|:
name|explicit
name|DynamicHLSL
argument_list|(
name|rx
operator|::
name|Renderer
operator|*
specifier|const
name|renderer
argument_list|)
decl_stmt|;
name|int
name|packVaryings
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
name|VaryingPacking
name|packing
argument_list|,
name|FragmentShader
operator|*
name|fragmentShader
argument_list|,
name|VertexShader
operator|*
name|vertexShader
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|transformFeedbackVaryings
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|generateVertexShaderForInputLayout
argument_list|(
argument|const std::string&sourceShader
argument_list|,
argument|const VertexFormat inputLayout[]
argument_list|,
argument|const sh::Attribute shaderAttributes[]
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|generatePixelShaderForOutputSignature
argument_list|(
argument|const std::string&sourceShader
argument_list|,
argument|const std::vector<PixelShaderOuputVariable>&outputVariables
argument_list|,
argument|bool usesFragDepth
argument_list|,
argument|const std::vector<GLenum>&outputLayout
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|generateShaderLinkHLSL
argument_list|(
name|InfoLog
operator|&
name|infoLog
argument_list|,
name|int
name|registers
argument_list|,
specifier|const
name|VaryingPacking
name|packing
argument_list|,
name|std
operator|::
name|string
operator|&
name|pixelHLSL
argument_list|,
name|std
operator|::
name|string
operator|&
name|vertexHLSL
argument_list|,
name|FragmentShader
operator|*
name|fragmentShader
argument_list|,
name|VertexShader
operator|*
name|vertexShader
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|transformFeedbackVaryings
argument_list|,
name|std
operator|::
name|vector
operator|<
name|LinkedVarying
operator|>
operator|*
name|linkedVaryings
argument_list|,
name|std
operator|::
name|map
operator|<
name|int
argument_list|,
name|VariableLocation
operator|>
operator|*
name|programOutputVars
argument_list|,
name|std
operator|::
name|vector
operator|<
name|PixelShaderOuputVariable
operator|>
operator|*
name|outPixelShaderKey
argument_list|,
name|bool
operator|*
name|outUsesFragDepth
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|string
name|generateGeometryShaderHLSL
argument_list|(
argument|int registers
argument_list|,
argument|FragmentShader *fragmentShader
argument_list|,
argument|VertexShader *vertexShader
argument_list|)
specifier|const
expr_stmt|;
name|void
name|getInputLayoutSignature
argument_list|(
specifier|const
name|VertexFormat
name|inputLayout
index|[]
argument_list|,
name|GLenum
name|signature
index|[]
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicHLSL
argument_list|)
expr_stmt|;
name|rx
operator|::
name|Renderer
operator|*
specifier|const
name|mRenderer
expr_stmt|;
struct_decl|struct
name|SemanticInfo
struct_decl|;
name|std
operator|::
name|string
name|getVaryingSemantic
argument_list|(
argument|bool pointSize
argument_list|)
specifier|const
expr_stmt|;
name|SemanticInfo
name|getSemanticInfo
argument_list|(
name|int
name|startRegisters
argument_list|,
name|bool
name|fragCoord
argument_list|,
name|bool
name|pointCoord
argument_list|,
name|bool
name|pointSize
argument_list|,
name|bool
name|pixelShader
argument_list|)
decl|const
decl_stmt|;
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
expr_stmt|;
name|std
operator|::
name|string
name|generateVaryingHLSL
argument_list|(
argument|VertexShader *shader
argument_list|)
specifier|const
expr_stmt|;
name|void
name|storeUserLinkedVaryings
argument_list|(
specifier|const
name|VertexShader
operator|*
name|vertexShader
argument_list|,
name|std
operator|::
name|vector
operator|<
name|LinkedVarying
operator|>
operator|*
name|linkedVaryings
argument_list|)
decl|const
decl_stmt|;
name|void
name|storeBuiltinLinkedVaryings
argument_list|(
specifier|const
name|SemanticInfo
operator|&
name|info
argument_list|,
name|std
operator|::
name|vector
operator|<
name|LinkedVarying
operator|>
operator|*
name|linkedVaryings
argument_list|)
decl|const
decl_stmt|;
name|void
name|defineOutputVariables
argument_list|(
name|FragmentShader
operator|*
name|fragmentShader
argument_list|,
name|std
operator|::
name|map
operator|<
name|int
argument_list|,
name|VariableLocation
operator|>
operator|*
name|programOutputVars
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|string
name|generatePointSpriteHLSL
argument_list|(
argument|int registers
argument_list|,
argument|FragmentShader *fragmentShader
argument_list|,
argument|VertexShader *vertexShader
argument_list|)
specifier|const
expr_stmt|;
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
expr_stmt|;
name|std
operator|::
name|string
name|generateAttributeConversionHLSL
argument_list|(
argument|const VertexFormat&vertexFormat
argument_list|,
argument|const sh::ShaderVariable&shaderAttrib
argument_list|)
specifier|const
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
comment|// LIBGLESV2_DYNAMIC_HLSL_H_
end_comment
end_unit
