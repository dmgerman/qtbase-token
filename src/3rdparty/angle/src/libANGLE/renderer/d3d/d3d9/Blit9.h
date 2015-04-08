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
name|LIBANGLE_RENDERER_D3D_D3D9_BLIT9_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D9_BLIT9_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D9_BLIT9_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
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
struct_decl|struct
name|Offset
struct_decl|;
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
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|explicit
name|Blit9
argument_list|(
name|Renderer9
operator|*
name|renderer
argument_list|)
block|;
operator|~
name|Blit9
argument_list|()
block|;
name|gl
operator|::
name|Error
name|initialize
argument_list|()
block|;
comment|// Copy from source surface to dest surface.
comment|// sourceRect, xoffset, yoffset are in D3D coordinates (0,0 in upper-left)
name|gl
operator|::
name|Error
name|copy2D
argument_list|(
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|const RECT&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|const gl::Offset&destOffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLint level
argument_list|)
block|;
name|gl
operator|::
name|Error
name|copyCube
argument_list|(
argument|const gl::Framebuffer *framebuffer
argument_list|,
argument|const RECT&sourceRect
argument_list|,
argument|GLenum destFormat
argument_list|,
argument|const gl::Offset&destOffset
argument_list|,
argument|TextureStorage *storage
argument_list|,
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
block|;
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
argument|const gl::Offset&destOffset
argument_list|,
argument|IDirect3DSurface9 *dest
argument_list|)
block|;
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
block|;
name|private
operator|:
name|Renderer9
operator|*
name|mRenderer
block|;
name|bool
name|mGeometryLoaded
block|;
name|IDirect3DVertexBuffer9
operator|*
name|mQuadVertexBuffer
block|;
name|IDirect3DVertexDeclaration9
operator|*
name|mQuadVertexDeclaration
block|;
name|gl
operator|::
name|Error
name|setFormatConvertShaders
argument_list|(
argument|GLenum destFormat
argument_list|)
block|;
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
argument|const gl::Offset&destOffset
argument_list|,
argument|IDirect3DSurface9 *dest
argument_list|)
block|;
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
block|;
name|void
name|setViewport
argument_list|(
specifier|const
name|RECT
operator|&
name|sourceRect
argument_list|,
specifier|const
name|gl
operator|::
name|Offset
operator|&
name|offset
argument_list|)
block|;
name|void
name|setCommonBlitState
argument_list|()
block|;
name|RECT
name|getSurfaceRect
argument_list|(
argument|IDirect3DSurface9 *surface
argument_list|)
specifier|const
block|;
comment|// This enum is used to index mCompiledShaders and mShaderSource.
block|enum
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
block|;
comment|// This actually contains IDirect3DVertexShader9 or IDirect3DPixelShader9 casted to IUnknown.
name|IUnknown
operator|*
name|mCompiledShaders
index|[
name|SHADER_COUNT
index|]
block|;
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
block|;
name|gl
operator|::
name|Error
name|setVertexShader
argument_list|(
argument|ShaderId shader
argument_list|)
block|;
name|gl
operator|::
name|Error
name|setPixelShader
argument_list|(
argument|ShaderId shader
argument_list|)
block|;
name|void
name|render
argument_list|()
block|;
name|void
name|saveState
argument_list|()
block|;
name|void
name|restoreState
argument_list|()
block|;
name|IDirect3DStateBlock9
operator|*
name|mSavedStateBlock
block|;
name|IDirect3DSurface9
operator|*
name|mSavedRenderTarget
block|;
name|IDirect3DSurface9
operator|*
name|mSavedDepthStencil
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D9_BLIT9_H_
end_comment
end_unit
