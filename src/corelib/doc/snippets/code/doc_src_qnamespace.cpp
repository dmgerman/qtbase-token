begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [1]
end_comment
begin_enum
DECL|enum|CustomEventPriority
enum|enum
name|CustomEventPriority
block|{
comment|// An important event
DECL|enumerator|ImportantEventPriority
name|ImportantEventPriority
init|=
name|Qt
operator|::
name|HighEventPriority
block|,
comment|// A more important event
DECL|enumerator|MoreImportantEventPriority
name|MoreImportantEventPriority
init|=
name|ImportantEventPriority
operator|+
literal|1
block|,
comment|// A critical event
DECL|enumerator|CriticalEventPriority
name|CriticalEventPriority
init|=
literal|100
operator|*
name|MoreImportantEventPriority
block|,
comment|// Not that important
DECL|enumerator|StatusEventPriority
name|StatusEventPriority
init|=
name|Qt
operator|::
name|LowEventPriority
block|,
comment|// These are less important than Status events
DECL|enumerator|IdleProcessingDoneEventPriority
name|IdleProcessingDoneEventPriority
init|=
name|StatusEventPriority
operator|-
literal|1
block|}
enum|;
end_enum
begin_comment
comment|//! [1]
end_comment
end_unit
