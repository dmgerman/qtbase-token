begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2error.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for error handling (specification).                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2006-2013 Adobe Systems Incorporated.                        */
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
name|__CF2ERROR_H__
end_ifndef
begin_define
DECL|macro|__CF2ERROR_H__
define|#
directive|define
name|__CF2ERROR_H__
end_define
begin_include
include|#
directive|include
include|FT_MODULE_ERRORS_H
end_include
begin_undef
DECL|macro|__FTERRORS_H__
undef|#
directive|undef
name|__FTERRORS_H__
end_undef
begin_undef
DECL|macro|FT_ERR_PREFIX
undef|#
directive|undef
name|FT_ERR_PREFIX
end_undef
begin_define
DECL|macro|FT_ERR_PREFIX
define|#
directive|define
name|FT_ERR_PREFIX
value|CF2_Err_
end_define
begin_define
DECL|macro|FT_ERR_BASE
define|#
directive|define
name|FT_ERR_BASE
value|FT_Mod_Err_CF2
end_define
begin_include
include|#
directive|include
include|FT_ERRORS_H
end_include
begin_include
include|#
directive|include
file|"cf2ft.h"
end_include
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*    * A poor-man error facility.    *    * This code being written in vanilla C, doesn't have the luxury of a    * language-supported exception mechanism such as the one available in    * Java.  Instead, we are stuck with using error codes that must be    * carefully managed and preserved.  However, it is convenient for us to    * model our error mechanism on a Java-like exception mechanism.    * When we assign an error code we are thus `throwing' an error.    *    * The perservation of an error code is done by coding convention.    * Upon a function call if the error code is anything other than    * `FT_Err_Ok', which is guaranteed to be zero, we    * will return without altering that error.  This will allow the    * error to propogate and be handled at the appropriate location in    * the code.    *    * This allows a style of code where the error code is initialized    * up front and a block of calls are made with the error code only    * being checked after the block.  If a new error occurs, the original    * error will be preserved and a functional no-op should result in any    * subsequent function that has an initial error code not equal to    * `FT_Err_Ok'.    *    * Errors are encoded by calling the `FT_THROW' macro.  For example,    *    * {    *   FT_Error  e;    *    *    *   ...    *   e = FT_THROW( Out_Of_Memory );    * }    *    */
comment|/* Set error code to a particular value. */
name|FT_LOCAL
parameter_list|(
name|void
parameter_list|)
function_decl|cf2_setError
parameter_list|(
name|FT_Error
modifier|*
name|error
parameter_list|,
name|FT_Error
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*    * A macro that conditionally sets an error code.    *    * This macro will first check whether `error' is set;    * if not, it will set it to `e'.    *   */
end_comment
begin_define
DECL|macro|CF2_SET_ERROR
define|#
directive|define
name|CF2_SET_ERROR
parameter_list|(
name|error
parameter_list|,
name|e
parameter_list|)
define|\
value|cf2_setError( error, FT_THROW( e ) )
end_define
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CF2ERROR_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
