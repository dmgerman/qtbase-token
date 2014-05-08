begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TOKEN_H
end_ifndef
begin_define
DECL|macro|TOKEN_H
define|#
directive|define
name|TOKEN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|FOR_ALL_TOKENS
define|#
directive|define
name|FOR_ALL_TOKENS
parameter_list|(
name|F
parameter_list|)
define|\
value|F(NOTOKEN) \     F(IDENTIFIER) \     F(INTEGER_LITERAL) \     F(CHARACTER_LITERAL) \     F(STRING_LITERAL) \     F(BOOLEAN_LITERAL) \     F(HEADER_NAME) \     F(LANGLE) \     F(RANGLE) \     F(LPAREN) \     F(RPAREN) \     F(ELIPSIS) \     F(LBRACK) \     F(RBRACK) \     F(LBRACE) \     F(RBRACE) \     F(EQ) \     F(SCOPE) \     F(SEMIC) \     F(COLON) \     F(DOTSTAR) \     F(QUESTION) \     F(DOT) \     F(DYNAMIC_CAST) \     F(STATIC_CAST) \     F(REINTERPRET_CAST) \     F(CONST_CAST) \     F(TYPEID) \     F(THIS) \     F(TEMPLATE) \     F(THROW) \     F(TRY) \     F(CATCH) \     F(TYPEDEF) \     F(FRIEND) \     F(CLASS) \     F(NAMESPACE) \     F(ENUM) \     F(STRUCT) \     F(UNION) \     F(VIRTUAL) \     F(PRIVATE) \     F(PROTECTED) \     F(PUBLIC) \     F(EXPORT) \     F(AUTO) \     F(REGISTER) \     F(EXTERN) \     F(MUTABLE) \     F(ASM) \     F(USING) \     F(INLINE) \     F(EXPLICIT) \     F(STATIC) \     F(CONST) \     F(VOLATILE) \     F(OPERATOR) \     F(SIZEOF) \     F(NEW) \     F(DELETE) \     F(PLUS) \     F(MINUS) \     F(STAR) \     F(SLASH) \     F(PERCENT) \     F(HAT) \     F(AND) \     F(OR) \     F(TILDE) \     F(NOT) \     F(PLUS_EQ) \     F(MINUS_EQ) \     F(STAR_EQ) \     F(SLASH_EQ) \     F(PERCENT_EQ) \     F(HAT_EQ) \     F(AND_EQ) \     F(OR_EQ) \     F(LTLT) \     F(GTGT) \     F(GTGT_EQ) \     F(LTLT_EQ) \     F(EQEQ) \     F(NE) \     F(LE) \     F(GE) \     F(ANDAND) \     F(OROR) \     F(INCR) \     F(DECR) \     F(COMMA) \     F(ARROW_STAR) \     F(ARROW) \     F(CHAR) \     F(WCHAR) \     F(BOOL) \     F(SHORT) \     F(INT) \     F(LONG) \     F(SIGNED) \     F(UNSIGNED) \     F(FLOAT) \     F(DOUBLE) \     F(VOID) \     F(CASE) \     F(DEFAULT) \     F(IF) \     F(ELSE) \     F(SWITCH) \     F(WHILE) \     F(DO) \     F(FOR) \     F(BREAK) \     F(CONTINUE) \     F(GOTO) \     F(SIGNALS) \     F(SLOTS) \     F(RETURN) \     F(Q_OBJECT_TOKEN) \     F(Q_GADGET_TOKEN) \     F(Q_PROPERTY_TOKEN) \     F(Q_PLUGIN_METADATA_TOKEN) \     F(Q_ENUMS_TOKEN) \     F(Q_FLAGS_TOKEN) \     F(Q_DECLARE_FLAGS_TOKEN) \     F(Q_DECLARE_INTERFACE_TOKEN) \     F(Q_DECLARE_METATYPE_TOKEN) \     F(Q_CLASSINFO_TOKEN) \     F(Q_INTERFACES_TOKEN) \     F(Q_SIGNALS_TOKEN) \     F(Q_SLOTS_TOKEN) \     F(Q_SIGNAL_TOKEN) \     F(Q_SLOT_TOKEN) \     F(Q_PRIVATE_SLOT_TOKEN) \     F(Q_MOC_COMPAT_TOKEN) \     F(Q_INVOKABLE_TOKEN) \     F(Q_SCRIPTABLE_TOKEN) \     F(Q_PRIVATE_PROPERTY_TOKEN) \     F(Q_REVISION_TOKEN) \     F(SPECIAL_TREATMENT_MARK) \     F(MOC_INCLUDE_BEGIN) \     F(MOC_INCLUDE_END) \     F(CPP_COMMENT) \     F(C_COMMENT) \     F(FLOATING_LITERAL) \     F(HASH) \     F(QUOTE) \     F(SINGLEQUOTE) \     F(LANGLE_SCOPE) \     F(DIGIT) \     F(CHARACTER) \     F(NEWLINE) \     F(WHITESPACE) \     F(BACKSLASH) \     F(INCOMPLETE) \     F(PP_DEFINE) \     F(PP_UNDEF) \     F(PP_IF) \     F(PP_IFDEF) \     F(PP_IFNDEF) \     F(PP_ELIF) \     F(PP_ELSE) \     F(PP_ENDIF) \     F(PP_INCLUDE) \     F(PP_HASHHASH) \     F(PP_HASH) \     F(PP_DEFINED) \     F(PP_INCOMPLETE) \     F(PP_MOC_TRUE) \     F(PP_MOC_FALSE)
DECL|enum|Token
name|enum
name|Token
block|{
DECL|macro|CREATE_ENUM_VALUE
define|#
directive|define
name|CREATE_ENUM_VALUE
parameter_list|(
name|Name
parameter_list|)
value|Name,
DECL|enumerator|FOR_ALL_TOKENS
name|FOR_ALL_TOKENS
argument_list|(
argument|CREATE_ENUM_VALUE
argument_list|)
DECL|macro|CREATE_ENUM_VALUE
undef|#
directive|undef
name|CREATE_ENUM_VALUE
comment|// aliases
name|PP_AND
operator|=
name|AND
operator|,
DECL|enumerator|PP_ANDAND
name|PP_ANDAND
operator|=
name|ANDAND
operator|,
DECL|enumerator|PP_BACKSLASH
name|PP_BACKSLASH
operator|=
name|BACKSLASH
operator|,
DECL|enumerator|PP_CHARACTER
name|PP_CHARACTER
operator|=
name|CHARACTER
operator|,
DECL|enumerator|PP_CHARACTER_LITERAL
name|PP_CHARACTER_LITERAL
operator|=
name|CHARACTER_LITERAL
operator|,
DECL|enumerator|PP_COLON
name|PP_COLON
operator|=
name|COLON
operator|,
DECL|enumerator|PP_COMMA
name|PP_COMMA
operator|=
name|COMMA
operator|,
DECL|enumerator|PP_CPP_COMMENT
name|PP_CPP_COMMENT
operator|=
name|CPP_COMMENT
operator|,
DECL|enumerator|PP_C_COMMENT
name|PP_C_COMMENT
operator|=
name|C_COMMENT
operator|,
DECL|enumerator|PP_DIGIT
name|PP_DIGIT
operator|=
name|DIGIT
operator|,
DECL|enumerator|PP_EQEQ
name|PP_EQEQ
operator|=
name|EQEQ
operator|,
DECL|enumerator|PP_FLOATING_LITERAL
name|PP_FLOATING_LITERAL
operator|=
name|FLOATING_LITERAL
operator|,
DECL|enumerator|PP_GE
name|PP_GE
operator|=
name|GE
operator|,
DECL|enumerator|PP_GTGT
name|PP_GTGT
operator|=
name|GTGT
operator|,
DECL|enumerator|PP_HAT
name|PP_HAT
operator|=
name|HAT
operator|,
DECL|enumerator|PP_IDENTIFIER
name|PP_IDENTIFIER
operator|=
name|IDENTIFIER
operator|,
DECL|enumerator|PP_INTEGER_LITERAL
name|PP_INTEGER_LITERAL
operator|=
name|INTEGER_LITERAL
operator|,
DECL|enumerator|PP_LANGLE
name|PP_LANGLE
operator|=
name|LANGLE
operator|,
DECL|enumerator|PP_LE
name|PP_LE
operator|=
name|LE
operator|,
DECL|enumerator|PP_LPAREN
name|PP_LPAREN
operator|=
name|LPAREN
operator|,
DECL|enumerator|PP_LTLT
name|PP_LTLT
operator|=
name|LTLT
operator|,
DECL|enumerator|PP_MINUS
name|PP_MINUS
operator|=
name|MINUS
operator|,
DECL|enumerator|PP_NE
name|PP_NE
operator|=
name|NE
operator|,
DECL|enumerator|PP_NEWLINE
name|PP_NEWLINE
operator|=
name|NEWLINE
operator|,
DECL|enumerator|PP_NOTOKEN
name|PP_NOTOKEN
operator|=
name|NOTOKEN
operator|,
DECL|enumerator|PP_NOT
name|PP_NOT
operator|=
name|NOT
operator|,
DECL|enumerator|PP_OR
name|PP_OR
operator|=
name|OR
operator|,
DECL|enumerator|PP_OROR
name|PP_OROR
operator|=
name|OROR
operator|,
DECL|enumerator|PP_PERCENT
name|PP_PERCENT
operator|=
name|PERCENT
operator|,
DECL|enumerator|PP_PLUS
name|PP_PLUS
operator|=
name|PLUS
operator|,
DECL|enumerator|PP_QUESTION
name|PP_QUESTION
operator|=
name|QUESTION
operator|,
DECL|enumerator|PP_QUOTE
name|PP_QUOTE
operator|=
name|QUOTE
operator|,
DECL|enumerator|PP_RANGLE
name|PP_RANGLE
operator|=
name|RANGLE
operator|,
DECL|enumerator|PP_RPAREN
name|PP_RPAREN
operator|=
name|RPAREN
operator|,
DECL|enumerator|PP_SINGLEQUOTE
name|PP_SINGLEQUOTE
operator|=
name|SINGLEQUOTE
operator|,
DECL|enumerator|PP_SLASH
name|PP_SLASH
operator|=
name|SLASH
operator|,
DECL|enumerator|PP_STAR
name|PP_STAR
operator|=
name|STAR
operator|,
DECL|enumerator|PP_STRING_LITERAL
name|PP_STRING_LITERAL
operator|=
name|STRING_LITERAL
operator|,
DECL|enumerator|PP_TILDE
name|PP_TILDE
operator|=
name|TILDE
operator|,
DECL|enumerator|PP_WHITESPACE
name|PP_WHITESPACE
operator|=
name|WHITESPACE
operator|,
DECL|enumerator|Q_META_TOKEN_BEGIN
name|Q_META_TOKEN_BEGIN
operator|=
name|Q_OBJECT_TOKEN
operator|,
DECL|enumerator|Q_META_TOKEN_END
name|Q_META_TOKEN_END
operator|=
name|SPECIAL_TREATMENT_MARK
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// for debugging only
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_MOC
argument_list|)
end_if
begin_function_decl
specifier|const
name|char
modifier|*
name|tokenTypeName
parameter_list|(
name|Token
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|PP_Token
typedef|typedef
name|Token
name|PP_Token
typedef|;
end_typedef
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TOKEN_H
end_comment
end_unit
