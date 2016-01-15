begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qtest.h>
end_include
begin_class
DECL|class|tst_qiodevice
class|class
name|tst_qiodevice
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|read_old
parameter_list|()
function_decl|;
DECL|function|read_old_data
name|void
name|read_old_data
parameter_list|()
block|{
name|read_data
argument_list|()
expr_stmt|;
block|}
comment|//void read_new();
comment|//void read_new_data() { read_data(); }
private|private:
name|void
name|read_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|read_data
name|void
name|tst_qiodevice
operator|::
name|read_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|qint64
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10k"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|10
operator|*
literal|1024
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100k"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|100
operator|*
literal|1024
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000k"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|1000
operator|*
literal|1024
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10000k"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|10000
operator|*
literal|1024
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100000k"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|100000
operator|*
literal|1024
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000000k"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|1000000
operator|*
literal|1024
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|read_old
name|void
name|tst_qiodevice
operator|::
name|read_old
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QString
name|name
init|=
literal|"tmp"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
block|{
name|QFile
name|file
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|file
operator|.
name|seek
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|file
operator|.
name|write
argument_list|(
literal|"x"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
name|QBENCHMARK
block|{
name|QFile
name|file
argument_list|(
name|name
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
name|QByteArray
name|ba
decl_stmt|;
name|qint64
name|s
init|=
name|size
operator|-
literal|1024
decl_stmt|;
name|file
operator|.
name|seek
argument_list|(
literal|512
argument_list|)
expr_stmt|;
name|ba
operator|=
name|file
operator|.
name|read
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|// crash happens during this read / assignment operation
block|}
block|{
name|QFile
name|file
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|file
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qiodevice
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
