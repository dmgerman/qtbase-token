begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the definitions for the interfaces */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:56 2012  */
end_comment
begin_comment
comment|/* Compiler settings for IA2TypeLibrary.idl:     Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
end_comment
begin_comment
comment|/* @@MIDL_FILE_HEADING(  ) */
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4049
name|)
end_pragma
begin_comment
comment|/* more than 64k source lines */
end_comment
begin_comment
comment|/* verify that the<rpcndr.h> version is high enough to compile this file*/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__REQUIRED_RPCNDR_H_VERSION__
end_ifndef
begin_define
DECL|macro|__REQUIRED_RPCNDR_H_VERSION__
define|#
directive|define
name|__REQUIRED_RPCNDR_H_VERSION__
value|475
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"rpc.h"
end_include
begin_include
include|#
directive|include
file|"rpcndr.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|__RPCNDR_H_VERSION__
end_ifndef
begin_error
error|#
directive|error
error|this stub requires an updated version of<rpcndr.h>
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __RPCNDR_H_VERSION__
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__IA2TypeLibrary_h__
end_ifndef
begin_define
DECL|macro|__IA2TypeLibrary_h__
define|#
directive|define
name|__IA2TypeLibrary_h__
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|>=
literal|1020
operator|)
end_if
begin_pragma
pragma|#
directive|pragma
name|once
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Forward Declarations */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* interface __MIDL_itf_IA2TypeLibrary_0000_0000 */
comment|/* [local] */
comment|// Type Library Definitions
specifier|extern
name|RPC_IF_HANDLE
name|__MIDL_itf_IA2TypeLibrary_0000_0000_v0_0_c_ifspec
decl_stmt|;
specifier|extern
name|RPC_IF_HANDLE
name|__MIDL_itf_IA2TypeLibrary_0000_0000_v0_0_s_ifspec
decl_stmt|;
ifndef|#
directive|ifndef
name|__IAccessible2Lib_LIBRARY_DEFINED__
DECL|macro|__IAccessible2Lib_LIBRARY_DEFINED__
define|#
directive|define
name|__IAccessible2Lib_LIBRARY_DEFINED__
comment|/* library IAccessible2Lib */
comment|/* [hidden][version][helpstring][uuid] */
DECL|variable|LIBID_IAccessible2Lib
name|EXTERN_C
specifier|const
name|IID
name|LIBID_IAccessible2Lib
decl_stmt|;
endif|#
directive|endif
comment|/* __IAccessible2Lib_LIBRARY_DEFINED__ */
comment|/* Additional Prototypes for ALL interfaces */
comment|/* end of Additional Prototypes */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
