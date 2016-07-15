begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVDEVMOUSEHANDLER_P_H
end_ifndef
begin_define
DECL|macro|QEVDEVMOUSEHANDLER_P_H
define|#
directive|define
name|QEVDEVMOUSEHANDLER_P_H
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
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEvdevMouseHandler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
name|QEvdevMouseHandler
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|device
argument_list|,
specifier|const
name|QString
operator|&
name|specification
argument_list|)
block|;
operator|~
name|QEvdevMouseHandler
argument_list|()
block|;
name|signals
operator|:
name|void
name|handleMouseEvent
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|bool abs
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|)
block|;
name|void
name|handleWheelEvent
argument_list|(
argument|int delta
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|readMouseData
argument_list|()
block|;
name|private
operator|:
name|QEvdevMouseHandler
argument_list|(
argument|const QString&device
argument_list|,
argument|int fd
argument_list|,
argument|bool abs
argument_list|,
argument|bool compression
argument_list|,
argument|int jitterLimit
argument_list|)
block|;
name|void
name|sendMouseEvent
argument_list|()
block|;
name|bool
name|getHardwareMaximum
argument_list|()
block|;
name|QString
name|m_device
block|;
name|int
name|m_fd
block|;
name|QSocketNotifier
operator|*
name|m_notify
block|;
name|int
name|m_x
block|,
name|m_y
block|;
name|int
name|m_prevx
block|,
name|m_prevy
block|;
name|bool
name|m_abs
block|;
name|bool
name|m_compression
block|;
name|Qt
operator|::
name|MouseButtons
name|m_buttons
block|;
name|int
name|m_jitterLimitSquared
block|;
name|bool
name|m_prevInvalid
block|;
name|int
name|m_hardwareWidth
block|;
name|int
name|m_hardwareHeight
block|;
name|qreal
name|m_hardwareScalerY
block|;
name|qreal
name|m_hardwareScalerX
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
comment|// QEVDEVMOUSEHANDLER_P_H
end_comment
end_unit
