begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QUrl
name|url
argument_list|(
literal|"http://www.example.com/List of holidays.xml"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// url.toEncoded() == "http://www.example.com/List%20of%20holidays.xml"
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|url
name|QUrl
name|url
init|=
name|QUrl
operator|::
name|fromEncoded
argument_list|(
literal|"http://qt.nokia.com/List%20of%20holidays.xml"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|checkUrl
name|bool
name|checkUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
if|if
condition|(
operator|!
name|url
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|qDebug
argument_list|(
name|QString
argument_list|(
literal|"Invalid URL: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|sock
name|QTcpSocket
name|sock
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|sock
operator|.
name|connectToHost
argument_list|(
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|url
operator|.
name|port
argument_list|(
literal|80
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
begin_label
name|http
label|:
end_label
begin_comment
comment|//www.example.com/cgi-bin/drawgraph.cgi?type(pie)color(green)
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
name|QUrl
name|baseUrl
argument_list|(
literal|"http://qt.nokia.com/support"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QUrl
name|relativeUrl
argument_list|(
literal|"../products/solutions"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|(
name|baseUrl
operator|.
name|resolved
argument_list|(
name|relativeUrl
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// prints "http://qt.nokia.com/products/solutions"
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|ba
name|QByteArray
name|ba
init|=
name|QUrl
operator|::
name|toPercentEncoding
argument_list|(
literal|"{a fishy string?}"
argument_list|,
literal|"{}"
argument_list|,
literal|"s"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// prints "{a fi%73hy %73tring%3F}"
end_comment
begin_comment
comment|//! [6]
end_comment
end_unit
