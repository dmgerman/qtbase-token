begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcmanag.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType Cache Manager (specification).                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2003, 2004, 2006, 2010, 2013 by                   */
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
comment|/* A cache manager is in charge of the following:                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  - Maintain a mapping between generic FTC_FaceIDs and live FT_Face    */
end_comment
begin_comment
comment|/*    objects.  The mapping itself is performed through a user-provided  */
end_comment
begin_comment
comment|/*    callback.  However, the manager maintains a small cache of FT_Face */
end_comment
begin_comment
comment|/*    and FT_Size objects in order to speed up things considerably.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  - Manage one or more cache objects.  Each cache is in charge of      */
end_comment
begin_comment
comment|/*    holding a varying number of `cache nodes'.  Each cache node        */
end_comment
begin_comment
comment|/*    represents a minimal amount of individually accessible cached      */
end_comment
begin_comment
comment|/*    data.  For example, a cache node can be an FT_Glyph image          */
end_comment
begin_comment
comment|/*    containing a vector outline, or some glyph metrics, or anything    */
end_comment
begin_comment
comment|/*    else.                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Each cache node has a certain size in bytes that is added to the   */
end_comment
begin_comment
comment|/*    total amount of `cache memory' within the manager.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    All cache nodes are located in a global LRU list, where the oldest */
end_comment
begin_comment
comment|/*    node is at the tail of the list.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Each node belongs to a single cache, and includes a reference      */
end_comment
begin_comment
comment|/*    count to avoid destroying it (due to caching).                     */
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
name|__FTCMANAG_H__
end_ifndef
begin_define
DECL|macro|__FTCMANAG_H__
define|#
directive|define
name|__FTCMANAG_H__
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
file|"ftcmru.h"
end_include
begin_include
include|#
directive|include
file|"ftccache.h"
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
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    cache_subsystem                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|FTC_MAX_FACES_DEFAULT
define|#
directive|define
name|FTC_MAX_FACES_DEFAULT
value|2
end_define
begin_define
DECL|macro|FTC_MAX_SIZES_DEFAULT
define|#
directive|define
name|FTC_MAX_SIZES_DEFAULT
value|4
end_define
begin_define
DECL|macro|FTC_MAX_BYTES_DEFAULT
define|#
directive|define
name|FTC_MAX_BYTES_DEFAULT
value|200000L
end_define
begin_comment
DECL|macro|FTC_MAX_BYTES_DEFAULT
comment|/* ~200kByte by default */
end_comment
begin_comment
comment|/* maximum number of caches registered in a single manager */
end_comment
begin_define
DECL|macro|FTC_MAX_CACHES
define|#
directive|define
name|FTC_MAX_CACHES
value|16
end_define
begin_typedef
DECL|struct|FTC_ManagerRec_
typedef|typedef
struct|struct
name|FTC_ManagerRec_
block|{
DECL|member|library
name|FT_Library
name|library
decl_stmt|;
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|nodes_list
name|FTC_Node
name|nodes_list
decl_stmt|;
DECL|member|max_weight
name|FT_Offset
name|max_weight
decl_stmt|;
DECL|member|cur_weight
name|FT_Offset
name|cur_weight
decl_stmt|;
DECL|member|num_nodes
name|FT_UInt
name|num_nodes
decl_stmt|;
DECL|member|caches
name|FTC_Cache
name|caches
index|[
name|FTC_MAX_CACHES
index|]
decl_stmt|;
DECL|member|num_caches
name|FT_UInt
name|num_caches
decl_stmt|;
DECL|member|faces
name|FTC_MruListRec
name|faces
decl_stmt|;
DECL|member|sizes
name|FTC_MruListRec
name|sizes
decl_stmt|;
DECL|member|request_data
name|FT_Pointer
name|request_data
decl_stmt|;
DECL|member|request_face
name|FTC_Face_Requester
name|request_face
decl_stmt|;
block|}
DECL|typedef|FTC_ManagerRec
name|FTC_ManagerRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FTC_Manager_Compress                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used to check the state of the cache manager if   */
end_comment
begin_comment
comment|/*    its `num_bytes' field is greater than its `max_bytes' field.  It   */
end_comment
begin_comment
comment|/*    will flush as many old cache nodes as possible (ignoring cache     */
end_comment
begin_comment
comment|/*    nodes with a non-zero reference count).                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    manager :: A handle to the cache manager.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Client applications should not call this function directly.  It is */
end_comment
begin_comment
comment|/*    normally invoked by specific cache implementations.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The reason this function is exported is to allow client-specific   */
end_comment
begin_comment
comment|/*    cache classes.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|manager
name|FTC_Manager_Compress
argument_list|(
argument|FTC_Manager  manager
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|manager
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* try to flush `count' old nodes from the cache; return the number    * of really flushed nodes    */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
name|FTC_Manager_FlushN
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FT_UInt      count
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* this must be used internally for the moment */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FTC_Manager_RegisterCache
name|FTC_Manager_RegisterCache
argument_list|(
argument|FTC_Manager      manager
argument_list|,
argument|FTC_CacheClass   clazz
argument_list|,
argument|FTC_Cache       *acache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_define
DECL|macro|FTC_SCALER_COMPARE
define|#
directive|define
name|FTC_SCALER_COMPARE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|( (a)->face_id      == (b)->face_id&&   \       (a)->width        == (b)->width&&   \       (a)->height       == (b)->height&&   \       ((a)->pixel != 0) == ((b)->pixel != 0)&&   \       ( (a)->pixel ||                             \         ( (a)->x_res == (b)->x_res&&             \           (a)->y_res == (b)->y_res ) ) )
end_define
begin_define
DECL|macro|FTC_SCALER_HASH
define|#
directive|define
name|FTC_SCALER_HASH
parameter_list|(
name|q
parameter_list|)
define|\
value|( _FTC_FACE_ID_HASH( (q)->face_id ) +                     \       (q)->width + (q)->height*7 +                           \       ( (q)->pixel ? 0 : ( (q)->x_res*33 ^ (q)->y_res*61 ) ) )
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
comment|/* __FTCMANAG_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
