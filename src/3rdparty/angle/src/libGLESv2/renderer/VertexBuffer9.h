begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// VertexBuffer9.h: Defines the D3D9 VertexBuffer implementation.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_VERTEXBUFFER9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_VERTEXBUFFER9_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_VERTEXBUFFER9_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/VertexBuffer.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
name|class
name|VertexBuffer9
range|:
name|public
name|VertexBuffer
block|{
name|public
operator|:
name|explicit
name|VertexBuffer9
argument_list|(
name|rx
operator|::
name|Renderer9
operator|*
specifier|const
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|VertexBuffer9
argument_list|()
block|;
name|virtual
name|bool
name|initialize
argument_list|(
argument|unsigned int size
argument_list|,
argument|bool dynamicUsage
argument_list|)
block|;
specifier|static
name|VertexBuffer9
operator|*
name|makeVertexBuffer9
argument_list|(
name|VertexBuffer
operator|*
name|vertexBuffer
argument_list|)
block|;
name|virtual
name|bool
name|storeVertexAttributes
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|GLint start
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|unsigned int offset
argument_list|)
block|;
name|virtual
name|bool
name|storeRawData
argument_list|(
argument|const void* data
argument_list|,
argument|unsigned int size
argument_list|,
argument|unsigned int offset
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getSpaceRequired
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|requiresConversion
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|)
specifier|const
block|;
name|unsigned
name|int
name|getVertexSize
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|)
specifier|const
block|;
name|D3DDECLTYPE
name|getDeclType
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getBufferSize
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|setBufferSize
argument_list|(
argument|unsigned int size
argument_list|)
block|;
name|virtual
name|bool
name|discard
argument_list|()
block|;
name|IDirect3DVertexBuffer9
operator|*
name|getBuffer
argument_list|()
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|VertexBuffer9
argument_list|)
block|;
name|rx
operator|::
name|Renderer9
operator|*
specifier|const
name|mRenderer
block|;
name|IDirect3DVertexBuffer9
operator|*
name|mVertexBuffer
block|;
name|unsigned
name|int
name|mBufferSize
block|;
name|bool
name|mDynamicUsage
block|;
comment|// Attribute format conversion
block|enum
block|{
name|NUM_GL_VERTEX_ATTRIB_TYPES
operator|=
literal|6
block|}
block|;      struct
name|FormatConverter
block|{
name|bool
name|identity
block|;
name|std
operator|::
name|size_t
name|outputElementSize
block|;
name|void
argument_list|(
argument|*convertArray
argument_list|)
operator|(
specifier|const
name|void
operator|*
name|in
expr|,
name|std
operator|::
name|size_t
name|stride
expr|,
name|std
operator|::
name|size_t
name|n
expr|,
name|void
operator|*
name|out
operator|)
block|;
name|D3DDECLTYPE
name|d3dDeclType
block|;     }
block|;
specifier|static
name|bool
name|mTranslationsInitialized
block|;
specifier|static
name|void
name|initializeTranslations
argument_list|(
argument|DWORD declTypes
argument_list|)
block|;
comment|// [GL types as enumerated by typeIndex()][normalized][size - 1]
specifier|static
name|FormatConverter
name|mFormatConverters
index|[
name|NUM_GL_VERTEX_ATTRIB_TYPES
index|]
index|[
literal|2
index|]
index|[
literal|4
index|]
block|;      struct
name|TranslationDescription
block|{
name|DWORD
name|capsFlag
block|;
name|FormatConverter
name|preferredConversion
block|;
name|FormatConverter
name|fallbackConversion
block|;     }
block|;
comment|// This table is used to generate mFormatConverters.
comment|// [GL types as enumerated by typeIndex()][normalized][size - 1]
specifier|static
specifier|const
name|TranslationDescription
name|mPossibleTranslations
index|[
name|NUM_GL_VERTEX_ATTRIB_TYPES
index|]
index|[
literal|2
index|]
index|[
literal|4
index|]
block|;
specifier|static
name|unsigned
name|int
name|typeIndex
argument_list|(
argument|GLenum type
argument_list|)
block|;
specifier|static
specifier|const
name|FormatConverter
operator|&
name|formatConverter
argument_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|&
name|attribute
argument_list|)
block|;
specifier|static
name|unsigned
name|int
name|spaceRequired
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|std::size_t count
argument_list|,
argument|GLsizei instances
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_VERTEXBUFFER9_H_
end_comment
end_unit
