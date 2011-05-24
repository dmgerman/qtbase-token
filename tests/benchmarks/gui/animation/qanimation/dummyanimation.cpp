begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|state
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
