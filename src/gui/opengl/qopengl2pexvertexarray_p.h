begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGL2PEXVERTEXARRAY_P_H
end_ifndef
begin_define
DECL|macro|QOPENGL2PEXVERTEXARRAY_P_H
define|#
directive|define
name|QOPENGL2PEXVERTEXARRAY_P_H
end_define
begin_include
include|#
directive|include
file|<QRectF>
end_include
begin_include
include|#
directive|include
file|<private/qdatabuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qvectorpath_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QOpenGLPoint
block|{
name|public
label|:
name|QOpenGLPoint
argument_list|(
argument|GLfloat new_x
argument_list|,
argument|GLfloat new_y
argument_list|)
block|:
name|x
argument_list|(
name|new_x
argument_list|)
operator|,
name|y
argument_list|(
argument|new_y
argument_list|)
block|{}
expr_stmt|;
name|QOpenGLPoint
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|)
operator|:
name|x
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|)
operator|,
name|y
argument_list|(
argument|p.y()
argument_list|)
block|{}
expr_stmt|;
name|QOpenGLPoint
argument_list|(
specifier|const
name|QPointF
operator|*
name|p
argument_list|)
operator|:
name|x
argument_list|(
name|p
operator|->
name|x
argument_list|()
argument_list|)
operator|,
name|y
argument_list|(
argument|p->y()
argument_list|)
block|{}
expr_stmt|;
name|GLfloat
name|x
decl_stmt|;
name|GLfloat
name|y
decl_stmt|;
name|operator
name|QPointF
parameter_list|()
block|{
return|return
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
name|operator
name|QPointF
argument_list|()
specifier|const
block|{
return|return
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QOpenGLRect
struct|struct
name|QOpenGLRect
block|{
DECL|function|QOpenGLRect
name|QOpenGLRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|)
operator|:
name|left
argument_list|(
name|r
operator|.
name|left
argument_list|()
argument_list|)
operator|,
name|top
argument_list|(
name|r
operator|.
name|top
argument_list|()
argument_list|)
operator|,
name|right
argument_list|(
name|r
operator|.
name|right
argument_list|()
argument_list|)
operator|,
name|bottom
argument_list|(
argument|r.bottom()
argument_list|)
block|{}
DECL|function|QOpenGLRect
name|QOpenGLRect
argument_list|(
argument|GLfloat l
argument_list|,
argument|GLfloat t
argument_list|,
argument|GLfloat r
argument_list|,
argument|GLfloat b
argument_list|)
operator|:
name|left
argument_list|(
name|l
argument_list|)
operator|,
name|top
argument_list|(
name|t
argument_list|)
operator|,
name|right
argument_list|(
name|r
argument_list|)
operator|,
name|bottom
argument_list|(
argument|b
argument_list|)
block|{}
DECL|member|left
name|GLfloat
name|left
expr_stmt|;
DECL|member|top
name|GLfloat
name|top
decl_stmt|;
DECL|member|right
name|GLfloat
name|right
decl_stmt|;
DECL|member|bottom
name|GLfloat
name|bottom
decl_stmt|;
DECL|function|QRectF
name|operator
name|QRectF
argument_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
name|left
argument_list|,
name|top
argument_list|,
name|right
operator|-
name|left
argument_list|,
name|bottom
operator|-
name|top
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QOpenGL2PEXVertexArray
block|{
name|public
label|:
name|QOpenGL2PEXVertexArray
argument_list|()
operator|:
name|vertexArray
argument_list|(
literal|0
argument_list|)
operator|,
name|vertexArrayStops
argument_list|(
literal|0
argument_list|)
operator|,
name|maxX
argument_list|(
operator|-
literal|2e10
argument_list|)
operator|,
name|maxY
argument_list|(
operator|-
literal|2e10
argument_list|)
operator|,
name|minX
argument_list|(
literal|2e10
argument_list|)
operator|,
name|minY
argument_list|(
literal|2e10
argument_list|)
operator|,
name|boundingRectDirty
argument_list|(
argument|true
argument_list|)
block|{ }
specifier|inline
name|void
name|addRect
argument_list|(
argument|const QRectF&rect
argument_list|)
block|{
name|qreal
name|top
operator|=
name|rect
operator|.
name|top
argument_list|()
block|;
name|qreal
name|left
operator|=
name|rect
operator|.
name|left
argument_list|()
block|;
name|qreal
name|bottom
operator|=
name|rect
operator|.
name|bottom
argument_list|()
block|;
name|qreal
name|right
operator|=
name|rect
operator|.
name|right
argument_list|()
block|;
name|vertexArray
operator|<<
name|QOpenGLPoint
argument_list|(
name|left
argument_list|,
name|top
argument_list|)
operator|<<
name|QOpenGLPoint
argument_list|(
name|right
argument_list|,
name|top
argument_list|)
operator|<<
name|QOpenGLPoint
argument_list|(
name|right
argument_list|,
name|bottom
argument_list|)
operator|<<
name|QOpenGLPoint
argument_list|(
name|right
argument_list|,
name|bottom
argument_list|)
operator|<<
name|QOpenGLPoint
argument_list|(
name|left
argument_list|,
name|bottom
argument_list|)
operator|<<
name|QOpenGLPoint
argument_list|(
name|left
argument_list|,
name|top
argument_list|)
block|;             }
specifier|inline
name|void
name|addQuad
argument_list|(
argument|const QRectF&rect
argument_list|)
block|{
name|qreal
name|top
operator|=
name|rect
operator|.
name|top
argument_list|()
block|;
name|qreal
name|left
operator|=
name|rect
operator|.
name|left
argument_list|()
block|;
name|qreal
name|bottom
operator|=
name|rect
operator|.
name|bottom
argument_list|()
block|;
name|qreal
name|right
operator|=
name|rect
operator|.
name|right
argument_list|()
block|;
name|vertexArray
operator|<<
name|QOpenGLPoint
argument_list|(
name|left
argument_list|,
name|top
argument_list|)
operator|<<
name|QOpenGLPoint
argument_list|(
name|right
argument_list|,
name|top
argument_list|)
operator|<<
name|QOpenGLPoint
argument_list|(
name|left
argument_list|,
name|bottom
argument_list|)
operator|<<
name|QOpenGLPoint
argument_list|(
name|right
argument_list|,
name|bottom
argument_list|)
block|;      }
specifier|inline
name|void
name|addVertex
argument_list|(
argument|const GLfloat x
argument_list|,
argument|const GLfloat y
argument_list|)
block|{
name|vertexArray
operator|.
name|add
argument_list|(
name|QOpenGLPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|;     }
name|void
name|addPath
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|GLfloat curveInverseScale
argument_list|,
argument|bool outline = true
argument_list|)
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|QOpenGLPoint
modifier|*
name|data
parameter_list|()
block|{
return|return
name|vertexArray
operator|.
name|data
argument_list|()
return|;
block|}
name|int
operator|*
name|stops
argument_list|()
specifier|const
block|{
return|return
name|vertexArrayStops
operator|.
name|data
argument_list|()
return|;
block|}
name|int
name|stopCount
argument_list|()
specifier|const
block|{
return|return
name|vertexArrayStops
operator|.
name|size
argument_list|()
return|;
block|}
name|QOpenGLRect
name|boundingRect
argument_list|()
specifier|const
expr_stmt|;
name|int
name|vertexCount
argument_list|()
specifier|const
block|{
return|return
name|vertexArray
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|lineToArray
parameter_list|(
specifier|const
name|GLfloat
name|x
parameter_list|,
specifier|const
name|GLfloat
name|y
parameter_list|)
function_decl|;
name|private
label|:
name|QDataBuffer
operator|<
name|QOpenGLPoint
operator|>
name|vertexArray
expr_stmt|;
name|QDataBuffer
operator|<
name|int
operator|>
name|vertexArrayStops
expr_stmt|;
name|GLfloat
name|maxX
decl_stmt|;
name|GLfloat
name|maxY
decl_stmt|;
name|GLfloat
name|minX
decl_stmt|;
name|GLfloat
name|minY
decl_stmt|;
name|bool
name|boundingRectDirty
decl_stmt|;
name|void
name|addClosingLine
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
name|void
name|addCentroid
parameter_list|(
specifier|const
name|QVectorPath
modifier|&
name|path
parameter_list|,
name|int
name|subPathIndex
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
