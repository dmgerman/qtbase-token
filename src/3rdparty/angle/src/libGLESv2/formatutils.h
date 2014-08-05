begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
comment|// formatutils.h: Queries for GL image formats.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_FORMATUTILS_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_FORMATUTILS_H_
define|#
directive|define
name|LIBGLESV2_FORMATUTILS_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Caps.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
end_include
begin_include
include|#
directive|include
file|<cstddef>
end_include
begin_typedef
DECL|typedef|MipGenerationFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|MipGenerationFunction
function_decl|)
parameter_list|(
name|size_t
name|sourceWidth
parameter_list|,
name|size_t
name|sourceHeight
parameter_list|,
name|size_t
name|sourceDepth
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|sourceData
parameter_list|,
name|size_t
name|sourceRowPitch
parameter_list|,
name|size_t
name|sourceDepthPitch
parameter_list|,
name|uint8_t
modifier|*
name|destData
parameter_list|,
name|size_t
name|destRowPitch
parameter_list|,
name|size_t
name|destDepthPitch
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|LoadImageFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|LoadImageFunction
function_decl|)
parameter_list|(
name|size_t
name|width
parameter_list|,
name|size_t
name|height
parameter_list|,
name|size_t
name|depth
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|input
parameter_list|,
name|size_t
name|inputRowPitch
parameter_list|,
name|size_t
name|inputDepthPitch
parameter_list|,
name|uint8_t
modifier|*
name|output
parameter_list|,
name|size_t
name|outputRowPitch
parameter_list|,
name|size_t
name|outputDepthPitch
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|InitializeTextureDataFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|InitializeTextureDataFunction
function_decl|)
parameter_list|(
name|size_t
name|width
parameter_list|,
name|size_t
name|height
parameter_list|,
name|size_t
name|depth
parameter_list|,
name|uint8_t
modifier|*
name|output
parameter_list|,
name|size_t
name|outputRowPitch
parameter_list|,
name|size_t
name|outputDepthPitch
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|ColorReadFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|ColorReadFunction
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|source
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|ColorWriteFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|ColorWriteFunction
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|source
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|ColorCopyFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|ColorCopyFunction
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|source
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|VertexCopyFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|VertexCopyFunction
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|input
parameter_list|,
name|size_t
name|stride
parameter_list|,
name|size_t
name|count
parameter_list|,
name|void
modifier|*
name|output
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
name|namespace
name|gl
block|{
typedef|typedef
name|std
operator|::
name|set
operator|<
name|GLenum
operator|>
name|FormatSet
expr_stmt|;
name|bool
name|IsValidInternalFormat
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
specifier|const
name|Extensions
modifier|&
name|extensions
parameter_list|,
name|GLuint
name|clientVersion
parameter_list|)
function_decl|;
name|bool
name|IsValidFormat
parameter_list|(
name|GLenum
name|format
parameter_list|,
specifier|const
name|Extensions
modifier|&
name|extensions
parameter_list|,
name|GLuint
name|clientVersion
parameter_list|)
function_decl|;
name|bool
name|IsValidType
parameter_list|(
name|GLenum
name|type
parameter_list|,
specifier|const
name|Extensions
modifier|&
name|extensions
parameter_list|,
name|GLuint
name|clientVersion
parameter_list|)
function_decl|;
name|bool
name|IsValidFormatCombination
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|Extensions
modifier|&
name|extensions
parameter_list|,
name|GLuint
name|clientVersion
parameter_list|)
function_decl|;
name|bool
name|IsValidCopyTexImageCombination
parameter_list|(
name|GLenum
name|textureInternalFormat
parameter_list|,
name|GLenum
name|frameBufferInternalFormat
parameter_list|,
name|GLuint
name|readBufferHandle
parameter_list|,
name|GLuint
name|clientVersion
parameter_list|)
function_decl|;
name|bool
name|IsRenderingSupported
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
specifier|const
name|Extensions
modifier|&
name|extensions
parameter_list|,
name|GLuint
name|clientVersion
parameter_list|)
function_decl|;
name|bool
name|IsFilteringSupported
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
specifier|const
name|Extensions
modifier|&
name|extensions
parameter_list|,
name|GLuint
name|clientVersion
parameter_list|)
function_decl|;
name|bool
name|IsSizedInternalFormat
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLenum
name|GetSizedInternalFormat
parameter_list|(
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|)
function_decl|;
name|GLuint
name|GetPixelBytes
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetAlphaBits
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetRedBits
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetGreenBits
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetBlueBits
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetLuminanceBits
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetDepthBits
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetStencilBits
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetTypeBytes
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|bool
name|IsSpecialInterpretationType
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|bool
name|IsFloatOrFixedComponentType
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|GLenum
name|GetFormat
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLenum
name|GetType
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLenum
name|GetComponentType
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetComponentCount
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLenum
name|GetColorEncoding
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetRowPitch
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLint
name|alignment
parameter_list|)
function_decl|;
name|GLuint
name|GetDepthPitch
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLint
name|alignment
parameter_list|)
function_decl|;
name|GLuint
name|GetBlockSize
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
name|bool
name|IsFormatCompressed
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetCompressedBlockWidth
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
name|GLuint
name|GetCompressedBlockHeight
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
specifier|const
name|FormatSet
modifier|&
name|GetAllSizedInternalFormats
parameter_list|()
function_decl|;
name|ColorWriteFunction
name|GetColorWriteFunction
parameter_list|(
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_FORMATUTILS_H_
end_comment
end_unit
