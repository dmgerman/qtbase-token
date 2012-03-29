begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXEVENTTHREAD_H
end_ifndef
begin_define
DECL|macro|QQNXEVENTTHREAD_H
define|#
directive|define
name|QQNXEVENTTHREAD_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxScreenEventHandler
name|class
name|QQnxScreenEventHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QQnxEventThread
range|:
name|public
name|QThread
block|{
name|public
operator|:
name|QQnxEventThread
argument_list|(
argument|screen_context_t context
argument_list|,
argument|QQnxScreenEventHandler *screenEventHandler
argument_list|)
block|;
name|virtual
operator|~
name|QQnxEventThread
argument_list|()
block|;
specifier|static
name|void
name|injectKeyboardEvent
argument_list|(
argument|int flags
argument_list|,
argument|int sym
argument_list|,
argument|int mod
argument_list|,
argument|int scan
argument_list|,
argument|int cap
argument_list|)
block|;
name|protected
operator|:
name|void
name|run
argument_list|()
block|;
name|private
operator|:
name|void
name|shutdown
argument_list|()
block|;
name|screen_context_t
name|m_screenContext
block|;
name|QQnxScreenEventHandler
operator|*
name|m_screenEventHandler
block|;
name|bool
name|m_quit
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQNXEVENTTHREAD_H
end_comment
end_unit
