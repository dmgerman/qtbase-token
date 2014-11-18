begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTOOLS_P_H
end_ifndef
begin_define
DECL|macro|QTOOLS_P_H
define|#
directive|define
name|QTOOLS_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|<limits>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtMiscUtils
block|{
specifier|inline
name|char
name|toHexUpper
parameter_list|(
name|uint
name|value
parameter_list|)
block|{
specifier|static
specifier|const
name|char
name|hexdigits
index|[]
init|=
literal|"0123456789ABCDEF"
decl_stmt|;
return|return
name|hexdigits
index|[
name|value
operator|&
literal|0xF
index|]
return|;
block|}
specifier|inline
name|char
name|toHexLower
parameter_list|(
name|uint
name|value
parameter_list|)
block|{
specifier|static
specifier|const
name|char
name|hexdigits
index|[]
init|=
literal|"0123456789abcdef"
decl_stmt|;
return|return
name|hexdigits
index|[
name|value
operator|&
literal|0xF
index|]
return|;
block|}
block|}
end_decl_stmt
begin_comment
comment|// We typically need an extra bit for qNextPowerOfTwo when determining the next allocation size.
end_comment
begin_enum
enum|enum
block|{
DECL|enumerator|MaxAllocSize
name|MaxAllocSize
init|=
operator|(
literal|1
operator|<<
operator|(
name|std
operator|::
name|numeric_limits
operator|<
name|int
operator|>
operator|::
name|digits
operator|-
literal|1
operator|)
operator|)
operator|-
literal|1
block|}
enum|;
end_enum
begin_comment
comment|// implemented in qbytearray.cpp
end_comment
begin_decl_stmt
name|int
name|Q_CORE_EXPORT
name|qAllocMore
argument_list|(
name|int
name|alloc
argument_list|,
name|int
name|extra
argument_list|)
name|Q_DECL_NOTHROW
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
comment|// QTOOLS_P_H
end_comment
end_unit
