begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qtextdocument.h>
end_include
begin_include
include|#
directive|include
file|<qabstracttextdocumentlayout.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qtexttable.h>
end_include
begin_include
include|#
directive|include
file|<qtextedit.h>
end_include
begin_include
include|#
directive|include
file|<qscrollbar.h>
end_include
begin_class
DECL|class|tst_QTextDocumentLayout
class|class
name|tst_QTextDocumentLayout
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QTextDocumentLayout
specifier|inline
name|tst_QTextDocumentLayout
parameter_list|()
block|{}
DECL|function|~tst_QTextDocumentLayout
specifier|virtual
name|~
name|tst_QTextDocumentLayout
parameter_list|()
block|{}
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|defaultPageSizeHandling
parameter_list|()
function_decl|;
name|void
name|idealWidth
parameter_list|()
function_decl|;
name|void
name|lineSeparatorFollowingTable
parameter_list|()
function_decl|;
name|void
name|wrapAtWordBoundaryOrAnywhere
parameter_list|()
function_decl|;
name|void
name|inlineImage
parameter_list|()
function_decl|;
name|void
name|clippedTableCell
parameter_list|()
function_decl|;
name|void
name|floatingTablePageBreak
parameter_list|()
function_decl|;
private|private:
DECL|member|doc
name|QTextDocument
modifier|*
name|doc
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|tst_QTextDocumentLayout
operator|::
name|init
parameter_list|()
block|{
name|doc
operator|=
operator|new
name|QTextDocument
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QTextDocumentLayout
operator|::
name|cleanup
parameter_list|()
block|{
operator|delete
name|doc
expr_stmt|;
name|doc
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QTextDocumentLayout
operator|::
name|cleanupTestCase
parameter_list|()
block|{
if|if
condition|(
name|qgetenv
argument_list|(
literal|"QTEST_KEEP_IMAGEDATA"
argument_list|)
operator|.
name|toInt
argument_list|()
operator|==
literal|0
condition|)
block|{
name|QFile
operator|::
name|remove
argument_list|(
name|QLatin1String
argument_list|(
literal|"expected.png"
argument_list|)
argument_list|)
expr_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|QLatin1String
argument_list|(
literal|"img.png"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|defaultPageSizeHandling
name|void
name|tst_QTextDocumentLayout
operator|::
name|defaultPageSizeHandling
parameter_list|()
block|{
name|QAbstractTextDocumentLayout
modifier|*
name|layout
init|=
name|doc
operator|->
name|documentLayout
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|doc
operator|->
name|pageSize
argument_list|()
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QSizeF
name|docSize
init|=
name|layout
operator|->
name|documentSize
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|docSize
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|docSize
operator|.
name|width
argument_list|()
operator|<
literal|1000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|docSize
operator|.
name|height
argument_list|()
operator|>
literal|0
operator|&&
name|docSize
operator|.
name|height
argument_list|()
operator|<
literal|1000
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setPlainText
argument_list|(
literal|"Some text\nwith a few lines\nand not real information\nor anything otherwise useful"
argument_list|)
expr_stmt|;
name|docSize
operator|=
name|layout
operator|->
name|documentSize
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|docSize
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|docSize
operator|.
name|width
argument_list|()
operator|!=
name|INT_MAX
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|docSize
operator|.
name|height
argument_list|()
operator|!=
name|INT_MAX
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|idealWidth
name|void
name|tst_QTextDocumentLayout
operator|::
name|idealWidth
parameter_list|()
block|{
name|doc
operator|->
name|setPlainText
argument_list|(
literal|"Some text\nwith a few lines\nand not real information\nor anything otherwise useful"
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setTextWidth
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doc
operator|->
name|textWidth
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doc
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|doc
operator|->
name|textWidth
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|doc
operator|->
name|idealWidth
argument_list|()
operator|<
name|doc
operator|->
name|textWidth
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|doc
operator|->
name|idealWidth
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QTextBlockFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignAbsolute
argument_list|)
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|select
argument_list|(
name|QTextCursor
operator|::
name|Document
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|mergeBlockFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doc
operator|->
name|textWidth
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doc
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|doc
operator|->
name|textWidth
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|doc
operator|->
name|idealWidth
argument_list|()
operator|<
name|doc
operator|->
name|textWidth
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|doc
operator|->
name|idealWidth
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// none of the QTextLine items in the document should intersect with the margin rect
end_comment
begin_function
DECL|function|lineSeparatorFollowingTable
name|void
name|tst_QTextDocumentLayout
operator|::
name|lineSeparatorFollowingTable
parameter_list|()
block|{
name|QString
name|html_begin
argument_list|(
literal|"<html><table border=1><tr><th>Column 1</th></tr><tr><td>Data</td></tr></table><br>"
argument_list|)
decl_stmt|;
name|QString
name|html_text
argument_list|(
literal|"bla bla bla bla bla bla bla bla<br>"
argument_list|)
decl_stmt|;
name|QString
name|html_end
argument_list|(
literal|"<table border=1><tr><th>Column 1</th></tr><tr><td>Data</td></tr></table></html>"
argument_list|)
decl_stmt|;
name|QString
name|html
init|=
name|html_begin
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|80
condition|;
operator|++
name|i
control|)
name|html
operator|+=
name|html_text
expr_stmt|;
name|html
operator|+=
name|html_end
expr_stmt|;
name|doc
operator|->
name|setHtml
argument_list|(
name|html
argument_list|)
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
specifier|const
name|int
name|margin
init|=
literal|87
decl_stmt|;
specifier|const
name|int
name|pageWidth
init|=
literal|873
decl_stmt|;
specifier|const
name|int
name|pageHeight
init|=
literal|1358
decl_stmt|;
name|QTextFrameFormat
name|fmt
init|=
name|doc
operator|->
name|rootFrame
argument_list|()
operator|->
name|frameFormat
argument_list|()
decl_stmt|;
name|fmt
operator|.
name|setMargin
argument_list|(
name|margin
argument_list|)
expr_stmt|;
name|doc
operator|->
name|rootFrame
argument_list|()
operator|->
name|setFrameFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|QFont
name|font
argument_list|(
name|doc
operator|->
name|defaultFont
argument_list|()
argument_list|)
decl_stmt|;
name|font
operator|.
name|setPointSize
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setDefaultFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setPageSize
argument_list|(
name|QSizeF
argument_list|(
name|pageWidth
argument_list|,
name|pageHeight
argument_list|)
argument_list|)
expr_stmt|;
name|QRectF
name|marginRect
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
name|pageHeight
operator|-
name|margin
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
name|pageWidth
argument_list|,
literal|2
operator|*
name|margin
argument_list|)
argument_list|)
decl_stmt|;
comment|// force layouting
name|doc
operator|->
name|pageCount
argument_list|()
expr_stmt|;
for|for
control|(
name|QTextBlock
name|block
init|=
name|doc
operator|->
name|begin
argument_list|()
init|;
name|block
operator|!=
name|doc
operator|->
name|end
argument_list|()
condition|;
name|block
operator|=
name|block
operator|.
name|next
argument_list|()
control|)
block|{
name|QTextLayout
modifier|*
name|layout
init|=
name|block
operator|.
name|layout
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|layout
operator|->
name|lineCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QTextLine
name|line
init|=
name|layout
operator|->
name|lineAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QRectF
name|rect
init|=
name|line
operator|.
name|rect
argument_list|()
operator|.
name|translated
argument_list|(
name|layout
operator|->
name|position
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|rect
operator|.
name|intersects
argument_list|(
name|marginRect
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|wrapAtWordBoundaryOrAnywhere
name|void
name|tst_QTextDocumentLayout
operator|::
name|wrapAtWordBoundaryOrAnywhere
parameter_list|()
block|{
comment|//task 150562
name|QTextEdit
name|edit
decl_stmt|;
name|edit
operator|.
name|setText
argument_list|(
literal|"<table><tr><td>hello hello hello"
literal|"thisisabigwordthisisabigwordthisisabigwordthisisabigwordthisisabigword"
literal|"hello hello hello</td></tr></table>"
argument_list|)
expr_stmt|;
name|edit
operator|.
name|setWordWrapMode
argument_list|(
name|QTextOption
operator|::
name|WrapAtWordBoundaryOrAnywhere
argument_list|)
expr_stmt|;
name|edit
operator|.
name|resize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|edit
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|edit
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|inlineImage
name|void
name|tst_QTextDocumentLayout
operator|::
name|inlineImage
parameter_list|()
block|{
name|doc
operator|->
name|setPageSize
argument_list|(
name|QSizeF
argument_list|(
literal|800
argument_list|,
literal|500
argument_list|)
argument_list|)
expr_stmt|;
name|QImage
name|img
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|QLatin1String
name|name
argument_list|(
literal|"bigImage"
argument_list|)
decl_stmt|;
name|doc
operator|->
name|addResource
argument_list|(
name|QTextDocument
operator|::
name|ImageResource
argument_list|,
name|QUrl
argument_list|(
name|name
argument_list|)
argument_list|,
name|img
argument_list|)
expr_stmt|;
name|QTextImageFormat
name|imgFormat
decl_stmt|;
name|imgFormat
operator|.
name|setName
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|imgFormat
operator|.
name|setWidth
argument_list|(
name|img
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QTextFrameFormat
name|fmt
init|=
name|doc
operator|->
name|rootFrame
argument_list|()
operator|->
name|frameFormat
argument_list|()
decl_stmt|;
name|qreal
name|height
init|=
name|doc
operator|->
name|pageSize
argument_list|()
operator|.
name|height
argument_list|()
operator|-
name|fmt
operator|.
name|topMargin
argument_list|()
operator|-
name|fmt
operator|.
name|bottomMargin
argument_list|()
decl_stmt|;
name|imgFormat
operator|.
name|setHeight
argument_list|(
name|height
argument_list|)
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertImage
argument_list|(
name|imgFormat
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doc
operator|->
name|pageCount
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clippedTableCell
name|void
name|tst_QTextDocumentLayout
operator|::
name|clippedTableCell
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|html
init|=
literal|"<table style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
literal|"border=\"0\" margin=\"0\" cellpadding=\"0\" cellspacing=\"0\"><tr><td></td></tr></table>"
decl_stmt|;
name|doc
operator|->
name|setHtml
argument_list|(
name|html
argument_list|)
expr_stmt|;
name|doc
operator|->
name|pageSize
argument_list|()
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Right
argument_list|)
expr_stmt|;
name|QTextTable
modifier|*
name|table
init|=
name|cursor
operator|.
name|currentTable
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|QTextCursor
name|cellCursor
init|=
name|table
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
decl_stmt|;
name|QImage
name|src
argument_list|(
literal|16
argument_list|,
literal|16
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|src
operator|.
name|fill
argument_list|(
literal|0xffff0000
argument_list|)
expr_stmt|;
name|cellCursor
operator|.
name|insertImage
argument_list|(
name|src
argument_list|)
expr_stmt|;
name|QTextBlock
name|block
init|=
name|cellCursor
operator|.
name|block
argument_list|()
decl_stmt|;
name|QRectF
name|r
init|=
name|doc
operator|->
name|documentLayout
argument_list|()
operator|->
name|blockBoundingRect
argument_list|(
name|block
argument_list|)
decl_stmt|;
name|QRectF
name|rect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|r
operator|.
name|left
argument_list|()
operator|+
literal|1
argument_list|,
literal|64
argument_list|)
decl_stmt|;
name|QImage
name|img
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|img
operator|.
name|fill
argument_list|(
literal|0x0
argument_list|)
expr_stmt|;
name|QImage
name|expected
init|=
name|img
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|doc
operator|->
name|drawContents
argument_list|(
operator|&
name|p
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|expected
argument_list|)
expr_stmt|;
name|r
operator|.
name|setWidth
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|r
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|img
operator|.
name|save
argument_list|(
literal|"img.png"
argument_list|)
expr_stmt|;
name|expected
operator|.
name|save
argument_list|(
literal|"expected.png"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|img
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|floatingTablePageBreak
name|void
name|tst_QTextDocumentLayout
operator|::
name|floatingTablePageBreak
parameter_list|()
block|{
name|doc
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|QTextTableFormat
name|tableFormat
decl_stmt|;
name|tableFormat
operator|.
name|setPosition
argument_list|(
name|QTextFrameFormat
operator|::
name|FloatLeft
argument_list|)
expr_stmt|;
name|QTextTable
modifier|*
name|table
init|=
name|cursor
operator|.
name|insertTable
argument_list|(
literal|50
argument_list|,
literal|1
argument_list|,
name|tableFormat
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|table
argument_list|)
expr_stmt|;
comment|// Make height of document 2/3 of the table, fitting the table into two pages
name|QSizeF
name|documentSize
init|=
name|doc
operator|->
name|size
argument_list|()
decl_stmt|;
name|documentSize
operator|.
name|rheight
argument_list|()
operator|*=
literal|2.0
operator|/
literal|3.0
expr_stmt|;
name|doc
operator|->
name|setPageSize
argument_list|(
name|documentSize
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doc
operator|->
name|pageCount
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTextDocumentLayout
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtextdocumentlayout.moc"
end_include
end_unit
