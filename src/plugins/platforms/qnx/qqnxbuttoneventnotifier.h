begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXBUTTONSEVENTNOTIFIER_H
end_ifndef
begin_define
DECL|macro|QQNXBUTTONSEVENTNOTIFIER_H
define|#
directive|define
name|QQNXBUTTONSEVENTNOTIFIER_H
end_define
begin_include
include|#
directive|include
file|<QObject>
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
name|QQnxButtonEventNotifier
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|ButtonId
argument_list|)
name|public
operator|:
expr|enum
name|ButtonId
block|{
name|bid_minus
operator|=
literal|0
block|,
name|bid_playpause
block|,
name|bid_plus
block|,
name|bid_power
block|,
name|ButtonCount
block|}
block|;      enum
name|ButtonState
block|{
name|ButtonUp
block|,
name|ButtonDown
block|}
block|;
name|explicit
name|QQnxButtonEventNotifier
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QQnxButtonEventNotifier
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|updateButtonStates
argument_list|()
block|;
name|private
operator|:
name|void
name|close
argument_list|()
block|;
name|bool
name|parsePPS
argument_list|(
argument|const QByteArray&ppsData
argument_list|,
argument|QHash<QByteArray
argument_list|,
argument|QByteArray> *messageFields
argument_list|)
specifier|const
block|;
name|int
name|m_fd
block|;
name|QSocketNotifier
operator|*
name|m_readNotifier
block|;
name|ButtonState
name|m_state
index|[
name|ButtonCount
index|]
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|m_buttonKeys
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
comment|// QQNXBUTTONSEVENTNOTIFIER_H
end_comment
end_unit
