begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextEdit
name|class
name|QTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [class definition with macro]
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
argument_list|()
block|;
comment|//! [class definition with macro]
name|explicit
name|MainWindow
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|tile
argument_list|(
specifier|const
name|QMainWindow
operator|*
name|previous
argument_list|)
block|;
name|protected
operator|:
name|void
name|closeEvent
argument_list|(
argument|QCloseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
name|slots
operator|:
name|void
name|newFile
argument_list|()
block|;
name|void
name|open
argument_list|()
block|;
name|bool
name|save
argument_list|()
block|;
name|bool
name|saveAs
argument_list|()
block|;
name|void
name|updateRecentFileActions
argument_list|()
block|;
name|void
name|openRecentFile
argument_list|()
block|;
name|void
name|about
argument_list|()
block|;
name|void
name|documentWasModified
argument_list|()
block|;
name|private
operator|:
expr|enum
block|{
name|MaxRecentFiles
operator|=
literal|5
block|}
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|createActions
argument_list|()
block|;
name|void
name|createStatusBar
argument_list|()
block|;
name|void
name|readSettings
argument_list|()
block|;
name|void
name|writeSettings
argument_list|()
block|;
name|bool
name|maybeSave
argument_list|()
block|;
name|void
name|openFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|loadFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
specifier|static
name|bool
name|hasRecentFiles
argument_list|()
block|;
name|void
name|prependToRecentFiles
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|setRecentFilesVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|bool
name|saveFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|setCurrentFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
specifier|static
name|QString
name|strippedName
argument_list|(
specifier|const
name|QString
operator|&
name|fullFileName
argument_list|)
block|;
name|MainWindow
operator|*
name|findMainWindow
argument_list|(
argument|const QString&fileName
argument_list|)
specifier|const
block|;
name|QTextEdit
operator|*
name|textEdit
block|;
name|QAction
operator|*
name|recentFileActs
index|[
name|MaxRecentFiles
index|]
block|;
name|QAction
operator|*
name|recentFileSeparator
block|;
name|QAction
operator|*
name|recentFileSubMenuAct
block|;
name|QString
name|curFile
block|;
name|bool
name|isUntitled
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
