begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|closeEvent
name|void
name|MyMainWindow
operator|::
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QSettings
name|settings
argument_list|(
literal|"MyCompany"
argument_list|,
literal|"MyApp"
argument_list|)
decl_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"geometry"
argument_list|,
name|saveGeometry
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"windowState"
argument_list|,
name|saveState
argument_list|()
argument_list|)
expr_stmt|;
name|QMainWindow
operator|::
name|closeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|readSettings
name|void
name|MainWindow
operator|::
name|readSettings
parameter_list|()
block|{
name|QSettings
name|settings
argument_list|(
literal|"MyCompany"
argument_list|,
literal|"MyApp"
argument_list|)
decl_stmt|;
name|restoreGeometry
argument_list|(
name|settings
operator|.
name|value
argument_list|(
literal|"myWidget/geometry"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|restoreState
argument_list|(
name|settings
operator|.
name|value
argument_list|(
literal|"myWidget/windowState"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
end_unit
