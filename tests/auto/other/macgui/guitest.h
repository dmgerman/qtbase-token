begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GUITEST_H
end_ifndef
begin_define
DECL|macro|GUITEST_H
define|#
directive|define
name|GUITEST_H
end_define
begin_include
include|#
directive|include
file|<QAccessibleInterface>
end_include
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_decl_stmt
name|QT_USE_NAMESPACE
comment|/*     GuiTest provides tools for:      - navigating the Qt Widget hiearchy using the accessibilty APIs.      - Simulating platform mouse and keybord events. */
name|class
name|TestBase
block|{
name|public
label|:
name|virtual
name|bool
name|operator
argument_list|()
argument_list|(
name|QAccessibleInterface
operator|*
name|candidate
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
operator|~
name|TestBase
argument_list|()
block|{}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*     WidgetNavigator navigates a Qt GUI hierarchy using the QAccessibility APIs. */
end_comment
begin_decl_stmt
name|class
name|WidgetNavigator
block|{
name|public
label|:
name|WidgetNavigator
argument_list|()
block|{}
empty_stmt|;
operator|~
name|WidgetNavigator
argument_list|()
expr_stmt|;
name|void
name|printAll
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
name|void
name|printAll
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
function_decl|;
name|QAccessibleInterface
modifier|*
name|find
argument_list|(
name|QAccessible
operator|::
name|Text
name|textType
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QWidget
operator|*
name|start
argument_list|)
decl_stmt|;
name|QAccessibleInterface
modifier|*
name|find
argument_list|(
name|QAccessible
operator|::
name|Text
name|textType
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QAccessibleInterface
operator|*
name|start
argument_list|)
decl_stmt|;
name|QAccessibleInterface
modifier|*
name|recursiveSearch
parameter_list|(
name|TestBase
modifier|*
name|test
parameter_list|,
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|)
function_decl|;
name|void
name|deleteInDestructor
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
function_decl|;
specifier|static
name|QWidget
modifier|*
name|getWidget
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
function_decl|;
name|private
label|:
name|QSet
operator|<
name|QAccessibleInterface
operator|*
operator|>
name|interfaces
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*     NativeEvents contains platform-specific code for simulating mouse and keybord events.     (Implemented so far: mouseClick on Mac) */
end_comment
begin_decl_stmt
name|namespace
name|NativeEvents
block|{
enum|enum
name|MousePosition
block|{
name|UpdatePosition
block|,
name|DontUpdatePosition
block|}
enum|;
comment|/*         Simulates a mouse click with button at globalPos.     */
name|void
name|mouseClick
argument_list|(
specifier|const
name|QPoint
operator|&
name|globalPos
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
argument_list|,
name|MousePosition
name|updateMouse
operator|=
name|DontUpdatePosition
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|ColorWidget
range|:
name|public
name|QWidget
block|{
name|public
operator|:
name|ColorWidget
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|QColor color = QColor(Qt::red)
argument_list|)
operator|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|,
name|color
argument_list|(
argument|color
argument_list|)
block|{}
name|QColor
name|color
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent  *
argument_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
block|;
name|p
operator|.
name|fillRect
argument_list|(
name|this
operator|->
name|rect
argument_list|()
argument_list|,
name|color
argument_list|)
block|;     }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|DelayedAction
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|DelayedAction
argument_list|()
operator|:
name|delay
argument_list|(
literal|0
argument_list|)
block|,
name|next
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|DelayedAction
argument_list|()
block|{}
name|public
name|slots
operator|:
name|virtual
name|void
name|run
argument_list|()
block|;
name|public
operator|:
name|int
name|delay
block|;
name|DelayedAction
operator|*
name|next
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ClickLaterAction
range|:
name|public
name|DelayedAction
block|{
name|Q_OBJECT
name|public
operator|:
name|ClickLaterAction
argument_list|(
argument|QAccessibleInterface *interface
argument_list|,
argument|Qt::MouseButtons buttons = Qt::LeftButton
argument_list|)
block|;
name|ClickLaterAction
argument_list|(
argument|QWidget *widget
argument_list|,
argument|Qt::MouseButtons buttons = Qt::LeftButton
argument_list|)
block|;
name|protected
name|slots
operator|:
name|void
name|run
argument_list|()
block|;
name|private
operator|:
name|bool
name|useInterface
block|;
name|QAccessibleInterface
operator|*
name|interface
block|;
name|QWidget
operator|*
name|widget
block|;
name|Qt
operator|::
name|MouseButtons
name|buttons
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*      */
end_comment
begin_decl_stmt
name|class
name|GuiTester
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|GuiTester
argument_list|()
block|;
operator|~
name|GuiTester
argument_list|()
block|;     enum
name|Direction
block|{
name|Horizontal
operator|=
literal|1
block|,
name|Vertical
operator|=
literal|2
block|,
name|HorizontalAndVertical
operator|=
literal|3
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Directions
argument_list|,
argument|Direction
argument_list|)
name|bool
name|isFilled
argument_list|(
argument|const QImage image
argument_list|,
argument|const QRect&rect
argument_list|,
argument|const QColor&color
argument_list|)
block|;
name|bool
name|isContent
argument_list|(
argument|const QImage image
argument_list|,
argument|const QRect&rect
argument_list|,
argument|Directions directions = HorizontalAndVertical
argument_list|)
block|;
name|protected
name|slots
operator|:
name|void
name|exitLoopSlot
argument_list|()
block|;
name|protected
operator|:
name|void
name|clickLater
argument_list|(
argument|QAccessibleInterface *interface
argument_list|,
argument|Qt::MouseButtons buttons = Qt::LeftButton
argument_list|,
argument|int delay =
literal|300
argument_list|)
block|;
name|void
name|clickLater
argument_list|(
argument|QWidget *widget
argument_list|,
argument|Qt::MouseButtons buttons = Qt::LeftButton
argument_list|,
argument|int delay =
literal|300
argument_list|)
block|;
name|void
name|clearSequence
argument_list|()
block|;
name|void
name|addToSequence
argument_list|(
argument|DelayedAction *action
argument_list|,
argument|int delay =
literal|0
argument_list|)
block|;
name|void
name|runSequence
argument_list|()
block|;
name|WidgetNavigator
name|wn
block|;
name|private
operator|:
name|QSet
operator|<
name|DelayedAction
operator|*
operator|>
name|actions
block|;
name|DelayedAction
operator|*
name|startAction
block|;
name|DelayedAction
operator|*
name|lastAction
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|GuiTester::Directions
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
