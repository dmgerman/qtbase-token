begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwidgetwindow_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWidgetWindow
name|QWidgetWindow
operator|::
name|QWidgetWindow
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|m_widget
argument_list|(
name|widget
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|event
name|bool
name|QWidgetWindow
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|Close
case|:
name|handleCloseEvent
argument_list|(
cast|static_cast
argument_list|<
name|QCloseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|KeyPress
case|:
case|case
name|QEvent
operator|::
name|KeyRelease
case|:
name|handleKeyEvent
argument_list|(
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|MouseMove
case|:
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
name|handleMouseEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|Move
case|:
name|handleMoveEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMoveEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|Resize
case|:
name|handleResizeEvent
argument_list|(
cast|static_cast
argument_list|<
name|QResizeEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
default|default:
break|break;
block|}
return|return
name|m_widget
operator|->
name|event
argument_list|(
name|event
argument_list|)
operator|||
name|QWindow
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|handleMouseEvent
name|void
name|QWidgetWindow
operator|::
name|handleMouseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
comment|// which child should have it?
name|QWidget
modifier|*
name|widget
init|=
name|m_widget
operator|->
name|childAt
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
comment|// TODO: make sure mouse release is delivered to same widget that got the press event
if|if
condition|(
operator|!
name|widget
condition|)
name|widget
operator|=
name|m_widget
expr_stmt|;
name|QPoint
name|mapped
init|=
name|widget
operator|->
name|mapFrom
argument_list|(
name|m_widget
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|QMouseEvent
name|translated
argument_list|(
name|event
operator|->
name|type
argument_list|()
argument_list|,
name|mapped
argument_list|,
name|event
operator|->
name|globalPos
argument_list|()
argument_list|,
name|event
operator|->
name|button
argument_list|()
argument_list|,
name|event
operator|->
name|buttons
argument_list|()
argument_list|,
name|event
operator|->
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|widget
argument_list|,
operator|&
name|translated
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleKeyEvent
name|void
name|QWidgetWindow
operator|::
name|handleKeyEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|QWidget
modifier|*
name|widget
init|=
name|m_widget
operator|->
name|focusWidget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
name|widget
operator|=
name|m_widget
expr_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|widget
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleMoveEvent
name|void
name|QWidgetWindow
operator|::
name|handleMoveEvent
parameter_list|(
name|QMoveEvent
modifier|*
name|event
parameter_list|)
block|{
name|m_widget
operator|->
name|data
operator|->
name|crect
operator|=
name|geometry
argument_list|()
expr_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|m_widget
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleResizeEvent
name|void
name|QWidgetWindow
operator|::
name|handleResizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|m_widget
operator|->
name|data
operator|->
name|crect
operator|=
name|geometry
argument_list|()
expr_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|m_widget
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleCloseEvent
name|void
name|QWidgetWindow
operator|::
name|handleCloseEvent
parameter_list|(
name|QCloseEvent
modifier|*
parameter_list|)
block|{
name|m_widget
operator|->
name|d_func
argument_list|()
operator|->
name|close_helper
argument_list|(
name|QWidgetPrivate
operator|::
name|CloseWithSpontaneousEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
