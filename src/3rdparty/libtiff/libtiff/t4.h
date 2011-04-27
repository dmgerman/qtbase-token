begin_unit
begin_comment
comment|/* $Id: t4.h,v 1.1.1.1 1999/07/27 21:50:27 mike Exp $ */
end_comment
begin_comment
comment|/*  * Copyright (c) 1988-1997 Sam Leffler  * Copyright (c) 1991-1997 Silicon Graphics, Inc.  *  * Permission to use, copy, modify, distribute, and sell this software and   * its documentation for any purpose is hereby granted without fee, provided  * that (i) the above copyright notices and this permission notice appear in  * all copies of the software and related documentation, and (ii) the names of  * Sam Leffler and Silicon Graphics may not be used in any advertising or  * publicity relating to the software without the specific, prior written  * permission of Sam Leffler and Silicon Graphics.  *   * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,   * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY   * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.    *   * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF   * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE   * OF THIS SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_T4_
end_ifndef
begin_define
DECL|macro|_T4_
define|#
directive|define
name|_T4_
end_define
begin_comment
comment|/*  * CCITT T.4 1D Huffman runlength codes and  * related definitions.  Given the small sizes  * of these tables it does not seem  * worthwhile to make code& length 8 bits.  */
end_comment
begin_typedef
DECL|struct|tableentry
typedef|typedef
struct|struct
name|tableentry
block|{
DECL|member|length
name|unsigned
name|short
name|length
decl_stmt|;
comment|/* bit length of g3 code */
DECL|member|code
name|unsigned
name|short
name|code
decl_stmt|;
comment|/* g3 code */
DECL|member|runlen
name|short
name|runlen
decl_stmt|;
comment|/* run length in bits */
block|}
DECL|typedef|tableentry
name|tableentry
typedef|;
end_typedef
begin_define
DECL|macro|EOL
define|#
directive|define
name|EOL
value|0x001
end_define
begin_comment
DECL|macro|EOL
comment|/* EOL code value - 0000 0000 0000 1 */
end_comment
begin_comment
comment|/* status values returned instead of a run length */
end_comment
begin_define
DECL|macro|G3CODE_EOL
define|#
directive|define
name|G3CODE_EOL
value|-1
end_define
begin_comment
DECL|macro|G3CODE_EOL
comment|/* NB: ACT_EOL - ACT_WRUNT */
end_comment
begin_define
DECL|macro|G3CODE_INVALID
define|#
directive|define
name|G3CODE_INVALID
value|-2
end_define
begin_comment
DECL|macro|G3CODE_INVALID
comment|/* NB: ACT_INVALID - ACT_WRUNT */
end_comment
begin_define
DECL|macro|G3CODE_EOF
define|#
directive|define
name|G3CODE_EOF
value|-3
end_define
begin_comment
DECL|macro|G3CODE_EOF
comment|/* end of input data */
end_comment
begin_define
DECL|macro|G3CODE_INCOMP
define|#
directive|define
name|G3CODE_INCOMP
value|-4
end_define
begin_comment
DECL|macro|G3CODE_INCOMP
comment|/* incomplete run code */
end_comment
begin_comment
comment|/*  * Note that these tables are ordered such that the  * index into the table is known to be either the  * run length, or (run length / 64) + a fixed offset.  *  * NB: The G3CODE_INVALID entries are only used  *     during state generation (see mkg3states.c).  */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|G3CODES
end_ifdef
begin_decl_stmt
DECL|variable|TIFFFaxWhiteCodes
specifier|const
name|tableentry
name|TIFFFaxWhiteCodes
index|[]
init|=
block|{
block|{
literal|8
block|,
literal|0x35
block|,
literal|0
block|}
block|,
comment|/* 0011 0101 */
block|{
literal|6
block|,
literal|0x7
block|,
literal|1
block|}
block|,
comment|/* 0001 11 */
block|{
literal|4
block|,
literal|0x7
block|,
literal|2
block|}
block|,
comment|/* 0111 */
block|{
literal|4
block|,
literal|0x8
block|,
literal|3
block|}
block|,
comment|/* 1000 */
block|{
literal|4
block|,
literal|0xB
block|,
literal|4
block|}
block|,
comment|/* 1011 */
block|{
literal|4
block|,
literal|0xC
block|,
literal|5
block|}
block|,
comment|/* 1100 */
block|{
literal|4
block|,
literal|0xE
block|,
literal|6
block|}
block|,
comment|/* 1110 */
block|{
literal|4
block|,
literal|0xF
block|,
literal|7
block|}
block|,
comment|/* 1111 */
block|{
literal|5
block|,
literal|0x13
block|,
literal|8
block|}
block|,
comment|/* 1001 1 */
block|{
literal|5
block|,
literal|0x14
block|,
literal|9
block|}
block|,
comment|/* 1010 0 */
block|{
literal|5
block|,
literal|0x7
block|,
literal|10
block|}
block|,
comment|/* 0011 1 */
block|{
literal|5
block|,
literal|0x8
block|,
literal|11
block|}
block|,
comment|/* 0100 0 */
block|{
literal|6
block|,
literal|0x8
block|,
literal|12
block|}
block|,
comment|/* 0010 00 */
block|{
literal|6
block|,
literal|0x3
block|,
literal|13
block|}
block|,
comment|/* 0000 11 */
block|{
literal|6
block|,
literal|0x34
block|,
literal|14
block|}
block|,
comment|/* 1101 00 */
block|{
literal|6
block|,
literal|0x35
block|,
literal|15
block|}
block|,
comment|/* 1101 01 */
block|{
literal|6
block|,
literal|0x2A
block|,
literal|16
block|}
block|,
comment|/* 1010 10 */
block|{
literal|6
block|,
literal|0x2B
block|,
literal|17
block|}
block|,
comment|/* 1010 11 */
block|{
literal|7
block|,
literal|0x27
block|,
literal|18
block|}
block|,
comment|/* 0100 111 */
block|{
literal|7
block|,
literal|0xC
block|,
literal|19
block|}
block|,
comment|/* 0001 100 */
block|{
literal|7
block|,
literal|0x8
block|,
literal|20
block|}
block|,
comment|/* 0001 000 */
block|{
literal|7
block|,
literal|0x17
block|,
literal|21
block|}
block|,
comment|/* 0010 111 */
block|{
literal|7
block|,
literal|0x3
block|,
literal|22
block|}
block|,
comment|/* 0000 011 */
block|{
literal|7
block|,
literal|0x4
block|,
literal|23
block|}
block|,
comment|/* 0000 100 */
block|{
literal|7
block|,
literal|0x28
block|,
literal|24
block|}
block|,
comment|/* 0101 000 */
block|{
literal|7
block|,
literal|0x2B
block|,
literal|25
block|}
block|,
comment|/* 0101 011 */
block|{
literal|7
block|,
literal|0x13
block|,
literal|26
block|}
block|,
comment|/* 0010 011 */
block|{
literal|7
block|,
literal|0x24
block|,
literal|27
block|}
block|,
comment|/* 0100 100 */
block|{
literal|7
block|,
literal|0x18
block|,
literal|28
block|}
block|,
comment|/* 0011 000 */
block|{
literal|8
block|,
literal|0x2
block|,
literal|29
block|}
block|,
comment|/* 0000 0010 */
block|{
literal|8
block|,
literal|0x3
block|,
literal|30
block|}
block|,
comment|/* 0000 0011 */
block|{
literal|8
block|,
literal|0x1A
block|,
literal|31
block|}
block|,
comment|/* 0001 1010 */
block|{
literal|8
block|,
literal|0x1B
block|,
literal|32
block|}
block|,
comment|/* 0001 1011 */
block|{
literal|8
block|,
literal|0x12
block|,
literal|33
block|}
block|,
comment|/* 0001 0010 */
block|{
literal|8
block|,
literal|0x13
block|,
literal|34
block|}
block|,
comment|/* 0001 0011 */
block|{
literal|8
block|,
literal|0x14
block|,
literal|35
block|}
block|,
comment|/* 0001 0100 */
block|{
literal|8
block|,
literal|0x15
block|,
literal|36
block|}
block|,
comment|/* 0001 0101 */
block|{
literal|8
block|,
literal|0x16
block|,
literal|37
block|}
block|,
comment|/* 0001 0110 */
block|{
literal|8
block|,
literal|0x17
block|,
literal|38
block|}
block|,
comment|/* 0001 0111 */
block|{
literal|8
block|,
literal|0x28
block|,
literal|39
block|}
block|,
comment|/* 0010 1000 */
block|{
literal|8
block|,
literal|0x29
block|,
literal|40
block|}
block|,
comment|/* 0010 1001 */
block|{
literal|8
block|,
literal|0x2A
block|,
literal|41
block|}
block|,
comment|/* 0010 1010 */
block|{
literal|8
block|,
literal|0x2B
block|,
literal|42
block|}
block|,
comment|/* 0010 1011 */
block|{
literal|8
block|,
literal|0x2C
block|,
literal|43
block|}
block|,
comment|/* 0010 1100 */
block|{
literal|8
block|,
literal|0x2D
block|,
literal|44
block|}
block|,
comment|/* 0010 1101 */
block|{
literal|8
block|,
literal|0x4
block|,
literal|45
block|}
block|,
comment|/* 0000 0100 */
block|{
literal|8
block|,
literal|0x5
block|,
literal|46
block|}
block|,
comment|/* 0000 0101 */
block|{
literal|8
block|,
literal|0xA
block|,
literal|47
block|}
block|,
comment|/* 0000 1010 */
block|{
literal|8
block|,
literal|0xB
block|,
literal|48
block|}
block|,
comment|/* 0000 1011 */
block|{
literal|8
block|,
literal|0x52
block|,
literal|49
block|}
block|,
comment|/* 0101 0010 */
block|{
literal|8
block|,
literal|0x53
block|,
literal|50
block|}
block|,
comment|/* 0101 0011 */
block|{
literal|8
block|,
literal|0x54
block|,
literal|51
block|}
block|,
comment|/* 0101 0100 */
block|{
literal|8
block|,
literal|0x55
block|,
literal|52
block|}
block|,
comment|/* 0101 0101 */
block|{
literal|8
block|,
literal|0x24
block|,
literal|53
block|}
block|,
comment|/* 0010 0100 */
block|{
literal|8
block|,
literal|0x25
block|,
literal|54
block|}
block|,
comment|/* 0010 0101 */
block|{
literal|8
block|,
literal|0x58
block|,
literal|55
block|}
block|,
comment|/* 0101 1000 */
block|{
literal|8
block|,
literal|0x59
block|,
literal|56
block|}
block|,
comment|/* 0101 1001 */
block|{
literal|8
block|,
literal|0x5A
block|,
literal|57
block|}
block|,
comment|/* 0101 1010 */
block|{
literal|8
block|,
literal|0x5B
block|,
literal|58
block|}
block|,
comment|/* 0101 1011 */
block|{
literal|8
block|,
literal|0x4A
block|,
literal|59
block|}
block|,
comment|/* 0100 1010 */
block|{
literal|8
block|,
literal|0x4B
block|,
literal|60
block|}
block|,
comment|/* 0100 1011 */
block|{
literal|8
block|,
literal|0x32
block|,
literal|61
block|}
block|,
comment|/* 0011 0010 */
block|{
literal|8
block|,
literal|0x33
block|,
literal|62
block|}
block|,
comment|/* 0011 0011 */
block|{
literal|8
block|,
literal|0x34
block|,
literal|63
block|}
block|,
comment|/* 0011 0100 */
block|{
literal|5
block|,
literal|0x1B
block|,
literal|64
block|}
block|,
comment|/* 1101 1 */
block|{
literal|5
block|,
literal|0x12
block|,
literal|128
block|}
block|,
comment|/* 1001 0 */
block|{
literal|6
block|,
literal|0x17
block|,
literal|192
block|}
block|,
comment|/* 0101 11 */
block|{
literal|7
block|,
literal|0x37
block|,
literal|256
block|}
block|,
comment|/* 0110 111 */
block|{
literal|8
block|,
literal|0x36
block|,
literal|320
block|}
block|,
comment|/* 0011 0110 */
block|{
literal|8
block|,
literal|0x37
block|,
literal|384
block|}
block|,
comment|/* 0011 0111 */
block|{
literal|8
block|,
literal|0x64
block|,
literal|448
block|}
block|,
comment|/* 0110 0100 */
block|{
literal|8
block|,
literal|0x65
block|,
literal|512
block|}
block|,
comment|/* 0110 0101 */
block|{
literal|8
block|,
literal|0x68
block|,
literal|576
block|}
block|,
comment|/* 0110 1000 */
block|{
literal|8
block|,
literal|0x67
block|,
literal|640
block|}
block|,
comment|/* 0110 0111 */
block|{
literal|9
block|,
literal|0xCC
block|,
literal|704
block|}
block|,
comment|/* 0110 0110 0 */
block|{
literal|9
block|,
literal|0xCD
block|,
literal|768
block|}
block|,
comment|/* 0110 0110 1 */
block|{
literal|9
block|,
literal|0xD2
block|,
literal|832
block|}
block|,
comment|/* 0110 1001 0 */
block|{
literal|9
block|,
literal|0xD3
block|,
literal|896
block|}
block|,
comment|/* 0110 1001 1 */
block|{
literal|9
block|,
literal|0xD4
block|,
literal|960
block|}
block|,
comment|/* 0110 1010 0 */
block|{
literal|9
block|,
literal|0xD5
block|,
literal|1024
block|}
block|,
comment|/* 0110 1010 1 */
block|{
literal|9
block|,
literal|0xD6
block|,
literal|1088
block|}
block|,
comment|/* 0110 1011 0 */
block|{
literal|9
block|,
literal|0xD7
block|,
literal|1152
block|}
block|,
comment|/* 0110 1011 1 */
block|{
literal|9
block|,
literal|0xD8
block|,
literal|1216
block|}
block|,
comment|/* 0110 1100 0 */
block|{
literal|9
block|,
literal|0xD9
block|,
literal|1280
block|}
block|,
comment|/* 0110 1100 1 */
block|{
literal|9
block|,
literal|0xDA
block|,
literal|1344
block|}
block|,
comment|/* 0110 1101 0 */
block|{
literal|9
block|,
literal|0xDB
block|,
literal|1408
block|}
block|,
comment|/* 0110 1101 1 */
block|{
literal|9
block|,
literal|0x98
block|,
literal|1472
block|}
block|,
comment|/* 0100 1100 0 */
block|{
literal|9
block|,
literal|0x99
block|,
literal|1536
block|}
block|,
comment|/* 0100 1100 1 */
block|{
literal|9
block|,
literal|0x9A
block|,
literal|1600
block|}
block|,
comment|/* 0100 1101 0 */
block|{
literal|6
block|,
literal|0x18
block|,
literal|1664
block|}
block|,
comment|/* 0110 00 */
block|{
literal|9
block|,
literal|0x9B
block|,
literal|1728
block|}
block|,
comment|/* 0100 1101 1 */
block|{
literal|11
block|,
literal|0x8
block|,
literal|1792
block|}
block|,
comment|/* 0000 0001 000 */
block|{
literal|11
block|,
literal|0xC
block|,
literal|1856
block|}
block|,
comment|/* 0000 0001 100 */
block|{
literal|11
block|,
literal|0xD
block|,
literal|1920
block|}
block|,
comment|/* 0000 0001 101 */
block|{
literal|12
block|,
literal|0x12
block|,
literal|1984
block|}
block|,
comment|/* 0000 0001 0010 */
block|{
literal|12
block|,
literal|0x13
block|,
literal|2048
block|}
block|,
comment|/* 0000 0001 0011 */
block|{
literal|12
block|,
literal|0x14
block|,
literal|2112
block|}
block|,
comment|/* 0000 0001 0100 */
block|{
literal|12
block|,
literal|0x15
block|,
literal|2176
block|}
block|,
comment|/* 0000 0001 0101 */
block|{
literal|12
block|,
literal|0x16
block|,
literal|2240
block|}
block|,
comment|/* 0000 0001 0110 */
block|{
literal|12
block|,
literal|0x17
block|,
literal|2304
block|}
block|,
comment|/* 0000 0001 0111 */
block|{
literal|12
block|,
literal|0x1C
block|,
literal|2368
block|}
block|,
comment|/* 0000 0001 1100 */
block|{
literal|12
block|,
literal|0x1D
block|,
literal|2432
block|}
block|,
comment|/* 0000 0001 1101 */
block|{
literal|12
block|,
literal|0x1E
block|,
literal|2496
block|}
block|,
comment|/* 0000 0001 1110 */
block|{
literal|12
block|,
literal|0x1F
block|,
literal|2560
block|}
block|,
comment|/* 0000 0001 1111 */
block|{
literal|12
block|,
literal|0x1
block|,
name|G3CODE_EOL
block|}
block|,
comment|/* 0000 0000 0001 */
block|{
literal|9
block|,
literal|0x1
block|,
name|G3CODE_INVALID
block|}
block|,
comment|/* 0000 0000 1 */
block|{
literal|10
block|,
literal|0x1
block|,
name|G3CODE_INVALID
block|}
block|,
comment|/* 0000 0000 01 */
block|{
literal|11
block|,
literal|0x1
block|,
name|G3CODE_INVALID
block|}
block|,
comment|/* 0000 0000 001 */
block|{
literal|12
block|,
literal|0x0
block|,
name|G3CODE_INVALID
block|}
block|,
comment|/* 0000 0000 0000 */
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TIFFFaxBlackCodes
specifier|const
name|tableentry
name|TIFFFaxBlackCodes
index|[]
init|=
block|{
block|{
literal|10
block|,
literal|0x37
block|,
literal|0
block|}
block|,
comment|/* 0000 1101 11 */
block|{
literal|3
block|,
literal|0x2
block|,
literal|1
block|}
block|,
comment|/* 010 */
block|{
literal|2
block|,
literal|0x3
block|,
literal|2
block|}
block|,
comment|/* 11 */
block|{
literal|2
block|,
literal|0x2
block|,
literal|3
block|}
block|,
comment|/* 10 */
block|{
literal|3
block|,
literal|0x3
block|,
literal|4
block|}
block|,
comment|/* 011 */
block|{
literal|4
block|,
literal|0x3
block|,
literal|5
block|}
block|,
comment|/* 0011 */
block|{
literal|4
block|,
literal|0x2
block|,
literal|6
block|}
block|,
comment|/* 0010 */
block|{
literal|5
block|,
literal|0x3
block|,
literal|7
block|}
block|,
comment|/* 0001 1 */
block|{
literal|6
block|,
literal|0x5
block|,
literal|8
block|}
block|,
comment|/* 0001 01 */
block|{
literal|6
block|,
literal|0x4
block|,
literal|9
block|}
block|,
comment|/* 0001 00 */
block|{
literal|7
block|,
literal|0x4
block|,
literal|10
block|}
block|,
comment|/* 0000 100 */
block|{
literal|7
block|,
literal|0x5
block|,
literal|11
block|}
block|,
comment|/* 0000 101 */
block|{
literal|7
block|,
literal|0x7
block|,
literal|12
block|}
block|,
comment|/* 0000 111 */
block|{
literal|8
block|,
literal|0x4
block|,
literal|13
block|}
block|,
comment|/* 0000 0100 */
block|{
literal|8
block|,
literal|0x7
block|,
literal|14
block|}
block|,
comment|/* 0000 0111 */
block|{
literal|9
block|,
literal|0x18
block|,
literal|15
block|}
block|,
comment|/* 0000 1100 0 */
block|{
literal|10
block|,
literal|0x17
block|,
literal|16
block|}
block|,
comment|/* 0000 0101 11 */
block|{
literal|10
block|,
literal|0x18
block|,
literal|17
block|}
block|,
comment|/* 0000 0110 00 */
block|{
literal|10
block|,
literal|0x8
block|,
literal|18
block|}
block|,
comment|/* 0000 0010 00 */
block|{
literal|11
block|,
literal|0x67
block|,
literal|19
block|}
block|,
comment|/* 0000 1100 111 */
block|{
literal|11
block|,
literal|0x68
block|,
literal|20
block|}
block|,
comment|/* 0000 1101 000 */
block|{
literal|11
block|,
literal|0x6C
block|,
literal|21
block|}
block|,
comment|/* 0000 1101 100 */
block|{
literal|11
block|,
literal|0x37
block|,
literal|22
block|}
block|,
comment|/* 0000 0110 111 */
block|{
literal|11
block|,
literal|0x28
block|,
literal|23
block|}
block|,
comment|/* 0000 0101 000 */
block|{
literal|11
block|,
literal|0x17
block|,
literal|24
block|}
block|,
comment|/* 0000 0010 111 */
block|{
literal|11
block|,
literal|0x18
block|,
literal|25
block|}
block|,
comment|/* 0000 0011 000 */
block|{
literal|12
block|,
literal|0xCA
block|,
literal|26
block|}
block|,
comment|/* 0000 1100 1010 */
block|{
literal|12
block|,
literal|0xCB
block|,
literal|27
block|}
block|,
comment|/* 0000 1100 1011 */
block|{
literal|12
block|,
literal|0xCC
block|,
literal|28
block|}
block|,
comment|/* 0000 1100 1100 */
block|{
literal|12
block|,
literal|0xCD
block|,
literal|29
block|}
block|,
comment|/* 0000 1100 1101 */
block|{
literal|12
block|,
literal|0x68
block|,
literal|30
block|}
block|,
comment|/* 0000 0110 1000 */
block|{
literal|12
block|,
literal|0x69
block|,
literal|31
block|}
block|,
comment|/* 0000 0110 1001 */
block|{
literal|12
block|,
literal|0x6A
block|,
literal|32
block|}
block|,
comment|/* 0000 0110 1010 */
block|{
literal|12
block|,
literal|0x6B
block|,
literal|33
block|}
block|,
comment|/* 0000 0110 1011 */
block|{
literal|12
block|,
literal|0xD2
block|,
literal|34
block|}
block|,
comment|/* 0000 1101 0010 */
block|{
literal|12
block|,
literal|0xD3
block|,
literal|35
block|}
block|,
comment|/* 0000 1101 0011 */
block|{
literal|12
block|,
literal|0xD4
block|,
literal|36
block|}
block|,
comment|/* 0000 1101 0100 */
block|{
literal|12
block|,
literal|0xD5
block|,
literal|37
block|}
block|,
comment|/* 0000 1101 0101 */
block|{
literal|12
block|,
literal|0xD6
block|,
literal|38
block|}
block|,
comment|/* 0000 1101 0110 */
block|{
literal|12
block|,
literal|0xD7
block|,
literal|39
block|}
block|,
comment|/* 0000 1101 0111 */
block|{
literal|12
block|,
literal|0x6C
block|,
literal|40
block|}
block|,
comment|/* 0000 0110 1100 */
block|{
literal|12
block|,
literal|0x6D
block|,
literal|41
block|}
block|,
comment|/* 0000 0110 1101 */
block|{
literal|12
block|,
literal|0xDA
block|,
literal|42
block|}
block|,
comment|/* 0000 1101 1010 */
block|{
literal|12
block|,
literal|0xDB
block|,
literal|43
block|}
block|,
comment|/* 0000 1101 1011 */
block|{
literal|12
block|,
literal|0x54
block|,
literal|44
block|}
block|,
comment|/* 0000 0101 0100 */
block|{
literal|12
block|,
literal|0x55
block|,
literal|45
block|}
block|,
comment|/* 0000 0101 0101 */
block|{
literal|12
block|,
literal|0x56
block|,
literal|46
block|}
block|,
comment|/* 0000 0101 0110 */
block|{
literal|12
block|,
literal|0x57
block|,
literal|47
block|}
block|,
comment|/* 0000 0101 0111 */
block|{
literal|12
block|,
literal|0x64
block|,
literal|48
block|}
block|,
comment|/* 0000 0110 0100 */
block|{
literal|12
block|,
literal|0x65
block|,
literal|49
block|}
block|,
comment|/* 0000 0110 0101 */
block|{
literal|12
block|,
literal|0x52
block|,
literal|50
block|}
block|,
comment|/* 0000 0101 0010 */
block|{
literal|12
block|,
literal|0x53
block|,
literal|51
block|}
block|,
comment|/* 0000 0101 0011 */
block|{
literal|12
block|,
literal|0x24
block|,
literal|52
block|}
block|,
comment|/* 0000 0010 0100 */
block|{
literal|12
block|,
literal|0x37
block|,
literal|53
block|}
block|,
comment|/* 0000 0011 0111 */
block|{
literal|12
block|,
literal|0x38
block|,
literal|54
block|}
block|,
comment|/* 0000 0011 1000 */
block|{
literal|12
block|,
literal|0x27
block|,
literal|55
block|}
block|,
comment|/* 0000 0010 0111 */
block|{
literal|12
block|,
literal|0x28
block|,
literal|56
block|}
block|,
comment|/* 0000 0010 1000 */
block|{
literal|12
block|,
literal|0x58
block|,
literal|57
block|}
block|,
comment|/* 0000 0101 1000 */
block|{
literal|12
block|,
literal|0x59
block|,
literal|58
block|}
block|,
comment|/* 0000 0101 1001 */
block|{
literal|12
block|,
literal|0x2B
block|,
literal|59
block|}
block|,
comment|/* 0000 0010 1011 */
block|{
literal|12
block|,
literal|0x2C
block|,
literal|60
block|}
block|,
comment|/* 0000 0010 1100 */
block|{
literal|12
block|,
literal|0x5A
block|,
literal|61
block|}
block|,
comment|/* 0000 0101 1010 */
block|{
literal|12
block|,
literal|0x66
block|,
literal|62
block|}
block|,
comment|/* 0000 0110 0110 */
block|{
literal|12
block|,
literal|0x67
block|,
literal|63
block|}
block|,
comment|/* 0000 0110 0111 */
block|{
literal|10
block|,
literal|0xF
block|,
literal|64
block|}
block|,
comment|/* 0000 0011 11 */
block|{
literal|12
block|,
literal|0xC8
block|,
literal|128
block|}
block|,
comment|/* 0000 1100 1000 */
block|{
literal|12
block|,
literal|0xC9
block|,
literal|192
block|}
block|,
comment|/* 0000 1100 1001 */
block|{
literal|12
block|,
literal|0x5B
block|,
literal|256
block|}
block|,
comment|/* 0000 0101 1011 */
block|{
literal|12
block|,
literal|0x33
block|,
literal|320
block|}
block|,
comment|/* 0000 0011 0011 */
block|{
literal|12
block|,
literal|0x34
block|,
literal|384
block|}
block|,
comment|/* 0000 0011 0100 */
block|{
literal|12
block|,
literal|0x35
block|,
literal|448
block|}
block|,
comment|/* 0000 0011 0101 */
block|{
literal|13
block|,
literal|0x6C
block|,
literal|512
block|}
block|,
comment|/* 0000 0011 0110 0 */
block|{
literal|13
block|,
literal|0x6D
block|,
literal|576
block|}
block|,
comment|/* 0000 0011 0110 1 */
block|{
literal|13
block|,
literal|0x4A
block|,
literal|640
block|}
block|,
comment|/* 0000 0010 0101 0 */
block|{
literal|13
block|,
literal|0x4B
block|,
literal|704
block|}
block|,
comment|/* 0000 0010 0101 1 */
block|{
literal|13
block|,
literal|0x4C
block|,
literal|768
block|}
block|,
comment|/* 0000 0010 0110 0 */
block|{
literal|13
block|,
literal|0x4D
block|,
literal|832
block|}
block|,
comment|/* 0000 0010 0110 1 */
block|{
literal|13
block|,
literal|0x72
block|,
literal|896
block|}
block|,
comment|/* 0000 0011 1001 0 */
block|{
literal|13
block|,
literal|0x73
block|,
literal|960
block|}
block|,
comment|/* 0000 0011 1001 1 */
block|{
literal|13
block|,
literal|0x74
block|,
literal|1024
block|}
block|,
comment|/* 0000 0011 1010 0 */
block|{
literal|13
block|,
literal|0x75
block|,
literal|1088
block|}
block|,
comment|/* 0000 0011 1010 1 */
block|{
literal|13
block|,
literal|0x76
block|,
literal|1152
block|}
block|,
comment|/* 0000 0011 1011 0 */
block|{
literal|13
block|,
literal|0x77
block|,
literal|1216
block|}
block|,
comment|/* 0000 0011 1011 1 */
block|{
literal|13
block|,
literal|0x52
block|,
literal|1280
block|}
block|,
comment|/* 0000 0010 1001 0 */
block|{
literal|13
block|,
literal|0x53
block|,
literal|1344
block|}
block|,
comment|/* 0000 0010 1001 1 */
block|{
literal|13
block|,
literal|0x54
block|,
literal|1408
block|}
block|,
comment|/* 0000 0010 1010 0 */
block|{
literal|13
block|,
literal|0x55
block|,
literal|1472
block|}
block|,
comment|/* 0000 0010 1010 1 */
block|{
literal|13
block|,
literal|0x5A
block|,
literal|1536
block|}
block|,
comment|/* 0000 0010 1101 0 */
block|{
literal|13
block|,
literal|0x5B
block|,
literal|1600
block|}
block|,
comment|/* 0000 0010 1101 1 */
block|{
literal|13
block|,
literal|0x64
block|,
literal|1664
block|}
block|,
comment|/* 0000 0011 0010 0 */
block|{
literal|13
block|,
literal|0x65
block|,
literal|1728
block|}
block|,
comment|/* 0000 0011 0010 1 */
block|{
literal|11
block|,
literal|0x8
block|,
literal|1792
block|}
block|,
comment|/* 0000 0001 000 */
block|{
literal|11
block|,
literal|0xC
block|,
literal|1856
block|}
block|,
comment|/* 0000 0001 100 */
block|{
literal|11
block|,
literal|0xD
block|,
literal|1920
block|}
block|,
comment|/* 0000 0001 101 */
block|{
literal|12
block|,
literal|0x12
block|,
literal|1984
block|}
block|,
comment|/* 0000 0001 0010 */
block|{
literal|12
block|,
literal|0x13
block|,
literal|2048
block|}
block|,
comment|/* 0000 0001 0011 */
block|{
literal|12
block|,
literal|0x14
block|,
literal|2112
block|}
block|,
comment|/* 0000 0001 0100 */
block|{
literal|12
block|,
literal|0x15
block|,
literal|2176
block|}
block|,
comment|/* 0000 0001 0101 */
block|{
literal|12
block|,
literal|0x16
block|,
literal|2240
block|}
block|,
comment|/* 0000 0001 0110 */
block|{
literal|12
block|,
literal|0x17
block|,
literal|2304
block|}
block|,
comment|/* 0000 0001 0111 */
block|{
literal|12
block|,
literal|0x1C
block|,
literal|2368
block|}
block|,
comment|/* 0000 0001 1100 */
block|{
literal|12
block|,
literal|0x1D
block|,
literal|2432
block|}
block|,
comment|/* 0000 0001 1101 */
block|{
literal|12
block|,
literal|0x1E
block|,
literal|2496
block|}
block|,
comment|/* 0000 0001 1110 */
block|{
literal|12
block|,
literal|0x1F
block|,
literal|2560
block|}
block|,
comment|/* 0000 0001 1111 */
block|{
literal|12
block|,
literal|0x1
block|,
name|G3CODE_EOL
block|}
block|,
comment|/* 0000 0000 0001 */
block|{
literal|9
block|,
literal|0x1
block|,
name|G3CODE_INVALID
block|}
block|,
comment|/* 0000 0000 1 */
block|{
literal|10
block|,
literal|0x1
block|,
name|G3CODE_INVALID
block|}
block|,
comment|/* 0000 0000 01 */
block|{
literal|11
block|,
literal|0x1
block|,
name|G3CODE_INVALID
block|}
block|,
comment|/* 0000 0000 001 */
block|{
literal|12
block|,
literal|0x0
block|,
name|G3CODE_INVALID
block|}
block|,
comment|/* 0000 0000 0000 */
block|}
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
specifier|extern
specifier|const
name|tableentry
name|TIFFFaxWhiteCodes
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|tableentry
name|TIFFFaxBlackCodes
index|[]
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _T4_ */
end_comment
end_unit
