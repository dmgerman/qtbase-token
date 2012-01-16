begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QScreen
class|class
name|tst_QScreen
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|angleBetween_data
parameter_list|()
function_decl|;
name|void
name|angleBetween
parameter_list|()
function_decl|;
name|void
name|transformBetween_data
parameter_list|()
function_decl|;
name|void
name|transformBetween
parameter_list|()
function_decl|;
name|void
name|orientationChange
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|angleBetween_data
name|void
name|tst_QScreen
operator|::
name|angleBetween_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|uint
argument_list|>
argument_list|(
literal|"oa"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|uint
argument_list|>
argument_list|(
literal|"ob"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait Portrait"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait Landscape"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|LandscapeOrientation
argument_list|)
operator|<<
literal|270
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait InvertedPortrait"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedPortraitOrientation
argument_list|)
operator|<<
literal|180
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait InvertedLandscape"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedLandscapeOrientation
argument_list|)
operator|<<
literal|90
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"InvertedLandscape InvertedPortrait"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedLandscapeOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedPortraitOrientation
argument_list|)
operator|<<
literal|90
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"InvertedLandscape Landscape"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedLandscapeOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|LandscapeOrientation
argument_list|)
operator|<<
literal|180
expr_stmt|;
block|}
end_function
begin_function
DECL|function|angleBetween
name|void
name|tst_QScreen
operator|::
name|angleBetween
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|uint
argument_list|,
name|oa
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|uint
argument_list|,
name|ob
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|a
init|=
name|Qt
operator|::
name|ScreenOrientation
argument_list|(
name|oa
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|b
init|=
name|Qt
operator|::
name|ScreenOrientation
argument_list|(
name|ob
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QScreen
operator|::
name|angleBetween
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QScreen
operator|::
name|angleBetween
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
argument_list|,
operator|(
literal|360
operator|-
name|expected
operator|)
operator|%
literal|360
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transformBetween_data
name|void
name|tst_QScreen
operator|::
name|transformBetween_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|uint
argument_list|>
argument_list|(
literal|"oa"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|uint
argument_list|>
argument_list|(
literal|"ob"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRect
argument_list|>
argument_list|(
literal|"rect"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QTransform
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QRect
name|rect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|480
argument_list|,
literal|640
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait Portrait"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|rect
operator|<<
name|QTransform
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait Landscape"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|LandscapeOrientation
argument_list|)
operator|<<
name|rect
operator|<<
name|QTransform
argument_list|(
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait InvertedPortrait"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedPortraitOrientation
argument_list|)
operator|<<
name|rect
operator|<<
name|QTransform
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait InvertedLandscape"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedLandscapeOrientation
argument_list|)
operator|<<
name|rect
operator|<<
name|QTransform
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"InvertedLandscape InvertedPortrait"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedLandscapeOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedPortraitOrientation
argument_list|)
operator|<<
name|rect
operator|<<
name|QTransform
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"InvertedLandscape Landscape"
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|InvertedLandscapeOrientation
argument_list|)
operator|<<
name|uint
argument_list|(
name|Qt
operator|::
name|LandscapeOrientation
argument_list|)
operator|<<
name|rect
operator|<<
name|QTransform
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transformBetween
name|void
name|tst_QScreen
operator|::
name|transformBetween
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|uint
argument_list|,
name|oa
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|uint
argument_list|,
name|ob
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRect
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|a
init|=
name|Qt
operator|::
name|ScreenOrientation
argument_list|(
name|oa
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|b
init|=
name|Qt
operator|::
name|ScreenOrientation
argument_list|(
name|ob
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QScreen
operator|::
name|transformBetween
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|rect
argument_list|)
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|orientationChange
name|void
name|tst_QScreen
operator|::
name|orientationChange
parameter_list|()
block|{
name|QScreen
modifier|*
name|screen
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenOrientationChange
argument_list|(
name|screen
argument_list|,
name|Qt
operator|::
name|LandscapeOrientation
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|screen
operator|->
name|currentOrientation
argument_list|()
argument_list|,
name|Qt
operator|::
name|LandscapeOrientation
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenOrientationChange
argument_list|(
name|screen
argument_list|,
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|screen
operator|->
name|currentOrientation
argument_list|()
argument_list|,
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|<tst_qscreen.moc>
end_include
begin_expr_stmt
DECL|variable|tst_QScreen
name|QTEST_MAIN
argument_list|(
name|tst_QScreen
argument_list|)
expr_stmt|;
end_expr_stmt
end_unit
