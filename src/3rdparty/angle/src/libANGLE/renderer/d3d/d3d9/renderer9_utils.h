begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// renderer9_utils.h: Conversion functions and other utility routines
end_comment
begin_comment
comment|// specific to the D3D9 renderer
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D9_RENDERER9UTILS_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D9_RENDERER9UTILS_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D9_RENDERER9UTILS_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Caps.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|FramebufferAttachment
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderTarget9
decl_stmt|;
struct_decl|struct
name|WorkaroundsD3D
struct_decl|;
name|namespace
name|gl_d3d9
block|{
name|D3DCMPFUNC
name|ConvertComparison
parameter_list|(
name|GLenum
name|comparison
parameter_list|)
function_decl|;
name|D3DCOLOR
name|ConvertColor
argument_list|(
name|gl
operator|::
name|ColorF
name|color
argument_list|)
decl_stmt|;
name|D3DBLEND
name|ConvertBlendFunc
parameter_list|(
name|GLenum
name|blend
parameter_list|)
function_decl|;
name|D3DBLENDOP
name|ConvertBlendOp
parameter_list|(
name|GLenum
name|blendOp
parameter_list|)
function_decl|;
name|D3DSTENCILOP
name|ConvertStencilOp
parameter_list|(
name|GLenum
name|stencilOp
parameter_list|)
function_decl|;
name|D3DTEXTUREADDRESS
name|ConvertTextureWrap
parameter_list|(
name|GLenum
name|wrap
parameter_list|)
function_decl|;
name|D3DCULL
name|ConvertCullMode
parameter_list|(
name|GLenum
name|cullFace
parameter_list|,
name|GLenum
name|frontFace
parameter_list|)
function_decl|;
name|D3DCUBEMAP_FACES
name|ConvertCubeFace
parameter_list|(
name|GLenum
name|cubeFace
parameter_list|)
function_decl|;
name|DWORD
name|ConvertColorMask
parameter_list|(
name|bool
name|red
parameter_list|,
name|bool
name|green
parameter_list|,
name|bool
name|blue
parameter_list|,
name|bool
name|alpha
parameter_list|)
function_decl|;
name|D3DTEXTUREFILTERTYPE
name|ConvertMagFilter
parameter_list|(
name|GLenum
name|magFilter
parameter_list|,
name|float
name|maxAnisotropy
parameter_list|)
function_decl|;
name|void
name|ConvertMinFilter
parameter_list|(
name|GLenum
name|minFilter
parameter_list|,
name|D3DTEXTUREFILTERTYPE
modifier|*
name|d3dMinFilter
parameter_list|,
name|D3DTEXTUREFILTERTYPE
modifier|*
name|d3dMipFilter
parameter_list|,
name|float
modifier|*
name|d3dLodBias
parameter_list|,
name|float
name|maxAnisotropy
parameter_list|,
name|size_t
name|baseLevel
parameter_list|)
function_decl|;
name|D3DMULTISAMPLE_TYPE
name|GetMultisampleType
parameter_list|(
name|GLuint
name|samples
parameter_list|)
function_decl|;
block|}
name|namespace
name|d3d9_gl
block|{
name|unsigned
name|int
name|GetReservedVertexUniformVectors
parameter_list|()
function_decl|;
name|unsigned
name|int
name|GetReservedFragmentUniformVectors
parameter_list|()
function_decl|;
name|GLsizei
name|GetSamplesCount
parameter_list|(
name|D3DMULTISAMPLE_TYPE
name|type
parameter_list|)
function_decl|;
name|bool
name|IsFormatChannelEquivalent
parameter_list|(
name|D3DFORMAT
name|d3dformat
parameter_list|,
name|GLenum
name|format
parameter_list|)
function_decl|;
name|void
name|GenerateCaps
argument_list|(
name|IDirect3D9
operator|*
name|d3d9
argument_list|,
name|IDirect3DDevice9
operator|*
name|device
argument_list|,
name|D3DDEVTYPE
name|deviceType
argument_list|,
name|UINT
name|adapter
argument_list|,
name|gl
operator|::
name|Caps
operator|*
name|caps
argument_list|,
name|gl
operator|::
name|TextureCapsMap
operator|*
name|textureCapsMap
argument_list|,
name|gl
operator|::
name|Extensions
operator|*
name|extensions
argument_list|,
name|gl
operator|::
name|Limitations
operator|*
name|limitations
argument_list|)
decl_stmt|;
block|}
name|namespace
name|d3d9
block|{
name|GLuint
name|ComputeBlockSize
parameter_list|(
name|D3DFORMAT
name|format
parameter_list|,
name|GLuint
name|width
parameter_list|,
name|GLuint
name|height
parameter_list|)
function_decl|;
name|void
name|MakeValidSize
parameter_list|(
name|bool
name|isImage
parameter_list|,
name|D3DFORMAT
name|format
parameter_list|,
name|GLsizei
modifier|*
name|requestWidth
parameter_list|,
name|GLsizei
modifier|*
name|requestHeight
parameter_list|,
name|int
modifier|*
name|levelOffset
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isDeviceLostError
parameter_list|(
name|HRESULT
name|errorCode
parameter_list|)
block|{
switch|switch
condition|(
name|errorCode
condition|)
block|{
case|case
name|D3DERR_DRIVERINTERNALERROR
case|:
case|case
name|D3DERR_DEVICELOST
case|:
case|case
name|D3DERR_DEVICEHUNG
case|:
case|case
name|D3DERR_DEVICEREMOVED
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
name|WorkaroundsD3D
name|GenerateWorkarounds
parameter_list|()
function_decl|;
block|}
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D9_RENDERER9UTILS_H_
end_comment
end_unit
