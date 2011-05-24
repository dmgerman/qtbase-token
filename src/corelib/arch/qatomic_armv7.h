begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_expr_stmt
name|QT_BEGIN_HEADER
comment|// use the DMB instruction when compiling for ARMv7, ...
ifndef|#
directive|ifndef
name|Q_CC_RCVT
DECL|macro|Q_DATA_MEMORY_BARRIER
define|#
directive|define
name|Q_DATA_MEMORY_BARRIER
value|asm volatile("dmb\n":::"memory")
else|#
directive|else
define|#
directive|define
name|Q_DATA_MEMORY_BARRIER
value|do{__asm { dmb } __schedule_barrier();}while(0)
endif|#
directive|endif
comment|// ... but the implementation is otherwise identical to that for ARMv6
name|QT_BEGIN_INCLUDE_HEADER
include|#
directive|include
file|"QtCore/qatomic_armv6.h"
name|QT_END_INCLUDE_HEADER
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_ARMV7_H
end_comment
end_unit
