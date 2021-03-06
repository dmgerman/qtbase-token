begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_TRANSLATOR_TRANSLATORHLSL_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_TRANSLATORHLSL_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_TRANSLATORHLSL_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/Compiler.h"
end_include
begin_decl_stmt
name|class
name|TranslatorHLSL
range|:
name|public
name|TCompiler
block|{
name|public
operator|:
name|TranslatorHLSL
argument_list|(
argument|sh::GLenum type
argument_list|,
argument|ShShaderSpec spec
argument_list|,
argument|ShShaderOutput output
argument_list|)
block|;
name|TranslatorHLSL
operator|*
name|getAsTranslatorHLSL
argument_list|()
name|override
block|{
return|return
name|this
return|;
block|}
name|bool
name|hasInterfaceBlock
argument_list|(
argument|const std::string&interfaceBlockName
argument_list|)
specifier|const
block|;
name|unsigned
name|int
name|getInterfaceBlockRegister
argument_list|(
argument|const std::string&interfaceBlockName
argument_list|)
specifier|const
block|;
name|bool
name|hasUniform
argument_list|(
argument|const std::string&uniformName
argument_list|)
specifier|const
block|;
name|unsigned
name|int
name|getUniformRegister
argument_list|(
argument|const std::string&uniformName
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|void
name|translate
argument_list|(
argument|TIntermNode *root
argument_list|,
argument|int compileOptions
argument_list|)
name|override
block|;
comment|// collectVariables needs to be run always so registers can be assigned.
name|bool
name|shouldCollectVariables
argument_list|(
argument|int compileOptions
argument_list|)
name|override
block|{
return|return
name|true
return|;
block|}
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
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_TRANSLATORHLSL_H_
end_comment
end_unit
