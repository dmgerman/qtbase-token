begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Intel Corporation. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QURLQUERY_H
end_ifndef
begin_define
DECL|macro|QURLQUERY_H
define|#
directive|define
name|QURLQUERY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qurl.h>
end_include
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
file|<QtCore/qstringlist.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QUrlQueryPrivate
name|class
name|QUrlQueryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QUrlQuery
block|{
name|public
label|:
name|QUrlQuery
argument_list|()
expr_stmt|;
name|explicit
name|QUrlQuery
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
name|explicit
name|QUrlQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|queryString
parameter_list|)
function_decl|;
name|QUrlQuery
argument_list|(
specifier|const
name|QUrlQuery
operator|&
name|other
argument_list|)
expr_stmt|;
name|QUrlQuery
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QUrlQuery
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QUrlQuery
modifier|&
name|operator
init|=
operator|(
name|QUrlQuery
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
name|QUrlQuery
argument_list|()
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QUrlQuery
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QUrlQuery
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|void
name|swap
parameter_list|(
name|QUrlQuery
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
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDetached
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|QString
name|query
argument_list|(
name|QUrl
operator|::
name|ComponentFormattingOptions
name|encoding
operator|=
name|QUrl
operator|::
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|void
name|setQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|queryString
parameter_list|)
function_decl|;
name|QString
name|toString
argument_list|(
name|QUrl
operator|::
name|ComponentFormattingOptions
name|encoding
operator|=
name|QUrl
operator|::
name|PrettyDecoded
argument_list|)
decl|const
block|{
return|return
name|query
argument_list|(
name|encoding
argument_list|)
return|;
block|}
name|void
name|setQueryDelimiters
parameter_list|(
name|QChar
name|valueDelimiter
parameter_list|,
name|QChar
name|pairDelimiter
parameter_list|)
function_decl|;
name|QChar
name|queryValueDelimiter
argument_list|()
specifier|const
expr_stmt|;
name|QChar
name|queryPairDelimiter
argument_list|()
specifier|const
expr_stmt|;
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
argument_list|(
argument|QUrl::ComponentFormattingOptions encoding = QUrl::PrettyDecoded
argument_list|)
specifier|const
expr_stmt|;
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
name|void
name|removeQueryItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
name|QString
name|queryItemValue
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
name|QUrl
operator|::
name|ComponentFormattingOptions
name|encoding
operator|=
name|QUrl
operator|::
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|allQueryItemValues
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
name|QUrl
operator|::
name|ComponentFormattingOptions
name|encoding
operator|=
name|QUrl
operator|::
name|PrettyDecoded
argument_list|)
decl|const
decl_stmt|;
name|void
name|removeAllQueryItems
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
specifier|static
name|QChar
name|defaultQueryValueDelimiter
parameter_list|()
block|{
return|return
name|QChar
argument_list|(
name|ushort
argument_list|(
literal|'='
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|QChar
name|defaultQueryPairDelimiter
parameter_list|()
block|{
return|return
name|QChar
argument_list|(
name|ushort
argument_list|(
literal|'&'
argument_list|)
argument_list|)
return|;
block|}
name|private
label|:
name|friend
name|class
name|QUrl
decl_stmt|;
name|QSharedDataPointer
operator|<
name|QUrlQueryPrivate
operator|>
name|d
expr_stmt|;
name|public
label|:
typedef|typedef
name|QSharedDataPointer
operator|<
name|QUrlQueryPrivate
operator|>
name|DataPtr
expr_stmt|;
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
argument|QUrlQuery
argument_list|)
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
begin_expr_stmt
specifier|inline
name|void
name|QUrl
operator|::
name|setQueryItems
argument_list|(
argument|const QList<QPair<QString
argument_list|,
argument|QString>>&qry
argument_list|)
block|{
name|QUrlQuery
name|q
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|q
operator|.
name|setQueryItems
argument_list|(
name|qry
argument_list|)
block|;
name|setQuery
argument_list|(
name|q
argument_list|)
block|; }
DECL|function|addQueryItem
specifier|inline
name|void
name|QUrl
operator|::
name|addQueryItem
argument_list|(
argument|const QString&key
argument_list|,
argument|const QString&value
argument_list|)
block|{
name|QUrlQuery
name|q
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|q
operator|.
name|addQueryItem
argument_list|(
name|key
argument_list|,
name|value
argument_list|)
block|;
name|setQuery
argument_list|(
name|q
argument_list|)
block|; }
DECL|variable|QString
DECL|function|queryItems
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
name|QUrl
operator|::
name|queryItems
argument_list|()
specifier|const
block|{
return|return
name|QUrlQuery
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|queryItems
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|hasQueryItem
specifier|inline
name|bool
name|QUrl
operator|::
name|hasQueryItem
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|{
return|return
name|QUrlQuery
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|hasQueryItem
argument_list|(
name|key
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|queryItemValue
specifier|inline
name|QString
name|QUrl
operator|::
name|queryItemValue
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|{
return|return
name|QUrlQuery
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|queryItemValue
argument_list|(
name|key
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|allQueryItemValues
specifier|inline
name|QStringList
name|QUrl
operator|::
name|allQueryItemValues
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|{
return|return
name|QUrlQuery
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|allQueryItemValues
argument_list|(
name|key
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|removeQueryItem
specifier|inline
name|void
name|QUrl
operator|::
name|removeQueryItem
argument_list|(
argument|const QString&key
argument_list|)
block|{
name|QUrlQuery
name|q
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|q
operator|.
name|removeQueryItem
argument_list|(
name|key
argument_list|)
block|;
name|setQuery
argument_list|(
name|q
argument_list|)
block|; }
DECL|function|removeAllQueryItems
specifier|inline
name|void
name|QUrl
operator|::
name|removeAllQueryItems
argument_list|(
argument|const QString&key
argument_list|)
block|{
name|QUrlQuery
name|q
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|q
operator|.
name|removeAllQueryItems
argument_list|(
name|key
argument_list|)
block|; }
DECL|function|addEncodedQueryItem
specifier|inline
name|void
name|QUrl
operator|::
name|addEncodedQueryItem
argument_list|(
argument|const QByteArray&key
argument_list|,
argument|const QByteArray&value
argument_list|)
block|{
name|QUrlQuery
name|q
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|q
operator|.
name|addQueryItem
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|key
argument_list|)
argument_list|,
name|QString
operator|::
name|fromUtf8
argument_list|(
name|value
argument_list|)
argument_list|)
block|;
name|setQuery
argument_list|(
name|q
argument_list|)
block|; }
DECL|function|hasEncodedQueryItem
specifier|inline
name|bool
name|QUrl
operator|::
name|hasEncodedQueryItem
argument_list|(
argument|const QByteArray&key
argument_list|)
specifier|const
block|{
return|return
name|QUrlQuery
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|hasQueryItem
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|key
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|encodedQueryItemValue
specifier|inline
name|QByteArray
name|QUrl
operator|::
name|encodedQueryItemValue
argument_list|(
argument|const QByteArray&key
argument_list|)
specifier|const
block|{
return|return
name|QUrlQuery
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|queryItemValue
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|key
argument_list|)
argument_list|,
name|QUrl
operator|::
name|FullyEncoded
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|removeEncodedQueryItem
specifier|inline
name|void
name|QUrl
operator|::
name|removeEncodedQueryItem
argument_list|(
argument|const QByteArray&key
argument_list|)
block|{
name|QUrlQuery
name|q
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|q
operator|.
name|removeQueryItem
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|key
argument_list|)
argument_list|)
block|;
name|setQuery
argument_list|(
name|q
argument_list|)
block|; }
DECL|function|removeAllEncodedQueryItems
specifier|inline
name|void
name|QUrl
operator|::
name|removeAllEncodedQueryItems
argument_list|(
argument|const QByteArray&key
argument_list|)
block|{
name|QUrlQuery
name|q
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|q
operator|.
name|removeAllQueryItems
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|key
argument_list|)
argument_list|)
block|; }
DECL|function|setEncodedQueryItems
specifier|inline
name|void
name|QUrl
operator|::
name|setEncodedQueryItems
argument_list|(
argument|const QList<QPair<QByteArray
argument_list|,
argument|QByteArray>>&qry
argument_list|)
block|{
name|QUrlQuery
name|q
block|;
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
block|,
name|QByteArray
operator|>
expr|>
operator|::
name|ConstIterator
name|it
operator|=
name|qry
operator|.
name|constBegin
argument_list|()
block|;
for|for
control|(
init|;
name|it
operator|!=
name|qry
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
name|q
operator|.
name|addQueryItem
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|it
operator|->
name|first
argument_list|)
argument_list|,
name|QString
operator|::
name|fromUtf8
argument_list|(
name|it
operator|->
name|second
argument_list|)
argument_list|)
expr_stmt|;
name|setQuery
argument_list|(
name|q
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|} inline
DECL|variable|QByteArray
DECL|function|encodedQueryItems
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
expr|>
name|QUrl
operator|::
name|encodedQueryItems
argument_list|()
specifier|const
block|{
name|QList
operator|<
name|QPair
operator|<
name|QString
block|,
name|QString
operator|>
expr|>
name|items
operator|=
name|QUrlQuery
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|queryItems
argument_list|(
name|QUrl
operator|::
name|FullyEncoded
argument_list|)
block|;
name|QList
operator|<
name|QPair
operator|<
name|QString
block|,
name|QString
operator|>
expr|>
operator|::
name|ConstIterator
name|it
operator|=
name|items
operator|.
name|constBegin
argument_list|()
block|;
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
block|,
name|QByteArray
operator|>
expr|>
name|result
block|;
name|result
operator|.
name|reserve
argument_list|(
name|items
operator|.
name|size
argument_list|()
argument_list|)
block|;
for|for
control|(
init|;
name|it
operator|!=
name|items
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
name|result
operator|<<
name|qMakePair
argument_list|(
name|it
operator|->
name|first
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|it
operator|->
name|second
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|result
return|;
end_return
begin_expr_stmt
unit|} inline
DECL|function|allEncodedQueryItemValues
name|QList
operator|<
name|QByteArray
operator|>
name|QUrl
operator|::
name|allEncodedQueryItemValues
argument_list|(
argument|const QByteArray&key
argument_list|)
specifier|const
block|{
name|QStringList
name|items
operator|=
name|QUrlQuery
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|allQueryItemValues
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|key
argument_list|)
argument_list|,
name|QUrl
operator|::
name|FullyEncoded
argument_list|)
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|result
block|;
name|result
operator|.
name|reserve
argument_list|(
name|items
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|Q_FOREACH
argument_list|(
argument|const QString&item
argument_list|,
argument|items
argument_list|)
name|result
operator|<<
name|item
operator|.
name|toLatin1
argument_list|()
block|;
return|return
name|result
return|;
block|}
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
comment|// QURLQUERY_H
end_comment
end_unit
