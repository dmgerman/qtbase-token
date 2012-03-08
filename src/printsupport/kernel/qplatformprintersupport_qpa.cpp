begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformprintersupport_qpa.h"
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/qprinterinfo.h>
end_include
begin_include
include|#
directive|include
file|<private/qprinterinfo_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QPlatformPrinterSupport
name|QPlatformPrinterSupport
operator|::
name|QPlatformPrinterSupport
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~QPlatformPrinterSupport
name|QPlatformPrinterSupport
operator|::
name|~
name|QPlatformPrinterSupport
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|createNativePrintEngine
name|QPrintEngine
modifier|*
name|QPlatformPrinterSupport
operator|::
name|createNativePrintEngine
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createPaintEngine
name|QPaintEngine
modifier|*
name|QPlatformPrinterSupport
operator|::
name|createPaintEngine
parameter_list|(
name|QPrintEngine
modifier|*
parameter_list|,
name|QPrinter
operator|::
name|PrinterMode
parameter_list|)
block|{
return|return
literal|0
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
name|QPlatformPrinterSupport
operator|::
name|supportedPaperSizes
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
parameter_list|)
specifier|const
block|{
return|return
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|availablePrinters
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|QPlatformPrinterSupport
operator|::
name|availablePrinters
parameter_list|()
block|{
return|return
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultPrinter
name|QPrinterInfo
name|QPlatformPrinterSupport
operator|::
name|defaultPrinter
parameter_list|()
block|{
specifier|const
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|printers
init|=
name|availablePrinters
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QPrinterInfo
modifier|&
name|printerInfo
decl|,
name|printers
control|)
block|{
if|if
condition|(
name|printerInfo
operator|.
name|isDefault
argument_list|()
condition|)
return|return
name|printerInfo
return|;
block|}
return|return
name|printers
operator|.
name|isEmpty
argument_list|()
condition|?
name|QPrinterInfo
argument_list|()
else|:
name|printers
operator|.
name|front
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|printerInfo
name|QPrinterInfo
name|QPlatformPrinterSupport
operator|::
name|printerInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|printerName
parameter_list|,
name|bool
name|isDefault
parameter_list|)
block|{
name|QPrinterInfo
name|pi
init|=
name|QPrinterInfo
argument_list|(
name|printerName
argument_list|)
decl_stmt|;
name|pi
operator|.
name|d_func
argument_list|()
operator|->
name|isDefault
operator|=
name|isDefault
expr_stmt|;
return|return
name|pi
return|;
block|}
end_function
begin_function
DECL|function|setPrinterInfoDefault
name|void
name|QPlatformPrinterSupport
operator|::
name|setPrinterInfoDefault
parameter_list|(
name|QPrinterInfo
modifier|*
name|p
parameter_list|,
name|bool
name|isDefault
parameter_list|)
block|{
name|p
operator|->
name|d_func
argument_list|()
operator|->
name|isDefault
operator|=
name|isDefault
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printerInfoIsDefault
name|bool
name|QPlatformPrinterSupport
operator|::
name|printerInfoIsDefault
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
name|p
parameter_list|)
block|{
return|return
name|p
operator|.
name|d_func
argument_list|()
operator|->
name|isDefault
return|;
block|}
end_function
begin_function
DECL|function|printerInfoCupsPrinterIndex
name|int
name|QPlatformPrinterSupport
operator|::
name|printerInfoCupsPrinterIndex
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
name|p
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CUPS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
return|return
name|p
operator|.
name|isNull
argument_list|()
condition|?
operator|-
literal|1
else|:
name|p
operator|.
name|d_func
argument_list|()
operator|->
name|cupsPrinterIndex
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|p
argument_list|)
return|return
operator|-
literal|1
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|setPrinterInfoCupsPrinterIndex
name|void
name|QPlatformPrinterSupport
operator|::
name|setPrinterInfoCupsPrinterIndex
parameter_list|(
name|QPrinterInfo
modifier|*
name|p
parameter_list|,
name|int
name|index
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CUPS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
name|p
operator|->
name|d_func
argument_list|()
operator|->
name|cupsPrinterIndex
operator|=
name|index
expr_stmt|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|p
argument_list|)
name|Q_UNUSED
argument_list|(
argument|index
argument_list|)
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*     Converts QSizeF in millimeters to a predefined PaperSize (returns Custom if     the size isn't a standard size) */
end_comment
begin_function
DECL|function|convertQSizeFToPaperSize
name|QPrinter
operator|::
name|PaperSize
name|QPlatformPrinterSupport
operator|::
name|convertQSizeFToPaperSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|sizef
parameter_list|)
block|{
specifier|extern
name|QPrinter
operator|::
name|PaperSize
name|qSizeFTopaperSize
argument_list|(
specifier|const
name|QSizeF
operator|&
argument_list|)
decl_stmt|;
return|return
name|qSizeFTopaperSize
argument_list|(
name|sizef
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*     Converts a predefined PaperSize to a QSizeF in millimeters (returns     QSizeF(0.0, 0.0) if PaperSize is Custom) */
end_comment
begin_function
DECL|function|convertPaperSizeToQSizeF
name|QSizeF
name|QPlatformPrinterSupport
operator|::
name|convertPaperSizeToQSizeF
parameter_list|(
name|QPrinter
operator|::
name|PaperSize
name|paperSize
parameter_list|)
block|{
specifier|extern
name|QSizeF
name|qt_paperSizeToQSizeF
argument_list|(
name|QPrinter
operator|::
name|PaperSize
name|size
argument_list|)
decl_stmt|;
return|return
name|qt_paperSizeToQSizeF
argument_list|(
name|paperSize
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
end_unit
