begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afwrtsys.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter writing systems (specification only).                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2013 by                                                      */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__AFWRTSYS_H__
end_ifndef
begin_define
DECL|macro|__AFWRTSYS_H__
define|#
directive|define
name|__AFWRTSYS_H__
end_define
begin_comment
comment|/* Since preprocessor directives can't create other preprocessor */
end_comment
begin_comment
comment|/* directives, we have to include the header files manually.     */
end_comment
begin_include
include|#
directive|include
file|"afdummy.h"
end_include
begin_include
include|#
directive|include
file|"aflatin.h"
end_include
begin_include
include|#
directive|include
file|"afcjk.h"
end_include
begin_include
include|#
directive|include
file|"afindic.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FT_OPTION_AUTOFIT2
end_ifdef
begin_include
include|#
directive|include
file|"aflatin2.h"
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
comment|/* __AFWRTSYS_H__ */
end_comment
begin_comment
comment|/* The following part can be included multiple times. */
end_comment
begin_comment
comment|/* Define `WRITING_SYSTEM' as needed.                 */
end_comment
begin_comment
comment|/* Add new writing systems here.  The arguments are the writing system */
end_comment
begin_comment
comment|/* name in lowercase and uppercase, respectively.                      */
end_comment
begin_macro
name|WRITING_SYSTEM
argument_list|(
argument|dummy
argument_list|,
argument|DUMMY
argument_list|)
end_macro
begin_macro
name|WRITING_SYSTEM
argument_list|(
argument|latin
argument_list|,
argument|LATIN
argument_list|)
end_macro
begin_macro
name|WRITING_SYSTEM
argument_list|(
argument|cjk
argument_list|,
argument|CJK
argument_list|)
end_macro
begin_macro
name|WRITING_SYSTEM
argument_list|(
argument|indic
argument_list|,
argument|INDIC
argument_list|)
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|FT_OPTION_AUTOFIT2
end_ifdef
begin_macro
name|WRITING_SYSTEM
argument_list|(
argument|latin2
argument_list|,
argument|LATIN2
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* END */
end_comment
end_unit
