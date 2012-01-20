begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsprintersupport.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/QPrinterInfo>
end_include
begin_include
include|#
directive|include
file|<qprintengine_win_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_alpha_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qprinterinfo_p.h>
end_include
begin_constructor
DECL|function|QWindowsPrinterSupport
name|QWindowsPrinterSupport
operator|::
name|QWindowsPrinterSupport
parameter_list|()
member_init_list|:
name|QPlatformPrinterSupport
argument_list|()
block|{
name|DWORD
name|needed
init|=
literal|0
decl_stmt|;
name|DWORD
name|returned
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|EnumPrinters
argument_list|(
name|PRINTER_ENUM_LOCAL
operator||
name|PRINTER_ENUM_CONNECTIONS
argument_list|,
name|NULL
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|needed
argument_list|,
operator|&
name|returned
argument_list|)
condition|)
block|{
name|LPBYTE
name|buffer
init|=
operator|new
name|BYTE
index|[
name|needed
index|]
decl_stmt|;
if|if
condition|(
name|EnumPrinters
argument_list|(
name|PRINTER_ENUM_LOCAL
operator||
name|PRINTER_ENUM_CONNECTIONS
argument_list|,
name|NULL
argument_list|,
literal|4
argument_list|,
name|buffer
argument_list|,
name|needed
argument_list|,
operator|&
name|needed
argument_list|,
operator|&
name|returned
argument_list|)
condition|)
block|{
name|PPRINTER_INFO_4
name|infoList
init|=
cast|reinterpret_cast
argument_list|<
name|PPRINTER_INFO_4
argument_list|>
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|QPrinterInfo
name|defPrn
init|=
name|defaultPrinter
argument_list|()
decl_stmt|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
name|returned
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|printerName
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|infoList
index|[
name|i
index|]
operator|.
name|pPrinterName
argument_list|)
argument_list|)
decl_stmt|;
name|QPrinterInfo
name|printerInfo
argument_list|(
name|printerName
argument_list|)
decl_stmt|;
if|if
condition|(
name|printerInfo
operator|.
name|printerName
argument_list|()
operator|==
name|defPrn
operator|.
name|printerName
argument_list|()
condition|)
name|printerInfo
operator|.
name|d_ptr
operator|->
name|isDefault
operator|=
literal|true
expr_stmt|;
name|mPrinterList
operator|.
name|append
argument_list|(
name|printerInfo
argument_list|)
expr_stmt|;
block|}
block|}
operator|delete
index|[]
name|buffer
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsPrinterSupport
name|QWindowsPrinterSupport
operator|::
name|~
name|QWindowsPrinterSupport
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|createNativePrintEngine
name|QPrintEngine
modifier|*
name|QWindowsPrinterSupport
operator|::
name|createNativePrintEngine
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
parameter_list|)
block|{
return|return
operator|new
name|QWin32PrintEngine
argument_list|(
name|printerMode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPaintEngine
name|QPaintEngine
modifier|*
name|QWindowsPrinterSupport
operator|::
name|createPaintEngine
parameter_list|(
name|QPrintEngine
modifier|*
name|engine
parameter_list|,
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|printerMode
argument_list|)
return|return
cast|static_cast
argument_list|<
name|QWin32PrintEngine
operator|*
argument_list|>
argument_list|(
name|engine
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportedPaperSizes
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|QWindowsPrinterSupport
operator|::
name|supportedPaperSizes
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|returnList
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QPrinterInfo
modifier|&
name|info
decl|,
name|mPrinterList
control|)
block|{
foreach|foreach
control|(
specifier|const
name|QPrinter
operator|::
name|PaperSize
name|supportedSize
decl|,
name|info
operator|.
name|supportedPaperSizes
argument_list|()
control|)
if|if
condition|(
operator|!
name|returnList
operator|.
name|contains
argument_list|(
name|supportedSize
argument_list|)
condition|)
name|returnList
operator|.
name|append
argument_list|(
name|supportedSize
argument_list|)
expr_stmt|;
block|}
return|return
name|returnList
return|;
block|}
end_function
begin_function
DECL|function|availablePrinters
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|QWindowsPrinterSupport
operator|::
name|availablePrinters
parameter_list|()
block|{
return|return
name|mPrinterList
return|;
block|}
end_function
end_unit
