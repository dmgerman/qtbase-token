begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qfont.h>
end_include
begin_include
include|#
directive|include
file|<qfontmetrics.h>
end_include
begin_include
include|#
directive|include
file|<qfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_class
DECL|class|tst_QFontMetrics
class|class
name|tst_QFontMetrics
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QFontMetrics
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QFontMetrics
parameter_list|()
destructor_decl|;
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
name|same
parameter_list|()
function_decl|;
name|void
name|metrics
parameter_list|()
function_decl|;
name|void
name|boundingRect
parameter_list|()
function_decl|;
name|void
name|elidedText_data
parameter_list|()
function_decl|;
name|void
name|elidedText
parameter_list|()
function_decl|;
name|void
name|veryNarrowElidedText
parameter_list|()
function_decl|;
name|void
name|averageCharWidth
parameter_list|()
function_decl|;
name|void
name|bypassShaping
parameter_list|()
function_decl|;
name|void
name|elidedMultiLength
parameter_list|()
function_decl|;
name|void
name|elidedMultiLengthF
parameter_list|()
function_decl|;
name|void
name|inFontUcs4
parameter_list|()
function_decl|;
name|void
name|lineWidth
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QFontMetrics
name|tst_QFontMetrics
operator|::
name|tst_QFontMetrics
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QFontMetrics
name|tst_QFontMetrics
operator|::
name|~
name|tst_QFontMetrics
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QFontMetrics
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QFontMetrics
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|same
name|void
name|tst_QFontMetrics
operator|::
name|same
parameter_list|()
block|{
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|font
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|text
init|=
name|QLatin1String
argument_list|(
literal|"Some stupid STRING"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fm
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text
argument_list|)
argument_list|,
name|fm
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|10
init|;
name|i
operator|<=
literal|32
condition|;
operator|++
name|i
control|)
block|{
name|font
operator|.
name|setPixelSize
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fm1
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fm1
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text
argument_list|)
argument_list|,
name|fm1
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QImage
name|image
decl_stmt|;
name|QFontMetrics
name|fm2
argument_list|(
name|font
argument_list|,
operator|&
name|image
argument_list|)
decl_stmt|;
name|QString
name|text2
init|=
name|QLatin1String
argument_list|(
literal|"Foo Foo"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fm2
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text2
argument_list|)
argument_list|,
name|fm2
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text2
argument_list|)
argument_list|)
expr_stmt|;
comment|//used to crash
block|}
block|{
name|QImage
name|image
decl_stmt|;
name|QFontMetricsF
name|fm3
argument_list|(
name|font
argument_list|,
operator|&
name|image
argument_list|)
decl_stmt|;
name|QString
name|text2
init|=
name|QLatin1String
argument_list|(
literal|"Foo Foo"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fm3
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text2
argument_list|)
argument_list|,
name|fm3
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text2
argument_list|)
argument_list|)
expr_stmt|;
comment|//used to crash
block|}
block|}
end_function
begin_function
DECL|function|metrics
name|void
name|tst_QFontMetrics
operator|::
name|metrics
parameter_list|()
block|{
name|QFont
name|font
decl_stmt|;
name|QFontDatabase
name|fdb
decl_stmt|;
comment|// Query the QFontDatabase for a specific font, store the
comment|// result in family, style and size.
name|QStringList
name|families
init|=
name|fdb
operator|.
name|families
argument_list|()
decl_stmt|;
if|if
condition|(
name|families
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QStringList
operator|::
name|ConstIterator
name|f_it
decl_stmt|,
name|f_end
init|=
name|families
operator|.
name|end
argument_list|()
decl_stmt|;
for|for
control|(
name|f_it
operator|=
name|families
operator|.
name|begin
argument_list|()
init|;
name|f_it
operator|!=
name|f_end
condition|;
operator|++
name|f_it
control|)
block|{
specifier|const
name|QString
modifier|&
name|family
init|=
operator|*
name|f_it
decl_stmt|;
name|QStringList
name|styles
init|=
name|fdb
operator|.
name|styles
argument_list|(
name|family
argument_list|)
decl_stmt|;
name|QStringList
operator|::
name|ConstIterator
name|s_it
decl_stmt|,
name|s_end
init|=
name|styles
operator|.
name|end
argument_list|()
decl_stmt|;
for|for
control|(
name|s_it
operator|=
name|styles
operator|.
name|begin
argument_list|()
init|;
name|s_it
operator|!=
name|s_end
condition|;
operator|++
name|s_it
control|)
block|{
specifier|const
name|QString
modifier|&
name|style
init|=
operator|*
name|s_it
decl_stmt|;
if|if
condition|(
name|fdb
operator|.
name|isSmoothlyScalable
argument_list|(
name|family
argument_list|,
name|style
argument_list|)
condition|)
block|{
comment|// smoothly scalable font... don't need to load every pointsize
name|font
operator|=
name|fdb
operator|.
name|font
argument_list|(
name|family
argument_list|,
name|style
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fontmetrics
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fontmetrics
operator|.
name|ascent
argument_list|()
operator|+
name|fontmetrics
operator|.
name|descent
argument_list|()
argument_list|,
name|fontmetrics
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fontmetrics
operator|.
name|height
argument_list|()
operator|+
name|fontmetrics
operator|.
name|leading
argument_list|()
argument_list|,
name|fontmetrics
operator|.
name|lineSpacing
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|sizes
init|=
name|fdb
operator|.
name|pointSizes
argument_list|(
name|family
argument_list|,
name|style
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|sizes
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
operator|::
name|ConstIterator
name|z_it
decl_stmt|,
name|z_end
init|=
name|sizes
operator|.
name|end
argument_list|()
decl_stmt|;
for|for
control|(
name|z_it
operator|=
name|sizes
operator|.
name|begin
argument_list|()
init|;
name|z_it
operator|!=
name|z_end
condition|;
operator|++
name|z_it
control|)
block|{
specifier|const
name|int
name|size
init|=
operator|*
name|z_it
decl_stmt|;
comment|// Initialize the font, and check if it is an exact match
name|font
operator|=
name|fdb
operator|.
name|font
argument_list|(
name|family
argument_list|,
name|style
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fontmetrics
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fontmetrics
operator|.
name|ascent
argument_list|()
operator|+
name|fontmetrics
operator|.
name|descent
argument_list|()
argument_list|,
name|fontmetrics
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fontmetrics
operator|.
name|height
argument_list|()
operator|+
name|fontmetrics
operator|.
name|leading
argument_list|()
argument_list|,
name|fontmetrics
operator|.
name|lineSpacing
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|boundingRect
name|void
name|tst_QFontMetrics
operator|::
name|boundingRect
parameter_list|()
block|{
name|QFont
name|f
decl_stmt|;
name|f
operator|.
name|setPointSize
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|QRect
name|r
init|=
name|fm
operator|.
name|boundingRect
argument_list|(
name|QChar
argument_list|(
literal|'Y'
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|r
operator|.
name|top
argument_list|()
operator|<
literal|0
argument_list|)
expr_stmt|;
name|r
operator|=
name|fm
operator|.
name|boundingRect
argument_list|(
name|QString
argument_list|(
literal|"Y"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|r
operator|.
name|top
argument_list|()
operator|<
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|elidedText_data
name|void
name|tst_QFontMetrics
operator|::
name|elidedText_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QFont
argument_list|>
argument_list|(
literal|"font"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"helvetica hello"
argument_list|)
operator|<<
name|QFont
argument_list|(
literal|"helvetica"
argument_list|,
literal|10
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"helvetica hello&Bye"
argument_list|)
operator|<<
name|QFont
argument_list|(
literal|"helvetica"
argument_list|,
literal|10
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"hello&Bye"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|elidedText
name|void
name|tst_QFontMetrics
operator|::
name|elidedText
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QFont
argument_list|,
name|font
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|int
name|w
init|=
name|fm
operator|.
name|width
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|QString
name|newtext
init|=
name|fm
operator|.
name|elidedText
argument_list|(
name|text
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
name|w
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|text
argument_list|,
name|newtext
argument_list|)
expr_stmt|;
comment|// should not elide
name|newtext
operator|=
name|fm
operator|.
name|elidedText
argument_list|(
name|text
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
name|w
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|text
operator|!=
name|newtext
argument_list|)
expr_stmt|;
comment|// should elide
block|}
end_function
begin_function
DECL|function|veryNarrowElidedText
name|void
name|tst_QFontMetrics
operator|::
name|veryNarrowElidedText
parameter_list|()
block|{
name|QFont
name|f
decl_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|QString
name|text
argument_list|(
literal|"hello"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fm
operator|.
name|elidedText
argument_list|(
name|text
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|averageCharWidth
name|void
name|tst_QFontMetrics
operator|::
name|averageCharWidth
parameter_list|()
block|{
name|QFont
name|f
decl_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fm
operator|.
name|averageCharWidth
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QFontMetricsF
name|fmf
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fmf
operator|.
name|averageCharWidth
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bypassShaping
name|void
name|tst_QFontMetrics
operator|::
name|bypassShaping
parameter_list|()
block|{
name|QFont
name|f
decl_stmt|;
name|f
operator|.
name|setStyleStrategy
argument_list|(
name|QFont
operator|::
name|ForceIntegerMetrics
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|QString
name|text
init|=
literal|" A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z"
decl_stmt|;
name|int
name|textWidth
init|=
name|fm
operator|.
name|width
argument_list|(
name|text
argument_list|,
operator|-
literal|1
argument_list|,
name|Qt
operator|::
name|TextBypassShaping
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|textWidth
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|int
name|charsWidth
init|=
literal|0
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
name|text
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|charsWidth
operator|+=
name|fm
operator|.
name|width
argument_list|(
name|text
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|// This assertion is needed in Qt WebKit's WebCore::Font::offsetForPositionForSimpleText
name|QCOMPARE
argument_list|(
name|textWidth
argument_list|,
name|charsWidth
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|elidedMultiLength_helper
template|template
parameter_list|<
name|class
name|FontMetrics
parameter_list|>
name|void
name|elidedMultiLength_helper
parameter_list|()
block|{
name|QString
name|text1
init|=
name|QLatin1String
argument_list|(
literal|"Long Text 1\x9cShorter\x9csmall"
argument_list|)
decl_stmt|;
name|QString
name|text1_long
init|=
literal|"Long Text 1"
decl_stmt|;
name|QString
name|text1_short
init|=
literal|"Shorter"
decl_stmt|;
name|QString
name|text1_small
init|=
literal|"small"
decl_stmt|;
name|FontMetrics
name|fm
init|=
name|FontMetrics
argument_list|(
name|QFont
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|width_long
init|=
name|fm
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text1_long
argument_list|)
operator|.
name|width
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fm
operator|.
name|elidedText
argument_list|(
name|text1
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
literal|8000
argument_list|)
argument_list|,
name|text1_long
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fm
operator|.
name|elidedText
argument_list|(
name|text1
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
name|width_long
operator|+
literal|1
argument_list|)
argument_list|,
name|text1_long
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fm
operator|.
name|elidedText
argument_list|(
name|text1
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
name|width_long
operator|-
literal|1
argument_list|)
argument_list|,
name|text1_short
argument_list|)
expr_stmt|;
name|int
name|width_short
init|=
name|fm
operator|.
name|size
argument_list|(
literal|0
argument_list|,
name|text1_short
argument_list|)
operator|.
name|width
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fm
operator|.
name|elidedText
argument_list|(
name|text1
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
name|width_short
operator|+
literal|1
argument_list|)
argument_list|,
name|text1_short
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fm
operator|.
name|elidedText
argument_list|(
name|text1
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
name|width_short
operator|-
literal|1
argument_list|)
argument_list|,
name|text1_small
argument_list|)
expr_stmt|;
comment|// Not even wide enough for "small" - should use ellipsis
name|QChar
name|ellipsisChar
argument_list|(
literal|0x2026
argument_list|)
decl_stmt|;
name|QString
name|text1_el
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"s"
argument_list|)
operator|+
name|ellipsisChar
decl_stmt|;
name|int
name|width_small
init|=
name|fm
operator|.
name|width
argument_list|(
name|text1_el
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fm
operator|.
name|elidedText
argument_list|(
name|text1
argument_list|,
name|Qt
operator|::
name|ElideRight
argument_list|,
name|width_small
operator|+
literal|1
argument_list|)
argument_list|,
name|text1_el
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|elidedMultiLength
name|void
name|tst_QFontMetrics
operator|::
name|elidedMultiLength
parameter_list|()
block|{
name|elidedMultiLength_helper
argument_list|<
name|QFontMetrics
argument_list|>
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|elidedMultiLengthF
name|void
name|tst_QFontMetrics
operator|::
name|elidedMultiLengthF
parameter_list|()
block|{
name|elidedMultiLength_helper
argument_list|<
name|QFontMetricsF
argument_list|>
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|inFontUcs4
name|void
name|tst_QFontMetrics
operator|::
name|inFontUcs4
parameter_list|()
block|{
name|int
name|id
init|=
name|QFontDatabase
operator|::
name|addApplicationFont
argument_list|(
literal|":/fonts/ucs4font.ttf"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|id
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|QFont
name|font
argument_list|(
literal|"QtTestUcs4"
argument_list|)
decl_stmt|;
block|{
name|QFontMetrics
name|fm
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fm
operator|.
name|inFontUcs4
argument_list|(
literal|0x1D7FF
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QFontMetricsF
name|fm
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fm
operator|.
name|inFontUcs4
argument_list|(
literal|0x1D7FF
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QFontEngine
modifier|*
name|engine
init|=
name|QFontPrivate
operator|::
name|get
argument_list|(
name|font
argument_list|)
operator|->
name|engineForScript
argument_list|(
name|QChar
operator|::
name|Script_Common
argument_list|)
decl_stmt|;
name|QGlyphLayout
name|glyphs
decl_stmt|;
name|glyphs
operator|.
name|numGlyphs
operator|=
literal|3
expr_stmt|;
name|uint
name|buf
index|[
literal|3
index|]
decl_stmt|;
name|glyphs
operator|.
name|glyphs
operator|=
name|buf
expr_stmt|;
name|QString
name|string
decl_stmt|;
block|{
name|string
operator|.
name|append
argument_list|(
name|QChar
operator|::
name|highSurrogate
argument_list|(
literal|0x1D7FF
argument_list|)
argument_list|)
expr_stmt|;
name|string
operator|.
name|append
argument_list|(
name|QChar
operator|::
name|lowSurrogate
argument_list|(
literal|0x1D7FF
argument_list|)
argument_list|)
expr_stmt|;
name|glyphs
operator|.
name|numGlyphs
operator|=
literal|3
expr_stmt|;
name|glyphs
operator|.
name|glyphs
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|QVERIFY
argument_list|(
name|engine
operator|->
name|stringToCMap
argument_list|(
name|string
operator|.
name|constData
argument_list|()
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|glyphs
argument_list|,
operator|&
name|glyphs
operator|.
name|numGlyphs
argument_list|,
name|QFontEngine
operator|::
name|GlyphIndicesOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|glyphs
operator|.
name|numGlyphs
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|glyphs
operator|.
name|glyphs
index|[
literal|0
index|]
argument_list|,
name|uint
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|string
operator|.
name|clear
argument_list|()
expr_stmt|;
name|string
operator|.
name|append
argument_list|(
name|QChar
operator|::
name|ObjectReplacementCharacter
argument_list|)
expr_stmt|;
name|glyphs
operator|.
name|numGlyphs
operator|=
literal|3
expr_stmt|;
name|glyphs
operator|.
name|glyphs
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|QVERIFY
argument_list|(
name|engine
operator|->
name|stringToCMap
argument_list|(
name|string
operator|.
name|constData
argument_list|()
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|glyphs
argument_list|,
operator|&
name|glyphs
operator|.
name|numGlyphs
argument_list|,
name|QFontEngine
operator|::
name|GlyphIndicesOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|glyphs
operator|.
name|glyphs
index|[
literal|0
index|]
operator|!=
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|QFontDatabase
operator|::
name|removeApplicationFont
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lineWidth
name|void
name|tst_QFontMetrics
operator|::
name|lineWidth
parameter_list|()
block|{
comment|// QTBUG-13009, QTBUG-13011
name|QFont
name|smallFont
decl_stmt|;
name|smallFont
operator|.
name|setPointSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|smallFont
operator|.
name|setWeight
argument_list|(
name|QFont
operator|::
name|Light
argument_list|)
expr_stmt|;
specifier|const
name|QFontMetrics
name|smallFontMetrics
argument_list|(
name|smallFont
argument_list|)
decl_stmt|;
name|QFont
name|bigFont
decl_stmt|;
name|bigFont
operator|.
name|setPointSize
argument_list|(
literal|40
argument_list|)
expr_stmt|;
name|bigFont
operator|.
name|setWeight
argument_list|(
name|QFont
operator|::
name|Black
argument_list|)
expr_stmt|;
specifier|const
name|QFontMetrics
name|bigFontMetrics
argument_list|(
name|bigFont
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|smallFontMetrics
operator|.
name|lineWidth
argument_list|()
operator|>=
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|smallFontMetrics
operator|.
name|lineWidth
argument_list|()
operator|<
name|bigFontMetrics
operator|.
name|lineWidth
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFontMetrics
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfontmetrics.moc"
end_include
end_unit
