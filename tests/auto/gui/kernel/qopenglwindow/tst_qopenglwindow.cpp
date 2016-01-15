begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QOpenGLWindow>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_class
DECL|class|tst_QOpenGLWindow
class|class
name|tst_QOpenGLWindow
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|create
parameter_list|()
function_decl|;
name|void
name|basic
parameter_list|()
function_decl|;
name|void
name|painter
parameter_list|()
function_decl|;
name|void
name|partial_data
parameter_list|()
function_decl|;
name|void
name|partial
parameter_list|()
function_decl|;
name|void
name|underOver
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|create
name|void
name|tst_QOpenGLWindow
operator|::
name|create
parameter_list|()
block|{
name|QOpenGLWindow
name|w
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|w
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|QOpenGLWindow
block|{
public|public:
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|initCount
operator|=
name|resizeCount
operator|=
name|paintCount
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|initializeGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
operator|++
name|initCount
expr_stmt|;
block|}
name|void
name|resizeGL
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
operator|++
name|resizeCount
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
argument_list|,
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|h
argument_list|,
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|paintGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
operator|++
name|paintCount
expr_stmt|;
name|QOpenGLContext
modifier|*
name|ctx
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ctx
argument_list|,
name|context
argument_list|()
argument_list|)
expr_stmt|;
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|ctx
operator|->
name|functions
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|f
operator|->
name|glClearColor
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|f
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
name|img
operator|=
name|grabFramebuffer
argument_list|()
expr_stmt|;
block|}
DECL|member|initCount
name|int
name|initCount
decl_stmt|;
DECL|member|resizeCount
name|int
name|resizeCount
decl_stmt|;
DECL|member|paintCount
name|int
name|paintCount
decl_stmt|;
DECL|member|img
name|QImage
name|img
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|basic
name|void
name|tst_QOpenGLWindow
operator|::
name|basic
parameter_list|()
block|{
name|Window
name|w
decl_stmt|;
name|w
operator|.
name|reset
argument_list|()
expr_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
comment|// Check that the virtuals are invoked.
name|QCOMPARE
argument_list|(
name|w
operator|.
name|initCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|int
name|resCount
init|=
name|w
operator|.
name|resizeCount
decl_stmt|;
name|QVERIFY
argument_list|(
name|resCount
operator|>=
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|paintCount
operator|>=
literal|1
argument_list|)
expr_stmt|;
comment|// Check that something has been drawn;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|img
operator|.
name|size
argument_list|()
argument_list|,
name|w
operator|.
name|size
argument_list|()
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|img
operator|.
name|pixel
argument_list|(
name|QPoint
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// Check that the viewport was properly set.
name|w
operator|.
name|makeCurrent
argument_list|()
expr_stmt|;
name|GLint
name|v
index|[
literal|4
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|w
operator|.
name|context
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glGetIntegerv
argument_list|(
name|GL_VIEWPORT
argument_list|,
name|v
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
index|[
literal|0
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
index|[
literal|2
index|]
argument_list|,
name|GLint
argument_list|(
name|w
operator|.
name|width
argument_list|()
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
index|[
literal|3
index|]
argument_list|,
name|GLint
argument_list|(
name|w
operator|.
name|height
argument_list|()
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|w
operator|.
name|doneCurrent
argument_list|()
expr_stmt|;
comment|// Check that a future resize triggers resizeGL.
name|w
operator|.
name|resize
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|int
name|maxWait
init|=
literal|1000
decl_stmt|;
while|while
condition|(
name|w
operator|.
name|resizeCount
operator|==
name|resCount
operator|&&
name|maxWait
operator|--
operator|>=
literal|0
condition|)
name|QTest
operator|::
name|qWait
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|resizeCount
operator|>
name|resCount
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|PainterWindow
class|class
name|PainterWindow
super|:
specifier|public
name|QOpenGLWindow
block|{
public|public:
name|void
name|paintGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
name|QOpenGLContext
modifier|*
name|ctx
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|ctx
argument_list|,
name|context
argument_list|()
argument_list|)
expr_stmt|;
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|ctx
operator|->
name|functions
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|beginNativePainting
argument_list|()
expr_stmt|;
name|f
operator|->
name|glClearColor
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|f
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
name|p
operator|.
name|endNativePainting
argument_list|()
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|img
operator|=
name|grabFramebuffer
argument_list|()
expr_stmt|;
block|}
DECL|member|img
name|QImage
name|img
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|painter
name|void
name|tst_QOpenGLWindow
operator|::
name|painter
parameter_list|()
block|{
name|PainterWindow
name|w
decl_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|img
operator|.
name|size
argument_list|()
argument_list|,
name|w
operator|.
name|size
argument_list|()
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|img
operator|.
name|pixel
argument_list|(
name|QPoint
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|img
operator|.
name|pixel
argument_list|(
name|QPoint
argument_list|(
literal|200
argument_list|,
literal|5
argument_list|)
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|PartialPainterWindow
class|class
name|PartialPainterWindow
super|:
specifier|public
name|QOpenGLWindow
block|{
public|public:
DECL|function|PartialPainterWindow
name|PartialPainterWindow
parameter_list|(
name|QOpenGLWindow
operator|::
name|UpdateBehavior
name|u
parameter_list|)
member_init_list|:
name|QOpenGLWindow
argument_list|(
name|u
argument_list|)
member_init_list|,
name|x
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|paintGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
operator|++
name|paintCount
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|x
condition|)
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|x
operator|+=
literal|20
expr_stmt|;
block|}
DECL|member|paintCount
name|int
name|paintCount
decl_stmt|;
DECL|member|x
name|int
name|x
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|partial_data
name|void
name|tst_QOpenGLWindow
operator|::
name|partial_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"behavior"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"blit"
argument_list|)
operator|<<
name|int
argument_list|(
name|QOpenGLWindow
operator|::
name|PartialUpdateBlit
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"blend"
argument_list|)
operator|<<
name|int
argument_list|(
name|QOpenGLWindow
operator|::
name|PartialUpdateBlend
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|partial
name|void
name|tst_QOpenGLWindow
operator|::
name|partial
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|behavior
argument_list|)
expr_stmt|;
name|QOpenGLWindow
operator|::
name|UpdateBehavior
name|u
init|=
name|QOpenGLWindow
operator|::
name|UpdateBehavior
argument_list|(
name|behavior
argument_list|)
decl_stmt|;
name|PartialPainterWindow
name|w
argument_list|(
name|u
argument_list|)
decl_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|800
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
comment|// Add a couple of small blue rects.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|w
operator|.
name|paintCount
operator|=
literal|0
expr_stmt|;
name|w
operator|.
name|update
argument_list|()
expr_stmt|;
name|int
name|maxWait
init|=
literal|1000
decl_stmt|;
while|while
condition|(
name|w
operator|.
name|paintCount
operator|==
literal|0
operator|&&
name|maxWait
operator|--
operator|>=
literal|0
condition|)
name|QTest
operator|::
name|qWait
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
comment|// Now since the painting went to an extra framebuffer, all the rects should
comment|// be present since everything is preserved between the frames.
name|QImage
name|img
init|=
name|w
operator|.
name|grabFramebuffer
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|img
operator|.
name|size
argument_list|()
argument_list|,
name|w
operator|.
name|size
argument_list|()
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
name|QPoint
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
argument_list|,
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
name|QPoint
argument_list|(
literal|15
argument_list|,
literal|5
argument_list|)
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
argument_list|,
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
name|QPoint
argument_list|(
literal|25
argument_list|,
literal|5
argument_list|)
operator|*
name|w
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
argument_list|,
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|PaintUnderOverWindow
class|class
name|PaintUnderOverWindow
super|:
specifier|public
name|QOpenGLWindow
block|{
public|public:
DECL|function|PaintUnderOverWindow
name|PaintUnderOverWindow
parameter_list|()
member_init_list|:
name|QOpenGLWindow
argument_list|(
name|PartialUpdateBlend
argument_list|)
member_init_list|,
name|m_state
argument_list|(
name|None
argument_list|)
block|{ }
DECL|enum|State
enum|enum
name|State
block|{
DECL|enumerator|None
name|None
block|,
DECL|enumerator|PaintUnder
name|PaintUnder
block|,
DECL|enumerator|Paint
name|Paint
block|,
DECL|enumerator|PaintOver
name|PaintOver
block|,
DECL|enumerator|Error
name|Error
block|}
DECL|member|m_state
name|m_state
enum|;
name|void
name|paintUnderGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
if|if
condition|(
name|m_state
operator|==
name|None
operator|||
name|m_state
operator|==
name|PaintOver
condition|)
name|m_state
operator|=
name|PaintUnder
expr_stmt|;
else|else
name|m_state
operator|=
name|Error
expr_stmt|;
name|GLuint
name|fbo
init|=
literal|0xFFFF
decl_stmt|;
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glGetIntegerv
argument_list|(
name|GL_FRAMEBUFFER_BINDING
argument_list|,
operator|(
name|GLint
operator|*
operator|)
operator|&
name|fbo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fbo
argument_list|,
name|GLuint
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|paintGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
if|if
condition|(
name|m_state
operator|==
name|PaintUnder
condition|)
name|m_state
operator|=
name|Paint
expr_stmt|;
else|else
name|m_state
operator|=
name|Error
expr_stmt|;
comment|// Using PartialUpdateBlend so paintGL() targets a user fbo, not the default.
name|GLuint
name|fbo
init|=
literal|0xFFFF
decl_stmt|;
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glGetIntegerv
argument_list|(
name|GL_FRAMEBUFFER_BINDING
argument_list|,
operator|(
name|GLint
operator|*
operator|)
operator|&
name|fbo
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fbo
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fbo
argument_list|,
name|defaultFramebufferObject
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|paintOverGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
if|if
condition|(
name|m_state
operator|==
name|Paint
condition|)
name|m_state
operator|=
name|PaintOver
expr_stmt|;
else|else
name|m_state
operator|=
name|Error
expr_stmt|;
name|GLuint
name|fbo
init|=
literal|0xFFFF
decl_stmt|;
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glGetIntegerv
argument_list|(
name|GL_FRAMEBUFFER_BINDING
argument_list|,
operator|(
name|GLint
operator|*
operator|)
operator|&
name|fbo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fbo
argument_list|,
name|GLuint
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|underOver
name|void
name|tst_QOpenGLWindow
operator|::
name|underOver
parameter_list|()
block|{
name|PaintUnderOverWindow
name|w
decl_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
comment|// under -> paint -> over -> under -> paint -> ... is the only acceptable sequence
name|QCOMPARE
argument_list|(
name|w
operator|.
name|m_state
argument_list|,
name|PaintUnderOverWindow
operator|::
name|PaintOver
argument_list|)
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|<tst_qopenglwindow.moc>
end_include
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QOpenGLWindow
argument_list|)
end_macro
end_unit
