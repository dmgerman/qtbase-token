begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RENDERTHREAD_H
end_ifndef
begin_define
DECL|macro|RENDERTHREAD_H
define|#
directive|define
name|RENDERTHREAD_H
end_define
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QSize>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QWaitCondition>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|RenderThread
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|RenderThread
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|RenderThread
argument_list|()
block|;
name|void
name|render
argument_list|(
argument|double centerX
argument_list|,
argument|double centerY
argument_list|,
argument|double scaleFactor
argument_list|,
argument|QSize resultSize
argument_list|)
block|;
name|signals
operator|:
name|void
name|renderedImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|double scaleFactor
argument_list|)
block|;
name|protected
operator|:
name|void
name|run
argument_list|()
block|;
name|private
operator|:
name|uint
name|rgbFromWaveLength
argument_list|(
argument|double wave
argument_list|)
block|;
name|QMutex
name|mutex
block|;
name|QWaitCondition
name|condition
block|;
name|double
name|centerX
block|;
name|double
name|centerY
block|;
name|double
name|scaleFactor
block|;
name|QSize
name|resultSize
block|;
name|bool
name|restart
block|;
name|bool
name|abort
block|;      enum
block|{
name|ColormapSize
operator|=
literal|512
block|}
block|;
name|uint
name|colormap
index|[
name|ColormapSize
index|]
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// RENDERTHREAD_H
end_comment
end_unit
