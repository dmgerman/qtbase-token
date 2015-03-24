begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  tttags.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Tags for TrueType and OpenType tables (specification only).          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2004, 2005, 2007, 2008, 2013 by                   */
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
name|__TTAGS_H__
end_ifndef
begin_define
DECL|macro|__TTAGS_H__
define|#
directive|define
name|__TTAGS_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|FT_BEGIN_HEADER
DECL|macro|TTAG_avar
define|#
directive|define
name|TTAG_avar
value|FT_MAKE_TAG( 'a', 'v', 'a', 'r' )
DECL|macro|TTAG_BASE
define|#
directive|define
name|TTAG_BASE
value|FT_MAKE_TAG( 'B', 'A', 'S', 'E' )
DECL|macro|TTAG_bdat
define|#
directive|define
name|TTAG_bdat
value|FT_MAKE_TAG( 'b', 'd', 'a', 't' )
DECL|macro|TTAG_BDF
define|#
directive|define
name|TTAG_BDF
value|FT_MAKE_TAG( 'B', 'D', 'F', ' ' )
DECL|macro|TTAG_bhed
define|#
directive|define
name|TTAG_bhed
value|FT_MAKE_TAG( 'b', 'h', 'e', 'd' )
DECL|macro|TTAG_bloc
define|#
directive|define
name|TTAG_bloc
value|FT_MAKE_TAG( 'b', 'l', 'o', 'c' )
DECL|macro|TTAG_bsln
define|#
directive|define
name|TTAG_bsln
value|FT_MAKE_TAG( 'b', 's', 'l', 'n' )
DECL|macro|TTAG_CBDT
define|#
directive|define
name|TTAG_CBDT
value|FT_MAKE_TAG( 'C', 'B', 'D', 'T' )
DECL|macro|TTAG_CBLC
define|#
directive|define
name|TTAG_CBLC
value|FT_MAKE_TAG( 'C', 'B', 'L', 'C' )
DECL|macro|TTAG_CFF
define|#
directive|define
name|TTAG_CFF
value|FT_MAKE_TAG( 'C', 'F', 'F', ' ' )
DECL|macro|TTAG_CID
define|#
directive|define
name|TTAG_CID
value|FT_MAKE_TAG( 'C', 'I', 'D', ' ' )
DECL|macro|TTAG_cmap
define|#
directive|define
name|TTAG_cmap
value|FT_MAKE_TAG( 'c', 'm', 'a', 'p' )
DECL|macro|TTAG_cvar
define|#
directive|define
name|TTAG_cvar
value|FT_MAKE_TAG( 'c', 'v', 'a', 'r' )
DECL|macro|TTAG_cvt
define|#
directive|define
name|TTAG_cvt
value|FT_MAKE_TAG( 'c', 'v', 't', ' ' )
DECL|macro|TTAG_DSIG
define|#
directive|define
name|TTAG_DSIG
value|FT_MAKE_TAG( 'D', 'S', 'I', 'G' )
DECL|macro|TTAG_EBDT
define|#
directive|define
name|TTAG_EBDT
value|FT_MAKE_TAG( 'E', 'B', 'D', 'T' )
DECL|macro|TTAG_EBLC
define|#
directive|define
name|TTAG_EBLC
value|FT_MAKE_TAG( 'E', 'B', 'L', 'C' )
DECL|macro|TTAG_EBSC
define|#
directive|define
name|TTAG_EBSC
value|FT_MAKE_TAG( 'E', 'B', 'S', 'C' )
DECL|macro|TTAG_feat
define|#
directive|define
name|TTAG_feat
value|FT_MAKE_TAG( 'f', 'e', 'a', 't' )
DECL|macro|TTAG_FOND
define|#
directive|define
name|TTAG_FOND
value|FT_MAKE_TAG( 'F', 'O', 'N', 'D' )
DECL|macro|TTAG_fpgm
define|#
directive|define
name|TTAG_fpgm
value|FT_MAKE_TAG( 'f', 'p', 'g', 'm' )
DECL|macro|TTAG_fvar
define|#
directive|define
name|TTAG_fvar
value|FT_MAKE_TAG( 'f', 'v', 'a', 'r' )
DECL|macro|TTAG_gasp
define|#
directive|define
name|TTAG_gasp
value|FT_MAKE_TAG( 'g', 'a', 's', 'p' )
DECL|macro|TTAG_GDEF
define|#
directive|define
name|TTAG_GDEF
value|FT_MAKE_TAG( 'G', 'D', 'E', 'F' )
DECL|macro|TTAG_glyf
define|#
directive|define
name|TTAG_glyf
value|FT_MAKE_TAG( 'g', 'l', 'y', 'f' )
DECL|macro|TTAG_GPOS
define|#
directive|define
name|TTAG_GPOS
value|FT_MAKE_TAG( 'G', 'P', 'O', 'S' )
DECL|macro|TTAG_GSUB
define|#
directive|define
name|TTAG_GSUB
value|FT_MAKE_TAG( 'G', 'S', 'U', 'B' )
DECL|macro|TTAG_gvar
define|#
directive|define
name|TTAG_gvar
value|FT_MAKE_TAG( 'g', 'v', 'a', 'r' )
DECL|macro|TTAG_hdmx
define|#
directive|define
name|TTAG_hdmx
value|FT_MAKE_TAG( 'h', 'd', 'm', 'x' )
DECL|macro|TTAG_head
define|#
directive|define
name|TTAG_head
value|FT_MAKE_TAG( 'h', 'e', 'a', 'd' )
DECL|macro|TTAG_hhea
define|#
directive|define
name|TTAG_hhea
value|FT_MAKE_TAG( 'h', 'h', 'e', 'a' )
DECL|macro|TTAG_hmtx
define|#
directive|define
name|TTAG_hmtx
value|FT_MAKE_TAG( 'h', 'm', 't', 'x' )
DECL|macro|TTAG_JSTF
define|#
directive|define
name|TTAG_JSTF
value|FT_MAKE_TAG( 'J', 'S', 'T', 'F' )
DECL|macro|TTAG_just
define|#
directive|define
name|TTAG_just
value|FT_MAKE_TAG( 'j', 'u', 's', 't' )
DECL|macro|TTAG_kern
define|#
directive|define
name|TTAG_kern
value|FT_MAKE_TAG( 'k', 'e', 'r', 'n' )
DECL|macro|TTAG_lcar
define|#
directive|define
name|TTAG_lcar
value|FT_MAKE_TAG( 'l', 'c', 'a', 'r' )
DECL|macro|TTAG_loca
define|#
directive|define
name|TTAG_loca
value|FT_MAKE_TAG( 'l', 'o', 'c', 'a' )
DECL|macro|TTAG_LTSH
define|#
directive|define
name|TTAG_LTSH
value|FT_MAKE_TAG( 'L', 'T', 'S', 'H' )
DECL|macro|TTAG_LWFN
define|#
directive|define
name|TTAG_LWFN
value|FT_MAKE_TAG( 'L', 'W', 'F', 'N' )
DECL|macro|TTAG_MATH
define|#
directive|define
name|TTAG_MATH
value|FT_MAKE_TAG( 'M', 'A', 'T', 'H' )
DECL|macro|TTAG_maxp
define|#
directive|define
name|TTAG_maxp
value|FT_MAKE_TAG( 'm', 'a', 'x', 'p' )
DECL|macro|TTAG_META
define|#
directive|define
name|TTAG_META
value|FT_MAKE_TAG( 'M', 'E', 'T', 'A' )
DECL|macro|TTAG_MMFX
define|#
directive|define
name|TTAG_MMFX
value|FT_MAKE_TAG( 'M', 'M', 'F', 'X' )
DECL|macro|TTAG_MMSD
define|#
directive|define
name|TTAG_MMSD
value|FT_MAKE_TAG( 'M', 'M', 'S', 'D' )
DECL|macro|TTAG_mort
define|#
directive|define
name|TTAG_mort
value|FT_MAKE_TAG( 'm', 'o', 'r', 't' )
DECL|macro|TTAG_morx
define|#
directive|define
name|TTAG_morx
value|FT_MAKE_TAG( 'm', 'o', 'r', 'x' )
DECL|macro|TTAG_name
define|#
directive|define
name|TTAG_name
value|FT_MAKE_TAG( 'n', 'a', 'm', 'e' )
DECL|macro|TTAG_opbd
define|#
directive|define
name|TTAG_opbd
value|FT_MAKE_TAG( 'o', 'p', 'b', 'd' )
DECL|macro|TTAG_OS2
define|#
directive|define
name|TTAG_OS2
value|FT_MAKE_TAG( 'O', 'S', '/', '2' )
DECL|macro|TTAG_OTTO
define|#
directive|define
name|TTAG_OTTO
value|FT_MAKE_TAG( 'O', 'T', 'T', 'O' )
DECL|macro|TTAG_PCLT
define|#
directive|define
name|TTAG_PCLT
value|FT_MAKE_TAG( 'P', 'C', 'L', 'T' )
DECL|macro|TTAG_POST
define|#
directive|define
name|TTAG_POST
value|FT_MAKE_TAG( 'P', 'O', 'S', 'T' )
DECL|macro|TTAG_post
define|#
directive|define
name|TTAG_post
value|FT_MAKE_TAG( 'p', 'o', 's', 't' )
DECL|macro|TTAG_prep
define|#
directive|define
name|TTAG_prep
value|FT_MAKE_TAG( 'p', 'r', 'e', 'p' )
DECL|macro|TTAG_prop
define|#
directive|define
name|TTAG_prop
value|FT_MAKE_TAG( 'p', 'r', 'o', 'p' )
DECL|macro|TTAG_sbix
define|#
directive|define
name|TTAG_sbix
value|FT_MAKE_TAG( 's', 'b', 'i', 'x' )
DECL|macro|TTAG_sfnt
define|#
directive|define
name|TTAG_sfnt
value|FT_MAKE_TAG( 's', 'f', 'n', 't' )
DECL|macro|TTAG_SING
define|#
directive|define
name|TTAG_SING
value|FT_MAKE_TAG( 'S', 'I', 'N', 'G' )
DECL|macro|TTAG_trak
define|#
directive|define
name|TTAG_trak
value|FT_MAKE_TAG( 't', 'r', 'a', 'k' )
DECL|macro|TTAG_true
define|#
directive|define
name|TTAG_true
value|FT_MAKE_TAG( 't', 'r', 'u', 'e' )
DECL|macro|TTAG_ttc
define|#
directive|define
name|TTAG_ttc
value|FT_MAKE_TAG( 't', 't', 'c', ' ' )
DECL|macro|TTAG_ttcf
define|#
directive|define
name|TTAG_ttcf
value|FT_MAKE_TAG( 't', 't', 'c', 'f' )
DECL|macro|TTAG_TYP1
define|#
directive|define
name|TTAG_TYP1
value|FT_MAKE_TAG( 'T', 'Y', 'P', '1' )
DECL|macro|TTAG_typ1
define|#
directive|define
name|TTAG_typ1
value|FT_MAKE_TAG( 't', 'y', 'p', '1' )
DECL|macro|TTAG_VDMX
define|#
directive|define
name|TTAG_VDMX
value|FT_MAKE_TAG( 'V', 'D', 'M', 'X' )
DECL|macro|TTAG_vhea
define|#
directive|define
name|TTAG_vhea
value|FT_MAKE_TAG( 'v', 'h', 'e', 'a' )
DECL|macro|TTAG_vmtx
define|#
directive|define
name|TTAG_vmtx
value|FT_MAKE_TAG( 'v', 'm', 't', 'x' )
DECL|macro|TTAG_wOFF
define|#
directive|define
name|TTAG_wOFF
value|FT_MAKE_TAG( 'w', 'O', 'F', 'F' )
name|FT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTAGS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
