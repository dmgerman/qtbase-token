begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTABBAR_H
end_ifndef
begin_define
DECL|macro|QTABBAR_H
define|#
directive|define
name|QTABBAR_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTabBarPrivate
name|class
name|QTabBarPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionTab
name|class
name|QStyleOptionTab
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTabBar
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|Shape shape READ shape WRITE setShape
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int count READ count
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool drawBase READ drawBase WRITE setDrawBase
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSize iconSize READ iconSize WRITE setIconSize
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextElideMode elideMode READ elideMode WRITE setElideMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool usesScrollButtons READ usesScrollButtons WRITE setUsesScrollButtons
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tabsClosable READ tabsClosable WRITE setTabsClosable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|SelectionBehavior selectionBehaviorOnRemove READ selectionBehaviorOnRemove WRITE setSelectionBehaviorOnRemove
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool expanding READ expanding WRITE setExpanding
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool movable READ isMovable WRITE setMovable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool documentMode READ documentMode WRITE setDocumentMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool autoHide READ autoHide WRITE setAutoHide
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool changeCurrentOnDrag READ changeCurrentOnDrag WRITE setChangeCurrentOnDrag
argument_list|)
name|public
operator|:
name|explicit
name|QTabBar
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QTabBar
argument_list|()
block|;      enum
name|Shape
block|{
name|RoundedNorth
block|,
name|RoundedSouth
block|,
name|RoundedWest
block|,
name|RoundedEast
block|,
name|TriangularNorth
block|,
name|TriangularSouth
block|,
name|TriangularWest
block|,
name|TriangularEast
block|}
block|;
name|Q_ENUM
argument_list|(
name|Shape
argument_list|)
expr|enum
name|ButtonPosition
block|{
name|LeftSide
block|,
name|RightSide
block|}
block|;      enum
name|SelectionBehavior
block|{
name|SelectLeftTab
block|,
name|SelectRightTab
block|,
name|SelectPreviousTab
block|}
block|;
name|Shape
name|shape
argument_list|()
specifier|const
block|;
name|void
name|setShape
argument_list|(
argument|Shape shape
argument_list|)
block|;
name|int
name|addTab
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|int
name|addTab
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|int
name|insertTab
argument_list|(
argument|int index
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|int
name|insertTab
argument_list|(
argument|int index
argument_list|,
argument|const QIcon&icon
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|void
name|removeTab
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|moveTab
argument_list|(
argument|int from
argument_list|,
argument|int to
argument_list|)
block|;
name|bool
name|isTabEnabled
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setTabEnabled
argument_list|(
argument|int index
argument_list|,
argument|bool
argument_list|)
block|;
name|QString
name|tabText
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setTabText
argument_list|(
argument|int index
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QColor
name|tabTextColor
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setTabTextColor
argument_list|(
argument|int index
argument_list|,
argument|const QColor&color
argument_list|)
block|;
name|QIcon
name|tabIcon
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setTabIcon
argument_list|(
argument|int index
argument_list|,
argument|const QIcon&icon
argument_list|)
block|;
name|Qt
operator|::
name|TextElideMode
name|elideMode
argument_list|()
specifier|const
block|;
name|void
name|setElideMode
argument_list|(
name|Qt
operator|::
name|TextElideMode
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|void
name|setTabToolTip
argument_list|(
argument|int index
argument_list|,
argument|const QString&tip
argument_list|)
block|;
name|QString
name|tabToolTip
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|void
name|setTabWhatsThis
argument_list|(
argument|int index
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QString
name|tabWhatsThis
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|void
name|setTabData
argument_list|(
argument|int index
argument_list|,
argument|const QVariant&data
argument_list|)
block|;
name|QVariant
name|tabData
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QRect
name|tabRect
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|tabAt
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|int
name|currentIndex
argument_list|()
specifier|const
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
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setDrawBase
argument_list|(
argument|bool drawTheBase
argument_list|)
block|;
name|bool
name|drawBase
argument_list|()
specifier|const
block|;
name|QSize
name|iconSize
argument_list|()
specifier|const
block|;
name|void
name|setIconSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|bool
name|usesScrollButtons
argument_list|()
specifier|const
block|;
name|void
name|setUsesScrollButtons
argument_list|(
argument|bool useButtons
argument_list|)
block|;
name|bool
name|tabsClosable
argument_list|()
specifier|const
block|;
name|void
name|setTabsClosable
argument_list|(
argument|bool closable
argument_list|)
block|;
name|void
name|setTabButton
argument_list|(
argument|int index
argument_list|,
argument|ButtonPosition position
argument_list|,
argument|QWidget *widget
argument_list|)
block|;
name|QWidget
operator|*
name|tabButton
argument_list|(
argument|int index
argument_list|,
argument|ButtonPosition position
argument_list|)
specifier|const
block|;
name|SelectionBehavior
name|selectionBehaviorOnRemove
argument_list|()
specifier|const
block|;
name|void
name|setSelectionBehaviorOnRemove
argument_list|(
argument|SelectionBehavior behavior
argument_list|)
block|;
name|bool
name|expanding
argument_list|()
specifier|const
block|;
name|void
name|setExpanding
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isMovable
argument_list|()
specifier|const
block|;
name|void
name|setMovable
argument_list|(
argument|bool movable
argument_list|)
block|;
name|bool
name|documentMode
argument_list|()
specifier|const
block|;
name|void
name|setDocumentMode
argument_list|(
argument|bool set
argument_list|)
block|;
name|bool
name|autoHide
argument_list|()
specifier|const
block|;
name|void
name|setAutoHide
argument_list|(
argument|bool hide
argument_list|)
block|;
name|bool
name|changeCurrentOnDrag
argument_list|()
specifier|const
block|;
name|void
name|setChangeCurrentOnDrag
argument_list|(
argument|bool change
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setCurrentIndex
argument_list|(
argument|int index
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|currentChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|tabCloseRequested
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|tabMoved
argument_list|(
argument|int from
argument_list|,
argument|int to
argument_list|)
block|;
name|void
name|tabBarClicked
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|tabBarDoubleClicked
argument_list|(
argument|int index
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|QSize
name|tabSizeHint
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|virtual
name|QSize
name|minimumTabSizeHint
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|tabInserted
argument_list|(
argument|int index
argument_list|)
block|;
name|virtual
name|void
name|tabRemoved
argument_list|(
argument|int index
argument_list|)
block|;
name|virtual
name|void
name|tabLayoutChange
argument_list|()
block|;
name|bool
name|event
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|showEvent
argument_list|(
argument|QShowEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|hideEvent
argument_list|(
argument|QHideEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
argument|QWheelEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
name|keyPressEvent
argument_list|(
argument|QKeyEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|changeEvent
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionTab *option
argument_list|,
argument|int tabIndex
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|friend
name|class
name|QAccessibleTabBar
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTabBar
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTabBar
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_scrollTabs()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_closeTab()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABBAR
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTABBAR_H
end_comment
end_unit
