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
comment|// angleutils.h: Common ANGLE utilities.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_ANGLEUTILS_H_
end_ifndef
begin_define
DECL|macro|COMMON_ANGLEUTILS_H_
define|#
directive|define
name|COMMON_ANGLEUTILS_H_
end_define
begin_include
include|#
directive|include
file|<stddef.h>
end_include
begin_comment
comment|// A macro to disallow the copy constructor and operator= functions
end_comment
begin_comment
comment|// This must be used in the private: declarations for a class
end_comment
begin_define
DECL|macro|DISALLOW_COPY_AND_ASSIGN
define|#
directive|define
name|DISALLOW_COPY_AND_ASSIGN
parameter_list|(
name|TypeName
parameter_list|)
define|\
value|TypeName(const TypeName&);               \   void operator=(const TypeName&)
end_define
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
name|int
name|N
operator|>
specifier|inline
name|unsigned
name|int
name|ArraySize
argument_list|(
argument|T(&)[N]
argument_list|)
block|{
return|return
name|N
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
name|int
name|N
operator|>
name|void
name|SafeRelease
argument_list|(
argument|T (&resourceBlock)[N]
argument_list|)
block|{
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|N
condition|;
name|i
operator|++
control|)
block|{
name|SafeRelease
argument_list|(
name|resourceBlock
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|SafeRelease
name|void
name|SafeRelease
argument_list|(
argument|T& resource
argument_list|)
block|{
if|if
condition|(
name|resource
condition|)
block|{
name|resource
operator|->
name|Release
argument_list|()
expr_stmt|;
name|resource
operator|=
name|NULL
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|SafeDelete
name|void
name|SafeDelete
argument_list|(
argument|T*& resource
argument_list|)
block|{
name|delete
name|resource
block|;
name|resource
operator|=
name|NULL
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|SafeDeleteArray
name|void
name|SafeDeleteArray
argument_list|(
argument|T*& resource
argument_list|)
block|{
name|delete
index|[]
name|resource
block|;
name|resource
operator|=
name|NULL
block|; }
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1900
end_if
begin_define
DECL|macro|snprintf
define|#
directive|define
name|snprintf
value|_snprintf
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|VENDOR_ID_AMD
define|#
directive|define
name|VENDOR_ID_AMD
value|0x1002
end_define
begin_define
DECL|macro|VENDOR_ID_INTEL
define|#
directive|define
name|VENDOR_ID_INTEL
value|0x8086
end_define
begin_define
DECL|macro|VENDOR_ID_NVIDIA
define|#
directive|define
name|VENDOR_ID_NVIDIA
value|0x10DE
end_define
begin_define
DECL|macro|GL_BGRA4_ANGLEX
define|#
directive|define
name|GL_BGRA4_ANGLEX
value|0x6ABC
end_define
begin_define
DECL|macro|GL_BGR5_A1_ANGLEX
define|#
directive|define
name|GL_BGR5_A1_ANGLEX
value|0x6ABD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMMON_ANGLEUTILS_H_
end_comment
end_unit
