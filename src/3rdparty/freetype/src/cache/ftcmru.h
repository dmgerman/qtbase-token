begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcmru.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Simple MRU list-cache (specification).                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2003, 2004, 2005, 2006 by                         */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* An MRU is a list that cannot hold more than a certain number of       */
end_comment
begin_comment
comment|/* elements (`max_elements').  All elements in the list are sorted in    */
end_comment
begin_comment
comment|/* least-recently-used order, i.e., the `oldest' element is at the tail  */
end_comment
begin_comment
comment|/* of the list.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* When doing a lookup (either through `Lookup()' or `Lookup_Node()'),   */
end_comment
begin_comment
comment|/* the list is searched for an element with the corresponding key.  If   */
end_comment
begin_comment
comment|/* it is found, the element is moved to the head of the list and is      */
end_comment
begin_comment
comment|/* returned.                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* If no corresponding element is found, the lookup routine will try to  */
end_comment
begin_comment
comment|/* obtain a new element with the relevant key.  If the list is already   */
end_comment
begin_comment
comment|/* full, the oldest element from the list is discarded and replaced by a */
end_comment
begin_comment
comment|/* new one; a new element is added to the list otherwise.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Note that it is possible to pre-allocate the element list nodes.      */
end_comment
begin_comment
comment|/* This is handy if `max_elements' is sufficiently small, as it saves    */
end_comment
begin_comment
comment|/* allocations/releases during the lookup process.                       */
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
name|__FTCMRU_H__
end_ifndef
begin_define
DECL|macro|__FTCMRU_H__
define|#
directive|define
name|__FTCMRU_H__
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
begin_define
DECL|macro|xxFT_DEBUG_ERROR
define|#
directive|define
name|xxFT_DEBUG_ERROR
end_define
begin_define
DECL|macro|FTC_INLINE
define|#
directive|define
name|FTC_INLINE
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|typedef|FTC_MruNode
typedef|typedef
name|struct
name|FTC_MruNodeRec_
modifier|*
name|FTC_MruNode
typedef|;
end_typedef
begin_typedef
DECL|struct|FTC_MruNodeRec_
typedef|typedef
struct|struct
name|FTC_MruNodeRec_
block|{
DECL|member|next
name|FTC_MruNode
name|next
decl_stmt|;
DECL|member|prev
name|FTC_MruNode
name|prev
decl_stmt|;
block|}
DECL|typedef|FTC_MruNodeRec
name|FTC_MruNodeRec
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FTC_MruNode_Prepend
argument_list|(
argument|FTC_MruNode  *plist
argument_list|,
argument|FTC_MruNode   node
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
name|FTC_MruNode_Up
argument_list|(
argument|FTC_MruNode  *plist
argument_list|,
argument|FTC_MruNode   node
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
name|FTC_MruNode_Remove
argument_list|(
argument|FTC_MruNode  *plist
argument_list|,
argument|FTC_MruNode   node
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|typedef|FTC_MruList
typedef|typedef
name|struct
name|FTC_MruListRec_
modifier|*
name|FTC_MruList
typedef|;
end_typedef
begin_typedef
DECL|typedef|FTC_MruListClass
typedef|typedef
name|struct
name|FTC_MruListClassRec_
specifier|const
modifier|*
name|FTC_MruListClass
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Bool
function_decl|(
DECL|typedef|FTC_MruNode_CompareFunc
modifier|*
name|FTC_MruNode_CompareFunc
function_decl|)
parameter_list|(
name|FTC_MruNode
name|node
parameter_list|,
name|FT_Pointer
name|key
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FTC_MruNode_InitFunc
modifier|*
name|FTC_MruNode_InitFunc
function_decl|)
parameter_list|(
name|FTC_MruNode
name|node
parameter_list|,
name|FT_Pointer
name|key
parameter_list|,
name|FT_Pointer
name|data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FTC_MruNode_ResetFunc
modifier|*
name|FTC_MruNode_ResetFunc
function_decl|)
parameter_list|(
name|FTC_MruNode
name|node
parameter_list|,
name|FT_Pointer
name|key
parameter_list|,
name|FT_Pointer
name|data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FTC_MruNode_DoneFunc
modifier|*
name|FTC_MruNode_DoneFunc
function_decl|)
parameter_list|(
name|FTC_MruNode
name|node
parameter_list|,
name|FT_Pointer
name|data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|FTC_MruListClassRec_
typedef|typedef
struct|struct
name|FTC_MruListClassRec_
block|{
DECL|member|node_size
name|FT_Offset
name|node_size
decl_stmt|;
DECL|member|node_compare
name|FTC_MruNode_CompareFunc
name|node_compare
decl_stmt|;
DECL|member|node_init
name|FTC_MruNode_InitFunc
name|node_init
decl_stmt|;
DECL|member|node_reset
name|FTC_MruNode_ResetFunc
name|node_reset
decl_stmt|;
DECL|member|node_done
name|FTC_MruNode_DoneFunc
name|node_done
decl_stmt|;
block|}
DECL|typedef|FTC_MruListClassRec
name|FTC_MruListClassRec
typedef|;
end_typedef
begin_typedef
DECL|struct|FTC_MruListRec_
typedef|typedef
struct|struct
name|FTC_MruListRec_
block|{
DECL|member|num_nodes
name|FT_UInt
name|num_nodes
decl_stmt|;
DECL|member|max_nodes
name|FT_UInt
name|max_nodes
decl_stmt|;
DECL|member|nodes
name|FTC_MruNode
name|nodes
decl_stmt|;
DECL|member|data
name|FT_Pointer
name|data
decl_stmt|;
DECL|member|clazz
name|FTC_MruListClassRec
name|clazz
decl_stmt|;
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
block|}
DECL|typedef|FTC_MruListRec
name|FTC_MruListRec
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FTC_MruList_Init
argument_list|(
argument|FTC_MruList       list
argument_list|,
argument|FTC_MruListClass  clazz
argument_list|,
argument|FT_UInt           max_nodes
argument_list|,
argument|FT_Pointer        data
argument_list|,
argument|FT_Memory         memory
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
DECL|variable|list
name|FTC_MruList_Reset
argument_list|(
argument|FTC_MruList  list
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|list
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|list
name|FTC_MruList_Done
argument_list|(
argument|FTC_MruList  list
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|list
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_MruList_New
argument_list|(
argument|FTC_MruList   list
argument_list|,
argument|FT_Pointer    key
argument_list|,
argument|FTC_MruNode  *anode
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
DECL|variable|FTC_MruList_Remove
name|FTC_MruList_Remove
argument_list|(
argument|FTC_MruList  list
argument_list|,
argument|FTC_MruNode  node
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
name|FTC_MruList_RemoveSelection
argument_list|(
argument|FTC_MruList              list
argument_list|,
argument|FTC_MruNode_CompareFunc  selection
argument_list|,
argument|FT_Pointer               key
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
DECL|macro|FTC_MRULIST_LOOKUP_CMP
define|#
directive|define
name|FTC_MRULIST_LOOKUP_CMP
parameter_list|(
name|list
parameter_list|,
name|key
parameter_list|,
name|compare
parameter_list|,
name|node
parameter_list|,
name|error
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                            \     FTC_MruNode*             _pfirst  =&(list)->nodes;                     \     FTC_MruNode_CompareFunc  _compare = (FTC_MruNode_CompareFunc)(compare); \     FTC_MruNode              _first, _node;                                 \                                                                             \                                                                             \     error  = 0;                                                             \     _first = *(_pfirst);                                                    \     _node  = NULL;                                                          \                                                                             \     if ( _first )                                                           \     {                                                                       \       _node = _first;                                                       \       do                                                                    \       {                                                                     \         if ( _compare( _node, (key) ) )                                     \         {                                                                   \           if ( _node != _first )                                            \             FTC_MruNode_Up( _pfirst, _node );                               \                                                                             \           node = _node;                                                     \           goto _MruOk;                                                      \         }                                                                   \         _node = _node->next;                                                \                                                                             \       } while ( _node != _first) ;                                          \     }                                                                       \                                                                             \     error = FTC_MruList_New( (list), (key), (FTC_MruNode*)(void*)&(node) ); \   _MruOk:                                                                   \     ;                                                                       \   FT_END_STMNT
end_define
begin_define
DECL|macro|FTC_MRULIST_LOOKUP
define|#
directive|define
name|FTC_MRULIST_LOOKUP
parameter_list|(
name|list
parameter_list|,
name|key
parameter_list|,
name|node
parameter_list|,
name|error
parameter_list|)
define|\
value|FTC_MRULIST_LOOKUP_CMP( list, key, (list)->clazz.node_compare, node, error )
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FTC_INLINE */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FTC_MruNode
argument_list|)
end_macro
begin_macro
name|FTC_MruList_Find
argument_list|(
argument|FTC_MruList  list
argument_list|,
argument|FT_Pointer   key
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
DECL|variable|FTC_MruList_Lookup
name|FTC_MruList_Lookup
argument_list|(
argument|FTC_MruList   list
argument_list|,
argument|FT_Pointer    key
argument_list|,
argument|FTC_MruNode  *pnode
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|FTC_MRULIST_LOOKUP
define|#
directive|define
name|FTC_MRULIST_LOOKUP
parameter_list|(
name|list
parameter_list|,
name|key
parameter_list|,
name|node
parameter_list|,
name|error
parameter_list|)
define|\
value|error = FTC_MruList_Lookup( (list), (key), (FTC_MruNode*)&(node) )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FTC_INLINE */
end_comment
begin_define
DECL|macro|FTC_MRULIST_LOOP
define|#
directive|define
name|FTC_MRULIST_LOOP
parameter_list|(
name|list
parameter_list|,
name|node
parameter_list|)
define|\
value|FT_BEGIN_STMNT                              \     FTC_MruNode  _first = (list)->nodes;      \                                               \                                               \     if ( _first )                             \     {                                         \       FTC_MruNode  _node = _first;            \                                               \                                               \       do                                      \       {                                       \         *(FTC_MruNode*)&(node) = _node;
end_define
begin_define
DECL|macro|FTC_MRULIST_LOOP_END
define|#
directive|define
name|FTC_MRULIST_LOOP_END
parameter_list|()
define|\
value|_node = _node->next;                 \                                              \       } while ( _node != _first );           \     }                                        \   FT_END_STMNT
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
comment|/* __FTCMRU_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
