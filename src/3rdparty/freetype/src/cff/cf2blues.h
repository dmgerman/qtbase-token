begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2blues.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for handling Blue Zones (specification).                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2009-2013 Adobe Systems Incorporated.                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This software, and all works of authorship, whether in source or       */
end_comment
begin_comment
comment|/*  object code form as indicated by the copyright notice(s) included      */
end_comment
begin_comment
comment|/*  herein (collectively, the "Work") is made available, and may only be   */
end_comment
begin_comment
comment|/*  used, modified, and distributed under the FreeType Project License,    */
end_comment
begin_comment
comment|/*  LICENSE.TXT.  Additionally, subject to the terms and conditions of the */
end_comment
begin_comment
comment|/*  FreeType Project License, each contributor to the Work hereby grants   */
end_comment
begin_comment
comment|/*  to any individual or legal entity exercising permissions granted by    */
end_comment
begin_comment
comment|/*  the FreeType Project License and this section (hereafter, "You" or     */
end_comment
begin_comment
comment|/*  "Your") a perpetual, worldwide, non-exclusive, no-charge,              */
end_comment
begin_comment
comment|/*  royalty-free, irrevocable (except as stated in this section) patent    */
end_comment
begin_comment
comment|/*  license to make, have made, use, offer to sell, sell, import, and      */
end_comment
begin_comment
comment|/*  otherwise transfer the Work, where such license applies only to those  */
end_comment
begin_comment
comment|/*  patent claims licensable by such contributor that are necessarily      */
end_comment
begin_comment
comment|/*  infringed by their contribution(s) alone or by combination of their    */
end_comment
begin_comment
comment|/*  contribution(s) with the Work to which such contribution(s) was        */
end_comment
begin_comment
comment|/*  submitted.  If You institute patent litigation against any entity      */
end_comment
begin_comment
comment|/*  (including a cross-claim or counterclaim in a lawsuit) alleging that   */
end_comment
begin_comment
comment|/*  the Work or a contribution incorporated within the Work constitutes    */
end_comment
begin_comment
comment|/*  direct or contributory patent infringement, then any patent licenses   */
end_comment
begin_comment
comment|/*  granted to You under this License for that Work shall terminate as of  */
end_comment
begin_comment
comment|/*  the date such litigation is filed.                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  By using, modifying, or distributing the Work you indicate that you    */
end_comment
begin_comment
comment|/*  have read and understood the terms and conditions of the               */
end_comment
begin_comment
comment|/*  FreeType Project License as well as those provided in this section,    */
end_comment
begin_comment
comment|/*  and you accept them fully.                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*    * A `CF2_Blues' object stores the blue zones (horizontal alignment    * zones) of a font.  These are specified in the CFF private dictionary    * by `BlueValues', `OtherBlues', `FamilyBlues', and `FamilyOtherBlues'.    * Each zone is defined by a top and bottom edge in character space.    * Further, each zone is either a top zone or a bottom zone, as recorded    * by `bottomZone'.    *    * The maximum number of `BlueValues' and `FamilyBlues' is 7 each.    * However, these are combined to produce a total of 7 zones.    * Similarly, the maximum number of `OtherBlues' and `FamilyOtherBlues'    * is 5 and these are combined to produce an additional 5 zones.    *    * Blue zones are used to `capture' hints and force them to a common    * alignment point.  This alignment is recorded in device space in    * `dsFlatEdge'.  Except for this value, a `CF2_Blues' object could be    * constructed independently of scaling.  Construction may occur once    * the matrix is known.  Other features implemented in the Capture    * method are overshoot suppression, overshoot enforcement, and Blue    * Boost.    *    * Capture is determined by `BlueValues' and `OtherBlues', but the    * alignment point may be adjusted to the scaled flat edge of    * `FamilyBlues' or `FamilyOtherBlues'.  No alignment is done to the    * curved edge of a zone.    *    */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__CF2BLUES_H__
end_ifndef
begin_define
DECL|macro|__CF2BLUES_H__
define|#
directive|define
name|__CF2BLUES_H__
end_define
begin_include
include|#
directive|include
file|"cf2glue.h"
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/*    * `CF2_Hint' is shared by `cf2hints.h' and    * `cf2blues.h', but `cf2blues.h' depends on    * `cf2hints.h', so define it here.  Note: The typedef is in    * `cf2glue.h'.    *    */
name|enum
type|{
DECL|enumerator|CF2_GhostBottom
name|CF2_GhostBottom
init|=
literal|0x1
decl_stmt|,
comment|/* a single bottom edge           */
DECL|enumerator|CF2_GhostTop
name|CF2_GhostTop
init|=
literal|0x2
decl_stmt|,
comment|/* a single top edge              */
DECL|enumerator|CF2_PairBottom
name|CF2_PairBottom
init|=
literal|0x4
decl_stmt|,
comment|/* the bottom edge of a stem hint */
DECL|enumerator|CF2_PairTop
name|CF2_PairTop
init|=
literal|0x8
decl_stmt|,
comment|/* the top edge of a stem hint    */
DECL|enumerator|CF2_Locked
name|CF2_Locked
init|=
literal|0x10
decl_stmt|,
comment|/* this edge has been aligned     */
comment|/* by a blue zone                 */
DECL|enumerator|CF2_Synthetic
name|CF2_Synthetic
init|=
literal|0x20
end_decl_stmt
begin_comment
DECL|enumerator|CF2_Synthetic
comment|/* this edge was synthesized      */
end_comment
begin_comment
unit|};
comment|/*    * Default value for OS/2 typoAscender/Descender when their difference    * is not equal to `unitsPerEm'.  The default is based on -250 and 1100    * in `CF2_Blues', assuming 1000 units per em here.    *    */
end_comment
begin_enum
enum|enum
block|{
DECL|enumerator|CF2_ICF_Top
name|CF2_ICF_Top
init|=
name|cf2_intToFixed
argument_list|(
literal|880
argument_list|)
block|,
DECL|enumerator|CF2_ICF_Bottom
name|CF2_ICF_Bottom
init|=
name|cf2_intToFixed
argument_list|(
argument|-
literal|120
argument_list|)
block|}
enum|;
end_enum
begin_comment
comment|/*    * Constant used for hint adjustment and for synthetic em box hint    * placement.    */
end_comment
begin_define
DECL|macro|CF2_MIN_COUNTER
define|#
directive|define
name|CF2_MIN_COUNTER
value|cf2_floatToFixed( 0.5 )
end_define
begin_comment
comment|/* shared typedef is in cf2glue.h */
end_comment
begin_struct
DECL|struct|CF2_HintRec_
struct|struct
name|CF2_HintRec_
block|{
DECL|member|flags
name|CF2_UInt
name|flags
decl_stmt|;
comment|/* attributes of the edge            */
DECL|member|index
name|size_t
name|index
decl_stmt|;
comment|/* index in original stem hint array */
comment|/* (if not synthetic)                */
DECL|member|csCoord
name|CF2_Fixed
name|csCoord
decl_stmt|;
DECL|member|dsCoord
name|CF2_Fixed
name|dsCoord
decl_stmt|;
DECL|member|scale
name|CF2_Fixed
name|scale
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|struct|CF2_BlueRec_
typedef|typedef
struct|struct
name|CF2_BlueRec_
block|{
DECL|member|csBottomEdge
name|CF2_Fixed
name|csBottomEdge
decl_stmt|;
DECL|member|csTopEdge
name|CF2_Fixed
name|csTopEdge
decl_stmt|;
DECL|member|csFlatEdge
name|CF2_Fixed
name|csFlatEdge
decl_stmt|;
comment|/* may be from either local or Family zones */
DECL|member|dsFlatEdge
name|CF2_Fixed
name|dsFlatEdge
decl_stmt|;
comment|/* top edge of bottom zone or bottom edge   */
comment|/* of top zone (rounded)                    */
DECL|member|bottomZone
name|FT_Bool
name|bottomZone
decl_stmt|;
block|}
DECL|typedef|CF2_BlueRec
name|CF2_BlueRec
typedef|;
end_typedef
begin_comment
comment|/* max total blue zones is 12 */
end_comment
begin_enum
enum|enum
block|{
DECL|enumerator|CF2_MAX_BLUES
name|CF2_MAX_BLUES
init|=
literal|7
block|,
DECL|enumerator|CF2_MAX_OTHERBLUES
name|CF2_MAX_OTHERBLUES
init|=
literal|5
block|}
enum|;
end_enum
begin_typedef
DECL|struct|CF2_BluesRec_
typedef|typedef
struct|struct
name|CF2_BluesRec_
block|{
DECL|member|scale
name|CF2_Fixed
name|scale
decl_stmt|;
DECL|member|count
name|CF2_UInt
name|count
decl_stmt|;
DECL|member|suppressOvershoot
name|FT_Bool
name|suppressOvershoot
decl_stmt|;
DECL|member|doEmBoxHints
name|FT_Bool
name|doEmBoxHints
decl_stmt|;
DECL|member|blueScale
name|CF2_Fixed
name|blueScale
decl_stmt|;
DECL|member|blueShift
name|CF2_Fixed
name|blueShift
decl_stmt|;
DECL|member|blueFuzz
name|CF2_Fixed
name|blueFuzz
decl_stmt|;
DECL|member|boost
name|CF2_Fixed
name|boost
decl_stmt|;
DECL|member|emBoxTopEdge
name|CF2_HintRec
name|emBoxTopEdge
decl_stmt|;
DECL|member|emBoxBottomEdge
name|CF2_HintRec
name|emBoxBottomEdge
decl_stmt|;
DECL|member|zone
name|CF2_BlueRec
name|zone
index|[
name|CF2_MAX_BLUES
operator|+
name|CF2_MAX_OTHERBLUES
index|]
decl_stmt|;
block|}
DECL|typedef|CF2_BluesRec
DECL|typedef|CF2_Blues
name|CF2_BluesRec
operator|,
typedef|*
name|CF2_Blues
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_blues_init
argument_list|(
argument|CF2_Blues  blues
argument_list|,
argument|CF2_Font   font
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|cf2_blues_capture
argument_list|(
argument|const CF2_Blues  blues
argument_list|,
argument|CF2_Hint         bottomHintEdge
argument_list|,
argument|CF2_Hint         topHintEdge
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
comment|/* __CF2BLUES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
