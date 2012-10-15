begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_PREPROCESSOR_PREPROCESSOR_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_PREPROCESSOR_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_PREPROCESSOR_H_
end_define
begin_include
include|#
directive|include
file|"pp_utils.h"
end_include
begin_decl_stmt
name|namespace
name|pp
block|{
name|class
name|Diagnostics
decl_stmt|;
name|class
name|DirectiveHandler
decl_stmt|;
struct_decl|struct
name|PreprocessorImpl
struct_decl|;
struct_decl|struct
name|Token
struct_decl|;
name|class
name|Preprocessor
block|{
name|public
label|:
name|Preprocessor
argument_list|(
name|Diagnostics
operator|*
name|diagnostics
argument_list|,
name|DirectiveHandler
operator|*
name|directiveHandler
argument_list|)
expr_stmt|;
operator|~
name|Preprocessor
argument_list|()
expr_stmt|;
comment|// count: specifies the number of elements in the string and length arrays.
comment|// string: specifies an array of pointers to strings.
comment|// length: specifies an array of string lengths.
comment|// If length is NULL, each string is assumed to be null terminated.
comment|// If length is a value other than NULL, it points to an array containing
comment|// a string length for each of the corresponding elements of string.
comment|// Each element in the length array may contain the length of the
comment|// corresponding string or a value less than 0 to indicate that the string
comment|// is null terminated.
name|bool
name|init
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
parameter_list|)
function_decl|;
comment|// Adds a pre-defined macro.
name|void
name|predefineMacro
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
name|void
name|lex
parameter_list|(
name|Token
modifier|*
name|token
parameter_list|)
function_decl|;
name|private
label|:
name|PP_DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Preprocessor
argument_list|)
expr_stmt|;
name|PreprocessorImpl
modifier|*
name|mImpl
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
comment|// COMPILER_PREPROCESSOR_PREPROCESSOR_H_
end_comment
end_unit
