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
comment|// internal_format_initializer_table:
end_comment
begin_comment
comment|//   Contains table to go from internal format and dxgi format to initializer function
end_comment
begin_comment
comment|//   for TextureFormat
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D11_INTERNALFORMATINITIALIZERTABLE_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_INTERNALFORMATINITIALIZERTABLE_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_INTERNALFORMATINITIALIZERTABLE_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|namespace
name|d3d11
block|{
name|InitializeTextureDataFunction
name|GetInternalFormatInitializer
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
name|DXGI_FORMAT
name|dxgiFormat
parameter_list|)
function_decl|;
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
comment|// LIBANGLE_RENDERER_D3D_D3D11_INTERNALFORMATINITIALIZERTABLE_H_
end_comment
end_unit
