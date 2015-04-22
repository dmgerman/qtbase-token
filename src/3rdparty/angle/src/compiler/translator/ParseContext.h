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
name|COMPILER_TRANSLATOR_PARSECONTEXT_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_PARSECONTEXT_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_PARSECONTEXT_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/Compiler.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Diagnostics.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/DirectiveHandler.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Intermediate.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/SymbolTable.h"
end_include
begin_include
include|#
directive|include
file|"compiler/preprocessor/Preprocessor.h"
end_include
begin_struct
DECL|struct|TMatrixFields
struct|struct
name|TMatrixFields
block|{
DECL|member|wholeRow
name|bool
name|wholeRow
decl_stmt|;
DECL|member|wholeCol
name|bool
name|wholeCol
decl_stmt|;
DECL|member|row
name|int
name|row
decl_stmt|;
DECL|member|col
name|int
name|col
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|//
end_comment
begin_comment
comment|// The following are extra variables needed during parsing, grouped together so
end_comment
begin_comment
comment|// they can be passed to the parser without needing a global.
end_comment
begin_comment
comment|//
end_comment
begin_struct
DECL|struct|TParseContext
struct|struct
name|TParseContext
block|{
DECL|function|TParseContext
name|TParseContext
argument_list|(
argument|TSymbolTable& symt
argument_list|,
argument|TExtensionBehavior& ext
argument_list|,
argument|TIntermediate& interm
argument_list|,
argument|sh::GLenum type
argument_list|,
argument|ShShaderSpec spec
argument_list|,
argument|int options
argument_list|,
argument|bool checksPrecErrors
argument_list|,
argument|TInfoSink& is
argument_list|,
argument|bool debugShaderPrecisionSupported
argument_list|)
block|:
name|intermediate
argument_list|(
name|interm
argument_list|)
operator|,
name|symbolTable
argument_list|(
name|symt
argument_list|)
operator|,
name|shaderType
argument_list|(
name|type
argument_list|)
operator|,
name|shaderSpec
argument_list|(
name|spec
argument_list|)
operator|,
name|compileOptions
argument_list|(
name|options
argument_list|)
operator|,
name|treeRoot
argument_list|(
literal|0
argument_list|)
operator|,
name|mLoopNestingLevel
argument_list|(
literal|0
argument_list|)
operator|,
name|structNestingLevel
argument_list|(
literal|0
argument_list|)
operator|,
name|mSwitchNestingLevel
argument_list|(
literal|0
argument_list|)
operator|,
name|currentFunctionType
argument_list|(
name|NULL
argument_list|)
operator|,
name|mFunctionReturnsValue
argument_list|(
name|false
argument_list|)
operator|,
name|checksPrecisionErrors
argument_list|(
name|checksPrecErrors
argument_list|)
operator|,
name|fragmentPrecisionHigh
argument_list|(
name|false
argument_list|)
operator|,
name|defaultMatrixPacking
argument_list|(
name|EmpColumnMajor
argument_list|)
operator|,
name|defaultBlockStorage
argument_list|(
name|EbsShared
argument_list|)
operator|,
name|diagnostics
argument_list|(
name|is
argument_list|)
operator|,
name|shaderVersion
argument_list|(
literal|100
argument_list|)
operator|,
name|directiveHandler
argument_list|(
name|ext
argument_list|,
name|diagnostics
argument_list|,
name|shaderVersion
argument_list|,
name|debugShaderPrecisionSupported
argument_list|)
operator|,
name|preprocessor
argument_list|(
operator|&
name|diagnostics
argument_list|,
operator|&
name|directiveHandler
argument_list|)
operator|,
name|scanner
argument_list|(
argument|NULL
argument_list|)
block|{  }
DECL|member|intermediate
name|TIntermediate
operator|&
name|intermediate
expr_stmt|;
comment|// to hold and build a parse tree
DECL|member|symbolTable
name|TSymbolTable
modifier|&
name|symbolTable
decl_stmt|;
comment|// symbol table that goes with the language currently being parsed
DECL|member|shaderType
name|sh
operator|::
name|GLenum
name|shaderType
expr_stmt|;
comment|// vertex or fragment language (future: pack or unpack)
DECL|member|shaderSpec
name|ShShaderSpec
name|shaderSpec
decl_stmt|;
comment|// The language specification compiler conforms to - GLES2 or WebGL.
DECL|member|shaderVersion
name|int
name|shaderVersion
decl_stmt|;
DECL|member|compileOptions
name|int
name|compileOptions
decl_stmt|;
DECL|member|treeRoot
name|TIntermNode
modifier|*
name|treeRoot
decl_stmt|;
comment|// root of parse tree being created
DECL|member|mLoopNestingLevel
name|int
name|mLoopNestingLevel
decl_stmt|;
comment|// 0 if outside all loops
DECL|member|structNestingLevel
name|int
name|structNestingLevel
decl_stmt|;
comment|// incremented while parsing a struct declaration
DECL|member|mSwitchNestingLevel
name|int
name|mSwitchNestingLevel
decl_stmt|;
comment|// 0 if outside all switch statements
DECL|member|currentFunctionType
specifier|const
name|TType
modifier|*
name|currentFunctionType
decl_stmt|;
comment|// the return type of the function that's currently being parsed
DECL|member|mFunctionReturnsValue
name|bool
name|mFunctionReturnsValue
decl_stmt|;
comment|// true if a non-void function has a return
DECL|member|checksPrecisionErrors
name|bool
name|checksPrecisionErrors
decl_stmt|;
comment|// true if an error will be generated when a variable is declared without precision, explicit or implicit.
DECL|member|fragmentPrecisionHigh
name|bool
name|fragmentPrecisionHigh
decl_stmt|;
comment|// true if highp precision is supported in the fragment language.
DECL|member|defaultMatrixPacking
name|TLayoutMatrixPacking
name|defaultMatrixPacking
decl_stmt|;
DECL|member|defaultBlockStorage
name|TLayoutBlockStorage
name|defaultBlockStorage
decl_stmt|;
DECL|member|HashErrMsg
name|TString
name|HashErrMsg
decl_stmt|;
DECL|member|diagnostics
name|TDiagnostics
name|diagnostics
decl_stmt|;
DECL|member|directiveHandler
name|TDirectiveHandler
name|directiveHandler
decl_stmt|;
DECL|member|preprocessor
name|pp
operator|::
name|Preprocessor
name|preprocessor
expr_stmt|;
DECL|member|scanner
name|void
modifier|*
name|scanner
decl_stmt|;
DECL|function|getShaderVersion
name|int
name|getShaderVersion
argument_list|()
specifier|const
block|{
return|return
name|shaderVersion
return|;
block|}
DECL|function|numErrors
name|int
name|numErrors
argument_list|()
specifier|const
block|{
return|return
name|diagnostics
operator|.
name|numErrors
argument_list|()
return|;
block|}
DECL|function|infoSink
name|TInfoSink
modifier|&
name|infoSink
parameter_list|()
block|{
return|return
name|diagnostics
operator|.
name|infoSink
argument_list|()
return|;
block|}
name|void
name|error
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|reason
parameter_list|,
specifier|const
name|char
modifier|*
name|token
parameter_list|,
specifier|const
name|char
modifier|*
name|extraInfo
init|=
literal|""
parameter_list|)
function_decl|;
name|void
name|warning
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|reason
parameter_list|,
specifier|const
name|char
modifier|*
name|token
parameter_list|,
specifier|const
name|char
modifier|*
name|extraInfo
init|=
literal|""
parameter_list|)
function_decl|;
name|void
name|trace
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|void
name|recover
parameter_list|()
function_decl|;
comment|// This method is guaranteed to succeed, even if no variable with 'name' exists.
specifier|const
name|TVariable
modifier|*
name|getNamedVariable
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|location
parameter_list|,
specifier|const
name|TString
modifier|*
name|name
parameter_list|,
specifier|const
name|TSymbol
modifier|*
name|symbol
parameter_list|)
function_decl|;
name|bool
name|parseVectorFields
parameter_list|(
specifier|const
name|TString
modifier|&
parameter_list|,
name|int
name|vecSize
parameter_list|,
name|TVectorFields
modifier|&
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|)
function_decl|;
name|bool
name|parseMatrixFields
parameter_list|(
specifier|const
name|TString
modifier|&
parameter_list|,
name|int
name|matCols
parameter_list|,
name|int
name|matRows
parameter_list|,
name|TMatrixFields
modifier|&
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|)
function_decl|;
name|bool
name|reservedErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|)
function_decl|;
name|void
name|assignError
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|op
parameter_list|,
name|TString
name|left
parameter_list|,
name|TString
name|right
parameter_list|)
function_decl|;
name|void
name|unaryOpError
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|op
parameter_list|,
name|TString
name|operand
parameter_list|)
function_decl|;
name|void
name|binaryOpError
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|op
parameter_list|,
name|TString
name|left
parameter_list|,
name|TString
name|right
parameter_list|)
function_decl|;
name|bool
name|precisionErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|TPrecision
name|precision
parameter_list|,
name|TBasicType
name|type
parameter_list|)
function_decl|;
name|bool
name|lValueErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|op
parameter_list|,
name|TIntermTyped
modifier|*
parameter_list|)
function_decl|;
name|bool
name|constErrorCheck
parameter_list|(
name|TIntermTyped
modifier|*
name|node
parameter_list|)
function_decl|;
name|bool
name|integerErrorCheck
parameter_list|(
name|TIntermTyped
modifier|*
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|token
parameter_list|)
function_decl|;
name|bool
name|globalErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|bool
name|global
parameter_list|,
specifier|const
name|char
modifier|*
name|token
parameter_list|)
function_decl|;
name|bool
name|constructorErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|TIntermNode
modifier|*
parameter_list|,
name|TFunction
modifier|&
parameter_list|,
name|TOperator
parameter_list|,
name|TType
modifier|*
parameter_list|)
function_decl|;
name|bool
name|arraySizeErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|TIntermTyped
modifier|*
name|expr
parameter_list|,
name|int
modifier|&
name|size
parameter_list|)
function_decl|;
name|bool
name|arrayQualifierErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|TPublicType
name|type
parameter_list|)
function_decl|;
name|bool
name|arrayTypeErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|TPublicType
name|type
parameter_list|)
function_decl|;
name|bool
name|arrayErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
specifier|const
name|TPublicType
modifier|&
name|type
parameter_list|,
name|TVariable
modifier|*
modifier|&
name|variable
parameter_list|)
function_decl|;
name|bool
name|voidErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
parameter_list|,
specifier|const
name|TString
modifier|&
parameter_list|,
specifier|const
name|TPublicType
modifier|&
parameter_list|)
function_decl|;
name|bool
name|boolErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
parameter_list|,
specifier|const
name|TIntermTyped
modifier|*
parameter_list|)
function_decl|;
name|bool
name|boolErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
parameter_list|,
specifier|const
name|TPublicType
modifier|&
parameter_list|)
function_decl|;
name|bool
name|samplerErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TPublicType
modifier|&
name|pType
parameter_list|,
specifier|const
name|char
modifier|*
name|reason
parameter_list|)
function_decl|;
name|bool
name|structQualifierErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TPublicType
modifier|&
name|pType
parameter_list|)
function_decl|;
name|bool
name|locationDeclaratorListCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TPublicType
modifier|&
name|pType
parameter_list|)
function_decl|;
name|bool
name|parameterSamplerErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|TQualifier
name|qualifier
parameter_list|,
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
name|bool
name|nonInitConstErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
name|TPublicType
modifier|&
name|type
parameter_list|,
name|bool
name|array
parameter_list|)
function_decl|;
name|bool
name|nonInitErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
specifier|const
name|TPublicType
modifier|&
name|type
parameter_list|,
name|TVariable
modifier|*
modifier|&
name|variable
parameter_list|)
function_decl|;
name|bool
name|paramErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|TQualifier
name|qualifier
parameter_list|,
name|TQualifier
name|paramQualifier
parameter_list|,
name|TType
modifier|*
name|type
parameter_list|)
function_decl|;
name|bool
name|extensionErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TString
modifier|&
parameter_list|)
function_decl|;
name|bool
name|singleDeclarationErrorCheck
parameter_list|(
name|TPublicType
modifier|&
name|publicType
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|identifierLocation
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|)
function_decl|;
name|bool
name|layoutLocationErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|location
parameter_list|,
specifier|const
name|TLayoutQualifier
modifier|&
name|layoutQualifier
parameter_list|)
function_decl|;
name|bool
name|functionCallLValueErrorCheck
parameter_list|(
specifier|const
name|TFunction
modifier|*
name|fnCandidate
parameter_list|,
name|TIntermAggregate
modifier|*
parameter_list|)
function_decl|;
DECL|function|pragma
specifier|const
name|TPragma
operator|&
name|pragma
argument_list|()
specifier|const
block|{
return|return
name|directiveHandler
operator|.
name|pragma
argument_list|()
return|;
block|}
DECL|function|extensionBehavior
specifier|const
name|TExtensionBehavior
operator|&
name|extensionBehavior
argument_list|()
specifier|const
block|{
return|return
name|directiveHandler
operator|.
name|extensionBehavior
argument_list|()
return|;
block|}
name|bool
name|supportsExtension
parameter_list|(
specifier|const
name|char
modifier|*
name|extension
parameter_list|)
function_decl|;
name|bool
name|isExtensionEnabled
argument_list|(
specifier|const
name|char
operator|*
name|extension
argument_list|)
decl|const
decl_stmt|;
name|void
name|handleExtensionDirective
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|extName
parameter_list|,
specifier|const
name|char
modifier|*
name|behavior
parameter_list|)
function_decl|;
name|void
name|handlePragmaDirective
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|bool
name|stdgl
parameter_list|)
function_decl|;
name|bool
name|containsSampler
parameter_list|(
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
name|bool
name|areAllChildConst
parameter_list|(
name|TIntermAggregate
modifier|*
name|aggrNode
parameter_list|)
function_decl|;
specifier|const
name|TFunction
modifier|*
name|findFunction
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
name|TFunction
modifier|*
name|pfnCall
parameter_list|,
name|int
name|inputShaderVersion
parameter_list|,
name|bool
modifier|*
name|builtIn
init|=
literal|0
parameter_list|)
function_decl|;
name|bool
name|executeInitializer
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
name|TPublicType
modifier|&
name|pType
parameter_list|,
name|TIntermTyped
modifier|*
name|initializer
parameter_list|,
name|TIntermNode
modifier|*
modifier|&
name|intermNode
parameter_list|,
name|TVariable
modifier|*
name|variable
init|=
literal|0
parameter_list|)
function_decl|;
name|TPublicType
name|addFullySpecifiedType
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|,
specifier|const
name|TPublicType
modifier|&
name|typeSpecifier
parameter_list|)
function_decl|;
name|TPublicType
name|addFullySpecifiedType
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|,
name|TLayoutQualifier
name|layoutQualifier
parameter_list|,
specifier|const
name|TPublicType
modifier|&
name|typeSpecifier
parameter_list|)
function_decl|;
name|TIntermAggregate
modifier|*
name|parseSingleDeclaration
parameter_list|(
name|TPublicType
modifier|&
name|publicType
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|identifierLocation
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|)
function_decl|;
name|TIntermAggregate
modifier|*
name|parseSingleArrayDeclaration
parameter_list|(
name|TPublicType
modifier|&
name|publicType
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|identifierLocation
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|indexLocation
parameter_list|,
name|TIntermTyped
modifier|*
name|indexExpression
parameter_list|)
function_decl|;
name|TIntermAggregate
modifier|*
name|parseSingleInitDeclaration
parameter_list|(
name|TPublicType
modifier|&
name|publicType
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|identifierLocation
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|initLocation
parameter_list|,
name|TIntermTyped
modifier|*
name|initializer
parameter_list|)
function_decl|;
name|TIntermAggregate
modifier|*
name|parseInvariantDeclaration
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|invariantLoc
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|identifierLoc
parameter_list|,
specifier|const
name|TString
modifier|*
name|identifier
parameter_list|,
specifier|const
name|TSymbol
modifier|*
name|symbol
parameter_list|)
function_decl|;
name|TIntermAggregate
modifier|*
name|parseDeclarator
parameter_list|(
name|TPublicType
modifier|&
name|publicType
parameter_list|,
name|TIntermAggregate
modifier|*
name|aggregateDeclaration
parameter_list|,
name|TSymbol
modifier|*
name|identifierSymbol
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|identifierLocation
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|)
function_decl|;
name|TIntermAggregate
modifier|*
name|parseArrayDeclarator
parameter_list|(
name|TPublicType
modifier|&
name|publicType
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|identifierLocation
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|arrayLocation
parameter_list|,
name|TIntermNode
modifier|*
name|declaratorList
parameter_list|,
name|TIntermTyped
modifier|*
name|indexExpression
parameter_list|)
function_decl|;
name|TIntermAggregate
modifier|*
name|parseInitDeclarator
parameter_list|(
name|TPublicType
modifier|&
name|publicType
parameter_list|,
name|TIntermAggregate
modifier|*
name|declaratorList
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|identifierLocation
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|initLocation
parameter_list|,
name|TIntermTyped
modifier|*
name|initializer
parameter_list|)
function_decl|;
name|void
name|parseGlobalLayoutQualifier
parameter_list|(
specifier|const
name|TPublicType
modifier|&
name|typeQualifier
parameter_list|)
function_decl|;
name|TFunction
modifier|*
name|addConstructorFunc
parameter_list|(
name|TPublicType
name|publicType
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addConstructor
parameter_list|(
name|TIntermNode
modifier|*
parameter_list|,
name|TType
modifier|*
parameter_list|,
name|TOperator
parameter_list|,
name|TFunction
modifier|*
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|foldConstConstructor
parameter_list|(
name|TIntermAggregate
modifier|*
name|aggrNode
parameter_list|,
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addConstVectorNode
parameter_list|(
name|TVectorFields
modifier|&
parameter_list|,
name|TIntermTyped
modifier|*
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addConstMatrixNode
parameter_list|(
name|int
parameter_list|,
name|TIntermTyped
modifier|*
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addConstArrayNode
parameter_list|(
name|int
name|index
parameter_list|,
name|TIntermTyped
modifier|*
name|node
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addConstStruct
parameter_list|(
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|,
name|TIntermTyped
modifier|*
name|node
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addIndexExpression
parameter_list|(
name|TIntermTyped
modifier|*
name|baseExpression
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|location
parameter_list|,
name|TIntermTyped
modifier|*
name|indexExpression
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addFieldSelectionExpression
parameter_list|(
name|TIntermTyped
modifier|*
name|baseExpression
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|dotLocation
parameter_list|,
specifier|const
name|TString
modifier|&
name|fieldString
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|fieldLocation
parameter_list|)
function_decl|;
name|TFieldList
modifier|*
name|addStructDeclaratorList
parameter_list|(
specifier|const
name|TPublicType
modifier|&
name|typeSpecifier
parameter_list|,
name|TFieldList
modifier|*
name|fieldList
parameter_list|)
function_decl|;
name|TPublicType
name|addStructure
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|structLine
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|nameLine
parameter_list|,
specifier|const
name|TString
modifier|*
name|structName
parameter_list|,
name|TFieldList
modifier|*
name|fieldList
parameter_list|)
function_decl|;
name|TIntermAggregate
modifier|*
name|addInterfaceBlock
parameter_list|(
specifier|const
name|TPublicType
modifier|&
name|typeQualifier
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|nameLine
parameter_list|,
specifier|const
name|TString
modifier|&
name|blockName
parameter_list|,
name|TFieldList
modifier|*
name|fieldList
parameter_list|,
specifier|const
name|TString
modifier|*
name|instanceName
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|instanceLine
parameter_list|,
name|TIntermTyped
modifier|*
name|arrayIndex
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|arrayIndexLine
parameter_list|)
function_decl|;
name|TLayoutQualifier
name|parseLayoutQualifier
parameter_list|(
specifier|const
name|TString
modifier|&
name|qualifierType
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|qualifierTypeLine
parameter_list|)
function_decl|;
name|TLayoutQualifier
name|parseLayoutQualifier
parameter_list|(
specifier|const
name|TString
modifier|&
name|qualifierType
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|qualifierTypeLine
parameter_list|,
specifier|const
name|TString
modifier|&
name|intValueString
parameter_list|,
name|int
name|intValue
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|intValueLine
parameter_list|)
function_decl|;
name|TLayoutQualifier
name|joinLayoutQualifiers
parameter_list|(
name|TLayoutQualifier
name|leftQualifier
parameter_list|,
name|TLayoutQualifier
name|rightQualifier
parameter_list|)
function_decl|;
name|TPublicType
name|joinInterpolationQualifiers
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|interpolationLoc
parameter_list|,
name|TQualifier
name|interpolationQualifier
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|storageLoc
parameter_list|,
name|TQualifier
name|storageQualifier
parameter_list|)
function_decl|;
comment|// Performs an error check for embedded struct declarations.
comment|// Returns true if an error was raised due to the declaration of
comment|// this struct.
name|bool
name|enterStructDeclaration
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TString
modifier|&
name|identifier
parameter_list|)
function_decl|;
name|void
name|exitStructDeclaration
parameter_list|()
function_decl|;
name|bool
name|structNestingErrorCheck
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|line
parameter_list|,
specifier|const
name|TField
modifier|&
name|field
parameter_list|)
function_decl|;
name|TIntermSwitch
modifier|*
name|addSwitch
parameter_list|(
name|TIntermTyped
modifier|*
name|init
parameter_list|,
name|TIntermAggregate
modifier|*
name|statementList
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
name|TIntermCase
modifier|*
name|addCase
parameter_list|(
name|TIntermTyped
modifier|*
name|condition
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
name|TIntermCase
modifier|*
name|addDefault
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addUnaryMath
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|child
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addUnaryMathLValue
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|child
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addBinaryMath
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|left
parameter_list|,
name|TIntermTyped
modifier|*
name|right
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addBinaryMathBooleanResult
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|left
parameter_list|,
name|TIntermTyped
modifier|*
name|right
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addAssign
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|left
parameter_list|,
name|TIntermTyped
modifier|*
name|right
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
name|TIntermBranch
modifier|*
name|addBranch
parameter_list|(
name|TOperator
name|op
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
name|TIntermBranch
modifier|*
name|addBranch
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|returnValue
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addFunctionCallOrMethod
parameter_list|(
name|TFunction
modifier|*
name|fnCall
parameter_list|,
name|TIntermNode
modifier|*
name|node
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|,
name|bool
modifier|*
name|fatalError
parameter_list|)
function_decl|;
DECL|member|private
name|private
label|:
DECL|member|left
DECL|member|right
name|TIntermTyped
modifier|*
name|addBinaryMathInternal
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|left
parameter_list|,
name|TIntermTyped
modifier|*
name|right
parameter_list|,
DECL|member|loc
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|createAssign
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|left
parameter_list|,
name|TIntermTyped
modifier|*
name|right
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
comment|// The funcReturnType parameter is expected to be non-null when the operation is a built-in function.
comment|// It is expected to be null for other unary operators.
name|TIntermTyped
modifier|*
name|createUnaryMath
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|child
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|,
specifier|const
name|TType
modifier|*
name|funcReturnType
parameter_list|)
function_decl|;
comment|// Return true if the checks pass
name|bool
name|binaryOpCommonCheck
parameter_list|(
name|TOperator
name|op
parameter_list|,
name|TIntermTyped
modifier|*
name|left
parameter_list|,
name|TIntermTyped
modifier|*
name|right
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_function_decl
name|int
name|PaParseStrings
parameter_list|(
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
name|string
index|[]
parameter_list|,
specifier|const
name|int
name|length
index|[]
parameter_list|,
name|TParseContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_PARSECONTEXT_H_
end_comment
end_unit
