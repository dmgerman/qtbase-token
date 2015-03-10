begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtPrintSupport module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTDEVICE_H
end_ifndef
begin_define
DECL|macro|QPRINTDEVICE_H
define|#
directive|define
name|QPRINTDEVICE_H
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
file|"private/qprint_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagelayout.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
DECL|variable|QPlatformPrintDevice
name|class
name|QPlatformPrintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMarginsF
name|class
name|QMarginsF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMimeType
name|class
name|QMimeType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPrintDevice
block|{
name|public
label|:
name|QPrintDevice
argument_list|()
expr_stmt|;
name|QPrintDevice
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
expr_stmt|;
name|QPrintDevice
argument_list|(
specifier|const
name|QPrintDevice
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QPrintDevice
argument_list|()
expr_stmt|;
name|QPrintDevice
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QPrintDevice
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QPrintDevice
modifier|&
name|operator
init|=
operator|(
name|QPrintDevice
operator|&&
name|other
operator|)
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QPrintDevice
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPrintDevice
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|QString
name|id
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|location
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|makeAndModel
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDefault
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isRemote
argument_list|()
specifier|const
expr_stmt|;
name|QPrint
operator|::
name|DeviceState
name|state
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValidPageLayout
argument_list|(
specifier|const
name|QPageLayout
operator|&
name|layout
argument_list|,
name|int
name|resolution
argument_list|)
decl|const
decl_stmt|;
name|bool
name|supportsMultipleCopies
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsCollateCopies
argument_list|()
specifier|const
expr_stmt|;
name|QPageSize
name|defaultPageSize
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPageSize
operator|>
name|supportedPageSizes
argument_list|()
specifier|const
expr_stmt|;
name|QPageSize
name|supportedPageSize
argument_list|(
specifier|const
name|QPageSize
operator|&
name|pageSize
argument_list|)
decl|const
decl_stmt|;
name|QPageSize
name|supportedPageSize
argument_list|(
name|QPageSize
operator|::
name|PageSizeId
name|pageSizeId
argument_list|)
decl|const
decl_stmt|;
name|QPageSize
name|supportedPageSize
argument_list|(
specifier|const
name|QString
operator|&
name|pageName
argument_list|)
decl|const
decl_stmt|;
name|QPageSize
name|supportedPageSize
argument_list|(
specifier|const
name|QSize
operator|&
name|pointSize
argument_list|)
decl|const
decl_stmt|;
name|QPageSize
name|supportedPageSize
argument_list|(
specifier|const
name|QSizeF
operator|&
name|size
argument_list|,
name|QPageSize
operator|::
name|Unit
name|units
operator|=
name|QPageSize
operator|::
name|Point
argument_list|)
decl|const
decl_stmt|;
name|bool
name|supportsCustomPageSizes
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|minimumPhysicalPageSize
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|maximumPhysicalPageSize
argument_list|()
specifier|const
expr_stmt|;
name|QMarginsF
name|printableMargins
argument_list|(
specifier|const
name|QPageSize
operator|&
name|pageSize
argument_list|,
name|QPageLayout
operator|::
name|Orientation
name|orientation
argument_list|,
name|int
name|resolution
argument_list|)
decl|const
decl_stmt|;
name|int
name|defaultResolution
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|supportedResolutions
argument_list|()
specifier|const
expr_stmt|;
name|QPrint
operator|::
name|InputSlot
name|defaultInputSlot
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPrint
operator|::
name|InputSlot
operator|>
name|supportedInputSlots
argument_list|()
specifier|const
expr_stmt|;
name|QPrint
operator|::
name|OutputBin
name|defaultOutputBin
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPrint
operator|::
name|OutputBin
operator|>
name|supportedOutputBins
argument_list|()
specifier|const
expr_stmt|;
name|QPrint
operator|::
name|DuplexMode
name|defaultDuplexMode
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPrint
operator|::
name|DuplexMode
operator|>
name|supportedDuplexModes
argument_list|()
specifier|const
expr_stmt|;
name|QPrint
operator|::
name|ColorMode
name|defaultColorMode
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPrint
operator|::
name|ColorMode
operator|>
name|supportedColorModes
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MIMETYPE
name|QList
operator|<
name|QMimeType
operator|>
name|supportedMimeTypes
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|private
label|:
name|friend
name|class
name|QPlatformPrinterSupport
decl_stmt|;
name|friend
name|class
name|QPlatformPrintDevice
decl_stmt|;
name|QPrintDevice
argument_list|(
name|QPlatformPrintDevice
operator|*
name|dd
argument_list|)
expr_stmt|;
name|QSharedDataPointer
operator|<
name|QPlatformPrintDevice
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QPrintDevice
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMPRINTDEVICE_H
end_comment
end_unit
