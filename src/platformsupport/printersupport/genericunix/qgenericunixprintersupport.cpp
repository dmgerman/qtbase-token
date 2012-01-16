begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgenericunixprintersupport_p.h"
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/QPrinterInfo>
end_include
begin_include
include|#
directive|include
file|<private/qcups_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|supportedPaperSizes
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|QGenericUnixPrinterSupport
operator|::
name|supportedPaperSizes
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
name|printerInfo
parameter_list|)
specifier|const
block|{
ifndef|#
directive|ifndef
name|QT_NO_CUPS
return|return
name|QCUPSSupport
operator|::
name|getCupsPrinterPaperSizes
argument_list|(
name|QPlatformPrinterSupport
operator|::
name|printerInfoCupsPrinterIndex
argument_list|(
name|printerInfo
argument_list|)
argument_list|)
return|;
else|#
directive|else
return|return
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|availablePrinters
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|QGenericUnixPrinterSupport
operator|::
name|availablePrinters
parameter_list|()
block|{
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|printers
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CUPS
foreach|foreach
control|(
specifier|const
name|QCUPSSupport
operator|::
name|Printer
modifier|&
name|p
decl|,
name|QCUPSSupport
operator|::
name|availableUnixPrinters
argument_list|()
control|)
block|{
name|QPrinterInfo
name|printer
argument_list|(
name|QPlatformPrinterSupport
operator|::
name|printerInfo
argument_list|(
name|p
operator|.
name|name
argument_list|,
name|p
operator|.
name|isDefault
argument_list|)
argument_list|)
decl_stmt|;
name|QPlatformPrinterSupport
operator|::
name|setPrinterInfoCupsPrinterIndex
argument_list|(
operator|&
name|printer
argument_list|,
name|p
operator|.
name|cupsPrinterIndex
argument_list|)
expr_stmt|;
name|printers
operator|.
name|append
argument_list|(
name|printer
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|printers
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
