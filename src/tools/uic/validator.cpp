begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"validator.h"
end_include
begin_include
include|#
directive|include
file|"driver.h"
end_include
begin_include
include|#
directive|include
file|"ui4.h"
end_include
begin_include
include|#
directive|include
file|"uic.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|Validator
name|Validator
operator|::
name|Validator
parameter_list|(
name|Uic
modifier|*
name|uic
parameter_list|)
member_init_list|:
name|m_driver
argument_list|(
name|uic
operator|->
name|driver
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|acceptUI
name|void
name|Validator
operator|::
name|acceptUI
parameter_list|(
name|DomUI
modifier|*
name|node
parameter_list|)
block|{
name|TreeWalker
operator|::
name|acceptUI
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptWidget
name|void
name|Validator
operator|::
name|acceptWidget
parameter_list|(
name|DomWidget
modifier|*
name|node
parameter_list|)
block|{
operator|(
name|void
operator|)
name|m_driver
operator|->
name|findOrInsertWidget
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptWidget
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptLayoutItem
name|void
name|Validator
operator|::
name|acceptLayoutItem
parameter_list|(
name|DomLayoutItem
modifier|*
name|node
parameter_list|)
block|{
operator|(
name|void
operator|)
name|m_driver
operator|->
name|findOrInsertLayoutItem
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptLayoutItem
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptLayout
name|void
name|Validator
operator|::
name|acceptLayout
parameter_list|(
name|DomLayout
modifier|*
name|node
parameter_list|)
block|{
operator|(
name|void
operator|)
name|m_driver
operator|->
name|findOrInsertLayout
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptLayout
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptActionGroup
name|void
name|Validator
operator|::
name|acceptActionGroup
parameter_list|(
name|DomActionGroup
modifier|*
name|node
parameter_list|)
block|{
operator|(
name|void
operator|)
name|m_driver
operator|->
name|findOrInsertActionGroup
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptActionGroup
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptAction
name|void
name|Validator
operator|::
name|acceptAction
parameter_list|(
name|DomAction
modifier|*
name|node
parameter_list|)
block|{
operator|(
name|void
operator|)
name|m_driver
operator|->
name|findOrInsertAction
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptAction
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
