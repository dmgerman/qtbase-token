begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFBCURSOR_P_H
end_ifndef
begin_define
DECL|macro|QFBCURSOR_P_H
define|#
directive|define
name|QFBCURSOR_P_H
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
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qinputdevicemanager_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFbScreen
name|class
name|QFbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbCursor
name|class
name|QFbCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFbCursorDeviceListener
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QFbCursorDeviceListener
argument_list|(
name|QFbCursor
operator|*
name|cursor
argument_list|)
operator|:
name|m_cursor
argument_list|(
argument|cursor
argument_list|)
block|{ }
name|bool
name|hasMouse
argument_list|()
specifier|const
block|;
name|public
name|slots
operator|:
name|void
name|onDeviceListChanged
argument_list|(
argument|QInputDeviceManager::DeviceType type
argument_list|)
block|;
name|private
operator|:
name|QFbCursor
operator|*
name|m_cursor
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFbCursor
range|:
name|public
name|QPlatformCursor
block|{
name|Q_OBJECT
name|public
operator|:
name|QFbCursor
argument_list|(
name|QFbScreen
operator|*
name|screen
argument_list|)
block|;
operator|~
name|QFbCursor
argument_list|()
block|;
comment|// output methods
name|QRect
name|dirtyRect
argument_list|()
block|;
name|virtual
name|QRect
name|drawCursor
argument_list|(
name|QPainter
operator|&
name|painter
argument_list|)
block|;
comment|// input methods
name|virtual
name|void
name|pointerEvent
argument_list|(
argument|const QMouseEvent&event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|virtual
name|void
name|changeCursor
argument_list|(
argument|QCursor *widgetCursor
argument_list|,
argument|QWindow *window
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|virtual
name|void
name|setDirty
argument_list|()
block|;
name|virtual
name|bool
name|isDirty
argument_list|()
specifier|const
block|{
return|return
name|mDirty
return|;
block|}
name|virtual
name|bool
name|isOnScreen
argument_list|()
specifier|const
block|{
return|return
name|mOnScreen
return|;
block|}
name|virtual
name|QRect
name|lastPainted
argument_list|()
specifier|const
block|{
return|return
name|mPrevRect
return|;
block|}
name|void
name|updateMouseStatus
argument_list|()
block|;
name|private
operator|:
name|void
name|setCursor
argument_list|(
argument|const uchar *data
argument_list|,
argument|const uchar *mask
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int hotX
argument_list|,
argument|int hotY
argument_list|)
block|;
name|void
name|setCursor
argument_list|(
argument|Qt::CursorShape shape
argument_list|)
block|;
name|void
name|setCursor
argument_list|(
argument|const QImage&image
argument_list|,
argument|int hotx
argument_list|,
argument|int hoty
argument_list|)
block|;
name|QRect
name|getCurrentRect
argument_list|()
block|;
name|bool
name|mVisible
block|;
name|QFbScreen
operator|*
name|mScreen
block|;
name|QRect
name|mCurrentRect
block|;
comment|// next place to draw the cursor
name|QRect
name|mPrevRect
block|;
comment|// last place the cursor was drawn
name|bool
name|mDirty
block|;
name|bool
name|mOnScreen
block|;
name|QPlatformCursorImage
operator|*
name|mGraphic
block|;
name|QFbCursorDeviceListener
operator|*
name|mDeviceListener
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
comment|// QFBCURSOR_P_H
end_comment
end_unit
