begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
