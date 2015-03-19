begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftmac.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Additional Mac-specific API.                                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2004, 2006, 2007, 2013 by                         */
end_comment
begin_comment
comment|/*  Just van Rossum, David Turner, Robert Wilhelm, and Werner Lemberg.     */
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
comment|/*                                                                         */
end_comment
begin_comment
comment|/* NOTE: Include this file after FT_FREETYPE_H and after any               */
end_comment
begin_comment
comment|/*       Mac-specific headers (because this header uses Mac types such as  */
end_comment
begin_comment
comment|/*       Handle, FSSpec, FSRef, etc.)                                      */
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
name|__FTMAC_H__
end_ifndef
begin_define
DECL|macro|__FTMAC_H__
define|#
directive|define
name|__FTMAC_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/* gcc-3.4.1 and later can warn about functions tagged as deprecated */
ifndef|#
directive|ifndef
name|FT_DEPRECATED_ATTRIBUTE
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
expr|\
operator|(
operator|(
name|__GNUC__
operator|>=
literal|4
operator|)
operator|||
operator|(
operator|(
name|__GNUC__
operator|==
literal|3
operator|)
operator|&&
operator|(
name|__GNUC_MINOR__
operator|>=
literal|1
operator|)
operator|)
operator|)
DECL|macro|FT_DEPRECATED_ATTRIBUTE
define|#
directive|define
name|FT_DEPRECATED_ATTRIBUTE
value|__attribute__((deprecated))
else|#
directive|else
define|#
directive|define
name|FT_DEPRECATED_ATTRIBUTE
endif|#
directive|endif
endif|#
directive|endif
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Section>                                                             */
comment|/*    mac_specific                                                       */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    Mac Specific Interface                                             */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    Only available on the Macintosh.                                   */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    The following definitions are only available if FreeType is        */
comment|/*    compiled on a Macintosh.                                           */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*    FT_New_Face_From_FOND                                              */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    Create a new face object from a FOND resource.                     */
comment|/*                                                                       */
comment|/*<InOut>                                                               */
comment|/*    library    :: A handle to the library resource.                    */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*    fond       :: A FOND resource.                                     */
comment|/*                                                                       */
comment|/*    face_index :: Only supported for the -1 `sanity check' special     */
comment|/*                  case.                                                */
comment|/*                                                                       */
comment|/*<Output>                                                              */
comment|/*    aface      :: A handle to a new face object.                       */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*    FreeType error code.  0~means success.                             */
comment|/*                                                                       */
comment|/*<Notes>                                                               */
comment|/*    This function can be used to create @FT_Face objects from fonts    */
comment|/*    that are installed in the system as follows.                       */
comment|/*                                                                       */
comment|/*    {                                                                  */
comment|/*      fond = GetResource( 'FOND', fontName );                          */
comment|/*      error = FT_New_Face_From_FOND( library, fond, 0,&face );        */
comment|/*    }                                                                  */
comment|/*                                                                       */
name|FT_EXPORT
argument_list|(
name|FT_Error
argument_list|)
name|FT_New_Face_From_FOND
argument_list|(
name|FT_Library
name|library
argument_list|,
name|Handle
name|fond
argument_list|,
name|FT_Long
name|face_index
argument_list|,
name|FT_Face
operator|*
name|aface
argument_list|)
name|FT_DEPRECATED_ATTRIBUTE
decl_stmt|;
end_decl_stmt
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
comment|/*    FT_GetFile_From_Mac_Name                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return an FSSpec for the disk file containing the named font.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    fontName   :: Mac OS name of the font (e.g., Times New Roman       */
end_comment
begin_comment
comment|/*                  Bold).                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    pathSpec   :: FSSpec to the file.  For passing to                  */
end_comment
begin_comment
comment|/*                  @FT_New_Face_From_FSSpec.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: Index of the face.  For passing to                   */
end_comment
begin_comment
comment|/*                  @FT_New_Face_From_FSSpec.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GetFile_From_Mac_Name
argument_list|(
argument|const char*  fontName
argument_list|,
argument|FSSpec*      pathSpec
argument_list|,
argument|FT_Long*     face_index
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|FT_DEPRECATED_ATTRIBUTE
name|FT_DEPRECATED_ATTRIBUTE
expr_stmt|;
end_expr_stmt
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
comment|/*    FT_GetFile_From_Mac_ATS_Name                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return an FSSpec for the disk file containing the named font.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    fontName   :: Mac OS name of the font in ATS framework.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    pathSpec   :: FSSpec to the file. For passing to                   */
end_comment
begin_comment
comment|/*                  @FT_New_Face_From_FSSpec.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: Index of the face. For passing to                    */
end_comment
begin_comment
comment|/*                  @FT_New_Face_From_FSSpec.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GetFile_From_Mac_ATS_Name
argument_list|(
argument|const char*  fontName
argument_list|,
argument|FSSpec*      pathSpec
argument_list|,
argument|FT_Long*     face_index
argument_list|)
end_macro
begin_expr_stmt
name|FT_DEPRECATED_ATTRIBUTE
expr_stmt|;
end_expr_stmt
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
comment|/*    FT_GetFilePath_From_Mac_ATS_Name                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return a pathname of the disk file and face index for given font   */
end_comment
begin_comment
comment|/*    name that is handled by ATS framework.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    fontName    :: Mac OS name of the font in ATS framework.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    path        :: Buffer to store pathname of the file.  For passing  */
end_comment
begin_comment
comment|/*                   to @FT_New_Face.  The client must allocate this     */
end_comment
begin_comment
comment|/*                   buffer before calling this function.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxPathSize :: Lengths of the buffer `path' that client allocated. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index  :: Index of the face.  For passing to @FT_New_Face.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GetFilePath_From_Mac_ATS_Name
argument_list|(
argument|const char*  fontName
argument_list|,
argument|UInt8*       path
argument_list|,
argument|UInt32       maxPathSize
argument_list|,
argument|FT_Long*     face_index
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|FT_DEPRECATED_ATTRIBUTE
name|FT_DEPRECATED_ATTRIBUTE
expr_stmt|;
end_expr_stmt
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
comment|/*    FT_New_Face_From_FSSpec                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Create a new face object from a given resource and typeface index  */
end_comment
begin_comment
comment|/*    using an FSSpec to the font file.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library    :: A handle to the library resource.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    spec       :: FSSpec to the font file.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: The index of the face within the resource.  The      */
end_comment
begin_comment
comment|/*                  first face has index~0.                              */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aface      :: A handle to a new face object.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    @FT_New_Face_From_FSSpec is identical to @FT_New_Face except       */
end_comment
begin_comment
comment|/*    it accepts an FSSpec instead of a path.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_New_Face_From_FSSpec
argument_list|(
argument|FT_Library     library
argument_list|,
argument|const FSSpec  *spec
argument_list|,
argument|FT_Long        face_index
argument_list|,
argument|FT_Face       *aface
argument_list|)
end_macro
begin_expr_stmt
name|FT_DEPRECATED_ATTRIBUTE
expr_stmt|;
end_expr_stmt
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
comment|/*    FT_New_Face_From_FSRef                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Create a new face object from a given resource and typeface index  */
end_comment
begin_comment
comment|/*    using an FSRef to the font file.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library    :: A handle to the library resource.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    spec       :: FSRef to the font file.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: The index of the face within the resource.  The      */
end_comment
begin_comment
comment|/*                  first face has index~0.                              */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aface      :: A handle to a new face object.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    @FT_New_Face_From_FSRef is identical to @FT_New_Face except        */
end_comment
begin_comment
comment|/*    it accepts an FSRef instead of a path.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_New_Face_From_FSRef
argument_list|(
argument|FT_Library    library
argument_list|,
argument|const FSRef  *ref
argument_list|,
argument|FT_Long       face_index
argument_list|,
argument|FT_Face      *aface
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|FT_DEPRECATED_ATTRIBUTE
name|FT_DEPRECATED_ATTRIBUTE
expr_stmt|;
end_expr_stmt
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
comment|/* __FTMAC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
