begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlibinputpointer_p.h"
end_include
begin_include
include|#
directive|include
file|<libinput.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QLibInputPointer
name|QLibInputPointer
operator|::
name|QLibInputPointer
parameter_list|()
member_init_list|:
name|m_buttons
argument_list|(
name|Qt
operator|::
name|NoButton
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|processButton
name|void
name|QLibInputPointer
operator|::
name|processButton
parameter_list|(
name|libinput_event_pointer
modifier|*
name|e
parameter_list|)
block|{
specifier|const
name|uint32_t
name|b
init|=
name|libinput_event_pointer_get_button
argument_list|(
name|e
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|pressed
init|=
name|libinput_event_pointer_get_button_state
argument_list|(
name|e
argument_list|)
operator|==
name|LIBINPUT_BUTTON_STATE_PRESSED
decl_stmt|;
name|Qt
operator|::
name|MouseButton
name|button
init|=
name|Qt
operator|::
name|NoButton
decl_stmt|;
switch|switch
condition|(
name|b
condition|)
block|{
case|case
literal|0x110
case|:
name|button
operator|=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
break|break;
comment|// BTN_LEFT
case|case
literal|0x111
case|:
name|button
operator|=
name|Qt
operator|::
name|RightButton
expr_stmt|;
break|break;
case|case
literal|0x112
case|:
name|button
operator|=
name|Qt
operator|::
name|MiddleButton
expr_stmt|;
break|break;
case|case
literal|0x113
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton1
expr_stmt|;
break|break;
comment|// AKA Qt::BackButton
case|case
literal|0x114
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton2
expr_stmt|;
break|break;
comment|// AKA Qt::ForwardButton
case|case
literal|0x115
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton3
expr_stmt|;
break|break;
comment|// AKA Qt::TaskButton
case|case
literal|0x116
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton4
expr_stmt|;
break|break;
case|case
literal|0x117
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton5
expr_stmt|;
break|break;
case|case
literal|0x118
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton6
expr_stmt|;
break|break;
case|case
literal|0x119
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton7
expr_stmt|;
break|break;
case|case
literal|0x11a
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton8
expr_stmt|;
break|break;
case|case
literal|0x11b
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton9
expr_stmt|;
break|break;
case|case
literal|0x11c
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton10
expr_stmt|;
break|break;
case|case
literal|0x11d
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton11
expr_stmt|;
break|break;
case|case
literal|0x11e
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton12
expr_stmt|;
break|break;
case|case
literal|0x11f
case|:
name|button
operator|=
name|Qt
operator|::
name|ExtraButton13
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|pressed
condition|)
name|m_buttons
operator||=
name|button
expr_stmt|;
else|else
name|m_buttons
operator|&=
operator|~
name|button
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|Q_NULLPTR
argument_list|,
name|m_pos
argument_list|,
name|m_pos
argument_list|,
name|m_buttons
argument_list|,
name|QGuiApplication
operator|::
name|keyboardModifiers
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processMotion
name|void
name|QLibInputPointer
operator|::
name|processMotion
parameter_list|(
name|libinput_event_pointer
modifier|*
name|e
parameter_list|)
block|{
specifier|const
name|double
name|dx
init|=
name|libinput_event_pointer_get_dx
argument_list|(
name|e
argument_list|)
decl_stmt|;
specifier|const
name|double
name|dy
init|=
name|libinput_event_pointer_get_dy
argument_list|(
name|e
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|g
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|virtualGeometry
argument_list|()
decl_stmt|;
name|m_pos
operator|.
name|setX
argument_list|(
name|qBound
argument_list|(
name|g
operator|.
name|left
argument_list|()
argument_list|,
name|qRound
argument_list|(
name|m_pos
operator|.
name|x
argument_list|()
operator|+
name|dx
argument_list|)
argument_list|,
name|g
operator|.
name|right
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_pos
operator|.
name|setY
argument_list|(
name|qBound
argument_list|(
name|g
operator|.
name|top
argument_list|()
argument_list|,
name|qRound
argument_list|(
name|m_pos
operator|.
name|y
argument_list|()
operator|+
name|dy
argument_list|)
argument_list|,
name|g
operator|.
name|bottom
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|Q_NULLPTR
argument_list|,
name|m_pos
argument_list|,
name|m_pos
argument_list|,
name|m_buttons
argument_list|,
name|QGuiApplication
operator|::
name|keyboardModifiers
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processAxis
name|void
name|QLibInputPointer
operator|::
name|processAxis
parameter_list|(
name|libinput_event_pointer
modifier|*
name|e
parameter_list|)
block|{
specifier|const
name|double
name|v
init|=
name|libinput_event_pointer_get_axis_value
argument_list|(
name|e
argument_list|)
operator|*
literal|120
decl_stmt|;
specifier|const
name|Qt
operator|::
name|Orientation
name|ori
init|=
name|libinput_event_pointer_get_axis
argument_list|(
name|e
argument_list|)
operator|==
name|LIBINPUT_POINTER_AXIS_SCROLL_VERTICAL
condition|?
name|Qt
operator|::
name|Vertical
else|:
name|Qt
operator|::
name|Horizontal
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWheelEvent
argument_list|(
name|Q_NULLPTR
argument_list|,
name|m_pos
argument_list|,
name|m_pos
argument_list|,
name|qRound
argument_list|(
operator|-
name|v
argument_list|)
argument_list|,
name|ori
argument_list|,
name|QGuiApplication
operator|::
name|keyboardModifiers
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
