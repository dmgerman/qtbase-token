begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"lalr.h"
end_include
begin_include
include|#
directive|include
file|"dotgraph.h"
end_include
begin_include
include|#
directive|include
file|"parsetable.h"
end_include
begin_include
include|#
directive|include
file|"cppgenerator.h"
end_include
begin_include
include|#
directive|include
file|"recognizer.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<cstdlib>
end_include
begin_define
DECL|macro|QLALR_NO_DEBUG_TABLE
define|#
directive|define
name|QLALR_NO_DEBUG_TABLE
end_define
begin_define
DECL|macro|QLALR_NO_DEBUG_DOT
define|#
directive|define
name|QLALR_NO_DEBUG_DOT
end_define
begin_function
DECL|function|help_me
specifier|static
name|void
name|help_me
parameter_list|()
block|{
name|qerr
operator|<<
literal|"Usage: qlalr [options] [input file name]"
operator|<<
name|endl
operator|<<
name|endl
operator|<<
literal|"  --help, -h\t\tdisplay this help and exit"
operator|<<
name|endl
operator|<<
literal|"  --verbose, -v\t\tverbose output"
operator|<<
name|endl
operator|<<
literal|"  --no-debug\t\tno debug information"
operator|<<
name|endl
operator|<<
literal|"  --no-lines\t\tno #line directives"
operator|<<
name|endl
operator|<<
literal|"  --dot\t\t\tgenerate a graph"
operator|<<
name|endl
operator|<<
literal|"  --qt\t\tadd the Qt copyright header and Qt-specific types and macros"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|bool
name|generate_dot
init|=
literal|false
decl_stmt|;
name|bool
name|generate_report
init|=
literal|false
decl_stmt|;
name|bool
name|no_lines
init|=
literal|false
decl_stmt|;
name|bool
name|debug_info
init|=
literal|true
decl_stmt|;
name|bool
name|qt_copyright
init|=
literal|false
decl_stmt|;
name|QString
name|file_name
init|=
literal|0
decl_stmt|;
name|QStringList
name|args
init|=
name|app
operator|.
name|arguments
argument_list|()
decl_stmt|;
name|args
operator|.
name|removeFirst
argument_list|()
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|args
control|)
block|{
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-h"
argument_list|)
operator|||
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"--help"
argument_list|)
condition|)
name|help_me
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-v"
argument_list|)
operator|||
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"--verbose"
argument_list|)
condition|)
name|generate_report
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"--dot"
argument_list|)
condition|)
name|generate_dot
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"--no-lines"
argument_list|)
condition|)
name|no_lines
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"--no-debug"
argument_list|)
condition|)
name|debug_info
operator|=
literal|false
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"--qt"
argument_list|)
condition|)
name|qt_copyright
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|file_name
operator|.
name|isEmpty
argument_list|()
condition|)
name|file_name
operator|=
name|arg
expr_stmt|;
else|else
name|qerr
operator|<<
literal|"*** Warning. Ignore argument `"
operator|<<
name|arg
operator|<<
literal|"'"
operator|<<
name|endl
expr_stmt|;
block|}
if|if
condition|(
name|file_name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|help_me
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
name|Grammar
name|grammar
decl_stmt|;
name|Recognizer
name|p
argument_list|(
operator|&
name|grammar
argument_list|,
name|no_lines
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|p
operator|.
name|parse
argument_list|(
name|file_name
argument_list|)
condition|)
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
if|if
condition|(
name|grammar
operator|.
name|rules
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qerr
operator|<<
literal|"*** Fatal. No rules!"
operator|<<
name|endl
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|grammar
operator|.
name|start
operator|==
name|grammar
operator|.
name|names
operator|.
name|end
argument_list|()
condition|)
block|{
name|qerr
operator|<<
literal|"*** Fatal. No start symbol!"
operator|<<
name|endl
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
name|grammar
operator|.
name|buildExtendedGrammar
argument_list|()
expr_stmt|;
name|grammar
operator|.
name|buildRuleMap
argument_list|()
expr_stmt|;
name|Automaton
name|aut
argument_list|(
operator|&
name|grammar
argument_list|)
decl_stmt|;
name|aut
operator|.
name|build
argument_list|()
expr_stmt|;
name|CppGenerator
name|gen
argument_list|(
name|p
argument_list|,
name|grammar
argument_list|,
name|aut
argument_list|,
name|generate_report
argument_list|)
decl_stmt|;
name|gen
operator|.
name|setDebugInfo
argument_list|(
name|debug_info
argument_list|)
expr_stmt|;
name|gen
operator|.
name|setCopyright
argument_list|(
name|qt_copyright
argument_list|)
expr_stmt|;
name|gen
argument_list|()
expr_stmt|;
if|if
condition|(
name|generate_dot
condition|)
block|{
name|DotGraph
name|genDotFile
argument_list|(
name|qout
argument_list|)
decl_stmt|;
name|genDotFile
argument_list|(
operator|&
name|aut
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|generate_report
condition|)
block|{
name|ParseTable
name|genParseTable
argument_list|(
name|qout
argument_list|)
decl_stmt|;
name|genParseTable
argument_list|(
operator|&
name|aut
argument_list|)
expr_stmt|;
block|}
return|return
name|EXIT_SUCCESS
return|;
block|}
end_function
begin_function
DECL|function|expand
name|QString
name|Recognizer
operator|::
name|expand
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
specifier|const
block|{
name|QString
name|code
init|=
name|text
decl_stmt|;
if|if
condition|(
name|_M_grammar
operator|->
name|start
operator|!=
name|_M_grammar
operator|->
name|names
operator|.
name|end
argument_list|()
condition|)
block|{
name|code
operator|=
name|code
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"$start_id"
argument_list|)
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|std
operator|::
name|distance
argument_list|(
name|_M_grammar
operator|->
name|names
operator|.
name|begin
argument_list|()
argument_list|,
name|_M_grammar
operator|->
name|start
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|code
operator|=
name|code
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"$start"
argument_list|)
argument_list|,
operator|*
name|_M_grammar
operator|->
name|start
argument_list|)
expr_stmt|;
block|}
name|code
operator|=
name|code
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"$header"
argument_list|)
argument_list|,
name|_M_grammar
operator|->
name|table_name
operator|.
name|toLower
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"_p.h"
argument_list|)
argument_list|)
expr_stmt|;
name|code
operator|=
name|code
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"$table"
argument_list|)
argument_list|,
name|_M_grammar
operator|->
name|table_name
argument_list|)
expr_stmt|;
name|code
operator|=
name|code
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"$parser"
argument_list|)
argument_list|,
name|_M_grammar
operator|->
name|table_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|_M_current_rule
operator|!=
name|_M_grammar
operator|->
name|rules
operator|.
name|end
argument_list|()
condition|)
block|{
name|code
operator|=
name|code
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"$rule_number"
argument_list|)
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|std
operator|::
name|distance
argument_list|(
name|_M_grammar
operator|->
name|rules
operator|.
name|begin
argument_list|()
argument_list|,
name|_M_current_rule
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|code
operator|=
name|code
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"$rule"
argument_list|)
argument_list|,
operator|*
name|_M_current_rule
operator|->
name|lhs
argument_list|)
expr_stmt|;
block|}
return|return
name|code
return|;
block|}
end_function
end_unit
