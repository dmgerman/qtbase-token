begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcglyph.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType Glyph Image (FT_Glyph) cache (body).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2003, 2004, 2006, 2009 by                         */
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
begin_include
include|#
directive|include
include|FT_ERRORS_H
end_include
begin_include
include|#
directive|include
file|"ftccback.h"
end_include
begin_include
include|#
directive|include
file|"ftcerror.h"
end_include
begin_comment
comment|/* create a new chunk node, setting its cache index and ref count */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_GNode_Init
name|FTC_GNode_Init
argument_list|(
argument|FTC_GNode   gnode
argument_list|,
argument|FT_UInt     gindex
argument_list|,
argument|FTC_Family  family
argument_list|)
end_macro
begin_block
block|{
name|gnode
operator|->
name|family
operator|=
name|family
expr_stmt|;
name|gnode
operator|->
name|gindex
operator|=
name|gindex
expr_stmt|;
name|family
operator|->
name|num_nodes
operator|++
expr_stmt|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_GNode_UnselectFamily
name|FTC_GNode_UnselectFamily
argument_list|(
argument|FTC_GNode  gnode
argument_list|,
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_block
block|{
name|FTC_Family
name|family
init|=
name|gnode
operator|->
name|family
decl_stmt|;
name|gnode
operator|->
name|family
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|family
operator|&&
operator|--
name|family
operator|->
name|num_nodes
operator|==
literal|0
condition|)
name|FTC_FAMILY_FREE
argument_list|(
name|family
argument_list|,
name|cache
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_GNode_Done
name|FTC_GNode_Done
argument_list|(
argument|FTC_GNode  gnode
argument_list|,
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_block
block|{
comment|/* finalize the node */
name|gnode
operator|->
name|gindex
operator|=
literal|0
expr_stmt|;
name|FTC_GNode_UnselectFamily
argument_list|(
name|gnode
argument_list|,
name|cache
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|ftc_gnode_compare
argument_list|(
argument|FTC_Node    ftcgnode
argument_list|,
argument|FT_Pointer  ftcgquery
argument_list|,
argument|FTC_Cache   cache
argument_list|)
end_macro
begin_block
block|{
name|FTC_GNode
name|gnode
init|=
operator|(
name|FTC_GNode
operator|)
name|ftcgnode
decl_stmt|;
name|FTC_GQuery
name|gquery
init|=
operator|(
name|FTC_GQuery
operator|)
name|ftcgquery
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|cache
argument_list|)
expr_stmt|;
return|return
name|FT_BOOL
argument_list|(
name|gnode
operator|->
name|family
operator|==
name|gquery
operator|->
name|family
operator|&&
name|gnode
operator|->
name|gindex
operator|==
name|gquery
operator|->
name|gindex
argument_list|)
return|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
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
begin_block
block|{
return|return
name|ftc_gnode_compare
argument_list|(
name|FTC_NODE
argument_list|(
name|gnode
argument_list|)
argument_list|,
name|gquery
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_block
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
comment|/*****                      CHUNK SETS                               *****/
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
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_Family_Init
name|FTC_Family_Init
argument_list|(
argument|FTC_Family  family
argument_list|,
argument|FTC_Cache   cache
argument_list|)
end_macro
begin_block
block|{
name|FTC_GCacheClass
name|clazz
init|=
name|FTC_CACHE__GCACHE_CLASS
argument_list|(
name|cache
argument_list|)
decl_stmt|;
name|family
operator|->
name|clazz
operator|=
name|clazz
operator|->
name|family_class
expr_stmt|;
name|family
operator|->
name|num_nodes
operator|=
literal|0
expr_stmt|;
name|family
operator|->
name|cache
operator|=
name|cache
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ftc_gcache_init
argument_list|(
argument|FTC_Cache  ftccache
argument_list|)
end_macro
begin_block
block|{
name|FTC_GCache
name|cache
init|=
operator|(
name|FTC_GCache
operator|)
name|ftccache
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|error
operator|=
name|FTC_Cache_Init
argument_list|(
name|FTC_CACHE
argument_list|(
name|cache
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|FTC_GCacheClass
name|clazz
init|=
operator|(
name|FTC_GCacheClass
operator|)
name|FTC_CACHE
argument_list|(
name|cache
argument_list|)
operator|->
name|org_class
decl_stmt|;
name|FTC_MruList_Init
argument_list|(
operator|&
name|cache
operator|->
name|families
argument_list|,
name|clazz
operator|->
name|family_class
argument_list|,
literal|0
argument_list|,
comment|/* no maximum here! */
name|cache
argument_list|,
name|FTC_CACHE
argument_list|(
name|cache
argument_list|)
operator|->
name|memory
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_if
if|#
directive|if
literal|0
end_if
begin_endif
unit|FT_LOCAL_DEF( FT_Error )   FTC_GCache_Init( FTC_GCache  cache )   {     return ftc_gcache_init( FTC_CACHE( cache ) );   }
endif|#
directive|endif
end_endif
begin_comment
comment|/* 0 */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ftc_gcache_done
name|ftc_gcache_done
argument_list|(
argument|FTC_Cache  ftccache
argument_list|)
end_macro
begin_block
block|{
name|FTC_GCache
name|cache
init|=
operator|(
name|FTC_GCache
operator|)
name|ftccache
decl_stmt|;
name|FTC_Cache_Done
argument_list|(
operator|(
name|FTC_Cache
operator|)
name|cache
argument_list|)
expr_stmt|;
name|FTC_MruList_Done
argument_list|(
operator|&
name|cache
operator|->
name|families
argument_list|)
expr_stmt|;
block|}
end_block
begin_if
if|#
directive|if
literal|0
end_if
begin_endif
unit|FT_LOCAL_DEF( void )   FTC_GCache_Done( FTC_GCache  cache )   {     ftc_gcache_done( FTC_CACHE( cache ) );   }
endif|#
directive|endif
end_endif
begin_comment
comment|/* 0 */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
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
begin_block
block|{
return|return
name|FTC_Manager_RegisterCache
argument_list|(
name|manager
argument_list|,
operator|(
name|FTC_CacheClass
operator|)
name|clazz
argument_list|,
operator|(
name|FTC_Cache
operator|*
operator|)
name|acache
argument_list|)
return|;
block|}
end_block
begin_ifndef
ifndef|#
directive|ifndef
name|FTC_INLINE
end_ifndef
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
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
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|query
operator|->
name|gindex
operator|=
name|gindex
expr_stmt|;
name|FTC_MRULIST_LOOKUP
argument_list|(
operator|&
name|cache
operator|->
name|families
argument_list|,
name|query
argument_list|,
name|query
operator|->
name|family
argument_list|,
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|FTC_Family
name|family
init|=
name|query
operator|->
name|family
decl_stmt|;
comment|/* prevent the family from being destroyed too early when an        */
comment|/* out-of-memory condition occurs during glyph node initialization. */
name|family
operator|->
name|num_nodes
operator|++
expr_stmt|;
name|error
operator|=
name|FTC_Cache_Lookup
argument_list|(
name|FTC_CACHE
argument_list|(
name|cache
argument_list|)
argument_list|,
name|hash
argument_list|,
name|query
argument_list|,
name|anode
argument_list|)
expr_stmt|;
if|if
condition|(
operator|--
name|family
operator|->
name|num_nodes
operator|==
literal|0
condition|)
name|FTC_FAMILY_FREE
argument_list|(
name|family
argument_list|,
name|cache
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FTC_INLINE */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
