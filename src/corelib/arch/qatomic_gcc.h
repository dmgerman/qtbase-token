begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_GCC_H
end_ifndef
begin_define
DECL|macro|QATOMIC_GCC_H
define|#
directive|define
name|QATOMIC_GCC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qgenericatomic.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
literal|0
comment|// silence syncqt warnings
expr|QT_END_NAMESPACE
pragma|#
directive|pragma
name|qt_sync_skip_header_check
pragma|#
directive|pragma
name|qt_sync_stop_processing
endif|#
directive|endif
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|int
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|unsigned
name|int
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_UNICODE_STRINGS
end_ifdef
begin_expr_stmt
DECL|struct|char32_t
DECL|enumerator|IsInteger
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|char32_t
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT32_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_TEST_AND_SET_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_POINTER_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
end_define
begin_expr_stmt
DECL|struct|X
name|template
operator|<
name|typename
name|X
operator|>
expr|struct
name|QAtomicOps
operator|:
name|QGenericAtomicOps
operator|<
name|QAtomicOps
operator|<
name|X
operator|>
expr|>
block|{
comment|// The GCC intrinsics all have fully-ordered memory semantics, so we define
comment|// only the xxxRelaxed functions. The exception is __sync_lock_and_test,
comment|// which has acquire semantics, so we need to define the Release and
comment|// Ordered versions too.
DECL|typedef|Type
typedef|typedef
name|X
name|Type
typedef|;
ifndef|#
directive|ifndef
name|__ia64__
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|loadAcquire
argument_list|(
argument|const T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|T
name|tmp
operator|=
name|_q_value
block|;
name|__sync_synchronize
argument_list|()
block|;
return|return
name|tmp
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|storeRelease
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|__sync_synchronize
argument_list|()
block|;
name|_q_value
operator|=
name|newValue
block|;     }
endif|#
directive|endif
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetNative
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|__sync_bool_compare_and_swap
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
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|__sync_lock_test_and_set
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
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreRelease
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|__sync_synchronize
argument_list|()
block|;
return|return
name|__sync_lock_test_and_set
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
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreOrdered
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|fetchAndStoreRelease
argument_list|(
name|_q_value
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
specifier|static
name|T
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|__sync_fetch_and_add
argument_list|(
operator|&
name|_q_value
argument_list|,
name|valueToAdd
operator|*
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AddScale
argument_list|)
return|;
block|}
end_expr_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_GCC_H
end_comment
end_unit
