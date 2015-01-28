begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDesktopServices>
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_include
include|#
directive|include
file|"searchbox.h"
end_include
begin_include
include|#
directive|include
file|"googlesuggest.h"
end_include
begin_define
DECL|macro|GSEARCH_URL
define|#
directive|define
name|GSEARCH_URL
value|"http://www.google.com/search?q=%1"
end_define
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|SearchBox
name|SearchBox
operator|::
name|SearchBox
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLineEdit
argument_list|(
name|parent
argument_list|)
block|{
name|completer
operator|=
operator|new
name|GSuggestCompletion
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|doSearch
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
literal|"Search with Google"
argument_list|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
name|resize
argument_list|(
literal|400
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|doSearch
name|void
name|SearchBox
operator|::
name|doSearch
parameter_list|()
block|{
name|completer
operator|->
name|preventSuggest
argument_list|()
expr_stmt|;
name|QString
name|url
init|=
name|QString
argument_list|(
name|GSEARCH_URL
argument_list|)
operator|.
name|arg
argument_list|(
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|QUrl
argument_list|(
name|url
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
end_unit
