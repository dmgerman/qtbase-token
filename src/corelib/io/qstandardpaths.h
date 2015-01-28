begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTANDARDPATHS_H
end_ifndef
begin_define
DECL|macro|QSTANDARDPATHS_H
define|#
directive|define
name|QSTANDARDPATHS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STANDARDPATHS
name|class
name|Q_CORE_EXPORT
name|QStandardPaths
block|{
name|public
label|:
comment|// Do not re-order, must match QDesktopServices
enum|enum
name|StandardLocation
block|{
name|DesktopLocation
block|,
name|DocumentsLocation
block|,
name|FontsLocation
block|,
name|ApplicationsLocation
block|,
name|MusicLocation
block|,
name|MoviesLocation
block|,
name|PicturesLocation
block|,
name|TempLocation
block|,
name|HomeLocation
block|,
name|DataLocation
block|,
name|CacheLocation
block|,
name|GenericDataLocation
block|,
name|RuntimeLocation
block|,
name|ConfigLocation
block|,
name|DownloadLocation
block|,
name|GenericCacheLocation
block|,
name|GenericConfigLocation
block|,
name|AppDataLocation
block|,
name|AppConfigLocation
block|,
name|AppLocalDataLocation
init|=
name|DataLocation
block|}
enum|;
specifier|static
name|QString
name|writableLocation
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|standardLocations
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
function_decl|;
enum|enum
name|LocateOption
block|{
name|LocateFile
init|=
literal|0x0
block|,
name|LocateDirectory
init|=
literal|0x1
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|LocateOptions
argument_list|,
argument|LocateOption
argument_list|)
specifier|static
name|QString
name|locate
parameter_list|(
name|StandardLocation
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|LocateOptions
name|options
init|=
name|LocateFile
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|locateAll
parameter_list|(
name|StandardLocation
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|LocateOptions
name|options
init|=
name|LocateFile
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
specifier|static
name|QString
name|displayName
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|static
name|QString
name|findExecutable
parameter_list|(
specifier|const
name|QString
modifier|&
name|executableName
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|paths
init|=
name|QStringList
argument_list|()
parameter_list|)
function_decl|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|2
argument_list|)
specifier|static
name|QT_DEPRECATED
name|void
name|enableTestMode
parameter_list|(
name|bool
name|testMode
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|static
name|void
name|setTestModeEnabled
parameter_list|(
name|bool
name|testMode
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isTestModeEnabled
parameter_list|()
function_decl|;
name|private
label|:
comment|// prevent construction
name|QStandardPaths
argument_list|()
expr_stmt|;
operator|~
name|QStandardPaths
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STANDARDPATHS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTANDARDPATHS_H
end_comment
end_unit
