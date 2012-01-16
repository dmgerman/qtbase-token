begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPLEXPONG_H
end_ifndef
begin_define
DECL|macro|COMPLEXPONG_H
define|#
directive|define
name|COMPLEXPONG_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusAbstractAdaptor>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusVariant>
end_include
begin_decl_stmt
name|class
name|Pong
range|:
name|public
name|QDBusAbstractAdaptor
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"com.trolltech.QtDBus.ComplexPong.Pong"
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString value READ value WRITE setValue
argument_list|)
name|public
operator|:
name|QString
name|m_value
block|;
name|QString
name|value
argument_list|()
specifier|const
block|;
name|void
name|setValue
argument_list|(
specifier|const
name|QString
operator|&
name|newValue
argument_list|)
block|;
name|Pong
argument_list|(
name|QObject
operator|*
name|obj
argument_list|)
operator|:
name|QDBusAbstractAdaptor
argument_list|(
argument|obj
argument_list|)
block|{ }
name|signals
operator|:
name|void
name|aboutToQuit
argument_list|()
block|;
name|public
name|slots
operator|:
name|QDBusVariant
name|query
argument_list|(
specifier|const
name|QString
operator|&
name|query
argument_list|)
block|;
name|Q_NOREPLY
name|void
name|quit
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
