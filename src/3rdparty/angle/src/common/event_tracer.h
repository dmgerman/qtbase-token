begin_unit
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_EVENT_TRACER_H_
end_ifndef
begin_define
DECL|macro|COMMON_EVENT_TRACER_H_
define|#
directive|define
name|COMMON_EVENT_TRACER_H_
end_define
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_include
include|#
directive|include
file|"platform/Platform.h"
end_include
begin_decl_stmt
name|namespace
name|angle
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|GetTraceCategoryEnabledFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|Platform
operator|::
name|TraceEventHandle
name|AddTraceEvent
argument_list|(
argument|char phase
argument_list|,
argument|const unsigned char* categoryGroupEnabled
argument_list|,
argument|const char* name
argument_list|,
argument|unsigned long long id
argument_list|,
argument|int numArgs
argument_list|,
argument|const char** argNames
argument_list|,
argument|const unsigned char* argTypes
argument_list|,
argument|const unsigned long long* argValues
argument_list|,
argument|unsigned char flags
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMMON_EVENT_TRACER_H_
end_comment
end_unit
