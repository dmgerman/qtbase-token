begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RE2NFA_H
end_ifndef
begin_define
DECL|macro|RE2NFA_H
define|#
directive|define
name|RE2NFA_H
end_define
begin_include
include|#
directive|include
file|"nfa.h"
end_include
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_decl_stmt
name|class
name|RE2NFA
block|{
name|public
label|:
name|RE2NFA
argument_list|(
argument|const QMap<QString
argument_list|,
argument|NFA>&macros
argument_list|,
argument|const QSet<InputType>&maxInputSet
argument_list|,
argument|Qt::CaseSensitivity cs
argument_list|)
empty_stmt|;
name|NFA
name|parse
parameter_list|(
specifier|const
name|QString
modifier|&
name|expression
parameter_list|,
name|int
modifier|*
name|errorColumn
init|=
literal|0
parameter_list|)
function_decl|;
name|private
label|:
name|NFA
name|parseExpr
parameter_list|()
function_decl|;
name|NFA
name|parseBranch
parameter_list|()
function_decl|;
name|NFA
name|parsePiece
parameter_list|()
function_decl|;
name|NFA
name|parseAtom
parameter_list|()
function_decl|;
name|NFA
name|parseMaybeQuantifier
parameter_list|(
specifier|const
name|NFA
modifier|&
name|nfa
parameter_list|)
function_decl|;
name|NFA
name|parseSet
parameter_list|()
function_decl|;
name|NFA
name|parseSet2
parameter_list|()
function_decl|;
name|NFA
name|createCharNFA
parameter_list|()
function_decl|;
name|private
label|:
name|friend
name|class
name|RegExpTokenizer
decl_stmt|;
enum|enum
name|Token
block|{
name|TOK_INVALID
block|,
name|TOK_STRING
block|,
name|TOK_LBRACE
block|,
comment|// {
name|TOK_RBRACE
block|,
comment|// }
name|TOK_LBRACKET
block|,
comment|// [
name|TOK_RBRACKET
block|,
comment|// ]
name|TOK_LPAREN
block|,
comment|// (
name|TOK_RPAREN
block|,
comment|// )
name|TOK_COMMA
block|,
name|TOK_STAR
block|,
name|TOK_OR
block|,
name|TOK_QUESTION
block|,
name|TOK_DOT
block|,
name|TOK_PLUS
block|,
name|TOK_SEQUENCE
block|,
name|TOK_QUOTED_STRING
block|}
enum|;
struct|struct
name|Symbol
block|{
specifier|inline
name|Symbol
argument_list|()
operator|:
name|token
argument_list|(
name|TOK_INVALID
argument_list|)
operator|,
name|column
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
specifier|inline
name|Symbol
argument_list|(
argument|Token t
argument_list|,
argument|const QString&l = QString()
argument_list|)
operator|:
name|token
argument_list|(
name|t
argument_list|)
operator|,
name|lexem
argument_list|(
name|l
argument_list|)
operator|,
name|column
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|Token
name|token
expr_stmt|;
name|QString
name|lexem
decl_stmt|;
name|int
name|column
decl_stmt|;
block|}
struct|;
specifier|inline
name|bool
name|hasNext
argument_list|()
specifier|const
block|{
return|return
name|index
operator|<
name|symbols
operator|.
name|count
argument_list|()
return|;
block|}
specifier|inline
name|Token
name|next
parameter_list|()
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|index
operator|++
argument_list|)
operator|.
name|token
return|;
block|}
name|bool
name|next
parameter_list|(
name|Token
name|t
parameter_list|)
function_decl|;
name|bool
name|test
parameter_list|(
name|Token
name|t
parameter_list|)
function_decl|;
specifier|inline
name|void
name|prev
parameter_list|()
block|{
name|index
operator|--
expr_stmt|;
block|}
specifier|inline
specifier|const
name|Symbol
operator|&
name|symbol
argument_list|()
specifier|const
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|index
operator|-
literal|1
argument_list|)
return|;
block|}
name|QString
name|lexemUntil
parameter_list|(
name|Token
name|t
parameter_list|)
function_decl|;
name|void
name|tokenize
parameter_list|(
specifier|const
name|QString
modifier|&
name|input
parameter_list|)
function_decl|;
name|QMap
operator|<
name|QString
operator|,
name|NFA
operator|>
name|macros
expr_stmt|;
name|QVector
operator|<
name|Symbol
operator|>
name|symbols
expr_stmt|;
name|int
name|index
decl_stmt|;
name|int
name|errorColumn
decl_stmt|;
specifier|const
name|QSet
operator|<
name|InputType
operator|>
name|maxInputSet
expr_stmt|;
name|Qt
operator|::
name|CaseSensitivity
name|caseSensitivity
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// RE2NFA_H
end_comment
end_unit
