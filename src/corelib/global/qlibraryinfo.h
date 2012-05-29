begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLIBRARYINFO_H
end_ifndef
begin_define
DECL|macro|QLIBRARYINFO_H
define|#
directive|define
name|QLIBRARYINFO_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDate>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QLibraryInfo
block|{
name|public
label|:
specifier|static
name|QString
name|licensee
parameter_list|()
function_decl|;
specifier|static
name|QString
name|licensedProducts
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
specifier|static
name|QDate
name|buildDate
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|//QT_NO_DATESTRING
specifier|static
name|bool
name|isDebugBuild
parameter_list|()
function_decl|;
enum|enum
name|LibraryLocation
block|{
name|PrefixPath
init|=
literal|0
block|,
name|DocumentationPath
block|,
name|HeadersPath
block|,
name|LibrariesPath
block|,
name|BinariesPath
block|,
name|PluginsPath
block|,
name|ImportsPath
block|,
name|DataPath
block|,
name|TranslationsPath
block|,
name|ExamplesPath
block|,
name|TestsPath
block|,
comment|// Insert new values above this line
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
comment|// These are not subject to binary compatibility constraints
name|SysrootPath
block|,
name|HostPrefixPath
block|,
name|HostBinariesPath
block|,
name|HostDataPath
block|,
name|LastHostPath
init|=
name|HostDataPath
block|,
endif|#
directive|endif
name|SettingsPath
init|=
literal|100
block|}
enum|;
specifier|static
name|QString
name|location
parameter_list|(
name|LibraryLocation
parameter_list|)
function_decl|;
comment|// ### Qt 6: consider renaming it to path()
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
enum|enum
name|PathGroup
block|{
name|FinalPaths
block|,
name|EffectivePaths
block|}
enum|;
specifier|static
name|QString
name|rawLocation
parameter_list|(
name|LibraryLocation
parameter_list|,
name|PathGroup
parameter_list|)
function_decl|;
endif|#
directive|endif
name|private
label|:
name|QLibraryInfo
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLIBRARYINFO_H
end_comment
end_unit
