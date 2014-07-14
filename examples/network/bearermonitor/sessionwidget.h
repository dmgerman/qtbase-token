begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SESSIONWIDGET_H
end_ifndef
begin_define
DECL|macro|SESSIONWIDGET_H
define|#
directive|define
name|SESSIONWIDGET_H
end_define
begin_include
include|#
directive|include
file|<qnetworksession.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|MAEMO_UI
end_ifdef
begin_include
include|#
directive|include
file|"ui_sessionwidget_maemo.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"ui_sessionwidget.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_USE_NAMESPACE
DECL|variable|QWidget
name|class
name|SessionWidget
range|:
name|public
name|QWidget
decl_stmt|,
name|public
name|Ui_SessionWidget
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|SessionWidget
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|SessionWidget
argument_list|()
expr_stmt|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|private
label|:
name|void
name|updateSessionState
argument_list|(
name|QNetworkSession
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|void
name|clearError
parameter_list|()
function_decl|;
name|private
name|Q_SLOTS
range|:
name|void
name|openSession
argument_list|()
decl_stmt|;
name|void
name|openSyncSession
parameter_list|()
function_decl|;
name|void
name|closeSession
parameter_list|()
function_decl|;
name|void
name|stopSession
parameter_list|()
function_decl|;
name|void
name|updateSession
parameter_list|()
function_decl|;
name|void
name|updateSessionError
argument_list|(
name|QNetworkSession
operator|::
name|SessionError
name|error
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|MAEMO_UI
name|void
name|deleteSession
parameter_list|()
function_decl|;
endif|#
directive|endif
name|private
label|:
name|QNetworkSession
modifier|*
name|session
decl_stmt|;
name|int
name|statsTimer
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
