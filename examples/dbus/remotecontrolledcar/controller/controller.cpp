begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"controller.h"
end_include
begin_include
include|#
directive|include
file|"car_interface.h"
end_include
begin_constructor
DECL|function|Controller
name|Controller
operator|::
name|Controller
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|car
operator|=
operator|new
name|org
operator|::
name|example
operator|::
name|Examples
operator|::
name|CarInterface
argument_list|(
literal|"org.example.CarExample"
argument_list|,
literal|"/Car"
argument_list|,
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|startTimer
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|timerEvent
name|void
name|Controller
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|car
operator|->
name|isValid
argument_list|()
condition|)
name|ui
operator|.
name|label
operator|->
name|setText
argument_list|(
literal|"connected"
argument_list|)
expr_stmt|;
else|else
name|ui
operator|.
name|label
operator|->
name|setText
argument_list|(
literal|"disconnected"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_accelerate_clicked
name|void
name|Controller
operator|::
name|on_accelerate_clicked
parameter_list|()
block|{
name|car
operator|->
name|accelerate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_decelerate_clicked
name|void
name|Controller
operator|::
name|on_decelerate_clicked
parameter_list|()
block|{
name|car
operator|->
name|decelerate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_left_clicked
name|void
name|Controller
operator|::
name|on_left_clicked
parameter_list|()
block|{
name|car
operator|->
name|turnLeft
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_right_clicked
name|void
name|Controller
operator|::
name|on_right_clicked
parameter_list|()
block|{
name|car
operator|->
name|turnRight
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
