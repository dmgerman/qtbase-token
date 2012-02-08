begin_unit
begin_comment
comment|/*  * Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies)  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  */
end_comment
begin_include
include|#
directive|include
file|"harfbuzz-shaper.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-shaper-private.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-external.h"
end_include
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_define
DECL|macro|LIBTHAI_MAJOR
define|#
directive|define
name|LIBTHAI_MAJOR
value|0
end_define
begin_comment
comment|/*  * if libthai changed please update these codes too.  */
end_comment
begin_struct
DECL|struct|thcell_t
struct|struct
name|thcell_t
block|{
DECL|member|base
name|unsigned
name|char
name|base
decl_stmt|;
comment|/**< base character */
DECL|member|hilo
name|unsigned
name|char
name|hilo
decl_stmt|;
comment|/**< upper/lower vowel/diacritic */
DECL|member|top
name|unsigned
name|char
name|top
decl_stmt|;
comment|/**< top-level mark */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|th_brk_def
typedef|typedef
name|int
function_decl|(
modifier|*
name|th_brk_def
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|th_render_cell_tis_def
typedef|typedef
name|int
function_decl|(
modifier|*
name|th_render_cell_tis_def
function_decl|)
parameter_list|(
name|struct
name|thcell_t
name|cell
parameter_list|,
name|unsigned
name|char
name|res
index|[]
parameter_list|,
name|size_t
name|res_sz
parameter_list|,
name|int
name|is_decomp_am
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|th_render_cell_win_def
typedef|typedef
name|int
function_decl|(
modifier|*
name|th_render_cell_win_def
function_decl|)
parameter_list|(
name|struct
name|thcell_t
name|cell
parameter_list|,
name|unsigned
name|char
name|res
index|[]
parameter_list|,
name|size_t
name|res_sz
parameter_list|,
name|int
name|is_decomp_am
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|th_render_cell_mac_def
typedef|typedef
name|int
function_decl|(
modifier|*
name|th_render_cell_mac_def
function_decl|)
parameter_list|(
name|struct
name|thcell_t
name|cell
parameter_list|,
name|unsigned
name|char
name|res
index|[]
parameter_list|,
name|size_t
name|res_sz
parameter_list|,
name|int
name|is_decomp_am
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|th_next_cell_def
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|th_next_cell_def
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|thcell_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* libthai releated function handles */
end_comment
begin_decl_stmt
DECL|variable|th_brk
specifier|static
name|th_brk_def
name|th_brk
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|th_next_cell
specifier|static
name|th_next_cell_def
name|th_next_cell
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|th_render_cell_tis
specifier|static
name|th_render_cell_tis_def
name|th_render_cell_tis
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|th_render_cell_win
specifier|static
name|th_render_cell_win_def
name|th_render_cell_win
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|th_render_cell_mac
specifier|static
name|th_render_cell_mac_def
name|th_render_cell_mac
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|init_libthai
specifier|static
name|int
name|init_libthai
parameter_list|()
block|{
if|if
condition|(
operator|!
name|th_brk
operator|||
operator|!
name|th_next_cell
operator|||
operator|!
name|th_render_cell_tis
operator|||
operator|!
name|th_render_cell_win
operator|||
operator|!
name|th_render_cell_mac
condition|)
block|{
name|th_brk
operator|=
operator|(
name|th_brk_def
operator|)
name|HB_Library_Resolve
argument_list|(
literal|"thai"
argument_list|,
operator|(
name|int
operator|)
name|LIBTHAI_MAJOR
argument_list|,
literal|"th_brk"
argument_list|)
expr_stmt|;
name|th_next_cell
operator|=
operator|(
name|th_next_cell_def
operator|)
name|HB_Library_Resolve
argument_list|(
literal|"thai"
argument_list|,
name|LIBTHAI_MAJOR
argument_list|,
literal|"th_next_cell"
argument_list|)
expr_stmt|;
name|th_render_cell_tis
operator|=
operator|(
name|th_render_cell_tis_def
operator|)
name|HB_Library_Resolve
argument_list|(
literal|"thai"
argument_list|,
operator|(
name|int
operator|)
name|LIBTHAI_MAJOR
argument_list|,
literal|"th_render_cell_tis"
argument_list|)
expr_stmt|;
name|th_render_cell_win
operator|=
operator|(
name|th_render_cell_win_def
operator|)
name|HB_Library_Resolve
argument_list|(
literal|"thai"
argument_list|,
operator|(
name|int
operator|)
name|LIBTHAI_MAJOR
argument_list|,
literal|"th_render_cell_win"
argument_list|)
expr_stmt|;
name|th_render_cell_mac
operator|=
operator|(
name|th_render_cell_mac_def
operator|)
name|HB_Library_Resolve
argument_list|(
literal|"thai"
argument_list|,
operator|(
name|int
operator|)
name|LIBTHAI_MAJOR
argument_list|,
literal|"th_render_cell_mac"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|th_brk
operator|&&
name|th_next_cell
operator|&&
name|th_render_cell_tis
operator|&&
name|th_render_cell_win
operator|&&
name|th_render_cell_mac
condition|)
return|return
literal|1
return|;
else|else
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|to_tis620
specifier|static
name|void
name|to_tis620
parameter_list|(
specifier|const
name|HB_UChar16
modifier|*
name|string
parameter_list|,
name|hb_uint32
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|cstr
parameter_list|)
block|{
name|hb_uint32
name|i
decl_stmt|;
name|unsigned
name|char
modifier|*
name|result
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|cstr
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|string
index|[
name|i
index|]
operator|<=
literal|0xa0
condition|)
name|result
index|[
name|i
index|]
operator|=
operator|(
name|unsigned
name|char
operator|)
name|string
index|[
name|i
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|string
index|[
name|i
index|]
operator|>=
literal|0xe01
operator|&&
name|string
index|[
name|i
index|]
operator|<=
literal|0xe5b
condition|)
name|result
index|[
name|i
index|]
operator|=
call|(
name|unsigned
name|char
call|)
argument_list|(
name|string
index|[
name|i
index|]
operator|-
literal|0xe00
operator|+
literal|0xa0
argument_list|)
expr_stmt|;
else|else
name|result
index|[
name|i
index|]
operator|=
literal|'?'
expr_stmt|;
block|}
name|result
index|[
name|len
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  * ---------------------------------------------------------------------------  * Thai Shaper / Attributes  * ---------------------------------------------------------------------------  */
end_comment
begin_comment
comment|/*  * USe basic_features prepare for future adding.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NO_OPENTYPE
end_ifndef
begin_decl_stmt
DECL|variable|thai_features
specifier|static
specifier|const
name|HB_OpenTypeFeature
name|thai_features
index|[]
init|=
block|{
block|{
name|HB_MAKE_TAG
argument_list|(
literal|'c'
argument_list|,
literal|'c'
argument_list|,
literal|'m'
argument_list|,
literal|'p'
argument_list|)
block|,
name|CcmpProperty
block|}
block|,
block|{
name|HB_MAKE_TAG
argument_list|(
literal|'l'
argument_list|,
literal|'i'
argument_list|,
literal|'g'
argument_list|,
literal|'a'
argument_list|)
block|,
name|CcmpProperty
block|}
block|,
block|{
name|HB_MAKE_TAG
argument_list|(
literal|'c'
argument_list|,
literal|'l'
argument_list|,
literal|'i'
argument_list|,
literal|'g'
argument_list|)
block|,
name|CcmpProperty
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TIS-to-Unicode glyph maps for characters 0x80-0xff */
end_comment
begin_decl_stmt
DECL|variable|tis620_0
specifier|static
name|int
name|tis620_0
index|[
literal|128
index|]
init|=
block|{
comment|/**/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/**/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/**/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/**/
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x0020
block|,
literal|0x0e01
block|,
literal|0x0e02
block|,
literal|0x0e03
block|,
literal|0x0e04
block|,
literal|0x0e05
block|,
literal|0x0e06
block|,
literal|0x0e07
block|,
literal|0x0e08
block|,
literal|0x0e09
block|,
literal|0x0e0a
block|,
literal|0x0e0b
block|,
literal|0x0e0c
block|,
literal|0x0e0d
block|,
literal|0x0e0e
block|,
literal|0x0e0f
block|,
literal|0x0e10
block|,
literal|0x0e11
block|,
literal|0x0e12
block|,
literal|0x0e13
block|,
literal|0x0e14
block|,
literal|0x0e15
block|,
literal|0x0e16
block|,
literal|0x0e17
block|,
literal|0x0e18
block|,
literal|0x0e19
block|,
literal|0x0e1a
block|,
literal|0x0e1b
block|,
literal|0x0e1c
block|,
literal|0x0e1d
block|,
literal|0x0e1e
block|,
literal|0x0e1f
block|,
literal|0x0e20
block|,
literal|0x0e21
block|,
literal|0x0e22
block|,
literal|0x0e23
block|,
literal|0x0e24
block|,
literal|0x0e25
block|,
literal|0x0e26
block|,
literal|0x0e27
block|,
literal|0x0e28
block|,
literal|0x0e29
block|,
literal|0x0e2a
block|,
literal|0x0e2b
block|,
literal|0x0e2c
block|,
literal|0x0e2d
block|,
literal|0x0e2e
block|,
literal|0x0e2f
block|,
literal|0x0e30
block|,
literal|0x0e31
block|,
literal|0x0e32
block|,
literal|0x0e33
block|,
literal|0x0e34
block|,
literal|0x0e35
block|,
literal|0x0e36
block|,
literal|0x0e37
block|,
literal|0x0e38
block|,
literal|0x0e39
block|,
literal|0x0e3a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x0e3f
block|,
literal|0x0e40
block|,
literal|0x0e41
block|,
literal|0x0e42
block|,
literal|0x0e43
block|,
literal|0x0e44
block|,
literal|0x0e45
block|,
literal|0x0e46
block|,
literal|0x0e47
block|,
literal|0x0e48
block|,
literal|0x0e49
block|,
literal|0x0e4a
block|,
literal|0x0e4b
block|,
literal|0x0e4c
block|,
literal|0x0e4d
block|,
literal|0x0e4e
block|,
literal|0x0e4f
block|,
literal|0x0e50
block|,
literal|0x0e51
block|,
literal|0x0e52
block|,
literal|0x0e53
block|,
literal|0x0e54
block|,
literal|0x0e55
block|,
literal|0x0e56
block|,
literal|0x0e57
block|,
literal|0x0e58
block|,
literal|0x0e59
block|,
literal|0x0e5a
block|,
literal|0x0e5b
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|tis620_1
specifier|static
name|int
name|tis620_1
index|[
literal|128
index|]
init|=
block|{
literal|0xf89e
block|,
literal|0
block|,
literal|0
block|,
literal|0xf88c
block|,
literal|0xf88f
block|,
literal|0xf892
block|,
literal|0xf895
block|,
literal|0xf898
block|,
literal|0xf88b
block|,
literal|0xf88e
block|,
literal|0xf891
block|,
literal|0xf894
block|,
literal|0xf897
block|,
literal|0
block|,
literal|0
block|,
literal|0xf899
block|,
literal|0xf89a
block|,
literal|0
block|,
literal|0xf884
block|,
literal|0xf889
block|,
literal|0xf885
block|,
literal|0xf886
block|,
literal|0xf887
block|,
literal|0xf888
block|,
literal|0xf88a
block|,
literal|0xf88d
block|,
literal|0xf890
block|,
literal|0xf893
block|,
literal|0xf896
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/**/
literal|0
block|,
literal|0x0e01
block|,
literal|0x0e02
block|,
literal|0x0e03
block|,
literal|0x0e04
block|,
literal|0x0e05
block|,
literal|0x0e06
block|,
literal|0x0e07
block|,
literal|0x0e08
block|,
literal|0x0e09
block|,
literal|0x0e0a
block|,
literal|0x0e0b
block|,
literal|0x0e0c
block|,
literal|0x0e0d
block|,
literal|0x0e0e
block|,
literal|0x0e0f
block|,
literal|0x0e10
block|,
literal|0x0e11
block|,
literal|0x0e12
block|,
literal|0x0e13
block|,
literal|0x0e14
block|,
literal|0x0e15
block|,
literal|0x0e16
block|,
literal|0x0e17
block|,
literal|0x0e18
block|,
literal|0x0e19
block|,
literal|0x0e1a
block|,
literal|0x0e1b
block|,
literal|0x0e1c
block|,
literal|0x0e1d
block|,
literal|0x0e1e
block|,
literal|0x0e1f
block|,
literal|0x0e20
block|,
literal|0x0e21
block|,
literal|0x0e22
block|,
literal|0x0e23
block|,
literal|0x0e24
block|,
literal|0x0e25
block|,
literal|0x0e26
block|,
literal|0x0e27
block|,
literal|0x0e28
block|,
literal|0x0e29
block|,
literal|0x0e2a
block|,
literal|0x0e2b
block|,
literal|0x0e2c
block|,
literal|0x0e2d
block|,
literal|0x0e2e
block|,
literal|0x0e2f
block|,
literal|0x0e30
block|,
literal|0x0e31
block|,
literal|0x0e32
block|,
literal|0x0e33
block|,
literal|0x0e34
block|,
literal|0x0e35
block|,
literal|0x0e36
block|,
literal|0x0e37
block|,
literal|0x0e38
block|,
literal|0x0e39
block|,
literal|0x0e3a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x0e3f
block|,
literal|0x0e40
block|,
literal|0x0e41
block|,
literal|0x0e42
block|,
literal|0x0e43
block|,
literal|0x0e44
block|,
literal|0x0e45
block|,
literal|0x0e46
block|,
literal|0x0e47
block|,
literal|0x0e48
block|,
literal|0x0e49
block|,
literal|0x0e4a
block|,
literal|0x0e4b
block|,
literal|0x0e4c
block|,
literal|0x0e4d
block|,
literal|0
block|,
literal|0x0e4f
block|,
literal|0x0e50
block|,
literal|0x0e51
block|,
literal|0x0e52
block|,
literal|0x0e53
block|,
literal|0x0e54
block|,
literal|0x0e55
block|,
literal|0x0e56
block|,
literal|0x0e57
block|,
literal|0x0e58
block|,
literal|0x0e59
block|,
literal|0
block|,
literal|0
block|,
literal|0xf89b
block|,
literal|0xf89c
block|,
literal|0xf89d
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|tis620_2
specifier|static
name|int
name|tis620_2
index|[
literal|128
index|]
init|=
block|{
literal|0xf700
block|,
literal|0xf701
block|,
literal|0xf702
block|,
literal|0xf703
block|,
literal|0xf704
block|,
literal|0x2026
block|,
literal|0xf705
block|,
literal|0xf706
block|,
literal|0xf707
block|,
literal|0xf708
block|,
literal|0xf709
block|,
literal|0xf70a
block|,
literal|0xf70b
block|,
literal|0xf70c
block|,
literal|0xf70d
block|,
literal|0xf70e
block|,
literal|0xf70f
block|,
literal|0x2018
block|,
literal|0x2019
block|,
literal|0x201c
block|,
literal|0x201d
block|,
literal|0x2022
block|,
literal|0x2013
block|,
literal|0x2014
block|,
literal|0xf710
block|,
literal|0xf711
block|,
literal|0xf712
block|,
literal|0xf713
block|,
literal|0xf714
block|,
literal|0xf715
block|,
literal|0xf716
block|,
literal|0xf717
block|,
literal|0x00a0
block|,
literal|0x0e01
block|,
literal|0x0e02
block|,
literal|0x0e03
block|,
literal|0x0e04
block|,
literal|0x0e05
block|,
literal|0x0e06
block|,
literal|0x0e07
block|,
literal|0x0e08
block|,
literal|0x0e09
block|,
literal|0x0e0a
block|,
literal|0x0e0b
block|,
literal|0x0e0c
block|,
literal|0x0e0d
block|,
literal|0x0e0e
block|,
literal|0x0e0f
block|,
literal|0x0e10
block|,
literal|0x0e11
block|,
literal|0x0e12
block|,
literal|0x0e13
block|,
literal|0x0e14
block|,
literal|0x0e15
block|,
literal|0x0e16
block|,
literal|0x0e17
block|,
literal|0x0e18
block|,
literal|0x0e19
block|,
literal|0x0e1a
block|,
literal|0x0e1b
block|,
literal|0x0e1c
block|,
literal|0x0e1d
block|,
literal|0x0e1e
block|,
literal|0x0e1f
block|,
literal|0x0e20
block|,
literal|0x0e21
block|,
literal|0x0e22
block|,
literal|0x0e23
block|,
literal|0x0e24
block|,
literal|0x0e25
block|,
literal|0x0e26
block|,
literal|0x0e27
block|,
literal|0x0e28
block|,
literal|0x0e29
block|,
literal|0x0e2a
block|,
literal|0x0e2b
block|,
literal|0x0e2c
block|,
literal|0x0e2d
block|,
literal|0x0e2e
block|,
literal|0x0e2f
block|,
literal|0x0e30
block|,
literal|0x0e31
block|,
literal|0x0e32
block|,
literal|0x0e33
block|,
literal|0x0e34
block|,
literal|0x0e35
block|,
literal|0x0e36
block|,
literal|0x0e37
block|,
literal|0x0e38
block|,
literal|0x0e39
block|,
literal|0x0e3a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x0e3f
block|,
literal|0x0e40
block|,
literal|0x0e41
block|,
literal|0x0e42
block|,
literal|0x0e43
block|,
literal|0x0e44
block|,
literal|0x0e45
block|,
literal|0x0e46
block|,
literal|0x0e47
block|,
literal|0x0e48
block|,
literal|0x0e49
block|,
literal|0x0e4a
block|,
literal|0x0e4b
block|,
literal|0x0e4c
block|,
literal|0x0e4d
block|,
literal|0x0e4e
block|,
literal|0x0e4f
block|,
literal|0x0e50
block|,
literal|0x0e51
block|,
literal|0x0e52
block|,
literal|0x0e53
block|,
literal|0x0e54
block|,
literal|0x0e55
block|,
literal|0x0e56
block|,
literal|0x0e57
block|,
literal|0x0e58
block|,
literal|0x0e59
block|,
literal|0x0e5a
block|,
literal|0x0e5b
block|,
literal|0xf718
block|,
literal|0xf719
block|,
literal|0xf71a
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_enum
DECL|enum|ThaiFontType
enum|enum
name|ThaiFontType
block|{
DECL|enumerator|TIS
name|TIS
block|,
DECL|enumerator|WIN
name|WIN
block|,
DECL|enumerator|MAC
name|MAC
block|, }
enum|;
end_enum
begin_function
DECL|function|thai_get_glyph_index
specifier|static
name|int
name|thai_get_glyph_index
parameter_list|(
name|ThaiFontType
name|font_type
parameter_list|,
name|unsigned
name|char
name|c
parameter_list|)
block|{
switch|switch
condition|(
name|font_type
condition|)
block|{
case|case
name|TIS
case|:
return|return
operator|(
name|c
operator|&
literal|0x80
operator|)
condition|?
name|tis620_0
index|[
name|c
operator|&
literal|0x7f
index|]
else|:
name|c
return|;
case|case
name|WIN
case|:
return|return
operator|(
name|c
operator|&
literal|0x80
operator|)
condition|?
name|tis620_1
index|[
name|c
operator|&
literal|0x7f
index|]
else|:
name|c
return|;
case|case
name|MAC
case|:
return|return
operator|(
name|c
operator|&
literal|0x80
operator|)
condition|?
name|tis620_2
index|[
name|c
operator|&
literal|0x7f
index|]
else|:
name|c
return|;
default|default:
return|return
literal|0
return|;
block|}
block|}
end_function
begin_function
DECL|function|thai_contain_glyphs
specifier|static
name|int
name|thai_contain_glyphs
parameter_list|(
name|HB_ShaperItem
modifier|*
name|shaper_item
parameter_list|,
specifier|const
name|int
name|glyph_map
index|[
literal|128
index|]
parameter_list|)
block|{
name|unsigned
name|char
name|c
decl_stmt|;
for|for
control|(
name|c
operator|=
literal|0
init|;
name|c
operator|<
literal|0x80
condition|;
name|c
operator|++
control|)
block|{
if|if
condition|(
name|glyph_map
index|[
name|c
index|]
condition|)
block|{
if|if
condition|(
operator|!
name|shaper_item
operator|->
name|font
operator|->
name|klass
operator|->
name|canRender
argument_list|(
name|shaper_item
operator|->
name|font
argument_list|,
operator|(
name|HB_UChar16
operator|*
operator|)
operator|&
name|glyph_map
index|[
name|c
index|]
argument_list|,
literal|1
argument_list|)
condition|)
return|return
literal|0
return|;
block|}
block|}
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|getThaiFontType
specifier|static
name|ThaiFontType
name|getThaiFontType
parameter_list|(
name|HB_ShaperItem
modifier|*
name|shaper_item
parameter_list|)
block|{
if|if
condition|(
name|thai_contain_glyphs
argument_list|(
name|shaper_item
argument_list|,
name|tis620_2
argument_list|)
condition|)
return|return
name|MAC
return|;
elseif|else
if|if
condition|(
name|thai_contain_glyphs
argument_list|(
name|shaper_item
argument_list|,
name|tis620_1
argument_list|)
condition|)
return|return
name|WIN
return|;
else|else
return|return
name|TIS
return|;
block|}
end_function
begin_comment
comment|/*  * convert to the correct display level of THAI vowels and marks.  */
end_comment
begin_function
DECL|function|HB_ThaiConvertStringToGlyphIndices
specifier|static
name|HB_Bool
name|HB_ThaiConvertStringToGlyphIndices
parameter_list|(
name|HB_ShaperItem
modifier|*
name|item
parameter_list|)
block|{
name|char
name|s
index|[
literal|128
index|]
decl_stmt|;
name|char
modifier|*
name|cstr
init|=
name|s
decl_stmt|;
specifier|const
name|HB_UChar16
modifier|*
name|string
init|=
name|item
operator|->
name|string
operator|+
name|item
operator|->
name|item
operator|.
name|pos
decl_stmt|;
specifier|const
name|hb_uint32
name|len
init|=
name|item
operator|->
name|item
operator|.
name|length
decl_stmt|;
name|unsigned
name|short
modifier|*
name|logClusters
init|=
name|item
operator|->
name|log_clusters
decl_stmt|;
name|hb_uint32
name|i
init|=
literal|0
decl_stmt|,
name|slen
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|init_libthai
argument_list|()
condition|)
return|return
name|HB_BasicShape
argument_list|(
name|item
argument_list|)
return|;
if|if
condition|(
name|len
operator|>=
literal|128
condition|)
name|cstr
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|len
operator|*
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|cstr
condition|)
return|return
name|HB_BasicShape
argument_list|(
name|item
argument_list|)
return|;
name|to_tis620
argument_list|(
name|string
argument_list|,
name|len
argument_list|,
name|cstr
argument_list|)
expr_stmt|;
comment|/* Get font type */
specifier|static
name|ThaiFontType
name|font_type
decl_stmt|;
specifier|static
name|HB_Font
name|itemFont
decl_stmt|;
if|if
condition|(
name|itemFont
operator|!=
name|item
operator|->
name|font
condition|)
block|{
name|font_type
operator|=
name|getThaiFontType
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|itemFont
operator|=
name|item
operator|->
name|font
expr_stmt|;
block|}
comment|/* allocate temporary glyphs buffers */
name|HB_STACKARRAY
argument_list|(
name|HB_UChar16
argument_list|,
name|glyphString
argument_list|,
operator|(
name|item
operator|->
name|item
operator|.
name|length
operator|*
literal|2
operator|)
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|item
operator|->
name|item
operator|.
name|length
condition|)
block|{
name|struct
name|thcell_t
name|tis_cell
decl_stmt|;
name|unsigned
name|char
name|rglyphs
index|[
literal|4
index|]
decl_stmt|;
name|int
name|cell_length
decl_stmt|;
name|int
name|lgn
init|=
literal|0
decl_stmt|;
name|HB_Bool
name|haveSaraAm
init|=
name|false
decl_stmt|;
name|cell_length
operator|=
name|th_next_cell
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|cstr
operator|+
name|i
argument_list|,
name|len
operator|-
name|i
argument_list|,
operator|&
name|tis_cell
argument_list|,
name|true
argument_list|)
expr_stmt|;
comment|/* !item->fixedPitch); */
name|haveSaraAm
operator|=
operator|(
name|cstr
index|[
name|i
operator|+
name|cell_length
operator|-
literal|1
index|]
operator|==
operator|(
name|char
operator|)
literal|0xd3
operator|)
expr_stmt|;
comment|/* set shaper item's log_clusters */
name|logClusters
index|[
name|i
index|]
operator|=
name|slen
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|1
init|;
name|j
operator|<
name|cell_length
condition|;
name|j
operator|++
control|)
block|{
name|logClusters
index|[
name|i
operator|+
name|j
index|]
operator|=
name|logClusters
index|[
name|i
index|]
expr_stmt|;
block|}
comment|/* Find Logical Glyphs by font type */
switch|switch
condition|(
name|font_type
condition|)
block|{
case|case
name|TIS
case|:
name|lgn
operator|=
name|th_render_cell_tis
argument_list|(
name|tis_cell
argument_list|,
name|rglyphs
argument_list|,
sizeof|sizeof
argument_list|(
name|rglyphs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rglyphs
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|true
argument_list|)
expr_stmt|;
break|break;
case|case
name|WIN
case|:
name|lgn
operator|=
name|th_render_cell_mac
argument_list|(
name|tis_cell
argument_list|,
name|rglyphs
argument_list|,
sizeof|sizeof
argument_list|(
name|rglyphs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rglyphs
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|true
argument_list|)
expr_stmt|;
break|break;
case|case
name|MAC
case|:
name|lgn
operator|=
name|th_render_cell_win
argument_list|(
name|tis_cell
argument_list|,
name|rglyphs
argument_list|,
sizeof|sizeof
argument_list|(
name|rglyphs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rglyphs
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|true
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* Add glyphs to glyphs string and setting some attributes */
for|for
control|(
name|int
name|lgi
init|=
literal|0
init|;
name|lgi
operator|<
name|lgn
condition|;
name|lgi
operator|++
control|)
block|{
if|if
condition|(
name|rglyphs
index|[
name|lgi
index|]
operator|==
literal|0xdd
comment|/*TH_BLANK_BASE_GLYPH*/
condition|)
block|{
name|glyphString
index|[
name|slen
operator|++
index|]
operator|=
name|C_DOTTED_CIRCLE
expr_stmt|;
block|}
else|else
block|{
name|glyphString
index|[
name|slen
operator|++
index|]
operator|=
operator|(
name|HB_UChar16
operator|)
name|thai_get_glyph_index
argument_list|(
name|font_type
argument_list|,
name|rglyphs
index|[
name|lgi
index|]
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Special case to handle U+0E33 (SARA AM, à¸³): SARA AM is normally written at the end of a          * word with a base character and an optional top character before it. For example, U+0E0B          * (base), U+0E49 (top), U+0E33 (SARA AM). The sequence should be converted to 4 glyphs:          * base, hilo (the little circle in the top left part of SARA AM, NIKHAHIT), top, then the          * right part of SARA AM (SARA AA).          *          * The painting process finds out the starting glyph and ending glyph of a character          * sequence by checking the logClusters array. In this case, logClusters array should          * ideally be [ 0, 1, 3 ] so that glyphsStart = 0 and glyphsEnd = 3 (slen - 1) to paint out          * all the glyphs generated.          *          * A special case in this special case is when we have no base character. When an isolated          * SARA AM is processed (cell_length = 1), libthai will produce 3 glyphs: dotted circle          * (indicates that the base is empty), NIKHAHIT then SARA AA. If logClusters[0] = 1, it will          * paint from the second glyph in the glyphs array. So in this case logClusters[0] should          * point to the first glyph it produces, aka. the dotted circle. */
if|if
condition|(
name|haveSaraAm
condition|)
block|{
name|logClusters
index|[
name|i
operator|+
name|cell_length
operator|-
literal|1
index|]
operator|=
name|cell_length
operator|==
literal|1
condition|?
name|slen
operator|-
literal|3
else|:
name|slen
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|tis_cell
operator|.
name|top
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|cell_length
operator|>
literal|1
condition|)
block|{
comment|/* set the logClusters[top character] to slen - 2 as it points to the second to                      * lastglyph (slen - 2) */
name|logClusters
index|[
name|i
operator|+
name|cell_length
operator|-
literal|2
index|]
operator|=
name|slen
operator|-
literal|2
expr_stmt|;
block|}
block|}
comment|/* check for overflow */
if|if
condition|(
name|logClusters
index|[
name|i
operator|+
name|cell_length
operator|-
literal|1
index|]
operator|>
name|slen
condition|)
name|logClusters
index|[
name|i
operator|+
name|cell_length
operator|-
literal|1
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|i
operator|+=
name|cell_length
expr_stmt|;
block|}
name|glyphString
index|[
name|slen
index|]
operator|=
operator|(
name|HB_UChar16
operator|)
literal|'\0'
expr_stmt|;
comment|/* for check, should reallocate space or not */
name|HB_Bool
name|spaceOK
init|=
operator|(
name|item
operator|->
name|num_glyphs
operator|>=
name|slen
operator|)
decl_stmt|;
comment|/* Convert to Glyph indices */
name|HB_Bool
name|haveGlyphs
init|=
name|item
operator|->
name|font
operator|->
name|klass
operator|->
name|convertStringToGlyphIndices
argument_list|(
name|item
operator|->
name|font
argument_list|,
name|glyphString
argument_list|,
name|slen
argument_list|,
name|item
operator|->
name|glyphs
argument_list|,
operator|&
name|item
operator|->
name|num_glyphs
argument_list|,
name|item
operator|->
name|shaperFlags
argument_list|)
decl_stmt|;
name|HB_FREE_STACKARRAY
argument_list|(
name|glyphString
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|>=
literal|128
condition|)
name|free
argument_list|(
name|cstr
argument_list|)
expr_stmt|;
return|return
operator|(
name|haveGlyphs
operator|&&
name|spaceOK
operator|)
return|;
block|}
end_function
begin_comment
comment|/*  * set the glyph attributes heuristically.  */
end_comment
begin_function
DECL|function|HB_ThaiHeuristicSetGlyphAttributes
specifier|static
name|void
name|HB_ThaiHeuristicSetGlyphAttributes
parameter_list|(
name|HB_ShaperItem
modifier|*
name|item
parameter_list|)
block|{
comment|/* Set Glyph Attributes */
name|hb_uint32
name|iCluster
init|=
literal|0
decl_stmt|;
name|hb_uint32
name|length
init|=
name|item
operator|->
name|item
operator|.
name|length
decl_stmt|;
while|while
condition|(
name|iCluster
operator|<
name|length
condition|)
block|{
name|int
name|cluster_start
init|=
name|item
operator|->
name|log_clusters
index|[
name|iCluster
index|]
decl_stmt|;
operator|++
name|iCluster
expr_stmt|;
while|while
condition|(
name|iCluster
operator|<
name|length
operator|&&
name|item
operator|->
name|log_clusters
index|[
name|iCluster
index|]
operator|==
name|cluster_start
condition|)
block|{
operator|++
name|iCluster
expr_stmt|;
block|}
name|int
name|cluster_end
init|=
operator|(
name|iCluster
operator|<
name|length
operator|)
condition|?
name|item
operator|->
name|log_clusters
index|[
name|iCluster
index|]
else|:
name|item
operator|->
name|num_glyphs
decl_stmt|;
name|item
operator|->
name|attributes
index|[
name|cluster_start
index|]
operator|.
name|clusterStart
operator|=
name|true
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|cluster_start
operator|+
literal|1
init|;
name|i
operator|<
name|cluster_end
condition|;
name|i
operator|++
control|)
block|{
name|item
operator|->
name|attributes
index|[
name|i
index|]
operator|.
name|clusterStart
operator|=
name|false
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*  * THAI Shaping.  */
end_comment
begin_function
DECL|function|HB_ThaiShape
name|HB_Bool
name|HB_ThaiShape
parameter_list|(
name|HB_ShaperItem
modifier|*
name|shaper_item
parameter_list|)
block|{
if|if
condition|(
operator|!
name|HB_ThaiConvertStringToGlyphIndices
argument_list|(
name|shaper_item
argument_list|)
condition|)
return|return
name|false
return|;
name|HB_ThaiHeuristicSetGlyphAttributes
argument_list|(
name|shaper_item
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NO_OPENTYPE
specifier|const
name|int
name|availableGlyphs
init|=
name|shaper_item
operator|->
name|num_glyphs
decl_stmt|;
if|if
condition|(
name|HB_SelectScript
argument_list|(
name|shaper_item
argument_list|,
name|thai_features
argument_list|)
condition|)
block|{
name|HB_OpenTypeShape
argument_list|(
name|shaper_item
argument_list|,
comment|/*properties*/
literal|0
argument_list|)
expr_stmt|;
return|return
name|HB_OpenTypePosition
argument_list|(
name|shaper_item
argument_list|,
name|availableGlyphs
argument_list|,
comment|/*doLogClusters*/
name|true
argument_list|)
return|;
block|}
endif|#
directive|endif
name|HB_HeuristicPosition
argument_list|(
name|shaper_item
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_comment
comment|/*  * Thai Attributes: computes Word Break, Word Boundary and Char stop for THAI.  */
end_comment
begin_function
DECL|function|HB_ThaiAssignAttributes
specifier|static
name|void
name|HB_ThaiAssignAttributes
parameter_list|(
specifier|const
name|HB_UChar16
modifier|*
name|string
parameter_list|,
name|hb_uint32
name|len
parameter_list|,
name|HB_CharAttributes
modifier|*
name|attributes
parameter_list|)
block|{
name|char
name|s
index|[
literal|128
index|]
decl_stmt|;
name|char
modifier|*
name|cstr
init|=
name|s
decl_stmt|;
name|int
modifier|*
name|break_positions
init|=
literal|0
decl_stmt|;
name|int
name|brp
index|[
literal|128
index|]
decl_stmt|;
name|int
name|brp_size
init|=
literal|0
decl_stmt|;
name|hb_uint32
name|numbreaks
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|,
name|cell_length
decl_stmt|;
name|struct
name|thcell_t
name|tis_cell
decl_stmt|;
if|if
condition|(
operator|!
name|init_libthai
argument_list|()
condition|)
return|return ;
if|if
condition|(
name|len
operator|>=
literal|128
condition|)
name|cstr
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|len
operator|*
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|to_tis620
argument_list|(
name|string
argument_list|,
name|len
argument_list|,
name|cstr
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
control|)
block|{
name|attributes
index|[
name|i
index|]
operator|.
name|lineBreakType
operator|=
name|HB_NoBreak
expr_stmt|;
name|attributes
index|[
name|i
index|]
operator|.
name|wordBoundary
operator|=
name|FALSE
expr_stmt|;
block|}
if|if
condition|(
name|len
operator|>
literal|128
condition|)
block|{
name|break_positions
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|len
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|break_positions
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|len
argument_list|)
expr_stmt|;
name|brp_size
operator|=
name|len
expr_stmt|;
block|}
else|else
block|{
name|break_positions
operator|=
name|brp
expr_stmt|;
name|brp_size
operator|=
literal|128
expr_stmt|;
block|}
if|if
condition|(
name|break_positions
condition|)
block|{
name|attributes
index|[
literal|0
index|]
operator|.
name|wordBoundary
operator|=
name|TRUE
expr_stmt|;
name|numbreaks
operator|=
name|th_brk
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|cstr
argument_list|,
name|break_positions
argument_list|,
name|brp_size
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|numbreaks
condition|;
operator|++
name|i
control|)
block|{
name|attributes
index|[
name|break_positions
index|[
name|i
index|]
index|]
operator|.
name|wordBoundary
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|break_positions
index|[
name|i
index|]
operator|>
literal|0
condition|)
name|attributes
index|[
name|break_positions
index|[
name|i
index|]
operator|-
literal|1
index|]
operator|.
name|lineBreakType
operator|=
name|HB_Break
expr_stmt|;
block|}
if|if
condition|(
name|break_positions
operator|!=
name|brp
condition|)
name|free
argument_list|(
name|break_positions
argument_list|)
expr_stmt|;
block|}
comment|/* manage charStop */
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|len
condition|)
block|{
name|cell_length
operator|=
name|th_next_cell
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|cstr
operator|+
name|i
argument_list|,
name|len
operator|-
name|i
argument_list|,
operator|&
name|tis_cell
argument_list|,
name|true
argument_list|)
expr_stmt|;
name|attributes
index|[
name|i
index|]
operator|.
name|charStop
operator|=
name|true
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|1
init|;
name|j
operator|<
name|cell_length
condition|;
name|j
operator|++
control|)
name|attributes
index|[
name|i
operator|+
name|j
index|]
operator|.
name|charStop
operator|=
name|false
expr_stmt|;
comment|/* Set charStop for SARA AM */
if|if
condition|(
name|cstr
index|[
name|i
operator|+
name|cell_length
operator|-
literal|1
index|]
operator|==
operator|(
name|char
operator|)
literal|0xd3
condition|)
name|attributes
index|[
name|i
operator|+
name|cell_length
operator|-
literal|1
index|]
operator|.
name|charStop
operator|=
name|true
expr_stmt|;
name|i
operator|+=
name|cell_length
expr_stmt|;
block|}
if|if
condition|(
name|len
operator|>=
literal|128
condition|)
name|free
argument_list|(
name|cstr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|HB_ThaiAttributes
name|void
name|HB_ThaiAttributes
parameter_list|(
name|HB_Script
name|script
parameter_list|,
specifier|const
name|HB_UChar16
modifier|*
name|text
parameter_list|,
name|hb_uint32
name|from
parameter_list|,
name|hb_uint32
name|len
parameter_list|,
name|HB_CharAttributes
modifier|*
name|attributes
parameter_list|)
block|{
name|assert
argument_list|(
name|script
operator|==
name|HB_Script_Thai
argument_list|)
expr_stmt|;
specifier|const
name|HB_UChar16
modifier|*
name|uc
init|=
name|text
operator|+
name|from
decl_stmt|;
name|attributes
operator|+=
name|from
expr_stmt|;
name|HB_UNUSED
argument_list|(
name|script
argument_list|)
expr_stmt|;
name|HB_ThaiAssignAttributes
argument_list|(
name|uc
argument_list|,
name|len
argument_list|,
name|attributes
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
