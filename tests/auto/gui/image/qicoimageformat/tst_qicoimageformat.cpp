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
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_class
DECL|class|tst_QIcoImageFormat
class|class
name|tst_QIcoImageFormat
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QIcoImageFormat
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QIcoImageFormat
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
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
name|format
parameter_list|()
function_decl|;
name|void
name|canRead_data
parameter_list|()
function_decl|;
name|void
name|canRead
parameter_list|()
function_decl|;
name|void
name|SequentialFile_data
parameter_list|()
function_decl|;
name|void
name|SequentialFile
parameter_list|()
function_decl|;
name|void
name|imageCount_data
parameter_list|()
function_decl|;
name|void
name|imageCount
parameter_list|()
function_decl|;
name|void
name|jumpToNextImage_data
parameter_list|()
function_decl|;
name|void
name|jumpToNextImage
parameter_list|()
function_decl|;
name|void
name|loopCount_data
parameter_list|()
function_decl|;
name|void
name|loopCount
parameter_list|()
function_decl|;
name|void
name|nextImageDelay_data
parameter_list|()
function_decl|;
name|void
name|nextImageDelay
parameter_list|()
function_decl|;
name|void
name|pngCompression_data
parameter_list|()
function_decl|;
name|void
name|pngCompression
parameter_list|()
function_decl|;
private|private:
DECL|member|m_IconPath
name|QString
name|m_IconPath
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QIcoImageFormat
name|tst_QIcoImageFormat
operator|::
name|tst_QIcoImageFormat
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QIcoImageFormat
name|tst_QIcoImageFormat
operator|::
name|~
name|tst_QIcoImageFormat
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QIcoImageFormat
operator|::
name|init
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QIcoImageFormat
operator|::
name|cleanup
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QIcoImageFormat
operator|::
name|initTestCase
parameter_list|()
block|{
name|m_IconPath
operator|=
name|QFINDTESTDATA
argument_list|(
literal|"icons"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_IconPath
operator|.
name|isEmpty
argument_list|()
condition|)
name|QFAIL
argument_list|(
literal|"Cannot find icons directory containing testdata!"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QIcoImageFormat
operator|::
name|cleanupTestCase
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|format
name|void
name|tst_QIcoImageFormat
operator|::
name|format
parameter_list|()
block|{
name|QImageReader
name|reader
argument_list|(
name|m_IconPath
operator|+
literal|"/valid/35FLOPPY.ICO"
argument_list|,
literal|"ico"
argument_list|)
decl_stmt|;
name|QByteArray
name|fmt
init|=
name|reader
operator|.
name|format
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
cast|const_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|fmt
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
literal|"ico"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|canRead_data
name|void
name|tst_QIcoImageFormat
operator|::
name|canRead_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"isValid"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"floppy (16px,32px - 16 colors)"
argument_list|)
operator|<<
literal|"valid/35FLOPPY.ICO"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px,48px - 256,16M colors"
argument_list|)
operator|<<
literal|"valid/abcardWindow.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px - 16 colors"
argument_list|)
operator|<<
literal|"valid/App.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px,48px - 16,256,16M colors"
argument_list|)
operator|<<
literal|"valid/Obj_N2_Internal_Mem.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px - 16,256,16M colors"
argument_list|)
operator|<<
literal|"valid/Status_Play.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px - 16 colors"
argument_list|)
operator|<<
literal|"valid/TIMER01.ICO"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px16c, 32px32c, 32px256c"
argument_list|)
operator|<<
literal|"valid/WORLD.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px16c, 32px32c, 32px256c"
argument_list|)
operator|<<
literal|"valid/WORLDH.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid floppy (first 8 bytes = 0xff)"
argument_list|)
operator|<<
literal|"invalid/35floppy.ico"
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"103x16px, 24BPP"
argument_list|)
operator|<<
literal|"valid/trolltechlogo_tiny.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"includes 32BPP w/alpha"
argument_list|)
operator|<<
literal|"valid/semitransparent.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"PNG compression"
argument_list|)
operator|<<
literal|"valid/Qt.ico"
operator|<<
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|canRead
name|void
name|tst_QIcoImageFormat
operator|::
name|canRead
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|isValid
argument_list|)
expr_stmt|;
name|QImageReader
name|reader
argument_list|(
name|m_IconPath
operator|+
literal|"/"
operator|+
name|fileName
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|reader
operator|.
name|canRead
argument_list|()
argument_list|,
operator|(
name|isValid
operator|==
literal|0
condition|?
literal|false
else|:
literal|true
operator|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QSequentialFile
class|class
name|QSequentialFile
super|:
specifier|public
name|QFile
block|{
public|public:
DECL|function|QSequentialFile
name|QSequentialFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
member_init_list|:
name|QFile
argument_list|(
name|name
argument_list|)
block|{}
DECL|function|~QSequentialFile
specifier|virtual
name|~
name|QSequentialFile
parameter_list|()
block|{}
DECL|function|isSequential
specifier|virtual
name|bool
name|isSequential
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|SequentialFile_data
name|void
name|tst_QIcoImageFormat
operator|::
name|SequentialFile_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"isValid"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"floppy (16,32 pixels - 16 colors)"
argument_list|)
operator|<<
literal|"valid/35FLOPPY.ICO"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid floppy (first 8 bytes = 0xff)"
argument_list|)
operator|<<
literal|"invalid/35floppy.ico"
operator|<<
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|SequentialFile
name|void
name|tst_QIcoImageFormat
operator|::
name|SequentialFile
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|isValid
argument_list|)
expr_stmt|;
name|QSequentialFile
modifier|*
name|file
init|=
operator|new
name|QSequentialFile
argument_list|(
name|m_IconPath
operator|+
literal|"/"
operator|+
name|fileName
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|->
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QImageReader
name|reader
argument_list|(
name|file
argument_list|)
decl_stmt|;
comment|// Perform the check twice. If canRead() does not restore the sequential device back to its original state,
comment|// it will fail on the second try.
name|QCOMPARE
argument_list|(
name|reader
operator|.
name|canRead
argument_list|()
argument_list|,
operator|(
name|isValid
operator|==
literal|0
condition|?
literal|false
else|:
literal|true
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|reader
operator|.
name|canRead
argument_list|()
argument_list|,
operator|(
name|isValid
operator|==
literal|0
condition|?
literal|false
else|:
literal|true
operator|)
argument_list|)
expr_stmt|;
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|imageCount_data
name|void
name|tst_QIcoImageFormat
operator|::
name|imageCount_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"count"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"floppy (16px,32px - 16 colors)"
argument_list|)
operator|<<
literal|"valid/35FLOPPY.ICO"
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px,48px - 256,16M colors"
argument_list|)
operator|<<
literal|"valid/abcardWindow.ico"
operator|<<
literal|6
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px - 16 colors"
argument_list|)
operator|<<
literal|"valid/App.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px,48px - 16,256,16M colors"
argument_list|)
operator|<<
literal|"valid/Obj_N2_Internal_Mem.ico"
operator|<<
literal|9
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px - 16,256,16M colors"
argument_list|)
operator|<<
literal|"valid/Status_Play.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px - 16 colors"
argument_list|)
operator|<<
literal|"valid/TIMER01.ICO"
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px16c, 32px32c, 32px256c"
argument_list|)
operator|<<
literal|"valid/WORLD.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px16c, 32px32c, 32px256c"
argument_list|)
operator|<<
literal|"valid/WORLDH.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid floppy (first 8 bytes = 0xff)"
argument_list|)
operator|<<
literal|"invalid/35floppy.ico"
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"includes 32BPP w/alpha"
argument_list|)
operator|<<
literal|"valid/semitransparent.ico"
operator|<<
literal|9
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"PNG compression"
argument_list|)
operator|<<
literal|"valid/Qt.ico"
operator|<<
literal|4
expr_stmt|;
block|}
end_function
begin_function
DECL|function|imageCount
name|void
name|tst_QIcoImageFormat
operator|::
name|imageCount
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QImageReader
name|reader
argument_list|(
name|m_IconPath
operator|+
literal|"/"
operator|+
name|fileName
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|reader
operator|.
name|imageCount
argument_list|()
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|jumpToNextImage_data
name|void
name|tst_QIcoImageFormat
operator|::
name|jumpToNextImage_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"count"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"floppy (16px,32px - 16 colors)"
argument_list|)
operator|<<
literal|"valid/35FLOPPY.ICO"
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px,48px - 256,16M colors"
argument_list|)
operator|<<
literal|"valid/abcardWindow.ico"
operator|<<
literal|6
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px - 16 colors"
argument_list|)
operator|<<
literal|"valid/App.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px,48px - 16,256,16M colors"
argument_list|)
operator|<<
literal|"valid/Obj_N2_Internal_Mem.ico"
operator|<<
literal|9
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px - 16,256,16M colors"
argument_list|)
operator|<<
literal|"valid/Status_Play.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px - 16 colors"
argument_list|)
operator|<<
literal|"valid/TIMER01.ICO"
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px16c, 32px32c, 32px256c"
argument_list|)
operator|<<
literal|"valid/WORLD.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px16c, 32px32c, 32px256c"
argument_list|)
operator|<<
literal|"valid/WORLDH.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"includes 32BPP w/alpha"
argument_list|)
operator|<<
literal|"valid/semitransparent.ico"
operator|<<
literal|9
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"PNG compression"
argument_list|)
operator|<<
literal|"valid/Qt.ico"
operator|<<
literal|4
expr_stmt|;
block|}
end_function
begin_function
DECL|function|jumpToNextImage
name|void
name|tst_QIcoImageFormat
operator|::
name|jumpToNextImage
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QImageReader
name|reader
argument_list|(
name|m_IconPath
operator|+
literal|"/"
operator|+
name|fileName
argument_list|)
decl_stmt|;
name|bool
name|bJumped
init|=
name|reader
operator|.
name|jumpToImage
argument_list|(
literal|0
argument_list|)
decl_stmt|;
while|while
condition|(
name|bJumped
condition|)
block|{
name|count
operator|--
expr_stmt|;
name|bJumped
operator|=
name|reader
operator|.
name|jumpToNextImage
argument_list|()
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|count
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loopCount_data
name|void
name|tst_QIcoImageFormat
operator|::
name|loopCount_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"count"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"floppy (16px,32px - 16 colors)"
argument_list|)
operator|<<
literal|"valid/35FLOPPY.ICO"
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid floppy (first 8 bytes = 0xff)"
argument_list|)
operator|<<
literal|"invalid/35floppy.ico"
operator|<<
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loopCount
name|void
name|tst_QIcoImageFormat
operator|::
name|loopCount
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QImageReader
name|reader
argument_list|(
name|m_IconPath
operator|+
literal|"/"
operator|+
name|fileName
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|reader
operator|.
name|loopCount
argument_list|()
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nextImageDelay_data
name|void
name|tst_QIcoImageFormat
operator|::
name|nextImageDelay_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"count"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"floppy (16px,32px - 16 colors)"
argument_list|)
operator|<<
literal|"valid/35FLOPPY.ICO"
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px,48px - 256,16M colors"
argument_list|)
operator|<<
literal|"valid/abcardWindow.ico"
operator|<<
literal|6
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px - 16 colors"
argument_list|)
operator|<<
literal|"valid/App.ico"
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px,48px - 16,256,16M colors"
argument_list|)
operator|<<
literal|"valid/Obj_N2_Internal_Mem.ico"
operator|<<
literal|9
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px - 16,256,16M colors"
argument_list|)
operator|<<
literal|"valid/Status_Play.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px,32px - 16 colors"
argument_list|)
operator|<<
literal|"valid/TIMER01.ICO"
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px16c, 32px32c, 32px256c"
argument_list|)
operator|<<
literal|"valid/WORLD.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"16px16c, 32px32c, 32px256c"
argument_list|)
operator|<<
literal|"valid/WORLDH.ico"
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid floppy (first 8 bytes = 0xff)"
argument_list|)
operator|<<
literal|"invalid/35floppy.ico"
operator|<<
operator|-
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"includes 32BPP w/alpha"
argument_list|)
operator|<<
literal|"valid/semitransparent.ico"
operator|<<
literal|9
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"PNG compression"
argument_list|)
operator|<<
literal|"valid/Qt.ico"
operator|<<
literal|4
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nextImageDelay
name|void
name|tst_QIcoImageFormat
operator|::
name|nextImageDelay
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QImageReader
name|reader
argument_list|(
name|m_IconPath
operator|+
literal|"/"
operator|+
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|count
operator|==
operator|-
literal|1
condition|)
block|{
name|QCOMPARE
argument_list|(
name|reader
operator|.
name|nextImageDelay
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
name|QVERIFY
argument_list|(
name|reader
operator|.
name|jumpToImage
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|reader
operator|.
name|nextImageDelay
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|pngCompression_data
name|void
name|tst_QIcoImageFormat
operator|::
name|pngCompression_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"index"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"width"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"height"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"PNG compression"
argument_list|)
operator|<<
literal|"valid/Qt.ico"
operator|<<
literal|4
operator|<<
literal|256
operator|<<
literal|256
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pngCompression
name|void
name|tst_QIcoImageFormat
operator|::
name|pngCompression
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|width
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|QImageReader
name|reader
argument_list|(
name|m_IconPath
operator|+
literal|"/"
operator|+
name|fileName
argument_list|)
decl_stmt|;
name|QImage
name|image
decl_stmt|;
name|reader
operator|.
name|jumpToImage
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|reader
operator|.
name|read
argument_list|(
operator|&
name|image
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|width
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
name|height
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QIcoImageFormat
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qicoimageformat.moc"
end_include
end_unit
