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
begin_include
include|#
directive|include
file|"Diagnostics.h"
end_include
begin_include
include|#
directive|include
file|<cassert>
end_include
begin_namespace
DECL|namespace|pp
namespace|namespace
name|pp
block|{
DECL|function|~Diagnostics
name|Diagnostics
operator|::
name|~
name|Diagnostics
parameter_list|()
block|{ }
DECL|function|report
name|void
name|Diagnostics
operator|::
name|report
parameter_list|(
name|ID
name|id
parameter_list|,
specifier|const
name|SourceLocation
modifier|&
name|loc
parameter_list|,
specifier|const
name|std
operator|::
name|string
modifier|&
name|text
parameter_list|)
block|{
comment|// TODO(alokp): Keep a count of errors and warnings.
name|print
argument_list|(
name|id
argument_list|,
name|loc
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
DECL|function|severity
name|Diagnostics
operator|::
name|Severity
name|Diagnostics
operator|::
name|severity
parameter_list|(
name|ID
name|id
parameter_list|)
block|{
if|if
condition|(
operator|(
name|id
operator|>
name|ERROR_BEGIN
operator|)
operator|&&
operator|(
name|id
operator|<
name|ERROR_END
operator|)
condition|)
return|return
name|ERROR
return|;
if|if
condition|(
operator|(
name|id
operator|>
name|WARNING_BEGIN
operator|)
operator|&&
operator|(
name|id
operator|<
name|WARNING_END
operator|)
condition|)
return|return
name|WARNING
return|;
name|assert
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
name|ERROR
return|;
block|}
DECL|function|message
name|std
operator|::
name|string
name|Diagnostics
operator|::
name|message
parameter_list|(
name|ID
name|id
parameter_list|)
block|{
switch|switch
condition|(
name|id
condition|)
block|{
comment|// Errors begin.
case|case
name|INTERNAL_ERROR
case|:
return|return
literal|"internal error"
return|;
case|case
name|OUT_OF_MEMORY
case|:
return|return
literal|"out of memory"
return|;
case|case
name|INVALID_CHARACTER
case|:
return|return
literal|"invalid character"
return|;
case|case
name|INVALID_NUMBER
case|:
return|return
literal|"invalid number"
return|;
case|case
name|INTEGER_OVERFLOW
case|:
return|return
literal|"integer overflow"
return|;
case|case
name|FLOAT_OVERFLOW
case|:
return|return
literal|"float overflow"
return|;
case|case
name|TOKEN_TOO_LONG
case|:
return|return
literal|"token too long"
return|;
case|case
name|INVALID_EXPRESSION
case|:
return|return
literal|"invalid expression"
return|;
case|case
name|DIVISION_BY_ZERO
case|:
return|return
literal|"division by zero"
return|;
case|case
name|EOF_IN_COMMENT
case|:
return|return
literal|"unexpected end of file found in comment"
return|;
case|case
name|UNEXPECTED_TOKEN
case|:
return|return
literal|"unexpected token"
return|;
case|case
name|DIRECTIVE_INVALID_NAME
case|:
return|return
literal|"invalid directive name"
return|;
case|case
name|MACRO_NAME_RESERVED
case|:
return|return
literal|"macro name is reserved"
return|;
case|case
name|MACRO_REDEFINED
case|:
return|return
literal|"macro redefined"
return|;
case|case
name|MACRO_PREDEFINED_REDEFINED
case|:
return|return
literal|"predefined macro redefined"
return|;
case|case
name|MACRO_PREDEFINED_UNDEFINED
case|:
return|return
literal|"predefined macro undefined"
return|;
case|case
name|MACRO_UNTERMINATED_INVOCATION
case|:
return|return
literal|"unterminated macro invocation"
return|;
case|case
name|MACRO_TOO_FEW_ARGS
case|:
return|return
literal|"Not enough arguments for macro"
return|;
case|case
name|MACRO_TOO_MANY_ARGS
case|:
return|return
literal|"Too many arguments for macro"
return|;
case|case
name|CONDITIONAL_ENDIF_WITHOUT_IF
case|:
return|return
literal|"unexpected #endif found without a matching #if"
return|;
case|case
name|CONDITIONAL_ELSE_WITHOUT_IF
case|:
return|return
literal|"unexpected #else found without a matching #if"
return|;
case|case
name|CONDITIONAL_ELSE_AFTER_ELSE
case|:
return|return
literal|"unexpected #else found after another #else"
return|;
case|case
name|CONDITIONAL_ELIF_WITHOUT_IF
case|:
return|return
literal|"unexpected #elif found without a matching #if"
return|;
case|case
name|CONDITIONAL_ELIF_AFTER_ELSE
case|:
return|return
literal|"unexpected #elif found after #else"
return|;
case|case
name|CONDITIONAL_UNTERMINATED
case|:
return|return
literal|"unexpected end of file found in conditional block"
return|;
case|case
name|INVALID_EXTENSION_NAME
case|:
return|return
literal|"invalid extension name"
return|;
case|case
name|INVALID_EXTENSION_BEHAVIOR
case|:
return|return
literal|"invalid extension behavior"
return|;
case|case
name|INVALID_EXTENSION_DIRECTIVE
case|:
return|return
literal|"invalid extension directive"
return|;
case|case
name|INVALID_VERSION_NUMBER
case|:
return|return
literal|"invalid version number"
return|;
case|case
name|INVALID_VERSION_DIRECTIVE
case|:
return|return
literal|"invalid version directive"
return|;
case|case
name|VERSION_NOT_FIRST_STATEMENT
case|:
return|return
literal|"#version directive must occur before anything else, "
literal|"except for comments and white space"
return|;
case|case
name|INVALID_LINE_NUMBER
case|:
return|return
literal|"invalid line number"
return|;
case|case
name|INVALID_FILE_NUMBER
case|:
return|return
literal|"invalid file number"
return|;
case|case
name|INVALID_LINE_DIRECTIVE
case|:
return|return
literal|"invalid line directive"
return|;
comment|// Errors end.
comment|// Warnings begin.
case|case
name|EOF_IN_DIRECTIVE
case|:
return|return
literal|"unexpected end of file found in directive"
return|;
case|case
name|CONDITIONAL_UNEXPECTED_TOKEN
case|:
return|return
literal|"unexpected token after conditional expression"
return|;
case|case
name|UNRECOGNIZED_PRAGMA
case|:
return|return
literal|"unrecognized pragma"
return|;
comment|// Warnings end.
default|default:
name|assert
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
literal|""
return|;
block|}
block|}
block|}
end_namespace
begin_comment
comment|// namespace pp
end_comment
end_unit
