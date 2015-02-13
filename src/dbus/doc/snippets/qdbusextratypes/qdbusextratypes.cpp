begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtDBus>
end_include
begin_function
DECL|function|callMyDBusFunction
specifier|static
name|QVariant
name|callMyDBusFunction
parameter_list|()
block|{
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|QDBusMessage
name|myDBusMessage
decl_stmt|;
comment|//! [0]
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
decl_stmt|;
name|arguments
operator|<<
name|QVariant
argument_list|(
literal|42
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QDBusVariant
argument_list|(
literal|43
argument_list|)
argument_list|)
operator|<<
name|QVariant
argument_list|(
literal|"hello"
argument_list|)
expr_stmt|;
name|myDBusMessage
operator|.
name|setArguments
argument_list|(
name|arguments
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
comment|// call a D-Bus function that returns a D-Bus variant
name|QVariant
name|v
init|=
name|callMyDBusFunction
argument_list|()
decl_stmt|;
comment|// retrieve the D-Bus variant
name|QDBusVariant
name|dbusVariant
init|=
name|qvariant_cast
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|(
name|v
argument_list|)
decl_stmt|;
comment|// retrieve the actual value stored in the D-Bus variant
name|QVariant
name|result
init|=
name|dbusVariant
operator|.
name|variant
argument_list|()
decl_stmt|;
comment|//! [1]
return|return
literal|0
return|;
block|}
end_function
end_unit
