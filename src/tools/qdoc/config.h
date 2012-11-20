begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
comment|/*   In QStringPair, the first string is the path to a directory;   the second string is some value.  */
end_comment
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringPair
typedef|typedef
name|QPair
operator|<
name|QString
operator|,
name|QString
operator|>
name|QStringPair
expr_stmt|;
end_typedef
begin_comment
comment|/*   In QStringListPair, the first string is the path to a directory;   the string list is a list of string values.  */
end_comment
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringListPair
typedef|typedef
name|QPair
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|QStringListPair
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringPairMultiMap
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|QStringPair
operator|>
name|QStringPairMultiMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringPairMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QStringPair
operator|>
name|QStringPairMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringListPairMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QStringListPair
operator|>
name|QStringListPairMap
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Config
block|{
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
name|unload
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
name|QString
name|getPath
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
name|getCanonicalRelativePathList
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|getCleanPathList
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|getPathList
argument_list|(
specifier|const
name|QString
operator|&
name|var
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
name|QStringPairMap
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
name|QT_STATIC_CONST
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
name|QMap
operator|<
name|QString
operator|,
name|Location
operator|>
name|locMap
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|stringValueMap
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|stringListValueMap
expr_stmt|;
name|QStringPairMap
name|stringPairMap
decl_stmt|;
name|QStringListPairMap
name|stringListPairMap
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
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|CONFIG_ALIAS
define|#
directive|define
name|CONFIG_ALIAS
value|"alias"
end_define
begin_define
DECL|macro|CONFIG_BASE
define|#
directive|define
name|CONFIG_BASE
value|"base"
end_define
begin_define
DECL|macro|CONFIG_BASEDIR
define|#
directive|define
name|CONFIG_BASEDIR
value|"basedir"
end_define
begin_define
DECL|macro|CONFIG_CODEINDENT
define|#
directive|define
name|CONFIG_CODEINDENT
value|"codeindent"
end_define
begin_define
DECL|macro|CONFIG_DEFINES
define|#
directive|define
name|CONFIG_DEFINES
value|"defines"
end_define
begin_define
DECL|macro|CONFIG_DEPENDS
define|#
directive|define
name|CONFIG_DEPENDS
value|"depends"
end_define
begin_define
DECL|macro|CONFIG_DESCRIPTION
define|#
directive|define
name|CONFIG_DESCRIPTION
value|"description"
end_define
begin_define
DECL|macro|CONFIG_EDITION
define|#
directive|define
name|CONFIG_EDITION
value|"edition"
end_define
begin_define
DECL|macro|CONFIG_ENDHEADER
define|#
directive|define
name|CONFIG_ENDHEADER
value|"endheader"
end_define
begin_define
DECL|macro|CONFIG_EXAMPLEDIRS
define|#
directive|define
name|CONFIG_EXAMPLEDIRS
value|"exampledirs"
end_define
begin_define
DECL|macro|CONFIG_EXAMPLES
define|#
directive|define
name|CONFIG_EXAMPLES
value|"examples"
end_define
begin_define
DECL|macro|CONFIG_EXCLUDEDIRS
define|#
directive|define
name|CONFIG_EXCLUDEDIRS
value|"excludedirs"
end_define
begin_define
DECL|macro|CONFIG_EXCLUDEFILES
define|#
directive|define
name|CONFIG_EXCLUDEFILES
value|"excludefiles"
end_define
begin_define
DECL|macro|CONFIG_EXTRAIMAGES
define|#
directive|define
name|CONFIG_EXTRAIMAGES
value|"extraimages"
end_define
begin_define
DECL|macro|CONFIG_FALSEHOODS
define|#
directive|define
name|CONFIG_FALSEHOODS
value|"falsehoods"
end_define
begin_define
DECL|macro|CONFIG_FORMATTING
define|#
directive|define
name|CONFIG_FORMATTING
value|"formatting"
end_define
begin_define
DECL|macro|CONFIG_GENERATEINDEX
define|#
directive|define
name|CONFIG_GENERATEINDEX
value|"generateindex"
end_define
begin_define
DECL|macro|CONFIG_HEADERDIRS
define|#
directive|define
name|CONFIG_HEADERDIRS
value|"headerdirs"
end_define
begin_define
DECL|macro|CONFIG_HEADERS
define|#
directive|define
name|CONFIG_HEADERS
value|"headers"
end_define
begin_define
DECL|macro|CONFIG_HEADERSCRIPTS
define|#
directive|define
name|CONFIG_HEADERSCRIPTS
value|"headerscripts"
end_define
begin_define
DECL|macro|CONFIG_HEADERSTYLES
define|#
directive|define
name|CONFIG_HEADERSTYLES
value|"headerstyles"
end_define
begin_define
DECL|macro|CONFIG_IGNOREDIRECTIVES
define|#
directive|define
name|CONFIG_IGNOREDIRECTIVES
value|"ignoredirectives"
end_define
begin_define
DECL|macro|CONFIG_IGNORETOKENS
define|#
directive|define
name|CONFIG_IGNORETOKENS
value|"ignoretokens"
end_define
begin_define
DECL|macro|CONFIG_IMAGEDIRS
define|#
directive|define
name|CONFIG_IMAGEDIRS
value|"imagedirs"
end_define
begin_define
DECL|macro|CONFIG_IMAGES
define|#
directive|define
name|CONFIG_IMAGES
value|"images"
end_define
begin_define
DECL|macro|CONFIG_INDEXES
define|#
directive|define
name|CONFIG_INDEXES
value|"indexes"
end_define
begin_define
DECL|macro|CONFIG_LANGUAGE
define|#
directive|define
name|CONFIG_LANGUAGE
value|"language"
end_define
begin_define
DECL|macro|CONFIG_MACRO
define|#
directive|define
name|CONFIG_MACRO
value|"macro"
end_define
begin_define
DECL|macro|CONFIG_NATURALLANGUAGE
define|#
directive|define
name|CONFIG_NATURALLANGUAGE
value|"naturallanguage"
end_define
begin_define
DECL|macro|CONFIG_NOLINKERRORS
define|#
directive|define
name|CONFIG_NOLINKERRORS
value|"nolinkerrors"
end_define
begin_define
DECL|macro|CONFIG_OBSOLETELINKS
define|#
directive|define
name|CONFIG_OBSOLETELINKS
value|"obsoletelinks"
end_define
begin_define
DECL|macro|CONFIG_OUTPUTDIR
define|#
directive|define
name|CONFIG_OUTPUTDIR
value|"outputdir"
end_define
begin_define
DECL|macro|CONFIG_OUTPUTENCODING
define|#
directive|define
name|CONFIG_OUTPUTENCODING
value|"outputencoding"
end_define
begin_define
DECL|macro|CONFIG_OUTPUTLANGUAGE
define|#
directive|define
name|CONFIG_OUTPUTLANGUAGE
value|"outputlanguage"
end_define
begin_define
DECL|macro|CONFIG_OUTPUTFORMATS
define|#
directive|define
name|CONFIG_OUTPUTFORMATS
value|"outputformats"
end_define
begin_define
DECL|macro|CONFIG_OUTPUTPREFIXES
define|#
directive|define
name|CONFIG_OUTPUTPREFIXES
value|"outputprefixes"
end_define
begin_define
DECL|macro|CONFIG_PROJECT
define|#
directive|define
name|CONFIG_PROJECT
value|"project"
end_define
begin_define
DECL|macro|CONFIG_QHP
define|#
directive|define
name|CONFIG_QHP
value|"qhp"
end_define
begin_define
DECL|macro|CONFIG_QUOTINGINFORMATION
define|#
directive|define
name|CONFIG_QUOTINGINFORMATION
value|"quotinginformation"
end_define
begin_define
DECL|macro|CONFIG_SCRIPTDIRS
define|#
directive|define
name|CONFIG_SCRIPTDIRS
value|"scriptdirs"
end_define
begin_define
DECL|macro|CONFIG_SCRIPTS
define|#
directive|define
name|CONFIG_SCRIPTS
value|"scripts"
end_define
begin_define
DECL|macro|CONFIG_SHOWINTERNAL
define|#
directive|define
name|CONFIG_SHOWINTERNAL
value|"showinternal"
end_define
begin_define
DECL|macro|CONFIG_SOURCEDIRS
define|#
directive|define
name|CONFIG_SOURCEDIRS
value|"sourcedirs"
end_define
begin_define
DECL|macro|CONFIG_SOURCEENCODING
define|#
directive|define
name|CONFIG_SOURCEENCODING
value|"sourceencoding"
end_define
begin_define
DECL|macro|CONFIG_SOURCES
define|#
directive|define
name|CONFIG_SOURCES
value|"sources"
end_define
begin_define
DECL|macro|CONFIG_SPURIOUS
define|#
directive|define
name|CONFIG_SPURIOUS
value|"spurious"
end_define
begin_define
DECL|macro|CONFIG_STYLEDIRS
define|#
directive|define
name|CONFIG_STYLEDIRS
value|"styledirs"
end_define
begin_define
DECL|macro|CONFIG_STYLE
define|#
directive|define
name|CONFIG_STYLE
value|"style"
end_define
begin_define
DECL|macro|CONFIG_STYLES
define|#
directive|define
name|CONFIG_STYLES
value|"styles"
end_define
begin_define
DECL|macro|CONFIG_STYLESHEETS
define|#
directive|define
name|CONFIG_STYLESHEETS
value|"stylesheets"
end_define
begin_define
DECL|macro|CONFIG_SYNTAXHIGHLIGHTING
define|#
directive|define
name|CONFIG_SYNTAXHIGHLIGHTING
value|"syntaxhighlighting"
end_define
begin_define
DECL|macro|CONFIG_TEMPLATEDIR
define|#
directive|define
name|CONFIG_TEMPLATEDIR
value|"templatedir"
end_define
begin_define
DECL|macro|CONFIG_TABSIZE
define|#
directive|define
name|CONFIG_TABSIZE
value|"tabsize"
end_define
begin_define
DECL|macro|CONFIG_TAGFILE
define|#
directive|define
name|CONFIG_TAGFILE
value|"tagfile"
end_define
begin_define
DECL|macro|CONFIG_TRANSLATORS
define|#
directive|define
name|CONFIG_TRANSLATORS
value|"translators"
end_define
begin_define
DECL|macro|CONFIG_URL
define|#
directive|define
name|CONFIG_URL
value|"url"
end_define
begin_define
DECL|macro|CONFIG_VERSION
define|#
directive|define
name|CONFIG_VERSION
value|"version"
end_define
begin_define
DECL|macro|CONFIG_VERSIONSYM
define|#
directive|define
name|CONFIG_VERSIONSYM
value|"versionsym"
end_define
begin_define
DECL|macro|CONFIG_FILEEXTENSIONS
define|#
directive|define
name|CONFIG_FILEEXTENSIONS
value|"fileextensions"
end_define
begin_define
DECL|macro|CONFIG_IMAGEEXTENSIONS
define|#
directive|define
name|CONFIG_IMAGEEXTENSIONS
value|"imageextensions"
end_define
begin_define
DECL|macro|CONFIG_QMLONLY
define|#
directive|define
name|CONFIG_QMLONLY
value|"qmlonly"
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
