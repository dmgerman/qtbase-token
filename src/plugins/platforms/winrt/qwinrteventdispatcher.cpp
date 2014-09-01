begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWinRTEventDispatcher
name|QWinRTEventDispatcher
operator|::
name|QWinRTEventDispatcher
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QEventDispatcherWinRT
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|hasPendingEvents
name|bool
name|QWinRTEventDispatcher
operator|::
name|hasPendingEvents
parameter_list|()
block|{
return|return
name|QEventDispatcherWinRT
operator|::
name|hasPendingEvents
argument_list|()
operator|||
name|QWindowSystemInterface
operator|::
name|windowSystemEventsQueued
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|sendPostedEvents
name|bool
name|QWinRTEventDispatcher
operator|::
name|sendPostedEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|bool
name|didProcess
init|=
name|QEventDispatcherWinRT
operator|::
name|sendPostedEvents
argument_list|(
name|flags
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
operator|)
condition|)
name|didProcess
operator||=
name|QWindowSystemInterface
operator|::
name|sendWindowSystemEvents
argument_list|(
name|flags
argument_list|)
expr_stmt|;
return|return
name|didProcess
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
