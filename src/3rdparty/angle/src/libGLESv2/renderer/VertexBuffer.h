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
name|LIBGLESV2_RENDERER_VERTEXBUFFER_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_VERTEXBUFFER_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_VERTEXBUFFER_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|VertexAttribute
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer
decl_stmt|;
name|class
name|VertexBuffer
block|{
name|public
label|:
name|VertexBuffer
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|VertexBuffer
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|initialize
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|,
name|bool
name|dynamicUsage
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|storeVertexAttributes
argument_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|&
name|attrib
argument_list|,
name|GLint
name|start
argument_list|,
name|GLsizei
name|count
argument_list|,
name|GLsizei
name|instances
argument_list|,
name|unsigned
name|int
name|offset
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|storeRawData
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|getSpaceRequired
argument_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|&
name|attrib
argument_list|,
name|GLsizei
name|count
argument_list|,
name|GLsizei
name|instances
argument_list|,
name|unsigned
name|int
operator|*
name|outSpaceRequired
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|requiresConversion
argument_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|&
name|attrib
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|unsigned
name|int
name|getBufferSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|setBufferSize
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|discard
parameter_list|()
init|=
literal|0
function_decl|;
name|unsigned
name|int
name|getSerial
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|void
name|updateSerial
parameter_list|()
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|VertexBuffer
argument_list|)
expr_stmt|;
name|unsigned
name|int
name|mSerial
decl_stmt|;
specifier|static
name|unsigned
name|int
name|mNextSerial
decl_stmt|;
block|}
empty_stmt|;
name|class
name|VertexBufferInterface
block|{
name|public
label|:
name|VertexBufferInterface
argument_list|(
argument|rx::Renderer *renderer
argument_list|,
argument|bool dynamic
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|VertexBufferInterface
argument_list|()
expr_stmt|;
name|bool
name|reserveVertexSpace
argument_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|&
name|attribute
argument_list|,
name|GLsizei
name|count
argument_list|,
name|GLsizei
name|instances
argument_list|)
decl_stmt|;
name|bool
name|reserveRawDataSpace
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
name|unsigned
name|int
name|getBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|int
name|getSerial
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|storeVertexAttributes
argument_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|&
name|attrib
argument_list|,
name|GLint
name|start
argument_list|,
name|GLsizei
name|count
argument_list|,
name|GLsizei
name|instances
argument_list|,
name|unsigned
name|int
operator|*
name|outStreamOffset
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|storeRawData
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|unsigned
name|int
modifier|*
name|outStreamOffset
parameter_list|)
function_decl|;
name|VertexBuffer
operator|*
name|getVertexBuffer
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|virtual
name|bool
name|reserveSpace
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|)
init|=
literal|0
function_decl|;
name|unsigned
name|int
name|getWritePosition
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWritePosition
parameter_list|(
name|unsigned
name|int
name|writePosition
parameter_list|)
function_decl|;
name|bool
name|discard
parameter_list|()
function_decl|;
name|bool
name|setBufferSize
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|VertexBufferInterface
argument_list|)
expr_stmt|;
name|rx
operator|::
name|Renderer
operator|*
specifier|const
name|mRenderer
expr_stmt|;
name|VertexBuffer
modifier|*
name|mVertexBuffer
decl_stmt|;
name|unsigned
name|int
name|mWritePosition
decl_stmt|;
name|unsigned
name|int
name|mReservedSpace
decl_stmt|;
name|bool
name|mDynamic
decl_stmt|;
block|}
empty_stmt|;
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
argument|rx::Renderer *renderer
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
name|bool
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
name|rx
operator|::
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
operator|~
name|StaticVertexBufferInterface
argument_list|()
block|;
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
argument|unsigned int *outStreamOffset
argument_list|)
block|;
name|bool
name|lookupAttribute
argument_list|(
argument|const gl::VertexAttribute&attribute
argument_list|,
argument|unsigned int* outStreamOffset
argument_list|)
block|;
name|protected
operator|:
name|bool
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
name|GLint
name|size
block|;
name|GLsizei
name|stride
block|;
name|bool
name|normalized
block|;
name|int
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
comment|// LIBGLESV2_RENDERER_VERTEXBUFFER_H_
end_comment
end_unit
