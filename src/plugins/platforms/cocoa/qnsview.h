begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNSVIEW_H
end_ifndef
begin_define
DECL|macro|QNSVIEW_H
define|#
directive|define
name|QNSVIEW_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QAccessible>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCocoaWindow
name|class
name|QCocoaWindow
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
expr|@
name|interface
name|QNSView
operator|:
name|NSView
operator|<
name|NSTextInputClient
operator|>
block|{
name|CGImageRef
name|m_cgImage
block|;
name|QWindow
operator|*
name|m_window
block|;
name|QCocoaWindow
operator|*
name|m_platformWindow
block|;
name|Qt
operator|::
name|MouseButtons
name|m_buttons
block|;
name|QAccessibleInterface
operator|*
name|m_accessibleRoot
block|;
name|QString
name|m_composingText
block|;
name|bool
name|m_sendKeyEvent
block|;
name|QStringList
operator|*
name|currentCustomDragTypes
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|currentWheelModifiers
block|; }
operator|-
operator|(
name|id
operator|)
name|init
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|initWithQWindow
operator|:
operator|(
name|QWindow
operator|*
operator|)
name|window
name|platformWindow
operator|:
operator|(
name|QCocoaWindow
operator|*
operator|)
name|platformWindow
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setImage
operator|:
operator|(
name|QImage
operator|*
operator|)
name|image
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|drawRect
operator|:
operator|(
name|NSRect
operator|)
name|dirtyRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|updateGeometry
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|windowNotification
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|windowNotification
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isFlipped
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|acceptsFirstResponder
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|handleMouseEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseMoved
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseEntered
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseExited
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|handleFrameStrutMouseEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|convertKeyCode
operator|:
operator|(
name|QChar
operator|)
name|keyCode
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|Qt
operator|::
name|KeyboardModifiers
operator|)
name|convertKeyModifiers
operator|:
operator|(
name|ulong
operator|)
name|modifierFlags
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|handleKeyEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
name|eventType
operator|:
operator|(
name|int
operator|)
name|eventType
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|keyDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|keyUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|registerDragTypes
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSDragOperation
operator|)
name|handleDrag
operator|:
operator|(
name|id
operator|<
name|NSDraggingInfo
operator|>
operator|)
name|sender
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
comment|//QNSVIEW_H
end_comment
end_unit
