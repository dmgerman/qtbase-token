begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DETAILSDIALOG_H
end_ifndef
begin_define
DECL|macro|DETAILSDIALOG_H
define|#
directive|define
name|DETAILSDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QDialog>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QPair>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
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
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableWidget
name|class
name|QTableWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextEdit
name|class
name|QTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|DetailsDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|DetailsDialog
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|verify
argument_list|()
block|;
name|public
operator|:
name|QList
operator|<
name|QPair
operator|<
name|QString
block|,
name|int
operator|>
expr|>
name|orderItems
argument_list|()
block|;
name|QString
name|senderName
argument_list|()
specifier|const
block|;
name|QString
name|senderAddress
argument_list|()
specifier|const
block|;
name|bool
name|sendOffers
argument_list|()
block|;
name|private
operator|:
name|void
name|setupItemsTable
argument_list|()
block|;
name|QLabel
operator|*
name|nameLabel
block|;
name|QLabel
operator|*
name|addressLabel
block|;
name|QCheckBox
operator|*
name|offersCheckBox
block|;
name|QLineEdit
operator|*
name|nameEdit
block|;
name|QStringList
name|items
block|;
name|QTableWidget
operator|*
name|itemsTable
block|;
name|QTextEdit
operator|*
name|addressEdit
block|;
name|QDialogButtonBox
operator|*
name|buttonBox
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
comment|// DETAILSDIALOG_H
end_comment
end_unit
