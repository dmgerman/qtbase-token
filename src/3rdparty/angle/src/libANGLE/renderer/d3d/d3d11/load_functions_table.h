begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2015 The ANGLE Project Authors. All rights reserved.
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
comment|// load_functions_table:
end_comment
begin_comment
comment|//   Contains load functions table depending on internal format and dxgi format
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D11_LOADFUNCTIONSTABLE_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_LOADFUNCTIONSTABLE_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_LOADFUNCTIONSTABLE_H_
end_define
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/texture_format_table.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|namespace
name|d3d11
block|{
specifier|const
name|std
operator|::
name|map
operator|<
name|GLenum
operator|,
name|LoadImageFunctionInfo
operator|>
operator|&
name|GetLoadFunctionsMap
argument_list|(
argument|GLenum internalFormat
argument_list|,
argument|DXGI_FORMAT dxgiFormat
argument_list|)
expr_stmt|;
block|}
comment|// namespace d3d11
block|}
end_decl_stmt
begin_comment
comment|// namespace rx
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D11_LOADFUNCTIONSTABLE_H_
end_comment
end_unit
