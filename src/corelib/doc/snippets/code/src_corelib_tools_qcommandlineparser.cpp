begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 David Faure<faure@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qcommandlineparser.h>
end_include
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
modifier|*
name|argv
parameter_list|)
block|{
block|{
name|QCommandLineParser
name|parser
decl_stmt|;
comment|//! [0]
name|bool
name|verbose
init|=
name|parser
operator|.
name|isSet
argument_list|(
literal|"verbose"
argument_list|)
decl_stmt|;
comment|//! [0]
block|}
block|{
comment|//! [1]
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QCommandLineParser
name|parser
decl_stmt|;
name|QCommandLineOption
name|verboseOption
argument_list|(
literal|"verbose"
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|verboseOption
argument_list|)
expr_stmt|;
name|parser
operator|.
name|process
argument_list|(
name|app
argument_list|)
expr_stmt|;
name|bool
name|verbose
init|=
name|parser
operator|.
name|isSet
argument_list|(
name|verboseOption
argument_list|)
decl_stmt|;
comment|//! [1]
block|}
block|{
name|QCommandLineParser
name|parser
decl_stmt|;
comment|//! [2]
comment|// Usage: image-editor file
comment|//
comment|// Arguments:
comment|//   file                  The file to open.
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"file"
argument_list|,
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"main"
argument_list|,
literal|"The file to open."
argument_list|)
argument_list|)
expr_stmt|;
comment|// Usage: web-browser [urls...]
comment|//
comment|// Arguments:
comment|//   urls                URLs to open, optionally.
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"urls"
argument_list|,
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"main"
argument_list|,
literal|"URLs to open, optionally."
argument_list|)
argument_list|,
literal|"[urls...]"
argument_list|)
expr_stmt|;
comment|// Usage: cp source destination
comment|//
comment|// Arguments:
comment|//   source                Source file to copy.
comment|//   destination           Destination directory.
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"source"
argument_list|,
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"main"
argument_list|,
literal|"Source file to copy."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"destination"
argument_list|,
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"main"
argument_list|,
literal|"Destination directory."
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
block|}
block|{
comment|//! [3]
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QCommandLineParser
name|parser
decl_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"command"
argument_list|,
literal|"The command to execute."
argument_list|)
expr_stmt|;
comment|// Call parse() to find out the positional arguments.
name|parser
operator|.
name|parse
argument_list|(
name|QCoreApplication
operator|::
name|arguments
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|args
init|=
name|parser
operator|.
name|positionalArguments
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|command
init|=
name|args
operator|.
name|isEmpty
argument_list|()
condition|?
name|QString
argument_list|()
else|:
name|args
operator|.
name|first
argument_list|()
decl_stmt|;
if|if
condition|(
name|command
operator|==
literal|"resize"
condition|)
block|{
name|parser
operator|.
name|clearPositionalArguments
argument_list|()
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"resize"
argument_list|,
literal|"Resize the object to a new size."
argument_list|,
literal|"resize [resize_options]"
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|QCommandLineOption
argument_list|(
literal|"size"
argument_list|,
literal|"New size."
argument_list|,
literal|"new_size"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|process
argument_list|(
name|app
argument_list|)
expr_stmt|;
comment|// ...
block|}
comment|/* This code results in context-dependent help:  $ tool --help Usage: tool command  Arguments:   command  The command to execute.  $ tool resize --help Usage: tool resize [resize_options]  Options:   --size<size>  New size.  Arguments:   resize         Resize the object to a new size. */
comment|//! [3]
block|}
block|{
comment|//! [4]
name|QCommandLineParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setApplicationDescription
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"main"
argument_list|,
literal|"The best application in the world"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addHelpOption
argument_list|()
expr_stmt|;
comment|//! [4]
block|}
block|}
end_function
end_unit
