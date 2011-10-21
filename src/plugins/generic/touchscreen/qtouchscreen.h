begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTOUCHSCREEN_H
end_ifndef
begin_define
DECL|macro|QTOUCHSCREEN_H
define|#
directive|define
name|QTOUCHSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTouchScreenData
name|class
name|QTouchScreenData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTouchScreenObserver
block|{
name|public
label|:
name|virtual
name|void
name|touch_configure
parameter_list|(
name|int
name|x_min
parameter_list|,
name|int
name|x_max
parameter_list|,
name|int
name|y_min
parameter_list|,
name|int
name|y_max
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|touch_point
argument_list|(
name|QEvent
operator|::
name|Type
name|state
argument_list|,
specifier|const
name|QList
operator|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
operator|&
name|points
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QTouchScreenHandler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QTouchScreenHandler
argument_list|(
specifier|const
name|QString
operator|&
name|spec
operator|=
name|QString
argument_list|()
argument_list|)
block|;
operator|~
name|QTouchScreenHandler
argument_list|()
block|;
name|void
name|addObserver
argument_list|(
name|QTouchScreenObserver
operator|*
name|observer
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|readData
argument_list|()
block|;
name|private
operator|:
name|void
name|try_udev
argument_list|(
name|QString
operator|*
name|path
argument_list|)
block|;
name|QSocketNotifier
operator|*
name|m_notify
block|;
name|int
name|m_fd
block|;
name|QTouchScreenData
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTouchScreenHandlerThread
range|:
name|public
name|QThread
block|{
name|public
operator|:
name|QTouchScreenHandlerThread
argument_list|(
specifier|const
name|QString
operator|&
name|spec
argument_list|,
name|QTouchScreenObserver
operator|*
name|observer
argument_list|)
block|;
operator|~
name|QTouchScreenHandlerThread
argument_list|()
block|;
name|void
name|run
argument_list|()
block|;
name|QTouchScreenHandler
operator|*
name|handler
argument_list|()
block|{
return|return
name|m_handler
return|;
block|}
name|private
operator|:
name|QString
name|m_spec
block|;
name|QTouchScreenHandler
operator|*
name|m_handler
block|;
name|QTouchScreenObserver
operator|*
name|m_observer
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
comment|// QTOUCHSCREEN_H
end_comment
end_unit
