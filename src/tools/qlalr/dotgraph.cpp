begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"dotgraph.h"
end_include
begin_include
include|#
directive|include
file|"lalr.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_constructor
DECL|function|DotGraph
name|DotGraph
operator|::
name|DotGraph
parameter_list|(
name|QTextStream
modifier|&
name|o
parameter_list|)
member_init_list|:
name|out
argument_list|(
name|o
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|operator ()
name|void
name|DotGraph
operator|::
name|operator
name|()
parameter_list|(
name|Automaton
modifier|*
name|aut
parameter_list|)
block|{
name|Grammar
modifier|*
name|g
init|=
name|aut
operator|->
name|_M_grammar
decl_stmt|;
name|out
operator|<<
literal|"digraph {"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
name|out
operator|<<
literal|"subgraph Includes {"
operator|<<
name|endl
expr_stmt|;
for|for
control|(
name|Automaton
operator|::
name|IncludesGraph
operator|::
name|iterator
name|incl
init|=
name|Automaton
operator|::
name|IncludesGraph
operator|::
name|begin_nodes
argument_list|()
init|;
name|incl
operator|!=
name|Automaton
operator|::
name|IncludesGraph
operator|::
name|end_nodes
argument_list|()
condition|;
operator|++
name|incl
control|)
block|{
for|for
control|(
name|Automaton
operator|::
name|IncludesGraph
operator|::
name|edge_iterator
name|edge
init|=
name|incl
operator|->
name|begin
argument_list|()
init|;
name|edge
operator|!=
name|incl
operator|->
name|end
argument_list|()
condition|;
operator|++
name|edge
control|)
block|{
name|out
operator|<<
literal|"\t\"("
operator|<<
name|aut
operator|->
name|id
argument_list|(
name|incl
operator|->
name|data
operator|.
name|state
argument_list|)
operator|<<
literal|", "
operator|<<
name|incl
operator|->
name|data
operator|.
name|nt
operator|<<
literal|")\""
expr_stmt|;
name|out
operator|<<
literal|"\t->\t"
expr_stmt|;
name|out
operator|<<
literal|"\"("
operator|<<
name|aut
operator|->
name|id
argument_list|(
operator|(
operator|*
name|edge
operator|)
operator|->
name|data
operator|.
name|state
argument_list|)
operator|<<
literal|", "
operator|<<
operator|(
operator|*
name|edge
operator|)
operator|->
name|data
operator|.
name|nt
operator|<<
literal|")\"\t"
expr_stmt|;
name|out
operator|<<
literal|"[label=\""
operator|<<
name|incl
operator|->
name|data
operator|.
name|state
operator|->
name|follows
index|[
name|incl
operator|->
name|data
operator|.
name|nt
index|]
operator|<<
literal|"\"]"
expr_stmt|;
name|out
operator|<<
name|endl
expr_stmt|;
block|}
block|}
name|out
operator|<<
literal|"}"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
name|out
operator|<<
literal|"subgraph LRA {"
operator|<<
name|endl
expr_stmt|;
comment|//out<< "node [shape=record];"<< endl<< endl;
for|for
control|(
name|StatePointer
name|q
init|=
name|aut
operator|->
name|states
operator|.
name|begin
argument_list|()
init|;
name|q
operator|!=
name|aut
operator|->
name|states
operator|.
name|end
argument_list|()
condition|;
operator|++
name|q
control|)
block|{
name|int
name|state
init|=
name|aut
operator|->
name|id
argument_list|(
name|q
argument_list|)
decl_stmt|;
name|out
operator|<<
literal|"\t"
operator|<<
name|state
operator|<<
literal|"\t[shape=record,label=\"{"
expr_stmt|;
name|out
operator|<<
literal|"<0> State "
operator|<<
name|state
expr_stmt|;
name|int
name|index
init|=
literal|1
decl_stmt|;
for|for
control|(
name|ItemPointer
name|item
init|=
name|q
operator|->
name|kernel
operator|.
name|begin
argument_list|()
init|;
name|item
operator|!=
name|q
operator|->
name|kernel
operator|.
name|end
argument_list|()
condition|;
operator|++
name|item
control|)
name|out
operator|<<
literal|"|<"
operator|<<
name|index
operator|++
operator|<<
literal|"> "
operator|<<
operator|*
name|item
expr_stmt|;
name|out
operator|<<
literal|"}\"]"
operator|<<
name|endl
expr_stmt|;
for|for
control|(
name|Bundle
operator|::
name|iterator
name|a
init|=
name|q
operator|->
name|bundle
operator|.
name|begin
argument_list|()
init|;
name|a
operator|!=
name|q
operator|->
name|bundle
operator|.
name|end
argument_list|()
condition|;
operator|++
name|a
control|)
block|{
specifier|const
name|char
modifier|*
name|clr
init|=
name|g
operator|->
name|isTerminal
argument_list|(
name|a
operator|.
name|key
argument_list|()
argument_list|)
condition|?
literal|"blue"
else|:
literal|"red"
decl_stmt|;
name|out
operator|<<
literal|"\t"
operator|<<
name|state
operator|<<
literal|"\t->\t"
operator|<<
name|aut
operator|->
name|id
argument_list|(
operator|*
name|a
argument_list|)
operator|<<
literal|"\t[color=\""
operator|<<
name|clr
operator|<<
literal|"\",label=\""
operator|<<
name|a
operator|.
name|key
argument_list|()
operator|<<
literal|"\"]"
operator|<<
name|endl
expr_stmt|;
block|}
name|out
operator|<<
name|endl
expr_stmt|;
block|}
name|out
operator|<<
literal|"}"
operator|<<
name|endl
expr_stmt|;
name|out
operator|<<
name|endl
operator|<<
name|endl
operator|<<
literal|"}"
operator|<<
name|endl
expr_stmt|;
block|}
end_function
end_unit