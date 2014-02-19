begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Intel Corporation ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCSVBENCHMARKLOGGER_P_H
end_ifndef
begin_define
DECL|macro|QCSVBENCHMARKLOGGER_P_H
define|#
directive|define
name|QCSVBENCHMARKLOGGER_P_H
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
file|"qabstracttestlogger_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCsvBenchmarkLogger
range|:
name|public
name|QAbstractTestLogger
block|{
name|public
operator|:
name|QCsvBenchmarkLogger
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
block|;
operator|~
name|QCsvBenchmarkLogger
argument_list|()
block|;
name|void
name|startLogging
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|stopLogging
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|enterTestFunction
argument_list|(
argument|const char *function
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|leaveTestFunction
argument_list|()
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|void
name|addBenchmarkResult
argument_list|(
argument|const QBenchmarkResult&result
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
comment|// QCSVBENCHMARKLOGGER_P_H
end_comment
end_unit
