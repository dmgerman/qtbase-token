begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDESKTOPWIDGET_H
end_ifndef
begin_define
DECL|macro|QDESKTOPWIDGET_H
define|#
directive|define
name|QDESKTOPWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QApplication
name|class
name|QApplication
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDesktopWidgetPrivate
name|class
name|QDesktopWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDesktopWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool virtualDesktop READ isVirtualDesktop
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int screenCount READ screenCount NOTIFY screenCountChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int primaryScreen READ primaryScreen
argument_list|)
name|public
operator|:
name|QDesktopWidget
argument_list|()
block|;
operator|~
name|QDesktopWidget
argument_list|()
block|;
name|bool
name|isVirtualDesktop
argument_list|()
specifier|const
block|;
name|int
name|numScreens
argument_list|()
specifier|const
block|;
name|int
name|screenCount
argument_list|()
specifier|const
block|;
name|int
name|primaryScreen
argument_list|()
specifier|const
block|;
name|int
name|screenNumber
argument_list|(
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|screenNumber
argument_list|(
argument|const QPoint&
argument_list|)
specifier|const
block|;
name|QWidget
operator|*
name|screen
argument_list|(
argument|int screen = -
literal|1
argument_list|)
block|;
specifier|const
name|QRect
name|screenGeometry
argument_list|(
argument|int screen = -
literal|1
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|screenGeometry
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|screenGeometry
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
block|{
return|return
name|screenGeometry
argument_list|(
name|screenNumber
argument_list|(
name|point
argument_list|)
argument_list|)
return|;
block|}
specifier|const
name|QRect
name|availableGeometry
argument_list|(
argument|int screen = -
literal|1
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|availableGeometry
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|availableGeometry
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
block|{
return|return
name|availableGeometry
argument_list|(
name|screenNumber
argument_list|(
name|point
argument_list|)
argument_list|)
return|;
block|}
name|Q_SIGNALS
operator|:
name|void
name|resized
argument_list|(
name|int
argument_list|)
block|;
name|void
name|workAreaResized
argument_list|(
name|int
argument_list|)
block|;
name|void
name|screenCountChanged
argument_list|(
name|int
argument_list|)
block|;
name|protected
operator|:
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDesktopWidget
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDesktopWidget
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateScreens()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_availableGeometryChanged()
argument_list|)
name|friend
name|class
name|QApplication
block|;
name|friend
name|class
name|QApplicationPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|screenCount
specifier|inline
name|int
name|QDesktopWidget
operator|::
name|screenCount
argument_list|()
specifier|const
block|{
return|return
name|numScreens
argument_list|()
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDESKTOPWIDGET_H
end_comment
end_unit
