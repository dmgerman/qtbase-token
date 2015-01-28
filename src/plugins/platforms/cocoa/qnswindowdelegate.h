begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNSWINDOWDELEGATE_H
end_ifndef
begin_define
DECL|macro|QNSWINDOWDELEGATE_H
define|#
directive|define
name|QNSWINDOWDELEGATE_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|"qcocoawindow.h"
end_include
begin_macro
unit|@
DECL|function|QT_MANGLE_NAMESPACE
name|interface
end_macro
begin_expr_stmt
DECL|function|QT_MANGLE_NAMESPACE
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QNSWindowDelegate
argument_list|)
operator|:
name|NSObject
operator|<
name|NSWindowDelegate
operator|>
block|{
name|QCocoaWindow
operator|*
name|m_cocoaWindow
block|; }
operator|-
operator|(
name|id
operator|)
name|initWithQCocoaWindow
operator|:
operator|(
name|QCocoaWindow
operator|*
operator|)
name|cocoaWindow
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|windowDidBecomeKey
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|notification
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|windowDidResize
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|notification
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|windowDidMove
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|notification
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|windowWillMove
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|notification
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|windowShouldClose
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|notification
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|windowShouldZoom
operator|:
operator|(
name|NSWindow
operator|*
operator|)
name|window
name|toFrame
operator|:
operator|(
name|NSRect
operator|)
name|newFrame
expr_stmt|;
end_expr_stmt
begin_function_decl
unit|@
name|end
name|QT_NAMESPACE_ALIAS_OBJC_CLASS
parameter_list|(
name|QNSWindowDelegate
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNSWINDOWDELEGATE_H
end_comment
end_unit
