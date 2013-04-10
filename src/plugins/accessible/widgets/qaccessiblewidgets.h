begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLEWIDGETS_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLEWIDGETS_H
define|#
directive|define
name|QACCESSIBLEWIDGETS_H
end_define
begin_include
include|#
directive|include
file|<QtGui/private/qaccessible2_p.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/private/qaccessiblewidget_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/QPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPair>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextEdit
name|class
name|QTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStackedWidget
name|class
name|QStackedWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolBox
name|class
name|QToolBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMdiArea
name|class
name|QMdiArea
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMdiSubWindow
name|class
name|QMdiSubWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRubberBand
name|class
name|QRubberBand
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBrowser
name|class
name|QTextBrowser
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCalendarWidget
name|class
name|QCalendarWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractItemView
name|class
name|QAbstractItemView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDockWidget
name|class
name|QDockWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDockWidgetLayout
name|class
name|QDockWidgetLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMainWindow
name|class
name|QMainWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlainTextEdit
name|class
name|QPlainTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCursor
name|class
name|QTextCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocument
name|class
name|QTextDocument
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_decl_stmt
DECL|variable|QAccessibleWidget
name|class
name|QAccessibleTextWidget
range|:
name|public
name|QAccessibleWidget
decl_stmt|,
DECL|variable|QAccessibleTextInterface
name|public
name|QAccessibleTextInterface
decl_stmt|,
name|public
name|QAccessibleEditableTextInterface
block|{
name|public
label|:
name|QAccessibleTextWidget
argument_list|(
argument|QWidget *o
argument_list|,
argument|QAccessible::Role r = QAccessible::EditableText
argument_list|,
argument|const QString&name = QString()
argument_list|)
empty_stmt|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
expr_stmt|;
comment|// QAccessibleTextInterface
comment|//  selection
name|void
name|selection
argument_list|(
name|int
name|selectionIndex
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
decl_stmt|;
name|int
name|selectionCount
argument_list|()
specifier|const
expr_stmt|;
name|void
name|addSelection
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
function_decl|;
name|void
name|removeSelection
parameter_list|(
name|int
name|selectionIndex
parameter_list|)
function_decl|;
name|void
name|setSelection
parameter_list|(
name|int
name|selectionIndex
parameter_list|,
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
function_decl|;
comment|// cursor
name|int
name|cursorPosition
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCursorPosition
parameter_list|(
name|int
name|position
parameter_list|)
function_decl|;
comment|// text
name|QString
name|text
argument_list|(
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|)
decl|const
decl_stmt|;
name|QString
name|textBeforeOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
decl_stmt|;
name|QString
name|textAfterOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
decl_stmt|;
name|QString
name|textAtOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
decl_stmt|;
name|int
name|characterCount
argument_list|()
specifier|const
expr_stmt|;
comment|// character<-> geometry
name|QRect
name|characterRect
argument_list|(
name|int
name|offset
argument_list|)
decl|const
decl_stmt|;
name|int
name|offsetAtPoint
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
decl|const
decl_stmt|;
name|QString
name|attributes
argument_list|(
name|int
name|offset
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
decl_stmt|;
comment|// QAccessibleEditableTextInterface
name|void
name|deleteText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
function_decl|;
name|void
name|insertText
parameter_list|(
name|int
name|offset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|replaceText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|using
name|QAccessibleWidget
operator|::
name|text
expr_stmt|;
name|protected
label|:
name|QTextCursor
name|textCursorForRange
argument_list|(
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPoint
name|scrollBarPosition
argument_list|()
specifier|const
expr_stmt|;
comment|// return the current text cursor at the caret position including a potential selection
name|virtual
name|QTextCursor
name|textCursor
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setTextCursor
parameter_list|(
specifier|const
name|QTextCursor
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QTextDocument
operator|*
name|textDocument
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QWidget
operator|*
name|viewport
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
end_ifndef
begin_decl_stmt
name|class
name|QAccessiblePlainTextEdit
range|:
name|public
name|QAccessibleTextWidget
block|{
name|public
operator|:
name|explicit
name|QAccessiblePlainTextEdit
argument_list|(
name|QWidget
operator|*
name|o
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|QAccessible::Text t
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
block|;
name|void
operator|*
name|interface_cast
argument_list|(
argument|QAccessible::InterfaceType t
argument_list|)
block|;
comment|// QAccessibleTextInterface
name|void
name|scrollToSubstring
argument_list|(
argument|int startIndex
argument_list|,
argument|int endIndex
argument_list|)
block|;
name|using
name|QAccessibleTextWidget
operator|::
name|text
block|;
name|protected
operator|:
name|QPlainTextEdit
operator|*
name|plainTextEdit
argument_list|()
specifier|const
block|;
name|QPoint
name|scrollBarPosition
argument_list|()
specifier|const
block|;
name|QTextCursor
name|textCursor
argument_list|()
specifier|const
block|;
name|void
name|setTextCursor
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|textCursor
argument_list|)
block|;
name|QTextDocument
operator|*
name|textDocument
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|viewport
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleTextEdit
range|:
name|public
name|QAccessibleTextWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleTextEdit
argument_list|(
name|QWidget
operator|*
name|o
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|QAccessible::Text t
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
block|;
name|void
operator|*
name|interface_cast
argument_list|(
argument|QAccessible::InterfaceType t
argument_list|)
block|;
comment|// QAccessibleTextInterface
name|void
name|scrollToSubstring
argument_list|(
argument|int startIndex
argument_list|,
argument|int endIndex
argument_list|)
block|;
name|using
name|QAccessibleTextWidget
operator|::
name|text
block|;
name|protected
operator|:
name|QTextEdit
operator|*
name|textEdit
argument_list|()
specifier|const
block|;
name|QPoint
name|scrollBarPosition
argument_list|()
specifier|const
block|;
name|QTextCursor
name|textCursor
argument_list|()
specifier|const
block|;
name|void
name|setTextCursor
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|textCursor
argument_list|)
block|;
name|QTextDocument
operator|*
name|textDocument
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|viewport
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTEDIT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_CURSOR
end_comment
begin_decl_stmt
name|class
name|QAccessibleStackedWidget
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleStackedWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QAccessibleInterface
operator|*
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QStackedWidget
operator|*
name|stackedWidget
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleToolBox
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleToolBox
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
comment|// FIXME we currently expose the toolbox but it is not keyboard navigatable
comment|// and the accessible hierarchy is not exactly beautiful.
comment|//    int childCount() const;
comment|//    QAccessibleInterface *child(int index) const;
comment|//    int indexOfChild(const QAccessibleInterface *child) const;
name|protected
operator|:
name|QToolBox
operator|*
name|toolBox
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MDIAREA
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleMdiArea
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleMdiArea
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QMdiArea
operator|*
name|mdiArea
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleMdiSubWindow
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleMdiSubWindow
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text textType
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|QAccessible::Text textType
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|QRect
name|rect
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QMdiSubWindow
operator|*
name|mdiSubWindow
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MDIAREA
end_comment
begin_decl_stmt
name|class
name|QAccessibleDialogButtonBox
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleDialogButtonBox
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_TEXTBROWSER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_CURSOR
argument_list|)
end_if
begin_decl_stmt
name|class
name|QAccessibleTextBrowser
range|:
name|public
name|QAccessibleTextEdit
block|{
name|public
operator|:
name|explicit
name|QAccessibleTextBrowser
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTBROWSER&& QT_NO_CURSOR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CALENDARWIDGET
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleCalendarWidget
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleCalendarWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QCalendarWidget
operator|*
name|calendarWidget
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QAbstractItemView
operator|*
name|calendarView
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|navigationBar
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CALENDARWIDGET
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleDockWidget
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleDockWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|QRect
name|rect
argument_list|()
specifier|const
block|;
name|QDockWidget
operator|*
name|dockWidget
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleTitleBar
range|:
name|public
name|QAccessibleInterface
block|{
name|public
operator|:
name|explicit
name|QAccessibleTitleBar
argument_list|(
name|QDockWidget
operator|*
name|widget
argument_list|)
block|;
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|QAccessible::Text t
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
block|;
name|QRect
name|rect
argument_list|()
specifier|const
block|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|QPointer
operator|<
name|QDockWidget
operator|>
name|m_dockWidget
block|;
name|QDockWidget
operator|*
name|dockWidget
argument_list|()
specifier|const
block|;
name|QDockWidgetLayout
operator|*
name|dockWidgetLayout
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DOCKWIDGET
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MAINWINDOW
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleMainWindow
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleMainWindow
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *iface
argument_list|)
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QMainWindow
operator|*
name|mainWindow
argument_list|()
specifier|const
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_MAINWINDOW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACESSIBLEWIDGETS_H
end_comment
end_unit
