begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Giuseppe D'Angelo<dangelog@gmail.com>. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"../tst_qregularexpression.h"
end_include
begin_class
DECL|class|tst_QRegularExpression_AlwaysOptimize
class|class
name|tst_QRegularExpression_AlwaysOptimize
super|:
specifier|public
name|tst_QRegularExpression
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
specifier|extern
name|Q_CORE_EXPORT
name|unsigned
name|int
name|qt_qregularexpression_optimize_after_use_count
decl_stmt|;
end_decl_stmt
begin_comment
comment|// from qregularexpression.cpp
end_comment
begin_function
name|QT_END_NAMESPACE
DECL|function|initTestCase
name|void
name|tst_QRegularExpression_AlwaysOptimize
operator|::
name|initTestCase
parameter_list|()
block|{
name|qt_qregularexpression_optimize_after_use_count
operator|=
literal|1
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QRegularExpression_AlwaysOptimize
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qregularexpression_alwaysoptimize.moc"
end_include
end_unit
