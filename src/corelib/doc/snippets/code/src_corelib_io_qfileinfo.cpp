begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//![newstuff]
end_comment
begin_decl_stmt
name|QFileInfo
name|fi
argument_list|(
literal|"c:/temp/foo"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|=
operator|>
name|fi
operator|.
name|absoluteFilePath
argument_list|()
operator|=
operator|>
literal|"C:/temp/foo"
comment|//![newstuff]
comment|//! [0]
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|QFileInfo
name|info1
argument_list|(
literal|"/home/bob/bin/untabify"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|info1
operator|.
name|isSymLink
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|info1
operator|.
name|absoluteFilePath
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "/home/bob/bin/untabify"
end_comment
begin_expr_stmt
name|info1
operator|.
name|size
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 56201
end_comment
begin_expr_stmt
name|info1
operator|.
name|symLinkTarget
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "/opt/pretty++/bin/untabify"
end_comment
begin_decl_stmt
name|QFileInfo
name|info2
argument_list|(
name|info1
operator|.
name|symLinkTarget
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|info2
operator|.
name|isSymLink
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_expr_stmt
name|info2
operator|.
name|absoluteFilePath
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "/opt/pretty++/bin/untabify"
end_comment
begin_expr_stmt
name|info2
operator|.
name|size
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 56201
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_decl_stmt
name|QFileInfo
name|info1
argument_list|(
literal|"C:\\Documents and Settings\\Bob\\untabify.lnk"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|info1
operator|.
name|isSymLink
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|info1
operator|.
name|absoluteFilePath
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "C:/Documents and Settings/Bob/untabify.lnk"
end_comment
begin_expr_stmt
name|info1
operator|.
name|size
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 743
end_comment
begin_expr_stmt
name|info1
operator|.
name|symLinkTarget
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "C:/Pretty++/untabify"
end_comment
begin_decl_stmt
name|QFileInfo
name|info2
argument_list|(
name|info1
operator|.
name|symLinkTarget
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|info2
operator|.
name|isSymLink
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_expr_stmt
name|info2
operator|.
name|absoluteFilePath
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "C:/Pretty++/untabify"
end_comment
begin_expr_stmt
name|info2
operator|.
name|size
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 63942
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|absolute
name|QString
name|absolute
init|=
literal|"/local/bin"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|relative
name|QString
name|relative
init|=
literal|"local/bin"
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QFileInfo
name|absFile
parameter_list|(
name|absolute
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QFileInfo
name|relFile
parameter_list|(
name|relative
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QDir
operator|::
name|setCurrent
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// absFile and relFile now point to the same file
end_comment
begin_expr_stmt
name|QDir
operator|::
name|setCurrent
argument_list|(
literal|"/tmp"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// absFile now points to "/local/bin",
end_comment
begin_comment
comment|// while relFile points to "/tmp/local/bin"
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
name|QFileInfo
name|fi
argument_list|(
literal|"/tmp/archive.tar.gz"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|name
name|QString
name|name
init|=
name|fi
operator|.
name|fileName
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|name
comment|// name = "archive.tar.gz"
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
name|QFileInfo
name|fi
argument_list|(
literal|"/Applications/Safari.app"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|bundle
name|QString
name|bundle
init|=
name|fi
operator|.
name|bundleName
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|bundle
comment|// name = "Safari"
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
name|QFileInfo
name|fi
argument_list|(
literal|"/tmp/archive.tar.gz"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|base
name|QString
name|base
init|=
name|fi
operator|.
name|baseName
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|base
comment|// base = "archive"
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
name|QFileInfo
name|fi
argument_list|(
literal|"/tmp/archive.tar.gz"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|base
name|QString
name|base
init|=
name|fi
operator|.
name|completeBaseName
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|base
comment|// base = "archive.tar"
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
name|QFileInfo
name|fi
argument_list|(
literal|"/tmp/archive.tar.gz"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ext
name|QString
name|ext
init|=
name|fi
operator|.
name|completeSuffix
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|ext
comment|// ext = "tar.gz"
end_comment
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
name|QFileInfo
name|fi
argument_list|(
literal|"/tmp/archive.tar.gz"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ext
name|QString
name|ext
init|=
name|fi
operator|.
name|suffix
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|ext
comment|// ext = "gz"
end_comment
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function_decl
name|QFileInfo
name|info
parameter_list|(
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|if
condition|(
name|info
operator|.
name|isSymLink
argument_list|()
condition|)
name|fileName
operator|=
name|info
operator|.
name|symLinkTarget
argument_list|()
expr_stmt|;
end_if
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
name|QFileInfo
name|fi
argument_list|(
literal|"/tmp/archive.tar.gz"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|fi
operator|.
name|permission
argument_list|(
name|QFile
operator|::
name|WriteUser
operator||
name|QFile
operator|::
name|ReadGroup
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"I can change the file; my group can read the file"
argument_list|)
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|fi
operator|.
name|permission
argument_list|(
name|QFile
operator|::
name|WriteGroup
operator||
name|QFile
operator|::
name|WriteOther
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"The group or others can change the file"
argument_list|)
expr_stmt|;
end_if
begin_comment
comment|//! [10]
end_comment
end_unit
