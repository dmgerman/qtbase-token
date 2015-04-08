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
name|COMPILER_TRANSLATOR_PRAGMA_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_PRAGMA_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_PRAGMA_H_
end_define
begin_struct
DECL|struct|TPragma
struct|struct
name|TPragma
block|{
DECL|struct|STDGL
struct|struct
name|STDGL
block|{
DECL|function|STDGL
name|STDGL
argument_list|()
operator|:
name|invariantAll
argument_list|(
argument|false
argument_list|)
block|{ }
DECL|member|invariantAll
name|bool
name|invariantAll
expr_stmt|;
block|}
struct|;
comment|// By default optimization is turned on and debug is turned off.
comment|// Precision emulation is turned on by default, but has no effect unless
comment|// the extension is enabled.
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
name|false
argument_list|)
operator|,
name|debugShaderPrecision
argument_list|(
argument|true
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
name|d
argument_list|)
operator|,
name|debugShaderPrecision
argument_list|(
argument|true
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
DECL|member|debugShaderPrecision
name|bool
name|debugShaderPrecision
decl_stmt|;
DECL|member|stdgl
name|STDGL
name|stdgl
decl_stmt|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_PRAGMA_H_
end_comment
end_unit
