begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_PREPROCESSOR_DIAGNOSTICSBASE_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_DIAGNOSTICSBASE_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_DIAGNOSTICSBASE_H_
end_define
begin_include
include|#
directive|include
file|<string>
end_include
begin_decl_stmt
name|namespace
name|pp
block|{
struct_decl|struct
name|SourceLocation
struct_decl|;
comment|// Base class for reporting diagnostic messages.
comment|// Derived classes are responsible for formatting and printing the messages.
name|class
name|Diagnostics
block|{
name|public
label|:
enum|enum
name|Severity
block|{
name|PP_ERROR
block|,
name|PP_WARNING
block|}
enum|;
enum|enum
name|ID
block|{
name|PP_ERROR_BEGIN
block|,
name|PP_INTERNAL_ERROR
block|,
name|PP_OUT_OF_MEMORY
block|,
name|PP_INVALID_CHARACTER
block|,
name|PP_INVALID_NUMBER
block|,
name|PP_INTEGER_OVERFLOW
block|,
name|PP_FLOAT_OVERFLOW
block|,
name|PP_TOKEN_TOO_LONG
block|,
name|PP_INVALID_EXPRESSION
block|,
name|PP_DIVISION_BY_ZERO
block|,
name|PP_EOF_IN_COMMENT
block|,
name|PP_UNEXPECTED_TOKEN
block|,
name|PP_DIRECTIVE_INVALID_NAME
block|,
name|PP_MACRO_NAME_RESERVED
block|,
name|PP_MACRO_REDEFINED
block|,
name|PP_MACRO_PREDEFINED_REDEFINED
block|,
name|PP_MACRO_PREDEFINED_UNDEFINED
block|,
name|PP_MACRO_UNTERMINATED_INVOCATION
block|,
name|PP_MACRO_TOO_FEW_ARGS
block|,
name|PP_MACRO_TOO_MANY_ARGS
block|,
name|PP_MACRO_DUPLICATE_PARAMETER_NAMES
block|,
name|PP_CONDITIONAL_ENDIF_WITHOUT_IF
block|,
name|PP_CONDITIONAL_ELSE_WITHOUT_IF
block|,
name|PP_CONDITIONAL_ELSE_AFTER_ELSE
block|,
name|PP_CONDITIONAL_ELIF_WITHOUT_IF
block|,
name|PP_CONDITIONAL_ELIF_AFTER_ELSE
block|,
name|PP_CONDITIONAL_UNTERMINATED
block|,
name|PP_CONDITIONAL_UNEXPECTED_TOKEN
block|,
name|PP_INVALID_EXTENSION_NAME
block|,
name|PP_INVALID_EXTENSION_BEHAVIOR
block|,
name|PP_INVALID_EXTENSION_DIRECTIVE
block|,
name|PP_INVALID_VERSION_NUMBER
block|,
name|PP_INVALID_VERSION_DIRECTIVE
block|,
name|PP_VERSION_NOT_FIRST_STATEMENT
block|,
name|PP_VERSION_NOT_FIRST_LINE_ESSL3
block|,
name|PP_INVALID_LINE_NUMBER
block|,
name|PP_INVALID_FILE_NUMBER
block|,
name|PP_INVALID_LINE_DIRECTIVE
block|,
name|PP_NON_PP_TOKEN_BEFORE_EXTENSION_ESSL3
block|,
name|PP_ERROR_END
block|,
name|PP_WARNING_BEGIN
block|,
name|PP_EOF_IN_DIRECTIVE
block|,
name|PP_UNRECOGNIZED_PRAGMA
block|,
name|PP_NON_PP_TOKEN_BEFORE_EXTENSION_ESSL1
block|,
name|PP_WARNING_MACRO_NAME_RESERVED
block|,
name|PP_WARNING_END
block|}
enum|;
name|virtual
operator|~
name|Diagnostics
argument_list|()
expr_stmt|;
name|void
name|report
argument_list|(
name|ID
name|id
argument_list|,
specifier|const
name|SourceLocation
operator|&
name|loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|text
argument_list|)
decl_stmt|;
name|protected
label|:
name|Severity
name|severity
parameter_list|(
name|ID
name|id
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|message
argument_list|(
argument|ID id
argument_list|)
expr_stmt|;
name|virtual
name|void
name|print
argument_list|(
name|ID
name|id
argument_list|,
specifier|const
name|SourceLocation
operator|&
name|loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|text
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace pp
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_PREPROCESSOR_DIAGNOSTICSBASE_H_
end_comment
end_unit
