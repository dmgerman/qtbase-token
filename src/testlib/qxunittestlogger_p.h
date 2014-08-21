begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXUNITTESTLOGGER_P_H
end_ifndef
begin_define
DECL|macro|QXUNITTESTLOGGER_P_H
define|#
directive|define
name|QXUNITTESTLOGGER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qabstracttestlogger_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTestXunitStreamer
name|class
name|QTestXunitStreamer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTestElement
name|class
name|QTestElement
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXunitTestLogger
range|:
name|public
name|QAbstractTestLogger
block|{
name|public
operator|:
name|QXunitTestLogger
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
block|;
operator|~
name|QXunitTestLogger
argument_list|()
block|;
name|void
name|startLogging
argument_list|()
block|;
name|void
name|stopLogging
argument_list|()
block|;
name|void
name|enterTestFunction
argument_list|(
specifier|const
name|char
operator|*
name|function
argument_list|)
block|;
name|void
name|leaveTestFunction
argument_list|()
block|;
name|void
name|addIncident
argument_list|(
argument|IncidentTypes type
argument_list|,
argument|const char *description
argument_list|,
argument|const char *file =
literal|0
argument_list|,
argument|int line =
literal|0
argument_list|)
block|;
name|void
name|addBenchmarkResult
argument_list|(
specifier|const
name|QBenchmarkResult
operator|&
name|result
argument_list|)
block|;
name|void
name|addTag
argument_list|(
name|QTestElement
operator|*
name|element
argument_list|)
block|;
name|void
name|addMessage
argument_list|(
argument|MessageTypes type
argument_list|,
argument|const QString&message
argument_list|,
argument|const char *file =
literal|0
argument_list|,
argument|int line =
literal|0
argument_list|)
block|;
name|private
operator|:
name|QTestElement
operator|*
name|listOfTestcases
block|;
name|QTestElement
operator|*
name|currentLogElement
block|;
name|QTestElement
operator|*
name|errorLogElement
block|;
name|QTestXunitStreamer
operator|*
name|logFormatter
block|;
name|int
name|testCounter
block|;
name|int
name|failureCounter
block|;
name|int
name|errorCounter
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
comment|// QXUNITTESTLOGGER_P_H
end_comment
end_unit
