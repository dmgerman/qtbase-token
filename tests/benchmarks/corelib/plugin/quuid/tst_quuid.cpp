begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUuid>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_bench_QUuid
class|class
name|tst_bench_QUuid
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_bench_QUuid
name|tst_bench_QUuid
parameter_list|()
block|{ }
private|private
name|slots
private|:
name|void
name|createUuid
parameter_list|()
function_decl|;
name|void
name|fromChar
parameter_list|()
function_decl|;
name|void
name|toString
parameter_list|()
function_decl|;
name|void
name|fromString
parameter_list|()
function_decl|;
name|void
name|toByteArray
parameter_list|()
function_decl|;
name|void
name|fromByteArray
parameter_list|()
function_decl|;
name|void
name|toRfc4122
parameter_list|()
function_decl|;
name|void
name|fromRfc4122
parameter_list|()
function_decl|;
name|void
name|createUuidV3
parameter_list|()
function_decl|;
name|void
name|createUuidV5
parameter_list|()
function_decl|;
name|void
name|toDataStream
parameter_list|()
function_decl|;
name|void
name|fromDataStream
parameter_list|()
function_decl|;
name|void
name|isNull
parameter_list|()
function_decl|;
name|void
name|operatorLess
parameter_list|()
function_decl|;
name|void
name|operatorMore
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|createUuid
name|void
name|tst_bench_QUuid
operator|::
name|createUuid
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fromChar
name|void
name|tst_bench_QUuid
operator|::
name|fromChar
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QUuid
name|uuid
argument_list|(
literal|"{67C8770B-44F1-410A-AB9A-F9B5446F13EE}"
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toString
name|void
name|tst_bench_QUuid
operator|::
name|toString
parameter_list|()
block|{
name|QUuid
name|uuid
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|uuid
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fromString
name|void
name|tst_bench_QUuid
operator|::
name|fromString
parameter_list|()
block|{
name|QString
name|string
init|=
literal|"{67C8770B-44F1-410A-AB9A-F9B5446F13EE}"
decl_stmt|;
name|QBENCHMARK
block|{
name|QUuid
name|uuid
argument_list|(
name|string
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toByteArray
name|void
name|tst_bench_QUuid
operator|::
name|toByteArray
parameter_list|()
block|{
name|QUuid
name|uuid
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|uuid
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fromByteArray
name|void
name|tst_bench_QUuid
operator|::
name|fromByteArray
parameter_list|()
block|{
name|QByteArray
name|string
init|=
literal|"{67C8770B-44F1-410A-AB9A-F9B5446F13EE}"
decl_stmt|;
name|QBENCHMARK
block|{
name|QUuid
name|uuid
argument_list|(
name|string
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toRfc4122
name|void
name|tst_bench_QUuid
operator|::
name|toRfc4122
parameter_list|()
block|{
name|QUuid
name|uuid
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|uuid
operator|.
name|toRfc4122
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fromRfc4122
name|void
name|tst_bench_QUuid
operator|::
name|fromRfc4122
parameter_list|()
block|{
name|QByteArray
name|string
init|=
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"67C8770B44F1410AAB9AF9B5446F13EE"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QUuid
name|uuid
init|=
name|QUuid
operator|::
name|fromRfc4122
argument_list|(
name|string
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createUuidV3
name|void
name|tst_bench_QUuid
operator|::
name|createUuidV3
parameter_list|()
block|{
name|QUuid
name|ns
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QByteArray
name|name
init|=
name|QByteArray
argument_list|(
literal|"Test"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QUuid
name|uuid
init|=
name|QUuid
operator|::
name|createUuidV3
argument_list|(
name|ns
argument_list|,
name|name
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createUuidV5
name|void
name|tst_bench_QUuid
operator|::
name|createUuidV5
parameter_list|()
block|{
name|QUuid
name|ns
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QByteArray
name|name
init|=
name|QByteArray
argument_list|(
literal|"Test"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QUuid
name|uuid
init|=
name|QUuid
operator|::
name|createUuidV5
argument_list|(
name|ns
argument_list|,
name|name
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toDataStream
name|void
name|tst_bench_QUuid
operator|::
name|toDataStream
parameter_list|()
block|{
name|QUuid
name|uuid1
decl_stmt|,
name|uuid2
decl_stmt|;
name|uuid1
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
name|QByteArray
name|ar
decl_stmt|;
block|{
name|QDataStream
name|out
argument_list|(
operator|&
name|ar
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|out
operator|<<
name|uuid1
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|fromDataStream
name|void
name|tst_bench_QUuid
operator|::
name|fromDataStream
parameter_list|()
block|{
name|QUuid
name|uuid1
decl_stmt|,
name|uuid2
decl_stmt|;
name|uuid1
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
name|QByteArray
name|ar
decl_stmt|;
block|{
name|QDataStream
name|out
argument_list|(
operator|&
name|ar
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|out
operator|<<
name|uuid1
expr_stmt|;
block|}
block|{
name|QDataStream
name|in
argument_list|(
operator|&
name|ar
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|in
operator|>>
name|uuid2
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|isNull
name|void
name|tst_bench_QUuid
operator|::
name|isNull
parameter_list|()
block|{
name|QUuid
name|uuid
init|=
name|QUuid
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|uuid
operator|.
name|isNull
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|operatorLess
name|void
name|tst_bench_QUuid
operator|::
name|operatorLess
parameter_list|()
block|{
name|QUuid
name|uuid1
decl_stmt|,
name|uuid2
decl_stmt|;
name|uuid1
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
name|uuid2
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
name|QBENCHMARK
block|{
name|uuid1
operator|<
name|uuid2
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|operatorMore
name|void
name|tst_bench_QUuid
operator|::
name|operatorMore
parameter_list|()
block|{
name|QUuid
name|uuid1
decl_stmt|,
name|uuid2
decl_stmt|;
name|uuid1
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
name|uuid2
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
name|QBENCHMARK
block|{
name|uuid1
operator|>
name|uuid2
expr_stmt|;
block|}
block|}
end_function
begin_expr_stmt
DECL|variable|tst_bench_QUuid
name|QTEST_MAIN
argument_list|(
name|tst_bench_QUuid
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_quuid.moc"
end_include
end_unit
