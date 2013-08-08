begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSPLITTER_P_H
end_ifndef
begin_define
DECL|macro|QSPLITTER_P_H
define|#
directive|define
name|QSPLITTER_P_H
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
file|"private/qframe_p.h"
end_include
begin_include
include|#
directive|include
file|"qrubberband.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Default
specifier|static
specifier|const
name|uint
name|Default
init|=
literal|2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSplitterLayoutStruct
block|{
name|public
label|:
name|QRect
name|rect
decl_stmt|;
name|int
name|sizer
decl_stmt|;
name|uint
name|collapsed
range|:
literal|1
decl_stmt|;
name|uint
name|collapsible
range|:
literal|2
decl_stmt|;
name|QWidget
modifier|*
name|widget
decl_stmt|;
name|QSplitterHandle
modifier|*
name|handle
decl_stmt|;
name|QSplitterLayoutStruct
argument_list|()
operator|:
name|sizer
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|collapsed
argument_list|(
name|false
argument_list|)
operator|,
name|collapsible
argument_list|(
name|Default
argument_list|)
operator|,
name|widget
argument_list|(
literal|0
argument_list|)
operator|,
name|handle
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|QSplitterLayoutStruct
argument_list|()
block|{
name|delete
name|handle
block|; }
name|int
name|getWidgetSize
argument_list|(
argument|Qt::Orientation orient
argument_list|)
expr_stmt|;
name|int
name|getHandleSize
argument_list|(
name|Qt
operator|::
name|Orientation
name|orient
argument_list|)
decl_stmt|;
name|int
name|pick
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|Qt
operator|::
name|Orientation
name|orient
argument_list|)
block|{
return|return
operator|(
name|orient
operator|==
name|Qt
operator|::
name|Horizontal
operator|)
condition|?
name|size
operator|.
name|width
argument_list|()
else|:
name|size
operator|.
name|height
argument_list|()
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QSplitterPrivate
range|:
name|public
name|QFramePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSplitter
argument_list|)
name|public
operator|:
name|QSplitterPrivate
argument_list|()
operator|:
name|rubberBand
argument_list|(
literal|0
argument_list|)
block|,
name|opaque
argument_list|(
name|true
argument_list|)
block|,
name|firstShow
argument_list|(
name|true
argument_list|)
block|,
name|childrenCollapsible
argument_list|(
name|true
argument_list|)
block|,
name|compatMode
argument_list|(
name|false
argument_list|)
block|,
name|handleWidth
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|blockChildAdd
argument_list|(
name|false
argument_list|)
block|,
name|opaqueResizeSet
argument_list|(
argument|false
argument_list|)
block|{}
name|QPointer
operator|<
name|QRubberBand
operator|>
name|rubberBand
block|;
name|mutable
name|QList
operator|<
name|QSplitterLayoutStruct
operator|*
operator|>
name|list
block|;
name|Qt
operator|::
name|Orientation
name|orient
block|;
name|bool
name|opaque
operator|:
literal|8
block|;
name|bool
name|firstShow
operator|:
literal|8
block|;
name|bool
name|childrenCollapsible
operator|:
literal|8
block|;
name|bool
name|compatMode
operator|:
literal|8
block|;
name|int
name|handleWidth
block|;
name|bool
name|blockChildAdd
block|;
name|bool
name|opaqueResizeSet
block|;
specifier|inline
name|int
name|pick
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|{
return|return
name|orient
operator|==
name|Qt
operator|::
name|Horizontal
operator|?
name|pos
operator|.
name|x
argument_list|()
operator|:
name|pos
operator|.
name|y
argument_list|()
return|;
block|}
specifier|inline
name|int
name|pick
argument_list|(
argument|const QSize&s
argument_list|)
specifier|const
block|{
return|return
name|orient
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|s
operator|.
name|width
argument_list|()
else|:
name|s
operator|.
name|height
argument_list|()
return|;
block|}
specifier|inline
name|int
name|trans
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|{
return|return
name|orient
operator|==
name|Qt
operator|::
name|Vertical
condition|?
name|pos
operator|.
name|x
argument_list|()
else|:
name|pos
operator|.
name|y
argument_list|()
return|;
block|}
specifier|inline
name|int
name|trans
argument_list|(
argument|const QSize&s
argument_list|)
specifier|const
block|{
return|return
name|orient
operator|==
name|Qt
operator|::
name|Vertical
condition|?
name|s
operator|.
name|width
argument_list|()
else|:
name|s
operator|.
name|height
argument_list|()
return|;
block|}
name|void
name|init
argument_list|()
block|;
name|void
name|recalc
argument_list|(
argument|bool update = false
argument_list|)
block|;
name|void
name|doResize
argument_list|()
block|;
name|void
name|storeSizes
argument_list|()
block|;
name|void
name|getRange
argument_list|(
argument|int index
argument_list|,
argument|int *
argument_list|,
argument|int *
argument_list|,
argument|int *
argument_list|,
argument|int *
argument_list|)
specifier|const
block|;
name|void
name|addContribution
argument_list|(
argument|int
argument_list|,
argument|int *
argument_list|,
argument|int *
argument_list|,
argument|bool
argument_list|)
specifier|const
block|;
name|int
name|adjustPos
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
argument|int *
argument_list|,
argument|int *
argument_list|,
argument|int *
argument_list|,
argument|int *
argument_list|)
specifier|const
block|;
name|bool
name|collapsible
argument_list|(
argument|QSplitterLayoutStruct *
argument_list|)
specifier|const
block|;
name|bool
name|collapsible
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
return|return
operator|(
name|index
operator|<
literal|0
operator|||
name|index
operator|>=
name|list
operator|.
name|size
argument_list|()
operator|)
condition|?
name|true
else|:
name|collapsible
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
block|}
name|QSplitterLayoutStruct
operator|*
name|findWidget
argument_list|(
argument|QWidget *
argument_list|)
specifier|const
block|;
name|void
name|insertWidget_helper
argument_list|(
argument|int index
argument_list|,
argument|QWidget *widget
argument_list|,
argument|bool show
argument_list|)
block|;
name|QSplitterLayoutStruct
operator|*
name|insertWidget
argument_list|(
argument|int index
argument_list|,
argument|QWidget *
argument_list|)
block|;
name|void
name|doMove
argument_list|(
argument|bool backwards
argument_list|,
argument|int pos
argument_list|,
argument|int index
argument_list|,
argument|int delta
argument_list|,
argument|bool mayCollapse
argument_list|,
argument|int *positions
argument_list|,
argument|int *widths
argument_list|)
block|;
name|void
name|setGeo
argument_list|(
argument|QSplitterLayoutStruct *s
argument_list|,
argument|int pos
argument_list|,
argument|int size
argument_list|,
argument|bool allowCollapse
argument_list|)
block|;
name|int
name|findWidgetJustBeforeOrJustAfter
argument_list|(
argument|int index
argument_list|,
argument|int delta
argument_list|,
argument|int&collapsibleSize
argument_list|)
specifier|const
block|;
name|void
name|updateHandles
argument_list|()
block|;
name|void
name|setSizes_helper
argument_list|(
argument|const QList<int>&sizes
argument_list|,
argument|bool clampNegativeSize = false
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSplitterHandlePrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSplitterHandle
argument_list|)
name|public
operator|:
name|QSplitterHandlePrivate
argument_list|()
operator|:
name|s
argument_list|(
literal|0
argument_list|)
block|,
name|orient
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
block|,
name|mouseOffset
argument_list|(
literal|0
argument_list|)
block|,
name|opaq
argument_list|(
name|false
argument_list|)
block|,
name|hover
argument_list|(
name|false
argument_list|)
block|,
name|pressed
argument_list|(
argument|false
argument_list|)
block|{}
specifier|inline
name|int
name|pick
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|{
return|return
name|orient
operator|==
name|Qt
operator|::
name|Horizontal
operator|?
name|pos
operator|.
name|x
argument_list|()
operator|:
name|pos
operator|.
name|y
argument_list|()
return|;
block|}
name|QSplitter
operator|*
name|s
block|;
name|Qt
operator|::
name|Orientation
name|orient
block|;
name|int
name|mouseOffset
block|;
name|bool
name|opaq
operator|:
literal|1
block|;
name|bool
name|hover
operator|:
literal|1
block|;
name|bool
name|pressed
operator|:
literal|1
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
