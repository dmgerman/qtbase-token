begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QPalette>
end_include
begin_include
include|#
directive|include
file|<QWindowsStyle>
end_include
begin_include
include|#
directive|include
file|<QDesktopWidget>
end_include
begin_include
include|#
directive|include
file|<QX11Info>
end_include
begin_include
include|#
directive|include
file|"../../shared/util.h"
end_include
begin_if
if|#
directive|if
name|QT_VERSION
operator|<
literal|0x050000
end_if
begin_include
include|#
directive|include
file|<private/qwindowsurface_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QWindowSurface
class|class
name|tst_QWindowSurface
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
else|#
directive|else
private|private
name|slots
private|:
name|void
name|getSetWindowSurface
parameter_list|()
function_decl|;
name|void
name|flushOutsidePaintEvent
parameter_list|()
function_decl|;
name|void
name|grabWidget
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_if
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
end_if
begin_function
DECL|function|initTestCase
name|void
name|tst_QWindowSurface
operator|::
name|initTestCase
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"This test is temporarily skipped until it is fixed for Qt5"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_class
DECL|class|MyWindowSurface
class|class
name|MyWindowSurface
super|:
specifier|public
name|QWindowSurface
block|{
public|public:
DECL|function|MyWindowSurface
name|MyWindowSurface
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QWindowSurface
argument_list|(
name|w
argument_list|)
block|{}
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|paintDevice
parameter_list|()
block|{
return|return
operator|&
name|image
return|;
block|}
DECL|function|flush
name|void
name|flush
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
specifier|const
name|QRegion
modifier|&
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
block|{
comment|/* nothing */
block|}
private|private:
DECL|member|image
name|QImage
name|image
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|ColorWidget
class|class
name|ColorWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|ColorWidget
name|ColorWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|QColor
modifier|&
name|c
init|=
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|,
name|Qt
operator|::
name|FramelessWindowHint
argument_list|)
member_init_list|,
name|color
argument_list|(
name|c
argument_list|)
block|{
name|QPalette
name|opaquePalette
init|=
name|palette
argument_list|()
decl_stmt|;
name|opaquePalette
operator|.
name|setColor
argument_list|(
name|backgroundRole
argument_list|()
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|setPalette
argument_list|(
name|opaquePalette
argument_list|)
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|e
parameter_list|)
block|{
name|r
operator|+=
name|e
operator|->
name|region
argument_list|()
expr_stmt|;
block|}
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|r
operator|=
name|QRegion
argument_list|()
expr_stmt|;
block|}
DECL|member|color
name|QColor
name|color
decl_stmt|;
DECL|member|r
name|QRegion
name|r
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//from tst_qwidget.cpp
end_comment
begin_function
DECL|function|VERIFY_COLOR
specifier|static
name|void
name|VERIFY_COLOR
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
specifier|const
name|QRegion
name|r
init|=
name|QRegion
argument_list|(
name|region
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|r
operator|.
name|rects
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QRect
name|rect
init|=
name|r
operator|.
name|rects
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|t
init|=
literal|0
init|;
name|t
operator|<
literal|5
condition|;
name|t
operator|++
control|)
block|{
specifier|const
name|QPixmap
name|pixmap
init|=
name|QPixmap
operator|::
name|grabWindow
argument_list|(
name|QDesktopWidget
argument_list|()
operator|.
name|winId
argument_list|()
argument_list|,
name|rect
operator|.
name|left
argument_list|()
argument_list|,
name|rect
operator|.
name|top
argument_list|()
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
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_QPA
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-20863 QPixmap::grabWindow unimplemented for qpa"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|pixmap
operator|.
name|size
argument_list|()
argument_list|,
name|rect
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QPixmap
name|expectedPixmap
argument_list|(
name|pixmap
argument_list|)
decl_stmt|;
comment|/* ensure equal formats */
name|expectedPixmap
operator|.
name|fill
argument_list|(
name|color
argument_list|)
expr_stmt|;
if|if
condition|(
name|pixmap
operator|.
name|toImage
argument_list|()
operator|.
name|pixel
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|!=
name|QColor
argument_list|(
name|color
argument_list|)
operator|.
name|rgb
argument_list|()
operator|&&
name|t
operator|<
literal|4
condition|)
block|{
name|QTest
operator|::
name|qWait
argument_list|(
literal|200
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|QCOMPARE
argument_list|(
name|pixmap
operator|.
name|toImage
argument_list|()
operator|.
name|pixel
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|color
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pixmap
argument_list|,
name|expectedPixmap
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|getSetWindowSurface
name|void
name|tst_QWindowSurface
operator|::
name|getSetWindowSurface
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|w
operator|.
name|windowSurface
argument_list|()
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|windowSurface
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
literal|2
condition|;
operator|++
name|i
control|)
block|{
name|MyWindowSurface
modifier|*
name|surface
init|=
operator|new
name|MyWindowSurface
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|windowSurface
argument_list|()
argument_list|,
operator|(
name|QWindowSurface
operator|*
operator|)
name|surface
argument_list|)
expr_stmt|;
name|w
operator|.
name|setWindowSurface
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|windowSurface
argument_list|()
argument_list|,
operator|(
name|QWindowSurface
operator|*
operator|)
name|surface
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|flushOutsidePaintEvent
name|void
name|tst_QWindowSurface
operator|::
name|flushOutsidePaintEvent
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|QX11Info
operator|::
name|isCompositingManagerRunning
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Test is unreliable with composition manager"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_WIN
if|if
condition|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|&
name|QSysInfo
operator|::
name|WV_VISTA
condition|)
block|{
name|QTest
operator|::
name|qWait
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|ColorWidget
name|w
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
decl_stmt|;
name|w
operator|.
name|setGeometry
argument_list|(
literal|10
argument_list|,
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
comment|// prevent custom styles from messing up the background
name|w
operator|.
name|setStyle
argument_list|(
operator|new
name|QWindowsStyle
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
name|QApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
comment|//for the glib event loop
endif|#
directive|endif
name|VERIFY_COLOR
argument_list|(
name|w
operator|.
name|geometry
argument_list|()
argument_list|,
name|w
operator|.
name|color
argument_list|)
expr_stmt|;
name|w
operator|.
name|reset
argument_list|()
expr_stmt|;
comment|// trigger a paintEvent() the next time the event loop is entered
name|w
operator|.
name|update
argument_list|()
expr_stmt|;
comment|// draw a black rectangle inside the widget
name|QWindowSurface
modifier|*
name|surface
init|=
name|w
operator|.
name|windowSurface
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|surface
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|rect
init|=
name|surface
operator|->
name|rect
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|surface
operator|->
name|beginPaint
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QImage
modifier|*
name|img
init|=
name|surface
operator|->
name|buffer
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
if|if
condition|(
name|img
condition|)
block|{
name|QPainter
name|p
argument_list|(
name|img
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|img
operator|->
name|size
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
block|}
name|surface
operator|->
name|endPaint
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|surface
operator|->
name|flush
argument_list|(
operator|&
name|w
argument_list|,
name|rect
argument_list|,
name|QPoint
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_QWS
name|VERIFY_COLOR
argument_list|(
name|w
operator|.
name|geometry
argument_list|()
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// the paintEvent() should overwrite the painted rectangle
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
name|QSKIP
argument_list|(
literal|"task 176755"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|VERIFY_COLOR
argument_list|(
name|w
operator|.
name|geometry
argument_list|()
argument_list|,
name|w
operator|.
name|color
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QRegion
argument_list|(
name|w
operator|.
name|rect
argument_list|()
argument_list|)
argument_list|,
name|w
operator|.
name|r
argument_list|)
expr_stmt|;
name|w
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|grabWidget
name|void
name|tst_QWindowSurface
operator|::
name|grabWidget
parameter_list|()
block|{
name|QWidget
name|parentWidget
decl_stmt|;
name|QWidget
name|childWidget
argument_list|(
operator|&
name|parentWidget
argument_list|)
decl_stmt|;
name|QWidget
name|babyWidget
argument_list|(
operator|&
name|childWidget
argument_list|)
decl_stmt|;
name|parentWidget
operator|.
name|resize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|childWidget
operator|.
name|setGeometry
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|childWidget
operator|.
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|babyWidget
operator|.
name|setGeometry
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|babyWidget
operator|.
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QPalette
name|pal
init|=
name|parentWidget
operator|.
name|palette
argument_list|()
decl_stmt|;
name|pal
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
expr_stmt|;
name|parentWidget
operator|.
name|setPalette
argument_list|(
name|pal
argument_list|)
expr_stmt|;
name|pal
operator|=
name|childWidget
operator|.
name|palette
argument_list|()
expr_stmt|;
name|pal
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|childWidget
operator|.
name|setPalette
argument_list|(
name|pal
argument_list|)
expr_stmt|;
name|pal
operator|=
name|babyWidget
operator|.
name|palette
argument_list|()
expr_stmt|;
name|pal
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|babyWidget
operator|.
name|setPalette
argument_list|(
name|pal
argument_list|)
expr_stmt|;
comment|// prevent custom styles from messing up the background
name|parentWidget
operator|.
name|setStyle
argument_list|(
operator|new
name|QWindowsStyle
argument_list|)
expr_stmt|;
name|babyWidget
operator|.
name|show
argument_list|()
expr_stmt|;
name|childWidget
operator|.
name|show
argument_list|()
expr_stmt|;
name|parentWidget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|parentWidget
argument_list|)
expr_stmt|;
name|QPixmap
name|parentPixmap
decl_stmt|;
name|QTRY_COMPARE
argument_list|(
operator|(
name|parentPixmap
operator|=
name|parentWidget
operator|.
name|windowSurface
argument_list|()
operator|->
name|grabWidget
argument_list|(
operator|&
name|parentWidget
argument_list|)
operator|)
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
argument_list|)
expr_stmt|;
name|QPixmap
name|childPixmap
init|=
name|childWidget
operator|.
name|windowSurface
argument_list|()
operator|->
name|grabWidget
argument_list|(
operator|&
name|childWidget
argument_list|)
decl_stmt|;
name|QPixmap
name|babyPixmap
init|=
name|babyWidget
operator|.
name|windowSurface
argument_list|()
operator|->
name|grabWidget
argument_list|(
operator|&
name|babyWidget
argument_list|)
decl_stmt|;
name|QPixmap
name|parentSubPixmap
init|=
name|parentWidget
operator|.
name|windowSurface
argument_list|()
operator|->
name|grabWidget
argument_list|(
operator|&
name|parentWidget
argument_list|,
name|QRect
argument_list|(
literal|25
argument_list|,
literal|25
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|QPixmap
name|childSubPixmap
init|=
name|childWidget
operator|.
name|windowSurface
argument_list|()
operator|->
name|grabWidget
argument_list|(
operator|&
name|childWidget
argument_list|,
name|QRect
argument_list|(
literal|55
argument_list|,
literal|55
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
decl_stmt|;
name|QPixmap
name|childInvalidSubPixmap
init|=
name|childWidget
operator|.
name|windowSurface
argument_list|()
operator|->
name|grabWidget
argument_list|(
operator|&
name|childWidget
argument_list|,
name|QRect
argument_list|(
operator|-
literal|50
argument_list|,
operator|-
literal|50
argument_list|,
literal|150
argument_list|,
literal|150
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|parentPixmap
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childPixmap
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|babyPixmap
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|parentSubPixmap
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childSubPixmap
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|childInvalidSubPixmap
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QImage
name|parentImage
init|=
name|parentPixmap
operator|.
name|toImage
argument_list|()
decl_stmt|;
name|QImage
name|childImage
init|=
name|childPixmap
operator|.
name|toImage
argument_list|()
decl_stmt|;
name|QImage
name|babyImage
init|=
name|babyPixmap
operator|.
name|toImage
argument_list|()
decl_stmt|;
name|QImage
name|parentSubImage
init|=
name|parentSubPixmap
operator|.
name|toImage
argument_list|()
decl_stmt|;
name|QImage
name|childSubImage
init|=
name|childSubPixmap
operator|.
name|toImage
argument_list|()
decl_stmt|;
name|QImage
name|childInvalidSubImage
init|=
name|childInvalidSubPixmap
operator|.
name|toImage
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|parentImage
operator|.
name|pixel
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|parentImage
operator|.
name|pixel
argument_list|(
literal|75
argument_list|,
literal|75
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|parentImage
operator|.
name|pixel
argument_list|(
literal|149
argument_list|,
literal|149
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|childImage
operator|.
name|pixel
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|childImage
operator|.
name|pixel
argument_list|(
literal|99
argument_list|,
literal|99
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|parentSubImage
operator|.
name|pixel
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|parentSubImage
operator|.
name|pixel
argument_list|(
literal|30
argument_list|,
literal|30
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|parentSubImage
operator|.
name|pixel
argument_list|(
literal|80
argument_list|,
literal|80
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|childSubImage
operator|.
name|pixel
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QColor
argument_list|(
name|childInvalidSubImage
operator|.
name|pixel
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|==
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QWindowSurface
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwindowsurface.moc"
end_include
end_unit
