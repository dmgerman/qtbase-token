begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_UTIL_H
end_ifndef
begin_define
DECL|macro|COMPILER_UTIL_H
define|#
directive|define
name|COMPILER_UTIL_H
end_define
begin_comment
comment|// atof_clamp is like atof but
end_comment
begin_comment
comment|//   1. it forces C locale, i.e. forcing '.' as decimal point.
end_comment
begin_comment
comment|//   2. it clamps the value to -FLT_MAX or FLT_MAX if overflow happens.
end_comment
begin_comment
comment|// Return false if overflow happens.
end_comment
begin_function_decl
specifier|extern
name|bool
name|atof_clamp
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|float
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// If overflow happens, clamp the value to INT_MIN or INT_MAX.
end_comment
begin_comment
comment|// Return false if overflow happens.
end_comment
begin_function_decl
specifier|extern
name|bool
name|atoi_clamp
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_UTIL_H
end_comment
end_unit
