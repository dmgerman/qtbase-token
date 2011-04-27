begin_unit
begin_comment
comment|/* inftrees.h -- header to use inftrees.c  * Copyright (C) 1995-2002 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment
begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment
begin_comment
comment|/* Huffman code lookup table entry--this entry is four bytes for machines    that have 16-bit pointers (e.g. PC's in the small or medium model). */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_INFTREES_H
end_ifndef
begin_define
DECL|macro|_INFTREES_H
define|#
directive|define
name|_INFTREES_H
end_define
begin_typedef
DECL|typedef|inflate_huft
typedef|typedef
name|struct
name|inflate_huft_s
name|FAR
name|inflate_huft
typedef|;
end_typedef
begin_struct
DECL|struct|inflate_huft_s
struct|struct
name|inflate_huft_s
block|{
union|union
block|{
struct|struct
block|{
DECL|member|Exop
name|Byte
name|Exop
decl_stmt|;
comment|/* number of extra bits or operation */
DECL|member|Bits
name|Byte
name|Bits
decl_stmt|;
comment|/* number of bits in this code or subcode */
block|}
DECL|member|what
name|what
struct|;
DECL|member|pad
name|uInt
name|pad
decl_stmt|;
comment|/* pad structure to a power of 2 (4 bytes for */
block|}
DECL|member|word
name|word
union|;
comment|/*  16-bit, 8 bytes for 32-bit int's) */
DECL|member|base
name|uInt
name|base
decl_stmt|;
comment|/* literal, length base, distance base,                            or table offset */
block|}
struct|;
end_struct
begin_comment
comment|/* Maximum size of dynamic tree.  The maximum found in a long but non-    exhaustive search was 1004 huft structures (850 for length/literals    and 154 for distances, the latter actually the result of an    exhaustive search).  The actual maximum is not known, but the    value below is more than safe. */
end_comment
begin_define
DECL|macro|MANY
define|#
directive|define
name|MANY
value|1440
end_define
begin_decl_stmt
name|local
name|int
name|inflate_trees_bits
name|OF
argument_list|(
operator|(
name|uIntf
operator|*
operator|,
comment|/* 19 code lengths */
name|uIntf
operator|*
operator|,
comment|/* bits tree desired/actual depth */
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* bits tree result */
name|inflate_huft
operator|*
operator|,
comment|/* space for trees */
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* for messages */
end_comment
begin_decl_stmt
name|local
name|int
name|inflate_trees_dynamic
name|OF
argument_list|(
operator|(
name|uInt
operator|,
comment|/* number of literal/length codes */
name|uInt
operator|,
comment|/* number of distance codes */
name|uIntf
operator|*
operator|,
comment|/* that many (total) code lengths */
name|uIntf
operator|*
operator|,
comment|/* literal desired/actual bit depth */
name|uIntf
operator|*
operator|,
comment|/* distance desired/actual bit depth */
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* literal/length tree result */
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* distance tree result */
name|inflate_huft
operator|*
operator|,
comment|/* space for trees */
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* for messages */
end_comment
begin_decl_stmt
name|local
name|int
name|inflate_trees_fixed
name|OF
argument_list|(
operator|(
name|uIntf
operator|*
operator|,
comment|/* literal desired/actual bit depth */
name|uIntf
operator|*
operator|,
comment|/* distance desired/actual bit depth */
specifier|const
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* literal/length tree result */
specifier|const
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* distance tree result */
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* for memory allocation */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _INFTREES_H */
end_comment
end_unit
