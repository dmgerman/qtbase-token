begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftrfork.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Embedded resource forks accessor (specification).                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2006, 2007 by                                          */
end_comment
begin_comment
comment|/*  Masatake YAMATO and Redhat K.K.                                        */
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
comment|/***************************************************************************/
end_comment
begin_comment
comment|/* Development of the code in this file is support of                      */
end_comment
begin_comment
comment|/* Information-technology Promotion Agency, Japan.                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTRFORK_H__
end_ifndef
begin_define
DECL|macro|__FTRFORK_H__
define|#
directive|define
name|__FTRFORK_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* Number of guessing rules supported in `FT_Raccess_Guess'.            */
end_comment
begin_comment
comment|/* Don't forget to increment the number if you add a new guessing rule. */
end_comment
begin_define
DECL|macro|FT_RACCESS_N_RULES
define|#
directive|define
name|FT_RACCESS_N_RULES
value|9
end_define
begin_comment
comment|/* A structure to describe a reference in a resource by its resource ID */
end_comment
begin_comment
comment|/* and internal offset.  The `POST' resource expects to be concatenated */
end_comment
begin_comment
comment|/* by the order of resource IDs instead of its appearance in the file.  */
end_comment
begin_typedef
DECL|struct|FT_RFork_Ref_
typedef|typedef
struct|struct
name|FT_RFork_Ref_
block|{
DECL|member|res_id
name|FT_UShort
name|res_id
decl_stmt|;
DECL|member|offset
name|FT_ULong
name|offset
decl_stmt|;
block|}
DECL|typedef|FT_RFork_Ref
name|FT_RFork_Ref
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
comment|/*    FT_Raccess_Guess                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Guess a file name and offset where the actual resource fork is     */
end_comment
begin_comment
comment|/*    stored.  The macro FT_RACCESS_N_RULES holds the number of          */
end_comment
begin_comment
comment|/*    guessing rules;  the guessed result for the Nth rule is            */
end_comment
begin_comment
comment|/*    represented as a triplet: a new file name (new_names[N]), a file   */
end_comment
begin_comment
comment|/*    offset (offsets[N]), and an error code (errors[N]).                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library ::                                                         */
end_comment
begin_comment
comment|/*      A FreeType library instance.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream ::                                                          */
end_comment
begin_comment
comment|/*      A file stream containing the resource fork.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    base_name ::                                                       */
end_comment
begin_comment
comment|/*      The (base) file name of the resource fork used for some          */
end_comment
begin_comment
comment|/*      guessing rules.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    new_names ::                                                       */
end_comment
begin_comment
comment|/*      An array of guessed file names in which the resource forks may   */
end_comment
begin_comment
comment|/*      exist.  If `new_names[N]' is NULL, the guessed file name is      */
end_comment
begin_comment
comment|/*      equal to `base_name'.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    offsets ::                                                         */
end_comment
begin_comment
comment|/*      An array of guessed file offsets.  `offsets[N]' holds the file   */
end_comment
begin_comment
comment|/*      offset of the possible start of the resource fork in file        */
end_comment
begin_comment
comment|/*      `new_names[N]'.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    errors ::                                                          */
end_comment
begin_comment
comment|/*      An array of FreeType error codes.  `errors[N]' is the error      */
end_comment
begin_comment
comment|/*      code of Nth guessing rule function.  If `errors[N]' is not       */
end_comment
begin_comment
comment|/*      FT_Err_Ok, `new_names[N]' and `offsets[N]' are meaningless.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Raccess_Guess
argument_list|(
argument|FT_Library  library
argument_list|,
argument|FT_Stream   stream
argument_list|,
argument|char*       base_name
argument_list|,
argument|char**      new_names
argument_list|,
argument|FT_Long*    offsets
argument_list|,
argument|FT_Error*   errors
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/*    FT_Raccess_Get_HeaderInfo                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Get the information from the header of resource fork.  The         */
end_comment
begin_comment
comment|/*    information includes the file offset where the resource map        */
end_comment
begin_comment
comment|/*    starts, and the file offset where the resource data starts.        */
end_comment
begin_comment
comment|/*    `FT_Raccess_Get_DataOffsets' requires these two data.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library ::                                                         */
end_comment
begin_comment
comment|/*      A FreeType library instance.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream ::                                                          */
end_comment
begin_comment
comment|/*      A file stream containing the resource fork.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    rfork_offset ::                                                    */
end_comment
begin_comment
comment|/*      The file offset where the resource fork starts.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    map_offset ::                                                      */
end_comment
begin_comment
comment|/*      The file offset where the resource map starts.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    rdata_pos ::                                                       */
end_comment
begin_comment
comment|/*      The file offset where the resource data starts.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  FT_Err_Ok means success.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Raccess_Get_HeaderInfo
argument_list|(
argument|FT_Library  library
argument_list|,
argument|FT_Stream   stream
argument_list|,
argument|FT_Long     rfork_offset
argument_list|,
argument|FT_Long    *map_offset
argument_list|,
argument|FT_Long    *rdata_pos
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/*    FT_Raccess_Get_DataOffsets                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Get the data offsets for a tag in a resource fork.  Offsets are    */
end_comment
begin_comment
comment|/*    stored in an array because, in some cases, resources in a resource */
end_comment
begin_comment
comment|/*    fork have the same tag.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library ::                                                         */
end_comment
begin_comment
comment|/*      A FreeType library instance.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream ::                                                          */
end_comment
begin_comment
comment|/*      A file stream containing the resource fork.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    map_offset ::                                                      */
end_comment
begin_comment
comment|/*      The file offset where the resource map starts.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    rdata_pos ::                                                       */
end_comment
begin_comment
comment|/*      The file offset where the resource data starts.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    tag ::                                                             */
end_comment
begin_comment
comment|/*      The resource tag.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    offsets ::                                                         */
end_comment
begin_comment
comment|/*      The stream offsets for the resource data specified by `tag'.     */
end_comment
begin_comment
comment|/*      This array is allocated by the function, so you have to call     */
end_comment
begin_comment
comment|/*      @ft_mem_free after use.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    count ::                                                           */
end_comment
begin_comment
comment|/*      The length of offsets array.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  FT_Err_Ok means success.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Normally you should use `FT_Raccess_Get_HeaderInfo' to get the     */
end_comment
begin_comment
comment|/*    value for `map_offset' and `rdata_pos'.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Raccess_Get_DataOffsets
name|FT_Raccess_Get_DataOffsets
argument_list|(
argument|FT_Library  library
argument_list|,
argument|FT_Stream   stream
argument_list|,
argument|FT_Long     map_offset
argument_list|,
argument|FT_Long     rdata_pos
argument_list|,
argument|FT_Long     tag
argument_list|,
argument|FT_Long   **offsets
argument_list|,
argument|FT_Long    *count
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTRFORK_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
