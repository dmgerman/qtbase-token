begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_struct
DECL|struct|MyApplication
struct|struct
name|MyApplication
super|:
specifier|public
name|QApplication
block|{
DECL|function|MyApplication
name|MyApplication
parameter_list|(
name|int
modifier|&
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
member_init_list|:
name|QApplication
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
block|{}
DECL|function|event
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|FileOpen
condition|)
block|{
name|QFileOpenEvent
modifier|*
name|ev
init|=
cast|static_cast
argument_list|<
name|QFileOpenEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QFile
name|file
decl_stmt|;
name|bool
name|ok
init|=
name|ev
operator|->
name|openFile
argument_list|(
name|file
argument_list|,
name|QFile
operator|::
name|Append
operator||
name|QFile
operator|::
name|Unbuffered
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
name|file
operator|.
name|write
argument_list|(
name|QByteArray
argument_list|(
literal|"+external"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
return|return
name|QApplication
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
block|}
block|}
struct|;
end_struct
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
name|MyApplication
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|a
operator|.
name|sendPostedEvents
argument_list|(
operator|&
name|a
argument_list|,
name|QEvent
operator|::
name|FileOpen
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
