begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTABWIDGET_H
end_ifndef
begin_define
DECL|macro|QTABWIDGET_H
define|#
directive|define
name|QTABWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TABWIDGET
DECL|variable|QTabBar
name|class
name|QTabBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTabWidgetPrivate
name|class
name|QTabWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionTabWidgetFrame
name|class
name|QStyleOptionTabWidgetFrame
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTabWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|TabPosition tabPosition READ tabPosition WRITE setTabPosition
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|TabShape tabShape READ tabShape WRITE setTabShape
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
argument|bool documentMode READ documentMode WRITE setDocumentMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tabsClosable READ tabsClosable WRITE setTabsClosable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool movable READ isMovable WRITE setMovable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tabBarAutoHide READ tabBarAutoHide WRITE setTabBarAutoHide
argument_list|)
name|public
operator|:
name|explicit
name|QTabWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QTabWidget
argument_list|()
block|;
name|int
name|addTab
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|int
name|addTab
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|label
argument_list|)
block|;
name|int
name|insertTab
argument_list|(
argument|int index
argument_list|,
argument|QWidget *widget
argument_list|,
argument|const QString&
argument_list|)
block|;
name|int
name|insertTab
argument_list|(
argument|int index
argument_list|,
argument|QWidget *widget
argument_list|,
argument|const QIcon& icon
argument_list|,
argument|const QString&label
argument_list|)
block|;
name|void
name|removeTab
argument_list|(
argument|int index
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
argument|const QString&
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
argument|const QIcon& icon
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
argument|const QString& tip
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
name|int
name|currentIndex
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|currentWidget
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|widget
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|indexOf
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|int
name|count
argument_list|()
specifier|const
block|;      enum
name|TabPosition
block|{
name|North
block|,
name|South
block|,
name|West
block|,
name|East
block|}
block|;
name|Q_ENUM
argument_list|(
argument|TabPosition
argument_list|)
name|TabPosition
name|tabPosition
argument_list|()
specifier|const
block|;
name|void
name|setTabPosition
argument_list|(
name|TabPosition
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
argument|bool closeable
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
block|;      enum
name|TabShape
block|{
name|Rounded
block|,
name|Triangular
block|}
block|;
name|Q_ENUM
argument_list|(
argument|TabShape
argument_list|)
name|TabShape
name|tabShape
argument_list|()
specifier|const
block|;
name|void
name|setTabShape
argument_list|(
argument|TabShape s
argument_list|)
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
name|int
name|heightForWidth
argument_list|(
argument|int width
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setCornerWidget
argument_list|(
argument|QWidget * w
argument_list|,
argument|Qt::Corner corner = Qt::TopRightCorner
argument_list|)
block|;
name|QWidget
operator|*
name|cornerWidget
argument_list|(
argument|Qt::Corner corner = Qt::TopRightCorner
argument_list|)
specifier|const
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
name|tabBarAutoHide
argument_list|()
specifier|const
block|;
name|void
name|setTabBarAutoHide
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|QTabBar
operator|*
name|tabBar
argument_list|()
specifier|const
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
name|void
name|setCurrentWidget
argument_list|(
name|QWidget
operator|*
name|widget
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
name|void
name|showEvent
argument_list|(
argument|QShowEvent *
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
name|keyPressEvent
argument_list|(
argument|QKeyEvent *
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
name|setTabBar
argument_list|(
name|QTabBar
operator|*
argument_list|)
block|;
name|void
name|changeEvent
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|event
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionTabWidgetFrame *option
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTabWidget
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QTabWidget
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_showTab(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_removeTab(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_tabMoved(int, int)
argument_list|)
name|void
name|setUpLayout
argument_list|(
name|bool
operator|=
name|false
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABWIDGET
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTABWIDGET_H
end_comment
end_unit
