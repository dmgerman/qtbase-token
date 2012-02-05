begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSTEMLIBRARY_P_H
end_ifndef
begin_define
DECL|macro|QSYSTEMLIBRARY_P_H
define|#
directive|define
name|QSYSTEMLIBRARY_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSystemLibrary
block|{
name|public
label|:
name|explicit
name|QSystemLibrary
parameter_list|(
specifier|const
name|QString
modifier|&
name|libraryName
parameter_list|)
block|{
name|m_libraryName
operator|=
name|libraryName
expr_stmt|;
name|m_handle
operator|=
literal|0
expr_stmt|;
name|m_didLoad
operator|=
name|false
expr_stmt|;
block|}
name|explicit
name|QSystemLibrary
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|libraryName
parameter_list|)
block|{
name|m_libraryName
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|libraryName
argument_list|)
expr_stmt|;
name|m_handle
operator|=
literal|0
expr_stmt|;
name|m_didLoad
operator|=
name|false
expr_stmt|;
block|}
name|bool
name|load
parameter_list|(
name|bool
name|onlySystemDirectory
init|=
name|true
parameter_list|)
block|{
name|m_handle
operator|=
name|load
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|m_libraryName
operator|.
name|utf16
argument_list|()
argument_list|,
name|onlySystemDirectory
argument_list|)
expr_stmt|;
name|m_didLoad
operator|=
name|true
expr_stmt|;
return|return
operator|(
name|m_handle
operator|!=
literal|0
operator|)
return|;
block|}
name|bool
name|isLoaded
parameter_list|()
block|{
return|return
operator|(
name|m_handle
operator|!=
literal|0
operator|)
return|;
block|}
name|QFunctionPointer
name|resolve
parameter_list|(
specifier|const
name|char
modifier|*
name|symbol
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_didLoad
condition|)
name|load
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_handle
condition|)
return|return
literal|0
return|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
return|return
name|QFunctionPointer
argument_list|(
name|GetProcAddress
argument_list|(
name|m_handle
argument_list|,
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|QString
operator|::
name|fromLatin1
argument_list|(
name|symbol
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|)
return|;
else|#
directive|else
return|return
name|QFunctionPointer
argument_list|(
name|GetProcAddress
argument_list|(
name|m_handle
argument_list|,
name|symbol
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
block|}
specifier|static
name|QFunctionPointer
name|resolve
parameter_list|(
specifier|const
name|QString
modifier|&
name|libraryName
parameter_list|,
specifier|const
name|char
modifier|*
name|symbol
parameter_list|)
block|{
return|return
name|QSystemLibrary
argument_list|(
name|libraryName
argument_list|)
operator|.
name|resolve
argument_list|(
name|symbol
argument_list|)
return|;
block|}
specifier|static
name|Q_CORE_EXPORT
name|HINSTANCE
name|load
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|lpFileName
parameter_list|,
name|bool
name|onlySystemDirectory
init|=
name|true
parameter_list|)
function_decl|;
name|private
label|:
name|HINSTANCE
name|m_handle
decl_stmt|;
name|QString
name|m_libraryName
decl_stmt|;
name|bool
name|m_didLoad
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
comment|//Q_OS_WIN
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QSYSTEMLIBRARY_P_H
end_comment
end_unit
