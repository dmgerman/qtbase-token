begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qabstractanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qanimationgroup.h>
end_include
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_class
DECL|class|tst_QAbstractAnimation
class|class
name|tst_QAbstractAnimation
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|construction
parameter_list|()
function_decl|;
name|void
name|destruction
parameter_list|()
function_decl|;
name|void
name|currentLoop
parameter_list|()
function_decl|;
name|void
name|currentLoopTime
parameter_list|()
function_decl|;
name|void
name|currentTime
parameter_list|()
function_decl|;
name|void
name|direction
parameter_list|()
function_decl|;
name|void
name|group
parameter_list|()
function_decl|;
name|void
name|loopCount
parameter_list|()
function_decl|;
name|void
name|state
parameter_list|()
function_decl|;
name|void
name|totalDuration
parameter_list|()
function_decl|;
name|void
name|avoidJumpAtStart
parameter_list|()
function_decl|;
name|void
name|avoidJumpAtStartWithStop
parameter_list|()
function_decl|;
name|void
name|avoidJumpAtStartWithRunning
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|TestableQAbstractAnimation
class|class
name|TestableQAbstractAnimation
super|:
specifier|public
name|QAbstractAnimation
block|{
name|Q_OBJECT
public|public:
DECL|function|TestableQAbstractAnimation
name|TestableQAbstractAnimation
parameter_list|()
member_init_list|:
name|m_duration
argument_list|(
literal|10
argument_list|)
block|{}
DECL|function|~TestableQAbstractAnimation
specifier|virtual
name|~
name|TestableQAbstractAnimation
parameter_list|()
block|{}
empty_stmt|;
DECL|function|duration
name|int
name|duration
parameter_list|()
specifier|const
block|{
return|return
name|m_duration
return|;
block|}
DECL|function|updateCurrentTime
specifier|virtual
name|void
name|updateCurrentTime
parameter_list|(
name|int
parameter_list|)
block|{}
DECL|function|setDuration
name|void
name|setDuration
parameter_list|(
name|int
name|duration
parameter_list|)
block|{
name|m_duration
operator|=
name|duration
expr_stmt|;
block|}
private|private:
DECL|member|m_duration
name|int
name|m_duration
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|DummyQAnimationGroup
class|class
name|DummyQAnimationGroup
super|:
specifier|public
name|QAnimationGroup
block|{
name|Q_OBJECT
public|public:
DECL|function|duration
name|int
name|duration
parameter_list|()
specifier|const
block|{
return|return
literal|10
return|;
block|}
DECL|function|updateCurrentTime
specifier|virtual
name|void
name|updateCurrentTime
parameter_list|(
name|int
parameter_list|)
block|{}
block|}
class|;
end_class
begin_function
DECL|function|construction
name|void
name|tst_QAbstractAnimation
operator|::
name|construction
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
block|}
end_function
begin_function
DECL|function|destruction
name|void
name|tst_QAbstractAnimation
operator|::
name|destruction
parameter_list|()
block|{
name|TestableQAbstractAnimation
modifier|*
name|anim
init|=
operator|new
name|TestableQAbstractAnimation
decl_stmt|;
operator|delete
name|anim
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentLoop
name|void
name|tst_QAbstractAnimation
operator|::
name|currentLoop
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|currentLoop
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentLoopTime
name|void
name|tst_QAbstractAnimation
operator|::
name|currentLoopTime
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|currentLoopTime
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentTime
name|void
name|tst_QAbstractAnimation
operator|::
name|currentTime
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|currentTime
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setCurrentTime
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|currentTime
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|direction
name|void
name|tst_QAbstractAnimation
operator|::
name|direction
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|direction
argument_list|()
argument_list|,
name|QAbstractAnimation
operator|::
name|Forward
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setDirection
argument_list|(
name|QAbstractAnimation
operator|::
name|Backward
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|direction
argument_list|()
argument_list|,
name|QAbstractAnimation
operator|::
name|Backward
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setDirection
argument_list|(
name|QAbstractAnimation
operator|::
name|Forward
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|direction
argument_list|()
argument_list|,
name|QAbstractAnimation
operator|::
name|Forward
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|group
name|void
name|tst_QAbstractAnimation
operator|::
name|group
parameter_list|()
block|{
name|TestableQAbstractAnimation
modifier|*
name|anim
init|=
operator|new
name|TestableQAbstractAnimation
decl_stmt|;
name|DummyQAnimationGroup
name|group
decl_stmt|;
name|group
operator|.
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|->
name|group
argument_list|()
argument_list|,
operator|&
name|group
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loopCount
name|void
name|tst_QAbstractAnimation
operator|::
name|loopCount
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|loopCount
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setLoopCount
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|loopCount
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|state
name|void
name|tst_QAbstractAnimation
operator|::
name|state
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|state
argument_list|()
argument_list|,
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|totalDuration
name|void
name|tst_QAbstractAnimation
operator|::
name|totalDuration
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|duration
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setLoopCount
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|totalDuration
argument_list|()
argument_list|,
literal|50
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|avoidJumpAtStart
name|void
name|tst_QAbstractAnimation
operator|::
name|avoidJumpAtStart
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|anim
operator|.
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/*         the timer shouldn't actually start until we hit the event loop,         so the sleep should have no effect     */
name|anim
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|anim
operator|.
name|currentTime
argument_list|()
operator|<
literal|50
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|avoidJumpAtStartWithStop
name|void
name|tst_QAbstractAnimation
operator|::
name|avoidJumpAtStartWithStop
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|anim
operator|.
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|TestableQAbstractAnimation
name|anim2
decl_stmt|;
name|anim2
operator|.
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|TestableQAbstractAnimation
name|anim3
decl_stmt|;
name|anim3
operator|.
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|anim
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|anim
operator|.
name|stop
argument_list|()
expr_stmt|;
comment|/*         same test as avoidJumpAtStart, but after there is a         running animation that is stopped     */
name|anim2
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|anim3
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|anim2
operator|.
name|currentTime
argument_list|()
operator|<
literal|50
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|anim3
operator|.
name|currentTime
argument_list|()
operator|<
literal|50
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|avoidJumpAtStartWithRunning
name|void
name|tst_QAbstractAnimation
operator|::
name|avoidJumpAtStartWithRunning
parameter_list|()
block|{
name|TestableQAbstractAnimation
name|anim
decl_stmt|;
name|anim
operator|.
name|setDuration
argument_list|(
literal|2000
argument_list|)
expr_stmt|;
name|TestableQAbstractAnimation
name|anim2
decl_stmt|;
name|anim2
operator|.
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|TestableQAbstractAnimation
name|anim3
decl_stmt|;
name|anim3
operator|.
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|anim
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|300
argument_list|)
expr_stmt|;
comment|//make sure timer has started
comment|/*         same test as avoidJumpAtStart, but with an         existing running animation     */
name|anim2
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|300
argument_list|)
expr_stmt|;
comment|//force large delta for next tick
name|anim3
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|anim2
operator|.
name|currentTime
argument_list|()
operator|<
literal|50
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|anim3
operator|.
name|currentTime
argument_list|()
operator|<
literal|50
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAbstractAnimation
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qabstractanimation.moc"
end_include
end_unit
