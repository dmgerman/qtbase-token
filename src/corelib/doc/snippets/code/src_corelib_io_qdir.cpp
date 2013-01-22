begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_function
DECL|function|wrapInFunction
name|void
name|wrapInFunction
parameter_list|()
block|{
comment|//! [0]
name|QDir
argument_list|(
literal|"/home/user/Documents"
argument_list|)
name|QDir
argument_list|(
literal|"C:/Documents and Settings"
argument_list|)
comment|//! [0]
comment|//! [1]
name|QDir
argument_list|(
literal|"images/landscape.png"
argument_list|)
comment|//! [1]
comment|//! [2]
name|QDir
argument_list|(
literal|"Documents/Letters/Applications"
argument_list|)
operator|.
name|dirName
argument_list|()
comment|// "Applications"
name|QDir
argument_list|()
operator|.
name|dirName
argument_list|()
comment|// "."
comment|//! [2]
comment|//! [3]
name|QDir
name|directory
argument_list|(
literal|"Documents/Letters"
argument_list|)
expr_stmt|;
name|QString
name|path
init|=
name|directory
operator|.
name|filePath
argument_list|(
literal|"contents.txt"
argument_list|)
decl_stmt|;
name|QString
name|absolutePath
init|=
name|directory
operator|.
name|absoluteFilePath
argument_list|(
literal|"contents.txt"
argument_list|)
decl_stmt|;
comment|//! [3]
comment|//! [4]
name|QDir
name|dir
argument_list|(
literal|"example"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dir
operator|.
name|exists
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"Cannot find the example directory"
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|QDir
name|dir
init|=
name|QDir
operator|::
name|root
argument_list|()
decl_stmt|;
comment|// "/"
if|if
condition|(
operator|!
name|dir
operator|.
name|cd
argument_list|(
literal|"tmp"
argument_list|)
condition|)
block|{
comment|// "/tmp"
name|qWarning
argument_list|(
literal|"Cannot find the \"/tmp\" directory"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QFile
name|file
argument_list|(
name|dir
operator|.
name|filePath
argument_list|(
literal|"ex1.txt"
argument_list|)
argument_list|)
decl_stmt|;
comment|// "/tmp/ex1.txt"
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"Cannot create the file %s"
argument_list|,
name|file
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|//! [5]
comment|//! [6]
name|QString
name|bin
init|=
literal|"/local/bin"
decl_stmt|;
comment|// where /local/bin is a symlink to /usr/bin
name|QDir
name|binDir
argument_list|(
name|bin
argument_list|)
decl_stmt|;
name|QString
name|canonicalBin
init|=
name|binDir
operator|.
name|canonicalPath
argument_list|()
decl_stmt|;
comment|// canonicalBin now equals "/usr/bin"
name|QString
name|ls
init|=
literal|"/local/bin/ls"
decl_stmt|;
comment|// where ls is the executable "ls"
name|QDir
name|lsDir
argument_list|(
name|ls
argument_list|)
decl_stmt|;
name|QString
name|canonicalLs
init|=
name|lsDir
operator|.
name|canonicalPath
argument_list|()
decl_stmt|;
comment|// canonicalLS now equals "/usr/bin/ls".
comment|//! [6]
comment|//! [7]
name|QDir
name|dir
argument_list|(
literal|"/home/bob"
argument_list|)
decl_stmt|;
name|QString
name|s
decl_stmt|;
name|s
operator|=
name|dir
operator|.
name|relativeFilePath
argument_list|(
literal|"images/file.jpg"
argument_list|)
expr_stmt|;
comment|// s is "images/file.jpg"
name|s
operator|=
name|dir
operator|.
name|relativeFilePath
argument_list|(
literal|"/home/mary/file.txt"
argument_list|)
expr_stmt|;
comment|// s is "../mary/file.txt"
comment|//! [7]
comment|//! [8]
name|QDir
operator|::
name|setSearchPaths
argument_list|(
literal|"icons"
argument_list|,
name|QStringList
argument_list|(
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
literal|"/images"
argument_list|)
argument_list|)
expr_stmt|;
name|QDir
operator|::
name|setSearchPaths
argument_list|(
literal|"docs"
argument_list|,
name|QStringList
argument_list|(
literal|":/embeddedDocuments"
argument_list|)
argument_list|)
expr_stmt|;
operator|...
name|QPixmap
name|pixmap
argument_list|(
literal|"icons:undo.png"
argument_list|)
expr_stmt|;
comment|// will look for undo.png in QDir::homePath() + "/images"
name|QFile
name|file
argument_list|(
literal|"docs:design.odf"
argument_list|)
decl_stmt|;
comment|// will look in the :/embeddedDocuments resource path
comment|//! [8]
comment|//! [9]
name|QDir
name|dir
argument_list|(
literal|"/tmp/root_link"
argument_list|)
decl_stmt|;
name|dir
operator|=
name|dir
operator|.
name|canonicalPath
argument_list|()
expr_stmt|;
if|if
condition|(
name|dir
operator|.
name|isRoot
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"It is a root link"
argument_list|)
expr_stmt|;
comment|//! [9]
comment|//! [10]
comment|// The current directory is "/usr/local"
name|QDir
name|d1
argument_list|(
literal|"/usr/local/bin"
argument_list|)
decl_stmt|;
name|QDir
name|d2
argument_list|(
literal|"bin"
argument_list|)
decl_stmt|;
if|if
condition|(
name|d1
operator|==
name|d2
condition|)
name|qDebug
argument_list|(
literal|"They're the same"
argument_list|)
expr_stmt|;
comment|//! [10]
comment|//! [11]
comment|// The current directory is "/usr/local"
name|QDir
name|d1
argument_list|(
literal|"/usr/local/bin"
argument_list|)
decl_stmt|;
name|d1
operator|.
name|setFilter
argument_list|(
name|QDir
operator|::
name|Executable
argument_list|)
expr_stmt|;
name|QDir
name|d2
argument_list|(
literal|"bin"
argument_list|)
decl_stmt|;
if|if
condition|(
name|d1
operator|!=
name|d2
condition|)
name|qDebug
argument_list|(
literal|"They differ"
argument_list|)
expr_stmt|;
comment|//! [11]
comment|//! [12]
name|C
label|:
operator|/
name|Documents
operator|and
name|Settings
operator|/
name|Username
comment|//! [12]
comment|//! [13]
name|Q_INIT_RESOURCE
argument_list|(
name|myapp
argument_list|)
expr_stmt|;
comment|//! [13]
comment|//! [14]
specifier|inline
name|void
name|initMyResource
parameter_list|()
block|{
name|Q_INIT_RESOURCE
argument_list|(
name|myapp
argument_list|)
expr_stmt|;
block|}
namespace|namespace
name|MyNamespace
block|{
operator|...
name|void
name|myFunction
argument_list|()
block|{
name|initMyResource
argument_list|()
block|;     }
block|}
comment|//! [14]
comment|//! [15]
name|Q_CLEANUP_RESOURCE
argument_list|(
name|myapp
argument_list|)
expr_stmt|;
comment|//! [15]
block|}
end_function
end_unit
