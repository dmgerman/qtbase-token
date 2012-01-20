begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_comment
comment|/* XPM test data for QPixmap, QImage tests (use drag cursors as example) */
end_comment
begin_decl_stmt
DECL|variable|xpmPixmapData1
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|xpmPixmapData1
index|[]
init|=
block|{
literal|"11 20 3 1"
block|,
literal|".        c None"
block|,
literal|"a        c #FFFFFF"
block|,
literal|"X        c #000000"
block|,
comment|// X11 cursor is traditionally black
literal|"aa........."
block|,
literal|"aXa........"
block|,
literal|"aXXa......."
block|,
literal|"aXXXa......"
block|,
literal|"aXXXXa....."
block|,
literal|"aXXXXXa...."
block|,
literal|"aXXXXXXa..."
block|,
literal|"aXXXXXXXa.."
block|,
literal|"aXXXXXXXXa."
block|,
literal|"aXXXXXXXXXa"
block|,
literal|"aXXXXXXaaaa"
block|,
literal|"aXXXaXXa..."
block|,
literal|"aXXaaXXa..."
block|,
literal|"aXa..aXXa.."
block|,
literal|"aa...aXXa.."
block|,
literal|"a.....aXXa."
block|,
literal|"......aXXa."
block|,
literal|".......aXXa"
block|,
literal|".......aXXa"
block|,
literal|"........aa."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|xpmPixmapData2
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|xpmPixmapData2
index|[]
init|=
block|{
literal|"11 20 4 1"
block|,
literal|".        c None"
block|,
literal|"a        c #FFFFFF"
block|,
literal|"b        c #0000FF"
block|,
literal|"X        c #000000"
block|,
literal|"aab........"
block|,
literal|"aXab......."
block|,
literal|"aXXab......"
block|,
literal|"aXXXab....."
block|,
literal|"aXXXXab...."
block|,
literal|"aXXXXXab..."
block|,
literal|"aXXXXXXab.."
block|,
literal|"aXXXXXXXa.."
block|,
literal|"aXXXXXXXXa."
block|,
literal|"aXXXXXXXXXa"
block|,
literal|"aXXXXXXaaaa"
block|,
literal|"aXXXaXXa..."
block|,
literal|"aXXaaXXa..."
block|,
literal|"aXa..aXXa.."
block|,
literal|"aa...aXXa.."
block|,
literal|"a.....aXXa."
block|,
literal|"......aXXa."
block|,
literal|".......aXXa"
block|,
literal|".......aXXa"
block|,
literal|"........aa."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|xpmPixmapData3
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|xpmPixmapData3
index|[]
init|=
block|{
literal|"20 20 2 1"
block|,
literal|"       c #000000"
block|,
literal|".      c #C32D2D"
block|,
literal|"          .........."
block|,
literal|"            ........"
block|,
literal|"             ......."
block|,
literal|"              ......"
block|,
literal|"                ...."
block|,
literal|"                  .."
block|,
literal|"                   ."
block|,
literal|"                    "
block|,
literal|"                    "
block|,
literal|".                   "
block|,
literal|"...                 "
block|,
literal|".....               "
block|,
literal|"......              "
block|,
literal|".......             "
block|,
literal|".........           "
block|,
literal|"...........         "
block|,
literal|"...........         "
block|,
literal|"............        "
block|,
literal|"............        "
block|,
literal|".............       "
block|}
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|tst_Cmptest
class|class
name|tst_Cmptest
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|compare_boolfuncs
parameter_list|()
function_decl|;
name|void
name|compare_pointerfuncs
parameter_list|()
function_decl|;
name|void
name|compare_tostring
parameter_list|()
function_decl|;
name|void
name|compare_tostring_data
parameter_list|()
function_decl|;
name|void
name|compareQStringLists
parameter_list|()
function_decl|;
name|void
name|compareQStringLists_data
parameter_list|()
function_decl|;
name|void
name|compareQPixmaps
parameter_list|()
function_decl|;
name|void
name|compareQPixmaps_data
parameter_list|()
function_decl|;
name|void
name|compareQImages
parameter_list|()
function_decl|;
name|void
name|compareQImages_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|boolfunc
specifier|static
name|bool
name|boolfunc
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|boolfunc2
specifier|static
name|bool
name|boolfunc2
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|compare_boolfuncs
name|void
name|tst_Cmptest
operator|::
name|compare_boolfuncs
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|boolfunc
argument_list|()
argument_list|,
name|boolfunc
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|boolfunc
argument_list|()
argument_list|,
name|boolfunc2
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|!
name|boolfunc
argument_list|()
argument_list|,
operator|!
name|boolfunc2
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|boolfunc
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|!
name|boolfunc
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|i
specifier|static
name|int
name|i
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|intptr
specifier|static
name|int
modifier|*
name|intptr
parameter_list|()
block|{
return|return
operator|&
name|i
return|;
block|}
end_function
begin_function
DECL|function|compare_pointerfuncs
name|void
name|tst_Cmptest
operator|::
name|compare_pointerfuncs
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|intptr
argument_list|()
argument_list|,
name|intptr
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|&
name|i
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|intptr
argument_list|()
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|&
name|i
argument_list|,
name|intptr
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QVariant
argument_list|)
end_macro
begin_struct
DECL|struct|PhonyClass
struct|struct
name|PhonyClass
block|{
DECL|member|i
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|compare_tostring_data
name|void
name|tst_Cmptest
operator|::
name|compare_tostring_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"actual"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"int, string"
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
literal|123
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QString
argument_list|(
literal|"hi"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"both invalid"
argument_list|)
operator|<<
name|QVariant
argument_list|()
operator|<<
name|QVariant
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null hash, invalid"
argument_list|)
operator|<<
name|QVariant
argument_list|(
name|QVariant
operator|::
name|Hash
argument_list|)
operator|<<
name|QVariant
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"string, null user type"
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A simple string"
argument_list|)
argument_list|)
operator|<<
name|QVariant
argument_list|(
name|QVariant
operator|::
name|Type
argument_list|(
name|qRegisterMetaType
argument_list|<
name|PhonyClass
argument_list|>
argument_list|(
literal|"PhonyClass"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|PhonyClass
name|fake1
init|=
block|{
literal|1
block|}
decl_stmt|;
name|PhonyClass
name|fake2
init|=
block|{
literal|2
block|}
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"both non-null user type"
argument_list|)
operator|<<
name|QVariant
argument_list|(
name|qRegisterMetaType
argument_list|<
name|PhonyClass
argument_list|>
argument_list|(
literal|"PhonyClass"
argument_list|)
argument_list|,
operator|(
specifier|const
name|void
operator|*
operator|)
operator|&
name|fake1
argument_list|)
operator|<<
name|QVariant
argument_list|(
name|qRegisterMetaType
argument_list|<
name|PhonyClass
argument_list|>
argument_list|(
literal|"PhonyClass"
argument_list|)
argument_list|,
operator|(
specifier|const
name|void
operator|*
operator|)
operator|&
name|fake2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compare_tostring
name|void
name|tst_Cmptest
operator|::
name|compare_tostring
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|actual
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|actual
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compareQStringLists_data
name|void
name|tst_Cmptest
operator|::
name|compareQStringLists_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"opA"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"opB"
argument_list|)
expr_stmt|;
block|{
name|QStringList
name|opA
decl_stmt|;
name|QStringList
name|opB
argument_list|(
name|opA
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty lists"
argument_list|)
operator|<<
name|opA
operator|<<
name|opB
expr_stmt|;
block|}
block|{
name|QStringList
name|opA
decl_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string1"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string2"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string3"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string4"
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|opB
argument_list|(
name|opA
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"equal lists"
argument_list|)
operator|<<
name|opA
operator|<<
name|opB
expr_stmt|;
block|}
block|{
name|QStringList
name|opA
decl_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string1"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string2"
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|opB
argument_list|(
name|opA
argument_list|)
decl_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string3"
argument_list|)
argument_list|)
expr_stmt|;
name|opB
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"DIFFERS"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"last item different"
argument_list|)
operator|<<
name|opA
operator|<<
name|opB
expr_stmt|;
block|}
block|{
name|QStringList
name|opA
decl_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string1"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string2"
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|opB
argument_list|(
name|opA
argument_list|)
decl_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string3"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string4"
argument_list|)
argument_list|)
expr_stmt|;
name|opB
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"DIFFERS"
argument_list|)
argument_list|)
expr_stmt|;
name|opB
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string4"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"second-last item different"
argument_list|)
operator|<<
name|opA
operator|<<
name|opB
expr_stmt|;
block|}
block|{
name|QStringList
name|opA
decl_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string1"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string2"
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|opB
decl_stmt|;
name|opB
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"string1"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"prefix"
argument_list|)
operator|<<
name|opA
operator|<<
name|opB
expr_stmt|;
block|}
block|{
name|QStringList
name|opA
decl_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"openInNewWindow"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"openInNewTab"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"separator"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"bookmark_add"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"savelinkas"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"copylinklocation"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"separator"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"openWith_submenu"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"preview1"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"actions_submenu"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"separator"
argument_list|)
argument_list|)
expr_stmt|;
name|opA
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"viewDocumentSource"
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|opB
decl_stmt|;
name|opB
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"viewDocumentSource"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"short list second"
argument_list|)
operator|<<
name|opA
operator|<<
name|opB
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"short list first"
argument_list|)
operator|<<
name|opB
operator|<<
name|opA
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|compareQStringLists
name|void
name|tst_Cmptest
operator|::
name|compareQStringLists
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|opA
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|opB
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|opA
argument_list|,
name|opB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compareQPixmaps_data
name|void
name|tst_Cmptest
operator|::
name|compareQPixmaps_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
literal|"opA"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
literal|"opB"
argument_list|)
expr_stmt|;
specifier|const
name|QPixmap
name|pixmap1
argument_list|(
name|xpmPixmapData1
argument_list|)
decl_stmt|;
specifier|const
name|QPixmap
name|pixmap2
argument_list|(
name|xpmPixmapData2
argument_list|)
decl_stmt|;
specifier|const
name|QPixmap
name|pixmap3
argument_list|(
name|xpmPixmapData3
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"both null"
argument_list|)
operator|<<
name|QPixmap
argument_list|()
operator|<<
name|QPixmap
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one null"
argument_list|)
operator|<<
name|QPixmap
argument_list|()
operator|<<
name|pixmap1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"other null"
argument_list|)
operator|<<
name|pixmap1
operator|<<
name|QPixmap
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"equal"
argument_list|)
operator|<<
name|pixmap1
operator|<<
name|pixmap1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"different size"
argument_list|)
operator|<<
name|pixmap1
operator|<<
name|pixmap3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"different pixels"
argument_list|)
operator|<<
name|pixmap1
operator|<<
name|pixmap2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compareQPixmaps
name|void
name|tst_Cmptest
operator|::
name|compareQPixmaps
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPixmap
argument_list|,
name|opA
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPixmap
argument_list|,
name|opB
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|opA
argument_list|,
name|opB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compareQImages_data
name|void
name|tst_Cmptest
operator|::
name|compareQImages_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QImage
argument_list|>
argument_list|(
literal|"opA"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QImage
argument_list|>
argument_list|(
literal|"opB"
argument_list|)
expr_stmt|;
specifier|const
name|QImage
name|image1
argument_list|(
name|QPixmap
argument_list|(
name|xpmPixmapData1
argument_list|)
operator|.
name|toImage
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QImage
name|image2
argument_list|(
name|QPixmap
argument_list|(
name|xpmPixmapData2
argument_list|)
operator|.
name|toImage
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QImage
name|image1Indexed
init|=
name|image1
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_Indexed8
argument_list|)
decl_stmt|;
specifier|const
name|QImage
name|image3
argument_list|(
name|QPixmap
argument_list|(
name|xpmPixmapData3
argument_list|)
operator|.
name|toImage
argument_list|()
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"both null"
argument_list|)
operator|<<
name|QImage
argument_list|()
operator|<<
name|QImage
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"one null"
argument_list|)
operator|<<
name|QImage
argument_list|()
operator|<<
name|image1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"other null"
argument_list|)
operator|<<
name|image1
operator|<<
name|QImage
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"equal"
argument_list|)
operator|<<
name|image1
operator|<<
name|image1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"different size"
argument_list|)
operator|<<
name|image1
operator|<<
name|image3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"different format"
argument_list|)
operator|<<
name|image1
operator|<<
name|image1Indexed
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"different pixels"
argument_list|)
operator|<<
name|image1
operator|<<
name|image2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compareQImages
name|void
name|tst_Cmptest
operator|::
name|compareQImages
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QImage
argument_list|,
name|opA
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QImage
argument_list|,
name|opB
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|opA
argument_list|,
name|opB
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Cmptest
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_cmptest.moc"
end_include
end_unit
