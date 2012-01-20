begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUUID_H
end_ifndef
begin_define
DECL|macro|QUUID_H
define|#
directive|define
name|QUUID_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcryptographichash.h>
end_include
begin_macro
name|QT_BEGIN_HEADER
end_macro
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|GUID_DEFINED
end_ifndef
begin_define
DECL|macro|GUID_DEFINED
define|#
directive|define
name|GUID_DEFINED
end_define
begin_typedef
DECL|struct|_GUID
typedef|typedef
struct|struct
name|_GUID
block|{
DECL|member|Data1
name|ulong
name|Data1
decl_stmt|;
DECL|member|Data2
name|ushort
name|Data2
decl_stmt|;
DECL|member|Data3
name|ushort
name|Data3
decl_stmt|;
DECL|member|Data4
name|uchar
name|Data4
index|[
literal|8
index|]
decl_stmt|;
block|}
DECL|typedef|GUID
DECL|typedef|REFGUID
DECL|typedef|LPGUID
name|GUID
operator|,
typedef|*
name|REFGUID
operator|,
typedef|*
name|LPGUID
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|Q_CORE_EXPORT
name|QUuid
decl_stmt|{ public:     enum Variant
block|{
name|VarUnknown
operator|=
operator|-
literal|1
operator|,
name|NCS
operator|=
literal|0
operator|,
comment|// 0 - -
name|DCE
operator|=
literal|2
operator|,
comment|// 1 0 -
name|Microsoft
operator|=
literal|6
operator|,
comment|// 1 1 0
name|Reserved
operator|=
literal|7
comment|// 1 1 1
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
enum|enum
name|Version
block|{
name|VerUnknown
init|=
operator|-
literal|1
block|,
name|Time
init|=
literal|1
block|,
comment|// 0 0 0 1
name|EmbeddedPOSIX
init|=
literal|2
block|,
comment|// 0 0 1 0
name|Md5
init|=
literal|3
block|,
comment|// 0 0 1 1
name|Name
init|=
name|Md5
block|,
name|Random
init|=
literal|4
block|,
comment|// 0 1 0 0
name|Sha1
init|=
literal|5
comment|// 0 1 0 1
block|}
enum|;
end_enum
begin_macro
name|QUuid
argument_list|()
end_macro
begin_block
block|{
name|data1
operator|=
literal|0
expr_stmt|;
name|data2
operator|=
literal|0
expr_stmt|;
name|data3
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
name|data4
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_block
begin_macro
name|QUuid
argument_list|(
argument|uint l
argument_list|,
argument|ushort w1
argument_list|,
argument|ushort w2
argument_list|,
argument|uchar b1
argument_list|,
argument|uchar b2
argument_list|,
argument|uchar b3
argument_list|,
argument|uchar b4
argument_list|,
argument|uchar b5
argument_list|,
argument|uchar b6
argument_list|,
argument|uchar b7
argument_list|,
argument|uchar b8
argument_list|)
end_macro
begin_block
block|{
name|data1
operator|=
name|l
expr_stmt|;
name|data2
operator|=
name|w1
expr_stmt|;
name|data3
operator|=
name|w2
expr_stmt|;
name|data4
index|[
literal|0
index|]
operator|=
name|b1
expr_stmt|;
name|data4
index|[
literal|1
index|]
operator|=
name|b2
expr_stmt|;
name|data4
index|[
literal|2
index|]
operator|=
name|b3
expr_stmt|;
name|data4
index|[
literal|3
index|]
operator|=
name|b4
expr_stmt|;
name|data4
index|[
literal|4
index|]
operator|=
name|b5
expr_stmt|;
name|data4
index|[
literal|5
index|]
operator|=
name|b6
expr_stmt|;
name|data4
index|[
literal|6
index|]
operator|=
name|b7
expr_stmt|;
name|data4
index|[
literal|7
index|]
operator|=
name|b8
expr_stmt|;
block|}
end_block
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QUUID_STRING
end_ifndef
begin_expr_stmt
name|QUuid
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QUuid
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QString
name|toString
parameter_list|()
function_decl|const;
end_function_decl
begin_expr_stmt
name|QUuid
argument_list|(
specifier|const
name|QByteArray
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QByteArray
name|toByteArray
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QByteArray
name|toRfc4122
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|QUuid
name|fromRfc4122
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QUuid
operator|&
name|orig
operator|)
specifier|const
block|{
name|uint
name|i
block|;
if|if
condition|(
name|data1
operator|!=
name|orig
operator|.
name|data1
operator|||
name|data2
operator|!=
name|orig
operator|.
name|data2
operator|||
name|data3
operator|!=
name|orig
operator|.
name|data3
condition|)
return|return
name|false
return|;
end_expr_stmt
begin_for
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|data4
index|[
name|i
index|]
operator|!=
name|orig
operator|.
name|data4
index|[
name|i
index|]
condition|)
return|return
name|false
return|;
end_for
begin_return
return|return
name|true
return|;
end_return
begin_expr_stmt
unit|}      bool
name|operator
operator|!=
operator|(
specifier|const
name|QUuid
operator|&
name|orig
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|orig
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QUuid
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QUuid
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_comment
comment|// On Windows we have a type GUID that is used by the platform API, so we
end_comment
begin_comment
comment|// provide convenience operators to cast from and to this type.
end_comment
begin_macro
name|QUuid
argument_list|(
argument|const GUID&guid
argument_list|)
end_macro
begin_block
block|{
name|data1
operator|=
name|guid
operator|.
name|Data1
expr_stmt|;
name|data2
operator|=
name|guid
operator|.
name|Data2
expr_stmt|;
name|data3
operator|=
name|guid
operator|.
name|Data3
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
name|data4
index|[
name|i
index|]
operator|=
name|guid
operator|.
name|Data4
index|[
name|i
index|]
expr_stmt|;
block|}
end_block
begin_decl_stmt
name|QUuid
modifier|&
name|operator
init|=
operator|(
specifier|const
name|GUID
operator|&
name|guid
operator|)
block|{
operator|*
name|this
operator|=
name|QUuid
argument_list|(
name|guid
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|operator
name|GUID
argument_list|()
specifier|const
block|{
name|GUID
name|guid
operator|=
block|{
name|data1
block|,
name|data2
block|,
name|data3
block|,
block|{
name|data4
index|[
literal|0
index|]
block|,
name|data4
index|[
literal|1
index|]
block|,
name|data4
index|[
literal|2
index|]
block|,
name|data4
index|[
literal|3
index|]
block|,
name|data4
index|[
literal|4
index|]
block|,
name|data4
index|[
literal|5
index|]
block|,
name|data4
index|[
literal|6
index|]
block|,
name|data4
index|[
literal|7
index|]
block|}
block|}
block|;
return|return
name|guid
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|GUID
operator|&
name|guid
operator|)
specifier|const
block|{
return|return
operator|*
name|this
operator|==
name|QUuid
argument_list|(
name|guid
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|GUID
operator|&
name|guid
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|guid
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|QUuid
name|createUuid
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QUuid
name|createUuidV3
parameter_list|(
specifier|const
name|QUuid
modifier|&
name|ns
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|baseData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QUuid
name|createUuidV5
parameter_list|(
specifier|const
name|QUuid
modifier|&
name|ns
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|baseData
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QUUID_STRING
end_ifndef
begin_function
specifier|static
specifier|inline
name|QUuid
name|createUuidV3
parameter_list|(
specifier|const
name|QUuid
modifier|&
name|ns
parameter_list|,
specifier|const
name|QString
modifier|&
name|baseData
parameter_list|)
block|{
return|return
name|QUuid
operator|::
name|createUuidV3
argument_list|(
name|ns
argument_list|,
name|baseData
operator|.
name|toUtf8
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|QUuid
name|createUuidV5
parameter_list|(
specifier|const
name|QUuid
modifier|&
name|ns
parameter_list|,
specifier|const
name|QString
modifier|&
name|baseData
parameter_list|)
block|{
return|return
name|QUuid
operator|::
name|createUuidV5
argument_list|(
name|ns
argument_list|,
name|baseData
operator|.
name|toUtf8
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QUuid
operator|::
name|Variant
name|variant
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QUuid
operator|::
name|Version
name|version
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|uint
name|data1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ushort
name|data2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ushort
name|data3
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uchar
name|data4
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QUuid
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QUuid
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QUuid
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QUuid
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|Q_CORE_EXPORT
name|uint
name|qHash
parameter_list|(
specifier|const
name|QUuid
modifier|&
name|uuid
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUUID_H
end_comment
end_unit
