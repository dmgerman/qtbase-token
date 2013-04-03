begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afglobal.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter routines to compute global hinting values                */
end_comment
begin_comment
comment|/*    (specification).                                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2005, 2007, 2009 by                              */
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
name|__AF_GLOBAL_H__
end_ifndef
begin_define
DECL|macro|__AF_GLOBAL_H__
define|#
directive|define
name|__AF_GLOBAL_H__
end_define
begin_include
include|#
directive|include
file|"aftypes.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/************************************************************************/
end_comment
begin_comment
comment|/************************************************************************/
end_comment
begin_comment
comment|/*****                                                              *****/
end_comment
begin_comment
comment|/*****                  F A C E   G L O B A L S                     *****/
end_comment
begin_comment
comment|/*****                                                              *****/
end_comment
begin_comment
comment|/************************************************************************/
end_comment
begin_comment
comment|/************************************************************************/
end_comment
begin_comment
comment|/*    *  model the global hints data for a given face, decomposed into    *  script-specific items    */
end_comment
begin_typedef
DECL|typedef|AF_FaceGlobals
typedef|typedef
name|struct
name|AF_FaceGlobalsRec_
modifier|*
name|AF_FaceGlobals
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_face_globals_new
argument_list|(
argument|FT_Face          face
argument_list|,
argument|AF_FaceGlobals  *aglobals
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
DECL|variable|af_face_globals_get_metrics
name|af_face_globals_get_metrics
argument_list|(
argument|AF_FaceGlobals     globals
argument_list|,
argument|FT_UInt            gindex
argument_list|,
argument|FT_UInt            options
argument_list|,
argument|AF_ScriptMetrics  *ametrics
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
DECL|variable|globals
name|af_face_globals_free
argument_list|(
argument|AF_FaceGlobals  globals
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|globals
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|af_face_globals_is_digit
argument_list|(
argument|AF_FaceGlobals  globals
argument_list|,
argument|FT_UInt         gindex
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/* __AF_GLOBALS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
