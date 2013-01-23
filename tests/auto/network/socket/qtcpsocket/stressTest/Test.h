begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TEST_H
end_ifndef
begin_define
DECL|macro|TEST_H
define|#
directive|define
name|TEST_H
end_define
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_include
include|#
directive|include
file|<QTcpServer>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_decl_stmt
name|class
name|My4Socket
range|:
name|public
name|QTcpSocket
block|{
name|Q_OBJECT
name|public
operator|:
name|My4Socket
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|void
name|sendTest
argument_list|(
argument|quint32 num
argument_list|)
block|;
name|bool
name|safeShutDown
block|;
name|private
name|slots
operator|:
name|void
name|read
argument_list|()
block|;
name|void
name|closed
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_decl_stmt
name|class
name|My4Server
range|:
name|public
name|QTcpServer
block|{
name|Q_OBJECT
name|public
operator|:
name|My4Server
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|void
name|incomingConnection
argument_list|(
argument|qintptr socket
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|stopServer
argument_list|()
block|;
name|private
operator|:
name|My4Socket
operator|*
name|m_socket
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_decl_stmt
name|class
name|Test
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Type
block|{
name|Qt4Client
block|,
name|Qt4Server
block|,     }
block|;
name|Test
argument_list|(
argument|Type type
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TEST_H
end_comment
end_unit
