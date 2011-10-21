begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STANDARDPATHS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QStandardPaths     \brief The QStandardPaths class provides methods for accessing standard paths.     \since 5.0      This class contains functions to query standard locations on the local     filesystem, for common tasks such as user-specific directories or system-wide     configuration directories. */
comment|/*!     \enum QStandardPaths::StandardLocation      This enum describes the different locations that can be queried using     methods such as QStandardPaths::storageLocation, QStandardPaths::standardLocations,     and QStandardPaths::displayName.      \value DesktopLocation Returns the user's desktop directory.     \value DocumentsLocation Returns the user's document.     \value FontsLocation Returns the user's fonts.     \value ApplicationsLocation Returns the user's applications.     \value MusicLocation Returns the users music.     \value MoviesLocation Returns the user's movies.     \value PicturesLocation Returns the user's pictures.     \value TempLocation Returns the system's temporary directory.     \value HomeLocation Returns the user's home directory.     \value DataLocation Returns a directory location where persistent            application data can be stored. QCoreApplication::organizationName            and QCoreApplication::applicationName are appended to the directory location            returned for GenericDataLocation.     \value CacheLocation Returns a directory location where user-specific            non-essential (cached) data should be written.     \value GenericDataLocation Returns a directory location where persistent            data shared across applications can be stored.     \value RuntimeLocation Returns a directory location where runtime communication            files should be written. For instance unix local sockets.     \value ConfigLocation Returns a directory location where user-specific            configuration files should be written.       \sa storageLocation() standardLocations() displayName() locate() locateAll() */
comment|/*!     \fn QString QStandardPaths::storageLocation(StandardLocation type)      Returns the directory where files of \a type should be written to, or an empty string     if the location cannot be determined.      \note The storage location returned can be a directory that does not exist; i.e., it     may need to be created by the system or the user.      \note On Symbian OS, ApplicationsLocation always point /sys/bin folder on the same drive     with executable. FontsLocation always points to folder on ROM drive. Symbian OS does not     have desktop concept, DesktopLocation returns same path as DocumentsLocation.     Rest of the standard locations point to folder on same drive with executable, except     that if executable is in ROM the folder from C drive is returned. */
comment|/*!    \fn QStringList QStandardPaths::standardLocations(StandardLocation type)     Returns all the directories where files of \a type belong.     Much like the PATH variable, it returns the directories in order of priority,    starting with the user-specific storageLocation() for the \a type.  */
comment|/*!     \enum QStandardPaths::LocateOption      This enum describes the different flags that can be used for     controlling the behavior of QStandardPaths::locate and     QStandardPaths::locateAll.      \value LocateFile return only files     \value LocateDirectory return only directories */
DECL|function|existsAsSpecified
specifier|static
name|bool
name|existsAsSpecified
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|QStandardPaths
operator|::
name|LocateOptions
name|options
parameter_list|)
block|{
if|if
condition|(
name|options
operator|&
name|QStandardPaths
operator|::
name|LocateDirectory
condition|)
return|return
name|QDir
argument_list|(
name|path
argument_list|)
operator|.
name|exists
argument_list|()
return|;
return|return
name|QFileInfo
argument_list|(
name|path
argument_list|)
operator|.
name|isFile
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!    Tries to find a file or directory called \a fileName in the standard locations    for \a type.     The full path to the first file or directory (depending on \a options) found is returned.    If no such file or directory can be found, an empty string is returned.  */
end_comment
begin_function
DECL|function|locate
name|QString
name|QStandardPaths
operator|::
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
parameter_list|)
block|{
specifier|const
name|QStringList
modifier|&
name|dirs
init|=
name|standardLocations
argument_list|(
name|type
argument_list|)
decl_stmt|;
for|for
control|(
name|QStringList
operator|::
name|const_iterator
name|dir
init|=
name|dirs
operator|.
name|constBegin
argument_list|()
init|;
name|dir
operator|!=
name|dirs
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|dir
control|)
block|{
specifier|const
name|QString
name|path
init|=
operator|*
name|dir
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|fileName
decl_stmt|;
if|if
condition|(
name|existsAsSpecified
argument_list|(
name|path
argument_list|,
name|options
argument_list|)
condition|)
return|return
name|path
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!    Tries to find all files or directories called \a fileName in the standard locations    for \a type.     The \a options flag allows to specify whether to look for files or directories.     Returns the list of all the files that were found.  */
end_comment
begin_function
DECL|function|locateAll
name|QStringList
name|QStandardPaths
operator|::
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
parameter_list|)
block|{
specifier|const
name|QStringList
modifier|&
name|dirs
init|=
name|standardLocations
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|QStringList
name|result
decl_stmt|;
for|for
control|(
name|QStringList
operator|::
name|const_iterator
name|dir
init|=
name|dirs
operator|.
name|constBegin
argument_list|()
init|;
name|dir
operator|!=
name|dirs
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|dir
control|)
block|{
specifier|const
name|QString
name|path
init|=
operator|*
name|dir
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|fileName
decl_stmt|;
if|if
condition|(
name|existsAsSpecified
argument_list|(
name|path
argument_list|,
name|options
argument_list|)
condition|)
name|result
operator|.
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_function
DECL|function|executableExtensions
specifier|static
name|QStringList
name|executableExtensions
parameter_list|()
block|{
name|QStringList
name|ret
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"PATHEXT"
argument_list|)
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ret
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|".exe"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
block|{
comment|// If %PATHEXT% does not contain .exe, it is either empty, malformed, or distorted in ways that we cannot support, anyway.
name|ret
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ret
operator|<<
name|QLatin1String
argument_list|(
literal|".exe"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|".com"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|".bat"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|".cmd"
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|checkExecutable
specifier|static
name|QString
name|checkExecutable
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
specifier|const
name|QFileInfo
name|info
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|info
operator|.
name|isBundle
argument_list|()
condition|)
return|return
name|info
operator|.
name|bundleName
argument_list|()
return|;
if|if
condition|(
name|info
operator|.
name|isFile
argument_list|()
operator|&&
name|info
operator|.
name|isExecutable
argument_list|()
condition|)
return|return
name|QDir
operator|::
name|cleanPath
argument_list|(
name|path
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Finds the executable named \a executableName in the paths specified by \a paths,   or the system paths if \a paths is empty.    On most operating systems the system path is determined by the PATH environment variable.    The directories where to search for the executable can be set in the \a paths argument.   To search in both your own paths and the system paths, call findExecutable twice, once with   \a paths set and once with \a paths empty.    Symlinks are not resolved, in order to preserve behavior for the case of executables   whose behavior depends on the name they are invoked with.    \note On Windows, the usual executable extensions (from the PATHEXT environment variable)   are automatically appended, so that for instance findExecutable("foo") will find foo.exe   or foo.bat if present.    Returns the absolute file path to the executable, or an empty string if not found.  */
end_comment
begin_function
DECL|function|findExecutable
name|QString
name|QStandardPaths
operator|::
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
parameter_list|)
block|{
if|if
condition|(
name|QFileInfo
argument_list|(
name|executableName
argument_list|)
operator|.
name|isAbsolute
argument_list|()
condition|)
return|return
name|checkExecutable
argument_list|(
name|executableName
argument_list|)
return|;
name|QStringList
name|searchPaths
init|=
name|paths
decl_stmt|;
if|if
condition|(
name|paths
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QByteArray
name|pEnv
init|=
name|qgetenv
argument_list|(
literal|"PATH"
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
specifier|const
name|QLatin1Char
name|pathSep
argument_list|(
literal|';'
argument_list|)
decl_stmt|;
else|#
directive|else
specifier|const
name|QLatin1Char
name|pathSep
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|searchPaths
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|pEnv
operator|.
name|constData
argument_list|()
argument_list|)
operator|.
name|split
argument_list|(
name|pathSep
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
expr_stmt|;
block|}
name|QDir
name|currentDir
init|=
name|QDir
operator|::
name|current
argument_list|()
decl_stmt|;
name|QString
name|absPath
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
specifier|static
name|QStringList
name|executable_extensions
init|=
name|executableExtensions
argument_list|()
decl_stmt|;
endif|#
directive|endif
for|for
control|(
name|QStringList
operator|::
name|const_iterator
name|p
init|=
name|searchPaths
operator|.
name|constBegin
argument_list|()
init|;
name|p
operator|!=
name|searchPaths
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|p
control|)
block|{
specifier|const
name|QString
name|candidate
init|=
name|currentDir
operator|.
name|absoluteFilePath
argument_list|(
operator|*
name|p
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|executableName
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
specifier|const
name|QString
name|extension
init|=
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|+
name|QFileInfo
argument_list|(
name|executableName
argument_list|)
operator|.
name|suffix
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|executable_extensions
operator|.
name|contains
argument_list|(
name|extension
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|extension
decl|,
name|executable_extensions
control|)
block|{
name|absPath
operator|=
name|checkExecutable
argument_list|(
name|candidate
operator|+
name|extension
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|absPath
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
block|}
block|}
endif|#
directive|endif
name|absPath
operator|=
name|checkExecutable
argument_list|(
name|candidate
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|absPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
break|break;
block|}
block|}
return|return
name|absPath
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QStandardPaths::displayName(StandardLocation type)      Returns a localized display name for the given location \a type or     an empty QString if no relevant location can be found. */
end_comment
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
