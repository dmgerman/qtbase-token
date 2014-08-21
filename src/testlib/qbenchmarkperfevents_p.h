begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Intel Corporation. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBENCHMARKPERFEVENTS_P_H
end_ifndef
begin_define
DECL|macro|QBENCHMARKPERFEVENTS_P_H
define|#
directive|define
name|QBENCHMARKPERFEVENTS_P_H
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
file|<QtTest/private/qbenchmarkmeasurement_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QBenchmarkPerfEventsMeasurer
range|:
name|public
name|QBenchmarkMeasurerBase
block|{
name|public
operator|:
name|QBenchmarkPerfEventsMeasurer
argument_list|()
block|;
operator|~
name|QBenchmarkPerfEventsMeasurer
argument_list|()
block|;
name|virtual
name|void
name|init
argument_list|()
block|;
name|virtual
name|void
name|start
argument_list|()
block|;
name|virtual
name|qint64
name|checkpoint
argument_list|()
block|;
name|virtual
name|qint64
name|stop
argument_list|()
block|;
name|virtual
name|bool
name|isMeasurementAccepted
argument_list|(
argument|qint64 measurement
argument_list|)
block|;
name|virtual
name|int
name|adjustIterationCount
argument_list|(
argument|int suggestion
argument_list|)
block|;
name|virtual
name|int
name|adjustMedianCount
argument_list|(
argument|int suggestion
argument_list|)
block|;
name|virtual
name|bool
name|repeatCount
argument_list|()
block|{
return|return
literal|1
return|;
block|}
name|virtual
name|bool
name|needsWarmupIteration
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|QTest
operator|::
name|QBenchmarkMetric
name|metricType
argument_list|()
block|;
specifier|static
name|bool
name|isAvailable
argument_list|()
block|;
specifier|static
name|QTest
operator|::
name|QBenchmarkMetric
name|metricForEvent
argument_list|(
argument|quint32 type
argument_list|,
argument|quint64 event_id
argument_list|)
block|;
specifier|static
name|void
name|setCounter
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
specifier|static
name|void
name|listCounters
argument_list|()
block|;
name|private
operator|:
name|int
name|fd
block|;
name|qint64
name|readValue
argument_list|()
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
comment|// QBENCHMARKPERFEVENTS_P_H
end_comment
end_unit
