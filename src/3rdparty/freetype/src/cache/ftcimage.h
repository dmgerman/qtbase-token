begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcimage.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType Generic Image cache (specification)                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2002, 2003, 2006 by                               */
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
comment|/*   *  FTC_ICache is an _abstract_ cache used to store a single FT_Glyph   *  image per cache node.   *   *  FTC_ICache extends FTC_GCache.  For an implementation example,   *  see FTC_ImageCache in `src/cache/ftbasic.c'.   */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Each image cache really manages FT_Glyph objects.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTCIMAGE_H__
end_ifndef
begin_define
DECL|macro|__FTCIMAGE_H__
define|#
directive|define
name|__FTCIMAGE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CACHE_H
end_include
begin_include
include|#
directive|include
file|"ftcglyph.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* the FT_Glyph image node type - we store only 1 glyph per node */
end_comment
begin_typedef
DECL|struct|FTC_INodeRec_
typedef|typedef
struct|struct
name|FTC_INodeRec_
block|{
DECL|member|gnode
name|FTC_GNodeRec
name|gnode
decl_stmt|;
DECL|member|glyph
name|FT_Glyph
name|glyph
decl_stmt|;
block|}
DECL|typedef|FTC_INodeRec
DECL|typedef|FTC_INode
name|FTC_INodeRec
operator|,
typedef|*
name|FTC_INode
typedef|;
end_typedef
begin_define
DECL|macro|FTC_INODE
define|#
directive|define
name|FTC_INODE
parameter_list|(
name|x
parameter_list|)
value|( (FTC_INode)( x ) )
end_define
begin_define
DECL|macro|FTC_INODE_GINDEX
define|#
directive|define
name|FTC_INODE_GINDEX
parameter_list|(
name|x
parameter_list|)
value|FTC_GNODE(x)->gindex
end_define
begin_define
DECL|macro|FTC_INODE_FAMILY
define|#
directive|define
name|FTC_INODE_FAMILY
parameter_list|(
name|x
parameter_list|)
value|FTC_GNODE(x)->family
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FTC_IFamily_LoadGlyphFunc
modifier|*
name|FTC_IFamily_LoadGlyphFunc
function_decl|)
parameter_list|(
name|FTC_Family
name|family
parameter_list|,
name|FT_UInt
name|gindex
parameter_list|,
name|FTC_Cache
name|cache
parameter_list|,
name|FT_Glyph
modifier|*
name|aglyph
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|FTC_IFamilyClassRec_
typedef|typedef
struct|struct
name|FTC_IFamilyClassRec_
block|{
DECL|member|clazz
name|FTC_MruListClassRec
name|clazz
decl_stmt|;
DECL|member|family_load_glyph
name|FTC_IFamily_LoadGlyphFunc
name|family_load_glyph
decl_stmt|;
block|}
DECL|typedef|FTC_IFamilyClassRec
name|FTC_IFamilyClassRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|FTC_IFamilyClass
typedef|typedef
specifier|const
name|FTC_IFamilyClassRec
modifier|*
name|FTC_IFamilyClass
typedef|;
end_typedef
begin_define
DECL|macro|FTC_IFAMILY_CLASS
define|#
directive|define
name|FTC_IFAMILY_CLASS
parameter_list|(
name|x
parameter_list|)
value|((FTC_IFamilyClass)(x))
end_define
begin_define
DECL|macro|FTC_CACHE__IFAMILY_CLASS
define|#
directive|define
name|FTC_CACHE__IFAMILY_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|FTC_IFAMILY_CLASS( FTC_CACHE__GCACHE_CLASS(x)->family_class )
end_define
begin_comment
comment|/* can be used as a @FTC_Node_FreeFunc */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FTC_INode_Free
argument_list|(
argument|FTC_INode  inode
argument_list|,
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Can be used as @FTC_Node_NewFunc.  `gquery.index' and `gquery.family'    * must be set correctly.  This function will call the `family_load_glyph'    * method to load the FT_Glyph into the cache node.    */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_INode_New
argument_list|(
argument|FTC_INode   *pinode
argument_list|,
argument|FTC_GQuery   gquery
argument_list|,
argument|FTC_Cache    cache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* can be used as @FTC_Node_WeightFunc */
end_comment
begin_endif
unit|FT_LOCAL( FT_ULong )   FTC_INode_Weight( FTC_INode  inode );
endif|#
directive|endif
end_endif
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTCIMAGE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
