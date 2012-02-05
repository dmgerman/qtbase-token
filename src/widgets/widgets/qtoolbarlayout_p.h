begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTOOLBARLAYOUT_P_H
end_ifndef
begin_define
DECL|macro|QTOOLBARLAYOUT_P_H
define|#
directive|define
name|QTOOLBARLAYOUT_P_H
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
file|<QtWidgets/qlayout.h>
end_include
begin_include
include|#
directive|include
file|<private/qlayoutengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolBarExtension
name|class
name|QToolBarExtension
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QToolBarItem
range|:
name|public
name|QWidgetItem
block|{
name|public
operator|:
name|QToolBarItem
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
name|QAction
operator|*
name|action
block|;
name|bool
name|customWidget
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QToolBarLayout
range|:
name|public
name|QLayout
block|{
name|Q_OBJECT
name|public
operator|:
name|QToolBarLayout
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QToolBarLayout
argument_list|()
block|;
name|void
name|addItem
argument_list|(
name|QLayoutItem
operator|*
name|item
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
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
name|void
name|invalidate
argument_list|()
block|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
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
name|QSize
name|minimumSize
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|void
name|insertAction
argument_list|(
argument|int index
argument_list|,
argument|QAction *action
argument_list|)
block|;
name|int
name|indexOf
argument_list|(
argument|QAction *action
argument_list|)
specifier|const
block|;
name|int
name|indexOf
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|{
return|return
name|QLayout
operator|::
name|indexOf
argument_list|(
name|widget
argument_list|)
return|;
block|}
name|bool
name|layoutActions
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|QSize
name|expandedSize
argument_list|(
argument|const QSize&size
argument_list|)
specifier|const
block|;
name|bool
name|expanded
block|,
name|animating
block|;
name|void
name|setUsePopupMenu
argument_list|(
argument|bool set
argument_list|)
block|;
comment|// Yeah, there's no getter, but it's internal.
name|void
name|checkUsePopupMenu
argument_list|()
block|;
name|bool
name|movable
argument_list|()
specifier|const
block|;
name|void
name|updateMarginAndSpacing
argument_list|()
block|;
name|bool
name|hasExpandFlag
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setExpanded
argument_list|(
argument|bool b
argument_list|)
block|;
name|private
operator|:
name|QList
operator|<
name|QToolBarItem
operator|*
operator|>
name|items
block|;
name|QSize
name|hint
block|,
name|minSize
block|;
name|bool
name|dirty
block|,
name|expanding
block|,
name|empty
block|,
name|expandFlag
block|;
name|QVector
operator|<
name|QLayoutStruct
operator|>
name|geomArray
block|;
name|QRect
name|handRect
block|;
name|QToolBarExtension
operator|*
name|extension
block|;
name|void
name|updateGeomArray
argument_list|()
specifier|const
block|;
name|QToolBarItem
operator|*
name|createItem
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|QMenu
operator|*
name|popupMenu
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TOOLBAR
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTOOLBARLAYOUT_P_H
end_comment
end_unit
