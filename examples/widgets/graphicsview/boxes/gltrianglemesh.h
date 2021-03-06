begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GLTRIANGLEMESH_H
end_ifndef
begin_define
DECL|macro|GLTRIANGLEMESH_H
define|#
directive|define
name|GLTRIANGLEMESH_H
end_define
begin_comment
comment|//#include<GL/glew.h>
end_comment
begin_include
include|#
directive|include
file|"glextensions.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_include
include|#
directive|include
file|"glbuffers.h"
end_include
begin_expr_stmt
DECL|variable|TVertex
name|template
operator|<
name|class
name|TVertex
operator|,
name|class
name|TIndex
operator|>
name|class
name|GLTriangleMesh
block|{
name|public
operator|:
name|GLTriangleMesh
argument_list|(
argument|int vertexCount
argument_list|,
argument|int indexCount
argument_list|)
operator|:
name|m_vb
argument_list|(
name|vertexCount
argument_list|)
block|,
name|m_ib
argument_list|(
argument|indexCount
argument_list|)
block|{     }
name|virtual
operator|~
name|GLTriangleMesh
argument_list|()
block|{     }
name|virtual
name|void
name|draw
argument_list|()
block|{
if|if
condition|(
name|failed
argument_list|()
condition|)
return|return;
name|int
name|type
operator|=
name|GL_UNSIGNED_INT
block|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|TIndex
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|char
argument_list|)
condition|)
name|type
operator|=
name|GL_UNSIGNED_BYTE
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
sizeof|sizeof
argument_list|(
name|TIndex
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|short
argument_list|)
condition|)
name|type
operator|=
name|GL_UNSIGNED_SHORT
expr_stmt|;
end_if
begin_expr_stmt
name|m_vb
operator|.
name|bind
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_ib
operator|.
name|bind
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|glDrawElements
argument_list|(
name|GL_TRIANGLES
argument_list|,
name|m_ib
operator|.
name|length
argument_list|()
argument_list|,
name|type
argument_list|,
name|BUFFER_OFFSET
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_vb
operator|.
name|unbind
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_ib
operator|.
name|unbind
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
unit|}      bool
name|failed
argument_list|()
end_macro
begin_block
block|{
return|return
name|m_vb
operator|.
name|failed
argument_list|()
operator|||
name|m_ib
operator|.
name|failed
argument_list|()
return|;
block|}
end_block
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|GLVertexBuffer
operator|<
name|TVertex
operator|>
name|m_vb
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|GLIndexBuffer
operator|<
name|TIndex
operator|>
name|m_ib
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
end_unit
