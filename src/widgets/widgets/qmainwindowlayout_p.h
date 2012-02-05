begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDYNAMICMAINWINDOWLAYOUT_P_H
end_ifndef
begin_define
DECL|macro|QDYNAMICMAINWINDOWLAYOUT_P_H
define|#
directive|define
name|QDYNAMICMAINWINDOWLAYOUT_P_H
end_define
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
file|"qmainwindow.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MAINWINDOW
end_ifndef
begin_include
include|#
directive|include
file|"QtWidgets/qlayout.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qtabbar.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qset.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qlayoutengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidgetanimator_p.h"
end_include
begin_include
include|#
directive|include
file|"qdockarealayout_p.h"
end_include
begin_include
include|#
directive|include
file|"qtoolbararealayout_p.h"
end_include
begin_comment
comment|//#define Q_DEBUG_MAINWINDOW_LAYOUT
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_DEBUG_MAINWINDOW_LAYOUT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_DOCKWIDGET
argument_list|)
end_if
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qt_dumpLayout
parameter_list|(
name|QTextStream
modifier|&
name|qout
parameter_list|,
name|QMainWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_DEBUG_MAINWINDOW_LAYOUT&& !QT_NO_DOCKWIDGET
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_comment
comment|// Forward defs to make avoid including Carbon.h (faster compile you know ;).
end_comment
begin_struct_decl
struct_decl|struct
name|OpaqueHIObjectRef
struct_decl|;
end_struct_decl
begin_typedef
DECL|typedef|HIObjectRef
typedef|typedef
name|struct
name|OpaqueHIObjectRef
modifier|*
name|HIObjectRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|HIToolbarItemRef
typedef|typedef
name|HIObjectRef
name|HIToolbarItemRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|CFTypeRef
typedef|typedef
specifier|const
name|void
modifier|*
name|CFTypeRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|CFStringRef
typedef|typedef
specifier|const
name|struct
name|__CFString
modifier|*
name|CFStringRef
typedef|;
end_typedef
begin_include
include|#
directive|include
file|<private/qunifiedtoolbarsurface_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_MAC
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QToolBar
name|class
name|QToolBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRubberBand
name|class
name|QRubberBand
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* This data structure represents the state of all the tool-bars and dock-widgets. It's value based    so it can be easilly copied into a temporary variable. All operations are performed without moving    any widgets. Only when we are sure we have the desired state, we call apply(), which moves the    widgets. */
end_comment
begin_decl_stmt
name|class
name|QMainWindowLayoutState
block|{
name|public
label|:
name|QRect
name|rect
decl_stmt|;
name|QMainWindow
modifier|*
name|mainWindow
decl_stmt|;
name|QMainWindowLayoutState
argument_list|(
name|QMainWindow
operator|*
name|win
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
name|QToolBarAreaLayout
name|toolBarAreaLayout
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
name|QDockAreaLayout
name|dockAreaLayout
decl_stmt|;
else|#
directive|else
name|QLayoutItem
modifier|*
name|centralWidgetItem
decl_stmt|;
name|QRect
name|centralWidgetRect
decl_stmt|;
endif|#
directive|endif
name|void
name|apply
parameter_list|(
name|bool
name|animated
parameter_list|)
function_decl|;
name|void
name|deleteAllLayoutItems
parameter_list|()
function_decl|;
name|void
name|deleteCentralWidgetItem
parameter_list|()
function_decl|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|fitLayout
parameter_list|()
function_decl|;
name|QLayoutItem
modifier|*
name|itemAt
argument_list|(
name|int
name|index
argument_list|,
name|int
operator|*
name|x
argument_list|)
decl|const
decl_stmt|;
name|QLayoutItem
modifier|*
name|takeAt
parameter_list|(
name|int
name|index
parameter_list|,
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
name|QList
operator|<
name|int
operator|>
name|indexOf
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
expr_stmt|;
name|QLayoutItem
modifier|*
name|item
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl_stmt|;
name|QRect
name|itemRect
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|gapRect
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
comment|// ### get rid of this, use itemRect() instead
name|bool
name|contains
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
decl|const
decl_stmt|;
name|void
name|setCentralWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
name|QWidget
operator|*
name|centralWidget
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|gapIndex
argument_list|(
argument|QWidget *widget
argument_list|,
argument|const QPoint&pos
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|insertGap
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|,
name|QLayoutItem
operator|*
name|item
argument_list|)
decl_stmt|;
name|void
name|remove
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl_stmt|;
name|void
name|remove
parameter_list|(
name|QLayoutItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QLayoutItem
modifier|*
name|plug
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl_stmt|;
name|QLayoutItem
modifier|*
name|unplug
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|,
name|QMainWindowLayoutState
operator|*
name|savedState
operator|=
literal|0
argument_list|)
decl_stmt|;
name|void
name|saveState
argument_list|(
name|QDataStream
operator|&
name|stream
argument_list|)
decl|const
decl_stmt|;
name|bool
name|checkFormat
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|bool
name|pre43
parameter_list|)
function_decl|;
name|bool
name|restoreState
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
specifier|const
name|QMainWindowLayoutState
modifier|&
name|oldState
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QMainWindowLayout
range|:
name|public
name|QLayout
block|{
name|Q_OBJECT
name|public
operator|:
name|QMainWindowLayoutState
name|layoutState
block|,
name|savedState
block|;
name|QMainWindowLayout
argument_list|(
name|QMainWindow
operator|*
name|mainwindow
argument_list|,
name|QLayout
operator|*
name|parentLayout
argument_list|)
block|;
operator|~
name|QMainWindowLayout
argument_list|()
block|;
name|QMainWindow
operator|::
name|DockOptions
name|dockOptions
block|;
name|void
name|setDockOptions
argument_list|(
argument|QMainWindow::DockOptions opts
argument_list|)
block|;
name|bool
name|usesHIToolBar
argument_list|(
argument|QToolBar *toolbar
argument_list|)
specifier|const
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|e
argument_list|)
block|;
comment|// status bar
name|QLayoutItem
operator|*
name|statusbar
block|;
ifndef|#
directive|ifndef
name|QT_NO_STATUSBAR
name|QStatusBar
operator|*
name|statusBar
argument_list|()
specifier|const
block|;
name|void
name|setStatusBar
argument_list|(
name|QStatusBar
operator|*
name|sb
argument_list|)
block|;
endif|#
directive|endif
comment|// central widget
name|QWidget
operator|*
name|centralWidget
argument_list|()
specifier|const
block|;
name|void
name|setCentralWidget
argument_list|(
name|QWidget
operator|*
name|cw
argument_list|)
block|;
comment|// toolbars
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
name|void
name|addToolBarBreak
argument_list|(
argument|Qt::ToolBarArea area
argument_list|)
block|;
name|void
name|insertToolBarBreak
argument_list|(
name|QToolBar
operator|*
name|before
argument_list|)
block|;
name|void
name|removeToolBarBreak
argument_list|(
name|QToolBar
operator|*
name|before
argument_list|)
block|;
name|void
name|addToolBar
argument_list|(
argument|Qt::ToolBarArea area
argument_list|,
argument|QToolBar *toolbar
argument_list|,
argument|bool needAddChildWidget = true
argument_list|)
block|;
name|void
name|insertToolBar
argument_list|(
name|QToolBar
operator|*
name|before
argument_list|,
name|QToolBar
operator|*
name|toolbar
argument_list|)
block|;
name|Qt
operator|::
name|ToolBarArea
name|toolBarArea
argument_list|(
argument|QToolBar *toolbar
argument_list|)
specifier|const
block|;
name|bool
name|toolBarBreak
argument_list|(
argument|QToolBar *toolBar
argument_list|)
specifier|const
block|;
name|void
name|getStyleOptionInfo
argument_list|(
argument|QStyleOptionToolBar *option
argument_list|,
argument|QToolBar *toolBar
argument_list|)
specifier|const
block|;
name|void
name|removeToolBar
argument_list|(
name|QToolBar
operator|*
name|toolbar
argument_list|)
block|;
name|void
name|toggleToolBarsVisible
argument_list|()
block|;
name|void
name|moveToolBar
argument_list|(
argument|QToolBar *toolbar
argument_list|,
argument|int pos
argument_list|)
block|;
endif|#
directive|endif
comment|// dock widgets
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
name|void
name|setCorner
argument_list|(
argument|Qt::Corner corner
argument_list|,
argument|Qt::DockWidgetArea area
argument_list|)
block|;
name|Qt
operator|::
name|DockWidgetArea
name|corner
argument_list|(
argument|Qt::Corner corner
argument_list|)
specifier|const
block|;
name|void
name|addDockWidget
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|,
argument|QDockWidget *dockwidget
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|splitDockWidget
argument_list|(
argument|QDockWidget *after
argument_list|,
argument|QDockWidget *dockwidget
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|tabifyDockWidget
argument_list|(
name|QDockWidget
operator|*
name|first
argument_list|,
name|QDockWidget
operator|*
name|second
argument_list|)
block|;
name|Qt
operator|::
name|DockWidgetArea
name|dockWidgetArea
argument_list|(
argument|QDockWidget *dockwidget
argument_list|)
specifier|const
block|;
name|void
name|raise
argument_list|(
name|QDockWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|setVerticalTabsEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|restoreDockWidget
argument_list|(
name|QDockWidget
operator|*
name|dockwidget
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|bool
name|_documentMode
block|;
name|bool
name|documentMode
argument_list|()
specifier|const
block|;
name|void
name|setDocumentMode
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|QTabBar
operator|*
name|getTabBar
argument_list|()
block|;
name|QSet
operator|<
name|QTabBar
operator|*
operator|>
name|usedTabBars
block|;
name|QList
operator|<
name|QTabBar
operator|*
operator|>
name|unusedTabBars
block|;
name|bool
name|verticalTabsEnabled
block|;
name|QWidget
operator|*
name|getSeparatorWidget
argument_list|()
block|;
name|QSet
operator|<
name|QWidget
operator|*
operator|>
name|usedSeparatorWidgets
block|;
name|QList
operator|<
name|QWidget
operator|*
operator|>
name|unusedSeparatorWidgets
block|;
name|int
name|sep
block|;
comment|// separator extent
ifndef|#
directive|ifndef
name|QT_NO_TABWIDGET
name|QTabWidget
operator|::
name|TabPosition
name|tabPositions
index|[
literal|4
index|]
block|;
name|QTabWidget
operator|::
name|TabShape
name|_tabShape
block|;
name|QTabWidget
operator|::
name|TabShape
name|tabShape
argument_list|()
specifier|const
block|;
name|void
name|setTabShape
argument_list|(
argument|QTabWidget::TabShape tabShape
argument_list|)
block|;
name|QTabWidget
operator|::
name|TabPosition
name|tabPosition
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|)
specifier|const
block|;
name|void
name|setTabPosition
argument_list|(
argument|Qt::DockWidgetAreas areas
argument_list|,
argument|QTabWidget::TabPosition tabPosition
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_TABWIDGET
endif|#
directive|endif
comment|// QT_NO_TABBAR
comment|// separators
name|QList
operator|<
name|int
operator|>
name|movingSeparator
block|;
name|QPoint
name|movingSeparatorOrigin
block|,
name|movingSeparatorPos
block|;
name|QBasicTimer
name|separatorMoveTimer
block|;
name|bool
name|startSeparatorMove
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|bool
name|separatorMove
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|bool
name|endSeparatorMove
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|void
name|keepSize
argument_list|(
name|QDockWidget
operator|*
name|w
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_DOCKWIDGET
comment|// save/restore
block|enum
block|{
comment|// sentinel values used to validate state data
name|VersionMarker
operator|=
literal|0xff
block|}
block|;
name|void
name|saveState
argument_list|(
argument|QDataStream&stream
argument_list|)
specifier|const
block|;
name|bool
name|restoreState
argument_list|(
name|QDataStream
operator|&
name|stream
argument_list|)
block|;
comment|// QLayout interface
name|void
name|addItem
argument_list|(
name|QLayoutItem
operator|*
name|item
argument_list|)
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
block|;
name|QLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QLayoutItem
operator|*
name|takeAt
argument_list|(
argument|int index
argument_list|)
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
block|;
name|mutable
name|QSize
name|szHint
block|;
name|mutable
name|QSize
name|minSize
block|;
name|void
name|invalidate
argument_list|()
block|;
comment|// animations
name|QWidgetAnimator
name|widgetAnimator
block|;
name|QList
operator|<
name|int
operator|>
name|currentGapPos
block|;
name|QRect
name|currentGapRect
block|;
name|QWidget
operator|*
name|pluggingWidget
block|;
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
name|QRubberBand
operator|*
name|gapIndicator
block|;
endif|#
directive|endif
name|QList
operator|<
name|int
operator|>
name|hover
argument_list|(
name|QLayoutItem
operator|*
name|widgetItem
argument_list|,
specifier|const
name|QPoint
operator|&
name|mousePos
argument_list|)
block|;
name|bool
name|plug
argument_list|(
name|QLayoutItem
operator|*
name|widgetItem
argument_list|)
block|;
name|QLayoutItem
operator|*
name|unplug
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|revert
argument_list|(
name|QLayoutItem
operator|*
name|widgetItem
argument_list|)
block|;
name|void
name|updateGapIndicator
argument_list|()
block|;
name|void
name|paintDropIndicator
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QRegion
operator|&
name|clip
argument_list|)
block|;
name|void
name|applyState
argument_list|(
argument|QMainWindowLayoutState&newState
argument_list|,
argument|bool animate = true
argument_list|)
block|;
name|void
name|restore
argument_list|(
argument|bool keepSavedState = false
argument_list|)
block|;
name|void
name|updateHIToolBarStatus
argument_list|()
block|;
name|void
name|animationFinished
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|void
name|tabChanged
argument_list|()
block|;
endif|#
directive|endif
endif|#
directive|endif
name|private
operator|:
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|void
name|updateTabBarShapes
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_MAC
specifier|static
name|OSStatus
name|qtmacToolbarDelegate
argument_list|(
name|EventHandlerCallRef
argument_list|,
name|EventRef
argument_list|,
name|void
operator|*
argument_list|)
block|;
specifier|static
name|OSStatus
name|qtoolbarInHIToolbarHandler
argument_list|(
argument|EventHandlerCallRef inCallRef
argument_list|,
argument|EventRef event
argument_list|,
argument|void *data
argument_list|)
block|;
specifier|static
name|void
name|qtMacHIToolbarRegisterQToolBarInHIToolborItemClass
argument_list|()
block|;
specifier|static
name|HIToolbarItemRef
name|CreateToolbarItemForIdentifier
argument_list|(
argument|CFStringRef identifier
argument_list|,
argument|CFTypeRef data
argument_list|)
block|;
specifier|static
name|HIToolbarItemRef
name|createQToolBarInHIToolbarItem
argument_list|(
name|QToolBar
operator|*
name|toolbar
argument_list|,
name|QMainWindowLayout
operator|*
name|layout
argument_list|)
block|;
name|public
operator|:
expr|struct
name|ToolBarSaveState
block|{
name|ToolBarSaveState
argument_list|()
operator|:
name|movable
argument_list|(
argument|false
argument_list|)
block|{ }
name|ToolBarSaveState
argument_list|(
argument|bool newMovable
argument_list|,
argument|const QSize&newMax
argument_list|)
operator|:
name|movable
argument_list|(
name|newMovable
argument_list|)
block|,
name|maximumSize
argument_list|(
argument|newMax
argument_list|)
block|{ }
name|bool
name|movable
block|;
name|QSize
name|maximumSize
block|;     }
block|;
name|QList
operator|<
name|QToolBar
operator|*
operator|>
name|qtoolbarsInUnifiedToolbarList
block|;
name|QList
operator|<
name|void
operator|*
operator|>
name|toolbarItemsCopy
block|;
name|QHash
operator|<
name|void
operator|*
block|,
name|QToolBar
operator|*
operator|>
name|unifiedToolbarHash
block|;
name|QHash
operator|<
name|QToolBar
operator|*
block|,
name|ToolBarSaveState
operator|>
name|toolbarSaveState
block|;
name|QHash
operator|<
name|QString
block|,
name|QToolBar
operator|*
operator|>
name|cocoaItemIDToToolbarHash
block|;
name|void
name|insertIntoMacToolbar
argument_list|(
name|QToolBar
operator|*
name|before
argument_list|,
name|QToolBar
operator|*
name|after
argument_list|)
block|;
name|void
name|removeFromMacToolbar
argument_list|(
name|QToolBar
operator|*
name|toolbar
argument_list|)
block|;
name|void
name|cleanUpMacToolbarItems
argument_list|()
block|;
name|void
name|fixSizeInUnifiedToolbar
argument_list|(
argument|QToolBar *tb
argument_list|)
specifier|const
block|;
name|bool
name|useHIToolBar
block|;
name|bool
name|activateUnifiedToolbarAfterFullScreen
block|;
name|void
name|syncUnifiedToolbarVisibility
argument_list|()
block|;
name|bool
name|blockVisiblityCheck
block|;
name|QUnifiedToolbarSurface
operator|*
name|unifiedSurface
block|;
name|void
name|updateUnifiedToolbarOffset
argument_list|()
block|;
endif|#
directive|endif
comment|// Q_WS_MAC
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MAINWINDOW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDYNAMICMAINWINDOWLAYOUT_P_H
end_comment
end_unit
