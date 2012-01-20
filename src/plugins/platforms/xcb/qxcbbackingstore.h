begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBBACKINGSTORE_H
end_ifndef
begin_define
DECL|macro|QXCBBACKINGSTORE_H
define|#
directive|define
name|QXCBBACKINGSTORE_H
end_define
begin_include
include|#
directive|include
file|<qplatformbackingstore_qpa.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbShmImage
name|class
name|QXcbShmImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbObject
name|class
name|QXcbBackingStore
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformBackingStore
block|{
name|public
label|:
name|QXcbBackingStore
argument_list|(
name|QWindow
operator|*
name|widget
argument_list|)
expr_stmt|;
operator|~
name|QXcbBackingStore
argument_list|()
expr_stmt|;
name|QPaintDevice
modifier|*
name|paintDevice
parameter_list|()
function_decl|;
name|void
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
function_decl|;
name|void
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|staticContents
parameter_list|)
function_decl|;
name|bool
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
function_decl|;
name|void
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
function_decl|;
name|void
name|endPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
function_decl|;
name|private
label|:
name|QXcbShmImage
modifier|*
name|m_image
decl_stmt|;
name|bool
name|m_syncingResize
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
