begin_unit
begin_comment
comment|/* infcodes.h -- header to use infcodes.c  * Copyright (C) 1995-2002 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment
begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_INFCODES_H
end_ifndef
begin_define
DECL|macro|_INFCODES_H
define|#
directive|define
name|_INFCODES_H
end_define
begin_struct_decl
struct_decl|struct
name|inflate_codes_state
struct_decl|;
end_struct_decl
begin_typedef
DECL|typedef|inflate_codes_statef
typedef|typedef
name|struct
name|inflate_codes_state
name|FAR
name|inflate_codes_statef
typedef|;
end_typedef
begin_decl_stmt
name|local
name|inflate_codes_statef
modifier|*
name|inflate_codes_new
name|OF
argument_list|(
operator|(
name|uInt
operator|,
name|uInt
operator|,
name|inflate_huft
operator|*
operator|,
name|inflate_huft
operator|*
operator|,
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|local
name|int
name|inflate_codes
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
begin_decl_stmt
name|local
name|void
name|inflate_codes_free
name|OF
argument_list|(
operator|(
name|inflate_codes_statef
operator|*
operator|,
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _INFCODES_H */
end_comment
end_unit
