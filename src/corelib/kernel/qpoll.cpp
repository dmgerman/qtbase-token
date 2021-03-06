begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcore_unix_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|macro|QT_POLL_READ_MASK
define|#
directive|define
name|QT_POLL_READ_MASK
value|(POLLIN | POLLRDNORM)
DECL|macro|QT_POLL_WRITE_MASK
define|#
directive|define
name|QT_POLL_WRITE_MASK
value|(POLLOUT | POLLWRNORM | POLLWRBAND)
DECL|macro|QT_POLL_EXCEPT_MASK
define|#
directive|define
name|QT_POLL_EXCEPT_MASK
value|(POLLPRI | POLLRDBAND)
DECL|macro|QT_POLL_ERROR_MASK
define|#
directive|define
name|QT_POLL_ERROR_MASK
value|(POLLERR | POLLNVAL)
DECL|macro|QT_POLL_EVENTS_MASK
define|#
directive|define
name|QT_POLL_EVENTS_MASK
value|(QT_POLL_READ_MASK | QT_POLL_WRITE_MASK | QT_POLL_EXCEPT_MASK)
DECL|function|qt_poll_prepare
specifier|static
specifier|inline
name|int
name|qt_poll_prepare
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fds
parameter_list|,
name|nfds_t
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|read_fds
parameter_list|,
name|fd_set
modifier|*
name|write_fds
parameter_list|,
name|fd_set
modifier|*
name|except_fds
parameter_list|)
block|{
name|int
name|max_fd
init|=
operator|-
literal|1
decl_stmt|;
name|FD_ZERO
argument_list|(
name|read_fds
argument_list|)
expr_stmt|;
name|FD_ZERO
argument_list|(
name|write_fds
argument_list|)
expr_stmt|;
name|FD_ZERO
argument_list|(
name|except_fds
argument_list|)
expr_stmt|;
for|for
control|(
name|nfds_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|nfds
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
operator|>=
name|FD_SETSIZE
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
operator|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
operator|<
literal|0
operator|)
operator|||
operator|(
name|fds
index|[
name|i
index|]
operator|.
name|revents
operator|&
name|QT_POLL_ERROR_MASK
operator|)
condition|)
continue|continue;
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|events
operator|&
name|QT_POLL_READ_MASK
condition|)
name|FD_SET
argument_list|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|,
name|read_fds
argument_list|)
expr_stmt|;
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|events
operator|&
name|QT_POLL_WRITE_MASK
condition|)
name|FD_SET
argument_list|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|,
name|write_fds
argument_list|)
expr_stmt|;
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|events
operator|&
name|QT_POLL_EXCEPT_MASK
condition|)
name|FD_SET
argument_list|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|,
name|except_fds
argument_list|)
expr_stmt|;
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|events
operator|&
name|QT_POLL_EVENTS_MASK
condition|)
name|max_fd
operator|=
name|qMax
argument_list|(
name|max_fd
argument_list|,
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|)
expr_stmt|;
block|}
return|return
name|max_fd
operator|+
literal|1
return|;
block|}
end_function
begin_function
DECL|function|qt_poll_examine_ready_read
specifier|static
specifier|inline
name|void
name|qt_poll_examine_ready_read
parameter_list|(
name|struct
name|pollfd
modifier|&
name|pfd
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
name|char
name|data
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|res
argument_list|,
operator|::
name|recv
argument_list|(
name|pfd
operator|.
name|fd
argument_list|,
operator|&
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|data
argument_list|)
argument_list|,
name|MSG_PEEK
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|int
name|error
init|=
operator|(
name|res
operator|<
literal|0
operator|)
condition|?
name|errno
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|res
operator|==
literal|0
condition|)
block|{
name|pfd
operator|.
name|revents
operator||=
name|POLLHUP
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|res
operator|>
literal|0
operator|||
name|error
operator|==
name|ENOTSOCK
operator|||
name|error
operator|==
name|ENOTCONN
condition|)
block|{
name|pfd
operator|.
name|revents
operator||=
name|QT_POLL_READ_MASK
operator|&
name|pfd
operator|.
name|events
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
name|error
condition|)
block|{
case|case
name|ESHUTDOWN
case|:
case|case
name|ECONNRESET
case|:
case|case
name|ECONNABORTED
case|:
case|case
name|ENETRESET
case|:
name|pfd
operator|.
name|revents
operator||=
name|POLLHUP
expr_stmt|;
break|break;
default|default:
name|pfd
operator|.
name|revents
operator||=
name|POLLERR
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|qt_poll_sweep
specifier|static
specifier|inline
name|int
name|qt_poll_sweep
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fds
parameter_list|,
name|nfds_t
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|read_fds
parameter_list|,
name|fd_set
modifier|*
name|write_fds
parameter_list|,
name|fd_set
modifier|*
name|except_fds
parameter_list|)
block|{
name|int
name|result
init|=
literal|0
decl_stmt|;
for|for
control|(
name|nfds_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|nfds
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
operator|<
literal|0
condition|)
continue|continue;
if|if
condition|(
name|FD_ISSET
argument_list|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|,
name|read_fds
argument_list|)
condition|)
name|qt_poll_examine_ready_read
argument_list|(
name|fds
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|FD_ISSET
argument_list|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|,
name|write_fds
argument_list|)
condition|)
name|fds
index|[
name|i
index|]
operator|.
name|revents
operator||=
name|QT_POLL_WRITE_MASK
operator|&
name|fds
index|[
name|i
index|]
operator|.
name|events
expr_stmt|;
if|if
condition|(
name|FD_ISSET
argument_list|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|,
name|except_fds
argument_list|)
condition|)
name|fds
index|[
name|i
index|]
operator|.
name|revents
operator||=
name|QT_POLL_EXCEPT_MASK
operator|&
name|fds
index|[
name|i
index|]
operator|.
name|events
expr_stmt|;
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|revents
operator|!=
literal|0
condition|)
name|result
operator|++
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|qt_poll_is_bad_fd
specifier|static
specifier|inline
name|bool
name|qt_poll_is_bad_fd
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_GETFD
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EBADF
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_poll_mark_bad_fds
specifier|static
specifier|inline
name|int
name|qt_poll_mark_bad_fds
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fds
parameter_list|,
specifier|const
name|nfds_t
name|nfds
parameter_list|)
block|{
name|int
name|n_marked
init|=
literal|0
decl_stmt|;
for|for
control|(
name|nfds_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|nfds
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
operator|<
literal|0
condition|)
continue|continue;
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|revents
operator|&
name|QT_POLL_ERROR_MASK
condition|)
continue|continue;
if|if
condition|(
name|qt_poll_is_bad_fd
argument_list|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|)
condition|)
block|{
name|fds
index|[
name|i
index|]
operator|.
name|revents
operator||=
name|POLLNVAL
expr_stmt|;
name|n_marked
operator|++
expr_stmt|;
block|}
block|}
return|return
name|n_marked
return|;
block|}
end_function
begin_function
DECL|function|qt_poll
name|int
name|qt_poll
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fds
parameter_list|,
name|nfds_t
name|nfds
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout_ts
parameter_list|)
block|{
if|if
condition|(
operator|!
name|fds
operator|&&
name|nfds
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|fd_set
name|read_fds
decl_stmt|,
name|write_fds
decl_stmt|,
name|except_fds
decl_stmt|;
name|struct
name|timeval
name|tv
decl_stmt|,
modifier|*
name|ptv
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|timeout_ts
condition|)
block|{
name|tv
operator|=
name|timespecToTimeval
argument_list|(
operator|*
name|timeout_ts
argument_list|)
expr_stmt|;
name|ptv
operator|=
operator|&
name|tv
expr_stmt|;
block|}
name|int
name|n_bad_fds
init|=
literal|0
decl_stmt|;
for|for
control|(
name|nfds_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|nfds
condition|;
name|i
operator|++
control|)
block|{
name|fds
index|[
name|i
index|]
operator|.
name|revents
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
operator|<
literal|0
condition|)
continue|continue;
if|if
condition|(
name|fds
index|[
name|i
index|]
operator|.
name|events
operator|&
name|QT_POLL_EVENTS_MASK
condition|)
continue|continue;
if|if
condition|(
name|qt_poll_is_bad_fd
argument_list|(
name|fds
index|[
name|i
index|]
operator|.
name|fd
argument_list|)
condition|)
block|{
comment|// Mark bad file descriptors that have no event flags set
comment|// here, as we won't be passing them to select below and therefore
comment|// need to do the check ourselves
name|fds
index|[
name|i
index|]
operator|.
name|revents
operator|=
name|POLLNVAL
expr_stmt|;
name|n_bad_fds
operator|++
expr_stmt|;
block|}
block|}
forever|forever
block|{
specifier|const
name|int
name|max_fd
init|=
name|qt_poll_prepare
argument_list|(
name|fds
argument_list|,
name|nfds
argument_list|,
operator|&
name|read_fds
argument_list|,
operator|&
name|write_fds
argument_list|,
operator|&
name|except_fds
argument_list|)
decl_stmt|;
if|if
condition|(
name|max_fd
operator|<
literal|0
condition|)
return|return
name|max_fd
return|;
if|if
condition|(
name|n_bad_fds
operator|>
literal|0
condition|)
block|{
name|tv
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|tv
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|ptv
operator|=
operator|&
name|tv
expr_stmt|;
block|}
specifier|const
name|int
name|ret
init|=
operator|::
name|select
argument_list|(
name|max_fd
argument_list|,
operator|&
name|read_fds
argument_list|,
operator|&
name|write_fds
argument_list|,
operator|&
name|except_fds
argument_list|,
name|ptv
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
return|return
name|n_bad_fds
return|;
if|if
condition|(
name|ret
operator|>
literal|0
condition|)
return|return
name|qt_poll_sweep
argument_list|(
name|fds
argument_list|,
name|nfds
argument_list|,
operator|&
name|read_fds
argument_list|,
operator|&
name|write_fds
argument_list|,
operator|&
name|except_fds
argument_list|)
return|;
if|if
condition|(
name|errno
operator|!=
name|EBADF
condition|)
return|return
operator|-
literal|1
return|;
comment|// We have at least one bad file descriptor that we waited on, find out which and try again
name|n_bad_fds
operator|+=
name|qt_poll_mark_bad_fds
argument_list|(
name|fds
argument_list|,
name|nfds
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
