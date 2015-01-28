begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QIODevice>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QTemporaryFile>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
DECL|class|tst_qtemporaryfile
class|class
name|tst_qtemporaryfile
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|openclose_data
parameter_list|()
function_decl|;
name|void
name|openclose
parameter_list|()
function_decl|;
DECL|function|readwrite_data
name|void
name|readwrite_data
parameter_list|()
block|{
name|openclose_data
argument_list|()
expr_stmt|;
block|}
name|void
name|readwrite
parameter_list|()
function_decl|;
private|private:
block|}
class|;
end_class
begin_function
DECL|function|openclose_data
name|void
name|tst_qtemporaryfile
operator|::
name|openclose_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|qint64
argument_list|>
argument_list|(
literal|"amount"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10000"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openclose
name|void
name|tst_qtemporaryfile
operator|::
name|openclose
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|amount
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|qint64
name|i
init|=
literal|0
init|;
name|i
operator|<
name|amount
condition|;
operator|++
name|i
control|)
block|{
name|QTemporaryFile
name|file
decl_stmt|;
name|file
operator|.
name|open
argument_list|()
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|readwrite
name|void
name|tst_qtemporaryfile
operator|::
name|readwrite
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|amount
argument_list|)
expr_stmt|;
specifier|const
name|int
name|dataSize
init|=
literal|4096
decl_stmt|;
name|QByteArray
name|data
decl_stmt|;
name|data
operator|.
name|fill
argument_list|(
literal|'a'
argument_list|,
name|dataSize
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|qint64
name|i
init|=
literal|0
init|;
name|i
operator|<
name|amount
condition|;
operator|++
name|i
control|)
block|{
name|QTemporaryFile
name|file
decl_stmt|;
name|file
operator|.
name|open
argument_list|()
expr_stmt|;
name|file
operator|.
name|write
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|file
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|file
operator|.
name|read
argument_list|(
name|dataSize
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qtemporaryfile
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
