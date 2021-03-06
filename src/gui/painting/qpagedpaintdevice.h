begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAGEDPAINTDEVICE_H
end_ifndef
begin_define
DECL|macro|QPAGEDPAINTDEVICE_H
define|#
directive|define
name|QPAGEDPAINTDEVICE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagelayout.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|B0
argument_list|)
DECL|macro|B0
undef|#
directive|undef
name|B0
comment|// Terminal hang-up.  We assume that you do not want that.
endif|#
directive|endif
DECL|variable|QPagedPaintDevicePrivate
name|class
name|QPagedPaintDevicePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPagedPaintDevice
range|:
name|public
name|QPaintDevice
block|{
name|public
operator|:
name|QPagedPaintDevice
argument_list|()
block|;
operator|~
name|QPagedPaintDevice
argument_list|()
block|;
name|virtual
name|bool
name|newPage
argument_list|()
operator|=
literal|0
block|;
comment|// ### Qt6 Remove in favor of QPage::PageSize
comment|// NOTE: Must keep in sync with QPageSize and QPrinter
block|enum
name|PageSize
block|{
comment|// Existing Qt sizes
name|A4
block|,
name|B5
block|,
name|Letter
block|,
name|Legal
block|,
name|Executive
block|,
name|A0
block|,
name|A1
block|,
name|A2
block|,
name|A3
block|,
name|A5
block|,
name|A6
block|,
name|A7
block|,
name|A8
block|,
name|A9
block|,
name|B0
block|,
name|B1
block|,
name|B10
block|,
name|B2
block|,
name|B3
block|,
name|B4
block|,
name|B6
block|,
name|B7
block|,
name|B8
block|,
name|B9
block|,
name|C5E
block|,
name|Comm10E
block|,
name|DLE
block|,
name|Folio
block|,
name|Ledger
block|,
name|Tabloid
block|,
name|Custom
block|,
comment|// New values derived from PPD standard
name|A10
block|,
name|A3Extra
block|,
name|A4Extra
block|,
name|A4Plus
block|,
name|A4Small
block|,
name|A5Extra
block|,
name|B5Extra
block|,
name|JisB0
block|,
name|JisB1
block|,
name|JisB2
block|,
name|JisB3
block|,
name|JisB4
block|,
name|JisB5
block|,
name|JisB6
block|,
name|JisB7
block|,
name|JisB8
block|,
name|JisB9
block|,
name|JisB10
block|,
comment|// AnsiA = Letter,
comment|// AnsiB = Ledger,
name|AnsiC
block|,
name|AnsiD
block|,
name|AnsiE
block|,
name|LegalExtra
block|,
name|LetterExtra
block|,
name|LetterPlus
block|,
name|LetterSmall
block|,
name|TabloidExtra
block|,
name|ArchA
block|,
name|ArchB
block|,
name|ArchC
block|,
name|ArchD
block|,
name|ArchE
block|,
name|Imperial7x9
block|,
name|Imperial8x10
block|,
name|Imperial9x11
block|,
name|Imperial9x12
block|,
name|Imperial10x11
block|,
name|Imperial10x13
block|,
name|Imperial10x14
block|,
name|Imperial12x11
block|,
name|Imperial15x11
block|,
name|ExecutiveStandard
block|,
name|Note
block|,
name|Quarto
block|,
name|Statement
block|,
name|SuperA
block|,
name|SuperB
block|,
name|Postcard
block|,
name|DoublePostcard
block|,
name|Prc16K
block|,
name|Prc32K
block|,
name|Prc32KBig
block|,
name|FanFoldUS
block|,
name|FanFoldGerman
block|,
name|FanFoldGermanLegal
block|,
name|EnvelopeB4
block|,
name|EnvelopeB5
block|,
name|EnvelopeB6
block|,
name|EnvelopeC0
block|,
name|EnvelopeC1
block|,
name|EnvelopeC2
block|,
name|EnvelopeC3
block|,
name|EnvelopeC4
block|,
comment|// EnvelopeC5 = C5E,
name|EnvelopeC6
block|,
name|EnvelopeC65
block|,
name|EnvelopeC7
block|,
comment|// EnvelopeDL = DLE,
name|Envelope9
block|,
comment|// Envelope10 = Comm10E,
name|Envelope11
block|,
name|Envelope12
block|,
name|Envelope14
block|,
name|EnvelopeMonarch
block|,
name|EnvelopePersonal
block|,
name|EnvelopeChou3
block|,
name|EnvelopeChou4
block|,
name|EnvelopeInvite
block|,
name|EnvelopeItalian
block|,
name|EnvelopeKaku2
block|,
name|EnvelopeKaku3
block|,
name|EnvelopePrc1
block|,
name|EnvelopePrc2
block|,
name|EnvelopePrc3
block|,
name|EnvelopePrc4
block|,
name|EnvelopePrc5
block|,
name|EnvelopePrc6
block|,
name|EnvelopePrc7
block|,
name|EnvelopePrc8
block|,
name|EnvelopePrc9
block|,
name|EnvelopePrc10
block|,
name|EnvelopeYou4
block|,
comment|// Last item, with commonly used synynoms from QPagedPrintEngine / QPrinter
name|LastPageSize
operator|=
name|EnvelopeYou4
block|,
name|NPageSize
operator|=
name|LastPageSize
block|,
name|NPaperSize
operator|=
name|LastPageSize
block|,
comment|// Convenience overloads for naming consistency
name|AnsiA
operator|=
name|Letter
block|,
name|AnsiB
operator|=
name|Ledger
block|,
name|EnvelopeC5
operator|=
name|C5E
block|,
name|EnvelopeDL
operator|=
name|DLE
block|,
name|Envelope10
operator|=
name|Comm10E
block|}
block|;
comment|// ### Qt6 Make these virtual
name|bool
name|setPageLayout
argument_list|(
specifier|const
name|QPageLayout
operator|&
name|pageLayout
argument_list|)
block|;
name|bool
name|setPageSize
argument_list|(
specifier|const
name|QPageSize
operator|&
name|pageSize
argument_list|)
block|;
name|bool
name|setPageOrientation
argument_list|(
argument|QPageLayout::Orientation orientation
argument_list|)
block|;
name|bool
name|setPageMargins
argument_list|(
specifier|const
name|QMarginsF
operator|&
name|margins
argument_list|)
block|;
name|bool
name|setPageMargins
argument_list|(
argument|const QMarginsF&margins
argument_list|,
argument|QPageLayout::Unit units
argument_list|)
block|;
name|QPageLayout
name|pageLayout
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setPageSize
argument_list|(
argument|PageSize size
argument_list|)
block|;
name|PageSize
name|pageSize
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setPageSizeMM
argument_list|(
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
block|;
name|QSizeF
name|pageSizeMM
argument_list|()
specifier|const
block|;
comment|// ### Qt6 Remove in favor of QMarginsF
block|struct
name|Margins
block|{
name|qreal
name|left
block|;
name|qreal
name|right
block|;
name|qreal
name|top
block|;
name|qreal
name|bottom
block|;     }
block|;
name|virtual
name|void
name|setMargins
argument_list|(
specifier|const
name|Margins
operator|&
name|margins
argument_list|)
block|;
name|Margins
name|margins
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QPagedPaintDevice
argument_list|(
name|QPagedPaintDevicePrivate
operator|*
name|dd
argument_list|)
block|;
name|QPagedPaintDevicePrivate
operator|*
name|dd
argument_list|()
block|;
name|QPageLayout
name|devicePageLayout
argument_list|()
specifier|const
block|;
name|QPageLayout
operator|&
name|devicePageLayout
argument_list|()
block|;
name|friend
name|class
name|QPagedPaintDevicePrivate
block|;
name|QPagedPaintDevicePrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
