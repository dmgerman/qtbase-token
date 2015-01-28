begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DROPSITEWINDOW_H
end_ifndef
begin_define
DECL|macro|DROPSITEWINDOW_H
define|#
directive|define
name|DROPSITEWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDialogButtonBox
name|class
name|QDialogButtonBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableWidget
name|class
name|QTableWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|DropArea
name|class
name|DropArea
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [DropSiteWindow header]
end_comment
begin_decl_stmt
name|class
name|DropSiteWindow
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|DropSiteWindow
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|updateFormatsTable
argument_list|(
specifier|const
name|QMimeData
operator|*
name|mimeData
argument_list|)
block|;
name|private
operator|:
name|DropArea
operator|*
name|dropArea
block|;
name|QLabel
operator|*
name|abstractLabel
block|;
name|QTableWidget
operator|*
name|formatsTable
block|;
name|QPushButton
operator|*
name|clearButton
block|;
name|QPushButton
operator|*
name|quitButton
block|;
name|QDialogButtonBox
operator|*
name|buttonBox
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [DropSiteWindow header]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DROPSITEWINDOW_H
end_comment
end_unit
