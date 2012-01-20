begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTDOCUMENT_H
end_ifndef
begin_define
DECL|macro|QTEXTDOCUMENT_H
define|#
directive|define
name|QTEXTDOCUMENT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QTextFormatCollection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextListFormat
name|class
name|QTextListFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPagedPaintDevice
name|class
name|QPagedPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractTextDocumentLayout
name|class
name|QAbstractTextDocumentLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextObject
name|class
name|QTextObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFormat
name|class
name|QTextFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFrame
name|class
name|QTextFrame
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlock
name|class
name|QTextBlock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCodec
name|class
name|QTextCodec
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextOption
name|class
name|QTextOption
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCursor
name|class
name|QTextCursor
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QVector
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QVector
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|namespace
name|Qt
block|{
enum|enum
name|HitTestAccuracy
block|{
name|ExactHit
block|,
name|FuzzyHit
block|}
enum|;
enum|enum
name|WhiteSpaceMode
block|{
name|WhiteSpaceNormal
block|,
name|WhiteSpacePre
block|,
name|WhiteSpaceNoWrap
block|,
name|WhiteSpaceModeUndefined
init|=
operator|-
literal|1
block|}
enum|;
name|Q_GUI_EXPORT
name|bool
name|mightBeRichText
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|Q_GUI_EXPORT
name|QString
name|convertFromPlainText
parameter_list|(
specifier|const
name|QString
modifier|&
name|plain
parameter_list|,
name|WhiteSpaceMode
name|mode
init|=
name|WhiteSpacePre
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|Q_GUI_EXPORT
name|QTextCodec
modifier|*
name|codecForHtml
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAbstractUndoItem
block|{
name|public
label|:
name|virtual
operator|~
name|QAbstractUndoItem
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|undo
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|redo
parameter_list|()
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|~QAbstractUndoItem
specifier|inline
name|QAbstractUndoItem
operator|::
operator|~
name|QAbstractUndoItem
argument_list|()
block|{ }
DECL|variable|QTextDocumentPrivate
name|class
name|QTextDocumentPrivate
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextDocument
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool undoRedoEnabled READ isUndoRedoEnabled WRITE setUndoRedoEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool modified READ isModified WRITE setModified DESIGNABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSizeF pageSize READ pageSize WRITE setPageSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QFont defaultFont READ defaultFont WRITE setDefaultFont
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool useDesignMetrics READ useDesignMetrics WRITE setUseDesignMetrics
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSizeF size READ size
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal textWidth READ textWidth WRITE setTextWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int blockCount READ blockCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal indentWidth READ indentWidth WRITE setIndentWidth
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_CSSPARSER
name|Q_PROPERTY
argument_list|(
argument|QString defaultStyleSheet READ defaultStyleSheet WRITE setDefaultStyleSheet
argument_list|)
endif|#
directive|endif
name|Q_PROPERTY
argument_list|(
argument|int maximumBlockCount READ maximumBlockCount WRITE setMaximumBlockCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal documentMargin READ documentMargin WRITE setDocumentMargin
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QTextOption defaultTextOption READ defaultTextOption WRITE setDefaultTextOption
argument_list|)
name|public
operator|:
name|explicit
name|QTextDocument
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QTextDocument
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
operator|~
name|QTextDocument
argument_list|()
block|;
name|QTextDocument
operator|*
name|clone
argument_list|(
argument|QObject *parent =
literal|0
argument_list|)
specifier|const
block|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|clear
argument_list|()
block|;
name|void
name|setUndoRedoEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isUndoRedoEnabled
argument_list|()
specifier|const
block|;
name|bool
name|isUndoAvailable
argument_list|()
specifier|const
block|;
name|bool
name|isRedoAvailable
argument_list|()
specifier|const
block|;
name|int
name|availableUndoSteps
argument_list|()
specifier|const
block|;
name|int
name|availableRedoSteps
argument_list|()
specifier|const
block|;
name|int
name|revision
argument_list|()
specifier|const
block|;
name|void
name|setDocumentLayout
argument_list|(
name|QAbstractTextDocumentLayout
operator|*
name|layout
argument_list|)
block|;
name|QAbstractTextDocumentLayout
operator|*
name|documentLayout
argument_list|()
specifier|const
block|;      enum
name|MetaInformation
block|{
name|DocumentTitle
block|,
name|DocumentUrl
block|}
block|;
name|void
name|setMetaInformation
argument_list|(
argument|MetaInformation info
argument_list|,
argument|const QString&
argument_list|)
block|;
name|QString
name|metaInformation
argument_list|(
argument|MetaInformation info
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
name|QString
name|toHtml
argument_list|(
argument|const QByteArray&encoding = QByteArray()
argument_list|)
specifier|const
block|;
name|void
name|setHtml
argument_list|(
specifier|const
name|QString
operator|&
name|html
argument_list|)
block|;
endif|#
directive|endif
name|QString
name|toPlainText
argument_list|()
specifier|const
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
name|QChar
name|characterAt
argument_list|(
argument|int pos
argument_list|)
specifier|const
block|;      enum
name|FindFlag
block|{
name|FindBackward
operator|=
literal|0x00001
block|,
name|FindCaseSensitively
operator|=
literal|0x00002
block|,
name|FindWholeWords
operator|=
literal|0x00004
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|FindFlags
argument_list|,
argument|FindFlag
argument_list|)
name|QTextCursor
name|find
argument_list|(
argument|const QString&subString
argument_list|,
argument|int from =
literal|0
argument_list|,
argument|FindFlags options =
literal|0
argument_list|)
specifier|const
block|;
name|QTextCursor
name|find
argument_list|(
argument|const QString&subString
argument_list|,
argument|const QTextCursor&from
argument_list|,
argument|FindFlags options =
literal|0
argument_list|)
specifier|const
block|;
name|QTextCursor
name|find
argument_list|(
argument|const QRegExp&expr
argument_list|,
argument|int from =
literal|0
argument_list|,
argument|FindFlags options =
literal|0
argument_list|)
specifier|const
block|;
name|QTextCursor
name|find
argument_list|(
argument|const QRegExp&expr
argument_list|,
argument|const QTextCursor&from
argument_list|,
argument|FindFlags options =
literal|0
argument_list|)
specifier|const
block|;
name|QTextFrame
operator|*
name|frameAt
argument_list|(
argument|int pos
argument_list|)
specifier|const
block|;
name|QTextFrame
operator|*
name|rootFrame
argument_list|()
specifier|const
block|;
name|QTextObject
operator|*
name|object
argument_list|(
argument|int objectIndex
argument_list|)
specifier|const
block|;
name|QTextObject
operator|*
name|objectForFormat
argument_list|(
argument|const QTextFormat&
argument_list|)
specifier|const
block|;
name|QTextBlock
name|findBlock
argument_list|(
argument|int pos
argument_list|)
specifier|const
block|;
name|QTextBlock
name|findBlockByNumber
argument_list|(
argument|int blockNumber
argument_list|)
specifier|const
block|;
name|QTextBlock
name|findBlockByLineNumber
argument_list|(
argument|int blockNumber
argument_list|)
specifier|const
block|;
name|QTextBlock
name|begin
argument_list|()
specifier|const
block|;
name|QTextBlock
name|end
argument_list|()
specifier|const
block|;
name|QTextBlock
name|firstBlock
argument_list|()
specifier|const
block|;
name|QTextBlock
name|lastBlock
argument_list|()
specifier|const
block|;
name|void
name|setPageSize
argument_list|(
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
block|;
name|QSizeF
name|pageSize
argument_list|()
specifier|const
block|;
name|void
name|setDefaultFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|QFont
name|defaultFont
argument_list|()
specifier|const
block|;
name|int
name|pageCount
argument_list|()
specifier|const
block|;
name|bool
name|isModified
argument_list|()
specifier|const
block|;
name|void
name|print
argument_list|(
argument|QPagedPaintDevice *printer
argument_list|)
specifier|const
block|;      enum
name|ResourceType
block|{
name|HtmlResource
operator|=
literal|1
block|,
name|ImageResource
operator|=
literal|2
block|,
name|StyleSheetResource
operator|=
literal|3
block|,
name|UserResource
operator|=
literal|100
block|}
block|;
name|QVariant
name|resource
argument_list|(
argument|int type
argument_list|,
argument|const QUrl&name
argument_list|)
specifier|const
block|;
name|void
name|addResource
argument_list|(
argument|int type
argument_list|,
argument|const QUrl&name
argument_list|,
argument|const QVariant&resource
argument_list|)
block|;
name|QVector
operator|<
name|QTextFormat
operator|>
name|allFormats
argument_list|()
specifier|const
block|;
name|void
name|markContentsDirty
argument_list|(
argument|int from
argument_list|,
argument|int length
argument_list|)
block|;
name|void
name|setUseDesignMetrics
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|useDesignMetrics
argument_list|()
specifier|const
block|;
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
argument_list|)
block|;
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
name|qreal
name|idealWidth
argument_list|()
specifier|const
block|;
name|qreal
name|indentWidth
argument_list|()
specifier|const
block|;
name|void
name|setIndentWidth
argument_list|(
argument|qreal width
argument_list|)
block|;
name|qreal
name|documentMargin
argument_list|()
specifier|const
block|;
name|void
name|setDocumentMargin
argument_list|(
argument|qreal margin
argument_list|)
block|;
name|void
name|adjustSize
argument_list|()
block|;
name|QSizeF
name|size
argument_list|()
specifier|const
block|;
name|int
name|blockCount
argument_list|()
specifier|const
block|;
name|int
name|lineCount
argument_list|()
specifier|const
block|;
name|int
name|characterCount
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_CSSPARSER
name|void
name|setDefaultStyleSheet
argument_list|(
specifier|const
name|QString
operator|&
name|sheet
argument_list|)
block|;
name|QString
name|defaultStyleSheet
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|undo
argument_list|(
name|QTextCursor
operator|*
name|cursor
argument_list|)
block|;
name|void
name|redo
argument_list|(
name|QTextCursor
operator|*
name|cursor
argument_list|)
block|;      enum
name|Stacks
block|{
name|UndoStack
operator|=
literal|0x01
block|,
name|RedoStack
operator|=
literal|0x02
block|,
name|UndoAndRedoStacks
operator|=
name|UndoStack
operator||
name|RedoStack
block|}
block|;
name|void
name|clearUndoRedoStacks
argument_list|(
argument|Stacks historyToClear = UndoAndRedoStacks
argument_list|)
block|;
name|int
name|maximumBlockCount
argument_list|()
specifier|const
block|;
name|void
name|setMaximumBlockCount
argument_list|(
argument|int maximum
argument_list|)
block|;
name|QTextOption
name|defaultTextOption
argument_list|()
specifier|const
block|;
name|void
name|setDefaultTextOption
argument_list|(
specifier|const
name|QTextOption
operator|&
name|option
argument_list|)
block|;
name|Qt
operator|::
name|CursorMoveStyle
name|defaultCursorMoveStyle
argument_list|()
specifier|const
block|;
name|void
name|setDefaultCursorMoveStyle
argument_list|(
argument|Qt::CursorMoveStyle style
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|contentsChange
argument_list|(
argument|int from
argument_list|,
argument|int charsRemoves
argument_list|,
argument|int charsAdded
argument_list|)
block|;
name|void
name|contentsChanged
argument_list|()
block|;
name|void
name|undoAvailable
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|redoAvailable
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|undoCommandAdded
argument_list|()
block|;
name|void
name|modificationChanged
argument_list|(
argument|bool m
argument_list|)
block|;
name|void
name|cursorPositionChanged
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|cursor
argument_list|)
block|;
name|void
name|blockCountChanged
argument_list|(
argument|int newBlockCount
argument_list|)
block|;
name|void
name|documentLayoutChanged
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|undo
argument_list|()
block|;
name|void
name|redo
argument_list|()
block|;
name|void
name|appendUndoItem
argument_list|(
name|QAbstractUndoItem
operator|*
argument_list|)
block|;
name|void
name|setModified
argument_list|(
argument|bool m = true
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|QTextObject
operator|*
name|createObject
argument_list|(
specifier|const
name|QTextFormat
operator|&
name|f
argument_list|)
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
name|QTextDocument
argument_list|(
name|QTextDocumentPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|public
operator|:
name|QTextDocumentPrivate
operator|*
name|docHandle
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTextDocument
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTextDocument
argument_list|)
name|friend
name|class
name|QTextObjectPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QTextDocument::FindFlags
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
comment|// QTEXTDOCUMENT_H
end_comment
end_unit
