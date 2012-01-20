begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTRIANGULATOR_P_H
end_ifndef
begin_define
DECL|macro|QTRIANGULATOR_P_H
define|#
directive|define
name|QTRIANGULATOR_P_H
end_define
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
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qvectorpath_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QVertexIndexVector
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|UnsignedInt
block|,
name|UnsignedShort
block|}
enum|;
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|t
return|;
block|}
specifier|inline
name|void
name|setDataUint
argument_list|(
specifier|const
name|QVector
operator|<
name|quint32
operator|>
operator|&
name|data
argument_list|)
block|{
name|t
operator|=
name|UnsignedInt
expr_stmt|;
name|indices32
operator|=
name|data
expr_stmt|;
block|}
specifier|inline
name|void
name|setDataUshort
argument_list|(
specifier|const
name|QVector
operator|<
name|quint16
operator|>
operator|&
name|data
argument_list|)
block|{
name|t
operator|=
name|UnsignedShort
expr_stmt|;
name|indices16
operator|=
name|data
expr_stmt|;
block|}
specifier|inline
specifier|const
name|void
operator|*
name|data
argument_list|()
specifier|const
block|{
if|if
condition|(
name|t
operator|==
name|UnsignedInt
condition|)
return|return
name|indices32
operator|.
name|data
argument_list|()
return|;
return|return
name|indices16
operator|.
name|data
argument_list|()
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
if|if
condition|(
name|t
operator|==
name|UnsignedInt
condition|)
return|return
name|indices32
operator|.
name|size
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|indices16
operator|.
name|size
argument_list|()
return|;
end_return
begin_decl_stmt
unit|}      inline
name|QVertexIndexVector
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QVertexIndexVector
operator|&
name|other
operator|)
block|{
if|if
condition|(
name|t
operator|==
name|UnsignedInt
condition|)
name|indices32
operator|=
name|other
operator|.
name|indices32
expr_stmt|;
else|else
name|indices16
operator|=
name|other
operator|.
name|indices16
expr_stmt|;
end_decl_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_decl_stmt
unit|}  private:
name|Type
name|t
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QVector
operator|<
name|quint32
operator|>
name|indices32
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVector
operator|<
name|quint16
operator|>
name|indices16
expr_stmt|;
end_expr_stmt
begin_struct
DECL|struct|QTriangleSet
unit|};
struct|struct
name|Q_GUI_EXPORT
name|QTriangleSet
block|{
DECL|function|QTriangleSet
specifier|inline
name|QTriangleSet
argument_list|()
block|{ }
DECL|function|QTriangleSet
specifier|inline
name|QTriangleSet
argument_list|(
specifier|const
name|QTriangleSet
operator|&
name|other
argument_list|)
operator|:
name|vertices
argument_list|(
name|other
operator|.
name|vertices
argument_list|)
operator|,
name|indices
argument_list|(
argument|other.indices
argument_list|)
block|{ }
DECL|member|operator
name|QTriangleSet
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QTriangleSet
operator|&
name|other
operator|)
block|{
name|vertices
operator|=
name|other
operator|.
name|vertices
block|;
name|indices
operator|=
name|other
operator|.
name|indices
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// The vertices of a triangle are given by: (x[i[n]], y[i[n]]), (x[j[n]], y[j[n]]), (x[k[n]], y[k[n]]), n = 0, 1, ...
name|QVector
operator|<
name|qreal
operator|>
name|vertices
expr_stmt|;
comment|// [x[0], y[0], x[1], y[1], x[2], ...]
DECL|member|indices
name|QVertexIndexVector
name|indices
decl_stmt|;
comment|// [i[0], j[0], k[0], i[1], j[1], k[1], i[2], ...]
block|}
struct|;
end_struct
begin_struct
DECL|struct|QPolylineSet
struct|struct
name|Q_GUI_EXPORT
name|QPolylineSet
block|{
DECL|function|QPolylineSet
specifier|inline
name|QPolylineSet
argument_list|()
block|{ }
DECL|function|QPolylineSet
specifier|inline
name|QPolylineSet
argument_list|(
specifier|const
name|QPolylineSet
operator|&
name|other
argument_list|)
operator|:
name|vertices
argument_list|(
name|other
operator|.
name|vertices
argument_list|)
operator|,
name|indices
argument_list|(
argument|other.indices
argument_list|)
block|{ }
DECL|member|operator
name|QPolylineSet
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPolylineSet
operator|&
name|other
operator|)
block|{
name|vertices
operator|=
name|other
operator|.
name|vertices
block|;
name|indices
operator|=
name|other
operator|.
name|indices
block|;
return|return
operator|*
name|this
return|;
block|}
name|QVector
operator|<
name|qreal
operator|>
name|vertices
expr_stmt|;
comment|// [x[0], y[0], x[1], y[1], x[2], ...]
DECL|member|indices
name|QVertexIndexVector
name|indices
decl_stmt|;
comment|// End of polyline is marked with -1.
block|}
struct|;
end_struct
begin_comment
comment|// The vertex coordinates of the returned triangle set will be rounded to a grid with a mesh size
end_comment
begin_comment
comment|// of 1/32. The polygon is first transformed, then scaled by 32, the coordinates are rounded to
end_comment
begin_comment
comment|// integers, the polygon is triangulated, and then scaled back by 1/32.
end_comment
begin_comment
comment|// 'hint' should be a combination of QVectorPath::Hints.
end_comment
begin_comment
comment|// 'lod' is the level of detail. Default is 1. Curves are split into more lines when 'lod' is higher.
end_comment
begin_function_decl
name|QTriangleSet
name|Q_GUI_EXPORT
name|qTriangulate
parameter_list|(
specifier|const
name|qreal
modifier|*
name|polygon
parameter_list|,
name|int
name|count
parameter_list|,
name|uint
name|hint
init|=
name|QVectorPath
operator|::
name|PolygonHint
operator||
name|QVectorPath
operator|::
name|OddEvenFill
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
init|=
name|QTransform
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QTriangleSet
name|Q_GUI_EXPORT
name|qTriangulate
parameter_list|(
specifier|const
name|QVectorPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
init|=
name|QTransform
argument_list|()
parameter_list|,
name|qreal
name|lod
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QTriangleSet
name|Q_GUI_EXPORT
name|qTriangulate
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
init|=
name|QTransform
argument_list|()
parameter_list|,
name|qreal
name|lod
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QPolylineSet
name|qPolyline
parameter_list|(
specifier|const
name|QVectorPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
init|=
name|QTransform
argument_list|()
parameter_list|,
name|qreal
name|lod
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QPolylineSet
name|Q_GUI_EXPORT
name|qPolyline
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
init|=
name|QTransform
argument_list|()
parameter_list|,
name|qreal
name|lod
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
