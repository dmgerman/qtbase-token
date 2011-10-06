begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the proxy stub code */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:58 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleHypertext.idl:     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
file|"AccessibleHypertext.h"
end_include
begin_define
DECL|macro|TYPE_FORMAT_STRING_SIZE
define|#
directive|define
name|TYPE_FORMAT_STRING_SIZE
value|29
end_define
begin_define
DECL|macro|PROC_FORMAT_STRING_SIZE
define|#
directive|define
name|PROC_FORMAT_STRING_SIZE
value|127
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
value|0
end_define
begin_typedef
DECL|struct|_AccessibleHypertext_MIDL_TYPE_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleHypertext_MIDL_TYPE_FORMAT_STRING
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
DECL|typedef|AccessibleHypertext_MIDL_TYPE_FORMAT_STRING
name|AccessibleHypertext_MIDL_TYPE_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleHypertext_MIDL_PROC_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleHypertext_MIDL_PROC_FORMAT_STRING
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
DECL|typedef|AccessibleHypertext_MIDL_PROC_FORMAT_STRING
name|AccessibleHypertext_MIDL_PROC_FORMAT_STRING
typedef|;
end_typedef
begin_typedef
DECL|struct|_AccessibleHypertext_MIDL_EXPR_FORMAT_STRING
typedef|typedef
struct|struct
name|_AccessibleHypertext_MIDL_EXPR_FORMAT_STRING
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
DECL|typedef|AccessibleHypertext_MIDL_EXPR_FORMAT_STRING
name|AccessibleHypertext_MIDL_EXPR_FORMAT_STRING
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
name|AccessibleHypertext_MIDL_TYPE_FORMAT_STRING
name|AccessibleHypertext__MIDL_TypeFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleHypertext_MIDL_PROC_FORMAT_STRING
name|AccessibleHypertext__MIDL_ProcFormatString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|AccessibleHypertext_MIDL_EXPR_FORMAT_STRING
name|AccessibleHypertext__MIDL_ExprFormatString
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
name|IAccessibleHypertext_ServerInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleHypertext_ProxyInfo
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
DECL|variable|AccessibleHypertext__MIDL_ProcFormatString
specifier|static
specifier|const
name|AccessibleHypertext_MIDL_PROC_FORMAT_STRING
name|AccessibleHypertext__MIDL_ProcFormatString
init|=
block|{
literal|0
block|,
block|{
comment|/* Procedure get_nHyperlinks */
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
literal|0x16
argument_list|)
block|,
comment|/* 22 */
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
comment|/* Parameter hyperlinkCount */
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
comment|/* Procedure get_hyperlink */
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
literal|0x17
argument_list|)
block|,
comment|/* 23 */
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
comment|/* Parameter index */
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
comment|/* Parameter hyperlink */
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
comment|/* Procedure get_hyperlinkIndex */
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
literal|0x18
argument_list|)
block|,
comment|/* 24 */
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
literal|0x44
block|,
comment|/* Oi2 Flags:  has return, has ext, */
literal|0x3
block|,
comment|/* 3 */
comment|/* 98 */
literal|0xa
block|,
comment|/* 10 */
literal|0x1
block|,
comment|/* Ext Flags:  new corr desc, */
comment|/* 100 */
name|NdrFcShort
argument_list|(
literal|0x0
argument_list|)
block|,
comment|/* 0 */
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
comment|/* Parameter charIndex */
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
comment|/* Parameter hyperlinkIndex */
comment|/* 114 */
name|NdrFcShort
argument_list|(
literal|0x2150
argument_list|)
block|,
comment|/* Flags:  out, base type, simple ref, srv alloc size=8 */
comment|/* 116 */
name|NdrFcShort
argument_list|(
literal|0x10
argument_list|)
block|,
comment|/* X64 Stack size/offset = 16 */
comment|/* 118 */
literal|0x8
block|,
comment|/* FC_LONG */
literal|0x0
block|,
comment|/* 0 */
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
literal|0x0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|AccessibleHypertext__MIDL_TypeFormatString
specifier|static
specifier|const
name|AccessibleHypertext_MIDL_TYPE_FORMAT_STRING
name|AccessibleHypertext__MIDL_TypeFormatString
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
literal|0x1c20f2b
argument_list|)
block|,
comment|/* 29495083 */
comment|/* 16 */
name|NdrFcShort
argument_list|(
literal|0x3dd2
argument_list|)
block|,
comment|/* 15826 */
comment|/* 18 */
name|NdrFcShort
argument_list|(
literal|0x400f
argument_list|)
block|,
comment|/* 16399 */
comment|/* 20 */
literal|0x94
block|,
comment|/* 148 */
literal|0x9f
block|,
comment|/* 159 */
comment|/* 22 */
literal|0xad
block|,
comment|/* 173 */
literal|0x0
block|,
comment|/* 0 */
comment|/* 24 */
literal|0xbd
block|,
comment|/* 189 */
literal|0xab
block|,
comment|/* 171 */
comment|/* 26 */
literal|0x1d
block|,
comment|/* 29 */
literal|0x41
block|,
comment|/* 65 */
literal|0x0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Object interface: IUnknown, ver. 0.0,    GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */
end_comment
begin_comment
comment|/* Object interface: IAccessibleText, ver. 0.0,    GUID={0x24FD2FFB,0x3AAD,0x4a08,{0x83,0x35,0xA3,0xAD,0x89,0xC0,0xFB,0x4B}} */
end_comment
begin_comment
comment|/* Object interface: IAccessibleHypertext, ver. 0.0,    GUID={0x6B4F8BBF,0xF1F2,0x418a,{0xB3,0x5E,0xA1,0x95,0xBC,0x41,0x03,0xB9}} */
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
DECL|variable|IAccessibleHypertext_FormatStringOffsetTable
specifier|static
specifier|const
name|unsigned
name|short
name|IAccessibleHypertext_FormatStringOffsetTable
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
literal|0
block|,
literal|38
block|,
literal|82
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|IAccessibleHypertext_ProxyInfo
specifier|static
specifier|const
name|MIDL_STUBLESS_PROXY_INFO
name|IAccessibleHypertext_ProxyInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
name|AccessibleHypertext__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleHypertext_FormatStringOffsetTable
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
DECL|variable|IAccessibleHypertext_ServerInfo
specifier|static
specifier|const
name|MIDL_SERVER_INFO
name|IAccessibleHypertext_ServerInfo
init|=
block|{
operator|&
name|Object_StubDesc
block|,
literal|0
block|,
name|AccessibleHypertext__MIDL_ProcFormatString
operator|.
name|Format
block|,
operator|&
name|IAccessibleHypertext_FormatStringOffsetTable
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
literal|25
argument_list|)
end_macro
begin_expr_stmt
name|_IAccessibleHypertextProxyVtbl
operator|=
block|{
operator|&
name|IAccessibleHypertext_ProxyInfo
block|,
operator|&
name|IID_IAccessibleHypertext
block|,
name|IUnknown_QueryInterface_Proxy
block|,
name|IUnknown_AddRef_Proxy
block|,
name|IUnknown_Release_Proxy
block|,
literal|0
comment|/* IAccessibleText::addSelection */
block|,
literal|0
comment|/* IAccessibleText::get_attributes */
block|,
literal|0
comment|/* IAccessibleText::get_caretOffset */
block|,
literal|0
comment|/* IAccessibleText::get_characterExtents */
block|,
literal|0
comment|/* IAccessibleText::get_nSelections */
block|,
literal|0
comment|/* IAccessibleText::get_offsetAtPoint */
block|,
literal|0
comment|/* IAccessibleText::get_selection */
block|,
literal|0
comment|/* IAccessibleText::get_text */
block|,
literal|0
comment|/* IAccessibleText::get_textBeforeOffset */
block|,
literal|0
comment|/* IAccessibleText::get_textAfterOffset */
block|,
literal|0
comment|/* IAccessibleText::get_textAtOffset */
block|,
literal|0
comment|/* IAccessibleText::removeSelection */
block|,
literal|0
comment|/* IAccessibleText::setCaretOffset */
block|,
literal|0
comment|/* IAccessibleText::setSelection */
block|,
literal|0
comment|/* IAccessibleText::get_nCharacters */
block|,
literal|0
comment|/* IAccessibleText::scrollSubstringTo */
block|,
literal|0
comment|/* IAccessibleText::scrollSubstringToPoint */
block|,
literal|0
comment|/* IAccessibleText::get_newText */
block|,
literal|0
comment|/* IAccessibleText::get_oldText */
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
comment|/* IAccessibleHypertext::get_nHyperlinks */
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
comment|/* IAccessibleHypertext::get_hyperlink */
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
comment|/* IAccessibleHypertext::get_hyperlinkIndex */
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|IAccessibleHypertext_table
specifier|static
specifier|const
name|PRPC_STUB_FUNCTION
name|IAccessibleHypertext_table
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
name|NdrStubCall2
block|,
name|NdrStubCall2
block|,
name|NdrStubCall2
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_IAccessibleHypertextStubVtbl
name|CInterfaceStubVtbl
name|_IAccessibleHypertextStubVtbl
init|=
block|{
operator|&
name|IID_IAccessibleHypertext
block|,
operator|&
name|IAccessibleHypertext_ServerInfo
block|,
literal|25
block|,
operator|&
name|IAccessibleHypertext_table
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
name|AccessibleHypertext__MIDL_TypeFormatString
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
literal|0
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
DECL|variable|_AccessibleHypertext_ProxyVtblList
specifier|const
name|CInterfaceProxyVtbl
modifier|*
specifier|const
name|_AccessibleHypertext_ProxyVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceProxyVtbl
operator|*
operator|)
operator|&
name|_IAccessibleHypertextProxyVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleHypertext_StubVtblList
specifier|const
name|CInterfaceStubVtbl
modifier|*
specifier|const
name|_AccessibleHypertext_StubVtblList
index|[]
init|=
block|{
operator|(
name|CInterfaceStubVtbl
operator|*
operator|)
operator|&
name|_IAccessibleHypertextStubVtbl
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleHypertext_InterfaceNamesList
name|PCInterfaceName
specifier|const
name|_AccessibleHypertext_InterfaceNamesList
index|[]
init|=
block|{
literal|"IAccessibleHypertext"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_AccessibleHypertext_BaseIIDList
specifier|const
name|IID
modifier|*
specifier|const
name|_AccessibleHypertext_BaseIIDList
index|[]
init|=
block|{
operator|&
name|IID_IAccessibleText
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|_AccessibleHypertext_CHECK_IID
define|#
directive|define
name|_AccessibleHypertext_CHECK_IID
parameter_list|(
name|n
parameter_list|)
value|IID_GENERIC_CHECK_IID( _AccessibleHypertext, pIID, n)
end_define
begin_function
DECL|function|_AccessibleHypertext_IID_Lookup
name|int
name|__stdcall
name|_AccessibleHypertext_IID_Lookup
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
name|_AccessibleHypertext_CHECK_IID
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
DECL|variable|AccessibleHypertext_ProxyFileInfo
specifier|const
name|ExtendedProxyFileInfo
name|AccessibleHypertext_ProxyFileInfo
init|=
block|{
operator|(
name|PCInterfaceProxyVtblList
operator|*
operator|)
operator|&
name|_AccessibleHypertext_ProxyVtblList
block|,
operator|(
name|PCInterfaceStubVtblList
operator|*
operator|)
operator|&
name|_AccessibleHypertext_StubVtblList
block|,
operator|(
specifier|const
name|PCInterfaceName
operator|*
operator|)
operator|&
name|_AccessibleHypertext_InterfaceNamesList
block|,
operator|(
specifier|const
name|IID
operator|*
operator|*
operator|)
operator|&
name|_AccessibleHypertext_BaseIIDList
block|,
operator|&
name|_AccessibleHypertext_IID_Lookup
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
