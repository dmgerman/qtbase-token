begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstandardpaths.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<private/qsystemlibrary_p.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
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
file|<windows.storage.h>
end_include
begin_include
include|#
directive|include
file|<Windows.ApplicationModel.h>
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
name|ApplicationModel
namespace|;
end_using
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STANDARDPATHS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|convertCharArray
specifier|static
name|QString
name|convertCharArray
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|path
parameter_list|)
block|{
return|return
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|path
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|writableLocation
name|QString
name|QStandardPaths
operator|::
name|writableLocation
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|ConfigLocation
case|:
comment|// same as AppLocalDataLocation, on Windows
case|case
name|GenericConfigLocation
case|:
comment|// same as GenericDataLocation, on Windows
case|case
name|AppDataLocation
case|:
case|case
name|AppLocalDataLocation
case|:
case|case
name|GenericDataLocation
case|:
block|{
name|ComPtr
argument_list|<
name|IApplicationDataStatics
argument_list|>
name|applicationDataStatics
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Storage_ApplicationData
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|applicationDataStatics
argument_list|)
argument_list|)
condition|)
break|break;
name|ComPtr
argument_list|<
name|IApplicationData
argument_list|>
name|applicationData
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|applicationDataStatics
operator|->
name|get_Current
argument_list|(
operator|&
name|applicationData
argument_list|)
argument_list|)
condition|)
break|break;
name|ComPtr
argument_list|<
name|IStorageFolder
argument_list|>
name|settingsFolder
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|applicationData
operator|->
name|get_LocalFolder
argument_list|(
operator|&
name|settingsFolder
argument_list|)
argument_list|)
condition|)
break|break;
name|ComPtr
argument_list|<
name|IStorageItem
argument_list|>
name|settingsFolderItem
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|settingsFolder
operator|.
name|As
argument_list|(
operator|&
name|settingsFolderItem
argument_list|)
argument_list|)
condition|)
break|break;
name|HString
name|path
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|settingsFolderItem
operator|->
name|get_Path
argument_list|(
name|path
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
argument_list|)
condition|)
break|break;
name|result
operator|=
name|convertCharArray
argument_list|(
name|path
operator|.
name|GetRawBuffer
argument_list|(
literal|nullptr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|isTestModeEnabled
argument_list|()
condition|)
name|result
operator|+=
name|QLatin1String
argument_list|(
literal|"/qttest"
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|CacheLocation
case|:
return|return
name|writableLocation
argument_list|(
name|AppLocalDataLocation
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"/cache"
argument_list|)
return|;
case|case
name|GenericCacheLocation
case|:
return|return
name|writableLocation
argument_list|(
name|GenericDataLocation
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"/cache"
argument_list|)
return|;
case|case
name|TempLocation
case|:
name|result
operator|=
name|QDir
operator|::
name|tempPath
argument_list|()
expr_stmt|;
break|break;
case|case
name|ApplicationsLocation
case|:
case|case
name|DesktopLocation
case|:
case|case
name|FontsLocation
case|:
case|case
name|HomeLocation
case|:
case|case
name|RuntimeLocation
case|:
comment|// these are read-only
break|break;
case|case
name|DocumentsLocation
case|:
case|case
name|MusicLocation
case|:
case|case
name|MoviesLocation
case|:
case|case
name|PicturesLocation
case|:
case|case
name|DownloadLocation
case|:
default|default:
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|standardLocations
name|QStringList
name|QStandardPaths
operator|::
name|standardLocations
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
return|return
name|QStringList
argument_list|(
name|writableLocation
argument_list|(
name|type
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STANDARDPATHS
end_comment
end_unit
