begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftconfig.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Amiga-specific configuration file (specification only).              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2005, 2006, 2007 by                                          */
end_comment
begin_comment
comment|/*  Werner Lemberg and Detlef Würkner.                                     */
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
comment|/*  * This is an example how to override the default FreeType2 header files  * with Amiga-specific changes. When the compiler searches this directory  * before the default directory, we can do some modifications.  *  * Here we must change FT_EXPORT_DEF so that SAS/C does  * generate the needed XDEFs.  */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_define
define|#
directive|define
name|FT_EXPORT_DEF
parameter_list|(
name|x
parameter_list|)
value|extern  x
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_undef
DECL|macro|FT_EXPORT_DEF
undef|#
directive|undef
name|FT_EXPORT_DEF
end_undef
begin_define
DECL|macro|FT_EXPORT_DEF
define|#
directive|define
name|FT_EXPORT_DEF
parameter_list|(
name|x
parameter_list|)
value|x
end_define
begin_comment
comment|/* Now include the original file */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__MORPHOS__
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__SASC
end_ifdef
begin_include
include|#
directive|include
file|"FT:include/freetype/config/ftconfig.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"/FT/include/freetype/config/ftconfig.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* We must define that, it seems that  * lib/gcc-lib/ppc-morphos/2.95.3/include/syslimits.h is missing in  * ppc-morphos-gcc-2.95.3-bin.tgz (gcc for 68k producing MorphOS PPC elf  * binaries from http://www.morphos.de)  */
end_comment
begin_define
DECL|macro|_LIBC_LIMITS_H_
define|#
directive|define
name|_LIBC_LIMITS_H_
end_define
begin_include
include|#
directive|include
file|"/FT/include/freetype/config/ftconfig.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Local Variables: coding: latin-1 End: */
end_comment
end_unit
