begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBACKINGSTORE_H
end_ifndef
begin_define
DECL|macro|QBACKINGSTORE_H
define|#
directive|define
name|QBACKINGSTORE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qregion.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBackingStorePrivate
name|class
name|QBackingStorePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformBackingStore
name|class
name|QPlatformBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QBackingStore
block|{
name|public
label|:
name|QBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
expr_stmt|;
operator|~
name|QBackingStore
argument_list|()
expr_stmt|;
name|QWindow
operator|*
name|window
argument_list|()
specifier|const
expr_stmt|;
name|QPaintDevice
modifier|*
name|paintDevice
parameter_list|()
function_decl|;
comment|// 'window' can be a child window, in which case 'region' is in child window coordinates and
comment|// offset is the (child) window's offset in relation to the window surface.
name|void
name|flush
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
name|QWindow
modifier|*
name|window
init|=
literal|0
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
init|=
name|QPoint
argument_list|()
parameter_list|)
function_decl|;
name|void
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|QSize
name|size
argument_list|()
specifier|const
expr_stmt|;
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
parameter_list|()
function_decl|;
name|void
name|setStaticContents
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|QRegion
name|staticContents
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasStaticContents
argument_list|()
specifier|const
expr_stmt|;
name|QPlatformBackingStore
operator|*
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QScopedPointer
operator|<
name|QBackingStorePrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBACKINGSTORE_H
end_comment
end_unit
