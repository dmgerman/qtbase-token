begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
name|class
name|Q_CORE_EXPORT
name|QLibraryInfo
decl_stmt|{ public:     static QString licensee(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_function_decl
specifier|static
name|QString
name|licensedProducts
parameter_list|()
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
end_ifndef
begin_function_decl
specifier|static
name|QDate
name|buildDate
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_DATESTRING
end_comment
begin_function_decl
specifier|static
name|bool
name|isDebugBuild
parameter_list|()
function_decl|;
end_function_decl
begin_enum
enum|enum
name|LibraryLocation
block|{
name|PrefixPath
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
name|DataPath
block|,
name|TranslationsPath
block|,
name|SettingsPath
block|,
name|ExamplesPath
block|,
name|ImportsPath
block|,
name|TestsPath
block|}
enum|;
end_enum
begin_function_decl
specifier|static
name|QString
name|location
parameter_list|(
name|LibraryLocation
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### Qt 5: consider renaming it to path()
end_comment
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QLibraryInfo
argument_list|()
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|/* QT_NO_SETTINGS */
end_comment
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
