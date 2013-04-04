begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttgxvar.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType GX Font Variation loader (specification)                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004 by                                                      */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, Werner Lemberg and George Williams.      */
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
name|__TTGXVAR_H__
end_ifndef
begin_define
DECL|macro|__TTGXVAR_H__
define|#
directive|define
name|__TTGXVAR_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"ttobjs.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    GX_AVarCorrespondenceRec                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A data structure representing `shortFracCorrespondence' in `avar'  */
end_comment
begin_comment
comment|/*    table according to the specifications from Apple.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|GX_AVarCorrespondenceRec_
typedef|typedef
struct|struct
name|GX_AVarCorrespondenceRec_
block|{
DECL|member|fromCoord
name|FT_Fixed
name|fromCoord
decl_stmt|;
DECL|member|toCoord
name|FT_Fixed
name|toCoord
decl_stmt|;
block|}
DECL|typedef|GX_AVarCorrespondenceRec_
DECL|typedef|GX_AVarCorrespondence
name|GX_AVarCorrespondenceRec_
operator|,
typedef|*
name|GX_AVarCorrespondence
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    GX_AVarRec                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Data from the segment field of `avar' table.                       */
end_comment
begin_comment
comment|/*    There is one of these for each axis.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|GX_AVarSegmentRec_
typedef|typedef
struct|struct
name|GX_AVarSegmentRec_
block|{
DECL|member|pairCount
name|FT_UShort
name|pairCount
decl_stmt|;
DECL|member|correspondence
name|GX_AVarCorrespondence
name|correspondence
decl_stmt|;
comment|/* array with pairCount entries */
block|}
DECL|typedef|GX_AVarSegmentRec
DECL|typedef|GX_AVarSegment
name|GX_AVarSegmentRec
operator|,
typedef|*
name|GX_AVarSegment
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    GX_BlendRec                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Data for interpolating a font from a distortable font specified    */
end_comment
begin_comment
comment|/*    by the GX *var tables ([fgca]var).                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    num_axis         :: The number of axes along which interpolation   */
end_comment
begin_comment
comment|/*                         may happen                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    normalizedcoords :: A normalized value (between [-1,1]) indicating */
end_comment
begin_comment
comment|/*                        the contribution along each axis to the final  */
end_comment
begin_comment
comment|/*                        interpolated font.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|GX_BlendRec_
typedef|typedef
struct|struct
name|GX_BlendRec_
block|{
DECL|member|num_axis
name|FT_UInt
name|num_axis
decl_stmt|;
DECL|member|normalizedcoords
name|FT_Fixed
modifier|*
name|normalizedcoords
decl_stmt|;
DECL|member|mmvar
name|FT_MM_Var
modifier|*
name|mmvar
decl_stmt|;
DECL|member|mmvar_len
name|FT_Offset
name|mmvar_len
decl_stmt|;
DECL|member|avar_checked
name|FT_Bool
name|avar_checked
decl_stmt|;
DECL|member|avar_segment
name|GX_AVarSegment
name|avar_segment
decl_stmt|;
DECL|member|tuplecount
name|FT_UInt
name|tuplecount
decl_stmt|;
comment|/* shared tuples in `gvar'           */
DECL|member|tuplecoords
name|FT_Fixed
modifier|*
name|tuplecoords
decl_stmt|;
comment|/* tuplecoords[tuplecount][num_axis] */
DECL|member|gv_glyphcnt
name|FT_UInt
name|gv_glyphcnt
decl_stmt|;
DECL|member|glyphoffsets
name|FT_ULong
modifier|*
name|glyphoffsets
decl_stmt|;
block|}
DECL|typedef|GX_BlendRec
name|GX_BlendRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<enum>                                                                */
end_comment
begin_comment
comment|/*    GX_TupleCountFlags                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Flags used within the `TupleCount' field of the `gvar' table.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|GX_TupleCountFlags_
typedef|typedef
enum|enum
name|GX_TupleCountFlags_
block|{
DECL|enumerator|GX_TC_TUPLES_SHARE_POINT_NUMBERS
name|GX_TC_TUPLES_SHARE_POINT_NUMBERS
init|=
literal|0x8000
block|,
DECL|enumerator|GX_TC_RESERVED_TUPLE_FLAGS
name|GX_TC_RESERVED_TUPLE_FLAGS
init|=
literal|0x7000
block|,
DECL|enumerator|GX_TC_TUPLE_COUNT_MASK
name|GX_TC_TUPLE_COUNT_MASK
init|=
literal|0x0FFF
block|}
DECL|typedef|GX_TupleCountFlags
name|GX_TupleCountFlags
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<enum>                                                                */
end_comment
begin_comment
comment|/*    GX_TupleIndexFlags                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Flags used within the `TupleIndex' field of the `gvar' and `cvar'  */
end_comment
begin_comment
comment|/*    tables.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|GX_TupleIndexFlags_
typedef|typedef
enum|enum
name|GX_TupleIndexFlags_
block|{
DECL|enumerator|GX_TI_EMBEDDED_TUPLE_COORD
name|GX_TI_EMBEDDED_TUPLE_COORD
init|=
literal|0x8000
block|,
DECL|enumerator|GX_TI_INTERMEDIATE_TUPLE
name|GX_TI_INTERMEDIATE_TUPLE
init|=
literal|0x4000
block|,
DECL|enumerator|GX_TI_PRIVATE_POINT_NUMBERS
name|GX_TI_PRIVATE_POINT_NUMBERS
init|=
literal|0x2000
block|,
DECL|enumerator|GX_TI_RESERVED_TUPLE_FLAG
name|GX_TI_RESERVED_TUPLE_FLAG
init|=
literal|0x1000
block|,
DECL|enumerator|GX_TI_TUPLE_INDEX_MASK
name|GX_TI_TUPLE_INDEX_MASK
init|=
literal|0x0FFF
block|}
DECL|typedef|GX_TupleIndexFlags
name|GX_TupleIndexFlags
typedef|;
end_typedef
begin_define
DECL|macro|TTAG_wght
define|#
directive|define
name|TTAG_wght
value|FT_MAKE_TAG( 'w', 'g', 'h', 't' )
end_define
begin_define
DECL|macro|TTAG_wdth
define|#
directive|define
name|TTAG_wdth
value|FT_MAKE_TAG( 'w', 'd', 't', 'h' )
end_define
begin_define
DECL|macro|TTAG_opsz
define|#
directive|define
name|TTAG_opsz
value|FT_MAKE_TAG( 'o', 'p', 's', 'z' )
end_define
begin_define
DECL|macro|TTAG_slnt
define|#
directive|define
name|TTAG_slnt
value|FT_MAKE_TAG( 's', 'l', 'n', 't' )
end_define
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|TT_Set_MM_Blend
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_UInt    num_coords
argument_list|,
argument|FT_Fixed*  coords
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|TT_Set_Var_Design
name|TT_Set_Var_Design
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_UInt    num_coords
argument_list|,
argument|FT_Fixed*  coords
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|TT_Get_MM_Var
argument_list|(
argument|TT_Face      face
argument_list|,
argument|FT_MM_Var*  *master
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|tt_face_vary_cvt
name|tt_face_vary_cvt
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|TT_Vary_Get_Glyph_Deltas
argument_list|(
argument|TT_Face      face
argument_list|,
argument|FT_UInt      glyph_index
argument_list|,
argument|FT_Vector*  *deltas
argument_list|,
argument|FT_UInt      n_points
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|tt_done_blend
name|tt_done_blend
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|GX_Blend   blend
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTGXVAR_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
