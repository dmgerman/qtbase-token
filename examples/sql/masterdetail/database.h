begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DATABASE_H
end_ifndef
begin_define
DECL|macro|DATABASE_H
define|#
directive|define
name|DATABASE_H
end_define
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QSqlDatabase>
end_include
begin_include
include|#
directive|include
file|<QSqlError>
end_include
begin_include
include|#
directive|include
file|<QSqlQuery>
end_include
begin_function
DECL|function|createConnection
specifier|static
name|bool
name|createConnection
parameter_list|()
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"QSQLITE"
argument_list|)
decl_stmt|;
name|db
operator|.
name|setDatabaseName
argument_list|(
literal|":memory:"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|db
operator|.
name|open
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|critical
argument_list|(
literal|0
argument_list|,
name|qApp
operator|->
name|tr
argument_list|(
literal|"Cannot open database"
argument_list|)
argument_list|,
name|qApp
operator|->
name|tr
argument_list|(
literal|"Unable to establish a database connection.\n"
literal|"This example needs SQLite support. Please read "
literal|"the Qt SQL driver documentation for information how "
literal|"to build it.\n\n"
literal|"Click Cancel to exit."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"create table artists (id int primary key, "
literal|"artist varchar(40), "
literal|"albumcount int)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into artists values(0, '<all>', 0)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into artists values(1, 'Ane Brun', 2)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into artists values(2, 'Thomas Dybdahl', 3)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into artists values(3, 'Kaizers Orchestra', 3)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"create table albums (albumid int primary key, "
literal|"title varchar(50), "
literal|"artistid int, "
literal|"year int)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into albums values(1, 'Spending Time With Morgan', 1, "
literal|"2003)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into albums values(2, 'A Temporary Dive', 1, 2005)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into albums values(3, '...The Great October Sound', 2, "
literal|"2002)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into albums values(4, 'Stray Dogs', 2, 2003)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into albums values(5, "
literal|"'One day you`ll dance for me, New York City', 2, 2004)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into albums values(6, 'Ompa Til Du D\xc3\xb8r', 3, 2001)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into albums values(7, 'Evig Pint', 3, 2002)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into albums values(8, 'Maestro', 3, 2005)"
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
