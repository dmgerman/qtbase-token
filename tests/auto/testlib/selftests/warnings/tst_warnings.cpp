begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRegularExpression>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_Warnings
class|class
name|tst_Warnings
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testWarnings
parameter_list|()
function_decl|;
name|void
name|testMissingWarnings
parameter_list|()
function_decl|;
name|void
name|testMissingWarningsRegularExpression
parameter_list|()
function_decl|;
name|void
name|testMissingWarningsWithData_data
parameter_list|()
function_decl|;
name|void
name|testMissingWarningsWithData
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testWarnings
name|void
name|tst_Warnings
operator|::
name|testWarnings
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"Warning"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Warning"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Warning"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Warning"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Debug"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtDebugMsg
argument_list|,
literal|"Debug"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Debug"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Debug"
argument_list|)
expr_stmt|;
name|qInfo
argument_list|(
literal|"Info"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtInfoMsg
argument_list|,
literal|"Info"
argument_list|)
expr_stmt|;
name|qInfo
argument_list|(
literal|"Info"
argument_list|)
expr_stmt|;
name|qInfo
argument_list|(
literal|"Info"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtDebugMsg
argument_list|,
literal|"Bubu"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Baba"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Bubu"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Baba"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtDebugMsg
argument_list|,
name|QRegularExpression
argument_list|(
literal|"^Bubu.*"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
name|QRegularExpression
argument_list|(
literal|"^Baba.*"
argument_list|)
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Bubublabla"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Babablabla"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"Bubublabla"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Babablabla"
argument_list|)
expr_stmt|;
comment|// accept redundant space at end to keep compatibility with Qt< 5.2
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtDebugMsg
argument_list|,
literal|"Bubu "
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Bubu"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testMissingWarnings
name|void
name|tst_Warnings
operator|::
name|testMissingWarnings
parameter_list|()
block|{
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Warning0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Warning1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Warning2"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Warning2"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testMissingWarningsRegularExpression
name|void
name|tst_Warnings
operator|::
name|testMissingWarningsRegularExpression
parameter_list|()
block|{
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
name|QRegularExpression
argument_list|(
literal|"Warning\\d\\d"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
name|QRegularExpression
argument_list|(
literal|"Warning\\s\\d"
argument_list|)
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Warning11"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testMissingWarningsWithData_data
name|void
name|tst_Warnings
operator|::
name|testMissingWarningsWithData_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"dummy"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"first row"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"second row"
argument_list|)
operator|<<
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testMissingWarningsWithData
name|void
name|tst_Warnings
operator|::
name|testMissingWarningsWithData
parameter_list|()
block|{
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Warning0"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Warning1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"Warning2"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Warning2"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Warnings
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_warnings.moc"
end_include
end_unit
