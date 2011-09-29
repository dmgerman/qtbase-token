begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QTest>
end_include
begin_include
include|#
directive|include
file|<qtextdocument.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_include
include|#
directive|include
file|<private/qtextdocument_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qtextobject.h>
end_include
begin_include
include|#
directive|include
file|<qtextcursor.h>
end_include
begin_comment
comment|//TESTED_FILES=
end_comment
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTextDocument
argument_list|)
end_macro
begin_class
DECL|class|tst_QTextBlock
class|class
name|tst_QTextBlock
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QTextBlock
parameter_list|()
constructor_decl|;
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
private|private
name|slots
private|:
name|void
name|fragmentOverBlockBoundaries
parameter_list|()
function_decl|;
name|void
name|excludeParagraphSeparatorFragment
parameter_list|()
function_decl|;
name|void
name|backwardsBlockIterator
parameter_list|()
function_decl|;
name|void
name|previousBlock_qtbug18026
parameter_list|()
function_decl|;
name|void
name|removedBlock_qtbug18500
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
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QTextBlock
name|tst_QTextBlock
operator|::
name|tst_QTextBlock
parameter_list|()
block|{}
end_constructor
begin_function
DECL|function|init
name|void
name|tst_QTextBlock
operator|::
name|init
parameter_list|()
block|{
name|doc
operator|=
operator|new
name|QTextDocument
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
name|tst_QTextBlock
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
DECL|function|fragmentOverBlockBoundaries
name|void
name|tst_QTextBlock
operator|::
name|fragmentOverBlockBoundaries
parameter_list|()
block|{
comment|/* this creates two fragments in the piecetable:      * 1) 'hello<parag separator here>world'      * 2) '<parag separator>'      * (they are not united because the former was interested after the latter,      * hence their position in the pt buffer is the other way around)      */
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"World"
argument_list|)
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
specifier|const
name|QTextDocument
modifier|*
name|doc
init|=
name|cursor
operator|.
name|block
argument_list|()
operator|.
name|document
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|doc
argument_list|)
expr_stmt|;
comment|// Block separators are always a fragment of their self. Thus:
comment|// |Hello|\b|World|\b|
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|QVERIFY
argument_list|(
name|doc
operator|->
name|docHandle
argument_list|()
operator|->
name|fragmentMap
argument_list|()
operator|.
name|numNodes
argument_list|()
operator|==
literal|4
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Hello"
argument_list|)
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
name|QCOMPARE
argument_list|(
name|cursor
operator|.
name|block
argument_list|()
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"World"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|excludeParagraphSeparatorFragment
name|void
name|tst_QTextBlock
operator|::
name|excludeParagraphSeparatorFragment
parameter_list|()
block|{
name|QTextCharFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello"
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|QTextBlock
name|block
init|=
name|doc
operator|->
name|begin
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|block
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QTextBlock
operator|::
name|Iterator
name|it
init|=
name|block
operator|.
name|begin
argument_list|()
decl_stmt|;
name|QTextFragment
name|fragment
init|=
name|it
operator|.
name|fragment
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|fragment
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fragment
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Hello"
argument_list|)
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
name|QVERIFY
argument_list|(
name|it
operator|.
name|atEnd
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|it
operator|==
name|block
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|backwardsBlockIterator
name|void
name|tst_QTextBlock
operator|::
name|backwardsBlockIterator
parameter_list|()
block|{
name|QTextCharFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|magenta
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"A"
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"A"
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|magenta
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"A"
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|QTextBlock
name|block
init|=
name|doc
operator|->
name|begin
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|block
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QTextBlock
operator|::
name|Iterator
name|it
init|=
name|block
operator|.
name|begin
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|it
operator|.
name|fragment
argument_list|()
operator|.
name|position
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
name|QCOMPARE
argument_list|(
name|it
operator|.
name|fragment
argument_list|()
operator|.
name|position
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
name|QCOMPARE
argument_list|(
name|it
operator|.
name|fragment
argument_list|()
operator|.
name|position
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
operator|--
name|it
expr_stmt|;
name|QCOMPARE
argument_list|(
name|it
operator|.
name|fragment
argument_list|()
operator|.
name|position
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|--
name|it
expr_stmt|;
name|QCOMPARE
argument_list|(
name|it
operator|.
name|fragment
argument_list|()
operator|.
name|position
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|previousBlock_qtbug18026
name|void
name|tst_QTextBlock
operator|::
name|previousBlock_qtbug18026
parameter_list|()
block|{
name|QTextBlock
name|last
init|=
name|doc
operator|->
name|end
argument_list|()
operator|.
name|previous
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|last
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removedBlock_qtbug18500
name|void
name|tst_QTextBlock
operator|::
name|removedBlock_qtbug18500
parameter_list|()
block|{
name|cursor
operator|.
name|insertText
argument_list|(
literal|"line 1\nline 2\nline 3 \nline 4\n"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setPosition
argument_list|(
literal|7
argument_list|)
expr_stmt|;
name|QTextBlock
name|block
init|=
name|cursor
operator|.
name|block
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|setPosition
argument_list|(
literal|21
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|removeSelectedText
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|block
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTextBlock
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtextblock.moc"
end_include
end_unit
