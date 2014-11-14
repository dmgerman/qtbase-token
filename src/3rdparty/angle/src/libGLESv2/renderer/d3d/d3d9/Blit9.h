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
comment|// Blit9.cpp: Surface copy utility class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_BLIT9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_BLIT9_H_
define|#
directive|define
name|LIBGLESV2_BLIT9_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Error.h"
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Framebuffer
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
name|class
name|TextureStorage
decl_stmt|;
name|class
name|Blit9
block|{
name|public
label|:
name|explicit
name|Blit9
parameter_list|(
name|Renderer9
modifier|*
name|renderer
parameter_list|)
function_decl|;
operator|~
name|Blit9
argument_list|()
expr_stmt|;
name|gl
operator|::
name|Error
name|initialize
argument_list|()
expr_stmt|;
comment|// Copy from source surface to dest surface.
comment|// sourceRect, xoffset, yoffset are in D3D coordinates (0,0 in upper-left)
name|gl
operator|::
name|Error
name|copy2D
argument_list|(
argument|gl::Framebuffer *framebuffer
argument_list|,
argument|const RECT&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLint level
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|copyCube
argument_list|(
argument|gl::Framebuffer *framebuffer
argument_list|,
argument|const RECT&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
expr_stmt|;
comment|// Copy from source surface to dest surface.
comment|// sourceRect, xoffset, yoffset are in D3D coordinates (0,0 in upper-left)
comment|// source is interpreted as RGBA and destFormat specifies the desired result format. For example, if destFormat = GL_RGB, the alpha channel will be forced to 0.
name|gl
operator|::
name|Error
name|formatConvert
argument_list|(
argument|IDirect3DSurface9 *source
argument_list|,
argument|const RECT&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|IDirect3DSurface9 *dest
argument_list|)
expr_stmt|;
comment|// 2x2 box filter sample from source to dest.
comment|// Requires that source is RGB(A) and dest has the same format as source.
name|gl
operator|::
name|Error
name|boxFilter
argument_list|(
name|IDirect3DSurface9
operator|*
name|source
argument_list|,
name|IDirect3DSurface9
operator|*
name|dest
argument_list|)
expr_stmt|;
name|private
label|:
name|Renderer9
modifier|*
name|mRenderer
decl_stmt|;
name|bool
name|mGeometryLoaded
decl_stmt|;
name|IDirect3DVertexBuffer9
modifier|*
name|mQuadVertexBuffer
decl_stmt|;
name|IDirect3DVertexDeclaration9
modifier|*
name|mQuadVertexDeclaration
decl_stmt|;
name|gl
operator|::
name|Error
name|setFormatConvertShaders
argument_list|(
argument|GLenum destFormat
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|copy
argument_list|(
argument|IDirect3DSurface9 *source
argument_list|,
argument|const RECT&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|IDirect3DSurface9 *dest
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|copySurfaceToTexture
argument_list|(
name|IDirect3DSurface9
operator|*
name|surface
argument_list|,
specifier|const
name|RECT
operator|&
name|sourceRect
argument_list|,
name|IDirect3DTexture9
operator|*
operator|*
name|outTexture
argument_list|)
expr_stmt|;
name|void
name|setViewport
parameter_list|(
specifier|const
name|RECT
modifier|&
name|sourceRect
parameter_list|,
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|)
function_decl|;
name|void
name|setCommonBlitState
parameter_list|()
function_decl|;
name|RECT
name|getSurfaceRect
argument_list|(
name|IDirect3DSurface9
operator|*
name|surface
argument_list|)
decl|const
decl_stmt|;
comment|// This enum is used to index mCompiledShaders and mShaderSource.
enum|enum
name|ShaderId
block|{
name|SHADER_VS_STANDARD
block|,
name|SHADER_VS_FLIPY
block|,
name|SHADER_PS_PASSTHROUGH
block|,
name|SHADER_PS_LUMINANCE
block|,
name|SHADER_PS_COMPONENTMASK
block|,
name|SHADER_COUNT
block|}
enum|;
comment|// This actually contains IDirect3DVertexShader9 or IDirect3DPixelShader9 casted to IUnknown.
name|IUnknown
modifier|*
name|mCompiledShaders
index|[
name|SHADER_COUNT
index|]
decl_stmt|;
name|template
operator|<
name|class
name|D3DShaderType
operator|>
name|gl
operator|::
name|Error
name|setShader
argument_list|(
argument|ShaderId source
argument_list|,
argument|const char *profile
argument_list|,
argument|gl::Error (Renderer9::*createShader)(const DWORD *, size_t length, D3DShaderType **outShader)
argument_list|,
argument|HRESULT (WINAPI IDirect3DDevice9::*setShader)(D3DShaderType*)
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|setVertexShader
argument_list|(
argument|ShaderId shader
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|setPixelShader
argument_list|(
argument|ShaderId shader
argument_list|)
expr_stmt|;
name|void
name|render
parameter_list|()
function_decl|;
name|void
name|saveState
parameter_list|()
function_decl|;
name|void
name|restoreState
parameter_list|()
function_decl|;
name|IDirect3DStateBlock9
modifier|*
name|mSavedStateBlock
decl_stmt|;
name|IDirect3DSurface9
modifier|*
name|mSavedRenderTarget
decl_stmt|;
name|IDirect3DSurface9
modifier|*
name|mSavedDepthStencil
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Blit9
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_BLIT9_H_
end_comment
end_unit
