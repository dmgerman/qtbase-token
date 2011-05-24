begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPUSHBUTTON_H
end_ifndef
begin_define
DECL|macro|QPUSHBUTTON_H
define|#
directive|define
name|QPUSHBUTTON_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qabstractbutton.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QPushButtonPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionButton
name|class
name|QStyleOptionButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPushButton
range|:
name|public
name|QAbstractButton
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool autoDefault READ autoDefault WRITE setAutoDefault
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool default READ isDefault WRITE setDefault
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool flat READ isFlat WRITE setFlat
argument_list|)
name|public
operator|:
name|explicit
name|QPushButton
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QPushButton
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QPushButton
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
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QPushButton
argument_list|()
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|bool
name|autoDefault
argument_list|()
specifier|const
block|;
name|void
name|setAutoDefault
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isDefault
argument_list|()
specifier|const
block|;
name|void
name|setDefault
argument_list|(
name|bool
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|void
name|setMenu
argument_list|(
name|QMenu
operator|*
name|menu
argument_list|)
block|;
name|QMenu
operator|*
name|menu
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setFlat
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isFlat
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|void
name|showMenu
argument_list|()
block|;
endif|#
directive|endif
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|bool
name|hitButton
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
endif|#
directive|endif
comment|// Q_WS_MAC
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
argument_list|)
block|;
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionButton *option
argument_list|)
specifier|const
block|;
name|QPushButton
argument_list|(
name|QPushButtonPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|public
operator|:
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|QT3_SUPPORT_CONSTRUCTOR
name|QPushButton
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QPushButton
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QPushButton
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
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
specifier|inline
name|QT3_SUPPORT
name|void
name|openPopup
argument_list|()
block|{
name|showMenu
argument_list|()
block|; }
specifier|inline
name|QT3_SUPPORT
name|bool
name|isMenuButton
argument_list|()
specifier|const
block|{
return|return
name|menu
argument_list|()
operator|!=
literal|0
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|void
name|setPopup
argument_list|(
argument|QMenu* popup
argument_list|)
block|{
name|setMenu
argument_list|(
name|popup
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|QMenu
operator|*
name|popup
argument_list|()
specifier|const
block|{
return|return
name|menu
argument_list|()
return|;
block|}
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPushButton
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPushButton
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_popupPressed()
argument_list|)
endif|#
directive|endif
expr|}
block|;
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPUSHBUTTON_H
end_comment
end_unit
