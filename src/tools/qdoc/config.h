begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   config.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef
begin_define
DECL|macro|CONFIG_H
define|#
directive|define
name|CONFIG_H
end_define
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qstack.h>
end_include
begin_include
include|#
directive|include
file|<qpair.h>
end_include
begin_include
include|#
directive|include
file|"location.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*   This struct contains all the information for   one config variable found in a qdocconf file.  */
end_comment
begin_struct
DECL|struct|ConfigVar
struct|struct
name|ConfigVar
block|{
DECL|member|plus_
name|bool
name|plus_
decl_stmt|;
DECL|member|name_
name|QString
name|name_
decl_stmt|;
DECL|member|values_
name|QStringList
name|values_
decl_stmt|;
DECL|member|currentPath_
name|QString
name|currentPath_
decl_stmt|;
DECL|member|location_
name|Location
name|location_
decl_stmt|;
DECL|function|ConfigVar
name|ConfigVar
argument_list|()
operator|:
name|plus_
argument_list|(
argument|false
argument_list|)
block|{ }
DECL|function|ConfigVar
name|ConfigVar
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QStringList
operator|&
name|values
argument_list|,
specifier|const
name|QString
operator|&
name|dir
argument_list|)
operator|:
name|plus_
argument_list|(
name|true
argument_list|)
operator|,
name|name_
argument_list|(
name|name
argument_list|)
operator|,
name|values_
argument_list|(
name|values
argument_list|)
operator|,
name|currentPath_
argument_list|(
argument|dir
argument_list|)
block|{ }
DECL|function|ConfigVar
name|ConfigVar
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QStringList
operator|&
name|values
argument_list|,
specifier|const
name|QString
operator|&
name|dir
argument_list|,
specifier|const
name|Location
operator|&
name|loc
argument_list|)
operator|:
name|plus_
argument_list|(
name|false
argument_list|)
operator|,
name|name_
argument_list|(
name|name
argument_list|)
operator|,
name|values_
argument_list|(
name|values
argument_list|)
operator|,
name|currentPath_
argument_list|(
name|dir
argument_list|)
operator|,
name|location_
argument_list|(
argument|loc
argument_list|)
block|{ }
block|}
struct|;
end_struct
begin_comment
comment|/*   In this multimap, the key is a config variable name.  */
end_comment
begin_typedef
DECL|typedef|QString
DECL|typedef|ConfigVarMultimap
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|ConfigVar
operator|>
name|ConfigVarMultimap
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Config
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::Config
argument_list|)
name|public
label|:
name|Config
argument_list|(
specifier|const
name|QString
operator|&
name|programName
argument_list|)
expr_stmt|;
operator|~
name|Config
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|debug_
decl_stmt|;
name|void
name|load
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|void
name|setStringList
parameter_list|(
specifier|const
name|QString
modifier|&
name|var
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|values
parameter_list|)
function_decl|;
specifier|const
name|QString
operator|&
name|programName
argument_list|()
specifier|const
block|{
return|return
name|prog
return|;
block|}
specifier|const
name|Location
operator|&
name|location
argument_list|()
specifier|const
block|{
return|return
name|loc
return|;
block|}
specifier|const
name|Location
operator|&
name|lastLocation
argument_list|()
specifier|const
block|{
return|return
name|lastLocation_
return|;
block|}
name|bool
name|getBool
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
decl|const
decl_stmt|;
name|int
name|getInt
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
decl|const
decl_stmt|;
name|QString
name|getOutputDir
argument_list|()
specifier|const
expr_stmt|;
name|QSet
operator|<
name|QString
operator|>
name|getOutputFormats
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|getString
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
decl|const
decl_stmt|;
name|QSet
operator|<
name|QString
operator|>
name|getStringSet
argument_list|(
argument|const QString& var
argument_list|)
specifier|const
expr_stmt|;
name|QStringList
name|getStringList
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|getCanonicalPathList
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|,
name|bool
name|validate
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|QRegExp
name|getRegExp
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QRegExp
operator|>
name|getRegExpList
argument_list|(
argument|const QString& var
argument_list|)
specifier|const
expr_stmt|;
name|QSet
operator|<
name|QString
operator|>
name|subVars
argument_list|(
argument|const QString& var
argument_list|)
specifier|const
expr_stmt|;
name|void
name|subVarsAndValues
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|,
name|ConfigVarMultimap
operator|&
name|t
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|getAllFiles
argument_list|(
specifier|const
name|QString
operator|&
name|filesVar
argument_list|,
specifier|const
name|QString
operator|&
name|dirsVar
argument_list|,
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|excludedDirs
operator|=
name|QSet
operator|<
name|QString
operator|>
operator|(
operator|)
argument_list|,
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|excludedFiles
operator|=
name|QSet
operator|<
name|QString
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
name|QString
name|getIncludeFilePath
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|getExampleQdocFiles
argument_list|(
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|excludedDirs
argument_list|,
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|excludedFiles
argument_list|)
decl_stmt|;
name|QStringList
name|getExampleImageFiles
argument_list|(
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|excludedDirs
argument_list|,
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|excludedFiles
argument_list|)
decl_stmt|;
specifier|static
name|QStringList
name|getFilesHere
argument_list|(
specifier|const
name|QString
operator|&
name|dir
argument_list|,
specifier|const
name|QString
operator|&
name|nameFilter
argument_list|,
specifier|const
name|Location
operator|&
name|location
operator|=
name|Location
argument_list|()
argument_list|,
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|excludedDirs
operator|=
name|QSet
operator|<
name|QString
operator|>
operator|(
operator|)
argument_list|,
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|excludedFiles
operator|=
name|QSet
operator|<
name|QString
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
specifier|static
name|QString
name|findFile
parameter_list|(
specifier|const
name|Location
modifier|&
name|location
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|dirs
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QString
modifier|&
name|userFriendlyFilePath
parameter_list|)
function_decl|;
specifier|static
name|QString
name|findFile
parameter_list|(
specifier|const
name|Location
modifier|&
name|location
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|dirs
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileBase
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|fileExtensions
parameter_list|,
name|QString
modifier|&
name|userFriendlyFilePath
parameter_list|)
function_decl|;
specifier|static
name|QString
name|copyFile
parameter_list|(
specifier|const
name|Location
modifier|&
name|location
parameter_list|,
specifier|const
name|QString
modifier|&
name|sourceFilePath
parameter_list|,
specifier|const
name|QString
modifier|&
name|userFriendlySourceFilePath
parameter_list|,
specifier|const
name|QString
modifier|&
name|targetDirPath
parameter_list|)
function_decl|;
specifier|static
name|int
name|numParams
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
specifier|static
name|bool
name|removeDirContents
parameter_list|(
specifier|const
name|QString
modifier|&
name|dir
parameter_list|)
function_decl|;
specifier|static
name|void
name|pushWorkingDir
parameter_list|(
specifier|const
name|QString
modifier|&
name|dir
parameter_list|)
function_decl|;
specifier|static
name|QString
name|popWorkingDir
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|QString
name|dot
decl_stmt|;
specifier|static
name|bool
name|generateExamples
decl_stmt|;
specifier|static
name|QString
name|installDir
decl_stmt|;
specifier|static
name|QString
name|overrideOutputDir
decl_stmt|;
specifier|static
name|QSet
operator|<
name|QString
operator|>
name|overrideOutputFormats
expr_stmt|;
name|private
label|:
specifier|static
name|bool
name|isMetaKeyChar
parameter_list|(
name|QChar
name|ch
parameter_list|)
function_decl|;
name|void
name|load
parameter_list|(
name|Location
name|location
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|QString
name|prog
decl_stmt|;
name|Location
name|loc
decl_stmt|;
name|Location
name|lastLocation_
decl_stmt|;
name|ConfigVarMultimap
name|configVars_
decl_stmt|;
specifier|static
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|uncompressedFiles
expr_stmt|;
specifier|static
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|extractedDirs
expr_stmt|;
specifier|static
name|int
name|numInstances
decl_stmt|;
specifier|static
name|QStack
operator|<
name|QString
operator|>
name|workingDirs_
expr_stmt|;
specifier|static
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|includeFilesMap_
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|ConfigStrings
struct|struct
name|ConfigStrings
block|{
DECL|member|ALIAS
specifier|static
name|QString
name|ALIAS
decl_stmt|;
DECL|member|AUTOLINKERRORS
specifier|static
name|QString
name|AUTOLINKERRORS
decl_stmt|;
DECL|member|BASE
specifier|static
name|QString
name|BASE
decl_stmt|;
DECL|member|BASEDIR
specifier|static
name|QString
name|BASEDIR
decl_stmt|;
DECL|member|BUILDVERSION
specifier|static
name|QString
name|BUILDVERSION
decl_stmt|;
DECL|member|CODEINDENT
specifier|static
name|QString
name|CODEINDENT
decl_stmt|;
DECL|member|CPPCLASSESPAGE
specifier|static
name|QString
name|CPPCLASSESPAGE
decl_stmt|;
DECL|member|DEFINES
specifier|static
name|QString
name|DEFINES
decl_stmt|;
DECL|member|DEPENDS
specifier|static
name|QString
name|DEPENDS
decl_stmt|;
DECL|member|DESCRIPTION
specifier|static
name|QString
name|DESCRIPTION
decl_stmt|;
DECL|member|EDITION
specifier|static
name|QString
name|EDITION
decl_stmt|;
DECL|member|ENDHEADER
specifier|static
name|QString
name|ENDHEADER
decl_stmt|;
DECL|member|EXAMPLEDIRS
specifier|static
name|QString
name|EXAMPLEDIRS
decl_stmt|;
DECL|member|EXAMPLES
specifier|static
name|QString
name|EXAMPLES
decl_stmt|;
DECL|member|EXAMPLESINSTALLPATH
specifier|static
name|QString
name|EXAMPLESINSTALLPATH
decl_stmt|;
DECL|member|EXCLUDEDIRS
specifier|static
name|QString
name|EXCLUDEDIRS
decl_stmt|;
DECL|member|EXCLUDEFILES
specifier|static
name|QString
name|EXCLUDEFILES
decl_stmt|;
DECL|member|EXTRAIMAGES
specifier|static
name|QString
name|EXTRAIMAGES
decl_stmt|;
DECL|member|FALSEHOODS
specifier|static
name|QString
name|FALSEHOODS
decl_stmt|;
DECL|member|FORMATTING
specifier|static
name|QString
name|FORMATTING
decl_stmt|;
DECL|member|GENERATEINDEX
specifier|static
name|QString
name|GENERATEINDEX
decl_stmt|;
DECL|member|HEADERDIRS
specifier|static
name|QString
name|HEADERDIRS
decl_stmt|;
DECL|member|HEADERS
specifier|static
name|QString
name|HEADERS
decl_stmt|;
DECL|member|HEADERSCRIPTS
specifier|static
name|QString
name|HEADERSCRIPTS
decl_stmt|;
DECL|member|HEADERSTYLES
specifier|static
name|QString
name|HEADERSTYLES
decl_stmt|;
DECL|member|HOMEPAGE
specifier|static
name|QString
name|HOMEPAGE
decl_stmt|;
DECL|member|IGNOREDIRECTIVES
specifier|static
name|QString
name|IGNOREDIRECTIVES
decl_stmt|;
DECL|member|IGNORETOKENS
specifier|static
name|QString
name|IGNORETOKENS
decl_stmt|;
DECL|member|IMAGEDIRS
specifier|static
name|QString
name|IMAGEDIRS
decl_stmt|;
DECL|member|IMAGES
specifier|static
name|QString
name|IMAGES
decl_stmt|;
DECL|member|INDEXES
specifier|static
name|QString
name|INDEXES
decl_stmt|;
DECL|member|LANDINGPAGE
specifier|static
name|QString
name|LANDINGPAGE
decl_stmt|;
DECL|member|LANGUAGE
specifier|static
name|QString
name|LANGUAGE
decl_stmt|;
DECL|member|MACRO
specifier|static
name|QString
name|MACRO
decl_stmt|;
DECL|member|MANIFESTMETA
specifier|static
name|QString
name|MANIFESTMETA
decl_stmt|;
DECL|member|NATURALLANGUAGE
specifier|static
name|QString
name|NATURALLANGUAGE
decl_stmt|;
DECL|member|NAVIGATION
specifier|static
name|QString
name|NAVIGATION
decl_stmt|;
DECL|member|NOLINKERRORS
specifier|static
name|QString
name|NOLINKERRORS
decl_stmt|;
DECL|member|OBSOLETELINKS
specifier|static
name|QString
name|OBSOLETELINKS
decl_stmt|;
DECL|member|OUTPUTDIR
specifier|static
name|QString
name|OUTPUTDIR
decl_stmt|;
DECL|member|OUTPUTENCODING
specifier|static
name|QString
name|OUTPUTENCODING
decl_stmt|;
DECL|member|OUTPUTLANGUAGE
specifier|static
name|QString
name|OUTPUTLANGUAGE
decl_stmt|;
DECL|member|OUTPUTFORMATS
specifier|static
name|QString
name|OUTPUTFORMATS
decl_stmt|;
DECL|member|OUTPUTPREFIXES
specifier|static
name|QString
name|OUTPUTPREFIXES
decl_stmt|;
DECL|member|PROJECT
specifier|static
name|QString
name|PROJECT
decl_stmt|;
DECL|member|REDIRECTDOCUMENTATIONTODEVNULL
specifier|static
name|QString
name|REDIRECTDOCUMENTATIONTODEVNULL
decl_stmt|;
DECL|member|QHP
specifier|static
name|QString
name|QHP
decl_stmt|;
DECL|member|QUOTINGINFORMATION
specifier|static
name|QString
name|QUOTINGINFORMATION
decl_stmt|;
DECL|member|SCRIPTDIRS
specifier|static
name|QString
name|SCRIPTDIRS
decl_stmt|;
DECL|member|SCRIPTS
specifier|static
name|QString
name|SCRIPTS
decl_stmt|;
DECL|member|SHOWINTERNAL
specifier|static
name|QString
name|SHOWINTERNAL
decl_stmt|;
DECL|member|SOURCEDIRS
specifier|static
name|QString
name|SOURCEDIRS
decl_stmt|;
DECL|member|SOURCEENCODING
specifier|static
name|QString
name|SOURCEENCODING
decl_stmt|;
DECL|member|SOURCES
specifier|static
name|QString
name|SOURCES
decl_stmt|;
DECL|member|SPURIOUS
specifier|static
name|QString
name|SPURIOUS
decl_stmt|;
DECL|member|STYLEDIRS
specifier|static
name|QString
name|STYLEDIRS
decl_stmt|;
DECL|member|STYLE
specifier|static
name|QString
name|STYLE
decl_stmt|;
DECL|member|STYLES
specifier|static
name|QString
name|STYLES
decl_stmt|;
DECL|member|STYLESHEETS
specifier|static
name|QString
name|STYLESHEETS
decl_stmt|;
DECL|member|SYNTAXHIGHLIGHTING
specifier|static
name|QString
name|SYNTAXHIGHLIGHTING
decl_stmt|;
DECL|member|TEMPLATEDIR
specifier|static
name|QString
name|TEMPLATEDIR
decl_stmt|;
DECL|member|TABSIZE
specifier|static
name|QString
name|TABSIZE
decl_stmt|;
DECL|member|TAGFILE
specifier|static
name|QString
name|TAGFILE
decl_stmt|;
DECL|member|TRANSLATORS
specifier|static
name|QString
name|TRANSLATORS
decl_stmt|;
DECL|member|URL
specifier|static
name|QString
name|URL
decl_stmt|;
DECL|member|VERSION
specifier|static
name|QString
name|VERSION
decl_stmt|;
DECL|member|VERSIONSYM
specifier|static
name|QString
name|VERSIONSYM
decl_stmt|;
DECL|member|FILEEXTENSIONS
specifier|static
name|QString
name|FILEEXTENSIONS
decl_stmt|;
DECL|member|IMAGEEXTENSIONS
specifier|static
name|QString
name|IMAGEEXTENSIONS
decl_stmt|;
DECL|member|QMLONLY
specifier|static
name|QString
name|QMLONLY
decl_stmt|;
DECL|member|QMLTYPESPAGE
specifier|static
name|QString
name|QMLTYPESPAGE
decl_stmt|;
block|}
struct|;
end_struct
begin_define
DECL|macro|CONFIG_ALIAS
define|#
directive|define
name|CONFIG_ALIAS
value|ConfigStrings::ALIAS
end_define
begin_define
DECL|macro|CONFIG_AUTOLINKERRORS
define|#
directive|define
name|CONFIG_AUTOLINKERRORS
value|ConfigStrings::AUTOLINKERRORS
end_define
begin_define
DECL|macro|CONFIG_BASE
define|#
directive|define
name|CONFIG_BASE
value|ConfigStrings::BASE
end_define
begin_define
DECL|macro|CONFIG_BASEDIR
define|#
directive|define
name|CONFIG_BASEDIR
value|ConfigStrings::BASEDIR
end_define
begin_define
DECL|macro|CONFIG_BUILDVERSION
define|#
directive|define
name|CONFIG_BUILDVERSION
value|ConfigStrings::BUILDVERSION
end_define
begin_define
DECL|macro|CONFIG_CODEINDENT
define|#
directive|define
name|CONFIG_CODEINDENT
value|ConfigStrings::CODEINDENT
end_define
begin_define
DECL|macro|CONFIG_CPPCLASSESPAGE
define|#
directive|define
name|CONFIG_CPPCLASSESPAGE
value|ConfigStrings::CPPCLASSESPAGE
end_define
begin_define
DECL|macro|CONFIG_DEFINES
define|#
directive|define
name|CONFIG_DEFINES
value|ConfigStrings::DEFINES
end_define
begin_define
DECL|macro|CONFIG_DEPENDS
define|#
directive|define
name|CONFIG_DEPENDS
value|ConfigStrings::DEPENDS
end_define
begin_define
DECL|macro|CONFIG_DESCRIPTION
define|#
directive|define
name|CONFIG_DESCRIPTION
value|ConfigStrings::DESCRIPTION
end_define
begin_define
DECL|macro|CONFIG_EDITION
define|#
directive|define
name|CONFIG_EDITION
value|ConfigStrings::EDITION
end_define
begin_define
DECL|macro|CONFIG_ENDHEADER
define|#
directive|define
name|CONFIG_ENDHEADER
value|ConfigStrings::ENDHEADER
end_define
begin_define
DECL|macro|CONFIG_EXAMPLEDIRS
define|#
directive|define
name|CONFIG_EXAMPLEDIRS
value|ConfigStrings::EXAMPLEDIRS
end_define
begin_define
DECL|macro|CONFIG_EXAMPLES
define|#
directive|define
name|CONFIG_EXAMPLES
value|ConfigStrings::EXAMPLES
end_define
begin_define
DECL|macro|CONFIG_EXAMPLESINSTALLPATH
define|#
directive|define
name|CONFIG_EXAMPLESINSTALLPATH
value|ConfigStrings::EXAMPLESINSTALLPATH
end_define
begin_define
DECL|macro|CONFIG_EXCLUDEDIRS
define|#
directive|define
name|CONFIG_EXCLUDEDIRS
value|ConfigStrings::EXCLUDEDIRS
end_define
begin_define
DECL|macro|CONFIG_EXCLUDEFILES
define|#
directive|define
name|CONFIG_EXCLUDEFILES
value|ConfigStrings::EXCLUDEFILES
end_define
begin_define
DECL|macro|CONFIG_EXTRAIMAGES
define|#
directive|define
name|CONFIG_EXTRAIMAGES
value|ConfigStrings::EXTRAIMAGES
end_define
begin_define
DECL|macro|CONFIG_FALSEHOODS
define|#
directive|define
name|CONFIG_FALSEHOODS
value|ConfigStrings::FALSEHOODS
end_define
begin_define
DECL|macro|CONFIG_FORMATTING
define|#
directive|define
name|CONFIG_FORMATTING
value|ConfigStrings::FORMATTING
end_define
begin_define
DECL|macro|CONFIG_GENERATEINDEX
define|#
directive|define
name|CONFIG_GENERATEINDEX
value|ConfigStrings::GENERATEINDEX
end_define
begin_define
DECL|macro|CONFIG_HEADERDIRS
define|#
directive|define
name|CONFIG_HEADERDIRS
value|ConfigStrings::HEADERDIRS
end_define
begin_define
DECL|macro|CONFIG_HEADERS
define|#
directive|define
name|CONFIG_HEADERS
value|ConfigStrings::HEADERS
end_define
begin_define
DECL|macro|CONFIG_HEADERSCRIPTS
define|#
directive|define
name|CONFIG_HEADERSCRIPTS
value|ConfigStrings::HEADERSCRIPTS
end_define
begin_define
DECL|macro|CONFIG_HEADERSTYLES
define|#
directive|define
name|CONFIG_HEADERSTYLES
value|ConfigStrings::HEADERSTYLES
end_define
begin_define
DECL|macro|CONFIG_HOMEPAGE
define|#
directive|define
name|CONFIG_HOMEPAGE
value|ConfigStrings::HOMEPAGE
end_define
begin_define
DECL|macro|CONFIG_IGNOREDIRECTIVES
define|#
directive|define
name|CONFIG_IGNOREDIRECTIVES
value|ConfigStrings::IGNOREDIRECTIVES
end_define
begin_define
DECL|macro|CONFIG_IGNORETOKENS
define|#
directive|define
name|CONFIG_IGNORETOKENS
value|ConfigStrings::IGNORETOKENS
end_define
begin_define
DECL|macro|CONFIG_IMAGEDIRS
define|#
directive|define
name|CONFIG_IMAGEDIRS
value|ConfigStrings::IMAGEDIRS
end_define
begin_define
DECL|macro|CONFIG_IMAGES
define|#
directive|define
name|CONFIG_IMAGES
value|ConfigStrings::IMAGES
end_define
begin_define
DECL|macro|CONFIG_INDEXES
define|#
directive|define
name|CONFIG_INDEXES
value|ConfigStrings::INDEXES
end_define
begin_define
DECL|macro|CONFIG_LANDINGPAGE
define|#
directive|define
name|CONFIG_LANDINGPAGE
value|ConfigStrings::LANDINGPAGE
end_define
begin_define
DECL|macro|CONFIG_LANGUAGE
define|#
directive|define
name|CONFIG_LANGUAGE
value|ConfigStrings::LANGUAGE
end_define
begin_define
DECL|macro|CONFIG_MACRO
define|#
directive|define
name|CONFIG_MACRO
value|ConfigStrings::MACRO
end_define
begin_define
DECL|macro|CONFIG_MANIFESTMETA
define|#
directive|define
name|CONFIG_MANIFESTMETA
value|ConfigStrings::MANIFESTMETA
end_define
begin_define
DECL|macro|CONFIG_NATURALLANGUAGE
define|#
directive|define
name|CONFIG_NATURALLANGUAGE
value|ConfigStrings::NATURALLANGUAGE
end_define
begin_define
DECL|macro|CONFIG_NAVIGATION
define|#
directive|define
name|CONFIG_NAVIGATION
value|ConfigStrings::NAVIGATION
end_define
begin_define
DECL|macro|CONFIG_NOLINKERRORS
define|#
directive|define
name|CONFIG_NOLINKERRORS
value|ConfigStrings::NOLINKERRORS
end_define
begin_define
DECL|macro|CONFIG_OBSOLETELINKS
define|#
directive|define
name|CONFIG_OBSOLETELINKS
value|ConfigStrings::OBSOLETELINKS
end_define
begin_define
DECL|macro|CONFIG_OUTPUTDIR
define|#
directive|define
name|CONFIG_OUTPUTDIR
value|ConfigStrings::OUTPUTDIR
end_define
begin_define
DECL|macro|CONFIG_OUTPUTENCODING
define|#
directive|define
name|CONFIG_OUTPUTENCODING
value|ConfigStrings::OUTPUTENCODING
end_define
begin_define
DECL|macro|CONFIG_OUTPUTLANGUAGE
define|#
directive|define
name|CONFIG_OUTPUTLANGUAGE
value|ConfigStrings::OUTPUTLANGUAGE
end_define
begin_define
DECL|macro|CONFIG_OUTPUTFORMATS
define|#
directive|define
name|CONFIG_OUTPUTFORMATS
value|ConfigStrings::OUTPUTFORMATS
end_define
begin_define
DECL|macro|CONFIG_OUTPUTPREFIXES
define|#
directive|define
name|CONFIG_OUTPUTPREFIXES
value|ConfigStrings::OUTPUTPREFIXES
end_define
begin_define
DECL|macro|CONFIG_PROJECT
define|#
directive|define
name|CONFIG_PROJECT
value|ConfigStrings::PROJECT
end_define
begin_define
DECL|macro|CONFIG_REDIRECTDOCUMENTATIONTODEVNULL
define|#
directive|define
name|CONFIG_REDIRECTDOCUMENTATIONTODEVNULL
value|ConfigStrings::REDIRECTDOCUMENTATIONTODEVNULL
end_define
begin_define
DECL|macro|CONFIG_QHP
define|#
directive|define
name|CONFIG_QHP
value|ConfigStrings::QHP
end_define
begin_define
DECL|macro|CONFIG_QUOTINGINFORMATION
define|#
directive|define
name|CONFIG_QUOTINGINFORMATION
value|ConfigStrings::QUOTINGINFORMATION
end_define
begin_define
DECL|macro|CONFIG_SCRIPTDIRS
define|#
directive|define
name|CONFIG_SCRIPTDIRS
value|ConfigStrings::SCRIPTDIRS
end_define
begin_define
DECL|macro|CONFIG_SCRIPTS
define|#
directive|define
name|CONFIG_SCRIPTS
value|ConfigStrings::SCRIPTS
end_define
begin_define
DECL|macro|CONFIG_SHOWINTERNAL
define|#
directive|define
name|CONFIG_SHOWINTERNAL
value|ConfigStrings::SHOWINTERNAL
end_define
begin_define
DECL|macro|CONFIG_SOURCEDIRS
define|#
directive|define
name|CONFIG_SOURCEDIRS
value|ConfigStrings::SOURCEDIRS
end_define
begin_define
DECL|macro|CONFIG_SOURCEENCODING
define|#
directive|define
name|CONFIG_SOURCEENCODING
value|ConfigStrings::SOURCEENCODING
end_define
begin_define
DECL|macro|CONFIG_SOURCES
define|#
directive|define
name|CONFIG_SOURCES
value|ConfigStrings::SOURCES
end_define
begin_define
DECL|macro|CONFIG_SPURIOUS
define|#
directive|define
name|CONFIG_SPURIOUS
value|ConfigStrings::SPURIOUS
end_define
begin_define
DECL|macro|CONFIG_STYLEDIRS
define|#
directive|define
name|CONFIG_STYLEDIRS
value|ConfigStrings::STYLEDIRS
end_define
begin_define
DECL|macro|CONFIG_STYLE
define|#
directive|define
name|CONFIG_STYLE
value|ConfigStrings::STYLE
end_define
begin_define
DECL|macro|CONFIG_STYLES
define|#
directive|define
name|CONFIG_STYLES
value|ConfigStrings::STYLES
end_define
begin_define
DECL|macro|CONFIG_STYLESHEETS
define|#
directive|define
name|CONFIG_STYLESHEETS
value|ConfigStrings::STYLESHEETS
end_define
begin_define
DECL|macro|CONFIG_SYNTAXHIGHLIGHTING
define|#
directive|define
name|CONFIG_SYNTAXHIGHLIGHTING
value|ConfigStrings::SYNTAXHIGHLIGHTING
end_define
begin_define
DECL|macro|CONFIG_TEMPLATEDIR
define|#
directive|define
name|CONFIG_TEMPLATEDIR
value|ConfigStrings::TEMPLATEDIR
end_define
begin_define
DECL|macro|CONFIG_TABSIZE
define|#
directive|define
name|CONFIG_TABSIZE
value|ConfigStrings::TABSIZE
end_define
begin_define
DECL|macro|CONFIG_TAGFILE
define|#
directive|define
name|CONFIG_TAGFILE
value|ConfigStrings::TAGFILE
end_define
begin_define
DECL|macro|CONFIG_TRANSLATORS
define|#
directive|define
name|CONFIG_TRANSLATORS
value|ConfigStrings::TRANSLATORS
end_define
begin_define
DECL|macro|CONFIG_URL
define|#
directive|define
name|CONFIG_URL
value|ConfigStrings::URL
end_define
begin_define
DECL|macro|CONFIG_VERSION
define|#
directive|define
name|CONFIG_VERSION
value|ConfigStrings::VERSION
end_define
begin_define
DECL|macro|CONFIG_VERSIONSYM
define|#
directive|define
name|CONFIG_VERSIONSYM
value|ConfigStrings::VERSIONSYM
end_define
begin_define
DECL|macro|CONFIG_FILEEXTENSIONS
define|#
directive|define
name|CONFIG_FILEEXTENSIONS
value|ConfigStrings::FILEEXTENSIONS
end_define
begin_define
DECL|macro|CONFIG_IMAGEEXTENSIONS
define|#
directive|define
name|CONFIG_IMAGEEXTENSIONS
value|ConfigStrings::IMAGEEXTENSIONS
end_define
begin_define
DECL|macro|CONFIG_QMLONLY
define|#
directive|define
name|CONFIG_QMLONLY
value|ConfigStrings::QMLONLY
end_define
begin_define
DECL|macro|CONFIG_QMLTYPESPAGE
define|#
directive|define
name|CONFIG_QMLTYPESPAGE
value|ConfigStrings::QMLTYPESPAGE
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
