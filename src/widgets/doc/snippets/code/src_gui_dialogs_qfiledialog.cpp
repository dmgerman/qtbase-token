begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|fileName
operator|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open Image"
argument_list|)
argument_list|,
literal|"/home/jana"
argument_list|,
name|tr
argument_list|(
literal|"Image Files (*.png *.jpg *.bmp)"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
literal|"Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"
comment|//! [1]
comment|//! [2]
name|QFileDialog
name|dialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|dialog
operator|.
name|setFileMode
argument_list|(
name|QFileDialog
operator|::
name|AnyFile
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_expr_stmt
name|dialog
operator|.
name|setNameFilter
argument_list|(
name|tr
argument_list|(
literal|"Images (*.png *.xpm *.jpg)"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
name|dialog
operator|.
name|setViewMode
argument_list|(
name|QFileDialog
operator|::
name|Detail
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|fileNames
name|QStringList
name|fileNames
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|dialog
operator|.
name|exec
argument_list|()
condition|)
name|fileNames
operator|=
name|dialog
operator|.
name|selectedFiles
argument_list|()
expr_stmt|;
end_if
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_expr_stmt
name|dialog
operator|.
name|setNameFilter
argument_list|(
literal|"All C++ files (*.cpp *.cc *.C *.cxx *.c++)"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|dialog
operator|.
name|setNameFilter
argument_list|(
literal|"*.cpp *.cc *.C *.cxx *.c++"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|filters
name|QStringList
name|filters
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|filters
operator|<<
literal|"Image files (*.png *.xpm *.jpg)"
operator|<<
literal|"Text files (*.txt)"
operator|<<
literal|"Any files (*)"
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QFileDialog
name|dialog
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|dialog
operator|.
name|setNameFilters
argument_list|(
name|filters
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|dialog
operator|.
name|exec
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|fileName
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open File"
argument_list|)
argument_list|,
literal|"/home"
argument_list|,
name|tr
argument_list|(
literal|"Images (*.png *.xpm *.jpg)"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|files
name|QStringList
name|files
init|=
name|QFileDialog
operator|::
name|getOpenFileNames
argument_list|(
name|this
argument_list|,
literal|"Select one or more files to open"
argument_list|,
literal|"/home"
argument_list|,
literal|"Images (*.png *.xpm *.jpg)"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
init|=
name|files
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|it
name|QStringList
operator|::
name|Iterator
name|it
init|=
name|list
operator|.
name|begin
argument_list|()
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|it
operator|!=
name|list
operator|.
name|end
argument_list|()
condition|)
block|{
name|myProcessing
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|fileName
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Save File"
argument_list|)
argument_list|,
literal|"/home/jana/untitled.png"
argument_list|,
name|tr
argument_list|(
literal|"Images (*.png *.xpm *.jpg)"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
DECL|variable|dir
name|QString
name|dir
init|=
name|QFileDialog
operator|::
name|getExistingDirectory
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open Directory"
argument_list|)
argument_list|,
literal|"/home"
argument_list|,
name|QFileDialog
operator|::
name|ShowDirsOnly
operator||
name|QFileDialog
operator|::
name|DontResolveSymlinks
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
DECL|variable|mimeTypeFilters
name|QStringList
name|mimeTypeFilters
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|mimeTypeFilters
operator|<<
literal|"image/jpeg"
comment|// will show "JPEG image (*.jpeg *.jpg *.jpe)
operator|<<
literal|"image/png"
comment|// will show "PNG image (*.png)"
operator|<<
literal|"application/octet-stream"
expr_stmt|;
end_expr_stmt
begin_comment
comment|// will show "All files (*)"
end_comment
begin_function_decl
name|QFileDialog
name|dialog
parameter_list|(
name|this
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|dialog
operator|.
name|setMimeTypeFilters
argument_list|(
name|mimeTypeFilters
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|dialog
operator|.
name|exec
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [13]
end_comment
end_unit
