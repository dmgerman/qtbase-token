begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_H
end_ifndef
begin_define
DECL|macro|QATOMIC_H
define|#
directive|define
name|QATOMIC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbasicatomic.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|406
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|push
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wextra"
endif|#
directive|endif
comment|// High-level atomic integer operations
name|class
name|QAtomicInt
range|:
name|public
name|QBasicAtomicInt
block|{
name|public
operator|:
comment|// Non-atomic API
ifdef|#
directive|ifdef
name|Q_BASIC_ATOMIC_HAS_CONSTRUCTORS
name|constexpr
name|QAtomicInt
argument_list|(
argument|int value =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|QBasicAtomicInt
argument_list|(
argument|value
argument_list|)
block|{}
else|#
directive|else
specifier|inline
name|QAtomicInt
argument_list|(
argument|int value =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|_q_value
operator|=
name|value
block|;     }
endif|#
directive|endif
specifier|inline
name|QAtomicInt
argument_list|(
argument|const QAtomicInt&other
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|store
argument_list|(
name|other
operator|.
name|load
argument_list|()
argument_list|)
block|;     }
specifier|inline
name|QAtomicInt
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QAtomicInt
operator|&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|this
operator|->
name|store
argument_list|(
name|other
operator|.
name|load
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
ifdef|#
directive|ifdef
name|qdoc
name|int
name|load
argument_list|()
specifier|const
block|;
name|int
name|loadAcquire
argument_list|()
specifier|const
block|;
name|void
name|store
argument_list|(
argument|int newValue
argument_list|)
block|;
name|void
name|storeRelease
argument_list|(
argument|int newValue
argument_list|)
block|;
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isReferenceCountingNative
argument_list|()
block|;
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isReferenceCountingWaitFree
argument_list|()
block|;
name|bool
name|ref
argument_list|()
block|;
name|bool
name|deref
argument_list|()
block|;
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetNative
argument_list|()
block|;
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetWaitFree
argument_list|()
block|;
name|bool
name|testAndSetRelaxed
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|;
name|bool
name|testAndSetAcquire
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|;
name|bool
name|testAndSetRelease
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|;
name|bool
name|testAndSetOrdered
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|;
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreNative
argument_list|()
block|;
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreWaitFree
argument_list|()
block|;
name|int
name|fetchAndStoreRelaxed
argument_list|(
argument|int newValue
argument_list|)
block|;
name|int
name|fetchAndStoreAcquire
argument_list|(
argument|int newValue
argument_list|)
block|;
name|int
name|fetchAndStoreRelease
argument_list|(
argument|int newValue
argument_list|)
block|;
name|int
name|fetchAndStoreOrdered
argument_list|(
argument|int newValue
argument_list|)
block|;
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddNative
argument_list|()
block|;
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddWaitFree
argument_list|()
block|;
name|int
name|fetchAndAddRelaxed
argument_list|(
argument|int valueToAdd
argument_list|)
block|;
name|int
name|fetchAndAddAcquire
argument_list|(
argument|int valueToAdd
argument_list|)
block|;
name|int
name|fetchAndAddRelease
argument_list|(
argument|int valueToAdd
argument_list|)
block|;
name|int
name|fetchAndAddOrdered
argument_list|(
argument|int valueToAdd
argument_list|)
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// High-level atomic pointer operations
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QAtomicPointer
operator|:
name|public
name|QBasicAtomicPointer
operator|<
name|T
operator|>
block|{
name|public
operator|:
ifdef|#
directive|ifdef
name|QT_BASIC_ATOMIC_HAS_CONSTRUCTORS
name|constexpr
name|QAtomicPointer
argument_list|(
argument|T *value =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|(
name|value
operator|)
block|{}
else|#
directive|else
specifier|inline
name|QAtomicPointer
argument_list|(
argument|T *value =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|this
operator|->
name|store
argument_list|(
name|value
argument_list|)
block|;     }
endif|#
directive|endif
specifier|inline
name|QAtomicPointer
argument_list|(
argument|const QAtomicPointer<T>&other
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|this
operator|->
name|store
argument_list|(
name|other
operator|.
name|load
argument_list|()
argument_list|)
block|;     }
specifier|inline
name|QAtomicPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QAtomicPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|this
operator|->
name|store
argument_list|(
name|other
operator|.
name|load
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
ifdef|#
directive|ifdef
name|qdoc
name|T
operator|*
name|load
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|T
operator|*
name|loadAcquire
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|store
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|storeRelease
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetNative
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetWaitFree
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|testAndSetRelaxed
parameter_list|(
name|T
modifier|*
name|expectedValue
parameter_list|,
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|testAndSetAcquire
parameter_list|(
name|T
modifier|*
name|expectedValue
parameter_list|,
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|testAndSetRelease
parameter_list|(
name|T
modifier|*
name|expectedValue
parameter_list|,
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|testAndSetOrdered
parameter_list|(
name|T
modifier|*
name|expectedValue
parameter_list|,
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreNative
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreWaitFree
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndStoreRelaxed
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndStoreAcquire
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndStoreRelease
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndStoreOrdered
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddNative
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddWaitFree
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndAddRelaxed
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndAddAcquire
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndAddRelease
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndAddOrdered
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_if
unit|};
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|406
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
end_if
begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|pop
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BASIC_ATOMIC_HAS_CONSTRUCTORS
end_ifdef
begin_undef
DECL|macro|QT_BASIC_ATOMIC_HAS_CONSTRUCTORS
undef|#
directive|undef
name|QT_BASIC_ATOMIC_HAS_CONSTRUCTORS
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     This is a helper for the assignment operators of implicitly     shared classes. Your assignment operator should look like this:      \snippet code/src.corelib.thread.qatomic.h 0 */
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qAtomicAssign
specifier|inline
name|void
name|qAtomicAssign
argument_list|(
argument|T *&d
argument_list|,
argument|T *x
argument_list|)
block|{
if|if
condition|(
name|d
operator|==
name|x
condition|)
return|return;
name|x
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|d
decl_stmt|;
end_if
begin_expr_stmt
name|d
operator|=
name|x
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|/*!     This is a helper for the detach method of implicitly shared     classes. Your private class needs a copy constructor which copies     the members and sets the refcount to 1. After that, your detach     function should look like this:      \snippet code/src.corelib.thread.qatomic.h 1 */
end_comment
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qAtomicDetach
specifier|inline
name|void
name|qAtomicDetach
argument_list|(
argument|T *&d
argument_list|)
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|1
condition|)
return|return;
name|T
operator|*
name|x
operator|=
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|d
operator|=
name|new
name|T
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|x
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|x
decl_stmt|;
end_if
begin_macro
unit|}  QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_H
end_comment
end_unit
