begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSWINDOW_H
end_ifndef
begin_define
DECL|macro|QWINDOWSWINDOW_H
define|#
directive|define
name|QWINDOWSWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscursor.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindow>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsOleDropTarget
name|class
name|QWindowsOleDropTarget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QWindowsGeometryHint
struct|struct
name|QWindowsGeometryHint
block|{
DECL|function|QWindowsGeometryHint
name|QWindowsGeometryHint
argument_list|()
block|{}
name|explicit
name|QWindowsGeometryHint
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
specifier|static
name|QMargins
name|frame
parameter_list|(
name|DWORD
name|style
parameter_list|,
name|DWORD
name|exStyle
parameter_list|)
function_decl|;
name|void
name|applyToMinMaxInfo
argument_list|(
name|DWORD
name|style
argument_list|,
name|DWORD
name|exStyle
argument_list|,
name|MINMAXINFO
operator|*
name|mmi
argument_list|)
decl|const
decl_stmt|;
name|void
name|applyToMinMaxInfo
argument_list|(
name|HWND
name|hwnd
argument_list|,
name|MINMAXINFO
operator|*
name|mmi
argument_list|)
decl|const
decl_stmt|;
name|bool
name|validSize
argument_list|(
specifier|const
name|QSize
operator|&
name|s
argument_list|)
decl|const
decl_stmt|;
specifier|static
specifier|inline
name|QPoint
name|mapToGlobal
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|QPoint
name|mapToGlobal
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|QPoint
name|mapFromGlobal
parameter_list|(
specifier|const
name|HWND
name|hwnd
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|QPoint
name|mapFromGlobal
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
DECL|member|minimumSize
name|QSize
name|minimumSize
decl_stmt|;
DECL|member|maximumSize
name|QSize
name|maximumSize
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QWindowCreationContext
struct|struct
name|QWindowCreationContext
block|{
name|QWindowCreationContext
argument_list|(
argument|const QWindow *w
argument_list|,
argument|const QRect&r
argument_list|,
argument|DWORD style
argument_list|,
argument|DWORD exStyle
argument_list|)
empty_stmt|;
DECL|function|applyToMinMaxInfo
name|void
name|applyToMinMaxInfo
argument_list|(
name|MINMAXINFO
operator|*
name|mmi
argument_list|)
decl|const
block|{
name|geometryHint
operator|.
name|applyToMinMaxInfo
argument_list|(
name|style
argument_list|,
name|exStyle
argument_list|,
name|mmi
argument_list|)
expr_stmt|;
block|}
DECL|member|geometryHint
name|QWindowsGeometryHint
name|geometryHint
decl_stmt|;
DECL|member|style
name|DWORD
name|style
decl_stmt|;
DECL|member|exStyle
name|DWORD
name|exStyle
decl_stmt|;
DECL|member|requestedGeometry
name|QRect
name|requestedGeometry
decl_stmt|;
DECL|member|obtainedGeometry
name|QRect
name|obtainedGeometry
decl_stmt|;
DECL|member|margins
name|QMargins
name|margins
decl_stmt|;
DECL|member|frameX
name|int
name|frameX
decl_stmt|;
comment|// Passed on to CreateWindowEx(), including frame.
DECL|member|frameY
name|int
name|frameY
decl_stmt|;
DECL|member|frameWidth
name|int
name|frameWidth
decl_stmt|;
DECL|member|frameHeight
name|int
name|frameHeight
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QWindowsWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
expr|enum
name|Flags
block|{
name|WithinWmPaint
operator|=
literal|0x1
block|,
name|WithinSetParent
operator|=
literal|0x2
block|,
name|FrameDirty
operator|=
literal|0x4
block|,
comment|//! Frame outdated by setStyle, recalculate in next query.
name|OpenGLSurface
operator|=
literal|0x10
block|,
name|OpenGLDoubleBuffered
operator|=
literal|0x20
block|,
name|OpenGlPixelFormatInitialized
operator|=
literal|0x40
block|}
block|;      struct
name|WindowData
block|{
name|WindowData
argument_list|()
operator|:
name|hwnd
argument_list|(
literal|0
argument_list|)
block|{}
name|Qt
operator|::
name|WindowFlags
name|flags
block|;
name|QRect
name|geometry
block|;
name|QMargins
name|frame
block|;
comment|// Do not use directly for windows, see FrameDirty.
name|HWND
name|hwnd
block|;
specifier|static
name|WindowData
name|create
argument_list|(
specifier|const
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|WindowData
operator|&
name|parameters
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;     }
block|;
name|QWindowsWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|WindowData
operator|&
name|data
argument_list|)
block|;
operator|~
name|QWindowsWindow
argument_list|()
block|;
name|virtual
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|virtual
name|QRect
name|geometry
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|geometry
return|;
block|}
name|virtual
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|bool
name|isVisible
argument_list|()
specifier|const
block|;
name|virtual
name|Qt
operator|::
name|WindowFlags
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|WindowState
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|HWND
name|handle
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|.
name|hwnd
return|;
block|}
name|virtual
name|WId
name|winId
argument_list|()
specifier|const
block|{
return|return
name|WId
argument_list|(
name|m_data
operator|.
name|hwnd
argument_list|)
return|;
block|}
name|virtual
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
block|;
name|virtual
name|void
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|virtual
name|void
name|raise
argument_list|()
block|;
name|virtual
name|void
name|lower
argument_list|()
block|;
name|virtual
name|void
name|propagateSizeHints
argument_list|()
block|;
name|virtual
name|QMargins
name|frameMargins
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
block|;
name|virtual
name|void
name|requestActivateWindow
argument_list|()
block|;
name|virtual
name|bool
name|setKeyboardGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|virtual
name|bool
name|setMouseGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|Qt
operator|::
name|WindowState
name|windowState_sys
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|WindowStates
name|windowStates_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|unsigned
name|style
argument_list|()
specifier|const
block|{
return|return
name|GetWindowLongPtr
argument_list|(
name|m_data
operator|.
name|hwnd
argument_list|,
name|GWL_STYLE
argument_list|)
return|;
block|}
name|void
name|setStyle
argument_list|(
argument|unsigned s
argument_list|)
specifier|const
block|;
specifier|inline
name|unsigned
name|exStyle
argument_list|()
specifier|const
block|{
return|return
name|GetWindowLongPtr
argument_list|(
name|m_data
operator|.
name|hwnd
argument_list|,
name|GWL_EXSTYLE
argument_list|)
return|;
block|}
name|void
name|setExStyle
argument_list|(
argument|unsigned s
argument_list|)
specifier|const
block|;
name|bool
name|handleWmPaint
argument_list|(
argument|HWND hwnd
argument_list|,
argument|UINT message
argument_list|,
argument|WPARAM wParam
argument_list|,
argument|LPARAM lParam
argument_list|)
block|;
name|void
name|handleMoved
argument_list|()
block|;
name|void
name|handleResized
argument_list|(
argument|int wParam
argument_list|)
block|;
name|void
name|handleShown
argument_list|()
block|;
name|void
name|handleHidden
argument_list|()
block|;
specifier|static
specifier|inline
name|HWND
name|handleOf
argument_list|(
specifier|const
name|QWindow
operator|*
name|w
argument_list|)
block|;
specifier|static
specifier|inline
name|QWindowsWindow
operator|*
name|baseWindowOf
argument_list|(
specifier|const
name|QWindow
operator|*
name|w
argument_list|)
block|;
specifier|static
name|QWindow
operator|*
name|topLevelOf
argument_list|(
name|QWindow
operator|*
name|w
argument_list|)
block|;
specifier|static
specifier|inline
name|void
operator|*
name|userDataOf
argument_list|(
argument|HWND hwnd
argument_list|)
block|;
specifier|static
specifier|inline
name|void
name|setUserDataOf
argument_list|(
argument|HWND hwnd
argument_list|,
argument|void *ud
argument_list|)
block|;
name|HDC
name|getDC
argument_list|()
block|;
name|void
name|releaseDC
argument_list|()
block|;
name|void
name|getSizeHints
argument_list|(
argument|MINMAXINFO *mmi
argument_list|)
specifier|const
block|;
name|QWindowsWindowCursor
name|cursor
argument_list|()
specifier|const
block|{
return|return
name|m_cursor
return|;
block|}
name|void
name|setCursor
argument_list|(
specifier|const
name|QWindowsWindowCursor
operator|&
name|c
argument_list|)
block|;
name|void
name|applyCursor
argument_list|()
block|;
name|QWindowsWindow
operator|*
name|childAt
argument_list|(
argument|const QPoint&clientPoint
argument_list|,
argument|unsigned cwexflags = CWP_SKIPINVISIBLE
argument_list|)
specifier|const
block|;
name|QWindowsWindow
operator|*
name|childAtScreenPoint
argument_list|(
argument|const QPoint&screenPoint
argument_list|,
argument|unsigned cwexflags = CWP_SKIPINVISIBLE
argument_list|)
specifier|const
block|;
specifier|static
name|QByteArray
name|debugWindowFlags
argument_list|(
argument|Qt::WindowFlags wf
argument_list|)
block|;
specifier|inline
name|bool
name|testFlag
argument_list|(
argument|unsigned f
argument_list|)
specifier|const
block|{
return|return
operator|(
name|m_flags
operator|&
name|f
operator|)
operator|!=
literal|0
return|;
block|}
specifier|inline
name|void
name|setFlag
argument_list|(
argument|unsigned f
argument_list|)
specifier|const
block|{
name|m_flags
operator||=
name|f
block|; }
specifier|inline
name|void
name|clearFlag
argument_list|(
argument|unsigned f
argument_list|)
specifier|const
block|{
name|m_flags
operator|&=
operator|~
name|f
block|; }
name|private
operator|:
specifier|inline
name|void
name|show_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|hide_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|setGeometry_sys
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
specifier|inline
name|QRect
name|frameGeometry_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|QRect
name|geometry_sys
argument_list|()
specifier|const
block|;
specifier|inline
name|WindowData
name|setWindowFlags_sys
argument_list|(
argument|Qt::WindowFlags wt
argument_list|,
argument|unsigned flags =
literal|0
argument_list|)
specifier|const
block|;
specifier|inline
name|void
name|setWindowState_sys
argument_list|(
argument|Qt::WindowState newState
argument_list|)
block|;
specifier|inline
name|void
name|setParent_sys
argument_list|(
argument|const QPlatformWindow *parent
argument_list|)
specifier|const
block|;
specifier|inline
name|void
name|setOpacity_sys
argument_list|(
argument|qreal level
argument_list|)
specifier|const
block|;
specifier|inline
name|void
name|setMouseGrabEnabled_sys
argument_list|(
argument|bool grab
argument_list|)
block|;
name|void
name|destroyWindow
argument_list|()
block|;
name|void
name|registerDropSite
argument_list|()
block|;
name|void
name|unregisterDropSite
argument_list|()
block|;
name|void
name|handleGeometryChange
argument_list|()
block|;
name|void
name|handleWindowStateChange
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|mutable
name|WindowData
name|m_data
block|;
name|mutable
name|unsigned
name|m_flags
block|;
name|HDC
name|m_hdc
block|;
name|Qt
operator|::
name|WindowState
name|m_windowState
block|;
name|qreal
name|m_opacity
block|;
name|bool
name|m_mouseGrab
block|;
name|QWindowsWindowCursor
name|m_cursor
block|;
name|QWindowsOleDropTarget
operator|*
name|m_dropTarget
block|;
name|unsigned
name|m_savedStyle
block|;
name|QRect
name|m_savedFrameGeometry
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Conveniences for window frames.
end_comment
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QRect
name|operator
operator|+
operator|(
specifier|const
name|QRect
operator|&
name|r
operator|,
specifier|const
name|QMargins
operator|&
name|m
operator|)
block|{
return|return
name|r
operator|.
name|adjusted
argument_list|(
operator|-
name|m
operator|.
name|left
argument_list|()
argument_list|,
operator|-
name|m
operator|.
name|top
argument_list|()
argument_list|,
name|m
operator|.
name|right
argument_list|()
argument_list|,
name|m
operator|.
name|bottom
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QRect
name|operator
operator|-
operator|(
specifier|const
name|QRect
operator|&
name|r
operator|,
specifier|const
name|QMargins
operator|&
name|m
operator|)
block|{
return|return
name|r
operator|.
name|adjusted
argument_list|(
name|m
operator|.
name|left
argument_list|()
argument_list|,
name|m
operator|.
name|top
argument_list|()
argument_list|,
operator|-
name|m
operator|.
name|right
argument_list|()
argument_list|,
operator|-
name|m
operator|.
name|bottom
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Debug
end_comment
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|RECT
operator|&
name|r
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|MINMAXINFO
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|NCCALCSIZE_PARAMS
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ---------- QWindowsGeometryHint inline functions.
end_comment
begin_expr_stmt
DECL|function|mapToGlobal
name|QPoint
name|QWindowsGeometryHint
operator|::
name|mapToGlobal
argument_list|(
argument|HWND hwnd
argument_list|,
argument|const QPoint&qp
argument_list|)
block|{
name|POINT
name|p
operator|=
block|{
name|qp
operator|.
name|x
argument_list|()
block|,
name|qp
operator|.
name|y
argument_list|()
block|}
block|;
name|ClientToScreen
argument_list|(
name|hwnd
argument_list|,
operator|&
name|p
argument_list|)
block|;
return|return
name|QPoint
argument_list|(
name|p
operator|.
name|x
argument_list|,
name|p
operator|.
name|y
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapFromGlobal
name|QPoint
name|QWindowsGeometryHint
operator|::
name|mapFromGlobal
argument_list|(
argument|const HWND hwnd
argument_list|,
argument|const QPoint&qp
argument_list|)
block|{
name|POINT
name|p
operator|=
block|{
name|qp
operator|.
name|x
argument_list|()
block|,
name|qp
operator|.
name|y
argument_list|()
block|}
block|;
name|ScreenToClient
argument_list|(
name|hwnd
argument_list|,
operator|&
name|p
argument_list|)
block|;
return|return
name|QPoint
argument_list|(
name|p
operator|.
name|x
argument_list|,
name|p
operator|.
name|y
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapToGlobal
name|QPoint
name|QWindowsGeometryHint
operator|::
name|mapToGlobal
argument_list|(
argument|const QWindow *w
argument_list|,
argument|const QPoint&p
argument_list|)
block|{
return|return
name|QWindowsGeometryHint
operator|::
name|mapToGlobal
argument_list|(
name|QWindowsWindow
operator|::
name|handleOf
argument_list|(
name|w
argument_list|)
argument_list|,
name|p
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|mapFromGlobal
name|QPoint
name|QWindowsGeometryHint
operator|::
name|mapFromGlobal
argument_list|(
argument|const QWindow *w
argument_list|,
argument|const QPoint&p
argument_list|)
block|{
return|return
name|QWindowsGeometryHint
operator|::
name|mapFromGlobal
argument_list|(
name|QWindowsWindow
operator|::
name|handleOf
argument_list|(
name|w
argument_list|)
argument_list|,
name|p
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// ---------- QWindowsBaseWindow inline functions.
end_comment
begin_expr_stmt
DECL|function|baseWindowOf
name|QWindowsWindow
operator|*
name|QWindowsWindow
operator|::
name|baseWindowOf
argument_list|(
argument|const QWindow *w
argument_list|)
block|{
if|if
condition|(
name|w
condition|)
if|if
condition|(
name|QPlatformWindow
modifier|*
name|pw
init|=
name|w
operator|->
name|handle
argument_list|()
condition|)
return|return
name|static_cast
operator|<
name|QWindowsWindow
operator|*
operator|>
operator|(
name|pw
operator|)
return|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_expr_stmt
unit|}  HWND
DECL|function|handleOf
name|QWindowsWindow
operator|::
name|handleOf
argument_list|(
argument|const QWindow *w
argument_list|)
block|{
if|if
condition|(
specifier|const
name|QWindowsWindow
modifier|*
name|bw
init|=
name|QWindowsWindow
operator|::
name|baseWindowOf
argument_list|(
name|w
argument_list|)
condition|)
return|return
name|bw
operator|->
name|handle
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_expr_stmt
unit|}  void
DECL|function|userDataOf
operator|*
name|QWindowsWindow
operator|::
name|userDataOf
argument_list|(
argument|HWND hwnd
argument_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|GetWindowLongPtr
argument_list|(
name|hwnd
argument_list|,
name|GWLP_USERDATA
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setUserDataOf
name|void
name|QWindowsWindow
operator|::
name|setUserDataOf
argument_list|(
argument|HWND hwnd
argument_list|,
argument|void *ud
argument_list|)
block|{
name|SetWindowLongPtr
argument_list|(
name|hwnd
argument_list|,
name|GWLP_USERDATA
argument_list|,
name|LONG_PTR
argument_list|(
name|ud
argument_list|)
argument_list|)
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSWINDOW_H
end_comment
end_unit
