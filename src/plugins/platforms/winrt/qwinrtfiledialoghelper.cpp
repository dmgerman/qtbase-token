begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtfiledialoghelper.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtfileengine.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QEventLoop>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.h>
end_include
begin_include
include|#
directive|include
file|<windows.storage.pickers.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Collections
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Storage
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Storage
operator|::
name|Pickers
namespace|;
end_using
begin_typedef
DECL|typedef|SingleFileHandler
typedef|typedef
name|IAsyncOperationCompletedHandler
argument_list|<
name|StorageFile
modifier|*
argument_list|>
name|SingleFileHandler
typedef|;
end_typedef
begin_typedef
DECL|typedef|MultipleFileHandler
typedef|typedef
name|IAsyncOperationCompletedHandler
argument_list|<
name|IVectorView
argument_list|<
name|StorageFile
modifier|*
argument_list|>
modifier|*
argument_list|>
name|MultipleFileHandler
typedef|;
end_typedef
begin_typedef
DECL|typedef|SingleFolderHandler
typedef|typedef
name|IAsyncOperationCompletedHandler
argument_list|<
name|StorageFolder
modifier|*
argument_list|>
name|SingleFolderHandler
typedef|;
end_typedef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// Required for save file picker
end_comment
begin_class
DECL|class|WindowsStringVector
class|class
name|WindowsStringVector
super|:
specifier|public
name|RuntimeClass
argument_list|<
name|IVector
argument_list|<
name|HSTRING
argument_list|>
argument_list|>
block|{
public|public:
DECL|function|GetAt
name|HRESULT
name|__stdcall
name|GetAt
parameter_list|(
name|quint32
name|index
parameter_list|,
name|HSTRING
modifier|*
name|item
parameter_list|)
block|{
operator|*
name|item
operator|=
name|impl
operator|.
name|at
argument_list|(
name|index
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|get_Size
name|HRESULT
name|__stdcall
name|get_Size
parameter_list|(
name|quint32
modifier|*
name|size
parameter_list|)
block|{
operator|*
name|size
operator|=
name|impl
operator|.
name|size
argument_list|()
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|GetView
name|HRESULT
name|__stdcall
name|GetView
parameter_list|(
name|IVectorView
argument_list|<
name|HSTRING
argument_list|>
modifier|*
modifier|*
name|view
parameter_list|)
block|{
operator|*
name|view
operator|=
name|Q_NULLPTR
expr_stmt|;
return|return
name|E_NOTIMPL
return|;
block|}
DECL|function|IndexOf
name|HRESULT
name|__stdcall
name|IndexOf
parameter_list|(
name|HSTRING
name|value
parameter_list|,
name|quint32
modifier|*
name|index
parameter_list|,
name|boolean
modifier|*
name|found
parameter_list|)
block|{
operator|*
name|found
operator|=
literal|false
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|impl
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|qint32
name|result
decl_stmt|;
name|HRESULT
name|hr
init|=
name|WindowsCompareStringOrdinal
argument_list|(
name|impl
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|value
argument_list|,
operator|&
name|result
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|hr
return|;
if|if
condition|(
name|result
operator|==
literal|0
condition|)
block|{
operator|*
name|index
operator|=
name|quint32
argument_list|(
name|i
argument_list|)
expr_stmt|;
operator|*
name|found
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
return|return
name|S_OK
return|;
block|}
DECL|function|SetAt
name|HRESULT
name|__stdcall
name|SetAt
parameter_list|(
name|quint32
name|index
parameter_list|,
name|HSTRING
name|item
parameter_list|)
block|{
name|HSTRING
name|newItem
decl_stmt|;
name|HRESULT
name|hr
init|=
name|WindowsDuplicateString
argument_list|(
name|item
argument_list|,
operator|&
name|newItem
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|hr
return|;
name|impl
index|[
name|index
index|]
operator|=
name|newItem
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|InsertAt
name|HRESULT
name|__stdcall
name|InsertAt
parameter_list|(
name|quint32
name|index
parameter_list|,
name|HSTRING
name|item
parameter_list|)
block|{
name|HSTRING
name|newItem
decl_stmt|;
name|HRESULT
name|hr
init|=
name|WindowsDuplicateString
argument_list|(
name|item
argument_list|,
operator|&
name|newItem
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|hr
return|;
name|impl
operator|.
name|insert
argument_list|(
name|index
argument_list|,
name|newItem
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|RemoveAt
name|HRESULT
name|__stdcall
name|RemoveAt
parameter_list|(
name|quint32
name|index
parameter_list|)
block|{
name|WindowsDeleteString
argument_list|(
name|impl
operator|.
name|takeAt
argument_list|(
name|index
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|Append
name|HRESULT
name|__stdcall
name|Append
parameter_list|(
name|HSTRING
name|item
parameter_list|)
block|{
name|HSTRING
name|newItem
decl_stmt|;
name|HRESULT
name|hr
init|=
name|WindowsDuplicateString
argument_list|(
name|item
argument_list|,
operator|&
name|newItem
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|hr
return|;
name|impl
operator|.
name|append
argument_list|(
name|newItem
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|RemoveAtEnd
name|HRESULT
name|__stdcall
name|RemoveAtEnd
parameter_list|()
block|{
name|WindowsDeleteString
argument_list|(
name|impl
operator|.
name|takeLast
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|Clear
name|HRESULT
name|__stdcall
name|Clear
parameter_list|()
block|{
foreach|foreach
control|(
specifier|const
name|HSTRING
modifier|&
name|item
decl|,
name|impl
control|)
name|WindowsDeleteString
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|impl
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
name|S_OK
return|;
block|}
private|private:
DECL|member|impl
name|QVector
argument_list|<
name|HSTRING
argument_list|>
name|impl
decl_stmt|;
block|}
class|;
end_class
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|initializePicker
specifier|static
name|bool
name|initializePicker
parameter_list|(
name|HSTRING
name|runtimeId
parameter_list|,
name|T
modifier|*
modifier|*
name|picker
parameter_list|,
specifier|const
name|QSharedPointer
argument_list|<
name|QFileDialogOptions
argument_list|>
modifier|&
name|options
parameter_list|)
block|{
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IInspectable
argument_list|>
name|basePicker
decl_stmt|;
name|hr
operator|=
name|RoActivateInstance
argument_list|(
name|runtimeId
argument_list|,
operator|&
name|basePicker
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to instantiate file picker"
argument_list|)
expr_stmt|;
name|hr
operator|=
name|basePicker
operator|.
name|Get
argument_list|()
operator|->
name|QueryInterface
argument_list|(
name|IID_PPV_ARGS
argument_list|(
name|picker
argument_list|)
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to cast file picker"
argument_list|)
expr_stmt|;
if|if
condition|(
name|options
operator|->
name|isLabelExplicitlySet
argument_list|(
name|QFileDialogOptions
operator|::
name|Accept
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|labelText
init|=
name|options
operator|->
name|labelText
argument_list|(
name|QFileDialogOptions
operator|::
name|Accept
argument_list|)
decl_stmt|;
name|HStringReference
name|labelTextRef
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|labelText
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|labelText
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|hr
operator|=
operator|(
operator|*
name|picker
operator|)
operator|->
name|put_CommitButtonText
argument_list|(
name|labelTextRef
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to set commit button text"
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|initializeOpenPickerOptions
specifier|static
name|bool
name|initializeOpenPickerOptions
parameter_list|(
name|T
modifier|*
name|picker
parameter_list|,
specifier|const
name|QSharedPointer
argument_list|<
name|QFileDialogOptions
argument_list|>
modifier|&
name|options
parameter_list|)
block|{
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|put_ViewMode
argument_list|(
name|options
operator|->
name|viewMode
argument_list|()
operator|==
name|QFileDialogOptions
operator|::
name|Detail
condition|?
name|PickerViewMode_Thumbnail
else|:
name|PickerViewMode_List
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to set picker view mode"
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IVector
argument_list|<
name|HSTRING
argument_list|>
argument_list|>
name|filters
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|get_FileTypeFilter
argument_list|(
operator|&
name|filters
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to get file type filters list"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|namedFilter
decl|,
name|options
operator|->
name|nameFilters
argument_list|()
control|)
block|{
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|filter
decl|,
name|QPlatformFileDialogHelper
operator|::
name|cleanFilterList
argument_list|(
name|namedFilter
argument_list|)
control|)
block|{
comment|// Remove leading star
specifier|const
name|int
name|offset
init|=
operator|(
name|filter
operator|.
name|length
argument_list|()
operator|>
literal|1
operator|&&
name|filter
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'*'
argument_list|)
argument_list|)
operator|)
condition|?
literal|1
else|:
literal|0
decl_stmt|;
name|HStringReference
name|filterRef
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|filter
operator|.
name|utf16
argument_list|()
operator|+
name|offset
argument_list|)
argument_list|,
name|filter
operator|.
name|length
argument_list|()
operator|-
name|offset
argument_list|)
decl_stmt|;
name|hr
operator|=
name|filters
operator|->
name|Append
argument_list|(
name|filterRef
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to add named file filter \"%s\": %s"
argument_list|,
name|qPrintable
argument_list|(
name|filter
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|// The file dialog won't open with an empty list - add a default wildcard
name|quint32
name|size
decl_stmt|;
name|hr
operator|=
name|filters
operator|->
name|get_Size
argument_list|(
operator|&
name|size
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to get file type filters list size"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|size
condition|)
block|{
name|hr
operator|=
name|filters
operator|->
name|Append
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
literal|L"*"
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to add default wildcard to file type filters list"
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_class
DECL|class|QWinRTFileDialogHelperPrivate
class|class
name|QWinRTFileDialogHelperPrivate
block|{
public|public:
DECL|member|shown
name|bool
name|shown
decl_stmt|;
DECL|member|loop
name|QEventLoop
name|loop
decl_stmt|;
comment|// Input
DECL|member|directory
name|QUrl
name|directory
decl_stmt|;
DECL|member|saveFileName
name|QUrl
name|saveFileName
decl_stmt|;
DECL|member|selectedNameFilter
name|QString
name|selectedNameFilter
decl_stmt|;
comment|// Output
DECL|member|selectedFiles
name|QList
argument_list|<
name|QUrl
argument_list|>
name|selectedFiles
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWinRTFileDialogHelper
name|QWinRTFileDialogHelper
operator|::
name|QWinRTFileDialogHelper
parameter_list|()
member_init_list|:
name|QPlatformFileDialogHelper
argument_list|()
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|QWinRTFileDialogHelperPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|d
operator|->
name|shown
operator|=
literal|false
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWinRTFileDialogHelper
name|QWinRTFileDialogHelper
operator|::
name|~
name|QWinRTFileDialogHelper
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|exec
name|void
name|QWinRTFileDialogHelper
operator|::
name|exec
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|shown
condition|)
name|show
argument_list|(
name|Qt
operator|::
name|Dialog
argument_list|,
name|Qt
operator|::
name|ApplicationModal
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|loop
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|show
name|bool
name|QWinRTFileDialogHelper
operator|::
name|show
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|windowFlags
parameter_list|,
name|Qt
operator|::
name|WindowModality
name|windowModality
parameter_list|,
name|QWindow
modifier|*
name|parent
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|windowFlags
argument_list|)
name|Q_UNUSED
argument_list|(
argument|windowModality
argument_list|)
name|Q_UNUSED
argument_list|(
argument|parent
argument_list|)
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
specifier|const
name|QSharedPointer
argument_list|<
name|QFileDialogOptions
argument_list|>
name|dialogOptions
init|=
name|options
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|dialogOptions
operator|->
name|acceptMode
argument_list|()
condition|)
block|{
default|default:
case|case
name|QFileDialogOptions
operator|::
name|AcceptOpen
case|:
block|{
switch|switch
condition|(
name|dialogOptions
operator|->
name|fileMode
argument_list|()
condition|)
block|{
case|case
name|QFileDialogOptions
operator|::
name|AnyFile
case|:
case|case
name|QFileDialogOptions
operator|::
name|ExistingFile
case|:
case|case
name|QFileDialogOptions
operator|::
name|ExistingFiles
case|:
block|{
name|ComPtr
argument_list|<
name|IFileOpenPicker
argument_list|>
name|picker
decl_stmt|;
if|if
condition|(
operator|!
name|initializePicker
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Storage_Pickers_FileOpenPicker
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|picker
operator|.
name|GetAddressOf
argument_list|()
argument_list|,
name|dialogOptions
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|initializeOpenPickerOptions
argument_list|(
name|picker
operator|.
name|Get
argument_list|()
argument_list|,
name|dialogOptions
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|dialogOptions
operator|->
name|fileMode
argument_list|()
operator|==
name|QFileDialogOptions
operator|::
name|ExistingFiles
condition|)
block|{
name|ComPtr
argument_list|<
name|IAsyncOperation
argument_list|<
name|IVectorView
argument_list|<
name|StorageFile
modifier|*
argument_list|>
modifier|*
argument_list|>
argument_list|>
name|op
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|PickMultipleFilesAsync
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to open multi file picker"
argument_list|)
expr_stmt|;
name|hr
operator|=
name|op
operator|->
name|put_Completed
argument_list|(
name|Callback
argument_list|<
name|MultipleFileHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTFileDialogHelper
operator|::
name|onMultipleFilesPicked
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ComPtr
argument_list|<
name|IAsyncOperation
argument_list|<
name|StorageFile
modifier|*
argument_list|>
argument_list|>
name|op
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|PickSingleFileAsync
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to open single file picker"
argument_list|)
expr_stmt|;
name|hr
operator|=
name|op
operator|->
name|put_Completed
argument_list|(
name|Callback
argument_list|<
name|SingleFileHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTFileDialogHelper
operator|::
name|onSingleFilePicked
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to attach file picker callback"
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QFileDialogOptions
operator|::
name|Directory
case|:
case|case
name|QFileDialogOptions
operator|::
name|DirectoryOnly
case|:
block|{
name|ComPtr
argument_list|<
name|IFolderPicker
argument_list|>
name|picker
decl_stmt|;
if|if
condition|(
operator|!
name|initializePicker
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Storage_Pickers_FolderPicker
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|picker
operator|.
name|GetAddressOf
argument_list|()
argument_list|,
name|dialogOptions
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|initializeOpenPickerOptions
argument_list|(
name|picker
operator|.
name|Get
argument_list|()
argument_list|,
name|dialogOptions
argument_list|)
condition|)
return|return
literal|false
return|;
name|ComPtr
argument_list|<
name|IAsyncOperation
argument_list|<
name|StorageFolder
modifier|*
argument_list|>
argument_list|>
name|op
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|PickSingleFolderAsync
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to open folder picker"
argument_list|)
expr_stmt|;
name|hr
operator|=
name|op
operator|->
name|put_Completed
argument_list|(
name|Callback
argument_list|<
name|SingleFolderHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTFileDialogHelper
operator|::
name|onSingleFolderPicked
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to attach folder picker callback"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
break|break;
block|}
case|case
name|QFileDialogOptions
operator|::
name|AcceptSave
case|:
block|{
name|ComPtr
argument_list|<
name|IFileSavePicker
argument_list|>
name|picker
decl_stmt|;
if|if
condition|(
operator|!
name|initializePicker
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Storage_Pickers_FileSavePicker
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|picker
operator|.
name|GetAddressOf
argument_list|()
argument_list|,
name|dialogOptions
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|dialogOptions
operator|->
name|nameFilters
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|ComPtr
argument_list|<
name|IMap
argument_list|<
name|HSTRING
argument_list|,
name|IVector
argument_list|<
name|HSTRING
argument_list|>
modifier|*
argument_list|>
argument_list|>
name|choices
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|get_FileTypeChoices
argument_list|(
operator|&
name|choices
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to get file extension choices"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|namedFilter
decl|,
name|dialogOptions
operator|->
name|nameFilters
argument_list|()
control|)
block|{
name|ComPtr
argument_list|<
name|IVector
argument_list|<
name|HSTRING
argument_list|>
argument_list|>
name|entry
init|=
name|Make
argument_list|<
name|WindowsStringVector
argument_list|>
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|filter
decl|,
name|QPlatformFileDialogHelper
operator|::
name|cleanFilterList
argument_list|(
name|namedFilter
argument_list|)
control|)
block|{
comment|// Remove leading star
specifier|const
name|int
name|offset
init|=
operator|(
name|filter
operator|.
name|length
argument_list|()
operator|>
literal|1
operator|&&
name|filter
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'*'
argument_list|)
argument_list|)
operator|)
condition|?
literal|1
else|:
literal|0
decl_stmt|;
name|HStringReference
name|filterRef
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|filter
operator|.
name|utf16
argument_list|()
operator|+
name|offset
argument_list|)
argument_list|,
name|filter
operator|.
name|length
argument_list|()
operator|-
name|offset
argument_list|)
decl_stmt|;
name|hr
operator|=
name|entry
operator|->
name|Append
argument_list|(
name|filterRef
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to add named file filter \"%s\": %s"
argument_list|,
name|qPrintable
argument_list|(
name|filter
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
specifier|const
name|int
name|offset
init|=
name|namedFilter
operator|.
name|indexOf
argument_list|(
name|QLatin1String
argument_list|(
literal|" ("
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|filterTitle
init|=
name|namedFilter
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
name|offset
argument_list|)
decl_stmt|;
name|HStringReference
name|namedFilterRef
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|filterTitle
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|filterTitle
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|boolean
name|replaced
decl_stmt|;
name|hr
operator|=
name|choices
operator|->
name|Insert
argument_list|(
name|namedFilterRef
operator|.
name|Get
argument_list|()
argument_list|,
name|entry
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|replaced
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to insert file extension choice entry"
argument_list|)
expr_stmt|;
block|}
block|}
specifier|const
name|QString
name|suffix
init|=
name|dialogOptions
operator|->
name|defaultSuffix
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|suffix
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|HStringReference
name|nativeSuffix
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|suffix
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|suffix
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|put_DefaultFileExtension
argument_list|(
name|nativeSuffix
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to set default file extension"
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QString
name|suggestedName
init|=
name|QFileInfo
argument_list|(
name|d
operator|->
name|saveFileName
operator|.
name|toLocalFile
argument_list|()
argument_list|)
operator|.
name|fileName
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|suggestedName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|HStringReference
name|nativeSuggestedName
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|suggestedName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|suggestedName
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|put_SuggestedFileName
argument_list|(
name|nativeSuggestedName
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to set suggested file name"
argument_list|)
expr_stmt|;
block|}
name|ComPtr
argument_list|<
name|IAsyncOperation
argument_list|<
name|StorageFile
modifier|*
argument_list|>
argument_list|>
name|op
decl_stmt|;
name|hr
operator|=
name|picker
operator|->
name|PickSaveFileAsync
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to open save file picker"
argument_list|)
expr_stmt|;
name|hr
operator|=
name|op
operator|->
name|put_Completed
argument_list|(
name|Callback
argument_list|<
name|SingleFileHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTFileDialogHelper
operator|::
name|onSingleFilePicked
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_FALSE_IF_FAILED
argument_list|(
literal|"Failed to attach file picker callback"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|d
operator|->
name|shown
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hide
name|void
name|QWinRTFileDialogHelper
operator|::
name|hide
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|shown
condition|)
return|return;
name|d
operator|->
name|shown
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDirectory
name|void
name|QWinRTFileDialogHelper
operator|::
name|setDirectory
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|directory
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|d
operator|->
name|directory
operator|=
name|directory
expr_stmt|;
block|}
end_function
begin_function
DECL|function|directory
name|QUrl
name|QWinRTFileDialogHelper
operator|::
name|directory
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|directory
return|;
block|}
end_function
begin_function
DECL|function|selectFile
name|void
name|QWinRTFileDialogHelper
operator|::
name|selectFile
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|saveFileName
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|d
operator|->
name|saveFileName
operator|=
name|saveFileName
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectedFiles
name|QList
argument_list|<
name|QUrl
argument_list|>
name|QWinRTFileDialogHelper
operator|::
name|selectedFiles
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|selectedFiles
return|;
block|}
end_function
begin_function
DECL|function|selectNameFilter
name|void
name|QWinRTFileDialogHelper
operator|::
name|selectNameFilter
parameter_list|(
specifier|const
name|QString
modifier|&
name|selectedNameFilter
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|d
operator|->
name|selectedNameFilter
operator|=
name|selectedNameFilter
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectedNameFilter
name|QString
name|QWinRTFileDialogHelper
operator|::
name|selectedNameFilter
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|selectedNameFilter
return|;
block|}
end_function
begin_function
DECL|function|onSingleFilePicked
name|HRESULT
name|QWinRTFileDialogHelper
operator|::
name|onSingleFilePicked
parameter_list|(
name|IAsyncOperation
argument_list|<
name|StorageFile
modifier|*
argument_list|>
modifier|*
name|args
parameter_list|,
name|AsyncStatus
name|status
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|QEventLoopLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|loop
argument_list|)
decl_stmt|;
name|d
operator|->
name|shown
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|selectedFiles
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|Canceled
operator|||
name|status
operator|==
name|Error
condition|)
block|{
emit|emit
name|reject
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IStorageFile
argument_list|>
name|file
decl_stmt|;
name|hr
operator|=
name|args
operator|->
name|GetResults
argument_list|(
operator|&
name|file
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|file
condition|)
block|{
emit|emit
name|reject
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
name|appendFile
argument_list|(
name|file
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|accept
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|onMultipleFilesPicked
name|HRESULT
name|QWinRTFileDialogHelper
operator|::
name|onMultipleFilesPicked
parameter_list|(
name|IAsyncOperation
argument_list|<
name|IVectorView
argument_list|<
name|StorageFile
modifier|*
argument_list|>
modifier|*
argument_list|>
modifier|*
name|args
parameter_list|,
name|AsyncStatus
name|status
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|QEventLoopLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|loop
argument_list|)
decl_stmt|;
name|d
operator|->
name|shown
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|selectedFiles
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|Canceled
operator|||
name|status
operator|==
name|Error
condition|)
block|{
emit|emit
name|reject
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IVectorView
argument_list|<
name|StorageFile
modifier|*
argument_list|>
argument_list|>
name|fileList
decl_stmt|;
name|hr
operator|=
name|args
operator|->
name|GetResults
argument_list|(
operator|&
name|fileList
argument_list|)
expr_stmt|;
name|RETURN_HR_IF_FAILED
argument_list|(
literal|"Failed to get file list"
argument_list|)
expr_stmt|;
name|quint32
name|size
decl_stmt|;
name|hr
operator|=
name|fileList
operator|->
name|get_Size
argument_list|(
operator|&
name|size
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|size
condition|)
block|{
emit|emit
name|reject
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
name|ComPtr
argument_list|<
name|IStorageFile
argument_list|>
name|file
decl_stmt|;
name|hr
operator|=
name|fileList
operator|->
name|GetAt
argument_list|(
name|i
argument_list|,
operator|&
name|file
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|appendFile
argument_list|(
name|file
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
block|}
emit|emit
name|accept
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|onSingleFolderPicked
name|HRESULT
name|QWinRTFileDialogHelper
operator|::
name|onSingleFolderPicked
parameter_list|(
name|IAsyncOperation
argument_list|<
name|StorageFolder
modifier|*
argument_list|>
modifier|*
name|args
parameter_list|,
name|AsyncStatus
name|status
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|QEventLoopLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|loop
argument_list|)
decl_stmt|;
name|d
operator|->
name|shown
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|selectedFiles
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|Canceled
operator|||
name|status
operator|==
name|Error
condition|)
block|{
emit|emit
name|reject
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IStorageFolder
argument_list|>
name|folder
decl_stmt|;
name|hr
operator|=
name|args
operator|->
name|GetResults
argument_list|(
operator|&
name|folder
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|folder
condition|)
block|{
emit|emit
name|reject
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
name|appendFile
argument_list|(
name|folder
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|accept
argument_list|()
emit|;
return|return
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|appendFile
name|void
name|QWinRTFileDialogHelper
operator|::
name|appendFile
parameter_list|(
name|IInspectable
modifier|*
name|file
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTFileDialogHelper
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IStorageItem
argument_list|>
name|item
decl_stmt|;
name|hr
operator|=
name|file
operator|->
name|QueryInterface
argument_list|(
name|IID_PPV_ARGS
argument_list|(
operator|&
name|item
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|HString
name|path
decl_stmt|;
name|hr
operator|=
name|item
operator|->
name|get_Path
argument_list|(
name|path
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|quint32
name|pathLen
decl_stmt|;
specifier|const
name|wchar_t
modifier|*
name|pathStr
init|=
name|path
operator|.
name|GetRawBuffer
argument_list|(
operator|&
name|pathLen
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|filePath
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|pathStr
argument_list|,
name|pathLen
argument_list|)
decl_stmt|;
name|QWinRTFileEngineHandler
operator|::
name|registerFile
argument_list|(
name|filePath
argument_list|,
name|item
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|selectedFiles
operator|.
name|append
argument_list|(
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|filePath
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
