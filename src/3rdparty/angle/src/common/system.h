begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// system.h: Includes Windows system headers and undefines macros that conflict.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_SYSTEM_H
end_ifndef
begin_define
DECL|macro|COMMON_SYSTEM_H
define|#
directive|define
name|COMMON_SYSTEM_H
end_define
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WIN32_LEAN_AND_MEAN
argument_list|)
end_if
begin_define
DECL|macro|WIN32_LEAN_AND_MEAN
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|min
argument_list|)
end_if
begin_undef
DECL|macro|min
undef|#
directive|undef
name|min
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|max
argument_list|)
end_if
begin_undef
DECL|macro|max
undef|#
directive|undef
name|max
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMMON_SYSTEM_H
end_comment
end_unit
