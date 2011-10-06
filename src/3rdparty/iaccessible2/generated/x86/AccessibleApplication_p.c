begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the proxy stub code */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:52 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleApplication.idl:     Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
end_comment
begin_comment
comment|/* @@MIDL_FILE_HEADING(  ) */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_M_IA64
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_M_AMD64
argument_list|)
end_if
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
begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1200
end_if
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4211
name|)
end_pragma
begin_comment
comment|/* redefine extern to static */
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4232
name|)
end_pragma
begin_comment
comment|/* dllimport identity*/
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4024
name|)
end_pragma
begin_comment
comment|/* array to pointer mapping*/
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4152
name|)
end_pragma
begin_comment
comment|/* function/data pointer conversion in expression */
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4100
name|)
end_pragma
begin_comment
comment|/* unreferenced arguments in x86 call */
end_comment
begin_pragma
pragma|#
directive|pragma
name|optimize
name|(
literal|""
name|,
name|off
name|)
end_pragma
begin_define
DECL|macro|USE_STUBLESS_PROXY
define|#
directive|define
name|USE_STUBLESS_PROXY
end_define
begin_comment
comment|/* verify that the<rpcproxy.h> version is high enough to compile this file*/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__REDQ_RPCPROXY_H_VERSION__
end_ifndef
begin_define
DECL|macro|__REQUIRED_RPCPROXY_H_VERSION__
define|#
directive|define
name|__REQUIRED_RPCPROXY_H_VERSION__
value|475
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"rpcproxy.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|__RPCPROXY_H_VERSION__
end_ifndef
begin_error
error|#
directive|error
error|this stub requires an updated version of<rpcproxy.h>
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __RPCPROXY_H_VERSION__ */
end_comment
begin_include
include|#
directive|include
file|"AccessibleApplication.h"
end_include
begin_define
DECL|macro|TYPE_FORMAT_STRING_SIZE
define|#
directive|define
name|TYPE_FORMAT_STRING_SIZE
value|43
end_define
begin_define
DECL|macro|PROC_FORMAT_STRING_SIZE
define|#
directive|define
name|PROC_FORMAT_STRING_SIZE
value|145
end_define
begin_define
DECL|macro|EXPR_FORMAT_STRING_SIZE
define|#
directive|define
name|EXPR_FORMAT_STRING_SIZE
value|1
end_define
begin_define
DECL|macro|TRANSMIT_AS_TABLE_SIZE
define|#
directive|define
name|TRANSMIT_AS_TABLE_SIZE
value|0
end_define
begin_define
DECL|macro|WIRE_MARSHAL_TABLE_SIZE
define|#
directive|define
name|WIRE_MARSHAL_TABLE_SIZE
value|1
end_define
begin_typedef
DECL|struct|_AccessibleApplication_MIDL_TYPE_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleApplication_MIDL_TYPE_FORMAT_STRING
block|{
DECL|member|Pad
name|short
name|Pad
decl_stmt|;
DECL|member|Format
name|unsigned
name|char
name|Format
index|[
name|TYPE_FORMAT_STRING_SIZE
index|]
decl_stmt|;
block|}
DECL|typedef|AccessibleApplication_MIDL_TYPE_FORMAT_STRING
name|AccessibleApplication_MIDL_TYPE_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleApplication_MIDL_PROC_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleApplication_MIDL_PROC_FORMAT_STRING
block|{
DECL|member|Pad
name|short
name|Pad
decl_stmt|;
DECL|member|Format
name|unsigned
name|char
name|Format
index|[
name|PROC_FORMAT_STRING_SIZE
index|]
decl_stmt|;
block|}
DECL|typedef|AccessibleApplication_MIDL_PROC_FORMAT_STRING
name|AccessibleApplication_MIDL_PROC_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleApplication_MIDL_EXPR_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleApplication_MIDL_EXPR_FORMAT_STRING
block|{
DECL|member|Pad
name|long
name|Pad
decl_stmt|;
DECL|member|Format
name|unsigned
name|char
name|Format
index|[
name|EXPR_FORMAT_STRING_SIZE
index|]
decl_stmt|;
block|}
DECL|typedef|AccessibleApplication_MIDL_EXPR_FORMAT_STRING
name|AccessibleApplication_MIDL_EXPR_FORMAT_STRING
typedef|;
end_typedef
begin_decl_stmt
DECL|variable|_RpcTransferSyntax
specifier|static
specifier|const
name|RPC_SYNTAX_IDENTIFIER
name|_RpcTransferSyntax
init|=
block|{
block|{
literal|0x8A885D04
block|,
literal|0x1CEB
block|,
literal|0x11C9
block|,
block|{
literal|0x9F
block|,
literal|0xE8
block|,
literal|0x08
block|,
literal|0x00
block|,
literal|0x2B
block|,
literal|0x10
block|,
literal|0x48
block|,
literal|0x60
block|}
block|}
block|,
block|{
literal|2
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleApplication_MIDL_TYPE_FORMAT_STRING
name|AccessibleApplication__MIDL_TypeFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleApplication_MIDL_PROC_FORMAT_STRING
name|AccessibleApplication__MIDL_ProcFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleApplication_MIDL_EXPR_FORMAT_STRING
name|AccessibleApplication__MIDL_ExprFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_STUB_DESC
name|Object_StubDesc
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_SERVER_INFO
name|IAccessibleApplication_ServerInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleApplication_ProxyInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|USER_MARSHAL_ROUTINE_QUADRUPLE
name|UserMarshalRoutines
index|[
name|WIRE_MARSHAL_TABLE_SIZE
index|]
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__RPC_WIN32__
argument_list|)
end_if
begin_error
error|#
directive|error
error|Invalid build platform for this stub.
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
operator|(
name|TARGET_IS_NT50_OR_LATER
operator|)
end_if
begin_error
error|#
directive|error
error|You need Windows 2000 or later to run this stub because it uses these features:
end_error
begin_error
error|#
directive|error
error|/robust command line switch.
end_error
begin_error
error|#
directive|error
error|However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
end_error
begin_error
error|#
directive|error
error|This app will fail with the RPC_X_WRONG_STUB_VERSION error.
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|AccessibleApplication__MIDL_ProcFormatString
specifier|static
specifier|const
name|AccessibleApplication_MIDL_PROC_FORMAT_STRING
name|AccessibleApplication__MIDL_ProcFormatString
init|=
block|{
literal|0
block|,
block|{
comment|/* Procedure get_appName */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/*  2 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/*  6 */
name|NdrFcShort
argument_list|(
literal|0x3
argument_list|)
block|,
comment|/* 3 */
comment|/*  8 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 10 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 12 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 14 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 16 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 18 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 20 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 22 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter name */
comment|/* 24 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 26 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 28 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* Type Offset=32 */
comment|/* Return value */
comment|/* 30 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 32 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 34 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_appVersion */
comment|/* 36 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 38 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 42 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 44 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 46 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 48 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 50 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 52 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 54 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 56 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 58 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter version */
comment|/* 60 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 62 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 64 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* Type Offset=32 */
comment|/* Return value */
comment|/* 66 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 68 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 70 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_toolkitName */
comment|/* 72 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 74 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 78 */
name|NdrFcShort
argument_list|(
literal|0x5
argument_list|)
block|,
comment|/* 5 */
comment|/* 80 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 82 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 84 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 86 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 88 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 90 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 92 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 94 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter name */
comment|/* 96 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 98 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 100 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* Type Offset=32 */
comment|/* Return value */
comment|/* 102 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 104 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 106 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_toolkitVersion */
comment|/* 108 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 110 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 114 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* 6 */
comment|/* 116 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 118 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 120 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 122 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 124 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 126 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 128 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 130 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter version */
comment|/* 132 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 134 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 136 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* Type Offset=32 */
comment|/* Return value */
comment|/* 138 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 140 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 142 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|AccessibleApplication__MIDL_TypeFormatString
specifier|static
specifier|const
name|AccessibleApplication_MIDL_TYPE_FORMAT_STRING
name|AccessibleApplication__MIDL_TypeFormatString
init|=
block|{
literal|0
block|,
block|{
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/*  2 */
literal|0x11
block|,
literal|0x4
block|,
comment|/* FC_RP [alloced_on_stack] */
comment|/*  4 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* Offset= 28 (32) */
comment|/*  6 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/*  8 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* Offset= 14 (22) */
comment|/* 10 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x1
block|,
comment|/* 1 */
comment|/* 12 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 14 */
literal|0x9
block|,
comment|/* Corr desc: FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 16 */
name|NdrFcShort
argument_list|(
literal|0xfffc
argument_list|)
block|,
comment|/* -4 */
comment|/* 18 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 20 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 22 */
literal|0x17
block|,
comment|/* FC_CSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 24 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 26 */
name|NdrFcShort
argument_list|(
literal|0xfff0
argument_list|)
block|,
comment|/* Offset= -16 (10) */
comment|/* 28 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 30 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 32 */
literal|0xb4
block|,
comment|/* FC_USER_MARSHAL */
literal|0x83
block|,
comment|/* 131 */
comment|/* 34 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 36 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 38 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 40 */
name|NdrFcShort
argument_list|(
literal|0xffde
argument_list|)
block|,
comment|/* Offset= -34 (6) */
literal|0x0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|UserMarshalRoutines
specifier|static
specifier|const
name|USER_MARSHAL_ROUTINE_QUADRUPLE
name|UserMarshalRoutines
index|[
name|WIRE_MARSHAL_TABLE_SIZE
index|]
init|=
block|{
block|{
name|BSTR_UserSize
block|,
name|BSTR_UserMarshal
block|,
name|BSTR_UserUnmarshal
block|,
name|BSTR_UserFree
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Object interface: IUnknown, ver. 0.0,    GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */
end_comment
begin_comment
comment|/* Object interface: IAccessibleApplication, ver. 0.0,    GUID={0xD49DED83,0x5B25,0x43F4,{0x9B,0x95,0x93,0xB4,0x45,0x95,0x97,0x9E}} */
end_comment
begin_pragma
pragma|#
directive|pragma
name|code_seg
name|(
literal|".orpc"
name|)
end_pragma
begin_decl_stmt
DECL|variable|IAccessibleApplication_FormatStringOffsetTable
specifier|static
specifier|const
name|unsigned
name|short
name|IAccessibleApplication_FormatStringOffsetTable
index|[]
init|=
block|{
literal|0
block|,
literal|36
block|,
literal|72
block|,
literal|108
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|IAccessibleApplication_ProxyInfo
specifier|static
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleApplication_ProxyInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
name|AccessibleApplication__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleApplication_FormatStringOffsetTable
index|[
operator|-
literal|3
index|]
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
DECL|variable|IAccessibleApplication_ServerInfo
specifier|static
specifier|const
name|MIDL_SERVER_INFO
name|IAccessibleApplication_ServerInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
literal|0
block|,
name|AccessibleApplication__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleApplication_FormatStringOffsetTable
index|[
operator|-
literal|3
index|]
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
begin_macro
name|CINTERFACE_PROXY_VTABLE
argument_list|(
literal|7
argument_list|)
end_macro
begin_expr_stmt
name|_IAccessibleApplicationProxyVtbl
operator|=
block|{
operator|&
name|IAccessibleApplication_ProxyInfo
block|,
operator|&
name|IID_IAccessibleApplication
block|,
name|IUnknown_QueryInterface_Proxy
block|,
name|IUnknown_AddRef_Proxy
block|,
name|IUnknown_Release_Proxy
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|INT_PTR
operator|)
operator|-
literal|1
comment|/* IAccessibleApplication::get_appName */
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|INT_PTR
operator|)
operator|-
literal|1
comment|/* IAccessibleApplication::get_appVersion */
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|INT_PTR
operator|)
operator|-
literal|1
comment|/* IAccessibleApplication::get_toolkitName */
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|INT_PTR
operator|)
operator|-
literal|1
comment|/* IAccessibleApplication::get_toolkitVersion */
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|_IAccessibleApplicationStubVtbl
specifier|const
name|CInterfaceStubVtbl
name|_IAccessibleApplicationStubVtbl
init|=
block|{
operator|&
name|IID_IAccessibleApplication
block|,
operator|&
name|IAccessibleApplication_ServerInfo
block|,
literal|7
block|,
literal|0
block|,
comment|/* pure interpreted */
name|CStdStubBuffer_METHODS
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Object_StubDesc
specifier|static
specifier|const
name|MIDL_STUB_DESC
name|Object_StubDesc
init|=
block|{
literal|0
block|,
name|NdrOleAllocate
block|,
name|NdrOleFree
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
name|AccessibleApplication__MIDL_TypeFormatString
operator|.
name|Format
block|,
literal|1
block|,
comment|/* -error bounds_check flag */
literal|0x50002
block|,
comment|/* Ndr library version */
literal|0
block|,
literal|0x700022b
block|,
comment|/* MIDL Version 7.0.555 */
literal|0
block|,
name|UserMarshalRoutines
block|,
literal|0
block|,
comment|/* notify& notify_flag routine table */
literal|0x1
block|,
comment|/* MIDL flag */
literal|0
block|,
comment|/* cs routines */
literal|0
block|,
comment|/* proxy/server info */
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleApplication_ProxyVtblList
specifier|const
name|CInterfaceProxyVtbl
modifier|*
specifier|const
name|_AccessibleApplication_ProxyVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceProxyVtbl
operator|*
operator|)
operator|&
name|_IAccessibleApplicationProxyVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleApplication_StubVtblList
specifier|const
name|CInterfaceStubVtbl
modifier|*
specifier|const
name|_AccessibleApplication_StubVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceStubVtbl
operator|*
operator|)
operator|&
name|_IAccessibleApplicationStubVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleApplication_InterfaceNamesList
name|PCInterfaceName
specifier|const
name|_AccessibleApplication_InterfaceNamesList
index|[]
init|=
block|{
literal|"IAccessibleApplication"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|_AccessibleApplication_CHECK_IID
define|#
directive|define
name|_AccessibleApplication_CHECK_IID
parameter_list|(
name|n
parameter_list|)
value|IID_GENERIC_CHECK_IID( _AccessibleApplication, pIID, n)
end_define
begin_function
DECL|function|_AccessibleApplication_IID_Lookup
name|int
name|__stdcall
name|_AccessibleApplication_IID_Lookup
parameter_list|(
specifier|const
name|IID
modifier|*
name|pIID
parameter_list|,
name|int
modifier|*
name|pIndex
parameter_list|)
block|{
if|if
condition|(
operator|!
name|_AccessibleApplication_CHECK_IID
argument_list|(
literal|0
argument_list|)
condition|)
block|{
operator|*
name|pIndex
operator|=
literal|0
expr_stmt|;
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|AccessibleApplication_ProxyFileInfo
specifier|const
name|ExtendedProxyFileInfo
name|AccessibleApplication_ProxyFileInfo
init|=
block|{
operator|(
name|PCInterfaceProxyVtblList
operator|*
operator|)
operator|&
name|_AccessibleApplication_ProxyVtblList
block|,
operator|(
name|PCInterfaceStubVtblList
operator|*
operator|)
operator|&
name|_AccessibleApplication_StubVtblList
block|,
operator|(
specifier|const
name|PCInterfaceName
operator|*
operator|)
operator|&
name|_AccessibleApplication_InterfaceNamesList
block|,
literal|0
block|,
comment|/* no delegation */
operator|&
name|_AccessibleApplication_IID_Lookup
block|,
literal|1
block|,
literal|2
block|,
literal|0
block|,
comment|/* table of [async_uuid] interfaces */
literal|0
block|,
comment|/* Filler1 */
literal|0
block|,
comment|/* Filler2 */
literal|0
comment|/* Filler3 */
block|}
decl_stmt|;
end_decl_stmt
begin_pragma
pragma|#
directive|pragma
name|optimize
name|(
literal|""
name|,
name|on
name|)
end_pragma
begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1200
end_if
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !defined(_M_IA64)&& !defined(_M_AMD64)*/
end_comment
end_unit
