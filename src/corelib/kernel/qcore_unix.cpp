begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcore_unix_p.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_NACL
end_ifdef
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_elif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/select.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<selectLib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<mach/mach_time.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_BLACKBERRY
end_ifdef
begin_include
include|#
directive|include
file|<qsocketnotifier.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_BLACKBERRY
end_comment
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|time_update
specifier|static
specifier|inline
name|bool
name|time_update
parameter_list|(
name|struct
name|timespec
modifier|*
name|tv
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|&
name|start
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|&
name|timeout
parameter_list|)
block|{
comment|// clock source is (hopefully) monotonic, so we can recalculate how much timeout is left;
comment|// if it isn't monotonic, we'll simply hope that it hasn't jumped, because we have no alternative
name|struct
name|timespec
name|now
init|=
name|qt_gettime
argument_list|()
decl_stmt|;
operator|*
name|tv
operator|=
name|timeout
operator|+
name|start
operator|-
name|now
expr_stmt|;
return|return
name|tv
operator|->
name|tv_sec
operator|>=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_safe_select
name|int
name|qt_safe_select
parameter_list|(
name|int
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|fdread
parameter_list|,
name|fd_set
modifier|*
name|fdwrite
parameter_list|,
name|fd_set
modifier|*
name|fdexcept
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|orig_timeout
parameter_list|)
block|{
if|if
condition|(
operator|!
name|orig_timeout
condition|)
block|{
comment|// no timeout -> block forever
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|select
argument_list|(
name|nfds
argument_list|,
name|fdread
argument_list|,
name|fdwrite
argument_list|,
name|fdexcept
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
name|timespec
name|start
init|=
name|qt_gettime
argument_list|()
decl_stmt|;
name|timespec
name|timeout
init|=
operator|*
name|orig_timeout
decl_stmt|;
comment|// loop and recalculate the timeout as needed
name|int
name|ret
decl_stmt|;
forever|forever
block|{
ifndef|#
directive|ifndef
name|Q_OS_QNX
name|ret
operator|=
operator|::
name|pselect
argument_list|(
name|nfds
argument_list|,
name|fdread
argument_list|,
name|fdwrite
argument_list|,
name|fdexcept
argument_list|,
operator|&
name|timeout
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|timeval
name|timeoutVal
decl_stmt|;
name|timeoutVal
operator|.
name|tv_sec
operator|=
name|timeout
operator|.
name|tv_sec
expr_stmt|;
name|timeoutVal
operator|.
name|tv_usec
operator|=
name|timeout
operator|.
name|tv_nsec
operator|/
literal|1000
expr_stmt|;
name|ret
operator|=
operator|::
name|select
argument_list|(
name|nfds
argument_list|,
name|fdread
argument_list|,
name|fdwrite
argument_list|,
name|fdexcept
argument_list|,
operator|&
name|timeoutVal
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ret
operator|!=
operator|-
literal|1
operator|||
name|errno
operator|!=
name|EINTR
condition|)
return|return
name|ret
return|;
comment|// recalculate the timeout
if|if
condition|(
operator|!
name|time_update
argument_list|(
operator|&
name|timeout
argument_list|,
name|start
argument_list|,
operator|*
name|orig_timeout
argument_list|)
condition|)
block|{
comment|// timeout during update
comment|// or clock reset, fake timeout error
return|return
literal|0
return|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|qt_select_msecs
name|int
name|qt_select_msecs
parameter_list|(
name|int
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|fdread
parameter_list|,
name|fd_set
modifier|*
name|fdwrite
parameter_list|,
name|int
name|timeout
parameter_list|)
block|{
if|if
condition|(
name|timeout
operator|<
literal|0
condition|)
return|return
name|qt_safe_select
argument_list|(
name|nfds
argument_list|,
name|fdread
argument_list|,
name|fdwrite
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
name|struct
name|timespec
name|tv
decl_stmt|;
name|tv
operator|.
name|tv_sec
operator|=
name|timeout
operator|/
literal|1000
expr_stmt|;
name|tv
operator|.
name|tv_nsec
operator|=
operator|(
name|timeout
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|*
literal|1000
expr_stmt|;
return|return
name|qt_safe_select
argument_list|(
name|nfds
argument_list|,
name|fdread
argument_list|,
name|fdwrite
argument_list|,
literal|0
argument_list|,
operator|&
name|tv
argument_list|)
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_BLACKBERRY
end_ifdef
begin_comment
comment|// The BlackBerry event dispatcher uses bps_get_event. Unfortunately, already registered
end_comment
begin_comment
comment|// socket notifiers are disabled by a call to select. This is to rearm the standard streams.
end_comment
begin_function
DECL|function|bb_select
name|int
name|bb_select
parameter_list|(
name|QList
argument_list|<
name|QSocketNotifier
modifier|*
argument_list|>
name|socketNotifiers
parameter_list|,
name|int
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|fdread
parameter_list|,
name|fd_set
modifier|*
name|fdwrite
parameter_list|,
name|int
name|timeout
parameter_list|)
block|{
name|QList
argument_list|<
name|bool
argument_list|>
name|socketNotifiersEnabled
decl_stmt|;
name|socketNotifiersEnabled
operator|.
name|reserve
argument_list|(
name|socketNotifiers
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|a
operator|<
name|socketNotifiers
operator|.
name|count
argument_list|()
condition|;
operator|++
name|a
control|)
block|{
if|if
condition|(
name|socketNotifiers
operator|.
name|at
argument_list|(
name|a
argument_list|)
operator|&&
name|socketNotifiers
operator|.
name|at
argument_list|(
name|a
argument_list|)
operator|->
name|isEnabled
argument_list|()
condition|)
block|{
name|socketNotifiersEnabled
operator|.
name|append
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|socketNotifiers
operator|.
name|at
argument_list|(
name|a
argument_list|)
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|socketNotifiersEnabled
operator|.
name|append
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
specifier|const
name|int
name|ret
init|=
name|qt_select_msecs
argument_list|(
name|nfds
argument_list|,
name|fdread
argument_list|,
name|fdwrite
argument_list|,
name|timeout
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|a
operator|<
name|socketNotifiers
operator|.
name|count
argument_list|()
condition|;
operator|++
name|a
control|)
block|{
if|if
condition|(
name|socketNotifiersEnabled
operator|.
name|at
argument_list|(
name|a
argument_list|)
operator|==
literal|true
condition|)
name|socketNotifiers
operator|.
name|at
argument_list|(
name|a
argument_list|)
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_BLACKBERRY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
