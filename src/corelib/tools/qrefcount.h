begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QREFCOUNT_H
end_ifndef
begin_define
DECL|macro|QREFCOUNT_H
define|#
directive|define
name|QREFCOUNT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|namespace
name|QtPrivate
decl_stmt|{  class RefCount
block|{
name|public
label|:
specifier|inline
name|bool
name|ref
parameter_list|()
block|{
name|int
name|count
init|=
name|atomic
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|count
operator|==
literal|0
condition|)
comment|// !isSharable
return|return
name|false
return|;
if|if
condition|(
name|count
operator|!=
operator|-
literal|1
condition|)
comment|// !isStatic
name|atomic
operator|.
name|ref
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
specifier|inline
name|bool
name|deref
parameter_list|()
block|{
name|int
name|count
init|=
name|atomic
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|count
operator|==
literal|0
condition|)
comment|// !isSharable
return|return
name|false
return|;
if|if
condition|(
name|count
operator|==
operator|-
literal|1
condition|)
comment|// isStatic
return|return
name|true
return|;
return|return
name|atomic
operator|.
name|deref
argument_list|()
return|;
block|}
name|bool
name|setSharable
parameter_list|(
name|bool
name|sharable
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isShared
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|sharable
condition|)
return|return
name|atomic
operator|.
name|testAndSetRelaxed
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
return|;
else|else
return|return
name|atomic
operator|.
name|testAndSetRelaxed
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|bool
name|isStatic
argument_list|()
specifier|const
block|{
comment|// Persistent object, never deleted
return|return
name|atomic
operator|.
name|load
argument_list|()
operator|==
operator|-
literal|1
return|;
block|}
name|bool
name|isSharable
argument_list|()
specifier|const
block|{
comment|// Sharable === Shared ownership.
return|return
name|atomic
operator|.
name|load
argument_list|()
operator|!=
literal|0
return|;
block|}
name|bool
name|isShared
argument_list|()
specifier|const
block|{
name|int
name|count
operator|=
name|atomic
operator|.
name|load
argument_list|()
block|;
return|return
operator|(
name|count
operator|!=
literal|1
operator|)
operator|&&
operator|(
name|count
operator|!=
literal|0
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|int
name|value
operator|)
specifier|const
block|{
return|return
name|atomic
operator|.
name|load
argument_list|()
operator|==
name|value
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|int
name|value
operator|)
specifier|const
block|{
return|return
name|atomic
operator|.
name|load
argument_list|()
operator|!=
name|value
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|atomic
operator|.
name|load
argument_list|()
return|;
block|}
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|atomic
operator|.
name|load
argument_list|()
return|;
block|}
name|void
name|initializeOwned
parameter_list|()
block|{
name|atomic
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|void
name|initializeUnsharable
parameter_list|()
block|{
name|atomic
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|QBasicAtomicInt
name|atomic
decl_stmt|;
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|Q_REFCOUNT_INITIALIZE_STATIC
unit|}
define|#
directive|define
name|Q_REFCOUNT_INITIALIZE_STATIC
value|{ Q_BASIC_ATOMIC_INITIALIZER(-1) }
end_define
begin_macro
DECL|macro|Q_REFCOUNT_INITIALIZE_STATIC
unit|QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
