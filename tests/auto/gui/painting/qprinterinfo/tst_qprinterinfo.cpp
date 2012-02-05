begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGlobal>
end_include
begin_include
include|#
directive|include
file|<QtAlgorithms>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QHostInfo>
end_include
begin_include
include|#
directive|include
file|<qprinterinfo.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/wait.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QRect
argument_list|)
end_macro
begin_class
DECL|class|tst_QPrinterInfo
class|class
name|tst_QPrinterInfo
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
ifdef|#
directive|ifdef
name|QT_NO_PRINTER
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
name|testForDefaultPrinter
parameter_list|()
function_decl|;
name|void
name|testForPrinters
parameter_list|()
function_decl|;
name|void
name|testForPaperSizes
parameter_list|()
function_decl|;
name|void
name|testConstructors
parameter_list|()
function_decl|;
name|void
name|testAssignment
parameter_list|()
function_decl|;
private|private:
name|void
name|macFixNameFormat
parameter_list|(
name|QString
modifier|*
name|printerName
parameter_list|)
function_decl|;
name|QString
name|getDefaultPrinterFromSystem
parameter_list|()
function_decl|;
name|QStringList
name|getPrintersFromSystem
parameter_list|()
function_decl|;
name|QString
name|getOutputFromCommand
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|command
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_PRINTER
end_ifdef
begin_function
DECL|function|initTestCase
name|void
name|tst_QPrinterInfo
operator|::
name|initTestCase
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"This test requires printing support"
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|macFixNameFormat
name|void
name|tst_QPrinterInfo
operator|::
name|macFixNameFormat
parameter_list|(
name|QString
modifier|*
name|printerName
parameter_list|)
block|{
comment|// Modify the format of the printer name to match Qt, lpstat returns
comment|// foo___domain_no, Qt returns foo @ domain.no
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|printerName
operator|->
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"___"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|" @ "
argument_list|)
argument_list|)
expr_stmt|;
name|printerName
operator|->
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"_"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|printerName
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|getDefaultPrinterFromSystem
name|QString
name|tst_QPrinterInfo
operator|::
name|getDefaultPrinterFromSystem
parameter_list|()
block|{
name|QStringList
name|command
decl_stmt|;
name|command
operator|<<
literal|"lpstat"
operator|<<
literal|"-d"
expr_stmt|;
name|QString
name|output
init|=
name|getOutputFromCommand
argument_list|(
name|command
argument_list|)
decl_stmt|;
name|QRegExp
name|noDefaultReg
argument_list|(
literal|"[^:]*no .*default"
argument_list|)
decl_stmt|;
name|int
name|pos
init|=
name|noDefaultReg
operator|.
name|indexIn
argument_list|(
name|output
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|>=
literal|0
condition|)
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|QRegExp
name|defaultReg
argument_list|(
literal|"default.*: *([a-zA-Z0-9_]+)"
argument_list|)
decl_stmt|;
name|defaultReg
operator|.
name|indexIn
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|QString
name|printer
init|=
name|defaultReg
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|macFixNameFormat
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
return|return
name|printer
return|;
block|}
end_function
begin_function
DECL|function|getPrintersFromSystem
name|QStringList
name|tst_QPrinterInfo
operator|::
name|getPrintersFromSystem
parameter_list|()
block|{
name|QStringList
name|ans
decl_stmt|;
name|QStringList
name|command
decl_stmt|;
name|command
operator|<<
literal|"lpstat"
operator|<<
literal|"-p"
expr_stmt|;
name|QString
name|output
init|=
name|getOutputFromCommand
argument_list|(
name|command
argument_list|)
decl_stmt|;
name|QStringList
name|list
init|=
name|output
operator|.
name|split
argument_list|(
name|QChar
operator|::
name|fromLatin1
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
decl_stmt|;
name|QRegExp
name|reg
argument_list|(
literal|"^[Pp]rinter ([.a-zA-Z0-9-_@]+)"
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
if|if
condition|(
name|reg
operator|.
name|indexIn
argument_list|(
name|list
index|[
name|c
index|]
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|QString
name|printer
init|=
name|reg
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|macFixNameFormat
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
name|ans
operator|<<
name|printer
expr_stmt|;
block|}
block|}
return|return
name|ans
return|;
block|}
end_function
begin_comment
comment|// This function does roughly the same as the `command substitution` in
end_comment
begin_comment
comment|// the shell.
end_comment
begin_function
DECL|function|getOutputFromCommand
name|QString
name|tst_QPrinterInfo
operator|::
name|getOutputFromCommand
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|command
parameter_list|)
block|{
comment|// The command execution does nothing on non-unix systems.
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|int
name|pid
decl_stmt|;
name|int
name|status
init|=
literal|0
decl_stmt|;
name|int
name|pipePtr
index|[
literal|2
index|]
decl_stmt|;
comment|// Create a pipe that is shared between parent and child process.
if|if
condition|(
name|pipe
argument_list|(
name|pipePtr
argument_list|)
operator|<
literal|0
condition|)
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|pid
operator|=
name|fork
argument_list|()
expr_stmt|;
if|if
condition|(
name|pid
operator|<
literal|0
condition|)
block|{
name|close
argument_list|(
name|pipePtr
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|pipePtr
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
name|pid
operator|==
literal|0
condition|)
block|{
comment|// In child.
comment|// Close the reading end.
name|close
argument_list|(
name|pipePtr
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// Redirect stdout to the pipe.
if|if
condition|(
name|dup2
argument_list|(
name|pipePtr
index|[
literal|1
index|]
argument_list|,
literal|1
argument_list|)
operator|<
literal|0
condition|)
block|{
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|char
modifier|*
modifier|*
name|argv
init|=
operator|new
name|char
operator|*
index|[
name|command
operator|.
name|size
argument_list|()
operator|+
literal|1
index|]
decl_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|command
operator|.
name|size
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
name|argv
index|[
name|c
index|]
operator|=
operator|new
name|char
index|[
name|command
index|[
name|c
index|]
operator|.
name|size
argument_list|()
operator|+
literal|1
index|]
expr_stmt|;
name|strcpy
argument_list|(
name|argv
index|[
name|c
index|]
argument_list|,
name|command
index|[
name|c
index|]
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|argv
index|[
name|command
operator|.
name|size
argument_list|()
index|]
operator|=
name|NULL
expr_stmt|;
name|execvp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|// Shouldn't get here, but it's possible if command is not found.
name|close
argument_list|(
name|pipePtr
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|command
operator|.
name|size
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
operator|delete
index|[]
name|argv
index|[
name|c
index|]
expr_stmt|;
block|}
operator|delete
index|[]
name|argv
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// In parent.
comment|// Close the writing end.
name|close
argument_list|(
name|pipePtr
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|QFile
name|pipeRead
decl_stmt|;
if|if
condition|(
operator|!
name|pipeRead
operator|.
name|open
argument_list|(
name|pipePtr
index|[
literal|0
index|]
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|close
argument_list|(
name|pipePtr
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
name|QByteArray
name|array
decl_stmt|;
name|array
operator|=
name|pipeRead
operator|.
name|readAll
argument_list|()
expr_stmt|;
name|pipeRead
operator|.
name|close
argument_list|()
expr_stmt|;
name|close
argument_list|(
name|pipePtr
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|wait
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|(
name|array
argument_list|)
return|;
block|}
else|#
directive|else
return|return
name|QString
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|testForDefaultPrinter
name|void
name|tst_QPrinterInfo
operator|::
name|testForDefaultPrinter
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WIN32
if|if
condition|(
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|==
literal|"fantomet"
operator|||
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|==
literal|"bobo"
condition|)
block|{
name|QWARN
argument_list|(
literal|"Test is hardcoded to \"fantomet\" and \"bobo\" on Windows and may fail"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QSKIP
argument_list|(
literal|"Test is hardcoded to \"fantomet\" and \"bobo\" on Windows"
argument_list|)
expr_stmt|;
block|}
name|QString
name|defSysPrinter
decl_stmt|;
if|if
condition|(
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|==
literal|"fantomet"
condition|)
block|{
name|defSysPrinter
operator|=
literal|"Yacc (Lexmark Optra T610 PS3)"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|==
literal|"bobo"
condition|)
block|{
name|defSysPrinter
operator|=
literal|"press"
expr_stmt|;
block|}
else|#
directive|else
name|QString
name|defSysPrinter
init|=
name|getDefaultPrinterFromSystem
argument_list|()
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|defSysPrinter
operator|==
literal|""
condition|)
return|return;
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|list
init|=
name|QPrinterInfo
operator|::
name|availablePrinters
argument_list|()
decl_stmt|;
name|bool
name|found
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
if|if
condition|(
name|list
index|[
name|c
index|]
operator|.
name|isDefault
argument_list|()
condition|)
block|{
name|QVERIFY
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|c
argument_list|)
operator|.
name|printerName
argument_list|()
operator|==
name|defSysPrinter
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|list
operator|.
name|at
argument_list|(
name|c
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|found
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|QVERIFY
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|c
argument_list|)
operator|.
name|printerName
argument_list|()
operator|!=
name|defSysPrinter
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|list
operator|.
name|at
argument_list|(
name|c
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|found
operator|&&
name|defSysPrinter
operator|!=
literal|""
condition|)
name|QFAIL
argument_list|(
literal|"No default printer reported by Qt, although there is one"
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Test doesn't work on non-Unix"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|testForPrinters
name|void
name|tst_QPrinterInfo
operator|::
name|testForPrinters
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WIN32
if|if
condition|(
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|==
literal|"fantomet"
operator|||
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|==
literal|"bobo"
condition|)
block|{
name|QWARN
argument_list|(
literal|"Test is hardcoded to \"fantomet\" and \"bobo\" on Windows and may fail"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QSKIP
argument_list|(
literal|"Test is hardcoded to \"fantomet\" and \"bobo\" on Windows"
argument_list|)
expr_stmt|;
block|}
name|QStringList
name|sysPrinters
decl_stmt|;
if|if
condition|(
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|==
literal|"fantomet"
condition|)
block|{
name|sysPrinters
operator|<<
literal|"Press"
operator|<<
literal|"Canon PS-IPU Color Laser Copier v52.3"
operator|<<
literal|"EPSON EPL-N4000 PS3"
operator|<<
literal|"Kroksleiven"
operator|<<
literal|"Lexmark Optra Color 1200 PS"
operator|<<
literal|"Yacc (Lexmark Optra T610 PCL)"
operator|<<
literal|"Yacc (Lexmark Optra T610 PS3)"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|==
literal|"bobo"
condition|)
block|{
name|sysPrinters
operator|<<
literal|"press"
operator|<<
literal|"finnmarka"
operator|<<
literal|"nordmarka"
expr_stmt|;
block|}
else|#
directive|else
name|QStringList
name|sysPrinters
init|=
name|getPrintersFromSystem
argument_list|()
decl_stmt|;
endif|#
directive|endif
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|printers
init|=
name|QPrinterInfo
operator|::
name|availablePrinters
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|printers
operator|.
name|size
argument_list|()
argument_list|,
name|sysPrinters
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|bool
argument_list|>
name|qtPrinters
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|printers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
name|qtPrinters
operator|.
name|insert
argument_list|(
name|printers
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|.
name|printerName
argument_list|()
argument_list|,
operator|!
name|printers
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|sysPrinters
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|qtPrinters
operator|.
name|value
argument_list|(
name|sysPrinters
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Available printers: "
operator|<<
name|qtPrinters
expr_stmt|;
name|QFAIL
argument_list|(
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"Printer '%1' reported by system, but not reported by Qt"
argument_list|)
operator|.
name|arg
argument_list|(
name|sysPrinters
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Test doesn't work on non-Unix"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|testForPaperSizes
name|void
name|tst_QPrinterInfo
operator|::
name|testForPaperSizes
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"PaperSize feature doesn't work on Windows, fails on Mac, and is unstable on Linux"
argument_list|)
expr_stmt|;
comment|// This test is based on common printers found at the Oslo
comment|// office. It is likely to be skipped or fail for other locations.
name|QStringList
name|hardPrinters
decl_stmt|;
name|hardPrinters
operator|<<
literal|"Finnmarka"
operator|<<
literal|"Huldra"
expr_stmt|;
name|QList
argument_list|<
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
argument_list|>
name|hardSizes
decl_stmt|;
name|hardSizes
operator|<<
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
argument_list|()
operator|<<
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
argument_list|()
expr_stmt|;
name|hardSizes
index|[
literal|0
index|]
comment|// Finnmarka
operator|<<
name|QPrinter
operator|::
name|Letter
operator|<<
name|QPrinter
operator|::
name|A4
operator|<<
name|QPrinter
operator|::
name|A3
operator|<<
name|QPrinter
operator|::
name|A5
operator|<<
name|QPrinter
operator|::
name|B4
operator|<<
name|QPrinter
operator|::
name|B5
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// COM10
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// C5
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// DL
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// Monarch
operator|<<
name|QPrinter
operator|::
name|Executive
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// Foolscap
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// ISO B5
operator|<<
name|QPrinter
operator|::
name|Ledger
operator|<<
name|QPrinter
operator|::
name|Legal
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// Japanese Post Card
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// Invoice
expr_stmt|;
name|hardSizes
index|[
literal|1
index|]
comment|// Huldra
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// Not listed at http://localhost:631/, name "Custom"
operator|<<
name|QPrinter
operator|::
name|Letter
operator|<<
name|QPrinter
operator|::
name|A4
operator|<<
name|QPrinter
operator|::
name|A5
operator|<<
name|QPrinter
operator|::
name|A6
operator|<<
name|QPrinter
operator|::
name|B5
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// #5 1/2 Envelope
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// 6x9 Envelope
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// #10 Envelope
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// A7 Envelope
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// C5 Envelope
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// DL Envelope
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// Monarch Envelope
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// #6 3/4 Envelope
operator|<<
name|QPrinter
operator|::
name|Executive
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// US Folio
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// Index Card
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// ISO B5
operator|<<
name|QPrinter
operator|::
name|Legal
operator|<<
name|QPrinter
operator|::
name|Custom
comment|// Statement
expr_stmt|;
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|printers
init|=
name|QPrinterInfo
operator|::
name|availablePrinters
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
name|printers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|hardPrinters
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|printers
index|[
name|i
index|]
operator|.
name|printerName
argument_list|()
operator|==
name|hardPrinters
index|[
name|j
index|]
condition|)
block|{
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|sizes
init|=
name|printers
index|[
name|i
index|]
operator|.
name|supportedPaperSizes
argument_list|()
decl_stmt|;
name|qSort
argument_list|(
name|sizes
argument_list|)
expr_stmt|;
name|qSort
argument_list|(
name|hardSizes
index|[
name|j
index|]
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sizes
argument_list|,
name|hardSizes
index|[
name|j
index|]
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|testConstructors
name|void
name|tst_QPrinterInfo
operator|::
name|testConstructors
parameter_list|()
block|{
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|prns
argument_list|(
name|QPrinterInfo
operator|::
name|availablePrinters
argument_list|()
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|prns
operator|.
name|size
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|list1
decl_stmt|,
name|list2
decl_stmt|;
name|list1
operator|=
name|prns
index|[
name|c
index|]
operator|.
name|supportedPaperSizes
argument_list|()
expr_stmt|;
name|QPrinter
name|pr
argument_list|(
name|prns
index|[
name|c
index|]
argument_list|)
decl_stmt|;
name|list2
operator|=
name|QPrinterInfo
argument_list|(
name|pr
argument_list|)
operator|.
name|supportedPaperSizes
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list2
argument_list|,
name|list1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|testAssignment
name|void
name|tst_QPrinterInfo
operator|::
name|testAssignment
parameter_list|()
block|{
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|prns
argument_list|(
name|QPrinterInfo
operator|::
name|availablePrinters
argument_list|()
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|prns
operator|.
name|size
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
name|QPrinterInfo
name|pi
init|=
name|QPrinterInfo
operator|::
name|defaultPrinter
argument_list|()
decl_stmt|;
name|pi
operator|=
name|prns
index|[
name|c
index|]
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pi
operator|.
name|printerName
argument_list|()
argument_list|,
name|prns
index|[
name|c
index|]
operator|.
name|printerName
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pi
operator|.
name|supportedPaperSizes
argument_list|()
argument_list|,
name|prns
index|[
name|c
index|]
operator|.
name|supportedPaperSizes
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPrinterInfo
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qprinterinfo.moc"
end_include
end_unit
