begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_BOOTSTRAP_H
end_ifndef
begin_define
DECL|macro|QATOMIC_BOOTSTRAP_H
define|#
directive|define
name|QATOMIC_BOOTSTRAP_H
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|ref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|ref
argument_list|()
block|{
return|return
operator|++
name|_q_value
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|deref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|deref
argument_list|()
block|{
return|return
operator|--
name|_q_value
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetOrdered
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetOrdered
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
if|if
condition|(
name|_q_value
operator|==
name|expectedValue
condition|)
block|{
name|_q_value
operator|=
name|newValue
expr_stmt|;
return|return
name|true
return|;
block|}
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|testAndSetAcquire
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetAcquire
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetRelease
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetRelease
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetRelaxed
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetRelaxed
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddOrdered
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddOrdered
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
name|int
name|returnValue
operator|=
name|_q_value
block|;
name|_q_value
operator|+=
name|valueToAdd
block|;
return|return
name|returnValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddAcquire
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddAcquire
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddRelease
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddRelease
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddRelaxed
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|testAndSetOrdered
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetOrdered
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
if|if
condition|(
name|_q_value
operator|==
name|expectedValue
condition|)
block|{
name|_q_value
operator|=
name|newValue
expr_stmt|;
return|return
name|true
return|;
block|}
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_macro
unit|}  QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_BOOTSTRAP_H
end_comment
end_unit
