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
comment|// VertexBuffer.h: Defines the abstract VertexBuffer class and VertexBufferInterface
end_comment
begin_comment
comment|// class with derivations, classes that perform graphics API agnostic vertex buffer operations.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_VERTEXBUFFER_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_VERTEXBUFFER_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_VERTEXBUFFER_H_
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
begin_include
include|#
directive|include
file|<cstddef>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
struct_decl|struct
name|VertexAttribute
struct_decl|;
struct_decl|struct
name|VertexAttribCurrentValueData
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|BufferFactoryD3D
decl_stmt|;
name|class
name|VertexBuffer
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|VertexBuffer
argument_list|()
block|;
name|virtual
operator|~
name|VertexBuffer
argument_list|()
block|;
name|virtual
name|gl
operator|::
name|Error
name|initialize
argument_list|(
argument|unsigned int size
argument_list|,
argument|bool dynamicUsage
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|storeVertexAttributes
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|const gl::VertexAttribCurrentValueData&currentValue
argument_list|,
argument|GLint start
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|unsigned int offset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|getSpaceRequired
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|unsigned int *outSpaceRequired
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|int
name|getBufferSize
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setBufferSize
argument_list|(
argument|unsigned int size
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|discard
argument_list|()
operator|=
literal|0
block|;
name|unsigned
name|int
name|getSerial
argument_list|()
specifier|const
block|;
comment|// This may be overridden (e.g. by VertexBuffer11) if necessary.
name|virtual
name|void
name|hintUnmapResource
argument_list|()
block|{ }
block|;
name|protected
operator|:
name|void
name|updateSerial
argument_list|()
block|;
name|private
operator|:
name|unsigned
name|int
name|mSerial
block|;
specifier|static
name|unsigned
name|int
name|mNextSerial
block|; }
decl_stmt|;
name|class
name|VertexBufferInterface
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|VertexBufferInterface
argument_list|(
argument|BufferFactoryD3D *factory
argument_list|,
argument|bool dynamic
argument_list|)
block|;
name|virtual
operator|~
name|VertexBufferInterface
argument_list|()
block|;
name|gl
operator|::
name|Error
name|reserveVertexSpace
argument_list|(
argument|const gl::VertexAttribute&attribute
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
block|;
name|unsigned
name|int
name|getBufferSize
argument_list|()
specifier|const
block|;
name|unsigned
name|int
name|getSerial
argument_list|()
specifier|const
block|;
name|virtual
name|gl
operator|::
name|Error
name|storeVertexAttributes
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|const gl::VertexAttribCurrentValueData&currentValue
argument_list|,
argument|GLint start
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|unsigned int *outStreamOffset
argument_list|)
block|;
name|bool
name|directStoragePossible
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|const gl::VertexAttribCurrentValueData&currentValue
argument_list|)
specifier|const
block|;
name|VertexBuffer
operator|*
name|getVertexBuffer
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|virtual
name|gl
operator|::
name|Error
name|reserveSpace
argument_list|(
argument|unsigned int size
argument_list|)
operator|=
literal|0
block|;
name|unsigned
name|int
name|getWritePosition
argument_list|()
specifier|const
block|;
name|void
name|setWritePosition
argument_list|(
argument|unsigned int writePosition
argument_list|)
block|;
name|gl
operator|::
name|Error
name|discard
argument_list|()
block|;
name|gl
operator|::
name|Error
name|setBufferSize
argument_list|(
argument|unsigned int size
argument_list|)
block|;
name|private
operator|:
name|BufferFactoryD3D
operator|*
specifier|const
name|mFactory
block|;
name|VertexBuffer
operator|*
name|mVertexBuffer
block|;
name|unsigned
name|int
name|mWritePosition
block|;
name|unsigned
name|int
name|mReservedSpace
block|;
name|bool
name|mDynamic
block|; }
decl_stmt|;
name|class
name|StreamingVertexBufferInterface
range|:
name|public
name|VertexBufferInterface
block|{
name|public
operator|:
name|StreamingVertexBufferInterface
argument_list|(
argument|BufferFactoryD3D *factory
argument_list|,
argument|std::size_t initialSize
argument_list|)
block|;
operator|~
name|StreamingVertexBufferInterface
argument_list|()
block|;
name|protected
operator|:
name|gl
operator|::
name|Error
name|reserveSpace
argument_list|(
argument|unsigned int size
argument_list|)
block|; }
decl_stmt|;
name|class
name|StaticVertexBufferInterface
range|:
name|public
name|VertexBufferInterface
block|{
name|public
operator|:
name|explicit
name|StaticVertexBufferInterface
argument_list|(
name|BufferFactoryD3D
operator|*
name|factory
argument_list|)
block|;
operator|~
name|StaticVertexBufferInterface
argument_list|()
block|;
name|gl
operator|::
name|Error
name|storeVertexAttributes
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|const gl::VertexAttribCurrentValueData&currentValue
argument_list|,
argument|GLint start
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|unsigned int *outStreamOffset
argument_list|)
block|;
name|bool
name|lookupAttribute
argument_list|(
argument|const gl::VertexAttribute&attribute
argument_list|,
argument|unsigned int* outStreamFffset
argument_list|)
block|;
name|protected
operator|:
name|gl
operator|::
name|Error
name|reserveSpace
argument_list|(
argument|unsigned int size
argument_list|)
block|;
name|private
operator|:
expr|struct
name|VertexElement
block|{
name|GLenum
name|type
block|;
name|GLuint
name|size
block|;
name|GLuint
name|stride
block|;
name|bool
name|normalized
block|;
name|bool
name|pureInteger
block|;
name|size_t
name|attributeOffset
block|;
name|unsigned
name|int
name|streamOffset
block|;     }
block|;
name|std
operator|::
name|vector
operator|<
name|VertexElement
operator|>
name|mCache
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_VERTEXBUFFER_H_
end_comment
end_unit
