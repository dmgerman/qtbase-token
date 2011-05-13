begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*  ////////////////////////////////////////////////////////////////////  This benchmark serves as reality check on the idea that hashing the complete string is a good idea.    Executive summary: It is not a good idea.  ////////////////////////////////////////////////////////////////////  ********* Start testing of tst_QHash ********* Config: Using QTest library 5.0.0, Qt 5.0.0 PASS   : tst_QHash::initTestCase() RESULT : tst_QHash::qhash_qt4():      0.041 msecs per iteration (total: 85, iterations: 2048) PASS   : tst_QHash::qhash_qt4() RESULT : tst_QHash::qhash_faster():      0.0122 msecs per iteration (total: 100, iterations: 8192) PASS   : tst_QHash::qhash_faster() PASS   : tst_QHash::cleanupTestCase() Totals: 4 passed, 0 failed, 0 skipped  ////////////////////////////////////////////////////////////////////  */
end_comment
begin_include
include|#
directive|include
file|"qhash_string.h"
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QTest>
end_include
begin_class
DECL|class|tst_QHash
class|class
name|tst_QHash
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|qhash_qt4
parameter_list|()
function_decl|;
name|void
name|qhash_faster
parameter_list|()
function_decl|;
private|private:
name|QString
name|data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|N
specifier|const
name|int
name|N
init|=
literal|1000000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|double
name|s
decl_stmt|;
end_decl_stmt
begin_comment
comment|///////////////////// QHash /////////////////////
end_comment
begin_function
DECL|function|data
name|QString
name|tst_QHash
operator|::
name|data
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
literal|"data.txt"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qhash_qt4
name|void
name|tst_QHash
operator|::
name|qhash_qt4
parameter_list|()
block|{
name|QStringList
name|items
init|=
name|data
argument_list|()
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
decl_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|hash
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|n
init|=
name|items
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|n
condition|;
operator|++
name|i
control|)
block|{
name|hash
index|[
name|items
operator|.
name|at
argument_list|(
name|i
argument_list|)
index|]
operator|=
name|i
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|qhash_faster
name|void
name|tst_QHash
operator|::
name|qhash_faster
parameter_list|()
block|{
name|QList
argument_list|<
name|String
argument_list|>
name|items
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|s
decl|,
name|data
argument_list|()
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
control|)
name|items
operator|.
name|append
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|String
argument_list|,
name|int
argument_list|>
name|hash
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|n
init|=
name|items
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|n
condition|;
operator|++
name|i
control|)
block|{
name|hash
index|[
name|items
operator|.
name|at
argument_list|(
name|i
argument_list|)
index|]
operator|=
name|i
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QHash
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"qhash_string.moc"
end_include
end_unit
