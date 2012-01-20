begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argv
argument_list|,
name|args
argument_list|)
decl_stmt|;
comment|//![0]
name|QList
argument_list|<
name|QUrl
argument_list|>
name|urls
decl_stmt|;
name|urls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
literal|"/home/gvatteka/dev/qt-45"
argument_list|)
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDesktopServices
operator|::
name|storageLocation
argument_list|(
name|QDesktopServices
operator|::
name|MusicLocation
argument_list|)
argument_list|)
expr_stmt|;
name|QFileDialog
name|dialog
decl_stmt|;
name|dialog
operator|.
name|setSidebarUrls
argument_list|(
name|urls
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|setFileMode
argument_list|(
name|QFileDialog
operator|::
name|AnyFile
argument_list|)
expr_stmt|;
if|if
condition|(
name|dialog
operator|.
name|exec
argument_list|()
condition|)
block|{
comment|// ...
block|}
comment|//![0]
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
