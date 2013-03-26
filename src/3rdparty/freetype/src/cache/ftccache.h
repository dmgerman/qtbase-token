begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftccache.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType internal cache interface (specification).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2002, 2003, 2004, 2005, 2006, 2007, 2009 by       */
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
name|__FTCCACHE_H__
end_ifndef
begin_define
DECL|macro|__FTCCACHE_H__
define|#
directive|define
name|__FTCCACHE_H__
end_define
begin_include
include|#
directive|include
file|"ftcmru.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* handle to cache object */
end_comment
begin_typedef
DECL|typedef|FTC_Cache
typedef|typedef
name|struct
name|FTC_CacheRec_
modifier|*
name|FTC_Cache
typedef|;
end_typedef
begin_comment
comment|/* handle to cache class */
end_comment
begin_typedef
DECL|typedef|FTC_CacheClass
typedef|typedef
specifier|const
name|struct
name|FTC_CacheClassRec_
modifier|*
name|FTC_CacheClass
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                   CACHE NODE DEFINITIONS                      *****/
end_comment
begin_comment
comment|/*****                                                               *****/
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
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Each cache controls one or more cache nodes.  Each node is part of    */
end_comment
begin_comment
comment|/* the global_lru list of the manager.  Its `data' field however is used */
end_comment
begin_comment
comment|/* as a reference count for now.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* A node can be anything, depending on the type of information held by  */
end_comment
begin_comment
comment|/* the cache.  It can be an individual glyph image, a set of bitmaps     */
end_comment
begin_comment
comment|/* glyphs for a given size, some metrics, etc.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* structure size should be 20 bytes on 32-bits machines */
end_comment
begin_typedef
DECL|struct|FTC_NodeRec_
typedef|typedef
struct|struct
name|FTC_NodeRec_
block|{
DECL|member|mru
name|FTC_MruNodeRec
name|mru
decl_stmt|;
comment|/* circular mru list pointer           */
DECL|member|link
name|FTC_Node
name|link
decl_stmt|;
comment|/* used for hashing                    */
DECL|member|hash
name|FT_UInt32
name|hash
decl_stmt|;
comment|/* used for hashing too                */
DECL|member|cache_index
name|FT_UShort
name|cache_index
decl_stmt|;
comment|/* index of cache the node belongs to  */
DECL|member|ref_count
name|FT_Short
name|ref_count
decl_stmt|;
comment|/* reference count for this node       */
block|}
DECL|typedef|FTC_NodeRec
name|FTC_NodeRec
typedef|;
end_typedef
begin_define
DECL|macro|FTC_NODE
define|#
directive|define
name|FTC_NODE
parameter_list|(
name|x
parameter_list|)
value|( (FTC_Node)(x) )
end_define
begin_define
DECL|macro|FTC_NODE_P
define|#
directive|define
name|FTC_NODE_P
parameter_list|(
name|x
parameter_list|)
value|( (FTC_Node*)(x) )
end_define
begin_define
DECL|macro|FTC_NODE__NEXT
define|#
directive|define
name|FTC_NODE__NEXT
parameter_list|(
name|x
parameter_list|)
value|FTC_NODE( (x)->mru.next )
end_define
begin_define
DECL|macro|FTC_NODE__PREV
define|#
directive|define
name|FTC_NODE__PREV
parameter_list|(
name|x
parameter_list|)
value|FTC_NODE( (x)->mru.prev )
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifdef
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|ftc_node_destroy
argument_list|(
argument|FTC_Node     node
argument_list|,
argument|FTC_Manager  manager
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                       CACHE DEFINITIONS                       *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* initialize a new cache node */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FTC_Node_NewFunc
modifier|*
name|FTC_Node_NewFunc
function_decl|)
parameter_list|(
name|FTC_Node
modifier|*
name|pnode
parameter_list|,
name|FT_Pointer
name|query
parameter_list|,
name|FTC_Cache
name|cache
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Offset
function_decl|(
DECL|typedef|FTC_Node_WeightFunc
modifier|*
name|FTC_Node_WeightFunc
function_decl|)
parameter_list|(
name|FTC_Node
name|node
parameter_list|,
name|FTC_Cache
name|cache
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* compare a node to a given key pair */
end_comment
begin_typedef
typedef|typedef
name|FT_Bool
function_decl|(
DECL|typedef|FTC_Node_CompareFunc
modifier|*
name|FTC_Node_CompareFunc
function_decl|)
parameter_list|(
name|FTC_Node
name|node
parameter_list|,
name|FT_Pointer
name|key
parameter_list|,
name|FTC_Cache
name|cache
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FTC_Node_FreeFunc
modifier|*
name|FTC_Node_FreeFunc
function_decl|)
parameter_list|(
name|FTC_Node
name|node
parameter_list|,
name|FTC_Cache
name|cache
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FTC_Cache_InitFunc
modifier|*
name|FTC_Cache_InitFunc
function_decl|)
parameter_list|(
name|FTC_Cache
name|cache
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FTC_Cache_DoneFunc
modifier|*
name|FTC_Cache_DoneFunc
function_decl|)
parameter_list|(
name|FTC_Cache
name|cache
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|FTC_CacheClassRec_
typedef|typedef
struct|struct
name|FTC_CacheClassRec_
block|{
DECL|member|node_new
name|FTC_Node_NewFunc
name|node_new
decl_stmt|;
DECL|member|node_weight
name|FTC_Node_WeightFunc
name|node_weight
decl_stmt|;
DECL|member|node_compare
name|FTC_Node_CompareFunc
name|node_compare
decl_stmt|;
DECL|member|node_remove_faceid
name|FTC_Node_CompareFunc
name|node_remove_faceid
decl_stmt|;
DECL|member|node_free
name|FTC_Node_FreeFunc
name|node_free
decl_stmt|;
DECL|member|cache_size
name|FT_Offset
name|cache_size
decl_stmt|;
DECL|member|cache_init
name|FTC_Cache_InitFunc
name|cache_init
decl_stmt|;
DECL|member|cache_done
name|FTC_Cache_DoneFunc
name|cache_done
decl_stmt|;
block|}
DECL|typedef|FTC_CacheClassRec
name|FTC_CacheClassRec
typedef|;
end_typedef
begin_comment
comment|/* each cache really implements a dynamic hash table to manage its nodes */
end_comment
begin_typedef
DECL|struct|FTC_CacheRec_
typedef|typedef
struct|struct
name|FTC_CacheRec_
block|{
DECL|member|p
name|FT_UFast
name|p
decl_stmt|;
DECL|member|mask
name|FT_UFast
name|mask
decl_stmt|;
DECL|member|slack
name|FT_Long
name|slack
decl_stmt|;
DECL|member|buckets
name|FTC_Node
modifier|*
name|buckets
decl_stmt|;
DECL|member|clazz
name|FTC_CacheClassRec
name|clazz
decl_stmt|;
comment|/* local copy, for speed  */
DECL|member|manager
name|FTC_Manager
name|manager
decl_stmt|;
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|index
name|FT_UInt
name|index
decl_stmt|;
comment|/* in manager's table     */
DECL|member|org_class
name|FTC_CacheClass
name|org_class
decl_stmt|;
comment|/* original class pointer */
block|}
DECL|typedef|FTC_CacheRec
name|FTC_CacheRec
typedef|;
end_typedef
begin_define
DECL|macro|FTC_CACHE
define|#
directive|define
name|FTC_CACHE
parameter_list|(
name|x
parameter_list|)
value|( (FTC_Cache)(x) )
end_define
begin_define
DECL|macro|FTC_CACHE_P
define|#
directive|define
name|FTC_CACHE_P
parameter_list|(
name|x
parameter_list|)
value|( (FTC_Cache*)(x) )
end_define
begin_comment
comment|/* default cache initialize */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_Cache_Init
argument_list|(
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* default cache finalizer */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FTC_Cache_Done
name|FTC_Cache_Done
argument_list|(
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FTC_Cache_Done
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Call this function to lookup the cache.  If no corresponding    * node is found, a new one is automatically created.  This function    * is capable of flushing the cache adequately to make room for the    * new cache object.    */
end_comment
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
name|FTC_Cache_Lookup
argument_list|(
argument|FTC_Cache   cache
argument_list|,
argument|FT_UInt32   hash
argument_list|,
argument|FT_Pointer  query
argument_list|,
argument|FTC_Node   *anode
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FTC_Cache_NewNode
name|FTC_Cache_NewNode
argument_list|(
argument|FTC_Cache   cache
argument_list|,
argument|FT_UInt32   hash
argument_list|,
argument|FT_Pointer  query
argument_list|,
argument|FTC_Node   *anode
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Remove all nodes that relate to a given face_id.  This is useful    * when un-installing fonts.  Note that if a cache node relates to    * the face_id, but is locked (i.e., has `ref_count> 0'), the node    * will _not_ be destroyed, but its internal face_id reference will    * be modified.    *    * The final result will be that the node will never come back    * in further lookup requests, and will be flushed on demand from    * the cache normally when its reference count reaches 0.    */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FTC_Cache_RemoveFaceID
argument_list|(
argument|FTC_Cache   cache
argument_list|,
argument|FTC_FaceID  face_id
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|FTC_INLINE
end_ifdef
begin_define
DECL|macro|FTC_CACHE_LOOKUP_CMP
define|#
directive|define
name|FTC_CACHE_LOOKUP_CMP
parameter_list|(
name|cache
parameter_list|,
name|nodecmp
parameter_list|,
name|hash
parameter_list|,
name|query
parameter_list|,
name|node
parameter_list|,
name|error
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                         \     FTC_Node             *_bucket, *_pnode, _node;                       \     FTC_Cache             _cache   = FTC_CACHE(cache);                   \     FT_UInt32             _hash    = (FT_UInt32)(hash);                  \     FTC_Node_CompareFunc  _nodcomp = (FTC_Node_CompareFunc)(nodecmp);    \     FT_UFast              _idx;                                          \                                                                          \                                                                          \     error = 0;                                                           \     node  = NULL;                                                        \     _idx  = _hash& _cache->mask;                                        \     if ( _idx< _cache->p )                                              \       _idx = _hash& ( _cache->mask*2 + 1 );                             \                                                                          \     _bucket = _pnode = _cache->buckets + _idx;                           \     for (;;)                                                             \     {                                                                    \       _node = *_pnode;                                                   \       if ( _node == NULL )                                               \         goto _NewNode;                                                   \                                                                          \       if ( _node->hash == _hash&& _nodcomp( _node, query, _cache ) )    \         break;                                                           \                                                                          \       _pnode =&_node->link;                                             \     }                                                                    \                                                                          \     if ( _node != *_bucket )                                             \     {                                                                    \       *_pnode     = _node->link;                                         \       _node->link = *_bucket;                                            \       *_bucket    = _node;                                               \     }                                                                    \                                                                          \     {                                                                    \       FTC_Manager  _manager = _cache->manager;                           \       void*        _nl      =&_manager->nodes_list;                     \                                                                          \                                                                          \       if ( _node != _manager->nodes_list )                               \         FTC_MruNode_Up( (FTC_MruNode*)_nl,                               \                         (FTC_MruNode)_node );                            \     }                                                                    \     goto _Ok;                                                            \                                                                          \   _NewNode:                                                              \     error = FTC_Cache_NewNode( _cache, _hash, query,&_node );           \                                                                          \   _Ok:                                                                   \     node = _node;                                                        \   FT_END_STMNT
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FTC_INLINE */
end_comment
begin_define
DECL|macro|FTC_CACHE_LOOKUP_CMP
define|#
directive|define
name|FTC_CACHE_LOOKUP_CMP
parameter_list|(
name|cache
parameter_list|,
name|nodecmp
parameter_list|,
name|hash
parameter_list|,
name|query
parameter_list|,
name|node
parameter_list|,
name|error
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                         \     error = FTC_Cache_Lookup( FTC_CACHE( cache ), hash, query,           \                               (FTC_Node*)&(node) );                      \   FT_END_STMNT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FTC_INLINE */
end_comment
begin_comment
comment|/*    * This macro, together with FTC_CACHE_TRYLOOP_END, defines a retry    * loop to flush the cache repeatedly in case of memory overflows.    *    * It is used when creating a new cache node, or within a lookup    * that needs to allocate data (e.g., the sbit cache lookup).    *    * Example:    *    *   {    *     FTC_CACHE_TRYLOOP( cache )    *       error = load_data( ... );    *     FTC_CACHE_TRYLOOP_END()    *   }    *    */
end_comment
begin_define
DECL|macro|FTC_CACHE_TRYLOOP
define|#
directive|define
name|FTC_CACHE_TRYLOOP
parameter_list|(
name|cache
parameter_list|)
define|\
value|{                                                          \     FTC_Manager  _try_manager = FTC_CACHE( cache )->manager; \     FT_UInt      _try_count   = 4;                           \                                                              \                                                              \     for (;;)                                                 \     {                                                        \       FT_UInt  _try_done;
end_define
begin_define
DECL|macro|FTC_CACHE_TRYLOOP_END
define|#
directive|define
name|FTC_CACHE_TRYLOOP_END
parameter_list|()
define|\
value|if ( !error || error != FT_Err_Out_Of_Memory )              \         break;                                                    \                                                                   \       _try_done = FTC_Manager_FlushN( _try_manager, _try_count ); \       if ( _try_done == 0 )                                       \         break;                                                    \                                                                   \       if ( _try_done == _try_count )                              \       {                                                           \         _try_count *= 2;                                          \         if ( _try_count< _try_done              ||               \             _try_count> _try_manager->num_nodes )                \           _try_count = _try_manager->num_nodes;                   \       }                                                           \     }                                                             \   }
end_define
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
comment|/* __FTCCACHE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
