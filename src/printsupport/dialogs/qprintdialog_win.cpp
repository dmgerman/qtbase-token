begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
end_ifndef
begin_include
include|#
directive|include
file|"qprintdialog.h"
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qmessagebox.h>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|"qabstractprintdialog_p.h"
end_include
begin_include
include|#
directive|include
file|"../kernel/qprintengine_win_p.h"
end_include
begin_include
include|#
directive|include
file|"../kernel/qprinter_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PD_NOCURRENTPAGE
argument_list|)
end_if
begin_define
DECL|macro|PD_NOCURRENTPAGE
define|#
directive|define
name|PD_NOCURRENTPAGE
value|0x00800000
end_define
begin_define
DECL|macro|PD_RESULT_PRINT
define|#
directive|define
name|PD_RESULT_PRINT
value|1
end_define
begin_define
DECL|macro|PD_RESULT_APPLY
define|#
directive|define
name|PD_RESULT_APPLY
value|2
end_define
begin_define
DECL|macro|START_PAGE_GENERAL
define|#
directive|define
name|START_PAGE_GENERAL
value|0XFFFFFFFF
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|//extern void qt_win_eatMouseMove();
end_comment
begin_class
DECL|class|QPrintDialogPrivate
class|class
name|QPrintDialogPrivate
super|:
specifier|public
name|QAbstractPrintDialogPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QPrintDialog
parameter_list|)
specifier|public
private|:
DECL|function|QPrintDialogPrivate
name|QPrintDialogPrivate
parameter_list|()
member_init_list|:
name|ep
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|_q_printToFileChanged
specifier|inline
name|void
name|_q_printToFileChanged
parameter_list|(
name|int
parameter_list|)
block|{}
DECL|function|_q_rbPrintRangeToggled
specifier|inline
name|void
name|_q_rbPrintRangeToggled
parameter_list|(
name|bool
parameter_list|)
block|{}
DECL|function|_q_printerChanged
specifier|inline
name|void
name|_q_printerChanged
parameter_list|(
name|int
parameter_list|)
block|{}
DECL|function|_q_chbPrintLastFirstToggled
specifier|inline
name|void
name|_q_chbPrintLastFirstToggled
parameter_list|(
name|bool
parameter_list|)
block|{}
DECL|function|_q_paperSizeChanged
specifier|inline
name|void
name|_q_paperSizeChanged
parameter_list|(
name|int
parameter_list|)
block|{}
DECL|function|_q_btnBrowseClicked
specifier|inline
name|void
name|_q_btnBrowseClicked
parameter_list|()
block|{}
DECL|function|_q_btnPropertiesClicked
specifier|inline
name|void
name|_q_btnPropertiesClicked
parameter_list|()
block|{}
name|int
name|openWindowsPrintDialogModally
parameter_list|()
function_decl|;
DECL|member|ep
name|QWin32PrintEnginePrivate
modifier|*
name|ep
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|qt_win_setup_PRINTDLGEX
specifier|static
name|void
name|qt_win_setup_PRINTDLGEX
parameter_list|(
name|PRINTDLGEX
modifier|*
name|pd
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|,
name|QPrintDialog
modifier|*
name|pdlg
parameter_list|,
name|QPrintDialogPrivate
modifier|*
name|d
parameter_list|,
name|HGLOBAL
modifier|*
name|tempDevNames
parameter_list|)
block|{
name|DEVMODE
modifier|*
name|devMode
init|=
name|d
operator|->
name|ep
operator|->
name|devMode
decl_stmt|;
if|if
condition|(
name|devMode
condition|)
block|{
name|int
name|size
init|=
sizeof|sizeof
argument_list|(
name|DEVMODE
argument_list|)
operator|+
name|devMode
operator|->
name|dmDriverExtra
decl_stmt|;
name|pd
operator|->
name|hDevMode
operator|=
name|GlobalAlloc
argument_list|(
name|GHND
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|{
name|void
modifier|*
name|dest
init|=
name|GlobalLock
argument_list|(
name|pd
operator|->
name|hDevMode
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|dest
argument_list|,
name|devMode
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|GlobalUnlock
argument_list|(
name|pd
operator|->
name|hDevMode
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|pd
operator|->
name|hDevMode
operator|=
name|NULL
expr_stmt|;
block|}
name|pd
operator|->
name|hDevNames
operator|=
name|tempDevNames
expr_stmt|;
name|pd
operator|->
name|Flags
operator|=
name|PD_RETURNDC
expr_stmt|;
name|pd
operator|->
name|Flags
operator||=
name|PD_USEDEVMODECOPIESANDCOLLATE
expr_stmt|;
if|if
condition|(
operator|!
name|pdlg
operator|->
name|isOptionEnabled
argument_list|(
name|QPrintDialog
operator|::
name|PrintSelection
argument_list|)
condition|)
name|pd
operator|->
name|Flags
operator||=
name|PD_NOSELECTION
expr_stmt|;
if|if
condition|(
name|pdlg
operator|->
name|isOptionEnabled
argument_list|(
name|QPrintDialog
operator|::
name|PrintPageRange
argument_list|)
condition|)
block|{
name|pd
operator|->
name|nMinPage
operator|=
name|pdlg
operator|->
name|minPage
argument_list|()
expr_stmt|;
name|pd
operator|->
name|nMaxPage
operator|=
name|pdlg
operator|->
name|maxPage
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|pdlg
operator|->
name|isOptionEnabled
argument_list|(
name|QPrintDialog
operator|::
name|PrintToFile
argument_list|)
condition|)
name|pd
operator|->
name|Flags
operator||=
name|PD_DISABLEPRINTTOFILE
expr_stmt|;
if|if
condition|(
name|pdlg
operator|->
name|printRange
argument_list|()
operator|==
name|QPrintDialog
operator|::
name|Selection
condition|)
name|pd
operator|->
name|Flags
operator||=
name|PD_SELECTION
expr_stmt|;
elseif|else
if|if
condition|(
name|pdlg
operator|->
name|printRange
argument_list|()
operator|==
name|QPrintDialog
operator|::
name|PageRange
condition|)
name|pd
operator|->
name|Flags
operator||=
name|PD_PAGENUMS
expr_stmt|;
else|else
name|pd
operator|->
name|Flags
operator||=
name|PD_ALLPAGES
expr_stmt|;
comment|// As stated by MSDN, to enable collate option when minpage==maxpage==0
comment|// set the PD_NOPAGENUMS flag
if|if
condition|(
name|pd
operator|->
name|nMinPage
operator|==
literal|0
operator|&&
name|pd
operator|->
name|nMaxPage
operator|==
literal|0
condition|)
name|pd
operator|->
name|Flags
operator||=
name|PD_NOPAGENUMS
expr_stmt|;
comment|// Disable Current Page option if not required as default is Enabled
if|if
condition|(
operator|!
name|pdlg
operator|->
name|isOptionEnabled
argument_list|(
name|QPrintDialog
operator|::
name|PrintCurrentPage
argument_list|)
condition|)
name|pd
operator|->
name|Flags
operator||=
name|PD_NOCURRENTPAGE
expr_stmt|;
comment|// Default to showing the General tab first
name|pd
operator|->
name|nStartPage
operator|=
name|START_PAGE_GENERAL
expr_stmt|;
comment|// We don't support more than one page range in the QPrinter API yet.
name|pd
operator|->
name|nPageRanges
operator|=
literal|1
expr_stmt|;
name|pd
operator|->
name|nMaxPageRanges
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ep
operator|->
name|printToFile
condition|)
name|pd
operator|->
name|Flags
operator||=
name|PD_PRINTTOFILE
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|parentWindow
init|=
name|parent
operator|->
name|windowHandle
argument_list|()
decl_stmt|;
name|pd
operator|->
name|hwndOwner
operator|=
name|parentWindow
condition|?
operator|(
name|HWND
operator|)
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
operator|->
name|nativeResourceForWindow
argument_list|(
literal|"handle"
argument_list|,
name|parentWindow
argument_list|)
else|:
literal|0
expr_stmt|;
name|pd
operator|->
name|lpPageRanges
index|[
literal|0
index|]
operator|.
name|nFromPage
operator|=
name|qMax
argument_list|(
name|pdlg
operator|->
name|fromPage
argument_list|()
argument_list|,
name|pdlg
operator|->
name|minPage
argument_list|()
argument_list|)
expr_stmt|;
name|pd
operator|->
name|lpPageRanges
index|[
literal|0
index|]
operator|.
name|nToPage
operator|=
operator|(
name|pdlg
operator|->
name|toPage
argument_list|()
operator|>
literal|0
operator|)
condition|?
name|qMin
argument_list|(
name|pdlg
operator|->
name|toPage
argument_list|()
argument_list|,
name|pdlg
operator|->
name|maxPage
argument_list|()
argument_list|)
else|:
literal|1
expr_stmt|;
name|pd
operator|->
name|nCopies
operator|=
name|d
operator|->
name|ep
operator|->
name|num_copies
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_win_read_back_PRINTDLGEX
specifier|static
name|void
name|qt_win_read_back_PRINTDLGEX
parameter_list|(
name|PRINTDLGEX
modifier|*
name|pd
parameter_list|,
name|QPrintDialog
modifier|*
name|pdlg
parameter_list|,
name|QPrintDialogPrivate
modifier|*
name|d
parameter_list|)
block|{
if|if
condition|(
name|pd
operator|->
name|Flags
operator|&
name|PD_SELECTION
condition|)
block|{
name|pdlg
operator|->
name|setPrintRange
argument_list|(
name|QPrintDialog
operator|::
name|Selection
argument_list|)
expr_stmt|;
name|pdlg
operator|->
name|setFromTo
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pd
operator|->
name|Flags
operator|&
name|PD_PAGENUMS
condition|)
block|{
name|pdlg
operator|->
name|setPrintRange
argument_list|(
name|QPrintDialog
operator|::
name|PageRange
argument_list|)
expr_stmt|;
name|pdlg
operator|->
name|setFromTo
argument_list|(
name|pd
operator|->
name|lpPageRanges
index|[
literal|0
index|]
operator|.
name|nFromPage
argument_list|,
name|pd
operator|->
name|lpPageRanges
index|[
literal|0
index|]
operator|.
name|nToPage
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pd
operator|->
name|Flags
operator|&
name|PD_CURRENTPAGE
condition|)
block|{
name|pdlg
operator|->
name|setPrintRange
argument_list|(
name|QPrintDialog
operator|::
name|CurrentPage
argument_list|)
expr_stmt|;
name|pdlg
operator|->
name|setFromTo
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// PD_ALLPAGES
name|pdlg
operator|->
name|setPrintRange
argument_list|(
name|QPrintDialog
operator|::
name|AllPages
argument_list|)
expr_stmt|;
name|pdlg
operator|->
name|setFromTo
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|ep
operator|->
name|printToFile
operator|=
operator|(
name|pd
operator|->
name|Flags
operator|&
name|PD_PRINTTOFILE
operator|)
operator|!=
literal|0
expr_stmt|;
name|d
operator|->
name|ep
operator|->
name|readDevnames
argument_list|(
name|pd
operator|->
name|hDevNames
argument_list|)
expr_stmt|;
name|d
operator|->
name|ep
operator|->
name|readDevmode
argument_list|(
name|pd
operator|->
name|hDevMode
argument_list|)
expr_stmt|;
name|d
operator|->
name|ep
operator|->
name|updateCustomPaperSize
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ep
operator|->
name|printToFile
operator|&&
name|d
operator|->
name|ep
operator|->
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|d
operator|->
name|ep
operator|->
name|fileName
operator|=
name|d
operator|->
name|ep
operator|->
name|port
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|d
operator|->
name|ep
operator|->
name|printToFile
operator|&&
name|d
operator|->
name|ep
operator|->
name|fileName
operator|==
name|QLatin1String
argument_list|(
literal|"FILE:"
argument_list|)
condition|)
name|d
operator|->
name|ep
operator|->
name|fileName
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|warnIfNotNative
specifier|static
name|bool
name|warnIfNotNative
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|)
block|{
if|if
condition|(
name|printer
operator|->
name|outputFormat
argument_list|()
operator|!=
name|QPrinter
operator|::
name|NativeFormat
condition|)
block|{
name|qWarning
argument_list|(
literal|"QPrintDialog: Cannot be used on non-native printers"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_constructor
DECL|function|QPrintDialog
name|QPrintDialog
operator|::
name|QPrintDialog
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractPrintDialog
argument_list|(
operator|*
operator|(
operator|new
name|QPrintDialogPrivate
operator|)
argument_list|,
name|printer
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|warnIfNotNative
argument_list|(
name|d
operator|->
name|printer
argument_list|)
condition|)
return|return;
name|d
operator|->
name|ep
operator|=
cast|static_cast
argument_list|<
name|QWin32PrintEngine
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|printer
operator|->
name|paintEngine
argument_list|()
argument_list|)
operator|->
name|d_func
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QPrintDialog
name|QPrintDialog
operator|::
name|QPrintDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractPrintDialog
argument_list|(
operator|*
operator|(
operator|new
name|QPrintDialogPrivate
operator|)
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|warnIfNotNative
argument_list|(
name|d
operator|->
name|printer
argument_list|)
condition|)
return|return;
name|d
operator|->
name|ep
operator|=
cast|static_cast
argument_list|<
name|QWin32PrintEngine
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|printer
operator|->
name|paintEngine
argument_list|()
argument_list|)
operator|->
name|d_func
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QPrintDialog
name|QPrintDialog
operator|::
name|~
name|QPrintDialog
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|exec
name|int
name|QPrintDialog
operator|::
name|exec
parameter_list|()
block|{
if|if
condition|(
operator|!
name|warnIfNotNative
argument_list|(
name|printer
argument_list|()
argument_list|)
condition|)
return|return
literal|0
return|;
name|Q_D
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|openWindowsPrintDialogModally
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|openWindowsPrintDialogModally
name|int
name|QPrintDialogPrivate
operator|::
name|openWindowsPrintDialogModally
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|parent
init|=
name|q
operator|->
name|parentWidget
argument_list|()
decl_stmt|;
if|if
condition|(
name|parent
condition|)
name|parent
operator|=
name|parent
operator|->
name|window
argument_list|()
expr_stmt|;
else|else
name|parent
operator|=
name|QApplication
operator|::
name|activeWindow
argument_list|()
expr_stmt|;
comment|// If there is no window, fall back to the print dialog itself
if|if
condition|(
name|parent
operator|==
literal|0
condition|)
name|parent
operator|=
name|q
expr_stmt|;
name|QWidget
name|modal_widget
decl_stmt|;
name|modal_widget
operator|.
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoChildEventsForParent
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|modal_widget
operator|.
name|setParent
argument_list|(
name|parent
argument_list|,
name|Qt
operator|::
name|Window
argument_list|)
expr_stmt|;
name|QApplicationPrivate
operator|::
name|enterModal
argument_list|(
operator|&
name|modal_widget
argument_list|)
expr_stmt|;
name|HGLOBAL
modifier|*
name|tempDevNames
init|=
name|ep
operator|->
name|createDevNames
argument_list|()
decl_stmt|;
name|bool
name|done
decl_stmt|;
name|bool
name|result
decl_stmt|;
name|bool
name|doPrinting
decl_stmt|;
name|PRINTPAGERANGE
name|pageRange
decl_stmt|;
name|PRINTDLGEX
name|pd
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pd
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|PRINTDLGEX
argument_list|)
argument_list|)
expr_stmt|;
name|pd
operator|.
name|lStructSize
operator|=
sizeof|sizeof
argument_list|(
name|PRINTDLGEX
argument_list|)
expr_stmt|;
name|pd
operator|.
name|lpPageRanges
operator|=
operator|&
name|pageRange
expr_stmt|;
name|qt_win_setup_PRINTDLGEX
argument_list|(
operator|&
name|pd
argument_list|,
name|parent
argument_list|,
name|q
argument_list|,
name|this
argument_list|,
name|tempDevNames
argument_list|)
expr_stmt|;
do|do
block|{
name|done
operator|=
literal|true
expr_stmt|;
name|doPrinting
operator|=
literal|false
expr_stmt|;
name|result
operator|=
operator|(
name|PrintDlgEx
argument_list|(
operator|&
name|pd
argument_list|)
operator|==
name|S_OK
operator|)
expr_stmt|;
if|if
condition|(
name|result
operator|&&
operator|(
name|pd
operator|.
name|dwResultAction
operator|==
name|PD_RESULT_PRINT
operator|||
name|pd
operator|.
name|dwResultAction
operator|==
name|PD_RESULT_APPLY
operator|)
condition|)
block|{
name|doPrinting
operator|=
operator|(
name|pd
operator|.
name|dwResultAction
operator|==
name|PD_RESULT_PRINT
operator|)
expr_stmt|;
if|if
condition|(
operator|(
name|pd
operator|.
name|Flags
operator|&
name|PD_PAGENUMS
operator|)
operator|&&
operator|(
name|pd
operator|.
name|lpPageRanges
index|[
literal|0
index|]
operator|.
name|nFromPage
operator|>
name|pd
operator|.
name|lpPageRanges
index|[
literal|0
index|]
operator|.
name|nToPage
operator|)
condition|)
block|{
name|pd
operator|.
name|lpPageRanges
index|[
literal|0
index|]
operator|.
name|nFromPage
operator|=
literal|1
expr_stmt|;
name|pd
operator|.
name|lpPageRanges
index|[
literal|0
index|]
operator|.
name|nToPage
operator|=
literal|1
expr_stmt|;
name|done
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|pd
operator|.
name|hDC
operator|==
literal|0
condition|)
name|result
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|done
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
literal|0
argument_list|,
name|QPrintDialog
operator|::
name|tr
argument_list|(
literal|"Print"
argument_list|)
argument_list|,
name|QPrintDialog
operator|::
name|tr
argument_list|(
literal|"The 'From' value cannot be greater than the 'To' value."
argument_list|)
argument_list|,
name|QPrintDialog
operator|::
name|tr
argument_list|(
literal|"OK"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
operator|!
name|done
condition|)
do|;
name|QApplicationPrivate
operator|::
name|leaveModal
argument_list|(
operator|&
name|modal_widget
argument_list|)
expr_stmt|;
comment|//    qt_win_eatMouseMove();
comment|// write values back...
if|if
condition|(
name|result
operator|&&
operator|(
name|pd
operator|.
name|dwResultAction
operator|==
name|PD_RESULT_PRINT
operator|||
name|pd
operator|.
name|dwResultAction
operator|==
name|PD_RESULT_APPLY
operator|)
condition|)
block|{
name|qt_win_read_back_PRINTDLGEX
argument_list|(
operator|&
name|pd
argument_list|,
name|q
argument_list|,
name|this
argument_list|)
expr_stmt|;
comment|// update printer validity
name|printer
operator|->
name|d_func
argument_list|()
operator|->
name|validPrinter
operator|=
operator|!
name|ep
operator|->
name|name
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
block|}
comment|// Cleanup...
name|GlobalFree
argument_list|(
name|tempDevNames
argument_list|)
expr_stmt|;
name|q
operator|->
name|done
argument_list|(
name|result
operator|&&
name|doPrinting
argument_list|)
expr_stmt|;
return|return
name|result
operator|&&
name|doPrinting
return|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QPrintDialog
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
comment|// its always modal, so we cannot hide a native print dialog
if|if
condition|(
operator|!
name|visible
condition|)
return|return;
if|if
condition|(
operator|!
name|warnIfNotNative
argument_list|(
name|d
operator|->
name|printer
argument_list|)
condition|)
return|return;
operator|(
name|void
operator|)
name|d
operator|->
name|openWindowsPrintDialogModally
argument_list|()
expr_stmt|;
return|return;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qprintdialog.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTDIALOG
end_comment
end_unit
