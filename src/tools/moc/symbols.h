begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SYMBOLS_H
end_ifndef
begin_define
DECL|macro|SYMBOLS_H
define|#
directive|define
name|SYMBOLS_H
end_define
begin_include
include|#
directive|include
file|"token.h"
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|//#define USE_LEXEM_STORE
end_comment
begin_struct
DECL|struct|SubArray
struct|struct
name|SubArray
block|{
DECL|function|SubArray
specifier|inline
name|SubArray
argument_list|()
operator|:
name|from
argument_list|(
literal|0
argument_list|)
operator|,
name|len
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
DECL|function|SubArray
specifier|inline
name|SubArray
argument_list|(
specifier|const
name|QByteArray
operator|&
name|a
argument_list|)
operator|:
name|array
argument_list|(
name|a
argument_list|)
operator|,
name|from
argument_list|(
literal|0
argument_list|)
operator|,
name|len
argument_list|(
argument|a.size()
argument_list|)
block|{}
DECL|function|SubArray
specifier|inline
name|SubArray
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
operator|:
name|array
argument_list|(
name|s
argument_list|)
operator|,
name|from
argument_list|(
literal|0
argument_list|)
block|{
name|len
operator|=
name|array
operator|.
name|size
argument_list|()
block|; }
DECL|function|SubArray
specifier|inline
name|SubArray
argument_list|(
argument|const QByteArray&a
argument_list|,
argument|int from
argument_list|,
argument|int len
argument_list|)
operator|:
name|array
argument_list|(
name|a
argument_list|)
operator|,
name|from
argument_list|(
name|from
argument_list|)
operator|,
name|len
argument_list|(
argument|len
argument_list|)
block|{}
DECL|member|array
name|QByteArray
name|array
expr_stmt|;
DECL|member|from
DECL|member|len
name|int
name|from
decl_stmt|,
name|len
decl_stmt|;
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SubArray
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|len
operator|!=
name|other
operator|.
name|len
condition|)
return|return
name|false
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|array
operator|.
name|at
argument_list|(
name|from
operator|+
name|i
argument_list|)
operator|!=
name|other
operator|.
name|array
operator|.
name|at
argument_list|(
name|other
operator|.
name|from
operator|+
name|i
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|true
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
name|SubArray
modifier|&
name|key
parameter_list|)
block|{
specifier|const
name|uchar
modifier|*
name|p
init|=
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|key
operator|.
name|array
operator|.
name|data
argument_list|()
operator|+
name|key
operator|.
name|from
operator|)
decl_stmt|;
name|int
name|n
init|=
name|key
operator|.
name|len
decl_stmt|;
name|uint
name|h
init|=
literal|0
decl_stmt|;
name|uint
name|g
decl_stmt|;
while|while
condition|(
name|n
operator|--
condition|)
block|{
name|h
operator|=
operator|(
name|h
operator|<<
literal|4
operator|)
operator|+
operator|*
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|g
operator|=
operator|(
name|h
operator|&
literal|0xf0000000
operator|)
operator|)
operator|!=
literal|0
condition|)
name|h
operator|^=
name|g
operator|>>
literal|23
expr_stmt|;
name|h
operator|&=
operator|~
name|g
expr_stmt|;
block|}
return|return
name|h
return|;
block|}
end_function
begin_struct
DECL|struct|Symbol
struct|struct
name|Symbol
block|{
ifdef|#
directive|ifdef
name|USE_LEXEM_STORE
DECL|typedef|SubArray
DECL|typedef|LexemStore
typedef|typedef
name|QHash
operator|<
name|SubArray
operator|,
name|QHashDummyValue
operator|>
name|LexemStore
expr_stmt|;
DECL|member|lexemStore
specifier|static
name|LexemStore
name|lexemStore
decl_stmt|;
DECL|function|Symbol
specifier|inline
name|Symbol
argument_list|()
operator|:
name|lineNum
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|token
argument_list|(
argument|NOTOKEN
argument_list|)
block|{}
DECL|function|Symbol
specifier|inline
name|Symbol
argument_list|(
argument|int lineNum
argument_list|,
argument|Token token
argument_list|)
operator|:
name|lineNum
argument_list|(
name|lineNum
argument_list|)
operator|,
name|token
argument_list|(
argument|token
argument_list|)
block|{}
DECL|function|Symbol
specifier|inline
name|Symbol
argument_list|(
argument|int lineNum
argument_list|,
argument|Token token
argument_list|,
argument|const QByteArray&lexem
argument_list|)
operator|:
name|lineNum
argument_list|(
name|lineNum
argument_list|)
operator|,
name|token
argument_list|(
name|token
argument_list|)
operator|,
name|lex
argument_list|(
argument|lexem
argument_list|)
block|{}
DECL|function|Symbol
specifier|inline
name|Symbol
argument_list|(
argument|int lineNum
argument_list|,
argument|Token token
argument_list|,
argument|const QByteArray&lexem
argument_list|,
argument|int from
argument_list|,
argument|int len
argument_list|)
operator|:
name|lineNum
argument_list|(
name|lineNum
argument_list|)
operator|,
name|token
argument_list|(
argument|token
argument_list|)
block|{
name|LexemStore
operator|::
name|const_iterator
name|it
operator|=
name|lexemStore
operator|.
name|constFind
argument_list|(
name|SubArray
argument_list|(
name|lexem
argument_list|,
name|from
argument_list|,
name|len
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|it
operator|!=
name|lexemStore
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|lex
operator|=
name|it
operator|.
name|key
argument_list|()
operator|.
name|array
expr_stmt|;
block|}
else|else
block|{
name|lex
operator|=
name|lexem
operator|.
name|mid
argument_list|(
name|from
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|lexemStore
operator|.
name|insert
argument_list|(
name|lex
argument_list|,
name|QHashDummyValue
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
DECL|member|lineNum
name|int
name|lineNum
struct|;
end_struct
begin_decl_stmt
DECL|member|token
name|Token
name|token
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|unquotedLexem
specifier|inline
name|QByteArray
name|unquotedLexem
argument_list|()
specifier|const
block|{
return|return
name|lex
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|lex
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|lexem
specifier|inline
name|QByteArray
name|lexem
argument_list|()
specifier|const
block|{
return|return
name|lex
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|QByteArray
specifier|inline
name|operator
name|QByteArray
argument_list|()
specifier|const
block|{
return|return
name|lex
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|member|lex
name|QByteArray
name|lex
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
specifier|inline
name|Symbol
argument_list|()
operator|:
name|lineNum
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|token
argument_list|(
name|NOTOKEN
argument_list|)
operator|,
name|from
argument_list|(
literal|0
argument_list|)
operator|,
name|len
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
specifier|inline
name|Symbol
argument_list|(
argument|int lineNum
argument_list|,
argument|Token token
argument_list|)
operator|:
name|lineNum
argument_list|(
name|lineNum
argument_list|)
operator|,
name|token
argument_list|(
name|token
argument_list|)
operator|,
name|from
argument_list|(
literal|0
argument_list|)
operator|,
name|len
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
specifier|inline
name|Symbol
argument_list|(
argument|int lineNum
argument_list|,
argument|Token token
argument_list|,
argument|const QByteArray&lexem
argument_list|)
operator|:
name|lineNum
argument_list|(
name|lineNum
argument_list|)
operator|,
name|token
argument_list|(
name|token
argument_list|)
operator|,
name|lex
argument_list|(
name|lexem
argument_list|)
operator|,
name|from
argument_list|(
literal|0
argument_list|)
block|{
name|len
operator|=
name|lex
operator|.
name|size
argument_list|()
block|; }
specifier|inline
name|Symbol
argument_list|(
argument|int lineNum
argument_list|,
argument|Token token
argument_list|,
argument|const QByteArray&lexem
argument_list|,
argument|int from
argument_list|,
argument|int len
argument_list|)
operator|:
name|lineNum
argument_list|(
name|lineNum
argument_list|)
operator|,
name|token
argument_list|(
name|token
argument_list|)
operator|,
name|lex
argument_list|(
name|lexem
argument_list|)
operator|,
name|from
argument_list|(
name|from
argument_list|)
operator|,
name|len
argument_list|(
argument|len
argument_list|)
block|{}
name|int
name|lineNum
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|Token
name|token
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|QByteArray
name|lexem
argument_list|()
specifier|const
block|{
return|return
name|lex
operator|.
name|mid
argument_list|(
name|from
argument_list|,
name|len
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QByteArray
name|unquotedLexem
argument_list|()
specifier|const
block|{
return|return
name|lex
operator|.
name|mid
argument_list|(
name|from
operator|+
literal|1
argument_list|,
name|len
operator|-
literal|2
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|operator
name|QByteArray
argument_list|()
specifier|const
block|{
return|return
name|lex
operator|.
name|mid
argument_list|(
name|from
argument_list|,
name|len
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|operator
name|SubArray
argument_list|()
specifier|const
block|{
return|return
name|SubArray
argument_list|(
name|lex
argument_list|,
name|from
argument_list|,
name|len
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|QByteArray
name|lex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|from
decl_stmt|,
name|len
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|Symbol
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|Symbols
typedef|typedef
name|QVector
operator|<
name|Symbol
operator|>
name|Symbols
expr_stmt|;
end_typedef
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SYMBOLS_H
end_comment
end_unit
