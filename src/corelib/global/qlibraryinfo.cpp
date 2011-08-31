begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|"qfile.h"
end_include
begin_include
include|#
directive|include
file|"qconfig.h"
end_include
begin_include
include|#
directive|include
file|"qsettings.h"
end_include
begin_include
include|#
directive|include
file|"qlibraryinfo.h"
end_include
begin_include
include|#
directive|include
file|"qscopedpointer.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_QMAKE
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_define
DECL|macro|BOOTSTRAPPING
define|#
directive|define
name|BOOTSTRAPPING
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|BOOTSTRAPPING
end_ifdef
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|QString
name|qmake_libraryInfoFile
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QT_END_NAMESPACE
else|#
directive|else
include|#
directive|include
file|"qcoreapplication.h"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_MAC
include|#
directive|include
file|"private/qcore_mac_p.h"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QLIBRARYINFO_EPOCROOT
include|#
directive|include
file|"symbian/epocroot_p.h"
endif|#
directive|endif
include|#
directive|include
file|"qconfig.cpp"
name|QT_BEGIN_NAMESPACE
specifier|extern
name|void
name|qDumpCPUFeatures
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// in qsimd.cpp
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
end_ifndef
begin_struct
DECL|struct|QLibrarySettings
struct|struct
name|QLibrarySettings
block|{
name|QLibrarySettings
parameter_list|()
constructor_decl|;
DECL|member|settings
name|QScopedPointer
argument_list|<
name|QSettings
argument_list|>
name|settings
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QLibrarySettings
argument_list|,
argument|qt_library_settings
argument_list|)
end_macro
begin_class
DECL|class|QLibraryInfoPrivate
class|class
name|QLibraryInfoPrivate
block|{
public|public:
specifier|static
name|QSettings
modifier|*
name|findConfiguration
parameter_list|()
function_decl|;
DECL|function|cleanup
specifier|static
name|void
name|cleanup
parameter_list|()
block|{
name|QLibrarySettings
modifier|*
name|ls
init|=
name|qt_library_settings
argument_list|()
decl_stmt|;
if|if
condition|(
name|ls
condition|)
name|ls
operator|->
name|settings
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
DECL|function|configuration
specifier|static
name|QSettings
modifier|*
name|configuration
parameter_list|()
block|{
name|QLibrarySettings
modifier|*
name|ls
init|=
name|qt_library_settings
argument_list|()
decl_stmt|;
return|return
name|ls
condition|?
name|ls
operator|->
name|settings
operator|.
name|data
argument_list|()
else|:
literal|0
return|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|QLibrarySettings
name|QLibrarySettings
operator|::
name|QLibrarySettings
parameter_list|()
member_init_list|:
name|settings
argument_list|(
name|QLibraryInfoPrivate
operator|::
name|findConfiguration
argument_list|()
argument_list|)
block|{
ifndef|#
directive|ifndef
name|BOOTSTRAPPING
name|qAddPostRoutine
argument_list|(
name|QLibraryInfoPrivate
operator|::
name|cleanup
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_function
DECL|function|findConfiguration
name|QSettings
modifier|*
name|QLibraryInfoPrivate
operator|::
name|findConfiguration
parameter_list|()
block|{
name|QString
name|qtconfig
init|=
name|QLatin1String
argument_list|(
literal|":/qt/etc/qt.conf"
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|BOOTSTRAPPING
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|qtconfig
argument_list|)
condition|)
name|qtconfig
operator|=
name|qmake_libraryInfoFile
argument_list|()
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|qtconfig
argument_list|)
operator|&&
name|QCoreApplication
operator|::
name|instance
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|CFBundleRef
name|bundleRef
init|=
name|CFBundleGetMainBundle
argument_list|()
decl_stmt|;
if|if
condition|(
name|bundleRef
condition|)
block|{
name|QCFType
argument_list|<
name|CFURLRef
argument_list|>
name|urlRef
init|=
name|CFBundleCopyResourceURL
argument_list|(
name|bundleRef
argument_list|,
name|QCFString
argument_list|(
name|QLatin1String
argument_list|(
literal|"qt.conf"
argument_list|)
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|urlRef
condition|)
block|{
name|QCFString
name|path
init|=
name|CFURLCopyFileSystemPath
argument_list|(
name|urlRef
argument_list|,
name|kCFURLPOSIXPathStyle
argument_list|)
decl_stmt|;
name|qtconfig
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|qtconfig
operator|.
name|isEmpty
argument_list|()
condition|)
endif|#
directive|endif
block|{
name|QDir
name|pwd
argument_list|(
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
argument_list|)
decl_stmt|;
name|qtconfig
operator|=
name|pwd
operator|.
name|filePath
argument_list|(
name|QLatin1String
argument_list|(
literal|"qt.conf"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|qtconfig
argument_list|)
condition|)
return|return
operator|new
name|QSettings
argument_list|(
name|qtconfig
argument_list|,
name|QSettings
operator|::
name|IniFormat
argument_list|)
return|;
return|return
literal|0
return|;
comment|//no luck
block|}
end_function
begin_comment
comment|/*!     \class QLibraryInfo     \brief The QLibraryInfo class provides information about the Qt library.      Many pieces of information are established when Qt is configured.     Installation paths, license information, and even a unique build     key. This class provides an abstraction for accessing this     information.      \table     \header \o Function           \o Return value     \row    \o buildKey()         \o A string that identifies the Qt version and                                      the configuration. This key is used to ensure                                      that \l{plugins} link against the same version                                      of Qt as the application.     \row    \o location()         \o The path to a certain Qt                                      component (e.g., documentation, header files).     \row    \o licensee(),                licensedProducts() \o Licensing information.     \endtable      You can also use a \c qt.conf file to override the hard-coded paths     that are compiled into the Qt library. For more information, see     the \l {Using qt.conf} documentation.      \sa QSysInfo, {Using qt.conf} */
end_comment
begin_comment
comment|/*! \internal     You cannot create a QLibraryInfo, instead only the static functions are available to query    information. */
end_comment
begin_constructor
DECL|function|QLibraryInfo
name|QLibraryInfo
operator|::
name|QLibraryInfo
parameter_list|()
block|{ }
end_constructor
begin_comment
comment|/*!   Returns the person to whom this build of Qt is licensed.    \sa licensedProducts() */
end_comment
begin_function
name|QString
DECL|function|licensee
name|QLibraryInfo
operator|::
name|licensee
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|str
init|=
name|QT_CONFIGURE_LICENSEE
decl_stmt|;
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|str
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the products that the license for this build of Qt has access to.    \sa licensee() */
end_comment
begin_function
name|QString
DECL|function|licensedProducts
name|QLibraryInfo
operator|::
name|licensedProducts
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|str
init|=
name|QT_CONFIGURE_LICENSED_PRODUCTS
decl_stmt|;
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|str
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.6     Returns the installation date for this build of Qt. The install date will     usually be the last time that Qt sources were configured. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
end_ifndef
begin_function
name|QDate
DECL|function|buildDate
name|QLibraryInfo
operator|::
name|buildDate
parameter_list|()
block|{
return|return
name|QDate
operator|::
name|fromString
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|qt_configure_installation
operator|+
literal|12
argument_list|)
argument_list|,
name|Qt
operator|::
name|ISODate
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_DATESTRING
end_comment
begin_comment
comment|/*!   Returns the location specified by \a loc.  */
end_comment
begin_function
name|QString
DECL|function|location
name|QLibraryInfo
operator|::
name|location
parameter_list|(
name|LibraryLocation
name|loc
parameter_list|)
block|{
name|QString
name|ret
decl_stmt|;
if|if
condition|(
operator|!
name|QLibraryInfoPrivate
operator|::
name|configuration
argument_list|()
condition|)
block|{
specifier|const
name|char
modifier|*
name|path
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|loc
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_CONFIGURE_PREFIX_PATH
case|case
name|PrefixPath
case|:
name|path
operator|=
name|QT_CONFIGURE_PREFIX_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_DOCUMENTATION_PATH
case|case
name|DocumentationPath
case|:
name|path
operator|=
name|QT_CONFIGURE_DOCUMENTATION_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_HEADERS_PATH
case|case
name|HeadersPath
case|:
name|path
operator|=
name|QT_CONFIGURE_HEADERS_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_LIBRARIES_PATH
case|case
name|LibrariesPath
case|:
name|path
operator|=
name|QT_CONFIGURE_LIBRARIES_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_BINARIES_PATH
case|case
name|BinariesPath
case|:
name|path
operator|=
name|QT_CONFIGURE_BINARIES_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_PLUGINS_PATH
case|case
name|PluginsPath
case|:
name|path
operator|=
name|QT_CONFIGURE_PLUGINS_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_IMPORTS_PATH
case|case
name|ImportsPath
case|:
name|path
operator|=
name|QT_CONFIGURE_IMPORTS_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_DATA_PATH
case|case
name|DataPath
case|:
name|path
operator|=
name|QT_CONFIGURE_DATA_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_TRANSLATIONS_PATH
case|case
name|TranslationsPath
case|:
name|path
operator|=
name|QT_CONFIGURE_TRANSLATIONS_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_SETTINGS_PATH
case|case
name|SettingsPath
case|:
name|path
operator|=
name|QT_CONFIGURE_SETTINGS_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_CONFIGURE_EXAMPLES_PATH
case|case
name|ExamplesPath
case|:
name|path
operator|=
name|QT_CONFIGURE_EXAMPLES_PATH
expr_stmt|;
break|break;
endif|#
directive|endif
default|default:
break|break;
block|}
if|if
condition|(
name|path
condition|)
name|ret
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QString
name|key
decl_stmt|;
name|QString
name|defaultValue
decl_stmt|;
switch|switch
condition|(
name|loc
condition|)
block|{
case|case
name|PrefixPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Prefix"
argument_list|)
expr_stmt|;
break|break;
case|case
name|DocumentationPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Documentation"
argument_list|)
expr_stmt|;
name|defaultValue
operator|=
name|QLatin1String
argument_list|(
literal|"doc"
argument_list|)
expr_stmt|;
break|break;
case|case
name|HeadersPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Headers"
argument_list|)
expr_stmt|;
name|defaultValue
operator|=
name|QLatin1String
argument_list|(
literal|"include"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LibrariesPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Libraries"
argument_list|)
expr_stmt|;
name|defaultValue
operator|=
name|QLatin1String
argument_list|(
literal|"lib"
argument_list|)
expr_stmt|;
break|break;
case|case
name|BinariesPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Binaries"
argument_list|)
expr_stmt|;
name|defaultValue
operator|=
name|QLatin1String
argument_list|(
literal|"bin"
argument_list|)
expr_stmt|;
break|break;
case|case
name|PluginsPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Plugins"
argument_list|)
expr_stmt|;
name|defaultValue
operator|=
name|QLatin1String
argument_list|(
literal|"plugins"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ImportsPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Imports"
argument_list|)
expr_stmt|;
name|defaultValue
operator|=
name|QLatin1String
argument_list|(
literal|"imports"
argument_list|)
expr_stmt|;
break|break;
case|case
name|DataPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Data"
argument_list|)
expr_stmt|;
break|break;
case|case
name|TranslationsPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Translations"
argument_list|)
expr_stmt|;
name|defaultValue
operator|=
name|QLatin1String
argument_list|(
literal|"translations"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SettingsPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Settings"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ExamplesPath
case|:
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Examples"
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QSettings
modifier|*
name|config
init|=
name|QLibraryInfoPrivate
operator|::
name|configuration
argument_list|()
decl_stmt|;
name|config
operator|->
name|beginGroup
argument_list|(
name|QLatin1String
argument_list|(
literal|"Paths"
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|subKey
decl_stmt|;
block|{
comment|/*                   find the child group whose version number is closest                   to the library version.  for example and we have the                   following groups:                    Paths                   Paths/4.0                   Paths/4.1.2                   Paths/4.2.5                   Paths/5                    if QT_VERSION is 4.0.1, then we use 'Paths/4.0'                   if QT_VERSION is 4.1.5, then we use 'Paths/4.1.2'                   if QT_VERSION is 4.6.3, then we use 'Paths/4.2.5'                   if QT_VERSION is 6.0.2, then we use 'Paths/5'                    note: any of the trailing version numbers may be                   omitted (in which case, they default to zero),                   i.e. 4 == 4.0.0, 4.1 == 4.1.0, and so on                 */
enum|enum
block|{
name|QT_MAJOR
init|=
operator|(
operator|(
name|QT_VERSION
operator|>>
literal|16
operator|)
operator|&
literal|0xFF
operator|)
block|,
name|QT_MINOR
init|=
operator|(
operator|(
name|QT_VERSION
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
operator|)
block|,
name|QT_PATCH
init|=
operator|(
name|QT_VERSION
operator|&
literal|0xFF
operator|)
block|}
enum|;
name|int
name|maj
init|=
literal|0
decl_stmt|,
name|min
init|=
literal|0
decl_stmt|,
name|pat
init|=
literal|0
decl_stmt|;
name|QStringList
name|children
init|=
name|config
operator|->
name|childGroups
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|child
init|=
literal|0
init|;
name|child
operator|<
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|child
control|)
block|{
name|QString
name|cver
init|=
name|children
operator|.
name|at
argument_list|(
name|child
argument_list|)
decl_stmt|;
name|QStringList
name|cver_list
init|=
name|cver
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|cver_list
operator|.
name|size
argument_list|()
operator|>
literal|0
operator|&&
name|cver_list
operator|.
name|size
argument_list|()
operator|<
literal|4
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|int
name|cmaj
init|=
operator|-
literal|1
decl_stmt|,
name|cmin
init|=
operator|-
literal|1
decl_stmt|,
name|cpat
init|=
operator|-
literal|1
decl_stmt|;
name|cmaj
operator|=
name|cver_list
index|[
literal|0
index|]
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
operator|||
name|cmaj
operator|<
literal|0
condition|)
continue|continue;
if|if
condition|(
name|cver_list
operator|.
name|size
argument_list|()
operator|>=
literal|2
condition|)
block|{
name|cmin
operator|=
name|cver_list
index|[
literal|1
index|]
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
continue|continue;
if|if
condition|(
name|cmin
operator|<
literal|0
condition|)
name|cmin
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|cver_list
operator|.
name|size
argument_list|()
operator|>=
literal|3
condition|)
block|{
name|cpat
operator|=
name|cver_list
index|[
literal|2
index|]
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
continue|continue;
if|if
condition|(
name|cpat
operator|<
literal|0
condition|)
name|cpat
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|cmaj
operator|>=
name|maj
operator|&&
name|cmaj
operator|<=
name|QT_MAJOR
operator|)
operator|&&
operator|(
name|cmin
operator|==
operator|-
literal|1
operator|||
operator|(
name|cmin
operator|>=
name|min
operator|&&
name|cmin
operator|<=
name|QT_MINOR
operator|)
operator|)
operator|&&
operator|(
name|cpat
operator|==
operator|-
literal|1
operator|||
operator|(
name|cpat
operator|>=
name|pat
operator|&&
name|cpat
operator|<=
name|QT_PATCH
operator|)
operator|)
operator|&&
name|config
operator|->
name|contains
argument_list|(
name|cver
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|key
argument_list|)
condition|)
block|{
name|subKey
operator|=
name|cver
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
name|maj
operator|=
name|cmaj
expr_stmt|;
name|min
operator|=
name|cmin
expr_stmt|;
name|pat
operator|=
name|cpat
expr_stmt|;
block|}
block|}
block|}
block|}
name|ret
operator|=
name|config
operator|->
name|value
argument_list|(
name|subKey
operator|+
name|key
argument_list|,
name|defaultValue
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
comment|// expand environment variables in the form $(ENVVAR)
name|int
name|rep
decl_stmt|;
name|QRegExp
name|reg_var
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\$\\(.*\\)"
argument_list|)
argument_list|)
decl_stmt|;
name|reg_var
operator|.
name|setMinimal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|rep
operator|=
name|reg_var
operator|.
name|indexIn
argument_list|(
name|ret
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
name|ret
operator|.
name|replace
argument_list|(
name|rep
argument_list|,
name|reg_var
operator|.
name|matchedLength
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
name|ret
operator|.
name|mid
argument_list|(
name|rep
operator|+
literal|2
argument_list|,
name|reg_var
operator|.
name|matchedLength
argument_list|()
operator|-
literal|3
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QLIBRARYINFO_EPOCROOT
comment|// $${EPOCROOT} is a special case, resolve it similarly to qmake.
name|QRegExp
name|epocrootMatcher
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\$\\$\\{EPOCROOT\\}"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|rep
operator|=
name|epocrootMatcher
operator|.
name|indexIn
argument_list|(
name|ret
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
name|ret
operator|.
name|replace
argument_list|(
name|rep
argument_list|,
name|epocrootMatcher
operator|.
name|matchedLength
argument_list|()
argument_list|,
name|qt_epocRoot
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|config
operator|->
name|endGroup
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|QDir
operator|::
name|isRelativePath
argument_list|(
name|ret
argument_list|)
condition|)
block|{
name|QString
name|baseDir
decl_stmt|;
if|if
condition|(
name|loc
operator|==
name|PrefixPath
condition|)
block|{
comment|// we make the prefix path absolute to the executable's directory
ifdef|#
directive|ifdef
name|BOOTSTRAPPING
name|baseDir
operator|=
name|QFileInfo
argument_list|(
name|qmake_libraryInfoFile
argument_list|()
argument_list|)
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|CFBundleRef
name|bundleRef
init|=
name|CFBundleGetMainBundle
argument_list|()
decl_stmt|;
if|if
condition|(
name|bundleRef
condition|)
block|{
name|QCFType
argument_list|<
name|CFURLRef
argument_list|>
name|urlRef
init|=
name|CFBundleCopyBundleURL
argument_list|(
name|bundleRef
argument_list|)
decl_stmt|;
if|if
condition|(
name|urlRef
condition|)
block|{
name|QCFString
name|path
init|=
name|CFURLCopyFileSystemPath
argument_list|(
name|urlRef
argument_list|,
name|kCFURLPOSIXPathStyle
argument_list|)
decl_stmt|;
return|return
name|QDir
operator|::
name|cleanPath
argument_list|(
name|QString
argument_list|(
name|path
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"/Contents/"
argument_list|)
operator|+
name|ret
argument_list|)
return|;
block|}
block|}
endif|#
directive|endif
name|baseDir
operator|=
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|baseDir
operator|=
name|QDir
operator|::
name|currentPath
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
else|else
block|{
comment|// we make any other path absolute to the prefix directory
name|baseDir
operator|=
name|location
argument_list|(
name|PrefixPath
argument_list|)
expr_stmt|;
block|}
name|ret
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|baseDir
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|ret
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|/*!     \enum QLibraryInfo::LibraryLocation      \keyword library location      This enum type is used to specify a specific location     specifier:      \value PrefixPath The default prefix for all paths.     \value DocumentationPath The location for documentation upon install.     \value HeadersPath The location for all headers.     \value LibrariesPath The location of installed libraries.     \value BinariesPath The location of installed Qt binaries (tools and applications).     \value PluginsPath The location of installed Qt plugins.     \value ImportsPath The location of installed QML extensions to import.     \value DataPath The location of general Qt data.     \value TranslationsPath The location of translation information for Qt strings.     \value SettingsPath The location for Qt settings.     \value ExamplesPath The location for examples upon install.      \sa location() */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SETTINGS
end_comment
begin_decl_stmt
name|QT_END_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
name|defined
argument_list|(
name|ELF_INTERPRETER
argument_list|)
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|<stdlib.h>
DECL|variable|qt_core_interpreter
specifier|extern
specifier|const
name|char
name|qt_core_interpreter
index|[]
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".interp"
argument_list|)
operator|)
argument_list|)
init|=
name|ELF_INTERPRETER
decl_stmt|;
end_decl_stmt
begin_extern
extern|extern
literal|"C"
name|void
name|qt_core_boilerplate
parameter_list|()
function_decl|;
end_extern
begin_function
DECL|function|qt_core_boilerplate
name|void
name|qt_core_boilerplate
parameter_list|()
block|{
name|printf
argument_list|(
literal|"This is the QtCore library version "
name|QT_VERSION_STR
literal|"\n"
literal|"Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).\n"
literal|"Contact: Nokia Corporation (qt-info@nokia.com)\n"
literal|"\n"
literal|"Build date:          %s\n"
literal|"Installation prefix: %s\n"
literal|"Library path:        %s\n"
literal|"Include path:        %s\n"
argument_list|,
name|qt_configure_installation
operator|+
literal|12
argument_list|,
name|qt_configure_prefix_path_str
operator|+
literal|12
argument_list|,
name|qt_configure_libraries_path_str
operator|+
literal|12
argument_list|,
name|qt_configure_headers_path_str
operator|+
literal|12
argument_list|)
expr_stmt|;
name|QT_PREPEND_NAMESPACE
function_decl|(
name|qDumpCPUFeatures
function_decl|)
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|QT_EVAL
specifier|extern
name|void
name|qt_core_eval_init
argument_list|(
name|uint
argument_list|)
decl_stmt|;
name|qt_core_eval_init
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
