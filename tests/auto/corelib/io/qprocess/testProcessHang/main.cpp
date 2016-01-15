begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN32__
argument_list|)
end_if
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_function
DECL|function|sleepForever
name|void
name|sleepForever
parameter_list|()
block|{
operator|::
name|Sleep
argument_list|(
name|INFINITE
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_function
DECL|function|sleepForever
name|void
name|sleepForever
parameter_list|()
block|{
operator|::
name|pause
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|puts
argument_list|(
literal|"ready."
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ready.\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
comment|// sleep forever, simulating a hung application
name|sleepForever
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
