begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"ui_form.h"
end_include
begin_include
include|#
directive|include
file|"animation.h"
end_include
begin_decl_stmt
DECL|variable|QObject
name|class
name|PixmapItem
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QGraphicsPixmapItem
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
name|QPointF
name|pos
name|READ
name|pos
name|WRITE
name|setPos
argument_list|)
name|public
range|:
name|PixmapItem
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pix
argument_list|)
operator|:
name|QGraphicsPixmapItem
argument_list|(
argument|pix
argument_list|)
block|{     }
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Window
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|Window
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|curveChanged
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|pathChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|periodChanged
argument_list|(
name|double
argument_list|)
block|;
name|void
name|amplitudeChanged
argument_list|(
name|double
argument_list|)
block|;
name|void
name|overshootChanged
argument_list|(
name|double
argument_list|)
block|;
name|private
operator|:
name|void
name|createCurveIcons
argument_list|()
block|;
name|void
name|startAnimation
argument_list|()
block|;
name|Ui
operator|::
name|Form
name|m_ui
block|;
name|QGraphicsScene
name|m_scene
block|;
name|PixmapItem
operator|*
name|m_item
block|;
name|Animation
operator|*
name|m_anim
block|;
name|QSize
name|m_iconSize
block|; }
decl_stmt|;
end_decl_stmt
end_unit
