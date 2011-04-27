begin_unit
begin_comment
comment|/* infutil.h -- types and macros common to blocks and codes  * Copyright (C) 1995-2002 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment
begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_INFUTIL_H
end_ifndef
begin_define
DECL|macro|_INFUTIL_H
define|#
directive|define
name|_INFUTIL_H
end_define
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|TYPE
name|TYPE
block|,
comment|/* get type bits (3, including end bit) */
DECL|enumerator|LENS
name|LENS
block|,
comment|/* get lengths for stored */
DECL|enumerator|STORED
name|STORED
block|,
comment|/* processing stored block */
DECL|enumerator|TABLE
name|TABLE
block|,
comment|/* get table lengths */
DECL|enumerator|BTREE
name|BTREE
block|,
comment|/* get bit lengths tree for a dynamic block */
DECL|enumerator|DTREE
name|DTREE
block|,
comment|/* get length, distance trees for a dynamic block */
DECL|enumerator|CODES
name|CODES
block|,
comment|/* processing fixed or dynamic block */
DECL|enumerator|DRY
name|DRY
block|,
comment|/* output remaining window bytes */
DECL|enumerator|DONE
name|DONE
block|,
comment|/* finished last block, done */
DECL|enumerator|BAD
name|BAD
block|}
comment|/* got a data error--stuck here */
DECL|typedef|inflate_block_mode
name|inflate_block_mode
typedef|;
end_typedef
begin_comment
comment|/* inflate blocks semi-private state */
end_comment
begin_struct
DECL|struct|inflate_blocks_state
struct|struct
name|inflate_blocks_state
block|{
comment|/* mode */
DECL|member|mode
name|inflate_block_mode
name|mode
decl_stmt|;
comment|/* current inflate_block mode */
comment|/* mode dependent information */
union|union
block|{
DECL|member|left
name|uInt
name|left
decl_stmt|;
comment|/* if STORED, bytes left to copy */
struct|struct
block|{
DECL|member|table
name|uInt
name|table
decl_stmt|;
comment|/* table lengths (14 bits) */
DECL|member|index
name|uInt
name|index
decl_stmt|;
comment|/* index into blens (or border) */
DECL|member|blens
name|uIntf
modifier|*
name|blens
decl_stmt|;
comment|/* bit lengths of codes */
DECL|member|bb
name|uInt
name|bb
decl_stmt|;
comment|/* bit length tree depth */
DECL|member|tb
name|inflate_huft
modifier|*
name|tb
decl_stmt|;
comment|/* bit length decoding tree */
block|}
DECL|member|trees
name|trees
struct|;
comment|/* if DTREE, decoding info for trees */
struct|struct
block|{
name|inflate_codes_statef
DECL|member|codes
modifier|*
name|codes
decl_stmt|;
block|}
DECL|member|decode
name|decode
struct|;
comment|/* if CODES, current state */
block|}
DECL|member|sub
name|sub
union|;
comment|/* submode */
DECL|member|last
name|uInt
name|last
decl_stmt|;
comment|/* true if this block is the last block */
comment|/* mode independent information */
DECL|member|bitk
name|uInt
name|bitk
decl_stmt|;
comment|/* bits in bit buffer */
DECL|member|bitb
name|uLong
name|bitb
decl_stmt|;
comment|/* bit buffer */
DECL|member|hufts
name|inflate_huft
modifier|*
name|hufts
decl_stmt|;
comment|/* single malloc for tree space */
DECL|member|window
name|Bytef
modifier|*
name|window
decl_stmt|;
comment|/* sliding window */
DECL|member|end
name|Bytef
modifier|*
name|end
decl_stmt|;
comment|/* one byte after sliding window */
DECL|member|read
name|Bytef
modifier|*
name|read
decl_stmt|;
comment|/* window read pointer */
DECL|member|write
name|Bytef
modifier|*
name|write
decl_stmt|;
comment|/* window write pointer */
DECL|member|checkfn
name|check_func
name|checkfn
decl_stmt|;
comment|/* check function */
DECL|member|check
name|uLong
name|check
decl_stmt|;
comment|/* check on output */
block|}
struct|;
end_struct
begin_comment
comment|/* defines for inflate input/output */
end_comment
begin_comment
comment|/*   update pointers and return */
end_comment
begin_define
DECL|macro|UPDBITS
define|#
directive|define
name|UPDBITS
value|{s->bitb=b;s->bitk=k;}
end_define
begin_define
DECL|macro|UPDIN
define|#
directive|define
name|UPDIN
value|{z->avail_in=n;z->total_in+=p-z->next_in;z->next_in=p;}
end_define
begin_define
DECL|macro|UPDOUT
define|#
directive|define
name|UPDOUT
value|{s->write=q;}
end_define
begin_define
DECL|macro|UPDATE
define|#
directive|define
name|UPDATE
value|{UPDBITS UPDIN UPDOUT}
end_define
begin_define
DECL|macro|LEAVE
define|#
directive|define
name|LEAVE
value|{UPDATE return inflate_flush(s,z,r);}
end_define
begin_comment
comment|/*   get bytes and bits */
end_comment
begin_define
DECL|macro|LOADIN
define|#
directive|define
name|LOADIN
value|{p=z->next_in;n=z->avail_in;b=s->bitb;k=s->bitk;}
end_define
begin_define
DECL|macro|NEEDBYTE
define|#
directive|define
name|NEEDBYTE
value|{if(n)r=Z_OK;else LEAVE}
end_define
begin_define
DECL|macro|NEXTBYTE
define|#
directive|define
name|NEXTBYTE
value|(n--,*p++)
end_define
begin_define
DECL|macro|NEEDBITS
define|#
directive|define
name|NEEDBITS
parameter_list|(
name|j
parameter_list|)
value|{while(k<(j)){NEEDBYTE;b|=((uLong)NEXTBYTE)<<k;k+=8;}}
end_define
begin_define
DECL|macro|DUMPBITS
define|#
directive|define
name|DUMPBITS
parameter_list|(
name|j
parameter_list|)
value|{b>>=(j);k-=(j);}
end_define
begin_comment
comment|/*   output bytes */
end_comment
begin_define
DECL|macro|WAVAIL
define|#
directive|define
name|WAVAIL
value|(uInt)(q<s->read?s->read-q-1:s->end-q)
end_define
begin_define
DECL|macro|LOADOUT
define|#
directive|define
name|LOADOUT
value|{q=s->write;m=(uInt)WAVAIL;}
end_define
begin_define
DECL|macro|WRAP
define|#
directive|define
name|WRAP
value|{if(q==s->end&&s->read!=s->window){q=s->window;m=(uInt)WAVAIL;}}
end_define
begin_define
DECL|macro|FLUSH
define|#
directive|define
name|FLUSH
value|{UPDOUT r=inflate_flush(s,z,r); LOADOUT}
end_define
begin_define
DECL|macro|NEEDOUT
define|#
directive|define
name|NEEDOUT
value|{if(m==0){WRAP if(m==0){FLUSH WRAP if(m==0) LEAVE}}r=Z_OK;}
end_define
begin_define
DECL|macro|OUTBYTE
define|#
directive|define
name|OUTBYTE
parameter_list|(
name|a
parameter_list|)
value|{*q++=(Byte)(a);m--;}
end_define
begin_comment
comment|/*   load local pointers */
end_comment
begin_define
DECL|macro|LOAD
define|#
directive|define
name|LOAD
value|{LOADIN LOADOUT}
end_define
begin_comment
comment|/* masks for lower bits (size given to avoid silly warnings with Visual C++) */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NO_INFLATE_MASK
end_ifndef
begin_decl_stmt
DECL|variable|inflate_mask
name|local
name|uInt
name|inflate_mask
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* copy as much as possible from the sliding window to the output area */
end_comment
begin_decl_stmt
name|local
name|int
name|inflate_flush
name|OF
argument_list|(
operator|(
name|inflate_blocks_statef
operator|*
operator|,
name|z_streamp
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
