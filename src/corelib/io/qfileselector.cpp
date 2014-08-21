begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfileselector.h"
end_include
begin_include
include|#
directive|include
file|"qfileselector_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutexLocker>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLocale>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//Environment variable to allow tooling full control of file selectors
DECL|variable|env_override
specifier|static
specifier|const
name|char
name|env_override
index|[]
init|=
literal|"QT_NO_BUILTIN_SELECTORS"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|selectorIndicator
specifier|static
specifier|const
name|ushort
name|selectorIndicator
init|=
literal|'+'
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QFileSelectorSharedData
argument_list|,
name|sharedData
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|sharedDataMutex
specifier|static
name|QBasicMutex
name|sharedDataMutex
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QFileSelectorPrivate
name|QFileSelectorPrivate
operator|::
name|QFileSelectorPrivate
parameter_list|()
member_init_list|:
name|QObjectPrivate
argument_list|()
block|{ }
end_constructor
begin_comment
comment|/*!     \class QFileSelector     \inmodule QtCore     \brief QFileSelector provides a convenient way of selecting file variants.     \since 5.2      QFileSelector is a convenience for selecting file variants based on platform or device     characteristics. This allows you to develop and deploy one codebase containing all the     different variants more easily in some circumstances, such as when the correct variant cannot     be determined during the deploy step.      \section1 Using QFileSelector      If you always use the same file you do not need to use QFileSelector.      Consider the following example usage, where you want to use different settings files on     different locales. You might select code between locales like this:      \code     QString defaultsBasePath = "data/";     QString defaultsPath = defaultsBasePath + "defaults.conf";     QString localizedPath = defaultsBasePath             + QString("%1/defaults.conf").arg(QLocale::system().name());     if (QFile::exists(localizedPath))         defaultsPath = localizedPath;     QFile defaults(defaultsPath);     \endcode      Similarly, if you want to pick a different data file based on target platform,     your code might look something like this:     \code     QString defaultsPath = "data/defaults.conf"; #if defined(Q_OS_ANDROID)     defaultsPath = "data/android/defaults.conf"; #elif defined(Q_OS_BLACKBERRY)     defaultsPath = "data/blackberry/defaults.conf"; #elif defined(Q_OS_IOS)     defaultsPath = "data/ios/defaults.conf"; #endif     QFile defaults(defaultsPath);     \endcode      QFileSelector provides a convenient alternative to writing such boilerplate code, and in the     latter case it allows you to start using an platform-specific configuration without a recompile.     QFileSelector also allows for chaining of multiple selectors in a convenient way, for example     selecting a different file only on certain combinations of platform and locale. For example, to     select based on platform and/or locale, the code is as follows:      \code     QFileSelector selector;     QFile defaultsFile(selector.select("data/defaults.conf"));     \endcode      The files to be selected are placed in directories named with a \c'+' and a selector name. In the above     example you could have the platform configurations selected by placing them in the following locations:     \code     data/defaults.conf     data/+android/defaults.conf     data/+blackberry/defaults.conf     data/+ios/+en_GB/defaults.conf     \endcode      To find selected files, QFileSelector looks in the same directory as the base file. If there are     any directories of the form +<selector> with an active selector, QFileSelector will prefer a file     with the same file name from that directory over the base file. These directories can be nested to     check against multiple selectors, for example:     \code     images/background.png     images/+android/+en_GB/background.png     images/+blackberry/+en_GB/background.png     \endcode     With those files available, you would select a different file on android and blackberry platforms,     but only if the locale was en_GB.      QFileSelector will not attempt to select if the base file does not exist. For error handling in     the case no valid selectors are present, it is recommended to have a default or error-handling     file in the base file location even if you expect selectors to be present for all deployments.      In a future version, some may be marked as deploy-time static and be moved during the     deployment step as an optimization. As selectors come with a performance cost, it is     recommended to avoid their use in circumstances involving performance-critical code.      \section1 Adding selectors      Selectors normally available are     \list     \li platform, any of the following strings which match the platform the application is running         on: android, blackberry, ios, osx, darwin, mac, linux, wince, unix, windows.     \li locale, same as QLocale::system().name().     \endlist      Further selectors will be added from the \c QT_FILE_SELECTORS environment variable, which     when set should be a set of comma separated selectors. Note that this variable will only be     read once; selectors may not update if the variable changes while the application is running.     The initial set of selectors are evaluated only once, on first use.      You can also add extra selectors at runtime for custom behavior. These will be used in any     future calls to select(). If the extra selectors list has been changed, calls to select() will     use the new list and may return differently.      \section1 Conflict resolution when multiple selectors apply      When multiple selectors could be applied to the same file, the first matching selector is chosen.     The order selectors are checked in are:      \list 1     \li Selectors set via setExtraSelectors(), in the order they are in the list     \li Selectors in the \c QT_FILE_SELECTORS environment variable, from left to right     \li Locale     \li Platform     \endlist      Here is an example involving multiple selectors matching at the same time. It uses platform     selectors, plus an extra selector named "admin" is set by the application based on user     credentials. The example is sorted so that the lowest matching file would be chosen if all     selectors were present:      \code     images/background.png     images/+linux/background.png     images/+windows/background.png     images/+admin/background.png     images/+admin/+linux/background.png     \endcode      Because extra selectors are checked before platform the \c{+admin/background.png} will be chosen     on Windows when the admin selector is set, and \c{+windows/background.png} will be chosen on     Windows when the admin selector is not set.  On Linux, the \c{+admin/+linux/background.png} will be     chosen when admin is set, and the \c{+linux/background.png} when it is not.  */
end_comment
begin_comment
comment|/*!     Create a QFileSelector instance. This instance will have the same static selectors as other     QFileSelector instances, but its own set of extra selectors.      If supplied, it will have the given QObject \a parent. */
end_comment
begin_constructor
DECL|function|QFileSelector
name|QFileSelector
operator|::
name|QFileSelector
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|(
operator|new
name|QFileSelectorPrivate
argument_list|()
operator|)
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys this selector instance. */
end_comment
begin_destructor
DECL|function|~QFileSelector
name|QFileSelector
operator|::
name|~
name|QFileSelector
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!    This function returns the selected version of the path, based on the conditions at runtime.    If no selectable files are present, returns the original \a filePath.     If the original file does not exist, the original \a filePath is returned. This means that you    must have a base file to fall back on, you cannot have only files in selectable sub-directories.     See the class overview for the selection algorithm. */
end_comment
begin_function
DECL|function|select
name|QString
name|QFileSelector
operator|::
name|select
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileSelector
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|select
argument_list|(
name|filePath
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qrcScheme
specifier|static
name|QString
name|qrcScheme
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"qrc"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    This is a convenience version of select operating on QUrls. If the scheme is not file or qrc,    \a filePath is returned immediately. Otherwise selection is applied to the path of \a filePath    and a QUrl is returned with the selected path and other QUrl parts the same as \a filePath.     See the class overview for the selection algorithm. */
end_comment
begin_function
DECL|function|select
name|QUrl
name|QFileSelector
operator|::
name|select
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|filePath
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileSelector
argument_list|)
expr_stmt|;
if|if
condition|(
name|filePath
operator|.
name|scheme
argument_list|()
operator|!=
name|qrcScheme
argument_list|()
operator|&&
operator|!
name|filePath
operator|.
name|isLocalFile
argument_list|()
condition|)
return|return
name|filePath
return|;
name|QUrl
name|ret
argument_list|(
name|filePath
argument_list|)
decl_stmt|;
if|if
condition|(
name|filePath
operator|.
name|scheme
argument_list|()
operator|==
name|qrcScheme
argument_list|()
condition|)
block|{
name|QString
name|equivalentPath
init|=
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|+
name|filePath
operator|.
name|path
argument_list|()
decl_stmt|;
name|QString
name|selectedPath
init|=
name|d
operator|->
name|select
argument_list|(
name|equivalentPath
argument_list|)
decl_stmt|;
name|ret
operator|.
name|setPath
argument_list|(
name|selectedPath
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ret
operator|=
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|d
operator|->
name|select
argument_list|(
name|ret
operator|.
name|toLocalFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|selectionHelper
specifier|static
name|QString
name|selectionHelper
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|selectors
parameter_list|)
block|{
comment|/* selectionHelper does a depth-first search of possible selected files. Because there is strict        selector ordering in the API, we can stop checking as soon as we find the file in a directory        which does not contain any other valid selector directories.     */
name|Q_ASSERT
argument_list|(
name|path
operator|.
name|isEmpty
argument_list|()
operator|||
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|s
decl|,
name|selectors
control|)
block|{
name|QString
name|prospectiveBase
init|=
name|path
operator|+
name|QLatin1Char
argument_list|(
name|selectorIndicator
argument_list|)
operator|+
name|s
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
decl_stmt|;
name|QStringList
name|remainingSelectors
init|=
name|selectors
decl_stmt|;
name|remainingSelectors
operator|.
name|removeAll
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QDir
argument_list|(
name|prospectiveBase
argument_list|)
operator|.
name|exists
argument_list|()
condition|)
continue|continue;
name|QString
name|prospectiveFile
init|=
name|selectionHelper
argument_list|(
name|prospectiveBase
argument_list|,
name|fileName
argument_list|,
name|remainingSelectors
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|prospectiveFile
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|prospectiveFile
return|;
block|}
comment|// If we reach here there were no successful files found at a lower level in this branch, so we
comment|// should check this level as a potential result.
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|path
operator|+
name|fileName
argument_list|)
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|path
operator|+
name|fileName
return|;
block|}
end_function
begin_function
DECL|function|select
name|QString
name|QFileSelectorPrivate
operator|::
name|select
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QFileSelector
argument_list|)
expr_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|filePath
argument_list|)
decl_stmt|;
comment|// If file doesn't exist, don't select
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
return|return
name|filePath
return|;
name|QString
name|ret
init|=
name|selectionHelper
argument_list|(
name|fi
operator|.
name|path
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|?
name|QString
argument_list|()
else|:
name|fi
operator|.
name|path
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|,
name|fi
operator|.
name|fileName
argument_list|()
argument_list|,
name|q
operator|->
name|allSelectors
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ret
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|ret
return|;
return|return
name|filePath
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the list of extra selectors which have been added programmatically to this instance. */
end_comment
begin_function
DECL|function|extraSelectors
name|QStringList
name|QFileSelector
operator|::
name|extraSelectors
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileSelector
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|extras
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the \a list of extra selectors which have been added programmatically to this instance.      These selectors have priority over any which have been automatically picked up. */
end_comment
begin_function
DECL|function|setExtraSelectors
name|void
name|QFileSelector
operator|::
name|setExtraSelectors
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFileSelector
argument_list|)
expr_stmt|;
name|d
operator|->
name|extras
operator|=
name|list
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the complete, ordered list of selectors used by this instance */
end_comment
begin_function
DECL|function|allSelectors
name|QStringList
name|QFileSelector
operator|::
name|allSelectors
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileSelector
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|sharedDataMutex
argument_list|)
decl_stmt|;
name|QFileSelectorPrivate
operator|::
name|updateSelectors
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|extras
operator|+
name|sharedData
operator|->
name|staticSelectors
return|;
block|}
end_function
begin_function
DECL|function|updateSelectors
name|void
name|QFileSelectorPrivate
operator|::
name|updateSelectors
parameter_list|()
block|{
if|if
condition|(
operator|!
name|sharedData
operator|->
name|staticSelectors
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
comment|//Already loaded
name|QLatin1Char
name|pathSep
argument_list|(
literal|','
argument_list|)
decl_stmt|;
name|QStringList
name|envSelectors
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_FILE_SELECTORS"
argument_list|)
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
if|if
condition|(
name|envSelectors
operator|.
name|count
argument_list|()
condition|)
name|sharedData
operator|->
name|staticSelectors
operator|<<
name|envSelectors
expr_stmt|;
if|if
condition|(
operator|!
name|qgetenv
argument_list|(
name|env_override
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|sharedData
operator|->
name|staticSelectors
operator|<<
name|sharedData
operator|->
name|preloadedStatics
expr_stmt|;
comment|//Potential for static selectors from other modules
comment|// TODO: Update on locale changed?
name|sharedData
operator|->
name|staticSelectors
operator|<<
name|QLocale
operator|::
name|system
argument_list|()
operator|.
name|name
argument_list|()
expr_stmt|;
name|sharedData
operator|->
name|staticSelectors
operator|<<
name|platformSelectors
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformSelectors
name|QStringList
name|QFileSelectorPrivate
operator|::
name|platformSelectors
parameter_list|()
block|{
comment|// similar, but not identical to QSysInfo::osType
name|QStringList
name|ret
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"windows"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"wince"
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"winrt"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINPHONE
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"winphone"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"unix"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"android"
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"blackberry"
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"qnx"
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"linux"
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_DARWIN
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"darwin"
argument_list|)
expr_stmt|;
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"mac"
argument_list|)
expr_stmt|;
comment|// compatibility synonym
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"ios"
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
name|ret
operator|<<
name|QStringLiteral
argument_list|(
literal|"osx"
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
name|ret
operator|<<
name|QSysInfo
operator|::
name|kernelType
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|addStatics
name|void
name|QFileSelectorPrivate
operator|::
name|addStatics
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|statics
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|sharedDataMutex
argument_list|)
decl_stmt|;
name|sharedData
operator|->
name|preloadedStatics
operator|<<
name|statics
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qfileselector.cpp"
end_include
end_unit
