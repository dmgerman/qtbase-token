begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ICONPREVIEWAREA_H
end_ifndef
begin_define
DECL|macro|ICONPREVIEWAREA_H
define|#
directive|define
name|ICONPREVIEWAREA_H
end_define
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|IconPreviewArea
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|IconPreviewArea
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|void
name|setSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|private
operator|:
name|QLabel
operator|*
name|createHeaderLabel
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QLabel
operator|*
name|createPixmapLabel
argument_list|()
block|;
name|void
name|updatePixmapLabels
argument_list|()
block|;      enum
block|{
name|NumModes
operator|=
literal|4
block|,
name|NumStates
operator|=
literal|2
block|}
block|;
name|QIcon
name|icon
block|;
name|QSize
name|size
block|;
name|QLabel
operator|*
name|stateLabels
index|[
name|NumStates
index|]
block|;
name|QLabel
operator|*
name|modeLabels
index|[
name|NumModes
index|]
block|;
name|QLabel
operator|*
name|pixmapLabels
index|[
name|NumModes
index|]
index|[
name|NumStates
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
end_unit
