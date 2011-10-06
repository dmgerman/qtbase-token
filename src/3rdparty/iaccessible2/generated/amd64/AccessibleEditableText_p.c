begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the proxy stub code */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:57 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleEditableText.idl:     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
file|"AccessibleEditableText.h"
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
value|315
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
DECL|struct|_AccessibleEditableText_MIDL_TYPE_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleEditableText_MIDL_TYPE_FORMAT_STRING
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
DECL|typedef|AccessibleEditableText_MIDL_TYPE_FORMAT_STRING
name|AccessibleEditableText_MIDL_TYPE_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleEditableText_MIDL_PROC_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleEditableText_MIDL_PROC_FORMAT_STRING
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
DECL|typedef|AccessibleEditableText_MIDL_PROC_FORMAT_STRING
name|AccessibleEditableText_MIDL_PROC_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleEditableText_MIDL_EXPR_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleEditableText_MIDL_EXPR_FORMAT_STRING
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
DECL|typedef|AccessibleEditableText_MIDL_EXPR_FORMAT_STRING
name|AccessibleEditableText_MIDL_EXPR_FORMAT_STRING
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
name|AccessibleEditableText_MIDL_TYPE_FORMAT_STRING
name|AccessibleEditableText__MIDL_TypeFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleEditableText_MIDL_PROC_FORMAT_STRING
name|AccessibleEditableText__MIDL_ProcFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleEditableText_MIDL_EXPR_FORMAT_STRING
name|AccessibleEditableText__MIDL_ExprFormatString
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
name|IAccessibleEditableText_ServerInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleEditableText_ProxyInfo
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
DECL|variable|AccessibleEditableText__MIDL_ProcFormatString
specifier|static
specifier|const
name|AccessibleEditableText_MIDL_PROC_FORMAT_STRING
name|AccessibleEditableText__MIDL_ProcFormatString
init|=
block|{
literal|0
block|,
block|{
comment|/* Procedure copyText */
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
comment|/* Procedure deleteText */
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
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 54 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 56 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 58 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 60 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
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
comment|/* Parameter startOffset */
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
comment|/* Parameter endOffset */
comment|/* 76 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
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
comment|/* Return value */
comment|/* 82 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
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
comment|/* Procedure insertText */
comment|/* 88 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 90 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 94 */
name|NdrFcShort
argument_list|(
literal|0x5
argument_list|)
block|,
comment|/* 5 */
comment|/* 96 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 98 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 100 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 102 */
literal|0x46
block|,
comment|/* Oi2 Flags:  clt must size, has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 104 */
literal|0xa
block|,
comment|/* 10 */
literal|0x5
block|,
comment|/* Ext Flags:  new corr desc, srv corr check, */
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
literal|0x1
argument_list|)
block|,
comment|/* 1 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 114 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 116 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 118 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 120 */
name|NdrFcShort
argument_list|(
literal|0x10b
argument_list|)
block|,
comment|/* Flags:  must size, must free, in, simple ref, */
comment|/* 122 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 124 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* Type Offset=32 */
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
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 130 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure cutText */
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
comment|/* X64 Stack size/offset = 32 */
comment|/* 142 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 144 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 146 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
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
comment|/* Parameter startOffset */
comment|/* 158 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
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
comment|/* Parameter endOffset */
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
comment|/* Return value */
comment|/* 170 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 172 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 174 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure pasteText */
comment|/* 176 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 178 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 182 */
name|NdrFcShort
argument_list|(
literal|0x7
argument_list|)
block|,
comment|/* 7 */
comment|/* 184 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 186 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 188 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 190 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 192 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 194 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 196 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 198 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 200 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter offset */
comment|/* 202 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 204 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 206 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 208 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 210 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 212 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure replaceText */
comment|/* 214 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 216 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 220 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 222 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 224 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 226 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 228 */
literal|0x46
block|,
comment|/* Oi2 Flags:  clt must size, has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 230 */
literal|0xa
block|,
comment|/* 10 */
literal|0x5
block|,
comment|/* Ext Flags:  new corr desc, srv corr check, */
comment|/* 232 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 234 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 236 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 238 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
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
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 244 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
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
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 250 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter text */
comment|/* 252 */
name|NdrFcShort
argument_list|(
literal|0x10b
argument_list|)
block|,
comment|/* Flags:  must size, must free, in, simple ref, */
comment|/* 254 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 256 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* Type Offset=32 */
comment|/* Return value */
comment|/* 258 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 260 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 262 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure setAttributes */
comment|/* 264 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 266 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 270 */
name|NdrFcShort
argument_list|(
literal|0x9
argument_list|)
block|,
comment|/* 9 */
comment|/* 272 */
name|NdrFcShort
argument_list|(
literal|0x28
argument_list|)
block|,
comment|/* X64 Stack size/offset = 40 */
comment|/* 274 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 276 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 278 */
literal|0x46
block|,
comment|/* Oi2 Flags:  clt must size, has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
comment|/* 280 */
literal|0xa
block|,
comment|/* 10 */
literal|0x5
block|,
comment|/* Ext Flags:  new corr desc, srv corr check, */
comment|/* 282 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 284 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 286 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 288 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter startOffset */
comment|/* 290 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 292 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* X64 Stack size/offset = 8 */
comment|/* 294 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter endOffset */
comment|/* 296 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 298 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 300 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter attributes */
comment|/* 302 */
name|NdrFcShort
argument_list|(
literal|0x10b
argument_list|)
block|,
comment|/* Flags:  must size, must free, in, simple ref, */
comment|/* 304 */
name|NdrFcShort
argument_list|(
literal|0x18
argument_list|)
block|,
comment|/* X64 Stack size/offset = 24 */
comment|/* 306 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* Type Offset=32 */
comment|/* Return value */
comment|/* 308 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 310 */
name|NdrFcShort
argument_list|(
literal|0x20
argument_list|)
block|,
comment|/* X64 Stack size/offset = 32 */
comment|/* 312 */
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
DECL|variable|AccessibleEditableText__MIDL_TypeFormatString
specifier|static
specifier|const
name|AccessibleEditableText_MIDL_TYPE_FORMAT_STRING
name|AccessibleEditableText__MIDL_TypeFormatString
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
literal|0x0
block|,
comment|/* FC_RP */
comment|/*  4 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* Offset= 28 (32) */
comment|/*  6 */
literal|0x12
block|,
literal|0x0
block|,
comment|/* FC_UP */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
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
comment|/* Object interface: IAccessibleEditableText, ver. 0.0,    GUID={0xA59AA09A,0x7011,0x4b65,{0x93,0x9D,0x32,0xB1,0xFB,0x55,0x47,0xE3}} */
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
DECL|variable|IAccessibleEditableText_FormatStringOffsetTable
specifier|static
specifier|const
name|unsigned
name|short
name|IAccessibleEditableText_FormatStringOffsetTable
index|[]
init|=
block|{
literal|0
block|,
literal|44
block|,
literal|88
block|,
literal|132
block|,
literal|176
block|,
literal|214
block|,
literal|264
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|IAccessibleEditableText_ProxyInfo
specifier|static
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleEditableText_ProxyInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
name|AccessibleEditableText__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleEditableText_FormatStringOffsetTable
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
DECL|variable|IAccessibleEditableText_ServerInfo
specifier|static
specifier|const
name|MIDL_SERVER_INFO
name|IAccessibleEditableText_ServerInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
literal|0
block|,
name|AccessibleEditableText__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleEditableText_FormatStringOffsetTable
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
literal|10
argument_list|)
end_macro
begin_expr_stmt
name|_IAccessibleEditableTextProxyVtbl
operator|=
block|{
operator|&
name|IAccessibleEditableText_ProxyInfo
block|,
operator|&
name|IID_IAccessibleEditableText
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
comment|/* IAccessibleEditableText::copyText */
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
comment|/* IAccessibleEditableText::deleteText */
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
comment|/* IAccessibleEditableText::insertText */
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
comment|/* IAccessibleEditableText::cutText */
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
comment|/* IAccessibleEditableText::pasteText */
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
comment|/* IAccessibleEditableText::replaceText */
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
comment|/* IAccessibleEditableText::setAttributes */
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|_IAccessibleEditableTextStubVtbl
specifier|const
name|CInterfaceStubVtbl
name|_IAccessibleEditableTextStubVtbl
init|=
block|{
operator|&
name|IID_IAccessibleEditableText
block|,
operator|&
name|IAccessibleEditableText_ServerInfo
block|,
literal|10
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
name|AccessibleEditableText__MIDL_TypeFormatString
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
DECL|variable|_AccessibleEditableText_ProxyVtblList
specifier|const
name|CInterfaceProxyVtbl
modifier|*
specifier|const
name|_AccessibleEditableText_ProxyVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceProxyVtbl
operator|*
operator|)
operator|&
name|_IAccessibleEditableTextProxyVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleEditableText_StubVtblList
specifier|const
name|CInterfaceStubVtbl
modifier|*
specifier|const
name|_AccessibleEditableText_StubVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceStubVtbl
operator|*
operator|)
operator|&
name|_IAccessibleEditableTextStubVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleEditableText_InterfaceNamesList
name|PCInterfaceName
specifier|const
name|_AccessibleEditableText_InterfaceNamesList
index|[]
init|=
block|{
literal|"IAccessibleEditableText"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|_AccessibleEditableText_CHECK_IID
define|#
directive|define
name|_AccessibleEditableText_CHECK_IID
parameter_list|(
name|n
parameter_list|)
value|IID_GENERIC_CHECK_IID( _AccessibleEditableText, pIID, n)
end_define
begin_function
DECL|function|_AccessibleEditableText_IID_Lookup
name|int
name|__stdcall
name|_AccessibleEditableText_IID_Lookup
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
name|_AccessibleEditableText_CHECK_IID
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
DECL|variable|AccessibleEditableText_ProxyFileInfo
specifier|const
name|ExtendedProxyFileInfo
name|AccessibleEditableText_ProxyFileInfo
init|=
block|{
operator|(
name|PCInterfaceProxyVtblList
operator|*
operator|)
operator|&
name|_AccessibleEditableText_ProxyVtblList
block|,
operator|(
name|PCInterfaceStubVtblList
operator|*
operator|)
operator|&
name|_AccessibleEditableText_StubVtblList
block|,
operator|(
specifier|const
name|PCInterfaceName
operator|*
operator|)
operator|&
name|_AccessibleEditableText_InterfaceNamesList
block|,
literal|0
block|,
comment|/* no delegation */
operator|&
name|_AccessibleEditableText_IID_Lookup
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
