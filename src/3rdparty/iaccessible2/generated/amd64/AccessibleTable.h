begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the definitions for the interfaces */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:59 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleTable.idl:     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
name|COM_NO_WINDOWS_H
end_ifndef
begin_include
include|#
directive|include
file|"windows.h"
end_include
begin_include
include|#
directive|include
file|"ole2.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*COM_NO_WINDOWS_H*/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__AccessibleTable_h__
end_ifndef
begin_define
DECL|macro|__AccessibleTable_h__
define|#
directive|define
name|__AccessibleTable_h__
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
begin_ifndef
ifndef|#
directive|ifndef
name|__IAccessibleTable_FWD_DEFINED__
end_ifndef
begin_define
DECL|macro|__IAccessibleTable_FWD_DEFINED__
define|#
directive|define
name|__IAccessibleTable_FWD_DEFINED__
end_define
begin_typedef
DECL|typedef|IAccessibleTable
typedef|typedef
name|interface
name|IAccessibleTable
name|IAccessibleTable
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __IAccessibleTable_FWD_DEFINED__ */
end_comment
begin_comment
comment|/* header files for imported files */
end_comment
begin_include
include|#
directive|include
file|"objidl.h"
end_include
begin_include
include|#
directive|include
file|"oaidl.h"
end_include
begin_include
include|#
directive|include
file|"oleacc.h"
end_include
begin_include
include|#
directive|include
file|"Accessible2.h"
end_include
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
ifndef|#
directive|ifndef
name|__IAccessibleTable_INTERFACE_DEFINED__
DECL|macro|__IAccessibleTable_INTERFACE_DEFINED__
define|#
directive|define
name|__IAccessibleTable_INTERFACE_DEFINED__
comment|/* interface IAccessibleTable */
comment|/* [uuid][object] */
DECL|variable|IID_IAccessibleTable
name|EXTERN_C
specifier|const
name|IID
name|IID_IAccessibleTable
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
name|MIDL_INTERFACE
argument_list|(
literal|"35AD8070-C20C-4fb4-B094-F4F7275DD469"
argument_list|)
name|IAccessibleTable
label|:
name|public
name|IUnknown
block|{
name|public
label|:
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accessibleAt
parameter_list|(
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|IUnknown
modifier|*
modifier|*
name|accessible
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_caption
parameter_list|(
comment|/* [retval][out] */
name|IUnknown
modifier|*
modifier|*
name|accessible
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_childIndex
parameter_list|(
comment|/* [in] */
name|long
name|rowIndex
parameter_list|,
comment|/* [in] */
name|long
name|columnIndex
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|cellIndex
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_columnDescription
parameter_list|(
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|description
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_columnExtentAt
parameter_list|(
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nColumnsSpanned
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_columnHeader
parameter_list|(
comment|/* [out] */
name|IAccessibleTable
modifier|*
modifier|*
name|accessibleTable
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|startingRowIndex
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_columnIndex
parameter_list|(
comment|/* [in] */
name|long
name|cellIndex
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|columnIndex
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nColumns
parameter_list|(
comment|/* [retval][out] */
name|long
modifier|*
name|columnCount
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nRows
parameter_list|(
comment|/* [retval][out] */
name|long
modifier|*
name|rowCount
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nSelectedChildren
parameter_list|(
comment|/* [retval][out] */
name|long
modifier|*
name|cellCount
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nSelectedColumns
parameter_list|(
comment|/* [retval][out] */
name|long
modifier|*
name|columnCount
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nSelectedRows
parameter_list|(
comment|/* [retval][out] */
name|long
modifier|*
name|rowCount
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowDescription
parameter_list|(
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|description
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowExtentAt
parameter_list|(
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nRowsSpanned
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowHeader
parameter_list|(
comment|/* [out] */
name|IAccessibleTable
modifier|*
modifier|*
name|accessibleTable
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|startingColumnIndex
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowIndex
parameter_list|(
comment|/* [in] */
name|long
name|cellIndex
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|rowIndex
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_selectedChildren
parameter_list|(
comment|/* [in] */
name|long
name|maxChildren
parameter_list|,
comment|/* [length_is][length_is][size_is][size_is][out] */
name|long
modifier|*
modifier|*
name|children
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nChildren
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_selectedColumns
parameter_list|(
comment|/* [in] */
name|long
name|maxColumns
parameter_list|,
comment|/* [length_is][length_is][size_is][size_is][out] */
name|long
modifier|*
modifier|*
name|columns
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nColumns
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_selectedRows
parameter_list|(
comment|/* [in] */
name|long
name|maxRows
parameter_list|,
comment|/* [length_is][length_is][size_is][size_is][out] */
name|long
modifier|*
modifier|*
name|rows
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nRows
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_summary
parameter_list|(
comment|/* [retval][out] */
name|IUnknown
modifier|*
modifier|*
name|accessible
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_isColumnSelected
parameter_list|(
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|boolean
modifier|*
name|isSelected
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_isRowSelected
parameter_list|(
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [retval][out] */
name|boolean
modifier|*
name|isSelected
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_isSelected
parameter_list|(
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|boolean
modifier|*
name|isSelected
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|HRESULT
name|STDMETHODCALLTYPE
name|selectRow
parameter_list|(
comment|/* [in] */
name|long
name|row
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|HRESULT
name|STDMETHODCALLTYPE
name|selectColumn
parameter_list|(
comment|/* [in] */
name|long
name|column
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|HRESULT
name|STDMETHODCALLTYPE
name|unselectRow
parameter_list|(
comment|/* [in] */
name|long
name|row
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|HRESULT
name|STDMETHODCALLTYPE
name|unselectColumn
parameter_list|(
comment|/* [in] */
name|long
name|column
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_rowColumnExtentsAtIndex
parameter_list|(
comment|/* [in] */
name|long
name|index
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|row
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|column
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|rowExtents
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|columnExtents
parameter_list|,
comment|/* [retval][out] */
name|boolean
modifier|*
name|isSelected
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_modelChange
parameter_list|(
comment|/* [retval][out] */
name|IA2TableModelChange
modifier|*
name|modelChange
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
else|#
directive|else
comment|/* C style interface */
DECL|struct|IAccessibleTableVtbl
typedef|typedef
struct|struct
name|IAccessibleTableVtbl
block|{
name|BEGIN_INTERFACE
DECL|member|QueryInterface
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|QueryInterface
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|REFIID
name|riid
parameter_list|,
comment|/* [annotation][iid_is][out] */
name|__RPC__deref_out
name|void
modifier|*
modifier|*
name|ppvObject
parameter_list|)
function_decl|;
DECL|member|AddRef
name|ULONG
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|AddRef
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|)
function_decl|;
DECL|member|Release
name|ULONG
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|Release
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|)
function_decl|;
DECL|member|get_accessibleAt
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_accessibleAt
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|IUnknown
modifier|*
modifier|*
name|accessible
parameter_list|)
function_decl|;
DECL|member|get_caption
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_caption
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|IUnknown
modifier|*
modifier|*
name|accessible
parameter_list|)
function_decl|;
DECL|member|get_childIndex
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_childIndex
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|rowIndex
parameter_list|,
comment|/* [in] */
name|long
name|columnIndex
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|cellIndex
parameter_list|)
function_decl|;
DECL|member|get_columnDescription
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_columnDescription
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|description
parameter_list|)
function_decl|;
DECL|member|get_columnExtentAt
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_columnExtentAt
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nColumnsSpanned
parameter_list|)
function_decl|;
DECL|member|get_columnHeader
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_columnHeader
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [out] */
name|IAccessibleTable
modifier|*
modifier|*
name|accessibleTable
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|startingRowIndex
parameter_list|)
function_decl|;
DECL|member|get_columnIndex
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_columnIndex
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|cellIndex
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|columnIndex
parameter_list|)
function_decl|;
DECL|member|get_nColumns
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nColumns
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|columnCount
parameter_list|)
function_decl|;
DECL|member|get_nRows
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nRows
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|rowCount
parameter_list|)
function_decl|;
DECL|member|get_nSelectedChildren
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nSelectedChildren
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|cellCount
parameter_list|)
function_decl|;
DECL|member|get_nSelectedColumns
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nSelectedColumns
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|columnCount
parameter_list|)
function_decl|;
DECL|member|get_nSelectedRows
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nSelectedRows
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|rowCount
parameter_list|)
function_decl|;
DECL|member|get_rowDescription
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_rowDescription
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|description
parameter_list|)
function_decl|;
DECL|member|get_rowExtentAt
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_rowExtentAt
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nRowsSpanned
parameter_list|)
function_decl|;
DECL|member|get_rowHeader
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_rowHeader
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [out] */
name|IAccessibleTable
modifier|*
modifier|*
name|accessibleTable
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|startingColumnIndex
parameter_list|)
function_decl|;
DECL|member|get_rowIndex
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_rowIndex
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|cellIndex
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|rowIndex
parameter_list|)
function_decl|;
DECL|member|get_selectedChildren
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_selectedChildren
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|maxChildren
parameter_list|,
comment|/* [length_is][length_is][size_is][size_is][out] */
name|long
modifier|*
modifier|*
name|children
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nChildren
parameter_list|)
function_decl|;
DECL|member|get_selectedColumns
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_selectedColumns
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|maxColumns
parameter_list|,
comment|/* [length_is][length_is][size_is][size_is][out] */
name|long
modifier|*
modifier|*
name|columns
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nColumns
parameter_list|)
function_decl|;
DECL|member|get_selectedRows
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_selectedRows
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|maxRows
parameter_list|,
comment|/* [length_is][length_is][size_is][size_is][out] */
name|long
modifier|*
modifier|*
name|rows
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nRows
parameter_list|)
function_decl|;
DECL|member|get_summary
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_summary
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|IUnknown
modifier|*
modifier|*
name|accessible
parameter_list|)
function_decl|;
DECL|member|get_isColumnSelected
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_isColumnSelected
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|boolean
modifier|*
name|isSelected
parameter_list|)
function_decl|;
DECL|member|get_isRowSelected
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_isRowSelected
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [retval][out] */
name|boolean
modifier|*
name|isSelected
parameter_list|)
function_decl|;
DECL|member|get_isSelected
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_isSelected
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|row
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|,
comment|/* [retval][out] */
name|boolean
modifier|*
name|isSelected
parameter_list|)
function_decl|;
DECL|member|selectRow
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|selectRow
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|row
parameter_list|)
function_decl|;
DECL|member|selectColumn
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|selectColumn
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|)
function_decl|;
DECL|member|unselectRow
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|unselectRow
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|row
parameter_list|)
function_decl|;
DECL|member|unselectColumn
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|unselectColumn
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|column
parameter_list|)
function_decl|;
DECL|member|get_rowColumnExtentsAtIndex
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_rowColumnExtentsAtIndex
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|index
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|row
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|column
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|rowExtents
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|columnExtents
parameter_list|,
comment|/* [retval][out] */
name|boolean
modifier|*
name|isSelected
parameter_list|)
function_decl|;
DECL|member|get_modelChange
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_modelChange
function_decl|)
parameter_list|(
name|IAccessibleTable
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|IA2TableModelChange
modifier|*
name|modelChange
parameter_list|)
function_decl|;
name|END_INTERFACE
block|}
DECL|typedef|IAccessibleTableVtbl
name|IAccessibleTableVtbl
typedef|;
name|interface
name|IAccessibleTable
block|{
name|CONST_VTBL
name|struct
name|IAccessibleTableVtbl
modifier|*
name|lpVtbl
decl_stmt|;
block|}
empty_stmt|;
ifdef|#
directive|ifdef
name|COBJMACROS
DECL|macro|IAccessibleTable_QueryInterface
define|#
directive|define
name|IAccessibleTable_QueryInterface
parameter_list|(
name|This
parameter_list|,
name|riid
parameter_list|,
name|ppvObject
parameter_list|)
define|\
value|( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
DECL|macro|IAccessibleTable_AddRef
define|#
directive|define
name|IAccessibleTable_AddRef
parameter_list|(
name|This
parameter_list|)
define|\
value|( (This)->lpVtbl -> AddRef(This) )
DECL|macro|IAccessibleTable_Release
define|#
directive|define
name|IAccessibleTable_Release
parameter_list|(
name|This
parameter_list|)
define|\
value|( (This)->lpVtbl -> Release(This) )
DECL|macro|IAccessibleTable_get_accessibleAt
define|#
directive|define
name|IAccessibleTable_get_accessibleAt
parameter_list|(
name|This
parameter_list|,
name|row
parameter_list|,
name|column
parameter_list|,
name|accessible
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_accessibleAt(This,row,column,accessible) )
DECL|macro|IAccessibleTable_get_caption
define|#
directive|define
name|IAccessibleTable_get_caption
parameter_list|(
name|This
parameter_list|,
name|accessible
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_caption(This,accessible) )
DECL|macro|IAccessibleTable_get_childIndex
define|#
directive|define
name|IAccessibleTable_get_childIndex
parameter_list|(
name|This
parameter_list|,
name|rowIndex
parameter_list|,
name|columnIndex
parameter_list|,
name|cellIndex
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_childIndex(This,rowIndex,columnIndex,cellIndex) )
DECL|macro|IAccessibleTable_get_columnDescription
define|#
directive|define
name|IAccessibleTable_get_columnDescription
parameter_list|(
name|This
parameter_list|,
name|column
parameter_list|,
name|description
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_columnDescription(This,column,description) )
DECL|macro|IAccessibleTable_get_columnExtentAt
define|#
directive|define
name|IAccessibleTable_get_columnExtentAt
parameter_list|(
name|This
parameter_list|,
name|row
parameter_list|,
name|column
parameter_list|,
name|nColumnsSpanned
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_columnExtentAt(This,row,column,nColumnsSpanned) )
DECL|macro|IAccessibleTable_get_columnHeader
define|#
directive|define
name|IAccessibleTable_get_columnHeader
parameter_list|(
name|This
parameter_list|,
name|accessibleTable
parameter_list|,
name|startingRowIndex
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_columnHeader(This,accessibleTable,startingRowIndex) )
DECL|macro|IAccessibleTable_get_columnIndex
define|#
directive|define
name|IAccessibleTable_get_columnIndex
parameter_list|(
name|This
parameter_list|,
name|cellIndex
parameter_list|,
name|columnIndex
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_columnIndex(This,cellIndex,columnIndex) )
DECL|macro|IAccessibleTable_get_nColumns
define|#
directive|define
name|IAccessibleTable_get_nColumns
parameter_list|(
name|This
parameter_list|,
name|columnCount
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nColumns(This,columnCount) )
DECL|macro|IAccessibleTable_get_nRows
define|#
directive|define
name|IAccessibleTable_get_nRows
parameter_list|(
name|This
parameter_list|,
name|rowCount
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nRows(This,rowCount) )
DECL|macro|IAccessibleTable_get_nSelectedChildren
define|#
directive|define
name|IAccessibleTable_get_nSelectedChildren
parameter_list|(
name|This
parameter_list|,
name|cellCount
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nSelectedChildren(This,cellCount) )
DECL|macro|IAccessibleTable_get_nSelectedColumns
define|#
directive|define
name|IAccessibleTable_get_nSelectedColumns
parameter_list|(
name|This
parameter_list|,
name|columnCount
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nSelectedColumns(This,columnCount) )
DECL|macro|IAccessibleTable_get_nSelectedRows
define|#
directive|define
name|IAccessibleTable_get_nSelectedRows
parameter_list|(
name|This
parameter_list|,
name|rowCount
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nSelectedRows(This,rowCount) )
DECL|macro|IAccessibleTable_get_rowDescription
define|#
directive|define
name|IAccessibleTable_get_rowDescription
parameter_list|(
name|This
parameter_list|,
name|row
parameter_list|,
name|description
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_rowDescription(This,row,description) )
DECL|macro|IAccessibleTable_get_rowExtentAt
define|#
directive|define
name|IAccessibleTable_get_rowExtentAt
parameter_list|(
name|This
parameter_list|,
name|row
parameter_list|,
name|column
parameter_list|,
name|nRowsSpanned
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_rowExtentAt(This,row,column,nRowsSpanned) )
DECL|macro|IAccessibleTable_get_rowHeader
define|#
directive|define
name|IAccessibleTable_get_rowHeader
parameter_list|(
name|This
parameter_list|,
name|accessibleTable
parameter_list|,
name|startingColumnIndex
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_rowHeader(This,accessibleTable,startingColumnIndex) )
DECL|macro|IAccessibleTable_get_rowIndex
define|#
directive|define
name|IAccessibleTable_get_rowIndex
parameter_list|(
name|This
parameter_list|,
name|cellIndex
parameter_list|,
name|rowIndex
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_rowIndex(This,cellIndex,rowIndex) )
DECL|macro|IAccessibleTable_get_selectedChildren
define|#
directive|define
name|IAccessibleTable_get_selectedChildren
parameter_list|(
name|This
parameter_list|,
name|maxChildren
parameter_list|,
name|children
parameter_list|,
name|nChildren
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_selectedChildren(This,maxChildren,children,nChildren) )
DECL|macro|IAccessibleTable_get_selectedColumns
define|#
directive|define
name|IAccessibleTable_get_selectedColumns
parameter_list|(
name|This
parameter_list|,
name|maxColumns
parameter_list|,
name|columns
parameter_list|,
name|nColumns
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_selectedColumns(This,maxColumns,columns,nColumns) )
DECL|macro|IAccessibleTable_get_selectedRows
define|#
directive|define
name|IAccessibleTable_get_selectedRows
parameter_list|(
name|This
parameter_list|,
name|maxRows
parameter_list|,
name|rows
parameter_list|,
name|nRows
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_selectedRows(This,maxRows,rows,nRows) )
DECL|macro|IAccessibleTable_get_summary
define|#
directive|define
name|IAccessibleTable_get_summary
parameter_list|(
name|This
parameter_list|,
name|accessible
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_summary(This,accessible) )
DECL|macro|IAccessibleTable_get_isColumnSelected
define|#
directive|define
name|IAccessibleTable_get_isColumnSelected
parameter_list|(
name|This
parameter_list|,
name|column
parameter_list|,
name|isSelected
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_isColumnSelected(This,column,isSelected) )
DECL|macro|IAccessibleTable_get_isRowSelected
define|#
directive|define
name|IAccessibleTable_get_isRowSelected
parameter_list|(
name|This
parameter_list|,
name|row
parameter_list|,
name|isSelected
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_isRowSelected(This,row,isSelected) )
DECL|macro|IAccessibleTable_get_isSelected
define|#
directive|define
name|IAccessibleTable_get_isSelected
parameter_list|(
name|This
parameter_list|,
name|row
parameter_list|,
name|column
parameter_list|,
name|isSelected
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_isSelected(This,row,column,isSelected) )
DECL|macro|IAccessibleTable_selectRow
define|#
directive|define
name|IAccessibleTable_selectRow
parameter_list|(
name|This
parameter_list|,
name|row
parameter_list|)
define|\
value|( (This)->lpVtbl -> selectRow(This,row) )
DECL|macro|IAccessibleTable_selectColumn
define|#
directive|define
name|IAccessibleTable_selectColumn
parameter_list|(
name|This
parameter_list|,
name|column
parameter_list|)
define|\
value|( (This)->lpVtbl -> selectColumn(This,column) )
DECL|macro|IAccessibleTable_unselectRow
define|#
directive|define
name|IAccessibleTable_unselectRow
parameter_list|(
name|This
parameter_list|,
name|row
parameter_list|)
define|\
value|( (This)->lpVtbl -> unselectRow(This,row) )
DECL|macro|IAccessibleTable_unselectColumn
define|#
directive|define
name|IAccessibleTable_unselectColumn
parameter_list|(
name|This
parameter_list|,
name|column
parameter_list|)
define|\
value|( (This)->lpVtbl -> unselectColumn(This,column) )
DECL|macro|IAccessibleTable_get_rowColumnExtentsAtIndex
define|#
directive|define
name|IAccessibleTable_get_rowColumnExtentsAtIndex
parameter_list|(
name|This
parameter_list|,
name|index
parameter_list|,
name|row
parameter_list|,
name|column
parameter_list|,
name|rowExtents
parameter_list|,
name|columnExtents
parameter_list|,
name|isSelected
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_rowColumnExtentsAtIndex(This,index,row,column,rowExtents,columnExtents,isSelected) )
DECL|macro|IAccessibleTable_get_modelChange
define|#
directive|define
name|IAccessibleTable_get_modelChange
parameter_list|(
name|This
parameter_list|,
name|modelChange
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_modelChange(This,modelChange) )
endif|#
directive|endif
comment|/* COBJMACROS */
endif|#
directive|endif
comment|/* C style interface */
endif|#
directive|endif
comment|/* __IAccessibleTable_INTERFACE_DEFINED__ */
comment|/* Additional Prototypes for ALL interfaces */
name|unsigned
name|long
name|__RPC_USER
name|BSTR_UserSize
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|BSTR
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|char
modifier|*
name|__RPC_USER
name|BSTR_UserMarshal
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|BSTR
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|char
modifier|*
name|__RPC_USER
name|BSTR_UserUnmarshal
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|BSTR
modifier|*
parameter_list|)
function_decl|;
name|void
name|__RPC_USER
name|BSTR_UserFree
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|BSTR
modifier|*
parameter_list|)
function_decl|;
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
