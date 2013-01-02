begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTEVENT_H
end_ifndef
begin_define
DECL|macro|QTESTEVENT_H
define|#
directive|define
name|QTESTEVENT_H
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// inform syncqt
end_comment
begin_pragma
pragma|#
directive|pragma
name|qt_no_master_include
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_GUI_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtTest/qtestkeyboard.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestmouse.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/qtestsystem.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QTestEvent
block|{
name|public
label|:
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
name|virtual
name|void
name|simulate
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
init|=
literal|0
function_decl|;
endif|#
directive|endif
name|virtual
name|QTestEvent
operator|*
name|clone
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
operator|~
name|QTestEvent
argument_list|()
block|{}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_GUI_LIB
end_ifdef
begin_decl_stmt
name|class
name|QTestKeyEvent
range|:
name|public
name|QTestEvent
block|{
name|public
operator|:
specifier|inline
name|QTestKeyEvent
argument_list|(
argument|QTest::KeyAction action
argument_list|,
argument|Qt::Key key
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|int delay
argument_list|)
operator|:
name|_action
argument_list|(
name|action
argument_list|)
block|,
name|_delay
argument_list|(
name|delay
argument_list|)
block|,
name|_modifiers
argument_list|(
name|modifiers
argument_list|)
block|,
name|_ascii
argument_list|(
literal|0
argument_list|)
block|,
name|_key
argument_list|(
argument|key
argument_list|)
block|{}
specifier|inline
name|QTestKeyEvent
argument_list|(
argument|QTest::KeyAction action
argument_list|,
argument|char ascii
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|int delay
argument_list|)
operator|:
name|_action
argument_list|(
name|action
argument_list|)
block|,
name|_delay
argument_list|(
name|delay
argument_list|)
block|,
name|_modifiers
argument_list|(
name|modifiers
argument_list|)
block|,
name|_ascii
argument_list|(
name|ascii
argument_list|)
block|,
name|_key
argument_list|(
argument|Qt::Key_unknown
argument_list|)
block|{}
specifier|inline
name|QTestEvent
operator|*
name|clone
argument_list|()
specifier|const
block|{
return|return
name|new
name|QTestKeyEvent
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
specifier|inline
name|void
name|simulate
argument_list|(
argument|QWidget *w
argument_list|)
block|{
if|if
condition|(
name|_ascii
operator|==
literal|0
condition|)
name|QTest
operator|::
name|keyEvent
argument_list|(
name|_action
argument_list|,
name|w
argument_list|,
name|_key
argument_list|,
name|_modifiers
argument_list|,
name|_delay
argument_list|)
expr_stmt|;
else|else
name|QTest
operator|::
name|keyEvent
argument_list|(
name|_action
argument_list|,
name|w
argument_list|,
name|_ascii
argument_list|,
name|_modifiers
argument_list|,
name|_delay
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|protected
operator|:
name|QTest
operator|::
name|KeyAction
name|_action
block|;
name|int
name|_delay
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|_modifiers
block|;
name|char
name|_ascii
block|;
name|Qt
operator|::
name|Key
name|_key
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTestKeyClicksEvent
range|:
name|public
name|QTestEvent
block|{
name|public
operator|:
specifier|inline
name|QTestKeyClicksEvent
argument_list|(
argument|const QString&keys
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|int delay
argument_list|)
operator|:
name|_keys
argument_list|(
name|keys
argument_list|)
block|,
name|_modifiers
argument_list|(
name|modifiers
argument_list|)
block|,
name|_delay
argument_list|(
argument|delay
argument_list|)
block|{}
specifier|inline
name|QTestEvent
operator|*
name|clone
argument_list|()
specifier|const
block|{
return|return
name|new
name|QTestKeyClicksEvent
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
specifier|inline
name|void
name|simulate
argument_list|(
argument|QWidget *w
argument_list|)
block|{
name|QTest
operator|::
name|keyClicks
argument_list|(
name|w
argument_list|,
name|_keys
argument_list|,
name|_modifiers
argument_list|,
name|_delay
argument_list|)
block|;     }
endif|#
directive|endif
name|private
operator|:
name|QString
name|_keys
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|_modifiers
block|;
name|int
name|_delay
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTestMouseEvent
range|:
name|public
name|QTestEvent
block|{
name|public
operator|:
specifier|inline
name|QTestMouseEvent
argument_list|(
argument|QTest::MouseAction action
argument_list|,
argument|Qt::MouseButton button
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|QPoint position
argument_list|,
argument|int delay
argument_list|)
operator|:
name|_action
argument_list|(
name|action
argument_list|)
block|,
name|_button
argument_list|(
name|button
argument_list|)
block|,
name|_modifiers
argument_list|(
name|modifiers
argument_list|)
block|,
name|_pos
argument_list|(
name|position
argument_list|)
block|,
name|_delay
argument_list|(
argument|delay
argument_list|)
block|{}
specifier|inline
name|QTestEvent
operator|*
name|clone
argument_list|()
specifier|const
block|{
return|return
name|new
name|QTestMouseEvent
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
specifier|inline
name|void
name|simulate
argument_list|(
argument|QWidget *w
argument_list|)
block|{
name|QTest
operator|::
name|mouseEvent
argument_list|(
name|_action
argument_list|,
name|w
argument_list|,
name|_button
argument_list|,
name|_modifiers
argument_list|,
name|_pos
argument_list|,
name|_delay
argument_list|)
block|;     }
endif|#
directive|endif
name|private
operator|:
name|QTest
operator|::
name|MouseAction
name|_action
block|;
name|Qt
operator|::
name|MouseButton
name|_button
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|_modifiers
block|;
name|QPoint
name|_pos
block|;
name|int
name|_delay
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_GUI_LIB
end_comment
begin_decl_stmt
name|class
name|QTestDelayEvent
range|:
name|public
name|QTestEvent
block|{
name|public
operator|:
specifier|inline
name|QTestDelayEvent
argument_list|(
argument|int msecs
argument_list|)
operator|:
name|_delay
argument_list|(
argument|msecs
argument_list|)
block|{}
specifier|inline
name|QTestEvent
operator|*
name|clone
argument_list|()
specifier|const
block|{
return|return
name|new
name|QTestDelayEvent
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
specifier|inline
name|void
name|simulate
argument_list|(
argument|QWidget *
comment|/*w*/
argument_list|)
block|{
name|QTest
operator|::
name|qWait
argument_list|(
name|_delay
argument_list|)
block|; }
endif|#
directive|endif
name|private
operator|:
name|int
name|_delay
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTestEventList
range|:
name|public
name|QList
operator|<
name|QTestEvent
operator|*
operator|>
block|{
name|public
operator|:
specifier|inline
name|QTestEventList
argument_list|()
block|{}
specifier|inline
name|QTestEventList
argument_list|(
specifier|const
name|QTestEventList
operator|&
name|other
argument_list|)
operator|:
name|QList
operator|<
name|QTestEvent
operator|*
operator|>
operator|(
operator|)
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
name|other
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|append
argument_list|(
name|other
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|clone
argument_list|()
argument_list|)
expr_stmt|;
block|}
specifier|inline
operator|~
name|QTestEventList
argument_list|()
block|{
name|clear
argument_list|()
block|; }
specifier|inline
name|void
name|clear
argument_list|()
block|{
name|qDeleteAll
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|QList
operator|<
name|QTestEvent
operator|*
operator|>
operator|::
name|clear
argument_list|()
block|; }
ifdef|#
directive|ifdef
name|QT_GUI_LIB
specifier|inline
name|void
name|addKeyClick
argument_list|(
argument|Qt::Key qtKey
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|addKeyEvent
argument_list|(
name|QTest
operator|::
name|Click
argument_list|,
name|qtKey
argument_list|,
name|modifiers
argument_list|,
name|msecs
argument_list|)
block|; }
specifier|inline
name|void
name|addKeyPress
argument_list|(
argument|Qt::Key qtKey
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|addKeyEvent
argument_list|(
name|QTest
operator|::
name|Press
argument_list|,
name|qtKey
argument_list|,
name|modifiers
argument_list|,
name|msecs
argument_list|)
block|; }
specifier|inline
name|void
name|addKeyRelease
argument_list|(
argument|Qt::Key qtKey
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|addKeyEvent
argument_list|(
name|QTest
operator|::
name|Release
argument_list|,
name|qtKey
argument_list|,
name|modifiers
argument_list|,
name|msecs
argument_list|)
block|; }
specifier|inline
name|void
name|addKeyEvent
argument_list|(
argument|QTest::KeyAction action
argument_list|,
argument|Qt::Key qtKey
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestKeyEvent(action, qtKey, modifiers, msecs)
argument_list|)
block|; }
specifier|inline
name|void
name|addKeyClick
argument_list|(
argument|char ascii
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|addKeyEvent
argument_list|(
name|QTest
operator|::
name|Click
argument_list|,
name|ascii
argument_list|,
name|modifiers
argument_list|,
name|msecs
argument_list|)
block|; }
specifier|inline
name|void
name|addKeyPress
argument_list|(
argument|char ascii
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|addKeyEvent
argument_list|(
name|QTest
operator|::
name|Press
argument_list|,
name|ascii
argument_list|,
name|modifiers
argument_list|,
name|msecs
argument_list|)
block|; }
specifier|inline
name|void
name|addKeyRelease
argument_list|(
argument|char ascii
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|addKeyEvent
argument_list|(
name|QTest
operator|::
name|Release
argument_list|,
name|ascii
argument_list|,
name|modifiers
argument_list|,
name|msecs
argument_list|)
block|; }
specifier|inline
name|void
name|addKeyClicks
argument_list|(
argument|const QString&keys
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestKeyClicksEvent(keys, modifiers, msecs)
argument_list|)
block|; }
specifier|inline
name|void
name|addKeyEvent
argument_list|(
argument|QTest::KeyAction action
argument_list|,
argument|char ascii
argument_list|,
argument|Qt::KeyboardModifiers modifiers = Qt::NoModifier
argument_list|,
argument|int msecs = -
literal|1
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestKeyEvent(action, ascii, modifiers, msecs)
argument_list|)
block|; }
specifier|inline
name|void
name|addMousePress
argument_list|(
argument|Qt::MouseButton button
argument_list|,
argument|Qt::KeyboardModifiers stateKey =
literal|0
argument_list|,
argument|QPoint pos = QPoint()
argument_list|,
argument|int delay=-
literal|1
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestMouseEvent(QTest::MousePress, button, stateKey, pos, delay)
argument_list|)
block|; }
specifier|inline
name|void
name|addMouseRelease
argument_list|(
argument|Qt::MouseButton button
argument_list|,
argument|Qt::KeyboardModifiers stateKey =
literal|0
argument_list|,
argument|QPoint pos = QPoint()
argument_list|,
argument|int delay=-
literal|1
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestMouseEvent(QTest::MouseRelease, button, stateKey, pos, delay)
argument_list|)
block|; }
specifier|inline
name|void
name|addMouseClick
argument_list|(
argument|Qt::MouseButton button
argument_list|,
argument|Qt::KeyboardModifiers stateKey =
literal|0
argument_list|,
argument|QPoint pos = QPoint()
argument_list|,
argument|int delay=-
literal|1
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestMouseEvent(QTest::MouseClick, button, stateKey, pos, delay)
argument_list|)
block|; }
specifier|inline
name|void
name|addMouseDClick
argument_list|(
argument|Qt::MouseButton button
argument_list|,
argument|Qt::KeyboardModifiers stateKey =
literal|0
argument_list|,
argument|QPoint pos = QPoint()
argument_list|,
argument|int delay=-
literal|1
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestMouseEvent(QTest::MouseDClick, button, stateKey, pos, delay)
argument_list|)
block|; }
specifier|inline
name|void
name|addMouseMove
argument_list|(
argument|QPoint pos = QPoint()
argument_list|,
argument|int delay=-
literal|1
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestMouseEvent(QTest::MouseMove, Qt::NoButton,
literal|0
argument|, pos, delay)
argument_list|)
block|; }
endif|#
directive|endif
comment|//QT_GUI_LIB
specifier|inline
name|void
name|addDelay
argument_list|(
argument|int msecs
argument_list|)
block|{
name|append
argument_list|(
argument|new QTestDelayEvent(msecs)
argument_list|)
block|; }
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
specifier|inline
name|void
name|simulate
argument_list|(
argument|QWidget *w
argument_list|)
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
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|simulate
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
expr|}
block|;
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
argument|QTestEventList
argument_list|)
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
