begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BORDERLAYOUT_H
end_ifndef
begin_define
DECL|macro|BORDERLAYOUT_H
define|#
directive|define
name|BORDERLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QLayout>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_decl_stmt
name|class
name|BorderLayout
range|:
name|public
name|QLayout
block|{
name|public
operator|:
expr|enum
name|Position
block|{
name|West
block|,
name|North
block|,
name|South
block|,
name|East
block|,
name|Center
block|}
block|;
name|explicit
name|BorderLayout
argument_list|(
argument|QWidget *parent
argument_list|,
argument|int margin =
literal|0
argument_list|,
argument|int spacing = -
literal|1
argument_list|)
block|;
name|BorderLayout
argument_list|(
argument|int spacing = -
literal|1
argument_list|)
block|;
operator|~
name|BorderLayout
argument_list|()
block|;
name|void
name|addItem
argument_list|(
argument|QLayoutItem *item
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|addWidget
argument_list|(
argument|QWidget *widget
argument_list|,
argument|Position position
argument_list|)
block|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|count
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setGeometry
argument_list|(
argument|const QRect&rect
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QLayoutItem
operator|*
name|takeAt
argument_list|(
argument|int index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|add
argument_list|(
argument|QLayoutItem *item
argument_list|,
argument|Position position
argument_list|)
block|;
name|private
operator|:
expr|struct
name|ItemWrapper
block|{
name|ItemWrapper
argument_list|(
argument|QLayoutItem *i
argument_list|,
argument|Position p
argument_list|)
block|{
name|item
operator|=
name|i
block|;
name|position
operator|=
name|p
block|;         }
name|QLayoutItem
operator|*
name|item
block|;
name|Position
name|position
block|;     }
block|;      enum
name|SizeType
block|{
name|MinimumSize
block|,
name|SizeHint
block|}
block|;
name|QSize
name|calculateSize
argument_list|(
argument|SizeType sizeType
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|ItemWrapper
operator|*
operator|>
name|list
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// BORDERLAYOUT_H
end_comment
end_unit
