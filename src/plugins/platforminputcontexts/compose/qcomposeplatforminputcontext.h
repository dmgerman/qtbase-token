begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOMPOSEPLATFORMINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QCOMPOSEPLATFORMINPUTCONTEXT_H
define|#
directive|define
name|QCOMPOSEPLATFORMINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|"generator/qtablegenerator.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QComposeInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|Q_OBJECT
name|public
operator|:
name|QComposeInputContext
argument_list|()
block|;
operator|~
name|QComposeInputContext
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setFocusObject
argument_list|(
argument|QObject *object
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|reset
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|update
argument_list|(
argument|Qt::InputMethodQueries
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|filterEvent
argument_list|(
argument|const QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|void
name|clearComposeBuffer
argument_list|()
block|;
name|bool
name|ignoreKey
argument_list|(
argument|int keyval
argument_list|)
specifier|const
block|;
name|bool
name|composeKey
argument_list|(
argument|int keyval
argument_list|)
specifier|const
block|;
name|bool
name|checkComposeTable
argument_list|()
block|;
name|void
name|commitText
argument_list|(
argument|uint character
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QObject
operator|*
name|m_focusObject
block|;
name|QVector
operator|<
name|QComposeTableElement
operator|>
name|m_composeTable
block|;
name|uint
name|m_composeBuffer
index|[
name|QT_KEYSEQUENCE_MAX_LEN
operator|+
literal|1
index|]
block|;
name|TableGenerator
operator|::
name|TableState
name|m_tableState
block|;
name|bool
name|m_compositionTableInitialized
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
comment|// QCOMPOSEPLATFORMINPUTCONTEXT_H
end_comment
end_unit
