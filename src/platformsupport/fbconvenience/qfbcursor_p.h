begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFbCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
name|QFbCursor
argument_list|(
name|QPlatformScreen
operator|*
name|scr
argument_list|)
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
specifier|const
name|QMouseEvent
operator|&
name|event
argument_list|)
block|;
name|virtual
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|widgetCursor
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|virtual
name|void
name|setDirty
argument_list|()
block|{
name|dirty
operator|=
name|true
block|;
comment|/* screen->setDirty(QRect()); */
block|}
name|virtual
name|bool
name|isDirty
argument_list|()
block|{
return|return
name|dirty
return|;
block|}
name|virtual
name|bool
name|isOnScreen
argument_list|()
block|{
return|return
name|onScreen
return|;
block|}
name|virtual
name|QRect
name|lastPainted
argument_list|()
block|{
return|return
name|prevRect
return|;
block|}
name|protected
operator|:
name|QPlatformCursorImage
operator|*
name|graphic
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
name|QPlatformScreen
operator|*
name|screen
block|;
name|QRect
name|currentRect
block|;
comment|// next place to draw the cursor
name|QRect
name|prevRect
block|;
comment|// last place the cursor was drawn
name|QRect
name|getCurrentRect
argument_list|()
block|;
name|bool
name|dirty
block|;
name|bool
name|onScreen
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
