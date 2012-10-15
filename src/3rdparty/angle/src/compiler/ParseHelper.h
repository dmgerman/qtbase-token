begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
name|_PARSER_HELPER_INCLUDED_
end_ifndef
begin_define
DECL|macro|_PARSER_HELPER_INCLUDED_
define|#
directive|define
name|_PARSER_HELPER_INCLUDED_
end_define
begin_include
include|#
directive|include
file|"compiler/Diagnostics.h"
end_include
begin_include
include|#
directive|include
file|"compiler/DirectiveHandler.h"
end_include
begin_include
include|#
directive|include
file|"compiler/localintermediate.h"
end_include
begin_include
include|#
directive|include
file|"compiler/preprocessor/new/Preprocessor.h"
end_include
begin_include
include|#
directive|include
file|"compiler/ShHandle.h"
end_include
begin_include
include|#
directive|include
file|"compiler/SymbolTable.h"
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
argument|ShShaderType type
argument_list|,
argument|ShShaderSpec spec
argument_list|,
argument|int options
argument_list|,
argument|bool checksPrecErrors
argument_list|,
argument|const char* sourcePath
argument_list|,
argument|TInfoSink& is
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
name|sourcePath
argument_list|(
name|sourcePath
argument_list|)
operator|,
name|treeRoot
argument_list|(
literal|0
argument_list|)
operator|,
name|lexAfterType
argument_list|(
name|false
argument_list|)
operator|,
name|loopNestingLevel
argument_list|(
literal|0
argument_list|)
operator|,
name|structNestingLevel
argument_list|(
literal|0
argument_list|)
operator|,
name|inTypeParen
argument_list|(
name|false
argument_list|)
operator|,
name|currentFunctionType
argument_list|(
name|NULL
argument_list|)
operator|,
name|functionReturnsValue
argument_list|(
name|false
argument_list|)
operator|,
name|checksPrecisionErrors
argument_list|(
name|checksPrecErrors
argument_list|)
operator|,
name|diagnostics
argument_list|(
name|is
argument_list|)
operator|,
name|directiveHandler
argument_list|(
name|ext
argument_list|,
name|diagnostics
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
name|ShShaderType
name|shaderType
decl_stmt|;
comment|// vertex or fragment language (future: pack or unpack)
DECL|member|shaderSpec
name|ShShaderSpec
name|shaderSpec
decl_stmt|;
comment|// The language specification compiler conforms to - GLES2 or WebGL.
DECL|member|compileOptions
name|int
name|compileOptions
decl_stmt|;
DECL|member|sourcePath
specifier|const
name|char
modifier|*
name|sourcePath
decl_stmt|;
comment|// Path of source file or NULL.
DECL|member|treeRoot
name|TIntermNode
modifier|*
name|treeRoot
decl_stmt|;
comment|// root of parse tree being created
DECL|member|lexAfterType
name|bool
name|lexAfterType
decl_stmt|;
comment|// true if we've recognized a type, so can only be looking for an identifier
DECL|member|loopNestingLevel
name|int
name|loopNestingLevel
decl_stmt|;
comment|// 0 if outside all loops
DECL|member|structNestingLevel
name|int
name|structNestingLevel
decl_stmt|;
comment|// incremented while parsing a struct declaration
DECL|member|inTypeParen
name|bool
name|inTypeParen
decl_stmt|;
comment|// true if in parentheses, looking only for an identifier
DECL|member|currentFunctionType
specifier|const
name|TType
modifier|*
name|currentFunctionType
decl_stmt|;
comment|// the return type of the function that's currently being parsed
DECL|member|functionReturnsValue
name|bool
name|functionReturnsValue
decl_stmt|;
comment|// true if a non-void function has a return
DECL|member|checksPrecisionErrors
name|bool
name|checksPrecisionErrors
decl_stmt|;
comment|// true if an error will be generated when a variable is declared without precision, explicit or implicit.
DECL|member|HashErrMsg
name|TString
name|HashErrMsg
decl_stmt|;
DECL|member|AfterEOF
name|bool
name|AfterEOF
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
name|TSourceLoc
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
name|TSourceLoc
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
name|int
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
name|matSize
parameter_list|,
name|TMatrixFields
modifier|&
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|bool
name|reservedErrorCheck
parameter_list|(
name|int
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
name|int
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
name|int
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
name|int
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
name|int
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
name|int
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
name|int
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
name|int
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
name|int
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
name|int
name|line
parameter_list|,
name|TPublicType
name|type
parameter_list|)
function_decl|;
name|bool
name|arrayTypeErrorCheck
parameter_list|(
name|int
name|line
parameter_list|,
name|TPublicType
name|type
parameter_list|)
function_decl|;
name|bool
name|arrayErrorCheck
parameter_list|(
name|int
name|line
parameter_list|,
name|TString
modifier|&
name|identifier
parameter_list|,
name|TPublicType
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
name|int
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
name|int
parameter_list|,
specifier|const
name|TIntermTyped
modifier|*
parameter_list|)
function_decl|;
name|bool
name|boolErrorCheck
parameter_list|(
name|int
parameter_list|,
specifier|const
name|TPublicType
modifier|&
parameter_list|)
function_decl|;
name|bool
name|samplerErrorCheck
parameter_list|(
name|int
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
name|int
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
name|int
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
name|int
name|line
parameter_list|,
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
name|int
name|line
parameter_list|,
name|TString
modifier|&
name|identifier
parameter_list|,
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
name|int
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
name|int
name|line
parameter_list|,
specifier|const
name|TString
modifier|&
parameter_list|)
function_decl|;
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
name|void
name|handleExtensionDirective
parameter_list|(
name|int
name|line
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
name|void
name|handlePragmaDirective
parameter_list|(
name|int
name|line
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
name|int
name|line
parameter_list|,
name|TFunction
modifier|*
name|pfnCall
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
name|TSourceLoc
name|line
parameter_list|,
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
name|bool
name|arraySetMaxSize
parameter_list|(
name|TIntermSymbol
modifier|*
parameter_list|,
name|TType
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|,
name|TSourceLoc
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addConstructor
parameter_list|(
name|TIntermNode
modifier|*
parameter_list|,
specifier|const
name|TType
modifier|*
parameter_list|,
name|TOperator
parameter_list|,
name|TFunction
modifier|*
parameter_list|,
name|TSourceLoc
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
name|constructStruct
parameter_list|(
name|TIntermNode
modifier|*
parameter_list|,
name|TType
modifier|*
parameter_list|,
name|int
parameter_list|,
name|TSourceLoc
parameter_list|,
name|bool
name|subset
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|constructBuiltIn
parameter_list|(
specifier|const
name|TType
modifier|*
parameter_list|,
name|TOperator
parameter_list|,
name|TIntermNode
modifier|*
parameter_list|,
name|TSourceLoc
parameter_list|,
name|bool
name|subset
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
name|TSourceLoc
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
name|TSourceLoc
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
name|TSourceLoc
name|line
parameter_list|)
function_decl|;
name|TIntermTyped
modifier|*
name|addConstStruct
parameter_list|(
name|TString
modifier|&
parameter_list|,
name|TIntermTyped
modifier|*
parameter_list|,
name|TSourceLoc
parameter_list|)
function_decl|;
comment|// Performs an error check for embedded struct declarations.
comment|// Returns true if an error was raised due to the declaration of
comment|// this struct.
name|bool
name|enterStructDeclaration
parameter_list|(
name|TSourceLoc
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
name|TSourceLoc
name|line
parameter_list|,
specifier|const
name|TType
modifier|&
name|fieldType
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_function_decl
name|int
name|PaParseStrings
parameter_list|(
name|int
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
comment|// _PARSER_HELPER_INCLUDED_
end_comment
end_unit
