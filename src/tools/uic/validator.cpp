begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
