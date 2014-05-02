begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLPLATFORMCURSOR_H
end_ifndef
begin_define
DECL|macro|QEGLPLATFORMCURSOR_H
define|#
directive|define
name|QEGLPLATFORMCURSOR_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLShaderProgram
name|class
name|QOpenGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDeviceDiscovery
name|class
name|QDeviceDiscovery
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEGLPlatformCursor
name|class
name|QEGLPlatformCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEGLPlatformCursorDeviceListener
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QEGLPlatformCursorDeviceListener
argument_list|(
name|QDeviceDiscovery
operator|*
name|dd
argument_list|,
name|QEGLPlatformCursor
operator|*
name|cursor
argument_list|)
block|;
name|bool
name|hasMouse
argument_list|()
specifier|const
block|;
name|private
name|slots
operator|:
name|void
name|onDeviceAdded
argument_list|()
block|;
name|void
name|onDeviceRemoved
argument_list|()
block|;
name|private
operator|:
name|QEGLPlatformCursor
operator|*
name|m_cursor
block|;
name|int
name|m_mouseCount
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEGLPlatformCursorUpdater
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QEGLPlatformCursorUpdater
argument_list|(
name|QPlatformScreen
operator|*
name|screen
argument_list|)
operator|:
name|m_screen
argument_list|(
name|screen
argument_list|)
block|,
name|m_active
argument_list|(
argument|false
argument_list|)
block|{ }
name|void
name|scheduleUpdate
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
specifier|const
name|QRegion
operator|&
name|rgn
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|update
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
specifier|const
name|QRegion
operator|&
name|rgn
argument_list|)
block|;
name|private
operator|:
name|QPlatformScreen
operator|*
name|m_screen
block|;
name|bool
name|m_active
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEGLPlatformCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
name|QEGLPlatformCursor
argument_list|(
name|QPlatformScreen
operator|*
name|screen
argument_list|)
block|;
operator|~
name|QEGLPlatformCursor
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|void
name|changeCursor
argument_list|(
argument|QCursor *cursor
argument_list|,
argument|QWindow *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
name|pointerEvent
argument_list|(
argument|const QMouseEvent&event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QPoint
name|pos
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setPos
argument_list|(
argument|const QPoint&pos
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QRect
name|cursorRect
argument_list|()
specifier|const
block|;
name|void
name|paintOnScreen
argument_list|()
block|;
name|void
name|resetResources
argument_list|()
block|;
name|void
name|setMouseDeviceDiscovery
argument_list|(
name|QDeviceDiscovery
operator|*
name|dd
argument_list|)
block|;
name|void
name|updateMouseStatus
argument_list|()
block|;
name|private
operator|:
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|bool
name|setCurrentCursor
argument_list|(
name|QCursor
operator|*
name|cursor
argument_list|)
block|;
endif|#
directive|endif
name|void
name|draw
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|void
name|update
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|void
name|createShaderPrograms
argument_list|()
block|;
specifier|static
name|void
name|createCursorTexture
argument_list|(
name|uint
operator|*
name|texture
argument_list|,
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|void
name|initCursorAtlas
argument_list|()
block|;
comment|// current cursor information
block|struct
name|Cursor
block|{
name|Cursor
argument_list|()
operator|:
name|texture
argument_list|(
literal|0
argument_list|)
block|,
name|shape
argument_list|(
name|Qt
operator|::
name|BlankCursor
argument_list|)
block|,
name|customCursorTexture
argument_list|(
literal|0
argument_list|)
block|,
name|customCursorPending
argument_list|(
argument|false
argument_list|)
block|{ }
name|uint
name|texture
block|;
comment|// a texture from 'image' or the atlas
name|Qt
operator|::
name|CursorShape
name|shape
block|;
name|QRectF
name|textureRect
block|;
comment|// normalized rect inside texture
name|QSize
name|size
block|;
comment|// size of the cursor
name|QPoint
name|hotSpot
block|;
name|QImage
name|customCursorImage
block|;
name|QPoint
name|pos
block|;
comment|// current cursor position
name|uint
name|customCursorTexture
block|;
name|bool
name|customCursorPending
block|;     }
name|m_cursor
block|;
comment|// cursor atlas information
block|struct
name|CursorAtlas
block|{
name|CursorAtlas
argument_list|()
operator|:
name|cursorsPerRow
argument_list|(
literal|0
argument_list|)
block|,
name|texture
argument_list|(
literal|0
argument_list|)
block|,
name|cursorWidth
argument_list|(
literal|0
argument_list|)
block|,
name|cursorHeight
argument_list|(
literal|0
argument_list|)
block|{ }
name|int
name|cursorsPerRow
block|;
name|uint
name|texture
block|;
name|int
name|width
block|,
name|height
block|;
comment|// width and height of the atlas
name|int
name|cursorWidth
block|,
name|cursorHeight
block|;
comment|// width and height of cursors inside the atlas
name|QList
operator|<
name|QPoint
operator|>
name|hotSpots
block|;
name|QImage
name|image
block|;
comment|// valid until it's uploaded
block|}
name|m_cursorAtlas
block|;
name|bool
name|m_visible
block|;
name|QPlatformScreen
operator|*
name|m_screen
block|;
name|QOpenGLShaderProgram
operator|*
name|m_program
block|;
name|int
name|m_vertexCoordEntry
block|;
name|int
name|m_textureCoordEntry
block|;
name|int
name|m_textureEntry
block|;
name|QEGLPlatformCursorDeviceListener
operator|*
name|m_deviceListener
block|;
name|QEGLPlatformCursorUpdater
name|m_updater
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
comment|// QEGLPLATFORMCURSOR_H
end_comment
end_unit
