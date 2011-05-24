begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QURL_H
end_ifndef
begin_define
DECL|macro|QURL_H
define|#
directive|define
name|QURL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QUrlPrivate
decl_stmt|;
DECL|variable|QDataStream
name|class
name|QDataStream
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QUrl
decl_stmt|{ public:     enum ParsingMode
block|{
name|TolerantMode
operator|,
name|StrictMode
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// encoding / toString values
end_comment
begin_enum
enum|enum
name|FormattingOption
block|{
name|None
init|=
literal|0x0
block|,
name|RemoveScheme
init|=
literal|0x1
block|,
name|RemovePassword
init|=
literal|0x2
block|,
name|RemoveUserInfo
init|=
name|RemovePassword
operator||
literal|0x4
block|,
name|RemovePort
init|=
literal|0x8
block|,
name|RemoveAuthority
init|=
name|RemoveUserInfo
operator||
name|RemovePort
operator||
literal|0x10
block|,
name|RemovePath
init|=
literal|0x20
block|,
name|RemoveQuery
init|=
literal|0x40
block|,
name|RemoveFragment
init|=
literal|0x80
block|,
comment|// 0x100: private: normalized
name|StripTrailingSlash
init|=
literal|0x10000
block|}
enum|;
end_enum
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|FormattingOptions
argument_list|,
argument|FormattingOption
argument_list|)
end_macro
begin_expr_stmt
name|QUrl
argument_list|()
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_URL_CAST_FROM_STRING
end_ifdef
begin_function_decl
name|explicit
endif|#
directive|endif
name|QUrl
parameter_list|(
specifier|const
name|QString
modifier|&
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QUrl
argument_list|(
argument|const QString&url
argument_list|,
argument|ParsingMode mode
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// ### Qt 5: merge the two constructors, with mode = TolerantMode
end_comment
begin_expr_stmt
name|QUrl
argument_list|(
specifier|const
name|QUrl
operator|&
name|copy
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QUrl
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QUrl
operator|&
name|copy
operator|)
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_URL_CAST_FROM_STRING
end_ifndef
begin_decl_stmt
name|QUrl
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QString
operator|&
name|url
operator|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_decl_stmt
specifier|inline
name|QUrl
modifier|&
name|operator
init|=
operator|(
name|QUrl
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
operator|~
name|QUrl
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function
specifier|inline
name|void
name|swap
parameter_list|(
name|QUrl
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|setUrl
parameter_list|(
specifier|const
name|QString
modifier|&
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setUrl
parameter_list|(
specifier|const
name|QString
modifier|&
name|url
parameter_list|,
name|ParsingMode
name|mode
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### Qt 5: merge the two setUrl() functions, with mode = TolerantMode
end_comment
begin_function_decl
name|void
name|setEncodedUrl
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setEncodedUrl
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|url
parameter_list|,
name|ParsingMode
name|mode
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### Qt 5: merge the two setEncodedUrl() functions, with mode = TolerantMode
end_comment
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setScheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|scheme
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|scheme
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setAuthority
parameter_list|(
specifier|const
name|QString
modifier|&
name|authority
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|authority
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setUserInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|userInfo
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|userInfo
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setUserName
parameter_list|(
specifier|const
name|QString
modifier|&
name|userName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|userName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEncodedUserName
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|userName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|encodedUserName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPassword
parameter_list|(
specifier|const
name|QString
modifier|&
name|password
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|password
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEncodedPassword
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|password
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|encodedPassword
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setHost
parameter_list|(
specifier|const
name|QString
modifier|&
name|host
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|host
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEncodedHost
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|host
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|encodedHost
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPort
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|port
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|port
argument_list|(
name|int
name|defaultPort
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ### Qt 5: merge the two port() functions, with defaultPort = -1
end_comment
begin_function_decl
name|void
name|setPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEncodedPath
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|encodedPath
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|hasQuery
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEncodedQuery
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|query
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|encodedQuery
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setQueryDelimiters
parameter_list|(
name|char
name|valueDelimiter
parameter_list|,
name|char
name|pairDelimiter
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|char
name|queryValueDelimiter
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|char
name|queryPairDelimiter
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|setQueryItems
argument_list|(
specifier|const
name|QList
operator|<
name|QPair
operator|<
name|QString
argument_list|,
name|QString
operator|>
expr|>
operator|&
name|query
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|addQueryItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QList
operator|<
name|QPair
operator|<
name|QString
operator|,
name|QString
operator|>
expr|>
name|queryItems
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|hasQueryItem
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|queryItemValue
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|allQueryItemValues
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|removeQueryItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|removeAllQueryItems
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|setEncodedQueryItems
argument_list|(
specifier|const
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
argument_list|,
name|QByteArray
operator|>
expr|>
operator|&
name|query
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|addEncodedQueryItem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
expr|>
name|encodedQueryItems
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|hasEncodedQueryItem
argument_list|(
specifier|const
name|QByteArray
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|encodedQueryItemValue
argument_list|(
specifier|const
name|QByteArray
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QByteArray
operator|>
name|allEncodedQueryItemValues
argument_list|(
argument|const QByteArray&key
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|removeEncodedQueryItem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|removeAllEncodedQueryItems
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setFragment
parameter_list|(
specifier|const
name|QString
modifier|&
name|fragment
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|fragment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEncodedFragment
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fragment
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|encodedFragment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|hasFragment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QUrl
name|resolved
argument_list|(
specifier|const
name|QUrl
operator|&
name|relative
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|bool
name|isRelative
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|isParentOf
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|QUrl
name|fromLocalFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|localfile
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|toLocalFile
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isLocalFile
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|toString
argument_list|(
name|FormattingOptions
name|options
operator|=
name|None
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|toEncoded
argument_list|(
name|FormattingOptions
name|options
operator|=
name|None
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|QUrl
name|fromEncoded
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QUrl
name|fromEncoded
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|url
parameter_list|,
name|ParsingMode
name|mode
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### Qt 5: merge the two fromEncoded() functions, with mode = TolerantMode
end_comment
begin_function_decl
specifier|static
name|QUrl
name|fromUserInput
parameter_list|(
specifier|const
name|QString
modifier|&
name|userInput
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|detach
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isDetached
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QUrl
operator|&
name|url
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QUrl
operator|&
name|url
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QUrl
operator|&
name|url
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|QString
name|fromPercentEncoding
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QByteArray
name|toPercentEncoding
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|exclude
init|=
name|QByteArray
argument_list|()
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|include
init|=
name|QByteArray
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|fromPunycode
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QByteArray
name|toPunycode
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|fromAce
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QByteArray
name|toAce
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QStringList
name|idnWhitelist
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|setIdnWhitelist
parameter_list|(
specifier|const
name|QStringList
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|defined
name|QT3_SUPPORT
end_if
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|QString
name|protocol
argument_list|()
specifier|const
block|{
return|return
name|scheme
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setProtocol
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
block|{
name|setScheme
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setUser
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
block|{
name|setUserName
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|QString
name|user
argument_list|()
specifier|const
block|{
return|return
name|userName
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|hasUser
argument_list|()
specifier|const
block|{
return|return
operator|!
name|userName
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|hasPassword
argument_list|()
specifier|const
block|{
return|return
operator|!
name|password
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|hasHost
argument_list|()
specifier|const
block|{
return|return
operator|!
name|host
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|hasPort
argument_list|()
specifier|const
block|{
return|return
name|port
argument_list|()
operator|!=
operator|-
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|hasPath
argument_list|()
specifier|const
block|{
return|return
operator|!
name|path
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|txt
parameter_list|)
block|{
name|setEncodedQuery
argument_list|(
name|txt
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|QString
name|query
argument_list|()
specifier|const
block|{
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|encodedQuery
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|QString
name|ref
argument_list|()
specifier|const
block|{
return|return
name|fragment
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setRef
parameter_list|(
specifier|const
name|QString
modifier|&
name|txt
parameter_list|)
block|{
name|setFragment
argument_list|(
name|txt
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|hasRef
argument_list|()
specifier|const
block|{
return|return
operator|!
name|fragment
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|addPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|p
parameter_list|)
block|{
name|setPath
argument_list|(
name|path
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|QT3_SUPPORT
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|txt
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QT3_SUPPORT
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT3_SUPPORT
name|QString
name|dirPath
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|QT3_SUPPORT
name|void
name|decode
parameter_list|(
name|QString
modifier|&
name|url
parameter_list|)
block|{
name|url
operator|=
name|QUrl
operator|::
name|fromPercentEncoding
argument_list|(
name|url
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|QT3_SUPPORT
name|void
name|encode
parameter_list|(
name|QString
modifier|&
name|url
parameter_list|)
block|{
name|url
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|QUrl
operator|::
name|toPercentEncoding
argument_list|(
name|url
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|operator
name|QString
argument_list|()
specifier|const
block|{
return|return
name|toString
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|bool
name|cdUp
parameter_list|()
block|{
operator|*
name|this
operator|=
name|resolved
argument_list|(
name|QUrl
argument_list|(
name|QLatin1String
argument_list|(
literal|".."
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|QT3_SUPPORT
name|bool
name|isRelativeUrl
parameter_list|(
specifier|const
name|QString
modifier|&
name|url
parameter_list|)
block|{
return|return
name|QUrl
argument_list|(
name|url
argument_list|)
operator|.
name|isRelative
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT3_SUPPORT
argument_list|)
end_if
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|reset
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QUrlPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_typedef
typedef|typedef
name|QUrlPrivate
modifier|*
name|DataPtr
typedef|;
end_typedef
begin_function
specifier|inline
name|DataPtr
modifier|&
name|data_ptr
parameter_list|()
block|{
return|return
name|d
return|;
block|}
end_function
begin_function
unit|};
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|url
operator|.
name|toEncoded
argument_list|(
name|QUrl
operator|::
name|FormattingOption
argument_list|(
literal|0x100
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QUrl
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QUrl
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QUrl::FormattingOptions
argument_list|)
end_macro
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
name|QUrl
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|operator
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QUrl
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
name|QUrl
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QURL_H
end_comment
end_unit
