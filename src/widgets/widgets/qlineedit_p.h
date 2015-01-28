begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLINEEDIT_P_H
end_ifndef
begin_define
DECL|macro|QLINEEDIT_P_H
define|#
directive|define
name|QLINEEDIT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qglobal.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
end_ifndef
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qlineedit.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qtoolbutton.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextlayout.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qicon.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qcompleter.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmimedata.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidgetlinecontrol_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// QLineEditIconButton: This is a simple helper class that represents clickable icons that fade in with text
name|class
name|QLineEditIconButton
range|:
name|public
name|QToolButton
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|qreal opacity READ opacity WRITE setOpacity
argument_list|)
name|public
operator|:
expr|enum
block|{
name|IconMargin
operator|=
literal|4
block|,
name|IconButtonSize
operator|=
literal|16
block|}
block|;
name|explicit
name|QLineEditIconButton
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|qreal
name|opacity
argument_list|()
specifier|const
block|{
return|return
name|m_opacity
return|;
block|}
name|void
name|setOpacity
argument_list|(
argument|qreal value
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|void
name|animateShow
argument_list|(
argument|bool visible
argument_list|)
block|{
name|startOpacityAnimation
argument_list|(
name|visible
operator|?
literal|1.0
operator|:
literal|0.0
argument_list|)
block|; }
endif|#
directive|endif
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
name|slots
operator|:
name|void
name|updateCursor
argument_list|()
block|;
name|private
operator|:
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|void
name|startOpacityAnimation
argument_list|(
argument|qreal endValue
argument_list|)
block|;
endif|#
directive|endif
name|qreal
name|m_opacity
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QLineEditPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QLineEdit
argument_list|)
name|public
operator|:
expr|enum
name|SideWidgetFlag
block|{
name|SideWidgetFadeInWithText
operator|=
literal|0x1
block|,
name|SideWidgetCreatedByWidgetAction
operator|=
literal|0x2
block|,
name|SideWidgetClearButton
operator|=
literal|0x4
block|}
block|;      struct
name|SideWidgetEntry
block|{
name|SideWidgetEntry
argument_list|(
argument|QWidget *w =
literal|0
argument_list|,
argument|QAction *a =
literal|0
argument_list|,
argument|int _flags =
literal|0
argument_list|)
operator|:
name|widget
argument_list|(
name|w
argument_list|)
block|,
name|action
argument_list|(
name|a
argument_list|)
block|,
name|flags
argument_list|(
argument|_flags
argument_list|)
block|{}
name|QWidget
operator|*
name|widget
block|;
name|QAction
operator|*
name|action
block|;
name|int
name|flags
block|;     }
block|;
typedef|typedef
name|QList
operator|<
name|SideWidgetEntry
operator|>
name|SideWidgetEntryList
expr_stmt|;
name|QLineEditPrivate
argument_list|()
operator|:
name|control
argument_list|(
literal|0
argument_list|)
block|,
name|frame
argument_list|(
literal|1
argument_list|)
block|,
name|contextMenuEnabled
argument_list|(
literal|1
argument_list|)
block|,
name|cursorVisible
argument_list|(
literal|0
argument_list|)
block|,
name|dragEnabled
argument_list|(
literal|0
argument_list|)
block|,
name|clickCausedFocus
argument_list|(
literal|0
argument_list|)
block|,
name|hscroll
argument_list|(
literal|0
argument_list|)
block|,
name|vscroll
argument_list|(
literal|0
argument_list|)
block|,
name|alignment
argument_list|(
name|Qt
operator|::
name|AlignLeading
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
block|,
name|leftTextMargin
argument_list|(
literal|0
argument_list|)
block|,
name|topTextMargin
argument_list|(
literal|0
argument_list|)
block|,
name|rightTextMargin
argument_list|(
literal|0
argument_list|)
block|,
name|bottomTextMargin
argument_list|(
literal|0
argument_list|)
block|,
name|lastTextSize
argument_list|(
literal|0
argument_list|)
block|{     }
operator|~
name|QLineEditPrivate
argument_list|()
block|{     }
name|QWidgetLineControl
operator|*
name|control
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
end_ifndef
begin_expr_stmt
name|QPointer
operator|<
name|QAction
operator|>
name|selectAllAction
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|init
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QRect
name|adjustedControlRect
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|xToPos
argument_list|(
name|int
name|x
argument_list|,
name|QTextLine
operator|::
name|CursorPosition
operator|=
name|QTextLine
operator|::
name|CursorBetweenCharacters
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QRect
name|cursorRect
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setCursorVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updatePasswordEchoEditing
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resetInputMethod
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|bool
name|shouldEnableInputMethod
argument_list|()
specifier|const
block|{
return|return
operator|!
name|control
operator|->
name|isReadOnly
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|shouldShowPlaceholderText
argument_list|()
specifier|const
block|{
return|return
name|control
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|control
operator|->
name|preeditAreaText
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
operator|(
operator|(
name|alignment
operator|&
name|Qt
operator|::
name|AlignHCenter
operator|)
operator|&&
name|q_func
argument_list|()
operator|->
name|hasFocus
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|QLineEditPrivate
modifier|*
name|get
parameter_list|(
name|QLineEdit
modifier|*
name|lineEdit
parameter_list|)
block|{
return|return
name|lineEdit
operator|->
name|d_func
argument_list|()
return|;
block|}
end_function
begin_decl_stmt
name|QPoint
name|tripleClick
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|tripleClickTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|frame
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|contextMenuEnabled
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|cursorVisible
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|dragEnabled
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|clickCausedFocus
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|hscroll
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|vscroll
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|alignment
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|int
name|verticalMargin
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|int
name|horizontalMargin
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|sendMouseEventToInputContext
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QRect
name|adjustedContentsRect
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|_q_handleWindowActivate
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_textEdited
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_cursorPositionChanged
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
end_ifdef
begin_function_decl
name|void
name|_q_editFocusChange
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|_q_selectionChanged
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_updateNeeded
parameter_list|(
specifier|const
name|QRect
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
end_ifndef
begin_function_decl
name|void
name|_q_completionHighlighted
parameter_list|(
name|QString
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QPoint
name|mousePressPos
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_decl_stmt
name|QBasicTimer
name|dndTimer
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|drag
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|_q_textChanged
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_clearButtonClicked
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|int
name|leftTextMargin
decl_stmt|;
end_decl_stmt
begin_comment
comment|// use effectiveLeftTextMargin() in case of icon.
end_comment
begin_decl_stmt
name|int
name|topTextMargin
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|rightTextMargin
decl_stmt|;
end_decl_stmt
begin_comment
comment|// use effectiveRightTextMargin() in case of icon.
end_comment
begin_decl_stmt
name|int
name|bottomTextMargin
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|placeholderText
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWidget
modifier|*
name|addAction
argument_list|(
name|QAction
operator|*
name|newAction
argument_list|,
name|QAction
operator|*
name|before
argument_list|,
name|QLineEdit
operator|::
name|ActionPosition
argument_list|,
name|int
name|flags
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|removeAction
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QSize
name|iconSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QIcon
name|clearButtonIcon
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setClearButtonEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|positionSideWidgets
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|bool
name|hasSideWidgets
argument_list|()
specifier|const
block|{
return|return
operator|!
name|leadingSideWidgets
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|trailingSideWidgets
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|SideWidgetEntryList
operator|&
name|leftSideWidgetList
argument_list|()
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|layoutDirection
argument_list|()
operator|==
name|Qt
operator|::
name|LeftToRight
operator|?
name|leadingSideWidgets
operator|:
name|trailingSideWidgets
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|SideWidgetEntryList
operator|&
name|rightSideWidgetList
argument_list|()
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|layoutDirection
argument_list|()
operator|==
name|Qt
operator|::
name|LeftToRight
operator|?
name|trailingSideWidgets
operator|:
name|leadingSideWidgets
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|effectiveLeftTextMargin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|effectiveRightTextMargin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_typedef
typedef|typedef
name|QPair
operator|<
name|QLineEdit
operator|::
name|ActionPosition
operator|,
name|int
operator|>
name|PositionIndexPair
expr_stmt|;
end_typedef
begin_decl_stmt
name|PositionIndexPair
name|findSideWidget
argument_list|(
specifier|const
name|QAction
operator|*
name|a
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|SideWidgetEntryList
name|leadingSideWidgets
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|SideWidgetEntryList
name|trailingSideWidgets
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|lastTextSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QSize
name|m_iconSize
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
DECL|function|effectiveLeftTextMargin
specifier|inline
name|int
name|QLineEditPrivate
operator|::
name|effectiveLeftTextMargin
argument_list|()
specifier|const
block|{
return|return
name|leftTextMargin
operator|+
name|leftSideWidgetList
argument_list|()
operator|.
name|size
argument_list|()
operator|*
operator|(
name|QLineEditIconButton
operator|::
name|IconMargin
operator|+
name|iconSize
argument_list|()
operator|.
name|width
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|effectiveRightTextMargin
specifier|inline
name|int
name|QLineEditPrivate
operator|::
name|effectiveRightTextMargin
argument_list|()
specifier|const
block|{
return|return
name|rightTextMargin
operator|+
name|rightSideWidgetList
argument_list|()
operator|.
name|size
argument_list|()
operator|*
operator|(
name|QLineEditIconButton
operator|::
name|IconMargin
operator|+
name|iconSize
argument_list|()
operator|.
name|width
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LINEEDIT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLINEEDIT_P_H
end_comment
end_unit
