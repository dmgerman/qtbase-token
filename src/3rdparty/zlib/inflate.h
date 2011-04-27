begin_unit
begin_comment
comment|/* inflate.h -- internal inflate state definition  * Copyright (C) 1995-2009 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment
begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment
begin_comment
comment|/* define NO_GZIP when compiling if you want to disable gzip header and    trailer decoding by inflate().  NO_GZIP would be used to avoid linking in    the crc code when it is not needed.  For shared libraries, gzip decoding    should be left enabled. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NO_GZIP
end_ifndef
begin_define
DECL|macro|GUNZIP
define|#
directive|define
name|GUNZIP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Possible inflate modes between inflate() calls */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HEAD
name|HEAD
block|,
comment|/* i: waiting for magic header */
DECL|enumerator|FLAGS
name|FLAGS
block|,
comment|/* i: waiting for method and flags (gzip) */
DECL|enumerator|TIME
name|TIME
block|,
comment|/* i: waiting for modification time (gzip) */
DECL|enumerator|OS
name|OS
block|,
comment|/* i: waiting for extra flags and operating system (gzip) */
DECL|enumerator|EXLEN
name|EXLEN
block|,
comment|/* i: waiting for extra length (gzip) */
DECL|enumerator|EXTRA
name|EXTRA
block|,
comment|/* i: waiting for extra bytes (gzip) */
DECL|enumerator|NAME
name|NAME
block|,
comment|/* i: waiting for end of file name (gzip) */
DECL|enumerator|COMMENT
name|COMMENT
block|,
comment|/* i: waiting for end of comment (gzip) */
DECL|enumerator|HCRC
name|HCRC
block|,
comment|/* i: waiting for header crc (gzip) */
DECL|enumerator|DICTID
name|DICTID
block|,
comment|/* i: waiting for dictionary check value */
DECL|enumerator|DICT
name|DICT
block|,
comment|/* waiting for inflateSetDictionary() call */
DECL|enumerator|TYPE
name|TYPE
block|,
comment|/* i: waiting for type bits, including last-flag bit */
DECL|enumerator|TYPEDO
name|TYPEDO
block|,
comment|/* i: same, but skip check to exit inflate on new block */
DECL|enumerator|STORED
name|STORED
block|,
comment|/* i: waiting for stored size (length and complement) */
DECL|enumerator|COPY_
name|COPY_
block|,
comment|/* i/o: same as COPY below, but only first time in */
DECL|enumerator|COPY
name|COPY
block|,
comment|/* i/o: waiting for input or output to copy stored block */
DECL|enumerator|TABLE
name|TABLE
block|,
comment|/* i: waiting for dynamic block table lengths */
DECL|enumerator|LENLENS
name|LENLENS
block|,
comment|/* i: waiting for code length code lengths */
DECL|enumerator|CODELENS
name|CODELENS
block|,
comment|/* i: waiting for length/lit and distance code lengths */
DECL|enumerator|LEN_
name|LEN_
block|,
comment|/* i: same as LEN below, but only first time in */
DECL|enumerator|LEN
name|LEN
block|,
comment|/* i: waiting for length/lit/eob code */
DECL|enumerator|LENEXT
name|LENEXT
block|,
comment|/* i: waiting for length extra bits */
DECL|enumerator|DIST
name|DIST
block|,
comment|/* i: waiting for distance code */
DECL|enumerator|DISTEXT
name|DISTEXT
block|,
comment|/* i: waiting for distance extra bits */
DECL|enumerator|MATCH
name|MATCH
block|,
comment|/* o: waiting for output space to copy string */
DECL|enumerator|LIT
name|LIT
block|,
comment|/* o: waiting for output space to write literal */
DECL|enumerator|CHECK
name|CHECK
block|,
comment|/* i: waiting for 32-bit check value */
DECL|enumerator|LENGTH
name|LENGTH
block|,
comment|/* i: waiting for 32-bit length (gzip) */
DECL|enumerator|DONE
name|DONE
block|,
comment|/* finished check, done -- remain here until reset */
DECL|enumerator|BAD
name|BAD
block|,
comment|/* got a data error -- remain here until reset */
DECL|enumerator|MEM
name|MEM
block|,
comment|/* got an inflate() memory error -- remain here until reset */
DECL|enumerator|SYNC
name|SYNC
comment|/* looking for synchronization bytes to restart inflate() */
block|}
DECL|typedef|inflate_mode
name|inflate_mode
typedef|;
end_typedef
begin_comment
comment|/*     State transitions between above modes -      (most modes can go to BAD or MEM on error -- not shown for clarity)      Process header:         HEAD -> (gzip) or (zlib) or (raw)         (gzip) -> FLAGS -> TIME -> OS -> EXLEN -> EXTRA -> NAME -> COMMENT ->                   HCRC -> TYPE         (zlib) -> DICTID or TYPE         DICTID -> DICT -> TYPE         (raw) -> TYPEDO     Read deflate blocks:             TYPE -> TYPEDO -> STORED or TABLE or LEN_ or CHECK             STORED -> COPY_ -> COPY -> TYPE             TABLE -> LENLENS -> CODELENS -> LEN_             LEN_ -> LEN     Read deflate codes in fixed or dynamic block:                 LEN -> LENEXT or LIT or TYPE                 LENEXT -> DIST -> DISTEXT -> MATCH -> LEN                 LIT -> LEN     Process trailer:         CHECK -> LENGTH -> DONE  */
end_comment
begin_comment
comment|/* state maintained between inflate() calls.  Approximately 10K bytes. */
end_comment
begin_struct
DECL|struct|inflate_state
struct|struct
name|inflate_state
block|{
DECL|member|mode
name|inflate_mode
name|mode
decl_stmt|;
comment|/* current inflate mode */
DECL|member|last
name|int
name|last
decl_stmt|;
comment|/* true if processing last block */
DECL|member|wrap
name|int
name|wrap
decl_stmt|;
comment|/* bit 0 true for zlib, bit 1 true for gzip */
DECL|member|havedict
name|int
name|havedict
decl_stmt|;
comment|/* true if dictionary provided */
DECL|member|flags
name|int
name|flags
decl_stmt|;
comment|/* gzip header method and flags (0 if zlib) */
DECL|member|dmax
name|unsigned
name|dmax
decl_stmt|;
comment|/* zlib header max distance (INFLATE_STRICT) */
DECL|member|check
name|unsigned
name|long
name|check
decl_stmt|;
comment|/* protected copy of check value */
DECL|member|total
name|unsigned
name|long
name|total
decl_stmt|;
comment|/* protected copy of output count */
DECL|member|head
name|gz_headerp
name|head
decl_stmt|;
comment|/* where to save gzip header information */
comment|/* sliding window */
DECL|member|wbits
name|unsigned
name|wbits
decl_stmt|;
comment|/* log base 2 of requested window size */
DECL|member|wsize
name|unsigned
name|wsize
decl_stmt|;
comment|/* window size or zero if not using window */
DECL|member|whave
name|unsigned
name|whave
decl_stmt|;
comment|/* valid bytes in the window */
DECL|member|wnext
name|unsigned
name|wnext
decl_stmt|;
comment|/* window write index */
DECL|member|window
name|unsigned
name|char
name|FAR
modifier|*
name|window
decl_stmt|;
comment|/* allocated sliding window, if needed */
comment|/* bit accumulator */
DECL|member|hold
name|unsigned
name|long
name|hold
decl_stmt|;
comment|/* input bit accumulator */
DECL|member|bits
name|unsigned
name|bits
decl_stmt|;
comment|/* number of bits in "in" */
comment|/* for string and stored block copying */
DECL|member|length
name|unsigned
name|length
decl_stmt|;
comment|/* literal or length of data to copy */
DECL|member|offset
name|unsigned
name|offset
decl_stmt|;
comment|/* distance back to copy string from */
comment|/* for table and code decoding */
DECL|member|extra
name|unsigned
name|extra
decl_stmt|;
comment|/* extra bits needed */
comment|/* fixed and dynamic code tables */
DECL|member|lencode
name|code
specifier|const
name|FAR
modifier|*
name|lencode
decl_stmt|;
comment|/* starting table for length/literal codes */
DECL|member|distcode
name|code
specifier|const
name|FAR
modifier|*
name|distcode
decl_stmt|;
comment|/* starting table for distance codes */
DECL|member|lenbits
name|unsigned
name|lenbits
decl_stmt|;
comment|/* index bits for lencode */
DECL|member|distbits
name|unsigned
name|distbits
decl_stmt|;
comment|/* index bits for distcode */
comment|/* dynamic table building */
DECL|member|ncode
name|unsigned
name|ncode
decl_stmt|;
comment|/* number of code length code lengths */
DECL|member|nlen
name|unsigned
name|nlen
decl_stmt|;
comment|/* number of length code lengths */
DECL|member|ndist
name|unsigned
name|ndist
decl_stmt|;
comment|/* number of distance code lengths */
DECL|member|have
name|unsigned
name|have
decl_stmt|;
comment|/* number of code lengths in lens[] */
DECL|member|next
name|code
name|FAR
modifier|*
name|next
decl_stmt|;
comment|/* next available space in codes[] */
DECL|member|lens
name|unsigned
name|short
name|lens
index|[
literal|320
index|]
decl_stmt|;
comment|/* temporary storage for code lengths */
DECL|member|work
name|unsigned
name|short
name|work
index|[
literal|288
index|]
decl_stmt|;
comment|/* work area for code table building */
DECL|member|codes
name|code
name|codes
index|[
name|ENOUGH
index|]
decl_stmt|;
comment|/* space for code tables */
DECL|member|sane
name|int
name|sane
decl_stmt|;
comment|/* if false, allow invalid distance too far */
DECL|member|back
name|int
name|back
decl_stmt|;
comment|/* bits back of last unprocessed length/lit */
DECL|member|was
name|unsigned
name|was
decl_stmt|;
comment|/* initial length of match */
block|}
struct|;
end_struct
end_unit
