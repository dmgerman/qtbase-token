begin_unit
begin_comment
comment|/* deflate.h -- internal compression state  * Copyright (C) 1995-2010 Jean-loup Gailly  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment
begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment
begin_comment
comment|/* @(#) $Id$ */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DEFLATE_H
end_ifndef
begin_define
DECL|macro|DEFLATE_H
define|#
directive|define
name|DEFLATE_H
end_define
begin_include
include|#
directive|include
file|"zutil.h"
end_include
begin_comment
comment|/* define NO_GZIP when compiling if you want to disable gzip header and    trailer creation by deflate().  NO_GZIP would be used to avoid linking in    the crc code when it is not needed.  For shared libraries, gzip encoding    should be left enabled. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NO_GZIP
end_ifndef
begin_define
DECL|macro|GZIP
define|#
directive|define
name|GZIP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ===========================================================================  * Internal compression state.  */
end_comment
begin_define
DECL|macro|LENGTH_CODES
define|#
directive|define
name|LENGTH_CODES
value|29
end_define
begin_comment
comment|/* number of length codes, not counting the special END_BLOCK code */
end_comment
begin_define
DECL|macro|LITERALS
define|#
directive|define
name|LITERALS
value|256
end_define
begin_comment
comment|/* number of literal bytes 0..255 */
end_comment
begin_define
DECL|macro|L_CODES
define|#
directive|define
name|L_CODES
value|(LITERALS+1+LENGTH_CODES)
end_define
begin_comment
comment|/* number of Literal or Length codes, including the END_BLOCK code */
end_comment
begin_define
DECL|macro|D_CODES
define|#
directive|define
name|D_CODES
value|30
end_define
begin_comment
comment|/* number of distance codes */
end_comment
begin_define
DECL|macro|BL_CODES
define|#
directive|define
name|BL_CODES
value|19
end_define
begin_comment
comment|/* number of codes used to transfer the bit lengths */
end_comment
begin_define
DECL|macro|HEAP_SIZE
define|#
directive|define
name|HEAP_SIZE
value|(2*L_CODES+1)
end_define
begin_comment
comment|/* maximum heap size */
end_comment
begin_define
DECL|macro|MAX_BITS
define|#
directive|define
name|MAX_BITS
value|15
end_define
begin_comment
comment|/* All codes must not exceed MAX_BITS bits */
end_comment
begin_define
DECL|macro|INIT_STATE
define|#
directive|define
name|INIT_STATE
value|42
end_define
begin_define
DECL|macro|EXTRA_STATE
define|#
directive|define
name|EXTRA_STATE
value|69
end_define
begin_define
DECL|macro|NAME_STATE
define|#
directive|define
name|NAME_STATE
value|73
end_define
begin_define
DECL|macro|COMMENT_STATE
define|#
directive|define
name|COMMENT_STATE
value|91
end_define
begin_define
DECL|macro|HCRC_STATE
define|#
directive|define
name|HCRC_STATE
value|103
end_define
begin_define
DECL|macro|BUSY_STATE
define|#
directive|define
name|BUSY_STATE
value|113
end_define
begin_define
DECL|macro|FINISH_STATE
define|#
directive|define
name|FINISH_STATE
value|666
end_define
begin_comment
comment|/* Stream status */
end_comment
begin_comment
comment|/* Data structure describing a single value and its code string. */
end_comment
begin_typedef
DECL|struct|ct_data_s
typedef|typedef
struct|struct
name|ct_data_s
block|{
union|union
block|{
DECL|member|freq
name|ush
name|freq
decl_stmt|;
comment|/* frequency count */
DECL|member|code
name|ush
name|code
decl_stmt|;
comment|/* bit string */
block|}
DECL|member|fc
name|fc
union|;
union|union
block|{
DECL|member|dad
name|ush
name|dad
decl_stmt|;
comment|/* father node in Huffman tree */
DECL|member|len
name|ush
name|len
decl_stmt|;
comment|/* length of bit string */
block|}
DECL|member|dl
name|dl
union|;
block|}
DECL|typedef|ct_data
name|FAR
name|ct_data
typedef|;
end_typedef
begin_define
DECL|macro|Freq
define|#
directive|define
name|Freq
value|fc.freq
end_define
begin_define
DECL|macro|Code
define|#
directive|define
name|Code
value|fc.code
end_define
begin_define
DECL|macro|Dad
define|#
directive|define
name|Dad
value|dl.dad
end_define
begin_define
DECL|macro|Len
define|#
directive|define
name|Len
value|dl.len
end_define
begin_typedef
DECL|typedef|static_tree_desc
typedef|typedef
name|struct
name|static_tree_desc_s
name|static_tree_desc
typedef|;
end_typedef
begin_typedef
DECL|struct|tree_desc_s
typedef|typedef
struct|struct
name|tree_desc_s
block|{
DECL|member|dyn_tree
name|ct_data
modifier|*
name|dyn_tree
decl_stmt|;
comment|/* the dynamic tree */
DECL|member|max_code
name|int
name|max_code
decl_stmt|;
comment|/* largest code with non zero frequency */
DECL|member|stat_desc
name|static_tree_desc
modifier|*
name|stat_desc
decl_stmt|;
comment|/* the corresponding static tree */
block|}
DECL|typedef|tree_desc
name|FAR
name|tree_desc
typedef|;
end_typedef
begin_typedef
DECL|typedef|Pos
typedef|typedef
name|ush
name|Pos
typedef|;
end_typedef
begin_typedef
DECL|typedef|Posf
typedef|typedef
name|Pos
name|FAR
name|Posf
typedef|;
end_typedef
begin_typedef
DECL|typedef|IPos
typedef|typedef
name|unsigned
name|IPos
typedef|;
end_typedef
begin_comment
comment|/* A Pos is an index in the character window. We use short instead of int to  * save space in the various tables. IPos is used only for parameter passing.  */
end_comment
begin_typedef
DECL|struct|internal_state
typedef|typedef
struct|struct
name|internal_state
block|{
DECL|member|strm
name|z_streamp
name|strm
decl_stmt|;
comment|/* pointer back to this zlib stream */
DECL|member|status
name|int
name|status
decl_stmt|;
comment|/* as the name implies */
DECL|member|pending_buf
name|Bytef
modifier|*
name|pending_buf
decl_stmt|;
comment|/* output still pending */
DECL|member|pending_buf_size
name|ulg
name|pending_buf_size
decl_stmt|;
comment|/* size of pending_buf */
DECL|member|pending_out
name|Bytef
modifier|*
name|pending_out
decl_stmt|;
comment|/* next pending byte to output to the stream */
DECL|member|pending
name|uInt
name|pending
decl_stmt|;
comment|/* nb of bytes in the pending buffer */
DECL|member|wrap
name|int
name|wrap
decl_stmt|;
comment|/* bit 0 true for zlib, bit 1 true for gzip */
DECL|member|gzhead
name|gz_headerp
name|gzhead
decl_stmt|;
comment|/* gzip header information to write */
DECL|member|gzindex
name|uInt
name|gzindex
decl_stmt|;
comment|/* where in extra, name, or comment */
DECL|member|method
name|Byte
name|method
decl_stmt|;
comment|/* STORED (for zip only) or DEFLATED */
DECL|member|last_flush
name|int
name|last_flush
decl_stmt|;
comment|/* value of flush param for previous deflate call */
comment|/* used by deflate.c: */
DECL|member|w_size
name|uInt
name|w_size
decl_stmt|;
comment|/* LZ77 window size (32K by default) */
DECL|member|w_bits
name|uInt
name|w_bits
decl_stmt|;
comment|/* log2(w_size)  (8..16) */
DECL|member|w_mask
name|uInt
name|w_mask
decl_stmt|;
comment|/* w_size - 1 */
DECL|member|window
name|Bytef
modifier|*
name|window
decl_stmt|;
comment|/* Sliding window. Input bytes are read into the second half of the window,      * and move to the first half later to keep a dictionary of at least wSize      * bytes. With this organization, matches are limited to a distance of      * wSize-MAX_MATCH bytes, but this ensures that IO is always      * performed with a length multiple of the block size. Also, it limits      * the window size to 64K, which is quite useful on MSDOS.      * To do: use the user input buffer as sliding window.      */
DECL|member|window_size
name|ulg
name|window_size
decl_stmt|;
comment|/* Actual size of window: 2*wSize, except when the user input buffer      * is directly used as sliding window.      */
DECL|member|prev
name|Posf
modifier|*
name|prev
decl_stmt|;
comment|/* Link to older string with same hash index. To limit the size of this      * array to 64K, this link is maintained only for the last 32K strings.      * An index in this array is thus a window index modulo 32K.      */
DECL|member|head
name|Posf
modifier|*
name|head
decl_stmt|;
comment|/* Heads of the hash chains or NIL. */
DECL|member|ins_h
name|uInt
name|ins_h
decl_stmt|;
comment|/* hash index of string to be inserted */
DECL|member|hash_size
name|uInt
name|hash_size
decl_stmt|;
comment|/* number of elements in hash table */
DECL|member|hash_bits
name|uInt
name|hash_bits
decl_stmt|;
comment|/* log2(hash_size) */
DECL|member|hash_mask
name|uInt
name|hash_mask
decl_stmt|;
comment|/* hash_size-1 */
DECL|member|hash_shift
name|uInt
name|hash_shift
decl_stmt|;
comment|/* Number of bits by which ins_h must be shifted at each input      * step. It must be such that after MIN_MATCH steps, the oldest      * byte no longer takes part in the hash key, that is:      *   hash_shift * MIN_MATCH>= hash_bits      */
DECL|member|block_start
name|long
name|block_start
decl_stmt|;
comment|/* Window position at the beginning of the current output block. Gets      * negative when the window is moved backwards.      */
DECL|member|match_length
name|uInt
name|match_length
decl_stmt|;
comment|/* length of best match */
DECL|member|prev_match
name|IPos
name|prev_match
decl_stmt|;
comment|/* previous match */
DECL|member|match_available
name|int
name|match_available
decl_stmt|;
comment|/* set if previous match exists */
DECL|member|strstart
name|uInt
name|strstart
decl_stmt|;
comment|/* start of string to insert */
DECL|member|match_start
name|uInt
name|match_start
decl_stmt|;
comment|/* start of matching string */
DECL|member|lookahead
name|uInt
name|lookahead
decl_stmt|;
comment|/* number of valid bytes ahead in window */
DECL|member|prev_length
name|uInt
name|prev_length
decl_stmt|;
comment|/* Length of the best match at previous step. Matches not greater than this      * are discarded. This is used in the lazy match evaluation.      */
DECL|member|max_chain_length
name|uInt
name|max_chain_length
decl_stmt|;
comment|/* To speed up deflation, hash chains are never searched beyond this      * length.  A higher limit improves compression ratio but degrades the      * speed.      */
DECL|member|max_lazy_match
name|uInt
name|max_lazy_match
decl_stmt|;
comment|/* Attempt to find a better match only when the current match is strictly      * smaller than this value. This mechanism is used only for compression      * levels>= 4.      */
DECL|macro|max_insert_length
define|#
directive|define
name|max_insert_length
value|max_lazy_match
comment|/* Insert new strings in the hash table only if the match length is not      * greater than this length. This saves time but degrades compression.      * max_insert_length is used only for compression levels<= 3.      */
DECL|member|level
name|int
name|level
decl_stmt|;
comment|/* compression level (1..9) */
DECL|member|strategy
name|int
name|strategy
decl_stmt|;
comment|/* favor or force Huffman coding*/
DECL|member|good_match
name|uInt
name|good_match
decl_stmt|;
comment|/* Use a faster search when the previous match is longer than this */
DECL|member|nice_match
name|int
name|nice_match
decl_stmt|;
comment|/* Stop searching when current match exceeds this */
comment|/* used by trees.c: */
comment|/* Didn't use ct_data typedef below to supress compiler warning */
DECL|member|dyn_ltree
name|struct
name|ct_data_s
name|dyn_ltree
index|[
name|HEAP_SIZE
index|]
decl_stmt|;
comment|/* literal and length tree */
DECL|member|dyn_dtree
name|struct
name|ct_data_s
name|dyn_dtree
index|[
literal|2
operator|*
name|D_CODES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* distance tree */
DECL|member|bl_tree
name|struct
name|ct_data_s
name|bl_tree
index|[
literal|2
operator|*
name|BL_CODES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Huffman tree for bit lengths */
DECL|member|l_desc
name|struct
name|tree_desc_s
name|l_desc
decl_stmt|;
comment|/* desc. for literal tree */
DECL|member|d_desc
name|struct
name|tree_desc_s
name|d_desc
decl_stmt|;
comment|/* desc. for distance tree */
DECL|member|bl_desc
name|struct
name|tree_desc_s
name|bl_desc
decl_stmt|;
comment|/* desc. for bit length tree */
DECL|member|bl_count
name|ush
name|bl_count
index|[
name|MAX_BITS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* number of codes at each bit length for an optimal tree */
DECL|member|heap
name|int
name|heap
index|[
literal|2
operator|*
name|L_CODES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* heap used to build the Huffman trees */
DECL|member|heap_len
name|int
name|heap_len
decl_stmt|;
comment|/* number of elements in the heap */
DECL|member|heap_max
name|int
name|heap_max
decl_stmt|;
comment|/* element of largest frequency */
comment|/* The sons of heap[n] are heap[2*n] and heap[2*n+1]. heap[0] is not used.      * The same heap array is used to build all trees.      */
DECL|member|depth
name|uch
name|depth
index|[
literal|2
operator|*
name|L_CODES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Depth of each subtree used as tie breaker for trees of equal frequency      */
DECL|member|l_buf
name|uchf
modifier|*
name|l_buf
decl_stmt|;
comment|/* buffer for literals or lengths */
DECL|member|lit_bufsize
name|uInt
name|lit_bufsize
decl_stmt|;
comment|/* Size of match buffer for literals/lengths.  There are 4 reasons for      * limiting lit_bufsize to 64K:      *   - frequencies can be kept in 16 bit counters      *   - if compression is not successful for the first block, all input      *     data is still in the window so we can still emit a stored block even      *     when input comes from standard input.  (This can also be done for      *     all blocks if lit_bufsize is not greater than 32K.)      *   - if compression is not successful for a file smaller than 64K, we can      *     even emit a stored file instead of a stored block (saving 5 bytes).      *     This is applicable only for zip (not gzip or zlib).      *   - creating new Huffman trees less frequently may not provide fast      *     adaptation to changes in the input data statistics. (Take for      *     example a binary file with poorly compressible code followed by      *     a highly compressible string table.) Smaller buffer sizes give      *     fast adaptation but have of course the overhead of transmitting      *     trees more frequently.      *   - I can't count above 4      */
DECL|member|last_lit
name|uInt
name|last_lit
decl_stmt|;
comment|/* running index in l_buf */
DECL|member|d_buf
name|ushf
modifier|*
name|d_buf
decl_stmt|;
comment|/* Buffer for distances. To simplify the code, d_buf and l_buf have      * the same number of elements. To use different lengths, an extra flag      * array would be necessary.      */
DECL|member|opt_len
name|ulg
name|opt_len
decl_stmt|;
comment|/* bit length of current block with optimal trees */
DECL|member|static_len
name|ulg
name|static_len
decl_stmt|;
comment|/* bit length of current block with static trees */
DECL|member|matches
name|uInt
name|matches
decl_stmt|;
comment|/* number of string matches in current block */
DECL|member|last_eob_len
name|int
name|last_eob_len
decl_stmt|;
comment|/* bit length of EOB code for last block */
ifdef|#
directive|ifdef
name|DEBUG
DECL|member|compressed_len
name|ulg
name|compressed_len
decl_stmt|;
comment|/* total bit length of compressed file mod 2^32 */
DECL|member|bits_sent
name|ulg
name|bits_sent
decl_stmt|;
comment|/* bit length of compressed data sent mod 2^32 */
endif|#
directive|endif
DECL|member|bi_buf
name|ush
name|bi_buf
decl_stmt|;
comment|/* Output buffer. bits are inserted starting at the bottom (least      * significant bits).      */
DECL|member|bi_valid
name|int
name|bi_valid
decl_stmt|;
comment|/* Number of valid bits in bi_buf.  All bits above the last valid bit      * are always zero.      */
DECL|member|high_water
name|ulg
name|high_water
decl_stmt|;
comment|/* High water mark offset in window for initialized bytes -- bytes above      * this are set to zero in order to avoid memory check warnings when      * longest match routines access bytes past the input.  This is then      * updated to the new high water mark.      */
block|}
DECL|typedef|deflate_state
name|FAR
name|deflate_state
typedef|;
end_typedef
begin_comment
comment|/* Output a byte on the stream.  * IN assertion: there is enough room in pending_buf.  */
end_comment
begin_define
DECL|macro|put_byte
define|#
directive|define
name|put_byte
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|{s->pending_buf[s->pending++] = (c);}
end_define
begin_define
DECL|macro|MIN_LOOKAHEAD
define|#
directive|define
name|MIN_LOOKAHEAD
value|(MAX_MATCH+MIN_MATCH+1)
end_define
begin_comment
comment|/* Minimum amount of lookahead, except at the end of the input file.  * See deflate.c for comments about the MIN_MATCH+1.  */
end_comment
begin_define
DECL|macro|MAX_DIST
define|#
directive|define
name|MAX_DIST
parameter_list|(
name|s
parameter_list|)
value|((s)->w_size-MIN_LOOKAHEAD)
end_define
begin_comment
comment|/* In order to simplify the code, particularly on 16 bit machines, match  * distances are limited to MAX_DIST instead of WSIZE.  */
end_comment
begin_define
DECL|macro|WIN_INIT
define|#
directive|define
name|WIN_INIT
value|MAX_MATCH
end_define
begin_comment
comment|/* Number of bytes after end of data in window to initialize in order to avoid    memory checker errors from longest match routines */
end_comment
begin_comment
comment|/* in trees.c */
end_comment
begin_decl_stmt
name|void
name|ZLIB_INTERNAL
name|_tr_init
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|ZLIB_INTERNAL
name|_tr_tally
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|,
name|unsigned
name|dist
operator|,
name|unsigned
name|lc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|ZLIB_INTERNAL
name|_tr_flush_block
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|,
name|charf
operator|*
name|buf
operator|,
name|ulg
name|stored_len
operator|,
name|int
name|last
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|ZLIB_INTERNAL
name|_tr_align
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|ZLIB_INTERNAL
name|_tr_stored_block
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|,
name|charf
operator|*
name|buf
operator|,
name|ulg
name|stored_len
operator|,
name|int
name|last
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|d_code
define|#
directive|define
name|d_code
parameter_list|(
name|dist
parameter_list|)
define|\
value|((dist)< 256 ? _dist_code[dist] : _dist_code[256+((dist)>>7)])
end_define
begin_comment
comment|/* Mapping from a distance to a distance code. dist is the distance - 1 and  * must not have side effects. _dist_code[256] and _dist_code[257] are never  * used.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef
begin_comment
comment|/* Inline versions of _tr_tally for speed: */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|GEN_TREES_H
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|STDC
argument_list|)
end_if
begin_decl_stmt
specifier|extern
name|uch
name|ZLIB_INTERNAL
name|_length_code
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|uch
name|ZLIB_INTERNAL
name|_dist_code
index|[]
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
specifier|extern
specifier|const
name|uch
name|ZLIB_INTERNAL
name|_length_code
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|uch
name|ZLIB_INTERNAL
name|_dist_code
index|[]
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|_tr_tally_lit
define|#
directive|define
name|_tr_tally_lit
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|flush
parameter_list|)
define|\
value|{ uch cc = (c); \     s->d_buf[s->last_lit] = 0; \     s->l_buf[s->last_lit++] = cc; \     s->dyn_ltree[cc].Freq++; \     flush = (s->last_lit == s->lit_bufsize-1); \    }
end_define
begin_define
DECL|macro|_tr_tally_dist
define|#
directive|define
name|_tr_tally_dist
parameter_list|(
name|s
parameter_list|,
name|distance
parameter_list|,
name|length
parameter_list|,
name|flush
parameter_list|)
define|\
value|{ uch len = (length); \     ush dist = (distance); \     s->d_buf[s->last_lit] = dist; \     s->l_buf[s->last_lit++] = len; \     dist--; \     s->dyn_ltree[_length_code[len]+LITERALS+1].Freq++; \     s->dyn_dtree[d_code(dist)].Freq++; \     flush = (s->last_lit == s->lit_bufsize-1); \   }
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|_tr_tally_lit
define|#
directive|define
name|_tr_tally_lit
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|flush
parameter_list|)
value|flush = _tr_tally(s, 0, c)
end_define
begin_define
DECL|macro|_tr_tally_dist
define|#
directive|define
name|_tr_tally_dist
parameter_list|(
name|s
parameter_list|,
name|distance
parameter_list|,
name|length
parameter_list|,
name|flush
parameter_list|)
define|\
value|flush = _tr_tally(s, distance, length)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* DEFLATE_H */
end_comment
end_unit
