begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_SYMBIAN_H
end_ifndef
begin_define
DECL|macro|QATOMIC_SYMBIAN_H
define|#
directive|define
name|QATOMIC_SYMBIAN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<e32std.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
specifier|inline
namespace|bool
name|QBasicAtomicInt
namespace|::
name|isReferenceCountingWaitFree
namespace|(
decl_stmt|)
block|{
return|return
name|false
return|;
block|}
end_decl_stmt
begin_define
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_SOMETIMES_NATIVE
end_define
begin_expr_stmt
DECL|function|isTestAndSetWaitFree
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
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
end_define
begin_expr_stmt
DECL|function|isFetchAndStoreWaitFree
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
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
end_define
begin_expr_stmt
DECL|function|isFetchAndAddWaitFree
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
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_SOMETIMES_NATIVE
end_define
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicPointer_isTestAndSetNative
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isTestAndSetNative
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
name|QBasicAtomicPointer_isTestAndSetNative
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isTestAndSetWaitFree
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
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
end_define
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicPointer_isFetchAndStoreNative
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndStoreNative
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
name|QBasicAtomicPointer_isFetchAndStoreNative
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndStoreWaitFree
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
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
end_define
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicPointer_isFetchAndAddNative
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndAddNative
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
name|QBasicAtomicPointer_isFetchAndAddNative
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndAddWaitFree
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
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicInt_testAndSetOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|QBasicAtomicInt_fetchAndStoreOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|QBasicAtomicInt_fetchAndAddOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicInt_testAndSetRelaxed
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|QBasicAtomicInt_fetchAndStoreRelaxed
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|QBasicAtomicInt_fetchAndAddRelaxed
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicInt_testAndSetAcquire
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|QBasicAtomicInt_fetchAndStoreAcquire
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|QBasicAtomicInt_fetchAndAddAcquire
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicInt_testAndSetRelease
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|QBasicAtomicInt_fetchAndStoreRelease
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|QBasicAtomicInt_fetchAndAddRelease
parameter_list|(
specifier|volatile
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicPointer_testAndSetOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|qptrdiff
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicPointer_testAndSetRelaxed
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreRelaxed
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddRelaxed
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|qptrdiff
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicPointer_testAndSetAcquire
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreAcquire
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddAcquire
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|qptrdiff
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|QBasicAtomicPointer_testAndSetRelease
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreRelease
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddRelease
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
parameter_list|,
name|qptrdiff
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Reference counting
end_comment
begin_comment
comment|//LockedInc and LockedDec are machine coded for ARMv6 (and future proof)
end_comment
begin_expr_stmt
DECL|function|ref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|ref
argument_list|()
block|{
name|int
name|original
operator|=
name|User
operator|::
name|LockedInc
argument_list|(
operator|(
name|TInt
operator|&
operator|)
name|_q_value
argument_list|)
block|;
return|return
name|original
operator|!=
operator|-
literal|1
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
name|int
name|original
operator|=
name|User
operator|::
name|LockedDec
argument_list|(
operator|(
name|TInt
operator|&
operator|)
name|_q_value
argument_list|)
block|;
return|return
name|original
operator|!=
literal|1
return|;
block|}
end_expr_stmt
begin_comment
comment|// Test and set for integers
end_comment
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
return|return
name|QBasicAtomicInt_testAndSetOrdered
argument_list|(
operator|&
name|_q_value
argument_list|,
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
name|QBasicAtomicInt_testAndSetRelaxed
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetAcquire
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
name|QBasicAtomicInt_testAndSetAcquire
argument_list|(
operator|&
name|_q_value
argument_list|,
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
name|QBasicAtomicInt_testAndSetRelease
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and store for integers
end_comment
begin_expr_stmt
DECL|function|fetchAndStoreOrdered
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreOrdered
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|QBasicAtomicInt_fetchAndStoreOrdered
argument_list|(
operator|&
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndStoreRelaxed
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
name|QBasicAtomicInt_fetchAndStoreRelaxed
argument_list|(
operator|&
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndStoreAcquire
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
name|QBasicAtomicInt_fetchAndStoreAcquire
argument_list|(
operator|&
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndStoreRelease
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
name|QBasicAtomicInt_fetchAndStoreRelease
argument_list|(
operator|&
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and add for integers
end_comment
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
return|return
name|QBasicAtomicInt_fetchAndAddOrdered
argument_list|(
operator|&
name|_q_value
argument_list|,
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
name|QBasicAtomicInt_fetchAndAddRelaxed
argument_list|(
operator|&
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
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
name|QBasicAtomicInt_fetchAndAddAcquire
argument_list|(
operator|&
name|_q_value
argument_list|,
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
name|QBasicAtomicInt_fetchAndAddRelease
argument_list|(
operator|&
name|_q_value
argument_list|,
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
return|return
name|QBasicAtomicPointer_testAndSetOrdered
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
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
DECL|function|testAndSetRelaxed
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
name|QBasicAtomicPointer_testAndSetRelaxed
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
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
DECL|function|testAndSetAcquire
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
name|QBasicAtomicPointer_testAndSetAcquire
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
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
DECL|function|testAndSetRelease
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
name|QBasicAtomicPointer_testAndSetRelease
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
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
DECL|function|fetchAndStoreOrdered
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
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QBasicAtomicPointer_fetchAndStoreOrdered
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
name|newValue
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreRelaxed
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
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QBasicAtomicPointer_fetchAndStoreRelaxed
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
name|newValue
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreAcquire
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
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QBasicAtomicPointer_fetchAndStoreAcquire
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
name|newValue
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreRelease
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
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QBasicAtomicPointer_fetchAndStoreRelease
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
name|newValue
argument_list|)
operator|)
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
DECL|function|fetchAndAddOrdered
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
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QBasicAtomicPointer_fetchAndAddOrdered
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
name|valueToAdd
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddRelaxed
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
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QBasicAtomicPointer_fetchAndAddRelaxed
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
name|valueToAdd
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddAcquire
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
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QBasicAtomicPointer_fetchAndAddAcquire
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
name|valueToAdd
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddRelease
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
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QBasicAtomicPointer_fetchAndAddRelease
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
argument_list|,
name|valueToAdd
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_SYMBIAN_H
end_comment
end_unit
