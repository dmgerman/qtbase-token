begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Robin Burchell<robin.burchell@viroteck.net> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QStack>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_class
DECL|class|tst_QStack
class|class
name|tst_QStack
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|qstack_push
parameter_list|()
function_decl|;
name|void
name|qstack_pop
parameter_list|()
function_decl|;
name|void
name|qstack_pushpopone
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
begin_function
DECL|function|qstack_push
name|void
name|tst_QStack
operator|::
name|qstack_push
parameter_list|()
block|{
name|QStack
argument_list|<
name|int
argument_list|>
name|v
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|push
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|v
operator|=
name|QStack
argument_list|<
name|int
argument_list|>
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qstack_pop
name|void
name|tst_QStack
operator|::
name|qstack_pop
parameter_list|()
block|{
name|QStack
argument_list|<
name|int
argument_list|>
name|v
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|push
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QStack
argument_list|<
name|int
argument_list|>
name|v2
init|=
name|v
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
block|{
name|v2
operator|.
name|pop
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|qstack_pushpopone
name|void
name|tst_QStack
operator|::
name|qstack_pushpopone
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QStack
argument_list|<
name|int
argument_list|>
name|v
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
block|{
name|v
operator|.
name|push
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|v
operator|.
name|pop
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QStack
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
