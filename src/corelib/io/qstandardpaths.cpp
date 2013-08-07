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
comment|/*!     \enum QStandardPaths::StandardLocation      This enum describes the different locations that can be queried using     methods such as QStandardPaths::writableLocation, QStandardPaths::standardLocations,     and QStandardPaths::displayName.      Some of the values in this enum represent a user configuration. Such enum     values will return the same paths in different applications, so they could     be used to share data with other applications. Other values are specific to     this application. Each enum value in the table below describes whether it's     application-specific or generic.      Application-specific directories should be assumed to be unreachable by     other applications. Therefore, files placed there might not be readable by     other applications, even if run by the same user. On the other hand, generic     directories should be assumed to be accessible by all applications run by     this user, but should still be assumed to be unreachable by applications by     other users.      The only exception is QStandardPaths::TempLocation (which is the same as     QDir::tempPath()): the path returned may be application-specific, but files     stored there may be accessed by other applications run by the same user.      Data interchange with other users is out of the scope of QStandardPaths.      \value DesktopLocation Returns the user's desktop directory. This is a generic value.            On systems with no concept of a desktop, this is the same as            QStandardPaths::HomeLocation.     \value DocumentsLocation Returns the directory containing user document files.            This is a generic value. The returned path is never empty.     \value FontsLocation Returns the directory containing user's fonts. This is a generic value.            Note that installing fonts may require additional, platform-specific operations.     \value ApplicationsLocation Returns the directory containing the user applications            (either executables, application bundles, or shortcuts to them). This is a generic value.            Note that installing applications may require additional, platform-specific operations.            Files, folders or shortcuts in this directory are platform-specific.     \value MusicLocation Returns the directory containing the user's music or other audio files.            This is a generic value. If no directory specific for music files exists, a sensible            fallback for storing user documents is returned.     \value MoviesLocation Returns the directory containing the user's movies and videos.            This is a generic value. If no directory specific for movie files exists, a sensible            fallback for storing user documents is returned.     \value PicturesLocation Returns the directory containing the user's pictures or photos.            This is a generic value. If no directory specific for picture files exists, a sensible            fallback for storing user documents is returned.     \value TempLocation Returns a directory where temporary files can be stored. The returned value            might be application-specific, shared among other applications for this user, or even            system-wide. The returned path is never empty.     \value HomeLocation Returns the user's home directory (the same as QDir::homePath()). On Unix            systems, this is equal to the HOME environment variable. This value might be            generic or application-specific, but the returned path is never empty.     \value DataLocation Returns a directory location where persistent            application data can be stored. This is an application-specific directory. To obtain a            path to store data to be shared with other applications, use            QStandardPaths::GenericDataLocation. The returned path is never empty.     \value CacheLocation Returns a directory location where user-specific            non-essential (cached) data should be written. This is an application-specific directory.            The returned path is never empty.     \value GenericCacheLocation Returns a directory location where user-specific non-essential            (cached) data, shared across applications, should be written. This is a generic value.            Note that the returned path may be empty if the system has no concept of shared cache.     \value GenericDataLocation Returns a directory location where persistent            data shared across applications can be stored. This is a generic value. The returned            path is never empty.     \value RuntimeLocation Returns a directory location where runtime communication            files should be written, like Unix local sockets. This is a generic value.            The returned path may be empty on some systems.     \value ConfigLocation Returns a directory location where user-specific            configuration files should be written. This may be either a generic value            or application-specific, and the returned path is never empty.     \value DownloadLocation Returns a directory for user's downloaded files. This is a generic value.            If no directory specific for downloads exists, a sensible fallback for storing user            documents is returned.      The following table gives examples of paths on different operating systems.     The first path is the writable path (unless noted). Other, additional     paths, if any, represent non-writable locations.      \table     \header \li Path type \li OS X  \li Windows     \row \li DesktopLocation          \li "~/Desktop"          \li "C:/Users/<USER>/Desktop"     \row \li DocumentsLocation          \li "~/Documents"          \li "C:/Users/<USER>/Documents"     \row \li FontsLocation          \li "/System/Library/Fonts" (not writable)          \li "C:/Windows/Fonts" (not writable)     \row \li ApplicationsLocation          \li "/Applications" (not writable)          \li "C:/Users/<USER>/AppData/Roaming/Microsoft/Windows/Start Menu/Programs"     \row \li MusicLocation          \li "~/Music"          \li "C:/Users/<USER>/Music"     \row \li MoviesLocation          \li "~/Movies"          \li "C:/Users/<USER>/Videos"     \row \li PicturesLocation          \li "~/Pictures"          \li "C:/Users/<USER>/Pictures"     \row \li TempLocation          \li randomly generated by the OS          \li "C:/Users/<USER>/AppData/Local/Temp"     \row \li HomeLocation          \li "~"          \li "C:/Users/<USER>"     \row \li DataLocation          \li "~/Library/Application Support/<APPNAME>", "/Library/Application Support/<APPNAME>"          \li "C:/Users/<USER>/AppData/Local/<APPNAME>", "C:/ProgramData/<APPNAME>"     \row \li CacheLocation          \li "~/Library/Caches/<APPNAME>", "/Library/Caches/<APPNAME>"          \li "C:/Users/<USER>/AppData/Local/<APPNAME>/cache"     \row \li GenericDataLocation          \li "~/Library/Application Support", "/Library/Application Support"          \li "C:/Users/<USER>/AppData/Local", "C:/ProgramData"     \row \li RuntimeLocation          \li "~/Library/Application Support"          \li "C:/Users/<USER>"     \row \li ConfigLocation          \li "~/Library/Preferences"          \li "C:/Users/<USER>/AppData/Local/<APPNAME>", "C:/ProgramData/<APPNAME>"     \row \li DownloadLocation          \li "~/Documents"          \li "C:/Users/<USER>/Documents"     \row \li GenericCacheLocation          \li "~/Library/Caches", "/Library/Caches"          \li "C:/Users/<USER>/AppData/Local/cache"     \endtable      \table     \header \li Path type \li Blackberry \li Linux (including Android)     \row \li DesktopLocation          \li "<APPROOT>/data"          \li "~/Desktop"     \row \li DocumentsLocation          \li "<APPROOT>/shared/documents"          \li "~/Documents"     \row \li FontsLocation          \li "/base/usr/fonts" (not writable)          \li "~/.fonts"     \row \li ApplicationsLocation          \li not supported (directory not readable)          \li "~/.local/share/applications", "/usr/local/share/applications", "/usr/share/applications"     \row \li MusicLocation          \li "<APPROOT>/shared/music"          \li "~/Music"     \row \li MoviesLocation          \li "<APPROOT>/shared/videos"          \li "~/Videos"     \row \li PicturesLocation          \li "<APPROOT>/shared/photos"          \li "~/Pictures"     \row \li TempLocation          \li "/var/tmp"          \li "/tmp"     \row \li HomeLocation          \li "<APPROOT>/data"          \li "~"     \row \li DataLocation          \li "<APPROOT>/data"          \li "~/.local/share/<APPNAME>", "/usr/local/share/<APPNAME>", "/usr/share/<APPNAME>"     \row \li CacheLocation          \li "<APPROOT>/data/Cache"          \li "~/.cache/<APPNAME>"     \row \li GenericDataLocation          \li "<APPROOT>/shared/misc"          \li "~/.local/share", "/usr/local/share", "/usr/share"     \row \li RuntimeLocation          \li "/var/tmp"          \li "/run/user/<USER>"     \row \li ConfigLocation          \li "<APPROOT>/data/Settings"          \li "~/.config", "/etc/xdg"     \row \li DownloadLocation          \li "<APPROOT>/shared/downloads"          \li "~/Downloads"     \row \li GenericCacheLocation          \li "<APPROOT>/data/Cache" (there is no shared cache)          \li "~/.cache"     \endtable      In the table above, \c<APPNAME> is usually the organization name, the     application name, or both, or a unique name generated at packaging.     Similarly,<APPROOT> is the location where this application is installed     (often a sandbox).      The paths above should not be relied upon, as they may change according to     OS configuration, locale, or they may change in future Qt versions.      \sa writableLocation(), standardLocations(), displayName(), locate(), locateAll() */
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
comment|/*!   \fn void QStandardPaths::enableTestMode(bool testMode)   \obsolete Use QStandardPaths::setTestModeEnabled  */
end_comment
begin_comment
comment|/*!   \fn void QStandardPaths::setTestModeEnabled(bool testMode)    If \a testMode is true, this enables a special "test mode" in   QStandardPaths, which changes writable locations   to point to test directories, in order to prevent auto tests from reading from   or writing to the current user's configuration.    This affects the locations into which test programs might write files:   GenericDataLocation, DataLocation, ConfigLocation,   GenericCacheLocation, CacheLocation.   Other locations are not affected.    On Unix, XDG_DATA_HOME is set to ~/.qttest/share, XDG_CONFIG_HOME is   set to ~/.qttest/config, and XDG_CACHE_HOME is set to ~/.qttest/cache.    On Mac, data goes to "~/.qttest/Application Support", cache goes to   ~/.qttest/Cache, and config goes to ~/.qttest/Preferences.    On Windows, everything goes to a "qttest" directory under Application Data. */
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
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|2
argument_list|)
end_if
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
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|setTestModeEnabled
name|void
name|QStandardPaths
operator|::
name|setTestModeEnabled
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
comment|/*!   \fn void QStandardPaths::isTestModeEnabled()    \internal    Returns \c true if test mode is enabled in QStandardPaths; otherwise returns \c false. */
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
