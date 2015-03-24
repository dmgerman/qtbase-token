begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftbdf.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for accessing BDF-specific strings (specification).     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2004, 2006, 2009, 2014 by                               */
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
name|__FTBDF_H__
end_ifndef
begin_define
DECL|macro|__FTBDF_H__
define|#
directive|define
name|__FTBDF_H__
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
comment|/*    bdf_fonts                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    BDF and PCF Files                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    BDF and PCF specific API.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section contains the declaration of functions specific to BDF */
end_comment
begin_comment
comment|/*    and PCF fonts.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/**********************************************************************    *    * @enum:    *    BDF_PropertyType    *    * @description:    *    A list of BDF property types.    *    * @values:    *    BDF_PROPERTY_TYPE_NONE ::    *      Value~0 is used to indicate a missing property.    *    *    BDF_PROPERTY_TYPE_ATOM ::    *      Property is a string atom.    *    *    BDF_PROPERTY_TYPE_INTEGER ::    *      Property is a 32-bit signed integer.    *    *    BDF_PROPERTY_TYPE_CARDINAL ::    *      Property is a 32-bit unsigned integer.    */
end_comment
begin_typedef
DECL|enum|BDF_PropertyType_
typedef|typedef
enum|enum
name|BDF_PropertyType_
block|{
DECL|enumerator|BDF_PROPERTY_TYPE_NONE
name|BDF_PROPERTY_TYPE_NONE
init|=
literal|0
block|,
DECL|enumerator|BDF_PROPERTY_TYPE_ATOM
name|BDF_PROPERTY_TYPE_ATOM
init|=
literal|1
block|,
DECL|enumerator|BDF_PROPERTY_TYPE_INTEGER
name|BDF_PROPERTY_TYPE_INTEGER
init|=
literal|2
block|,
DECL|enumerator|BDF_PROPERTY_TYPE_CARDINAL
name|BDF_PROPERTY_TYPE_CARDINAL
init|=
literal|3
block|}
DECL|typedef|BDF_PropertyType
name|BDF_PropertyType
typedef|;
end_typedef
begin_comment
comment|/**********************************************************************    *    * @type:    *    BDF_Property    *    * @description:    *    A handle to a @BDF_PropertyRec structure to model a given    *    BDF/PCF property.    */
end_comment
begin_typedef
DECL|typedef|BDF_Property
typedef|typedef
name|struct
name|BDF_PropertyRec_
modifier|*
name|BDF_Property
typedef|;
end_typedef
begin_comment
comment|/**********************************************************************   *   * @struct:   *    BDF_PropertyRec   *   * @description:   *    This structure models a given BDF/PCF property.   *   * @fields:   *    type ::   *      The property type.   *   *    u.atom ::   *      The atom string, if type is @BDF_PROPERTY_TYPE_ATOM.  May be   *      NULL, indicating an empty string.   *   *    u.integer ::   *      A signed integer, if type is @BDF_PROPERTY_TYPE_INTEGER.   *   *    u.cardinal ::   *      An unsigned integer, if type is @BDF_PROPERTY_TYPE_CARDINAL.   */
end_comment
begin_typedef
DECL|struct|BDF_PropertyRec_
typedef|typedef
struct|struct
name|BDF_PropertyRec_
block|{
DECL|member|type
name|BDF_PropertyType
name|type
decl_stmt|;
union|union
block|{
DECL|member|atom
specifier|const
name|char
modifier|*
name|atom
decl_stmt|;
DECL|member|integer
name|FT_Int32
name|integer
decl_stmt|;
DECL|member|cardinal
name|FT_UInt32
name|cardinal
decl_stmt|;
block|}
DECL|member|u
name|u
union|;
block|}
DECL|typedef|BDF_PropertyRec
name|BDF_PropertyRec
typedef|;
end_typedef
begin_comment
comment|/**********************************************************************   *   * @function:   *    FT_Get_BDF_Charset_ID   *   * @description:   *    Retrieve a BDF font character set identity, according to   *    the BDF specification.   *   * @input:   *    face ::   *       A handle to the input face.   *   * @output:   *    acharset_encoding ::   *       Charset encoding, as a C~string, owned by the face.   *   *    acharset_registry ::   *       Charset registry, as a C~string, owned by the face.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   This function only works with BDF faces, returning an error otherwise.   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_BDF_Charset_ID
argument_list|(
argument|FT_Face       face
argument_list|,
argument|const char*  *acharset_encoding
argument_list|,
argument|const char*  *acharset_registry
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**********************************************************************   *   * @function:   *    FT_Get_BDF_Property   *   * @description:   *    Retrieve a BDF property from a BDF or PCF font file.   *   * @input:   *    face :: A handle to the input face.   *   *    name :: The property name.   *   * @output:   *    aproperty :: The property.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   This function works with BDF _and_ PCF fonts.  It returns an error   *   otherwise.  It also returns an error if the property is not in the   *   font.   *   *   A `property' is a either key-value pair within the STARTPROPERTIES   *   ... ENDPROPERTIES block of a BDF font or a key-value pair from the   *   `info->props' array within a `FontRec' structure of a PCF font.   *   *   Integer properties are always stored as `signed' within PCF fonts;   *   consequently, @BDF_PROPERTY_TYPE_CARDINAL is a possible return value   *   for BDF fonts only.   *   *   In case of error, `aproperty->type' is always set to   *   @BDF_PROPERTY_TYPE_NONE.   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_BDF_Property
name|FT_Get_BDF_Property
argument_list|(
argument|FT_Face           face
argument_list|,
argument|const char*       prop_name
argument_list|,
argument|BDF_PropertyRec  *aproperty
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
comment|/* __FTBDF_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
