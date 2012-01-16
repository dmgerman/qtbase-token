begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QScreenDriverPlugin>
end_include
begin_include
include|#
directive|include
file|"dbscreen.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|DBScreenDriverPlugin
class|class
name|DBScreenDriverPlugin
super|:
specifier|public
name|QScreenDriverPlugin
block|{
public|public:
name|DBScreenDriverPlugin
parameter_list|()
constructor_decl|;
name|QScreen
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|int
name|displayId
parameter_list|)
function_decl|;
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DBScreenDriverPlugin
name|DBScreenDriverPlugin
operator|::
name|DBScreenDriverPlugin
parameter_list|()
member_init_list|:
name|QScreenDriverPlugin
argument_list|()
block|{ }
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|create
name|QScreen
modifier|*
name|DBScreenDriverPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|int
name|displayId
parameter_list|)
block|{
if|if
condition|(
name|key
operator|.
name|toLower
argument_list|()
operator|!=
literal|"dbscreen"
condition|)
return|return
literal|0
return|;
return|return
operator|new
name|DBScreen
argument_list|(
name|displayId
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|keys
name|QStringList
name|DBScreenDriverPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
literal|"dbscreen"
return|;
block|}
end_function
begin_comment
comment|//! [2] //! [3]
end_comment
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|dbscreen
argument_list|,
argument|DBScreenDriverPlugin
argument_list|)
end_macro
begin_comment
comment|//! [3]
end_comment
end_unit
