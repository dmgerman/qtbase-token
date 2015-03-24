begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afstyles.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter styles (specification only).                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2013, 2014 by                                                */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/* The following part can be included multiple times. */
end_comment
begin_comment
comment|/* Define `STYLE' as needed.                          */
end_comment
begin_comment
comment|/* Add new styles here.  The first and second arguments are the  */
end_comment
begin_comment
comment|/* style name in lowercase and uppercase, respectively, followed */
end_comment
begin_comment
comment|/* by a description string.  The next arguments are the          */
end_comment
begin_comment
comment|/* corresponding writing system, script, blue stringset, and     */
end_comment
begin_comment
comment|/* coverage.                                                     */
end_comment
begin_comment
comment|/*                                                               */
end_comment
begin_comment
comment|/* Note that styles using `AF_COVERAGE_DEFAULT' should always    */
end_comment
begin_comment
comment|/* come after styles with other coverages.                       */
end_comment
begin_comment
comment|/*                                                               */
end_comment
begin_comment
comment|/* Example:                                                      */
end_comment
begin_comment
comment|/*                                                               */
end_comment
begin_comment
comment|/*   STYLE( cyrl_dflt, CYRL_DFLT,                                */
end_comment
begin_comment
comment|/*          "Cyrillic default style",                            */
end_comment
begin_comment
comment|/*          AF_WRITING_SYSTEM_LATIN,                             */
end_comment
begin_comment
comment|/*          AF_SCRIPT_CYRL,                                      */
end_comment
begin_comment
comment|/*          AF_BLUE_STRINGSET_CYRL,                              */
end_comment
begin_comment
comment|/*          AF_COVERAGE_DEFAULT )                                */
end_comment
begin_undef
DECL|macro|STYLE_LATIN
undef|#
directive|undef
name|STYLE_LATIN
end_undef
begin_define
DECL|macro|STYLE_LATIN
define|#
directive|define
name|STYLE_LATIN
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|f
parameter_list|,
name|F
parameter_list|,
name|ds
parameter_list|,
name|df
parameter_list|,
name|C
parameter_list|)
define|\
value|STYLE( s ## _ ## f, S ## _ ## F,   \                  ds " " df " style",         \                  AF_WRITING_SYSTEM_LATIN,    \                  AF_SCRIPT_ ## S,            \                  AF_BLUE_STRINGSET_ ## S,    \                  AF_COVERAGE_ ## C )
end_define
begin_undef
DECL|macro|META_STYLE_LATIN
undef|#
directive|undef
name|META_STYLE_LATIN
end_undef
begin_define
DECL|macro|META_STYLE_LATIN
define|#
directive|define
name|META_STYLE_LATIN
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|ds
parameter_list|)
define|\
value|STYLE_LATIN( s, S, c2cp, C2CP, ds,             \                        "petite capticals from capitals", \                        PETITE_CAPITALS_FROM_CAPITALS )   \           STYLE_LATIN( s, S, c2sc, C2SC, ds,             \                        "small capticals from capitals",  \                        SMALL_CAPITALS_FROM_CAPITALS )    \           STYLE_LATIN( s, S, ordn, ORDN, ds,             \                        "ordinals",                       \                        ORDINALS )                        \           STYLE_LATIN( s, S, pcap, PCAP, ds,             \                        "petite capitals",                \                        PETITE_CAPITALS )                 \           STYLE_LATIN( s, S, sinf, SINF, ds,             \                        "scientific inferiors",           \                        SCIENTIFIC_INFERIORS )            \           STYLE_LATIN( s, S, smcp, SMCP, ds,             \                        "small capitals",                 \                        SMALL_CAPITALS )                  \           STYLE_LATIN( s, S, subs, SUBS, ds,             \                        "subscript",                      \                        SUBSCRIPT )                       \           STYLE_LATIN( s, S, sups, SUPS, ds,             \                        "superscript",                    \                        SUPERSCRIPT )                     \           STYLE_LATIN( s, S, titl, TITL, ds,             \                        "titling",                        \                        TITLING )                         \           STYLE_LATIN( s, S, dflt, DFLT, ds,             \                        "default",                        \                        DEFAULT )
end_define
begin_macro
name|META_STYLE_LATIN
argument_list|(
argument|cyrl
argument_list|,
argument|CYRL
argument_list|,
literal|"Cyrillic"
argument_list|)
end_macro
begin_macro
name|META_STYLE_LATIN
argument_list|(
argument|grek
argument_list|,
argument|GREK
argument_list|,
literal|"Greek"
argument_list|)
end_macro
begin_macro
name|STYLE
argument_list|(
argument|hebr_dflt
argument_list|,
argument|HEBR_DFLT
argument_list|,
literal|"Hebrew default style"
argument_list|,
argument|AF_WRITING_SYSTEM_LATIN
argument_list|,
argument|AF_SCRIPT_HEBR
argument_list|,
argument|AF_BLUE_STRINGSET_HEBR
argument_list|,
argument|AF_COVERAGE_DEFAULT
argument_list|)
end_macro
begin_macro
name|META_STYLE_LATIN
argument_list|(
argument|latn
argument_list|,
argument|LATN
argument_list|,
literal|"Latin"
argument_list|)
end_macro
begin_macro
name|STYLE
argument_list|(
argument|deva_dflt
argument_list|,
argument|DEVA_DFLT
argument_list|,
literal|"Devanagari default style"
argument_list|,
argument|AF_WRITING_SYSTEM_LATIN
argument_list|,
argument|AF_SCRIPT_DEVA
argument_list|,
argument|AF_BLUE_STRINGSET_DEVA
argument_list|,
argument|AF_COVERAGE_DEFAULT
argument_list|)
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|FT_OPTION_AUTOFIT2
end_ifdef
begin_macro
name|STYLE
argument_list|(
argument|ltn2_dflt
argument_list|,
argument|LTN2_DFLT
argument_list|,
literal|"Latin 2 default style"
argument_list|,
argument|AF_WRITING_SYSTEM_LATIN2
argument_list|,
argument|AF_SCRIPT_LATN
argument_list|,
argument|AF_BLUE_STRINGSET_LATN
argument_list|,
argument|AF_COVERAGE_DEFAULT
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|STYLE
argument_list|(
argument|none_dflt
argument_list|,
argument|NONE_DFLT
argument_list|,
literal|"no style"
argument_list|,
argument|AF_WRITING_SYSTEM_DUMMY
argument_list|,
argument|AF_SCRIPT_NONE
argument_list|,
argument|(AF_Blue_Stringset)
literal|0
argument_list|,
argument|AF_COVERAGE_DEFAULT
argument_list|)
end_macro
begin_macro
name|STYLE
argument_list|(
argument|telu_dflt
argument_list|,
argument|TELU_DFLT
argument_list|,
literal|"Telugu default style"
argument_list|,
argument|AF_WRITING_SYSTEM_LATIN
argument_list|,
argument|AF_SCRIPT_TELU
argument_list|,
argument|AF_BLUE_STRINGSET_TELU
argument_list|,
argument|AF_COVERAGE_DEFAULT
argument_list|)
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_INDIC
end_ifdef
begin_comment
comment|/* no blue stringset support for the Indic writing system yet */
end_comment
begin_undef
DECL|macro|STYLE_DEFAULT_INDIC
undef|#
directive|undef
name|STYLE_DEFAULT_INDIC
end_undef
begin_define
DECL|macro|STYLE_DEFAULT_INDIC
define|#
directive|define
name|STYLE_DEFAULT_INDIC
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|)
define|\
value|STYLE( s ## _dflt, S ## _DFLT,  \                  d " default style",      \                  AF_WRITING_SYSTEM_INDIC, \                  AF_SCRIPT_ ## S,         \                  (AF_Blue_Stringset)0,    \                  AF_COVERAGE_DEFAULT )
end_define
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|beng
argument_list|,
argument|BENG
argument_list|,
literal|"Bengali"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|gujr
argument_list|,
argument|GUJR
argument_list|,
literal|"Gujarati"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|guru
argument_list|,
argument|GURU
argument_list|,
literal|"Gurmukhi"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|knda
argument_list|,
argument|KNDA
argument_list|,
literal|"Kannada"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|limb
argument_list|,
argument|LIMB
argument_list|,
literal|"Limbu"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|mlym
argument_list|,
argument|MLYM
argument_list|,
literal|"Malayalam"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|orya
argument_list|,
argument|ORYA
argument_list|,
literal|"Oriya"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|sinh
argument_list|,
argument|SINH
argument_list|,
literal|"Sinhala"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|sund
argument_list|,
argument|SUND
argument_list|,
literal|"Sundanese"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|sylo
argument_list|,
argument|SYLO
argument_list|,
literal|"Syloti Nagri"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|taml
argument_list|,
argument|TAML
argument_list|,
literal|"Tamil"
argument_list|)
end_macro
begin_macro
name|STYLE_DEFAULT_INDIC
argument_list|(
argument|tibt
argument_list|,
argument|TIBT
argument_list|,
literal|"Tibetan"
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* AF_CONFIG_OPTION_INDIC */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_CJK
end_ifdef
begin_macro
name|STYLE
argument_list|(
argument|hani_dflt
argument_list|,
argument|HANI_DFLT
argument_list|,
literal|"CJKV ideographs default style"
argument_list|,
argument|AF_WRITING_SYSTEM_CJK
argument_list|,
argument|AF_SCRIPT_HANI
argument_list|,
argument|AF_BLUE_STRINGSET_HANI
argument_list|,
argument|AF_COVERAGE_DEFAULT
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* AF_CONFIG_OPTION_CJK */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
