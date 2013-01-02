begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLIDERSGROUP_H
end_ifndef
begin_define
DECL|macro|SLIDERSGROUP_H
define|#
directive|define
name|SLIDERSGROUP_H
end_define
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDial
name|class
name|QDial
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollBar
name|class
name|QScrollBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSlider
name|class
name|QSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|SlidersGroup
range|:
name|public
name|QGroupBox
block|{
name|Q_OBJECT
name|public
operator|:
name|SlidersGroup
argument_list|(
argument|Qt::Orientation orientation
argument_list|,
argument|const QString&title
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|signals
operator|:
name|void
name|valueChanged
argument_list|(
argument|int value
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|setValue
argument_list|(
argument|int value
argument_list|)
block|;
name|void
name|setMinimum
argument_list|(
argument|int value
argument_list|)
block|;
name|void
name|setMaximum
argument_list|(
argument|int value
argument_list|)
block|;
name|void
name|invertAppearance
argument_list|(
argument|bool invert
argument_list|)
block|;
name|void
name|invertKeyBindings
argument_list|(
argument|bool invert
argument_list|)
block|;
name|private
operator|:
name|QSlider
operator|*
name|slider
block|;
name|QScrollBar
operator|*
name|scrollBar
block|;
name|QDial
operator|*
name|dial
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
