begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2012 Intel Corporation. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QUrlQuery
name|class
name|QUrlQuery
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrlPrivate
name|class
name|QUrlPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDataStream
name|class
name|QDataStream
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|E1
name|template
operator|<
name|typename
name|E1
operator|,
name|typename
name|E2
operator|>
name|class
name|QUrlTwoFlags
block|{
name|int
name|i
block|;
typedef|typedef
name|int
name|QUrlTwoFlags
operator|::
operator|*
name|Zero
expr_stmt|;
name|public
operator|:
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
argument_list|(
argument|E1 f
argument_list|)
operator|:
name|i
argument_list|(
argument|f
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
argument_list|(
argument|E2 f
argument_list|)
operator|:
name|i
argument_list|(
argument|f
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
argument_list|(
argument|QFlag f
argument_list|)
operator|:
name|i
argument_list|(
argument|f
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
argument_list|(
name|QFlags
operator|<
name|E1
operator|>
name|f
argument_list|)
operator|:
name|i
argument_list|(
argument|f.operator int()
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
argument_list|(
name|QFlags
operator|<
name|E2
operator|>
name|f
argument_list|)
operator|:
name|i
argument_list|(
argument|f.operator int()
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
argument_list|(
name|Zero
operator|=
literal|0
argument_list|)
operator|:
name|i
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|QUrlTwoFlags
operator|&
name|operator
operator|&=
operator|(
name|int
name|mask
operator|)
block|{
name|i
operator|&=
name|mask
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QUrlTwoFlags
operator|&
name|operator
operator|&=
operator|(
name|uint
name|mask
operator|)
block|{
name|i
operator|&=
name|mask
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QUrlTwoFlags
operator|&
name|operator
operator||=
operator|(
name|QUrlTwoFlags
name|f
operator|)
block|{
name|i
operator||=
name|f
operator|.
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QUrlTwoFlags
operator|&
name|operator
operator||=
operator|(
name|E1
name|f
operator|)
block|{
name|i
operator||=
name|f
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QUrlTwoFlags
operator|&
name|operator
operator||=
operator|(
name|E2
name|f
operator|)
block|{
name|i
operator||=
name|f
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QUrlTwoFlags
operator|&
name|operator
operator|^=
operator|(
name|QUrlTwoFlags
name|f
operator|)
block|{
name|i
operator|^=
name|f
operator|.
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QUrlTwoFlags
operator|&
name|operator
operator|^=
operator|(
name|E1
name|f
operator|)
block|{
name|i
operator|^=
name|f
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QUrlTwoFlags
operator|&
name|operator
operator|^=
operator|(
name|E2
name|f
operator|)
block|{
name|i
operator|^=
name|f
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|operator
name|QFlags
operator|<
name|E1
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|E1
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|operator
name|QFlags
operator|<
name|E2
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|E2
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
operator||
operator|(
name|QUrlTwoFlags
name|f
operator|)
specifier|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E1
argument_list|(
name|i
operator||
name|f
operator|.
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
operator||
operator|(
name|E1
name|f
operator|)
specifier|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E1
argument_list|(
name|i
operator||
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
operator||
operator|(
name|E2
name|f
operator|)
specifier|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E2
argument_list|(
name|i
operator||
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
modifier|^
argument_list|(
name|QUrlTwoFlags
name|f
argument_list|)
decl|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E1
argument_list|(
name|i
operator|^
name|f
operator|.
name|i
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
modifier|^
argument_list|(
name|E1
name|f
argument_list|)
decl|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E1
argument_list|(
name|i
operator|^
name|f
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
modifier|^
argument_list|(
name|E2
name|f
argument_list|)
decl|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E2
argument_list|(
name|i
operator|^
name|f
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
modifier|&
argument_list|(
name|int
name|mask
argument_list|)
decl|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E1
argument_list|(
name|i
operator|&
name|mask
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
modifier|&
argument_list|(
name|uint
name|mask
argument_list|)
decl|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E1
argument_list|(
name|i
operator|&
name|mask
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
modifier|&
argument_list|(
name|E1
name|f
argument_list|)
decl|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E1
argument_list|(
name|i
operator|&
name|f
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
modifier|&
argument_list|(
name|E2
name|f
argument_list|)
decl|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E2
argument_list|(
name|i
operator|&
name|f
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrlTwoFlags
name|operator
operator|~
operator|(
operator|)
specifier|const
block|{
return|return
name|QUrlTwoFlags
argument_list|(
name|E1
argument_list|(
operator|~
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|bool
name|testFlag
argument_list|(
name|E1
name|f
argument_list|)
decl|const
block|{
return|return
operator|(
name|i
operator|&
name|f
operator|)
operator|==
name|f
operator|&&
operator|(
name|f
operator|!=
literal|0
operator|||
name|i
operator|==
name|int
argument_list|(
name|f
argument_list|)
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|bool
name|testFlag
argument_list|(
name|E2
name|f
argument_list|)
decl|const
block|{
return|return
operator|(
name|i
operator|&
name|f
operator|)
operator|==
name|f
operator|&&
operator|(
name|f
operator|!=
literal|0
operator|||
name|i
operator|==
name|int
argument_list|(
name|f
argument_list|)
operator|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
unit|};
DECL|variable|E1
name|template
operator|<
name|typename
name|E1
operator|,
name|typename
name|E2
operator|>
DECL|variable|E1
DECL|variable|E1
DECL|variable|E2
DECL|variable|E1
name|class
name|QTypeInfo
operator|<
name|QUrlTwoFlags
operator|<
name|E1
operator|,
name|E2
operator|>
expr|>
operator|:
name|public
name|QTypeInfoMerger
operator|<
name|QUrlTwoFlags
operator|<
name|E1
operator|,
name|E2
operator|>
operator|,
name|E1
operator|,
name|E2
operator|>
block|{}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QUrl
block|{
name|public
label|:
enum|enum
name|ParsingMode
block|{
name|TolerantMode
block|,
name|StrictMode
block|,
name|DecodedMode
block|}
enum|;
comment|// encoding / toString values
enum|enum
name|UrlFormattingOption
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
comment|// 0x100 was a private code in Qt 4, keep unused for a while
name|PreferLocalFile
init|=
literal|0x200
block|,
name|StripTrailingSlash
init|=
literal|0x400
block|}
enum|;
enum|enum
name|ComponentFormattingOption
block|{
name|PrettyDecoded
init|=
literal|0x000000
block|,
name|EncodeSpaces
init|=
literal|0x100000
block|,
name|EncodeUnicode
init|=
literal|0x200000
block|,
name|EncodeDelimiters
init|=
literal|0x400000
operator||
literal|0x800000
block|,
name|EncodeReserved
init|=
literal|0x1000000
block|,
name|DecodeReserved
init|=
literal|0x2000000
block|,
comment|// 0x4000000 used to indicate full-decode mode
name|FullyEncoded
init|=
name|EncodeSpaces
operator||
name|EncodeUnicode
operator||
name|EncodeDelimiters
operator||
name|EncodeReserved
block|,
name|FullyDecoded
init|=
name|FullyEncoded
operator||
name|DecodeReserved
operator||
literal|0x4000000
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ComponentFormattingOptions
argument_list|,
argument|ComponentFormattingOption
argument_list|)
ifdef|#
directive|ifdef
name|Q_QDOC
name|Q_DECLARE_FLAGS
argument_list|(
argument|FormattingOptions
argument_list|,
argument|UrlFormattingOption
argument_list|)
else|#
directive|else
typedef|typedef
name|QUrlTwoFlags
operator|<
name|UrlFormattingOption
operator|,
name|ComponentFormattingOption
operator|>
name|FormattingOptions
expr_stmt|;
endif|#
directive|endif
name|QUrl
argument_list|()
expr_stmt|;
name|QUrl
argument_list|(
specifier|const
name|QUrl
operator|&
name|copy
argument_list|)
expr_stmt|;
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
ifdef|#
directive|ifdef
name|QT_NO_URL_CAST_FROM_STRING
name|explicit
name|QUrl
parameter_list|(
specifier|const
name|QString
modifier|&
name|url
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
else|#
directive|else
name|QUrl
argument_list|(
argument|const QString&url
argument_list|,
argument|ParsingMode mode = TolerantMode
argument_list|)
empty_stmt|;
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QUrl
argument_list|(
name|QUrl
operator|&&
name|other
argument_list|)
operator|:
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|; }
specifier|inline
name|QUrl
operator|&
name|operator
operator|=
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
endif|#
directive|endif
operator|~
name|QUrl
argument_list|()
expr_stmt|;
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
init|=
name|TolerantMode
parameter_list|)
function_decl|;
name|QString
name|url
argument_list|(
name|FormattingOptions
name|options
operator|=
name|FormattingOptions
argument_list|(
name|PrettyDecoded
argument_list|)
argument_list|)
decl|const
decl_stmt|;
name|QString
name|toString
argument_list|(
name|FormattingOptions
name|options
operator|=
name|FormattingOptions
argument_list|(
name|PrettyDecoded
argument_list|)
argument_list|)
decl|const
decl_stmt|;
name|QString
name|toDisplayString
argument_list|(
name|FormattingOptions
name|options
operator|=
name|FormattingOptions
argument_list|(
name|PrettyDecoded
argument_list|)
argument_list|)
decl|const
decl_stmt|;
name|QUrl
name|adjusted
argument_list|(
name|FormattingOptions
name|options
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|toEncoded
argument_list|(
name|FormattingOptions
name|options
operator|=
name|FullyEncoded
argument_list|)
decl|const
decl_stmt|;
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
init|=
name|TolerantMode
parameter_list|)
function_decl|;
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
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|setScheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|scheme
parameter_list|)
function_decl|;
name|QString
name|scheme
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAuthority
parameter_list|(
specifier|const
name|QString
modifier|&
name|authority
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
name|QString
name|authority
argument_list|(
name|ComponentFormattingOptions
name|options
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|void
name|setUserInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|userInfo
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
name|QString
name|userInfo
argument_list|(
name|ComponentFormattingOptions
name|options
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|void
name|setUserName
parameter_list|(
specifier|const
name|QString
modifier|&
name|userName
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
name|QString
name|userName
argument_list|(
name|ComponentFormattingOptions
name|options
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|void
name|setPassword
parameter_list|(
specifier|const
name|QString
modifier|&
name|password
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
name|QString
name|password
argument_list|(
name|ComponentFormattingOptions
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|void
name|setHost
parameter_list|(
specifier|const
name|QString
modifier|&
name|host
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
name|QString
name|host
argument_list|(
name|ComponentFormattingOptions
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|QString
name|topLevelDomain
argument_list|(
name|ComponentFormattingOptions
name|options
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|void
name|setPort
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
name|int
name|port
argument_list|(
name|int
name|defaultPort
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|void
name|setPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
name|QString
name|path
argument_list|(
name|ComponentFormattingOptions
name|options
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasQuery
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
name|void
name|setQuery
parameter_list|(
specifier|const
name|QUrlQuery
modifier|&
name|query
parameter_list|)
function_decl|;
name|QString
name|query
argument_list|(
name|ComponentFormattingOptions
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasFragment
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|fragment
argument_list|(
name|ComponentFormattingOptions
name|options
operator|=
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|void
name|setFragment
parameter_list|(
specifier|const
name|QString
modifier|&
name|fragment
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
function_decl|;
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
name|bool
name|isRelative
argument_list|()
specifier|const
expr_stmt|;
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
name|bool
name|isLocalFile
argument_list|()
specifier|const
expr_stmt|;
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
name|QString
name|toLocalFile
argument_list|()
specifier|const
expr_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
name|bool
name|isDetached
argument_list|()
specifier|const
expr_stmt|;
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
specifier|static
name|QString
name|fromPercentEncoding
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
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
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|static
name|QString
name|fromPunycode
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|punycode
parameter_list|)
block|{
return|return
name|fromAce
argument_list|(
name|punycode
argument_list|)
return|;
block|}
name|QT_DEPRECATED
specifier|static
name|QByteArray
name|toPunycode
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
block|{
return|return
name|toAce
argument_list|(
name|string
argument_list|)
return|;
block|}
name|QT_DEPRECATED
specifier|inline
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
name|qry
argument_list|)
decl_stmt|;
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
name|void
name|removeQueryItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
name|QT_DEPRECATED
specifier|inline
name|void
name|removeAllQueryItems
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
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
name|QT_DEPRECATED
specifier|inline
name|void
name|removeEncodedQueryItem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
function_decl|;
name|QT_DEPRECATED
specifier|inline
name|void
name|removeAllEncodedQueryItems
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
function_decl|;
name|QT_DEPRECATED
name|void
name|setEncodedUrl
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|u
parameter_list|,
name|ParsingMode
name|mode
init|=
name|TolerantMode
parameter_list|)
block|{
name|setUrl
argument_list|(
name|fromEncodedComponent_helper
argument_list|(
name|u
argument_list|)
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
name|QT_DEPRECATED
name|QByteArray
name|encodedUserName
argument_list|()
specifier|const
block|{
return|return
name|userName
argument_list|(
name|FullyEncoded
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
name|QT_DEPRECATED
name|void
name|setEncodedUserName
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|setUserName
argument_list|(
name|fromEncodedComponent_helper
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QT_DEPRECATED
name|QByteArray
name|encodedPassword
argument_list|()
specifier|const
block|{
return|return
name|password
argument_list|(
name|FullyEncoded
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
name|QT_DEPRECATED
name|void
name|setEncodedPassword
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|setPassword
argument_list|(
name|fromEncodedComponent_helper
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QT_DEPRECATED
name|QByteArray
name|encodedHost
argument_list|()
specifier|const
block|{
return|return
name|host
argument_list|(
name|FullyEncoded
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
name|QT_DEPRECATED
name|void
name|setEncodedHost
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|setHost
argument_list|(
name|fromEncodedComponent_helper
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QT_DEPRECATED
name|QByteArray
name|encodedPath
argument_list|()
specifier|const
block|{
return|return
name|path
argument_list|(
name|FullyEncoded
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
name|QT_DEPRECATED
name|void
name|setEncodedPath
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|setPath
argument_list|(
name|fromEncodedComponent_helper
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QT_DEPRECATED
name|QByteArray
name|encodedQuery
argument_list|()
specifier|const
block|{
return|return
name|toLatin1_helper
argument_list|(
name|query
argument_list|(
name|FullyEncoded
argument_list|)
argument_list|)
return|;
block|}
name|QT_DEPRECATED
name|void
name|setEncodedQuery
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|setQuery
argument_list|(
name|fromEncodedComponent_helper
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QT_DEPRECATED
name|QByteArray
name|encodedFragment
argument_list|()
specifier|const
block|{
return|return
name|toLatin1_helper
argument_list|(
name|fragment
argument_list|(
name|FullyEncoded
argument_list|)
argument_list|)
return|;
block|}
name|QT_DEPRECATED
name|void
name|setEncodedFragment
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|setFragment
argument_list|(
name|fromEncodedComponent_helper
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|private
label|:
comment|// helper function for the encodedQuery and encodedFragment functions
specifier|static
name|QByteArray
name|toLatin1_helper
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
block|{
if|if
condition|(
name|string
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|string
operator|.
name|isNull
argument_list|()
condition|?
name|QByteArray
argument_list|()
else|:
name|QByteArray
argument_list|(
literal|""
argument_list|)
return|;
return|return
name|string
operator|.
name|toLatin1
argument_list|()
return|;
block|}
endif|#
directive|endif
name|private
label|:
specifier|static
name|QString
name|fromEncodedComponent_helper
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
function_decl|;
name|public
label|:
specifier|static
name|QString
name|fromAce
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|toAce
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|idnWhitelist
parameter_list|()
function_decl|;
specifier|static
name|QStringList
name|toStringList
argument_list|(
specifier|const
name|QList
operator|<
name|QUrl
operator|>
operator|&
name|uris
argument_list|,
name|FormattingOptions
name|options
operator|=
name|FormattingOptions
argument_list|(
name|PrettyDecoded
argument_list|)
argument_list|)
decl_stmt|;
specifier|static
name|QList
operator|<
name|QUrl
operator|>
name|fromStringList
argument_list|(
argument|const QStringList&uris
argument_list|,
argument|ParsingMode mode = TolerantMode
argument_list|)
expr_stmt|;
specifier|static
name|void
name|setIdnWhitelist
parameter_list|(
specifier|const
name|QStringList
modifier|&
parameter_list|)
function_decl|;
name|friend
name|Q_CORE_EXPORT
name|uint
name|qHash
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|,
name|uint
name|seed
operator|=
literal|0
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|private
label|:
name|QUrlPrivate
modifier|*
name|d
decl_stmt|;
name|friend
name|class
name|QUrlQuery
decl_stmt|;
name|public
label|:
typedef|typedef
name|QUrlPrivate
modifier|*
name|DataPtr
typedef|;
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
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QUrl
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QUrl::ComponentFormattingOptions
argument_list|)
end_macro
begin_comment
comment|//Q_DECLARE_OPERATORS_FOR_FLAGS(QUrl::FormattingOptions)
end_comment
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|UrlFormattingOption
name|f1
operator|,
name|QUrl
operator|::
name|UrlFormattingOption
name|f2
operator|)
block|{
return|return
name|QUrl
operator|::
name|FormattingOptions
argument_list|(
name|f1
argument_list|)
operator||
name|f2
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|UrlFormattingOption
name|f1
operator|,
name|QUrl
operator|::
name|FormattingOptions
name|f2
operator|)
block|{
return|return
name|f2
operator||
name|f1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
name|Q_DECL_CONSTEXPR
specifier|inline
name|QIncompatibleFlag
name|operator
operator||
operator|(
name|QUrl
operator|::
name|UrlFormattingOption
name|f1
operator|,
name|int
name|f2
operator|)
block|{
return|return
name|QIncompatibleFlag
argument_list|(
name|int
argument_list|(
name|f1
argument_list|)
operator||
name|f2
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// add operators for OR'ing the two types of flags
end_comment
begin_expr_stmt
DECL|variable|operator
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
operator|&
name|operator
operator||=
operator|(
name|QUrl
operator|::
name|FormattingOptions
operator|&
name|i
operator|,
name|QUrl
operator|::
name|ComponentFormattingOptions
name|f
operator|)
block|{
name|i
operator||=
name|QUrl
operator|::
name|UrlFormattingOption
argument_list|(
name|int
argument_list|(
name|f
argument_list|)
argument_list|)
block|;
return|return
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|UrlFormattingOption
name|i
operator|,
name|QUrl
operator|::
name|ComponentFormattingOption
name|f
operator|)
block|{
return|return
name|i
operator||
name|QUrl
operator|::
name|UrlFormattingOption
argument_list|(
name|int
argument_list|(
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|UrlFormattingOption
name|i
operator|,
name|QUrl
operator|::
name|ComponentFormattingOptions
name|f
operator|)
block|{
return|return
name|i
operator||
name|QUrl
operator|::
name|UrlFormattingOption
argument_list|(
name|int
argument_list|(
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|ComponentFormattingOption
name|f
operator|,
name|QUrl
operator|::
name|UrlFormattingOption
name|i
operator|)
block|{
return|return
name|i
operator||
name|QUrl
operator|::
name|UrlFormattingOption
argument_list|(
name|int
argument_list|(
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|ComponentFormattingOptions
name|f
operator|,
name|QUrl
operator|::
name|UrlFormattingOption
name|i
operator|)
block|{
return|return
name|i
operator||
name|QUrl
operator|::
name|UrlFormattingOption
argument_list|(
name|int
argument_list|(
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|FormattingOptions
name|i
operator|,
name|QUrl
operator|::
name|ComponentFormattingOptions
name|f
operator|)
block|{
return|return
name|i
operator||
name|QUrl
operator|::
name|UrlFormattingOption
argument_list|(
name|int
argument_list|(
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|ComponentFormattingOption
name|f
operator|,
name|QUrl
operator|::
name|FormattingOptions
name|i
operator|)
block|{
return|return
name|i
operator||
name|QUrl
operator|::
name|UrlFormattingOption
argument_list|(
name|int
argument_list|(
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QUrl
operator|::
name|FormattingOptions
name|operator
operator||
operator|(
name|QUrl
operator|::
name|ComponentFormattingOptions
name|f
operator|,
name|QUrl
operator|::
name|FormattingOptions
name|i
operator|)
block|{
return|return
name|i
operator||
name|QUrl
operator|::
name|UrlFormattingOption
argument_list|(
name|int
argument_list|(
name|f
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|//inline QUrl::UrlFormattingOption&operator=(const QUrl::UrlFormattingOption&i, QUrl::ComponentFormattingOptions f)
end_comment
begin_comment
comment|//{ i = int(f); f; }
end_comment
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qurlquery.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QURL_H
end_comment
end_unit
