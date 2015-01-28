begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDRAG_H
end_ifndef
begin_define
DECL|macro|QDRAG_H
define|#
directive|define
name|QDRAG_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDragPrivate
name|class
name|QDragPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDragManager
name|class
name|QDragManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDrag
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDrag
argument_list|)
name|public
operator|:
name|explicit
name|QDrag
argument_list|(
name|QObject
operator|*
name|dragSource
argument_list|)
block|;
operator|~
name|QDrag
argument_list|()
block|;
name|void
name|setMimeData
argument_list|(
name|QMimeData
operator|*
name|data
argument_list|)
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|()
specifier|const
block|;
name|void
name|setPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
name|QPixmap
name|pixmap
argument_list|()
specifier|const
block|;
name|void
name|setHotSpot
argument_list|(
specifier|const
name|QPoint
operator|&
name|hotspot
argument_list|)
block|;
name|QPoint
name|hotSpot
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|source
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|target
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|DropAction
name|start
argument_list|(
argument|Qt::DropActions supportedActions = Qt::CopyAction
argument_list|)
block|;
name|Qt
operator|::
name|DropAction
name|exec
argument_list|(
argument|Qt::DropActions supportedActions = Qt::MoveAction
argument_list|)
block|;
name|Qt
operator|::
name|DropAction
name|exec
argument_list|(
argument|Qt::DropActions supportedActions
argument_list|,
argument|Qt::DropAction defaultAction
argument_list|)
block|;
name|void
name|setDragCursor
argument_list|(
argument|const QPixmap&cursor
argument_list|,
argument|Qt::DropAction action
argument_list|)
block|;
name|QPixmap
name|dragCursor
argument_list|(
argument|Qt::DropAction action
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|DropActions
name|supportedActions
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|DropAction
name|defaultAction
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|actionChanged
argument_list|(
argument|Qt::DropAction action
argument_list|)
block|;
name|void
name|targetChanged
argument_list|(
name|QObject
operator|*
name|newTarget
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QDragManager
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QDrag
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDRAG_H
end_comment
end_unit
