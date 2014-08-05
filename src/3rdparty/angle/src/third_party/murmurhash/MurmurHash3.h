begin_unit
begin_comment
comment|//-----------------------------------------------------------------------------
end_comment
begin_comment
comment|// MurmurHash3 was written by Austin Appleby, and is placed in the public
end_comment
begin_comment
comment|// domain. The author hereby disclaims copyright to this source code.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_MURMURHASH3_H_
end_ifndef
begin_define
DECL|macro|_MURMURHASH3_H_
define|#
directive|define
name|_MURMURHASH3_H_
end_define
begin_comment
comment|//-----------------------------------------------------------------------------
end_comment
begin_comment
comment|// Platform-specific functions and macros
end_comment
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_comment
comment|//-----------------------------------------------------------------------------
end_comment
begin_function_decl
name|void
name|MurmurHash3_x86_32
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|int
name|len
parameter_list|,
name|uint32_t
name|seed
parameter_list|,
name|void
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|MurmurHash3_x86_128
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|int
name|len
parameter_list|,
name|uint32_t
name|seed
parameter_list|,
name|void
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|MurmurHash3_x64_128
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|int
name|len
parameter_list|,
name|uint32_t
name|seed
parameter_list|,
name|void
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//-----------------------------------------------------------------------------
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _MURMURHASH3_H_
end_comment
end_unit
