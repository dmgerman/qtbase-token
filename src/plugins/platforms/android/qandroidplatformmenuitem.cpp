begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformmenuitem.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformmenu.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QAndroidPlatformMenuItem
name|QAndroidPlatformMenuItem
operator|::
name|QAndroidPlatformMenuItem
parameter_list|()
block|{
name|m_tag
operator|=
cast|reinterpret_cast
argument_list|<
name|quintptr
argument_list|>
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// QMenu will overwrite this later, but we need a unique ID for QtQuick
name|m_menu
operator|=
literal|0
expr_stmt|;
name|m_isVisible
operator|=
literal|true
expr_stmt|;
name|m_isSeparator
operator|=
literal|false
expr_stmt|;
name|m_role
operator|=
name|NoRole
expr_stmt|;
name|m_isCheckable
operator|=
literal|false
expr_stmt|;
name|m_isChecked
operator|=
literal|false
expr_stmt|;
name|m_isEnabled
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTag
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
block|{
name|m_tag
operator|=
name|tag
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tag
name|quintptr
name|QAndroidPlatformMenuItem
operator|::
name|tag
parameter_list|()
specifier|const
block|{
return|return
name|m_tag
return|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|m_text
operator|=
name|text
expr_stmt|;
if|if
condition|(
name|m_menu
condition|)
name|m_menu
operator|->
name|setText
argument_list|(
name|m_text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAndroidPlatformMenuItem
operator|::
name|text
parameter_list|()
specifier|const
block|{
return|return
name|m_text
return|;
block|}
end_function
begin_function
DECL|function|setIcon
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|m_icon
operator|=
name|icon
expr_stmt|;
if|if
condition|(
name|m_menu
condition|)
name|m_menu
operator|->
name|setIcon
argument_list|(
name|m_icon
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|icon
name|QIcon
name|QAndroidPlatformMenuItem
operator|::
name|icon
parameter_list|()
specifier|const
block|{
return|return
name|m_icon
return|;
block|}
end_function
begin_function
DECL|function|setMenu
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|m_menu
operator|=
cast|static_cast
argument_list|<
name|QAndroidPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menu
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_menu
condition|)
return|return;
name|m_menu
operator|->
name|setText
argument_list|(
name|m_text
argument_list|)
expr_stmt|;
name|m_menu
operator|->
name|setIcon
argument_list|(
name|m_icon
argument_list|)
expr_stmt|;
name|m_menu
operator|->
name|setVisible
argument_list|(
name|m_isVisible
argument_list|)
expr_stmt|;
name|m_menu
operator|->
name|setEnabled
argument_list|(
name|m_isEnabled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|menu
name|QAndroidPlatformMenu
modifier|*
name|QAndroidPlatformMenuItem
operator|::
name|menu
parameter_list|()
specifier|const
block|{
return|return
name|m_menu
return|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setVisible
parameter_list|(
name|bool
name|isVisible
parameter_list|)
block|{
name|m_isVisible
operator|=
name|isVisible
expr_stmt|;
if|if
condition|(
name|m_menu
condition|)
name|m_menu
operator|->
name|setVisible
argument_list|(
name|m_isVisible
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isVisible
name|bool
name|QAndroidPlatformMenuItem
operator|::
name|isVisible
parameter_list|()
specifier|const
block|{
return|return
name|m_isVisible
return|;
block|}
end_function
begin_function
DECL|function|setIsSeparator
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setIsSeparator
parameter_list|(
name|bool
name|isSeparator
parameter_list|)
block|{
name|m_isSeparator
operator|=
name|isSeparator
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isSeparator
name|bool
name|QAndroidPlatformMenuItem
operator|::
name|isSeparator
parameter_list|()
specifier|const
block|{
return|return
name|m_isSeparator
return|;
block|}
end_function
begin_function
DECL|function|setFont
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|font
argument_list|)
block|}
end_function
begin_function
DECL|function|setRole
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setRole
parameter_list|(
name|QPlatformMenuItem
operator|::
name|MenuRole
name|role
parameter_list|)
block|{
name|m_role
operator|=
name|role
expr_stmt|;
block|}
end_function
begin_function
DECL|function|role
name|QPlatformMenuItem
operator|::
name|MenuRole
name|QAndroidPlatformMenuItem
operator|::
name|role
parameter_list|()
specifier|const
block|{
return|return
name|m_role
return|;
block|}
end_function
begin_function
DECL|function|setCheckable
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setCheckable
parameter_list|(
name|bool
name|checkable
parameter_list|)
block|{
name|m_isCheckable
operator|=
name|checkable
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isCheckable
name|bool
name|QAndroidPlatformMenuItem
operator|::
name|isCheckable
parameter_list|()
specifier|const
block|{
return|return
name|m_isCheckable
return|;
block|}
end_function
begin_function
DECL|function|setChecked
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setChecked
parameter_list|(
name|bool
name|isChecked
parameter_list|)
block|{
name|m_isChecked
operator|=
name|isChecked
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isChecked
name|bool
name|QAndroidPlatformMenuItem
operator|::
name|isChecked
parameter_list|()
specifier|const
block|{
return|return
name|m_isChecked
return|;
block|}
end_function
begin_function
DECL|function|setShortcut
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setShortcut
parameter_list|(
specifier|const
name|QKeySequence
modifier|&
name|shortcut
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|shortcut
argument_list|)
block|}
end_function
begin_function
DECL|function|setEnabled
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|m_isEnabled
operator|=
name|enabled
expr_stmt|;
if|if
condition|(
name|m_menu
condition|)
name|m_menu
operator|->
name|setEnabled
argument_list|(
name|m_isEnabled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isEnabled
name|bool
name|QAndroidPlatformMenuItem
operator|::
name|isEnabled
parameter_list|()
specifier|const
block|{
return|return
name|m_isEnabled
return|;
block|}
end_function
begin_function
DECL|function|setIconSize
name|void
name|QAndroidPlatformMenuItem
operator|::
name|setIconSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|size
argument_list|)
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
