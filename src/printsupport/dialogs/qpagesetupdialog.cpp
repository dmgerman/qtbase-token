begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpagesetupdialog.h"
end_include
begin_include
include|#
directive|include
file|<private/qpagesetupdialog_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/qprinter.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QPageSetupDialog      \brief The QPageSetupDialog class provides a configuration dialog     for the page-related options on a printer.      \ingroup standard-dialogs     \ingroup printing     \inmodule QtPrintSupport      On Windows and Mac OS X the page setup dialog is implemented using     the native page setup dialogs.      Note that on Windows and Mac OS X custom paper sizes won't be     reflected in the native page setup dialogs. Additionally, custom     page margins set on a QPrinter won't show in the native Mac OS X     page setup dialog.      \sa QPrinter, QPrintDialog */
end_comment
begin_comment
comment|/*!     \fn QPageSetupDialog::QPageSetupDialog(QPrinter *printer, QWidget *parent)      Constructs a page setup dialog that configures \a printer with \a     parent as the parent widget. */
end_comment
begin_comment
comment|/*!     \fn QPageSetupDialog::~QPageSetupDialog()      Destroys the page setup dialog. */
end_comment
begin_comment
comment|/*!     \since 4.5      \fn QPageSetupDialog::QPageSetupDialog(QWidget *parent)      Constructs a page setup dialog that configures a default-constructed     QPrinter with \a parent as the parent widget.      \sa printer() */
end_comment
begin_comment
comment|/*!     \fn QPrinter *QPageSetupDialog::printer()      Returns the printer that was passed to the QPageSetupDialog     constructor. */
end_comment
begin_constructor
DECL|function|QPageSetupDialogPrivate
name|QPageSetupDialogPrivate
operator|::
name|QPageSetupDialogPrivate
parameter_list|(
name|QPrinter
modifier|*
name|prntr
parameter_list|)
member_init_list|:
name|printer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|ownsPrinter
argument_list|(
literal|false
argument_list|)
block|{
name|setPrinter
argument_list|(
name|prntr
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setPrinter
name|void
name|QPageSetupDialogPrivate
operator|::
name|setPrinter
parameter_list|(
name|QPrinter
modifier|*
name|newPrinter
parameter_list|)
block|{
if|if
condition|(
name|printer
operator|&&
name|ownsPrinter
condition|)
operator|delete
name|printer
expr_stmt|;
if|if
condition|(
name|newPrinter
condition|)
block|{
name|printer
operator|=
name|newPrinter
expr_stmt|;
name|ownsPrinter
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|printer
operator|=
operator|new
name|QPrinter
expr_stmt|;
name|ownsPrinter
operator|=
literal|true
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|Q_DEAD_CODE_FROM_QT4_X11
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
name|qWarning
argument_list|(
literal|"QPageSetupDialog: Cannot be used on non-native printers"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     \overload     \since 4.5      Opens the dialog and connects its accepted() signal to the slot specified     by \a receiver and \a member.      The signal will be disconnected from the slot when the dialog is closed. */
end_comment
begin_function
DECL|function|open
name|void
name|QPageSetupDialog
operator|::
name|open
parameter_list|(
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPageSetupDialog
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|)
expr_stmt|;
name|d
operator|->
name|receiverToDisconnectOnClose
operator|=
name|receiver
expr_stmt|;
name|d
operator|->
name|memberToDisconnectOnClose
operator|=
name|member
expr_stmt|;
name|QDialog
operator|::
name|open
argument_list|()
expr_stmt|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_comment
comment|/*! \fn void QPageSetupDialog::setVisible(bool visible)     \reimp */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_destructor
DECL|function|~QPageSetupDialog
name|QPageSetupDialog
operator|::
name|~
name|QPageSetupDialog
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPageSetupDialog
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ownsPrinter
condition|)
operator|delete
name|d
operator|->
name|printer
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|printer
name|QPrinter
modifier|*
name|QPageSetupDialog
operator|::
name|printer
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPageSetupDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|printer
return|;
block|}
end_function
begin_comment
comment|/*!     \fn int QPageSetupDialog::exec()      This virtual function is called to pop up the dialog. It must be     reimplemented in subclasses. */
end_comment
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|done
name|void
name|QPageSetupDialog
operator|::
name|done
parameter_list|(
name|int
name|result
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPageSetupDialog
argument_list|)
expr_stmt|;
name|QDialog
operator|::
name|done
argument_list|(
name|result
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|receiverToDisconnectOnClose
condition|)
block|{
name|disconnect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|d
operator|->
name|receiverToDisconnectOnClose
argument_list|,
name|d
operator|->
name|memberToDisconnectOnClose
argument_list|)
expr_stmt|;
name|d
operator|->
name|receiverToDisconnectOnClose
operator|=
literal|0
expr_stmt|;
block|}
name|d
operator|->
name|memberToDisconnectOnClose
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
