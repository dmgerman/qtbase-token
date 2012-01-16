begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CARD_H
end_ifndef
begin_define
DECL|macro|CARD_H
define|#
directive|define
name|CARD_H
end_define
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_class
DECL|class|CardLayout
class|class
name|CardLayout
super|:
specifier|public
name|QLayout
block|{
public|public:
DECL|function|CardLayout
name|CardLayout
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|int
name|dist
parameter_list|)
member_init_list|:
name|QLayout
argument_list|(
name|parent
argument_list|,
literal|0
argument_list|,
name|dist
argument_list|)
block|{}
DECL|function|CardLayout
name|CardLayout
parameter_list|(
name|QLayout
modifier|*
name|parent
parameter_list|,
name|int
name|dist
parameter_list|)
member_init_list|:
name|QLayout
argument_list|(
name|parent
argument_list|,
name|dist
argument_list|)
block|{}
DECL|function|CardLayout
name|CardLayout
parameter_list|(
name|int
name|dist
parameter_list|)
member_init_list|:
name|QLayout
argument_list|(
name|dist
argument_list|)
block|{}
name|~
name|CardLayout
parameter_list|()
destructor_decl|;
name|void
name|addItem
parameter_list|(
name|QLayoutItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|QSize
name|sizeHint
parameter_list|()
specifier|const
function_decl|;
name|QSize
name|minimumSize
parameter_list|()
specifier|const
function_decl|;
name|QLayoutItem
modifier|*
name|count
parameter_list|()
specifier|const
function_decl|;
name|QLayoutItem
modifier|*
name|itemAt
parameter_list|(
name|int
parameter_list|)
specifier|const
function_decl|;
name|QLayoutItem
modifier|*
name|takeAt
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
private|private:
DECL|member|list
name|QList
argument_list|<
name|QLayoutItem
modifier|*
argument_list|>
name|list
decl_stmt|;
block|}
class|;
end_class
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//#include "card.h"
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|count
name|QLayoutItem
modifier|*
name|CardLayout
operator|::
name|count
parameter_list|()
specifier|const
block|{
comment|// QList::size() returns the number of QLayoutItems in the list
return|return
name|list
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|itemAt
name|QLayoutItem
modifier|*
name|CardLayout
operator|::
name|itemAt
parameter_list|(
name|int
name|idx
parameter_list|)
specifier|const
block|{
comment|// QList::value() performs index checking, and returns 0 if we are
comment|// outside the valid range
return|return
name|list
operator|.
name|value
argument_list|(
name|idx
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|takeAt
name|QLayoutItem
modifier|*
name|CardLayout
operator|::
name|takeAt
parameter_list|(
name|int
name|idx
parameter_list|)
block|{
comment|// QList::take does not do index checking
return|return
name|idx
operator|>=
literal|0
operator|&&
name|idx
operator|<
name|list
operator|.
name|size
argument_list|()
condition|?
name|list
operator|.
name|takeAt
argument_list|(
name|idx
argument_list|)
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|addItem
name|void
name|CardLayout
operator|::
name|addItem
parameter_list|(
name|QLayoutItem
modifier|*
name|item
parameter_list|)
block|{
name|list
operator|.
name|append
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_destructor
DECL|function|~CardLayout
name|CardLayout
operator|::
name|~
name|CardLayout
parameter_list|()
block|{
name|QLayoutItem
modifier|*
name|item
decl_stmt|;
while|while
condition|(
operator|(
name|item
operator|=
name|takeAt
argument_list|(
literal|0
argument_list|)
operator|)
condition|)
operator|delete
name|item
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|setGeometry
name|void
name|CardLayout
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
block|{
name|QLayout
operator|::
name|setGeometry
argument_list|(
name|r
argument_list|)
expr_stmt|;
if|if
condition|(
name|list
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
return|return;
name|int
name|w
init|=
name|r
operator|.
name|width
argument_list|()
operator|-
operator|(
name|list
operator|.
name|count
argument_list|()
operator|-
literal|1
operator|)
operator|*
name|spacing
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|r
operator|.
name|height
argument_list|()
operator|-
operator|(
name|list
operator|.
name|count
argument_list|()
operator|-
literal|1
operator|)
operator|*
name|spacing
argument_list|()
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|list
operator|.
name|size
argument_list|()
condition|)
block|{
name|QLayoutItem
modifier|*
name|o
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QRect
name|geom
argument_list|(
name|r
operator|.
name|x
argument_list|()
operator|+
name|i
operator|*
name|spacing
argument_list|()
argument_list|,
name|r
operator|.
name|y
argument_list|()
operator|+
name|i
operator|*
name|spacing
argument_list|()
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
decl_stmt|;
name|o
operator|->
name|setGeometry
argument_list|(
name|geom
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|CardLayout
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|QSize
name|s
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|n
init|=
name|list
operator|.
name|count
argument_list|()
decl_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
name|s
operator|=
name|QSize
argument_list|(
literal|100
argument_list|,
literal|70
argument_list|)
expr_stmt|;
comment|//start with a nice default size
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|n
condition|)
block|{
name|QLayoutItem
modifier|*
name|o
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|s
operator|=
name|s
operator|.
name|expandedTo
argument_list|(
name|o
operator|->
name|sizeHint
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
return|return
name|s
operator|+
name|n
operator|*
name|QSize
argument_list|(
name|spacing
argument_list|()
argument_list|,
name|spacing
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|minimumSize
name|QSize
name|CardLayout
operator|::
name|minimumSize
parameter_list|()
specifier|const
block|{
name|QSize
name|s
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|n
init|=
name|list
operator|.
name|count
argument_list|()
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|n
condition|)
block|{
name|QLayoutItem
modifier|*
name|o
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|s
operator|=
name|s
operator|.
name|expandedTo
argument_list|(
name|o
operator|->
name|minimumSize
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
return|return
name|s
operator|+
name|n
operator|*
name|QSize
argument_list|(
name|spacing
argument_list|()
argument_list|,
name|spacing
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
end_unit
