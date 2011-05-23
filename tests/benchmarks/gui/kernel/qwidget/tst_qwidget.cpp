begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_function
DECL|function|processEvents
specifier|static
name|void
name|processEvents
parameter_list|()
block|{
name|QApplication
operator|::
name|flush
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_class
DECL|class|UpdateWidget
class|class
name|UpdateWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|UpdateWidget
name|UpdateWidget
parameter_list|(
name|int
name|rows
parameter_list|,
name|int
name|columns
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|rowCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|columnCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|opaqueChildren
argument_list|(
literal|false
argument_list|)
block|{
name|fill
argument_list|(
name|rows
argument_list|,
name|columns
argument_list|)
expr_stmt|;
block|}
DECL|function|UpdateWidget
name|UpdateWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|rowCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|columnCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|opaqueChildren
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|fill
name|void
name|fill
parameter_list|(
name|int
name|rows
parameter_list|,
name|int
name|columns
parameter_list|)
block|{
if|if
condition|(
name|rows
operator|==
name|rowCount
operator|&&
name|columns
operator|==
name|columnCount
condition|)
return|return;
operator|delete
name|layout
argument_list|()
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|rowCount
operator|=
name|rows
expr_stmt|;
name|columnCount
operator|=
name|columns
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|rowCount
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|columnCount
condition|;
operator|++
name|column
control|)
block|{
name|UpdateWidget
modifier|*
name|widget
init|=
operator|new
name|UpdateWidget
decl_stmt|;
name|widget
operator|->
name|setFixedSize
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|widget
argument_list|,
name|row
argument_list|,
name|column
argument_list|)
expr_stmt|;
name|children
operator|.
name|append
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
block|}
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
block|}
DECL|function|setOpaqueChildren
name|void
name|setOpaqueChildren
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
if|if
condition|(
name|opaqueChildren
operator|!=
name|enable
condition|)
block|{
foreach|foreach
control|(
name|QWidget
modifier|*
name|w
decl|,
name|children
control|)
name|w
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_OpaquePaintEvent
argument_list|,
name|enable
argument_list|)
expr_stmt|;
name|opaqueChildren
operator|=
name|enable
expr_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
specifier|static
name|int
name|color
init|=
name|Qt
operator|::
name|black
decl_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|GlobalColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|color
operator|>
name|Qt
operator|::
name|darkYellow
condition|)
name|color
operator|=
name|Qt
operator|::
name|black
expr_stmt|;
block|}
DECL|member|updateRegion
name|QRegion
name|updateRegion
decl_stmt|;
DECL|member|children
name|QList
argument_list|<
name|UpdateWidget
modifier|*
argument_list|>
name|children
decl_stmt|;
DECL|member|rowCount
name|int
name|rowCount
decl_stmt|;
DECL|member|columnCount
name|int
name|columnCount
decl_stmt|;
DECL|member|opaqueChildren
name|bool
name|opaqueChildren
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|tst_QWidget
class|class
name|tst_QWidget
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|update_data
parameter_list|()
function_decl|;
name|void
name|update
parameter_list|()
function_decl|;
name|void
name|updatePartial_data
parameter_list|()
function_decl|;
name|void
name|updatePartial
parameter_list|()
function_decl|;
name|void
name|updateComplex_data
parameter_list|()
function_decl|;
name|void
name|updateComplex
parameter_list|()
function_decl|;
private|private:
DECL|member|widget
name|UpdateWidget
name|widget
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QWidget
operator|::
name|initTestCase
parameter_list|()
block|{
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QWidget
operator|::
name|init
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|widget
operator|.
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
operator|++
name|i
control|)
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|update_data
name|void
name|tst_QWidget
operator|::
name|update_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"rows"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"columns"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"numUpdates"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"opaque"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10x10x1 transparent"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10x10x10 transparent"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10x10x100 transparent"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|100
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10x10x1 opaque"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|1
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10x10x10 opaque"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10x10x100 opaque"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|100
operator|<<
literal|true
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
comment|//These test cases cause stack overflow in QWidgetPrivate::paintSiblingsRecursive
comment|//see http://bugreports.qt.nokia.com/browse/QTBUG-8512
comment|//Symbian threads have a hard limit of 80kB user stack
name|QTest
operator|::
name|newRow
argument_list|(
literal|"25x25x1 transparent "
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
literal|1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"25x25x10 transparent"
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
literal|10
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"25x25x100 transparent"
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
literal|100
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"25x25x1 opaque"
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
literal|1
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"25x25x10 opaque"
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
literal|10
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"25x25x100 opaque"
argument_list|)
operator|<<
literal|25
operator|<<
literal|25
operator|<<
literal|100
operator|<<
literal|true
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|update
name|void
name|tst_QWidget
operator|::
name|update
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|rows
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|columns
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|numUpdates
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|opaque
argument_list|)
expr_stmt|;
name|widget
operator|.
name|fill
argument_list|(
name|rows
argument_list|,
name|columns
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setOpaqueChildren
argument_list|(
name|opaque
argument_list|)
expr_stmt|;
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
operator|<
name|widget
operator|.
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|numUpdates
condition|;
operator|++
name|j
control|)
name|widget
operator|.
name|children
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|update
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
block|}
block|}
name|QApplication
operator|::
name|flush
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updatePartial_data
name|void
name|tst_QWidget
operator|::
name|updatePartial_data
parameter_list|()
block|{
name|update_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updatePartial
name|void
name|tst_QWidget
operator|::
name|updatePartial
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|rows
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|columns
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|numUpdates
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|opaque
argument_list|)
expr_stmt|;
name|widget
operator|.
name|fill
argument_list|(
name|rows
argument_list|,
name|columns
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setOpaqueChildren
argument_list|(
name|opaque
argument_list|)
expr_stmt|;
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
operator|<
name|widget
operator|.
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|widget
operator|.
name|children
index|[
name|i
index|]
decl_stmt|;
specifier|const
name|int
name|x
init|=
name|w
operator|->
name|width
argument_list|()
operator|/
literal|2
decl_stmt|;
specifier|const
name|int
name|y
init|=
name|w
operator|->
name|height
argument_list|()
operator|/
literal|2
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|numUpdates
condition|;
operator|++
name|j
control|)
block|{
name|w
operator|->
name|update
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|w
operator|->
name|update
argument_list|(
name|x
argument_list|,
literal|0
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|w
operator|->
name|update
argument_list|(
literal|0
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|w
operator|->
name|update
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|updateComplex_data
name|void
name|tst_QWidget
operator|::
name|updateComplex_data
parameter_list|()
block|{
name|update_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateComplex
name|void
name|tst_QWidget
operator|::
name|updateComplex
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|rows
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|columns
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|numUpdates
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|opaque
argument_list|)
expr_stmt|;
name|widget
operator|.
name|fill
argument_list|(
name|rows
argument_list|,
name|columns
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setOpaqueChildren
argument_list|(
name|opaque
argument_list|)
expr_stmt|;
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
operator|<
name|widget
operator|.
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|widget
operator|.
name|children
index|[
name|i
index|]
decl_stmt|;
specifier|const
name|int
name|x
init|=
name|w
operator|->
name|width
argument_list|()
operator|/
literal|2
decl_stmt|;
specifier|const
name|int
name|y
init|=
name|w
operator|->
name|height
argument_list|()
operator|/
literal|2
decl_stmt|;
name|QRegion
name|r1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|QRegion
operator|::
name|Ellipse
argument_list|)
decl_stmt|;
name|QRegion
name|r2
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|QRegion
operator|::
name|Ellipse
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|numUpdates
condition|;
operator|++
name|j
control|)
block|{
name|w
operator|->
name|update
argument_list|(
name|r1
argument_list|)
expr_stmt|;
name|w
operator|->
name|update
argument_list|(
name|r2
argument_list|)
expr_stmt|;
block|}
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QWidget
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwidget.moc"
end_include
end_unit
