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
begin_comment
comment|// debug.h: Debugging utilities.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_DEBUG_H_
end_ifndef
begin_define
DECL|macro|COMPILER_DEBUG_H_
define|#
directive|define
name|COMPILER_DEBUG_H_
end_define
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|_DEBUG
end_ifdef
begin_define
DECL|macro|TRACE_ENABLED
define|#
directive|define
name|TRACE_ENABLED
end_define
begin_comment
DECL|macro|TRACE_ENABLED
comment|// define to enable debug message tracing
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _DEBUG
end_comment
begin_comment
comment|// Outputs text to the debug log
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|TRACE_ENABLED
end_ifdef
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
comment|// __cplusplus
name|void
name|Trace
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __cplusplus
end_comment
begin_else
else|#
directive|else
end_else
begin_comment
comment|// TRACE_ENABLED
end_comment
begin_define
DECL|macro|Trace
define|#
directive|define
name|Trace
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TRACE_ENABLED
end_comment
begin_comment
comment|// A macro asserting a condition and outputting failures to the debug log
end_comment
begin_define
DECL|macro|ASSERT
define|#
directive|define
name|ASSERT
parameter_list|(
name|expression
parameter_list|)
value|do { \     if(!(expression)) \         Trace("Assert failed: %s(%d): "#expression"\n", __FUNCTION__, __LINE__); \     assert(expression); \ } while(0)
end_define
begin_define
DECL|macro|UNIMPLEMENTED
define|#
directive|define
name|UNIMPLEMENTED
parameter_list|()
value|do { \     Trace("Unimplemented invoked: %s(%d)\n", __FUNCTION__, __LINE__); \     assert(false); \ } while(0)
end_define
begin_define
DECL|macro|UNREACHABLE
define|#
directive|define
name|UNREACHABLE
parameter_list|()
value|do { \     Trace("Unreachable reached: %s(%d)\n", __FUNCTION__, __LINE__); \     assert(false); \ } while(0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_DEBUG_H_
end_comment
end_unit
