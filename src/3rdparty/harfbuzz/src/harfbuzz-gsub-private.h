begin_unit
begin_comment
comment|/*  * Copyright (C) 1998-2004  David Turner and Werner Lemberg  * Copyright (C) 2006  Behdad Esfahbod  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HARFBUZZ_GSUB_PRIVATE_H
end_ifndef
begin_define
DECL|macro|HARFBUZZ_GSUB_PRIVATE_H
define|#
directive|define
name|HARFBUZZ_GSUB_PRIVATE_H
end_define
begin_include
include|#
directive|include
file|"harfbuzz-impl.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-stream-private.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-gsub.h"
end_include
begin_macro
name|HB_BEGIN_HEADER
end_macro
begin_typedef
DECL|typedef|HB_GSUB_SubTable
typedef|typedef
name|union
name|HB_GSUB_SubTable_
name|HB_GSUB_SubTable
typedef|;
end_typedef
begin_comment
comment|/* LookupType 1 */
end_comment
begin_struct
DECL|struct|HB_SingleSubstFormat1_
struct|struct
name|HB_SingleSubstFormat1_
block|{
DECL|member|DeltaGlyphID
name|HB_Short
name|DeltaGlyphID
decl_stmt|;
comment|/* constant added to get 					 substitution glyph index */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SingleSubstFormat1
typedef|typedef
name|struct
name|HB_SingleSubstFormat1_
name|HB_SingleSubstFormat1
typedef|;
end_typedef
begin_struct
DECL|struct|HB_SingleSubstFormat2_
struct|struct
name|HB_SingleSubstFormat2_
block|{
DECL|member|Substitute
name|HB_UShort
modifier|*
name|Substitute
decl_stmt|;
comment|/* array of substitute glyph IDs */
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* number of glyph IDs in 					 Substitute array              */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SingleSubstFormat2
typedef|typedef
name|struct
name|HB_SingleSubstFormat2_
name|HB_SingleSubstFormat2
typedef|;
end_typedef
begin_struct
DECL|struct|HB_SingleSubst_
struct|struct
name|HB_SingleSubst_
block|{
union|union
block|{
DECL|member|ssf1
name|HB_SingleSubstFormat1
name|ssf1
decl_stmt|;
DECL|member|ssf2
name|HB_SingleSubstFormat2
name|ssf2
decl_stmt|;
block|}
DECL|member|ssf
name|ssf
union|;
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table */
DECL|member|SubstFormat
name|HB_Byte
name|SubstFormat
decl_stmt|;
comment|/* 1 or 2         */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SingleSubst
typedef|typedef
name|struct
name|HB_SingleSubst_
name|HB_SingleSubst
typedef|;
end_typedef
begin_comment
comment|/* LookupType 2 */
end_comment
begin_struct
DECL|struct|HB_Sequence_
struct|struct
name|HB_Sequence_
block|{
DECL|member|Substitute
name|HB_UShort
modifier|*
name|Substitute
decl_stmt|;
comment|/* string of glyph IDs to 					 substitute                 */
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* number of glyph IDs in the 					 Substitute array           */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_Sequence
typedef|typedef
name|struct
name|HB_Sequence_
name|HB_Sequence
typedef|;
end_typedef
begin_struct
DECL|struct|HB_MultipleSubst_
struct|struct
name|HB_MultipleSubst_
block|{
DECL|member|Sequence
name|HB_Sequence
modifier|*
name|Sequence
decl_stmt|;
comment|/* array of Sequence tables  */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table            */
DECL|member|SubstFormat
name|HB_UShort
name|SubstFormat
decl_stmt|;
comment|/* always 1                  */
DECL|member|SequenceCount
name|HB_UShort
name|SequenceCount
decl_stmt|;
comment|/* number of Sequence tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_MultipleSubst
typedef|typedef
name|struct
name|HB_MultipleSubst_
name|HB_MultipleSubst
typedef|;
end_typedef
begin_comment
comment|/* LookupType 3 */
end_comment
begin_struct
DECL|struct|HB_AlternateSet_
struct|struct
name|HB_AlternateSet_
block|{
DECL|member|Alternate
name|HB_UShort
modifier|*
name|Alternate
decl_stmt|;
comment|/* array of alternate glyph IDs */
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* number of glyph IDs in the 					 Alternate array              */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_AlternateSet
typedef|typedef
name|struct
name|HB_AlternateSet_
name|HB_AlternateSet
typedef|;
end_typedef
begin_struct
DECL|struct|HB_AlternateSubst_
struct|struct
name|HB_AlternateSubst_
block|{
DECL|member|AlternateSet
name|HB_AlternateSet
modifier|*
name|AlternateSet
decl_stmt|;
comment|/* array of AlternateSet tables  */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table                */
DECL|member|SubstFormat
name|HB_UShort
name|SubstFormat
decl_stmt|;
comment|/* always 1                      */
DECL|member|AlternateSetCount
name|HB_UShort
name|AlternateSetCount
decl_stmt|;
comment|/* number of AlternateSet tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_AlternateSubst
typedef|typedef
name|struct
name|HB_AlternateSubst_
name|HB_AlternateSubst
typedef|;
end_typedef
begin_comment
comment|/* LookupType 4 */
end_comment
begin_struct
DECL|struct|HB_Ligature_
struct|struct
name|HB_Ligature_
block|{
DECL|member|Component
name|HB_UShort
modifier|*
name|Component
decl_stmt|;
comment|/* array of component glyph IDs     */
DECL|member|LigGlyph
name|HB_UShort
name|LigGlyph
decl_stmt|;
comment|/* glyphID of ligature 					 to substitute                    */
DECL|member|ComponentCount
name|HB_UShort
name|ComponentCount
decl_stmt|;
comment|/* number of components in ligature */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_Ligature
typedef|typedef
name|struct
name|HB_Ligature_
name|HB_Ligature
typedef|;
end_typedef
begin_struct
DECL|struct|HB_LigatureSet_
struct|struct
name|HB_LigatureSet_
block|{
DECL|member|Ligature
name|HB_Ligature
modifier|*
name|Ligature
decl_stmt|;
comment|/* array of Ligature tables  */
DECL|member|LigatureCount
name|HB_UShort
name|LigatureCount
decl_stmt|;
comment|/* number of Ligature tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_LigatureSet
typedef|typedef
name|struct
name|HB_LigatureSet_
name|HB_LigatureSet
typedef|;
end_typedef
begin_struct
DECL|struct|HB_LigatureSubst_
struct|struct
name|HB_LigatureSubst_
block|{
DECL|member|LigatureSet
name|HB_LigatureSet
modifier|*
name|LigatureSet
decl_stmt|;
comment|/* array of LigatureSet tables  */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table               */
DECL|member|SubstFormat
name|HB_UShort
name|SubstFormat
decl_stmt|;
comment|/* always 1                     */
DECL|member|LigatureSetCount
name|HB_UShort
name|LigatureSetCount
decl_stmt|;
comment|/* number of LigatureSet tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_LigatureSubst
typedef|typedef
name|struct
name|HB_LigatureSubst_
name|HB_LigatureSubst
typedef|;
end_typedef
begin_comment
comment|/* needed by both lookup type 5 and 6 */
end_comment
begin_struct
DECL|struct|HB_SubstLookupRecord_
struct|struct
name|HB_SubstLookupRecord_
block|{
DECL|member|SequenceIndex
name|HB_UShort
name|SequenceIndex
decl_stmt|;
comment|/* index into current 					 glyph sequence               */
DECL|member|LookupListIndex
name|HB_UShort
name|LookupListIndex
decl_stmt|;
comment|/* Lookup to apply to that pos. */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SubstLookupRecord
typedef|typedef
name|struct
name|HB_SubstLookupRecord_
name|HB_SubstLookupRecord
typedef|;
end_typedef
begin_comment
comment|/* LookupType 5 */
end_comment
begin_struct
DECL|struct|HB_SubRule_
struct|struct
name|HB_SubRule_
block|{
DECL|member|Input
name|HB_UShort
modifier|*
name|Input
decl_stmt|;
comment|/* array of input glyph IDs     */
DECL|member|SubstLookupRecord
name|HB_SubstLookupRecord
modifier|*
name|SubstLookupRecord
decl_stmt|;
comment|/* array of SubstLookupRecord 					 tables                       */
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* total number of input glyphs */
DECL|member|SubstCount
name|HB_UShort
name|SubstCount
decl_stmt|;
comment|/* number of SubstLookupRecord 					 tables                       */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SubRule
typedef|typedef
name|struct
name|HB_SubRule_
name|HB_SubRule
typedef|;
end_typedef
begin_struct
DECL|struct|HB_SubRuleSet_
struct|struct
name|HB_SubRuleSet_
block|{
DECL|member|SubRule
name|HB_SubRule
modifier|*
name|SubRule
decl_stmt|;
comment|/* array of SubRule tables  */
DECL|member|SubRuleCount
name|HB_UShort
name|SubRuleCount
decl_stmt|;
comment|/* number of SubRule tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SubRuleSet
typedef|typedef
name|struct
name|HB_SubRuleSet_
name|HB_SubRuleSet
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ContextSubstFormat1_
struct|struct
name|HB_ContextSubstFormat1_
block|{
DECL|member|SubRuleSet
name|HB_SubRuleSet
modifier|*
name|SubRuleSet
decl_stmt|;
comment|/* array of SubRuleSet tables  */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table              */
DECL|member|SubRuleSetCount
name|HB_UShort
name|SubRuleSetCount
decl_stmt|;
comment|/* number of SubRuleSet tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ContextSubstFormat1
typedef|typedef
name|struct
name|HB_ContextSubstFormat1_
name|HB_ContextSubstFormat1
typedef|;
end_typedef
begin_struct
DECL|struct|HB_SubClassRule_
struct|struct
name|HB_SubClassRule_
block|{
DECL|member|Class
name|HB_UShort
modifier|*
name|Class
decl_stmt|;
comment|/* array of classes                */
DECL|member|SubstLookupRecord
name|HB_SubstLookupRecord
modifier|*
name|SubstLookupRecord
decl_stmt|;
comment|/* array of SubstLookupRecord 					 tables                          */
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* total number of context classes */
DECL|member|SubstCount
name|HB_UShort
name|SubstCount
decl_stmt|;
comment|/* number of SubstLookupRecord 					 tables                          */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SubClassRule
typedef|typedef
name|struct
name|HB_SubClassRule_
name|HB_SubClassRule
typedef|;
end_typedef
begin_struct
DECL|struct|HB_SubClassSet_
struct|struct
name|HB_SubClassSet_
block|{
DECL|member|SubClassRule
name|HB_SubClassRule
modifier|*
name|SubClassRule
decl_stmt|;
comment|/* array of SubClassRule tables  */
DECL|member|SubClassRuleCount
name|HB_UShort
name|SubClassRuleCount
decl_stmt|;
comment|/* number of SubClassRule tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SubClassSet
typedef|typedef
name|struct
name|HB_SubClassSet_
name|HB_SubClassSet
typedef|;
end_typedef
begin_comment
comment|/* The `MaxContextLength' field is not defined in the TTO specification    but simplifies the implementation of this format.  It holds the    maximal context length used in the context rules.                    */
end_comment
begin_struct
DECL|struct|HB_ContextSubstFormat2_
struct|struct
name|HB_ContextSubstFormat2_
block|{
DECL|member|SubClassSet
name|HB_SubClassSet
modifier|*
name|SubClassSet
decl_stmt|;
comment|/* array of SubClassSet tables  */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table               */
DECL|member|ClassDef
name|HB_ClassDefinition
name|ClassDef
decl_stmt|;
comment|/* ClassDef table               */
DECL|member|SubClassSetCount
name|HB_UShort
name|SubClassSetCount
decl_stmt|;
comment|/* number of SubClassSet tables */
DECL|member|MaxContextLength
name|HB_UShort
name|MaxContextLength
decl_stmt|;
comment|/* maximal context length       */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ContextSubstFormat2
typedef|typedef
name|struct
name|HB_ContextSubstFormat2_
name|HB_ContextSubstFormat2
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ContextSubstFormat3_
struct|struct
name|HB_ContextSubstFormat3_
block|{
DECL|member|Coverage
name|HB_Coverage
modifier|*
name|Coverage
decl_stmt|;
comment|/* array of Coverage tables      */
DECL|member|SubstLookupRecord
name|HB_SubstLookupRecord
modifier|*
name|SubstLookupRecord
decl_stmt|;
comment|/* array of substitution lookups */
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* number of input glyphs        */
DECL|member|SubstCount
name|HB_UShort
name|SubstCount
decl_stmt|;
comment|/* number of SubstLookupRecords  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ContextSubstFormat3
typedef|typedef
name|struct
name|HB_ContextSubstFormat3_
name|HB_ContextSubstFormat3
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ContextSubst_
struct|struct
name|HB_ContextSubst_
block|{
union|union
block|{
DECL|member|csf1
name|HB_ContextSubstFormat1
name|csf1
decl_stmt|;
DECL|member|csf2
name|HB_ContextSubstFormat2
name|csf2
decl_stmt|;
DECL|member|csf3
name|HB_ContextSubstFormat3
name|csf3
decl_stmt|;
block|}
DECL|member|csf
name|csf
union|;
DECL|member|SubstFormat
name|HB_Byte
name|SubstFormat
decl_stmt|;
comment|/* 1, 2, or 3 */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ContextSubst
typedef|typedef
name|struct
name|HB_ContextSubst_
name|HB_ContextSubst
typedef|;
end_typedef
begin_comment
comment|/* LookupType 6 */
end_comment
begin_struct
DECL|struct|HB_ChainSubRule_
struct|struct
name|HB_ChainSubRule_
block|{
DECL|member|Backtrack
name|HB_UShort
modifier|*
name|Backtrack
decl_stmt|;
comment|/* array of backtrack glyph IDs     */
DECL|member|Input
name|HB_UShort
modifier|*
name|Input
decl_stmt|;
comment|/* array of input glyph IDs         */
DECL|member|Lookahead
name|HB_UShort
modifier|*
name|Lookahead
decl_stmt|;
comment|/* array of lookahead glyph IDs     */
DECL|member|SubstLookupRecord
name|HB_SubstLookupRecord
modifier|*
name|SubstLookupRecord
decl_stmt|;
comment|/* array of SubstLookupRecords      */
DECL|member|BacktrackGlyphCount
name|HB_UShort
name|BacktrackGlyphCount
decl_stmt|;
comment|/* total number of backtrack glyphs */
DECL|member|InputGlyphCount
name|HB_UShort
name|InputGlyphCount
decl_stmt|;
comment|/* total number of input glyphs     */
DECL|member|LookaheadGlyphCount
name|HB_UShort
name|LookaheadGlyphCount
decl_stmt|;
comment|/* total number of lookahead glyphs */
DECL|member|SubstCount
name|HB_UShort
name|SubstCount
decl_stmt|;
comment|/* number of SubstLookupRecords     */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainSubRule
typedef|typedef
name|struct
name|HB_ChainSubRule_
name|HB_ChainSubRule
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainSubRuleSet_
struct|struct
name|HB_ChainSubRuleSet_
block|{
DECL|member|ChainSubRule
name|HB_ChainSubRule
modifier|*
name|ChainSubRule
decl_stmt|;
comment|/* array of ChainSubRule tables  */
DECL|member|ChainSubRuleCount
name|HB_UShort
name|ChainSubRuleCount
decl_stmt|;
comment|/* number of ChainSubRule tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainSubRuleSet
typedef|typedef
name|struct
name|HB_ChainSubRuleSet_
name|HB_ChainSubRuleSet
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainContextSubstFormat1_
struct|struct
name|HB_ChainContextSubstFormat1_
block|{
DECL|member|ChainSubRuleSet
name|HB_ChainSubRuleSet
modifier|*
name|ChainSubRuleSet
decl_stmt|;
comment|/* array of ChainSubRuleSet tables  */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table                   */
DECL|member|ChainSubRuleSetCount
name|HB_UShort
name|ChainSubRuleSetCount
decl_stmt|;
comment|/* number of ChainSubRuleSet tables */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainContextSubstFormat1
typedef|typedef
name|struct
name|HB_ChainContextSubstFormat1_
name|HB_ChainContextSubstFormat1
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainSubClassRule_
struct|struct
name|HB_ChainSubClassRule_
block|{
DECL|member|Backtrack
name|HB_UShort
modifier|*
name|Backtrack
decl_stmt|;
comment|/* array of backtrack classes      */
DECL|member|Input
name|HB_UShort
modifier|*
name|Input
decl_stmt|;
comment|/* array of context classes        */
DECL|member|Lookahead
name|HB_UShort
modifier|*
name|Lookahead
decl_stmt|;
comment|/* array of lookahead classes      */
DECL|member|SubstLookupRecord
name|HB_SubstLookupRecord
modifier|*
name|SubstLookupRecord
decl_stmt|;
comment|/* array of substitution lookups   */
DECL|member|BacktrackGlyphCount
name|HB_UShort
name|BacktrackGlyphCount
decl_stmt|;
comment|/* total number of backtrack 					 classes                         */
DECL|member|InputGlyphCount
name|HB_UShort
name|InputGlyphCount
decl_stmt|;
comment|/* total number of context classes */
DECL|member|LookaheadGlyphCount
name|HB_UShort
name|LookaheadGlyphCount
decl_stmt|;
comment|/* total number of lookahead 					 classes                         */
DECL|member|SubstCount
name|HB_UShort
name|SubstCount
decl_stmt|;
comment|/* number of SubstLookupRecords    */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainSubClassRule
typedef|typedef
name|struct
name|HB_ChainSubClassRule_
name|HB_ChainSubClassRule
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainSubClassSet_
struct|struct
name|HB_ChainSubClassSet_
block|{
DECL|member|ChainSubClassRule
name|HB_ChainSubClassRule
modifier|*
name|ChainSubClassRule
decl_stmt|;
comment|/* array of ChainSubClassRule 					 tables                      */
DECL|member|ChainSubClassRuleCount
name|HB_UShort
name|ChainSubClassRuleCount
decl_stmt|;
comment|/* number of ChainSubClassRule 					 tables                      */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainSubClassSet
typedef|typedef
name|struct
name|HB_ChainSubClassSet_
name|HB_ChainSubClassSet
typedef|;
end_typedef
begin_comment
comment|/* The `MaxXXXLength' fields are not defined in the TTO specification    but simplifies the implementation of this format.  It holds the    maximal context length used in the specific context rules.         */
end_comment
begin_struct
DECL|struct|HB_ChainContextSubstFormat2_
struct|struct
name|HB_ChainContextSubstFormat2_
block|{
DECL|member|ChainSubClassSet
name|HB_ChainSubClassSet
modifier|*
name|ChainSubClassSet
decl_stmt|;
comment|/* array of ChainSubClassSet 					 tables                     */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table             */
DECL|member|BacktrackClassDef
name|HB_ClassDefinition
name|BacktrackClassDef
decl_stmt|;
comment|/* BacktrackClassDef table    */
DECL|member|InputClassDef
name|HB_ClassDefinition
name|InputClassDef
decl_stmt|;
comment|/* InputClassDef table        */
DECL|member|LookaheadClassDef
name|HB_ClassDefinition
name|LookaheadClassDef
decl_stmt|;
comment|/* LookaheadClassDef table    */
DECL|member|ChainSubClassSetCount
name|HB_UShort
name|ChainSubClassSetCount
decl_stmt|;
comment|/* number of ChainSubClassSet 					 tables                     */
DECL|member|MaxBacktrackLength
name|HB_UShort
name|MaxBacktrackLength
decl_stmt|;
comment|/* maximal backtrack length   */
DECL|member|MaxLookaheadLength
name|HB_UShort
name|MaxLookaheadLength
decl_stmt|;
comment|/* maximal lookahead length   */
DECL|member|MaxInputLength
name|HB_UShort
name|MaxInputLength
decl_stmt|;
comment|/* maximal input length       */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainContextSubstFormat2
typedef|typedef
name|struct
name|HB_ChainContextSubstFormat2_
name|HB_ChainContextSubstFormat2
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainContextSubstFormat3_
struct|struct
name|HB_ChainContextSubstFormat3_
block|{
DECL|member|BacktrackCoverage
name|HB_Coverage
modifier|*
name|BacktrackCoverage
decl_stmt|;
comment|/* array of backtrack Coverage 					 tables                        */
DECL|member|InputCoverage
name|HB_Coverage
modifier|*
name|InputCoverage
decl_stmt|;
comment|/* array of input coverage 					 tables                        */
DECL|member|LookaheadCoverage
name|HB_Coverage
modifier|*
name|LookaheadCoverage
decl_stmt|;
comment|/* array of lookahead coverage 					 tables                        */
DECL|member|SubstLookupRecord
name|HB_SubstLookupRecord
modifier|*
name|SubstLookupRecord
decl_stmt|;
comment|/* array of substitution lookups */
DECL|member|BacktrackGlyphCount
name|HB_UShort
name|BacktrackGlyphCount
decl_stmt|;
comment|/* number of backtrack glyphs    */
DECL|member|InputGlyphCount
name|HB_UShort
name|InputGlyphCount
decl_stmt|;
comment|/* number of input glyphs        */
DECL|member|LookaheadGlyphCount
name|HB_UShort
name|LookaheadGlyphCount
decl_stmt|;
comment|/* number of lookahead glyphs    */
DECL|member|SubstCount
name|HB_UShort
name|SubstCount
decl_stmt|;
comment|/* number of SubstLookupRecords  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainContextSubstFormat3
typedef|typedef
name|struct
name|HB_ChainContextSubstFormat3_
name|HB_ChainContextSubstFormat3
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainContextSubst_
struct|struct
name|HB_ChainContextSubst_
block|{
union|union
block|{
DECL|member|ccsf1
name|HB_ChainContextSubstFormat1
name|ccsf1
decl_stmt|;
DECL|member|ccsf2
name|HB_ChainContextSubstFormat2
name|ccsf2
decl_stmt|;
DECL|member|ccsf3
name|HB_ChainContextSubstFormat3
name|ccsf3
decl_stmt|;
block|}
DECL|member|ccsf
name|ccsf
union|;
DECL|member|SubstFormat
name|HB_Byte
name|SubstFormat
decl_stmt|;
comment|/* 1, 2, or 3 */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainContextSubst
typedef|typedef
name|struct
name|HB_ChainContextSubst_
name|HB_ChainContextSubst
typedef|;
end_typedef
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* LookupType 7 */
end_comment
begin_comment
unit|struct HB_ExtensionSubst_ {   HB_GSUB_SubTable *subtable;
comment|/* referenced subtable */
end_comment
begin_comment
unit|HB_UShort      SubstFormat;
comment|/* always 1 */
end_comment
begin_comment
unit|HB_UShort      LookuptType;
comment|/* lookup-type of referenced subtable */
end_comment
begin_endif
unit|};  typedef struct HB_ExtensionSubst_  HB_ExtensionSubst;
endif|#
directive|endif
end_endif
begin_comment
comment|/* LookupType 8 */
end_comment
begin_struct
DECL|struct|HB_ReverseChainContextSubst_
struct|struct
name|HB_ReverseChainContextSubst_
block|{
DECL|member|LookaheadCoverage
name|HB_Coverage
modifier|*
name|LookaheadCoverage
decl_stmt|;
comment|/* array of lookahead Coverage 					 tables                          */
DECL|member|Substitute
name|HB_UShort
modifier|*
name|Substitute
decl_stmt|;
comment|/* array of substitute Glyph ID    */
DECL|member|BacktrackCoverage
name|HB_Coverage
modifier|*
name|BacktrackCoverage
decl_stmt|;
comment|/* array of backtrack Coverage 					 tables                          */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* coverage table for input glyphs */
DECL|member|SubstFormat
name|HB_UShort
name|SubstFormat
decl_stmt|;
comment|/* always 1 */
DECL|member|BacktrackGlyphCount
name|HB_UShort
name|BacktrackGlyphCount
decl_stmt|;
comment|/* number of backtrack glyphs      */
DECL|member|LookaheadGlyphCount
name|HB_UShort
name|LookaheadGlyphCount
decl_stmt|;
comment|/* number of lookahead glyphs      */
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* number of Glyph IDs             */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ReverseChainContextSubst
typedef|typedef
name|struct
name|HB_ReverseChainContextSubst_
name|HB_ReverseChainContextSubst
typedef|;
end_typedef
begin_union
DECL|union|HB_GSUB_SubTable_
union|union
name|HB_GSUB_SubTable_
block|{
DECL|member|single
name|HB_SingleSubst
name|single
decl_stmt|;
DECL|member|multiple
name|HB_MultipleSubst
name|multiple
decl_stmt|;
DECL|member|alternate
name|HB_AlternateSubst
name|alternate
decl_stmt|;
DECL|member|ligature
name|HB_LigatureSubst
name|ligature
decl_stmt|;
DECL|member|context
name|HB_ContextSubst
name|context
decl_stmt|;
DECL|member|chain
name|HB_ChainContextSubst
name|chain
decl_stmt|;
DECL|member|reverse
name|HB_ReverseChainContextSubst
name|reverse
decl_stmt|;
block|}
union|;
end_union
begin_function_decl
name|HB_INTERNAL
name|HB_Error
name|_HB_GSUB_Load_SubTable
parameter_list|(
name|HB_GSUB_SubTable
modifier|*
name|st
parameter_list|,
name|HB_Stream
name|stream
parameter_list|,
name|HB_UShort
name|lookup_type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|HB_INTERNAL
name|void
name|_HB_GSUB_Free_SubTable
parameter_list|(
name|HB_GSUB_SubTable
modifier|*
name|st
parameter_list|,
name|HB_UShort
name|lookup_type
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|HB_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* HARFBUZZ_GSUB_PRIVATE_H */
end_comment
end_unit
