begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"dummyanimation.h"
end_include
begin_include
include|#
directive|include
file|"dummyobject.h"
end_include
begin_constructor
DECL|function|DummyAnimation
name|DummyAnimation
operator|::
name|DummyAnimation
parameter_list|(
name|DummyObject
modifier|*
name|d
parameter_list|)
member_init_list|:
name|m_dummy
argument_list|(
name|d
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|updateCurrentValue
name|void
name|DummyAnimation
operator|::
name|updateCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|state
argument_list|()
operator|==
name|Stopped
condition|)
return|return;
if|if
condition|(
name|m_dummy
condition|)
name|m_dummy
operator|->
name|setRect
argument_list|(
name|value
operator|.
name|toRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateState
name|void
name|DummyAnimation
operator|::
name|updateState
parameter_list|(
name|State
name|newstate
parameter_list|,
name|State
name|oldstate
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|newstate
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|oldstate
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
