begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVDEVTABLET_P_H
end_ifndef
begin_define
DECL|macro|QEVDEVTABLET_P_H
define|#
directive|define
name|QEVDEVTABLET_P_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QEvdevTabletData
name|class
name|QEvdevTabletData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEvdevTabletHandler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QEvdevTabletHandler
argument_list|(
specifier|const
name|QString
operator|&
name|spec
operator|=
name|QString
argument_list|()
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEvdevTabletHandler
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|readData
argument_list|()
block|;
name|private
operator|:
name|QEvdevTabletData
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEvdevTabletHandlerThread
range|:
name|public
name|QThread
block|{
name|public
operator|:
name|QEvdevTabletHandlerThread
argument_list|(
specifier|const
name|QString
operator|&
name|spec
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEvdevTabletHandlerThread
argument_list|()
block|;
name|void
name|run
argument_list|()
block|;
name|QEvdevTabletHandler
operator|*
name|handler
argument_list|()
block|{
return|return
name|m_handler
return|;
block|}
name|private
operator|:
name|QString
name|m_spec
block|;
name|QEvdevTabletHandler
operator|*
name|m_handler
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVDEVTABLET_P_H
end_comment
end_unit
