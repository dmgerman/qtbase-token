begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011-2014 The ANGLE Project Authors. All rights reserved.
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
begin_comment
comment|//
end_comment
begin_comment
comment|// length_limits.h
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_LENGTHLIMITS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_LENGTHLIMITS_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_LENGTHLIMITS_H_
end_define
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_comment
comment|// These constants are factored out from the rest of the headers to
end_comment
begin_comment
comment|// make it easier to reference them from the compiler sources.
end_comment
begin_function_decl
name|size_t
name|GetGlobalMaxTokenSize
parameter_list|(
name|ShShaderSpec
name|spec
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_LENGTHLIMITS_H_
end_comment
end_unit
