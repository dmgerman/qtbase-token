begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"object.h"
end_include
begin_constructor
DECL|function|Object
name|Object
operator|::
name|Object
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|print
name|void
name|Object
operator|::
name|print
parameter_list|()
block|{
name|int
name|numberOfPages
init|=
literal|10
decl_stmt|;
name|int
name|lastPage
init|=
name|numberOfPages
operator|-
literal|1
decl_stmt|;
comment|//! [0]
name|QPrinter
name|printer
argument_list|(
name|QPrinter
operator|::
name|HighResolution
argument_list|)
decl_stmt|;
name|printer
operator|.
name|setOutputFileName
argument_list|(
literal|"print.ps"
argument_list|)
expr_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|page
init|=
literal|0
init|;
name|page
operator|<
name|numberOfPages
condition|;
operator|++
name|page
control|)
block|{
comment|// Use the painter to draw on the page.
if|if
condition|(
name|page
operator|!=
name|lastPage
condition|)
name|printer
operator|.
name|newPage
argument_list|()
expr_stmt|;
block|}
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
comment|//! [0]
name|qApp
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
