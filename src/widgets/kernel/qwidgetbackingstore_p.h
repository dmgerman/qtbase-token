begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWIDGETBACKINGSTORE_P_H
end_ifndef
begin_define
DECL|macro|QWIDGETBACKINGSTORE_P_H
define|#
directive|define
name|QWIDGETBACKINGSTORE_P_H
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
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<private/qwidget_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qbackingstore.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformTextureList
name|class
name|QPlatformTextureList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformTextureListWatcher
name|class
name|QPlatformTextureListWatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidgetBackingStore
name|class
name|QWidgetBackingStore
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|BeginPaintInfo
struct|struct
name|BeginPaintInfo
block|{
DECL|function|BeginPaintInfo
specifier|inline
name|BeginPaintInfo
argument_list|()
operator|:
name|wasFlushed
argument_list|(
literal|0
argument_list|)
operator|,
name|nothingToPaint
argument_list|(
literal|0
argument_list|)
operator|,
name|backingStoreRecreated
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|wasFlushed
name|uint
name|wasFlushed
operator|:
literal|1
expr_stmt|;
DECL|member|nothingToPaint
name|uint
name|nothingToPaint
range|:
literal|1
decl_stmt|;
DECL|member|backingStoreRecreated
name|uint
name|backingStoreRecreated
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_decl_stmt
name|class
name|QPlatformTextureListWatcher
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QPlatformTextureListWatcher
argument_list|(
name|QWidgetBackingStore
operator|*
name|backingStore
argument_list|)
block|;
name|void
name|watch
argument_list|(
name|QPlatformTextureList
operator|*
name|textureList
argument_list|)
block|;
name|bool
name|isLocked
argument_list|()
specifier|const
block|;
name|private
name|slots
operator|:
name|void
name|onLockStatusChanged
argument_list|(
argument|bool locked
argument_list|)
block|;
name|private
operator|:
name|QHash
operator|<
name|QPlatformTextureList
operator|*
block|,
name|bool
operator|>
name|m_locked
block|;
name|QWidgetBackingStore
operator|*
name|m_backingStore
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QWidgetBackingStore
block|{
name|public
label|:
enum|enum
name|UpdateTime
block|{
name|UpdateNow
block|,
name|UpdateLater
block|}
enum|;
enum|enum
name|BufferState
block|{
name|BufferValid
block|,
name|BufferInvalid
block|}
enum|;
name|QWidgetBackingStore
argument_list|(
name|QWidget
operator|*
name|t
argument_list|)
expr_stmt|;
operator|~
name|QWidgetBackingStore
argument_list|()
expr_stmt|;
specifier|static
name|void
name|showYellowThing
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|,
name|int
name|msec
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|void
name|sync
parameter_list|(
name|QWidget
modifier|*
name|exposedWidget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|exposedRegion
parameter_list|)
function_decl|;
name|void
name|sync
parameter_list|()
function_decl|;
name|void
name|flush
parameter_list|(
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
function_decl|;
specifier|inline
name|QPoint
name|topLevelOffset
argument_list|()
specifier|const
block|{
return|return
name|tlwOffset
return|;
block|}
name|QBackingStore
operator|*
name|backingStore
argument_list|()
specifier|const
block|{
return|return
name|store
return|;
block|}
specifier|inline
name|bool
name|isDirty
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|dirtyWidgets
operator|.
name|isEmpty
argument_list|()
operator|&&
name|dirty
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|fullUpdatePending
operator|)
return|;
block|}
comment|// ### Qt 4.6: Merge into a template function (after MSVC isn't supported anymore).
name|void
name|markDirty
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|,
name|UpdateTime
name|updateTime
init|=
name|UpdateLater
parameter_list|,
name|BufferState
name|bufferState
init|=
name|BufferValid
parameter_list|)
function_decl|;
name|void
name|markDirty
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|,
name|UpdateTime
name|updateTime
init|=
name|UpdateLater
parameter_list|,
name|BufferState
name|bufferState
init|=
name|BufferValid
parameter_list|)
function_decl|;
name|private
label|:
name|QWidget
modifier|*
name|tlw
decl_stmt|;
name|QRegion
name|dirtyOnScreen
decl_stmt|;
comment|// needsFlush
name|QRegion
name|dirty
decl_stmt|;
comment|// needsRepaint
name|QRegion
name|dirtyFromPreviousSync
decl_stmt|;
name|QVector
operator|<
name|QWidget
operator|*
operator|>
name|dirtyWidgets
expr_stmt|;
name|QVector
operator|<
name|QWidget
operator|*
operator|>
name|dirtyRenderToTextureWidgets
expr_stmt|;
name|QVector
operator|<
name|QWidget
operator|*
operator|>
operator|*
name|dirtyOnScreenWidgets
expr_stmt|;
name|QList
operator|<
name|QWidget
operator|*
operator|>
name|staticWidgets
expr_stmt|;
name|QBackingStore
modifier|*
name|store
decl_stmt|;
name|uint
name|fullUpdatePending
range|:
literal|1
decl_stmt|;
name|uint
name|updateRequestSent
range|:
literal|1
decl_stmt|;
name|QPoint
name|tlwOffset
decl_stmt|;
name|QPlatformTextureListWatcher
modifier|*
name|textureListWatcher
decl_stmt|;
name|QElapsedTimer
name|perfTime
decl_stmt|;
name|int
name|perfFrames
decl_stmt|;
name|void
name|sendUpdateRequest
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|UpdateTime
name|updateTime
parameter_list|)
function_decl|;
specifier|static
name|bool
name|flushPaint
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|)
function_decl|;
specifier|static
name|void
name|unflushPaint
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|)
function_decl|;
specifier|static
name|void
name|qt_flush
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
name|QBackingStore
modifier|*
name|backingStore
parameter_list|,
name|QWidget
modifier|*
name|tlw
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|tlwOffset
parameter_list|,
name|QPlatformTextureList
modifier|*
name|widgetTextures
parameter_list|,
name|QWidgetBackingStore
modifier|*
name|widgetBackingStore
parameter_list|)
function_decl|;
name|void
name|doSync
parameter_list|()
function_decl|;
name|bool
name|bltRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
name|void
name|releaseBuffer
parameter_list|()
function_decl|;
name|void
name|beginPaint
parameter_list|(
name|QRegion
modifier|&
name|toClean
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QBackingStore
modifier|*
name|backingStore
parameter_list|,
name|BeginPaintInfo
modifier|*
name|returnInfo
parameter_list|,
name|bool
name|toCleanIsInTopLevelCoordinates
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|endPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|cleaned
parameter_list|,
name|QBackingStore
modifier|*
name|backingStore
parameter_list|,
name|BeginPaintInfo
modifier|*
name|beginPaintInfo
parameter_list|)
function_decl|;
name|QRegion
name|dirtyRegion
argument_list|(
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QRegion
name|staticContents
argument_list|(
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|,
specifier|const
name|QRect
operator|&
name|withinClipRect
operator|=
name|QRect
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|markDirtyOnScreen
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|dirtyOnScreen
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|topLevelOffset
parameter_list|)
function_decl|;
name|void
name|removeDirtyWidget
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
name|void
name|updateLists
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
name|bool
name|syncAllowed
parameter_list|()
function_decl|;
specifier|inline
name|void
name|addDirtyWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|)
block|{
if|if
condition|(
name|widget
operator|&&
operator|!
name|widget
operator|->
name|d_func
argument_list|()
operator|->
name|inDirtyList
operator|&&
operator|!
name|widget
operator|->
name|data
operator|->
name|in_destructor
condition|)
block|{
name|QWidgetPrivate
modifier|*
name|widgetPrivate
init|=
name|widget
operator|->
name|d_func
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSEFFECT
if|if
condition|(
name|widgetPrivate
operator|->
name|graphicsEffect
condition|)
name|widgetPrivate
operator|->
name|dirty
operator|=
name|widgetPrivate
operator|->
name|effectiveRectFor
argument_list|(
name|rgn
operator|.
name|boundingRect
argument_list|()
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
comment|//QT_NO_GRAPHICSEFFECT
name|widgetPrivate
operator|->
name|dirty
operator|=
name|rgn
expr_stmt|;
name|dirtyWidgets
operator|.
name|append
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|widgetPrivate
operator|->
name|inDirtyList
operator|=
name|true
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|addDirtyRenderToTextureWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
name|widget
operator|&&
operator|!
name|widget
operator|->
name|d_func
argument_list|()
operator|->
name|inDirtyList
operator|&&
operator|!
name|widget
operator|->
name|data
operator|->
name|in_destructor
condition|)
block|{
name|QWidgetPrivate
modifier|*
name|widgetPrivate
init|=
name|widget
operator|->
name|d_func
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|widgetPrivate
operator|->
name|renderToTexture
argument_list|)
expr_stmt|;
name|dirtyRenderToTextureWidgets
operator|.
name|append
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|widgetPrivate
operator|->
name|inDirtyList
operator|=
name|true
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|dirtyWidgetsRemoveAll
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|dirtyWidgets
operator|.
name|size
argument_list|()
condition|)
block|{
if|if
condition|(
name|dirtyWidgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|widget
condition|)
name|dirtyWidgets
operator|.
name|remove
argument_list|(
name|i
argument_list|)
expr_stmt|;
else|else
operator|++
name|i
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|addStaticWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
operator|!
name|widget
condition|)
return|return;
name|Q_ASSERT
argument_list|(
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|staticWidgets
operator|.
name|contains
argument_list|(
name|widget
argument_list|)
condition|)
name|staticWidgets
operator|.
name|append
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|removeStaticWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|staticWidgets
operator|.
name|removeAll
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
comment|// Move the reparented widget and all its static children from this backing store
comment|// to the new backing store if reparented into another top-level / backing store.
specifier|inline
name|void
name|moveStaticWidgets
parameter_list|(
name|QWidget
modifier|*
name|reparented
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|reparented
argument_list|)
expr_stmt|;
name|QWidgetBackingStore
modifier|*
name|newBs
init|=
name|reparented
operator|->
name|d_func
argument_list|()
operator|->
name|maybeBackingStore
argument_list|()
decl_stmt|;
if|if
condition|(
name|newBs
operator|==
name|this
condition|)
return|return;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|staticWidgets
operator|.
name|size
argument_list|()
condition|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|staticWidgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|reparented
operator|==
name|w
operator|||
name|reparented
operator|->
name|isAncestorOf
argument_list|(
name|w
argument_list|)
condition|)
block|{
name|staticWidgets
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|newBs
condition|)
name|newBs
operator|->
name|addStaticWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|++
name|i
expr_stmt|;
block|}
block|}
block|}
specifier|inline
name|QRect
name|topLevelRect
argument_list|()
specifier|const
block|{
return|return
name|tlw
operator|->
name|data
operator|->
name|crect
return|;
block|}
specifier|inline
name|void
name|appendDirtyOnScreenWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
operator|!
name|widget
condition|)
return|return;
if|if
condition|(
operator|!
name|dirtyOnScreenWidgets
condition|)
block|{
name|dirtyOnScreenWidgets
operator|=
name|new
name|QVector
operator|<
name|QWidget
operator|*
operator|>
expr_stmt|;
name|dirtyOnScreenWidgets
operator|->
name|append
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|dirtyOnScreenWidgets
operator|->
name|contains
argument_list|(
name|widget
argument_list|)
condition|)
block|{
name|dirtyOnScreenWidgets
operator|->
name|append
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|dirtyOnScreenWidgetsRemoveAll
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
operator|!
name|widget
operator|||
operator|!
name|dirtyOnScreenWidgets
condition|)
return|return;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|dirtyOnScreenWidgets
operator|->
name|size
argument_list|()
condition|)
block|{
if|if
condition|(
name|dirtyOnScreenWidgets
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|widget
condition|)
name|dirtyOnScreenWidgets
operator|->
name|remove
argument_list|(
name|i
argument_list|)
expr_stmt|;
else|else
operator|++
name|i
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|resetWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
name|widget
condition|)
block|{
name|widget
operator|->
name|d_func
argument_list|()
operator|->
name|inDirtyList
operator|=
name|false
expr_stmt|;
name|widget
operator|->
name|d_func
argument_list|()
operator|->
name|isScrolled
operator|=
name|false
expr_stmt|;
name|widget
operator|->
name|d_func
argument_list|()
operator|->
name|isMoved
operator|=
name|false
expr_stmt|;
name|widget
operator|->
name|d_func
argument_list|()
operator|->
name|dirty
operator|=
name|QRegion
argument_list|()
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|updateStaticContentsSize
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|staticWidgets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidgetPrivate
modifier|*
name|wd
init|=
name|staticWidgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|d_func
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|wd
operator|->
name|extra
condition|)
name|wd
operator|->
name|createExtra
argument_list|()
expr_stmt|;
name|wd
operator|->
name|extra
operator|->
name|staticContentsSize
operator|=
name|wd
operator|->
name|data
operator|.
name|crect
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
block|}
specifier|inline
name|bool
name|hasStaticContents
argument_list|()
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
return|return
operator|!
name|staticWidgets
operator|.
name|isEmpty
argument_list|()
return|;
else|#
directive|else
return|return
operator|!
name|staticWidgets
operator|.
name|isEmpty
argument_list|()
operator|&&
name|false
return|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_function_decl
name|friend
name|QRegion
name|qt_dirtyRegion
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|friend
name|class
name|QWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QBackingStore
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QWidgetBackingStore
argument_list|)
end_macro
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBACKINGSTORE_P_H
end_comment
end_unit
