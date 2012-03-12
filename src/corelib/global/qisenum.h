begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QISENUM_H
end_ifndef
begin_define
DECL|macro|QISENUM_H
define|#
directive|define
name|QISENUM_H
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|Q_IS_ENUM
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|3
operator|)
operator|)
DECL|macro|Q_IS_ENUM
define|#
directive|define
name|Q_IS_ENUM
parameter_list|(
name|x
parameter_list|)
value|__is_enum(x)
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_FULL_VER
argument_list|)
operator|&&
operator|(
name|_MSC_FULL_VER
operator|>=
literal|140050215
operator|)
define|#
directive|define
name|Q_IS_ENUM
parameter_list|(
name|x
parameter_list|)
value|__is_enum(x)
else|#
directive|else
include|#
directive|include
file|<QtCore/qtypetraits.h>
define|#
directive|define
name|Q_IS_ENUM
parameter_list|(
name|x
parameter_list|)
value|QtPrivate::is_enum<x>::value
endif|#
directive|endif
endif|#
directive|endif
name|QT_END_HEADER
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QISENUM_H
end_comment
end_unit
