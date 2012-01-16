begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGLWidget>
end_include
begin_include
include|#
directive|include
file|<QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<QVector3D>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|"qtlogo.h"
end_include
begin_decl_stmt
DECL|variable|tee_height
specifier|static
specifier|const
name|qreal
name|tee_height
init|=
literal|0.311126
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|cross_width
specifier|static
specifier|const
name|qreal
name|cross_width
init|=
literal|0.25
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|bar_thickness
specifier|static
specifier|const
name|qreal
name|bar_thickness
init|=
literal|0.113137
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|inside_diam
specifier|static
specifier|const
name|qreal
name|inside_diam
init|=
literal|0.20
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|outside_diam
specifier|static
specifier|const
name|qreal
name|outside_diam
init|=
literal|0.30
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|logo_depth
specifier|static
specifier|const
name|qreal
name|logo_depth
init|=
literal|0.10
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|num_divisions
specifier|static
specifier|const
name|int
name|num_divisions
init|=
literal|32
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_struct
DECL|struct|Geometry
struct|struct
name|Geometry
block|{
DECL|member|faces
name|QVector
argument_list|<
name|GLushort
argument_list|>
name|faces
decl_stmt|;
DECL|member|vertices
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|vertices
decl_stmt|;
DECL|member|normals
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|normals
decl_stmt|;
name|void
name|appendSmooth
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|n
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
name|void
name|appendFaceted
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|n
parameter_list|)
function_decl|;
name|void
name|finalize
parameter_list|()
function_decl|;
name|void
name|loadArrays
parameter_list|()
specifier|const
function_decl|;
block|}
struct|;
end_struct
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_class
DECL|class|Patch
class|class
name|Patch
block|{
public|public:
DECL|enum|Smoothing
DECL|enumerator|Faceted
DECL|enumerator|Smooth
enum|enum
name|Smoothing
block|{
name|Faceted
block|,
name|Smooth
block|}
enum|;
name|Patch
parameter_list|(
name|Geometry
modifier|*
parameter_list|)
constructor_decl|;
DECL|function|setSmoothing
name|void
name|setSmoothing
parameter_list|(
name|Smoothing
name|s
parameter_list|)
block|{
name|sm
operator|=
name|s
expr_stmt|;
block|}
name|void
name|translate
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|t
parameter_list|)
function_decl|;
name|void
name|rotate
parameter_list|(
name|qreal
name|deg
parameter_list|,
name|QVector3D
name|axis
parameter_list|)
function_decl|;
name|void
name|draw
parameter_list|()
specifier|const
function_decl|;
name|void
name|addTri
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|b
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|c
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|n
parameter_list|)
function_decl|;
name|void
name|addQuad
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|b
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|c
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|d
parameter_list|)
function_decl|;
DECL|member|start
name|GLushort
name|start
decl_stmt|;
DECL|member|count
name|GLushort
name|count
decl_stmt|;
DECL|member|initv
name|GLushort
name|initv
decl_stmt|;
DECL|member|faceColor
name|GLfloat
name|faceColor
index|[
literal|4
index|]
decl_stmt|;
DECL|member|mat
name|QMatrix4x4
name|mat
decl_stmt|;
DECL|member|sm
name|Smoothing
name|sm
decl_stmt|;
DECL|member|geom
name|Geometry
modifier|*
name|geom
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|qSetColor
specifier|static
specifier|inline
name|void
name|qSetColor
parameter_list|(
name|float
name|colorVec
index|[]
parameter_list|,
name|QColor
name|c
parameter_list|)
block|{
name|colorVec
index|[
literal|0
index|]
operator|=
name|c
operator|.
name|redF
argument_list|()
expr_stmt|;
name|colorVec
index|[
literal|1
index|]
operator|=
name|c
operator|.
name|greenF
argument_list|()
expr_stmt|;
name|colorVec
index|[
literal|2
index|]
operator|=
name|c
operator|.
name|blueF
argument_list|()
expr_stmt|;
name|colorVec
index|[
literal|3
index|]
operator|=
name|c
operator|.
name|alphaF
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadArrays
name|void
name|Geometry
operator|::
name|loadArrays
parameter_list|()
specifier|const
block|{
name|glVertexPointer
argument_list|(
literal|3
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
name|vertices
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|glNormalPointer
argument_list|(
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
name|normals
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finalize
name|void
name|Geometry
operator|::
name|finalize
parameter_list|()
block|{
comment|// TODO: add vertex buffer uploading here
comment|// Finish smoothing normals by ensuring accumulated normals are returned
comment|// to length 1.0.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|normals
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|normals
index|[
name|i
index|]
operator|.
name|normalize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|appendSmooth
name|void
name|Geometry
operator|::
name|appendSmooth
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|n
parameter_list|,
name|int
name|from
parameter_list|)
block|{
comment|// Smooth normals are acheived by averaging the normals for faces meeting
comment|// at a point.  First find the point in geometry already generated
comment|// (working backwards, since most often the points shared are between faces
comment|// recently added).
name|int
name|v
init|=
name|vertices
operator|.
name|count
argument_list|()
operator|-
literal|1
decl_stmt|;
for|for
control|(
init|;
name|v
operator|>=
name|from
condition|;
operator|--
name|v
control|)
if|if
condition|(
name|qFuzzyCompare
argument_list|(
name|vertices
index|[
name|v
index|]
argument_list|,
name|a
argument_list|)
condition|)
break|break;
if|if
condition|(
name|v
operator|<
name|from
condition|)
block|{
comment|// The vert was not found so add it as a new one, and initialize
comment|// its corresponding normal
name|v
operator|=
name|vertices
operator|.
name|count
argument_list|()
expr_stmt|;
name|vertices
operator|.
name|append
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|normals
operator|.
name|append
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Vert found, accumulate normals into corresponding normal slot.
comment|// Must call finalize once finished accumulating normals
name|normals
index|[
name|v
index|]
operator|+=
name|n
expr_stmt|;
block|}
comment|// In both cases (found or not) reference the vert via its index
name|faces
operator|.
name|append
argument_list|(
name|v
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|appendFaceted
name|void
name|Geometry
operator|::
name|appendFaceted
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|n
parameter_list|)
block|{
comment|// Faceted normals are achieved by duplicating the vert for every
comment|// normal, so that faces meeting at a vert get a sharp edge.
name|int
name|v
init|=
name|vertices
operator|.
name|count
argument_list|()
decl_stmt|;
name|vertices
operator|.
name|append
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|normals
operator|.
name|append
argument_list|(
name|n
argument_list|)
expr_stmt|;
name|faces
operator|.
name|append
argument_list|(
name|v
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|Patch
name|Patch
operator|::
name|Patch
parameter_list|(
name|Geometry
modifier|*
name|g
parameter_list|)
member_init_list|:
name|start
argument_list|(
name|g
operator|->
name|faces
operator|.
name|count
argument_list|()
argument_list|)
member_init_list|,
name|count
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|initv
argument_list|(
name|g
operator|->
name|vertices
operator|.
name|count
argument_list|()
argument_list|)
member_init_list|,
name|sm
argument_list|(
name|Patch
operator|::
name|Smooth
argument_list|)
member_init_list|,
name|geom
argument_list|(
name|g
argument_list|)
block|{
name|qSetColor
argument_list|(
name|faceColor
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|darkGray
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|rotate
name|void
name|Patch
operator|::
name|rotate
parameter_list|(
name|qreal
name|deg
parameter_list|,
name|QVector3D
name|axis
parameter_list|)
block|{
name|mat
operator|.
name|rotate
argument_list|(
name|deg
argument_list|,
name|axis
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|translate
name|void
name|Patch
operator|::
name|translate
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|t
parameter_list|)
block|{
name|mat
operator|.
name|translate
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qMultMatrix
specifier|static
specifier|inline
name|void
name|qMultMatrix
parameter_list|(
specifier|const
name|QMatrix4x4
modifier|&
name|mat
parameter_list|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
condition|)
name|glMultMatrixf
argument_list|(
operator|(
name|GLfloat
operator|*
operator|)
name|mat
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES
elseif|else
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|GLdouble
argument_list|)
condition|)
name|glMultMatrixd
argument_list|(
operator|(
name|GLdouble
operator|*
operator|)
name|mat
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|else
block|{
name|GLfloat
name|fmat
index|[
literal|16
index|]
decl_stmt|;
name|qreal
specifier|const
modifier|*
name|r
init|=
name|mat
operator|.
name|constData
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
operator|++
name|i
control|)
name|fmat
index|[
name|i
index|]
operator|=
name|r
index|[
name|i
index|]
expr_stmt|;
name|glMultMatrixf
argument_list|(
name|fmat
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|draw
name|void
name|Patch
operator|::
name|draw
parameter_list|()
specifier|const
block|{
name|glPushMatrix
argument_list|()
expr_stmt|;
name|qMultMatrix
argument_list|(
name|mat
argument_list|)
expr_stmt|;
name|glMaterialfv
argument_list|(
name|GL_FRONT_AND_BACK
argument_list|,
name|GL_AMBIENT_AND_DIFFUSE
argument_list|,
name|faceColor
argument_list|)
expr_stmt|;
specifier|const
name|GLushort
modifier|*
name|indices
init|=
name|geom
operator|->
name|faces
operator|.
name|constData
argument_list|()
decl_stmt|;
name|glDrawElements
argument_list|(
name|GL_TRIANGLES
argument_list|,
name|count
argument_list|,
name|GL_UNSIGNED_SHORT
argument_list|,
name|indices
operator|+
name|start
argument_list|)
expr_stmt|;
name|glPopMatrix
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|addTri
name|void
name|Patch
operator|::
name|addTri
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|b
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|c
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|n
parameter_list|)
block|{
name|QVector3D
name|norm
init|=
name|n
operator|.
name|isNull
argument_list|()
condition|?
name|QVector3D
operator|::
name|normal
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
else|:
name|n
decl_stmt|;
if|if
condition|(
name|sm
operator|==
name|Smooth
condition|)
block|{
name|geom
operator|->
name|appendSmooth
argument_list|(
name|a
argument_list|,
name|norm
argument_list|,
name|initv
argument_list|)
expr_stmt|;
name|geom
operator|->
name|appendSmooth
argument_list|(
name|b
argument_list|,
name|norm
argument_list|,
name|initv
argument_list|)
expr_stmt|;
name|geom
operator|->
name|appendSmooth
argument_list|(
name|c
argument_list|,
name|norm
argument_list|,
name|initv
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|geom
operator|->
name|appendFaceted
argument_list|(
name|a
argument_list|,
name|norm
argument_list|)
expr_stmt|;
name|geom
operator|->
name|appendFaceted
argument_list|(
name|b
argument_list|,
name|norm
argument_list|)
expr_stmt|;
name|geom
operator|->
name|appendFaceted
argument_list|(
name|c
argument_list|,
name|norm
argument_list|)
expr_stmt|;
block|}
name|count
operator|+=
literal|3
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addQuad
name|void
name|Patch
operator|::
name|addQuad
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|b
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|c
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|d
parameter_list|)
block|{
name|QVector3D
name|norm
init|=
name|QVector3D
operator|::
name|normal
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
decl_stmt|;
if|if
condition|(
name|sm
operator|==
name|Smooth
condition|)
block|{
name|addTri
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|norm
argument_list|)
expr_stmt|;
name|addTri
argument_list|(
name|a
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|norm
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// If faceted share the two common verts
name|addTri
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|norm
argument_list|)
expr_stmt|;
name|int
name|k
init|=
name|geom
operator|->
name|vertices
operator|.
name|count
argument_list|()
decl_stmt|;
name|geom
operator|->
name|appendSmooth
argument_list|(
name|a
argument_list|,
name|norm
argument_list|,
name|k
argument_list|)
expr_stmt|;
name|geom
operator|->
name|appendSmooth
argument_list|(
name|c
argument_list|,
name|norm
argument_list|,
name|k
argument_list|)
expr_stmt|;
name|geom
operator|->
name|appendFaceted
argument_list|(
name|d
argument_list|,
name|norm
argument_list|)
expr_stmt|;
name|count
operator|+=
literal|3
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|extrude
specifier|static
specifier|inline
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|extrude
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|QVector3D
argument_list|>
modifier|&
name|verts
parameter_list|,
name|qreal
name|depth
parameter_list|)
block|{
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|extr
init|=
name|verts
decl_stmt|;
for|for
control|(
name|int
name|v
init|=
literal|0
init|;
name|v
operator|<
name|extr
operator|.
name|count
argument_list|()
condition|;
operator|++
name|v
control|)
name|extr
index|[
name|v
index|]
operator|.
name|setZ
argument_list|(
name|extr
index|[
name|v
index|]
operator|.
name|z
argument_list|()
operator|-
name|depth
argument_list|)
expr_stmt|;
return|return
name|extr
return|;
block|}
end_function
begin_class
DECL|class|Rectoid
class|class
name|Rectoid
block|{
public|public:
DECL|function|translate
name|void
name|translate
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|t
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|parts
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|parts
index|[
name|i
index|]
operator|->
name|translate
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
DECL|function|rotate
name|void
name|rotate
parameter_list|(
name|qreal
name|deg
parameter_list|,
name|QVector3D
name|axis
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|parts
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|parts
index|[
name|i
index|]
operator|->
name|rotate
argument_list|(
name|deg
argument_list|,
name|axis
argument_list|)
expr_stmt|;
block|}
comment|// No special Rectoid destructor - the parts are fetched out of this member
comment|// variable, and destroyed by the new owner
DECL|member|parts
name|QList
argument_list|<
name|Patch
modifier|*
argument_list|>
name|parts
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|RectPrism
class|class
name|RectPrism
super|:
specifier|public
name|Rectoid
block|{
public|public:
name|RectPrism
parameter_list|(
name|Geometry
modifier|*
name|g
parameter_list|,
name|qreal
name|width
parameter_list|,
name|qreal
name|height
parameter_list|,
name|qreal
name|depth
parameter_list|)
constructor_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|RectPrism
name|RectPrism
operator|::
name|RectPrism
parameter_list|(
name|Geometry
modifier|*
name|g
parameter_list|,
name|qreal
name|width
parameter_list|,
name|qreal
name|height
parameter_list|,
name|qreal
name|depth
parameter_list|)
block|{
enum|enum
block|{
name|bl
block|,
name|br
block|,
name|tr
block|,
name|tl
block|}
enum|;
name|Patch
modifier|*
name|fb
init|=
operator|new
name|Patch
argument_list|(
name|g
argument_list|)
decl_stmt|;
name|fb
operator|->
name|setSmoothing
argument_list|(
name|Patch
operator|::
name|Faceted
argument_list|)
expr_stmt|;
comment|// front face
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|r
argument_list|(
literal|4
argument_list|)
decl_stmt|;
name|r
index|[
name|br
index|]
operator|.
name|setX
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|r
index|[
name|tr
index|]
operator|.
name|setX
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|r
index|[
name|tr
index|]
operator|.
name|setY
argument_list|(
name|height
argument_list|)
expr_stmt|;
name|r
index|[
name|tl
index|]
operator|.
name|setY
argument_list|(
name|height
argument_list|)
expr_stmt|;
name|QVector3D
name|adjToCenter
argument_list|(
operator|-
name|width
operator|/
literal|2.0
argument_list|,
operator|-
name|height
operator|/
literal|2.0
argument_list|,
name|depth
operator|/
literal|2.0
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
name|r
index|[
name|i
index|]
operator|+=
name|adjToCenter
expr_stmt|;
name|fb
operator|->
name|addQuad
argument_list|(
name|r
index|[
name|bl
index|]
argument_list|,
name|r
index|[
name|br
index|]
argument_list|,
name|r
index|[
name|tr
index|]
argument_list|,
name|r
index|[
name|tl
index|]
argument_list|)
expr_stmt|;
comment|// back face
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|s
init|=
name|extrude
argument_list|(
name|r
argument_list|,
name|depth
argument_list|)
decl_stmt|;
name|fb
operator|->
name|addQuad
argument_list|(
name|s
index|[
name|tl
index|]
argument_list|,
name|s
index|[
name|tr
index|]
argument_list|,
name|s
index|[
name|br
index|]
argument_list|,
name|s
index|[
name|bl
index|]
argument_list|)
expr_stmt|;
comment|// side faces
name|Patch
modifier|*
name|sides
init|=
operator|new
name|Patch
argument_list|(
name|g
argument_list|)
decl_stmt|;
name|sides
operator|->
name|setSmoothing
argument_list|(
name|Patch
operator|::
name|Faceted
argument_list|)
expr_stmt|;
name|sides
operator|->
name|addQuad
argument_list|(
name|s
index|[
name|bl
index|]
argument_list|,
name|s
index|[
name|br
index|]
argument_list|,
name|r
index|[
name|br
index|]
argument_list|,
name|r
index|[
name|bl
index|]
argument_list|)
expr_stmt|;
name|sides
operator|->
name|addQuad
argument_list|(
name|s
index|[
name|br
index|]
argument_list|,
name|s
index|[
name|tr
index|]
argument_list|,
name|r
index|[
name|tr
index|]
argument_list|,
name|r
index|[
name|br
index|]
argument_list|)
expr_stmt|;
name|sides
operator|->
name|addQuad
argument_list|(
name|s
index|[
name|tr
index|]
argument_list|,
name|s
index|[
name|tl
index|]
argument_list|,
name|r
index|[
name|tl
index|]
argument_list|,
name|r
index|[
name|tr
index|]
argument_list|)
expr_stmt|;
name|sides
operator|->
name|addQuad
argument_list|(
name|s
index|[
name|tl
index|]
argument_list|,
name|s
index|[
name|bl
index|]
argument_list|,
name|r
index|[
name|bl
index|]
argument_list|,
name|r
index|[
name|tl
index|]
argument_list|)
expr_stmt|;
name|parts
operator|<<
name|fb
operator|<<
name|sides
expr_stmt|;
block|}
end_constructor
begin_class
DECL|class|RectTorus
class|class
name|RectTorus
super|:
specifier|public
name|Rectoid
block|{
public|public:
name|RectTorus
parameter_list|(
name|Geometry
modifier|*
name|g
parameter_list|,
name|qreal
name|iRad
parameter_list|,
name|qreal
name|oRad
parameter_list|,
name|qreal
name|depth
parameter_list|,
name|int
name|numSectors
parameter_list|)
constructor_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|RectTorus
name|RectTorus
operator|::
name|RectTorus
parameter_list|(
name|Geometry
modifier|*
name|g
parameter_list|,
name|qreal
name|iRad
parameter_list|,
name|qreal
name|oRad
parameter_list|,
name|qreal
name|depth
parameter_list|,
name|int
name|k
parameter_list|)
block|{
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|inside
decl_stmt|;
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|outside
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|k
condition|;
operator|++
name|i
control|)
block|{
name|qreal
name|angle
init|=
operator|(
name|i
operator|*
literal|2
operator|*
name|M_PI
operator|)
operator|/
name|k
decl_stmt|;
name|inside
operator|<<
name|QVector3D
argument_list|(
name|iRad
operator|*
name|qSin
argument_list|(
name|angle
argument_list|)
argument_list|,
name|iRad
operator|*
name|qCos
argument_list|(
name|angle
argument_list|)
argument_list|,
name|depth
operator|/
literal|2.0
argument_list|)
expr_stmt|;
name|outside
operator|<<
name|QVector3D
argument_list|(
name|oRad
operator|*
name|qSin
argument_list|(
name|angle
argument_list|)
argument_list|,
name|oRad
operator|*
name|qCos
argument_list|(
name|angle
argument_list|)
argument_list|,
name|depth
operator|/
literal|2.0
argument_list|)
expr_stmt|;
block|}
name|inside
operator|<<
name|QVector3D
argument_list|(
literal|0.0
argument_list|,
name|iRad
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|outside
operator|<<
name|QVector3D
argument_list|(
literal|0.0
argument_list|,
name|oRad
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|in_back
init|=
name|extrude
argument_list|(
name|inside
argument_list|,
name|depth
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QVector3D
argument_list|>
name|out_back
init|=
name|extrude
argument_list|(
name|outside
argument_list|,
name|depth
argument_list|)
decl_stmt|;
comment|// Create front, back and sides as separate patches so that smooth normals
comment|// are generated for the curving sides, but a faceted edge is created between
comment|// sides and front/back
name|Patch
modifier|*
name|front
init|=
operator|new
name|Patch
argument_list|(
name|g
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|k
condition|;
operator|++
name|i
control|)
name|front
operator|->
name|addQuad
argument_list|(
name|outside
index|[
name|i
index|]
argument_list|,
name|inside
index|[
name|i
index|]
argument_list|,
name|inside
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|k
index|]
argument_list|,
name|outside
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|k
index|]
argument_list|)
expr_stmt|;
name|Patch
modifier|*
name|back
init|=
operator|new
name|Patch
argument_list|(
name|g
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|k
condition|;
operator|++
name|i
control|)
name|back
operator|->
name|addQuad
argument_list|(
name|in_back
index|[
name|i
index|]
argument_list|,
name|out_back
index|[
name|i
index|]
argument_list|,
name|out_back
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|k
index|]
argument_list|,
name|in_back
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|k
index|]
argument_list|)
expr_stmt|;
name|Patch
modifier|*
name|is
init|=
operator|new
name|Patch
argument_list|(
name|g
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|k
condition|;
operator|++
name|i
control|)
name|is
operator|->
name|addQuad
argument_list|(
name|in_back
index|[
name|i
index|]
argument_list|,
name|in_back
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|k
index|]
argument_list|,
name|inside
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|k
index|]
argument_list|,
name|inside
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|Patch
modifier|*
name|os
init|=
operator|new
name|Patch
argument_list|(
name|g
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|k
condition|;
operator|++
name|i
control|)
name|os
operator|->
name|addQuad
argument_list|(
name|out_back
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|k
index|]
argument_list|,
name|out_back
index|[
name|i
index|]
argument_list|,
name|outside
index|[
name|i
index|]
argument_list|,
name|outside
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|k
index|]
argument_list|)
expr_stmt|;
name|parts
operator|<<
name|front
operator|<<
name|back
operator|<<
name|is
operator|<<
name|os
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QtLogo
name|QtLogo
operator|::
name|QtLogo
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|,
name|int
name|divisions
parameter_list|,
name|qreal
name|scale
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|geom
argument_list|(
operator|new
name|Geometry
argument_list|()
argument_list|)
block|{
name|buildGeometry
argument_list|(
name|divisions
argument_list|,
name|scale
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QtLogo
name|QtLogo
operator|::
name|~
name|QtLogo
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|parts
argument_list|)
expr_stmt|;
operator|delete
name|geom
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setColor
name|void
name|QtLogo
operator|::
name|setColor
parameter_list|(
name|QColor
name|c
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|parts
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|qSetColor
argument_list|(
name|parts
index|[
name|i
index|]
operator|->
name|faceColor
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|buildGeometry
name|void
name|QtLogo
operator|::
name|buildGeometry
parameter_list|(
name|int
name|divisions
parameter_list|,
name|qreal
name|scale
parameter_list|)
block|{
name|qreal
name|cw
init|=
name|cross_width
operator|*
name|scale
decl_stmt|;
name|qreal
name|bt
init|=
name|bar_thickness
operator|*
name|scale
decl_stmt|;
name|qreal
name|ld
init|=
name|logo_depth
operator|*
name|scale
decl_stmt|;
name|qreal
name|th
init|=
name|tee_height
operator|*
name|scale
decl_stmt|;
name|RectPrism
name|cross
argument_list|(
name|geom
argument_list|,
name|cw
argument_list|,
name|bt
argument_list|,
name|ld
argument_list|)
decl_stmt|;
name|RectPrism
name|stem
argument_list|(
name|geom
argument_list|,
name|bt
argument_list|,
name|th
argument_list|,
name|ld
argument_list|)
decl_stmt|;
name|QVector3D
name|z
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|1.0
argument_list|)
decl_stmt|;
name|cross
operator|.
name|rotate
argument_list|(
literal|45.0
argument_list|,
name|z
argument_list|)
expr_stmt|;
name|stem
operator|.
name|rotate
argument_list|(
literal|45.0
argument_list|,
name|z
argument_list|)
expr_stmt|;
name|qreal
name|stem_downshift
init|=
operator|(
name|th
operator|+
name|bt
operator|)
operator|/
literal|2.0
decl_stmt|;
name|stem
operator|.
name|translate
argument_list|(
name|QVector3D
argument_list|(
literal|0.0
argument_list|,
operator|-
name|stem_downshift
argument_list|,
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|RectTorus
name|body
argument_list|(
name|geom
argument_list|,
literal|0.20
argument_list|,
literal|0.30
argument_list|,
literal|0.1
argument_list|,
name|divisions
argument_list|)
decl_stmt|;
name|parts
operator|<<
name|stem
operator|.
name|parts
operator|<<
name|cross
operator|.
name|parts
operator|<<
name|body
operator|.
name|parts
expr_stmt|;
name|geom
operator|->
name|finalize
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|draw
name|void
name|QtLogo
operator|::
name|draw
parameter_list|()
specifier|const
block|{
name|geom
operator|->
name|loadArrays
argument_list|()
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_VERTEX_ARRAY
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_NORMAL_ARRAY
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|parts
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|parts
index|[
name|i
index|]
operator|->
name|draw
argument_list|()
expr_stmt|;
name|glDisableClientState
argument_list|(
name|GL_VERTEX_ARRAY
argument_list|)
expr_stmt|;
name|glDisableClientState
argument_list|(
name|GL_NORMAL_ARRAY
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
