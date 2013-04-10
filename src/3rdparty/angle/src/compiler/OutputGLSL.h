begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2011 The ANGLE Project Authors. All rights reserved.
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
name|CROSSCOMPILERGLSL_OUTPUTGLSL_H_
end_ifndef
begin_define
DECL|macro|CROSSCOMPILERGLSL_OUTPUTGLSL_H_
define|#
directive|define
name|CROSSCOMPILERGLSL_OUTPUTGLSL_H_
end_define
begin_include
include|#
directive|include
file|"compiler/OutputGLSLBase.h"
end_include
begin_decl_stmt
name|class
name|TOutputGLSL
range|:
name|public
name|TOutputGLSLBase
block|{
name|public
operator|:
name|TOutputGLSL
argument_list|(
argument|TInfoSinkBase& objSink
argument_list|,
argument|ShArrayIndexClampingStrategy clampingStrategy
argument_list|,
argument|ShHashFunction64 hashFunction
argument_list|,
argument|NameMap& nameMap
argument_list|,
argument|TSymbolTable& symbolTable
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|writeVariablePrecision
argument_list|(
name|TPrecision
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CROSSCOMPILERGLSL_OUTPUTGLSL_H_
end_comment
end_unit
