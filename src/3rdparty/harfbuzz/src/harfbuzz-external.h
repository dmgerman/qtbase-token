begin_unit
begin_comment
comment|/*  * Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies)  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HARFBUZZ_EXTERNAL_H
end_ifndef
begin_define
DECL|macro|HARFBUZZ_EXTERNAL_H
define|#
directive|define
name|HARFBUZZ_EXTERNAL_H
end_define
begin_include
include|#
directive|include
file|"harfbuzz-global.h"
end_include
begin_macro
name|HB_BEGIN_HEADER
end_macro
begin_comment
comment|/* This header contains some methods that are not part of    Harfbuzz itself, but referenced by it.    They need to be provided by the application/library */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_Mark_NonSpacing
name|HB_Mark_NonSpacing
block|,
comment|/*   Mn */
DECL|enumerator|HB_Mark_SpacingCombining
name|HB_Mark_SpacingCombining
block|,
comment|/*   Mc */
DECL|enumerator|HB_Mark_Enclosing
name|HB_Mark_Enclosing
block|,
comment|/*   Me */
DECL|enumerator|HB_Number_DecimalDigit
name|HB_Number_DecimalDigit
block|,
comment|/*   Nd */
DECL|enumerator|HB_Number_Letter
name|HB_Number_Letter
block|,
comment|/*   Nl */
DECL|enumerator|HB_Number_Other
name|HB_Number_Other
block|,
comment|/*   No */
DECL|enumerator|HB_Separator_Space
name|HB_Separator_Space
block|,
comment|/*   Zs */
DECL|enumerator|HB_Separator_Line
name|HB_Separator_Line
block|,
comment|/*   Zl */
DECL|enumerator|HB_Separator_Paragraph
name|HB_Separator_Paragraph
block|,
comment|/*   Zp */
DECL|enumerator|HB_Other_Control
name|HB_Other_Control
block|,
comment|/*   Cc */
DECL|enumerator|HB_Other_Format
name|HB_Other_Format
block|,
comment|/*   Cf */
DECL|enumerator|HB_Other_Surrogate
name|HB_Other_Surrogate
block|,
comment|/*   Cs */
DECL|enumerator|HB_Other_PrivateUse
name|HB_Other_PrivateUse
block|,
comment|/*   Co */
DECL|enumerator|HB_Other_NotAssigned
name|HB_Other_NotAssigned
block|,
comment|/*   Cn */
DECL|enumerator|HB_Letter_Uppercase
name|HB_Letter_Uppercase
block|,
comment|/*   Lu */
DECL|enumerator|HB_Letter_Lowercase
name|HB_Letter_Lowercase
block|,
comment|/*   Ll */
DECL|enumerator|HB_Letter_Titlecase
name|HB_Letter_Titlecase
block|,
comment|/*   Lt */
DECL|enumerator|HB_Letter_Modifier
name|HB_Letter_Modifier
block|,
comment|/*   Lm */
DECL|enumerator|HB_Letter_Other
name|HB_Letter_Other
block|,
comment|/*   Lo */
DECL|enumerator|HB_Punctuation_Connector
name|HB_Punctuation_Connector
block|,
comment|/*   Pc */
DECL|enumerator|HB_Punctuation_Dash
name|HB_Punctuation_Dash
block|,
comment|/*   Pd */
DECL|enumerator|HB_Punctuation_Open
name|HB_Punctuation_Open
block|,
comment|/*   Ps */
DECL|enumerator|HB_Punctuation_Close
name|HB_Punctuation_Close
block|,
comment|/*   Pe */
DECL|enumerator|HB_Punctuation_InitialQuote
name|HB_Punctuation_InitialQuote
block|,
comment|/*   Pi */
DECL|enumerator|HB_Punctuation_FinalQuote
name|HB_Punctuation_FinalQuote
block|,
comment|/*   Pf */
DECL|enumerator|HB_Punctuation_Other
name|HB_Punctuation_Other
block|,
comment|/*   Po */
DECL|enumerator|HB_Symbol_Math
name|HB_Symbol_Math
block|,
comment|/*   Sm */
DECL|enumerator|HB_Symbol_Currency
name|HB_Symbol_Currency
block|,
comment|/*   Sc */
DECL|enumerator|HB_Symbol_Modifier
name|HB_Symbol_Modifier
block|,
comment|/*   Sk */
DECL|enumerator|HB_Symbol_Other
name|HB_Symbol_Other
comment|/*   So */
block|}
DECL|typedef|HB_CharCategory
name|HB_CharCategory
typedef|;
end_typedef
begin_function_decl
name|void
name|HB_GetUnicodeCharProperties
parameter_list|(
name|HB_UChar32
name|ch
parameter_list|,
name|HB_CharCategory
modifier|*
name|category
parameter_list|,
name|int
modifier|*
name|combiningClass
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|HB_CharCategory
name|HB_GetUnicodeCharCategory
parameter_list|(
name|HB_UChar32
name|ch
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|HB_GetUnicodeCharCombiningClass
parameter_list|(
name|HB_UChar32
name|ch
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|HB_UChar16
name|HB_GetMirroredChar
parameter_list|(
name|HB_UChar16
name|ch
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|void
argument_list|(
operator|*
name|HB_Library_Resolve
argument_list|(
argument|const char *library
argument_list|,
argument|int version
argument_list|,
argument|const char *symbol
argument_list|)
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
name|HB_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
