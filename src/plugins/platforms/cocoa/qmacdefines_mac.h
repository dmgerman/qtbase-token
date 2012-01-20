begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Copyright (c) 2007-2008, Apple, Inc. ** ** All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are met: ** **   * Redistributions of source code must retain the above copyright notice, **     this list of conditions and the following disclaimer. ** **   * Redistributions in binary form must reproduce the above copyright notice, **     this list of conditions and the following disclaimer in the documentation **     and/or other materials provided with the distribution. ** **   * Neither the name of Apple, Inc. nor the names of its contributors **     may be used to endorse or promote products derived from this software **     without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR ** CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, ** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, ** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR ** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF ** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING ** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS ** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** ****************************************************************************/
end_comment
begin_comment
comment|/*  *  qmacdefines_mac_p.h  *  All the defines you'll ever need for Qt/Mac :-)  */
end_comment
begin_comment
comment|/* This is just many defines. Therefore it doesn't need things like: QT_BEGIN_HEADER  QT_BEGIN_NAMESPACE  QT_MODULE(Gui)  QT_END_NAMESPACE  QT_END_HEADER  Yes, it is an informative comment ;-) */
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|qDebug
end_ifdef
begin_define
DECL|macro|old_qDebug
define|#
directive|define
name|old_qDebug
value|qDebug
end_define
begin_undef
DECL|macro|qDebug
undef|#
directive|undef
name|qDebug
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef
begin_typedef
DECL|typedef|OSStatus
typedef|typedef
name|signed
name|int
name|OSStatus
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|OSStatus
typedef|typedef
name|signed
name|long
name|OSStatus
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|__OBJC__
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|slots
end_ifdef
begin_define
DECL|macro|old_slots
define|#
directive|define
name|old_slots
value|slots
end_define
begin_undef
DECL|macro|slots
undef|#
directive|undef
name|slots
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|old_slots
end_ifdef
begin_undef
DECL|macro|slots
undef|#
directive|undef
name|slots
end_undef
begin_define
DECL|macro|slots
define|#
directive|define
name|slots
end_define
begin_undef
DECL|macro|old_slots
undef|#
directive|undef
name|old_slots
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|EventHandlerCallRef
typedef|typedef
name|struct
name|OpaqueEventHandlerCallRef
modifier|*
name|EventHandlerCallRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|EventRef
typedef|typedef
name|struct
name|OpaqueEventRef
modifier|*
name|EventRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|MenuRef
typedef|typedef
name|struct
name|OpaqueMenuRef
modifier|*
name|MenuRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|PasteboardRef
typedef|typedef
name|struct
name|OpaquePasteboardRef
modifier|*
name|PasteboardRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|RgnHandle
typedef|typedef
name|struct
name|OpaqueRgnHandle
modifier|*
name|RgnHandle
typedef|;
end_typedef
begin_typedef
DECL|typedef|HIShapeRef
typedef|typedef
specifier|const
name|struct
name|__HIShape
modifier|*
name|HIShapeRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|HIMutableShapeRef
typedef|typedef
name|struct
name|__HIShape
modifier|*
name|HIMutableShapeRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|CGRect
typedef|typedef
name|struct
name|CGRect
name|CGRect
typedef|;
end_typedef
begin_typedef
DECL|typedef|CGImageRef
typedef|typedef
name|struct
name|CGImage
modifier|*
name|CGImageRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|CGContextRef
typedef|typedef
name|struct
name|CGContext
modifier|*
name|CGContextRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|GDPtr
typedef|typedef
name|struct
name|GDevice
modifier|*
name|GDPtr
typedef|;
end_typedef
begin_typedef
DECL|typedef|GDHandle
typedef|typedef
name|GDPtr
modifier|*
name|GDHandle
typedef|;
end_typedef
begin_typedef
DECL|typedef|IconRef
typedef|typedef
name|struct
name|OpaqueIconRef
modifier|*
name|IconRef
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|__OBJC__
end_ifdef
begin_typedef
DECL|typedef|OSWindowRef
typedef|typedef
name|NSWindow
modifier|*
name|OSWindowRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|OSViewRef
typedef|typedef
name|NSView
modifier|*
name|OSViewRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|OSMenuRef
typedef|typedef
name|NSMenu
modifier|*
name|OSMenuRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|OSEventRef
typedef|typedef
name|NSEvent
modifier|*
name|OSEventRef
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|OSWindowRef
typedef|typedef
name|void
modifier|*
name|OSWindowRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|OSViewRef
typedef|typedef
name|void
modifier|*
name|OSViewRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|OSMenuRef
typedef|typedef
name|void
modifier|*
name|OSMenuRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|OSEventRef
typedef|typedef
name|void
modifier|*
name|OSEventRef
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|OSPasteboardRef
typedef|typedef
name|PasteboardRef
name|OSPasteboardRef
typedef|;
end_typedef
begin_typedef
DECL|typedef|AEDescList
typedef|typedef
name|struct
name|AEDesc
name|AEDescList
typedef|;
end_typedef
begin_typedef
DECL|typedef|AERecord
typedef|typedef
name|AEDescList
name|AERecord
typedef|;
end_typedef
begin_typedef
DECL|typedef|AppleEvent
typedef|typedef
name|AERecord
name|AppleEvent
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|check
end_ifdef
begin_undef
DECL|macro|check
undef|#
directive|undef
name|check
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|old_qDebug
end_ifdef
begin_undef
DECL|macro|qDebug
undef|#
directive|undef
name|qDebug
end_undef
begin_define
DECL|macro|qDebug
define|#
directive|define
name|qDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_undef
DECL|macro|old_qDebug
undef|#
directive|undef
name|old_qDebug
end_undef
begin_endif
endif|#
directive|endif
end_endif
end_unit
