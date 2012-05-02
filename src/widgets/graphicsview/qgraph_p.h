begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPH_P_H
end_ifndef
begin_define
DECL|macro|QGRAPH_P_H
define|#
directive|define
name|QGRAPH_P_H
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
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QQueue>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Vertex
name|template
operator|<
name|typename
name|Vertex
operator|,
name|typename
name|EdgeData
operator|>
name|class
name|Graph
block|{
name|public
operator|:
name|Graph
argument_list|()
block|{}
name|class
name|const_iterator
block|{
name|public
operator|:
name|const_iterator
argument_list|(
argument|const Graph *graph
argument_list|,
argument|bool begin
argument_list|)
operator|:
name|g
argument_list|(
argument|graph
argument_list|)
block|{
if|if
condition|(
name|begin
condition|)
block|{
name|row
operator|=
name|g
operator|->
name|m_graph
operator|.
name|constBegin
argument_list|()
expr_stmt|;
comment|//test if the graph is empty
if|if
condition|(
name|row
operator|!=
name|g
operator|->
name|m_graph
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|column
operator|=
operator|(
operator|*
name|row
operator|)
operator|->
name|constBegin
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|row
operator|=
name|g
operator|->
name|m_graph
operator|.
name|constEnd
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_function
unit|}          inline
name|Vertex
modifier|*
name|operator
modifier|*
parameter_list|()
block|{
return|return
name|column
operator|.
name|key
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|Vertex
operator|*
name|from
argument_list|()
specifier|const
block|{
return|return
name|row
operator|.
name|key
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|Vertex
operator|*
name|to
argument_list|()
specifier|const
block|{
return|return
name|column
operator|.
name|key
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|!=
name|o
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
if|if
condition|(
name|row
operator|==
name|g
operator|->
name|m_graph
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|row
operator|!=
name|o
operator|.
name|row
return|;
block|}
end_expr_stmt
begin_else
else|else
block|{
return|return
name|row
operator|!=
name|o
operator|.
name|row
operator|||
name|column
operator|!=
name|o
operator|.
name|column
return|;
block|}
end_else
begin_decl_stmt
unit|}         inline
name|const_iterator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
name|row
operator|=
name|o
operator|.
name|row
block|;
name|column
operator|=
name|o
operator|.
name|column
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_comment
comment|// prefix
end_comment
begin_expr_stmt
name|const_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
if|if
condition|(
name|row
operator|!=
name|g
operator|->
name|m_graph
operator|.
name|constEnd
argument_list|()
condition|)
block|{
operator|++
name|column
expr_stmt|;
if|if
condition|(
name|column
operator|==
operator|(
operator|*
name|row
operator|)
operator|->
name|constEnd
argument_list|()
condition|)
block|{
operator|++
name|row
expr_stmt|;
if|if
condition|(
name|row
operator|!=
name|g
operator|->
name|m_graph
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|column
operator|=
operator|(
operator|*
name|row
operator|)
operator|->
name|constBegin
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_return
unit|}             }
return|return
operator|*
name|this
return|;
end_return
begin_decl_stmt
unit|}      private:
specifier|const
name|Graph
modifier|*
name|g
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|typename
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|EdgeData
operator|*
operator|>
operator|*
operator|>
operator|::
name|const_iterator
name|row
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|typename
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|EdgeData
operator|*
operator|>
operator|::
name|const_iterator
name|column
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|const_iterator
name|constBegin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
name|true
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|const_iterator
name|constEnd
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
name|false
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|/*!      * \internal      *      * If there is an edge between \a first and \a second, it will return a structure      * containing the data associated with the edge, otherwise it will return 0.      *      */
end_comment
begin_function
name|EdgeData
modifier|*
name|edgeData
parameter_list|(
name|Vertex
modifier|*
name|first
parameter_list|,
name|Vertex
modifier|*
name|second
parameter_list|)
block|{
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|EdgeData
operator|*
operator|>
operator|*
name|row
operator|=
name|m_graph
operator|.
name|value
argument_list|(
name|first
argument_list|)
expr_stmt|;
return|return
name|row
condition|?
name|row
operator|->
name|value
argument_list|(
name|second
argument_list|)
else|:
literal|0
return|;
block|}
end_function
begin_function
name|void
name|createEdge
parameter_list|(
name|Vertex
modifier|*
name|first
parameter_list|,
name|Vertex
modifier|*
name|second
parameter_list|,
name|EdgeData
modifier|*
name|data
parameter_list|)
block|{
comment|// Creates a bidirectional edge
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
operator|&&
literal|0
name|qDebug
argument_list|(
literal|"Graph::createEdge(): %s"
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1-%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|first
operator|->
name|toString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|second
operator|->
name|toString
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|edgeData
argument_list|(
name|first
argument_list|,
name|second
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG
name|qWarning
argument_list|(
literal|"%s-%s already has an edge"
argument_list|,
name|qPrintable
argument_list|(
name|first
operator|->
name|toString
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|second
operator|->
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|createDirectedEdge
argument_list|(
name|first
argument_list|,
name|second
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|createDirectedEdge
argument_list|(
name|second
argument_list|,
name|first
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|removeEdge
parameter_list|(
name|Vertex
modifier|*
name|first
parameter_list|,
name|Vertex
modifier|*
name|second
parameter_list|)
block|{
comment|// Removes a bidirectional edge
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
operator|&&
literal|0
name|qDebug
argument_list|(
literal|"Graph::removeEdge(): %s"
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1-%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|first
operator|->
name|toString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|second
operator|->
name|toString
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|EdgeData
modifier|*
name|data
init|=
name|edgeData
argument_list|(
name|first
argument_list|,
name|second
argument_list|)
decl_stmt|;
name|removeDirectedEdge
argument_list|(
name|first
argument_list|,
name|second
argument_list|)
expr_stmt|;
name|removeDirectedEdge
argument_list|(
name|second
argument_list|,
name|first
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
condition|)
name|delete
name|data
decl_stmt|;
block|}
end_function
begin_function
name|EdgeData
modifier|*
name|takeEdge
parameter_list|(
name|Vertex
modifier|*
name|first
parameter_list|,
name|Vertex
modifier|*
name|second
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
operator|&&
literal|0
name|qDebug
argument_list|(
literal|"Graph::takeEdge(): %s"
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1-%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|first
operator|->
name|toString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|second
operator|->
name|toString
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Removes a bidirectional edge
name|EdgeData
modifier|*
name|data
init|=
name|edgeData
argument_list|(
name|first
argument_list|,
name|second
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
condition|)
block|{
name|removeDirectedEdge
argument_list|(
name|first
argument_list|,
name|second
argument_list|)
expr_stmt|;
name|removeDirectedEdge
argument_list|(
name|second
argument_list|,
name|first
argument_list|)
expr_stmt|;
block|}
return|return
name|data
return|;
block|}
end_function
begin_expr_stmt
name|QList
operator|<
name|Vertex
operator|*
operator|>
name|adjacentVertices
argument_list|(
argument|Vertex *vertex
argument_list|)
specifier|const
block|{
name|QHash
operator|<
name|Vertex
operator|*
block|,
name|EdgeData
operator|*
operator|>
operator|*
name|row
operator|=
name|m_graph
operator|.
name|value
argument_list|(
name|vertex
argument_list|)
block|;
name|QList
operator|<
name|Vertex
operator|*
operator|>
name|l
block|;
if|if
condition|(
name|row
condition|)
name|l
operator|=
name|row
operator|->
name|keys
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|l
return|;
end_return
begin_expr_stmt
unit|}      QSet
operator|<
name|Vertex
operator|*
operator|>
name|vertices
argument_list|()
specifier|const
block|{
name|QSet
operator|<
name|Vertex
operator|*
operator|>
name|setOfVertices
block|;
for|for
control|(
name|const_iterator
name|it
init|=
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|setOfVertices
operator|.
name|insert
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|setOfVertices
return|;
end_return
begin_expr_stmt
unit|}      QList
operator|<
name|QPair
operator|<
name|Vertex
operator|*
operator|,
name|Vertex
operator|*
operator|>
expr|>
name|connections
argument_list|()
specifier|const
block|{
name|QList
operator|<
name|QPair
operator|<
name|Vertex
operator|*
block|,
name|Vertex
operator|*
operator|>
expr|>
name|conns
block|;
for|for
control|(
name|const_iterator
name|it
init|=
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|Vertex
modifier|*
name|from
init|=
name|it
operator|.
name|from
argument_list|()
decl_stmt|;
name|Vertex
modifier|*
name|to
init|=
name|it
operator|.
name|to
argument_list|()
decl_stmt|;
comment|// do not return (from,to) *and* (to,from)
if|if
condition|(
name|from
operator|<
name|to
condition|)
block|{
name|conns
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|from
argument_list|,
name|to
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}         return
name|conns
expr_stmt|;
end_expr_stmt
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
end_if
begin_macro
unit|QString
name|serializeToDot
argument_list|()
end_macro
begin_block
block|{
comment|// traversal
name|QString
name|strVertices
decl_stmt|;
name|QString
name|edges
decl_stmt|;
name|QSet
operator|<
name|Vertex
operator|*
operator|>
name|setOfVertices
operator|=
name|vertices
argument_list|()
expr_stmt|;
for|for
control|(
name|typename
name|QSet
operator|<
name|Vertex
operator|*
operator|>
operator|::
name|const_iterator
name|it
operator|=
name|setOfVertices
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|setOfVertices
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|Vertex
modifier|*
name|v
init|=
operator|*
name|it
decl_stmt|;
name|QList
operator|<
name|Vertex
operator|*
operator|>
name|adjacents
operator|=
name|adjacentVertices
argument_list|(
name|v
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
name|adjacents
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|Vertex
modifier|*
name|v1
init|=
name|adjacents
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|EdgeData
modifier|*
name|data
init|=
name|edgeData
argument_list|(
name|v
argument_list|,
name|v1
argument_list|)
decl_stmt|;
name|bool
name|forward
init|=
name|data
operator|->
name|from
operator|==
name|v
decl_stmt|;
if|if
condition|(
name|forward
condition|)
block|{
name|edges
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\"%1\"->\"%2\" [label=\"[%3,%4,%5,%6,%7]\" color=\"#000000\"] \n"
argument_list|)
operator|.
name|arg
argument_list|(
name|v
operator|->
name|toString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|v1
operator|->
name|toString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|data
operator|->
name|minSize
argument_list|)
operator|.
name|arg
argument_list|(
name|data
operator|->
name|minPrefSize
argument_list|)
operator|.
name|arg
argument_list|(
name|data
operator|->
name|prefSize
argument_list|)
operator|.
name|arg
argument_list|(
name|data
operator|->
name|maxPrefSize
argument_list|)
operator|.
name|arg
argument_list|(
name|data
operator|->
name|maxSize
argument_list|)
expr_stmt|;
block|}
block|}
name|strVertices
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\"%1\" [label=\"%2\"]\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|v
operator|->
name|toString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|v
operator|->
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1\n%2\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|strVertices
argument_list|)
operator|.
name|arg
argument_list|(
name|edges
argument_list|)
return|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|protected
label|:
end_label
begin_function
name|void
name|createDirectedEdge
parameter_list|(
name|Vertex
modifier|*
name|from
parameter_list|,
name|Vertex
modifier|*
name|to
parameter_list|,
name|EdgeData
modifier|*
name|data
parameter_list|)
block|{
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|EdgeData
operator|*
operator|>
operator|*
name|adjacentToFirst
operator|=
name|m_graph
operator|.
name|value
argument_list|(
name|from
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|adjacentToFirst
condition|)
block|{
name|adjacentToFirst
operator|=
name|new
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|EdgeData
operator|*
operator|>
operator|(
operator|)
expr_stmt|;
name|m_graph
operator|.
name|insert
argument_list|(
name|from
argument_list|,
name|adjacentToFirst
argument_list|)
expr_stmt|;
block|}
name|adjacentToFirst
operator|->
name|insert
argument_list|(
name|to
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|removeDirectedEdge
parameter_list|(
name|Vertex
modifier|*
name|from
parameter_list|,
name|Vertex
modifier|*
name|to
parameter_list|)
block|{
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|EdgeData
operator|*
operator|>
operator|*
name|adjacentToFirst
operator|=
name|m_graph
operator|.
name|value
argument_list|(
name|from
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|adjacentToFirst
argument_list|)
expr_stmt|;
name|adjacentToFirst
operator|->
name|remove
argument_list|(
name|to
argument_list|)
expr_stmt|;
if|if
condition|(
name|adjacentToFirst
operator|->
name|isEmpty
argument_list|()
condition|)
block|{
comment|//nobody point to 'from' so we can remove it from the graph
name|m_graph
operator|.
name|remove
argument_list|(
name|from
argument_list|)
expr_stmt|;
name|delete
name|adjacentToFirst
decl_stmt|;
block|}
block|}
end_function
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|QHash
operator|<
name|Vertex
operator|*
operator|,
name|EdgeData
operator|*
operator|>
operator|*
operator|>
name|m_graph
expr_stmt|;
end_expr_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
