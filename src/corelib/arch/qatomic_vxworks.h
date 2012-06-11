begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_VXWORKS_H
end_ifndef
begin_define
DECL|macro|QATOMIC_VXWORKS_H
define|#
directive|define
name|QATOMIC_VXWORKS_H
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
if|#
directive|if
name|defined
argument_list|(
name|__ppc
argument_list|)
include|#
directive|include
file|<QtCore/qatomic_power.h>
else|#
directive|else
comment|// generic implementation with taskLock()
include|#
directive|include
file|<QtCore/qoldbasicatomic.h>
if|#
directive|if
literal|0
comment|// we don't want to include the system header here for two function prototypes,
comment|// because it pulls in a _lot_ of stuff that pollutes the global namespace
include|#
directive|include
file|<vxWorksCommon.h>
include|#
directive|include
file|<taskLib.h>
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|_WRS_KERNEL
argument_list|)
specifier|extern
literal|"C"
name|int
name|taskLock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_extern
extern|extern
literal|"C"
name|int
name|taskUnlock
parameter_list|()
function_decl|;
end_extern
begin_else
else|#
directive|else
end_else
begin_function
specifier|inline
name|int
name|taskLock
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
specifier|inline
name|int
name|taskUnlock
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_NOT_NATIVE
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isReferenceCountingNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isReferenceCountingWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_NOT_NATIVE
end_define
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isTestAndSetNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isTestAndSetWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_NOT_NATIVE
end_define
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndStoreNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_NOT_NATIVE
end_define
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndAddNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndAddWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isTestAndSetNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isTestAndSetWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndStoreNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndAddNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndAddWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_comment
comment|// Reference counting
end_comment
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|ref
argument_list|()
block|{
name|taskLock
argument_list|()
block|;
name|bool
name|ret
operator|=
operator|(
operator|++
name|_q_value
operator|!=
literal|0
operator|)
block|;
name|taskUnlock
argument_list|()
block|;
return|return
name|ret
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|deref
argument_list|()
block|{
name|taskLock
argument_list|()
block|;
name|bool
name|ret
operator|=
operator|(
operator|--
name|_q_value
operator|!=
literal|0
operator|)
block|;
name|taskUnlock
argument_list|()
block|;
return|return
name|ret
return|;
block|}
end_expr_stmt
begin_comment
comment|// Test-and-set for integers
end_comment
begin_expr_stmt
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
name|taskLock
argument_list|()
block|;
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
name|taskUnlock
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
name|taskUnlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|}  inline
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
specifier|inline
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
begin_comment
comment|// Fetch-and-store for integers
end_comment
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreOrdered
argument_list|(
argument|int newValue
argument_list|)
block|{
name|taskLock
argument_list|()
block|;
name|int
name|returnValue
operator|=
name|_q_value
block|;
name|_q_value
operator|=
name|newValue
block|;
name|taskUnlock
argument_list|()
block|;
return|return
name|returnValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreAcquire
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreRelease
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch-and-add for integers
end_comment
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddOrdered
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
name|taskLock
argument_list|()
block|;
name|int
name|originalValue
operator|=
name|_q_value
block|;
name|_q_value
operator|+=
name|valueToAdd
block|;
name|taskUnlock
argument_list|()
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
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
begin_comment
comment|// Test and set for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
name|taskLock
argument_list|()
block|;
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
name|taskUnlock
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
name|taskUnlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
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
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetAcquire
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
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
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetRelease
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
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
begin_comment
comment|// Fetch and store for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreOrdered
argument_list|(
argument|T *newValue
argument_list|)
block|{
name|taskLock
argument_list|()
block|;
name|T
operator|*
name|returnValue
operator|=
operator|(
name|_q_value
operator|)
block|;
name|_q_value
operator|=
name|newValue
block|;
name|taskUnlock
argument_list|()
block|;
return|return
name|returnValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
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
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreAcquire
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
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
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreRelease
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and add for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddOrdered
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
name|taskLock
argument_list|()
block|;
name|T
operator|*
name|returnValue
operator|=
operator|(
name|_q_value
operator|)
block|;
name|_q_value
operator|+=
name|valueToAdd
block|;
name|taskUnlock
argument_list|()
block|;
return|return
name|returnValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|qptrdiff valueToAdd
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
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddAcquire
argument_list|(
argument|qptrdiff valueToAdd
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
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddRelease
argument_list|(
argument|qptrdiff valueToAdd
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
name|QT_END_NAMESPACE
endif|#
directive|endif
comment|// generic implementation with taskLock()
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_VXWORKS_H
end_comment
end_unit
