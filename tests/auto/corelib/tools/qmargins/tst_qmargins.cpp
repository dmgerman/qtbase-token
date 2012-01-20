begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qmargins.h>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QMargins
argument_list|)
end_macro
begin_class
DECL|class|tst_QMargins
class|class
name|tst_QMargins
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|dataStreamCheck
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QMargins
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QMargins
name|margins
decl_stmt|;
comment|// int QMargins::width()
comment|// void QMargins::setWidth(int)
name|margins
operator|.
name|setLeft
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|margins
operator|.
name|left
argument_list|()
argument_list|)
expr_stmt|;
name|margins
operator|.
name|setTop
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|margins
operator|.
name|top
argument_list|()
argument_list|)
expr_stmt|;
name|margins
operator|.
name|setBottom
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|margins
operator|.
name|bottom
argument_list|()
argument_list|)
expr_stmt|;
name|margins
operator|.
name|setRight
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|margins
operator|.
name|right
argument_list|()
argument_list|)
expr_stmt|;
name|margins
operator|=
name|QMargins
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|margins
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|margins
operator|.
name|setLeft
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|margins
operator|.
name|setRight
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|margins
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|margins
argument_list|,
name|QMargins
argument_list|(
literal|5
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Testing QDataStream operators
end_comment
begin_function
DECL|function|dataStreamCheck
name|void
name|tst_QMargins
operator|::
name|dataStreamCheck
parameter_list|()
block|{
name|QByteArray
name|buffer
decl_stmt|;
comment|// stream out
block|{
name|QMargins
name|marginsOut
argument_list|(
literal|0
argument_list|,
name|INT_MIN
argument_list|,
name|INT_MAX
argument_list|,
literal|6852
argument_list|)
decl_stmt|;
name|QDataStream
name|streamOut
argument_list|(
operator|&
name|buffer
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|streamOut
operator|<<
name|marginsOut
expr_stmt|;
block|}
comment|// stream in& compare
block|{
name|QMargins
name|marginsIn
decl_stmt|;
name|QDataStream
name|streamIn
argument_list|(
operator|&
name|buffer
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|streamIn
operator|>>
name|marginsIn
expr_stmt|;
name|QCOMPARE
argument_list|(
name|marginsIn
operator|.
name|left
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|marginsIn
operator|.
name|top
argument_list|()
argument_list|,
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|marginsIn
operator|.
name|right
argument_list|()
argument_list|,
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|marginsIn
operator|.
name|bottom
argument_list|()
argument_list|,
literal|6852
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QMargins
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmargins.moc"
end_include
end_unit
