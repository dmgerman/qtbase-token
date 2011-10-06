begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the proxy stub code */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:54:00 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleText.idl:     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
value|939
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
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
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
comment|/* Parameter startOffset */
comment|/* 26 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
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
comment|/* Parameter endOffset */
comment|/* 32 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
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
comment|/* Return value */
comment|/* 38 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 40 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 42 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_attributes */
comment|/* 44 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 46 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 50 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 52 */
name|NdrFcShort
argument_list|(
literal|0x30
argument_list|)
block|,
comment|/* X64 Stack size/offset = 48 */
comment|/* 54 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 56 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 58 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x5
block|,
comment|/* 5 */
comment|/* 60 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 62 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 64 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 66 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 68 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 70 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 72 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 74 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 76 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 78 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 80 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 82 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 84 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 86 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter textAttributes */
comment|/* 88 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 90 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 92 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 94 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 96 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 98 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_caretOffset */
comment|/* 100 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 102 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 106 */
name|NdrFcShort
argument_list|(
literal|0x5
argument_list|)
block|,
comment|/* 5 */
comment|/* 108 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 110 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 112 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 114 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 116 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 122 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 124 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 126 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 128 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 130 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 132 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 134 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 136 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_characterExtents */
comment|/* 138 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 140 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 144 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* 6 */
comment|/* 146 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* X64 Stack size/offset = 64 */
comment|/* 148 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 150 */
name|NdrFcShort
argument_list|(
literal|0x78
argument_list|)
block|,
comment|/* 120 */
comment|/* 152 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x7
block|,
comment|/* 7 */
comment|/* 154 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 156 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 162 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 164 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 166 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 168 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter coordType */
comment|/* 170 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 172 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 174 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter x */
comment|/* 176 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 178 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 180 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter y */
comment|/* 182 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 184 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 186 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter width */
comment|/* 188 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 190 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 192 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter height */
comment|/* 194 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 196 */
name|NdrFcShort
argument_list|(
literal|0x30
argument_list|)
block|,
comment|/* X64 Stack size/offset = 48 */
comment|/* 198 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 200 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 202 */
name|NdrFcShort
argument_list|(
literal|0x38
argument_list|)
block|,
comment|/* X64 Stack size/offset = 56 */
comment|/* 204 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_nSelections */
comment|/* 206 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 208 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 212 */
name|NdrFcShort
argument_list|(
literal|0x7
argument_list|)
block|,
comment|/* 7 */
comment|/* 214 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
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
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 220 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 222 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 224 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
comment|/* Parameter nSelections */
comment|/* 232 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 234 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 236 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 238 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 240 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 242 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_offsetAtPoint */
comment|/* 244 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 246 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 250 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 252 */
name|NdrFcShort
argument_list|(
literal|0x30
argument_list|)
block|,
comment|/* X64 Stack size/offset = 48 */
comment|/* 254 */
name|NdrFcShort
argument_list|(
literal|0x16
argument_list|)
block|,
comment|/* 22 */
comment|/* 256 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 258 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x5
block|,
comment|/* 5 */
comment|/* 260 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 262 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 264 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 266 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 268 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter x */
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
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 274 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter y */
comment|/* 276 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 278 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 280 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter coordType */
comment|/* 282 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 284 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 286 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 288 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 290 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 292 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 294 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 296 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 298 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_selection */
comment|/* 300 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 302 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 306 */
name|NdrFcShort
argument_list|(
literal|0x9
argument_list|)
block|,
comment|/* 9 */
comment|/* 308 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 310 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 312 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 314 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 316 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 322 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 324 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter selectionIndex */
comment|/* 326 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 328 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 330 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 332 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 334 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 336 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 338 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 340 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 342 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 344 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 346 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 348 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_text */
comment|/* 350 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 352 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 356 */
name|NdrFcShort
argument_list|(
literal|0xa
argument_list|)
block|,
comment|/* 10 */
comment|/* 358 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 360 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 362 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 364 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 366 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 368 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 370 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 372 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 374 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 376 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 378 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 380 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 382 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 384 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 386 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 388 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 390 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 392 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 394 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 396 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 398 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_textBeforeOffset */
comment|/* 400 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 402 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 406 */
name|NdrFcShort
argument_list|(
literal|0xb
argument_list|)
block|,
comment|/* 11 */
comment|/* 408 */
name|NdrFcShort
argument_list|(
literal|0x38
argument_list|)
block|,
comment|/* X64 Stack size/offset = 56 */
comment|/* 410 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 412 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 414 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x6
block|,
comment|/* 6 */
comment|/* 416 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 418 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 420 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 422 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 424 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 426 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 428 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 430 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter boundaryType */
comment|/* 432 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 434 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 436 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 438 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 440 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 442 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 444 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 446 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 448 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 450 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 452 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 454 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 456 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 458 */
name|NdrFcShort
argument_list|(
literal|0x30
argument_list|)
block|,
comment|/* X64 Stack size/offset = 48 */
comment|/* 460 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_textAfterOffset */
comment|/* 462 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 464 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 468 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* 12 */
comment|/* 470 */
name|NdrFcShort
argument_list|(
literal|0x38
argument_list|)
block|,
comment|/* X64 Stack size/offset = 56 */
comment|/* 472 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 474 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 476 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x6
block|,
comment|/* 6 */
comment|/* 478 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 480 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
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
comment|/* 486 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 488 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 490 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 492 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter boundaryType */
comment|/* 494 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 496 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 498 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 500 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 502 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 504 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 506 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 508 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 510 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 512 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 514 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 516 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 518 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 520 */
name|NdrFcShort
argument_list|(
literal|0x30
argument_list|)
block|,
comment|/* X64 Stack size/offset = 48 */
comment|/* 522 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_textAtOffset */
comment|/* 524 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 526 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 530 */
name|NdrFcShort
argument_list|(
literal|0xd
argument_list|)
block|,
comment|/* 13 */
comment|/* 532 */
name|NdrFcShort
argument_list|(
literal|0x38
argument_list|)
block|,
comment|/* X64 Stack size/offset = 56 */
comment|/* 534 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 536 */
name|NdrFcShort
argument_list|(
literal|0x40
argument_list|)
block|,
comment|/* 64 */
comment|/* 538 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x6
block|,
comment|/* 6 */
comment|/* 540 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 542 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 544 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 546 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 548 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 550 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 552 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 554 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter boundaryType */
comment|/* 556 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 558 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 560 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 562 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 564 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 566 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 568 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 570 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 572 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 574 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 576 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 578 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* Type Offset=36 */
comment|/* Return value */
comment|/* 580 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 582 */
name|NdrFcShort
argument_list|(
literal|0x30
argument_list|)
block|,
comment|/* X64 Stack size/offset = 48 */
comment|/* 584 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure removeSelection */
comment|/* 586 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 588 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 592 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 594 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 596 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 598 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 600 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 602 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 604 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 606 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter selectionIndex */
comment|/* 612 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 614 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 616 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 618 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 620 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 622 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure setCaretOffset */
comment|/* 624 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 626 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 630 */
name|NdrFcShort
argument_list|(
literal|0xf
argument_list|)
block|,
comment|/* 15 */
comment|/* 632 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 634 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 636 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 638 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 640 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 642 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 644 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 650 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 652 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 654 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 656 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 658 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 660 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure setSelection */
comment|/* 662 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 664 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 668 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 670 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 672 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* 24 */
comment|/* 674 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 676 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 678 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 680 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 682 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter selectionIndex */
comment|/* 688 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 690 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 692 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 694 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 696 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 698 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 700 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 702 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 704 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
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
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 710 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_nCharacters */
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
literal|0x11
argument_list|)
block|,
comment|/* 17 */
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
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 726 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 728 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 730 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
comment|/* Parameter nCharacters */
comment|/* 738 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 740 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 742 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
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
comment|/* Procedure scrollSubstringTo */
comment|/* 750 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 752 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 756 */
name|NdrFcShort
argument_list|(
literal|0x12
argument_list|)
block|,
comment|/* 18 */
comment|/* 758 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 760 */
name|NdrFcShort
argument_list|(
literal|0x16
argument_list|)
block|,
comment|/* 22 */
comment|/* 762 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 764 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 766 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 768 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 774 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter startIndex */
comment|/* 776 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 778 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 780 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endIndex */
comment|/* 782 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 784 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 786 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter scrollType */
comment|/* 788 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 790 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 792 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 794 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 796 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 798 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure scrollSubstringToPoint */
comment|/* 800 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 802 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 806 */
name|NdrFcShort
argument_list|(
literal|0x13
argument_list|)
block|,
comment|/* 19 */
comment|/* 808 */
name|NdrFcShort
argument_list|(
literal|0x38
argument_list|)
block|,
comment|/* X64 Stack size/offset = 56 */
comment|/* 810 */
name|NdrFcShort
argument_list|(
literal|0x26
argument_list|)
block|,
comment|/* 38 */
comment|/* 812 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 814 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x6
block|,
comment|/* 6 */
comment|/* 816 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 818 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 820 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 822 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 824 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter startIndex */
comment|/* 826 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 828 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 830 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endIndex */
comment|/* 832 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 834 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 836 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter coordinateType */
comment|/* 838 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 840 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 842 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter x */
comment|/* 844 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 846 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 848 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter y */
comment|/* 850 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 852 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 854 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 856 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 858 */
name|NdrFcShort
argument_list|(
literal|0x30
argument_list|)
block|,
comment|/* X64 Stack size/offset = 48 */
comment|/* 860 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_newText */
comment|/* 862 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 864 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 868 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* 20 */
comment|/* 870 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 872 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 874 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 876 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 878 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 880 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 882 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
comment|/* Parameter newText */
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
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
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
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 898 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_oldText */
comment|/* 900 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 902 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 906 */
name|NdrFcShort
argument_list|(
literal|0x15
argument_list|)
block|,
comment|/* 21 */
comment|/* 908 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 910 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 912 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 914 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 916 */
literal|0xa
block|,
comment|/* 10 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 918 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 920 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 922 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 924 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter oldText */
comment|/* 926 */
name|NdrFcShort
argument_list|(
literal|0x4113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
comment|/* 928 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 930 */
name|NdrFcShort
argument_list|(
literal|0x32
argument_list|)
block|,
comment|/* Type Offset=50 */
comment|/* Return value */
comment|/* 932 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 934 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 936 */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
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
literal|0x10
argument_list|)
block|,
comment|/* 16 */
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
literal|44
block|,
literal|100
block|,
literal|138
block|,
literal|206
block|,
literal|244
block|,
literal|300
block|,
literal|350
block|,
literal|400
block|,
literal|462
block|,
literal|524
block|,
literal|586
block|,
literal|624
block|,
literal|662
block|,
literal|712
block|,
literal|750
block|,
literal|800
block|,
literal|862
block|,
literal|900
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
