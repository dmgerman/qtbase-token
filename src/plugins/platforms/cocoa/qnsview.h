begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<AppKit/AppKit.h>
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
begin_include
include|#
directive|include
file|"private/qcore_mac_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCocoaWindow
name|class
name|QCocoaWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCocoaBackingStore
name|class
name|QCocoaBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCocoaGLContext
name|class
name|QCocoaGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_FORWARD_DECLARE_OBJC_CLASS
argument_list|(
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QNSViewMouseMoveHelper
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|function|QT_MANGLE_NAMESPACE
name|interface
end_macro
begin_expr_stmt
DECL|function|QT_MANGLE_NAMESPACE
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QNSView
argument_list|)
operator|:
name|NSView
operator|<
name|NSTextInputClient
operator|>
block|{
name|QCocoaBackingStore
operator|*
name|m_backingStore
block|;
name|QPoint
name|m_backingStoreOffset
block|;
name|CGImageRef
name|m_maskImage
block|;
name|uchar
operator|*
name|m_maskData
block|;
name|bool
name|m_shouldInvalidateWindowShadow
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|m_window
block|;
name|QCocoaWindow
operator|*
name|m_platformWindow
block|;
name|NSTrackingArea
operator|*
name|m_trackingArea
block|;
name|Qt
operator|::
name|MouseButtons
name|m_buttons
block|;
name|Qt
operator|::
name|MouseButtons
name|m_frameStrutButtons
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
name|bool
name|m_sendUpAsRightButton
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|currentWheelModifiers
block|;
name|bool
name|m_subscribesForGlobalFrameNotifications
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|QCocoaGLContext
operator|*
name|m_glContext
block|;
name|bool
name|m_shouldSetGLContextinDrawRect
block|;
endif|#
directive|endif
name|NSString
operator|*
name|m_inputSource
block|;
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QNSViewMouseMoveHelper
argument_list|)
operator|*
name|m_mouseMoveHelper
block|;
name|bool
name|m_resendKeyEvent
block|;
name|bool
name|m_scrolling
block|;
name|bool
name|m_updatingDrag
block|;
name|bool
name|m_exposedOnMoveToWindow
block|;
name|NSEvent
operator|*
name|m_currentlyInterpretedKeyEvent
block|;
name|bool
name|m_isMenuView
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
name|clearQWindowPointers
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setQCocoaGLContext
operator|:
operator|(
name|QCocoaGLContext
operator|*
operator|)
name|context
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|flushBackingStore
operator|:
operator|(
name|QCocoaBackingStore
operator|*
operator|)
name|backingStore
name|region
operator|:
operator|(
specifier|const
name|QRegion
operator|&
operator|)
name|region
name|offset
operator|:
operator|(
name|QPoint
operator|)
name|offset
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|clearBackingStore
operator|:
operator|(
name|QCocoaBackingStore
operator|*
operator|)
name|backingStore
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setMaskRegion
operator|:
operator|(
specifier|const
name|QRegion
operator|*
operator|)
name|region
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|invalidateWindowShadowIfNeeded
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
name|notifyWindowStateChanged
operator|:
operator|(
name|Qt
operator|::
name|WindowState
operator|)
name|newState
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
name|void
operator|)
name|notifyWindowWillZoom
operator|:
operator|(
name|BOOL
operator|)
name|willZoom
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|textInputContextKeyboardSelectionDidChangeNotification
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|textInputContextKeyboardSelectionDidChangeNotification
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|viewDidHide
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|viewDidUnhide
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
name|BOOL
operator|)
name|becomeFirstResponder
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|hasMask
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isOpaque
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|convertFromScreen
operator|:
operator|(
name|NSPoint
operator|)
name|mouseLocation
name|toWindowPoint
operator|:
operator|(
name|QPointF
operator|*
operator|)
name|qtWindowPoint
name|andScreenPoint
operator|:
operator|(
name|QPointF
operator|*
operator|)
name|qtScreenPoint
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|resetMouseButtons
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
name|mouseMovedImpl
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
name|mouseEnteredImpl
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
name|mouseExitedImpl
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
name|cursorUpdateImpl
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
name|void
operator|)
name|handleTabletEvent
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
name|tabletPoint
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
name|tabletProximity
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
operator|+
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
begin_function_decl
unit|@
name|end
name|QT_NAMESPACE_ALIAS_OBJC_CLASS
parameter_list|(
name|QNSView
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QNSVIEW_H
end_comment
end_unit
