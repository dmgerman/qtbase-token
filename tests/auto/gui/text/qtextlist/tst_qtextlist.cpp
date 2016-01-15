begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qtextdocumentfragment.h>
end_include
begin_include
include|#
directive|include
file|<qtextlist.h>
end_include
begin_include
include|#
directive|include
file|<qabstracttextdocumentlayout.h>
end_include
begin_include
include|#
directive|include
file|<qtextcursor.h>
end_include
begin_include
include|#
directive|include
file|"../qtextdocument/common.h"
end_include
begin_class
DECL|class|tst_QTextList
class|class
name|tst_QTextList
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|item
parameter_list|()
function_decl|;
name|void
name|autoNumbering
parameter_list|()
function_decl|;
name|void
name|autoNumberingRTL
parameter_list|()
function_decl|;
name|void
name|autoNumberingPrefixAndSuffix
parameter_list|()
function_decl|;
name|void
name|autoNumberingPrefixAndSuffixRTL
parameter_list|()
function_decl|;
name|void
name|autoNumberingPrefixAndSuffixHtmlExportImport
parameter_list|()
function_decl|;
name|void
name|romanNumbering
parameter_list|()
function_decl|;
name|void
name|romanNumberingLimit
parameter_list|()
function_decl|;
name|void
name|formatChange
parameter_list|()
function_decl|;
name|void
name|cursorNavigation
parameter_list|()
function_decl|;
name|void
name|partialRemoval
parameter_list|()
function_decl|;
name|void
name|formatReferenceChange
parameter_list|()
function_decl|;
name|void
name|ensureItemOrder
parameter_list|()
function_decl|;
name|void
name|add
parameter_list|()
function_decl|;
name|void
name|defaultIndent
parameter_list|()
function_decl|;
name|void
name|blockUpdate
parameter_list|()
function_decl|;
name|void
name|numbering_data
parameter_list|()
function_decl|;
name|void
name|numbering
parameter_list|()
function_decl|;
private|private:
DECL|member|doc
name|QTextDocument
modifier|*
name|doc
decl_stmt|;
DECL|member|cursor
name|QTextCursor
name|cursor
decl_stmt|;
DECL|member|layout
name|QTestDocumentLayout
modifier|*
name|layout
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|tst_QTextList
operator|::
name|init
parameter_list|()
block|{
name|doc
operator|=
operator|new
name|QTextDocument
argument_list|()
expr_stmt|;
name|layout
operator|=
operator|new
name|QTestDocumentLayout
argument_list|(
name|doc
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setDocumentLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|QTextCursor
argument_list|(
name|doc
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QTextList
operator|::
name|cleanup
parameter_list|()
block|{
name|cursor
operator|=
name|QTextCursor
argument_list|()
expr_stmt|;
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
DECL|function|item
name|void
name|tst_QTextList
operator|::
name|item
parameter_list|()
block|{
comment|// this is basically a test for the key() + 1 in QTextList::item.
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|QTextListFormat
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|->
name|item
argument_list|(
literal|0
argument_list|)
operator|.
name|blockFormat
argument_list|()
operator|.
name|objectIndex
argument_list|()
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|autoNumbering
name|void
name|tst_QTextList
operator|::
name|autoNumbering
parameter_list|()
block|{
name|QTextListFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerAlpha
argument_list|)
expr_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
argument_list|)
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
literal|27
condition|;
operator|++
name|i
control|)
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|28
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemNumber
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
literal|27
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemText
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"ab."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|autoNumberingPrefixAndSuffix
name|void
name|tst_QTextList
operator|::
name|autoNumberingPrefixAndSuffix
parameter_list|()
block|{
name|QTextListFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerAlpha
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setNumberPrefix
argument_list|(
literal|"-"
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setNumberSuffix
argument_list|(
literal|")"
argument_list|)
expr_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
argument_list|)
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
literal|27
condition|;
operator|++
name|i
control|)
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|28
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemNumber
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
literal|27
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemText
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"-ab)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|autoNumberingPrefixAndSuffixRTL
name|void
name|tst_QTextList
operator|::
name|autoNumberingPrefixAndSuffixRTL
parameter_list|()
block|{
name|QTextBlockFormat
name|bfmt
decl_stmt|;
name|bfmt
operator|.
name|setLayoutDirection
argument_list|(
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|bfmt
argument_list|)
expr_stmt|;
name|QTextListFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListUpperAlpha
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setNumberPrefix
argument_list|(
literal|"-"
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setNumberSuffix
argument_list|(
literal|"*"
argument_list|)
expr_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemText
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"*B-"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|autoNumberingPrefixAndSuffixHtmlExportImport
name|void
name|tst_QTextList
operator|::
name|autoNumberingPrefixAndSuffixHtmlExportImport
parameter_list|()
block|{
name|QTextListFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerAlpha
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setNumberPrefix
argument_list|(
literal|"\""
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setNumberSuffix
argument_list|(
literal|"#"
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setIndent
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|// FIXME: Would like to test "'" but there's a problem in the css parser (Scanner::preprocess
comment|// is called before the values are being parsed), so the quoting does not work.
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
argument_list|)
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
literal|27
condition|;
operator|++
name|i
control|)
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|28
argument_list|)
expr_stmt|;
name|QString
name|htmlExport
init|=
name|doc
operator|->
name|toHtml
argument_list|()
decl_stmt|;
name|QTextDocument
name|importDoc
decl_stmt|;
name|importDoc
operator|.
name|setHtml
argument_list|(
name|htmlExport
argument_list|)
expr_stmt|;
name|QTextCursor
name|importCursor
argument_list|(
operator|&
name|importDoc
argument_list|)
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
literal|27
condition|;
operator|++
name|i
control|)
name|importCursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextBlock
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|importCursor
operator|.
name|currentList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|importCursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemNumber
argument_list|(
name|importCursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
literal|27
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|importCursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemText
argument_list|(
name|importCursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\"ab#"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|importCursor
operator|.
name|currentList
argument_list|()
operator|->
name|format
argument_list|()
operator|.
name|indent
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|autoNumberingRTL
name|void
name|tst_QTextList
operator|::
name|autoNumberingRTL
parameter_list|()
block|{
name|QTextBlockFormat
name|bfmt
decl_stmt|;
name|bfmt
operator|.
name|setLayoutDirection
argument_list|(
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|bfmt
argument_list|)
expr_stmt|;
name|QTextListFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListUpperAlpha
argument_list|)
expr_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemText
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|".B"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|romanNumbering
name|void
name|tst_QTextList
operator|::
name|romanNumbering
parameter_list|()
block|{
name|QTextListFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListUpperRoman
argument_list|)
expr_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
argument_list|)
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
literal|4998
condition|;
operator|++
name|i
control|)
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|4999
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemNumber
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
literal|4998
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemText
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"MMMMCMXCIX."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|romanNumberingLimit
name|void
name|tst_QTextList
operator|::
name|romanNumberingLimit
parameter_list|()
block|{
name|QTextListFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerRoman
argument_list|)
expr_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
argument_list|)
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
literal|4999
condition|;
operator|++
name|i
control|)
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemNumber
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
literal|4999
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemText
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"?."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatChange
name|void
name|tst_QTextList
operator|::
name|formatChange
parameter_list|()
block|{
comment|// testing the formatChanged slot in QTextListManager
comment|/*<initial block>      * 1.      * 2.      */
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
decl_stmt|;
name|QTextList
modifier|*
name|firstList
init|=
name|list
decl_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|&&
name|list
operator|->
name|count
argument_list|()
operator|==
literal|2
argument_list|)
expr_stmt|;
name|QTextBlockFormat
name|bfmt
init|=
name|cursor
operator|.
name|blockFormat
argument_list|()
decl_stmt|;
comment|//     QCOMPARE(bfmt.object(), list);
name|bfmt
operator|.
name|setObjectIndex
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|bfmt
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|firstList
operator|->
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cursorNavigation
name|void
name|tst_QTextList
operator|::
name|cursorNavigation
parameter_list|()
block|{
comment|// testing some cursor list methods
comment|/*<initial block>      * 1.      * 2.      */
name|cursor
operator|.
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextBlock
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextBlock
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|PreviousBlock
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemNumber
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|partialRemoval
name|void
name|tst_QTextList
operator|::
name|partialRemoval
parameter_list|()
block|{
comment|/* this is essentially a test for PieceTable::removeBlock to not miss any        blocks with the blockChanged signal emission that actually get removed.         It creates two lists, like this:         1. Hello World        a. Foobar         and then removes from within the 'Hello World' into the 'Foobar' .        There used to be no emission for the removal of the second (a.) block,        causing list inconsistencies.         */
name|QTextList
modifier|*
name|firstList
init|=
name|cursor
operator|.
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
decl_stmt|;
name|QTextCursor
name|selStart
init|=
name|cursor
decl_stmt|;
name|selStart
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|PreviousCharacter
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello World"
argument_list|)
expr_stmt|;
comment|// position it well into the 'hello world' text.
name|selStart
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextCharacter
argument_list|)
expr_stmt|;
name|selStart
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextCharacter
argument_list|)
expr_stmt|;
name|selStart
operator|.
name|clearSelection
argument_list|()
expr_stmt|;
name|QPointer
argument_list|<
name|QTextList
argument_list|>
name|secondList
init|=
name|cursor
operator|.
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|ListCircle
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Foobar"
argument_list|)
expr_stmt|;
comment|// position it into the 'foo bar' text.
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|PreviousCharacter
argument_list|)
expr_stmt|;
name|QTextCursor
name|selEnd
init|=
name|cursor
decl_stmt|;
comment|// this creates a selection that includes parts of both text-fragments and also the list item of the second list.
name|QTextCursor
name|selection
init|=
name|selStart
decl_stmt|;
name|selection
operator|.
name|setPosition
argument_list|(
name|selEnd
operator|.
name|position
argument_list|()
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
name|selection
operator|.
name|deleteChar
argument_list|()
expr_stmt|;
comment|// deletes the second list
name|QVERIFY
argument_list|(
operator|!
name|secondList
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|firstList
operator|->
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|doc
operator|->
name|undo
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatReferenceChange
name|void
name|tst_QTextList
operator|::
name|formatReferenceChange
parameter_list|()
block|{
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Some Content..."
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|(
name|QTextBlockFormat
argument_list|()
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setPosition
argument_list|(
name|list
operator|->
name|item
argument_list|(
literal|0
argument_list|)
operator|.
name|position
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|listItemStartPos
init|=
name|cursor
operator|.
name|position
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextBlock
argument_list|)
expr_stmt|;
name|int
name|listItemLen
init|=
name|cursor
operator|.
name|position
argument_list|()
operator|-
name|listItemStartPos
decl_stmt|;
name|layout
operator|->
name|expect
argument_list|(
name|listItemStartPos
argument_list|,
name|listItemLen
argument_list|,
name|listItemLen
argument_list|)
expr_stmt|;
name|QTextListFormat
name|fmt
init|=
name|list
operator|->
name|format
argument_list|()
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListCircle
argument_list|)
expr_stmt|;
name|list
operator|->
name|setFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layout
operator|->
name|called
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|layout
operator|->
name|error
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ensureItemOrder
name|void
name|tst_QTextList
operator|::
name|ensureItemOrder
parameter_list|()
block|{
comment|/*      * Insert a new list item before the first one and verify the blocks      * are sorted after that.      */
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
decl_stmt|;
name|QTextBlockFormat
name|fmt
init|=
name|cursor
operator|.
name|blockFormat
argument_list|()
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
name|cursor
operator|.
name|insertBlock
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|item
argument_list|(
literal|0
argument_list|)
operator|.
name|position
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|item
argument_list|(
literal|1
argument_list|)
operator|.
name|position
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|add
name|void
name|tst_QTextList
operator|::
name|add
parameter_list|()
block|{
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|(
name|QTextBlockFormat
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|(
name|QTextBlockFormat
argument_list|()
argument_list|)
expr_stmt|;
name|list
operator|->
name|add
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Task #72036
end_comment
begin_function
DECL|function|defaultIndent
name|void
name|tst_QTextList
operator|::
name|defaultIndent
parameter_list|()
block|{
name|QTextListFormat
name|fmt
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fmt
operator|.
name|indent
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blockUpdate
name|void
name|tst_QTextList
operator|::
name|blockUpdate
parameter_list|()
block|{
comment|// three items
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
comment|// remove second, needs also update on the third
comment|// since the numbering might have changed
specifier|const
name|int
name|len
init|=
name|cursor
operator|.
name|position
argument_list|()
operator|+
name|cursor
operator|.
name|block
argument_list|()
operator|.
name|length
argument_list|()
operator|-
literal|1
decl_stmt|;
name|layout
operator|->
name|expect
argument_list|(
literal|1
argument_list|,
name|len
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|list
operator|->
name|remove
argument_list|(
name|list
operator|->
name|item
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|layout
operator|->
name|error
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|numbering_data
name|void
name|tst_QTextList
operator|::
name|numbering_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"format"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"number"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"result"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"E."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextListFormat
operator|::
name|ListUpperAlpha
argument_list|)
operator|<<
literal|5
operator|<<
literal|"E."
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"abc."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerAlpha
argument_list|)
operator|<<
operator|(
literal|26
operator|+
literal|2
operator|)
operator|*
literal|26
operator|+
literal|3
operator|<<
literal|"abc."
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"12."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
operator|<<
literal|12
operator|<<
literal|"12."
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"XXIV."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextListFormat
operator|::
name|ListUpperRoman
argument_list|)
operator|<<
literal|24
operator|<<
literal|"XXIV."
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"VIII."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextListFormat
operator|::
name|ListUpperRoman
argument_list|)
operator|<<
literal|8
operator|<<
literal|"VIII."
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"xxx."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerRoman
argument_list|)
operator|<<
literal|30
operator|<<
literal|"xxx."
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"xxix."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerRoman
argument_list|)
operator|<<
literal|29
operator|<<
literal|"xxix."
expr_stmt|;
comment|//    QTest::newRow("xxx. alpha")<< int(QTextListFormat::ListLowerAlpha)<< (24 * 26 + 24) * 26 + 24<< "xxx."; //Too slow
block|}
end_function
begin_function
DECL|function|numbering
name|void
name|tst_QTextList
operator|::
name|numbering
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|number
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QTextListFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|Style
argument_list|(
name|format
argument_list|)
argument_list|)
expr_stmt|;
name|QTextList
modifier|*
name|list
init|=
name|cursor
operator|.
name|createList
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|number
condition|;
operator|++
name|i
control|)
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|->
name|count
argument_list|()
argument_list|,
name|number
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemNumber
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|number
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|currentList
argument_list|()
operator|->
name|itemText
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTextList
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtextlist.moc"
end_include
end_unit
