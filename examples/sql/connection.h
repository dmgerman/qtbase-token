begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONNECTION_H
end_ifndef
begin_define
DECL|macro|CONNECTION_H
define|#
directive|define
name|CONNECTION_H
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
begin_comment
comment|/*     This file defines a helper function to open a connection to an     in-memory SQLITE database and to create a test table.      If you want to use another database, simply modify the code     below. All the examples in this directory use this function to     connect to a database. */
end_comment
begin_comment
comment|//! [0]
end_comment
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
literal|"create table person (id int primary key, "
literal|"firstname varchar(20), lastname varchar(20))"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into person values(101, 'Danny', 'Young')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into person values(102, 'Christine', 'Holand')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into person values(103, 'Lars', 'Gordon')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into person values(104, 'Roberto', 'Robitaille')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into person values(105, 'Maria', 'Papadopoulos')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"create table items (id int primary key,"
literal|"imagefile int,"
literal|"itemtype varchar(20),"
literal|"description varchar(100))"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into items "
literal|"values(0, 0, 'Qt',"
literal|"'Qt is a full development framework with tools designed to "
literal|"streamline the creation of stunning applications and  "
literal|"amazing user interfaces for desktop, embedded and mobile "
literal|"platforms.')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into items "
literal|"values(1, 1, 'Qt Quick',"
literal|"'Qt Quick is a collection of techniques designed to help "
literal|"developers create intuitive, modern-looking, and fluid "
literal|"user interfaces using a CSS& JavaScript like language.')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into items "
literal|"values(2, 2, 'Qt Creator',"
literal|"'Qt Creator is a powerful cross-platform integrated "
literal|"development environment (IDE), including UI design tools "
literal|"and on-device debugging.')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into items "
literal|"values(3, 3, 'Qt Project',"
literal|"'The Qt Project governs the open source development of Qt, "
literal|"allowing anyone wanting to contribute to join the effort "
literal|"through a meritocratic structure of approvers and "
literal|"maintainers.')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"create table images (itemid int, file varchar(20))"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into images values(0, 'images/qt-logo.png')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into images values(1, 'images/qt-quick.png')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into images values(2, 'images/qt-creator.png')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into images values(3, 'images/qt-project.png')"
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
