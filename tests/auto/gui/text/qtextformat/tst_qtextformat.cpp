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
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qsettings.h>
end_include
begin_include
include|#
directive|include
file|<qtextformat.h>
end_include
begin_include
include|#
directive|include
file|<qtextdocument.h>
end_include
begin_include
include|#
directive|include
file|<qtextcursor.h>
end_include
begin_include
include|#
directive|include
file|<qtextobject.h>
end_include
begin_include
include|#
directive|include
file|<qtextlayout.h>
end_include
begin_include
include|#
directive|include
file|<qabstracttextdocumentlayout.h>
end_include
begin_class
DECL|class|tst_QTextFormat
class|class
name|tst_QTextFormat
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|defaultAlignment
parameter_list|()
function_decl|;
name|void
name|testQTextCharFormat
parameter_list|()
specifier|const
function_decl|;
name|void
name|testUnderlinePropertyPrecedence
parameter_list|()
function_decl|;
name|void
name|toFormat
parameter_list|()
function_decl|;
name|void
name|resolveFont
parameter_list|()
function_decl|;
name|void
name|testLetterSpacing
parameter_list|()
function_decl|;
name|void
name|testFontStretch
parameter_list|()
function_decl|;
name|void
name|getSetTabs
parameter_list|()
function_decl|;
name|void
name|testTabsUsed
parameter_list|()
function_decl|;
name|void
name|testFontStyleSetters
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/*! \internal   This (used to) trigger a crash in:       QDataStream&operator>>(QDataStream&stream, QTextFormat&fmt)    which is most easily produced through QSettings.  */
end_comment
begin_function
DECL|function|testQTextCharFormat
name|void
name|tst_QTextFormat
operator|::
name|testQTextCharFormat
parameter_list|()
specifier|const
block|{
name|QSettings
name|settings
argument_list|(
literal|"test"
argument_list|,
literal|"test"
argument_list|)
decl_stmt|;
name|QTextCharFormat
name|test
decl_stmt|;
name|settings
operator|.
name|value
argument_list|(
literal|"test"
argument_list|,
name|test
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QTextFormat
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QTextFormat
name|obj1
decl_stmt|;
comment|// int QTextFormat::objectIndex()
comment|// void QTextFormat::setObjectIndex(int)
name|obj1
operator|.
name|setObjectIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|objectIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setObjectIndex
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|objectIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setObjectIndex
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|objectIndex
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultAlignment
name|void
name|tst_QTextFormat
operator|::
name|defaultAlignment
parameter_list|()
block|{
name|QTextBlockFormat
name|fmt
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|BlockAlignment
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fmt
operator|.
name|intProperty
argument_list|(
name|QTextFormat
operator|::
name|BlockAlignment
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|alignment
argument_list|()
operator|==
name|Qt
operator|::
name|AlignLeft
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testUnderlinePropertyPrecedence
name|void
name|tst_QTextFormat
operator|::
name|testUnderlinePropertyPrecedence
parameter_list|()
block|{
name|QTextCharFormat
name|format
decl_stmt|;
comment|// use normal accessors and check internal state
name|format
operator|.
name|setUnderlineStyle
argument_list|(
name|QTextCharFormat
operator|::
name|NoUnderline
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|TextUnderlineStyle
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
operator|.
name|toBool
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|TextUnderlineStyle
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|format
operator|=
name|QTextCharFormat
argument_list|()
expr_stmt|;
name|format
operator|.
name|setUnderlineStyle
argument_list|(
name|QTextCharFormat
operator|::
name|SingleUnderline
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|TextUnderlineStyle
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
operator|.
name|toBool
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|TextUnderlineStyle
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|format
operator|=
name|QTextCharFormat
argument_list|()
expr_stmt|;
name|format
operator|.
name|setUnderlineStyle
argument_list|(
name|QTextCharFormat
operator|::
name|DotLine
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|TextUnderlineStyle
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
operator|.
name|toBool
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|TextUnderlineStyle
argument_list|)
operator|.
name|toInt
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|// override accessors and use setProperty to create a false state.
comment|// then check font()
name|format
operator|=
name|QTextCharFormat
argument_list|()
expr_stmt|;
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|FontUnderline
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|TextUnderlineStyle
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|fontUnderline
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|format
operator|=
name|QTextCharFormat
argument_list|()
expr_stmt|;
comment|// create conflict. Should use the new property
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|TextUnderlineStyle
argument_list|,
name|QTextCharFormat
operator|::
name|SingleUnderline
argument_list|)
expr_stmt|;
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|FontUnderline
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|fontUnderline
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|format
operator|=
name|QTextCharFormat
argument_list|()
expr_stmt|;
comment|// create conflict. Should use the new property
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|TextUnderlineStyle
argument_list|,
name|QTextCharFormat
operator|::
name|NoUnderline
argument_list|)
expr_stmt|;
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|FontUnderline
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|fontUnderline
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
comment|// do it again, but reverse the ordering (we use a QVector internally, so test a LOT ;)
comment|// create conflict. Should use the new property
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|FontUnderline
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|TextUnderlineStyle
argument_list|,
name|QTextCharFormat
operator|::
name|SingleUnderline
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|fontUnderline
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|format
operator|=
name|QTextCharFormat
argument_list|()
expr_stmt|;
comment|// create conflict. Should use the new property
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|FontUnderline
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|format
operator|.
name|setProperty
argument_list|(
name|QTextCharFormat
operator|::
name|TextUnderlineStyle
argument_list|,
name|QTextCharFormat
operator|::
name|NoUnderline
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|fontUnderline
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toFormat
name|void
name|tst_QTextFormat
operator|::
name|toFormat
parameter_list|()
block|{
block|{
name|QTextFormat
name|fmt
init|=
name|QTextFrameFormat
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fmt
operator|.
name|toFrameFormat
argument_list|()
operator|.
name|type
argument_list|()
argument_list|,
name|int
argument_list|(
name|QTextFormat
operator|::
name|FrameFormat
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QTextFormat
name|fmt
init|=
name|QTextTableFormat
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fmt
operator|.
name|toTableFormat
argument_list|()
operator|.
name|type
argument_list|()
argument_list|,
name|int
argument_list|(
name|QTextFormat
operator|::
name|FrameFormat
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fmt
operator|.
name|toTableFormat
argument_list|()
operator|.
name|objectType
argument_list|()
argument_list|,
name|int
argument_list|(
name|QTextFormat
operator|::
name|TableObject
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QTextFormat
name|fmt
init|=
name|QTextBlockFormat
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fmt
operator|.
name|toBlockFormat
argument_list|()
operator|.
name|type
argument_list|()
argument_list|,
name|int
argument_list|(
name|QTextFormat
operator|::
name|BlockFormat
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QTextFormat
name|fmt
init|=
name|QTextCharFormat
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fmt
operator|.
name|toCharFormat
argument_list|()
operator|.
name|type
argument_list|()
argument_list|,
name|int
argument_list|(
name|QTextFormat
operator|::
name|CharFormat
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QTextFormat
name|fmt
init|=
name|QTextListFormat
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fmt
operator|.
name|toListFormat
argument_list|()
operator|.
name|type
argument_list|()
argument_list|,
name|int
argument_list|(
name|QTextFormat
operator|::
name|ListFormat
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resolveFont
name|void
name|tst_QTextFormat
operator|::
name|resolveFont
parameter_list|()
block|{
name|QTextDocument
name|doc
decl_stmt|;
name|QTextCharFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setProperty
argument_list|(
name|QTextFormat
operator|::
name|ForegroundBrush
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setProperty
argument_list|(
name|QTextFormat
operator|::
name|FontItalic
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QTextCursor
argument_list|(
operator|&
name|doc
argument_list|)
operator|.
name|insertText
argument_list|(
literal|"Test"
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QTextFormat
argument_list|>
name|formats
init|=
name|doc
operator|.
name|allFormats
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|formats
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|formats
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|type
argument_list|()
operator|==
name|QTextFormat
operator|::
name|CharFormat
argument_list|)
expr_stmt|;
name|fmt
operator|=
name|formats
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toCharFormat
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ForegroundBrush
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|f
decl_stmt|;
name|f
operator|.
name|setUnderline
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|doc
operator|.
name|setDefaultFont
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|formats
operator|=
name|doc
operator|.
name|allFormats
argument_list|()
expr_stmt|;
name|fmt
operator|=
name|formats
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toCharFormat
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
argument_list|)
expr_stmt|;
comment|// verify that deleting a non-existent property does not affect the font resolving
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|BackgroundBrush
argument_list|)
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|clearProperty
argument_list|(
name|QTextFormat
operator|::
name|BackgroundBrush
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|BackgroundBrush
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|)
expr_stmt|;
comment|// verify that deleting an existent but font _unrelated_ property does not affect the font resolving
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ForegroundBrush
argument_list|)
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|clearProperty
argument_list|(
name|QTextFormat
operator|::
name|ForegroundBrush
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ForegroundBrush
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|)
expr_stmt|;
comment|// verify that removing a font property _does_ clear the resolving
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontItalic
argument_list|)
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|clearProperty
argument_list|(
name|QTextFormat
operator|::
name|FontItalic
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontItalic
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|italic
argument_list|()
argument_list|)
expr_stmt|;
comment|// reset
name|fmt
operator|=
name|formats
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toCharFormat
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
argument_list|)
expr_stmt|;
comment|// verify that _setting_ an unrelated property does _not_ affect the resolving
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|IsAnchor
argument_list|)
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setProperty
argument_list|(
name|QTextFormat
operator|::
name|IsAnchor
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|IsAnchor
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
argument_list|)
expr_stmt|;
comment|// verify that setting a _related_ font property does affect the resolving
comment|//
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontStrikeOut
argument_list|)
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setProperty
argument_list|(
name|QTextFormat
operator|::
name|FontStrikeOut
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontStrikeOut
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|underline
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fmt
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontUnderline
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fmt
operator|.
name|font
argument_list|()
operator|.
name|strikeOut
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testLetterSpacing
name|void
name|tst_QTextFormat
operator|::
name|testLetterSpacing
parameter_list|()
block|{
name|QTextCharFormat
name|format
decl_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontLetterSpacing
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontAbsoluteLetterSpacing
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFontAbsoluteLetterSpacing
argument_list|(
literal|10.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontLetterSpacing
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontAbsoluteLetterSpacing
argument_list|)
operator|.
name|toDouble
argument_list|()
argument_list|,
literal|10.0
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFontLetterSpacing
argument_list|(
literal|110.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontLetterSpacing
argument_list|)
operator|.
name|toDouble
argument_list|()
argument_list|,
literal|110.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontAbsoluteLetterSpacing
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFontAbsoluteLetterSpacing
argument_list|(
literal|10.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontLetterSpacing
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontAbsoluteLetterSpacing
argument_list|)
operator|.
name|toDouble
argument_list|()
argument_list|,
literal|10.0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFontStretch
name|void
name|tst_QTextFormat
operator|::
name|testFontStretch
parameter_list|()
block|{
name|QTextCharFormat
name|format
decl_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|FontStretch
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFontStretch
argument_list|(
literal|130.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|property
argument_list|(
name|QTextFormat
operator|::
name|FontStretch
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|130
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getSetTabs
name|void
name|tst_QTextFormat
operator|::
name|getSetTabs
parameter_list|()
block|{
class|class
name|Comparator
block|{
public|public:
name|Comparator
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
modifier|&
name|tabs
parameter_list|,
specifier|const
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
modifier|&
name|tabs2
parameter_list|)
block|{
name|QCOMPARE
argument_list|(
name|tabs
operator|.
name|count
argument_list|()
argument_list|,
name|tabs2
operator|.
name|count
argument_list|()
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
name|tabs
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QTextOption
operator|::
name|Tab
name|t1
init|=
name|tabs
index|[
name|i
index|]
decl_stmt|;
name|QTextOption
operator|::
name|Tab
name|t2
init|=
name|tabs2
index|[
name|i
index|]
decl_stmt|;
name|QCOMPARE
argument_list|(
name|t1
operator|.
name|position
argument_list|,
name|t2
operator|.
name|position
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t1
operator|.
name|type
argument_list|,
name|t2
operator|.
name|type
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t1
operator|.
name|delimiter
argument_list|,
name|t2
operator|.
name|delimiter
argument_list|)
expr_stmt|;
block|}
block|}
block|}
class|;
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
name|tabs
decl_stmt|;
name|QTextBlockFormat
name|format
decl_stmt|;
name|format
operator|.
name|setTabPositions
argument_list|(
name|tabs
argument_list|)
expr_stmt|;
name|Comparator
name|c1
argument_list|(
name|tabs
argument_list|,
name|format
operator|.
name|tabPositions
argument_list|()
argument_list|)
decl_stmt|;
name|QTextOption
operator|::
name|Tab
name|tab1
decl_stmt|;
name|tab1
operator|.
name|position
operator|=
literal|1234
expr_stmt|;
name|tabs
operator|.
name|append
argument_list|(
name|tab1
argument_list|)
expr_stmt|;
name|format
operator|.
name|setTabPositions
argument_list|(
name|tabs
argument_list|)
expr_stmt|;
name|Comparator
name|c2
argument_list|(
name|tabs
argument_list|,
name|format
operator|.
name|tabPositions
argument_list|()
argument_list|)
decl_stmt|;
name|QTextOption
operator|::
name|Tab
name|tab2
argument_list|(
literal|3456
argument_list|,
name|QTextOption
operator|::
name|RightTab
argument_list|,
name|QChar
argument_list|(
literal|'x'
argument_list|)
argument_list|)
decl_stmt|;
name|tabs
operator|.
name|append
argument_list|(
name|tab2
argument_list|)
expr_stmt|;
name|format
operator|.
name|setTabPositions
argument_list|(
name|tabs
argument_list|)
expr_stmt|;
name|Comparator
name|c3
argument_list|(
name|tabs
argument_list|,
name|format
operator|.
name|tabPositions
argument_list|()
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|testTabsUsed
name|void
name|tst_QTextFormat
operator|::
name|testTabsUsed
parameter_list|()
block|{
name|QTextDocument
name|doc
decl_stmt|;
name|QTextCursor
name|cursor
argument_list|(
operator|&
name|doc
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
name|tabs
decl_stmt|;
name|QTextBlockFormat
name|format
decl_stmt|;
name|QTextOption
operator|::
name|Tab
name|tab
decl_stmt|;
name|tab
operator|.
name|position
operator|=
literal|100
expr_stmt|;
name|tabs
operator|.
name|append
argument_list|(
name|tab
argument_list|)
expr_stmt|;
name|format
operator|.
name|setTabPositions
argument_list|(
name|tabs
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|mergeBlockFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"foo\tbar"
argument_list|)
expr_stmt|;
comment|//doc.setPageSize(QSizeF(200, 200));
name|doc
operator|.
name|documentLayout
argument_list|()
operator|->
name|pageCount
argument_list|()
expr_stmt|;
comment|// force layout;
name|QTextBlock
name|block
init|=
name|doc
operator|.
name|begin
argument_list|()
decl_stmt|;
name|QTextLayout
modifier|*
name|layout
init|=
name|block
operator|.
name|layout
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|->
name|lineCount
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QTextLine
name|line
init|=
name|layout
operator|->
name|lineAt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|line
operator|.
name|cursorToX
argument_list|(
literal|4
argument_list|)
argument_list|,
literal|100.
argument_list|)
expr_stmt|;
name|QTextOption
name|option
init|=
name|layout
operator|->
name|textOption
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|option
operator|.
name|tabs
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
name|tabs
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFontStyleSetters
name|void
name|tst_QTextFormat
operator|::
name|testFontStyleSetters
parameter_list|()
block|{
name|QTextCharFormat
name|format
decl_stmt|;
comment|// test the setters
name|format
operator|.
name|setFontStyleHint
argument_list|(
name|QFont
operator|::
name|Serif
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|styleHint
argument_list|()
argument_list|,
name|QFont
operator|::
name|Serif
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|styleStrategy
argument_list|()
argument_list|,
name|QFont
operator|::
name|PreferDefault
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFontStyleStrategy
argument_list|(
name|QFont
operator|::
name|PreferOutline
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|styleStrategy
argument_list|()
argument_list|,
name|QFont
operator|::
name|PreferOutline
argument_list|)
expr_stmt|;
comment|// test setting properties through setFont()
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setStyleHint
argument_list|(
name|QFont
operator|::
name|SansSerif
argument_list|,
name|QFont
operator|::
name|PreferAntialias
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|styleHint
argument_list|()
argument_list|,
name|QFont
operator|::
name|SansSerif
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|styleStrategy
argument_list|()
argument_list|,
name|QFont
operator|::
name|PreferAntialias
argument_list|)
expr_stmt|;
comment|// test kerning
name|format
operator|.
name|setFontKerning
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|kerning
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFontKerning
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|kerning
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|font
operator|.
name|setKerning
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|.
name|font
argument_list|()
operator|.
name|kerning
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTextFormat
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtextformat.moc"
end_include
end_unit
