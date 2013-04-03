begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftccback.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Callback functions of the caching sub-system (specification only).   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005, 2006 by                                          */
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
name|__FTCCBACK_H__
end_ifndef
begin_define
DECL|macro|__FTCCBACK_H__
define|#
directive|define
name|__FTCCBACK_H__
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
file|"ftcimage.h"
end_include
begin_include
include|#
directive|include
file|"ftcmanag.h"
end_include
begin_include
include|#
directive|include
file|"ftcglyph.h"
end_include
begin_include
include|#
directive|include
file|"ftcsbits.h"
end_include
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|ftc_inode_free
argument_list|(
argument|FTC_Node   inode
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
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ftc_inode_new
argument_list|(
argument|FTC_Node   *pinode
argument_list|,
argument|FT_Pointer  gquery
argument_list|,
argument|FTC_Cache   cache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Offset
argument_list|)
end_macro
begin_macro
DECL|variable|ftc_inode_weight
name|ftc_inode_weight
argument_list|(
argument|FTC_Node   inode
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
name|ftc_snode_free
argument_list|(
argument|FTC_Node   snode
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
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ftc_snode_new
argument_list|(
argument|FTC_Node   *psnode
argument_list|,
argument|FT_Pointer  gquery
argument_list|,
argument|FTC_Cache   cache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Offset
argument_list|)
end_macro
begin_macro
DECL|variable|ftc_snode_weight
name|ftc_snode_weight
argument_list|(
argument|FTC_Node   snode
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
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|ftc_snode_compare
argument_list|(
argument|FTC_Node    snode
argument_list|,
argument|FT_Pointer  gquery
argument_list|,
argument|FTC_Cache   cache
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
DECL|variable|ftc_gnode_compare
name|ftc_gnode_compare
argument_list|(
argument|FTC_Node    gnode
argument_list|,
argument|FT_Pointer  gquery
argument_list|,
argument|FTC_Cache   cache
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
name|ftc_gcache_init
argument_list|(
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
DECL|variable|ftc_gcache_done
name|ftc_gcache_done
argument_list|(
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|ftc_gcache_done
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ftc_cache_init
argument_list|(
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
DECL|variable|ftc_cache_done
name|ftc_cache_done
argument_list|(
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|ftc_cache_done
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifndef
begin_macro
name|FT_LOCAL
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTCCBACK_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
