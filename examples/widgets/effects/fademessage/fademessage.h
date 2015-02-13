begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FADEMESSAGE_H
end_ifndef
begin_define
DECL|macro|FADEMESSAGE_H
define|#
directive|define
name|FADEMESSAGE_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsEffect>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QPropertyAnimation>
end_include
begin_include
include|#
directive|include
file|"fademessage.h"
end_include
begin_decl_stmt
name|class
name|FadeMessage
range|:
name|public
name|QGraphicsView
block|{
name|Q_OBJECT
name|public
operator|:
name|FadeMessage
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|void
name|setupScene
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|togglePopup
argument_list|()
block|;
name|private
operator|:
name|QGraphicsScene
name|m_scene
block|;
name|QGraphicsColorizeEffect
operator|*
name|m_effect
block|;
name|QGraphicsItem
operator|*
name|m_message
block|;
name|QPropertyAnimation
operator|*
name|m_animation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// FADEMESSAGE_H
end_comment
end_unit
