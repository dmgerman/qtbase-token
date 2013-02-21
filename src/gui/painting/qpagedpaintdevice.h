begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
block|;      enum
name|PageSize
block|{
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
name|NPageSize
operator|=
name|Custom
block|}
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
block|;      struct
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
