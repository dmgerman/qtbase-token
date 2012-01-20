begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|manager
name|QNetworkAccessManager
modifier|*
name|manager
init|=
operator|new
name|QNetworkAccessManager
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|diskCache
name|QNetworkDiskCache
modifier|*
name|diskCache
init|=
operator|new
name|QNetworkDiskCache
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|diskCache
operator|->
name|setCacheDirectory
argument_list|(
literal|"cacheDir"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|manager
operator|->
name|setCache
argument_list|(
name|diskCache
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|// do a normal request (preferred from network, as this is the default)
end_comment
begin_decl_stmt
name|QNetworkRequest
name|request
argument_list|(
name|QUrl
argument_list|(
name|QString
argument_list|(
literal|"http://qt.nokia.com"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|manager
operator|->
name|get
argument_list|(
name|request
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// do a request preferred from cache
end_comment
begin_decl_stmt
name|QNetworkRequest
name|request2
argument_list|(
name|QUrl
argument_list|(
name|QString
argument_list|(
literal|"http://qt.nokia.com"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|request2
operator|.
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|CacheLoadControlAttribute
argument_list|,
name|QNetworkRequest
operator|::
name|PreferCache
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|manager
operator|->
name|get
argument_list|(
name|request2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|replyFinished
name|void
name|replyFinished
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|)
block|{
name|QVariant
name|fromCache
init|=
name|reply
operator|->
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|SourceIsFromCacheAttribute
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"page from cache?"
operator|<<
name|fromCache
operator|.
name|toBool
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
end_unit
