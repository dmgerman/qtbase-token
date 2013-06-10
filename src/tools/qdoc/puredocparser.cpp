begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   puredocparser.cpp */
end_comment
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|"codechunk.h"
end_include
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_include
include|#
directive|include
file|"tokenizer.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qdocdatabase.h"
end_include
begin_include
include|#
directive|include
file|"puredocparser.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!   Constructs the pure doc parser. */
DECL|function|PureDocParser
name|PureDocParser
operator|::
name|PureDocParser
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!   Destroys the pure doc parser.  */
end_comment
begin_destructor
DECL|function|~PureDocParser
name|PureDocParser
operator|::
name|~
name|PureDocParser
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns a list of the kinds of files that the pure doc   parser is meant to parse. The elements of the list are   file suffixes.  */
end_comment
begin_function
DECL|function|sourceFileNameFilter
name|QStringList
name|PureDocParser
operator|::
name|sourceFileNameFilter
parameter_list|()
block|{
return|return
name|QStringList
argument_list|()
operator|<<
literal|"*.qdoc"
operator|<<
literal|"*.qtx"
operator|<<
literal|"*.qtt"
operator|<<
literal|"*.js"
return|;
block|}
end_function
begin_comment
comment|/*!   Parses the source file identified by \a filePath and adds its   parsed contents to the database. The \a location is used for   reporting errors.  */
end_comment
begin_function
DECL|function|parseSourceFile
name|void
name|PureDocParser
operator|::
name|parseSourceFile
parameter_list|(
specifier|const
name|Location
modifier|&
name|location
parameter_list|,
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
block|{
name|QFile
name|in
argument_list|(
name|filePath
argument_list|)
decl_stmt|;
name|currentFile_
operator|=
name|filePath
expr_stmt|;
if|if
condition|(
operator|!
name|in
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|location
operator|.
name|error
argument_list|(
name|tr
argument_list|(
literal|"Can't open source file '%1' (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|filePath
argument_list|)
operator|.
name|arg
argument_list|(
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|currentFile_
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return;
block|}
name|reset
argument_list|()
expr_stmt|;
name|Location
name|fileLocation
argument_list|(
name|filePath
argument_list|)
decl_stmt|;
name|Tokenizer
name|fileTokenizer
argument_list|(
name|fileLocation
argument_list|,
name|in
argument_list|)
decl_stmt|;
name|tokenizer
operator|=
operator|&
name|fileTokenizer
expr_stmt|;
name|readToken
argument_list|()
expr_stmt|;
comment|/*       The set of open namespaces is cleared before parsing       each source file. The word "source" here means cpp file.      */
name|qdb_
operator|->
name|clearOpenNamespaces
argument_list|()
expr_stmt|;
name|processQdocComments
argument_list|()
expr_stmt|;
name|in
operator|.
name|close
argument_list|()
expr_stmt|;
name|currentFile_
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   This is called by parseSourceFile() to do the actual parsing   and tree building. It only processes qdoc comments. It skips   everything else.  */
end_comment
begin_function
DECL|function|processQdocComments
name|bool
name|PureDocParser
operator|::
name|processQdocComments
parameter_list|()
block|{
name|QSet
argument_list|<
name|QString
argument_list|>
name|topicCommandsAllowed
init|=
name|topicCommands
argument_list|()
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|otherMetacommandsAllowed
init|=
name|otherMetaCommands
argument_list|()
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|metacommandsAllowed
init|=
name|topicCommandsAllowed
operator|+
name|otherMetacommandsAllowed
decl_stmt|;
while|while
condition|(
name|tok
operator|!=
name|Tok_Eoi
condition|)
block|{
if|if
condition|(
name|tok
operator|==
name|Tok_Doc
condition|)
block|{
comment|/*               lexeme() returns an entire qdoc comment.              */
name|QString
name|comment
init|=
name|lexeme
argument_list|()
decl_stmt|;
name|Location
name|start_loc
argument_list|(
name|location
argument_list|()
argument_list|)
decl_stmt|;
name|readToken
argument_list|()
expr_stmt|;
name|Doc
operator|::
name|trimCStyleComment
argument_list|(
name|start_loc
argument_list|,
name|comment
argument_list|)
expr_stmt|;
name|Location
name|end_loc
argument_list|(
name|location
argument_list|()
argument_list|)
decl_stmt|;
comment|/*               Doc parses the comment.              */
name|Doc
name|doc
argument_list|(
name|start_loc
argument_list|,
name|end_loc
argument_list|,
name|comment
argument_list|,
name|metacommandsAllowed
argument_list|)
decl_stmt|;
name|QString
name|topic
decl_stmt|;
name|ArgList
name|args
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|topicCommandsUsed
init|=
name|topicCommandsAllowed
operator|&
name|doc
operator|.
name|metaCommandsUsed
argument_list|()
decl_stmt|;
comment|/*               There should be one topic command in the set,               or none. If the set is empty, then the comment               should be a function description.              */
if|if
condition|(
name|topicCommandsUsed
operator|.
name|count
argument_list|()
operator|>
literal|0
condition|)
block|{
name|topic
operator|=
operator|*
name|topicCommandsUsed
operator|.
name|begin
argument_list|()
expr_stmt|;
name|args
operator|=
name|doc
operator|.
name|metaCommandArgs
argument_list|(
name|topic
argument_list|)
expr_stmt|;
block|}
name|NodeList
name|nodes
decl_stmt|;
name|QList
argument_list|<
name|Doc
argument_list|>
name|docs
decl_stmt|;
if|if
condition|(
name|topic
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|doc
operator|.
name|location
argument_list|()
operator|.
name|warning
argument_list|(
name|tr
argument_list|(
literal|"This qdoc comment contains no topic command "
literal|"(e.g., '\\%1', '\\%2')."
argument_list|)
operator|.
name|arg
argument_list|(
name|COMMAND_MODULE
argument_list|)
operator|.
name|arg
argument_list|(
name|COMMAND_PAGE
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/*                   There is a topic command. Process it.                  */
if|if
condition|(
operator|(
name|topic
operator|==
name|COMMAND_QMLPROPERTY
operator|)
operator|||
operator|(
name|topic
operator|==
name|COMMAND_QMLATTACHEDPROPERTY
operator|)
condition|)
block|{
name|Doc
name|nodeDoc
init|=
name|doc
decl_stmt|;
name|Node
modifier|*
name|node
init|=
name|processTopicCommandGroup
argument_list|(
name|nodeDoc
argument_list|,
name|topic
argument_list|,
name|args
argument_list|)
decl_stmt|;
if|if
condition|(
name|node
operator|!=
literal|0
condition|)
block|{
name|nodes
operator|.
name|append
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|docs
operator|.
name|append
argument_list|(
name|nodeDoc
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|ArgList
operator|::
name|ConstIterator
name|a
init|=
name|args
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|a
operator|!=
name|args
operator|.
name|end
argument_list|()
condition|)
block|{
name|Doc
name|nodeDoc
init|=
name|doc
decl_stmt|;
name|Node
modifier|*
name|node
init|=
name|processTopicCommand
argument_list|(
name|nodeDoc
argument_list|,
name|topic
argument_list|,
operator|*
name|a
argument_list|)
decl_stmt|;
if|if
condition|(
name|node
operator|!=
literal|0
condition|)
block|{
name|nodes
operator|.
name|append
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|docs
operator|.
name|append
argument_list|(
name|nodeDoc
argument_list|)
expr_stmt|;
block|}
operator|++
name|a
expr_stmt|;
block|}
block|}
block|}
name|Node
modifier|*
name|treeRoot
init|=
name|QDocDatabase
operator|::
name|qdocDB
argument_list|()
operator|->
name|treeRoot
argument_list|()
decl_stmt|;
name|NodeList
operator|::
name|Iterator
name|n
init|=
name|nodes
operator|.
name|begin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|Doc
argument_list|>
operator|::
name|Iterator
name|d
init|=
name|docs
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|n
operator|!=
name|nodes
operator|.
name|end
argument_list|()
condition|)
block|{
name|processOtherMetaCommands
argument_list|(
operator|*
name|d
argument_list|,
operator|*
name|n
argument_list|)
expr_stmt|;
operator|(
operator|*
name|n
operator|)
operator|->
name|setDoc
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
name|checkModuleInclusion
argument_list|(
operator|*
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|n
operator|)
operator|->
name|isInnerNode
argument_list|()
operator|&&
operator|(
operator|(
name|InnerNode
operator|*
operator|)
operator|*
name|n
operator|)
operator|->
name|includes
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|InnerNode
modifier|*
name|m
init|=
cast|static_cast
argument_list|<
name|InnerNode
operator|*
argument_list|>
argument_list|(
operator|*
name|n
argument_list|)
decl_stmt|;
while|while
condition|(
name|m
operator|->
name|parent
argument_list|()
operator|&&
name|m
operator|->
name|parent
argument_list|()
operator|!=
name|treeRoot
condition|)
name|m
operator|=
name|m
operator|->
name|parent
argument_list|()
expr_stmt|;
if|if
condition|(
name|m
operator|==
operator|*
name|n
condition|)
operator|(
operator|(
name|InnerNode
operator|*
operator|)
operator|*
name|n
operator|)
operator|->
name|addInclude
argument_list|(
operator|(
operator|*
name|n
operator|)
operator|->
name|name
argument_list|()
argument_list|)
expr_stmt|;
else|else
operator|(
operator|(
name|InnerNode
operator|*
operator|)
operator|*
name|n
operator|)
operator|->
name|setIncludes
argument_list|(
name|m
operator|->
name|includes
argument_list|()
argument_list|)
expr_stmt|;
block|}
operator|++
name|d
expr_stmt|;
operator|++
name|n
expr_stmt|;
block|}
block|}
else|else
block|{
name|readToken
argument_list|()
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
