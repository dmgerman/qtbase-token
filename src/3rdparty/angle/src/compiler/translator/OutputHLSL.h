begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_OUTPUTHLSL_H_
end_ifndef
begin_define
DECL|macro|COMPILER_OUTPUTHLSL_H_
define|#
directive|define
name|COMPILER_OUTPUTHLSL_H_
end_define
begin_include
include|#
directive|include
file|<list>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/intermediate.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/ParseContext.h"
end_include
begin_include
include|#
directive|include
file|"common/shadervars.h"
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
name|class
name|UnfoldShortCircuit
decl_stmt|;
name|class
name|StructureHLSL
decl_stmt|;
name|class
name|UniformHLSL
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|TString
operator|,
name|TIntermSymbol
operator|*
operator|>
name|ReferencedSymbols
expr_stmt|;
name|class
name|OutputHLSL
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|OutputHLSL
argument_list|(
argument|TParseContext&context
argument_list|,
argument|const ShBuiltInResources& resources
argument_list|,
argument|ShShaderOutput outputType
argument_list|)
block|;
operator|~
name|OutputHLSL
argument_list|()
block|;
name|void
name|output
argument_list|()
block|;
name|TInfoSinkBase
operator|&
name|getBodyStream
argument_list|()
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Uniform
operator|>
operator|&
name|getUniforms
argument_list|()
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|InterfaceBlock
operator|>
operator|&
name|getInterfaceBlocks
argument_list|()
specifier|const
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Attribute
operator|>
operator|&
name|getOutputVariables
argument_list|()
specifier|const
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Attribute
operator|>
operator|&
name|getAttributes
argument_list|()
specifier|const
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Varying
operator|>
operator|&
name|getVaryings
argument_list|()
specifier|const
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
name|getUniformRegisterMap
argument_list|()
specifier|const
block|;
specifier|static
name|TString
name|initializer
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|)
block|;
name|protected
operator|:
name|void
name|header
argument_list|()
block|;
comment|// Visit AST nodes and output their code to the body stream
name|void
name|visitSymbol
argument_list|(
name|TIntermSymbol
operator|*
argument_list|)
block|;
name|void
name|visitRaw
argument_list|(
name|TIntermRaw
operator|*
argument_list|)
block|;
name|void
name|visitConstantUnion
argument_list|(
name|TIntermConstantUnion
operator|*
argument_list|)
block|;
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary*
argument_list|)
block|;
name|bool
name|visitUnary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermUnary*
argument_list|)
block|;
name|bool
name|visitSelection
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermSelection*
argument_list|)
block|;
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate*
argument_list|)
block|;
name|bool
name|visitLoop
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermLoop*
argument_list|)
block|;
name|bool
name|visitBranch
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBranch*
argument_list|)
block|;
name|void
name|traverseStatements
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
block|;
name|bool
name|isSingleStatement
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
block|;
name|bool
name|handleExcessiveLoop
argument_list|(
name|TIntermLoop
operator|*
name|node
argument_list|)
block|;
name|void
name|outputTriplet
argument_list|(
argument|Visit visit
argument_list|,
argument|const TString&preString
argument_list|,
argument|const TString&inString
argument_list|,
argument|const TString&postString
argument_list|)
block|;
name|void
name|outputLineDirective
argument_list|(
argument|int line
argument_list|)
block|;
name|TString
name|argumentString
argument_list|(
specifier|const
name|TIntermSymbol
operator|*
name|symbol
argument_list|)
block|;
name|int
name|vectorSize
argument_list|(
argument|const TType&type
argument_list|)
specifier|const
block|;
name|void
name|outputConstructor
argument_list|(
argument|Visit visit
argument_list|,
argument|const TType&type
argument_list|,
argument|const TString&name
argument_list|,
argument|const TIntermSequence *parameters
argument_list|)
block|;
specifier|const
name|ConstantUnion
operator|*
name|writeConstantUnion
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|,
specifier|const
name|ConstantUnion
operator|*
name|constUnion
argument_list|)
block|;
name|TParseContext
operator|&
name|mContext
block|;
specifier|const
name|ShShaderOutput
name|mOutputType
block|;
name|UnfoldShortCircuit
operator|*
name|mUnfoldShortCircuit
block|;
name|bool
name|mInsideFunction
block|;
comment|// Output streams
name|TInfoSinkBase
name|mHeader
block|;
name|TInfoSinkBase
name|mBody
block|;
name|TInfoSinkBase
name|mFooter
block|;
name|ReferencedSymbols
name|mReferencedUniforms
block|;
name|ReferencedSymbols
name|mReferencedInterfaceBlocks
block|;
name|ReferencedSymbols
name|mReferencedAttributes
block|;
name|ReferencedSymbols
name|mReferencedVaryings
block|;
name|ReferencedSymbols
name|mReferencedOutputVariables
block|;
name|StructureHLSL
operator|*
name|mStructureHLSL
block|;
name|UniformHLSL
operator|*
name|mUniformHLSL
block|;      struct
name|TextureFunction
block|{         enum
name|Method
block|{
name|IMPLICIT
block|,
comment|// Mipmap LOD determined implicitly (standard lookup)
name|BIAS
block|,
name|LOD
block|,
name|LOD0
block|,
name|LOD0BIAS
block|,
name|SIZE
block|,
comment|// textureSize()
name|FETCH
block|,
name|GRAD
block|}
block|;
name|TBasicType
name|sampler
block|;
name|int
name|coords
block|;
name|bool
name|proj
block|;
name|bool
name|offset
block|;
name|Method
name|method
block|;
name|TString
name|name
argument_list|()
specifier|const
block|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|TextureFunction
operator|&
name|rhs
operator|)
specifier|const
block|;     }
block|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|TextureFunction
operator|>
name|TextureFunctionSet
expr_stmt|;
comment|// Parameters determining what goes in the header output
name|TextureFunctionSet
name|mUsesTexture
decl_stmt|;
name|bool
name|mUsesFragColor
decl_stmt|;
name|bool
name|mUsesFragData
decl_stmt|;
name|bool
name|mUsesDepthRange
decl_stmt|;
name|bool
name|mUsesFragCoord
decl_stmt|;
name|bool
name|mUsesPointCoord
decl_stmt|;
name|bool
name|mUsesFrontFacing
decl_stmt|;
name|bool
name|mUsesPointSize
decl_stmt|;
name|bool
name|mUsesFragDepth
decl_stmt|;
name|bool
name|mUsesXor
decl_stmt|;
name|bool
name|mUsesMod1
decl_stmt|;
name|bool
name|mUsesMod2v
decl_stmt|;
name|bool
name|mUsesMod2f
decl_stmt|;
name|bool
name|mUsesMod3v
decl_stmt|;
name|bool
name|mUsesMod3f
decl_stmt|;
name|bool
name|mUsesMod4v
decl_stmt|;
name|bool
name|mUsesMod4f
decl_stmt|;
name|bool
name|mUsesFaceforward1
decl_stmt|;
name|bool
name|mUsesFaceforward2
decl_stmt|;
name|bool
name|mUsesFaceforward3
decl_stmt|;
name|bool
name|mUsesFaceforward4
decl_stmt|;
name|bool
name|mUsesAtan2_1
decl_stmt|;
name|bool
name|mUsesAtan2_2
decl_stmt|;
name|bool
name|mUsesAtan2_3
decl_stmt|;
name|bool
name|mUsesAtan2_4
decl_stmt|;
name|bool
name|mUsesDiscardRewriting
decl_stmt|;
name|bool
name|mUsesNestedBreak
decl_stmt|;
name|int
name|mNumRenderTargets
decl_stmt|;
name|int
name|mUniqueIndex
decl_stmt|;
comment|// For creating unique names
name|bool
name|mContainsLoopDiscontinuity
decl_stmt|;
name|bool
name|mOutputLod0Function
decl_stmt|;
name|bool
name|mInsideDiscontinuousLoop
decl_stmt|;
name|int
name|mNestedLoopDepth
decl_stmt|;
name|TIntermSymbol
modifier|*
name|mExcessiveLoopIndex
decl_stmt|;
name|void
name|declareVaryingToList
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|,
name|TQualifier
name|baseTypeQualifier
argument_list|,
specifier|const
name|TString
operator|&
name|name
argument_list|,
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Varying
operator|>
operator|&
name|fieldsOut
argument_list|)
decl_stmt|;
name|TString
name|structInitializerString
parameter_list|(
name|int
name|indent
parameter_list|,
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|,
specifier|const
name|TString
modifier|&
name|rhsStructName
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Attribute
operator|>
name|mActiveOutputVariables
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Attribute
operator|>
name|mActiveAttributes
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Varying
operator|>
name|mActiveVaryings
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|TIntermTyped
operator|*
operator|,
name|TString
operator|>
name|mFlaggedStructMappedNames
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|TIntermTyped
operator|*
operator|,
name|TString
operator|>
name|mFlaggedStructOriginalNames
expr_stmt|;
name|void
name|makeFlaggedStructMaps
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|TIntermTyped
operator|*
operator|>
operator|&
name|flaggedStructs
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_OUTPUTHLSL_H_
end_comment
end_unit
