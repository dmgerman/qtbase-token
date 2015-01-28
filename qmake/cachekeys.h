begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CACHEKEYS_H
end_ifndef
begin_define
DECL|macro|CACHEKEYS_H
define|#
directive|define
name|CACHEKEYS_H
end_define
begin_include
include|#
directive|include
file|"project.h"
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// -------------------------------------------------------------------------------------------------
end_comment
begin_struct
DECL|struct|FixStringCacheKey
struct|struct
name|FixStringCacheKey
block|{
DECL|member|hash
name|mutable
name|uint
name|hash
decl_stmt|;
DECL|member|string
DECL|member|pwd
name|QString
name|string
decl_stmt|,
name|pwd
decl_stmt|;
DECL|member|flags
name|uchar
name|flags
decl_stmt|;
DECL|function|FixStringCacheKey
name|FixStringCacheKey
argument_list|(
argument|const QString&s
argument_list|,
argument|uchar f
argument_list|)
block|{
name|hash
operator|=
literal|0
expr_stmt|;
name|pwd
operator|=
name|qmake_getpwd
argument_list|()
expr_stmt|;
name|string
operator|=
name|s
expr_stmt|;
name|flags
operator|=
name|f
expr_stmt|;
block|}
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FixStringCacheKey
operator|&
name|f
operator|)
specifier|const
block|{
return|return
operator|(
name|hashCode
argument_list|()
operator|==
name|f
operator|.
name|hashCode
argument_list|()
operator|&&
name|f
operator|.
name|flags
operator|==
name|flags
operator|&&
name|f
operator|.
name|string
operator|==
name|string
operator|&&
name|f
operator|.
name|pwd
operator|==
name|pwd
operator|)
return|;
block|}
DECL|function|hashCode
specifier|inline
name|uint
name|hashCode
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hash
condition|)
name|hash
operator|=
name|qHash
argument_list|(
name|string
argument_list|)
operator|^
name|qHash
argument_list|(
name|flags
argument_list|)
comment|/*^ qHash(pwd)*/
expr_stmt|;
return|return
name|hash
return|;
block|}
end_struct
begin_function
unit|};
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|FixStringCacheKey
modifier|&
name|f
parameter_list|)
block|{
return|return
name|f
operator|.
name|hashCode
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// -------------------------------------------------------------------------------------------------
end_comment
begin_struct
DECL|struct|FileInfoCacheKey
struct|struct
name|FileInfoCacheKey
block|{
DECL|member|hash
name|mutable
name|uint
name|hash
decl_stmt|;
DECL|member|file
DECL|member|pwd
name|QString
name|file
decl_stmt|,
name|pwd
decl_stmt|;
DECL|function|FileInfoCacheKey
name|FileInfoCacheKey
argument_list|(
argument|const QString&f
argument_list|)
block|{
name|hash
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|isRelativePath
argument_list|(
name|f
argument_list|)
condition|)
name|pwd
operator|=
name|qmake_getpwd
argument_list|()
expr_stmt|;
name|file
operator|=
name|f
expr_stmt|;
block|}
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FileInfoCacheKey
operator|&
name|f
operator|)
specifier|const
block|{
return|return
operator|(
name|hashCode
argument_list|()
operator|==
name|f
operator|.
name|hashCode
argument_list|()
operator|&&
name|f
operator|.
name|file
operator|==
name|file
operator|&&
name|f
operator|.
name|pwd
operator|==
name|pwd
operator|)
return|;
block|}
DECL|function|hashCode
specifier|inline
name|uint
name|hashCode
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hash
condition|)
name|hash
operator|=
name|qHash
argument_list|(
name|file
argument_list|)
comment|/*^ qHash(pwd)*/
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|isRelativePath
specifier|inline
namespace|bool
name|isRelativePath
namespace|(const
name|QString
namespace|&
name|file
struct|)
block|{
name|int
name|length
init|=
name|file
operator|.
name|length
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|length
condition|)
return|return
name|true
return|;
specifier|const
name|QChar
name|c0
init|=
name|file
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|QChar
name|c1
init|=
name|length
operator|>=
literal|2
condition|?
name|file
operator|.
name|at
argument_list|(
literal|1
argument_list|)
else|:
name|QChar
argument_list|(
literal|0
argument_list|)
decl_stmt|;
return|return
operator|!
operator|(
name|c0
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|||
name|c0
operator|==
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
operator|||
operator|(
name|c0
operator|.
name|isLetter
argument_list|()
operator|&&
name|c1
operator|==
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|)
operator|||
operator|(
name|c0
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|&&
name|c1
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|)
operator|||
operator|(
name|c0
operator|==
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
operator|&&
name|c1
operator|==
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
operator|)
operator|)
return|;
block|}
end_struct
begin_function
unit|};
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|FileInfoCacheKey
modifier|&
name|f
parameter_list|)
block|{
return|return
name|f
operator|.
name|hashCode
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// -------------------------------------------------------------------------------------------------
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qmakeDeleteCacheClear
specifier|inline
name|void
name|qmakeDeleteCacheClear
argument_list|(
argument|void *i
argument_list|)
block|{
name|delete
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|i
operator|)
block|; }
DECL|function|qmakeFreeCacheClear
specifier|inline
name|void
name|qmakeFreeCacheClear
argument_list|(
argument|void *i
argument_list|)
block|{
name|free
argument_list|(
name|i
argument_list|)
block|; }
end_expr_stmt
begin_typedef
DECL|typedef|qmakeCacheClearFunc
typedef|typedef
name|void
function_decl|(
modifier|*
name|qmakeCacheClearFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
name|void
name|qmakeAddCacheClear
parameter_list|(
name|qmakeCacheClearFunc
name|func
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qmakeClearCaches
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CACHEKEYS_H
end_comment
end_unit
