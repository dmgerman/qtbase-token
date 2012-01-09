begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTERINFO_H
end_ifndef
begin_define
DECL|macro|QPRINTERINFO_H
define|#
directive|define
name|QPRINTERINFO_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/QPrinter>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
DECL|variable|QPrinterInfoPrivate
name|class
name|QPrinterInfoPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrinterInfoPrivateDeleter
name|class
name|QPrinterInfoPrivateDeleter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPrinterInfo
block|{
name|public
label|:
name|QPrinterInfo
argument_list|()
expr_stmt|;
name|QPrinterInfo
argument_list|(
specifier|const
name|QPrinterInfo
operator|&
name|other
argument_list|)
expr_stmt|;
name|QPrinterInfo
argument_list|(
specifier|const
name|QPrinter
operator|&
name|printer
argument_list|)
expr_stmt|;
operator|~
name|QPrinterInfo
argument_list|()
expr_stmt|;
name|QPrinterInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QPrinterInfo
operator|&
name|other
operator|)
decl_stmt|;
name|QString
name|printerName
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDefault
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPrinter
operator|::
name|PaperSize
operator|>
name|supportedPaperSizes
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QList
operator|<
name|QPrinterInfo
operator|>
name|availablePrinters
argument_list|()
expr_stmt|;
specifier|static
name|QPrinterInfo
name|defaultPrinter
parameter_list|()
function_decl|;
name|private
label|:
name|QPrinterInfo
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
expr_stmt|;
name|private
label|:
name|friend
name|class
name|QPlatformPrinterSupport
decl_stmt|;
name|friend
name|class
name|QWindowsPrinterSupport
decl_stmt|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPrinterInfo
argument_list|)
name|QScopedPointer
operator|<
name|QPrinterInfoPrivate
operator|,
name|QPrinterInfoPrivateDeleter
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTERINFO_H
end_comment
end_unit
