begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_comment
comment|// This file was generated by qlalr - DO NOT EDIT!
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQMLJSGRAMMAR_P_H
end_ifndef
begin_define
DECL|macro|QQMLJSGRAMMAR_P_H
define|#
directive|define
name|QQMLJSGRAMMAR_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QQmlJSGrammar
block|{
name|public
label|:
enum|enum
name|VariousConstants
block|{
name|EOF_SYMBOL
init|=
literal|0
block|,
name|REDUCE_HERE
init|=
literal|101
block|,
name|SHIFT_THERE
init|=
literal|100
block|,
name|T_AND
init|=
literal|1
block|,
name|T_AND_AND
init|=
literal|2
block|,
name|T_AND_EQ
init|=
literal|3
block|,
name|T_AS
init|=
literal|91
block|,
name|T_AUTOMATIC_SEMICOLON
init|=
literal|62
block|,
name|T_BREAK
init|=
literal|4
block|,
name|T_CASE
init|=
literal|5
block|,
name|T_CATCH
init|=
literal|6
block|,
name|T_COLON
init|=
literal|7
block|,
name|T_COMMA
init|=
literal|8
block|,
name|T_COMMENT
init|=
literal|88
block|,
name|T_CONST
init|=
literal|84
block|,
name|T_CONTINUE
init|=
literal|9
block|,
name|T_DEBUGGER
init|=
literal|85
block|,
name|T_DEFAULT
init|=
literal|10
block|,
name|T_DELETE
init|=
literal|11
block|,
name|T_DIVIDE_
init|=
literal|12
block|,
name|T_DIVIDE_EQ
init|=
literal|13
block|,
name|T_DO
init|=
literal|14
block|,
name|T_DOT
init|=
literal|15
block|,
name|T_ELSE
init|=
literal|16
block|,
name|T_EQ
init|=
literal|17
block|,
name|T_EQ_EQ
init|=
literal|18
block|,
name|T_EQ_EQ_EQ
init|=
literal|19
block|,
name|T_ERROR
init|=
literal|93
block|,
name|T_FALSE
init|=
literal|83
block|,
name|T_FEED_JS_EXPRESSION
init|=
literal|97
block|,
name|T_FEED_JS_PROGRAM
init|=
literal|99
block|,
name|T_FEED_JS_SOURCE_ELEMENT
init|=
literal|98
block|,
name|T_FEED_JS_STATEMENT
init|=
literal|96
block|,
name|T_FEED_UI_OBJECT_MEMBER
init|=
literal|95
block|,
name|T_FEED_UI_PROGRAM
init|=
literal|94
block|,
name|T_FINALLY
init|=
literal|20
block|,
name|T_FOR
init|=
literal|21
block|,
name|T_FUNCTION
init|=
literal|22
block|,
name|T_GE
init|=
literal|23
block|,
name|T_GT
init|=
literal|24
block|,
name|T_GT_GT
init|=
literal|25
block|,
name|T_GT_GT_EQ
init|=
literal|26
block|,
name|T_GT_GT_GT
init|=
literal|27
block|,
name|T_GT_GT_GT_EQ
init|=
literal|28
block|,
name|T_IDENTIFIER
init|=
literal|29
block|,
name|T_IF
init|=
literal|30
block|,
name|T_IMPORT
init|=
literal|90
block|,
name|T_IN
init|=
literal|31
block|,
name|T_INSTANCEOF
init|=
literal|32
block|,
name|T_LBRACE
init|=
literal|33
block|,
name|T_LBRACKET
init|=
literal|34
block|,
name|T_LE
init|=
literal|35
block|,
name|T_LPAREN
init|=
literal|36
block|,
name|T_LT
init|=
literal|37
block|,
name|T_LT_LT
init|=
literal|38
block|,
name|T_LT_LT_EQ
init|=
literal|39
block|,
name|T_MINUS
init|=
literal|40
block|,
name|T_MINUS_EQ
init|=
literal|41
block|,
name|T_MINUS_MINUS
init|=
literal|42
block|,
name|T_MULTILINE_STRING_LITERAL
init|=
literal|87
block|,
name|T_NEW
init|=
literal|43
block|,
name|T_NOT
init|=
literal|44
block|,
name|T_NOT_EQ
init|=
literal|45
block|,
name|T_NOT_EQ_EQ
init|=
literal|46
block|,
name|T_NULL
init|=
literal|81
block|,
name|T_NUMERIC_LITERAL
init|=
literal|47
block|,
name|T_ON
init|=
literal|92
block|,
name|T_OR
init|=
literal|48
block|,
name|T_OR_EQ
init|=
literal|49
block|,
name|T_OR_OR
init|=
literal|50
block|,
name|T_PLUS
init|=
literal|51
block|,
name|T_PLUS_EQ
init|=
literal|52
block|,
name|T_PLUS_PLUS
init|=
literal|53
block|,
name|T_PROPERTY
init|=
literal|66
block|,
name|T_PUBLIC
init|=
literal|89
block|,
name|T_QUESTION
init|=
literal|54
block|,
name|T_RBRACE
init|=
literal|55
block|,
name|T_RBRACKET
init|=
literal|56
block|,
name|T_READONLY
init|=
literal|68
block|,
name|T_REMAINDER
init|=
literal|57
block|,
name|T_REMAINDER_EQ
init|=
literal|58
block|,
name|T_RESERVED_WORD
init|=
literal|86
block|,
name|T_RETURN
init|=
literal|59
block|,
name|T_RPAREN
init|=
literal|60
block|,
name|T_SEMICOLON
init|=
literal|61
block|,
name|T_SIGNAL
init|=
literal|67
block|,
name|T_STAR
init|=
literal|63
block|,
name|T_STAR_EQ
init|=
literal|64
block|,
name|T_STRING_LITERAL
init|=
literal|65
block|,
name|T_SWITCH
init|=
literal|69
block|,
name|T_THIS
init|=
literal|70
block|,
name|T_THROW
init|=
literal|71
block|,
name|T_TILDE
init|=
literal|72
block|,
name|T_TRUE
init|=
literal|82
block|,
name|T_TRY
init|=
literal|73
block|,
name|T_TYPEOF
init|=
literal|74
block|,
name|T_VAR
init|=
literal|75
block|,
name|T_VOID
init|=
literal|76
block|,
name|T_WHILE
init|=
literal|77
block|,
name|T_WITH
init|=
literal|78
block|,
name|T_XOR
init|=
literal|79
block|,
name|T_XOR_EQ
init|=
literal|80
block|,
name|ACCEPT_STATE
init|=
literal|644
block|,
name|RULE_COUNT
init|=
literal|349
block|,
name|STATE_COUNT
init|=
literal|645
block|,
name|TERMINAL_COUNT
init|=
literal|102
block|,
name|NON_TERMINAL_COUNT
init|=
literal|107
block|,
name|GOTO_INDEX_OFFSET
init|=
literal|645
block|,
name|GOTO_INFO_OFFSET
init|=
literal|2807
block|,
name|GOTO_CHECK_OFFSET
init|=
literal|2807
block|}
enum|;
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|spell
index|[]
decl_stmt|;
specifier|static
specifier|const
name|short
name|lhs
index|[]
decl_stmt|;
specifier|static
specifier|const
name|short
name|rhs
index|[]
decl_stmt|;
specifier|static
specifier|const
name|short
name|goto_default
index|[]
decl_stmt|;
specifier|static
specifier|const
name|short
name|action_default
index|[]
decl_stmt|;
specifier|static
specifier|const
name|short
name|action_index
index|[]
decl_stmt|;
specifier|static
specifier|const
name|short
name|action_info
index|[]
decl_stmt|;
specifier|static
specifier|const
name|short
name|action_check
index|[]
decl_stmt|;
specifier|static
specifier|inline
name|int
name|nt_action
parameter_list|(
name|int
name|state
parameter_list|,
name|int
name|nt
parameter_list|)
block|{
specifier|const
name|int
name|yyn
init|=
name|action_index
index|[
name|GOTO_INDEX_OFFSET
operator|+
name|state
index|]
operator|+
name|nt
decl_stmt|;
if|if
condition|(
name|yyn
operator|<
literal|0
operator|||
name|action_check
index|[
name|GOTO_CHECK_OFFSET
operator|+
name|yyn
index|]
operator|!=
name|nt
condition|)
return|return
name|goto_default
index|[
name|nt
index|]
return|;
return|return
name|action_info
index|[
name|GOTO_INFO_OFFSET
operator|+
name|yyn
index|]
return|;
block|}
specifier|static
specifier|inline
name|int
name|t_action
parameter_list|(
name|int
name|state
parameter_list|,
name|int
name|token
parameter_list|)
block|{
specifier|const
name|int
name|yyn
init|=
name|action_index
index|[
name|state
index|]
operator|+
name|token
decl_stmt|;
if|if
condition|(
name|yyn
operator|<
literal|0
operator|||
name|action_check
index|[
name|yyn
index|]
operator|!=
name|token
condition|)
return|return
operator|-
name|action_default
index|[
name|state
index|]
return|;
return|return
name|action_info
index|[
name|yyn
index|]
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQMLJSGRAMMAR_P_H
end_comment
end_unit
