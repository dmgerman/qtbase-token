begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PRINTDIALOGPANEL_H
end_ifndef
begin_define
DECL|macro|PRINTDIALOGPANEL_H
define|#
directive|define
name|PRINTDIALOGPANEL_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|"ui_printdialogpanel.h"
end_include
begin_if
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050300
end_if
begin_include
include|#
directive|include
file|<QPageLayout>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QPrinter>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPrinter
name|class
name|QPrinter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGroupBox
name|class
name|QGroupBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|PageSizeControl
name|class
name|PageSizeControl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|OptionsControl
name|class
name|OptionsControl
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|QT_VERSION
operator|<
literal|0x050300
end_if
begin_comment
comment|// Copied from class QPageLayout introduced in Qt 5.3
end_comment
begin_decl_stmt
name|namespace
name|QPageLayout
block|{
enum|enum
name|Unit
block|{
name|Millimeter
block|,
name|Point
block|,
name|Inch
block|,
name|Pica
block|,
name|Didot
block|,
name|Cicero
block|}
enum|;
enum|enum
name|Orientation
block|{
name|Portrait
block|,
name|Landscape
block|}
enum|;
enum|enum
name|Mode
block|{
name|StandardMode
block|,
comment|// Paint Rect includes margins
name|FullPageMode
comment|// Paint Rect excludes margins
block|}
enum|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|PrintDialogPanel
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|PrintDialogPanel
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|PrintDialogPanel
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|createPrinter
argument_list|()
block|;
name|void
name|deletePrinter
argument_list|()
block|;
name|void
name|showPrintDialog
argument_list|()
block|;
name|void
name|showPreviewDialog
argument_list|()
block|;
name|void
name|showPageSetupDialog
argument_list|()
block|;
name|void
name|directPrint
argument_list|()
block|;
name|void
name|unitsChanged
argument_list|()
block|;
name|void
name|pageSizeChanged
argument_list|()
block|;
name|void
name|pageDimensionsChanged
argument_list|()
block|;
name|void
name|orientationChanged
argument_list|()
block|;
name|void
name|marginsChanged
argument_list|()
block|;
name|void
name|layoutModeChanged
argument_list|()
block|;
name|void
name|printerChanged
argument_list|()
block|;
name|private
operator|:
name|QSizeF
name|customPageSize
argument_list|()
specifier|const
block|;
name|void
name|applySettings
argument_list|(
argument|QPrinter *printer
argument_list|)
specifier|const
block|;
name|void
name|retrieveSettings
argument_list|(
specifier|const
name|QPrinter
operator|*
name|printer
argument_list|)
block|;
name|void
name|updatePageLayoutWidgets
argument_list|()
block|;
name|void
name|enablePanels
argument_list|()
block|;
name|bool
name|m_blockSignals
block|;
name|Ui
operator|::
name|PrintDialogPanel
name|m_panel
block|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050300
name|QPageLayout
name|m_pageLayout
block|;
else|#
directive|else
name|QPrinter
name|m_printerLayout
block|;
name|QPrinter
operator|::
name|Unit
name|m_units
block|;
endif|#
directive|endif
name|QScopedPointer
operator|<
name|QPrinter
operator|>
name|m_printer
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_PRINTER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PRINTDIALOGPANEL_H
end_comment
end_unit
