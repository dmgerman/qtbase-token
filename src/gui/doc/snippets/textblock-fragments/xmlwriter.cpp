begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"xmlwriter.h"
end_include
begin_function
DECL|function|toXml
name|QDomDocument
modifier|*
name|XmlWriter
operator|::
name|toXml
parameter_list|()
block|{
name|QDomImplementation
name|implementation
decl_stmt|;
name|QDomDocumentType
name|docType
init|=
name|implementation
operator|.
name|createDocumentType
argument_list|(
literal|"scribe-document"
argument_list|,
literal|"scribe"
argument_list|,
literal|"qt.nokia.com/scribe"
argument_list|)
decl_stmt|;
name|document
operator|=
operator|new
name|QDomDocument
argument_list|(
name|docType
argument_list|)
expr_stmt|;
comment|// ### This processing instruction is required to ensure that any kind
comment|// of encoding is given when the document is written.
name|QDomProcessingInstruction
name|process
init|=
name|document
operator|->
name|createProcessingInstruction
argument_list|(
literal|"xml"
argument_list|,
literal|"version=\"1.0\" encoding=\"utf-8\""
argument_list|)
decl_stmt|;
name|document
operator|->
name|appendChild
argument_list|(
name|process
argument_list|)
expr_stmt|;
name|QDomElement
name|documentElement
init|=
name|document
operator|->
name|createElement
argument_list|(
literal|"document"
argument_list|)
decl_stmt|;
name|document
operator|->
name|appendChild
argument_list|(
name|documentElement
argument_list|)
expr_stmt|;
comment|//! [0]
name|QTextBlock
name|currentBlock
init|=
name|textDocument
operator|->
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|currentBlock
operator|.
name|isValid
argument_list|()
condition|)
block|{
comment|//! [0]
name|QDomElement
name|blockElement
init|=
name|document
operator|->
name|createElement
argument_list|(
literal|"block"
argument_list|)
decl_stmt|;
name|document
operator|->
name|appendChild
argument_list|(
name|blockElement
argument_list|)
expr_stmt|;
name|readFragment
argument_list|(
name|currentBlock
argument_list|,
name|blockElement
argument_list|,
name|document
argument_list|)
expr_stmt|;
comment|//! [1]
name|processBlock
argument_list|(
name|currentBlock
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|currentBlock
operator|=
name|currentBlock
operator|.
name|next
argument_list|()
expr_stmt|;
block|}
comment|//! [2]
return|return
name|document
return|;
block|}
end_function
begin_function
DECL|function|readFragment
name|void
name|XmlWriter
operator|::
name|readFragment
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|currentBlock
parameter_list|,
name|QDomElement
name|blockElement
parameter_list|,
name|QDomDocument
modifier|*
name|document
parameter_list|)
block|{
comment|//! [3] //! [4]
name|QTextBlock
operator|::
name|iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|currentBlock
operator|.
name|begin
argument_list|()
init|;
operator|!
operator|(
name|it
operator|.
name|atEnd
argument_list|()
operator|)
condition|;
operator|++
name|it
control|)
block|{
name|QTextFragment
name|currentFragment
init|=
name|it
operator|.
name|fragment
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentFragment
operator|.
name|isValid
argument_list|()
condition|)
comment|//! [3] //! [5]
name|processFragment
argument_list|(
name|currentFragment
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
if|if
condition|(
name|currentFragment
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QDomElement
name|fragmentElement
init|=
name|document
operator|->
name|createElement
argument_list|(
literal|"fragment"
argument_list|)
decl_stmt|;
name|blockElement
operator|.
name|appendChild
argument_list|(
name|fragmentElement
argument_list|)
expr_stmt|;
name|fragmentElement
operator|.
name|setAttribute
argument_list|(
literal|"length"
argument_list|,
name|currentFragment
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|QDomText
name|fragmentText
init|=
name|document
operator|->
name|createTextNode
argument_list|(
name|currentFragment
operator|.
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|fragmentElement
operator|.
name|appendChild
argument_list|(
name|fragmentText
argument_list|)
expr_stmt|;
block|}
comment|//! [6] //! [7]
block|}
comment|//! [7] //! [6]
block|}
end_function
begin_function
DECL|function|processBlock
name|void
name|XmlWriter
operator|::
name|processBlock
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|currentBlock
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|processFragment
name|void
name|XmlWriter
operator|::
name|processFragment
parameter_list|(
specifier|const
name|QTextFragment
modifier|&
name|currentFragment
parameter_list|)
block|{ }
end_function
end_unit
