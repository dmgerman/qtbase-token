begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_CAPS_H
end_ifndef
begin_define
DECL|macro|LIBGLESV2_CAPS_H
define|#
directive|define
name|LIBGLESV2_CAPS_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|<unordered_map>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
struct|struct
name|TextureCaps
block|{
name|TextureCaps
argument_list|()
expr_stmt|;
comment|// Supports for basic texturing: glTexImage, glTexSubImage, etc
name|bool
name|texturable
decl_stmt|;
comment|// Support for linear or anisotropic filtering
name|bool
name|filterable
decl_stmt|;
comment|// Support for being used as a framebuffer attachment or renderbuffer format
name|bool
name|renderable
decl_stmt|;
name|std
operator|::
name|set
operator|<
name|GLuint
operator|>
name|sampleCounts
expr_stmt|;
block|}
struct|;
name|class
name|TextureCapsMap
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|GLenum
operator|,
name|TextureCaps
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|void
name|insert
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
specifier|const
name|TextureCaps
modifier|&
name|caps
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
specifier|const
name|TextureCaps
modifier|&
name|get
argument_list|(
name|GLenum
name|internalFormat
argument_list|)
decl|const
decl_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
name|const_iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|size
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|GLenum
operator|,
name|TextureCaps
operator|>
name|InternalFormatToCapsMap
expr_stmt|;
name|InternalFormatToCapsMap
name|mCapsMap
decl_stmt|;
block|}
empty_stmt|;
struct|struct
name|Extensions
block|{
name|Extensions
argument_list|()
expr_stmt|;
comment|// Generate a vector of supported extension strings
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|getStrings
argument_list|()
specifier|const
expr_stmt|;
comment|// Set all texture related extension support based on the supported textures.
comment|// Determines support for:
comment|// GL_OES_rgb8_rgba8
comment|// GL_EXT_texture_format_BGRA8888
comment|// GL_OES_texture_half_float, GL_OES_texture_half_float_linear
comment|// GL_OES_texture_float, GL_OES_texture_float_linear
comment|// GL_EXT_texture_rg
comment|// GL_EXT_texture_compression_dxt1, GL_ANGLE_texture_compression_dxt3, GL_ANGLE_texture_compression_dxt5
comment|// GL_ANGLE_depth_texture
comment|// GL_EXT_color_buffer_float
name|void
name|setTextureExtensionSupport
parameter_list|(
specifier|const
name|TextureCapsMap
modifier|&
name|textureCaps
parameter_list|)
function_decl|;
comment|// ES2 Extension support
comment|// GL_OES_element_index_uint
name|bool
name|elementIndexUint
decl_stmt|;
comment|// GL_OES_packed_depth_stencil
name|bool
name|packedDepthStencil
decl_stmt|;
comment|// GL_OES_get_program_binary
name|bool
name|getProgramBinary
decl_stmt|;
comment|// GL_OES_rgb8_rgba8
comment|// Implies that TextureCaps for GL_RGB8 and GL_RGBA8 exist
name|bool
name|rgb8rgba8
decl_stmt|;
comment|// GL_EXT_texture_format_BGRA8888
comment|// Implies that TextureCaps for GL_BGRA8 exist
name|bool
name|textureFormatBGRA8888
decl_stmt|;
comment|// GL_EXT_read_format_bgra
name|bool
name|readFormatBGRA
decl_stmt|;
comment|// GL_NV_pixel_buffer_object
name|bool
name|pixelBufferObject
decl_stmt|;
comment|// GL_OES_mapbuffer and GL_EXT_map_buffer_range
name|bool
name|mapBuffer
decl_stmt|;
name|bool
name|mapBufferRange
decl_stmt|;
comment|// GL_OES_texture_half_float and GL_OES_texture_half_float_linear
comment|// Implies that TextureCaps for GL_RGB16F, GL_RGBA16F, GL_ALPHA32F_EXT, GL_LUMINANCE32F_EXT and
comment|// GL_LUMINANCE_ALPHA32F_EXT exist
name|bool
name|textureHalfFloat
decl_stmt|;
name|bool
name|textureHalfFloatLinear
decl_stmt|;
comment|// GL_OES_texture_float and GL_OES_texture_float_linear
comment|// Implies that TextureCaps for GL_RGB32F, GL_RGBA32F, GL_ALPHA16F_EXT, GL_LUMINANCE16F_EXT and
comment|// GL_LUMINANCE_ALPHA16F_EXT exist
name|bool
name|textureFloat
decl_stmt|;
name|bool
name|textureFloatLinear
decl_stmt|;
comment|// GL_EXT_texture_rg
comment|// Implies that TextureCaps for GL_R8, GL_RG8 (and floating point R/RG texture formats if floating point extensions
comment|// are also present) exist
name|bool
name|textureRG
decl_stmt|;
comment|// GL_EXT_texture_compression_dxt1, GL_ANGLE_texture_compression_dxt3 and GL_ANGLE_texture_compression_dxt5
comment|// Implies that TextureCaps for GL_COMPRESSED_RGB_S3TC_DXT1_EXT, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
comment|// GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE and GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
name|bool
name|textureCompressionDXT1
decl_stmt|;
name|bool
name|textureCompressionDXT3
decl_stmt|;
name|bool
name|textureCompressionDXT5
decl_stmt|;
comment|// GL_EXT_sRGB
comment|// Implies that TextureCaps for GL_SRGB8_ALPHA8 and GL_SRGB8 exist
comment|// TODO: Don't advertise this extension in ES3
name|bool
name|sRGB
decl_stmt|;
comment|// GL_ANGLE_depth_texture
name|bool
name|depthTextures
decl_stmt|;
comment|// GL_EXT_texture_storage
name|bool
name|textureStorage
decl_stmt|;
comment|// GL_OES_texture_npot
name|bool
name|textureNPOT
decl_stmt|;
comment|// GL_EXT_draw_buffers
name|bool
name|drawBuffers
decl_stmt|;
comment|// GL_EXT_texture_filter_anisotropic
name|bool
name|textureFilterAnisotropic
decl_stmt|;
name|GLfloat
name|maxTextureAnisotropy
decl_stmt|;
comment|// GL_EXT_occlusion_query_boolean
name|bool
name|occlusionQueryBoolean
decl_stmt|;
comment|// GL_NV_fence
name|bool
name|fence
decl_stmt|;
comment|// GL_ANGLE_timer_query
name|bool
name|timerQuery
decl_stmt|;
comment|// GL_EXT_robustness
name|bool
name|robustness
decl_stmt|;
comment|// GL_EXT_blend_minmax
name|bool
name|blendMinMax
decl_stmt|;
comment|// GL_ANGLE_framebuffer_blit
name|bool
name|framebufferBlit
decl_stmt|;
comment|// GL_ANGLE_framebuffer_multisample
name|bool
name|framebufferMultisample
decl_stmt|;
comment|// GL_ANGLE_instanced_arrays
name|bool
name|instancedArrays
decl_stmt|;
comment|// GL_ANGLE_pack_reverse_row_order
name|bool
name|packReverseRowOrder
decl_stmt|;
comment|// GL_OES_standard_derivatives
name|bool
name|standardDerivatives
decl_stmt|;
comment|// GL_EXT_shader_texture_lod
name|bool
name|shaderTextureLOD
decl_stmt|;
comment|// GL_EXT_frag_depth
name|bool
name|fragDepth
decl_stmt|;
comment|// GL_ANGLE_texture_usage
name|bool
name|textureUsage
decl_stmt|;
comment|// GL_ANGLE_translated_shader_source
name|bool
name|translatedShaderSource
decl_stmt|;
comment|// ES3 Extension support
comment|// GL_EXT_color_buffer_float
name|bool
name|colorBufferFloat
decl_stmt|;
block|}
struct|;
struct|struct
name|Caps
block|{
name|Caps
argument_list|()
expr_stmt|;
comment|// Table 6.28, implementation dependent values
name|GLuint64
name|maxElementIndex
decl_stmt|;
name|GLuint
name|max3DTextureSize
decl_stmt|;
name|GLuint
name|max2DTextureSize
decl_stmt|;
name|GLuint
name|maxArrayTextureLayers
decl_stmt|;
name|GLfloat
name|maxLODBias
decl_stmt|;
name|GLuint
name|maxCubeMapTextureSize
decl_stmt|;
name|GLuint
name|maxRenderbufferSize
decl_stmt|;
name|GLuint
name|maxDrawBuffers
decl_stmt|;
name|GLuint
name|maxColorAttachments
decl_stmt|;
name|GLuint
name|maxViewportWidth
decl_stmt|;
name|GLuint
name|maxViewportHeight
decl_stmt|;
name|GLfloat
name|minAliasedPointSize
decl_stmt|;
name|GLfloat
name|maxAliasedPointSize
decl_stmt|;
name|GLfloat
name|minAliasedLineWidth
decl_stmt|;
name|GLfloat
name|maxAliasedLineWidth
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_CAPS_H
end_comment
end_unit
