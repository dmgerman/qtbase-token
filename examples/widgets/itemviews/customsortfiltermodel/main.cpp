begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_function
DECL|function|addMail
name|void
name|addMail
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|,
specifier|const
name|QString
modifier|&
name|subject
parameter_list|,
specifier|const
name|QString
modifier|&
name|sender
parameter_list|,
specifier|const
name|QDateTime
modifier|&
name|date
parameter_list|)
block|{
name|model
operator|->
name|insertRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|subject
argument_list|)
expr_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|sender
argument_list|)
expr_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
argument_list|,
name|date
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createMailModel
name|QAbstractItemModel
modifier|*
name|createMailModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
block|{
name|QStandardItemModel
modifier|*
name|model
init|=
operator|new
name|QStandardItemModel
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
name|parent
argument_list|)
decl_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Subject"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Sender"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|2
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Date"
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"Happy New Year!"
argument_list|,
literal|"Grace K.<grace@software-inc.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|12
argument_list|,
literal|31
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|17
argument_list|,
literal|03
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"Radically new concept"
argument_list|,
literal|"Grace K.<grace@software-inc.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|12
argument_list|,
literal|22
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|9
argument_list|,
literal|44
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"Accounts"
argument_list|,
literal|"pascale@nospam.com"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|12
argument_list|,
literal|31
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|12
argument_list|,
literal|50
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"Expenses"
argument_list|,
literal|"Joe Bloggs<joe@bloggs.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|12
argument_list|,
literal|25
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|11
argument_list|,
literal|39
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"Re: Expenses"
argument_list|,
literal|"Andy<andy@nospam.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2007
argument_list|,
literal|01
argument_list|,
literal|02
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|16
argument_list|,
literal|05
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"Re: Accounts"
argument_list|,
literal|"Joe Bloggs<joe@bloggs.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2007
argument_list|,
literal|01
argument_list|,
literal|03
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|14
argument_list|,
literal|18
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"Re: Accounts"
argument_list|,
literal|"Andy<andy@nospam.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2007
argument_list|,
literal|01
argument_list|,
literal|03
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|14
argument_list|,
literal|26
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"Sports"
argument_list|,
literal|"Linda Smith<linda.smith@nospam.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2007
argument_list|,
literal|01
argument_list|,
literal|05
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|11
argument_list|,
literal|33
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"AW: Sports"
argument_list|,
literal|"Rolf Newschweinstein<rolfn@nospam.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2007
argument_list|,
literal|01
argument_list|,
literal|05
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|12
argument_list|,
literal|00
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|addMail
argument_list|(
name|model
argument_list|,
literal|"RE: Sports"
argument_list|,
literal|"Petra Schmidt<petras@nospam.com>"
argument_list|,
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2007
argument_list|,
literal|01
argument_list|,
literal|05
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|12
argument_list|,
literal|01
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|window
operator|.
name|setSourceModel
argument_list|(
name|createMailModel
argument_list|(
operator|&
name|window
argument_list|)
argument_list|)
expr_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
end_unit
