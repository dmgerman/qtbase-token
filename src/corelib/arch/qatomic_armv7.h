begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_ARMV7_H
end_ifndef
begin_define
DECL|macro|QATOMIC_ARMV7_H
define|#
directive|define
name|QATOMIC_ARMV7_H
end_define
begin_comment
comment|// use the DMB instruction when compiling for ARMv7, ...
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_CC_RCVT
end_ifndef
begin_define
DECL|macro|Q_DATA_MEMORY_BARRIER
define|#
directive|define
name|Q_DATA_MEMORY_BARRIER
value|asm volatile("dmb\n":::"memory")
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_DATA_MEMORY_BARRIER
define|#
directive|define
name|Q_DATA_MEMORY_BARRIER
value|do{__asm { dmb } __schedule_barrier();}while(0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ... but the implementation is otherwise identical to that for ARMv6
end_comment
begin_include
include|#
directive|include
file|"QtCore/qatomic_armv6.h"
end_include
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// silence syncqt warnings
end_comment
begin_pragma
unit|QT_BEGIN_NAMESPACE  QT_END_NAMESPACE
pragma|#
directive|pragma
name|qt_sync_skip_header_check
end_pragma
begin_pragma
pragma|#
directive|pragma
name|qt_sync_stop_processing
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_ARMV7_H
end_comment
end_unit
