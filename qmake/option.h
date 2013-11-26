begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|OPTION_H
end_ifndef
begin_define
DECL|macro|OPTION_H
define|#
directive|define
name|OPTION_H
end_define
begin_include
include|#
directive|include
file|<qmakeglobals.h>
end_include
begin_include
include|#
directive|include
file|<qmakevfs.h>
end_include
begin_include
include|#
directive|include
file|<qmakeparser.h>
end_include
begin_include
include|#
directive|include
file|<qmakeevaluator.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qlibraryinfo.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
DECL|macro|QMAKE_VERSION_STR
define|#
directive|define
name|QMAKE_VERSION_STR
value|"3.0"
name|QString
name|qmake_getpwd
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|qmake_setpwd
parameter_list|(
specifier|const
name|QString
modifier|&
name|p
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|debug_msg
define|#
directive|define
name|debug_msg
value|if(Option::debug_level) debug_msg_internal
end_define
begin_function_decl
name|void
name|debug_msg_internal
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//don't call directly, use debug_msg
end_comment
begin_enum
DECL|enum|QMakeWarn
enum|enum
name|QMakeWarn
block|{
DECL|enumerator|WarnNone
name|WarnNone
init|=
literal|0x00
block|,
DECL|enumerator|WarnParser
name|WarnParser
init|=
literal|0x01
block|,
DECL|enumerator|WarnLogic
name|WarnLogic
init|=
literal|0x02
block|,
DECL|enumerator|WarnDeprecated
name|WarnDeprecated
init|=
literal|0x04
block|,
DECL|enumerator|WarnAll
name|WarnAll
init|=
literal|0xFF
block|}
enum|;
end_enum
begin_function_decl
name|void
name|warn_msg
parameter_list|(
name|QMakeWarn
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|QMakeProject
name|class
name|QMakeProject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|EvalHandler
range|:
name|public
name|QMakeHandler
block|{
name|public
operator|:
name|void
name|message
argument_list|(
argument|int type
argument_list|,
argument|const QString&msg
argument_list|,
argument|const QString&fileName
argument_list|,
argument|int lineNo
argument_list|)
block|;
name|void
name|fileMessage
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|)
block|;
name|void
name|aboutToEval
argument_list|(
name|ProFile
operator|*
argument_list|,
name|ProFile
operator|*
argument_list|,
name|EvalFileType
argument_list|)
block|;
name|void
name|doneWithEval
argument_list|(
name|ProFile
operator|*
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|Option
struct|struct
name|Option
block|{
DECL|member|evalHandler
specifier|static
name|EvalHandler
name|evalHandler
decl_stmt|;
DECL|member|globals
specifier|static
name|QMakeGlobals
modifier|*
name|globals
decl_stmt|;
DECL|member|proFileCache
specifier|static
name|ProFileCache
modifier|*
name|proFileCache
decl_stmt|;
DECL|member|vfs
specifier|static
name|QMakeVfs
modifier|*
name|vfs
decl_stmt|;
DECL|member|parser
specifier|static
name|QMakeParser
modifier|*
name|parser
decl_stmt|;
comment|//simply global convenience
DECL|member|libtool_ext
specifier|static
name|QString
name|libtool_ext
decl_stmt|;
DECL|member|pkgcfg_ext
specifier|static
name|QString
name|pkgcfg_ext
decl_stmt|;
DECL|member|prf_ext
specifier|static
name|QString
name|prf_ext
decl_stmt|;
DECL|member|prl_ext
specifier|static
name|QString
name|prl_ext
decl_stmt|;
DECL|member|ui_ext
specifier|static
name|QString
name|ui_ext
decl_stmt|;
DECL|member|h_ext
specifier|static
name|QStringList
name|h_ext
decl_stmt|;
DECL|member|cpp_ext
specifier|static
name|QStringList
name|cpp_ext
decl_stmt|;
DECL|member|c_ext
specifier|static
name|QStringList
name|c_ext
decl_stmt|;
DECL|member|cpp_moc_ext
specifier|static
name|QString
name|cpp_moc_ext
decl_stmt|;
DECL|member|obj_ext
specifier|static
name|QString
name|obj_ext
decl_stmt|;
DECL|member|lex_ext
specifier|static
name|QString
name|lex_ext
decl_stmt|;
DECL|member|yacc_ext
specifier|static
name|QString
name|yacc_ext
decl_stmt|;
DECL|member|h_moc_mod
specifier|static
name|QString
name|h_moc_mod
decl_stmt|;
DECL|member|lex_mod
specifier|static
name|QString
name|lex_mod
decl_stmt|;
DECL|member|yacc_mod
specifier|static
name|QString
name|yacc_mod
decl_stmt|;
DECL|member|dir_sep
specifier|static
name|QString
name|dir_sep
decl_stmt|;
DECL|member|pro_ext
specifier|static
name|QString
name|pro_ext
decl_stmt|;
DECL|member|res_ext
specifier|static
name|QString
name|res_ext
decl_stmt|;
DECL|member|field_sep
specifier|static
name|char
name|field_sep
decl_stmt|;
DECL|enum|CmdLineFlags
enum|enum
name|CmdLineFlags
block|{
DECL|enumerator|QMAKE_CMDLINE_SUCCESS
name|QMAKE_CMDLINE_SUCCESS
init|=
literal|0x00
block|,
DECL|enumerator|QMAKE_CMDLINE_SHOW_USAGE
name|QMAKE_CMDLINE_SHOW_USAGE
init|=
literal|0x01
block|,
DECL|enumerator|QMAKE_CMDLINE_BAIL
name|QMAKE_CMDLINE_BAIL
init|=
literal|0x02
block|,
DECL|enumerator|QMAKE_CMDLINE_ERROR
name|QMAKE_CMDLINE_ERROR
init|=
literal|0x04
block|}
enum|;
comment|//both of these must be called..
specifier|static
name|int
name|init
parameter_list|(
name|int
name|argc
init|=
literal|0
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
init|=
literal|0
parameter_list|)
function_decl|;
comment|//parse cmdline
specifier|static
name|void
name|prepareProject
parameter_list|(
specifier|const
name|QString
modifier|&
name|pfile
parameter_list|)
function_decl|;
specifier|static
name|bool
name|postProcessProject
parameter_list|(
name|QMakeProject
modifier|*
parameter_list|)
function_decl|;
DECL|enum|StringFixFlags
enum|enum
name|StringFixFlags
block|{
DECL|enumerator|FixNone
name|FixNone
init|=
literal|0x00
block|,
DECL|enumerator|FixEnvVars
name|FixEnvVars
init|=
literal|0x01
block|,
DECL|enumerator|FixPathCanonicalize
name|FixPathCanonicalize
init|=
literal|0x02
block|,
DECL|enumerator|FixPathToLocalSeparators
name|FixPathToLocalSeparators
init|=
literal|0x04
block|,
DECL|enumerator|FixPathToTargetSeparators
name|FixPathToTargetSeparators
init|=
literal|0x08
block|,
DECL|enumerator|FixPathToNormalSeparators
name|FixPathToNormalSeparators
init|=
literal|0x10
block|}
enum|;
specifier|static
name|QString
name|fixString
parameter_list|(
name|QString
name|string
parameter_list|,
name|uchar
name|flags
parameter_list|)
function_decl|;
comment|//and convenience functions
DECL|function|fixPathToLocalOS
specifier|inline
specifier|static
name|QString
name|fixPathToLocalOS
parameter_list|(
specifier|const
name|QString
modifier|&
name|in
parameter_list|,
name|bool
name|fix_env
init|=
name|true
parameter_list|,
name|bool
name|canonical
init|=
name|true
parameter_list|)
block|{
name|uchar
name|flags
init|=
name|FixPathToLocalSeparators
decl_stmt|;
if|if
condition|(
name|fix_env
condition|)
name|flags
operator||=
name|FixEnvVars
expr_stmt|;
if|if
condition|(
name|canonical
condition|)
name|flags
operator||=
name|FixPathCanonicalize
expr_stmt|;
return|return
name|fixString
argument_list|(
name|in
argument_list|,
name|flags
argument_list|)
return|;
block|}
DECL|function|fixPathToTargetOS
specifier|inline
specifier|static
name|QString
name|fixPathToTargetOS
parameter_list|(
specifier|const
name|QString
modifier|&
name|in
parameter_list|,
name|bool
name|fix_env
init|=
name|true
parameter_list|,
name|bool
name|canonical
init|=
name|true
parameter_list|)
block|{
name|uchar
name|flags
init|=
name|FixPathToTargetSeparators
decl_stmt|;
if|if
condition|(
name|fix_env
condition|)
name|flags
operator||=
name|FixEnvVars
expr_stmt|;
if|if
condition|(
name|canonical
condition|)
name|flags
operator||=
name|FixPathCanonicalize
expr_stmt|;
return|return
name|fixString
argument_list|(
name|in
argument_list|,
name|flags
argument_list|)
return|;
block|}
DECL|function|normalizePath
specifier|inline
specifier|static
name|QString
name|normalizePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|in
parameter_list|,
name|bool
name|fix_env
init|=
name|true
parameter_list|,
name|bool
name|canonical
init|=
name|true
parameter_list|)
block|{
name|uchar
name|flags
init|=
name|FixPathToNormalSeparators
decl_stmt|;
if|if
condition|(
name|fix_env
condition|)
name|flags
operator||=
name|FixEnvVars
expr_stmt|;
if|if
condition|(
name|canonical
condition|)
name|flags
operator||=
name|FixPathCanonicalize
expr_stmt|;
return|return
name|fixString
argument_list|(
name|in
argument_list|,
name|flags
argument_list|)
return|;
block|}
DECL|function|hasFileExtension
specifier|inline
specifier|static
name|bool
name|hasFileExtension
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|extensions
parameter_list|)
block|{
name|foreach
argument_list|(
argument|const QString&ext
argument_list|,
argument|extensions
argument_list|)
if|if
condition|(
name|str
operator|.
name|endsWith
argument_list|(
name|ext
argument_list|)
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|//global qmake mode, can only be in one mode per invocation!
DECL|enum|QMAKE_MODE
DECL|enumerator|QMAKE_GENERATE_NOTHING
enum|enum
name|QMAKE_MODE
block|{
name|QMAKE_GENERATE_NOTHING
block|,
DECL|enumerator|QMAKE_GENERATE_PROJECT
DECL|enumerator|QMAKE_GENERATE_MAKEFILE
DECL|enumerator|QMAKE_GENERATE_PRL
name|QMAKE_GENERATE_PROJECT
block|,
name|QMAKE_GENERATE_MAKEFILE
block|,
name|QMAKE_GENERATE_PRL
block|,
DECL|enumerator|QMAKE_SET_PROPERTY
DECL|enumerator|QMAKE_UNSET_PROPERTY
DECL|enumerator|QMAKE_QUERY_PROPERTY
name|QMAKE_SET_PROPERTY
block|,
name|QMAKE_UNSET_PROPERTY
block|,
name|QMAKE_QUERY_PROPERTY
block|}
enum|;
DECL|member|qmake_mode
specifier|static
name|QMAKE_MODE
name|qmake_mode
decl_stmt|;
comment|//all modes
DECL|member|output
specifier|static
name|QFile
name|output
decl_stmt|;
DECL|member|output_dir
specifier|static
name|QString
name|output_dir
decl_stmt|;
DECL|member|debug_level
specifier|static
name|int
name|debug_level
decl_stmt|;
DECL|member|warn_level
specifier|static
name|int
name|warn_level
decl_stmt|;
DECL|member|recursive
specifier|static
name|bool
name|recursive
decl_stmt|;
comment|//QMAKE_*_PROPERTY options
DECL|struct|prop
struct|struct
name|prop
block|{
DECL|member|properties
specifier|static
name|QStringList
name|properties
decl_stmt|;
block|}
struct|;
comment|//QMAKE_GENERATE_PROJECT options
DECL|struct|projfile
struct|struct
name|projfile
block|{
DECL|member|do_pwd
specifier|static
name|bool
name|do_pwd
decl_stmt|;
DECL|member|project_dirs
specifier|static
name|QStringList
name|project_dirs
decl_stmt|;
block|}
struct|;
comment|//QMAKE_GENERATE_MAKEFILE options
DECL|struct|mkfile
struct|struct
name|mkfile
block|{
DECL|member|do_deps
specifier|static
name|bool
name|do_deps
decl_stmt|;
DECL|member|do_mocs
specifier|static
name|bool
name|do_mocs
decl_stmt|;
DECL|member|do_dep_heuristics
specifier|static
name|bool
name|do_dep_heuristics
decl_stmt|;
DECL|member|do_preprocess
specifier|static
name|bool
name|do_preprocess
decl_stmt|;
DECL|member|do_stub_makefile
specifier|static
name|bool
name|do_stub_makefile
decl_stmt|;
DECL|member|cachefile_depth
specifier|static
name|int
name|cachefile_depth
decl_stmt|;
DECL|member|project_files
specifier|static
name|QStringList
name|project_files
decl_stmt|;
block|}
struct|;
DECL|member|private
name|private
label|:
DECL|member|state
specifier|static
name|int
name|parseCommandLine
parameter_list|(
name|QStringList
modifier|&
name|args
parameter_list|,
name|QMakeCmdLineParserState
modifier|&
name|state
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_function
DECL|function|fixEnvVariables
specifier|inline
name|QString
name|fixEnvVariables
parameter_list|(
specifier|const
name|QString
modifier|&
name|x
parameter_list|)
block|{
return|return
name|Option
operator|::
name|fixString
argument_list|(
name|x
argument_list|,
name|Option
operator|::
name|FixEnvVars
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|splitPathList
specifier|inline
name|QStringList
name|splitPathList
parameter_list|(
specifier|const
name|QString
modifier|&
name|paths
parameter_list|)
block|{
return|return
name|paths
operator|.
name|isEmpty
argument_list|()
condition|?
name|QStringList
argument_list|()
else|:
name|paths
operator|.
name|split
argument_list|(
name|Option
operator|::
name|globals
operator|->
name|dirlist_sep
argument_list|)
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
comment|// OPTION_H
end_comment
end_unit
