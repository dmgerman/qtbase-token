begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QClipboard>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
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
modifier|*
name|argv
parameter_list|)
block|{
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QString
name|paste
init|=
name|QStringLiteral
argument_list|(
literal|"testString.!"
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|const
name|QStringList
name|arguments
init|=
name|app
operator|.
name|arguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|arguments
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
name|paste
operator|=
name|arguments
operator|.
name|at
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setText
argument_list|(
name|paste
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
