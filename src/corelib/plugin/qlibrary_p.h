begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLIBRARY_P_H
end_ifndef
begin_define
DECL|macro|QLIBRARY_P_H
define|#
directive|define
name|QLIBRARY_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_include
include|#
directive|include
file|"QtCore/qt_windows.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"QtCore/qlibrary.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qplugin.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsharedpointer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|bool
name|qt_debug_component
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|QLibraryPrivate
block|{
name|public
label|:
ifdef|#
directive|ifdef
name|Q_WS_WIN
name|HINSTANCE
else|#
directive|else
name|void
modifier|*
endif|#
directive|endif
name|pHnd
decl_stmt|;
name|QString
name|fileName
decl_stmt|,
name|qualifiedFileName
decl_stmt|;
name|QString
name|fullVersion
decl_stmt|;
name|bool
name|load
parameter_list|()
function_decl|;
name|bool
name|loadPlugin
parameter_list|()
function_decl|;
comment|// loads and resolves instance
name|bool
name|unload
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
name|QFunctionPointer
name|resolve
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|QLibraryPrivate
modifier|*
name|findOrCreate
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|version
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|QWeakPointer
operator|<
name|QObject
operator|>
name|inst
expr_stmt|;
name|QtPluginInstanceFunction
name|instance
decl_stmt|;
name|uint
name|qt_version
decl_stmt|;
name|QString
name|lastModified
decl_stmt|;
name|QString
name|errorString
decl_stmt|;
name|QLibrary
operator|::
name|LoadHints
name|loadHints
expr_stmt|;
name|bool
name|isPlugin
parameter_list|()
function_decl|;
name|private
label|:
name|explicit
name|QLibraryPrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|canonicalFileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|version
parameter_list|)
function_decl|;
operator|~
name|QLibraryPrivate
argument_list|()
expr_stmt|;
name|bool
name|load_sys
parameter_list|()
function_decl|;
name|bool
name|unload_sys
parameter_list|()
function_decl|;
name|QFunctionPointer
name|resolve_sys
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|QAtomicInt
name|libraryRefCount
decl_stmt|;
name|QAtomicInt
name|libraryUnloadCount
decl_stmt|;
enum|enum
block|{
name|IsAPlugin
block|,
name|IsNotAPlugin
block|,
name|MightBeAPlugin
block|}
name|pluginState
enum|;
name|friend
name|class
name|QLibraryPrivateHasFriends
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLIBRARY_P_H
end_comment
end_unit
