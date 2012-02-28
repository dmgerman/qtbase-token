begin_unit
begin_comment
comment|/************************ sha-private.h ************************/
end_comment
begin_comment
comment|/***************** See RFC 6234 for details. *******************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_SHA_PRIVATE__H
end_ifndef
begin_define
DECL|macro|_SHA_PRIVATE__H
define|#
directive|define
name|_SHA_PRIVATE__H
end_define
begin_comment
comment|/*  * These definitions are defined in FIPS 180-3, section 4.1.  * Ch() and Maj() are defined identically in sections 4.1.1,  * 4.1.2, and 4.1.3.  *  * The definitions used in FIPS 180-3 are as follows:  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|USE_MODIFIED_MACROS
end_ifndef
begin_define
DECL|macro|SHA_Ch
define|#
directive|define
name|SHA_Ch
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)& (y)) ^ ((~(x))& (z)))
end_define
begin_define
DECL|macro|SHA_Maj
define|#
directive|define
name|SHA_Maj
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)& (y)) ^ ((x)& (z)) ^ ((y)& (z)))
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* USE_MODIFIED_MACROS */
end_comment
begin_comment
comment|/*  * The following definitions are equivalent and potentially faster.  */
end_comment
begin_define
DECL|macro|SHA_Ch
define|#
directive|define
name|SHA_Ch
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)& ((y) ^ (z))) ^ (z))
end_define
begin_define
DECL|macro|SHA_Maj
define|#
directive|define
name|SHA_Maj
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)& ((y) | (z))) | ((y)& (z)))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* USE_MODIFIED_MACROS */
end_comment
begin_define
DECL|macro|SHA_Parity
define|#
directive|define
name|SHA_Parity
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((x) ^ (y) ^ (z))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _SHA_PRIVATE__H */
end_comment
end_unit
