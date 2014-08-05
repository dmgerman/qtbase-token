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
name|TRANSLATOR_UNIFORMHLSL_H_
end_ifndef
begin_define
DECL|macro|TRANSLATOR_UNIFORMHLSL_H_
define|#
directive|define
name|TRANSLATOR_UNIFORMHLSL_H_
end_define
begin_include
include|#
directive|include
file|"common/shadervars.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Types.h"
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
block|{
name|public
label|:
name|UniformHLSL
argument_list|(
argument|StructureHLSL *structureHLSL
argument_list|,
argument|ShShaderOutput outputType
argument_list|)
empty_stmt|;
name|void
name|reserveUniformRegisters
parameter_list|(
name|unsigned
name|int
name|registerCount
parameter_list|)
function_decl|;
name|void
name|reserveInterfaceBlockRegisters
parameter_list|(
name|unsigned
name|int
name|registerCount
parameter_list|)
function_decl|;
name|TString
name|uniformsHeader
parameter_list|(
name|ShShaderOutput
name|outputType
parameter_list|,
specifier|const
name|ReferencedSymbols
modifier|&
name|referencedUniforms
parameter_list|)
function_decl|;
name|TString
name|interfaceBlocksHeader
parameter_list|(
specifier|const
name|ReferencedSymbols
modifier|&
name|referencedInterfaceBlocks
parameter_list|)
function_decl|;
comment|// Used for direct index references
specifier|static
name|TString
name|interfaceBlockInstanceString
parameter_list|(
specifier|const
name|TInterfaceBlock
modifier|&
name|interfaceBlock
parameter_list|,
name|unsigned
name|int
name|arrayIndex
parameter_list|)
function_decl|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|Uniform
operator|>
operator|&
name|getUniforms
argument_list|()
specifier|const
block|{
return|return
name|mActiveUniforms
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|InterfaceBlock
operator|>
operator|&
name|getInterfaceBlocks
argument_list|()
specifier|const
block|{
return|return
name|mActiveInterfaceBlocks
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
operator|,
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
operator|,
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
label|:
name|TString
name|interfaceBlockString
parameter_list|(
specifier|const
name|TInterfaceBlock
modifier|&
name|interfaceBlock
parameter_list|,
name|unsigned
name|int
name|registerIndex
parameter_list|,
name|unsigned
name|int
name|arrayIndex
parameter_list|)
function_decl|;
name|TString
name|interfaceBlockMembersString
parameter_list|(
specifier|const
name|TInterfaceBlock
modifier|&
name|interfaceBlock
parameter_list|,
name|TLayoutBlockStorage
name|blockStorage
parameter_list|)
function_decl|;
name|TString
name|interfaceBlockStructString
parameter_list|(
specifier|const
name|TInterfaceBlock
modifier|&
name|interfaceBlock
parameter_list|)
function_decl|;
comment|// Returns the uniform's register index
name|unsigned
name|int
name|declareUniformAndAssignRegister
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|,
specifier|const
name|TString
modifier|&
name|name
parameter_list|)
function_decl|;
name|unsigned
name|int
name|mUniformRegister
decl_stmt|;
name|unsigned
name|int
name|mInterfaceBlockRegister
decl_stmt|;
name|unsigned
name|int
name|mSamplerRegister
decl_stmt|;
name|StructureHLSL
modifier|*
name|mStructureHLSL
decl_stmt|;
name|ShShaderOutput
name|mOutputType
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Uniform
operator|>
name|mActiveUniforms
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|InterfaceBlock
operator|>
name|mActiveInterfaceBlocks
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|unsigned
name|int
operator|>
name|mInterfaceBlockRegisterMap
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|unsigned
name|int
operator|>
name|mUniformRegisterMap
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
comment|// TRANSLATOR_UNIFORMHLSL_H_
end_comment
end_unit
