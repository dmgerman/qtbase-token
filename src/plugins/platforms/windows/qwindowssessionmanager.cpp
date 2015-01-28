begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Samuel Gaist<samuel.gaist@edeltech.ch> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowssessionmanager.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWindowsSessionManager
name|QWindowsSessionManager
operator|::
name|QWindowsSessionManager
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
member_init_list|:
name|QPlatformSessionManager
argument_list|(
name|id
argument_list|,
name|key
argument_list|)
member_init_list|,
name|m_isActive
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_blockUserInput
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_canceled
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|allowsInteraction
name|bool
name|QWindowsSessionManager
operator|::
name|allowsInteraction
parameter_list|()
block|{
name|m_blockUserInput
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|allowsErrorInteraction
name|bool
name|QWindowsSessionManager
operator|::
name|allowsErrorInteraction
parameter_list|()
block|{
name|m_blockUserInput
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|QWindowsSessionManager
operator|::
name|release
parameter_list|()
block|{
if|if
condition|(
name|m_isActive
condition|)
name|m_blockUserInput
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cancel
name|void
name|QWindowsSessionManager
operator|::
name|cancel
parameter_list|()
block|{
name|m_canceled
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
