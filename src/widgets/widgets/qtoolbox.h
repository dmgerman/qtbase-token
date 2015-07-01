begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTOOLBOX_H
end_ifndef
begin_define
DECL|macro|QTOOLBOX_H
define|#
directive|define
name|QTOOLBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qframe.h>
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
name|QT_NO_TOOLBOX
DECL|variable|QToolBoxPrivate
name|class
name|QToolBoxPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QToolBox
range|:
name|public
name|QFrame
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int count READ count
argument_list|)
name|public
operator|:
name|explicit
name|QToolBox
argument_list|(
argument|QWidget *parent = Q_NULLPTR
argument_list|,
argument|Qt::WindowFlags f = Qt::WindowFlags()
argument_list|)
block|;
operator|~
name|QToolBox
argument_list|()
block|;
name|int
name|addItem
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|int
name|addItem
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
name|text
argument_list|)
block|;
name|int
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|QWidget *widget
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|int
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|QWidget *widget
argument_list|,
argument|const QIcon&icon
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|void
name|removeItem
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|setItemEnabled
argument_list|(
argument|int index
argument_list|,
argument|bool enabled
argument_list|)
block|;
name|bool
name|isItemEnabled
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setItemText
argument_list|(
argument|int index
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QString
name|itemText
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setItemIcon
argument_list|(
argument|int index
argument_list|,
argument|const QIcon&icon
argument_list|)
block|;
name|QIcon
name|itemIcon
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|void
name|setItemToolTip
argument_list|(
argument|int index
argument_list|,
argument|const QString&toolTip
argument_list|)
block|;
name|QString
name|itemToolTip
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
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|itemInserted
argument_list|(
argument|int index
argument_list|)
block|;
name|virtual
name|void
name|itemRemoved
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
argument|QShowEvent *e
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
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QToolBox
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QToolBox
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_buttonClicked()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_widgetDestroyed(QObject*)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|addItem
specifier|inline
name|int
name|QToolBox
operator|::
name|addItem
argument_list|(
argument|QWidget *item
argument_list|,
argument|const QString&text
argument_list|)
block|{
return|return
name|insertItem
argument_list|(
operator|-
literal|1
argument_list|,
name|item
argument_list|,
name|QIcon
argument_list|()
argument_list|,
name|text
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|addItem
specifier|inline
name|int
name|QToolBox
operator|::
name|addItem
argument_list|(
argument|QWidget *item
argument_list|,
argument|const QIcon&iconSet
argument_list|,
argument|const QString&text
argument_list|)
block|{
return|return
name|insertItem
argument_list|(
operator|-
literal|1
argument_list|,
name|item
argument_list|,
name|iconSet
argument_list|,
name|text
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|insertItem
specifier|inline
name|int
name|QToolBox
operator|::
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|QWidget *item
argument_list|,
argument|const QString&text
argument_list|)
block|{
return|return
name|insertItem
argument_list|(
name|index
argument_list|,
name|item
argument_list|,
name|QIcon
argument_list|()
argument_list|,
name|text
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TOOLBOX
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTOOLBOX_H
end_comment
end_unit
