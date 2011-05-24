begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwsinputcontext_p.h"
end_include
begin_include
include|#
directive|include
file|"qinputcontext_p.h"
end_include
begin_include
include|#
directive|include
file|"qwsdisplay_qws.h"
end_include
begin_include
include|#
directive|include
file|"qwsevent_qws.h"
end_include
begin_include
include|#
directive|include
file|"private/qwscommand_qws_p.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsystem_qws.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qtextformat.h"
end_include
begin_include
include|#
directive|include
file|<qbuffer.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_INPUTMETHODS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|activeWidget
specifier|static
name|QWidget
modifier|*
name|activeWidget
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
comment|//#define EXTRA_DEBUG
end_comment
begin_constructor
DECL|function|QWSInputContext
name|QWSInputContext
operator|::
name|QWSInputContext
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QInputContext
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|reset
name|void
name|QWSInputContext
operator|::
name|reset
parameter_list|()
block|{
name|QPaintDevice
operator|::
name|qwsDisplay
argument_list|()
operator|->
name|resetIM
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFocusWidget
name|void
name|QWSInputContext
operator|::
name|setFocusWidget
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
name|QWidget
modifier|*
name|oldFocus
init|=
name|focusWidget
argument_list|()
decl_stmt|;
if|if
condition|(
name|oldFocus
operator|==
name|w
condition|)
return|return;
if|if
condition|(
name|w
condition|)
block|{
name|QWSInputContext
operator|::
name|updateImeStatus
argument_list|(
name|w
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|oldFocus
condition|)
name|QWSInputContext
operator|::
name|updateImeStatus
argument_list|(
name|oldFocus
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|oldFocus
condition|)
block|{
name|QWidget
modifier|*
name|tlw
init|=
name|oldFocus
operator|->
name|window
argument_list|()
decl_stmt|;
name|int
name|winid
init|=
name|tlw
operator|->
name|internalWinId
argument_list|()
decl_stmt|;
name|int
name|widgetid
init|=
name|oldFocus
operator|->
name|internalWinId
argument_list|()
decl_stmt|;
name|QPaintDevice
operator|::
name|qwsDisplay
argument_list|()
operator|->
name|sendIMUpdate
argument_list|(
name|QWSInputMethod
operator|::
name|FocusOut
argument_list|,
name|winid
argument_list|,
name|widgetid
argument_list|)
expr_stmt|;
block|}
name|QInputContext
operator|::
name|setFocusWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|w
condition|)
return|return;
name|QWidget
modifier|*
name|tlw
init|=
name|w
operator|->
name|window
argument_list|()
decl_stmt|;
name|int
name|winid
init|=
name|tlw
operator|->
name|winId
argument_list|()
decl_stmt|;
name|int
name|widgetid
init|=
name|w
operator|->
name|winId
argument_list|()
decl_stmt|;
name|QPaintDevice
operator|::
name|qwsDisplay
argument_list|()
operator|->
name|sendIMUpdate
argument_list|(
name|QWSInputMethod
operator|::
name|FocusIn
argument_list|,
name|winid
argument_list|,
name|widgetid
argument_list|)
expr_stmt|;
comment|//setfocus ???
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|widgetDestroyed
name|void
name|QWSInputContext
operator|::
name|widgetDestroyed
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
if|if
condition|(
name|w
operator|==
name|QT_PREPEND_NAMESPACE
argument_list|(
name|activeWidget
argument_list|)
condition|)
name|QT_PREPEND_NAMESPACE
argument_list|(
name|activeWidget
argument_list|)
operator|=
literal|0
expr_stmt|;
name|QInputContext
operator|::
name|widgetDestroyed
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QWSInputContext
operator|::
name|update
parameter_list|()
block|{
name|QWidget
modifier|*
name|w
init|=
name|focusWidget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|w
condition|)
return|return;
name|QWidget
modifier|*
name|tlw
init|=
name|w
operator|->
name|window
argument_list|()
decl_stmt|;
name|int
name|winid
init|=
name|tlw
operator|->
name|winId
argument_list|()
decl_stmt|;
name|int
name|widgetid
init|=
name|w
operator|->
name|winId
argument_list|()
decl_stmt|;
name|QPaintDevice
operator|::
name|qwsDisplay
argument_list|()
operator|->
name|sendIMUpdate
argument_list|(
name|QWSInputMethod
operator|::
name|Update
argument_list|,
name|winid
argument_list|,
name|widgetid
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseHandler
name|void
name|QWSInputContext
operator|::
name|mouseHandler
parameter_list|(
name|int
name|x
parameter_list|,
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonPress
operator|||
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonRelease
condition|)
name|QPaintDevice
operator|::
name|qwsDisplay
argument_list|()
operator|->
name|sendIMMouseEvent
argument_list|(
name|x
argument_list|,
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonPress
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|activeWidget
name|QWidget
modifier|*
name|QWSInputContext
operator|::
name|activeWidget
parameter_list|()
block|{
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|activeWidget
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isComposing
name|bool
name|QWSInputContext
operator|::
name|isComposing
parameter_list|()
specifier|const
block|{
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|activeWidget
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|translateIMQueryEvent
name|bool
name|QWSInputContext
operator|::
name|translateIMQueryEvent
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QWSIMQueryEvent
modifier|*
name|e
parameter_list|)
block|{
name|Qt
operator|::
name|InputMethodQuery
name|type
init|=
cast|static_cast
argument_list|<
name|Qt
operator|::
name|InputMethodQuery
argument_list|>
argument_list|(
name|e
operator|->
name|simpleData
operator|.
name|property
argument_list|)
decl_stmt|;
name|QVariant
name|result
init|=
name|w
operator|->
name|inputMethodQuery
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|tlw
init|=
name|w
operator|->
name|window
argument_list|()
decl_stmt|;
name|int
name|winId
init|=
name|tlw
operator|->
name|winId
argument_list|()
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|ImMicroFocus
condition|)
block|{
comment|// translate to relative to tlw
name|QRect
name|mf
init|=
name|result
operator|.
name|toRect
argument_list|()
decl_stmt|;
name|mf
operator|.
name|moveTopLeft
argument_list|(
name|w
operator|->
name|mapTo
argument_list|(
name|tlw
argument_list|,
name|mf
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|mf
expr_stmt|;
block|}
name|QPaintDevice
operator|::
name|qwsDisplay
argument_list|()
operator|->
name|sendIMResponse
argument_list|(
name|winId
argument_list|,
name|e
operator|->
name|simpleData
operator|.
name|property
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|translateIMInitEvent
name|bool
name|QWSInputContext
operator|::
name|translateIMInitEvent
parameter_list|(
specifier|const
name|QWSIMInitEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"### QWSInputContext::translateIMInitEvent not implemented ###"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|translateIMEvent
name|bool
name|QWSInputContext
operator|::
name|translateIMEvent
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QWSIMEvent
modifier|*
name|e
parameter_list|)
block|{
name|QDataStream
name|stream
argument_list|(
name|e
operator|->
name|streamingData
argument_list|)
decl_stmt|;
name|QString
name|preedit
decl_stmt|;
name|QString
name|commit
decl_stmt|;
name|stream
operator|>>
name|preedit
expr_stmt|;
name|stream
operator|>>
name|commit
expr_stmt|;
if|if
condition|(
name|preedit
operator|.
name|isEmpty
argument_list|()
operator|&&
name|QT_PREPEND_NAMESPACE
argument_list|(
name|activeWidget
argument_list|)
condition|)
name|w
operator|=
name|QT_PREPEND_NAMESPACE
argument_list|(
name|activeWidget
argument_list|)
expr_stmt|;
name|QInputContext
modifier|*
name|qic
init|=
name|w
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qic
condition|)
return|return
literal|false
return|;
name|QList
argument_list|<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|>
name|attrs
decl_stmt|;
while|while
condition|(
operator|!
name|stream
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|int
name|type
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|start
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|length
init|=
operator|-
literal|1
decl_stmt|;
name|QVariant
name|data
decl_stmt|;
name|stream
operator|>>
name|type
operator|>>
name|start
operator|>>
name|length
operator|>>
name|data
expr_stmt|;
if|if
condition|(
name|stream
operator|.
name|status
argument_list|()
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
block|{
name|qWarning
argument_list|(
literal|"corrupted QWSIMEvent"
argument_list|)
expr_stmt|;
comment|//qic->reset(); //???
return|return
literal|false
return|;
block|}
if|if
condition|(
name|type
operator|==
name|QInputMethodEvent
operator|::
name|TextFormat
condition|)
name|data
operator|=
name|qic
operator|->
name|standardFormat
argument_list|(
cast|static_cast
argument_list|<
name|QInputContext
operator|::
name|StandardFormat
argument_list|>
argument_list|(
name|data
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|attrs
operator|<<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
cast|static_cast
argument_list|<
name|QInputMethodEvent
operator|::
name|AttributeType
argument_list|>
argument_list|(
name|type
argument_list|)
argument_list|,
name|start
argument_list|,
name|length
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|EXTRA_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"preedit"
operator|<<
name|preedit
operator|<<
literal|"len"
operator|<<
name|preedit
operator|.
name|length
argument_list|()
operator|<<
literal|"commit"
operator|<<
name|commit
operator|<<
literal|"len"
operator|<<
name|commit
operator|.
name|length
argument_list|()
operator|<<
literal|"n attr"
operator|<<
name|attrs
operator|.
name|count
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|preedit
operator|.
name|isEmpty
argument_list|()
condition|)
name|QT_PREPEND_NAMESPACE
argument_list|(
name|activeWidget
argument_list|)
operator|=
literal|0
expr_stmt|;
else|else
name|QT_PREPEND_NAMESPACE
argument_list|(
name|activeWidget
argument_list|)
operator|=
name|w
expr_stmt|;
name|QInputMethodEvent
name|ime
argument_list|(
name|preedit
argument_list|,
name|attrs
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|commit
operator|.
name|isEmpty
argument_list|()
operator|||
name|e
operator|->
name|simpleData
operator|.
name|replaceLength
operator|>
literal|0
condition|)
name|ime
operator|.
name|setCommitString
argument_list|(
name|commit
argument_list|,
name|e
operator|->
name|simpleData
operator|.
name|replaceFrom
argument_list|,
name|e
operator|->
name|simpleData
operator|.
name|replaceLength
argument_list|)
expr_stmt|;
specifier|extern
name|bool
name|qt_sendSpontaneousEvent
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
decl_stmt|;
comment|//qapplication_qws.cpp
name|qt_sendSpontaneousEvent
argument_list|(
name|w
argument_list|,
operator|&
name|ime
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function_decl
DECL|variable|qt_qws_inputMethodStatusChanged
name|Q_GUI_EXPORT
name|void
function_decl|(
modifier|*
name|qt_qws_inputMethodStatusChanged
function_decl|)
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|=
literal|0
function_decl|;
end_function_decl
begin_function
DECL|function|updateImeStatus
name|void
name|QWSInputContext
operator|::
name|updateImeStatus
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|bool
name|hasFocus
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|hasFocus
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|w
operator|||
operator|!
name|qt_qws_inputMethodStatusChanged
condition|)
return|return;
name|qt_qws_inputMethodStatusChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_INPUTMETHODS
end_comment
end_unit
