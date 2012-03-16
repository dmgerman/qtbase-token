begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the proxy stub code */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:55 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleValue.idl:     Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
file|"AccessibleValue.h"
end_include
begin_define
DECL|macro|TYPE_FORMAT_STRING_SIZE
define|#
directive|define
name|TYPE_FORMAT_STRING_SIZE
value|1053
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
DECL|struct|_AccessibleValue_MIDL_TYPE_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleValue_MIDL_TYPE_FORMAT_STRING
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
DECL|typedef|AccessibleValue_MIDL_TYPE_FORMAT_STRING
name|AccessibleValue_MIDL_TYPE_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleValue_MIDL_PROC_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleValue_MIDL_PROC_FORMAT_STRING
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
DECL|typedef|AccessibleValue_MIDL_PROC_FORMAT_STRING
name|AccessibleValue_MIDL_PROC_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleValue_MIDL_EXPR_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleValue_MIDL_EXPR_FORMAT_STRING
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
DECL|typedef|AccessibleValue_MIDL_EXPR_FORMAT_STRING
name|AccessibleValue_MIDL_EXPR_FORMAT_STRING
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
name|AccessibleValue_MIDL_TYPE_FORMAT_STRING
name|AccessibleValue__MIDL_TypeFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleValue_MIDL_PROC_FORMAT_STRING
name|AccessibleValue__MIDL_ProcFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleValue_MIDL_EXPR_FORMAT_STRING
name|AccessibleValue__MIDL_ExprFormatString
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
name|IAccessibleValue_ServerInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleValue_ProxyInfo
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
DECL|variable|AccessibleValue__MIDL_ProcFormatString
specifier|static
specifier|const
name|AccessibleValue_MIDL_PROC_FORMAT_STRING
name|AccessibleValue__MIDL_ProcFormatString
init|=
block|{
literal|0
block|,
block|{
comment|/* Procedure get_currentValue */
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
comment|/* Parameter currentValue */
comment|/* 24 */
name|NdrFcShort
argument_list|(
literal|0x4113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
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
literal|0x404
argument_list|)
block|,
comment|/* Type Offset=1028 */
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
comment|/* Procedure setCurrentValue */
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
literal|0x18
argument_list|)
block|,
comment|/* x86 Stack size/offset = 24 */
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
literal|0x46
block|,
comment|/* Oi2 Flags:  clt must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 52 */
literal|0x8
block|,
comment|/* 8 */
literal|0x5
block|,
comment|/* Ext Flags:  new corr desc, srv corr check, */
comment|/* 54 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 56 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 58 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter value */
comment|/* 60 */
name|NdrFcShort
argument_list|(
literal|0x8b
argument_list|)
block|,
comment|/* Flags:  must size, must free, in, by val, */
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
literal|0x412
argument_list|)
block|,
comment|/* Type Offset=1042 */
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
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 70 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_maximumValue */
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
comment|/* Parameter maximumValue */
comment|/* 96 */
name|NdrFcShort
argument_list|(
literal|0x4113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
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
literal|0x404
argument_list|)
block|,
comment|/* Type Offset=1028 */
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
comment|/* Procedure get_minimumValue */
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
comment|/* Parameter minimumValue */
comment|/* 132 */
name|NdrFcShort
argument_list|(
literal|0x4113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
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
literal|0x404
argument_list|)
block|,
comment|/* Type Offset=1028 */
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
DECL|variable|AccessibleValue__MIDL_TypeFormatString
specifier|static
specifier|const
name|AccessibleValue_MIDL_TYPE_FORMAT_STRING
name|AccessibleValue__MIDL_TypeFormatString
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
literal|0x400
argument_list|)
block|,
comment|/* Offset= 1024 (1028) */
comment|/*  6 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/*  8 */
name|NdrFcShort
argument_list|(
literal|0x3e8
argument_list|)
block|,
comment|/* Offset= 1000 (1008) */
comment|/* 10 */
literal|0x2b
block|,
comment|/* FC_NON_ENCAPSULATED_UNION */
literal|0x9
block|,
comment|/* FC_ULONG */
comment|/* 12 */
literal|0x7
block|,
comment|/* Corr desc: FC_USHORT */
literal|0x0
block|,
comment|/*  */
comment|/* 14 */
name|NdrFcShort
argument_list|(
literal|0xfff8
argument_list|)
block|,
comment|/* -8 */
comment|/* 16 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 18 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (20) */
comment|/* 20 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 22 */
name|NdrFcShort
argument_list|(
literal|0x2f
argument_list|)
block|,
comment|/* 47 */
comment|/* 24 */
name|NdrFcLong
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* 20 */
comment|/* 28 */
name|NdrFcShort
argument_list|(
literal|0x800b
argument_list|)
block|,
comment|/* Simple arm type: FC_HYPER */
comment|/* 30 */
name|NdrFcLong
argument_list|(
literal|0x3
argument_list|)
block|,
comment|/* 3 */
comment|/* 34 */
name|NdrFcShort
argument_list|(
literal|0x8008
argument_list|)
block|,
comment|/* Simple arm type: FC_LONG */
comment|/* 36 */
name|NdrFcLong
argument_list|(
literal|0x11
argument_list|)
block|,
comment|/* 17 */
comment|/* 40 */
name|NdrFcShort
argument_list|(
literal|0x8001
argument_list|)
block|,
comment|/* Simple arm type: FC_BYTE */
comment|/* 42 */
name|NdrFcLong
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 46 */
name|NdrFcShort
argument_list|(
literal|0x8006
argument_list|)
block|,
comment|/* Simple arm type: FC_SHORT */
comment|/* 48 */
name|NdrFcLong
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 52 */
name|NdrFcShort
argument_list|(
literal|0x800a
argument_list|)
block|,
comment|/* Simple arm type: FC_FLOAT */
comment|/* 54 */
name|NdrFcLong
argument_list|(
literal|0x5
argument_list|)
block|,
comment|/* 5 */
comment|/* 58 */
name|NdrFcShort
argument_list|(
literal|0x800c
argument_list|)
block|,
comment|/* Simple arm type: FC_DOUBLE */
comment|/* 60 */
name|NdrFcLong
argument_list|(
literal|0xb
argument_list|)
block|,
comment|/* 11 */
comment|/* 64 */
name|NdrFcShort
argument_list|(
literal|0x8006
argument_list|)
block|,
comment|/* Simple arm type: FC_SHORT */
comment|/* 66 */
name|NdrFcLong
argument_list|(
literal|0xa
argument_list|)
block|,
comment|/* 10 */
comment|/* 70 */
name|NdrFcShort
argument_list|(
literal|0x8008
argument_list|)
block|,
comment|/* Simple arm type: FC_LONG */
comment|/* 72 */
name|NdrFcLong
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* 6 */
comment|/* 76 */
name|NdrFcShort
argument_list|(
literal|0xe8
argument_list|)
block|,
comment|/* Offset= 232 (308) */
comment|/* 78 */
name|NdrFcLong
argument_list|(
literal|0x7
argument_list|)
block|,
comment|/* 7 */
comment|/* 82 */
name|NdrFcShort
argument_list|(
literal|0x800c
argument_list|)
block|,
comment|/* Simple arm type: FC_DOUBLE */
comment|/* 84 */
name|NdrFcLong
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 88 */
name|NdrFcShort
argument_list|(
literal|0xe2
argument_list|)
block|,
comment|/* Offset= 226 (314) */
comment|/* 90 */
name|NdrFcLong
argument_list|(
literal|0xd
argument_list|)
block|,
comment|/* 13 */
comment|/* 94 */
name|NdrFcShort
argument_list|(
literal|0xf6
argument_list|)
block|,
comment|/* Offset= 246 (340) */
comment|/* 96 */
name|NdrFcLong
argument_list|(
literal|0x9
argument_list|)
block|,
comment|/* 9 */
comment|/* 100 */
name|NdrFcShort
argument_list|(
literal|0x102
argument_list|)
block|,
comment|/* Offset= 258 (358) */
comment|/* 102 */
name|NdrFcLong
argument_list|(
literal|0x2000
argument_list|)
block|,
comment|/* 8192 */
comment|/* 106 */
name|NdrFcShort
argument_list|(
literal|0x10e
argument_list|)
block|,
comment|/* Offset= 270 (376) */
comment|/* 108 */
name|NdrFcLong
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 112 */
name|NdrFcShort
argument_list|(
literal|0x336
argument_list|)
block|,
comment|/* Offset= 822 (934) */
comment|/* 114 */
name|NdrFcLong
argument_list|(
literal|0x4024
argument_list|)
block|,
comment|/* 16420 */
comment|/* 118 */
name|NdrFcShort
argument_list|(
literal|0x330
argument_list|)
block|,
comment|/* Offset= 816 (934) */
comment|/* 120 */
name|NdrFcLong
argument_list|(
literal|0x4011
argument_list|)
block|,
comment|/* 16401 */
comment|/* 124 */
name|NdrFcShort
argument_list|(
literal|0x32e
argument_list|)
block|,
comment|/* Offset= 814 (938) */
comment|/* 126 */
name|NdrFcLong
argument_list|(
literal|0x4002
argument_list|)
block|,
comment|/* 16386 */
comment|/* 130 */
name|NdrFcShort
argument_list|(
literal|0x32c
argument_list|)
block|,
comment|/* Offset= 812 (942) */
comment|/* 132 */
name|NdrFcLong
argument_list|(
literal|0x4003
argument_list|)
block|,
comment|/* 16387 */
comment|/* 136 */
name|NdrFcShort
argument_list|(
literal|0x32a
argument_list|)
block|,
comment|/* Offset= 810 (946) */
comment|/* 138 */
name|NdrFcLong
argument_list|(
literal|0x4014
argument_list|)
block|,
comment|/* 16404 */
comment|/* 142 */
name|NdrFcShort
argument_list|(
literal|0x328
argument_list|)
block|,
comment|/* Offset= 808 (950) */
comment|/* 144 */
name|NdrFcLong
argument_list|(
literal|0x4004
argument_list|)
block|,
comment|/* 16388 */
comment|/* 148 */
name|NdrFcShort
argument_list|(
literal|0x326
argument_list|)
block|,
comment|/* Offset= 806 (954) */
comment|/* 150 */
name|NdrFcLong
argument_list|(
literal|0x4005
argument_list|)
block|,
comment|/* 16389 */
comment|/* 154 */
name|NdrFcShort
argument_list|(
literal|0x324
argument_list|)
block|,
comment|/* Offset= 804 (958) */
comment|/* 156 */
name|NdrFcLong
argument_list|(
literal|0x400b
argument_list|)
block|,
comment|/* 16395 */
comment|/* 160 */
name|NdrFcShort
argument_list|(
literal|0x30e
argument_list|)
block|,
comment|/* Offset= 782 (942) */
comment|/* 162 */
name|NdrFcLong
argument_list|(
literal|0x400a
argument_list|)
block|,
comment|/* 16394 */
comment|/* 166 */
name|NdrFcShort
argument_list|(
literal|0x30c
argument_list|)
block|,
comment|/* Offset= 780 (946) */
comment|/* 168 */
name|NdrFcLong
argument_list|(
literal|0x4006
argument_list|)
block|,
comment|/* 16390 */
comment|/* 172 */
name|NdrFcShort
argument_list|(
literal|0x316
argument_list|)
block|,
comment|/* Offset= 790 (962) */
comment|/* 174 */
name|NdrFcLong
argument_list|(
literal|0x4007
argument_list|)
block|,
comment|/* 16391 */
comment|/* 178 */
name|NdrFcShort
argument_list|(
literal|0x30c
argument_list|)
block|,
comment|/* Offset= 780 (958) */
comment|/* 180 */
name|NdrFcLong
argument_list|(
literal|0x4008
argument_list|)
block|,
comment|/* 16392 */
comment|/* 184 */
name|NdrFcShort
argument_list|(
literal|0x30e
argument_list|)
block|,
comment|/* Offset= 782 (966) */
comment|/* 186 */
name|NdrFcLong
argument_list|(
literal|0x400d
argument_list|)
block|,
comment|/* 16397 */
comment|/* 190 */
name|NdrFcShort
argument_list|(
literal|0x30c
argument_list|)
block|,
comment|/* Offset= 780 (970) */
comment|/* 192 */
name|NdrFcLong
argument_list|(
literal|0x4009
argument_list|)
block|,
comment|/* 16393 */
comment|/* 196 */
name|NdrFcShort
argument_list|(
literal|0x30a
argument_list|)
block|,
comment|/* Offset= 778 (974) */
comment|/* 198 */
name|NdrFcLong
argument_list|(
literal|0x6000
argument_list|)
block|,
comment|/* 24576 */
comment|/* 202 */
name|NdrFcShort
argument_list|(
literal|0x308
argument_list|)
block|,
comment|/* Offset= 776 (978) */
comment|/* 204 */
name|NdrFcLong
argument_list|(
literal|0x400c
argument_list|)
block|,
comment|/* 16396 */
comment|/* 208 */
name|NdrFcShort
argument_list|(
literal|0x306
argument_list|)
block|,
comment|/* Offset= 774 (982) */
comment|/* 210 */
name|NdrFcLong
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 214 */
name|NdrFcShort
argument_list|(
literal|0x8002
argument_list|)
block|,
comment|/* Simple arm type: FC_CHAR */
comment|/* 216 */
name|NdrFcLong
argument_list|(
literal|0x12
argument_list|)
block|,
comment|/* 18 */
comment|/* 220 */
name|NdrFcShort
argument_list|(
literal|0x8006
argument_list|)
block|,
comment|/* Simple arm type: FC_SHORT */
comment|/* 222 */
name|NdrFcLong
argument_list|(
literal|0x13
argument_list|)
block|,
comment|/* 19 */
comment|/* 226 */
name|NdrFcShort
argument_list|(
literal|0x8008
argument_list|)
block|,
comment|/* Simple arm type: FC_LONG */
comment|/* 228 */
name|NdrFcLong
argument_list|(
literal|0x15
argument_list|)
block|,
comment|/* 21 */
comment|/* 232 */
name|NdrFcShort
argument_list|(
literal|0x800b
argument_list|)
block|,
comment|/* Simple arm type: FC_HYPER */
comment|/* 234 */
name|NdrFcLong
argument_list|(
literal|0x16
argument_list|)
block|,
comment|/* 22 */
comment|/* 238 */
name|NdrFcShort
argument_list|(
literal|0x8008
argument_list|)
block|,
comment|/* Simple arm type: FC_LONG */
comment|/* 240 */
name|NdrFcLong
argument_list|(
literal|0x17
argument_list|)
block|,
comment|/* 23 */
comment|/* 244 */
name|NdrFcShort
argument_list|(
literal|0x8008
argument_list|)
block|,
comment|/* Simple arm type: FC_LONG */
comment|/* 246 */
name|NdrFcLong
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 250 */
name|NdrFcShort
argument_list|(
literal|0x2e4
argument_list|)
block|,
comment|/* Offset= 740 (990) */
comment|/* 252 */
name|NdrFcLong
argument_list|(
literal|0x400e
argument_list|)
block|,
comment|/* 16398 */
comment|/* 256 */
name|NdrFcShort
argument_list|(
literal|0x2e8
argument_list|)
block|,
comment|/* Offset= 744 (1000) */
comment|/* 258 */
name|NdrFcLong
argument_list|(
literal|0x4010
argument_list|)
block|,
comment|/* 16400 */
comment|/* 262 */
name|NdrFcShort
argument_list|(
literal|0x2e6
argument_list|)
block|,
comment|/* Offset= 742 (1004) */
comment|/* 264 */
name|NdrFcLong
argument_list|(
literal|0x4012
argument_list|)
block|,
comment|/* 16402 */
comment|/* 268 */
name|NdrFcShort
argument_list|(
literal|0x2a2
argument_list|)
block|,
comment|/* Offset= 674 (942) */
comment|/* 270 */
name|NdrFcLong
argument_list|(
literal|0x4013
argument_list|)
block|,
comment|/* 16403 */
comment|/* 274 */
name|NdrFcShort
argument_list|(
literal|0x2a0
argument_list|)
block|,
comment|/* Offset= 672 (946) */
comment|/* 276 */
name|NdrFcLong
argument_list|(
literal|0x4015
argument_list|)
block|,
comment|/* 16405 */
comment|/* 280 */
name|NdrFcShort
argument_list|(
literal|0x29e
argument_list|)
block|,
comment|/* Offset= 670 (950) */
comment|/* 282 */
name|NdrFcLong
argument_list|(
literal|0x4016
argument_list|)
block|,
comment|/* 16406 */
comment|/* 286 */
name|NdrFcShort
argument_list|(
literal|0x294
argument_list|)
block|,
comment|/* Offset= 660 (946) */
comment|/* 288 */
name|NdrFcLong
argument_list|(
literal|0x4017
argument_list|)
block|,
comment|/* 16407 */
comment|/* 292 */
name|NdrFcShort
argument_list|(
literal|0x28e
argument_list|)
block|,
comment|/* Offset= 654 (946) */
comment|/* 294 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 298 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Offset= 0 (298) */
comment|/* 300 */
name|NdrFcLong
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 304 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Offset= 0 (304) */
comment|/* 306 */
name|NdrFcShort
argument_list|(
literal|0xffff
argument_list|)
block|,
comment|/* Offset= -1 (305) */
comment|/* 308 */
literal|0x15
block|,
comment|/* FC_STRUCT */
literal|0x7
block|,
comment|/* 7 */
comment|/* 310 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 312 */
literal|0xb
block|,
comment|/* FC_HYPER */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 314 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 316 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* Offset= 14 (330) */
comment|/* 318 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x1
block|,
comment|/* 1 */
comment|/* 320 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 322 */
literal|0x9
block|,
comment|/* Corr desc: FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 324 */
name|NdrFcShort
argument_list|(
literal|0xfffc
argument_list|)
block|,
comment|/* -4 */
comment|/* 326 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 328 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 330 */
literal|0x17
block|,
comment|/* FC_CSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 332 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 334 */
name|NdrFcShort
argument_list|(
literal|0xfff0
argument_list|)
block|,
comment|/* Offset= -16 (318) */
comment|/* 336 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 338 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 340 */
literal|0x2f
block|,
comment|/* FC_IP */
literal|0x5a
block|,
comment|/* FC_CONSTANT_IID */
comment|/* 342 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 346 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 348 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 350 */
literal|0xc0
block|,
comment|/* 192 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 352 */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 354 */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 356 */
literal|0x0
block|,
comment|/* 0 */
literal|0x46
block|,
comment|/* 70 */
comment|/* 358 */
literal|0x2f
block|,
comment|/* FC_IP */
literal|0x5a
block|,
comment|/* FC_CONSTANT_IID */
comment|/* 360 */
name|NdrFcLong
argument_list|(
literal|0x20400
argument_list|)
block|,
comment|/* 132096 */
comment|/* 364 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 366 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 368 */
literal|0xc0
block|,
comment|/* 192 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 370 */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 372 */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 374 */
literal|0x0
block|,
comment|/* 0 */
literal|0x46
block|,
comment|/* 70 */
comment|/* 376 */
literal|0x13
block|,
literal|0x10
block|,
comment|/* FC_OP [pointer_deref] */
comment|/* 378 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (380) */
comment|/* 380 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 382 */
name|NdrFcShort
argument_list|(
literal|0x216
argument_list|)
block|,
comment|/* Offset= 534 (916) */
comment|/* 384 */
literal|0x2a
block|,
comment|/* FC_ENCAPSULATED_UNION */
literal|0x49
block|,
comment|/* 73 */
comment|/* 386 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* 24 */
comment|/* 388 */
name|NdrFcShort
argument_list|(
literal|0xa
argument_list|)
block|,
comment|/* 10 */
comment|/* 390 */
name|NdrFcLong
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 394 */
name|NdrFcShort
argument_list|(
literal|0x5a
argument_list|)
block|,
comment|/* Offset= 90 (484) */
comment|/* 396 */
name|NdrFcLong
argument_list|(
literal|0xd
argument_list|)
block|,
comment|/* 13 */
comment|/* 400 */
name|NdrFcShort
argument_list|(
literal|0x7e
argument_list|)
block|,
comment|/* Offset= 126 (526) */
comment|/* 402 */
name|NdrFcLong
argument_list|(
literal|0x9
argument_list|)
block|,
comment|/* 9 */
comment|/* 406 */
name|NdrFcShort
argument_list|(
literal|0x9e
argument_list|)
block|,
comment|/* Offset= 158 (564) */
comment|/* 408 */
name|NdrFcLong
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* 12 */
comment|/* 412 */
name|NdrFcShort
argument_list|(
literal|0xc8
argument_list|)
block|,
comment|/* Offset= 200 (612) */
comment|/* 414 */
name|NdrFcLong
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 418 */
name|NdrFcShort
argument_list|(
literal|0x124
argument_list|)
block|,
comment|/* Offset= 292 (710) */
comment|/* 420 */
name|NdrFcLong
argument_list|(
literal|0x800d
argument_list|)
block|,
comment|/* 32781 */
comment|/* 424 */
name|NdrFcShort
argument_list|(
literal|0x140
argument_list|)
block|,
comment|/* Offset= 320 (744) */
comment|/* 426 */
name|NdrFcLong
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 430 */
name|NdrFcShort
argument_list|(
literal|0x15a
argument_list|)
block|,
comment|/* Offset= 346 (776) */
comment|/* 432 */
name|NdrFcLong
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 436 */
name|NdrFcShort
argument_list|(
literal|0x174
argument_list|)
block|,
comment|/* Offset= 372 (808) */
comment|/* 438 */
name|NdrFcLong
argument_list|(
literal|0x3
argument_list|)
block|,
comment|/* 3 */
comment|/* 442 */
name|NdrFcShort
argument_list|(
literal|0x18e
argument_list|)
block|,
comment|/* Offset= 398 (840) */
comment|/* 444 */
name|NdrFcLong
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* 20 */
comment|/* 448 */
name|NdrFcShort
argument_list|(
literal|0x1a8
argument_list|)
block|,
comment|/* Offset= 424 (872) */
comment|/* 450 */
name|NdrFcShort
argument_list|(
literal|0xffff
argument_list|)
block|,
comment|/* Offset= -1 (449) */
comment|/* 452 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 454 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 456 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 458 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 460 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 462 */
literal|0x4b
block|,
comment|/* FC_PP */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 464 */
literal|0x48
block|,
comment|/* FC_VARIABLE_REPEAT */
literal|0x49
block|,
comment|/* FC_FIXED_OFFSET */
comment|/* 466 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 468 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 470 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 472 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 474 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 476 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 478 */
name|NdrFcShort
argument_list|(
literal|0xff6c
argument_list|)
block|,
comment|/* Offset= -148 (330) */
comment|/* 480 */
literal|0x5b
block|,
comment|/* FC_END */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 482 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 484 */
literal|0x16
block|,
comment|/* FC_PSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 486 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 488 */
literal|0x4b
block|,
comment|/* FC_PP */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 490 */
literal|0x46
block|,
comment|/* FC_NO_REPEAT */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 492 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 494 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 496 */
literal|0x11
block|,
literal|0x0
block|,
comment|/* FC_RP */
comment|/* 498 */
name|NdrFcShort
argument_list|(
literal|0xffd2
argument_list|)
block|,
comment|/* Offset= -46 (452) */
comment|/* 500 */
literal|0x5b
block|,
comment|/* FC_END */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 502 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 504 */
literal|0x21
block|,
comment|/* FC_BOGUS_ARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 506 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 508 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 510 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 512 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 514 */
name|NdrFcLong
argument_list|(
literal|0xffffffff
argument_list|)
block|,
comment|/* -1 */
comment|/* 518 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Corr flags:  */
comment|/* 520 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 522 */
name|NdrFcShort
argument_list|(
literal|0xff4a
argument_list|)
block|,
comment|/* Offset= -182 (340) */
comment|/* 524 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 526 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 528 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 530 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 532 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* Offset= 6 (538) */
comment|/* 534 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x36
block|,
comment|/* FC_POINTER */
comment|/* 536 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 538 */
literal|0x11
block|,
literal|0x0
block|,
comment|/* FC_RP */
comment|/* 540 */
name|NdrFcShort
argument_list|(
literal|0xffdc
argument_list|)
block|,
comment|/* Offset= -36 (504) */
comment|/* 542 */
literal|0x21
block|,
comment|/* FC_BOGUS_ARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 544 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 546 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 548 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 550 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 552 */
name|NdrFcLong
argument_list|(
literal|0xffffffff
argument_list|)
block|,
comment|/* -1 */
comment|/* 556 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Corr flags:  */
comment|/* 558 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 560 */
name|NdrFcShort
argument_list|(
literal|0xff36
argument_list|)
block|,
comment|/* Offset= -202 (358) */
comment|/* 562 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 564 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 566 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 568 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 570 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* Offset= 6 (576) */
comment|/* 572 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x36
block|,
comment|/* FC_POINTER */
comment|/* 574 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 576 */
literal|0x11
block|,
literal|0x0
block|,
comment|/* FC_RP */
comment|/* 578 */
name|NdrFcShort
argument_list|(
literal|0xffdc
argument_list|)
block|,
comment|/* Offset= -36 (542) */
comment|/* 580 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 582 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 584 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 586 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 588 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 590 */
literal|0x4b
block|,
comment|/* FC_PP */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 592 */
literal|0x48
block|,
comment|/* FC_VARIABLE_REPEAT */
literal|0x49
block|,
comment|/* FC_FIXED_OFFSET */
comment|/* 594 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 596 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 598 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 600 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 602 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 604 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 606 */
name|NdrFcShort
argument_list|(
literal|0x192
argument_list|)
block|,
comment|/* Offset= 402 (1008) */
comment|/* 608 */
literal|0x5b
block|,
comment|/* FC_END */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 610 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 612 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 614 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 616 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 618 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* Offset= 6 (624) */
comment|/* 620 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x36
block|,
comment|/* FC_POINTER */
comment|/* 622 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 624 */
literal|0x11
block|,
literal|0x0
block|,
comment|/* FC_RP */
comment|/* 626 */
name|NdrFcShort
argument_list|(
literal|0xffd2
argument_list|)
block|,
comment|/* Offset= -46 (580) */
comment|/* 628 */
literal|0x2f
block|,
comment|/* FC_IP */
literal|0x5a
block|,
comment|/* FC_CONSTANT_IID */
comment|/* 630 */
name|NdrFcLong
argument_list|(
literal|0x2f
argument_list|)
block|,
comment|/* 47 */
comment|/* 634 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 636 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 638 */
literal|0xc0
block|,
comment|/* 192 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 640 */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 642 */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 644 */
literal|0x0
block|,
comment|/* 0 */
literal|0x46
block|,
comment|/* 70 */
comment|/* 646 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x0
block|,
comment|/* 0 */
comment|/* 648 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 650 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 652 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 654 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 656 */
literal|0x1
block|,
comment|/* FC_BYTE */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 658 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 660 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 662 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 664 */
name|NdrFcShort
argument_list|(
literal|0xa
argument_list|)
block|,
comment|/* Offset= 10 (674) */
comment|/* 666 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 668 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 670 */
name|NdrFcShort
argument_list|(
literal|0xffd6
argument_list|)
block|,
comment|/* Offset= -42 (628) */
comment|/* 672 */
literal|0x36
block|,
comment|/* FC_POINTER */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 674 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 676 */
name|NdrFcShort
argument_list|(
literal|0xffe2
argument_list|)
block|,
comment|/* Offset= -30 (646) */
comment|/* 678 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 680 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 682 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 684 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 686 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 688 */
literal|0x4b
block|,
comment|/* FC_PP */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 690 */
literal|0x48
block|,
comment|/* FC_VARIABLE_REPEAT */
literal|0x49
block|,
comment|/* FC_FIXED_OFFSET */
comment|/* 692 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 694 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 696 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 698 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 700 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 702 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 704 */
name|NdrFcShort
argument_list|(
literal|0xffd2
argument_list|)
block|,
comment|/* Offset= -46 (658) */
comment|/* 706 */
literal|0x5b
block|,
comment|/* FC_END */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 708 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 710 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 712 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 714 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 716 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* Offset= 6 (722) */
comment|/* 718 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x36
block|,
comment|/* FC_POINTER */
comment|/* 720 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 722 */
literal|0x11
block|,
literal|0x0
block|,
comment|/* FC_RP */
comment|/* 724 */
name|NdrFcShort
argument_list|(
literal|0xffd2
argument_list|)
block|,
comment|/* Offset= -46 (678) */
comment|/* 726 */
literal|0x1d
block|,
comment|/* FC_SMFARRAY */
literal|0x0
block|,
comment|/* 0 */
comment|/* 728 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 730 */
literal|0x1
block|,
comment|/* FC_BYTE */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 732 */
literal|0x15
block|,
comment|/* FC_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 734 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 736 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x6
block|,
comment|/* FC_SHORT */
comment|/* 738 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
comment|/* 740 */
literal|0x0
block|,
comment|/* 0 */
name|NdrFcShort
argument_list|(
literal|0xfff1
argument_list|)
block|,
comment|/* Offset= -15 (726) */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 744 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 746 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* 24 */
comment|/* 748 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 750 */
name|NdrFcShort
argument_list|(
literal|0xa
argument_list|)
block|,
comment|/* Offset= 10 (760) */
comment|/* 752 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x36
block|,
comment|/* FC_POINTER */
comment|/* 754 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 756 */
name|NdrFcShort
argument_list|(
literal|0xffe8
argument_list|)
block|,
comment|/* Offset= -24 (732) */
comment|/* 758 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 760 */
literal|0x11
block|,
literal|0x0
block|,
comment|/* FC_RP */
comment|/* 762 */
name|NdrFcShort
argument_list|(
literal|0xfefe
argument_list|)
block|,
comment|/* Offset= -258 (504) */
comment|/* 764 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x0
block|,
comment|/* 0 */
comment|/* 766 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 768 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 770 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 772 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 774 */
literal|0x1
block|,
comment|/* FC_BYTE */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 776 */
literal|0x16
block|,
comment|/* FC_PSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 778 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 780 */
literal|0x4b
block|,
comment|/* FC_PP */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 782 */
literal|0x46
block|,
comment|/* FC_NO_REPEAT */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 784 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 786 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 788 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 790 */
name|NdrFcShort
argument_list|(
literal|0xffe6
argument_list|)
block|,
comment|/* Offset= -26 (764) */
comment|/* 792 */
literal|0x5b
block|,
comment|/* FC_END */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 794 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 796 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x1
block|,
comment|/* 1 */
comment|/* 798 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 800 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 802 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 804 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 806 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 808 */
literal|0x16
block|,
comment|/* FC_PSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 810 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 812 */
literal|0x4b
block|,
comment|/* FC_PP */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 814 */
literal|0x46
block|,
comment|/* FC_NO_REPEAT */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 816 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 818 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 820 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 822 */
name|NdrFcShort
argument_list|(
literal|0xffe6
argument_list|)
block|,
comment|/* Offset= -26 (796) */
comment|/* 824 */
literal|0x5b
block|,
comment|/* FC_END */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 826 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 828 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 830 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 832 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 834 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 836 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 838 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 840 */
literal|0x16
block|,
comment|/* FC_PSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 842 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 844 */
literal|0x4b
block|,
comment|/* FC_PP */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 846 */
literal|0x46
block|,
comment|/* FC_NO_REPEAT */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 848 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 850 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 852 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 854 */
name|NdrFcShort
argument_list|(
literal|0xffe6
argument_list|)
block|,
comment|/* Offset= -26 (828) */
comment|/* 856 */
literal|0x5b
block|,
comment|/* FC_END */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 858 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 860 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x7
block|,
comment|/* 7 */
comment|/* 862 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 864 */
literal|0x19
block|,
comment|/* Corr desc:  field pointer, FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 866 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 868 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 870 */
literal|0xb
block|,
comment|/* FC_HYPER */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 872 */
literal|0x16
block|,
comment|/* FC_PSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 874 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 876 */
literal|0x4b
block|,
comment|/* FC_PP */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 878 */
literal|0x46
block|,
comment|/* FC_NO_REPEAT */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 880 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 882 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 884 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 886 */
name|NdrFcShort
argument_list|(
literal|0xffe6
argument_list|)
block|,
comment|/* Offset= -26 (860) */
comment|/* 888 */
literal|0x5b
block|,
comment|/* FC_END */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 890 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 892 */
literal|0x15
block|,
comment|/* FC_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 894 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 896 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 898 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 900 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 902 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 904 */
literal|0x7
block|,
comment|/* Corr desc: FC_USHORT */
literal|0x0
block|,
comment|/*  */
comment|/* 906 */
name|NdrFcShort
argument_list|(
literal|0xffd8
argument_list|)
block|,
comment|/* -40 */
comment|/* 908 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 910 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 912 */
name|NdrFcShort
argument_list|(
literal|0xffec
argument_list|)
block|,
comment|/* Offset= -20 (892) */
comment|/* 914 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 916 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 918 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* 40 */
comment|/* 920 */
name|NdrFcShort
argument_list|(
literal|0xffec
argument_list|)
block|,
comment|/* Offset= -20 (900) */
comment|/* 922 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Offset= 0 (922) */
comment|/* 924 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x6
block|,
comment|/* FC_SHORT */
comment|/* 926 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 928 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 930 */
name|NdrFcShort
argument_list|(
literal|0xfdde
argument_list|)
block|,
comment|/* Offset= -546 (384) */
comment|/* 932 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 934 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 936 */
name|NdrFcShort
argument_list|(
literal|0xfeea
argument_list|)
block|,
comment|/* Offset= -278 (658) */
comment|/* 938 */
literal|0x13
block|,
literal|0x8
block|,
comment|/* FC_OP [simple_pointer] */
comment|/* 940 */
literal|0x1
block|,
comment|/* FC_BYTE */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 942 */
literal|0x13
block|,
literal|0x8
block|,
comment|/* FC_OP [simple_pointer] */
comment|/* 944 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 946 */
literal|0x13
block|,
literal|0x8
block|,
comment|/* FC_OP [simple_pointer] */
comment|/* 948 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 950 */
literal|0x13
block|,
literal|0x8
block|,
comment|/* FC_OP [simple_pointer] */
comment|/* 952 */
literal|0xb
block|,
comment|/* FC_HYPER */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 954 */
literal|0x13
block|,
literal|0x8
block|,
comment|/* FC_OP [simple_pointer] */
comment|/* 956 */
literal|0xa
block|,
comment|/* FC_FLOAT */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 958 */
literal|0x13
block|,
literal|0x8
block|,
comment|/* FC_OP [simple_pointer] */
comment|/* 960 */
literal|0xc
block|,
comment|/* FC_DOUBLE */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 962 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 964 */
name|NdrFcShort
argument_list|(
literal|0xfd70
argument_list|)
block|,
comment|/* Offset= -656 (308) */
comment|/* 966 */
literal|0x13
block|,
literal|0x10
block|,
comment|/* FC_OP [pointer_deref] */
comment|/* 968 */
name|NdrFcShort
argument_list|(
literal|0xfd72
argument_list|)
block|,
comment|/* Offset= -654 (314) */
comment|/* 970 */
literal|0x13
block|,
literal|0x10
block|,
comment|/* FC_OP [pointer_deref] */
comment|/* 972 */
name|NdrFcShort
argument_list|(
literal|0xfd88
argument_list|)
block|,
comment|/* Offset= -632 (340) */
comment|/* 974 */
literal|0x13
block|,
literal|0x10
block|,
comment|/* FC_OP [pointer_deref] */
comment|/* 976 */
name|NdrFcShort
argument_list|(
literal|0xfd96
argument_list|)
block|,
comment|/* Offset= -618 (358) */
comment|/* 978 */
literal|0x13
block|,
literal|0x10
block|,
comment|/* FC_OP [pointer_deref] */
comment|/* 980 */
name|NdrFcShort
argument_list|(
literal|0xfda4
argument_list|)
block|,
comment|/* Offset= -604 (376) */
comment|/* 982 */
literal|0x13
block|,
literal|0x10
block|,
comment|/* FC_OP [pointer_deref] */
comment|/* 984 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (986) */
comment|/* 986 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 988 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* Offset= 20 (1008) */
comment|/* 990 */
literal|0x15
block|,
comment|/* FC_STRUCT */
literal|0x7
block|,
comment|/* 7 */
comment|/* 992 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 994 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x1
block|,
comment|/* FC_BYTE */
comment|/* 996 */
literal|0x1
block|,
comment|/* FC_BYTE */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 998 */
literal|0xb
block|,
comment|/* FC_HYPER */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 1000 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 1002 */
name|NdrFcShort
argument_list|(
literal|0xfff4
argument_list|)
block|,
comment|/* Offset= -12 (990) */
comment|/* 1004 */
literal|0x13
block|,
literal|0x8
block|,
comment|/* FC_OP [simple_pointer] */
comment|/* 1006 */
literal|0x2
block|,
comment|/* FC_CHAR */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 1008 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x7
block|,
comment|/* 7 */
comment|/* 1010 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* 32 */
comment|/* 1012 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 1014 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Offset= 0 (1014) */
comment|/* 1016 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 1018 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x6
block|,
comment|/* FC_SHORT */
comment|/* 1020 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x6
block|,
comment|/* FC_SHORT */
comment|/* 1022 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 1024 */
name|NdrFcShort
argument_list|(
literal|0xfc0a
argument_list|)
block|,
comment|/* Offset= -1014 (10) */
comment|/* 1026 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 1028 */
literal|0xb4
block|,
comment|/* FC_USER_MARSHAL */
literal|0x83
block|,
comment|/* 131 */
comment|/* 1030 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 1032 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 1034 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 1036 */
name|NdrFcShort
argument_list|(
literal|0xfbfa
argument_list|)
block|,
comment|/* Offset= -1030 (6) */
comment|/* 1038 */
literal|0x12
block|,
literal|0x0
block|,
comment|/* FC_UP */
comment|/* 1040 */
name|NdrFcShort
argument_list|(
literal|0xffe0
argument_list|)
block|,
comment|/* Offset= -32 (1008) */
comment|/* 1042 */
literal|0xb4
block|,
comment|/* FC_USER_MARSHAL */
literal|0x83
block|,
comment|/* 131 */
comment|/* 1044 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 1046 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 1048 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 1050 */
name|NdrFcShort
argument_list|(
literal|0xfff4
argument_list|)
block|,
comment|/* Offset= -12 (1038) */
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
name|VARIANT_UserSize
block|,
name|VARIANT_UserMarshal
block|,
name|VARIANT_UserUnmarshal
block|,
name|VARIANT_UserFree
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Object interface: IUnknown, ver. 0.0,    GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */
end_comment
begin_comment
comment|/* Object interface: IAccessibleValue, ver. 0.0,    GUID={0x35855B5B,0xC566,0x4fd0,{0xA7,0xB1,0xE6,0x54,0x65,0x60,0x03,0x94}} */
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
DECL|variable|IAccessibleValue_FormatStringOffsetTable
specifier|static
specifier|const
name|unsigned
name|short
name|IAccessibleValue_FormatStringOffsetTable
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
DECL|variable|IAccessibleValue_ProxyInfo
specifier|static
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleValue_ProxyInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
name|AccessibleValue__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleValue_FormatStringOffsetTable
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
DECL|variable|IAccessibleValue_ServerInfo
specifier|static
specifier|const
name|MIDL_SERVER_INFO
name|IAccessibleValue_ServerInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
literal|0
block|,
name|AccessibleValue__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleValue_FormatStringOffsetTable
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
name|_IAccessibleValueProxyVtbl
operator|=
block|{
operator|&
name|IAccessibleValue_ProxyInfo
block|,
operator|&
name|IID_IAccessibleValue
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
comment|/* IAccessibleValue::get_currentValue */
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
comment|/* IAccessibleValue::setCurrentValue */
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
comment|/* IAccessibleValue::get_maximumValue */
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
comment|/* IAccessibleValue::get_minimumValue */
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|_IAccessibleValueStubVtbl
specifier|const
name|CInterfaceStubVtbl
name|_IAccessibleValueStubVtbl
init|=
block|{
operator|&
name|IID_IAccessibleValue
block|,
operator|&
name|IAccessibleValue_ServerInfo
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
name|AccessibleValue__MIDL_TypeFormatString
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
DECL|variable|_AccessibleValue_ProxyVtblList
specifier|const
name|CInterfaceProxyVtbl
modifier|*
specifier|const
name|_AccessibleValue_ProxyVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceProxyVtbl
operator|*
operator|)
operator|&
name|_IAccessibleValueProxyVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleValue_StubVtblList
specifier|const
name|CInterfaceStubVtbl
modifier|*
specifier|const
name|_AccessibleValue_StubVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceStubVtbl
operator|*
operator|)
operator|&
name|_IAccessibleValueStubVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleValue_InterfaceNamesList
name|PCInterfaceName
specifier|const
name|_AccessibleValue_InterfaceNamesList
index|[]
init|=
block|{
literal|"IAccessibleValue"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|_AccessibleValue_CHECK_IID
define|#
directive|define
name|_AccessibleValue_CHECK_IID
parameter_list|(
name|n
parameter_list|)
value|IID_GENERIC_CHECK_IID( _AccessibleValue, pIID, n)
end_define
begin_function
DECL|function|_AccessibleValue_IID_Lookup
name|int
name|__stdcall
name|_AccessibleValue_IID_Lookup
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
name|_AccessibleValue_CHECK_IID
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
DECL|variable|AccessibleValue_ProxyFileInfo
specifier|const
name|ExtendedProxyFileInfo
name|AccessibleValue_ProxyFileInfo
init|=
block|{
operator|(
name|PCInterfaceProxyVtblList
operator|*
operator|)
operator|&
name|_AccessibleValue_ProxyVtblList
block|,
operator|(
name|PCInterfaceStubVtblList
operator|*
operator|)
operator|&
name|_AccessibleValue_StubVtblList
block|,
operator|(
specifier|const
name|PCInterfaceName
operator|*
operator|)
operator|&
name|_AccessibleValue_InterfaceNamesList
block|,
literal|0
block|,
comment|/* no delegation */
operator|&
name|_AccessibleValue_IID_Lookup
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
