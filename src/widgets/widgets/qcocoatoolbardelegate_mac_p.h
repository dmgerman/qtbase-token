begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|"qmacdefines_mac.h"
end_include
begin_empty
empty|#import<Cocoa/Cocoa.h>
end_empty
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMainWindowLayout
name|class
name|QMainWindowLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolBar
name|class
name|QToolBar
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
expr|@
DECL|variable|NSToolbarItem
name|class
name|NSToolbarItem
expr_stmt|;
end_expr_stmt
begin_macro
DECL|variable|NSToolbarItem
unit|@
DECL|function|QT_MANGLE_NAMESPACE
name|interface
end_macro
begin_expr_stmt
DECL|function|QT_MANGLE_NAMESPACE
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QCocoaToolBarDelegate
argument_list|)
operator|:
name|NSObject
block|{
name|QT_PREPEND_NAMESPACE
argument_list|(
name|QMainWindowLayout
argument_list|)
operator|*
name|mainWindowLayout
block|;
name|NSToolbarItem
operator|*
name|toolbarItem
block|; }
operator|-
operator|(
name|id
operator|)
name|initWithMainWindowLayout
operator|:
operator|(
name|QT_PREPEND_NAMESPACE
argument_list|(
name|QMainWindowLayout
argument_list|)
operator|*
operator|)
name|layout
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
end_unit
