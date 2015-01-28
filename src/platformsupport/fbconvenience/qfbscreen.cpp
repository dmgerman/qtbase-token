begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfbscreen_p.h"
end_include
begin_include
include|#
directive|include
file|"qfbcursor_p.h"
end_include
begin_include
include|#
directive|include
file|"qfbwindow_p.h"
end_include
begin_include
include|#
directive|include
file|"qfbbackingstore_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QElapsedTimer>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QFbScreen
name|QFbScreen
operator|::
name|QFbScreen
parameter_list|()
member_init_list|:
name|mUpdatePending
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mCursor
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mGeometry
argument_list|()
member_init_list|,
name|mDepth
argument_list|(
literal|16
argument_list|)
member_init_list|,
name|mFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB16
argument_list|)
member_init_list|,
name|mScreenImage
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mCompositePainter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mIsUpToDate
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QFbScreen
name|QFbScreen
operator|::
name|~
name|QFbScreen
parameter_list|()
block|{
operator|delete
name|mCompositePainter
expr_stmt|;
operator|delete
name|mScreenImage
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initializeCompositor
name|void
name|QFbScreen
operator|::
name|initializeCompositor
parameter_list|()
block|{
name|mScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|mGeometry
operator|.
name|size
argument_list|()
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
name|scheduleUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QFbScreen
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|UpdateRequest
condition|)
block|{
name|doRedraw
argument_list|()
expr_stmt|;
name|mUpdatePending
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|QObject
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QFbScreen
operator|::
name|addWindow
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
block|{
name|mWindowStack
operator|.
name|prepend
argument_list|(
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mBackingStores
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|//check if we have a backing store for this window
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mBackingStores
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QFbBackingStore
modifier|*
name|bs
init|=
name|mBackingStores
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
comment|// this gets called during QWindow::create() at a point where the
comment|// invariant (window->handle()->window() == window) is broken
if|if
condition|(
name|bs
operator|->
name|window
argument_list|()
operator|==
name|window
operator|->
name|window
argument_list|()
condition|)
block|{
name|window
operator|->
name|setBackingStore
argument_list|(
name|bs
argument_list|)
expr_stmt|;
name|mBackingStores
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|w
init|=
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|topWindowChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QFbScreen
operator|::
name|removeWindow
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
block|{
name|mWindowStack
operator|.
name|removeOne
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|w
init|=
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|topWindowChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QFbScreen
operator|::
name|raise
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
block|{
name|int
name|index
init|=
name|mWindowStack
operator|.
name|indexOf
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|<=
literal|0
condition|)
return|return;
name|mWindowStack
operator|.
name|move
argument_list|(
name|index
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|w
init|=
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|topWindowChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lower
name|void
name|QFbScreen
operator|::
name|lower
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
block|{
name|int
name|index
init|=
name|mWindowStack
operator|.
name|indexOf
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
operator|||
name|index
operator|==
operator|(
name|mWindowStack
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|)
condition|)
return|return;
name|mWindowStack
operator|.
name|move
argument_list|(
name|index
argument_list|,
name|mWindowStack
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|w
init|=
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|topWindowChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|topWindow
name|QWindow
modifier|*
name|QFbScreen
operator|::
name|topWindow
parameter_list|()
specifier|const
block|{
foreach|foreach
control|(
name|QFbWindow
modifier|*
name|fbw
decl|,
name|mWindowStack
control|)
if|if
condition|(
name|fbw
operator|->
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Window
operator|||
name|fbw
operator|->
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Dialog
condition|)
return|return
name|fbw
operator|->
name|window
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|topLevelAt
name|QWindow
modifier|*
name|QFbScreen
operator|::
name|topLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
specifier|const
block|{
foreach|foreach
control|(
name|QFbWindow
modifier|*
name|fbw
decl|,
name|mWindowStack
control|)
block|{
if|if
condition|(
name|fbw
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|p
argument_list|,
literal|false
argument_list|)
operator|&&
name|fbw
operator|->
name|window
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
return|return
name|fbw
operator|->
name|window
argument_list|()
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|setDirty
name|void
name|QFbScreen
operator|::
name|setDirty
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QRect
name|intersection
init|=
name|rect
operator|.
name|intersected
argument_list|(
name|mGeometry
argument_list|)
decl_stmt|;
name|QPoint
name|screenOffset
init|=
name|mGeometry
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|mRepaintRegion
operator|+=
name|intersection
operator|.
name|translated
argument_list|(
operator|-
name|screenOffset
argument_list|)
expr_stmt|;
comment|// global to local translation
name|scheduleUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scheduleUpdate
name|void
name|QFbScreen
operator|::
name|scheduleUpdate
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mUpdatePending
condition|)
block|{
name|mUpdatePending
operator|=
literal|true
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|UpdateRequest
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setPhysicalSize
name|void
name|QFbScreen
operator|::
name|setPhysicalSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|mPhysicalSize
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QFbScreen
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
operator|delete
name|mCompositePainter
expr_stmt|;
name|mCompositePainter
operator|=
literal|0
expr_stmt|;
operator|delete
name|mScreenImage
expr_stmt|;
name|mGeometry
operator|=
name|rect
expr_stmt|;
name|mScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|mGeometry
operator|.
name|size
argument_list|()
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenGeometryChange
argument_list|(
name|QPlatformScreen
operator|::
name|screen
argument_list|()
argument_list|,
name|geometry
argument_list|()
argument_list|,
name|availableGeometry
argument_list|()
argument_list|)
expr_stmt|;
name|resizeMaximizedWindows
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|generateRects
name|void
name|QFbScreen
operator|::
name|generateRects
parameter_list|()
block|{
name|mCachedRects
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QPoint
name|screenOffset
init|=
name|mGeometry
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|QRegion
name|remainingScreen
argument_list|(
name|mGeometry
operator|.
name|translated
argument_list|(
operator|-
name|screenOffset
argument_list|)
argument_list|)
decl_stmt|;
comment|// global to local translation
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mWindowStack
operator|.
name|length
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|remainingScreen
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
if|#
directive|if
literal|0
block|if (!mWindowStack[i]->isVisible())             continue;         if (mWindowStack[i]->isMinimized())             continue;          if (!mWindowStack[i]->testAttribute(Qt::WA_TranslucentBackground)) {             QRect localGeometry = mWindowStack.at(i)->geometry().translated(-screenOffset);
comment|// global to local translation
block|remainingScreen -= localGeometry;             QRegion windowRegion(localGeometry);             windowRegion -= remainingScreen;             foreach (const QRect&rect, windowRegion.rects()) {                 mCachedRects += QPair<QRect, int>(rect, i);             }         }
endif|#
directive|endif
block|}
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|remainingScreen
operator|.
name|rects
argument_list|()
control|)
name|mCachedRects
operator|+=
name|QPair
argument_list|<
name|QRect
argument_list|,
name|int
argument_list|>
argument_list|(
name|rect
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|mIsUpToDate
operator|=
literal|true
expr_stmt|;
return|return;
block|}
end_function
begin_function
DECL|function|doRedraw
name|QRegion
name|QFbScreen
operator|::
name|doRedraw
parameter_list|()
block|{
name|QPoint
name|screenOffset
init|=
name|mGeometry
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|QRegion
name|touchedRegion
decl_stmt|;
if|if
condition|(
name|mCursor
operator|&&
name|mCursor
operator|->
name|isDirty
argument_list|()
operator|&&
name|mCursor
operator|->
name|isOnScreen
argument_list|()
condition|)
block|{
name|QRect
name|lastCursor
init|=
name|mCursor
operator|->
name|dirtyRect
argument_list|()
decl_stmt|;
name|mRepaintRegion
operator|+=
name|lastCursor
expr_stmt|;
block|}
if|if
condition|(
name|mRepaintRegion
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
operator|!
name|mCursor
operator|||
operator|!
name|mCursor
operator|->
name|isDirty
argument_list|()
operator|)
condition|)
block|{
return|return
name|touchedRegion
return|;
block|}
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|mRepaintRegion
operator|.
name|rects
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|mIsUpToDate
condition|)
name|generateRects
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|mCompositePainter
condition|)
name|mCompositePainter
operator|=
operator|new
name|QPainter
argument_list|(
name|mScreenImage
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|rectIndex
init|=
literal|0
init|;
name|rectIndex
operator|<
name|mRepaintRegion
operator|.
name|rectCount
argument_list|()
condition|;
name|rectIndex
operator|++
control|)
block|{
name|QRegion
name|rectRegion
init|=
name|rects
index|[
name|rectIndex
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mCachedRects
operator|.
name|length
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QRect
name|screenSubRect
init|=
name|mCachedRects
index|[
name|i
index|]
operator|.
name|first
decl_stmt|;
name|int
name|layer
init|=
name|mCachedRects
index|[
name|i
index|]
operator|.
name|second
decl_stmt|;
name|QRegion
name|intersect
init|=
name|rectRegion
operator|.
name|intersected
argument_list|(
name|screenSubRect
argument_list|)
decl_stmt|;
if|if
condition|(
name|intersect
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|rectRegion
operator|-=
name|intersect
expr_stmt|;
comment|// we only expect one rectangle, but defensive coding...
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|intersect
operator|.
name|rects
argument_list|()
control|)
block|{
name|bool
name|firstLayer
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|layer
operator|==
operator|-
literal|1
condition|)
block|{
name|mCompositePainter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|firstLayer
operator|=
literal|false
expr_stmt|;
name|layer
operator|=
name|mWindowStack
operator|.
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
block|}
for|for
control|(
name|int
name|layerIndex
init|=
name|layer
init|;
name|layerIndex
operator|!=
operator|-
literal|1
condition|;
name|layerIndex
operator|--
control|)
block|{
if|if
condition|(
operator|!
name|mWindowStack
index|[
name|layerIndex
index|]
operator|->
name|window
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
continue|continue;
comment|// if (mWindowStack[layerIndex]->isMinimized())
comment|//     continue;
name|QRect
name|windowRect
init|=
name|mWindowStack
index|[
name|layerIndex
index|]
operator|->
name|geometry
argument_list|()
operator|.
name|translated
argument_list|(
operator|-
name|screenOffset
argument_list|)
decl_stmt|;
name|QRect
name|windowIntersect
init|=
name|rect
operator|.
name|translated
argument_list|(
operator|-
name|windowRect
operator|.
name|left
argument_list|()
argument_list|,
operator|-
name|windowRect
operator|.
name|top
argument_list|()
argument_list|)
decl_stmt|;
name|QFbBackingStore
modifier|*
name|backingStore
init|=
name|mWindowStack
index|[
name|layerIndex
index|]
operator|->
name|backingStore
argument_list|()
decl_stmt|;
if|if
condition|(
name|backingStore
condition|)
block|{
name|backingStore
operator|->
name|lock
argument_list|()
expr_stmt|;
name|mCompositePainter
operator|->
name|drawImage
argument_list|(
name|rect
argument_list|,
name|backingStore
operator|->
name|image
argument_list|()
argument_list|,
name|windowIntersect
argument_list|)
expr_stmt|;
name|backingStore
operator|->
name|unlock
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|firstLayer
condition|)
block|{
name|firstLayer
operator|=
literal|false
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
name|QRect
name|cursorRect
decl_stmt|;
if|if
condition|(
name|mCursor
operator|&&
operator|(
name|mCursor
operator|->
name|isDirty
argument_list|()
operator|||
name|mRepaintRegion
operator|.
name|intersects
argument_list|(
name|mCursor
operator|->
name|lastPainted
argument_list|()
argument_list|)
operator|)
condition|)
block|{
name|cursorRect
operator|=
name|mCursor
operator|->
name|drawCursor
argument_list|(
operator|*
name|mCompositePainter
argument_list|)
expr_stmt|;
name|touchedRegion
operator|+=
name|cursorRect
expr_stmt|;
block|}
name|touchedRegion
operator|+=
name|mRepaintRegion
expr_stmt|;
name|mRepaintRegion
operator|=
name|QRegion
argument_list|()
expr_stmt|;
comment|//    qDebug()<< "QFbScreen::doRedraw"<< mWindowStack.size()<< mScreenImage->size()<< touchedRegion;
return|return
name|touchedRegion
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
