begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_endif
unit|QT_BEGIN_NAMESPACE  QT_END_NAMESPACE
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
