begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2013 Ivan Komissarov. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKEYSEQUENCEEDIT_H
end_ifndef
begin_define
DECL|macro|QKEYSEQUENCEEDIT_H
define|#
directive|define
name|QKEYSEQUENCEEDIT_H
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
name|QT_NO_KEYSEQUENCEEDIT
DECL|variable|QKeySequenceEditPrivate
name|class
name|QKeySequenceEditPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QKeySequenceEdit
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QKeySequence keySequence READ keySequence WRITE setKeySequence NOTIFY keySequenceChanged USER true
argument_list|)
name|public
operator|:
name|explicit
name|QKeySequenceEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QKeySequenceEdit
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|keySequence
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QKeySequenceEdit
argument_list|()
block|;
name|QKeySequence
name|keySequence
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setKeySequence
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|keySequence
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|editingFinished
argument_list|()
block|;
name|void
name|keySequenceChanged
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|keySequence
argument_list|)
block|;
name|protected
operator|:
name|QKeySequenceEdit
argument_list|(
argument|QKeySequenceEditPrivate&d
argument_list|,
argument|QWidget *parent
argument_list|,
argument|Qt::WindowFlags f
argument_list|)
block|;
name|bool
name|event
argument_list|(
argument|QEvent *
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
name|keyReleaseEvent
argument_list|(
argument|QKeyEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QKeySequenceEdit
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QKeySequenceEdit
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_KEYSEQUENCEEDIT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QKEYSEQUENCEEDIT_H
end_comment
end_unit
