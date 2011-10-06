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
comment|/* Compiler settings for AccessibleTable2.idl:     Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
file|"AccessibleTable2.h"
end_include
begin_define
DECL|macro|TYPE_FORMAT_STRING_SIZE
define|#
directive|define
name|TYPE_FORMAT_STRING_SIZE
value|141
end_define
begin_define
DECL|macro|PROC_FORMAT_STRING_SIZE
define|#
directive|define
name|PROC_FORMAT_STRING_SIZE
value|775
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
DECL|struct|_AccessibleTable2_MIDL_TYPE_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleTable2_MIDL_TYPE_FORMAT_STRING
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
DECL|typedef|AccessibleTable2_MIDL_TYPE_FORMAT_STRING
name|AccessibleTable2_MIDL_TYPE_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleTable2_MIDL_PROC_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleTable2_MIDL_PROC_FORMAT_STRING
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
DECL|typedef|AccessibleTable2_MIDL_PROC_FORMAT_STRING
name|AccessibleTable2_MIDL_PROC_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleTable2_MIDL_EXPR_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleTable2_MIDL_EXPR_FORMAT_STRING
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
DECL|typedef|AccessibleTable2_MIDL_EXPR_FORMAT_STRING
name|AccessibleTable2_MIDL_EXPR_FORMAT_STRING
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
name|AccessibleTable2_MIDL_TYPE_FORMAT_STRING
name|AccessibleTable2__MIDL_TypeFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleTable2_MIDL_PROC_FORMAT_STRING
name|AccessibleTable2__MIDL_ProcFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleTable2_MIDL_EXPR_FORMAT_STRING
name|AccessibleTable2__MIDL_ExprFormatString
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
name|IAccessibleTable2_ServerInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleTable2_ProxyInfo
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
DECL|variable|AccessibleTable2__MIDL_ProcFormatString
specifier|static
specifier|const
name|AccessibleTable2_MIDL_PROC_FORMAT_STRING
name|AccessibleTable2__MIDL_ProcFormatString
init|=
block|{
literal|0
block|,
block|{
comment|/* Procedure get_cellAt */
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
literal|0x14
argument_list|)
block|,
comment|/* x86 Stack size/offset = 20 */
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
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x4
block|,
comment|/* 4 */
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
comment|/* Parameter row */
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
comment|/* Parameter column */
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
comment|/* Parameter cell */
comment|/* 36 */
name|NdrFcShort
argument_list|(
literal|0x13
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, */
comment|/* 38 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 40 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Type Offset=2 */
comment|/* Return value */
comment|/* 42 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 44 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 46 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_caption */
comment|/* 48 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 50 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 54 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 56 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 62 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 64 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
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
comment|/* 70 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter accessible */
comment|/* 72 */
name|NdrFcShort
argument_list|(
literal|0x13
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, */
comment|/* 74 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 76 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Type Offset=2 */
comment|/* Return value */
comment|/* 78 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 80 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 82 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_columnDescription */
comment|/* 84 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 86 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 90 */
name|NdrFcShort
argument_list|(
literal|0x5
argument_list|)
block|,
comment|/* 5 */
comment|/* 92 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 94 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 96 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 98 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 100 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 102 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
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
comment|/* Parameter column */
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
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 112 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter description */
comment|/* 114 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 116 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 118 */
name|NdrFcShort
argument_list|(
literal|0x36
argument_list|)
block|,
comment|/* Type Offset=54 */
comment|/* Return value */
comment|/* 120 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 122 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 124 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_nColumns */
comment|/* 126 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 128 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 132 */
name|NdrFcShort
argument_list|(
literal|0x6
argument_list|)
block|,
comment|/* 6 */
comment|/* 134 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 136 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 138 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 140 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 142 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 144 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 146 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 148 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter columnCount */
comment|/* 150 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 152 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 154 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 156 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 158 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 160 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_nRows */
comment|/* 162 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 164 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 168 */
name|NdrFcShort
argument_list|(
literal|0x7
argument_list|)
block|,
comment|/* 7 */
comment|/* 170 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 172 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 174 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 176 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 178 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 180 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 182 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 184 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter rowCount */
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
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
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
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 196 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_nSelectedCells */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
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
comment|/* Parameter cellCount */
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
comment|/* Procedure get_nSelectedColumns */
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
literal|0x9
argument_list|)
block|,
comment|/* 9 */
comment|/* 242 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 244 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
literal|0x2
block|,
comment|/* 2 */
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
comment|/* Parameter columnCount */
comment|/* 258 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
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
comment|/* Return value */
comment|/* 264 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
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
comment|/* Procedure get_nSelectedRows */
comment|/* 270 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 272 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 276 */
name|NdrFcShort
argument_list|(
literal|0xa
argument_list|)
block|,
comment|/* 10 */
comment|/* 278 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
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
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 284 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 286 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 288 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 290 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 292 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter rowCount */
comment|/* 294 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 296 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 298 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 300 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 302 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 304 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_rowDescription */
comment|/* 306 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 308 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 312 */
name|NdrFcShort
argument_list|(
literal|0xb
argument_list|)
block|,
comment|/* 11 */
comment|/* 314 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 316 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 318 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 320 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 322 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 324 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
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
comment|/* Parameter row */
comment|/* 330 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 332 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 334 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter description */
comment|/* 336 */
name|NdrFcShort
argument_list|(
literal|0x2113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
comment|/* 338 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 340 */
name|NdrFcShort
argument_list|(
literal|0x36
argument_list|)
block|,
comment|/* Type Offset=54 */
comment|/* Return value */
comment|/* 342 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 344 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 346 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_selectedCells */
comment|/* 348 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 350 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 354 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* 12 */
comment|/* 356 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 358 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 360 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 362 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 364 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 366 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
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
comment|/* Parameter cells */
comment|/* 372 */
name|NdrFcShort
argument_list|(
literal|0x2013
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, srv alloc size=8 */
comment|/* 374 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 376 */
name|NdrFcShort
argument_list|(
literal|0x44
argument_list|)
block|,
comment|/* Type Offset=68 */
comment|/* Parameter nSelectedCells */
comment|/* 378 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 380 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 382 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 384 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 386 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 388 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_selectedColumns */
comment|/* 390 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 392 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 396 */
name|NdrFcShort
argument_list|(
literal|0xd
argument_list|)
block|,
comment|/* 13 */
comment|/* 398 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 400 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 402 */
name|NdrFcShort
argument_list|(
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 404 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 406 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 408 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 410 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 412 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter selectedColumns */
comment|/* 414 */
name|NdrFcShort
argument_list|(
literal|0x2013
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, srv alloc size=8 */
comment|/* 416 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 418 */
name|NdrFcShort
argument_list|(
literal|0x62
argument_list|)
block|,
comment|/* Type Offset=98 */
comment|/* Parameter nColumns */
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
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 424 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 426 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 428 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 430 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_selectedRows */
comment|/* 432 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 434 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 438 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* 14 */
comment|/* 440 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
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
literal|0x24
argument_list|)
block|,
comment|/* 36 */
comment|/* 446 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 448 */
literal|0x8
block|,
comment|/* 8 */
literal|0x3
block|,
comment|/* Ext Flags:  new corr desc, clt corr check, */
comment|/* 450 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* 1 */
comment|/* 452 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 454 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter selectedRows */
comment|/* 456 */
name|NdrFcShort
argument_list|(
literal|0x2013
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, srv alloc size=8 */
comment|/* 458 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 460 */
name|NdrFcShort
argument_list|(
literal|0x62
argument_list|)
block|,
comment|/* Type Offset=98 */
comment|/* Parameter nRows */
comment|/* 462 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 464 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 466 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 468 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 470 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 472 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_summary */
comment|/* 474 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 476 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 480 */
name|NdrFcShort
argument_list|(
literal|0xf
argument_list|)
block|,
comment|/* 15 */
comment|/* 482 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 488 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 490 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 492 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 494 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 496 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter accessible */
comment|/* 498 */
name|NdrFcShort
argument_list|(
literal|0x13
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, */
comment|/* 500 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 502 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Type Offset=2 */
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
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 508 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_isColumnSelected */
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
literal|0x10
argument_list|)
block|,
comment|/* 16 */
comment|/* 518 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
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
literal|0x21
argument_list|)
block|,
comment|/* 33 */
comment|/* 524 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 526 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 528 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
comment|/* Parameter column */
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
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 538 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter isSelected */
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
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 544 */
literal|0x3
block|,
comment|/* FC_SMALL */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 546 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 548 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 550 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_isRowSelected */
comment|/* 552 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 554 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 558 */
name|NdrFcShort
argument_list|(
literal|0x11
argument_list|)
block|,
comment|/* 17 */
comment|/* 560 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* x86 Stack size/offset = 16 */
comment|/* 562 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 564 */
name|NdrFcShort
argument_list|(
literal|0x21
argument_list|)
block|,
comment|/* 33 */
comment|/* 566 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 568 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 574 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter row */
comment|/* 576 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 578 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 580 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Parameter isSelected */
comment|/* 582 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 584 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 586 */
literal|0x3
block|,
comment|/* FC_SMALL */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 588 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 590 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 592 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure selectRow */
comment|/* 594 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 596 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 600 */
name|NdrFcShort
argument_list|(
literal|0x12
argument_list|)
block|,
comment|/* 18 */
comment|/* 602 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 604 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 606 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 608 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 610 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 612 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 614 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 616 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter row */
comment|/* 618 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 620 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 622 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 624 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 626 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 628 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure selectColumn */
comment|/* 630 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 632 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 636 */
name|NdrFcShort
argument_list|(
literal|0x13
argument_list|)
block|,
comment|/* 19 */
comment|/* 638 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 640 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 642 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 644 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 646 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 648 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 650 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 652 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter column */
comment|/* 654 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 656 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 658 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 660 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 662 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 664 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure unselectRow */
comment|/* 666 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 668 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 672 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* 20 */
comment|/* 674 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
comment|/* 676 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 678 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 680 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 682 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
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
comment|/* 688 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter row */
comment|/* 690 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 692 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 694 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 696 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 698 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 700 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure unselectColumn */
comment|/* 702 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 704 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 708 */
name|NdrFcShort
argument_list|(
literal|0x15
argument_list|)
block|,
comment|/* 21 */
comment|/* 710 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 716 */
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 718 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 720 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter column */
comment|/* 726 */
name|NdrFcShort
argument_list|(
literal|0x48
argument_list|)
block|,
comment|/* Flags:  in, base type, */
comment|/* 728 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 730 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Return value */
comment|/* 732 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 734 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 736 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
comment|/* Procedure get_modelChange */
comment|/* 738 */
literal|0x33
block|,
comment|/* FC_AUTO_HANDLE */
literal|0x6c
block|,
comment|/* Old Flags:  object, Oi2 */
comment|/* 740 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 744 */
name|NdrFcShort
argument_list|(
literal|0x16
argument_list|)
block|,
comment|/* 22 */
comment|/* 746 */
name|NdrFcShort
argument_list|(
literal|0xc
argument_list|)
block|,
comment|/* x86 Stack size/offset = 12 */
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
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 752 */
literal|0x45
block|,
comment|/* Oi2 Flags:  srv must size, has return, has ext, */
literal|0x2
block|,
comment|/* 2 */
comment|/* 754 */
literal|0x8
block|,
comment|/* 8 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 756 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 758 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 760 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* Parameter modelChange */
comment|/* 762 */
name|NdrFcShort
argument_list|(
literal|0x6113
argument_list|)
block|,
comment|/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
comment|/* 764 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* x86 Stack size/offset = 4 */
comment|/* 766 */
name|NdrFcShort
argument_list|(
literal|0x7e
argument_list|)
block|,
comment|/* Type Offset=126 */
comment|/* Return value */
comment|/* 768 */
name|NdrFcShort
argument_list|(
literal|0x70
argument_list|)
block|,
comment|/* Flags:  out, return, base type, */
comment|/* 770 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 772 */
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
DECL|variable|AccessibleTable2__MIDL_TypeFormatString
specifier|static
specifier|const
name|AccessibleTable2_MIDL_TYPE_FORMAT_STRING
name|AccessibleTable2__MIDL_TypeFormatString
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
literal|0x10
block|,
comment|/* FC_RP [pointer_deref] */
comment|/*  4 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (6) */
comment|/*  6 */
literal|0x2f
block|,
comment|/* FC_IP */
literal|0x5a
block|,
comment|/* FC_CONSTANT_IID */
comment|/*  8 */
name|NdrFcLong
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 12 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 14 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 16 */
literal|0xc0
block|,
comment|/* 192 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 18 */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 20 */
literal|0x0
block|,
comment|/* 0 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 22 */
literal|0x0
block|,
comment|/* 0 */
literal|0x46
block|,
comment|/* 70 */
comment|/* 24 */
literal|0x11
block|,
literal|0x4
block|,
comment|/* FC_RP [alloced_on_stack] */
comment|/* 26 */
name|NdrFcShort
argument_list|(
literal|0x1c
argument_list|)
block|,
comment|/* Offset= 28 (54) */
comment|/* 28 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 30 */
name|NdrFcShort
argument_list|(
literal|0xe
argument_list|)
block|,
comment|/* Offset= 14 (44) */
comment|/* 32 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x1
block|,
comment|/* 1 */
comment|/* 34 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* 2 */
comment|/* 36 */
literal|0x9
block|,
comment|/* Corr desc: FC_ULONG */
literal|0x0
block|,
comment|/*  */
comment|/* 38 */
name|NdrFcShort
argument_list|(
literal|0xfffc
argument_list|)
block|,
comment|/* -4 */
comment|/* 40 */
name|NdrFcShort
argument_list|(
literal|0x1
argument_list|)
block|,
comment|/* Corr flags:  early, */
comment|/* 42 */
literal|0x6
block|,
comment|/* FC_SHORT */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 44 */
literal|0x17
block|,
comment|/* FC_CSTRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 46 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* 8 */
comment|/* 48 */
name|NdrFcShort
argument_list|(
literal|0xfff0
argument_list|)
block|,
comment|/* Offset= -16 (32) */
comment|/* 50 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 52 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 54 */
literal|0xb4
block|,
comment|/* FC_USER_MARSHAL */
literal|0x83
block|,
comment|/* 131 */
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
literal|0x4
argument_list|)
block|,
comment|/* 4 */
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
literal|0xffde
argument_list|)
block|,
comment|/* Offset= -34 (28) */
comment|/* 64 */
literal|0x11
block|,
literal|0xc
block|,
comment|/* FC_RP [alloced_on_stack] [simple_pointer] */
comment|/* 66 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 68 */
literal|0x11
block|,
literal|0x14
block|,
comment|/* FC_RP [alloced_on_stack] [pointer_deref] */
comment|/* 70 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (72) */
comment|/* 72 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 74 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (76) */
comment|/* 76 */
literal|0x21
block|,
comment|/* FC_BOGUS_ARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 78 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 80 */
literal|0x28
block|,
comment|/* Corr desc:  parameter, FC_LONG */
literal|0x54
block|,
comment|/* FC_DEREFERENCE */
comment|/* 82 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 84 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Corr flags:  */
comment|/* 86 */
name|NdrFcLong
argument_list|(
literal|0xffffffff
argument_list|)
block|,
comment|/* -1 */
comment|/* 90 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Corr flags:  */
comment|/* 92 */
literal|0x4c
block|,
comment|/* FC_EMBEDDED_COMPLEX */
literal|0x0
block|,
comment|/* 0 */
comment|/* 94 */
name|NdrFcShort
argument_list|(
literal|0xffa8
argument_list|)
block|,
comment|/* Offset= -88 (6) */
comment|/* 96 */
literal|0x5c
block|,
comment|/* FC_PAD */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 98 */
literal|0x11
block|,
literal|0x14
block|,
comment|/* FC_RP [alloced_on_stack] [pointer_deref] */
comment|/* 100 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (102) */
comment|/* 102 */
literal|0x13
block|,
literal|0x0
block|,
comment|/* FC_OP */
comment|/* 104 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (106) */
comment|/* 106 */
literal|0x1b
block|,
comment|/* FC_CARRAY */
literal|0x3
block|,
comment|/* 3 */
comment|/* 108 */
name|NdrFcShort
argument_list|(
literal|0x4
argument_list|)
block|,
comment|/* 4 */
comment|/* 110 */
literal|0x28
block|,
comment|/* Corr desc:  parameter, FC_LONG */
literal|0x54
block|,
comment|/* FC_DEREFERENCE */
comment|/* 112 */
name|NdrFcShort
argument_list|(
literal|0x8
argument_list|)
block|,
comment|/* x86 Stack size/offset = 8 */
comment|/* 114 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Corr flags:  */
comment|/* 116 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x5b
block|,
comment|/* FC_END */
comment|/* 118 */
literal|0x11
block|,
literal|0xc
block|,
comment|/* FC_RP [alloced_on_stack] [simple_pointer] */
comment|/* 120 */
literal|0x3
block|,
comment|/* FC_SMALL */
literal|0x5c
block|,
comment|/* FC_PAD */
comment|/* 122 */
literal|0x11
block|,
literal|0x4
block|,
comment|/* FC_RP [alloced_on_stack] */
comment|/* 124 */
name|NdrFcShort
argument_list|(
literal|0x2
argument_list|)
block|,
comment|/* Offset= 2 (126) */
comment|/* 126 */
literal|0x1a
block|,
comment|/* FC_BOGUS_STRUCT */
literal|0x3
block|,
comment|/* 3 */
comment|/* 128 */
name|NdrFcShort
argument_list|(
literal|0x14
argument_list|)
block|,
comment|/* 20 */
comment|/* 130 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
comment|/* 132 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* Offset= 0 (132) */
comment|/* 134 */
literal|0xd
block|,
comment|/* FC_ENUM16 */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 136 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x8
block|,
comment|/* FC_LONG */
comment|/* 138 */
literal|0x8
block|,
comment|/* FC_LONG */
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
comment|/* Object interface: IUnknown, ver. 0.0,    GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */
end_comment
begin_comment
comment|/* Object interface: IAccessibleTable2, ver. 0.0,    GUID={0x6167f295,0x06f0,0x4cdd,{0xa1,0xfa,0x02,0xe2,0x51,0x53,0xd8,0x69}} */
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
DECL|variable|IAccessibleTable2_FormatStringOffsetTable
specifier|static
specifier|const
name|unsigned
name|short
name|IAccessibleTable2_FormatStringOffsetTable
index|[]
init|=
block|{
literal|0
block|,
literal|48
block|,
literal|84
block|,
literal|126
block|,
literal|162
block|,
literal|198
block|,
literal|234
block|,
literal|270
block|,
literal|306
block|,
literal|348
block|,
literal|390
block|,
literal|432
block|,
literal|474
block|,
literal|510
block|,
literal|552
block|,
literal|594
block|,
literal|630
block|,
literal|666
block|,
literal|702
block|,
literal|738
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|IAccessibleTable2_ProxyInfo
specifier|static
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleTable2_ProxyInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
name|AccessibleTable2__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleTable2_FormatStringOffsetTable
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
DECL|variable|IAccessibleTable2_ServerInfo
specifier|static
specifier|const
name|MIDL_SERVER_INFO
name|IAccessibleTable2_ServerInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
literal|0
block|,
name|AccessibleTable2__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleTable2_FormatStringOffsetTable
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
literal|23
argument_list|)
end_macro
begin_expr_stmt
name|_IAccessibleTable2ProxyVtbl
operator|=
block|{
operator|&
name|IAccessibleTable2_ProxyInfo
block|,
operator|&
name|IID_IAccessibleTable2
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
comment|/* IAccessibleTable2::get_cellAt */
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
comment|/* IAccessibleTable2::get_caption */
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
comment|/* IAccessibleTable2::get_columnDescription */
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
comment|/* IAccessibleTable2::get_nColumns */
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
comment|/* IAccessibleTable2::get_nRows */
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
comment|/* IAccessibleTable2::get_nSelectedCells */
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
comment|/* IAccessibleTable2::get_nSelectedColumns */
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
comment|/* IAccessibleTable2::get_nSelectedRows */
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
comment|/* IAccessibleTable2::get_rowDescription */
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
comment|/* IAccessibleTable2::get_selectedCells */
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
comment|/* IAccessibleTable2::get_selectedColumns */
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
comment|/* IAccessibleTable2::get_selectedRows */
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
comment|/* IAccessibleTable2::get_summary */
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
comment|/* IAccessibleTable2::get_isColumnSelected */
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
comment|/* IAccessibleTable2::get_isRowSelected */
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
comment|/* IAccessibleTable2::selectRow */
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
comment|/* IAccessibleTable2::selectColumn */
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
comment|/* IAccessibleTable2::unselectRow */
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
comment|/* IAccessibleTable2::unselectColumn */
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
comment|/* IAccessibleTable2::get_modelChange */
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|_IAccessibleTable2StubVtbl
specifier|const
name|CInterfaceStubVtbl
name|_IAccessibleTable2StubVtbl
init|=
block|{
operator|&
name|IID_IAccessibleTable2
block|,
operator|&
name|IAccessibleTable2_ServerInfo
block|,
literal|23
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
name|AccessibleTable2__MIDL_TypeFormatString
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
DECL|variable|_AccessibleTable2_ProxyVtblList
specifier|const
name|CInterfaceProxyVtbl
modifier|*
specifier|const
name|_AccessibleTable2_ProxyVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceProxyVtbl
operator|*
operator|)
operator|&
name|_IAccessibleTable2ProxyVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleTable2_StubVtblList
specifier|const
name|CInterfaceStubVtbl
modifier|*
specifier|const
name|_AccessibleTable2_StubVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceStubVtbl
operator|*
operator|)
operator|&
name|_IAccessibleTable2StubVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleTable2_InterfaceNamesList
name|PCInterfaceName
specifier|const
name|_AccessibleTable2_InterfaceNamesList
index|[]
init|=
block|{
literal|"IAccessibleTable2"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|_AccessibleTable2_CHECK_IID
define|#
directive|define
name|_AccessibleTable2_CHECK_IID
parameter_list|(
name|n
parameter_list|)
value|IID_GENERIC_CHECK_IID( _AccessibleTable2, pIID, n)
end_define
begin_function
DECL|function|_AccessibleTable2_IID_Lookup
name|int
name|__stdcall
name|_AccessibleTable2_IID_Lookup
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
name|_AccessibleTable2_CHECK_IID
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
DECL|variable|AccessibleTable2_ProxyFileInfo
specifier|const
name|ExtendedProxyFileInfo
name|AccessibleTable2_ProxyFileInfo
init|=
block|{
operator|(
name|PCInterfaceProxyVtblList
operator|*
operator|)
operator|&
name|_AccessibleTable2_ProxyVtblList
block|,
operator|(
name|PCInterfaceStubVtblList
operator|*
operator|)
operator|&
name|_AccessibleTable2_StubVtblList
block|,
operator|(
specifier|const
name|PCInterfaceName
operator|*
operator|)
operator|&
name|_AccessibleTable2_InterfaceNamesList
block|,
literal|0
block|,
comment|/* no delegation */
operator|&
name|_AccessibleTable2_IID_Lookup
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
