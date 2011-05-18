begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_if
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|<=
name|MAC_OS_X_VERSION_10_5
end_if
begin_expr_stmt
unit|@
name|protocol
name|NSWindowDelegate
operator|<
name|NSObject
operator|>
comment|//- (NSSize)windowWillResize:(NSWindow *)window toSize:(NSSize)proposedFrameSize;
comment|//- (void)windowDidMiniaturize:(NSNotification*)notification;
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
name|windowWillClose
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|notification
expr_stmt|;
end_expr_stmt
begin_comment
comment|//- (NSRect)windowWillUseStandardFrame:(NSWindow *)window defaultFrame:(NSRect)defaultFrame;
end_comment
begin_comment
comment|//- (void)windowDidMove:(NSNotification *)notification;
end_comment
begin_comment
comment|//- (BOOL)windowShouldClose:(id)window;
end_comment
begin_comment
comment|//- (void)windowDidDeminiaturize:(NSNotification *)notification;
end_comment
begin_comment
comment|//- (void)windowDidBecomeMain:(NSNotification*)notification;
end_comment
begin_comment
comment|//- (void)windowDidResignMain:(NSNotification*)notification;
end_comment
begin_comment
comment|//- (void)windowDidBecomeKey:(NSNotification*)notification;
end_comment
begin_comment
comment|//- (void)windowDidResignKey:(NSNotification*)notification;
end_comment
begin_comment
comment|//- (BOOL)window:(NSWindow *)window shouldPopUpDocumentPathMenu:(NSMenu *)menu;
end_comment
begin_comment
comment|//- (BOOL)window:(NSWindow *)window shouldDragDocumentWithEvent:(NSEvent *)event from:(NSPoint)dragImageLocation withPasteboard:(NSPasteboard *)pasteboard;
end_comment
begin_comment
comment|//- (BOOL)windowShouldZoom:(NSWindow *)window toFrame:(NSRect)newFrame;
end_comment
begin_expr_stmt
unit|@
name|end
endif|#
directive|endif
expr|@
name|interface
name|QNSWindowDelegate
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
name|windowWillClose
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|notification
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNSWINDOWDELEGATE_H
end_comment
end_unit
