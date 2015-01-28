begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCHECKBOX_H
end_ifndef
begin_define
DECL|macro|QCHECKBOX_H
define|#
directive|define
name|QCHECKBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractbutton.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCheckBoxPrivate
name|class
name|QCheckBoxPrivate
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
name|Q_WIDGETS_EXPORT
name|QCheckBox
range|:
name|public
name|QAbstractButton
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool tristate READ isTristate WRITE setTristate
argument_list|)
name|public
operator|:
name|explicit
name|QCheckBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QCheckBox
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
operator|~
name|QCheckBox
argument_list|()
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
name|setTristate
argument_list|(
argument|bool y = true
argument_list|)
block|;
name|bool
name|isTristate
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|CheckState
name|checkState
argument_list|()
specifier|const
block|;
name|void
name|setCheckState
argument_list|(
argument|Qt::CheckState state
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|stateChanged
argument_list|(
name|int
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
name|bool
name|hitButton
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|checkStateSet
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|nextCheckState
argument_list|()
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
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionButton *option
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QCheckBox
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QCheckBox
argument_list|)
name|friend
name|class
name|QAccessibleButton
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
begin_comment
comment|// QCHECKBOX_H
end_comment
end_unit
