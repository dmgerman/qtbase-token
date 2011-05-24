begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"private/qsoftkeymanager_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qaction_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qsoftkeymanager_common_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_include
include|#
directive|include
file|"private/qsoftkeymanager_s60_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|SYMBIAN_VERSION_SYMBIAN3
end_ifdef
begin_include
include|#
directive|include
file|"private/qt_s60_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SOFTKEYMANAGER
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|self
name|QSoftKeyManager
modifier|*
name|QSoftKeyManagerPrivate
operator|::
name|self
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|standardSoftKeyText
name|QString
name|QSoftKeyManager
operator|::
name|standardSoftKeyText
parameter_list|(
name|StandardSoftKey
name|standardKey
parameter_list|)
block|{
name|QString
name|softKeyText
decl_stmt|;
switch|switch
condition|(
name|standardKey
condition|)
block|{
case|case
name|OkSoftKey
case|:
name|softKeyText
operator|=
name|QSoftKeyManager
operator|::
name|tr
argument_list|(
literal|"Ok"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SelectSoftKey
case|:
name|softKeyText
operator|=
name|QSoftKeyManager
operator|::
name|tr
argument_list|(
literal|"Select"
argument_list|)
expr_stmt|;
break|break;
case|case
name|DoneSoftKey
case|:
name|softKeyText
operator|=
name|QSoftKeyManager
operator|::
name|tr
argument_list|(
literal|"Done"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MenuSoftKey
case|:
name|softKeyText
operator|=
name|QSoftKeyManager
operator|::
name|tr
argument_list|(
literal|"Options"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CancelSoftKey
case|:
name|softKeyText
operator|=
name|QSoftKeyManager
operator|::
name|tr
argument_list|(
literal|"Cancel"
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
empty_stmt|;
return|return
name|softKeyText
return|;
block|}
end_function
begin_function
DECL|function|instance
name|QSoftKeyManager
modifier|*
name|QSoftKeyManager
operator|::
name|instance
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QSoftKeyManagerPrivate
operator|::
name|self
condition|)
name|QSoftKeyManagerPrivate
operator|::
name|self
operator|=
operator|new
name|QSoftKeyManager
expr_stmt|;
return|return
name|QSoftKeyManagerPrivate
operator|::
name|self
return|;
block|}
end_function
begin_constructor
DECL|function|QSoftKeyManager
name|QSoftKeyManager
operator|::
name|QSoftKeyManager
parameter_list|()
member_init_list|:
ifdef|#
directive|ifdef
name|Q_WS_S60
name|QObject
argument_list|(
operator|*
operator|(
operator|new
name|QSoftKeyManagerPrivateS60
operator|)
argument_list|,
literal|0
argument_list|)
else|#
directive|else
name|QObject
argument_list|(
operator|*
operator|(
operator|new
name|QSoftKeyManagerPrivate
operator|)
argument_list|,
literal|0
argument_list|)
endif|#
directive|endif
block|{ }
end_constructor
begin_function
DECL|function|createAction
name|QAction
modifier|*
name|QSoftKeyManager
operator|::
name|createAction
parameter_list|(
name|StandardSoftKey
name|standardKey
parameter_list|,
name|QWidget
modifier|*
name|actionWidget
parameter_list|)
block|{
name|QAction
modifier|*
name|action
init|=
operator|new
name|QAction
argument_list|(
name|standardSoftKeyText
argument_list|(
name|standardKey
argument_list|)
argument_list|,
name|actionWidget
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|SYMBIAN_VERSION_SYMBIAN3
name|int
name|key
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|standardKey
condition|)
block|{
case|case
name|OkSoftKey
case|:
name|key
operator|=
name|EAknSoftkeyOk
expr_stmt|;
break|break;
case|case
name|SelectSoftKey
case|:
name|key
operator|=
name|EAknSoftkeySelect
expr_stmt|;
break|break;
case|case
name|DoneSoftKey
case|:
name|key
operator|=
name|EAknSoftkeyDone
expr_stmt|;
break|break;
case|case
name|MenuSoftKey
case|:
name|key
operator|=
name|EAknSoftkeyOptions
expr_stmt|;
break|break;
case|case
name|CancelSoftKey
case|:
name|key
operator|=
name|EAknSoftkeyCancel
expr_stmt|;
break|break;
default|default:
break|break;
block|}
empty_stmt|;
if|if
condition|(
name|key
operator|!=
literal|0
condition|)
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|softKeyCommandActions
operator|.
name|insert
argument_list|(
name|action
argument_list|,
name|key
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QAction
operator|::
name|SoftKeyRole
name|softKeyRole
init|=
name|QAction
operator|::
name|NoSoftKey
decl_stmt|;
switch|switch
condition|(
name|standardKey
condition|)
block|{
case|case
name|MenuSoftKey
case|:
comment|// FALL-THROUGH
name|QActionPrivate
operator|::
name|get
argument_list|(
name|action
argument_list|)
operator|->
name|menuActionSoftkeys
operator|=
literal|true
expr_stmt|;
case|case
name|OkSoftKey
case|:
case|case
name|SelectSoftKey
case|:
case|case
name|DoneSoftKey
case|:
name|softKeyRole
operator|=
name|QAction
operator|::
name|PositiveSoftKey
expr_stmt|;
break|break;
case|case
name|CancelSoftKey
case|:
name|softKeyRole
operator|=
name|QAction
operator|::
name|NegativeSoftKey
expr_stmt|;
break|break;
block|}
name|action
operator|->
name|setSoftKeyRole
argument_list|(
name|softKeyRole
argument_list|)
expr_stmt|;
name|action
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setForceEnabledInSoftkeys
argument_list|(
name|action
argument_list|)
expr_stmt|;
return|return
name|action
return|;
block|}
end_function
begin_comment
comment|/*! \internal    Creates a QAction and registers the 'triggered' signal to send the given key event to   \a actionWidget as a convenience.  */
end_comment
begin_function
DECL|function|createKeyedAction
name|QAction
modifier|*
name|QSoftKeyManager
operator|::
name|createKeyedAction
parameter_list|(
name|StandardSoftKey
name|standardKey
parameter_list|,
name|Qt
operator|::
name|Key
name|key
parameter_list|,
name|QWidget
modifier|*
name|actionWidget
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|QScopedPointer
argument_list|<
name|QAction
argument_list|>
name|action
argument_list|(
name|createAction
argument_list|(
name|standardKey
argument_list|,
name|actionWidget
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|action
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|sendKeyEvent
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|action
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|cleanupHash
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|keyedActions
operator|.
name|insert
argument_list|(
name|action
operator|.
name|data
argument_list|()
argument_list|,
name|key
argument_list|)
expr_stmt|;
return|return
name|action
operator|.
name|take
argument_list|()
return|;
endif|#
directive|endif
comment|//QT_NO_ACTION
block|}
end_function
begin_function
DECL|function|cleanupHash
name|void
name|QSoftKeyManager
operator|::
name|cleanupHash
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSoftKeyManager
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|action
init|=
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
decl_stmt|;
name|d
operator|->
name|keyedActions
operator|.
name|remove
argument_list|(
name|action
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SYMBIAN_VERSION_SYMBIAN3
name|d
operator|->
name|softKeyCommandActions
operator|.
name|remove
argument_list|(
name|action
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|sendKeyEvent
name|void
name|QSoftKeyManager
operator|::
name|sendKeyEvent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSoftKeyManager
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|action
init|=
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|action
condition|)
return|return;
name|Qt
operator|::
name|Key
name|keyToSend
init|=
name|d
operator|->
name|keyedActions
operator|.
name|value
argument_list|(
name|action
argument_list|,
name|Qt
operator|::
name|Key_unknown
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyToSend
operator|!=
name|Qt
operator|::
name|Key_unknown
condition|)
name|QApplication
operator|::
name|postEvent
argument_list|(
name|action
operator|->
name|parentWidget
argument_list|()
argument_list|,
operator|new
name|QKeyEvent
argument_list|(
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|keyToSend
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateSoftKeys
name|void
name|QSoftKeyManager
operator|::
name|updateSoftKeys
parameter_list|()
block|{
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|pendingUpdate
operator|=
literal|true
expr_stmt|;
name|QEvent
modifier|*
name|event
init|=
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|UpdateSoftKeys
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|postEvent
argument_list|(
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|appendSoftkeys
name|bool
name|QSoftKeyManager
operator|::
name|appendSoftkeys
parameter_list|(
specifier|const
name|QWidget
modifier|&
name|source
parameter_list|,
name|int
name|level
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSoftKeyManager
argument_list|)
expr_stmt|;
name|bool
name|ret
init|=
literal|false
decl_stmt|;
foreach|foreach
control|(
name|QAction
modifier|*
name|action
decl|,
name|source
operator|.
name|actions
argument_list|()
control|)
block|{
if|if
condition|(
name|action
operator|->
name|softKeyRole
argument_list|()
operator|!=
name|QAction
operator|::
name|NoSoftKey
operator|&&
operator|(
name|action
operator|->
name|isVisible
argument_list|()
operator|||
name|isForceEnabledInSofkeys
argument_list|(
name|action
argument_list|)
operator|)
condition|)
block|{
name|d
operator|->
name|requestedSoftKeyActions
operator|.
name|insert
argument_list|(
name|level
argument_list|,
name|action
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|true
expr_stmt|;
block|}
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|isChildOf
specifier|static
name|bool
name|isChildOf
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|c
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|p
parameter_list|)
block|{
while|while
condition|(
name|c
condition|)
block|{
if|if
condition|(
name|c
operator|==
name|p
condition|)
return|return
literal|true
return|;
name|c
operator|=
name|c
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|softkeySource
name|QWidget
modifier|*
name|QSoftKeyManager
operator|::
name|softkeySource
parameter_list|(
name|QWidget
modifier|*
name|previousSource
parameter_list|,
name|bool
modifier|&
name|recursiveMerging
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSoftKeyManager
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|source
init|=
name|NULL
decl_stmt|;
if|if
condition|(
operator|!
name|previousSource
condition|)
block|{
comment|// Initial source is primarily focuswidget and secondarily activeWindow
name|QWidget
modifier|*
name|focus
init|=
name|QApplication
operator|::
name|focusWidget
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|popup
init|=
name|QApplication
operator|::
name|activePopupWidget
argument_list|()
decl_stmt|;
if|if
condition|(
name|popup
condition|)
block|{
if|if
condition|(
name|isChildOf
argument_list|(
name|focus
argument_list|,
name|popup
argument_list|)
condition|)
name|source
operator|=
name|focus
expr_stmt|;
else|else
name|source
operator|=
name|popup
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|source
condition|)
block|{
name|QWidget
modifier|*
name|modal
init|=
name|QApplication
operator|::
name|activeModalWidget
argument_list|()
decl_stmt|;
if|if
condition|(
name|modal
condition|)
block|{
if|if
condition|(
name|isChildOf
argument_list|(
name|focus
argument_list|,
name|modal
argument_list|)
condition|)
name|source
operator|=
name|focus
expr_stmt|;
else|else
name|source
operator|=
name|modal
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|source
condition|)
block|{
name|source
operator|=
name|focus
expr_stmt|;
if|if
condition|(
operator|!
name|source
condition|)
name|source
operator|=
name|QApplication
operator|::
name|activeWindow
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Softkey merging is based on four criterias
comment|// 1. Implicit merging is used whenever focus widget does not specify any softkeys
name|bool
name|implicitMerging
init|=
name|d
operator|->
name|requestedSoftKeyActions
operator|.
name|isEmpty
argument_list|()
decl_stmt|;
comment|// 2. Explicit merging with parent is used whenever WA_MergeSoftkeys widget attribute is set
name|bool
name|explicitMerging
init|=
name|previousSource
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_MergeSoftkeys
argument_list|)
decl_stmt|;
comment|// 3. Explicit merging with all parents
name|recursiveMerging
operator||=
name|previousSource
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_MergeSoftkeysRecursively
argument_list|)
expr_stmt|;
comment|// 4. Implicit and explicit merging always stops at window boundary
name|bool
name|merging
init|=
operator|(
name|implicitMerging
operator|||
name|explicitMerging
operator|||
name|recursiveMerging
operator|)
operator|&&
operator|!
name|previousSource
operator|->
name|isWindow
argument_list|()
decl_stmt|;
name|source
operator|=
name|merging
condition|?
name|previousSource
operator|->
name|parentWidget
argument_list|()
else|:
name|NULL
expr_stmt|;
block|}
return|return
name|source
return|;
block|}
end_function
begin_function
DECL|function|handleUpdateSoftKeys
name|bool
name|QSoftKeyManager
operator|::
name|handleUpdateSoftKeys
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSoftKeyManager
argument_list|)
expr_stmt|;
name|int
name|level
init|=
literal|0
decl_stmt|;
name|d
operator|->
name|requestedSoftKeyActions
operator|.
name|clear
argument_list|()
expr_stmt|;
name|bool
name|recursiveMerging
init|=
literal|false
decl_stmt|;
name|QWidget
modifier|*
name|source
init|=
name|softkeySource
argument_list|(
name|NULL
argument_list|,
name|recursiveMerging
argument_list|)
decl_stmt|;
name|d
operator|->
name|initialSoftKeySource
operator|=
name|source
expr_stmt|;
while|while
condition|(
name|source
condition|)
block|{
if|if
condition|(
name|appendSoftkeys
argument_list|(
operator|*
name|source
argument_list|,
name|level
argument_list|)
condition|)
operator|++
name|level
expr_stmt|;
name|source
operator|=
name|softkeySource
argument_list|(
name|source
argument_list|,
name|recursiveMerging
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|updateSoftKeys_sys
argument_list|()
expr_stmt|;
name|d
operator|->
name|pendingUpdate
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setForceEnabledInSoftkeys
name|void
name|QSoftKeyManager
operator|::
name|setForceEnabledInSoftkeys
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
block|{
name|QActionPrivate
operator|::
name|get
argument_list|(
name|action
argument_list|)
operator|->
name|forceEnabledInSoftkeys
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isForceEnabledInSofkeys
name|bool
name|QSoftKeyManager
operator|::
name|isForceEnabledInSofkeys
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
block|{
return|return
name|QActionPrivate
operator|::
name|get
argument_list|(
name|action
argument_list|)
operator|->
name|forceEnabledInSoftkeys
return|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QSoftKeyManager
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_ACTION
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|UpdateSoftKeys
condition|)
return|return
name|handleUpdateSoftKeys
argument_list|()
return|;
endif|#
directive|endif
comment|//QT_NO_ACTION
return|return
literal|false
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_function
DECL|function|handleCommand
name|bool
name|QSoftKeyManager
operator|::
name|handleCommand
parameter_list|(
name|int
name|command
parameter_list|)
block|{
if|if
condition|(
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|pendingUpdate
condition|)
operator|(
name|void
operator|)
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
operator|->
name|handleUpdateSoftKeys
argument_list|()
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|QSoftKeyManagerPrivateS60
operator|*
argument_list|>
argument_list|(
name|QSoftKeyManager
operator|::
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
argument_list|)
operator|->
name|handleCommand
argument_list|(
name|command
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_SOFTKEYMANAGER
end_comment
end_unit
