begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAPRINTDEVICE_H
end_ifndef
begin_define
DECL|macro|QCOCOAPRINTDEVICE_H
define|#
directive|define
name|QCOCOAPRINTDEVICE_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of internal files.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformprintdevice.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|"qt_mac_p.h"
end_include
begin_include
include|#
directive|include
file|<cups/ppd.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaPrintDevice
range|:
name|public
name|QPlatformPrintDevice
block|{
name|public
operator|:
name|QCocoaPrintDevice
argument_list|()
block|;
name|explicit
name|QCocoaPrintDevice
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|QCocoaPrintDevice
argument_list|(
specifier|const
name|QCocoaPrintDevice
operator|&
name|other
argument_list|)
block|;
name|virtual
operator|~
name|QCocoaPrintDevice
argument_list|()
block|;
name|QCocoaPrintDevice
operator|*
name|clone
argument_list|()
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QCocoaPrintDevice
operator|&
name|other
operator|)
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isDefault
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPrint
operator|::
name|DeviceState
name|state
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPageSize
name|defaultPageSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QMarginsF
name|printableMargins
argument_list|(
argument|const QPageSize&pageSize
argument_list|,
argument|QPageLayout::Orientation orientation
argument_list|,
argument|int resolution
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|defaultResolution
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPrint
operator|::
name|InputSlot
name|defaultInputSlot
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPrint
operator|::
name|OutputBin
name|defaultOutputBin
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPrint
operator|::
name|DuplexMode
name|defaultDuplexMode
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPrint
operator|::
name|ColorMode
name|defaultColorMode
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|PMPrinter
name|macPrinter
argument_list|()
specifier|const
block|;
name|PMPaper
name|macPaper
argument_list|(
argument|const QPageSize&pageSize
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|void
name|loadPageSizes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|loadResolutions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|loadInputSlots
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|loadOutputBins
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|loadDuplexModes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|loadColorModes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|loadMimeTypes
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QPageSize
name|createPageSize
argument_list|(
argument|const PMPaper&paper
argument_list|)
specifier|const
block|;
name|bool
name|openPpdFile
argument_list|()
block|;
comment|// Mac Core Printing
name|PMPrinter
name|m_printer
block|;
name|PMPrintSession
name|m_session
block|;
name|mutable
name|QHash
operator|<
name|QString
block|,
name|PMPaper
operator|>
name|m_macPapers
block|;
comment|// PPD File
name|ppd_file_t
operator|*
name|m_ppd
block|;
name|QMarginsF
name|m_customMargins
block|;
name|mutable
name|QHash
operator|<
name|QString
block|,
name|QMarginsF
operator|>
name|m_printableMargins
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
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOCOAPRINTDEVICE_H
end_comment
end_unit
