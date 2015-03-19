begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2hints.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for handling CFF hints (body).                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007-2013 Adobe Systems Incorporated.                        */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__CF2HINTS_H__
end_ifndef
begin_define
DECL|macro|__CF2HINTS_H__
define|#
directive|define
name|__CF2HINTS_H__
end_define
begin_decl_stmt
name|FT_BEGIN_HEADER
name|enum
type|{
DECL|enumerator|CF2_MAX_HINTS
name|CF2_MAX_HINTS
init|=
literal|96
end_decl_stmt
begin_comment
DECL|enumerator|CF2_MAX_HINTS
comment|/* maximum # of hints */
end_comment
begin_comment
unit|};
comment|/*    * A HintMask object stores a bit mask that specifies which hints in the    * charstring are active at a given time.  Hints in CFF must be declared    * at the start, before any drawing operators, with horizontal hints    * preceding vertical hints.  The HintMask is ordered the same way, with    * horizontal hints immediately followed by vertical hints.  Clients are    * responsible for knowing how many of each type are present.    *    * The maximum total number of hints is 96, as specified by the CFF    * specification.    *    * A HintMask is built 0 or more times while interpreting a charstring, by    * the HintMask operator.  There is only one HintMask, but it is built or    * rebuilt each time there is a hint substitution (HintMask operator) in    * the charstring.  A default HintMask with all bits set is built if there    * has been no HintMask operator prior to the first drawing operator.    *    */
end_comment
begin_typedef
DECL|struct|CF2_HintMaskRec_
typedef|typedef
struct|struct
name|CF2_HintMaskRec_
block|{
DECL|member|error
name|FT_Error
modifier|*
name|error
decl_stmt|;
DECL|member|isValid
name|FT_Bool
name|isValid
decl_stmt|;
DECL|member|isNew
name|FT_Bool
name|isNew
decl_stmt|;
DECL|member|bitCount
name|size_t
name|bitCount
decl_stmt|;
DECL|member|byteCount
name|size_t
name|byteCount
decl_stmt|;
DECL|member|mask
name|FT_Byte
name|mask
index|[
operator|(
name|CF2_MAX_HINTS
operator|+
literal|7
operator|)
operator|/
literal|8
index|]
decl_stmt|;
block|}
DECL|typedef|CF2_HintMaskRec
DECL|typedef|CF2_HintMask
name|CF2_HintMaskRec
operator|,
typedef|*
name|CF2_HintMask
typedef|;
end_typedef
begin_typedef
DECL|struct|CF2_StemHintRec_
typedef|typedef
struct|struct
name|CF2_StemHintRec_
block|{
DECL|member|used
name|FT_Bool
name|used
decl_stmt|;
comment|/* DS positions are valid         */
DECL|member|min
name|CF2_Fixed
name|min
decl_stmt|;
comment|/* original character space value */
DECL|member|max
name|CF2_Fixed
name|max
decl_stmt|;
DECL|member|minDS
name|CF2_Fixed
name|minDS
decl_stmt|;
comment|/* DS position after first use    */
DECL|member|maxDS
name|CF2_Fixed
name|maxDS
decl_stmt|;
block|}
DECL|typedef|CF2_StemHintRec
DECL|typedef|CF2_StemHint
name|CF2_StemHintRec
operator|,
typedef|*
name|CF2_StemHint
typedef|;
end_typedef
begin_comment
comment|/*    * A HintMap object stores a piecewise linear function for mapping    * y-coordinates from character space to device space, providing    * appropriate pixel alignment to stem edges.    *    * The map is implemented as an array of `CF2_Hint' elements, each    * representing an edge.  When edges are paired, as from stem hints, the    * bottom edge must immediately precede the top edge in the array.    * Element character space AND device space positions must both increase    * monotonically in the array.  `CF2_Hint' elements are also used as    * parameters to `cf2_blues_capture'.    *    * The `cf2_hintmap_build' method must be called before any drawing    * operation (beginning with a Move operator) and at each hint    * substitution (HintMask operator).    *    * The `cf2_hintmap_map' method is called to transform y-coordinates at    * each drawing operation (move, line, curve).    *    */
end_comment
begin_comment
comment|/* TODO: make this a CF2_ArrStack and add a deep copy method */
end_comment
begin_enum
enum|enum
block|{
DECL|enumerator|CF2_MAX_HINT_EDGES
name|CF2_MAX_HINT_EDGES
init|=
name|CF2_MAX_HINTS
operator|*
literal|2
block|}
enum|;
end_enum
begin_typedef
DECL|struct|CF2_HintMapRec_
typedef|typedef
struct|struct
name|CF2_HintMapRec_
block|{
DECL|member|font
name|CF2_Font
name|font
decl_stmt|;
comment|/* initial map based on blue zones */
DECL|member|initialHintMap
name|struct
name|CF2_HintMapRec_
modifier|*
name|initialHintMap
decl_stmt|;
comment|/* working storage for 2nd pass adjustHints */
DECL|member|hintMoves
name|CF2_ArrStack
name|hintMoves
decl_stmt|;
DECL|member|isValid
name|FT_Bool
name|isValid
decl_stmt|;
DECL|member|hinted
name|FT_Bool
name|hinted
decl_stmt|;
DECL|member|scale
name|CF2_Fixed
name|scale
decl_stmt|;
DECL|member|count
name|CF2_UInt
name|count
decl_stmt|;
comment|/* start search from this index */
DECL|member|lastIndex
name|CF2_UInt
name|lastIndex
decl_stmt|;
DECL|member|edge
name|CF2_HintRec
name|edge
index|[
name|CF2_MAX_HINT_EDGES
index|]
decl_stmt|;
comment|/* 192 */
block|}
DECL|typedef|CF2_HintMapRec
DECL|typedef|CF2_HintMap
name|CF2_HintMapRec
operator|,
typedef|*
name|CF2_HintMap
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|cf2_hint_isValid
argument_list|(
argument|const CF2_Hint  hint
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
DECL|variable|cf2_hint_isTop
name|cf2_hint_isTop
argument_list|(
argument|const CF2_Hint  hint
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cf2_hint_isTop
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|cf2_hint_isBottom
argument_list|(
argument|const CF2_Hint  hint
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
DECL|variable|cf2_hint_lock
name|cf2_hint_lock
argument_list|(
argument|CF2_Hint  hint
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cf2_hint_lock
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_hintmap_init
argument_list|(
argument|CF2_HintMap   hintmap
argument_list|,
argument|CF2_Font      font
argument_list|,
argument|CF2_HintMap   initialMap
argument_list|,
argument|CF2_ArrStack  hintMoves
argument_list|,
argument|CF2_Fixed     scale
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
name|cf2_hintmap_build
argument_list|(
argument|CF2_HintMap   hintmap
argument_list|,
argument|CF2_ArrStack  hStemHintArray
argument_list|,
argument|CF2_ArrStack  vStemHintArray
argument_list|,
argument|CF2_HintMask  hintMask
argument_list|,
argument|CF2_Fixed     hintOrigin
argument_list|,
argument|FT_Bool       initialMap
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    * GlyphPath is a wrapper for drawing operations that scales the    * coordinates according to the render matrix and HintMap.  It also tracks    * open paths to control ClosePath and to insert MoveTo for broken fonts.    *    */
end_comment
begin_typedef
DECL|struct|CF2_GlyphPathRec_
typedef|typedef
struct|struct
name|CF2_GlyphPathRec_
block|{
comment|/* TODO: gather some of these into a hinting context */
DECL|member|font
name|CF2_Font
name|font
decl_stmt|;
comment|/* font instance    */
DECL|member|callbacks
name|CF2_OutlineCallbacks
name|callbacks
decl_stmt|;
comment|/* outline consumer */
DECL|member|hintMap
name|CF2_HintMapRec
name|hintMap
decl_stmt|;
comment|/* current hint map            */
DECL|member|firstHintMap
name|CF2_HintMapRec
name|firstHintMap
decl_stmt|;
comment|/* saved copy                  */
DECL|member|initialHintMap
name|CF2_HintMapRec
name|initialHintMap
decl_stmt|;
comment|/* based on all captured hints */
DECL|member|hintMoves
name|CF2_ArrStackRec
name|hintMoves
decl_stmt|;
comment|/* list of hint moves for 2nd pass */
DECL|member|scaleX
name|CF2_Fixed
name|scaleX
decl_stmt|;
comment|/* matrix a */
DECL|member|scaleC
name|CF2_Fixed
name|scaleC
decl_stmt|;
comment|/* matrix c */
DECL|member|scaleY
name|CF2_Fixed
name|scaleY
decl_stmt|;
comment|/* matrix d */
DECL|member|fractionalTranslation
name|FT_Vector
name|fractionalTranslation
decl_stmt|;
comment|/* including deviceXScale */
if|#
directive|if
literal|0
block|CF2_Fixed  hShift;
comment|/* character space horizontal shift */
comment|/* (for fauxing)                    */
endif|#
directive|endif
DECL|member|pathIsOpen
name|FT_Bool
name|pathIsOpen
decl_stmt|;
comment|/* true after MoveTo                     */
DECL|member|pathIsClosing
name|FT_Bool
name|pathIsClosing
decl_stmt|;
comment|/* true when synthesizing closepath line */
DECL|member|darken
name|FT_Bool
name|darken
decl_stmt|;
comment|/* true if stem darkening                */
DECL|member|moveIsPending
name|FT_Bool
name|moveIsPending
decl_stmt|;
comment|/* true between MoveTo and offset MoveTo */
comment|/* references used to call `cf2_hintmap_build', if necessary */
DECL|member|hStemHintArray
name|CF2_ArrStack
name|hStemHintArray
decl_stmt|;
DECL|member|vStemHintArray
name|CF2_ArrStack
name|vStemHintArray
decl_stmt|;
DECL|member|hintMask
name|CF2_HintMask
name|hintMask
decl_stmt|;
comment|/* ptr to the current mask */
DECL|member|hintOriginY
name|CF2_Fixed
name|hintOriginY
decl_stmt|;
comment|/* copy of current origin  */
DECL|member|blues
specifier|const
name|CF2_BluesRec
modifier|*
name|blues
decl_stmt|;
DECL|member|xOffset
name|CF2_Fixed
name|xOffset
decl_stmt|;
comment|/* character space offsets */
DECL|member|yOffset
name|CF2_Fixed
name|yOffset
decl_stmt|;
comment|/* character space miter limit threshold */
DECL|member|miterLimit
name|CF2_Fixed
name|miterLimit
decl_stmt|;
comment|/* vertical/horzizontal snap distance in character space */
DECL|member|snapThreshold
name|CF2_Fixed
name|snapThreshold
decl_stmt|;
DECL|member|offsetStart0
name|FT_Vector
name|offsetStart0
decl_stmt|;
comment|/* first and second points of first */
DECL|member|offsetStart1
name|FT_Vector
name|offsetStart1
decl_stmt|;
comment|/* element with offset applied      */
comment|/* current point, character space, before offset */
DECL|member|currentCS
name|FT_Vector
name|currentCS
decl_stmt|;
comment|/* current point, device space */
DECL|member|currentDS
name|FT_Vector
name|currentDS
decl_stmt|;
comment|/* start point of subpath, character space */
DECL|member|start
name|FT_Vector
name|start
decl_stmt|;
comment|/* the following members constitute the `queue' of one element */
DECL|member|elemIsQueued
name|FT_Bool
name|elemIsQueued
decl_stmt|;
DECL|member|prevElemOp
name|CF2_Int
name|prevElemOp
decl_stmt|;
DECL|member|prevElemP0
name|FT_Vector
name|prevElemP0
decl_stmt|;
DECL|member|prevElemP1
name|FT_Vector
name|prevElemP1
decl_stmt|;
DECL|member|prevElemP2
name|FT_Vector
name|prevElemP2
decl_stmt|;
DECL|member|prevElemP3
name|FT_Vector
name|prevElemP3
decl_stmt|;
block|}
DECL|typedef|CF2_GlyphPathRec
DECL|typedef|CF2_GlyphPath
name|CF2_GlyphPathRec
operator|,
typedef|*
name|CF2_GlyphPath
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_glyphpath_init
argument_list|(
argument|CF2_GlyphPath         glyphpath
argument_list|,
argument|CF2_Font              font
argument_list|,
argument|CF2_OutlineCallbacks  callbacks
argument_list|,
argument|CF2_Fixed             scaleY
argument_list|,
comment|/* CF2_Fixed hShift, */
argument|CF2_ArrStack          hStemHintArray
argument_list|,
argument|CF2_ArrStack          vStemHintArray
argument_list|,
argument|CF2_HintMask          hintMask
argument_list|,
argument|CF2_Fixed             hintOrigin
argument_list|,
argument|const CF2_Blues       blues
argument_list|,
argument|const FT_Vector*      fractionalTranslation
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
DECL|variable|glyphpath
name|cf2_glyphpath_finalize
argument_list|(
argument|CF2_GlyphPath  glyphpath
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|glyphpath
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_glyphpath_moveTo
argument_list|(
argument|CF2_GlyphPath  glyphpath
argument_list|,
argument|CF2_Fixed      x
argument_list|,
argument|CF2_Fixed      y
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
name|cf2_glyphpath_lineTo
argument_list|(
argument|CF2_GlyphPath  glyphpath
argument_list|,
argument|CF2_Fixed      x
argument_list|,
argument|CF2_Fixed      y
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
name|cf2_glyphpath_curveTo
argument_list|(
argument|CF2_GlyphPath  glyphpath
argument_list|,
argument|CF2_Fixed      x1
argument_list|,
argument|CF2_Fixed      y1
argument_list|,
argument|CF2_Fixed      x2
argument_list|,
argument|CF2_Fixed      y2
argument_list|,
argument|CF2_Fixed      x3
argument_list|,
argument|CF2_Fixed      y3
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
DECL|variable|glyphpath
name|cf2_glyphpath_closeOpenPath
argument_list|(
argument|CF2_GlyphPath  glyphpath
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|glyphpath
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
comment|/* __CF2HINTS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
