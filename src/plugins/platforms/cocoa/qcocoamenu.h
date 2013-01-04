begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author James Turner<james.turner@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAMENU_H
end_ifndef
begin_define
DECL|macro|QCOCOAMENU_H
define|#
directive|define
name|QCOCOAMENU_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|"qcocoamenuitem.h"
end_include
begin_decl_stmt
unit|@
DECL|variable|NSMenuItem
name|class
name|NSMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|NSMenuItem
unit|@
DECL|variable|NSMenu
name|class
name|NSMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|NSMenu
unit|@
DECL|variable|NSObject
name|class
name|NSObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaMenu
range|:
name|public
name|QPlatformMenu
block|{
name|public
operator|:
name|QCocoaMenu
argument_list|()
block|;
operator|~
name|QCocoaMenu
argument_list|()
block|;
specifier|inline
name|virtual
name|void
name|setTag
argument_list|(
argument|quintptr tag
argument_list|)
block|{
name|m_tag
operator|=
name|tag
block|; }
specifier|inline
name|virtual
name|quintptr
name|tag
argument_list|()
specifier|const
block|{
return|return
name|m_tag
return|;
block|}
name|void
name|insertMenuItem
argument_list|(
name|QPlatformMenuItem
operator|*
name|menuItem
argument_list|,
name|QPlatformMenuItem
operator|*
name|before
argument_list|)
block|;
name|void
name|removeMenuItem
argument_list|(
name|QPlatformMenuItem
operator|*
name|menuItem
argument_list|)
block|;
name|void
name|syncMenuItem
argument_list|(
name|QPlatformMenuItem
operator|*
name|menuItem
argument_list|)
block|;
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|showPopup
argument_list|(
argument|const QWindow *parentWindow
argument_list|,
argument|QPoint pos
argument_list|,
argument|const QPlatformMenuItem *item
argument_list|)
block|;
name|void
name|syncSeparatorsCollapsible
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|syncModalState
argument_list|(
argument|bool modal
argument_list|)
block|;
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|setMinimumWidth
argument_list|(
argument|int width
argument_list|)
block|;
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|void
name|setParentItem
argument_list|(
name|QCocoaMenuItem
operator|*
name|item
argument_list|)
block|;
specifier|inline
name|NSMenu
operator|*
name|nsMenu
argument_list|()
specifier|const
block|{
return|return
name|m_nativeMenu
return|;
block|}
specifier|inline
name|NSMenuItem
operator|*
name|nsMenuItem
argument_list|()
specifier|const
block|{
return|return
name|m_nativeItem
return|;
block|}
name|virtual
name|QPlatformMenuItem
operator|*
name|menuItemAt
argument_list|(
argument|int position
argument_list|)
specifier|const
block|;
name|virtual
name|QPlatformMenuItem
operator|*
name|menuItemForTag
argument_list|(
argument|quintptr tag
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QCocoaMenuItem
operator|*
operator|>
name|merged
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QCocoaMenuItem
operator|*
name|itemOrNull
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|insertNative
argument_list|(
name|QCocoaMenuItem
operator|*
name|item
argument_list|,
name|QCocoaMenuItem
operator|*
name|beforeItem
argument_list|)
block|;
name|QList
operator|<
name|QCocoaMenuItem
operator|*
operator|>
name|m_menuItems
block|;
name|NSMenu
operator|*
name|m_nativeMenu
block|;
name|NSMenuItem
operator|*
name|m_nativeItem
block|;
name|NSObject
operator|*
name|m_delegate
block|;
name|bool
name|m_enabled
block|;
name|quintptr
name|m_tag
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
end_unit
