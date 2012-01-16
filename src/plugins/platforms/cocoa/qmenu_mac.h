begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qt_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qmenu.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qmenubar.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qplatformmenu_qpa.h>
end_include
begin_decl_stmt
unit|@
DECL|variable|NSMenuItem
name|class
name|NSMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaMenuAction
range|:
name|public
name|QPlatformMenuAction
block|{
name|public
operator|:
name|QCocoaMenuAction
argument_list|()
block|;
operator|~
name|QCocoaMenuAction
argument_list|()
block|;
name|NSMenuItem
operator|*
name|menuItem
block|;
name|uchar
name|ignore_accel
operator|:
literal|1
block|;
name|uchar
name|merged
operator|:
literal|1
block|;
name|OSMenuRef
name|menu
block|;
name|QPointer
operator|<
name|QMenu
operator|>
name|qtMenu
block|; }
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QMenuMergeItem
struct|struct
name|QMenuMergeItem
block|{
DECL|function|QMenuMergeItem
specifier|inline
name|QMenuMergeItem
argument_list|(
name|NSMenuItem
operator|*
name|c
argument_list|,
name|QCocoaMenuAction
operator|*
name|a
argument_list|)
operator|:
name|menuItem
argument_list|(
name|c
argument_list|)
operator|,
name|action
argument_list|(
argument|a
argument_list|)
block|{ }
DECL|member|menuItem
name|NSMenuItem
operator|*
name|menuItem
expr_stmt|;
DECL|member|action
name|QCocoaMenuAction
modifier|*
name|action
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|QMenuMergeList
typedef|typedef
name|QList
operator|<
name|QMenuMergeItem
operator|>
name|QMenuMergeList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QCocoaMenu
range|:
name|public
name|QPlatformMenu
block|{
name|public
operator|:
name|QCocoaMenu
argument_list|(
name|QMenu
operator|*
name|qtMenu
argument_list|)
block|;
operator|~
name|QCocoaMenu
argument_list|()
block|;
name|OSMenuRef
name|macMenu
argument_list|(
argument|OSMenuRef merge =
literal|0
argument_list|)
block|;
name|void
name|syncSeparatorsCollapsible
argument_list|(
argument|bool collapse
argument_list|)
block|;
name|void
name|setMenuEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|addAction
argument_list|(
name|QAction
operator|*
name|action
argument_list|,
name|QAction
operator|*
name|before
argument_list|)
block|;
name|void
name|syncAction
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|removeAction
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|addAction
argument_list|(
name|QCocoaMenuAction
operator|*
name|action
argument_list|,
name|QCocoaMenuAction
operator|*
name|before
argument_list|)
block|;
name|void
name|syncAction
argument_list|(
name|QCocoaMenuAction
operator|*
name|action
argument_list|)
block|;
name|void
name|removeAction
argument_list|(
name|QCocoaMenuAction
operator|*
name|action
argument_list|)
block|;
name|bool
name|merged
argument_list|(
argument|const QAction *action
argument_list|)
specifier|const
block|;
name|QCocoaMenuAction
operator|*
name|findAction
argument_list|(
argument|QAction *action
argument_list|)
specifier|const
block|;
name|OSMenuRef
name|menu
block|;
specifier|static
name|QHash
operator|<
name|OSMenuRef
block|,
name|OSMenuRef
operator|>
name|mergeMenuHash
block|;
specifier|static
name|QHash
operator|<
name|OSMenuRef
block|,
name|QMenuMergeList
operator|*
operator|>
name|mergeMenuItemsHash
block|;
name|QList
operator|<
name|QCocoaMenuAction
operator|*
operator|>
name|actionItems
block|;
name|QMenu
operator|*
name|qtMenu
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaMenuBar
range|:
name|public
name|QPlatformMenuBar
block|{
name|public
operator|:
name|QCocoaMenuBar
argument_list|(
name|QMenuBar
operator|*
name|qtMenuBar
argument_list|)
block|;
operator|~
name|QCocoaMenuBar
argument_list|()
block|;
name|void
name|handleReparent
argument_list|(
name|QWidget
operator|*
name|newParent
argument_list|)
block|;
name|void
name|addAction
argument_list|(
name|QAction
operator|*
name|action
argument_list|,
name|QAction
operator|*
name|before
argument_list|)
block|;
name|void
name|syncAction
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|removeAction
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|addAction
argument_list|(
name|QCocoaMenuAction
operator|*
name|action
argument_list|,
name|QCocoaMenuAction
operator|*
name|before
argument_list|)
block|;
name|void
name|syncAction
argument_list|(
name|QCocoaMenuAction
operator|*
name|action
argument_list|)
block|;
name|void
name|removeAction
argument_list|(
name|QCocoaMenuAction
operator|*
name|action
argument_list|)
block|;
name|bool
name|macWidgetHasNativeMenubar
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|macCreateMenuBar
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|void
name|macDestroyMenuBar
argument_list|()
block|;
name|OSMenuRef
name|macMenu
argument_list|()
block|;
specifier|static
name|bool
name|macUpdateMenuBarImmediatly
argument_list|()
block|;
specifier|static
name|void
name|macUpdateMenuBar
argument_list|()
block|;
name|QCocoaMenuAction
operator|*
name|findAction
argument_list|(
argument|QAction *action
argument_list|)
specifier|const
block|;
name|OSMenuRef
name|menu
block|;
name|OSMenuRef
name|apple_menu
block|;
name|QList
operator|<
name|QCocoaMenuAction
operator|*
operator|>
name|actionItems
block|;
name|QMenuBar
operator|*
name|qtMenuBar
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
