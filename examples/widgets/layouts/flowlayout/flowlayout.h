begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FLOWLAYOUT_H
end_ifndef
begin_define
DECL|macro|FLOWLAYOUT_H
define|#
directive|define
name|FLOWLAYOUT_H
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
begin_include
include|#
directive|include
file|<QWidgetItem>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|FlowLayout
range|:
name|public
name|QLayout
block|{
name|public
operator|:
name|explicit
name|FlowLayout
argument_list|(
argument|QWidget *parent
argument_list|,
argument|int margin = -
literal|1
argument_list|,
argument|int hSpacing = -
literal|1
argument_list|,
argument|int vSpacing = -
literal|1
argument_list|)
block|;
name|explicit
name|FlowLayout
argument_list|(
argument|int margin = -
literal|1
argument_list|,
argument|int hSpacing = -
literal|1
argument_list|,
argument|int vSpacing = -
literal|1
argument_list|)
block|;
operator|~
name|FlowLayout
argument_list|()
block|;
name|void
name|addItem
argument_list|(
name|QLayoutItem
operator|*
name|item
argument_list|)
block|;
name|int
name|horizontalSpacing
argument_list|()
specifier|const
block|;
name|int
name|verticalSpacing
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
block|;
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
block|;
name|int
name|heightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|QLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QLayoutItem
operator|*
name|takeAt
argument_list|(
argument|int index
argument_list|)
block|;
name|private
operator|:
name|int
name|doLayout
argument_list|(
argument|const QRect&rect
argument_list|,
argument|bool testOnly
argument_list|)
specifier|const
block|;
name|int
name|smartSpacing
argument_list|(
argument|QStyle::PixelMetric pm
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QLayoutItem
operator|*
operator|>
name|itemList
block|;
name|int
name|m_hSpace
block|;
name|int
name|m_vSpace
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
