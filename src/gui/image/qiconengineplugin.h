begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QICONENGINEPLUGIN_H
end_ifndef
begin_define
DECL|macro|QICONENGINEPLUGIN_H
define|#
directive|define
name|QICONENGINEPLUGIN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfactoryinterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIconEngine
name|class
name|QIconEngine
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QIconEngineFactoryInterface_iid
define|#
directive|define
name|QIconEngineFactoryInterface_iid
value|"org.qt-project.Qt.QIconEngineFactoryInterface"
end_define
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QIconEnginePlugin
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QIconEnginePlugin
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QIconEnginePlugin
argument_list|()
block|;
name|virtual
name|QIconEngine
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|filename
operator|=
name|QString
argument_list|()
argument_list|)
operator|=
literal|0
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
comment|// QICONENGINEPLUGIN_H
end_comment
end_unit
