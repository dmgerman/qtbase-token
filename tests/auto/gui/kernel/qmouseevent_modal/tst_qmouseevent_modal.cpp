begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qfontinfo.h>
end_include
begin_include
include|#
directive|include
file|<qpushbutton.h>
end_include
begin_include
include|#
directive|include
file|<qscrollbar.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qdialog.h>
end_include
begin_class_decl
class_decl|class
name|TstWidget
class_decl|;
end_class_decl
begin_class_decl
class_decl|class
name|TstDialog
class_decl|;
end_class_decl
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QPushButton
argument_list|)
end_macro
begin_class
DECL|class|tst_qmouseevent_modal
class|class
name|tst_qmouseevent_modal
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_qmouseevent_modal
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_qmouseevent_modal
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|mousePressRelease
parameter_list|()
function_decl|;
private|private:
DECL|member|w
name|TstWidget
modifier|*
name|w
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|TstWidget
class|class
name|TstWidget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
name|TstWidget
parameter_list|()
constructor_decl|;
public|public
name|slots
public|:
name|void
name|buttonPressed
parameter_list|()
function_decl|;
public|public:
DECL|member|pb
name|QPushButton
modifier|*
name|pb
decl_stmt|;
DECL|member|d
name|TstDialog
modifier|*
name|d
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|TstDialog
class|class
name|TstDialog
super|:
specifier|public
name|QDialog
block|{
name|Q_OBJECT
public|public:
name|TstDialog
parameter_list|(
name|QWidget
modifier|*
name|mouseWidget
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
constructor_decl|;
DECL|function|count
name|int
name|count
parameter_list|()
block|{
return|return
name|c
return|;
block|}
protected|protected:
name|void
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
parameter_list|)
function_decl|;
public|public
name|slots
public|:
name|void
name|releaseMouse
parameter_list|()
function_decl|;
name|void
name|closeDialog
parameter_list|()
function_decl|;
private|private:
DECL|member|m
name|QWidget
modifier|*
name|m
decl_stmt|;
DECL|member|c
name|int
name|c
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_qmouseevent_modal
name|tst_qmouseevent_modal
operator|::
name|tst_qmouseevent_modal
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_qmouseevent_modal
name|tst_qmouseevent_modal
operator|::
name|~
name|tst_qmouseevent_modal
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_qmouseevent_modal
operator|::
name|initTestCase
parameter_list|()
block|{
name|w
operator|=
operator|new
name|TstWidget
expr_stmt|;
name|w
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_qmouseevent_modal
operator|::
name|cleanupTestCase
parameter_list|()
block|{
operator|delete
name|w
expr_stmt|;
name|w
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_qmouseevent_modal
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_qmouseevent_modal
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*   Test for task 22500 */
end_comment
begin_function
DECL|function|mousePressRelease
name|void
name|tst_qmouseevent_modal
operator|::
name|mousePressRelease
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
name|w
operator|->
name|d
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|d
operator|->
name|count
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mousePress
argument_list|(
name|w
operator|->
name|pb
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
operator|!
name|w
operator|->
name|d
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|d
operator|->
name|count
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|w
operator|->
name|pb
operator|->
name|isDown
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mousePress
argument_list|(
name|w
operator|->
name|pb
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
operator|!
name|w
operator|->
name|d
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|d
operator|->
name|count
argument_list|()
operator|==
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|w
operator|->
name|pb
operator|->
name|isDown
argument_list|()
argument_list|)
expr_stmt|;
comment|// With the current QWS mouse handling, the 3rd press would fail...
name|QTest
operator|::
name|mousePress
argument_list|(
name|w
operator|->
name|pb
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
operator|!
name|w
operator|->
name|d
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|d
operator|->
name|count
argument_list|()
operator|==
literal|3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|w
operator|->
name|pb
operator|->
name|isDown
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mousePress
argument_list|(
name|w
operator|->
name|pb
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
operator|!
name|w
operator|->
name|d
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|d
operator|->
name|count
argument_list|()
operator|==
literal|4
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|w
operator|->
name|pb
operator|->
name|isDown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|TstWidget
name|TstWidget
operator|::
name|TstWidget
parameter_list|()
block|{
name|pb
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"Press me"
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|pb
operator|->
name|setObjectName
argument_list|(
literal|"testbutton"
argument_list|)
expr_stmt|;
name|QSize
name|s
init|=
name|pb
operator|->
name|sizeHint
argument_list|()
decl_stmt|;
name|pb
operator|->
name|setGeometry
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
name|s
operator|.
name|width
argument_list|()
argument_list|,
name|s
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pb
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|buttonPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//    QScrollBar *sb = new QScrollBar( Qt::Horizontal,  this );
comment|//    sb->setGeometry( 5, pb->geometry().bottom() + 5, 100, sb->sizeHint().height() );
name|d
operator|=
operator|new
name|TstDialog
argument_list|(
name|pb
argument_list|,
name|this
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|buttonPressed
name|void
name|TstWidget
operator|::
name|buttonPressed
parameter_list|()
block|{
name|d
operator|->
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|TstDialog
name|TstDialog
operator|::
name|TstDialog
parameter_list|(
name|QWidget
modifier|*
name|mouseWidget
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|setObjectName
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|setModal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m
operator|=
name|mouseWidget
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|showEvent
name|void
name|TstDialog
operator|::
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
parameter_list|)
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|1
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|releaseMouse
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|100
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|closeDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|releaseMouse
name|void
name|TstDialog
operator|::
name|releaseMouse
parameter_list|()
block|{
name|QTest
operator|::
name|mouseRelease
argument_list|(
name|m
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|closeDialog
name|void
name|TstDialog
operator|::
name|closeDialog
parameter_list|()
block|{
if|if
condition|(
name|isVisible
argument_list|()
condition|)
block|{
name|c
operator|++
expr_stmt|;
name|accept
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qmouseevent_modal
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmouseevent_modal.moc"
end_include
end_unit
