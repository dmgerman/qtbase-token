begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcglyph.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType abstract glyph cache (specification).                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2003, 2004, 2006, 2007 by                         */
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
comment|/*    *    *  FTC_GCache is an _abstract_ cache object optimized to store glyph    *  data.  It works as follows:    *    *   - It manages FTC_GNode objects. Each one of them can hold one or more    *     glyph `items'.  Item types are not specified in the FTC_GCache but    *     in classes that extend it.    *    *   - Glyph attributes, like face ID, character size, render mode, etc.,    *     can be grouped into abstract `glyph families'.  This avoids storing    *     the attributes within the FTC_GCache, since it is likely that many    *     FTC_GNodes will belong to the same family in typical uses.    *    *   - Each FTC_GNode is thus an FTC_Node with two additional fields:    *    *       * gindex: A glyph index, or the first index in a glyph range.    *       * family: A pointer to a glyph `family'.    *    *   - Family types are not fully specific in the FTC_Family type, but    *     by classes that extend it.    *    *  Note that both FTC_ImageCache and FTC_SBitCache extend FTC_GCache.    *  They share an FTC_Family sub-class called FTC_BasicFamily which is    *  used to store the following data: face ID, pixel/point sizes, load    *  flags.  For more details see the file `src/cache/ftcbasic.c'.    *    *  Client applications can extend FTC_GNode with their own FTC_GNode    *  and FTC_Family sub-classes to implement more complex caches (e.g.,    *  handling automatic synthesis, like obliquing& emboldening, colored    *  glyphs, etc.).    *    *  See also the FTC_ICache& FTC_SCache classes in `ftcimage.h' and    *  `ftcsbits.h', which both extend FTC_GCache with additional    *  optimizations.    *    *  A typical FTC_GCache implementation must provide at least the    *  following:    *    *  - FTC_GNode sub-class, e.g. MyNode, with relevant methods:    *        my_node_new            (must call FTC_GNode_Init)    *        my_node_free           (must call FTC_GNode_Done)    *        my_node_compare        (must call FTC_GNode_Compare)    *        my_node_remove_faceid  (must call ftc_gnode_unselect in case    *                                of match)    *    *  - FTC_Family sub-class, e.g. MyFamily, with relevant methods:    *        my_family_compare    *        my_family_init    *        my_family_reset (optional)    *        my_family_done    *    *  - FTC_GQuery sub-class, e.g. MyQuery, to hold cache-specific query    *    data.    *    *  - Constant structures for a FTC_GNodeClass.    *    *  - MyCacheNew() can be implemented easily as a call to the convenience    *    function FTC_GCache_New.    *    *  - MyCacheLookup with a call to FTC_GCache_Lookup.  This function will    *    automatically:    *    *    - Search for the corresponding family in the cache, or create    *      a new one if necessary.  Put it in FTC_GQUERY(myquery).family    *    *    - Call FTC_Cache_Lookup.    *    *    If it returns NULL, you should create a new node, then call    *    ftc_cache_add as usual.    */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Important: The functions defined in this file are only used to        */
end_comment
begin_comment
comment|/*            implement an abstract glyph cache class.  You need to      */
end_comment
begin_comment
comment|/*            provide additional logic to implement a complete cache.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*********                                                       *********/
end_comment
begin_comment
comment|/*********             WARNING, THIS IS BETA CODE.               *********/
end_comment
begin_comment
comment|/*********                                                       *********/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTCGLYPH_H__
end_ifndef
begin_define
DECL|macro|__FTCGLYPH_H__
define|#
directive|define
name|__FTCGLYPH_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"ftcmanag.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*   *  We can group glyphs into `families'.  Each family correspond to a   *  given face ID, character size, transform, etc.   *   *  Families are implemented as MRU list nodes.  They are   *  reference-counted.   */
end_comment
begin_typedef
DECL|struct|FTC_FamilyRec_
typedef|typedef
struct|struct
name|FTC_FamilyRec_
block|{
DECL|member|mrunode
name|FTC_MruNodeRec
name|mrunode
decl_stmt|;
DECL|member|num_nodes
name|FT_UInt
name|num_nodes
decl_stmt|;
comment|/* current number of nodes in this family */
DECL|member|cache
name|FTC_Cache
name|cache
decl_stmt|;
DECL|member|clazz
name|FTC_MruListClass
name|clazz
decl_stmt|;
block|}
DECL|typedef|FTC_FamilyRec
DECL|typedef|FTC_Family
name|FTC_FamilyRec
operator|,
typedef|*
name|FTC_Family
typedef|;
end_typedef
begin_define
DECL|macro|FTC_FAMILY
define|#
directive|define
name|FTC_FAMILY
parameter_list|(
name|x
parameter_list|)
value|( (FTC_Family)(x) )
end_define
begin_define
DECL|macro|FTC_FAMILY_P
define|#
directive|define
name|FTC_FAMILY_P
parameter_list|(
name|x
parameter_list|)
value|( (FTC_Family*)(x) )
end_define
begin_typedef
DECL|struct|FTC_GNodeRec_
typedef|typedef
struct|struct
name|FTC_GNodeRec_
block|{
DECL|member|node
name|FTC_NodeRec
name|node
decl_stmt|;
DECL|member|family
name|FTC_Family
name|family
decl_stmt|;
DECL|member|gindex
name|FT_UInt
name|gindex
decl_stmt|;
block|}
DECL|typedef|FTC_GNodeRec
DECL|typedef|FTC_GNode
name|FTC_GNodeRec
operator|,
typedef|*
name|FTC_GNode
typedef|;
end_typedef
begin_define
DECL|macro|FTC_GNODE
define|#
directive|define
name|FTC_GNODE
parameter_list|(
name|x
parameter_list|)
value|( (FTC_GNode)(x) )
end_define
begin_define
DECL|macro|FTC_GNODE_P
define|#
directive|define
name|FTC_GNODE_P
parameter_list|(
name|x
parameter_list|)
value|( (FTC_GNode*)(x) )
end_define
begin_typedef
DECL|struct|FTC_GQueryRec_
typedef|typedef
struct|struct
name|FTC_GQueryRec_
block|{
DECL|member|gindex
name|FT_UInt
name|gindex
decl_stmt|;
DECL|member|family
name|FTC_Family
name|family
decl_stmt|;
block|}
DECL|typedef|FTC_GQueryRec
DECL|typedef|FTC_GQuery
name|FTC_GQueryRec
operator|,
typedef|*
name|FTC_GQuery
typedef|;
end_typedef
begin_define
DECL|macro|FTC_GQUERY
define|#
directive|define
name|FTC_GQUERY
parameter_list|(
name|x
parameter_list|)
value|( (FTC_GQuery)(x) )
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These functions are exported so that they can be called from          */
end_comment
begin_comment
comment|/* user-provided cache classes; otherwise, they are really part of the   */
end_comment
begin_comment
comment|/* cache sub-system internals.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* must be called by derived FTC_Node_InitFunc routines */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FTC_GNode_Init
argument_list|(
argument|FTC_GNode   node
argument_list|,
argument|FT_UInt     gindex
argument_list|,
comment|/* glyph index for node */
argument|FTC_Family  family
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* returns TRUE iff the query's glyph index correspond to the node;  */
end_comment
begin_comment
comment|/* this assumes that the `family' and `hash' fields of the query are */
end_comment
begin_comment
comment|/* already correctly set                                             */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|FTC_GNode_Compare
argument_list|(
argument|FTC_GNode   gnode
argument_list|,
argument|FTC_GQuery  gquery
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* call this function to clear a node's family -- this is necessary */
end_comment
begin_comment
comment|/* to implement the `node_remove_faceid' cache method correctly     */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FTC_GNode_UnselectFamily
name|FTC_GNode_UnselectFamily
argument_list|(
argument|FTC_GNode  gnode
argument_list|,
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* must be called by derived FTC_Node_DoneFunc routines */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FTC_GNode_Done
argument_list|(
argument|FTC_GNode  node
argument_list|,
argument|FTC_Cache  cache
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
name|FTC_Family_Init
argument_list|(
argument|FTC_Family  family
argument_list|,
argument|FTC_Cache   cache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|struct|FTC_GCacheRec_
typedef|typedef
struct|struct
name|FTC_GCacheRec_
block|{
DECL|member|cache
name|FTC_CacheRec
name|cache
decl_stmt|;
DECL|member|families
name|FTC_MruListRec
name|families
decl_stmt|;
block|}
DECL|typedef|FTC_GCacheRec
DECL|typedef|FTC_GCache
name|FTC_GCacheRec
operator|,
typedef|*
name|FTC_GCache
typedef|;
end_typedef
begin_define
DECL|macro|FTC_GCACHE
define|#
directive|define
name|FTC_GCACHE
parameter_list|(
name|x
parameter_list|)
value|((FTC_GCache)(x))
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* can be used as @FTC_Cache_InitFunc */
end_comment
begin_endif
unit|FT_LOCAL( FT_Error )   FTC_GCache_Init( FTC_GCache  cache );
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* can be used as @FTC_Cache_DoneFunc */
end_comment
begin_endif
unit|FT_LOCAL( void )   FTC_GCache_Done( FTC_GCache  cache );
endif|#
directive|endif
end_endif
begin_comment
comment|/* the glyph cache class adds fields for the family implementation */
end_comment
begin_typedef
DECL|struct|FTC_GCacheClassRec_
typedef|typedef
struct|struct
name|FTC_GCacheClassRec_
block|{
DECL|member|clazz
name|FTC_CacheClassRec
name|clazz
decl_stmt|;
DECL|member|family_class
name|FTC_MruListClass
name|family_class
decl_stmt|;
block|}
DECL|typedef|FTC_GCacheClassRec
name|FTC_GCacheClassRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|FTC_GCacheClass
typedef|typedef
specifier|const
name|FTC_GCacheClassRec
modifier|*
name|FTC_GCacheClass
typedef|;
end_typedef
begin_define
DECL|macro|FTC_GCACHE_CLASS
define|#
directive|define
name|FTC_GCACHE_CLASS
parameter_list|(
name|x
parameter_list|)
value|((FTC_GCacheClass)(x))
end_define
begin_define
DECL|macro|FTC_CACHE__GCACHE_CLASS
define|#
directive|define
name|FTC_CACHE__GCACHE_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|FTC_GCACHE_CLASS( FTC_CACHE(x)->org_class )
end_define
begin_define
DECL|macro|FTC_CACHE__FAMILY_CLASS
define|#
directive|define
name|FTC_CACHE__FAMILY_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|( (FTC_MruListClass)FTC_CACHE__GCACHE_CLASS( x )->family_class )
end_define
begin_comment
comment|/* convenience function; use it instead of FTC_Manager_Register_Cache */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_GCache_New
argument_list|(
argument|FTC_Manager       manager
argument_list|,
argument|FTC_GCacheClass   clazz
argument_list|,
argument|FTC_GCache       *acache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|FTC_INLINE
end_ifndef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FTC_GCache_Lookup
name|FTC_GCache_Lookup
argument_list|(
argument|FTC_GCache   cache
argument_list|,
argument|FT_UInt32    hash
argument_list|,
argument|FT_UInt      gindex
argument_list|,
argument|FTC_GQuery   query
argument_list|,
argument|FTC_Node    *anode
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* */
end_comment
begin_define
DECL|macro|FTC_FAMILY_FREE
define|#
directive|define
name|FTC_FAMILY_FREE
parameter_list|(
name|family
parameter_list|,
name|cache
parameter_list|)
define|\
value|FTC_MruList_Remove(&FTC_GCACHE((cache))->families, \                               (FTC_MruNode)(family) )
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|FTC_INLINE
end_ifdef
begin_define
DECL|macro|FTC_GCACHE_LOOKUP_CMP
define|#
directive|define
name|FTC_GCACHE_LOOKUP_CMP
parameter_list|(
name|cache
parameter_list|,
name|famcmp
parameter_list|,
name|nodecmp
parameter_list|,
name|hash
parameter_list|,                \
name|gindex
parameter_list|,
name|query
parameter_list|,
name|node
parameter_list|,
name|error
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                            \     FTC_GCache               _gcache   = FTC_GCACHE( cache );               \     FTC_GQuery               _gquery   = (FTC_GQuery)( query );             \     FTC_MruNode_CompareFunc  _fcompare = (FTC_MruNode_CompareFunc)(famcmp); \     FTC_MruNode              _mrunode;                                      \                                                                             \                                                                             \     _gquery->gindex = (gindex);                                             \                                                                             \     FTC_MRULIST_LOOKUP_CMP(&_gcache->families, _gquery, _fcompare,         \                             _mrunode, error );                              \     _gquery->family = FTC_FAMILY( _mrunode );                               \     if ( !error )                                                           \     {                                                                       \       FTC_Family  _gqfamily = _gquery->family;                              \                                                                             \                                                                             \       _gqfamily->num_nodes++;                                               \                                                                             \       FTC_CACHE_LOOKUP_CMP( cache, nodecmp, hash, query, node, error );     \                                                                             \       if ( --_gqfamily->num_nodes == 0 )                                    \         FTC_FAMILY_FREE( _gqfamily, _gcache );                              \     }                                                                       \   FT_END_STMNT
end_define
begin_comment
comment|/* */
end_comment
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FTC_INLINE */
end_comment
begin_define
DECL|macro|FTC_GCACHE_LOOKUP_CMP
define|#
directive|define
name|FTC_GCACHE_LOOKUP_CMP
parameter_list|(
name|cache
parameter_list|,
name|famcmp
parameter_list|,
name|nodecmp
parameter_list|,
name|hash
parameter_list|,          \
name|gindex
parameter_list|,
name|query
parameter_list|,
name|node
parameter_list|,
name|error
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                     \                                                                       \      error = FTC_GCache_Lookup( FTC_GCACHE( cache ), hash, gindex,    \                                 FTC_GQUERY( query ), node );          \                                                                       \    FT_END_STMNT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FTC_INLINE */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTCGLYPH_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
