begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2014 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbb10styleplugin.h"
end_include
begin_include
include|#
directive|include
file|"qbb10darkstyle.h"
end_include
begin_include
include|#
directive|include
file|"qbb10brightstyle.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QBB10StylePlugin
name|QBB10StylePlugin
operator|::
name|QBB10StylePlugin
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~QBB10StylePlugin
name|QBB10StylePlugin
operator|::
name|~
name|QBB10StylePlugin
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|create
name|QStyle
modifier|*
name|QBB10StylePlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
specifier|const
name|QString
name|keyLower
argument_list|(
name|key
operator|.
name|toLower
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyLower
operator|==
name|QLatin1String
argument_list|(
literal|"bb10bright"
argument_list|)
condition|)
return|return
operator|new
name|QBB10BrightStyle
return|;
elseif|else
if|if
condition|(
name|keyLower
operator|==
name|QLatin1String
argument_list|(
literal|"bb10dark"
argument_list|)
condition|)
return|return
operator|new
name|QBB10DarkStyle
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|keys
name|QStringList
name|QBB10StylePlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"bb10bright"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"bb10dark"
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qbb10styleplugin.cpp"
end_include
end_unit
