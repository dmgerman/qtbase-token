begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_MIPS_H
end_ifndef
begin_define
DECL|macro|QATOMIC_MIPS_H
define|#
directive|define
name|QATOMIC_MIPS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qgenericatomic.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
literal|0
comment|// silence syncqt warnings
expr|QT_END_NAMESPACE QT_END_HEADER
pragma|#
directive|pragma
name|qt_sync_stop_processing
endif|#
directive|endif
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT32_IS_SUPPORTED
DECL|macro|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
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
begin_expr_stmt
DECL|struct|size
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|QBasicAtomicOps
operator|:
name|QGenericAtomicOps
operator|<
name|QBasicAtomicOps
operator|<
name|size
operator|>
expr|>
block|{
specifier|static
name|void
name|acquireMemoryFence
argument_list|()
block|;
specifier|static
name|void
name|releaseMemoryFence
argument_list|()
block|;
specifier|static
name|void
name|orderedMemoryFence
argument_list|()
block|;
DECL|function|isReferenceCountingNative
specifier|static
specifier|inline
name|bool
name|isReferenceCountingNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|ref
argument_list|(
name|T
operator|&
name|_q_value
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|deref
argument_list|(
name|T
operator|&
name|_q_value
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|isTestAndSetNative
specifier|static
specifier|inline
name|bool
name|isTestAndSetNative
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function
begin_function
DECL|function|isTestAndSetWaitFree
specifier|static
specifier|inline
name|bool
name|isTestAndSetWaitFree
parameter_list|()
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
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|isFetchAndStoreNative
specifier|static
specifier|inline
name|bool
name|isFetchAndStoreNative
parameter_list|()
block|{
return|return
name|true
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
name|T
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|isFetchAndAddNative
specifier|static
specifier|inline
name|bool
name|isFetchAndAddNative
parameter_list|()
block|{
return|return
name|true
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
name|T
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
DECL|function|sizeof
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QAtomicOps
operator|:
name|QBasicAtomicOps
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
block|{
typedef|typedef
name|T
name|Type
typedef|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS1
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|==
literal|1
operator|)
end_if
begin_error
error|#
directive|error
literal|"Sorry, the MIPS1 architecture is not supported"
end_error
begin_error
error|#
directive|error
literal|"please set '-march=' to your architecture (e.g., -march=mips32)"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
specifier|inline
DECL|function|acquireMemoryFence
name|void
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|acquireMemoryFence
argument_list|()
block|{
name|asm
specifier|volatile
operator|(
literal|"sync 0x11"
operator|::
operator|:
literal|"memory"
operator|)
block|; }
name|template
operator|<
name|int
name|size
operator|>
specifier|inline
DECL|function|releaseMemoryFence
name|void
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|releaseMemoryFence
argument_list|()
block|{
name|asm
specifier|volatile
operator|(
literal|"sync 0x12"
operator|::
operator|:
literal|"memory"
operator|)
block|; }
name|template
operator|<
name|int
name|size
operator|>
specifier|inline
DECL|function|orderedMemoryFence
name|void
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|orderedMemoryFence
argument_list|()
block|{
name|asm
specifier|volatile
operator|(
literal|"sync 0"
operator|::
operator|:
literal|"memory"
operator|)
block|; }
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|ref
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
specifier|register
name|T
name|originalValue
block|;
specifier|register
name|T
name|newValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ll %[originalValue], %[_q_value]\n"
literal|"addiu %[newValue], %[originalValue], %[one]\n"
literal|"sc %[newValue], %[_q_value]\n"
literal|"beqz %[newValue], 0b\n"
literal|"nop\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|:
index|[
name|one
index|]
literal|"i"
operator|(
literal|1
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
operator|!=
name|T
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|deref
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
specifier|register
name|T
name|originalValue
block|;
specifier|register
name|T
name|newValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ll %[originalValue], %[_q_value]\n"
literal|"addiu %[newValue], %[originalValue], %[minusOne]\n"
literal|"sc %[newValue], %[_q_value]\n"
literal|"beqz %[newValue], 0b\n"
literal|"nop\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|:
index|[
name|minusOne
index|]
literal|"i"
operator|(
operator|-
literal|1
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
operator|!=
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|testAndSetRelaxed
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
block|{
specifier|register
name|T
name|result
block|;
specifier|register
name|T
name|tempValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ll %[result], %[_q_value]\n"
literal|"xor %[result], %[result], %[expectedValue]\n"
literal|"bnez %[result], 0f\n"
literal|"nop\n"
literal|"move %[tempValue], %[newValue]\n"
literal|"sc %[tempValue], %[_q_value]\n"
literal|"beqz %[tempValue], 0b\n"
literal|"nop\n"
literal|"0:\n"
operator|:
index|[
name|result
index|]
literal|"=&r"
operator|(
name|result
operator|)
operator|,
index|[
name|tempValue
index|]
literal|"=&r"
operator|(
name|tempValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|expectedValue
index|]
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndStoreRelaxed
name|T
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
block|{
specifier|register
name|T
name|originalValue
block|;
specifier|register
name|T
name|tempValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ll %[originalValue], %[_q_value]\n"
literal|"move %[tempValue], %[newValue]\n"
literal|"sc %[tempValue], %[_q_value]\n"
literal|"beqz %[tempValue], 0b\n"
literal|"nop\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|tempValue
index|]
literal|"=&r"
operator|(
name|tempValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndAddRelaxed
name|T
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
block|{
specifier|register
name|T
name|originalValue
block|;
specifier|register
name|T
name|newValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ll %[originalValue], %[_q_value]\n"
literal|"addu %[newValue], %[originalValue], %[valueToAdd]\n"
literal|"sc %[newValue], %[_q_value]\n"
literal|"beqz %[newValue], 0b\n"
literal|"nop\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|:
index|[
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|*
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AddScale
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips64
argument_list|)
end_if
begin_define
DECL|macro|Q_ATOMIC_INT64_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT64_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|long
name|long
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
name|long
name|long
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
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|ref
name|bool
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
specifier|register
name|T
name|originalValue
block|;
specifier|register
name|T
name|newValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"lld %[originalValue], %[_q_value]\n"
literal|"addiu %[newValue], %[originalValue], %[one]\n"
literal|"scd %[newValue], %[_q_value]\n"
literal|"beqz %[newValue], 0b\n"
literal|"nop\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|:
index|[
name|one
index|]
literal|"i"
operator|(
literal|1
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
operator|!=
name|T
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|deref
name|bool
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
specifier|register
name|T
name|originalValue
block|;
specifier|register
name|T
name|newValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"lld %[originalValue], %[_q_value]\n"
literal|"addiu %[newValue], %[originalValue], %[minusOne]\n"
literal|"scd %[newValue], %[_q_value]\n"
literal|"beqz %[newValue], 0b\n"
literal|"nop\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|:
index|[
name|minusOne
index|]
literal|"i"
operator|(
operator|-
literal|1
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
operator|!=
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|testAndSetRelaxed
name|bool
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
block|{
specifier|register
name|T
name|result
block|;
specifier|register
name|T
name|tempValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"lld %[result], %[_q_value]\n"
literal|"xor %[result], %[result], %[expectedValue]\n"
literal|"bnez %[result], 0f\n"
literal|"nop\n"
literal|"move %[tempValue], %[newValue]\n"
literal|"scd %[tempValue], %[_q_value]\n"
literal|"beqz %[tempValue], 0b\n"
literal|"nop\n"
literal|"0:\n"
operator|:
index|[
name|result
index|]
literal|"=&r"
operator|(
name|result
operator|)
operator|,
index|[
name|tempValue
index|]
literal|"=&r"
operator|(
name|tempValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|expectedValue
index|]
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndStoreRelaxed
name|T
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
block|{
specifier|register
name|T
name|originalValue
block|;
specifier|register
name|T
name|tempValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"lld %[originalValue], %[_q_value]\n"
literal|"move %[tempValue], %[newValue]\n"
literal|"scd %[tempValue], %[_q_value]\n"
literal|"beqz %[tempValue], 0b\n"
literal|"nop\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|tempValue
index|]
literal|"=&r"
operator|(
name|tempValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndAddRelaxed
name|T
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
block|{
specifier|register
name|T
name|originalValue
block|;
specifier|register
name|T
name|newValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"lld %[originalValue], %[_q_value]\n"
literal|"addu %[newValue], %[originalValue], %[valueToAdd]\n"
literal|"scd %[newValue], %[_q_value]\n"
literal|"beqz %[newValue], 0b\n"
literal|"nop\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"+m"
operator|(
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|:
index|[
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|*
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AddScale
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MIPS64
end_comment
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
literal|"This compiler for MIPS is not supported"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_CC_GNU
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_MIPS_H
end_comment
end_unit
