begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Samuel Gaist<samuel.gaist@edeltech.ch> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSSESSIONMANAGER_H
end_ifndef
begin_define
DECL|macro|QWINDOWSSESSIONMANAGER_H
define|#
directive|define
name|QWINDOWSSESSIONMANAGER_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformsessionmanager.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QWindowsSessionManager
range|:
name|public
name|QPlatformSessionManager
block|{
name|public
operator|:
name|explicit
name|QWindowsSessionManager
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|,
specifier|const
name|QString
operator|&
name|key
argument_list|)
block|;
name|bool
name|allowsInteraction
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|allowsErrorInteraction
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|blocksInteraction
argument_list|()
block|{
name|m_blockUserInput
operator|=
name|true
block|; }
name|bool
name|isInteractionBlocked
argument_list|()
specifier|const
block|{
return|return
name|m_blockUserInput
return|;
block|}
name|void
name|release
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|cancel
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|clearCancellation
argument_list|()
block|{
name|m_canceled
operator|=
name|false
block|; }
name|bool
name|wasCanceled
argument_list|()
specifier|const
block|{
return|return
name|m_canceled
return|;
block|}
name|void
name|setActive
argument_list|(
argument|bool active
argument_list|)
block|{
name|m_isActive
operator|=
name|active
block|; }
name|bool
name|isActive
argument_list|()
specifier|const
block|{
return|return
name|m_isActive
return|;
block|}
name|private
operator|:
name|bool
name|m_isActive
block|;
name|bool
name|m_blockUserInput
block|;
name|bool
name|m_canceled
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsSessionManager
argument_list|)
block|}
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
comment|// QWINDOWSSESSIONMANAGER_H
end_comment
end_unit
