begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PROPERTY_WATCHER_H
end_ifndef
begin_define
DECL|macro|PROPERTY_WATCHER_H
define|#
directive|define
name|PROPERTY_WATCHER_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFormLayout
name|class
name|QFormLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PropertyWatcher
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|PropertyWatcher
argument_list|(
argument|QObject* subject
argument_list|,
argument|QString annotation = QString()
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
operator|~
name|PropertyWatcher
argument_list|()
block|;
name|QFormLayout
operator|*
name|layout
argument_list|()
block|{
return|return
name|m_layout
return|;
block|}
name|QObject
operator|*
name|subject
argument_list|()
block|{
return|return
name|m_subject
return|;
block|}
name|public
name|slots
operator|:
name|void
name|updateAllFields
argument_list|()
block|;
name|void
name|subjectDestroyed
argument_list|()
block|;
name|signals
operator|:
name|void
name|updatedAllFields
argument_list|(
name|PropertyWatcher
operator|*
name|sender
argument_list|)
block|;
name|protected
operator|:
name|QObject
operator|*
name|m_subject
block|;
name|QFormLayout
operator|*
name|m_layout
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PROPERTY_WATCHER_H
end_comment
end_unit
