begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"renderthread.h"
end_include
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
name|m_abort
operator|=
literal|false
expr_stmt|;
block|}
end_constructor
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
name|m_abort
operator|=
literal|true
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
comment|//![processing the image (start)]
end_comment
begin_function
DECL|function|processImage
name|void
name|RenderThread
operator|::
name|processImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|m_image
operator|=
name|image
expr_stmt|;
name|m_abort
operator|=
literal|false
expr_stmt|;
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|run
name|void
name|RenderThread
operator|::
name|run
parameter_list|()
block|{
name|int
name|size
init|=
name|qMax
argument_list|(
name|m_image
operator|.
name|width
argument_list|()
operator|/
literal|20
argument_list|,
name|m_image
operator|.
name|height
argument_list|()
operator|/
literal|20
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|s
init|=
name|size
init|;
name|s
operator|>
literal|0
condition|;
operator|--
name|s
control|)
block|{
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
literal|400
condition|;
operator|++
name|c
control|)
block|{
comment|//![processing the image (start)]
name|int
name|x1
init|=
name|qMax
argument_list|(
literal|0
argument_list|,
operator|(
name|qrand
argument_list|()
operator|%
name|m_image
operator|.
name|width
argument_list|()
operator|)
operator|-
name|s
operator|/
literal|2
argument_list|)
decl_stmt|;
name|int
name|x2
init|=
name|qMin
argument_list|(
name|x1
operator|+
name|s
operator|/
literal|2
operator|+
literal|1
argument_list|,
name|m_image
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|y1
init|=
name|qMax
argument_list|(
literal|0
argument_list|,
operator|(
name|qrand
argument_list|()
operator|%
name|m_image
operator|.
name|height
argument_list|()
operator|)
operator|-
name|s
operator|/
literal|2
argument_list|)
decl_stmt|;
name|int
name|y2
init|=
name|qMin
argument_list|(
name|y1
operator|+
name|s
operator|/
literal|2
operator|+
literal|1
argument_list|,
name|m_image
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|n
init|=
literal|0
decl_stmt|;
name|int
name|red
init|=
literal|0
decl_stmt|;
name|int
name|green
init|=
literal|0
decl_stmt|;
name|int
name|blue
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|y1
init|;
name|i
operator|<
name|y2
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|j
init|=
name|x1
init|;
name|j
operator|<
name|x2
condition|;
operator|++
name|j
control|)
block|{
name|QRgb
name|pixel
init|=
name|m_image
operator|.
name|pixel
argument_list|(
name|j
argument_list|,
name|i
argument_list|)
decl_stmt|;
name|red
operator|+=
name|qRed
argument_list|(
name|pixel
argument_list|)
expr_stmt|;
name|green
operator|+=
name|qGreen
argument_list|(
name|pixel
argument_list|)
expr_stmt|;
name|blue
operator|+=
name|qBlue
argument_list|(
name|pixel
argument_list|)
expr_stmt|;
name|n
operator|+=
literal|1
expr_stmt|;
block|}
block|}
comment|//![processing the image (finish)]
name|Block
name|block
argument_list|(
name|QRect
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
operator|-
name|x1
operator|+
literal|1
argument_list|,
name|y2
operator|-
name|y1
operator|+
literal|1
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|red
operator|/
name|n
argument_list|,
name|green
operator|/
name|n
argument_list|,
name|blue
operator|/
name|n
argument_list|)
argument_list|)
decl_stmt|;
emit|emit
name|sendBlock
argument_list|(
name|block
argument_list|)
emit|;
if|if
condition|(
name|m_abort
condition|)
return|return;
name|msleep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//![processing the image (finish)]
end_comment
begin_function
DECL|function|stopProcess
name|void
name|RenderThread
operator|::
name|stopProcess
parameter_list|()
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|m_abort
operator|=
literal|true
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
