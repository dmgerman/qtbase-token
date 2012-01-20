begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|INITDB_H
end_ifndef
begin_define
DECL|macro|INITDB_H
define|#
directive|define
name|INITDB_H
end_define
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_function
DECL|function|addBook
name|void
name|addBook
parameter_list|(
name|QSqlQuery
modifier|&
name|q
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|int
name|year
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|authorId
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|genreId
parameter_list|,
name|int
name|rating
parameter_list|)
block|{
name|q
operator|.
name|addBindValue
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|q
operator|.
name|addBindValue
argument_list|(
name|year
argument_list|)
expr_stmt|;
name|q
operator|.
name|addBindValue
argument_list|(
name|authorId
argument_list|)
expr_stmt|;
name|q
operator|.
name|addBindValue
argument_list|(
name|genreId
argument_list|)
expr_stmt|;
name|q
operator|.
name|addBindValue
argument_list|(
name|rating
argument_list|)
expr_stmt|;
name|q
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addGenre
name|QVariant
name|addGenre
parameter_list|(
name|QSqlQuery
modifier|&
name|q
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|q
operator|.
name|addBindValue
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|q
operator|.
name|exec
argument_list|()
expr_stmt|;
return|return
name|q
operator|.
name|lastInsertId
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|addAuthor
name|QVariant
name|addAuthor
parameter_list|(
name|QSqlQuery
modifier|&
name|q
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QDate
modifier|&
name|birthdate
parameter_list|)
block|{
name|q
operator|.
name|addBindValue
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|q
operator|.
name|addBindValue
argument_list|(
name|birthdate
argument_list|)
expr_stmt|;
name|q
operator|.
name|exec
argument_list|()
expr_stmt|;
return|return
name|q
operator|.
name|lastInsertId
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|initDb
name|QSqlError
name|initDb
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
return|return
name|db
operator|.
name|lastError
argument_list|()
return|;
name|QStringList
name|tables
init|=
name|db
operator|.
name|tables
argument_list|()
decl_stmt|;
if|if
condition|(
name|tables
operator|.
name|contains
argument_list|(
literal|"books"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|&&
name|tables
operator|.
name|contains
argument_list|(
literal|"authors"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|QSqlError
argument_list|()
return|;
name|QSqlQuery
name|q
decl_stmt|;
if|if
condition|(
operator|!
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"create table books(id integer primary key, title varchar, author integer, genre integer, year integer, rating integer)"
argument_list|)
argument_list|)
condition|)
return|return
name|q
operator|.
name|lastError
argument_list|()
return|;
if|if
condition|(
operator|!
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"create table authors(id integer primary key, name varchar, birthdate date)"
argument_list|)
argument_list|)
condition|)
return|return
name|q
operator|.
name|lastError
argument_list|()
return|;
if|if
condition|(
operator|!
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"create table genres(id integer primary key, name varchar)"
argument_list|)
argument_list|)
condition|)
return|return
name|q
operator|.
name|lastError
argument_list|()
return|;
if|if
condition|(
operator|!
name|q
operator|.
name|prepare
argument_list|(
name|QLatin1String
argument_list|(
literal|"insert into authors(name, birthdate) values(?, ?)"
argument_list|)
argument_list|)
condition|)
return|return
name|q
operator|.
name|lastError
argument_list|()
return|;
name|QVariant
name|asimovId
init|=
name|addAuthor
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Isaac Asimov"
argument_list|)
argument_list|,
name|QDate
argument_list|(
literal|1920
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|QVariant
name|greeneId
init|=
name|addAuthor
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Graham Greene"
argument_list|)
argument_list|,
name|QDate
argument_list|(
literal|1904
argument_list|,
literal|10
argument_list|,
literal|2
argument_list|)
argument_list|)
decl_stmt|;
name|QVariant
name|pratchettId
init|=
name|addAuthor
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Terry Pratchett"
argument_list|)
argument_list|,
name|QDate
argument_list|(
literal|1948
argument_list|,
literal|4
argument_list|,
literal|28
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|q
operator|.
name|prepare
argument_list|(
name|QLatin1String
argument_list|(
literal|"insert into genres(name) values(?)"
argument_list|)
argument_list|)
condition|)
return|return
name|q
operator|.
name|lastError
argument_list|()
return|;
name|QVariant
name|sfiction
init|=
name|addGenre
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Science Fiction"
argument_list|)
argument_list|)
decl_stmt|;
name|QVariant
name|fiction
init|=
name|addGenre
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Fiction"
argument_list|)
argument_list|)
decl_stmt|;
name|QVariant
name|fantasy
init|=
name|addGenre
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Fantasy"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|q
operator|.
name|prepare
argument_list|(
name|QLatin1String
argument_list|(
literal|"insert into books(title, year, author, genre, rating) values(?, ?, ?, ?, ?)"
argument_list|)
argument_list|)
condition|)
return|return
name|q
operator|.
name|lastError
argument_list|()
return|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Foundation"
argument_list|)
argument_list|,
literal|1951
argument_list|,
name|asimovId
argument_list|,
name|sfiction
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Foundation and Empire"
argument_list|)
argument_list|,
literal|1952
argument_list|,
name|asimovId
argument_list|,
name|sfiction
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Second Foundation"
argument_list|)
argument_list|,
literal|1953
argument_list|,
name|asimovId
argument_list|,
name|sfiction
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Foundation's Edge"
argument_list|)
argument_list|,
literal|1982
argument_list|,
name|asimovId
argument_list|,
name|sfiction
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Foundation and Earth"
argument_list|)
argument_list|,
literal|1986
argument_list|,
name|asimovId
argument_list|,
name|sfiction
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Prelude to Foundation"
argument_list|)
argument_list|,
literal|1988
argument_list|,
name|asimovId
argument_list|,
name|sfiction
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Forward the Foundation"
argument_list|)
argument_list|,
literal|1993
argument_list|,
name|asimovId
argument_list|,
name|sfiction
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"The Power and the Glory"
argument_list|)
argument_list|,
literal|1940
argument_list|,
name|greeneId
argument_list|,
name|fiction
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"The Third Man"
argument_list|)
argument_list|,
literal|1950
argument_list|,
name|greeneId
argument_list|,
name|fiction
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Our Man in Havana"
argument_list|)
argument_list|,
literal|1958
argument_list|,
name|greeneId
argument_list|,
name|fiction
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Guards! Guards!"
argument_list|)
argument_list|,
literal|1989
argument_list|,
name|pratchettId
argument_list|,
name|fantasy
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Night Watch"
argument_list|)
argument_list|,
literal|2002
argument_list|,
name|pratchettId
argument_list|,
name|fantasy
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|addBook
argument_list|(
name|q
argument_list|,
name|QLatin1String
argument_list|(
literal|"Going Postal"
argument_list|)
argument_list|,
literal|2004
argument_list|,
name|pratchettId
argument_list|,
name|fantasy
argument_list|,
literal|3
argument_list|)
expr_stmt|;
return|return
name|QSqlError
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
