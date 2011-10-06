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
comment|/* Compiler settings for AccessibleText.idl:     Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
file|"AccessibleText.h"
end_include
begin_define
DECL|macro|TYPE_FORMAT_STRING_SIZE
define|#
directive|define
name|TYPE_FORMAT_STRING_SIZE
value|67
end_define
begin_define
DECL|macro|PROC_FORMAT_STRING_SIZE
define|#
directive|define
name|PROC_FORMAT_STRING_SIZE
value|901
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
DECL|struct|_AccessibleText_MIDL_TYPE_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleText_MIDL_TYPE_FORMAT_STRING
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
DECL|typedef|AccessibleText_MIDL_TYPE_FORMAT_STRING
name|AccessibleText_MIDL_TYPE_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleText_MIDL_PROC_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleText_MIDL_PROC_FORMAT_STRING
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
DECL|typedef|AccessibleText_MIDL_PROC_FORMAT_STRING
name|AccessibleText_MIDL_PROC_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleText_MIDL_EXPR_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleText_MIDL_EXPR_FORMAT_STRING
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
DECL|typedef|AccessibleText_MIDL_EXPR_FORMAT_STRING
name|AccessibleText_MIDL_EXPR_FORMAT_STRING
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
name|AccessibleText_MIDL_TYPE_FORMAT_STRING
name|AccessibleText__MIDL_TypeFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleText_MIDL_PROC_FORMAT_STRING
name|AccessibleText__MIDL_ProcFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleText_MIDL_EXPR_FORMAT_STRING
name|AccessibleText__MIDL_ExprFormatString
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
name|IAccessibleText_ServerInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleText_ProxyInfo
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
DECL|variable|AccessibleText__MIDL_ProcFormatString
specifier|static
specifier|const
name|AccessibleText_MIDL_PROC_FORMAT_STRING
name|AccessibleText__MIDL_ProcFormatString
init|=
block|{
literal|0
block|,
block|{
comment|/* Procedure addSelection */
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
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 10 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 12 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 14 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 16 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 18 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
comment|/* Parameter startOffset */
comment|/* 24 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 26 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 28 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 30 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
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
comment|/* Return value */
comment|/* 36 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 38 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 40 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_attributes */
comment|/* 42 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 44 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 48 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 50 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* x86 Stack size/offset = 24 */
comment|/* 52 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 54 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 56 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x5
block|,
comment|/* 5 */
comment|/* 58 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 60 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 62 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 64 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 66 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 68 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 70 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 72 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 74 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 76 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 78 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 80 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 82 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter textAttributes */
comment|/* 84 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 86 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 88 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 90 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 92 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 94 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_caretOffset */
comment|/* 96 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 98 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 102 */
name|NdrFcShort
argument_list|(
literal|0x5
argument_list|)
block|,
comment|/* 5 */
comment|/* 104 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 106 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 108 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 110 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 112 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 114 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 116 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 118 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 120 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 122 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 124 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 126 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 128 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 130 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_characterExtents */
comment|/* 132 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 134 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 138 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* 6 */
comment|/* 140 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* x86 Stack size/offset = 32 */
comment|/* 142 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 144 */
name|NdrFcShort
argument_list|(
literal|0x78
argument_list|)
block|,
comment|/* 120 */
comment|/* 146 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x7
block|,
comment|/* 7 */
comment|/* 148 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 150 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 152 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 154 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 156 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 158 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 160 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter coordType */
comment|/* 162 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 164 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 166 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter x */
comment|/* 168 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 170 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 172 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter y */
comment|/* 174 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 176 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 178 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter width */
comment|/* 180 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 182 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 184 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter height */
comment|/* 186 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 188 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* x86 Stack size/offset = 24 */
comment|/* 190 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 192 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 194 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* x86 Stack size/offset = 28 */
comment|/* 196 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_nSelections */
comment|/* 198 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 200 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 204 */
name|NdrFcShort
argument_list|(
literal|0x7
argument_list|)
block|,
comment|/* 7 */
comment|/* 206 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 208 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 210 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 212 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 214 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 216 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 218 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 220 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter nSelections */
comment|/* 222 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 224 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 226 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 228 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 230 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 232 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_offsetAtPoint */
comment|/* 234 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 236 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 240 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 242 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* x86 Stack size/offset = 24 */
comment|/* 244 */
name|NdrFcShort
argument_list|(
literal|0x16
argument_list|)
block|,
comment|/* 22 */
comment|/* 246 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 248 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x5
block|,
comment|/* 5 */
comment|/* 250 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 252 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 254 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 256 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter x */
comment|/* 258 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 260 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 262 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter y */
comment|/* 264 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 266 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 268 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter coordType */
comment|/* 270 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 272 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 274 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 276 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 278 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 280 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 282 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 284 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 286 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_selection */
comment|/* 288 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 290 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 294 */
name|NdrFcShort
argument_list|(
literal|0x9
argument_list|)
block|,
comment|/* 9 */
comment|/* 296 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 298 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 300 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 302 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 304 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 306 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 308 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 310 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter selectionIndex */
comment|/* 312 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 314 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 316 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 318 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 320 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 322 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 324 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 326 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 328 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 330 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 332 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 334 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_text */
comment|/* 336 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 338 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 342 */
name|NdrFcShort
argument_list|(
literal|0xa
argument_list|)
block|,
comment|/* 10 */
comment|/* 344 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 346 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 348 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 350 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 352 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 354 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 356 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 358 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 360 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 362 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 364 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 366 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 368 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 370 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 372 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 374 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 376 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 378 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 380 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 382 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_textBeforeOffset */
comment|/* 384 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 386 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 390 */
name|NdrFcShort
argument_list|(
literal|0xb
argument_list|)
block|,
comment|/* 11 */
comment|/* 392 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* x86 Stack size/offset = 28 */
comment|/* 394 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 396 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 398 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x6
block|,
comment|/* 6 */
comment|/* 400 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 402 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 404 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 406 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 408 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 410 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 412 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter boundaryType */
comment|/* 414 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 416 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 418 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 420 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 422 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 424 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 426 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 428 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 430 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 432 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 434 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 436 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 438 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 440 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* x86 Stack size/offset = 24 */
comment|/* 442 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_textAfterOffset */
comment|/* 444 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 446 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 450 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* 12 */
comment|/* 452 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* x86 Stack size/offset = 28 */
comment|/* 454 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 456 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 458 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x6
block|,
comment|/* 6 */
comment|/* 460 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 462 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 464 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 466 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 468 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 470 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 472 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter boundaryType */
comment|/* 474 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 476 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 478 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 480 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 482 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 484 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 486 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 488 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 490 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 492 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 494 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 496 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 498 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 500 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* x86 Stack size/offset = 24 */
comment|/* 502 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_textAtOffset */
comment|/* 504 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 506 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 510 */
name|NdrFcShort
argument_list|(
literal|0xd
argument_list|)
block|,
comment|/* 13 */
comment|/* 512 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* x86 Stack size/offset = 28 */
comment|/* 514 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 516 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 518 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x6
block|,
comment|/* 6 */
comment|/* 520 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 522 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 524 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 526 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 528 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 530 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 532 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter boundaryType */
comment|/* 534 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 536 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 538 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 540 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 542 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 544 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 546 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 548 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 550 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 552 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 554 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 556 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 558 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 560 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* x86 Stack size/offset = 24 */
comment|/* 562 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure removeSelection */
comment|/* 564 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 566 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 570 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 572 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 574 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 576 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 578 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 580 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 582 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 584 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 586 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter selectionIndex */
comment|/* 588 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 590 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 592 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 594 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 596 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 598 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure setCaretOffset */
comment|/* 600 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 602 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 606 */
name|NdrFcShort
argument_list|(
literal|0xf
argument_list|)
block|,
comment|/* 15 */
comment|/* 608 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 610 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 612 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 614 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 616 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 618 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 620 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 622 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 624 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 626 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 628 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 630 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 632 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 634 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure setSelection */
comment|/* 636 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 638 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 642 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 644 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 646 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* 24 */
comment|/* 648 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 650 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 652 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 654 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 656 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 658 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter selectionIndex */
comment|/* 660 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 662 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 664 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 666 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 668 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 670 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 672 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 674 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 676 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 678 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 680 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 682 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_nCharacters */
comment|/* 684 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 686 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 690 */
name|NdrFcShort
argument_list|(
literal|0x11
argument_list|)
block|,
comment|/* 17 */
comment|/* 692 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
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
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 698 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 700 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 702 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 704 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 706 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter nCharacters */
comment|/* 708 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 710 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 712 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 714 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 716 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 718 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure scrollSubstringTo */
comment|/* 720 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 722 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 726 */
name|NdrFcShort
argument_list|(
literal|0x12
argument_list|)
block|,
comment|/* 18 */
comment|/* 728 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 730 */
name|NdrFcShort
argument_list|(
literal|0x16
argument_list|)
block|,
comment|/* 22 */
comment|/* 732 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 734 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 736 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 738 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 740 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 742 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter startIndex */
comment|/* 744 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 746 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 748 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endIndex */
comment|/* 750 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 752 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 754 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter scrollType */
comment|/* 756 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 758 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 760 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 762 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 764 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 766 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure scrollSubstringToPoint */
comment|/* 768 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 770 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 774 */
name|NdrFcShort
argument_list|(
literal|0x13
argument_list|)
block|,
comment|/* 19 */
comment|/* 776 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* x86 Stack size/offset = 28 */
comment|/* 778 */
name|NdrFcShort
argument_list|(
literal|0x26
argument_list|)
block|,
comment|/* 38 */
comment|/* 780 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 782 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x6
block|,
comment|/* 6 */
comment|/* 784 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 786 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 788 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 790 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter startIndex */
comment|/* 792 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 794 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 796 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endIndex */
comment|/* 798 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 800 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 802 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter coordinateType */
comment|/* 804 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 806 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 808 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter x */
comment|/* 810 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 812 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 814 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter y */
comment|/* 816 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 818 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
comment|/* 820 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 822 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 824 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* x86 Stack size/offset = 24 */
comment|/* 826 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_newText */
comment|/* 828 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 830 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 834 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* 20 */
comment|/* 836 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 838 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 840 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 842 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 844 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 846 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 848 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 850 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter newText */
comment|/* 852 */
name|NdrFcShort
argument_list|(
literal|0x4113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
comment|/* 854 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 856 */
name|NdrFcShort
argument_list|(
literal|0x32
argument_list|)
block|,
comment|/* Type Offset=50 */
comment|/* Return value */
comment|/* 858 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 860 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 862 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_oldText */
comment|/* 864 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 866 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 870 */
name|NdrFcShort
argument_list|(
literal|0x15
argument_list|)
block|,
comment|/* 21 */
comment|/* 872 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 874 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 876 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 878 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 880 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 882 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 884 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 886 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter oldText */
comment|/* 888 */
name|NdrFcShort
argument_list|(
literal|0x4113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
comment|/* 890 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 892 */
name|NdrFcShort
argument_list|(
literal|0x32
argument_list|)
block|,
comment|/* Type Offset=50 */
comment|/* Return value */
comment|/* 894 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 896 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 898 */
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
DECL|variable|AccessibleText__MIDL_TypeFormatString
specifier|static
specifier|const
name|AccessibleText_MIDL_TYPE_FORMAT_STRING
name|AccessibleText__MIDL_TypeFormatString
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
literal|0xc
block|,
comment|/* FC_RP [alloced_on_stack] [simple_pointer] */
comment|/*  4 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/*  6 */
literal|0x11
block|,
literal|0x4
block|,
comment|/* FC_RP [alloced_on_stack] */
comment|/*  8 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* Offset= 28 (36) */
comment|/* 10 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 12 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* Offset= 14 (26) */
comment|/* 14 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x1
block|,
comment|/* 1 */
comment|/* 16 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 18 */
literal|0x9
block|,
comment|/* Corr desc: FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 20 */
name|NdrFcShort
argument_list|(
literal|0xfffc
argument_list|)
block|,
comment|/* -4 */
comment|/* 22 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 24 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 26 */
literal|0x17
block|,
comment|/* FC_CSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 28 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 30 */
name|NdrFcShort
argument_list|(
literal|0xfff0
argument_list|)
block|,
comment|/* Offset= -16 (14) */
comment|/* 32 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 34 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 36 */
literal|0xb4
block|,
comment|/* FC_USER_MARSHAL */
literal|0x83
block|,
comment|/* 131 */
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
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 42 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 44 */
name|NdrFcShort
argument_list|(
literal|0xffde
argument_list|)
block|,
comment|/* Offset= -34 (10) */
comment|/* 46 */
literal|0x11
block|,
literal|0x4
block|,
comment|/* FC_RP [alloced_on_stack] */
comment|/* 48 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (50) */
comment|/* 50 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 52 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* 12 */
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
literal|0x0
argument_list|)
block|,
comment|/* Offset= 0 (56) */
comment|/* 58 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 60 */
name|NdrFcShort
argument_list|(
literal|0xffe8
argument_list|)
block|,
comment|/* Offset= -24 (36) */
comment|/* 62 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 64 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
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
comment|/* Standard interface: __MIDL_itf_AccessibleText_0000_0000, ver. 0.0,    GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */
end_comment
begin_comment
comment|/* Object interface: IUnknown, ver. 0.0,    GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */
end_comment
begin_comment
comment|/* Object interface: IAccessibleText, ver. 0.0,    GUID={0x24FD2FFB,0x3AAD,0x4a08,{0x83,0x35,0xA3,0xAD,0x89,0xC0,0xFB,0x4B}} */
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
DECL|variable|IAccessibleText_FormatStringOffsetTable
specifier|static
specifier|const
name|unsigned
name|short
name|IAccessibleText_FormatStringOffsetTable
index|[]
init|=
block|{
literal|0
block|,
literal|42
block|,
literal|96
block|,
literal|132
block|,
literal|198
block|,
literal|234
block|,
literal|288
block|,
literal|336
block|,
literal|384
block|,
literal|444
block|,
literal|504
block|,
literal|564
block|,
literal|600
block|,
literal|636
block|,
literal|684
block|,
literal|720
block|,
literal|768
block|,
literal|828
block|,
literal|864
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|IAccessibleText_ProxyInfo
specifier|static
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleText_ProxyInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
name|AccessibleText__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleText_FormatStringOffsetTable
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
DECL|variable|IAccessibleText_ServerInfo
specifier|static
specifier|const
name|MIDL_SERVER_INFO
name|IAccessibleText_ServerInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
literal|0
block|,
name|AccessibleText__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleText_FormatStringOffsetTable
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
literal|22
argument_list|)
end_macro
begin_expr_stmt
name|_IAccessibleTextProxyVtbl
operator|=
block|{
operator|&
name|IAccessibleText_ProxyInfo
block|,
operator|&
name|IID_IAccessibleText
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
comment|/* IAccessibleText::addSelection */
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
comment|/* IAccessibleText::get_attributes */
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
comment|/* IAccessibleText::get_caretOffset */
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
comment|/* IAccessibleText::get_characterExtents */
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
comment|/* IAccessibleText::get_nSelections */
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
comment|/* IAccessibleText::get_offsetAtPoint */
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
comment|/* IAccessibleText::get_selection */
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
comment|/* IAccessibleText::get_text */
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
comment|/* IAccessibleText::get_textBeforeOffset */
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
comment|/* IAccessibleText::get_textAfterOffset */
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
comment|/* IAccessibleText::get_textAtOffset */
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
comment|/* IAccessibleText::removeSelection */
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
comment|/* IAccessibleText::setCaretOffset */
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
comment|/* IAccessibleText::setSelection */
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
comment|/* IAccessibleText::get_nCharacters */
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
comment|/* IAccessibleText::scrollSubstringTo */
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
comment|/* IAccessibleText::scrollSubstringToPoint */
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
comment|/* IAccessibleText::get_newText */
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
comment|/* IAccessibleText::get_oldText */
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|_IAccessibleTextStubVtbl
specifier|const
name|CInterfaceStubVtbl
name|_IAccessibleTextStubVtbl
init|=
block|{
operator|&
name|IID_IAccessibleText
block|,
operator|&
name|IAccessibleText_ServerInfo
block|,
literal|22
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
name|AccessibleText__MIDL_TypeFormatString
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
DECL|variable|_AccessibleText_ProxyVtblList
specifier|const
name|CInterfaceProxyVtbl
modifier|*
specifier|const
name|_AccessibleText_ProxyVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceProxyVtbl
operator|*
operator|)
operator|&
name|_IAccessibleTextProxyVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleText_StubVtblList
specifier|const
name|CInterfaceStubVtbl
modifier|*
specifier|const
name|_AccessibleText_StubVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceStubVtbl
operator|*
operator|)
operator|&
name|_IAccessibleTextStubVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleText_InterfaceNamesList
name|PCInterfaceName
specifier|const
name|_AccessibleText_InterfaceNamesList
index|[]
init|=
block|{
literal|"IAccessibleText"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|_AccessibleText_CHECK_IID
define|#
directive|define
name|_AccessibleText_CHECK_IID
parameter_list|(
name|n
parameter_list|)
value|IID_GENERIC_CHECK_IID( _AccessibleText, pIID, n)
end_define
begin_function
DECL|function|_AccessibleText_IID_Lookup
name|int
name|__stdcall
name|_AccessibleText_IID_Lookup
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
name|_AccessibleText_CHECK_IID
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
DECL|variable|AccessibleText_ProxyFileInfo
specifier|const
name|ExtendedProxyFileInfo
name|AccessibleText_ProxyFileInfo
init|=
block|{
operator|(
name|PCInterfaceProxyVtblList
operator|*
operator|)
operator|&
name|_AccessibleText_ProxyVtblList
block|,
operator|(
name|PCInterfaceStubVtblList
operator|*
operator|)
operator|&
name|_AccessibleText_StubVtblList
block|,
operator|(
specifier|const
name|PCInterfaceName
operator|*
operator|)
operator|&
name|_AccessibleText_InterfaceNamesList
block|,
literal|0
block|,
comment|/* no delegation */
operator|&
name|_AccessibleText_IID_Lookup
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
