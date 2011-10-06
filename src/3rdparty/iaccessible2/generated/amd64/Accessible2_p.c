begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the proxy stub code */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:56 2012  */
end_comment
begin_comment
comment|/* Compiler settings for Accessible2.idl:     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
end_comment
begin_comment
comment|/* @@MIDL_FILE_HEADING(  ) */
end_comment
begin_if
if|#
directive|if
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
file|"Accessible2.h"
end_include
begin_define
DECL|macro|TYPE_FORMAT_STRING_SIZE
define|#
directive|define
name|TYPE_FORMAT_STRING_SIZE
value|189
end_define
begin_define
DECL|macro|PROC_FORMAT_STRING_SIZE
define|#
directive|define
name|PROC_FORMAT_STRING_SIZE
value|751
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
value|2
end_define
begin_typedef
DECL|struct|_Accessible2_MIDL_TYPE_FORMAT_STRING
typedef|typedef
struct|struct
name|_Accessible2_MIDL_TYPE_FORMAT_STRING
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
DECL|typedef|Accessible2_MIDL_TYPE_FORMAT_STRING
name|Accessible2_MIDL_TYPE_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_Accessible2_MIDL_PROC_FORMAT_STRING
typedef|typedef
struct|struct
name|_Accessible2_MIDL_PROC_FORMAT_STRING
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
DECL|typedef|Accessible2_MIDL_PROC_FORMAT_STRING
name|Accessible2_MIDL_PROC_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_Accessible2_MIDL_EXPR_FORMAT_STRING
typedef|typedef
struct|struct
name|_Accessible2_MIDL_EXPR_FORMAT_STRING
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
DECL|typedef|Accessible2_MIDL_EXPR_FORMAT_STRING
name|Accessible2_MIDL_EXPR_FORMAT_STRING
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
name|Accessible2_MIDL_TYPE_FORMAT_STRING
name|Accessible2__MIDL_TypeFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|Accessible2_MIDL_PROC_FORMAT_STRING
name|Accessible2__MIDL_ProcFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|Accessible2_MIDL_EXPR_FORMAT_STRING
name|Accessible2__MIDL_ExprFormatString
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
name|IAccessible2_ServerInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessible2_ProxyInfo
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
name|__RPC_WIN64__
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
begin_decl_stmt
DECL|variable|Accessible2__MIDL_ProcFormatString
specifier|static
specifier|const
name|Accessible2_MIDL_PROC_FORMAT_STRING
name|Accessible2__MIDL_ProcFormatString
init|=
block|{
literal|0
block|,
block|{
comment|/* Procedure get_nRelations */
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
literal|0x1c
argument_list|)
block|,
comment|/* 28 */
comment|/*  8 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
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
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 14 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 16 */
literal|0xa
block|,
comment|/* 10 */
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
comment|/* 24 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter nRelations */
comment|/* 26 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 28 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 30 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 32 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 34 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 36 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_relation */
comment|/* 38 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 40 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 44 */
name|NdrFcShort
argument_list|(
literal|0x1d
argument_list|)
block|,
comment|/* 29 */
comment|/* 46 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 48 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 50 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 52 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 54 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
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
comment|/* 60 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 62 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter relationIndex */
comment|/* 64 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 66 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 68 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter relation */
comment|/* 70 */
name|NdrFcShort
argument_list|(
literal|0x13
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, */
comment|/* 72 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 74 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* Type Offset=6 */
comment|/* Return value */
comment|/* 76 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 78 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 80 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_relations */
comment|/* 82 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 84 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 88 */
name|NdrFcShort
argument_list|(
literal|0x1e
argument_list|)
block|,
comment|/* 30 */
comment|/* 90 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 92 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 94 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 96 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 98 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 100 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 102 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 104 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 106 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter maxRelations */
comment|/* 108 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 110 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 112 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter relations */
comment|/* 114 */
name|NdrFcShort
argument_list|(
literal|0x113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, */
comment|/* 116 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 118 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* Type Offset=32 */
comment|/* Parameter nRelations */
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
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
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
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 130 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure role */
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
literal|0x1f
argument_list|)
block|,
comment|/* 31 */
comment|/* 140 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 142 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 144 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 146 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 148 */
literal|0xa
block|,
comment|/* 10 */
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
comment|/* 156 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter role */
comment|/* 158 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 160 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 162 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 164 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 166 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 168 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure scrollTo */
comment|/* 170 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 172 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 176 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* 32 */
comment|/* 178 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 180 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* 6 */
comment|/* 182 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 184 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 186 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 188 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 190 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 192 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 194 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter scrollType */
comment|/* 196 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 198 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 200 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 202 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 204 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 206 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure scrollToPoint */
comment|/* 208 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 210 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 214 */
name|NdrFcShort
argument_list|(
literal|0x21
argument_list|)
block|,
comment|/* 33 */
comment|/* 216 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 218 */
name|NdrFcShort
argument_list|(
literal|0x16
argument_list|)
block|,
comment|/* 22 */
comment|/* 220 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 222 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 224 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 226 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 228 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 230 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 232 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter coordinateType */
comment|/* 234 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 236 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 238 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter x */
comment|/* 240 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 242 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 244 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter y */
comment|/* 246 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 248 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 250 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 252 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 254 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 256 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_groupPosition */
comment|/* 258 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 260 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 264 */
name|NdrFcShort
argument_list|(
literal|0x22
argument_list|)
block|,
comment|/* 34 */
comment|/* 266 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 268 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 270 */
name|NdrFcShort
argument_list|(
literal|0x5c
argument_list|)
block|,
comment|/* 92 */
comment|/* 272 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 274 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 276 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 278 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 280 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 282 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter groupLevel */
comment|/* 284 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 286 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 288 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter similarItemsInGroup */
comment|/* 290 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 292 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 294 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter positionInGroup */
comment|/* 296 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 298 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 300 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 302 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 304 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 306 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_states */
comment|/* 308 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 310 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 314 */
name|NdrFcShort
argument_list|(
literal|0x23
argument_list|)
block|,
comment|/* 35 */
comment|/* 316 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 318 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 320 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 322 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 324 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 326 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 328 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 330 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 332 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter states */
comment|/* 334 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 336 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 338 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 340 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 342 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 344 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_extendedRole */
comment|/* 346 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 348 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 352 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 354 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 360 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 362 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 364 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 366 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 368 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 370 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter extendedRole */
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
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 376 */
name|NdrFcShort
argument_list|(
literal|0x54
argument_list|)
block|,
comment|/* Type Offset=84 */
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
comment|/* X64 Stack size/offset = 16 */
comment|/* 382 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_localizedExtendedRole */
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
literal|0x25
argument_list|)
block|,
comment|/* 37 */
comment|/* 392 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 394 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 396 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 398 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 400 */
literal|0xa
block|,
comment|/* 10 */
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
comment|/* 408 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter localizedExtendedRole */
comment|/* 410 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 412 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 414 */
name|NdrFcShort
argument_list|(
literal|0x54
argument_list|)
block|,
comment|/* Type Offset=84 */
comment|/* Return value */
comment|/* 416 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 418 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 420 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_nExtendedStates */
comment|/* 422 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 424 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 428 */
name|NdrFcShort
argument_list|(
literal|0x26
argument_list|)
block|,
comment|/* 38 */
comment|/* 430 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 432 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 434 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 436 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 438 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 440 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 442 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 444 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 446 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter nExtendedStates */
comment|/* 448 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 450 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 452 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 454 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 456 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 458 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_extendedStates */
comment|/* 460 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 462 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 466 */
name|NdrFcShort
argument_list|(
literal|0x27
argument_list|)
block|,
comment|/* 39 */
comment|/* 468 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 470 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 472 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 474 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 476 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 478 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 480 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 482 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 484 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter maxExtendedStates */
comment|/* 486 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 488 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 490 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter extendedStates */
comment|/* 492 */
name|NdrFcShort
argument_list|(
literal|0x2013
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, srv alloc size=8 */
comment|/* 494 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 496 */
name|NdrFcShort
argument_list|(
literal|0x5e
argument_list|)
block|,
comment|/* Type Offset=94 */
comment|/* Parameter nExtendedStates */
comment|/* 498 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 500 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 502 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 504 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 506 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 508 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_localizedExtendedStates */
comment|/* 510 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 512 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 516 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* 40 */
comment|/* 518 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 520 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 522 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 524 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 526 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 528 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 534 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter maxLocalizedExtendedStates */
comment|/* 536 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 538 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 540 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter localizedExtendedStates */
comment|/* 542 */
name|NdrFcShort
argument_list|(
literal|0x2013
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, srv alloc size=8 */
comment|/* 544 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 546 */
name|NdrFcShort
argument_list|(
literal|0x5e
argument_list|)
block|,
comment|/* Type Offset=94 */
comment|/* Parameter nLocalizedExtendedStates */
comment|/* 548 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 550 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 552 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 554 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 556 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 558 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_uniqueID */
comment|/* 560 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 562 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 566 */
name|NdrFcShort
argument_list|(
literal|0x29
argument_list|)
block|,
comment|/* 41 */
comment|/* 568 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 570 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 572 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 574 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 576 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 578 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 580 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
comment|/* Parameter uniqueID */
comment|/* 586 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 588 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 590 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 592 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 594 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 596 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_windowHandle */
comment|/* 598 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 600 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 604 */
name|NdrFcShort
argument_list|(
literal|0x2a
argument_list|)
block|,
comment|/* 42 */
comment|/* 606 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 608 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 610 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 612 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 614 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 616 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
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
comment|/* Parameter windowHandle */
comment|/* 624 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 626 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 628 */
name|NdrFcShort
argument_list|(
literal|0x98
argument_list|)
block|,
comment|/* Type Offset=152 */
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
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 634 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_indexInParent */
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
literal|0x2b
argument_list|)
block|,
comment|/* 43 */
comment|/* 644 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 646 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 648 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 650 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 652 */
literal|0xa
block|,
comment|/* 10 */
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
comment|/* 660 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter indexInParent */
comment|/* 662 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 664 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 666 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 668 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 670 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 672 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_locale */
comment|/* 674 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 676 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 680 */
name|NdrFcShort
argument_list|(
literal|0x2c
argument_list|)
block|,
comment|/* 44 */
comment|/* 682 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 688 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 690 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 692 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 698 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter locale */
comment|/* 700 */
name|NdrFcShort
argument_list|(
literal|0x6113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
comment|/* 702 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 704 */
name|NdrFcShort
argument_list|(
literal|0xa6
argument_list|)
block|,
comment|/* Type Offset=166 */
comment|/* Return value */
comment|/* 706 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 708 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 710 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_attributes */
comment|/* 712 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 714 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 718 */
name|NdrFcShort
argument_list|(
literal|0x2d
argument_list|)
block|,
comment|/* 45 */
comment|/* 720 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 722 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 724 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 726 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 728 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 730 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 732 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 734 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 736 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter attributes */
comment|/* 738 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 740 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 742 */
name|NdrFcShort
argument_list|(
literal|0x54
argument_list|)
block|,
comment|/* Type Offset=84 */
comment|/* Return value */
comment|/* 744 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 746 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 748 */
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
DECL|variable|Accessible2__MIDL_TypeFormatString
specifier|static
specifier|const
name|Accessible2_MIDL_TYPE_FORMAT_STRING
name|Accessible2__MIDL_TypeFormatString
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
literal|0x10
block|,
comment|/* FC_RP [pointer_deref] */
comment|/*  8 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (10) */
comment|/* 10 */
literal|0x2f
block|,
comment|/* FC_IP */
literal|0x5a
block|,
comment|/* FC_CONSTANT_IID */
comment|/* 12 */
name|NdrFcLong
argument_list|(
literal|0x7cdf86ee
argument_list|)
block|,
comment|/* 2095023854 */
comment|/* 16 */
name|NdrFcShort
argument_list|(
literal|0xc3da
argument_list|)
block|,
comment|/* -15398 */
comment|/* 18 */
name|NdrFcShort
argument_list|(
literal|0x496a
argument_list|)
block|,
comment|/* 18794 */
comment|/* 20 */
literal|0xbd
block|,
comment|/* 189 */
literal|0xa4
block|,
comment|/* 164 */
comment|/* 22 */
literal|0x28
block|,
comment|/* 40 */
literal|0x1b
block|,
comment|/* 27 */
comment|/* 24 */
literal|0x33
block|,
comment|/* 51 */
literal|0x6e
block|,
comment|/* 110 */
comment|/* 26 */
literal|0x1f
block|,
comment|/* 31 */
literal|0xdc
block|,
comment|/* 220 */
comment|/* 28 */
literal|0x11
block|,
literal|0x0
block|,
comment|/* FC_RP */
comment|/* 30 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (32) */
comment|/* 32 */
literal|0x21
block|,
comment|/* FC_BOGUS_ARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 34 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 36 */
literal|0x28
block|,
comment|/* Corr desc:  parameter, FC_LONG */
literal|0x0
block|,
comment|/*  */
comment|/* 38 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 40 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 42 */
literal|0x28
block|,
comment|/* Corr desc:  parameter, FC_LONG */
literal|0x54
block|,
comment|/* FC_DEREFERENCE */
comment|/* 44 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 46 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Corr flags:  */
comment|/* 48 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 50 */
name|NdrFcShort
argument_list|(
literal|0xffd8
argument_list|)
block|,
comment|/* Offset= -40 (10) */
comment|/* 52 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 54 */
literal|0x11
block|,
literal|0x4
block|,
comment|/* FC_RP [alloced_on_stack] */
comment|/* 56 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* Offset= 28 (84) */
comment|/* 58 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 60 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* Offset= 14 (74) */
comment|/* 62 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x1
block|,
comment|/* 1 */
comment|/* 64 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 66 */
literal|0x9
block|,
comment|/* Corr desc: FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 68 */
name|NdrFcShort
argument_list|(
literal|0xfffc
argument_list|)
block|,
comment|/* -4 */
comment|/* 70 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 72 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 74 */
literal|0x17
block|,
comment|/* FC_CSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 76 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 78 */
name|NdrFcShort
argument_list|(
literal|0xfff0
argument_list|)
block|,
comment|/* Offset= -16 (62) */
comment|/* 80 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 82 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 84 */
literal|0xb4
block|,
comment|/* FC_USER_MARSHAL */
literal|0x83
block|,
comment|/* 131 */
comment|/* 86 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 88 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 90 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 92 */
name|NdrFcShort
argument_list|(
literal|0xffde
argument_list|)
block|,
comment|/* Offset= -34 (58) */
comment|/* 94 */
literal|0x11
block|,
literal|0x14
block|,
comment|/* FC_RP [alloced_on_stack] [pointer_deref] */
comment|/* 96 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (98) */
comment|/* 98 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 100 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (102) */
comment|/* 102 */
literal|0x21
block|,
comment|/* FC_BOGUS_ARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 104 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 106 */
literal|0x28
block|,
comment|/* Corr desc:  parameter, FC_LONG */
literal|0x0
block|,
comment|/*  */
comment|/* 108 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 110 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 112 */
literal|0x28
block|,
comment|/* Corr desc:  parameter, FC_LONG */
literal|0x54
block|,
comment|/* FC_DEREFERENCE */
comment|/* 114 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 116 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Corr flags:  */
comment|/* 118 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 120 */
name|NdrFcShort
argument_list|(
literal|0xffdc
argument_list|)
block|,
comment|/* Offset= -36 (84) */
comment|/* 122 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 124 */
literal|0x11
block|,
literal|0x4
block|,
comment|/* FC_RP [alloced_on_stack] */
comment|/* 126 */
name|NdrFcShort
argument_list|(
literal|0x1a
argument_list|)
block|,
comment|/* Offset= 26 (152) */
comment|/* 128 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 130 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (132) */
comment|/* 132 */
literal|0x2a
block|,
comment|/* FC_ENCAPSULATED_UNION */
literal|0x48
block|,
comment|/* 72 */
comment|/* 134 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 136 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 138 */
name|NdrFcLong
argument_list|(
literal|0x48746457
argument_list|)
block|,
comment|/* 1215587415 */
comment|/* 142 */
name|NdrFcShort
argument_list|(
literal|0x8008
argument_list|)
block|,
comment|/* Simple arm type: FC_LONG */
comment|/* 144 */
name|NdrFcLong
argument_list|(
literal|0x52746457
argument_list|)
block|,
comment|/* 1383359575 */
comment|/* 148 */
name|NdrFcShort
argument_list|(
literal|0x8008
argument_list|)
block|,
comment|/* Simple arm type: FC_LONG */
comment|/* 150 */
name|NdrFcShort
argument_list|(
literal|0xffff
argument_list|)
block|,
comment|/* Offset= -1 (149) */
comment|/* 152 */
literal|0xb4
block|,
comment|/* FC_USER_MARSHAL */
literal|0x83
block|,
comment|/* 131 */
comment|/* 154 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 156 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 158 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 160 */
name|NdrFcShort
argument_list|(
literal|0xffe0
argument_list|)
block|,
comment|/* Offset= -32 (128) */
comment|/* 162 */
literal|0x11
block|,
literal|0x4
block|,
comment|/* FC_RP [alloced_on_stack] */
comment|/* 164 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (166) */
comment|/* 166 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 168 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* 24 */
comment|/* 170 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 172 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Offset= 0 (172) */
comment|/* 174 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 176 */
name|NdrFcShort
argument_list|(
literal|0xffa4
argument_list|)
block|,
comment|/* Offset= -92 (84) */
comment|/* 178 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 180 */
name|NdrFcShort
argument_list|(
literal|0xffa0
argument_list|)
block|,
comment|/* Offset= -96 (84) */
comment|/* 182 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 184 */
name|NdrFcShort
argument_list|(
literal|0xff9c
argument_list|)
block|,
comment|/* Offset= -100 (84) */
comment|/* 186 */
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
block|,
block|{
name|HWND_UserSize
block|,
name|HWND_UserMarshal
block|,
name|HWND_UserUnmarshal
block|,
name|HWND_UserFree
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Standard interface: __MIDL_itf_Accessible2_0000_0000, ver. 0.0,    GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */
end_comment
begin_comment
comment|/* Object interface: IUnknown, ver. 0.0,    GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */
end_comment
begin_comment
comment|/* Object interface: IDispatch, ver. 0.0,    GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */
end_comment
begin_comment
comment|/* Object interface: IAccessible, ver. 0.0,    GUID={0x618736e0,0x3c3d,0x11cf,{0x81,0x0c,0x00,0xaa,0x00,0x38,0x9b,0x71}} */
end_comment
begin_comment
comment|/* Object interface: IAccessible2, ver. 0.0,    GUID={0xE89F726E,0xC4F4,0x4c19,{0xBB,0x19,0xB6,0x47,0xD7,0xFA,0x84,0x78}} */
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
DECL|variable|IAccessible2_FormatStringOffsetTable
specifier|static
specifier|const
name|unsigned
name|short
name|IAccessible2_FormatStringOffsetTable
index|[]
init|=
block|{
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
operator|(
name|unsigned
name|short
operator|)
operator|-
literal|1
block|,
literal|0
block|,
literal|38
block|,
literal|82
block|,
literal|132
block|,
literal|170
block|,
literal|208
block|,
literal|258
block|,
literal|308
block|,
literal|346
block|,
literal|384
block|,
literal|422
block|,
literal|460
block|,
literal|510
block|,
literal|560
block|,
literal|598
block|,
literal|636
block|,
literal|674
block|,
literal|712
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|IAccessible2_ProxyInfo
specifier|static
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessible2_ProxyInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
name|Accessible2__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessible2_FormatStringOffsetTable
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
DECL|variable|IAccessible2_ServerInfo
specifier|static
specifier|const
name|MIDL_SERVER_INFO
name|IAccessible2_ServerInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
literal|0
block|,
name|Accessible2__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessible2_FormatStringOffsetTable
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
literal|46
argument_list|)
end_macro
begin_expr_stmt
name|_IAccessible2ProxyVtbl
operator|=
block|{
operator|&
name|IAccessible2_ProxyInfo
block|,
operator|&
name|IID_IAccessible2
block|,
name|IUnknown_QueryInterface_Proxy
block|,
name|IUnknown_AddRef_Proxy
block|,
name|IUnknown_Release_Proxy
block|,
literal|0
comment|/* IDispatch::GetTypeInfoCount */
block|,
literal|0
comment|/* IDispatch::GetTypeInfo */
block|,
literal|0
comment|/* IDispatch::GetIDsOfNames */
block|,
literal|0
comment|/* IDispatch_Invoke_Proxy */
block|,
literal|0
comment|/* IAccessible::get_accParent */
block|,
literal|0
comment|/* IAccessible::get_accChildCount */
block|,
literal|0
comment|/* IAccessible::get_accChild */
block|,
literal|0
comment|/* IAccessible::get_accName */
block|,
literal|0
comment|/* IAccessible::get_accValue */
block|,
literal|0
comment|/* IAccessible::get_accDescription */
block|,
literal|0
comment|/* IAccessible::get_accRole */
block|,
literal|0
comment|/* IAccessible::get_accState */
block|,
literal|0
comment|/* IAccessible::get_accHelp */
block|,
literal|0
comment|/* IAccessible::get_accHelpTopic */
block|,
literal|0
comment|/* IAccessible::get_accKeyboardShortcut */
block|,
literal|0
comment|/* IAccessible::get_accFocus */
block|,
literal|0
comment|/* IAccessible::get_accSelection */
block|,
literal|0
comment|/* IAccessible::get_accDefaultAction */
block|,
literal|0
comment|/* IAccessible::accSelect */
block|,
literal|0
comment|/* IAccessible::accLocation */
block|,
literal|0
comment|/* IAccessible::accNavigate */
block|,
literal|0
comment|/* IAccessible::accHitTest */
block|,
literal|0
comment|/* IAccessible::accDoDefaultAction */
block|,
literal|0
comment|/* IAccessible::put_accName */
block|,
literal|0
comment|/* IAccessible::put_accValue */
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
comment|/* IAccessible2::get_nRelations */
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
comment|/* IAccessible2::get_relation */
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
comment|/* IAccessible2::get_relations */
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
comment|/* IAccessible2::role */
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
comment|/* IAccessible2::scrollTo */
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
comment|/* IAccessible2::scrollToPoint */
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
comment|/* IAccessible2::get_groupPosition */
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
comment|/* IAccessible2::get_states */
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
comment|/* IAccessible2::get_extendedRole */
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
comment|/* IAccessible2::get_localizedExtendedRole */
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
comment|/* IAccessible2::get_nExtendedStates */
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
comment|/* IAccessible2::get_extendedStates */
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
comment|/* IAccessible2::get_localizedExtendedStates */
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
comment|/* IAccessible2::get_uniqueID */
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
comment|/* IAccessible2::get_windowHandle */
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
comment|/* IAccessible2::get_indexInParent */
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
comment|/* IAccessible2::get_locale */
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
comment|/* IAccessible2::get_attributes */
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|IAccessible2_table
specifier|static
specifier|const
name|PRPC_STUB_FUNCTION
name|IAccessible2_table
index|[]
init|=
block|{
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|STUB_FORWARDING_FUNCTION
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_IAccessible2StubVtbl
name|CInterfaceStubVtbl
name|_IAccessible2StubVtbl
init|=
block|{
operator|&
name|IID_IAccessible2
block|,
operator|&
name|IAccessible2_ServerInfo
block|,
literal|46
block|,
operator|&
name|IAccessible2_table
index|[
operator|-
literal|3
index|]
block|,
name|CStdStubBuffer_DELEGATING_METHODS
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
name|Accessible2__MIDL_TypeFormatString
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
DECL|variable|_Accessible2_ProxyVtblList
specifier|const
name|CInterfaceProxyVtbl
modifier|*
specifier|const
name|_Accessible2_ProxyVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceProxyVtbl
operator|*
operator|)
operator|&
name|_IAccessible2ProxyVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_Accessible2_StubVtblList
specifier|const
name|CInterfaceStubVtbl
modifier|*
specifier|const
name|_Accessible2_StubVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceStubVtbl
operator|*
operator|)
operator|&
name|_IAccessible2StubVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_Accessible2_InterfaceNamesList
name|PCInterfaceName
specifier|const
name|_Accessible2_InterfaceNamesList
index|[]
init|=
block|{
literal|"IAccessible2"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_Accessible2_BaseIIDList
specifier|const
name|IID
modifier|*
specifier|const
name|_Accessible2_BaseIIDList
index|[]
init|=
block|{
operator|&
name|IID_IAccessible
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|_Accessible2_CHECK_IID
define|#
directive|define
name|_Accessible2_CHECK_IID
parameter_list|(
name|n
parameter_list|)
value|IID_GENERIC_CHECK_IID( _Accessible2, pIID, n)
end_define
begin_function
DECL|function|_Accessible2_IID_Lookup
name|int
name|__stdcall
name|_Accessible2_IID_Lookup
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
name|_Accessible2_CHECK_IID
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
DECL|variable|Accessible2_ProxyFileInfo
specifier|const
name|ExtendedProxyFileInfo
name|Accessible2_ProxyFileInfo
init|=
block|{
operator|(
name|PCInterfaceProxyVtblList
operator|*
operator|)
operator|&
name|_Accessible2_ProxyVtblList
block|,
operator|(
name|PCInterfaceStubVtblList
operator|*
operator|)
operator|&
name|_Accessible2_StubVtblList
block|,
operator|(
specifier|const
name|PCInterfaceName
operator|*
operator|)
operator|&
name|_Accessible2_InterfaceNamesList
block|,
operator|(
specifier|const
name|IID
operator|*
operator|*
operator|)
operator|&
name|_Accessible2_BaseIIDList
block|,
operator|&
name|_Accessible2_IID_Lookup
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
comment|/* defined(_M_AMD64)*/
end_comment
end_unit
