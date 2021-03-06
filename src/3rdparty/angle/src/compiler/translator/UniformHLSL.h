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
comment|// UniformHLSL.h:
end_comment
begin_comment
comment|//   Methods for GLSL to HLSL translation for uniforms and interface blocks.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_UNIFORMHLSL_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_UNIFORMHLSL_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_UNIFORMHLSL_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/OutputHLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/UtilsHLSL.h"
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
name|class
name|StructureHLSL
decl_stmt|;
name|class
name|UniformHLSL
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|UniformHLSL
argument_list|(
argument|StructureHLSL *structureHLSL
argument_list|,
argument|ShShaderOutput outputType
argument_list|,
argument|const std::vector<Uniform>&uniforms
argument_list|)
block|;
name|void
name|reserveUniformRegisters
argument_list|(
argument|unsigned int registerCount
argument_list|)
block|;
name|void
name|reserveInterfaceBlockRegisters
argument_list|(
argument|unsigned int registerCount
argument_list|)
block|;
name|void
name|outputHLSLSamplerUniformGroup
argument_list|(
argument|TInfoSinkBase&out
argument_list|,
argument|const HLSLTextureSamplerGroup textureGroup
argument_list|,
argument|const TVector<const TIntermSymbol *>&group
argument_list|,
argument|unsigned int *groupTextureRegisterIndex
argument_list|)
block|;
name|void
name|uniformsHeader
argument_list|(
argument|TInfoSinkBase&out
argument_list|,
argument|ShShaderOutput outputType
argument_list|,
argument|const ReferencedSymbols&referencedUniforms
argument_list|)
block|;
name|TString
name|interfaceBlocksHeader
argument_list|(
specifier|const
name|ReferencedSymbols
operator|&
name|referencedInterfaceBlocks
argument_list|)
block|;
comment|// Used for direct index references
specifier|static
name|TString
name|interfaceBlockInstanceString
argument_list|(
argument|const TInterfaceBlock& interfaceBlock
argument_list|,
argument|unsigned int arrayIndex
argument_list|)
block|;
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|unsigned
name|int
operator|>
operator|&
name|getInterfaceBlockRegisterMap
argument_list|()
specifier|const
block|{
return|return
name|mInterfaceBlockRegisterMap
return|;
block|}
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|unsigned
name|int
operator|>
operator|&
name|getUniformRegisterMap
argument_list|()
specifier|const
block|{
return|return
name|mUniformRegisterMap
return|;
block|}
name|private
operator|:
name|TString
name|interfaceBlockString
argument_list|(
argument|const TInterfaceBlock&interfaceBlock
argument_list|,
argument|unsigned int registerIndex
argument_list|,
argument|unsigned int arrayIndex
argument_list|)
block|;
name|TString
name|interfaceBlockMembersString
argument_list|(
argument|const TInterfaceBlock&interfaceBlock
argument_list|,
argument|TLayoutBlockStorage blockStorage
argument_list|)
block|;
name|TString
name|interfaceBlockStructString
argument_list|(
specifier|const
name|TInterfaceBlock
operator|&
name|interfaceBlock
argument_list|)
block|;
specifier|const
name|Uniform
operator|*
name|findUniformByName
argument_list|(
argument|const TString&name
argument_list|)
specifier|const
block|;
comment|// Returns the uniform's register index
name|unsigned
name|int
name|declareUniformAndAssignRegister
argument_list|(
argument|const TType&type
argument_list|,
argument|const TString&name
argument_list|,
argument|unsigned int *registerCount
argument_list|)
block|;
name|unsigned
name|int
name|declareUniformAndAssignRegister
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|,
specifier|const
name|TString
operator|&
name|name
argument_list|)
block|;
name|unsigned
name|int
name|mUniformRegister
block|;
name|unsigned
name|int
name|mInterfaceBlockRegister
block|;
name|unsigned
name|int
name|mSamplerRegister
block|;
name|StructureHLSL
operator|*
name|mStructureHLSL
block|;
name|ShShaderOutput
name|mOutputType
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|Uniform
operator|>
operator|&
name|mUniforms
block|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|unsigned
name|int
operator|>
name|mInterfaceBlockRegisterMap
block|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|unsigned
name|int
operator|>
name|mUniformRegisterMap
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_UNIFORMHLSL_H_
end_comment
end_unit
