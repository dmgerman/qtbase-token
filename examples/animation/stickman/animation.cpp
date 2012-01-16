begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"animation.h"
end_include
begin_include
include|#
directive|include
file|<QPointF>
end_include
begin_include
include|#
directive|include
file|<QIODevice>
end_include
begin_include
include|#
directive|include
file|<QDataStream>
end_include
begin_class
DECL|class|Frame
class|class
name|Frame
block|{
public|public:
DECL|function|Frame
name|Frame
parameter_list|()
block|{     }
DECL|function|nodeCount
name|int
name|nodeCount
parameter_list|()
specifier|const
block|{
return|return
name|m_nodePositions
operator|.
name|size
argument_list|()
return|;
block|}
DECL|function|setNodeCount
name|void
name|setNodeCount
parameter_list|(
name|int
name|nodeCount
parameter_list|)
block|{
while|while
condition|(
name|nodeCount
operator|>
name|m_nodePositions
operator|.
name|size
argument_list|()
condition|)
name|m_nodePositions
operator|.
name|append
argument_list|(
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|nodeCount
operator|<
name|m_nodePositions
operator|.
name|size
argument_list|()
condition|)
name|m_nodePositions
operator|.
name|removeLast
argument_list|()
expr_stmt|;
block|}
DECL|function|nodePos
name|QPointF
name|nodePos
parameter_list|(
name|int
name|idx
parameter_list|)
specifier|const
block|{
return|return
name|m_nodePositions
operator|.
name|at
argument_list|(
name|idx
argument_list|)
return|;
block|}
DECL|function|setNodePos
name|void
name|setNodePos
parameter_list|(
name|int
name|idx
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|pos
parameter_list|)
block|{
name|m_nodePositions
index|[
name|idx
index|]
operator|=
name|pos
expr_stmt|;
block|}
private|private:
DECL|member|m_nodePositions
name|QList
argument_list|<
name|QPointF
argument_list|>
name|m_nodePositions
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|Animation
name|Animation
operator|::
name|Animation
parameter_list|()
block|{
name|m_currentFrame
operator|=
literal|0
expr_stmt|;
name|m_frames
operator|.
name|append
argument_list|(
operator|new
name|Frame
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Animation
name|Animation
operator|::
name|~
name|Animation
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|m_frames
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setTotalFrames
name|void
name|Animation
operator|::
name|setTotalFrames
parameter_list|(
name|int
name|totalFrames
parameter_list|)
block|{
while|while
condition|(
name|m_frames
operator|.
name|size
argument_list|()
operator|<
name|totalFrames
condition|)
name|m_frames
operator|.
name|append
argument_list|(
operator|new
name|Frame
argument_list|)
expr_stmt|;
while|while
condition|(
name|totalFrames
operator|<
name|m_frames
operator|.
name|size
argument_list|()
condition|)
operator|delete
name|m_frames
operator|.
name|takeLast
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|totalFrames
name|int
name|Animation
operator|::
name|totalFrames
parameter_list|()
specifier|const
block|{
return|return
name|m_frames
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setCurrentFrame
name|void
name|Animation
operator|::
name|setCurrentFrame
parameter_list|(
name|int
name|currentFrame
parameter_list|)
block|{
name|m_currentFrame
operator|=
name|qMax
argument_list|(
name|qMin
argument_list|(
name|currentFrame
argument_list|,
name|totalFrames
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentFrame
name|int
name|Animation
operator|::
name|currentFrame
parameter_list|()
specifier|const
block|{
return|return
name|m_currentFrame
return|;
block|}
end_function
begin_function
DECL|function|setNodeCount
name|void
name|Animation
operator|::
name|setNodeCount
parameter_list|(
name|int
name|nodeCount
parameter_list|)
block|{
name|Frame
modifier|*
name|frame
init|=
name|m_frames
operator|.
name|at
argument_list|(
name|m_currentFrame
argument_list|)
decl_stmt|;
name|frame
operator|->
name|setNodeCount
argument_list|(
name|nodeCount
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nodeCount
name|int
name|Animation
operator|::
name|nodeCount
parameter_list|()
specifier|const
block|{
name|Frame
modifier|*
name|frame
init|=
name|m_frames
operator|.
name|at
argument_list|(
name|m_currentFrame
argument_list|)
decl_stmt|;
return|return
name|frame
operator|->
name|nodeCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setNodePos
name|void
name|Animation
operator|::
name|setNodePos
parameter_list|(
name|int
name|idx
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|pos
parameter_list|)
block|{
name|Frame
modifier|*
name|frame
init|=
name|m_frames
operator|.
name|at
argument_list|(
name|m_currentFrame
argument_list|)
decl_stmt|;
name|frame
operator|->
name|setNodePos
argument_list|(
name|idx
argument_list|,
name|pos
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nodePos
name|QPointF
name|Animation
operator|::
name|nodePos
parameter_list|(
name|int
name|idx
parameter_list|)
specifier|const
block|{
name|Frame
modifier|*
name|frame
init|=
name|m_frames
operator|.
name|at
argument_list|(
name|m_currentFrame
argument_list|)
decl_stmt|;
return|return
name|frame
operator|->
name|nodePos
argument_list|(
name|idx
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|Animation
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
end_function
begin_function
DECL|function|setName
name|void
name|Animation
operator|::
name|setName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|m_name
operator|=
name|name
expr_stmt|;
block|}
end_function
begin_function
DECL|function|save
name|void
name|Animation
operator|::
name|save
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
specifier|const
block|{
name|QDataStream
name|stream
argument_list|(
name|device
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|m_name
expr_stmt|;
name|stream
operator|<<
name|m_frames
operator|.
name|size
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|Frame
modifier|*
name|frame
decl|,
name|m_frames
control|)
block|{
name|stream
operator|<<
name|frame
operator|->
name|nodeCount
argument_list|()
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
name|frame
operator|->
name|nodeCount
argument_list|()
condition|;
operator|++
name|i
control|)
name|stream
operator|<<
name|frame
operator|->
name|nodePos
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|load
name|void
name|Animation
operator|::
name|load
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_frames
operator|.
name|isEmpty
argument_list|()
condition|)
name|qDeleteAll
argument_list|(
name|m_frames
argument_list|)
expr_stmt|;
name|m_frames
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QDataStream
name|stream
argument_list|(
name|device
argument_list|)
decl_stmt|;
name|stream
operator|>>
name|m_name
expr_stmt|;
name|int
name|frameCount
decl_stmt|;
name|stream
operator|>>
name|frameCount
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
name|frameCount
condition|;
operator|++
name|i
control|)
block|{
name|int
name|nodeCount
decl_stmt|;
name|stream
operator|>>
name|nodeCount
expr_stmt|;
name|Frame
modifier|*
name|frame
init|=
operator|new
name|Frame
decl_stmt|;
name|frame
operator|->
name|setNodeCount
argument_list|(
name|nodeCount
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|nodeCount
condition|;
operator|++
name|j
control|)
block|{
name|QPointF
name|pos
decl_stmt|;
name|stream
operator|>>
name|pos
expr_stmt|;
name|frame
operator|->
name|setNodePos
argument_list|(
name|j
argument_list|,
name|pos
argument_list|)
expr_stmt|;
block|}
name|m_frames
operator|.
name|append
argument_list|(
name|frame
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
