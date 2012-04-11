begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxservices.h"
end_include
begin_include
include|#
directive|include
file|"qqnxabstractnavigator.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxServices
name|QQnxServices
operator|::
name|QQnxServices
parameter_list|(
name|QQnxAbstractNavigator
modifier|*
name|navigator
parameter_list|)
member_init_list|:
name|m_navigator
argument_list|(
name|navigator
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QQnxServices
name|QQnxServices
operator|::
name|~
name|QQnxServices
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|openUrl
name|bool
name|QQnxServices
operator|::
name|openUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|navigatorInvoke
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|openDocument
name|bool
name|QQnxServices
operator|::
name|openDocument
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|navigatorInvoke
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|navigatorInvoke
name|bool
name|QQnxServices
operator|::
name|navigatorInvoke
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|m_navigator
operator|->
name|invokeUrl
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
