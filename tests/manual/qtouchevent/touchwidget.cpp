begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"touchwidget.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QtEvents>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QTouchEvent>
end_include
begin_function
DECL|function|reset
name|void
name|TouchWidget
operator|::
name|reset
parameter_list|()
block|{
name|acceptTouchBegin
operator|=
name|acceptTouchUpdate
operator|=
name|acceptTouchEnd
operator|=
name|seenTouchBegin
operator|=
name|seenTouchUpdate
operator|=
name|seenTouchEnd
operator|=
name|closeWindowOnTouchEnd
operator|=
name|acceptMousePress
operator|=
name|acceptMouseMove
operator|=
name|acceptMouseRelease
operator|=
name|seenMousePress
operator|=
name|seenMouseMove
operator|=
name|seenMouseRelease
operator|=
name|closeWindowOnMouseRelease
operator|=
literal|false
expr_stmt|;
name|touchPointCount
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|TouchWidget
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
name|TouchBegin
case|:
if|if
condition|(
name|seenTouchBegin
condition|)
name|qWarning
argument_list|(
literal|"TouchBegin: already seen a TouchBegin"
argument_list|)
expr_stmt|;
if|if
condition|(
name|seenTouchUpdate
condition|)
name|qWarning
argument_list|(
literal|"TouchBegin: TouchUpdate cannot happen before TouchBegin"
argument_list|)
expr_stmt|;
if|if
condition|(
name|seenTouchEnd
condition|)
name|qWarning
argument_list|(
literal|"TouchBegin: TouchEnd cannot happen before TouchBegin"
argument_list|)
expr_stmt|;
name|seenTouchBegin
operator|=
operator|!
name|seenTouchBegin
operator|&&
operator|!
name|seenTouchUpdate
operator|&&
operator|!
name|seenTouchEnd
expr_stmt|;
name|touchPointCount
operator|=
name|qMax
argument_list|(
name|touchPointCount
argument_list|,
cast|static_cast
argument_list|<
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
operator|->
name|touchPoints
argument_list|()
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|acceptTouchBegin
condition|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|TouchUpdate
case|:
if|if
condition|(
operator|!
name|seenTouchBegin
condition|)
name|qWarning
argument_list|(
literal|"TouchUpdate: have not seen TouchBegin"
argument_list|)
expr_stmt|;
if|if
condition|(
name|seenTouchEnd
condition|)
name|qWarning
argument_list|(
literal|"TouchUpdate: TouchEnd cannot happen before TouchUpdate"
argument_list|)
expr_stmt|;
name|seenTouchUpdate
operator|=
name|seenTouchBegin
operator|&&
operator|!
name|seenTouchEnd
expr_stmt|;
name|touchPointCount
operator|=
name|qMax
argument_list|(
name|touchPointCount
argument_list|,
cast|static_cast
argument_list|<
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
operator|->
name|touchPoints
argument_list|()
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|acceptTouchUpdate
condition|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|TouchEnd
case|:
if|if
condition|(
operator|!
name|seenTouchBegin
condition|)
name|qWarning
argument_list|(
literal|"TouchEnd: have not seen TouchBegin"
argument_list|)
expr_stmt|;
if|if
condition|(
name|seenTouchEnd
condition|)
name|qWarning
argument_list|(
literal|"TouchEnd: already seen a TouchEnd"
argument_list|)
expr_stmt|;
name|seenTouchEnd
operator|=
name|seenTouchBegin
operator|&&
operator|!
name|seenTouchEnd
expr_stmt|;
name|touchPointCount
operator|=
name|qMax
argument_list|(
name|touchPointCount
argument_list|,
cast|static_cast
argument_list|<
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
operator|->
name|touchPoints
argument_list|()
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|closeWindowOnTouchEnd
condition|)
name|window
argument_list|()
operator|->
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|acceptTouchEnd
condition|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
name|seenMousePress
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|acceptMousePress
condition|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|MouseMove
case|:
name|seenMouseMove
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|acceptMouseMove
condition|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
name|seenMouseRelease
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|closeWindowOnMouseRelease
condition|)
name|window
argument_list|()
operator|->
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|acceptMouseRelease
condition|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
default|default:
break|break;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
end_unit
