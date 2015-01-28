begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWIDGETTEXTCONTROL_P_H
end_ifndef
begin_define
DECL|macro|QWIDGETTEXTCONTROL_P_H
define|#
directive|define
name|QWIDGETTEXTCONTROL_P_H
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
begin_include
include|#
directive|include
file|<QtWidgets/qtextedit.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qmenu.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qabstracttextdocumentlayout.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextdocumentfragment.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qclipboard.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmimedata.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStyleSheet
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
DECL|variable|QWidgetTextControlPrivate
name|class
name|QWidgetTextControlPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractScrollArea
name|class
name|QAbstractScrollArea
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimerEvent
name|class
name|QTimerEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QWidgetTextControl
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWidgetTextControl
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
argument|bool overwriteMode READ overwriteMode WRITE setOverwriteMode
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
argument|bool openExternalLinks READ openExternalLinks WRITE setOpenExternalLinks
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool ignoreUnusedNavigationEvents READ ignoreUnusedNavigationEvents WRITE setIgnoreUnusedNavigationEvents
argument_list|)
name|public
operator|:
name|explicit
name|QWidgetTextControl
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QWidgetTextControl
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QWidgetTextControl
argument_list|(
name|QTextDocument
operator|*
name|doc
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QWidgetTextControl
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
name|bool
name|find
argument_list|(
argument|const QString&exp
argument_list|,
argument|QTextDocument::FindFlags options =
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
name|bool
name|find
argument_list|(
argument|const QRegExp&exp
argument_list|,
argument|QTextDocument::FindFlags options =
literal|0
argument_list|)
block|;
endif|#
directive|endif
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
name|virtual
name|void
name|ensureCursorVisible
argument_list|()
block|;
name|Q_INVOKABLE
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
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
endif|#
directive|endif
name|QTextCursor
name|cursorForPosition
argument_list|(
argument|const QPointF&pos
argument_list|)
specifier|const
block|;
name|QRectF
name|cursorRect
argument_list|(
argument|const QTextCursor&cursor
argument_list|)
specifier|const
block|;
name|QRectF
name|cursorRect
argument_list|()
specifier|const
block|;
name|QRectF
name|selectionRect
argument_list|(
argument|const QTextCursor&cursor
argument_list|)
specifier|const
block|;
name|QRectF
name|selectionRect
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|anchorAt
argument_list|(
argument|const QPointF&pos
argument_list|)
specifier|const
block|;
name|QPointF
name|anchorPosition
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QString
name|anchorAtCursor
argument_list|()
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
block|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
name|void
name|setExtraSelections
argument_list|(
specifier|const
name|QList
operator|<
name|QTextEdit
operator|::
name|ExtraSelection
operator|>
operator|&
name|selections
argument_list|)
block|;
name|QList
operator|<
name|QTextEdit
operator|::
name|ExtraSelection
operator|>
name|extraSelections
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setTextWidth
argument_list|(
argument|qreal width
argument_list|)
block|;
name|qreal
name|textWidth
argument_list|()
specifier|const
block|;
name|QSizeF
name|size
argument_list|()
specifier|const
block|;
name|void
name|setOpenExternalLinks
argument_list|(
argument|bool open
argument_list|)
block|;
name|bool
name|openExternalLinks
argument_list|()
specifier|const
block|;
name|void
name|setIgnoreUnusedNavigationEvents
argument_list|(
argument|bool ignore
argument_list|)
block|;
name|bool
name|ignoreUnusedNavigationEvents
argument_list|()
specifier|const
block|;
name|void
name|moveCursor
argument_list|(
argument|QTextCursor::MoveOperation op
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
name|setCursorIsFocusIndicator
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|cursorIsFocusIndicator
argument_list|()
specifier|const
block|;
name|void
name|setDragEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isDragEnabled
argument_list|()
specifier|const
block|;
name|bool
name|isWordSelectionEnabled
argument_list|()
specifier|const
block|;
name|void
name|setWordSelectionEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|print
argument_list|(
argument|QPagedPaintDevice *printer
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|hitTest
argument_list|(
argument|const QPointF&point
argument_list|,
argument|Qt::HitTestAccuracy accuracy
argument_list|)
specifier|const
block|;
name|virtual
name|QRectF
name|blockBoundingRect
argument_list|(
argument|const QTextBlock&block
argument_list|)
specifier|const
block|;
name|QAbstractTextDocumentLayout
operator|::
name|PaintContext
name|getPaintContext
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setPlainText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|setHtml
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
argument_list|(
argument|QClipboard::Mode mode = QClipboard::Clipboard
argument_list|)
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
name|appendHtml
argument_list|(
specifier|const
name|QString
operator|&
name|html
argument_list|)
block|;
name|void
name|appendPlainText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|adjustSize
argument_list|()
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
comment|// control signals
name|void
name|updateRequest
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
operator|=
name|QRectF
argument_list|()
argument_list|)
block|;
name|void
name|documentSizeChanged
argument_list|(
specifier|const
name|QSizeF
operator|&
argument_list|)
block|;
name|void
name|blockCountChanged
argument_list|(
argument|int newBlockCount
argument_list|)
block|;
name|void
name|visibilityRequest
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|void
name|microFocusChanged
argument_list|()
block|;
name|void
name|linkActivated
argument_list|(
specifier|const
name|QString
operator|&
name|link
argument_list|)
block|;
name|void
name|linkHovered
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|modificationChanged
argument_list|(
argument|bool m
argument_list|)
block|;
name|public
operator|:
comment|// control properties
name|QPalette
name|palette
argument_list|()
specifier|const
block|;
name|void
name|setPalette
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
block|;
name|virtual
name|void
name|processEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|,
specifier|const
name|QMatrix
operator|&
name|matrix
argument_list|,
name|QWidget
operator|*
name|contextWidget
operator|=
literal|0
argument_list|)
block|;
name|void
name|processEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|,
specifier|const
name|QPointF
operator|&
name|coordinateOffset
operator|=
name|QPointF
argument_list|()
argument_list|,
name|QWidget
operator|*
name|contextWidget
operator|=
literal|0
argument_list|)
block|;
comment|// control methods
name|void
name|drawContents
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRectF
operator|&
name|rect
operator|=
name|QRectF
argument_list|()
argument_list|,
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
block|;
name|void
name|setFocus
argument_list|(
argument|bool focus
argument_list|,
argument|Qt::FocusReason = Qt::OtherFocusReason
argument_list|)
block|;
name|virtual
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery property
argument_list|,
argument|QVariant argument
argument_list|)
specifier|const
block|;
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
name|bool
name|setFocusToAnchor
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|newCursor
argument_list|)
block|;
name|bool
name|setFocusToNextOrPreviousAnchor
argument_list|(
argument|bool next
argument_list|)
block|;
name|bool
name|findNextPrevAnchor
argument_list|(
argument|const QTextCursor& from
argument_list|,
argument|bool next
argument_list|,
argument|QTextCursor& newAnchor
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWidgetTextControl
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateCurrentCharFormatAndSelection()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitCursorPosChanged(const QTextCursor&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_deleteSelected()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_copyLink()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateBlock(const QTextBlock&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_documentLayoutChanged()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_contentsChanged(int, int, int)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
end_ifndef
begin_decl_stmt
name|class
name|QUnicodeControlCharacterMenu
range|:
name|public
name|QMenu
block|{
name|Q_OBJECT
name|public
operator|:
name|QUnicodeControlCharacterMenu
argument_list|(
name|QObject
operator|*
name|editWidget
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|menuActionTriggered
argument_list|()
block|;
name|private
operator|:
name|QObject
operator|*
name|editWidget
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONTEXTMENU
end_comment
begin_comment
comment|// also used by QLabel
end_comment
begin_decl_stmt
name|class
name|QTextEditMimeData
range|:
name|public
name|QMimeData
block|{
name|public
operator|:
specifier|inline
name|QTextEditMimeData
argument_list|(
specifier|const
name|QTextDocumentFragment
operator|&
name|aFragment
argument_list|)
operator|:
name|fragment
argument_list|(
argument|aFragment
argument_list|)
block|{}
name|virtual
name|QStringList
name|formats
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|virtual
name|QVariant
name|retrieveData
argument_list|(
argument|const QString&mimeType
argument_list|,
argument|QVariant::Type type
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|setup
argument_list|()
specifier|const
block|;
name|mutable
name|QTextDocumentFragment
name|fragment
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWidgetTextControl_H
end_comment
end_unit
