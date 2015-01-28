begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QSystemSemaphore>
end_include
begin_function
DECL|function|acquire
name|int
name|acquire
parameter_list|(
name|int
name|count
init|=
literal|1
parameter_list|)
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"store"
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|sem
operator|.
name|acquire
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Could not acquire"
operator|<<
name|sem
operator|.
name|key
argument_list|()
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
block|}
name|qDebug
argument_list|(
literal|"done aquiring"
argument_list|)
expr_stmt|;
return|return
name|EXIT_SUCCESS
return|;
block|}
end_function
begin_function
DECL|function|release
name|int
name|release
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"store"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|sem
operator|.
name|release
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Could not release"
operator|<<
name|sem
operator|.
name|key
argument_list|()
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
name|qDebug
argument_list|(
literal|"done releasing"
argument_list|)
expr_stmt|;
return|return
name|EXIT_SUCCESS
return|;
block|}
end_function
begin_function
DECL|function|acquirerelease
name|int
name|acquirerelease
parameter_list|()
block|{
name|QSystemSemaphore
name|sem
argument_list|(
literal|"store"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|sem
operator|.
name|acquire
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Could not acquire"
operator|<<
name|sem
operator|.
name|key
argument_list|()
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
if|if
condition|(
operator|!
name|sem
operator|.
name|release
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Could not release"
operator|<<
name|sem
operator|.
name|key
argument_list|()
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
return|return
name|EXIT_SUCCESS
return|;
block|}
end_function
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
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QStringList
name|arguments
init|=
name|app
operator|.
name|arguments
argument_list|()
decl_stmt|;
comment|// binary name is not used here
name|arguments
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
if|if
condition|(
name|arguments
operator|.
name|count
argument_list|()
operator|<
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"Please call the helper with the function to call as argument"
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
name|QString
name|function
init|=
name|arguments
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
if|if
condition|(
name|function
operator|==
name|QLatin1String
argument_list|(
literal|"acquire"
argument_list|)
condition|)
block|{
name|int
name|count
init|=
literal|1
decl_stmt|;
name|bool
name|ok
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|arguments
operator|.
name|count
argument_list|()
condition|)
name|count
operator|=
name|arguments
operator|.
name|takeFirst
argument_list|()
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|count
operator|=
literal|1
expr_stmt|;
return|return
name|acquire
argument_list|(
name|count
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|function
operator|==
name|QLatin1String
argument_list|(
literal|"release"
argument_list|)
condition|)
block|{
return|return
name|release
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
name|function
operator|==
name|QLatin1String
argument_list|(
literal|"acquirerelease"
argument_list|)
condition|)
block|{
return|return
name|acquirerelease
argument_list|()
return|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Unknown function"
operator|<<
name|function
expr_stmt|;
block|}
return|return
name|EXIT_SUCCESS
return|;
block|}
end_function
end_unit
