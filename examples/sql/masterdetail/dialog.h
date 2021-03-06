begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DIALOG_H
end_ifndef
begin_define
DECL|macro|DIALOG_H
define|#
directive|define
name|DIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_include
include|#
directive|include
file|<QtXml>
end_include
begin_decl_stmt
name|class
name|Dialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|Dialog
argument_list|(
argument|QSqlRelationalTableModel *albums
argument_list|,
argument|QDomDocument details
argument_list|,
argument|QFile *output
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|revert
argument_list|()
block|;
name|void
name|submit
argument_list|()
block|;
name|private
operator|:
name|int
name|addNewAlbum
argument_list|(
argument|const QString&title
argument_list|,
argument|int artistId
argument_list|)
block|;
name|int
name|addNewArtist
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|void
name|addTracks
argument_list|(
argument|int albumId
argument_list|,
argument|QStringList tracks
argument_list|)
block|;
name|QDialogButtonBox
operator|*
name|createButtons
argument_list|()
block|;
name|QGroupBox
operator|*
name|createInputWidgets
argument_list|()
block|;
name|int
name|findArtistId
argument_list|(
specifier|const
name|QString
operator|&
name|artist
argument_list|)
block|;
name|int
name|generateAlbumId
argument_list|()
block|;
name|int
name|generateArtistId
argument_list|()
block|;
name|void
name|increaseAlbumCount
argument_list|(
argument|QModelIndex artistIndex
argument_list|)
block|;
name|QModelIndex
name|indexOfArtist
argument_list|(
specifier|const
name|QString
operator|&
name|artist
argument_list|)
block|;
name|QSqlRelationalTableModel
operator|*
name|model
block|;
name|QDomDocument
name|albumDetails
block|;
name|QFile
operator|*
name|outputFile
block|;
name|QLineEdit
operator|*
name|artistEditor
block|;
name|QLineEdit
operator|*
name|titleEditor
block|;
name|QSpinBox
operator|*
name|yearEditor
block|;
name|QLineEdit
operator|*
name|tracksEditor
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
