begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_SkipInit
class|class
name|tst_SkipInit
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
specifier|const
function_decl|;
name|void
name|aTestFunction
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_SkipInit
operator|::
name|initTestCase
parameter_list|()
specifier|const
block|{
name|QSKIP
argument_list|(
literal|"Skip inside initTestCase. This should skip all tests in the class."
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal   This function should never be run because initTestCase fails.  */
end_comment
begin_function
DECL|function|aTestFunction
name|void
name|tst_SkipInit
operator|::
name|aTestFunction
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
literal|"ERROR: This function is NOT supposed to be run."
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_SkipInit
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_skipinit.moc"
end_include
end_unit
