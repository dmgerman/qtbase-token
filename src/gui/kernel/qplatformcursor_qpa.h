begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtOpenVG module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSYSTEMCURSOR_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSYSTEMCURSOR_H
define|#
directive|define
name|QGRAPHICSSYSTEMCURSOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QWeakPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QCursor>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
comment|// Cursor graphics management
name|class
name|Q_GUI_EXPORT
name|QPlatformCursorImage
block|{
name|public
label|:
name|QPlatformCursorImage
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
block|{
name|set
argument_list|(
name|data
argument_list|,
name|mask
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|hotX
argument_list|,
name|hotY
argument_list|)
expr_stmt|;
block|}
name|QImage
modifier|*
name|image
parameter_list|()
block|{
return|return
operator|&
name|cursorImage
return|;
block|}
name|QPoint
name|hotspot
parameter_list|()
block|{
return|return
name|hot
return|;
block|}
name|void
name|set
parameter_list|(
specifier|const
name|uchar
modifier|*
name|data
parameter_list|,
specifier|const
name|uchar
modifier|*
name|mask
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|hotX
parameter_list|,
name|int
name|hotY
parameter_list|)
function_decl|;
name|void
name|set
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|int
name|hx
parameter_list|,
name|int
name|hy
parameter_list|)
function_decl|;
name|void
name|set
argument_list|(
name|Qt
operator|::
name|CursorShape
argument_list|)
decl_stmt|;
name|private
label|:
specifier|static
name|void
name|createSystemCursor
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
name|QImage
name|cursorImage
decl_stmt|;
name|QPoint
name|hot
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QPlatformCursor
name|class
name|QPlatformCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformCursorPrivate
block|{
name|public
label|:
specifier|static
name|QList
operator|<
name|QWeakPointer
operator|<
name|QPlatformCursor
operator|>
expr|>
name|getInstances
argument_list|()
block|{
return|return
name|instances
return|;
block|}
specifier|static
name|QList
operator|<
name|QWeakPointer
operator|<
name|QPlatformCursor
operator|>
expr|>
name|instances
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformCursor
range|:
name|public
name|QObject
block|{
name|public
operator|:
name|QPlatformCursor
argument_list|(
name|QPlatformScreen
operator|*
argument_list|)
block|;
comment|// input methods
name|virtual
name|void
name|pointerEvent
argument_list|(
argument|const QMouseEvent& event
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
block|; }
name|virtual
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|windowCursor
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QPoint
name|pos
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setPos
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|protected
operator|:
name|QPlatformScreen
operator|*
name|screen
block|;
comment|// Where to request an update
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
name|QPlatformCursor
argument_list|)
block|;
name|friend
name|void
name|qt_qpa_set_cursor
argument_list|(
argument|QWidget * w
argument_list|,
argument|bool force
argument_list|)
block|;
name|friend
name|class
name|QApplicationPrivate
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
comment|// QGRAPHICSSYSTEMCURSOR_H
end_comment
end_unit
