begin_unit
begin_comment
comment|/*  * This code implements the MD5 message-digest algorithm.  * The algorithm is due to Ron Rivest.  This code was  * written by Colin Plumb in 1993, no copyright is claimed.  * This code is in the public domain; do with it what you wish.  *  * Equivalent code is available from RSA Data Security, Inc.  * This code has been tested against that, and is equivalent,  * except that you don't need to include two pages of legalese  * with every copy.  *  * To compute the message digest of a chunk of bytes, declare an  * MD5Context structure, pass it to MD5Init, call MD5Update as  * needed on buffers full of bytes, and then call MD5Final, which  * will fill a supplied 16-byte array with the digest.  *  * Changed so as no longer to depend on Colin Plumb's `usual.h' header  * definitions; now uses stuff from dpkg's config.h.  *  - Ian Jackson<ian@chiark.greenend.org.uk>.  * Still in the public domain.  */
end_comment
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_comment
comment|/* for memcpy() */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_comment
comment|/* for stupid systems */
end_comment
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<windef.h>
end_include
begin_include
include|#
directive|include
file|<types.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"md5.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
specifier|static
name|void
DECL|function|byteSwap
name|byteSwap
parameter_list|(
name|UWORD32
modifier|*
name|buf
parameter_list|,
name|unsigned
name|words
parameter_list|)
block|{
specifier|const
name|quint32
name|byteOrderTest
init|=
literal|0x1
decl_stmt|;
if|if
condition|(
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
name|byteOrderTest
operator|)
index|[
literal|0
index|]
operator|==
literal|0
condition|)
block|{
name|md5byte
modifier|*
name|p
init|=
operator|(
name|md5byte
operator|*
operator|)
name|buf
decl_stmt|;
do|do
block|{
operator|*
name|buf
operator|++
operator|=
call|(
name|UWORD32
call|)
argument_list|(
operator|(
name|unsigned
operator|)
name|p
index|[
literal|3
index|]
operator|<<
literal|8
operator||
name|p
index|[
literal|2
index|]
argument_list|)
operator|<<
literal|16
operator||
operator|(
operator|(
name|unsigned
operator|)
name|p
index|[
literal|1
index|]
operator|<<
literal|8
operator||
name|p
index|[
literal|0
index|]
operator|)
expr_stmt|;
name|p
operator|+=
literal|4
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|words
condition|)
do|;
block|}
block|}
end_function
begin_comment
comment|/*  * Start MD5 accumulation.  Set bit count to 0 and buffer to mysterious  * initialization constants.  */
end_comment
begin_function
specifier|static
name|void
DECL|function|MD5Init
name|MD5Init
parameter_list|(
name|struct
name|MD5Context
modifier|*
name|ctx
parameter_list|)
block|{
name|ctx
operator|->
name|buf
index|[
literal|0
index|]
operator|=
literal|0x67452301
expr_stmt|;
name|ctx
operator|->
name|buf
index|[
literal|1
index|]
operator|=
literal|0xefcdab89
expr_stmt|;
name|ctx
operator|->
name|buf
index|[
literal|2
index|]
operator|=
literal|0x98badcfe
expr_stmt|;
name|ctx
operator|->
name|buf
index|[
literal|3
index|]
operator|=
literal|0x10325476
expr_stmt|;
name|ctx
operator|->
name|bytes
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|ctx
operator|->
name|bytes
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  * Update context to reflect the concatenation of another buffer full  * of bytes.  */
end_comment
begin_function
specifier|static
name|void
DECL|function|MD5Update
name|MD5Update
parameter_list|(
name|struct
name|MD5Context
modifier|*
name|ctx
parameter_list|,
name|md5byte
specifier|const
modifier|*
name|buf
parameter_list|,
name|unsigned
name|len
parameter_list|)
block|{
name|UWORD32
name|t
decl_stmt|;
comment|/* Update byte count */
name|t
operator|=
name|ctx
operator|->
name|bytes
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|ctx
operator|->
name|bytes
index|[
literal|0
index|]
operator|=
name|t
operator|+
name|len
operator|)
operator|<
name|t
condition|)
name|ctx
operator|->
name|bytes
index|[
literal|1
index|]
operator|++
expr_stmt|;
comment|/* Carry from low to high */
name|t
operator|=
literal|64
operator|-
operator|(
name|t
operator|&
literal|0x3f
operator|)
expr_stmt|;
comment|/* Space available in ctx->in (at least 1) */
if|if
condition|(
name|t
operator|>
name|len
condition|)
block|{
name|memcpy
argument_list|(
operator|(
name|md5byte
operator|*
operator|)
name|ctx
operator|->
name|in
operator|+
literal|64
operator|-
name|t
argument_list|,
name|buf
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* First chunk is an odd size */
name|memcpy
argument_list|(
operator|(
name|md5byte
operator|*
operator|)
name|ctx
operator|->
name|in
operator|+
literal|64
operator|-
name|t
argument_list|,
name|buf
argument_list|,
name|t
argument_list|)
expr_stmt|;
name|byteSwap
argument_list|(
name|ctx
operator|->
name|in
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|MD5Transform
argument_list|(
name|ctx
operator|->
name|buf
argument_list|,
name|ctx
operator|->
name|in
argument_list|)
expr_stmt|;
name|buf
operator|+=
name|t
expr_stmt|;
name|len
operator|-=
name|t
expr_stmt|;
comment|/* Process data in 64-byte chunks */
while|while
condition|(
name|len
operator|>=
literal|64
condition|)
block|{
name|memcpy
argument_list|(
name|ctx
operator|->
name|in
argument_list|,
name|buf
argument_list|,
literal|64
argument_list|)
expr_stmt|;
name|byteSwap
argument_list|(
name|ctx
operator|->
name|in
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|MD5Transform
argument_list|(
name|ctx
operator|->
name|buf
argument_list|,
name|ctx
operator|->
name|in
argument_list|)
expr_stmt|;
name|buf
operator|+=
literal|64
expr_stmt|;
name|len
operator|-=
literal|64
expr_stmt|;
block|}
comment|/* Handle any remaining bytes of data. */
name|memcpy
argument_list|(
name|ctx
operator|->
name|in
argument_list|,
name|buf
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  * Final wrapup - pad to 64-byte boundary with the bit pattern   * 1 0* (64-bit count of bits processed, MSB-first)  */
end_comment
begin_function
specifier|static
name|void
DECL|function|MD5Final
name|MD5Final
parameter_list|(
name|struct
name|MD5Context
modifier|*
name|ctx
parameter_list|,
name|md5byte
name|digest
index|[
literal|16
index|]
parameter_list|)
block|{
name|int
name|count
init|=
name|ctx
operator|->
name|bytes
index|[
literal|0
index|]
operator|&
literal|0x3f
decl_stmt|;
comment|/* Number of bytes in ctx->in */
name|md5byte
modifier|*
name|p
init|=
operator|(
name|md5byte
operator|*
operator|)
name|ctx
operator|->
name|in
operator|+
name|count
decl_stmt|;
comment|/* Set the first char of padding to 0x80.  There is always room. */
operator|*
name|p
operator|++
operator|=
literal|0x80
expr_stmt|;
comment|/* Bytes of padding needed to make 56 bytes (-8..55) */
name|count
operator|=
literal|56
operator|-
literal|1
operator|-
name|count
expr_stmt|;
if|if
condition|(
name|count
operator|<
literal|0
condition|)
block|{
comment|/* Padding forces an extra block */
name|memset
argument_list|(
name|p
argument_list|,
literal|0
argument_list|,
name|count
operator|+
literal|8
argument_list|)
expr_stmt|;
name|byteSwap
argument_list|(
name|ctx
operator|->
name|in
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|MD5Transform
argument_list|(
name|ctx
operator|->
name|buf
argument_list|,
name|ctx
operator|->
name|in
argument_list|)
expr_stmt|;
name|p
operator|=
operator|(
name|md5byte
operator|*
operator|)
name|ctx
operator|->
name|in
expr_stmt|;
name|count
operator|=
literal|56
expr_stmt|;
block|}
name|memset
argument_list|(
name|p
argument_list|,
literal|0
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|byteSwap
argument_list|(
name|ctx
operator|->
name|in
argument_list|,
literal|14
argument_list|)
expr_stmt|;
comment|/* Append length in bits and transform */
name|ctx
operator|->
name|in
index|[
literal|14
index|]
operator|=
name|ctx
operator|->
name|bytes
index|[
literal|0
index|]
operator|<<
literal|3
expr_stmt|;
name|ctx
operator|->
name|in
index|[
literal|15
index|]
operator|=
name|ctx
operator|->
name|bytes
index|[
literal|1
index|]
operator|<<
literal|3
operator||
name|ctx
operator|->
name|bytes
index|[
literal|0
index|]
operator|>>
literal|29
expr_stmt|;
name|MD5Transform
argument_list|(
name|ctx
operator|->
name|buf
argument_list|,
name|ctx
operator|->
name|in
argument_list|)
expr_stmt|;
name|byteSwap
argument_list|(
name|ctx
operator|->
name|buf
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|digest
argument_list|,
name|ctx
operator|->
name|buf
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|ctx
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|ctx
argument_list|)
argument_list|)
expr_stmt|;
comment|/* In case it's sensitive */
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|ASM_MD5
end_ifndef
begin_comment
comment|/* The four core functions - F1 is optimized somewhat */
end_comment
begin_comment
comment|/* #define F1(x, y, z) (x& y | ~x& z) */
end_comment
begin_define
DECL|macro|F1
define|#
directive|define
name|F1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(z ^ (x& (y ^ z)))
end_define
begin_define
DECL|macro|F2
define|#
directive|define
name|F2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|F1(z, x, y)
end_define
begin_define
DECL|macro|F3
define|#
directive|define
name|F3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(x ^ y ^ z)
end_define
begin_define
DECL|macro|F4
define|#
directive|define
name|F4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(y ^ (x | ~z))
end_define
begin_comment
comment|/* This is the central step in the MD5 algorithm. */
end_comment
begin_define
DECL|macro|MD5STEP
define|#
directive|define
name|MD5STEP
parameter_list|(
name|f
parameter_list|,
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|in
parameter_list|,
name|s
parameter_list|)
define|\
value|(w += f(x,y,z) + in, w = (w<<s | w>>(32-s)) + x)
end_define
begin_comment
comment|/*  * The core of the MD5 algorithm, this alters an existing MD5 hash to  * reflect the addition of 16 longwords of new data.  MD5Update blocks  * the data and converts bytes into longwords for this routine.  */
end_comment
begin_function
specifier|static
name|void
DECL|function|MD5Transform
name|MD5Transform
parameter_list|(
name|UWORD32
name|buf
index|[
literal|4
index|]
parameter_list|,
name|UWORD32
specifier|const
name|in
index|[
literal|16
index|]
parameter_list|)
block|{
specifier|register
name|UWORD32
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
name|a
operator|=
name|buf
index|[
literal|0
index|]
expr_stmt|;
name|b
operator|=
name|buf
index|[
literal|1
index|]
expr_stmt|;
name|c
operator|=
name|buf
index|[
literal|2
index|]
expr_stmt|;
name|d
operator|=
name|buf
index|[
literal|3
index|]
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|0
index|]
operator|+
literal|0xd76aa478
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|1
index|]
operator|+
literal|0xe8c7b756
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|2
index|]
operator|+
literal|0x242070db
argument_list|,
literal|17
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|3
index|]
operator|+
literal|0xc1bdceee
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|4
index|]
operator|+
literal|0xf57c0faf
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|5
index|]
operator|+
literal|0x4787c62a
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|6
index|]
operator|+
literal|0xa8304613
argument_list|,
literal|17
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|7
index|]
operator|+
literal|0xfd469501
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|8
index|]
operator|+
literal|0x698098d8
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|9
index|]
operator|+
literal|0x8b44f7af
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|10
index|]
operator|+
literal|0xffff5bb1
argument_list|,
literal|17
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|11
index|]
operator|+
literal|0x895cd7be
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|12
index|]
operator|+
literal|0x6b901122
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|13
index|]
operator|+
literal|0xfd987193
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|14
index|]
operator|+
literal|0xa679438e
argument_list|,
literal|17
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F1
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|15
index|]
operator|+
literal|0x49b40821
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|1
index|]
operator|+
literal|0xf61e2562
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|6
index|]
operator|+
literal|0xc040b340
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|11
index|]
operator|+
literal|0x265e5a51
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|0
index|]
operator|+
literal|0xe9b6c7aa
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|5
index|]
operator|+
literal|0xd62f105d
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|10
index|]
operator|+
literal|0x02441453
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|15
index|]
operator|+
literal|0xd8a1e681
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|4
index|]
operator|+
literal|0xe7d3fbc8
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|9
index|]
operator|+
literal|0x21e1cde6
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|14
index|]
operator|+
literal|0xc33707d6
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|3
index|]
operator|+
literal|0xf4d50d87
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|8
index|]
operator|+
literal|0x455a14ed
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|13
index|]
operator|+
literal|0xa9e3e905
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|2
index|]
operator|+
literal|0xfcefa3f8
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|7
index|]
operator|+
literal|0x676f02d9
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F2
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|12
index|]
operator|+
literal|0x8d2a4c8a
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|5
index|]
operator|+
literal|0xfffa3942
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|8
index|]
operator|+
literal|0x8771f681
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|11
index|]
operator|+
literal|0x6d9d6122
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|14
index|]
operator|+
literal|0xfde5380c
argument_list|,
literal|23
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|1
index|]
operator|+
literal|0xa4beea44
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|4
index|]
operator|+
literal|0x4bdecfa9
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|7
index|]
operator|+
literal|0xf6bb4b60
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|10
index|]
operator|+
literal|0xbebfbc70
argument_list|,
literal|23
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|13
index|]
operator|+
literal|0x289b7ec6
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|0
index|]
operator|+
literal|0xeaa127fa
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|3
index|]
operator|+
literal|0xd4ef3085
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|6
index|]
operator|+
literal|0x04881d05
argument_list|,
literal|23
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|9
index|]
operator|+
literal|0xd9d4d039
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|12
index|]
operator|+
literal|0xe6db99e5
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|15
index|]
operator|+
literal|0x1fa27cf8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F3
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|2
index|]
operator|+
literal|0xc4ac5665
argument_list|,
literal|23
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|0
index|]
operator|+
literal|0xf4292244
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|7
index|]
operator|+
literal|0x432aff97
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|14
index|]
operator|+
literal|0xab9423a7
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|5
index|]
operator|+
literal|0xfc93a039
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|12
index|]
operator|+
literal|0x655b59c3
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|3
index|]
operator|+
literal|0x8f0ccc92
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|10
index|]
operator|+
literal|0xffeff47d
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|1
index|]
operator|+
literal|0x85845dd1
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|8
index|]
operator|+
literal|0x6fa87e4f
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|15
index|]
operator|+
literal|0xfe2ce6e0
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|6
index|]
operator|+
literal|0xa3014314
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|13
index|]
operator|+
literal|0x4e0811a1
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|in
index|[
literal|4
index|]
operator|+
literal|0xf7537e82
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|in
index|[
literal|11
index|]
operator|+
literal|0xbd3af235
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|in
index|[
literal|2
index|]
operator|+
literal|0x2ad7d2bb
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|MD5STEP
argument_list|(
name|F4
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|a
argument_list|,
name|in
index|[
literal|9
index|]
operator|+
literal|0xeb86d391
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|buf
index|[
literal|0
index|]
operator|+=
name|a
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|+=
name|b
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|+=
name|c
expr_stmt|;
name|buf
index|[
literal|3
index|]
operator|+=
name|d
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
