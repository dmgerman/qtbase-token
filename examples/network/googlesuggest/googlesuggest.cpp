begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [1]
end_comment
begin_include
include|#
directive|include
file|"googlesuggest.h"
end_include
begin_define
DECL|macro|GSUGGEST_URL
define|#
directive|define
name|GSUGGEST_URL
value|"http://google.com/complete/search?output=toolbar&q=%1"
end_define
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_constructor
DECL|function|GSuggestCompletion
name|GSuggestCompletion
operator|::
name|GSuggestCompletion
parameter_list|(
name|QLineEdit
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|editor
argument_list|(
name|parent
argument_list|)
block|{
name|popup
operator|=
operator|new
name|QTreeWidget
expr_stmt|;
name|popup
operator|->
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|Popup
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setFocusProxy
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setColumnCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setUniformRowHeights
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setRootIsDecorated
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setEditTriggers
argument_list|(
name|QTreeWidget
operator|::
name|NoEditTriggers
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setSelectionBehavior
argument_list|(
name|QTreeWidget
operator|::
name|SelectRows
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|Box
operator||
name|QFrame
operator|::
name|Plain
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|popup
operator|->
name|header
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|popup
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|popup
argument_list|,
name|SIGNAL
argument_list|(
name|itemClicked
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|doneCompletion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|timer
operator|->
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|timer
operator|->
name|setInterval
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|autoSuggest
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|editor
argument_list|,
name|SIGNAL
argument_list|(
name|textEdited
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|timer
argument_list|,
name|SLOT
argument_list|(
name|start
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|networkManager
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|handleNetworkData
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_destructor
DECL|function|~GSuggestCompletion
name|GSuggestCompletion
operator|::
name|~
name|GSuggestCompletion
parameter_list|()
block|{
operator|delete
name|popup
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|eventFilter
name|bool
name|GSuggestCompletion
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
name|QEvent
modifier|*
name|ev
parameter_list|)
block|{
if|if
condition|(
name|obj
operator|!=
name|popup
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|ev
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonPress
condition|)
block|{
name|popup
operator|->
name|hide
argument_list|()
expr_stmt|;
name|editor
operator|->
name|setFocus
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|ev
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
block|{
name|bool
name|consumed
init|=
literal|false
decl_stmt|;
name|int
name|key
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|ev
argument_list|)
operator|->
name|key
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|key
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Enter
case|:
case|case
name|Qt
operator|::
name|Key_Return
case|:
name|doneCompletion
argument_list|()
expr_stmt|;
name|consumed
operator|=
literal|true
expr_stmt|;
case|case
name|Qt
operator|::
name|Key_Escape
case|:
name|editor
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|popup
operator|->
name|hide
argument_list|()
expr_stmt|;
name|consumed
operator|=
literal|true
expr_stmt|;
case|case
name|Qt
operator|::
name|Key_Up
case|:
case|case
name|Qt
operator|::
name|Key_Down
case|:
case|case
name|Qt
operator|::
name|Key_Home
case|:
case|case
name|Qt
operator|::
name|Key_End
case|:
case|case
name|Qt
operator|::
name|Key_PageUp
case|:
case|case
name|Qt
operator|::
name|Key_PageDown
case|:
break|break;
default|default:
name|editor
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|editor
operator|->
name|event
argument_list|(
name|ev
argument_list|)
expr_stmt|;
name|popup
operator|->
name|hide
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
name|consumed
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|showCompletion
name|void
name|GSuggestCompletion
operator|::
name|showCompletion
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|choices
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|hits
parameter_list|)
block|{
if|if
condition|(
name|choices
operator|.
name|isEmpty
argument_list|()
operator|||
name|choices
operator|.
name|count
argument_list|()
operator|!=
name|hits
operator|.
name|count
argument_list|()
condition|)
return|return;
specifier|const
name|QPalette
modifier|&
name|pal
init|=
name|editor
operator|->
name|palette
argument_list|()
decl_stmt|;
name|QColor
name|color
init|=
name|pal
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|)
decl_stmt|;
name|popup
operator|->
name|setUpdatesEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|popup
operator|->
name|clear
argument_list|()
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
name|choices
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
decl_stmt|;
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|popup
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|choices
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|hits
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|item
operator|->
name|setTextAlignment
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|item
operator|->
name|setTextColor
argument_list|(
literal|1
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
name|popup
operator|->
name|setCurrentItem
argument_list|(
name|popup
operator|->
name|topLevelItem
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|popup
operator|->
name|resizeColumnToContents
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|popup
operator|->
name|resizeColumnToContents
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|popup
operator|->
name|adjustSize
argument_list|()
expr_stmt|;
name|popup
operator|->
name|setUpdatesEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|int
name|h
init|=
name|popup
operator|->
name|sizeHintForRow
argument_list|(
literal|0
argument_list|)
operator|*
name|qMin
argument_list|(
literal|7
argument_list|,
name|choices
operator|.
name|count
argument_list|()
argument_list|)
operator|+
literal|3
decl_stmt|;
name|popup
operator|->
name|resize
argument_list|(
name|popup
operator|->
name|width
argument_list|()
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|popup
operator|->
name|move
argument_list|(
name|editor
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
name|editor
operator|->
name|height
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|popup
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|popup
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|doneCompletion
name|void
name|GSuggestCompletion
operator|::
name|doneCompletion
parameter_list|()
block|{
name|timer
operator|->
name|stop
argument_list|()
expr_stmt|;
name|popup
operator|->
name|hide
argument_list|()
expr_stmt|;
name|editor
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|popup
operator|->
name|currentItem
argument_list|()
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|editor
operator|->
name|setText
argument_list|(
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|editor
argument_list|,
literal|"returnPressed"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|autoSuggest
name|void
name|GSuggestCompletion
operator|::
name|autoSuggest
parameter_list|()
block|{
name|QString
name|str
init|=
name|editor
operator|->
name|text
argument_list|()
decl_stmt|;
name|QString
name|url
init|=
name|QString
argument_list|(
name|GSUGGEST_URL
argument_list|)
operator|.
name|arg
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|networkManager
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|QString
argument_list|(
name|url
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|preventSuggest
name|void
name|GSuggestCompletion
operator|::
name|preventSuggest
parameter_list|()
block|{
name|timer
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|handleNetworkData
name|void
name|GSuggestCompletion
operator|::
name|handleNetworkData
parameter_list|(
name|QNetworkReply
modifier|*
name|networkReply
parameter_list|)
block|{
name|QUrl
name|url
init|=
name|networkReply
operator|->
name|url
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|networkReply
operator|->
name|error
argument_list|()
condition|)
block|{
name|QStringList
name|choices
decl_stmt|;
name|QStringList
name|hits
decl_stmt|;
name|QByteArray
name|response
argument_list|(
name|networkReply
operator|->
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|QXmlStreamReader
name|xml
argument_list|(
name|response
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|xml
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|xml
operator|.
name|readNext
argument_list|()
expr_stmt|;
if|if
condition|(
name|xml
operator|.
name|tokenType
argument_list|()
operator|==
name|QXmlStreamReader
operator|::
name|StartElement
condition|)
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"suggestion"
condition|)
block|{
name|QStringRef
name|str
init|=
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"data"
argument_list|)
decl_stmt|;
name|choices
operator|<<
name|str
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|xml
operator|.
name|tokenType
argument_list|()
operator|==
name|QXmlStreamReader
operator|::
name|StartElement
condition|)
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"num_queries"
condition|)
block|{
name|QStringRef
name|str
init|=
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"int"
argument_list|)
decl_stmt|;
name|hits
operator|<<
name|str
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
block|}
name|showCompletion
argument_list|(
name|choices
argument_list|,
name|hits
argument_list|)
expr_stmt|;
block|}
name|networkReply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
end_unit
