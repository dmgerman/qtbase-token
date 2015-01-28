begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qprintengine_pdf_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|<qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qbuffer.h>
end_include
begin_include
include|#
directive|include
file|"qprinterinfo.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagelayout.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// overrides QT_OPEN
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<io.h>
end_include
begin_comment
comment|// _close.
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QPdfPrintEngine
name|QPdfPrintEngine
operator|::
name|QPdfPrintEngine
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
name|m
parameter_list|)
member_init_list|:
name|QPdfEngine
argument_list|(
operator|*
operator|new
name|QPdfPrintEnginePrivate
argument_list|(
name|m
argument_list|)
argument_list|)
block|{
name|state
operator|=
name|QPrinter
operator|::
name|Idle
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QPdfPrintEngine
name|QPdfPrintEngine
operator|::
name|QPdfPrintEngine
parameter_list|(
name|QPdfPrintEnginePrivate
modifier|&
name|p
parameter_list|)
member_init_list|:
name|QPdfEngine
argument_list|(
name|p
argument_list|)
block|{
name|state
operator|=
name|QPrinter
operator|::
name|Idle
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QPdfPrintEngine
name|QPdfPrintEngine
operator|::
name|~
name|QPdfPrintEngine
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|begin
name|bool
name|QPdfPrintEngine
operator|::
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|pdev
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPdfPrintEngine
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|openPrintDevice
argument_list|()
condition|)
block|{
name|state
operator|=
name|QPrinter
operator|::
name|Error
expr_stmt|;
return|return
literal|false
return|;
block|}
name|state
operator|=
name|QPrinter
operator|::
name|Active
expr_stmt|;
return|return
name|QPdfEngine
operator|::
name|begin
argument_list|(
name|pdev
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|end
name|bool
name|QPdfPrintEngine
operator|::
name|end
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPdfPrintEngine
argument_list|)
expr_stmt|;
name|QPdfEngine
operator|::
name|end
argument_list|()
expr_stmt|;
name|d
operator|->
name|closePrintDevice
argument_list|()
expr_stmt|;
name|state
operator|=
name|QPrinter
operator|::
name|Idle
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|newPage
name|bool
name|QPdfPrintEngine
operator|::
name|newPage
parameter_list|()
block|{
return|return
name|QPdfEngine
operator|::
name|newPage
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|metric
name|int
name|QPdfPrintEngine
operator|::
name|metric
parameter_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|m
parameter_list|)
specifier|const
block|{
return|return
name|QPdfEngine
operator|::
name|metric
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setProperty
name|void
name|QPdfPrintEngine
operator|::
name|setProperty
parameter_list|(
name|PrintEnginePropertyKey
name|key
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPdfPrintEngine
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|int
argument_list|(
name|key
argument_list|)
condition|)
block|{
comment|// The following keys are properties or derived values and so cannot be set
case|case
name|PPK_PageRect
case|:
break|break;
case|case
name|PPK_PaperRect
case|:
break|break;
case|case
name|PPK_PaperSources
case|:
break|break;
case|case
name|PPK_SupportsMultipleCopies
case|:
break|break;
case|case
name|PPK_SupportedResolutions
case|:
break|break;
comment|// The following keys are settings that are unsupported by the PDF PrintEngine
case|case
name|PPK_CustomBase
case|:
break|break;
comment|// The following keys are properties and settings that are supported by the PDF PrintEngine
case|case
name|PPK_CollateCopies
case|:
name|d
operator|->
name|collate
operator|=
name|value
operator|.
name|toBool
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_ColorMode
case|:
name|d
operator|->
name|grayscale
operator|=
operator|(
name|QPrinter
operator|::
name|ColorMode
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
operator|==
name|QPrinter
operator|::
name|GrayScale
operator|)
expr_stmt|;
break|break;
case|case
name|PPK_Creator
case|:
name|d
operator|->
name|creator
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_DocumentName
case|:
name|d
operator|->
name|title
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_FullPage
case|:
if|if
condition|(
name|value
operator|.
name|toBool
argument_list|()
condition|)
name|d
operator|->
name|m_pageLayout
operator|.
name|setMode
argument_list|(
name|QPageLayout
operator|::
name|FullPageMode
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|m_pageLayout
operator|.
name|setMode
argument_list|(
name|QPageLayout
operator|::
name|StandardMode
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_CopyCount
case|:
comment|// fallthrough
case|case
name|PPK_NumberOfCopies
case|:
name|d
operator|->
name|copies
operator|=
name|value
operator|.
name|toInt
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_Orientation
case|:
name|d
operator|->
name|m_pageLayout
operator|.
name|setOrientation
argument_list|(
name|QPageLayout
operator|::
name|Orientation
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_OutputFileName
case|:
name|d
operator|->
name|outputFileName
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_PageOrder
case|:
name|d
operator|->
name|pageOrder
operator|=
name|QPrinter
operator|::
name|PageOrder
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_PageSize
case|:
block|{
name|QPageSize
name|pageSize
init|=
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|PageSizeId
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|pageSize
operator|.
name|isValid
argument_list|()
condition|)
name|d
operator|->
name|m_pageLayout
operator|.
name|setPageSize
argument_list|(
name|pageSize
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|PPK_PaperName
case|:
block|{
name|QString
name|name
init|=
name|value
operator|.
name|toString
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
operator|<=
name|QPageSize
operator|::
name|LastPageSize
condition|;
operator|++
name|i
control|)
block|{
name|QPageSize
name|pageSize
init|=
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|PageSizeId
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|==
name|pageSize
operator|.
name|name
argument_list|()
condition|)
block|{
name|d
operator|->
name|m_pageLayout
operator|.
name|setPageSize
argument_list|(
name|pageSize
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
break|break;
block|}
case|case
name|PPK_WindowsPageSize
case|:
name|d
operator|->
name|m_pageLayout
operator|.
name|setPageSize
argument_list|(
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|id
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_PaperSource
case|:
name|d
operator|->
name|paperSource
operator|=
name|QPrinter
operator|::
name|PaperSource
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_PrinterName
case|:
name|d
operator|->
name|printerName
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_PrinterProgram
case|:
name|d
operator|->
name|printProgram
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_Resolution
case|:
name|d
operator|->
name|resolution
operator|=
name|value
operator|.
name|toInt
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_SelectionOption
case|:
name|d
operator|->
name|selectionOption
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_FontEmbedding
case|:
name|d
operator|->
name|embedFonts
operator|=
name|value
operator|.
name|toBool
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_Duplex
case|:
name|d
operator|->
name|duplex
operator|=
cast|static_cast
argument_list|<
name|QPrint
operator|::
name|DuplexMode
argument_list|>
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_CustomPaperSize
case|:
name|d
operator|->
name|m_pageLayout
operator|.
name|setPageSize
argument_list|(
name|QPageSize
argument_list|(
name|value
operator|.
name|toSizeF
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Point
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_PageMargins
case|:
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|margins
argument_list|(
name|value
operator|.
name|toList
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|margins
operator|.
name|size
argument_list|()
operator|==
literal|4
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_pageLayout
operator|.
name|setUnits
argument_list|(
name|QPageLayout
operator|::
name|Point
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_pageLayout
operator|.
name|setMargins
argument_list|(
name|QMarginsF
argument_list|(
name|margins
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toReal
argument_list|()
argument_list|,
name|margins
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toReal
argument_list|()
argument_list|,
name|margins
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|toReal
argument_list|()
argument_list|,
name|margins
operator|.
name|at
argument_list|(
literal|3
argument_list|)
operator|.
name|toReal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|PPK_QPageSize
case|:
block|{
name|QPageSize
name|pageSize
init|=
name|value
operator|.
name|value
argument_list|<
name|QPageSize
argument_list|>
argument_list|()
decl_stmt|;
if|if
condition|(
name|pageSize
operator|.
name|isValid
argument_list|()
condition|)
name|d
operator|->
name|m_pageLayout
operator|.
name|setPageSize
argument_list|(
name|pageSize
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|PPK_QPageMargins
case|:
block|{
name|QPair
argument_list|<
name|QMarginsF
argument_list|,
name|QPageLayout
operator|::
name|Unit
argument_list|>
name|pair
init|=
name|value
operator|.
name|value
argument_list|<
name|QPair
argument_list|<
name|QMarginsF
argument_list|,
name|QPageLayout
operator|::
name|Unit
argument_list|>
argument_list|>
argument_list|()
decl_stmt|;
name|d
operator|->
name|m_pageLayout
operator|.
name|setUnits
argument_list|(
name|pair
operator|.
name|second
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_pageLayout
operator|.
name|setMargins
argument_list|(
name|pair
operator|.
name|first
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|PPK_QPageLayout
case|:
block|{
name|QPageLayout
name|pageLayout
init|=
name|value
operator|.
name|value
argument_list|<
name|QPageLayout
argument_list|>
argument_list|()
decl_stmt|;
if|if
condition|(
name|pageLayout
operator|.
name|isValid
argument_list|()
condition|)
name|d
operator|->
name|m_pageLayout
operator|=
name|pageLayout
expr_stmt|;
break|break;
block|}
comment|// No default so that compiler will complain if new keys added and not handled in this engine
block|}
block|}
end_function
begin_function
DECL|function|property
name|QVariant
name|QPdfPrintEngine
operator|::
name|property
parameter_list|(
name|PrintEnginePropertyKey
name|key
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfPrintEngine
argument_list|)
expr_stmt|;
name|QVariant
name|ret
decl_stmt|;
switch|switch
condition|(
name|int
argument_list|(
name|key
argument_list|)
condition|)
block|{
comment|// The following keys are settings that are unsupported by the PDF PrintEngine
comment|// Return sensible default values to ensure consistent behavior across platforms
case|case
name|PPK_CustomBase
case|:
comment|// Special case, leave null
break|break;
comment|// The following keys are properties and settings that are supported by the PDF PrintEngine
case|case
name|PPK_CollateCopies
case|:
name|ret
operator|=
name|d
operator|->
name|collate
expr_stmt|;
break|break;
case|case
name|PPK_ColorMode
case|:
name|ret
operator|=
name|d
operator|->
name|grayscale
condition|?
name|QPrinter
operator|::
name|GrayScale
else|:
name|QPrinter
operator|::
name|Color
expr_stmt|;
break|break;
case|case
name|PPK_Creator
case|:
name|ret
operator|=
name|d
operator|->
name|creator
expr_stmt|;
break|break;
case|case
name|PPK_DocumentName
case|:
name|ret
operator|=
name|d
operator|->
name|title
expr_stmt|;
break|break;
case|case
name|PPK_FullPage
case|:
name|ret
operator|=
name|d
operator|->
name|m_pageLayout
operator|.
name|mode
argument_list|()
operator|==
name|QPageLayout
operator|::
name|FullPageMode
expr_stmt|;
break|break;
case|case
name|PPK_CopyCount
case|:
name|ret
operator|=
name|d
operator|->
name|copies
expr_stmt|;
break|break;
case|case
name|PPK_SupportsMultipleCopies
case|:
name|ret
operator|=
literal|false
expr_stmt|;
break|break;
case|case
name|PPK_NumberOfCopies
case|:
name|ret
operator|=
name|d
operator|->
name|copies
expr_stmt|;
break|break;
case|case
name|PPK_Orientation
case|:
name|ret
operator|=
name|d
operator|->
name|m_pageLayout
operator|.
name|orientation
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_OutputFileName
case|:
name|ret
operator|=
name|d
operator|->
name|outputFileName
expr_stmt|;
break|break;
case|case
name|PPK_PageOrder
case|:
name|ret
operator|=
name|d
operator|->
name|pageOrder
expr_stmt|;
break|break;
case|case
name|PPK_PageSize
case|:
name|ret
operator|=
name|d
operator|->
name|m_pageLayout
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_PaperName
case|:
name|ret
operator|=
name|d
operator|->
name|m_pageLayout
operator|.
name|pageSize
argument_list|()
operator|.
name|name
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_WindowsPageSize
case|:
name|ret
operator|=
name|d
operator|->
name|m_pageLayout
operator|.
name|pageSize
argument_list|()
operator|.
name|windowsId
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_PaperSource
case|:
name|ret
operator|=
name|d
operator|->
name|paperSource
expr_stmt|;
break|break;
case|case
name|PPK_PrinterName
case|:
name|ret
operator|=
name|d
operator|->
name|printerName
expr_stmt|;
break|break;
case|case
name|PPK_PrinterProgram
case|:
name|ret
operator|=
name|d
operator|->
name|printProgram
expr_stmt|;
break|break;
case|case
name|PPK_Resolution
case|:
name|ret
operator|=
name|d
operator|->
name|resolution
expr_stmt|;
break|break;
case|case
name|PPK_SupportedResolutions
case|:
name|ret
operator|=
name|QList
argument_list|<
name|QVariant
argument_list|>
argument_list|()
operator|<<
literal|72
expr_stmt|;
break|break;
case|case
name|PPK_PaperRect
case|:
name|ret
operator|=
name|d
operator|->
name|m_pageLayout
operator|.
name|fullRectPixels
argument_list|(
name|d
operator|->
name|resolution
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_PageRect
case|:
name|ret
operator|=
name|d
operator|->
name|m_pageLayout
operator|.
name|paintRectPixels
argument_list|(
name|d
operator|->
name|resolution
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_SelectionOption
case|:
name|ret
operator|=
name|d
operator|->
name|selectionOption
expr_stmt|;
break|break;
case|case
name|PPK_FontEmbedding
case|:
name|ret
operator|=
name|d
operator|->
name|embedFonts
expr_stmt|;
break|break;
case|case
name|PPK_Duplex
case|:
name|ret
operator|=
name|d
operator|->
name|duplex
expr_stmt|;
break|break;
case|case
name|PPK_CustomPaperSize
case|:
name|ret
operator|=
name|d
operator|->
name|m_pageLayout
operator|.
name|fullRectPoints
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_PageMargins
case|:
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|list
decl_stmt|;
name|QMarginsF
name|margins
init|=
name|d
operator|->
name|m_pageLayout
operator|.
name|margins
argument_list|(
name|QPageLayout
operator|::
name|Point
argument_list|)
decl_stmt|;
name|list
operator|<<
name|margins
operator|.
name|left
argument_list|()
operator|<<
name|margins
operator|.
name|top
argument_list|()
operator|<<
name|margins
operator|.
name|right
argument_list|()
operator|<<
name|margins
operator|.
name|bottom
argument_list|()
expr_stmt|;
name|ret
operator|=
name|list
expr_stmt|;
break|break;
block|}
case|case
name|PPK_QPageSize
case|:
name|ret
operator|.
name|setValue
argument_list|(
name|d
operator|->
name|m_pageLayout
operator|.
name|pageSize
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|PPK_QPageMargins
case|:
block|{
name|QPair
argument_list|<
name|QMarginsF
argument_list|,
name|QPageLayout
operator|::
name|Unit
argument_list|>
name|pair
init|=
name|qMakePair
argument_list|(
name|d
operator|->
name|m_pageLayout
operator|.
name|margins
argument_list|()
argument_list|,
name|d
operator|->
name|m_pageLayout
operator|.
name|units
argument_list|()
argument_list|)
decl_stmt|;
name|ret
operator|.
name|setValue
argument_list|(
name|pair
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|PPK_QPageLayout
case|:
name|ret
operator|.
name|setValue
argument_list|(
name|d
operator|->
name|m_pageLayout
argument_list|)
expr_stmt|;
break|break;
comment|// No default so that compiler will complain if new keys added and not handled in this engine
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|openPrintDevice
name|bool
name|QPdfPrintEnginePrivate
operator|::
name|openPrintDevice
parameter_list|()
block|{
if|if
condition|(
name|outDevice
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|outputFileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
modifier|*
name|file
init|=
operator|new
name|QFile
argument_list|(
name|outputFileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|->
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Truncate
argument_list|)
condition|)
block|{
operator|delete
name|file
expr_stmt|;
return|return
literal|false
return|;
block|}
name|outDevice
operator|=
name|file
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|closePrintDevice
name|void
name|QPdfPrintEnginePrivate
operator|::
name|closePrintDevice
parameter_list|()
block|{
if|if
condition|(
name|outDevice
condition|)
block|{
name|outDevice
operator|->
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|fd
operator|>=
literal|0
condition|)
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
operator|::
name|_close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
else|#
directive|else
operator|::
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
operator|delete
name|outDevice
expr_stmt|;
name|outDevice
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|QPdfPrintEnginePrivate
name|QPdfPrintEnginePrivate
operator|::
name|QPdfPrintEnginePrivate
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
name|m
parameter_list|)
member_init_list|:
name|QPdfEnginePrivate
argument_list|()
member_init_list|,
name|duplex
argument_list|(
name|QPrint
operator|::
name|DuplexNone
argument_list|)
member_init_list|,
name|collate
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|copies
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|pageOrder
argument_list|(
name|QPrinter
operator|::
name|FirstPageFirst
argument_list|)
member_init_list|,
name|paperSource
argument_list|(
name|QPrinter
operator|::
name|Auto
argument_list|)
member_init_list|,
name|fd
argument_list|(
operator|-
literal|1
argument_list|)
block|{
name|resolution
operator|=
literal|72
expr_stmt|;
if|if
condition|(
name|m
operator|==
name|QPrinter
operator|::
name|HighResolution
condition|)
name|resolution
operator|=
literal|1200
expr_stmt|;
elseif|else
if|if
condition|(
name|m
operator|==
name|QPrinter
operator|::
name|ScreenResolution
condition|)
name|resolution
operator|=
name|qt_defaultDpi
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QPdfPrintEnginePrivate
name|QPdfPrintEnginePrivate
operator|::
name|~
name|QPdfPrintEnginePrivate
parameter_list|()
block|{ }
end_destructor
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
