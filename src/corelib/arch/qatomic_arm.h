begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_ARM_H
end_ifndef
begin_define
DECL|macro|QATOMIC_ARM_H
define|#
directive|define
name|QATOMIC_ARM_H
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7R__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7M__
argument_list|)
DECL|macro|QT_ARCH_ARMV7
define|#
directive|define
name|QT_ARCH_ARMV7
name|QT_BEGIN_INCLUDE_HEADER
include|#
directive|include
file|"QtCore/qatomic_armv7.h"
name|QT_END_INCLUDE_HEADER
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6T2__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6M__
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__TARGET_ARCH_ARM
argument_list|)
operator|&&
operator|(
name|__TARGET_ARCH_ARM
operator|-
literal|0
operator|>=
literal|6
operator|)
operator|)
define|#
directive|define
name|QT_ARCH_ARMV6
name|QT_BEGIN_INCLUDE_HEADER
include|#
directive|include
file|"QtCore/qatomic_armv6.h"
name|QT_END_INCLUDE_HEADER
else|#
directive|else
define|#
directive|define
name|QT_ARCH_ARMV5
name|QT_BEGIN_INCLUDE_HEADER
include|#
directive|include
file|"QtCore/qatomic_armv5.h"
name|QT_END_INCLUDE_HEADER
endif|#
directive|endif
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_ARM_H
end_comment
end_unit
