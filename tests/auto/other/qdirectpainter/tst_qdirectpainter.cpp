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
file|<qwindowsystem_qws.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qdesktopwidget.h>
end_include
begin_include
include|#
directive|include
file|<qdirectpainter_qws.h>
end_include
begin_include
include|#
directive|include
file|<private/qwindowsurface_qws_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_class
DECL|class|tst_QDirectPainter
class|class
name|tst_QDirectPainter
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QDirectPainter
name|tst_QDirectPainter
parameter_list|()
block|{}
DECL|function|~tst_QDirectPainter
name|~
name|tst_QDirectPainter
parameter_list|()
block|{}
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|setGeometry_data
parameter_list|()
function_decl|;
name|void
name|setGeometry
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
name|void
name|regionSynchronization
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|reservedSynchronous
parameter_list|()
function_decl|;
private|private:
name|QWSWindow
modifier|*
name|getWindow
parameter_list|(
name|int
name|windId
parameter_list|)
function_decl|;
DECL|member|bgColor
name|QColor
name|bgColor
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|ColorPainter
class|class
name|ColorPainter
super|:
specifier|public
name|QDirectPainter
block|{
public|public:
DECL|function|ColorPainter
name|ColorPainter
parameter_list|(
name|SurfaceFlag
name|flag
init|=
name|NonReserved
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
init|=
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
parameter_list|)
member_init_list|:
name|QDirectPainter
argument_list|(
literal|0
argument_list|,
name|flag
argument_list|)
member_init_list|,
name|c
argument_list|(
name|color
argument_list|)
block|{}
DECL|function|color
name|QColor
name|color
parameter_list|()
block|{
return|return
name|c
return|;
block|}
protected|protected:
DECL|function|regionChanged
name|void
name|regionChanged
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|QScreen
operator|::
name|instance
argument_list|()
operator|->
name|solidFill
argument_list|(
name|c
argument_list|,
name|region
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|c
name|QColor
name|c
decl_stmt|;
DECL|member|r
name|QRegion
name|r
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QDirectPainter::SurfaceFlag
argument_list|)
end_macro
begin_function
DECL|function|initTestCase
name|void
name|tst_QDirectPainter
operator|::
name|initTestCase
parameter_list|()
block|{
name|bgColor
operator|=
name|QColor
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|QWSServer
modifier|*
name|server
init|=
name|QWSServer
operator|::
name|instance
argument_list|()
decl_stmt|;
name|server
operator|->
name|setBackground
argument_list|(
name|bgColor
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getWindow
name|QWSWindow
modifier|*
name|tst_QDirectPainter
operator|::
name|getWindow
parameter_list|(
name|int
name|winId
parameter_list|)
block|{
name|QWSServer
modifier|*
name|server
init|=
name|QWSServer
operator|::
name|instance
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QWSWindow
modifier|*
name|w
decl|,
name|server
operator|->
name|clientWindows
argument_list|()
control|)
block|{
if|if
condition|(
name|w
operator|->
name|winId
argument_list|()
operator|==
name|winId
condition|)
return|return
name|w
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
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
begin_define
DECL|macro|VERIFY_COLOR
define|#
directive|define
name|VERIFY_COLOR
parameter_list|(
name|rect
parameter_list|,
name|color
parameter_list|)
value|{                                     \     const QPixmap pixmap = QPixmap::grabWindow(QDesktopWidget().winId(), \                                                rect.left(), rect.top(), \                                                rect.width(), rect.height()); \     QCOMPARE(pixmap.size(), rect.size());                               \     QPixmap expectedPixmap(pixmap);
comment|/* ensure equal formats */
value|\     expectedPixmap.fill(color);                                         \     QCOMPARE(pixmap, expectedPixmap);                                   \ }
end_define
begin_function
DECL|function|setGeometry_data
name|void
name|tst_QDirectPainter
operator|::
name|setGeometry_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QDirectPainter
operator|::
name|SurfaceFlag
argument_list|>
argument_list|(
literal|"flag"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NonReserved"
argument_list|)
operator|<<
name|QDirectPainter
operator|::
name|NonReserved
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Reserved"
argument_list|)
operator|<<
name|QDirectPainter
operator|::
name|Reserved
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ReservedSynchronous"
argument_list|)
operator|<<
name|QDirectPainter
operator|::
name|ReservedSynchronous
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|tst_QDirectPainter
operator|::
name|setGeometry
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QDirectPainter
operator|::
name|SurfaceFlag
argument_list|,
name|flag
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|rect
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
block|{
name|ColorPainter
name|w
argument_list|(
name|flag
argument_list|)
decl_stmt|;
name|w
operator|.
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|geometry
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|VERIFY_COLOR
argument_list|(
name|rect
argument_list|,
name|w
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|VERIFY_COLOR
argument_list|(
name|rect
argument_list|,
name|bgColor
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_function
DECL|function|regionSynchronization
name|void
name|tst_QDirectPainter
operator|::
name|regionSynchronization
parameter_list|()
block|{
name|QRect
name|dpRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
decl_stmt|;
comment|// Start the direct painter in a different process
name|QProcess
name|proc
decl_stmt|;
name|QStringList
name|args
decl_stmt|;
name|args
operator|<<
name|QString
operator|::
name|number
argument_list|(
name|dpRect
operator|.
name|x
argument_list|()
argument_list|)
operator|<<
name|QString
operator|::
name|number
argument_list|(
name|dpRect
operator|.
name|y
argument_list|()
argument_list|)
operator|<<
name|QString
operator|::
name|number
argument_list|(
name|dpRect
operator|.
name|width
argument_list|()
argument_list|)
operator|<<
name|QString
operator|::
name|number
argument_list|(
name|dpRect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|proc
operator|.
name|start
argument_list|(
literal|"runDirectPainter/runDirectPainter"
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proc
operator|.
name|waitForStarted
argument_list|(
literal|5
operator|*
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|VERIFY_COLOR
argument_list|(
name|dpRect
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
comment|// blue hardcoded in runDirectPainter
name|QTime
name|t
decl_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
specifier|static
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|t
operator|.
name|elapsed
argument_list|()
operator|<
literal|10
operator|*
literal|1000
condition|)
block|{
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|ColorWidget
name|w
decl_stmt|;
name|w
operator|.
name|setGeometry
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|wRect
init|=
name|dpRect
operator|.
name|translated
argument_list|(
literal|10
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|w
operator|.
name|setGeometry
argument_list|(
name|wRect
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
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
comment|//glib event loop workaround
name|VERIFY_COLOR
argument_list|(
name|wRect
argument_list|,
name|w
operator|.
name|color
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|i
operator|>
literal|100
argument_list|)
expr_stmt|;
comment|// sanity check
name|proc
operator|.
name|kill
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|MyObject
class|class
name|MyObject
super|:
specifier|public
name|QObject
block|{
public|public:
DECL|function|MyObject
name|MyObject
parameter_list|(
name|QObject
modifier|*
name|p
init|=
literal|0
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|p
argument_list|)
member_init_list|,
name|lastEvent
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|event
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|lastEvent
operator|=
name|e
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|member|lastEvent
name|QEvent
modifier|*
name|lastEvent
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|reservedSynchronous
name|void
name|tst_QDirectPainter
operator|::
name|reservedSynchronous
parameter_list|()
block|{
name|MyObject
name|o
decl_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
operator|&
name|o
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|None
argument_list|)
argument_list|)
expr_stmt|;
name|QDirectPainter
name|p
argument_list|(
literal|0
argument_list|,
name|QDirectPainter
operator|::
name|ReservedSynchronous
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRegion
argument_list|(
name|QRect
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
comment|// The event loop should not have been executed
name|QVERIFY
argument_list|(
name|o
operator|.
name|lastEvent
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|allocatedRegion
argument_list|()
argument_list|,
name|QRegion
argument_list|(
name|QRect
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDirectPainter
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdirectpainter.moc"
end_include
end_unit
