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
begin_comment
comment|// pp_utils.h: Common preprocessor utilities
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_PREPROCESSOR_PPUTILS_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_PPUTILS_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_PPUTILS_H_
end_define
begin_comment
comment|// A macro to disallow the copy constructor and operator= functions
end_comment
begin_comment
comment|// This must be used in the private: declarations for a class.
end_comment
begin_define
DECL|macro|PP_DISALLOW_COPY_AND_ASSIGN
define|#
directive|define
name|PP_DISALLOW_COPY_AND_ASSIGN
parameter_list|(
name|TypeName
parameter_list|)
define|\
value|TypeName(const TypeName&);               \   void operator=(const TypeName&)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_PREPROCESSOR_PPUTILS_H_
end_comment
end_unit
