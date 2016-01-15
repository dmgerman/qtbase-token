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
file|<qabstractprintdialog.h>
end_include
begin_include
include|#
directive|include
file|<qprinter.h>
end_include
begin_class
DECL|class|tst_QAbstractPrintDialog
class|class
name|tst_QAbstractPrintDialog
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_PRINTER
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_NO_PRINTDIALOG
argument_list|)
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
else|#
directive|else
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|setMinMax
parameter_list|()
function_decl|;
name|void
name|setFromTo
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_PRINTER
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_NO_PRINTDIALOG
argument_list|)
end_if
begin_function
DECL|function|initTestCase
name|void
name|tst_QAbstractPrintDialog
operator|::
name|initTestCase
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"This test requires printing and print dialog support"
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_class
DECL|class|MyAbstractPrintDialog
class|class
name|MyAbstractPrintDialog
super|:
specifier|public
name|QAbstractPrintDialog
block|{
public|public:
DECL|function|MyAbstractPrintDialog
name|MyAbstractPrintDialog
parameter_list|(
name|QPrinter
modifier|*
name|p
parameter_list|)
member_init_list|:
name|QAbstractPrintDialog
argument_list|(
name|p
argument_list|)
block|{}
DECL|function|exec
name|int
name|exec
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QAbstractPrintDialog
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QPrinter
name|printer
decl_stmt|;
name|MyAbstractPrintDialog
name|obj1
argument_list|(
operator|&
name|printer
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|printer
argument_list|()
argument_list|,
operator|&
name|printer
argument_list|)
expr_stmt|;
comment|// PrintDialogOptions QAbstractPrintDialog::enabledOptions()
comment|// void QAbstractPrintDialog::setEnabledOptions(PrintDialogOptions)
name|obj1
operator|.
name|setEnabledOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|None
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|None
argument_list|)
argument_list|,
name|obj1
operator|.
name|enabledOptions
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setEnabledOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintToFile
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintToFile
argument_list|)
argument_list|,
name|obj1
operator|.
name|enabledOptions
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setEnabledOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintSelection
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintSelection
argument_list|)
argument_list|,
name|obj1
operator|.
name|enabledOptions
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setEnabledOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintPageRange
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintPageRange
argument_list|)
argument_list|,
name|obj1
operator|.
name|enabledOptions
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setEnabledOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintCollateCopies
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintCollateCopies
argument_list|)
argument_list|,
name|obj1
operator|.
name|enabledOptions
argument_list|()
argument_list|)
expr_stmt|;
comment|// PrintRange QAbstractPrintDialog::printRange()
comment|// void QAbstractPrintDialog::setPrintRange(PrintRange)
name|obj1
operator|.
name|setPrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|AllPages
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|AllPages
argument_list|)
argument_list|,
name|obj1
operator|.
name|printRange
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setPrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|Selection
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|Selection
argument_list|)
argument_list|,
name|obj1
operator|.
name|printRange
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setPrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PageRange
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintRange
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PageRange
argument_list|)
argument_list|,
name|obj1
operator|.
name|printRange
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setMinMax
name|void
name|tst_QAbstractPrintDialog
operator|::
name|setMinMax
parameter_list|()
block|{
name|QPrinter
name|printer
decl_stmt|;
name|MyAbstractPrintDialog
name|obj1
argument_list|(
operator|&
name|printer
argument_list|)
decl_stmt|;
name|obj1
operator|.
name|setEnabledOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
argument_list|(
name|QAbstractPrintDialog
operator|::
name|None
argument_list|)
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-22637"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|minPage
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|maxPage
argument_list|()
argument_list|,
name|INT_MAX
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|obj1
operator|.
name|isOptionEnabled
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintPageRange
argument_list|)
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinMax
argument_list|(
literal|2
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|minPage
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|maxPage
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|obj1
operator|.
name|enabledOptions
argument_list|()
operator|&
name|QAbstractPrintDialog
operator|::
name|PrintPageRange
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|obj1
operator|.
name|isOptionEnabled
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintPageRange
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFromTo
name|void
name|tst_QAbstractPrintDialog
operator|::
name|setFromTo
parameter_list|()
block|{
name|QPrinter
name|printer
decl_stmt|;
name|MyAbstractPrintDialog
name|obj1
argument_list|(
operator|&
name|printer
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|fromPage
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|toPage
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinMax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|minPage
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|maxPage
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setFromTo
argument_list|(
literal|20
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|fromPage
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|toPage
argument_list|()
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|minPage
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|maxPage
argument_list|()
argument_list|,
literal|50
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAbstractPrintDialog
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qabstractprintdialog.moc"
end_include
end_unit
