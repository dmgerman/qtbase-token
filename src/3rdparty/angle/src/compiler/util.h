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
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// atof_dot is like atof but forcing C locale, i.e. forcing '.' as decimal point.
name|double
name|atof_dot
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_comment
comment|// end extern "C"
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_UTIL_H
end_comment
end_unit
