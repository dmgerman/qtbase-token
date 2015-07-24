begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIOSMENU_H
end_ifndef
begin_define
DECL|macro|QIOSMENU_H
define|#
directive|define
name|QIOSMENU_H
end_define
begin_empty
empty|#import<UIKit/UIKit.h>
end_empty
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_empty
empty|#import "quiview.h"
end_empty
begin_decl_stmt
DECL|variable|QIOSMenu
name|class
name|QIOSMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIOSMenu
unit|@
DECL|variable|QUIMenuController
name|class
name|QUIMenuController
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUIMenuController
unit|@
DECL|variable|QUIPickerView
name|class
name|QUIPickerView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QIOSMenuItem
range|:
name|public
name|QPlatformMenuItem
block|{
name|public
operator|:
name|QIOSMenuItem
argument_list|()
block|;
name|void
name|setTag
argument_list|(
argument|quintptr tag
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|quintptr
name|tag
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setText
argument_list|(
argument|const QString&text
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setIcon
argument_list|(
argument|const QIcon&
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|void
name|setMenu
argument_list|(
argument|QPlatformMenu *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setVisible
argument_list|(
argument|bool isVisible
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setIsSeparator
argument_list|(
argument|bool
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setFont
argument_list|(
argument|const QFont&
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|void
name|setRole
argument_list|(
argument|MenuRole role
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setCheckable
argument_list|(
argument|bool
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|void
name|setChecked
argument_list|(
argument|bool
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|void
name|setShortcut
argument_list|(
argument|const QKeySequence&
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setIconSize
argument_list|(
argument|int
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|quintptr
name|m_tag
block|;
name|bool
name|m_visible
block|;
name|QString
name|m_text
block|;
name|MenuRole
name|m_role
block|;
name|bool
name|m_enabled
block|;
name|bool
name|m_separator
block|;
name|QIOSMenu
operator|*
name|m_menu
block|;
name|private
operator|:
name|QString
name|removeMnemonics
argument_list|(
specifier|const
name|QString
operator|&
name|original
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QIOSMenuItemList
typedef|typedef
name|QList
operator|<
name|QIOSMenuItem
operator|*
operator|>
name|QIOSMenuItemList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QIOSMenu
range|:
name|public
name|QPlatformMenu
block|{
name|public
operator|:
name|QIOSMenu
argument_list|()
block|;
operator|~
name|QIOSMenu
argument_list|()
block|;
name|void
name|insertMenuItem
argument_list|(
argument|QPlatformMenuItem *menuItem
argument_list|,
argument|QPlatformMenuItem *before
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|removeMenuItem
argument_list|(
argument|QPlatformMenuItem *menuItem
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|syncMenuItem
argument_list|(
argument|QPlatformMenuItem *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|syncSeparatorsCollapsible
argument_list|(
argument|bool
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|void
name|setTag
argument_list|(
argument|quintptr tag
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|quintptr
name|tag
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setText
argument_list|(
argument|const QString&
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setIcon
argument_list|(
argument|const QIcon&
argument_list|)
name|Q_DECL_OVERRIDE
block|{}
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setMenuType
argument_list|(
argument|MenuType type
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|showPopup
argument_list|(
argument|const QWindow *parentWindow
argument_list|,
argument|const QRect&targetRect
argument_list|,
argument|const QPlatformMenuItem *item
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dismiss
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QPlatformMenuItem
operator|*
name|menuItemAt
argument_list|(
argument|int position
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformMenuItem
operator|*
name|menuItemForTag
argument_list|(
argument|quintptr tag
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|handleItemSelected
argument_list|(
name|QIOSMenuItem
operator|*
name|menuItem
argument_list|)
block|;
specifier|static
name|QIOSMenu
operator|*
name|currentMenu
argument_list|()
block|{
return|return
name|m_currentMenu
return|;
block|}
specifier|static
name|id
name|menuActionTarget
argument_list|()
block|{
return|return
name|m_currentMenu
operator|?
name|m_currentMenu
operator|->
name|m_menuController
operator|:
literal|0
return|;
block|}
name|protected
operator|:
name|bool
name|eventFilter
argument_list|(
argument|QObject *obj
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|quintptr
name|m_tag
block|;
name|bool
name|m_enabled
block|;
name|bool
name|m_visible
block|;
name|QString
name|m_text
block|;
name|MenuType
name|m_menuType
block|;
name|MenuType
name|m_effectiveMenuType
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|m_parentWindow
block|;
name|QRect
name|m_targetRect
block|;
specifier|const
name|QIOSMenuItem
operator|*
name|m_targetItem
block|;
name|QUIMenuController
operator|*
name|m_menuController
block|;
name|QUIPickerView
operator|*
name|m_pickerView
block|;
name|QIOSMenuItemList
name|m_menuItems
block|;
specifier|static
name|QIOSMenu
operator|*
name|m_currentMenu
block|;
name|void
name|updateVisibility
argument_list|()
block|;
name|void
name|toggleShowUsingUIMenuController
argument_list|(
argument|bool show
argument_list|)
block|;
name|void
name|toggleShowUsingUIPickerView
argument_list|(
argument|bool show
argument_list|)
block|;
name|QIOSMenuItemList
name|visibleMenuItems
argument_list|()
specifier|const
block|;
name|void
name|repositionMenu
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIOSMENU_H
end_comment
end_unit
