begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qblittable_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BLITTABLE
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QBlittablePrivate
class|class
name|QBlittablePrivate
block|{
public|public:
DECL|function|QBlittablePrivate
name|QBlittablePrivate
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QBlittable
operator|::
name|Capabilities
name|caps
parameter_list|)
member_init_list|:
name|caps
argument_list|(
name|caps
argument_list|)
member_init_list|,
name|m_size
argument_list|(
name|size
argument_list|)
member_init_list|,
name|locked
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|cachedImg
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|caps
name|QBlittable
operator|::
name|Capabilities
name|caps
decl_stmt|;
DECL|member|m_size
name|QSize
name|m_size
decl_stmt|;
DECL|member|locked
name|bool
name|locked
decl_stmt|;
DECL|member|cachedImg
name|QImage
modifier|*
name|cachedImg
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QBlittable
name|QBlittable
operator|::
name|QBlittable
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|Capabilities
name|caps
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QBlittablePrivate
argument_list|(
name|size
argument_list|,
name|caps
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QBlittable
name|QBlittable
operator|::
name|~
name|QBlittable
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|capabilities
name|QBlittable
operator|::
name|Capabilities
name|QBlittable
operator|::
name|capabilities
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBlittable
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|caps
return|;
block|}
end_function
begin_function
DECL|function|size
name|QSize
name|QBlittable
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBlittable
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|m_size
return|;
block|}
end_function
begin_function
DECL|function|lock
name|QImage
modifier|*
name|QBlittable
operator|::
name|lock
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QBlittable
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|locked
condition|)
block|{
name|d
operator|->
name|cachedImg
operator|=
name|doLock
argument_list|()
expr_stmt|;
name|d
operator|->
name|locked
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|d
operator|->
name|cachedImg
return|;
block|}
end_function
begin_function
DECL|function|unlock
name|void
name|QBlittable
operator|::
name|unlock
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QBlittable
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|locked
condition|)
block|{
name|doUnlock
argument_list|()
expr_stmt|;
name|d
operator|->
name|locked
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isLocked
name|bool
name|QBlittable
operator|::
name|isLocked
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBlittable
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|locked
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_BLITTABLE
end_comment
end_unit
