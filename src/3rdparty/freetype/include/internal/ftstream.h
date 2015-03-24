begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftstream.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Stream handling (specification).                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2002, 2004-2006, 2011, 2013 by                          */
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
name|__FTSTREAM_H__
end_ifndef
begin_define
DECL|macro|__FTSTREAM_H__
define|#
directive|define
name|__FTSTREAM_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_SYSTEM_H
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
comment|/* format of an 8-bit frame_op value:           */
end_comment
begin_comment
comment|/*                                              */
end_comment
begin_comment
comment|/* bit  76543210                                */
end_comment
begin_comment
comment|/*      xxxxxxes                                */
end_comment
begin_comment
comment|/*                                              */
end_comment
begin_comment
comment|/* s is set to 1 if the value is signed.        */
end_comment
begin_comment
comment|/* e is set to 1 if the value is little-endian. */
end_comment
begin_comment
comment|/* xxx is a command.                            */
end_comment
begin_define
DECL|macro|FT_FRAME_OP_SHIFT
define|#
directive|define
name|FT_FRAME_OP_SHIFT
value|2
end_define
begin_define
DECL|macro|FT_FRAME_OP_SIGNED
define|#
directive|define
name|FT_FRAME_OP_SIGNED
value|1
end_define
begin_define
DECL|macro|FT_FRAME_OP_LITTLE
define|#
directive|define
name|FT_FRAME_OP_LITTLE
value|2
end_define
begin_define
DECL|macro|FT_FRAME_OP_COMMAND
define|#
directive|define
name|FT_FRAME_OP_COMMAND
parameter_list|(
name|x
parameter_list|)
value|( x>> FT_FRAME_OP_SHIFT )
end_define
begin_define
DECL|macro|FT_MAKE_FRAME_OP
define|#
directive|define
name|FT_MAKE_FRAME_OP
parameter_list|(
name|command
parameter_list|,
name|little
parameter_list|,
name|sign
parameter_list|)
define|\
value|( ( command<< FT_FRAME_OP_SHIFT ) | ( little<< 1 ) | sign )
end_define
begin_define
DECL|macro|FT_FRAME_OP_END
define|#
directive|define
name|FT_FRAME_OP_END
value|0
end_define
begin_define
DECL|macro|FT_FRAME_OP_START
define|#
directive|define
name|FT_FRAME_OP_START
value|1
end_define
begin_comment
DECL|macro|FT_FRAME_OP_START
comment|/* start a new frame     */
end_comment
begin_define
DECL|macro|FT_FRAME_OP_BYTE
define|#
directive|define
name|FT_FRAME_OP_BYTE
value|2
end_define
begin_comment
DECL|macro|FT_FRAME_OP_BYTE
comment|/* read 1-byte value     */
end_comment
begin_define
DECL|macro|FT_FRAME_OP_SHORT
define|#
directive|define
name|FT_FRAME_OP_SHORT
value|3
end_define
begin_comment
DECL|macro|FT_FRAME_OP_SHORT
comment|/* read 2-byte value     */
end_comment
begin_define
DECL|macro|FT_FRAME_OP_LONG
define|#
directive|define
name|FT_FRAME_OP_LONG
value|4
end_define
begin_comment
DECL|macro|FT_FRAME_OP_LONG
comment|/* read 4-byte value     */
end_comment
begin_define
DECL|macro|FT_FRAME_OP_OFF3
define|#
directive|define
name|FT_FRAME_OP_OFF3
value|5
end_define
begin_comment
DECL|macro|FT_FRAME_OP_OFF3
comment|/* read 3-byte value     */
end_comment
begin_define
DECL|macro|FT_FRAME_OP_BYTES
define|#
directive|define
name|FT_FRAME_OP_BYTES
value|6
end_define
begin_comment
DECL|macro|FT_FRAME_OP_BYTES
comment|/* read a bytes sequence */
end_comment
begin_typedef
DECL|enum|FT_Frame_Op_
typedef|typedef
enum|enum
name|FT_Frame_Op_
block|{
DECL|enumerator|ft_frame_end
name|ft_frame_end
init|=
literal|0
block|,
DECL|enumerator|ft_frame_start
name|ft_frame_start
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_START
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_byte
name|ft_frame_byte
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_BYTE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_schar
name|ft_frame_schar
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_BYTE
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|,
DECL|enumerator|ft_frame_ushort_be
name|ft_frame_ushort_be
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_SHORT
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_short_be
name|ft_frame_short_be
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_SHORT
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|,
DECL|enumerator|ft_frame_ushort_le
name|ft_frame_ushort_le
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_SHORT
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_short_le
name|ft_frame_short_le
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_SHORT
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
DECL|enumerator|ft_frame_ulong_be
name|ft_frame_ulong_be
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_LONG
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_long_be
name|ft_frame_long_be
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_LONG
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|,
DECL|enumerator|ft_frame_ulong_le
name|ft_frame_ulong_le
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_LONG
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_long_le
name|ft_frame_long_le
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_LONG
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
DECL|enumerator|ft_frame_uoff3_be
name|ft_frame_uoff3_be
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_OFF3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_off3_be
name|ft_frame_off3_be
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_OFF3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|,
DECL|enumerator|ft_frame_uoff3_le
name|ft_frame_uoff3_le
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_OFF3
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_off3_le
name|ft_frame_off3_le
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_OFF3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
DECL|enumerator|ft_frame_bytes
name|ft_frame_bytes
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
name|FT_FRAME_OP_BYTES
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|ft_frame_skip
name|ft_frame_skip
init|=
name|FT_MAKE_FRAME_OP
argument_list|(
argument|FT_FRAME_OP_BYTES
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|}
DECL|typedef|FT_Frame_Op
name|FT_Frame_Op
typedef|;
end_typedef
begin_typedef
DECL|struct|FT_Frame_Field_
typedef|typedef
struct|struct
name|FT_Frame_Field_
block|{
DECL|member|value
name|FT_Byte
name|value
decl_stmt|;
DECL|member|size
name|FT_Byte
name|size
decl_stmt|;
DECL|member|offset
name|FT_UShort
name|offset
decl_stmt|;
block|}
DECL|typedef|FT_Frame_Field
name|FT_Frame_Field
typedef|;
end_typedef
begin_comment
comment|/* Construct an FT_Frame_Field out of a structure type and a field name. */
end_comment
begin_comment
comment|/* The structure type must be set in the FT_STRUCTURE macro before       */
end_comment
begin_comment
comment|/* calling the FT_FRAME_START() macro.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_FIELD_SIZE
define|#
directive|define
name|FT_FIELD_SIZE
parameter_list|(
name|f
parameter_list|)
define|\
value|(FT_Byte)sizeof ( ((FT_STRUCTURE*)0)->f )
end_define
begin_define
DECL|macro|FT_FIELD_SIZE_DELTA
define|#
directive|define
name|FT_FIELD_SIZE_DELTA
parameter_list|(
name|f
parameter_list|)
define|\
value|(FT_Byte)sizeof ( ((FT_STRUCTURE*)0)->f[0] )
end_define
begin_define
DECL|macro|FT_FIELD_OFFSET
define|#
directive|define
name|FT_FIELD_OFFSET
parameter_list|(
name|f
parameter_list|)
define|\
value|(FT_UShort)( offsetof( FT_STRUCTURE, f ) )
end_define
begin_define
DECL|macro|FT_FRAME_FIELD
define|#
directive|define
name|FT_FRAME_FIELD
parameter_list|(
name|frame_op
parameter_list|,
name|field
parameter_list|)
define|\
value|{                               \             frame_op,                     \             FT_FIELD_SIZE( field ),       \             FT_FIELD_OFFSET( field )      \           }
end_define
begin_define
DECL|macro|FT_MAKE_EMPTY_FIELD
define|#
directive|define
name|FT_MAKE_EMPTY_FIELD
parameter_list|(
name|frame_op
parameter_list|)
value|{ frame_op, 0, 0 }
end_define
begin_define
DECL|macro|FT_FRAME_START
define|#
directive|define
name|FT_FRAME_START
parameter_list|(
name|size
parameter_list|)
value|{ ft_frame_start, 0, size }
end_define
begin_define
DECL|macro|FT_FRAME_END
define|#
directive|define
name|FT_FRAME_END
value|{ ft_frame_end, 0, 0 }
end_define
begin_define
DECL|macro|FT_FRAME_LONG
define|#
directive|define
name|FT_FRAME_LONG
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_long_be, f )
end_define
begin_define
DECL|macro|FT_FRAME_ULONG
define|#
directive|define
name|FT_FRAME_ULONG
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_ulong_be, f )
end_define
begin_define
DECL|macro|FT_FRAME_SHORT
define|#
directive|define
name|FT_FRAME_SHORT
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_short_be, f )
end_define
begin_define
DECL|macro|FT_FRAME_USHORT
define|#
directive|define
name|FT_FRAME_USHORT
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_ushort_be, f )
end_define
begin_define
DECL|macro|FT_FRAME_OFF3
define|#
directive|define
name|FT_FRAME_OFF3
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_off3_be, f )
end_define
begin_define
DECL|macro|FT_FRAME_UOFF3
define|#
directive|define
name|FT_FRAME_UOFF3
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_uoff3_be, f )
end_define
begin_define
DECL|macro|FT_FRAME_BYTE
define|#
directive|define
name|FT_FRAME_BYTE
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_byte, f )
end_define
begin_define
DECL|macro|FT_FRAME_CHAR
define|#
directive|define
name|FT_FRAME_CHAR
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_schar, f )
end_define
begin_define
DECL|macro|FT_FRAME_LONG_LE
define|#
directive|define
name|FT_FRAME_LONG_LE
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_long_le, f )
end_define
begin_define
DECL|macro|FT_FRAME_ULONG_LE
define|#
directive|define
name|FT_FRAME_ULONG_LE
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_ulong_le, f )
end_define
begin_define
DECL|macro|FT_FRAME_SHORT_LE
define|#
directive|define
name|FT_FRAME_SHORT_LE
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_short_le, f )
end_define
begin_define
DECL|macro|FT_FRAME_USHORT_LE
define|#
directive|define
name|FT_FRAME_USHORT_LE
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_ushort_le, f )
end_define
begin_define
DECL|macro|FT_FRAME_OFF3_LE
define|#
directive|define
name|FT_FRAME_OFF3_LE
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_off3_le, f )
end_define
begin_define
DECL|macro|FT_FRAME_UOFF3_LE
define|#
directive|define
name|FT_FRAME_UOFF3_LE
parameter_list|(
name|f
parameter_list|)
value|FT_FRAME_FIELD( ft_frame_uoff3_le, f )
end_define
begin_define
DECL|macro|FT_FRAME_SKIP_LONG
define|#
directive|define
name|FT_FRAME_SKIP_LONG
value|{ ft_frame_long_be, 0, 0 }
end_define
begin_define
DECL|macro|FT_FRAME_SKIP_SHORT
define|#
directive|define
name|FT_FRAME_SKIP_SHORT
value|{ ft_frame_short_be, 0, 0 }
end_define
begin_define
DECL|macro|FT_FRAME_SKIP_BYTE
define|#
directive|define
name|FT_FRAME_SKIP_BYTE
value|{ ft_frame_byte, 0, 0 }
end_define
begin_define
DECL|macro|FT_FRAME_BYTES
define|#
directive|define
name|FT_FRAME_BYTES
parameter_list|(
name|field
parameter_list|,
name|count
parameter_list|)
define|\
value|{                            \             ft_frame_bytes,            \             count,                     \             FT_FIELD_OFFSET( field )   \           }
end_define
begin_define
DECL|macro|FT_FRAME_SKIP_BYTES
define|#
directive|define
name|FT_FRAME_SKIP_BYTES
parameter_list|(
name|count
parameter_list|)
value|{ ft_frame_skip, count, 0 }
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Integer extraction macros -- the `buffer' parameter must ALWAYS be of */
end_comment
begin_comment
comment|/* type `char*' or equivalent (1-byte elements).                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_BYTE_
define|#
directive|define
name|FT_BYTE_
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|( ((const FT_Byte*)(p))[(i)] )
end_define
begin_define
DECL|macro|FT_INT16
define|#
directive|define
name|FT_INT16
parameter_list|(
name|x
parameter_list|)
value|( (FT_Int16)(x)  )
end_define
begin_define
DECL|macro|FT_UINT16
define|#
directive|define
name|FT_UINT16
parameter_list|(
name|x
parameter_list|)
value|( (FT_UInt16)(x) )
end_define
begin_define
DECL|macro|FT_INT32
define|#
directive|define
name|FT_INT32
parameter_list|(
name|x
parameter_list|)
value|( (FT_Int32)(x)  )
end_define
begin_define
DECL|macro|FT_UINT32
define|#
directive|define
name|FT_UINT32
parameter_list|(
name|x
parameter_list|)
value|( (FT_UInt32)(x) )
end_define
begin_define
DECL|macro|FT_BYTE_U16
define|#
directive|define
name|FT_BYTE_U16
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|,
name|s
parameter_list|)
value|( FT_UINT16( FT_BYTE_( p, i ) )<< (s) )
end_define
begin_define
DECL|macro|FT_BYTE_U32
define|#
directive|define
name|FT_BYTE_U32
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|,
name|s
parameter_list|)
value|( FT_UINT32( FT_BYTE_( p, i ) )<< (s) )
end_define
begin_define
DECL|macro|FT_PEEK_SHORT
define|#
directive|define
name|FT_PEEK_SHORT
parameter_list|(
name|p
parameter_list|)
value|FT_INT16( FT_BYTE_U16( p, 0, 8) | \                                       FT_BYTE_U16( p, 1, 0) )
end_define
begin_define
DECL|macro|FT_PEEK_USHORT
define|#
directive|define
name|FT_PEEK_USHORT
parameter_list|(
name|p
parameter_list|)
value|FT_UINT16( FT_BYTE_U16( p, 0, 8 ) | \                                         FT_BYTE_U16( p, 1, 0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_LONG
define|#
directive|define
name|FT_PEEK_LONG
parameter_list|(
name|p
parameter_list|)
value|FT_INT32( FT_BYTE_U32( p, 0, 24 ) | \                                      FT_BYTE_U32( p, 1, 16 ) | \                                      FT_BYTE_U32( p, 2,  8 ) | \                                      FT_BYTE_U32( p, 3,  0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_ULONG
define|#
directive|define
name|FT_PEEK_ULONG
parameter_list|(
name|p
parameter_list|)
value|FT_UINT32( FT_BYTE_U32( p, 0, 24 ) | \                                        FT_BYTE_U32( p, 1, 16 ) | \                                        FT_BYTE_U32( p, 2,  8 ) | \                                        FT_BYTE_U32( p, 3,  0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_OFF3
define|#
directive|define
name|FT_PEEK_OFF3
parameter_list|(
name|p
parameter_list|)
value|FT_INT32( FT_BYTE_U32( p, 0, 16 ) | \                                      FT_BYTE_U32( p, 1,  8 ) | \                                      FT_BYTE_U32( p, 2,  0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_UOFF3
define|#
directive|define
name|FT_PEEK_UOFF3
parameter_list|(
name|p
parameter_list|)
value|FT_UINT32( FT_BYTE_U32( p, 0, 16 ) | \                                        FT_BYTE_U32( p, 1,  8 ) | \                                        FT_BYTE_U32( p, 2,  0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_SHORT_LE
define|#
directive|define
name|FT_PEEK_SHORT_LE
parameter_list|(
name|p
parameter_list|)
value|FT_INT16( FT_BYTE_U16( p, 1, 8 ) | \                                          FT_BYTE_U16( p, 0, 0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_USHORT_LE
define|#
directive|define
name|FT_PEEK_USHORT_LE
parameter_list|(
name|p
parameter_list|)
value|FT_UINT16( FT_BYTE_U16( p, 1, 8 ) |  \                                            FT_BYTE_U16( p, 0, 0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_LONG_LE
define|#
directive|define
name|FT_PEEK_LONG_LE
parameter_list|(
name|p
parameter_list|)
value|FT_INT32( FT_BYTE_U32( p, 3, 24 ) | \                                         FT_BYTE_U32( p, 2, 16 ) | \                                         FT_BYTE_U32( p, 1,  8 ) | \                                         FT_BYTE_U32( p, 0,  0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_ULONG_LE
define|#
directive|define
name|FT_PEEK_ULONG_LE
parameter_list|(
name|p
parameter_list|)
value|FT_UINT32( FT_BYTE_U32( p, 3, 24 ) | \                                           FT_BYTE_U32( p, 2, 16 ) | \                                           FT_BYTE_U32( p, 1,  8 ) | \                                           FT_BYTE_U32( p, 0,  0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_OFF3_LE
define|#
directive|define
name|FT_PEEK_OFF3_LE
parameter_list|(
name|p
parameter_list|)
value|FT_INT32( FT_BYTE_U32( p, 2, 16 ) | \                                         FT_BYTE_U32( p, 1,  8 ) | \                                         FT_BYTE_U32( p, 0,  0 ) )
end_define
begin_define
DECL|macro|FT_PEEK_UOFF3_LE
define|#
directive|define
name|FT_PEEK_UOFF3_LE
parameter_list|(
name|p
parameter_list|)
value|FT_UINT32( FT_BYTE_U32( p, 2, 16 ) | \                                           FT_BYTE_U32( p, 1,  8 ) | \                                           FT_BYTE_U32( p, 0,  0 ) )
end_define
begin_define
DECL|macro|FT_NEXT_CHAR
define|#
directive|define
name|FT_NEXT_CHAR
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (signed char)*buffer++ )
end_define
begin_define
DECL|macro|FT_NEXT_BYTE
define|#
directive|define
name|FT_NEXT_BYTE
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (unsigned char)*buffer++ )
end_define
begin_define
DECL|macro|FT_NEXT_SHORT
define|#
directive|define
name|FT_NEXT_SHORT
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (short)( buffer += 2, FT_PEEK_SHORT( buffer - 2 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_USHORT
define|#
directive|define
name|FT_NEXT_USHORT
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (unsigned short)( buffer += 2, FT_PEEK_USHORT( buffer - 2 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_OFF3
define|#
directive|define
name|FT_NEXT_OFF3
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (long)( buffer += 3, FT_PEEK_OFF3( buffer - 3 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_UOFF3
define|#
directive|define
name|FT_NEXT_UOFF3
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (unsigned long)( buffer += 3, FT_PEEK_UOFF3( buffer - 3 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_LONG
define|#
directive|define
name|FT_NEXT_LONG
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (long)( buffer += 4, FT_PEEK_LONG( buffer - 4 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_ULONG
define|#
directive|define
name|FT_NEXT_ULONG
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (unsigned long)( buffer += 4, FT_PEEK_ULONG( buffer - 4 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_SHORT_LE
define|#
directive|define
name|FT_NEXT_SHORT_LE
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (short)( buffer += 2, FT_PEEK_SHORT_LE( buffer - 2 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_USHORT_LE
define|#
directive|define
name|FT_NEXT_USHORT_LE
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (unsigned short)( buffer += 2, FT_PEEK_USHORT_LE( buffer - 2 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_OFF3_LE
define|#
directive|define
name|FT_NEXT_OFF3_LE
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (long)( buffer += 3, FT_PEEK_OFF3_LE( buffer - 3 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_UOFF3_LE
define|#
directive|define
name|FT_NEXT_UOFF3_LE
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (unsigned long)( buffer += 3, FT_PEEK_UOFF3_LE( buffer - 3 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_LONG_LE
define|#
directive|define
name|FT_NEXT_LONG_LE
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (long)( buffer += 4, FT_PEEK_LONG_LE( buffer - 4 ) ) )
end_define
begin_define
DECL|macro|FT_NEXT_ULONG_LE
define|#
directive|define
name|FT_NEXT_ULONG_LE
parameter_list|(
name|buffer
parameter_list|)
define|\
value|( (unsigned long)( buffer += 4, FT_PEEK_ULONG_LE( buffer - 4 ) ) )
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Each GET_xxxx() macro uses an implicit `stream' variable.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_define
define|#
directive|define
name|FT_GET_MACRO
parameter_list|(
name|type
parameter_list|)
value|FT_NEXT_ ## type ( stream->cursor )
end_define
begin_define
define|#
directive|define
name|FT_GET_CHAR
parameter_list|()
value|FT_GET_MACRO( CHAR )
end_define
begin_define
define|#
directive|define
name|FT_GET_BYTE
parameter_list|()
value|FT_GET_MACRO( BYTE )
end_define
begin_define
define|#
directive|define
name|FT_GET_SHORT
parameter_list|()
value|FT_GET_MACRO( SHORT )
end_define
begin_define
define|#
directive|define
name|FT_GET_USHORT
parameter_list|()
value|FT_GET_MACRO( USHORT )
end_define
begin_define
define|#
directive|define
name|FT_GET_OFF3
parameter_list|()
value|FT_GET_MACRO( OFF3 )
end_define
begin_define
define|#
directive|define
name|FT_GET_UOFF3
parameter_list|()
value|FT_GET_MACRO( UOFF3 )
end_define
begin_define
define|#
directive|define
name|FT_GET_LONG
parameter_list|()
value|FT_GET_MACRO( LONG )
end_define
begin_define
define|#
directive|define
name|FT_GET_ULONG
parameter_list|()
value|FT_GET_MACRO( ULONG )
end_define
begin_define
define|#
directive|define
name|FT_GET_TAG4
parameter_list|()
value|FT_GET_MACRO( ULONG )
end_define
begin_define
define|#
directive|define
name|FT_GET_SHORT_LE
parameter_list|()
value|FT_GET_MACRO( SHORT_LE )
end_define
begin_define
define|#
directive|define
name|FT_GET_USHORT_LE
parameter_list|()
value|FT_GET_MACRO( USHORT_LE )
end_define
begin_define
define|#
directive|define
name|FT_GET_LONG_LE
parameter_list|()
value|FT_GET_MACRO( LONG_LE )
end_define
begin_define
define|#
directive|define
name|FT_GET_ULONG_LE
parameter_list|()
value|FT_GET_MACRO( ULONG_LE )
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_GET_MACRO
define|#
directive|define
name|FT_GET_MACRO
parameter_list|(
name|func
parameter_list|,
name|type
parameter_list|)
value|( (type)func( stream ) )
end_define
begin_define
DECL|macro|FT_GET_CHAR
define|#
directive|define
name|FT_GET_CHAR
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetChar, FT_Char )
end_define
begin_define
DECL|macro|FT_GET_BYTE
define|#
directive|define
name|FT_GET_BYTE
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetChar, FT_Byte )
end_define
begin_define
DECL|macro|FT_GET_SHORT
define|#
directive|define
name|FT_GET_SHORT
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetUShort, FT_Short )
end_define
begin_define
DECL|macro|FT_GET_USHORT
define|#
directive|define
name|FT_GET_USHORT
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetUShort, FT_UShort )
end_define
begin_define
DECL|macro|FT_GET_OFF3
define|#
directive|define
name|FT_GET_OFF3
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetUOffset, FT_Long )
end_define
begin_define
DECL|macro|FT_GET_UOFF3
define|#
directive|define
name|FT_GET_UOFF3
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetUOffset, FT_ULong )
end_define
begin_define
DECL|macro|FT_GET_LONG
define|#
directive|define
name|FT_GET_LONG
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetULong, FT_Long )
end_define
begin_define
DECL|macro|FT_GET_ULONG
define|#
directive|define
name|FT_GET_ULONG
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetULong, FT_ULong )
end_define
begin_define
DECL|macro|FT_GET_TAG4
define|#
directive|define
name|FT_GET_TAG4
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetULong, FT_ULong )
end_define
begin_define
DECL|macro|FT_GET_SHORT_LE
define|#
directive|define
name|FT_GET_SHORT_LE
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetUShortLE, FT_Short )
end_define
begin_define
DECL|macro|FT_GET_USHORT_LE
define|#
directive|define
name|FT_GET_USHORT_LE
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetUShortLE, FT_UShort )
end_define
begin_define
DECL|macro|FT_GET_LONG_LE
define|#
directive|define
name|FT_GET_LONG_LE
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetULongLE, FT_Long )
end_define
begin_define
DECL|macro|FT_GET_ULONG_LE
define|#
directive|define
name|FT_GET_ULONG_LE
parameter_list|()
value|FT_GET_MACRO( FT_Stream_GetULongLE, FT_ULong )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|FT_READ_MACRO
define|#
directive|define
name|FT_READ_MACRO
parameter_list|(
name|func
parameter_list|,
name|type
parameter_list|,
name|var
parameter_list|)
define|\
value|( var = (type)func( stream,&error ), \             error != FT_Err_Ok )
end_define
begin_define
DECL|macro|FT_READ_BYTE
define|#
directive|define
name|FT_READ_BYTE
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadChar, FT_Byte, var )
end_define
begin_define
DECL|macro|FT_READ_CHAR
define|#
directive|define
name|FT_READ_CHAR
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadChar, FT_Char, var )
end_define
begin_define
DECL|macro|FT_READ_SHORT
define|#
directive|define
name|FT_READ_SHORT
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadUShort, FT_Short, var )
end_define
begin_define
DECL|macro|FT_READ_USHORT
define|#
directive|define
name|FT_READ_USHORT
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadUShort, FT_UShort, var )
end_define
begin_define
DECL|macro|FT_READ_OFF3
define|#
directive|define
name|FT_READ_OFF3
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadUOffset, FT_Long, var )
end_define
begin_define
DECL|macro|FT_READ_UOFF3
define|#
directive|define
name|FT_READ_UOFF3
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadUOffset, FT_ULong, var )
end_define
begin_define
DECL|macro|FT_READ_LONG
define|#
directive|define
name|FT_READ_LONG
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadULong, FT_Long, var )
end_define
begin_define
DECL|macro|FT_READ_ULONG
define|#
directive|define
name|FT_READ_ULONG
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadULong, FT_ULong, var )
end_define
begin_define
DECL|macro|FT_READ_SHORT_LE
define|#
directive|define
name|FT_READ_SHORT_LE
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadUShortLE, FT_Short, var )
end_define
begin_define
DECL|macro|FT_READ_USHORT_LE
define|#
directive|define
name|FT_READ_USHORT_LE
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadUShortLE, FT_UShort, var )
end_define
begin_define
DECL|macro|FT_READ_LONG_LE
define|#
directive|define
name|FT_READ_LONG_LE
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadULongLE, FT_Long, var )
end_define
begin_define
DECL|macro|FT_READ_ULONG_LE
define|#
directive|define
name|FT_READ_ULONG_LE
parameter_list|(
name|var
parameter_list|)
value|FT_READ_MACRO( FT_Stream_ReadULongLE, FT_ULong, var )
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_NO_DEFAULT_SYSTEM
end_ifndef
begin_comment
comment|/* initialize a stream for reading a regular system stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_Open
argument_list|(
argument|FT_Stream    stream
argument_list|,
argument|const char*  filepathname
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_NO_DEFAULT_SYSTEM */
end_comment
begin_comment
comment|/* create a new (input) stream from an FT_Open_Args structure */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_New
name|FT_Stream_New
argument_list|(
argument|FT_Library           library
argument_list|,
argument|const FT_Open_Args*  args
argument_list|,
argument|FT_Stream           *astream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* free a stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Stream_Free
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Int     external
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* initialize a stream for reading in-memory data */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Stream_OpenMemory
argument_list|(
argument|FT_Stream       stream
argument_list|,
argument|const FT_Byte*  base
argument_list|,
argument|FT_ULong        size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* close a stream (does not destroy the stream structure) */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|stream
name|FT_Stream_Close
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|stream
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* seek within a stream. position is relative to start of stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_Seek
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   pos
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* skip bytes in a stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_Skip
name|FT_Stream_Skip
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Long    distance
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* return current stream position */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Long
argument_list|)
end_macro
begin_macro
name|FT_Stream_Pos
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read bytes from a stream into a user-allocated buffer, returns an */
end_comment
begin_comment
comment|/* error if not all bytes could be read.                             */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_Read
name|FT_Stream_Read
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Byte*   buffer
argument_list|,
argument|FT_ULong   count
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read bytes from a stream at a given position */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_ReadAt
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   pos
argument_list|,
argument|FT_Byte*   buffer
argument_list|,
argument|FT_ULong   count
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* try to read bytes at the end of a stream; return number of bytes */
end_comment
begin_comment
comment|/* really available                                                 */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_TryRead
name|FT_Stream_TryRead
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Byte*   buffer
argument_list|,
argument|FT_ULong   count
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Enter a frame of `count' consecutive bytes in a stream.  Returns an */
end_comment
begin_comment
comment|/* error if the frame could not be read/accessed.  The caller can use  */
end_comment
begin_comment
comment|/* the FT_Stream_Get_XXX functions to retrieve frame data without      */
end_comment
begin_comment
comment|/* error checks.                                                       */
end_comment
begin_comment
comment|/*                                                                     */
end_comment
begin_comment
comment|/* You must _always_ call FT_Stream_ExitFrame() once you have entered  */
end_comment
begin_comment
comment|/* a stream frame!                                                     */
end_comment
begin_comment
comment|/*                                                                     */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_EnterFrame
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   count
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* exit a stream frame */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_ExitFrame
name|FT_Stream_ExitFrame
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Stream_ExitFrame
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Extract a stream frame.  If the stream is disk-based, a heap block */
end_comment
begin_comment
comment|/* is allocated and the frame bytes are read into it.  If the stream  */
end_comment
begin_comment
comment|/* is memory-based, this function simply set a pointer to the data.   */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/* Useful to optimize access to memory-based streams transparently.   */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/* All extracted frames must be `freed' with a call to the function   */
end_comment
begin_comment
comment|/* FT_Stream_ReleaseFrame().                                          */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_ExtractFrame
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   count
argument_list|,
argument|FT_Byte**  pbytes
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* release an extract frame (see FT_Stream_ExtractFrame) */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_ReleaseFrame
name|FT_Stream_ReleaseFrame
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Byte**  pbytes
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a byte from an entered frame */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Char
argument_list|)
end_macro
begin_macro
name|FT_Stream_GetChar
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 16-bit big-endian unsigned integer from an entered frame */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_UShort
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_GetUShort
name|FT_Stream_GetUShort
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Stream_GetUShort
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 24-bit big-endian unsigned integer from an entered frame */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
name|FT_Stream_GetUOffset
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 32-bit big-endian unsigned integer from an entered frame */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_GetULong
name|FT_Stream_GetULong
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Stream_GetULong
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 16-bit little-endian unsigned integer from an entered frame */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_UShort
argument_list|)
end_macro
begin_macro
name|FT_Stream_GetUShortLE
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 32-bit little-endian unsigned integer from an entered frame */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_GetULongLE
name|FT_Stream_GetULongLE
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Stream_GetULongLE
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a byte from a stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Char
argument_list|)
end_macro
begin_macro
name|FT_Stream_ReadChar
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Error*  error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 16-bit big-endian unsigned integer from a stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_UShort
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_ReadUShort
name|FT_Stream_ReadUShort
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Error*  error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 24-bit big-endian unsigned integer from a stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
name|FT_Stream_ReadUOffset
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Error*  error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 32-bit big-endian integer from a stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_ReadULong
name|FT_Stream_ReadULong
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Error*  error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 16-bit little-endian unsigned integer from a stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_UShort
argument_list|)
end_macro
begin_macro
name|FT_Stream_ReadUShortLE
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Error*  error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read a 32-bit little-endian unsigned integer from a stream */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stream_ReadULongLE
name|FT_Stream_ReadULongLE
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Error*  error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Read a structure from a stream.  The structure must be described */
end_comment
begin_comment
comment|/* by an array of FT_Frame_Field records.                           */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_ReadFields
argument_list|(
argument|FT_Stream              stream
argument_list|,
argument|const FT_Frame_Field*  fields
argument_list|,
argument|void*                  structure
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|FT_STREAM_POS
define|#
directive|define
name|FT_STREAM_POS
parameter_list|()
define|\
value|FT_Stream_Pos( stream )
end_define
begin_define
DECL|macro|FT_STREAM_SEEK
define|#
directive|define
name|FT_STREAM_SEEK
parameter_list|(
name|position
parameter_list|)
define|\
value|FT_SET_ERROR( FT_Stream_Seek( stream,                  \                                         (FT_ULong)(position) ) )
end_define
begin_define
DECL|macro|FT_STREAM_SKIP
define|#
directive|define
name|FT_STREAM_SKIP
parameter_list|(
name|distance
parameter_list|)
define|\
value|FT_SET_ERROR( FT_Stream_Skip( stream,                 \                                         (FT_Long)(distance) ) )
end_define
begin_define
DECL|macro|FT_STREAM_READ
define|#
directive|define
name|FT_STREAM_READ
parameter_list|(
name|buffer
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_SET_ERROR( FT_Stream_Read( stream,               \                                         (FT_Byte*)(buffer),   \                                         (FT_ULong)(count) ) )
end_define
begin_define
DECL|macro|FT_STREAM_READ_AT
define|#
directive|define
name|FT_STREAM_READ_AT
parameter_list|(
name|position
parameter_list|,
name|buffer
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_SET_ERROR( FT_Stream_ReadAt( stream,               \                                           (FT_ULong)(position), \                                           (FT_Byte*)buffer,     \                                           (FT_ULong)(count) ) )
end_define
begin_define
DECL|macro|FT_STREAM_READ_FIELDS
define|#
directive|define
name|FT_STREAM_READ_FIELDS
parameter_list|(
name|fields
parameter_list|,
name|object
parameter_list|)
define|\
value|FT_SET_ERROR( FT_Stream_ReadFields( stream, fields, object ) )
end_define
begin_define
DECL|macro|FT_FRAME_ENTER
define|#
directive|define
name|FT_FRAME_ENTER
parameter_list|(
name|size
parameter_list|)
define|\
value|FT_SET_ERROR(                                                  \             FT_DEBUG_INNER( FT_Stream_EnterFrame( stream,                \                                                   (FT_ULong)(size) ) ) )
end_define
begin_define
DECL|macro|FT_FRAME_EXIT
define|#
directive|define
name|FT_FRAME_EXIT
parameter_list|()
define|\
value|FT_DEBUG_INNER( FT_Stream_ExitFrame( stream ) )
end_define
begin_define
DECL|macro|FT_FRAME_EXTRACT
define|#
directive|define
name|FT_FRAME_EXTRACT
parameter_list|(
name|size
parameter_list|,
name|bytes
parameter_list|)
define|\
value|FT_SET_ERROR(                                                       \             FT_DEBUG_INNER( FT_Stream_ExtractFrame( stream,                   \                                                     (FT_ULong)(size),         \                                                     (FT_Byte**)&(bytes) ) ) )
end_define
begin_define
DECL|macro|FT_FRAME_RELEASE
define|#
directive|define
name|FT_FRAME_RELEASE
parameter_list|(
name|bytes
parameter_list|)
define|\
value|FT_DEBUG_INNER( FT_Stream_ReleaseFrame( stream,                 \                                                   (FT_Byte**)&(bytes) ) )
end_define
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTSTREAM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
