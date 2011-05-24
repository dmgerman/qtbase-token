begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROXYSCREEN_QWS_H
end_ifndef
begin_define
DECL|macro|QPROXYSCREEN_QWS_H
define|#
directive|define
name|QPROXYSCREEN_QWS_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qscreen_qws.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_PROXYSCREEN
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QProxyScreenPrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_CURSOR
end_ifndef
begin_decl_stmt
DECL|variable|QProxyScreenCursorPrivate
name|class
name|QProxyScreenCursorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QProxyScreenCursor
range|:
name|public
name|QScreenCursor
block|{
name|public
operator|:
name|QProxyScreenCursor
argument_list|()
block|;
operator|~
name|QProxyScreenCursor
argument_list|()
block|;
name|void
name|setScreenCursor
argument_list|(
name|QScreenCursor
operator|*
name|cursor
argument_list|)
block|;
name|QScreenCursor
operator|*
name|screenCursor
argument_list|()
specifier|const
block|;
name|void
name|set
argument_list|(
argument|const QImage&image
argument_list|,
argument|int hotx
argument_list|,
argument|int hoty
argument_list|)
block|;
name|void
name|move
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|void
name|show
argument_list|()
block|;
name|void
name|hide
argument_list|()
block|;
name|private
operator|:
name|void
name|configure
argument_list|()
block|;
name|QScreenCursor
operator|*
name|realCursor
block|;
name|QProxyScreenCursorPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_CURSOR
end_comment
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QProxyScreen
range|:
name|public
name|QScreen
block|{
name|public
operator|:
name|QProxyScreen
argument_list|(
argument|int display_id
argument_list|,
argument|ClassId = ProxyClass
argument_list|)
block|;
operator|~
name|QProxyScreen
argument_list|()
block|;
name|void
name|setScreen
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
name|QScreen
operator|*
name|screen
argument_list|()
specifier|const
block|;
name|QSize
name|mapToDevice
argument_list|(
argument|const QSize&s
argument_list|)
specifier|const
block|;
name|QSize
name|mapFromDevice
argument_list|(
argument|const QSize&s
argument_list|)
specifier|const
block|;
name|QPoint
name|mapToDevice
argument_list|(
argument|const QPoint&
argument_list|,
argument|const QSize&
argument_list|)
specifier|const
block|;
name|QPoint
name|mapFromDevice
argument_list|(
argument|const QPoint&
argument_list|,
argument|const QSize&
argument_list|)
specifier|const
block|;
name|QRect
name|mapToDevice
argument_list|(
argument|const QRect&
argument_list|,
argument|const QSize&
argument_list|)
specifier|const
block|;
name|QRect
name|mapFromDevice
argument_list|(
argument|const QRect&
argument_list|,
argument|const QSize&
argument_list|)
specifier|const
block|;
name|QRegion
name|mapToDevice
argument_list|(
argument|const QRegion&
argument_list|,
argument|const QSize&
argument_list|)
specifier|const
block|;
name|QRegion
name|mapFromDevice
argument_list|(
argument|const QRegion&
argument_list|,
argument|const QSize&
argument_list|)
specifier|const
block|;
name|bool
name|connect
argument_list|(
specifier|const
name|QString
operator|&
name|displaySpec
argument_list|)
block|;
name|bool
name|initDevice
argument_list|()
block|;
name|void
name|shutdownDevice
argument_list|()
block|;
name|void
name|disconnect
argument_list|()
block|;
name|void
name|setMode
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int depth
argument_list|)
block|;
name|bool
name|supportsDepth
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|void
name|save
argument_list|()
block|;
name|void
name|restore
argument_list|()
block|;
name|void
name|blank
argument_list|(
argument|bool on
argument_list|)
block|;
name|bool
name|onCard
argument_list|(
argument|const unsigned char *
argument_list|)
specifier|const
block|;
name|bool
name|onCard
argument_list|(
argument|const unsigned char *
argument_list|,
argument|ulong& out_offset
argument_list|)
specifier|const
block|;
name|bool
name|isInterlaced
argument_list|()
specifier|const
block|;
name|bool
name|isTransformed
argument_list|()
specifier|const
block|;
name|int
name|transformOrientation
argument_list|()
specifier|const
block|;
name|int
name|memoryNeeded
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|int
name|sharedRamSize
argument_list|(
name|void
operator|*
argument_list|)
block|;
name|void
name|haltUpdates
argument_list|()
block|;
name|void
name|resumeUpdates
argument_list|()
block|;
name|void
name|exposeRegion
argument_list|(
argument|QRegion r
argument_list|,
argument|int changing
argument_list|)
block|;
name|void
name|blit
argument_list|(
specifier|const
name|QImage
operator|&
name|img
argument_list|,
specifier|const
name|QPoint
operator|&
name|topLeft
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|void
name|solidFill
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|void
name|setDirty
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
block|;
name|QWSWindowSurface
operator|*
name|createSurface
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|QWSWindowSurface
operator|*
name|createSurface
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QScreen
operator|*
operator|>
name|subScreens
argument_list|()
specifier|const
block|;
name|QRegion
name|region
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|configure
argument_list|()
block|;
name|QScreen
operator|*
name|realScreen
block|;
name|QProxyScreenPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_PROXYSCREEN
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPROXYSCREEN_QWS_H
end_comment
end_unit
