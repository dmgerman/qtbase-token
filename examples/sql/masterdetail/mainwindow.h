begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MAINWINDOW_H
end_ifndef
begin_define
DECL|macro|MAINWINDOW_H
define|#
directive|define
name|MAINWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QDomDocument>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QModelIndex>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFile
name|class
name|QFile
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGroupBox
name|class
name|QGroupBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QListWidget
name|class
name|QListWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRelationalTableModel
name|class
name|QSqlRelationalTableModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableView
name|class
name|QTableView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|MainWindow
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|MainWindow
argument_list|(
specifier|const
name|QString
operator|&
name|artistTable
argument_list|,
specifier|const
name|QString
operator|&
name|albumTable
argument_list|,
name|QFile
operator|*
name|albumDetails
argument_list|,
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
name|about
argument_list|()
block|;
name|void
name|addAlbum
argument_list|()
block|;
name|void
name|changeArtist
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|deleteAlbum
argument_list|()
block|;
name|void
name|showAlbumDetails
argument_list|(
argument|QModelIndex index
argument_list|)
block|;
name|void
name|showArtistProfile
argument_list|(
argument|QModelIndex index
argument_list|)
block|;
name|void
name|updateHeader
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
block|;
name|private
operator|:
name|void
name|adjustHeader
argument_list|()
block|;
name|QGroupBox
operator|*
name|createAlbumGroupBox
argument_list|()
block|;
name|QGroupBox
operator|*
name|createArtistGroupBox
argument_list|()
block|;
name|QGroupBox
operator|*
name|createDetailsGroupBox
argument_list|()
block|;
name|void
name|createMenuBar
argument_list|()
block|;
name|void
name|decreaseAlbumCount
argument_list|(
argument|QModelIndex artistIndex
argument_list|)
block|;
name|void
name|getTrackList
argument_list|(
argument|QDomNode album
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
name|void
name|readAlbumData
argument_list|()
block|;
name|void
name|removeAlbumFromDatabase
argument_list|(
argument|QModelIndex album
argument_list|)
block|;
name|void
name|removeAlbumFromFile
argument_list|(
argument|int id
argument_list|)
block|;
name|void
name|showImageLabel
argument_list|()
block|;
name|QTableView
operator|*
name|albumView
block|;
name|QComboBox
operator|*
name|artistView
block|;
name|QListWidget
operator|*
name|trackList
block|;
name|QLabel
operator|*
name|iconLabel
block|;
name|QLabel
operator|*
name|imageLabel
block|;
name|QLabel
operator|*
name|profileLabel
block|;
name|QLabel
operator|*
name|titleLabel
block|;
name|QDomDocument
name|albumData
block|;
name|QFile
operator|*
name|file
block|;
name|QSqlRelationalTableModel
operator|*
name|model
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
