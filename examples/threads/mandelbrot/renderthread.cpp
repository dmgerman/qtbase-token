begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|"renderthread.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|RenderThread
name|RenderThread
operator|::
name|RenderThread
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
block|{
name|restart
operator|=
literal|false
expr_stmt|;
name|abort
operator|=
literal|false
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
name|ColormapSize
condition|;
operator|++
name|i
control|)
name|colormap
index|[
name|i
index|]
operator|=
name|rgbFromWaveLength
argument_list|(
literal|380.0
operator|+
operator|(
name|i
operator|*
literal|400.0
operator|/
name|ColormapSize
operator|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_destructor
DECL|function|~RenderThread
name|RenderThread
operator|::
name|~
name|RenderThread
parameter_list|()
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|abort
operator|=
literal|true
expr_stmt|;
name|condition
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|wait
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|render
name|void
name|RenderThread
operator|::
name|render
parameter_list|(
name|double
name|centerX
parameter_list|,
name|double
name|centerY
parameter_list|,
name|double
name|scaleFactor
parameter_list|,
name|QSize
name|resultSize
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|this
operator|->
name|centerX
operator|=
name|centerX
expr_stmt|;
name|this
operator|->
name|centerY
operator|=
name|centerY
expr_stmt|;
name|this
operator|->
name|scaleFactor
operator|=
name|scaleFactor
expr_stmt|;
name|this
operator|->
name|resultSize
operator|=
name|resultSize
expr_stmt|;
if|if
condition|(
operator|!
name|isRunning
argument_list|()
condition|)
block|{
name|start
argument_list|(
name|LowPriority
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|restart
operator|=
literal|true
expr_stmt|;
name|condition
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|run
name|void
name|RenderThread
operator|::
name|run
parameter_list|()
block|{
forever|forever
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QSize
name|resultSize
init|=
name|this
operator|->
name|resultSize
decl_stmt|;
name|double
name|scaleFactor
init|=
name|this
operator|->
name|scaleFactor
decl_stmt|;
name|double
name|centerX
init|=
name|this
operator|->
name|centerX
decl_stmt|;
name|double
name|centerY
init|=
name|this
operator|->
name|centerY
decl_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|int
name|halfWidth
init|=
name|resultSize
operator|.
name|width
argument_list|()
operator|/
literal|2
decl_stmt|;
comment|//! [4] //! [5]
name|int
name|halfHeight
init|=
name|resultSize
operator|.
name|height
argument_list|()
operator|/
literal|2
decl_stmt|;
name|QImage
name|image
argument_list|(
name|resultSize
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
specifier|const
name|int
name|NumPasses
init|=
literal|8
decl_stmt|;
name|int
name|pass
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|pass
operator|<
name|NumPasses
condition|)
block|{
specifier|const
name|int
name|MaxIterations
init|=
operator|(
literal|1
operator|<<
operator|(
literal|2
operator|*
name|pass
operator|+
literal|6
operator|)
operator|)
operator|+
literal|32
decl_stmt|;
specifier|const
name|int
name|Limit
init|=
literal|4
decl_stmt|;
name|bool
name|allBlack
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
operator|-
name|halfHeight
init|;
name|y
operator|<
name|halfHeight
condition|;
operator|++
name|y
control|)
block|{
if|if
condition|(
name|restart
condition|)
break|break;
if|if
condition|(
name|abort
condition|)
return|return;
name|uint
modifier|*
name|scanLine
init|=
cast|reinterpret_cast
argument_list|<
name|uint
operator|*
argument_list|>
argument_list|(
name|image
operator|.
name|scanLine
argument_list|(
name|y
operator|+
name|halfHeight
argument_list|)
argument_list|)
decl_stmt|;
name|double
name|ay
init|=
name|centerY
operator|+
operator|(
name|y
operator|*
name|scaleFactor
operator|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
operator|-
name|halfWidth
init|;
name|x
operator|<
name|halfWidth
condition|;
operator|++
name|x
control|)
block|{
name|double
name|ax
init|=
name|centerX
operator|+
operator|(
name|x
operator|*
name|scaleFactor
operator|)
decl_stmt|;
name|double
name|a1
init|=
name|ax
decl_stmt|;
name|double
name|b1
init|=
name|ay
decl_stmt|;
name|int
name|numIterations
init|=
literal|0
decl_stmt|;
do|do
block|{
operator|++
name|numIterations
expr_stmt|;
name|double
name|a2
init|=
operator|(
name|a1
operator|*
name|a1
operator|)
operator|-
operator|(
name|b1
operator|*
name|b1
operator|)
operator|+
name|ax
decl_stmt|;
name|double
name|b2
init|=
operator|(
literal|2
operator|*
name|a1
operator|*
name|b1
operator|)
operator|+
name|ay
decl_stmt|;
if|if
condition|(
operator|(
name|a2
operator|*
name|a2
operator|)
operator|+
operator|(
name|b2
operator|*
name|b2
operator|)
operator|>
name|Limit
condition|)
break|break;
operator|++
name|numIterations
expr_stmt|;
name|a1
operator|=
operator|(
name|a2
operator|*
name|a2
operator|)
operator|-
operator|(
name|b2
operator|*
name|b2
operator|)
operator|+
name|ax
expr_stmt|;
name|b1
operator|=
operator|(
literal|2
operator|*
name|a2
operator|*
name|b2
operator|)
operator|+
name|ay
expr_stmt|;
if|if
condition|(
operator|(
name|a1
operator|*
name|a1
operator|)
operator|+
operator|(
name|b1
operator|*
name|b1
operator|)
operator|>
name|Limit
condition|)
break|break;
block|}
do|while
condition|(
name|numIterations
operator|<
name|MaxIterations
condition|)
do|;
if|if
condition|(
name|numIterations
operator|<
name|MaxIterations
condition|)
block|{
operator|*
name|scanLine
operator|++
operator|=
name|colormap
index|[
name|numIterations
operator|%
name|ColormapSize
index|]
expr_stmt|;
name|allBlack
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
operator|*
name|scanLine
operator|++
operator|=
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|allBlack
operator|&&
name|pass
operator|==
literal|0
condition|)
block|{
name|pass
operator|=
literal|4
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|restart
condition|)
emit|emit
name|renderedImage
argument_list|(
name|image
argument_list|,
name|scaleFactor
argument_list|)
emit|;
comment|//! [5] //! [6]
operator|++
name|pass
expr_stmt|;
block|}
comment|//! [6] //! [7]
block|}
comment|//! [7]
comment|//! [8]
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
comment|//! [8] //! [9]
if|if
condition|(
operator|!
name|restart
condition|)
name|condition
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
name|restart
operator|=
literal|false
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|rgbFromWaveLength
name|uint
name|RenderThread
operator|::
name|rgbFromWaveLength
parameter_list|(
name|double
name|wave
parameter_list|)
block|{
name|double
name|r
init|=
literal|0.0
decl_stmt|;
name|double
name|g
init|=
literal|0.0
decl_stmt|;
name|double
name|b
init|=
literal|0.0
decl_stmt|;
if|if
condition|(
name|wave
operator|>=
literal|380.0
operator|&&
name|wave
operator|<=
literal|440.0
condition|)
block|{
name|r
operator|=
operator|-
literal|1.0
operator|*
operator|(
name|wave
operator|-
literal|440.0
operator|)
operator|/
operator|(
literal|440.0
operator|-
literal|380.0
operator|)
expr_stmt|;
name|b
operator|=
literal|1.0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|wave
operator|>=
literal|440.0
operator|&&
name|wave
operator|<=
literal|490.0
condition|)
block|{
name|g
operator|=
operator|(
name|wave
operator|-
literal|440.0
operator|)
operator|/
operator|(
literal|490.0
operator|-
literal|440.0
operator|)
expr_stmt|;
name|b
operator|=
literal|1.0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|wave
operator|>=
literal|490.0
operator|&&
name|wave
operator|<=
literal|510.0
condition|)
block|{
name|g
operator|=
literal|1.0
expr_stmt|;
name|b
operator|=
operator|-
literal|1.0
operator|*
operator|(
name|wave
operator|-
literal|510.0
operator|)
operator|/
operator|(
literal|510.0
operator|-
literal|490.0
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|wave
operator|>=
literal|510.0
operator|&&
name|wave
operator|<=
literal|580.0
condition|)
block|{
name|r
operator|=
operator|(
name|wave
operator|-
literal|510.0
operator|)
operator|/
operator|(
literal|580.0
operator|-
literal|510.0
operator|)
expr_stmt|;
name|g
operator|=
literal|1.0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|wave
operator|>=
literal|580.0
operator|&&
name|wave
operator|<=
literal|645.0
condition|)
block|{
name|r
operator|=
literal|1.0
expr_stmt|;
name|g
operator|=
operator|-
literal|1.0
operator|*
operator|(
name|wave
operator|-
literal|645.0
operator|)
operator|/
operator|(
literal|645.0
operator|-
literal|580.0
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|wave
operator|>=
literal|645.0
operator|&&
name|wave
operator|<=
literal|780.0
condition|)
block|{
name|r
operator|=
literal|1.0
expr_stmt|;
block|}
name|double
name|s
init|=
literal|1.0
decl_stmt|;
if|if
condition|(
name|wave
operator|>
literal|700.0
condition|)
name|s
operator|=
literal|0.3
operator|+
literal|0.7
operator|*
operator|(
literal|780.0
operator|-
name|wave
operator|)
operator|/
operator|(
literal|780.0
operator|-
literal|700.0
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|wave
operator|<
literal|420.0
condition|)
name|s
operator|=
literal|0.3
operator|+
literal|0.7
operator|*
operator|(
name|wave
operator|-
literal|380.0
operator|)
operator|/
operator|(
literal|420.0
operator|-
literal|380.0
operator|)
expr_stmt|;
name|r
operator|=
name|pow
argument_list|(
name|r
operator|*
name|s
argument_list|,
literal|0.8
argument_list|)
expr_stmt|;
name|g
operator|=
name|pow
argument_list|(
name|g
operator|*
name|s
argument_list|,
literal|0.8
argument_list|)
expr_stmt|;
name|b
operator|=
name|pow
argument_list|(
name|b
operator|*
name|s
argument_list|,
literal|0.8
argument_list|)
expr_stmt|;
return|return
name|qRgb
argument_list|(
name|int
argument_list|(
name|r
operator|*
literal|255
argument_list|)
argument_list|,
name|int
argument_list|(
name|g
operator|*
literal|255
argument_list|)
argument_list|,
name|int
argument_list|(
name|b
operator|*
literal|255
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
end_unit
