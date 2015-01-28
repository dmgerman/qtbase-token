begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSHAPEDPIXMAPDNDWINDOW_H
end_ifndef
begin_define
DECL|macro|QSHAPEDPIXMAPDNDWINDOW_H
define|#
directive|define
name|QSHAPEDPIXMAPDNDWINDOW_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_include
include|#
directive|include
file|<QtGui/QBackingStore>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QShapedPixmapWindow
range|:
name|public
name|QWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|QShapedPixmapWindow
argument_list|()
block|;
operator|~
name|QShapedPixmapWindow
argument_list|()
block|;
name|void
name|render
argument_list|()
block|;
name|void
name|setPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
block|;
name|void
name|setHotspot
argument_list|(
specifier|const
name|QPoint
operator|&
name|hotspot
argument_list|)
block|;
name|void
name|updateGeometry
argument_list|()
block|;
name|protected
operator|:
name|void
name|exposeEvent
argument_list|(
argument|QExposeEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QBackingStore
operator|*
name|m_backingStore
block|;
name|QPixmap
name|m_pixmap
block|;
name|QPoint
name|m_hotSpot
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
comment|// QSHAPEDPIXMAPDNDWINDOW_H
end_comment
end_unit
