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
name|COMPILER_PRAGMA_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PRAGMA_H_
define|#
directive|define
name|COMPILER_PRAGMA_H_
end_define
begin_struct
DECL|struct|TPragma
struct|struct
name|TPragma
block|{
comment|// By default optimization is turned on and debug is turned off.
DECL|function|TPragma
name|TPragma
argument_list|()
operator|:
name|optimize
argument_list|(
name|true
argument_list|)
operator|,
name|debug
argument_list|(
argument|false
argument_list|)
block|{ }
DECL|function|TPragma
name|TPragma
argument_list|(
argument|bool o
argument_list|,
argument|bool d
argument_list|)
operator|:
name|optimize
argument_list|(
name|o
argument_list|)
operator|,
name|debug
argument_list|(
argument|d
argument_list|)
block|{ }
DECL|member|optimize
name|bool
name|optimize
expr_stmt|;
DECL|member|debug
name|bool
name|debug
decl_stmt|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_PRAGMA_H_
end_comment
end_unit
