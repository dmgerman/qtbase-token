begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ** This file implements the generic atomics interface using ARMv6 assembly ** instructions. It is more efficient than the inline versions when Qt is ** built for the THUMB instruction set, as the required instructions are ** only available in ARM state. ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_HAVE_ARMV6
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|SYMBIAN_E32_ATOMIC_API
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
name|QT_USE_NAMESPACE
ifdef|#
directive|ifdef
name|Q_CC_RVCT
pragma|#
directive|pragma
name|push
pragma|#
directive|pragma
name|arm
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_testAndSetRelaxed
name|bool
name|QBasicAtomicInt_testAndSetRelaxed
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|expectedValue
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_testAndSetAcquire
name|bool
name|QBasicAtomicInt_testAndSetAcquire
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|expectedValue
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_testAndSetRelease
name|bool
name|QBasicAtomicInt_testAndSetRelease
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|expectedValue
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_testAndSetOrdered
name|bool
name|QBasicAtomicInt_testAndSetOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|expectedValue
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//R0 = _q_value
comment|//R1 = expectedValue
comment|//R2 = newValue
name|retry_testAndSetOrdered
name|LDREX
name|r3
decl_stmt|,[
name|r0
decl|]
comment|//r3 = *_q_value
name|EORS
name|r3
decl_stmt|,
name|r3
decl_stmt|,
name|r1
comment|//if (r3 == expectedValue) {
name|STREXEQ
name|r3
decl_stmt|,
name|r2
decl_stmt|,[
name|r0
decl|]
comment|//*_q_value = newvalue, r3 = error
name|TEQEQ
name|r3
decl_stmt|,#1
comment|//if error
name|BEQ
name|retry_testAndSetOrdered
comment|//then goto retry }
name|RSBS
name|r0
decl_stmt|,
name|r3
decl_stmt|,#1
comment|//return (r3 == 0)
name|MOVCC
name|r0
decl_stmt|,#0
name|BX
name|r14
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_fetchAndStoreRelaxed
name|int
name|QBasicAtomicInt_fetchAndStoreRelaxed
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_fetchAndStoreAcquire
name|int
name|QBasicAtomicInt_fetchAndStoreAcquire
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_fetchAndStoreRelease
name|int
name|QBasicAtomicInt_fetchAndStoreRelease
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_fetchAndStoreOrdered
name|int
name|QBasicAtomicInt_fetchAndStoreOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//R0 = _q_value
comment|//R1 = newValue
name|retry_fetchAndStoreOrdered
name|LDREX
name|r3
decl_stmt|,[
name|r0
decl|]
comment|//r3 = *_q_value
name|STREX
name|r2
decl_stmt|,
name|r1
decl_stmt|,[
name|r0
decl|]
comment|//*_q_value = newValue, r2 = error
name|TEQ
name|r2
decl_stmt|,#0
comment|//if error
name|BNE
name|retry_fetchAndStoreOrdered
comment|//then goto retry
name|MOV
name|r0
decl_stmt|,
name|r3
comment|//return r3
name|BX
name|r14
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_fetchAndAddRelaxed
name|int
name|QBasicAtomicInt_fetchAndAddRelaxed
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|valueToAdd
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_fetchAndAddAcquire
name|int
name|QBasicAtomicInt_fetchAndAddAcquire
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|valueToAdd
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_fetchAndAddRelease
name|int
name|QBasicAtomicInt_fetchAndAddRelease
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|valueToAdd
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicInt_fetchAndAddOrdered
name|int
name|QBasicAtomicInt_fetchAndAddOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|valueToAdd
parameter_list|)
block|{
name|CODE32
comment|//R0 = _q_value
comment|//R1 = valueToAdd
name|STMDB
name|sp
operator|!
operator|,
block|{
name|r12
block|,
name|lr
block|}
name|retry_fetchAndAddOrdered
name|LDREX
name|r2
operator|,
index|[
name|r0
index|]
comment|//r2 = *_q_value
name|ADD
name|r3
operator|,
name|r2
operator|,
name|r1
comment|//r3 = r2 + r1
name|STREX
name|r12
operator|,
name|r3
operator|,
index|[
name|r0
index|]
comment|//*_q_value = r3, r12 = error
name|TEQ
name|r12
operator|,
operator|#
literal|0
comment|//if error
name|BNE
name|retry_fetchAndAddOrdered
comment|//then retry
name|MOV
name|r0
operator|,
name|r2
comment|//return r2
name|LDMIA
name|sp
operator|!
operator|,
block|{
name|r12
block|,
name|pc
block|}
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_testAndSetRelaxed
name|bool
name|QBasicAtomicPointer_testAndSetRelaxed
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|expectedValue
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_testAndSetRelease
name|bool
name|QBasicAtomicPointer_testAndSetRelease
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|expectedValue
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_testAndSetAcquire
name|bool
name|QBasicAtomicPointer_testAndSetAcquire
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|expectedValue
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_testAndSetOrdered
name|bool
name|QBasicAtomicPointer_testAndSetOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|expectedValue
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//R0 = _q_value
comment|//R1 = expectedValue
comment|//R2 = newValue
name|retryPointer_testAndSetOrdered
name|LDREX
name|r3
decl_stmt|,[
name|r0
decl|]
comment|//r3 = *_q_value
name|EORS
name|r3
decl_stmt|,
name|r3
decl_stmt|,
name|r1
comment|//if (r3 == expectedValue) {
name|STREXEQ
name|r3
decl_stmt|,
name|r2
decl_stmt|,[
name|r0
decl|]
comment|//*_q_value = newvalue, r3 = error
name|TEQEQ
name|r3
decl_stmt|,#1
comment|//if error
name|BEQ
name|retryPointer_testAndSetOrdered
comment|//then goto retry }
name|RSBS
name|r0
decl_stmt|,
name|r3
decl_stmt|,#1
comment|//return (r3 == 0)
name|MOVCC
name|r0
decl_stmt|,#0
name|BX
name|r14
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_fetchAndStoreRelaxed
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreRelaxed
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_fetchAndStoreAcquire
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreAcquire
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_fetchAndStoreRelease
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreRelease
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_fetchAndStoreOrdered
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|CODE32
comment|//R0 = _q_value
comment|//R1 = newValue
name|retryPointer_fetchAndStoreOrdered
name|LDREX
name|r3
decl_stmt|,[
name|r0
decl|]
comment|//r3 = *_q_value
name|STREX
name|r2
decl_stmt|,
name|r1
decl_stmt|,[
name|r0
decl|]
comment|//*_q_value = newValue, r2 = error
name|TEQ
name|r2
decl_stmt|,#0
comment|//if error
name|BNE
name|retryPointer_fetchAndStoreOrdered
comment|//then goto retry
name|MOV
name|r0
decl_stmt|,
name|r3
comment|//return r3
name|BX
name|r14
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_fetchAndAddRelaxed
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddRelaxed
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_fetchAndAddRelease
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddRelease
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_fetchAndAddAcquire
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddAcquire
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
name|CODE32
comment|//fall through
block|}
end_function
begin_function
name|Q_CORE_EXPORT
name|asm
DECL|function|QBasicAtomicPointer_fetchAndAddOrdered
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
name|CODE32
comment|//R0 = _q_value
comment|//R1 = valueToAdd
name|STMDB
name|sp
operator|!
operator|,
block|{
name|r12
block|,
name|lr
block|}
name|retryPointer_fetchAndAddOrdered
name|LDREX
name|r2
operator|,
index|[
name|r0
index|]
comment|//r2 = *_q_value
name|ADD
name|r3
operator|,
name|r2
operator|,
name|r1
comment|//r3 = r2 + r1
name|STREX
name|r12
operator|,
name|r3
operator|,
index|[
name|r0
index|]
comment|//*_q_value = r3, r12 = error
name|TEQ
name|r12
operator|,
operator|#
literal|0
comment|//if error
name|BNE
name|retryPointer_fetchAndAddOrdered
comment|//then retry
name|MOV
name|r0
operator|,
name|r2
comment|//return r2
name|LDMIA
name|sp
operator|!
operator|,
block|{
name|r12
block|,
name|pc
block|}
block|}
end_function
begin_pragma
pragma|#
directive|pragma
name|pop
end_pragma
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GCCE
argument_list|)
end_elif
begin_decl_stmt
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|bool
name|QBasicAtomicInt_testAndSetRelaxed
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|expectedValue
argument_list|,
name|int
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|bool
name|QBasicAtomicInt_testAndSetAcquire
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|expectedValue
argument_list|,
name|int
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|bool
name|QBasicAtomicInt_testAndSetRelease
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|expectedValue
argument_list|,
name|int
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|bool
name|QBasicAtomicInt_testAndSetOrdered
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|expectedValue
argument_list|,
name|int
name|newValue
argument_list|)
argument_list|{
comment|//R0 = _q_value
comment|//R1 = expectedValue
comment|//R2 = newValue
name|asm
argument_list|(
literal|"retry_testAndSetOrdered:"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"    LDREX    r3,[r0]"
argument_list|)
argument_list|;
comment|//r3 = *_q_value
name|asm
argument_list|(
literal|"    EORS     r3,r3,r1"
argument_list|)
argument_list|;
comment|//if (r3 == expectedValue) {
name|asm
argument_list|(
literal|"    STREXEQ  r3,r2,[r0]"
argument_list|)
argument_list|;
comment|//*_q_value = newvalue, r3 = error
name|asm
argument_list|(
literal|"    TEQEQ    r3,#1"
argument_list|)
argument_list|;
comment|//if error
name|asm
argument_list|(
literal|"    BEQ      retry_testAndSetOrdered"
argument_list|)
argument_list|;
comment|//then goto retry }
name|asm
argument_list|(
literal|"    RSBS     r0,r3,#1"
argument_list|)
argument_list|;
comment|//return (r3 == 0)
name|asm
argument_list|(
literal|"    MOVCC    r0,#0"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"    BX       r14"
argument_list|)
argument_list|; }
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|int
name|QBasicAtomicInt_fetchAndStoreRelaxed
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|int
name|QBasicAtomicInt_fetchAndStoreAcquire
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|int
name|QBasicAtomicInt_fetchAndStoreRelease
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|int
name|QBasicAtomicInt_fetchAndStoreOrdered
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|newValue
argument_list|)
argument_list|{
comment|//R0 = _q_value
comment|//R1 = newValue
name|asm
argument_list|(
literal|"retry_fetchAndStoreOrdered:"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"    LDREX    r3,[r0]"
argument_list|)
argument_list|;
comment|//r3 = *_q_value
name|asm
argument_list|(
literal|"    STREX    r2,r1,[r0]"
argument_list|)
argument_list|;
comment|//*_q_value = newValue, r2 = error
name|asm
argument_list|(
literal|"    TEQ      r2,#0"
argument_list|)
argument_list|;
comment|//if error
name|asm
argument_list|(
literal|"    BNE      retry_fetchAndStoreOrdered"
argument_list|)
argument_list|;
comment|//then goto retry
name|asm
argument_list|(
literal|"    MOV      r0,r3"
argument_list|)
argument_list|;
comment|//return r3
name|asm
argument_list|(
literal|"    BX       r14"
argument_list|)
argument_list|; }
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|int
name|QBasicAtomicInt_fetchAndAddRelaxed
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|valueToAdd
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|int
name|QBasicAtomicInt_fetchAndAddAcquire
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|valueToAdd
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|int
name|QBasicAtomicInt_fetchAndAddRelease
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|valueToAdd
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|int
name|QBasicAtomicInt_fetchAndAddOrdered
argument_list|(
specifier|volatile
name|int
operator|*
name|_q_value
argument_list|,
name|int
name|valueToAdd
argument_list|)
argument_list|{
comment|//R0 = _q_value
comment|//R1 = valueToAdd
name|asm
argument_list|(
literal|"    STMDB    sp!,{r12,lr}"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"retry_fetchAndAddOrdered:"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"    LDREX    r2,[r0]"
argument_list|)
argument_list|;
comment|//r2 = *_q_value
name|asm
argument_list|(
literal|"    ADD      r3,r2,r1 "
argument_list|)
argument_list|;
comment|//r3 = r2 + r1
name|asm
argument_list|(
literal|"    STREX    r12,r3,[r0]"
argument_list|)
argument_list|;
comment|//*_q_value = r3, r12 = error
name|asm
argument_list|(
literal|"    TEQ      r12,#0"
argument_list|)
argument_list|;
comment|//if error
name|asm
argument_list|(
literal|"    BNE      retry_fetchAndAddOrdered"
argument_list|)
argument_list|;
comment|//then retry
name|asm
argument_list|(
literal|"    MOV      r0,r2"
argument_list|)
argument_list|;
comment|//return r2
name|asm
argument_list|(
literal|"    LDMIA    sp!,{r12,pc}"
argument_list|)
argument_list|; }
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|bool
name|QBasicAtomicPointer_testAndSetRelaxed
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|void
operator|*
name|expectedValue
argument_list|,
name|void
operator|*
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|bool
name|QBasicAtomicPointer_testAndSetRelease
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|void
operator|*
name|expectedValue
argument_list|,
name|void
operator|*
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|bool
name|QBasicAtomicPointer_testAndSetAcquire
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|void
operator|*
name|expectedValue
argument_list|,
name|void
operator|*
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|bool
name|QBasicAtomicPointer_testAndSetOrdered
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|void
operator|*
name|expectedValue
argument_list|,
name|void
operator|*
name|newValue
argument_list|)
argument_list|{
comment|//R0 = _q_value
comment|//R1 = expectedValue
comment|//R2 = newValue
name|asm
argument_list|(
literal|"retryPointer_testAndSetOrdered:"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"    LDREX    r3,[r0]"
argument_list|)
argument_list|;
comment|//r3 = *_q_value
name|asm
argument_list|(
literal|"    EORS     r3,r3,r1"
argument_list|)
argument_list|;
comment|//if (r3 == expectedValue) {
name|asm
argument_list|(
literal|"    STREXEQ  r3,r2,[r0]"
argument_list|)
argument_list|;
comment|//*_q_value = newvalue, r3 = error
name|asm
argument_list|(
literal|"    TEQEQ    r3,#1"
argument_list|)
argument_list|;
comment|//if error
name|asm
argument_list|(
literal|"    BEQ      retryPointer_testAndSetOrdered"
argument_list|)
argument_list|;
comment|//then goto retry }
name|asm
argument_list|(
literal|"    RSBS     r0,r3,#1"
argument_list|)
argument_list|;
comment|//return (r3 == 0)
name|asm
argument_list|(
literal|"    MOVCC    r0,#0"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"    BX       r14"
argument_list|)
argument_list|; }
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreRelaxed
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|void
operator|*
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreAcquire
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|void
operator|*
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreRelease
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|void
operator|*
name|newValue
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreOrdered
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|void
operator|*
name|newValue
argument_list|)
argument_list|{
comment|//R0 = _q_value
comment|//R1 = newValue
name|asm
argument_list|(
literal|"retryPointer_fetchAndStoreOrdered:"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"    LDREX    r3,[r0]"
argument_list|)
argument_list|;
comment|//r3 = *_q_value
name|asm
argument_list|(
literal|"    STREX    r2,r1,[r0]"
argument_list|)
argument_list|;
comment|//*_q_value = newValue, r2 = error
name|asm
argument_list|(
literal|"    TEQ      r2,#0"
argument_list|)
argument_list|;
comment|//if error
name|asm
argument_list|(
literal|"    BNE      retryPointer_fetchAndStoreOrdered"
argument_list|)
argument_list|;
comment|//then goto retry
name|asm
argument_list|(
literal|"    MOV      r0,r3"
argument_list|)
argument_list|;
comment|//return r3
name|asm
argument_list|(
literal|"    BX       r14"
argument_list|)
argument_list|; }
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddRelaxed
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|qptrdiff
name|valueToAdd
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddRelease
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|qptrdiff
name|valueToAdd
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddAcquire
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|qptrdiff
name|valueToAdd
argument_list|)
argument_list|{
comment|//fall through
argument_list|}
name|Q_CORE_EXPORT
name|__declspec
argument_list|(
name|naked
argument_list|)
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddOrdered
argument_list|(
name|void
operator|*
specifier|volatile
operator|*
name|_q_value
argument_list|,
name|qptrdiff
name|valueToAdd
argument_list|)
argument_list|{
comment|//R0 = _q_value
comment|//R1 = valueToAdd
name|asm
argument_list|(
literal|"    STMDB    sp!,{r12,lr}"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"retryPointer_fetchAndAddOrdered:"
argument_list|)
argument_list|;
name|asm
argument_list|(
literal|"    LDREX    r2,[r0]"
argument_list|)
argument_list|;
comment|//r2 = *_q_value
name|asm
argument_list|(
literal|"    ADD      r3,r2,r1"
argument_list|)
argument_list|;
comment|//r3 = r2 + r1
name|asm
argument_list|(
literal|"    STREX    r12,r3,[r0]"
argument_list|)
argument_list|;
comment|//*_q_value = r3, r12 = error
name|asm
argument_list|(
literal|"    TEQ      r12,#0"
argument_list|)
argument_list|;
comment|//if error
name|asm
argument_list|(
literal|"    BNE      retryPointer_fetchAndAddOrdered"
argument_list|)
argument_list|;
comment|//then retry
name|asm
argument_list|(
literal|"    MOV      r0,r2"
argument_list|)
argument_list|;
comment|//return r2
name|asm
argument_list|(
literal|"    LDMIA    sp!,{r12,pc}"
argument_list|)
argument_list|; }
else|#
directive|else
error|#
directive|error
error|unknown arm compiler
endif|#
directive|endif
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
