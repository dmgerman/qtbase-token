begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2014 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_PREPROCESSOR_TOKENIZER_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_TOKENIZER_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_TOKENIZER_H_
end_define
begin_include
include|#
directive|include
file|"Input.h"
end_include
begin_include
include|#
directive|include
file|"Lexer.h"
end_include
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
name|Tokenizer
range|:
name|public
name|Lexer
block|{
name|public
operator|:
expr|struct
name|Context
block|{
name|Diagnostics
operator|*
name|diagnostics
block|;
name|Input
name|input
block|;
comment|// The location where yytext points to. Token location should track
comment|// scanLoc instead of Input::mReadLoc because they may not be the same
comment|// if text is buffered up in the scanner input buffer.
name|Input
operator|::
name|Location
name|scanLoc
block|;
name|bool
name|leadingSpace
block|;
name|bool
name|lineStart
block|;     }
block|;
name|Tokenizer
argument_list|(
name|Diagnostics
operator|*
name|diagnostics
argument_list|)
block|;
operator|~
name|Tokenizer
argument_list|()
block|;
name|bool
name|init
argument_list|(
argument|size_t count
argument_list|,
argument|const char * const string[]
argument_list|,
argument|const int length[]
argument_list|)
block|;
name|void
name|setFileNumber
argument_list|(
argument|int file
argument_list|)
block|;
name|void
name|setLineNumber
argument_list|(
argument|int line
argument_list|)
block|;
name|void
name|setMaxTokenSize
argument_list|(
argument|size_t maxTokenSize
argument_list|)
block|;
name|virtual
name|void
name|lex
argument_list|(
name|Token
operator|*
name|token
argument_list|)
block|;
name|private
operator|:
name|PP_DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Tokenizer
argument_list|)
block|;
name|bool
name|initScanner
argument_list|()
block|;
name|void
name|destroyScanner
argument_list|()
block|;
name|void
operator|*
name|mHandle
block|;
comment|// Scanner handle.
name|Context
name|mContext
block|;
comment|// Scanner extra.
name|size_t
name|mMaxTokenSize
block|;
comment|// Maximum token size
block|}
decl_stmt|;
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
comment|// COMPILER_PREPROCESSOR_TOKENIZER_H_
end_comment
end_unit
