begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  fttypes.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType simple types definitions (specification only).              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2004, 2006, 2007, 2008 by                   */
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
name|__FTTYPES_H__
end_ifndef
begin_define
DECL|macro|__FTTYPES_H__
define|#
directive|define
name|__FTTYPES_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_CONFIG_H
end_include
begin_include
include|#
directive|include
include|FT_SYSTEM_H
end_include
begin_include
include|#
directive|include
include|FT_IMAGE_H
end_include
begin_include
include|#
directive|include
file|<stddef.h>
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
comment|/*    basic_types                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Basic Data Types                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    The basic data types defined by the library.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section contains the basic data types defined by FreeType~2,  */
end_comment
begin_comment
comment|/*    ranging from simple scalar types to bitmap descriptors.  More      */
end_comment
begin_comment
comment|/*    font-specific structures are defined in a different section.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Order>                                                               */
end_comment
begin_comment
comment|/*    FT_Byte                                                            */
end_comment
begin_comment
comment|/*    FT_Bytes                                                           */
end_comment
begin_comment
comment|/*    FT_Char                                                            */
end_comment
begin_comment
comment|/*    FT_Int                                                             */
end_comment
begin_comment
comment|/*    FT_UInt                                                            */
end_comment
begin_comment
comment|/*    FT_Int16                                                           */
end_comment
begin_comment
comment|/*    FT_UInt16                                                          */
end_comment
begin_comment
comment|/*    FT_Int32                                                           */
end_comment
begin_comment
comment|/*    FT_UInt32                                                          */
end_comment
begin_comment
comment|/*    FT_Short                                                           */
end_comment
begin_comment
comment|/*    FT_UShort                                                          */
end_comment
begin_comment
comment|/*    FT_Long                                                            */
end_comment
begin_comment
comment|/*    FT_ULong                                                           */
end_comment
begin_comment
comment|/*    FT_Bool                                                            */
end_comment
begin_comment
comment|/*    FT_Offset                                                          */
end_comment
begin_comment
comment|/*    FT_PtrDist                                                         */
end_comment
begin_comment
comment|/*    FT_String                                                          */
end_comment
begin_comment
comment|/*    FT_Tag                                                             */
end_comment
begin_comment
comment|/*    FT_Error                                                           */
end_comment
begin_comment
comment|/*    FT_Fixed                                                           */
end_comment
begin_comment
comment|/*    FT_Pointer                                                         */
end_comment
begin_comment
comment|/*    FT_Pos                                                             */
end_comment
begin_comment
comment|/*    FT_Vector                                                          */
end_comment
begin_comment
comment|/*    FT_BBox                                                            */
end_comment
begin_comment
comment|/*    FT_Matrix                                                          */
end_comment
begin_comment
comment|/*    FT_FWord                                                           */
end_comment
begin_comment
comment|/*    FT_UFWord                                                          */
end_comment
begin_comment
comment|/*    FT_F2Dot14                                                         */
end_comment
begin_comment
comment|/*    FT_UnitVector                                                      */
end_comment
begin_comment
comment|/*    FT_F26Dot6                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Generic                                                         */
end_comment
begin_comment
comment|/*    FT_Generic_Finalizer                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Bitmap                                                          */
end_comment
begin_comment
comment|/*    FT_Pixel_Mode                                                      */
end_comment
begin_comment
comment|/*    FT_Palette_Mode                                                    */
end_comment
begin_comment
comment|/*    FT_Glyph_Format                                                    */
end_comment
begin_comment
comment|/*    FT_IMAGE_TAG                                                       */
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
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Bool                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef of unsigned char, used for simple booleans.  As usual,   */
end_comment
begin_comment
comment|/*    values 1 and~0 represent true and false, respectively.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Bool
typedef|typedef
name|unsigned
name|char
name|FT_Bool
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_FWord                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A signed 16-bit integer used to store a distance in original font  */
end_comment
begin_comment
comment|/*    units.                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_FWord
typedef|typedef
name|signed
name|short
name|FT_FWord
typedef|;
end_typedef
begin_comment
DECL|typedef|FT_FWord
comment|/* distance in FUnits */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_UFWord                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An unsigned 16-bit integer used to store a distance in original    */
end_comment
begin_comment
comment|/*    font units.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_UFWord
typedef|typedef
name|unsigned
name|short
name|FT_UFWord
typedef|;
end_typedef
begin_comment
DECL|typedef|FT_UFWord
comment|/* unsigned distance */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Char                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple typedef for the _signed_ char type.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Char
typedef|typedef
name|signed
name|char
name|FT_Char
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Byte                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple typedef for the _unsigned_ char type.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Byte
typedef|typedef
name|unsigned
name|char
name|FT_Byte
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Bytes                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef for constant memory areas.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Bytes
typedef|typedef
specifier|const
name|FT_Byte
modifier|*
name|FT_Bytes
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Tag                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef for 32-bit tags (as used in the SFNT format).            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Tag
typedef|typedef
name|FT_UInt32
name|FT_Tag
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_String                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple typedef for the char type, usually used for strings.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_String
typedef|typedef
name|char
name|FT_String
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Short                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef for signed short.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Short
typedef|typedef
name|signed
name|short
name|FT_Short
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_UShort                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef for unsigned short.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_UShort
typedef|typedef
name|unsigned
name|short
name|FT_UShort
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Int                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef for the int type.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Int
typedef|typedef
name|signed
name|int
name|FT_Int
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_UInt                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef for the unsigned int type.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_UInt
typedef|typedef
name|unsigned
name|int
name|FT_UInt
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Long                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef for signed long.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Long
typedef|typedef
name|signed
name|long
name|FT_Long
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_ULong                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A typedef for unsigned long.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_ULong
typedef|typedef
name|unsigned
name|long
name|FT_ULong
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_F2Dot14                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A signed 2.14 fixed float type used for unit vectors.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_F2Dot14
typedef|typedef
name|signed
name|short
name|FT_F2Dot14
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_F26Dot6                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A signed 26.6 fixed float type used for vectorial pixel            */
end_comment
begin_comment
comment|/*    coordinates.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_F26Dot6
typedef|typedef
name|signed
name|long
name|FT_F26Dot6
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Fixed                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This type is used to store 16.16 fixed float values, like scaling  */
end_comment
begin_comment
comment|/*    values or matrix coefficients.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Fixed
typedef|typedef
name|signed
name|long
name|FT_Fixed
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Error                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The FreeType error code type.  A value of~0 is always interpreted  */
end_comment
begin_comment
comment|/*    as a successful operation.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Error
typedef|typedef
name|int
name|FT_Error
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Pointer                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple typedef for a typeless pointer.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Pointer
typedef|typedef
name|void
modifier|*
name|FT_Pointer
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Offset                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This is equivalent to the ANSI~C `size_t' type, i.e., the largest  */
end_comment
begin_comment
comment|/*    _unsigned_ integer type used to express a file size or position,   */
end_comment
begin_comment
comment|/*    or a memory block size.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Offset
typedef|typedef
name|size_t
name|FT_Offset
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_PtrDist                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This is equivalent to the ANSI~C `ptrdiff_t' type, i.e., the       */
end_comment
begin_comment
comment|/*    largest _signed_ integer type used to express the distance         */
end_comment
begin_comment
comment|/*    between two pointers.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_PtrDist
typedef|typedef
name|ft_ptrdiff_t
name|FT_PtrDist
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_UnitVector                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple structure used to store a 2D vector unit vector.  Uses    */
end_comment
begin_comment
comment|/*    FT_F2Dot14 types.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    x :: Horizontal coordinate.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y :: Vertical coordinate.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_UnitVector_
typedef|typedef
struct|struct
name|FT_UnitVector_
block|{
DECL|member|x
name|FT_F2Dot14
name|x
decl_stmt|;
DECL|member|y
name|FT_F2Dot14
name|y
decl_stmt|;
block|}
DECL|typedef|FT_UnitVector
name|FT_UnitVector
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_Matrix                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple structure used to store a 2x2 matrix.  Coefficients are   */
end_comment
begin_comment
comment|/*    in 16.16 fixed float format.  The computation performed is:        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*       {                                                               */
end_comment
begin_comment
comment|/*          x' = x*xx + y*xy                                             */
end_comment
begin_comment
comment|/*          y' = x*yx + y*yy                                             */
end_comment
begin_comment
comment|/*       }                                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    xx :: Matrix coefficient.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    xy :: Matrix coefficient.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    yx :: Matrix coefficient.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    yy :: Matrix coefficient.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Matrix_
typedef|typedef
struct|struct
name|FT_Matrix_
block|{
DECL|member|xx
DECL|member|xy
name|FT_Fixed
name|xx
decl_stmt|,
name|xy
decl_stmt|;
DECL|member|yx
DECL|member|yy
name|FT_Fixed
name|yx
decl_stmt|,
name|yy
decl_stmt|;
block|}
DECL|typedef|FT_Matrix
name|FT_Matrix
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_Data                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Read-only binary data represented as a pointer and a length.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    pointer :: The data.                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    length  :: The length of the data in bytes.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Data_
typedef|typedef
struct|struct
name|FT_Data_
block|{
DECL|member|pointer
specifier|const
name|FT_Byte
modifier|*
name|pointer
decl_stmt|;
DECL|member|length
name|FT_Int
name|length
decl_stmt|;
block|}
DECL|typedef|FT_Data
name|FT_Data
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    FT_Generic_Finalizer                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Describe a function used to destroy the `client' data of any       */
end_comment
begin_comment
comment|/*    FreeType object.  See the description of the @FT_Generic type for  */
end_comment
begin_comment
comment|/*    details of usage.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    The address of the FreeType object which is under finalization.    */
end_comment
begin_comment
comment|/*    Its client data is accessed through its `generic' field.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Generic_Finalizer
typedef|typedef
name|void
function_decl|(
modifier|*
name|FT_Generic_Finalizer
function_decl|)
parameter_list|(
name|void
modifier|*
name|object
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_Generic                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Client applications often need to associate their own data to a    */
end_comment
begin_comment
comment|/*    variety of FreeType core objects.  For example, a text layout API  */
end_comment
begin_comment
comment|/*    might want to associate a glyph cache to a given size object.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Most FreeType object contains a `generic' field, of type           */
end_comment
begin_comment
comment|/*    FT_Generic, which usage is left to client applications and font    */
end_comment
begin_comment
comment|/*    servers.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    It can be used to store a pointer to client-specific data, as well */
end_comment
begin_comment
comment|/*    as the address of a `finalizer' function, which will be called by  */
end_comment
begin_comment
comment|/*    FreeType when the object is destroyed (for example, the previous   */
end_comment
begin_comment
comment|/*    client example would put the address of the glyph cache destructor */
end_comment
begin_comment
comment|/*    in the `finalizer' field).                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    data      :: A typeless pointer to any client-specified data. This */
end_comment
begin_comment
comment|/*                 field is completely ignored by the FreeType library.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    finalizer :: A pointer to a `generic finalizer' function, which    */
end_comment
begin_comment
comment|/*                 will be called when the object is destroyed.  If this */
end_comment
begin_comment
comment|/*                 field is set to NULL, no code will be called.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Generic_
typedef|typedef
struct|struct
name|FT_Generic_
block|{
DECL|member|data
name|void
modifier|*
name|data
decl_stmt|;
DECL|member|finalizer
name|FT_Generic_Finalizer
name|finalizer
decl_stmt|;
block|}
DECL|typedef|FT_Generic
name|FT_Generic
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_MAKE_TAG                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This macro converts four-letter tags which are used to label       */
end_comment
begin_comment
comment|/*    TrueType tables into an unsigned long to be used within FreeType.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The produced values *must* be 32-bit integers.  Don't redefine     */
end_comment
begin_comment
comment|/*    this macro.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_MAKE_TAG
define|#
directive|define
name|FT_MAKE_TAG
parameter_list|(
name|_x1
parameter_list|,
name|_x2
parameter_list|,
name|_x3
parameter_list|,
name|_x4
parameter_list|)
define|\
value|(FT_Tag)                        \           ( ( (FT_ULong)_x1<< 24 ) |     \             ( (FT_ULong)_x2<< 16 ) |     \             ( (FT_ULong)_x3<<  8 ) |     \               (FT_ULong)_x4         )
end_define
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
comment|/*                    L I S T   M A N A G E M E N T                      */
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
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    list_processing                                                    */
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
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_ListNode                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*     Many elements and objects in FreeType are listed through an       */
end_comment
begin_comment
comment|/*     @FT_List record (see @FT_ListRec).  As its name suggests, an      */
end_comment
begin_comment
comment|/*     FT_ListNode is a handle to a single list element.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_ListNode
typedef|typedef
name|struct
name|FT_ListNodeRec_
modifier|*
name|FT_ListNode
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_List                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a list record (see @FT_ListRec).                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_List
typedef|typedef
name|struct
name|FT_ListRec_
modifier|*
name|FT_List
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_ListNodeRec                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to hold a single list element.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    prev :: The previous element in the list.  NULL if first.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    next :: The next element in the list.  NULL if last.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    data :: A typeless pointer to the listed object.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_ListNodeRec_
typedef|typedef
struct|struct
name|FT_ListNodeRec_
block|{
DECL|member|prev
name|FT_ListNode
name|prev
decl_stmt|;
DECL|member|next
name|FT_ListNode
name|next
decl_stmt|;
DECL|member|data
name|void
modifier|*
name|data
decl_stmt|;
block|}
DECL|typedef|FT_ListNodeRec
name|FT_ListNodeRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_ListRec                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to hold a simple doubly-linked list.  These are   */
end_comment
begin_comment
comment|/*    used in many parts of FreeType.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    head :: The head (first element) of doubly-linked list.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    tail :: The tail (last element) of doubly-linked list.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_ListRec_
typedef|typedef
struct|struct
name|FT_ListRec_
block|{
DECL|member|head
name|FT_ListNode
name|head
decl_stmt|;
DECL|member|tail
name|FT_ListNode
name|tail
decl_stmt|;
block|}
DECL|typedef|FT_ListRec
name|FT_ListRec
typedef|;
end_typedef
begin_comment
comment|/* */
end_comment
begin_define
DECL|macro|FT_IS_EMPTY
define|#
directive|define
name|FT_IS_EMPTY
parameter_list|(
name|list
parameter_list|)
value|( (list).head == 0 )
end_define
begin_comment
comment|/* return base error code (without module-specific prefix) */
end_comment
begin_define
DECL|macro|FT_ERROR_BASE
define|#
directive|define
name|FT_ERROR_BASE
parameter_list|(
name|x
parameter_list|)
value|( (x)& 0xFF )
end_define
begin_comment
comment|/* return module error code */
end_comment
begin_define
DECL|macro|FT_ERROR_MODULE
define|#
directive|define
name|FT_ERROR_MODULE
parameter_list|(
name|x
parameter_list|)
value|( (x)& 0xFF00U )
end_define
begin_define
DECL|macro|FT_BOOL
define|#
directive|define
name|FT_BOOL
parameter_list|(
name|x
parameter_list|)
value|( (FT_Bool)( x ) )
end_define
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTTYPES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
