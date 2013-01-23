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
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
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
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STANDARDPATHS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QStandardPaths     \inmodule QtCore     \brief The QStandardPaths class provides methods for accessing standard paths.     \since 5.0      This class contains functions to query standard locations on the local     filesystem, for common tasks such as user-specific directories or system-wide     configuration directories. */
comment|/*!     \enum QStandardPaths::StandardLocation      This enum describes the different locations that can be queried using     methods such as QStandardPaths::writableLocation, QStandardPaths::standardLocations,     and QStandardPaths::displayName.      \value DesktopLocation Returns the user's desktop directory.     \value DocumentsLocation Returns the user's document.     \value FontsLocation Returns the user's fonts.     \value ApplicationsLocation Returns the user's applications.     \value MusicLocation Returns the user's music.     \value MoviesLocation Returns the user's movies.     \value PicturesLocation Returns the user's pictures.     \value TempLocation Returns the system's temporary directory.     \value HomeLocation Returns the user's home directory.     \value DataLocation Returns a directory location where persistent            application data can be stored. QCoreApplication::organizationName            and QCoreApplication::applicationName are appended to the directory location            returned for GenericDataLocation.     \value CacheLocation Returns a directory location where user-specific            non-essential (cached) data should be written.     \value GenericCacheLocation Returns a directory location where user-specific            non-essential (cached) data, shared across applications, should be written.     \value GenericDataLocation Returns a directory location where persistent            data shared across applications can be stored.     \value RuntimeLocation Returns a directory location where runtime communication            files should be written. For instance unix local sockets.     \value ConfigLocation Returns a directory location where user-specific            configuration files should be written.     \value DownloadLocation Returns a directory for user's downloaded files.       \sa writableLocation(), standardLocations(), displayName(), locate(), locateAll() */
comment|/*!     \fn QString QStandardPaths::writableLocation(StandardLocation type)      Returns the directory where files of \a type should be written to, or an empty string     if the location cannot be determined.      \note The storage location returned can be a directory that does not exist; i.e., it     may need to be created by the system or the user. */
comment|/*!    \fn QStringList QStandardPaths::standardLocations(StandardLocation type)     Returns all the directories where files of \a type belong.     The list of directories is sorted from high to low priority, starting with    writableLocation() if it can be determined. This list is empty if no locations    for \a type are defined.     \sa writableLocation()  */
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
comment|// If %PATHEXT% does not contain .exe, it is either empty, malformed, or distorted in ways that we cannot support, anyway.
specifier|const
name|QStringList
name|pathExt
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
name|toLower
argument_list|()
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|pathExt
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
condition|?
name|pathExt
else|:
name|QStringList
argument_list|()
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
begin_function
DECL|function|searchExecutable
specifier|static
specifier|inline
name|QString
name|searchExecutable
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|searchPaths
parameter_list|,
specifier|const
name|QString
modifier|&
name|executableName
parameter_list|)
block|{
specifier|const
name|QDir
name|currentDir
init|=
name|QDir
operator|::
name|current
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|searchPath
decl|,
name|searchPaths
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
name|searchPath
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|executableName
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|absPath
init|=
name|checkExecutable
argument_list|(
name|candidate
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|absPath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|absPath
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_comment
comment|// Find executable appending candidate suffixes, used for suffix-less executables
end_comment
begin_comment
comment|// on Windows.
end_comment
begin_function
specifier|static
specifier|inline
name|QString
DECL|function|searchExecutableAppendSuffix
name|searchExecutableAppendSuffix
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|searchPaths
parameter_list|,
specifier|const
name|QString
modifier|&
name|executableName
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|suffixes
parameter_list|)
block|{
specifier|const
name|QDir
name|currentDir
init|=
name|QDir
operator|::
name|current
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|searchPath
decl|,
name|searchPaths
control|)
block|{
specifier|const
name|QString
name|candidateRoot
init|=
name|currentDir
operator|.
name|absoluteFilePath
argument_list|(
name|searchPath
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|executableName
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|suffix
decl|,
name|suffixes
control|)
block|{
specifier|const
name|QString
name|absPath
init|=
name|checkExecutable
argument_list|(
name|candidateRoot
operator|+
name|suffix
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|absPath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|absPath
return|;
block|}
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
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
comment|// Remove trailing slashes, which occur on Windows.
specifier|const
name|QStringList
name|rawPaths
init|=
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
decl_stmt|;
name|searchPaths
operator|.
name|reserve
argument_list|(
name|rawPaths
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|rawPath
decl|,
name|rawPaths
control|)
block|{
name|QString
name|cleanPath
init|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|rawPath
argument_list|)
decl_stmt|;
if|if
condition|(
name|cleanPath
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|&&
name|cleanPath
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|cleanPath
operator|.
name|truncate
argument_list|(
name|cleanPath
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|searchPaths
operator|.
name|push_back
argument_list|(
name|cleanPath
argument_list|)
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// On Windows, if the name does not have a suffix or a suffix not
comment|// in PATHEXT ("xx.foo"), append suffixes from PATHEXT.
specifier|static
specifier|const
name|QStringList
name|executable_extensions
init|=
name|executableExtensions
argument_list|()
decl_stmt|;
if|if
condition|(
name|executableName
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|suffix
init|=
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
name|suffix
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|executable_extensions
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|+
name|suffix
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
name|searchExecutableAppendSuffix
argument_list|(
name|searchPaths
argument_list|,
name|executableName
argument_list|,
name|executable_extensions
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|searchExecutableAppendSuffix
argument_list|(
name|searchPaths
argument_list|,
name|executableName
argument_list|,
name|executable_extensions
argument_list|)
return|;
block|}
endif|#
directive|endif
return|return
name|searchExecutable
argument_list|(
name|searchPaths
argument_list|,
name|executableName
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QStandardPaths::displayName(StandardLocation type)      Returns a localized display name for the given location \a type or     an empty QString if no relevant location can be found. */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_function
DECL|function|displayName
name|QString
name|QStandardPaths
operator|::
name|displayName
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|DesktopLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Desktop"
argument_list|)
return|;
case|case
name|DocumentsLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Documents"
argument_list|)
return|;
case|case
name|FontsLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Fonts"
argument_list|)
return|;
case|case
name|ApplicationsLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Applications"
argument_list|)
return|;
case|case
name|MusicLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Music"
argument_list|)
return|;
case|case
name|MoviesLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Movies"
argument_list|)
return|;
case|case
name|PicturesLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Pictures"
argument_list|)
return|;
case|case
name|TempLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Temporary Directory"
argument_list|)
return|;
case|case
name|HomeLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Home"
argument_list|)
return|;
case|case
name|DataLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Application Data"
argument_list|)
return|;
case|case
name|CacheLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Cache"
argument_list|)
return|;
case|case
name|GenericDataLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Shared Data"
argument_list|)
return|;
case|case
name|RuntimeLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Runtime"
argument_list|)
return|;
case|case
name|ConfigLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Configuration"
argument_list|)
return|;
case|case
name|GenericCacheLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Shared Cache"
argument_list|)
return|;
case|case
name|DownloadLocation
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Download"
argument_list|)
return|;
block|}
comment|// not reached
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!   \fn void QStandardPaths::enableTestMode(bool testMode)    If \a testMode is true, this enables a special "test mode" in   QStandardPaths, which changes writable locations   to point to test directories, in order to prevent auto tests from reading from   or writing to the current user's configuration.    This affects the locations into which test programs might write files:   GenericDataLocation, DataLocation, ConfigLocation,   GenericCacheLocation, CacheLocation.   Other locations are not affected.    On Unix, XDG_DATA_HOME is set to ~/.qttest/share, XDG_CONFIG_HOME is   set to ~/.qttest/config, and XDG_CACHE_HOME is set to ~/.qttest/cache.    On Mac, data goes to "~/.qttest/Application Support", cache goes to   ~/.qttest/Cache, and config goes to ~/.qttest/Preferences.    On Windows, everything goes to a "qttest" directory under Application Data. */
end_comment
begin_decl_stmt
DECL|variable|qsp_testMode
specifier|static
name|bool
name|qsp_testMode
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|enableTestMode
name|void
name|QStandardPaths
operator|::
name|enableTestMode
parameter_list|(
name|bool
name|testMode
parameter_list|)
block|{
name|qsp_testMode
operator|=
name|testMode
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \fn void QStandardPaths::isTestModeEnabled()    \internal    Returns true if test mode is enabled in QStandardPaths; otherwise returns false. */
end_comment
begin_function
DECL|function|isTestModeEnabled
name|bool
name|QStandardPaths
operator|::
name|isTestModeEnabled
parameter_list|()
block|{
return|return
name|qsp_testMode
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
