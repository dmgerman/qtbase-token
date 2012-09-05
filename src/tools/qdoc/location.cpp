begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_include
include|#
directive|include
file|"location.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|null
name|QT_STATIC_CONST_IMPL
name|Location
name|Location
operator|::
name|null
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|tabSize
name|int
name|Location
operator|::
name|tabSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|programName
name|QString
name|Location
operator|::
name|programName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|spuriousRegExp
name|QRegExp
modifier|*
name|Location
operator|::
name|spuriousRegExp
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   \class Location    \brief The Location class provides a way to mark a location in a file.    It maintains a stack of file positions. A file position   consists of the file path, line number, and column number.   The location is used for printing error messages that are   tied to a location in a file.  */
end_comment
begin_comment
comment|/*!   Constructs an empty location.  */
end_comment
begin_constructor
DECL|function|Location
name|Location
operator|::
name|Location
parameter_list|()
member_init_list|:
name|stk
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|stkTop
argument_list|(
operator|&
name|stkBottom
argument_list|)
member_init_list|,
name|stkDepth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|etcetera
argument_list|(
literal|false
argument_list|)
block|{
comment|// nothing.
block|}
end_constructor
begin_comment
comment|/*!   Constructs a location with (fileName, 1, 1) on its file   position stack.  */
end_comment
begin_constructor
DECL|function|Location
name|Location
operator|::
name|Location
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
member_init_list|:
name|stk
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|stkTop
argument_list|(
operator|&
name|stkBottom
argument_list|)
member_init_list|,
name|stkDepth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|etcetera
argument_list|(
literal|false
argument_list|)
block|{
name|push
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   The copy constructor copies the contents of \a other into   this Location using the assignment operator.  */
end_comment
begin_constructor
DECL|function|Location
name|Location
operator|::
name|Location
parameter_list|(
specifier|const
name|Location
modifier|&
name|other
parameter_list|)
member_init_list|:
name|stk
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|stkTop
argument_list|(
operator|&
name|stkBottom
argument_list|)
member_init_list|,
name|stkDepth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|etcetera
argument_list|(
literal|false
argument_list|)
block|{
operator|*
name|this
operator|=
name|other
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   The assignment operator does a deep copy of the entire   state of \a other into this Location.  */
end_comment
begin_function
DECL|function|operator =
name|Location
modifier|&
name|Location
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|Location
modifier|&
name|other
parameter_list|)
block|{
name|QStack
argument_list|<
name|StackEntry
argument_list|>
modifier|*
name|oldStk
init|=
name|stk
decl_stmt|;
name|stkBottom
operator|=
name|other
operator|.
name|stkBottom
expr_stmt|;
if|if
condition|(
name|other
operator|.
name|stk
operator|==
literal|0
condition|)
block|{
name|stk
operator|=
literal|0
expr_stmt|;
name|stkTop
operator|=
operator|&
name|stkBottom
expr_stmt|;
block|}
else|else
block|{
name|stk
operator|=
operator|new
name|QStack
argument_list|<
name|StackEntry
argument_list|>
argument_list|(
operator|*
name|other
operator|.
name|stk
argument_list|)
expr_stmt|;
name|stkTop
operator|=
operator|&
name|stk
operator|->
name|top
argument_list|()
expr_stmt|;
block|}
name|stkDepth
operator|=
name|other
operator|.
name|stkDepth
expr_stmt|;
name|etcetera
operator|=
name|other
operator|.
name|etcetera
expr_stmt|;
operator|delete
name|oldStk
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!   If the file position on top of the stack has a line number   less than 1, set its line number to 1 and its column number   to 1. Otherwise, do nothing.   */
end_comment
begin_function
DECL|function|start
name|void
name|Location
operator|::
name|start
parameter_list|()
block|{
if|if
condition|(
name|stkTop
operator|->
name|lineNo
operator|<
literal|1
condition|)
block|{
name|stkTop
operator|->
name|lineNo
operator|=
literal|1
expr_stmt|;
name|stkTop
operator|->
name|columnNo
operator|=
literal|1
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   Advance the current file position, using \a ch to decide how to do   that. If \a ch is a \c{'\\n'}, increment the current line number and   set the column number to 1. If \ch is a \c{'\\t'}, increment to the   next tab column. Otherwise, increment the column number by 1.    The current file position is the one on top of the position stack.  */
end_comment
begin_function
DECL|function|advance
name|void
name|Location
operator|::
name|advance
parameter_list|(
name|QChar
name|ch
parameter_list|)
block|{
if|if
condition|(
name|ch
operator|==
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
condition|)
block|{
name|stkTop
operator|->
name|lineNo
operator|++
expr_stmt|;
name|stkTop
operator|->
name|columnNo
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ch
operator|==
name|QLatin1Char
argument_list|(
literal|'\t'
argument_list|)
condition|)
block|{
name|stkTop
operator|->
name|columnNo
operator|=
literal|1
operator|+
name|tabSize
operator|*
operator|(
name|stkTop
operator|->
name|columnNo
operator|+
name|tabSize
operator|-
literal|1
operator|)
operator|/
name|tabSize
expr_stmt|;
block|}
else|else
block|{
name|stkTop
operator|->
name|columnNo
operator|++
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   Pushes \a filePath onto the file position stack. The current   file position becomes (\a filePath, 1, 1).    \sa pop() */
end_comment
begin_function
DECL|function|push
name|void
name|Location
operator|::
name|push
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
block|{
if|if
condition|(
name|stkDepth
operator|++
operator|>=
literal|1
condition|)
block|{
if|if
condition|(
name|stk
operator|==
literal|0
condition|)
name|stk
operator|=
operator|new
name|QStack
argument_list|<
name|StackEntry
argument_list|>
expr_stmt|;
name|stk
operator|->
name|push
argument_list|(
name|StackEntry
argument_list|()
argument_list|)
expr_stmt|;
name|stkTop
operator|=
operator|&
name|stk
operator|->
name|top
argument_list|()
expr_stmt|;
block|}
name|stkTop
operator|->
name|filePath
operator|=
name|filePath
expr_stmt|;
name|stkTop
operator|->
name|lineNo
operator|=
name|INT_MIN
expr_stmt|;
name|stkTop
operator|->
name|columnNo
operator|=
literal|1
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Pops the top of the internal stack. The current file position   becomes the next one in the new top of stack.    \sa push() */
end_comment
begin_function
DECL|function|pop
name|void
name|Location
operator|::
name|pop
parameter_list|()
block|{
if|if
condition|(
operator|--
name|stkDepth
operator|==
literal|0
condition|)
block|{
name|stkBottom
operator|=
name|StackEntry
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|stk
operator|->
name|pop
argument_list|()
expr_stmt|;
if|if
condition|(
name|stk
operator|->
name|isEmpty
argument_list|()
condition|)
block|{
operator|delete
name|stk
expr_stmt|;
name|stk
operator|=
literal|0
expr_stmt|;
name|stkTop
operator|=
operator|&
name|stkBottom
expr_stmt|;
block|}
else|else
block|{
name|stkTop
operator|=
operator|&
name|stk
operator|->
name|top
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*! \fn bool Location::isEmpty() const    Returns true if there is no file name set yet; returns false   otherwise. The functions filePath(), lineNo() and columnNo()   must not be called on an empty Location object.  */
end_comment
begin_comment
comment|/*! \fn const QString& Location::filePath() const   Returns the current path and file name.   Must not be called on an empty Location object.    \sa lineNo(), columnNo()  */
end_comment
begin_comment
comment|/*!   Returns the file name part of the file path, ie the   current file.  Must not be called on an empty Location   object.  */
end_comment
begin_function
DECL|function|fileName
name|QString
name|Location
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
name|QString
name|fp
init|=
name|filePath
argument_list|()
decl_stmt|;
return|return
name|fp
operator|.
name|mid
argument_list|(
name|fp
operator|.
name|lastIndexOf
argument_list|(
literal|'/'
argument_list|)
operator|+
literal|1
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!  * \brief  Returns \a path which is canonicalized and relative to the config file.  *  *         QDir::relativeFilePath does not canonicalize the paths, so  *         if the config file is located at qtbase\src\widgets\doc\qtwidgets.qdocconf  *         and it has a reference to any ancestor folder (e.g. ".." or even "../doc")  * \param path  * \return  */
end_comment
begin_function
DECL|function|canonicalRelativePath
name|QString
name|Location
operator|::
name|canonicalRelativePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
specifier|const
block|{
name|QDir
name|configFileDir
argument_list|(
name|QFileInfo
argument_list|(
name|filePath
argument_list|()
argument_list|)
operator|.
name|dir
argument_list|()
argument_list|)
decl_stmt|;
name|QDir
name|dir
argument_list|(
name|path
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|canon
init|=
name|dir
operator|.
name|canonicalPath
argument_list|()
decl_stmt|;
return|return
name|configFileDir
operator|.
name|relativeFilePath
argument_list|(
name|canon
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \fn int Location::lineNo() const   Returns the current line number.   Must not be called on an empty Location object.    \sa filePath(), columnNo() */
end_comment
begin_comment
comment|/*! \fn int Location::columnNo() const   Returns the current column number.   Must not be called on an empty Location object.    \sa filePath(), lineNo() */
end_comment
begin_comment
comment|/*!   Writes \a message and \a detals to stderr as a formatted   warning message.  */
end_comment
begin_function
DECL|function|warning
name|void
name|Location
operator|::
name|warning
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|details
parameter_list|)
specifier|const
block|{
name|emitMessage
argument_list|(
name|Warning
argument_list|,
name|message
argument_list|,
name|details
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Writes \a message and \a detals to stderr as a formatted   error message.  */
end_comment
begin_function
DECL|function|error
name|void
name|Location
operator|::
name|error
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|details
parameter_list|)
specifier|const
block|{
name|emitMessage
argument_list|(
name|Error
argument_list|,
name|message
argument_list|,
name|details
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Writes \a message and \a detals to stderr as a formatted   error message and then exits the program.  */
end_comment
begin_function
DECL|function|fatal
name|void
name|Location
operator|::
name|fatal
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|details
parameter_list|)
specifier|const
block|{
name|emitMessage
argument_list|(
name|Error
argument_list|,
name|message
argument_list|,
name|details
argument_list|)
expr_stmt|;
name|information
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|information
argument_list|(
name|details
argument_list|)
expr_stmt|;
name|information
argument_list|(
literal|"Aborting"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Gets several parameters from the \a config, including   tab size, program name, and a regular expression that   appears to be used for matching certain error messages   so that emitMessage() can avoid printing them.  */
end_comment
begin_function
DECL|function|initialize
name|void
name|Location
operator|::
name|initialize
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
block|{
name|tabSize
operator|=
name|config
operator|.
name|getInt
argument_list|(
name|CONFIG_TABSIZE
argument_list|)
expr_stmt|;
name|programName
operator|=
name|config
operator|.
name|programName
argument_list|()
expr_stmt|;
name|QRegExp
name|regExp
init|=
name|config
operator|.
name|getRegExp
argument_list|(
name|CONFIG_SPURIOUS
argument_list|)
decl_stmt|;
if|if
condition|(
name|regExp
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|spuriousRegExp
operator|=
operator|new
name|QRegExp
argument_list|(
name|regExp
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|config
operator|.
name|lastLocation
argument_list|()
operator|.
name|warning
argument_list|(
name|tr
argument_list|(
literal|"Invalid regular expression '%1'"
argument_list|)
operator|.
name|arg
argument_list|(
name|regExp
operator|.
name|pattern
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   Apparently, all this does is delete the regular expression   used for intercepting certain error messages that should   not be emitted by emitMessage().  */
end_comment
begin_function
DECL|function|terminate
name|void
name|Location
operator|::
name|terminate
parameter_list|()
block|{
operator|delete
name|spuriousRegExp
expr_stmt|;
name|spuriousRegExp
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Prints \a message to \c stdout followed by a \c{'\n'}.  */
end_comment
begin_function
DECL|function|information
name|void
name|Location
operator|::
name|information
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|message
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Report a program bug, including the \a hint.  */
end_comment
begin_function
DECL|function|internalError
name|void
name|Location
operator|::
name|internalError
parameter_list|(
specifier|const
name|QString
modifier|&
name|hint
parameter_list|)
block|{
name|Location
operator|::
name|null
operator|.
name|fatal
argument_list|(
name|tr
argument_list|(
literal|"Internal error (%1)"
argument_list|)
operator|.
name|arg
argument_list|(
name|hint
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"There is a bug in %1. Seek advice from your local"
literal|" %2 guru."
argument_list|)
operator|.
name|arg
argument_list|(
name|programName
argument_list|)
operator|.
name|arg
argument_list|(
name|programName
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Formats \a message and \a details into a single string   and outputs that string to \c stderr. \a type specifies   whether the \a message is an error or a warning.  */
end_comment
begin_function
DECL|function|emitMessage
name|void
name|Location
operator|::
name|emitMessage
parameter_list|(
name|MessageType
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|details
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|type
operator|==
name|Warning
operator|&&
name|spuriousRegExp
operator|!=
literal|0
operator|&&
name|spuriousRegExp
operator|->
name|exactMatch
argument_list|(
name|message
argument_list|)
condition|)
return|return;
name|QString
name|result
init|=
name|message
decl_stmt|;
if|if
condition|(
operator|!
name|details
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|+=
literal|"\n["
operator|+
name|details
operator|+
name|QLatin1Char
argument_list|(
literal|']'
argument_list|)
expr_stmt|;
name|result
operator|.
name|replace
argument_list|(
literal|"\n"
argument_list|,
literal|"\n    "
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|Error
condition|)
name|result
operator|.
name|prepend
argument_list|(
name|tr
argument_list|(
literal|"error: "
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|prepend
argument_list|(
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|result
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Converts the location to a string to be prepended to error   messages.  */
end_comment
begin_function
DECL|function|toString
name|QString
name|Location
operator|::
name|toString
parameter_list|()
specifier|const
block|{
name|QString
name|str
decl_stmt|;
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
block|{
name|str
operator|=
name|programName
expr_stmt|;
block|}
else|else
block|{
name|Location
name|loc2
init|=
operator|*
name|this
decl_stmt|;
name|loc2
operator|.
name|setEtc
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|loc2
operator|.
name|pop
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|loc2
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|blah
init|=
name|tr
argument_list|(
literal|"In file included from "
argument_list|)
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|str
operator|+=
name|blah
expr_stmt|;
name|str
operator|+=
name|loc2
operator|.
name|top
argument_list|()
expr_stmt|;
name|loc2
operator|.
name|pop
argument_list|()
expr_stmt|;
if|if
condition|(
name|loc2
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
name|str
operator|+=
name|tr
argument_list|(
literal|","
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|blah
operator|.
name|fill
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
name|str
operator|+=
name|tr
argument_list|(
literal|":"
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
name|str
operator|+=
name|top
argument_list|()
expr_stmt|;
block|}
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|": "
argument_list|)
expr_stmt|;
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|top
name|QString
name|Location
operator|::
name|top
parameter_list|()
specifier|const
block|{
name|QString
name|str
init|=
name|filePath
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QDir
operator|::
name|isAbsolutePath
argument_list|(
name|str
argument_list|)
condition|)
block|{
name|QDir
name|path
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|str
operator|=
name|path
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|lineNo
argument_list|()
operator|>=
literal|1
condition|)
block|{
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|lineNo
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|etc
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" (etc.)"
argument_list|)
expr_stmt|;
return|return
name|str
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
