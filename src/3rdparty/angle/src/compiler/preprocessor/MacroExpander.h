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
name|COMPILER_PREPROCESSOR_MACRO_EXPANDER_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_MACRO_EXPANDER_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_MACRO_EXPANDER_H_
end_define
begin_include
include|#
directive|include
file|<cassert>
end_include
begin_include
include|#
directive|include
file|<memory>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|"Lexer.h"
end_include
begin_include
include|#
directive|include
file|"Macro.h"
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
name|MacroExpander
range|:
name|public
name|Lexer
block|{
name|public
operator|:
name|MacroExpander
argument_list|(
name|Lexer
operator|*
name|lexer
argument_list|,
name|MacroSet
operator|*
name|macroSet
argument_list|,
name|Diagnostics
operator|*
name|diagnostics
argument_list|)
block|;
name|virtual
operator|~
name|MacroExpander
argument_list|()
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
name|MacroExpander
argument_list|)
block|;
name|void
name|getToken
argument_list|(
name|Token
operator|*
name|token
argument_list|)
block|;
name|void
name|ungetToken
argument_list|(
specifier|const
name|Token
operator|&
name|token
argument_list|)
block|;
name|bool
name|isNextTokenLeftParen
argument_list|()
block|;
name|bool
name|pushMacro
argument_list|(
specifier|const
name|Macro
operator|&
name|macro
argument_list|,
specifier|const
name|Token
operator|&
name|identifier
argument_list|)
block|;
name|void
name|popMacro
argument_list|()
block|;
name|bool
name|expandMacro
argument_list|(
specifier|const
name|Macro
operator|&
name|macro
argument_list|,
specifier|const
name|Token
operator|&
name|identifier
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Token
operator|>
operator|*
name|replacements
argument_list|)
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Token
operator|>
name|MacroArg
expr_stmt|;
name|bool
name|collectMacroArgs
argument_list|(
specifier|const
name|Macro
operator|&
name|macro
argument_list|,
specifier|const
name|Token
operator|&
name|identifier
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MacroArg
operator|>
operator|*
name|args
argument_list|)
decl_stmt|;
name|void
name|replaceMacroParams
argument_list|(
specifier|const
name|Macro
operator|&
name|macro
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|MacroArg
operator|>
operator|&
name|args
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Token
operator|>
operator|*
name|replacements
argument_list|)
decl_stmt|;
struct|struct
name|MacroContext
block|{
specifier|const
name|Macro
modifier|*
name|macro
decl_stmt|;
name|std
operator|::
name|size_t
name|index
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Token
operator|>
name|replacements
expr_stmt|;
name|MacroContext
argument_list|()
operator|:
name|macro
argument_list|(
literal|0
argument_list|)
operator|,
name|index
argument_list|(
literal|0
argument_list|)
block|{         }
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|index
operator|==
name|replacements
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|Token
modifier|&
name|get
parameter_list|()
block|{
return|return
name|replacements
index|[
name|index
operator|++
index|]
return|;
block|}
name|void
name|unget
parameter_list|()
block|{
name|assert
argument_list|(
name|index
operator|>
literal|0
argument_list|)
expr_stmt|;
operator|--
name|index
expr_stmt|;
block|}
block|}
struct|;
name|Lexer
modifier|*
name|mLexer
decl_stmt|;
name|MacroSet
modifier|*
name|mMacroSet
decl_stmt|;
name|Diagnostics
modifier|*
name|mDiagnostics
decl_stmt|;
name|std
operator|::
name|auto_ptr
operator|<
name|Token
operator|>
name|mReserveToken
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|MacroContext
operator|*
operator|>
name|mContextStack
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
unit|}
comment|// namespace pp
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_PREPROCESSOR_MACRO_EXPANDER_H_
end_comment
end_unit
