begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTEDIT_H
end_ifndef
begin_define
DECL|macro|QTEXTEDIT_H
define|#
directive|define
name|QTEXTEDIT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractscrollarea.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextdocument.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextoption.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextformat.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QStyleSheet
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocument
name|class
name|QTextDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextEditPrivate
name|class
name|QTextEditPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPagedPaintDevice
name|class
name|QPagedPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTextEdit
range|:
name|public
name|QAbstractScrollArea
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTextEdit
argument_list|)
name|Q_FLAGS
argument_list|(
argument|AutoFormatting
argument_list|)
name|Q_ENUMS
argument_list|(
argument|LineWrapMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|AutoFormatting autoFormatting READ autoFormatting WRITE setAutoFormatting
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tabChangesFocus READ tabChangesFocus WRITE setTabChangesFocus
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString documentTitle READ documentTitle WRITE setDocumentTitle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool undoRedoEnabled READ isUndoRedoEnabled WRITE setUndoRedoEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|LineWrapMode lineWrapMode READ lineWrapMode WRITE setLineWrapMode
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QTextOption::WrapMode wordWrapMode READ wordWrapMode WRITE setWordWrapMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int lineWrapColumnOrWidth READ lineWrapColumnOrWidth WRITE setLineWrapColumnOrWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool readOnly READ isReadOnly WRITE setReadOnly
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
name|Q_PROPERTY
argument_list|(
argument|QString html READ toHtml WRITE setHtml NOTIFY textChanged USER true
argument_list|)
endif|#
directive|endif
name|Q_PROPERTY
argument_list|(
argument|QString plainText READ toPlainText WRITE setPlainText DESIGNABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool overwriteMode READ overwriteMode WRITE setOverwriteMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int tabStopWidth READ tabStopWidth WRITE setTabStopWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool acceptRichText READ acceptRichText WRITE setAcceptRichText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int cursorWidth READ cursorWidth WRITE setCursorWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextInteractionFlags textInteractionFlags READ textInteractionFlags WRITE setTextInteractionFlags
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QObject *document READ document
argument_list|)
name|public
operator|:
expr|enum
name|LineWrapMode
block|{
name|NoWrap
block|,
name|WidgetWidth
block|,
name|FixedPixelWidth
block|,
name|FixedColumnWidth
block|}
block|;      enum
name|AutoFormattingFlag
block|{
name|AutoNone
operator|=
literal|0
block|,
name|AutoBulletList
operator|=
literal|0x00000001
block|,
name|AutoAll
operator|=
literal|0xffffffff
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|AutoFormatting
argument_list|,
argument|AutoFormattingFlag
argument_list|)
name|explicit
name|QTextEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QTextEdit
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QTextEdit
argument_list|()
block|;
name|void
name|setDocument
argument_list|(
name|QTextDocument
operator|*
name|document
argument_list|)
block|;
name|QTextDocument
operator|*
name|document
argument_list|()
specifier|const
block|;
name|void
name|setTextCursor
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|cursor
argument_list|)
block|;
name|QTextCursor
name|textCursor
argument_list|()
specifier|const
block|;
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|;
name|void
name|setReadOnly
argument_list|(
argument|bool ro
argument_list|)
block|;
name|void
name|setTextInteractionFlags
argument_list|(
argument|Qt::TextInteractionFlags flags
argument_list|)
block|;
name|Qt
operator|::
name|TextInteractionFlags
name|textInteractionFlags
argument_list|()
specifier|const
block|;
name|qreal
name|fontPointSize
argument_list|()
specifier|const
block|;
name|QString
name|fontFamily
argument_list|()
specifier|const
block|;
name|int
name|fontWeight
argument_list|()
specifier|const
block|;
name|bool
name|fontUnderline
argument_list|()
specifier|const
block|;
name|bool
name|fontItalic
argument_list|()
specifier|const
block|;
name|QColor
name|textColor
argument_list|()
specifier|const
block|;
name|QColor
name|textBackgroundColor
argument_list|()
specifier|const
block|;
name|QFont
name|currentFont
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|;
name|void
name|mergeCurrentCharFormat
argument_list|(
specifier|const
name|QTextCharFormat
operator|&
name|modifier
argument_list|)
block|;
name|void
name|setCurrentCharFormat
argument_list|(
specifier|const
name|QTextCharFormat
operator|&
name|format
argument_list|)
block|;
name|QTextCharFormat
name|currentCharFormat
argument_list|()
specifier|const
block|;
name|AutoFormatting
name|autoFormatting
argument_list|()
specifier|const
block|;
name|void
name|setAutoFormatting
argument_list|(
argument|AutoFormatting features
argument_list|)
block|;
name|bool
name|tabChangesFocus
argument_list|()
specifier|const
block|;
name|void
name|setTabChangesFocus
argument_list|(
argument|bool b
argument_list|)
block|;
specifier|inline
name|void
name|setDocumentTitle
argument_list|(
argument|const QString&title
argument_list|)
block|{
name|document
argument_list|()
operator|->
name|setMetaInformation
argument_list|(
name|QTextDocument
operator|::
name|DocumentTitle
argument_list|,
name|title
argument_list|)
block|; }
specifier|inline
name|QString
name|documentTitle
argument_list|()
specifier|const
block|{
return|return
name|document
argument_list|()
operator|->
name|metaInformation
argument_list|(
name|QTextDocument
operator|::
name|DocumentTitle
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isUndoRedoEnabled
argument_list|()
specifier|const
block|{
return|return
name|document
argument_list|()
operator|->
name|isUndoRedoEnabled
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setUndoRedoEnabled
argument_list|(
argument|bool enable
argument_list|)
block|{
name|document
argument_list|()
operator|->
name|setUndoRedoEnabled
argument_list|(
name|enable
argument_list|)
block|; }
name|LineWrapMode
name|lineWrapMode
argument_list|()
specifier|const
block|;
name|void
name|setLineWrapMode
argument_list|(
argument|LineWrapMode mode
argument_list|)
block|;
name|int
name|lineWrapColumnOrWidth
argument_list|()
specifier|const
block|;
name|void
name|setLineWrapColumnOrWidth
argument_list|(
argument|int w
argument_list|)
block|;
name|QTextOption
operator|::
name|WrapMode
name|wordWrapMode
argument_list|()
specifier|const
block|;
name|void
name|setWordWrapMode
argument_list|(
argument|QTextOption::WrapMode policy
argument_list|)
block|;
name|bool
name|find
argument_list|(
argument|const QString&exp
argument_list|,
argument|QTextDocument::FindFlags options =
literal|0
argument_list|)
block|;
name|QString
name|toPlainText
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
name|QString
name|toHtml
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|ensureCursorVisible
argument_list|()
block|;
name|virtual
name|QVariant
name|loadResource
argument_list|(
argument|int type
argument_list|,
argument|const QUrl&name
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|QMenu
operator|*
name|createStandardContextMenu
argument_list|()
block|;
name|QMenu
operator|*
name|createStandardContextMenu
argument_list|(
specifier|const
name|QPoint
operator|&
name|position
argument_list|)
block|;
endif|#
directive|endif
name|QTextCursor
name|cursorForPosition
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|QRect
name|cursorRect
argument_list|(
argument|const QTextCursor&cursor
argument_list|)
specifier|const
block|;
name|QRect
name|cursorRect
argument_list|()
specifier|const
block|;
name|QString
name|anchorAt
argument_list|(
argument|const QPoint& pos
argument_list|)
specifier|const
block|;
name|bool
name|overwriteMode
argument_list|()
specifier|const
block|;
name|void
name|setOverwriteMode
argument_list|(
argument|bool overwrite
argument_list|)
block|;
name|int
name|tabStopWidth
argument_list|()
specifier|const
block|;
name|void
name|setTabStopWidth
argument_list|(
argument|int width
argument_list|)
block|;
name|int
name|cursorWidth
argument_list|()
specifier|const
block|;
name|void
name|setCursorWidth
argument_list|(
argument|int width
argument_list|)
block|;
name|bool
name|acceptRichText
argument_list|()
specifier|const
block|;
name|void
name|setAcceptRichText
argument_list|(
argument|bool accept
argument_list|)
block|;      struct
name|ExtraSelection
block|{
name|QTextCursor
name|cursor
block|;
name|QTextCharFormat
name|format
block|;     }
block|;
name|void
name|setExtraSelections
argument_list|(
specifier|const
name|QList
operator|<
name|ExtraSelection
operator|>
operator|&
name|selections
argument_list|)
block|;
name|QList
operator|<
name|ExtraSelection
operator|>
name|extraSelections
argument_list|()
specifier|const
block|;
name|void
name|moveCursor
argument_list|(
argument|QTextCursor::MoveOperation operation
argument_list|,
argument|QTextCursor::MoveMode mode = QTextCursor::MoveAnchor
argument_list|)
block|;
name|bool
name|canPaste
argument_list|()
specifier|const
block|;
name|void
name|print
argument_list|(
argument|QPagedPaintDevice *printer
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setFontPointSize
argument_list|(
argument|qreal s
argument_list|)
block|;
name|void
name|setFontFamily
argument_list|(
specifier|const
name|QString
operator|&
name|fontFamily
argument_list|)
block|;
name|void
name|setFontWeight
argument_list|(
argument|int w
argument_list|)
block|;
name|void
name|setFontUnderline
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|setFontItalic
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|setTextColor
argument_list|(
specifier|const
name|QColor
operator|&
name|c
argument_list|)
block|;
name|void
name|setTextBackgroundColor
argument_list|(
specifier|const
name|QColor
operator|&
name|c
argument_list|)
block|;
name|void
name|setCurrentFont
argument_list|(
specifier|const
name|QFont
operator|&
name|f
argument_list|)
block|;
name|void
name|setAlignment
argument_list|(
argument|Qt::Alignment a
argument_list|)
block|;
name|void
name|setPlainText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
name|void
name|setHtml
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
endif|#
directive|endif
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|void
name|cut
argument_list|()
block|;
name|void
name|copy
argument_list|()
block|;
name|void
name|paste
argument_list|()
block|;
endif|#
directive|endif
name|void
name|undo
argument_list|()
block|;
name|void
name|redo
argument_list|()
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|selectAll
argument_list|()
block|;
name|void
name|insertPlainText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
name|void
name|insertHtml
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_TEXTHTMLPARSER
name|void
name|append
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|scrollToAnchor
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|void
name|zoomIn
argument_list|(
argument|int range =
literal|1
argument_list|)
block|;
name|void
name|zoomOut
argument_list|(
argument|int range =
literal|1
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|textChanged
argument_list|()
block|;
name|void
name|undoAvailable
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|redoAvailable
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|currentCharFormatChanged
argument_list|(
specifier|const
name|QTextCharFormat
operator|&
name|format
argument_list|)
block|;
name|void
name|copyAvailable
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|selectionChanged
argument_list|()
block|;
name|void
name|cursorPositionChanged
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|keyReleaseEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|virtual
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|virtual
name|void
name|dragEnterEvent
argument_list|(
name|QDragEnterEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|dragLeaveEvent
argument_list|(
name|QDragLeaveEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|dragMoveEvent
argument_list|(
name|QDragMoveEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|dropEvent
argument_list|(
name|QDropEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|virtual
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|virtual
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|virtual
name|QMimeData
operator|*
name|createMimeDataFromSelection
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|canInsertFromMimeData
argument_list|(
argument|const QMimeData *source
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|insertFromMimeData
argument_list|(
specifier|const
name|QMimeData
operator|*
name|source
argument_list|)
block|;
name|virtual
name|void
name|inputMethodEvent
argument_list|(
name|QInputMethodEvent
operator|*
argument_list|)
block|;
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery property
argument_list|)
specifier|const
block|;
name|QTextEdit
argument_list|(
name|QTextEditPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|virtual
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTextEdit
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_repaintContents(const QRectF&r)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_currentCharFormatChanged(const QTextCharFormat&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_adjustScrollbars()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_ensureVisible(const QRectF&)
argument_list|)
name|friend
name|class
name|QTextEditControl
block|;
name|friend
name|class
name|QTextDocument
block|;
name|friend
name|class
name|QWidgetTextControl
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QTextEdit::AutoFormatting
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
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
comment|// QTEXTEDIT_H
end_comment
end_unit
