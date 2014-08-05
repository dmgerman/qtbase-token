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
name|COMPILER_PREPROCESSOR_MACRO_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_MACRO_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_MACRO_H_
end_define
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_decl_stmt
name|namespace
name|pp
block|{
struct_decl|struct
name|Token
struct_decl|;
struct|struct
name|Macro
block|{
enum|enum
name|Type
block|{
name|kTypeObj
block|,
name|kTypeFunc
block|}
enum|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Parameters
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Token
operator|>
name|Replacements
expr_stmt|;
name|Macro
argument_list|()
operator|:
name|predefined
argument_list|(
name|false
argument_list|)
operator|,
name|disabled
argument_list|(
name|false
argument_list|)
operator|,
name|type
argument_list|(
argument|kTypeObj
argument_list|)
block|{     }
name|bool
name|equals
argument_list|(
argument|const Macro&other
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|predefined
decl_stmt|;
name|mutable
name|bool
name|disabled
decl_stmt|;
name|Type
name|type
decl_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
name|Parameters
name|parameters
decl_stmt|;
name|Replacements
name|replacements
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|Macro
operator|>
name|MacroSet
expr_stmt|;
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
comment|// COMPILER_PREPROCESSOR_MACRO_H_
end_comment
end_unit
