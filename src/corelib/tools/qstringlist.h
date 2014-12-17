begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTRINGLIST_H
end_ifndef
begin_define
DECL|macro|QSTRINGLIST_H
define|#
directive|define
name|QSTRINGLIST_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qalgorithms.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qregexp.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringmatcher.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRegExp
name|class
name|QRegExp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegularExpression
name|class
name|QRegularExpression
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QStringListIterator
typedef|typedef
name|QListIterator
operator|<
name|QString
operator|>
name|QStringListIterator
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QMutableStringListIterator
typedef|typedef
name|QMutableListIterator
operator|<
name|QString
operator|>
name|QMutableStringListIterator
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QStringList
range|:
name|public
name|QList
operator|<
name|QString
operator|>
block|{
name|public
operator|:
specifier|inline
name|QStringList
argument_list|()
block|{ }
specifier|inline
name|explicit
name|QStringList
argument_list|(
argument|const QString&i
argument_list|)
block|{
name|append
argument_list|(
name|i
argument_list|)
block|; }
specifier|inline
name|QStringList
argument_list|(
specifier|const
name|QList
operator|<
name|QString
operator|>
operator|&
name|l
argument_list|)
operator|:
name|QList
operator|<
name|QString
operator|>
operator|(
name|l
operator|)
block|{ }
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QStringList
argument_list|(
name|QList
operator|<
name|QString
operator|>
operator|&&
name|l
argument_list|)
operator|:
name|QList
operator|<
name|QString
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|l
argument_list|)
operator|)
block|{ }
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
specifier|inline
name|QStringList
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|QString
operator|>
name|args
argument_list|)
operator|:
name|QList
operator|<
name|QString
operator|>
operator|(
name|args
operator|)
block|{ }
endif|#
directive|endif
name|QStringList
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QList
operator|<
name|QString
operator|>
operator|&
name|other
operator|)
block|{
name|QList
operator|<
name|QString
operator|>
operator|::
name|operator
operator|=
operator|(
name|other
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QStringList
operator|&
name|operator
operator|=
operator|(
name|QList
operator|<
name|QString
operator|>
operator|&&
name|other
operator|)
block|{
name|QList
operator|<
name|QString
operator|>
operator|::
name|operator
operator|=
operator|(
name|std
operator|::
name|move
argument_list|(
name|other
argument_list|)
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|sort
argument_list|(
argument|Qt::CaseSensitivity cs = Qt::CaseSensitive
argument_list|)
block|;
specifier|inline
name|int
name|removeDuplicates
argument_list|()
block|;
specifier|inline
name|QString
name|join
argument_list|(
argument|const QString&sep
argument_list|)
specifier|const
block|;
specifier|inline
name|QString
name|join
argument_list|(
argument|QChar sep
argument_list|)
specifier|const
block|;
specifier|inline
name|QStringList
name|filter
argument_list|(
argument|const QString&str
argument_list|,
argument|Qt::CaseSensitivity cs = Qt::CaseSensitive
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|contains
argument_list|(
argument|const QString&str
argument_list|,
argument|Qt::CaseSensitivity cs = Qt::CaseSensitive
argument_list|)
specifier|const
block|;
specifier|inline
name|QStringList
operator|&
name|replaceInStrings
argument_list|(
argument|const QString&before
argument_list|,
argument|const QString&after
argument_list|,
argument|Qt::CaseSensitivity cs = Qt::CaseSensitive
argument_list|)
block|;
specifier|inline
name|QStringList
name|operator
operator|+
operator|(
specifier|const
name|QStringList
operator|&
name|other
operator|)
specifier|const
block|{
name|QStringList
name|n
operator|=
operator|*
name|this
block|;
name|n
operator|+=
name|other
block|;
return|return
name|n
return|;
block|}
specifier|inline
name|QStringList
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QString
operator|&
name|str
operator|)
block|{
name|append
argument_list|(
name|str
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QStringList
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QStringList
operator|&
name|l
operator|)
block|{
operator|*
name|this
operator|+=
name|l
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QStringList
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QList
operator|<
name|QString
operator|>
operator|&
name|l
operator|)
block|{
operator|*
name|this
operator|+=
name|l
block|;
return|return
operator|*
name|this
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
specifier|inline
name|QStringList
name|filter
argument_list|(
argument|const QRegExp&rx
argument_list|)
specifier|const
block|;
specifier|inline
name|QStringList
operator|&
name|replaceInStrings
argument_list|(
specifier|const
name|QRegExp
operator|&
name|rx
argument_list|,
specifier|const
name|QString
operator|&
name|after
argument_list|)
block|;
specifier|inline
name|int
name|indexOf
argument_list|(
argument|const QRegExp&rx
argument_list|,
argument|int from =
literal|0
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|lastIndexOf
argument_list|(
argument|const QRegExp&rx
argument_list|,
argument|int from = -
literal|1
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|indexOf
argument_list|(
argument|QRegExp&rx
argument_list|,
argument|int from =
literal|0
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|lastIndexOf
argument_list|(
argument|QRegExp&rx
argument_list|,
argument|int from = -
literal|1
argument_list|)
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
ifndef|#
directive|ifndef
name|QT_NO_REGULAREXPRESSION
specifier|inline
name|QStringList
name|filter
argument_list|(
argument|const QRegularExpression&re
argument_list|)
specifier|const
block|;
specifier|inline
name|QStringList
operator|&
name|replaceInStrings
argument_list|(
specifier|const
name|QRegularExpression
operator|&
name|re
argument_list|,
specifier|const
name|QString
operator|&
name|after
argument_list|)
block|;
specifier|inline
name|int
name|indexOf
argument_list|(
argument|const QRegularExpression&re
argument_list|,
argument|int from =
literal|0
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|lastIndexOf
argument_list|(
argument|const QRegularExpression&re
argument_list|,
argument|int from = -
literal|1
argument_list|)
specifier|const
block|;
endif|#
directive|endif
comment|// QT_NO_REGULAREXPRESSION
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
name|using
name|QList
operator|<
name|QString
operator|>
operator|::
name|indexOf
block|;
name|using
name|QList
operator|<
name|QString
operator|>
operator|::
name|lastIndexOf
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QStringList
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|namespace
name|QtPrivate
block|{
name|void
name|Q_CORE_EXPORT
name|QStringList_sort
argument_list|(
name|QStringList
operator|*
name|that
argument_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
argument_list|)
decl_stmt|;
name|int
name|Q_CORE_EXPORT
name|QStringList_removeDuplicates
parameter_list|(
name|QStringList
modifier|*
name|that
parameter_list|)
function_decl|;
name|QString
name|Q_CORE_EXPORT
name|QStringList_join
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QChar
modifier|*
name|sep
parameter_list|,
name|int
name|seplen
parameter_list|)
function_decl|;
name|QStringList
name|Q_CORE_EXPORT
name|QStringList_filter
argument_list|(
specifier|const
name|QStringList
operator|*
name|that
argument_list|,
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
argument_list|)
decl_stmt|;
name|bool
name|Q_CORE_EXPORT
name|QStringList_contains
argument_list|(
specifier|const
name|QStringList
operator|*
name|that
argument_list|,
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
argument_list|)
decl_stmt|;
name|void
name|Q_CORE_EXPORT
name|QStringList_replaceInStrings
argument_list|(
name|QStringList
operator|*
name|that
argument_list|,
specifier|const
name|QString
operator|&
name|before
argument_list|,
specifier|const
name|QString
operator|&
name|after
argument_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
name|void
name|Q_CORE_EXPORT
name|QStringList_replaceInStrings
parameter_list|(
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegExp
modifier|&
name|rx
parameter_list|,
specifier|const
name|QString
modifier|&
name|after
parameter_list|)
function_decl|;
name|QStringList
name|Q_CORE_EXPORT
name|QStringList_filter
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegExp
modifier|&
name|re
parameter_list|)
function_decl|;
name|int
name|Q_CORE_EXPORT
name|QStringList_indexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
name|int
name|Q_CORE_EXPORT
name|QStringList_lastIndexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
name|int
name|Q_CORE_EXPORT
name|QStringList_indexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
name|int
name|Q_CORE_EXPORT
name|QStringList_lastIndexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
ifndef|#
directive|ifndef
name|QT_NO_REGULAREXPRESSION
name|void
name|Q_CORE_EXPORT
name|QStringList_replaceInStrings
parameter_list|(
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegularExpression
modifier|&
name|rx
parameter_list|,
specifier|const
name|QString
modifier|&
name|after
parameter_list|)
function_decl|;
name|QStringList
name|Q_CORE_EXPORT
name|QStringList_filter
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegularExpression
modifier|&
name|re
parameter_list|)
function_decl|;
name|int
name|Q_CORE_EXPORT
name|QStringList_indexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegularExpression
modifier|&
name|re
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
name|int
name|Q_CORE_EXPORT
name|QStringList_lastIndexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegularExpression
modifier|&
name|re
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// QT_NO_REGULAREXPRESSION
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
block|}
end_decl_stmt
begin_expr_stmt
DECL|function|sort
specifier|inline
name|void
name|QStringList
operator|::
name|sort
argument_list|(
argument|Qt::CaseSensitivity cs
argument_list|)
block|{
name|QtPrivate
operator|::
name|QStringList_sort
argument_list|(
name|this
argument_list|,
name|cs
argument_list|)
block|; }
DECL|function|removeDuplicates
specifier|inline
name|int
name|QStringList
operator|::
name|removeDuplicates
argument_list|()
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_removeDuplicates
argument_list|(
name|this
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|join
specifier|inline
name|QString
name|QStringList
operator|::
name|join
argument_list|(
argument|const QString&sep
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_join
argument_list|(
name|this
argument_list|,
name|sep
operator|.
name|constData
argument_list|()
argument_list|,
name|sep
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|join
specifier|inline
name|QString
name|QStringList
operator|::
name|join
argument_list|(
argument|QChar sep
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_join
argument_list|(
name|this
argument_list|,
operator|&
name|sep
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|filter
specifier|inline
name|QStringList
name|QStringList
operator|::
name|filter
argument_list|(
argument|const QString&str
argument_list|,
argument|Qt::CaseSensitivity cs
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_filter
argument_list|(
name|this
argument_list|,
name|str
argument_list|,
name|cs
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|contains
specifier|inline
name|bool
name|QStringList
operator|::
name|contains
argument_list|(
argument|const QString&str
argument_list|,
argument|Qt::CaseSensitivity cs
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_contains
argument_list|(
name|this
argument_list|,
name|str
argument_list|,
name|cs
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|replaceInStrings
specifier|inline
name|QStringList
operator|&
name|QStringList
operator|::
name|replaceInStrings
argument_list|(
argument|const QString&before
argument_list|,
argument|const QString&after
argument_list|,
argument|Qt::CaseSensitivity cs
argument_list|)
block|{
name|QtPrivate
operator|::
name|QStringList_replaceInStrings
argument_list|(
name|this
argument_list|,
name|before
argument_list|,
name|after
argument_list|,
name|cs
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_expr_stmt
DECL|function|replaceInStrings
specifier|inline
name|QStringList
operator|&
name|QStringList
operator|::
name|replaceInStrings
argument_list|(
argument|const QRegExp&rx
argument_list|,
argument|const QString&after
argument_list|)
block|{
name|QtPrivate
operator|::
name|QStringList_replaceInStrings
argument_list|(
name|this
argument_list|,
name|rx
argument_list|,
name|after
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|filter
specifier|inline
name|QStringList
name|QStringList
operator|::
name|filter
argument_list|(
argument|const QRegExp&rx
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_filter
argument_list|(
name|this
argument_list|,
name|rx
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|indexOf
specifier|inline
name|int
name|QStringList
operator|::
name|indexOf
argument_list|(
argument|const QRegExp&rx
argument_list|,
argument|int from
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_indexOf
argument_list|(
name|this
argument_list|,
name|rx
argument_list|,
name|from
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|lastIndexOf
specifier|inline
name|int
name|QStringList
operator|::
name|lastIndexOf
argument_list|(
argument|const QRegExp&rx
argument_list|,
argument|int from
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_lastIndexOf
argument_list|(
name|this
argument_list|,
name|rx
argument_list|,
name|from
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|indexOf
specifier|inline
name|int
name|QStringList
operator|::
name|indexOf
argument_list|(
argument|QRegExp&rx
argument_list|,
argument|int from
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_indexOf
argument_list|(
name|this
argument_list|,
name|rx
argument_list|,
name|from
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|lastIndexOf
specifier|inline
name|int
name|QStringList
operator|::
name|lastIndexOf
argument_list|(
argument|QRegExp&rx
argument_list|,
argument|int from
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_lastIndexOf
argument_list|(
name|this
argument_list|,
name|rx
argument_list|,
name|from
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGULAREXPRESSION
end_ifndef
begin_expr_stmt
DECL|function|replaceInStrings
specifier|inline
name|QStringList
operator|&
name|QStringList
operator|::
name|replaceInStrings
argument_list|(
argument|const QRegularExpression&rx
argument_list|,
argument|const QString&after
argument_list|)
block|{
name|QtPrivate
operator|::
name|QStringList_replaceInStrings
argument_list|(
name|this
argument_list|,
name|rx
argument_list|,
name|after
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|filter
specifier|inline
name|QStringList
name|QStringList
operator|::
name|filter
argument_list|(
argument|const QRegularExpression&rx
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_filter
argument_list|(
name|this
argument_list|,
name|rx
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|indexOf
specifier|inline
name|int
name|QStringList
operator|::
name|indexOf
argument_list|(
argument|const QRegularExpression&rx
argument_list|,
argument|int from
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_indexOf
argument_list|(
name|this
argument_list|,
name|rx
argument_list|,
name|from
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|lastIndexOf
specifier|inline
name|int
name|QStringList
operator|::
name|lastIndexOf
argument_list|(
argument|const QRegularExpression&rx
argument_list|,
argument|int from
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QStringList_lastIndexOf
argument_list|(
name|this
argument_list|,
name|rx
argument_list|,
name|from
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_REGULAREXPRESSION
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_BOOTSTRAPPED
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QStringList
operator|&
name|list
operator|)
block|{
return|return
name|operator
operator|>>
operator|(
name|in
operator|,
name|static_cast
operator|<
name|QList
operator|<
name|QString
operator|>
operator|&
operator|>
operator|(
name|list
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QStringList
operator|&
name|list
operator|)
block|{
return|return
name|operator
operator|<<
operator|(
name|out
operator|,
name|static_cast
operator|<
specifier|const
name|QList
operator|<
name|QString
operator|>
operator|&
operator|>
operator|(
name|list
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTRINGLIST_H
end_comment
end_unit
