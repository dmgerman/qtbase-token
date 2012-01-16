begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMATH_P_H
end_ifndef
begin_define
DECL|macro|QMATH_P_H
define|#
directive|define
name|QMATH_P_H
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
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Q_PI
specifier|static
specifier|const
name|qreal
name|Q_PI
init|=
name|qreal
argument_list|(
literal|3.14159265358979323846
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|Q_PI
comment|// pi
end_comment
begin_decl_stmt
DECL|variable|Q_2PI
specifier|static
specifier|const
name|qreal
name|Q_2PI
init|=
name|qreal
argument_list|(
literal|6.28318530717958647693
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|Q_2PI
comment|// 2*pi
end_comment
begin_decl_stmt
DECL|variable|Q_PI2
specifier|static
specifier|const
name|qreal
name|Q_PI2
init|=
name|qreal
argument_list|(
literal|1.57079632679489661923
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|Q_PI2
comment|// pi/2
end_comment
begin_function
DECL|function|qIntSqrtInt
specifier|inline
name|int
name|qIntSqrtInt
parameter_list|(
name|int
name|v
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|qSqrt
argument_list|(
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|v
operator|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMATH_P_H
end_comment
end_unit
