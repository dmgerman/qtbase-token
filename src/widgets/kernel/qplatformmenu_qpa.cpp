begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformmenu_qpa.h"
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|// QPlatformMenuAction
comment|//
DECL|function|~QPlatformMenuAction
name|QPlatformMenuAction
operator|::
name|~
name|QPlatformMenuAction
operator|(
operator|)
block|{  }
comment|//
comment|// QPlatformMenu
comment|//
DECL|function|QPlatformMenu
name|QPlatformMenu
operator|::
name|QPlatformMenu
operator|(
operator|)
block|{ }
DECL|function|~QPlatformMenu
name|QPlatformMenu
operator|::
name|~
name|QPlatformMenu
operator|(
operator|)
block|{  }
DECL|function|setMenuEnabled
name|void
name|QPlatformMenu
operator|::
name|setMenuEnabled
operator|(
name|bool
name|enable
operator|)
block|{
name|Q_UNUSED
argument_list|(
name|enable
argument_list|)
block|; }
DECL|function|syncSeparatorsCollapsible
name|void
name|QPlatformMenu
operator|::
name|syncSeparatorsCollapsible
operator|(
name|bool
name|enable
operator|)
block|{
name|Q_UNUSED
argument_list|(
name|enable
argument_list|)
block|; }
comment|//
comment|// QPlatformMenuBar
comment|//
DECL|function|QPlatformMenuBar
name|QPlatformMenuBar
operator|::
name|QPlatformMenuBar
operator|(
operator|)
block|{  }
DECL|function|~QPlatformMenuBar
name|QPlatformMenuBar
operator|::
name|~
name|QPlatformMenuBar
operator|(
operator|)
block|{  }
DECL|function|handleReparent
name|void
name|QPlatformMenuBar
operator|::
name|handleReparent
operator|(
name|QWidget
operator|*
name|newParent
operator|)
block|{
name|Q_UNUSED
argument_list|(
name|newParent
argument_list|)
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
end_unit
