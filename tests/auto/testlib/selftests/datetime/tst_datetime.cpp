begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDateTime>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_comment
comment|/*!   \internal  */
end_comment
begin_class
DECL|class|tst_DateTime
class|class
name|tst_DateTime
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|dateTime
parameter_list|()
specifier|const
function_decl|;
name|void
name|qurl
parameter_list|()
specifier|const
function_decl|;
name|void
name|qurl_data
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|dateTime
name|void
name|tst_DateTime
operator|::
name|dateTime
parameter_list|()
specifier|const
block|{
specifier|const
name|QDateTime
name|utc
argument_list|(
name|QDate
argument_list|(
literal|2000
argument_list|,
literal|5
argument_list|,
literal|3
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|4
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
argument_list|,
name|Qt
operator|::
name|UTC
argument_list|)
decl_stmt|;
specifier|const
name|QDateTime
name|local
argument_list|(
name|QDate
argument_list|(
literal|2000
argument_list|,
literal|5
argument_list|,
literal|3
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|4
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
argument_list|,
name|Qt
operator|::
name|OffsetFromUTC
argument_list|,
literal|120
comment|/* 2 minutes */
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|local
argument_list|,
name|utc
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qurl
name|void
name|tst_DateTime
operator|::
name|qurl
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QUrl
argument_list|,
name|operandA
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QUrl
argument_list|,
name|operandB
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|operandA
argument_list|,
name|operandB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qurl_data
name|void
name|tst_DateTime
operator|::
name|qurl_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QUrl
argument_list|>
argument_list|(
literal|"operandA"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QUrl
argument_list|>
argument_list|(
literal|"operandB"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty urls"
argument_list|)
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QUrl
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty rhs"
argument_list|)
operator|<<
name|QUrl
argument_list|(
name|QLatin1String
argument_list|(
literal|"http://example.com"
argument_list|)
argument_list|)
operator|<<
name|QUrl
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty lhs"
argument_list|)
operator|<<
name|QUrl
argument_list|()
operator|<<
name|QUrl
argument_list|(
name|QLatin1String
argument_list|(
literal|"http://example.com"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"same urls"
argument_list|)
operator|<<
name|QUrl
argument_list|(
name|QLatin1String
argument_list|(
literal|"http://example.com"
argument_list|)
argument_list|)
operator|<<
name|QUrl
argument_list|(
name|QLatin1String
argument_list|(
literal|"http://example.com"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_DateTime
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_datetime.moc"
end_include
end_unit
