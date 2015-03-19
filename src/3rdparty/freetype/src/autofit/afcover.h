begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afcover.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter coverages (specification only).                          */
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
comment|/* This header file can be included multiple times. */
end_comment
begin_comment
comment|/* Define `COVERAGE' as needed.                     */
end_comment
begin_comment
comment|/* Add new coverages here.  The first and second arguments are the   */
end_comment
begin_comment
comment|/* coverage name in lowercase and uppercase, respectively, followed  */
end_comment
begin_comment
comment|/* by a description string.  The last four arguments are the four    */
end_comment
begin_comment
comment|/* characters defining the corresponding OpenType feature.           */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* XXX: It's not possible to define blue zone characters in advance. */
end_comment
begin_endif
unit|COVERAGE( alternative_fractions, ALTERNATIVE_FRACTIONS,             "alternative fractions",             'a', 'f', 'r', 'c' )
endif|#
directive|endif
end_endif
begin_macro
name|COVERAGE
argument_list|(
argument|petite_capitals_from_capitals
argument_list|,
argument|PETITE_CAPITALS_FROM_CAPITALS
argument_list|,
literal|"petite capitals from capitals"
argument_list|,
literal|'c'
argument_list|,
literal|'2'
argument_list|,
literal|'c'
argument_list|,
literal|'p'
argument_list|)
end_macro
begin_macro
name|COVERAGE
argument_list|(
argument|small_capitals_from_capitals
argument_list|,
argument|SMALL_CAPITALS_FROM_CAPITALS
argument_list|,
literal|"small capitals from capitals"
argument_list|,
literal|'c'
argument_list|,
literal|'2'
argument_list|,
literal|'s'
argument_list|,
literal|'c'
argument_list|)
end_macro
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* XXX: Only digits are in this coverage, however, both normal style */
end_comment
begin_comment
comment|/*      and oldstyle representation forms are possible.              */
end_comment
begin_endif
unit|COVERAGE( denominators, DENOMINATORS,             "denominators",             'd', 'n', 'o', 'm' )
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* XXX: It's not possible to define blue zone characters in advance. */
end_comment
begin_endif
unit|COVERAGE( fractions, FRACTIONS,             "fractions",             'f', 'r', 'a', 'c' )
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* XXX: Only digits are in this coverage, however, both normal style */
end_comment
begin_comment
comment|/*      and oldstyle representation forms are possible.              */
end_comment
begin_endif
unit|COVERAGE( numerators, NUMERATORS,             "numerators",             'n', 'u', 'm', 'r' )
endif|#
directive|endif
end_endif
begin_macro
name|COVERAGE
argument_list|(
argument|ordinals
argument_list|,
argument|ORDINALS
argument_list|,
literal|"ordinals"
argument_list|,
literal|'o'
argument_list|,
literal|'r'
argument_list|,
literal|'d'
argument_list|,
literal|'n'
argument_list|)
end_macro
begin_macro
name|COVERAGE
argument_list|(
argument|petite_capitals
argument_list|,
argument|PETITE_CAPITALS
argument_list|,
literal|"petite capitals"
argument_list|,
literal|'p'
argument_list|,
literal|'c'
argument_list|,
literal|'a'
argument_list|,
literal|'p'
argument_list|)
end_macro
begin_macro
name|COVERAGE
argument_list|(
argument|ruby
argument_list|,
argument|RUBY
argument_list|,
literal|"ruby"
argument_list|,
literal|'r'
argument_list|,
literal|'u'
argument_list|,
literal|'b'
argument_list|,
literal|'y'
argument_list|)
end_macro
begin_macro
name|COVERAGE
argument_list|(
argument|scientific_inferiors
argument_list|,
argument|SCIENTIFIC_INFERIORS
argument_list|,
literal|"scientific inferiors"
argument_list|,
literal|'s'
argument_list|,
literal|'i'
argument_list|,
literal|'n'
argument_list|,
literal|'f'
argument_list|)
end_macro
begin_macro
name|COVERAGE
argument_list|(
argument|small_capitals
argument_list|,
argument|SMALL_CAPITALS
argument_list|,
literal|"small capitals"
argument_list|,
literal|'s'
argument_list|,
literal|'m'
argument_list|,
literal|'c'
argument_list|,
literal|'p'
argument_list|)
end_macro
begin_macro
name|COVERAGE
argument_list|(
argument|subscript
argument_list|,
argument|SUBSCRIPT
argument_list|,
literal|"subscript"
argument_list|,
literal|'s'
argument_list|,
literal|'u'
argument_list|,
literal|'b'
argument_list|,
literal|'s'
argument_list|)
end_macro
begin_macro
name|COVERAGE
argument_list|(
argument|superscript
argument_list|,
argument|SUPERSCRIPT
argument_list|,
literal|"superscript"
argument_list|,
literal|'s'
argument_list|,
literal|'u'
argument_list|,
literal|'p'
argument_list|,
literal|'s'
argument_list|)
end_macro
begin_macro
name|COVERAGE
argument_list|(
argument|titling
argument_list|,
argument|TITLING
argument_list|,
literal|"titling"
argument_list|,
literal|'t'
argument_list|,
literal|'i'
argument_list|,
literal|'t'
argument_list|,
literal|'l'
argument_list|)
end_macro
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* to be always excluded */
end_comment
begin_comment
unit|COVERAGE(nalt, 'n', 'a', 'l', 't');
comment|/* Alternate Annotation Forms (?) */
end_comment
begin_comment
unit|COVERAGE(ornm, 'o', 'r', 'n', 'm');
comment|/* Ornaments (?) */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* END */
end_comment
end_unit
