begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_ALPHA_H
end_ifndef
begin_define
DECL|macro|QATOMIC_ALPHA_H
define|#
directive|define
name|QATOMIC_ALPHA_H
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
DECL|function|isReferenceCountingNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isReferenceCountingNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isReferenceCountingWaitFree
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
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_expr_stmt
DECL|function|isTestAndSetNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isTestAndSetNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
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
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_expr_stmt
DECL|function|isFetchAndStoreNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndStoreNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
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
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_expr_stmt
DECL|function|isFetchAndAddNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndAddNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
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
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
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
name|true
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
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
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
name|true
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
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
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
name|true
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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_expr_stmt
DECL|function|ref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|ref
argument_list|()
block|{
specifier|register
name|int
name|old
block|,
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldl_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"addl  %0,1,%1\n"
comment|/* tmp=old+1;                              */
literal|"stl_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp == 0) goto 2;                   */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|int
name|old
block|,
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldl_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"subl  %0,1,%1\n"
comment|/* tmp=old-1;                              */
literal|"stl_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
operator|!=
literal|1
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
specifier|register
name|int
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldl_l %0,%1\n"
comment|/* ret=*ptr;                               */
literal|"cmpeq %0,%2,%0\n"
comment|/* if (ret==expected) ret=0; else ret=1;   */
literal|"beq   %0,3f\n"
comment|/* if (ret==0) goto 3;                     */
literal|"mov   %3,%0\n"
comment|/* ret=newval;                             */
literal|"stl_c %0,%1\n"
comment|/* if ((*ptr=ret)!=ret) ret=0; else ret=1; */
literal|"beq   %0,2f\n"
comment|/* if (ret==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
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
specifier|register
name|int
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldl_l %0,%1\n"
comment|/* ret=*ptr;                               */
literal|"cmpeq %0,%2,%0\n"
comment|/* if (ret==expected) ret=0; else ret=1;   */
literal|"beq   %0,3f\n"
comment|/* if (ret==0) goto 3;                     */
literal|"mov   %3,%0\n"
comment|/* ret=newval;                             */
literal|"stl_c %0,%1\n"
comment|/* if ((*ptr=ret)!=ret) ret=0; else ret=1; */
literal|"beq   %0,2f\n"
comment|/* if (ret==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
literal|"mb\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
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
specifier|register
name|int
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"mb\n"
literal|"1:\n"
literal|"ldl_l %0,%1\n"
comment|/* ret=*ptr;                               */
literal|"cmpeq %0,%2,%0\n"
comment|/* if (ret==expected) ret=0; else ret=1;   */
literal|"beq   %0,3f\n"
comment|/* if (ret==0) goto 3;                     */
literal|"mov   %3,%0\n"
comment|/* ret=newval;                             */
literal|"stl_c %0,%1\n"
comment|/* if ((*ptr=ret)!=ret) ret=0; else ret=1; */
literal|"beq   %0,2f\n"
comment|/* if (ret==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
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
specifier|register
name|int
name|old
block|,
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldl_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"mov   %3,%1\n"
comment|/* tmp=newval;                             */
literal|"stl_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|int
name|old
block|,
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldl_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"mov   %3,%1\n"
comment|/* tmp=newval;                             */
literal|"stl_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
literal|"mb\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|int
name|old
block|,
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"mb\n"
literal|"1:\n"
literal|"ldl_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"mov   %3,%1\n"
comment|/* tmp=newval;                             */
literal|"stl_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|int
name|old
block|,
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldl_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"addl  %0,%3,%1\n"
comment|/* tmp=old+value;                          */
literal|"stl_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp == 0) goto 2;                   */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|int
name|old
block|,
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldl_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"addl  %0,%3,%1\n"
comment|/* tmp=old+value;                          */
literal|"stl_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp == 0) goto 2;                   */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
literal|"mb\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|int
name|old
block|,
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"mb\n"
literal|"1:\n"
literal|"ldl_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"addl  %0,%3,%1\n"
comment|/* tmp=old+value;                          */
literal|"stl_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp == 0) goto 2;                   */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|void
operator|*
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldq_l %0,%1\n"
comment|/* ret=*ptr;                               */
literal|"cmpeq %0,%2,%0\n"
comment|/* if (ret==expected) tmp=0; else tmp=1;   */
literal|"beq   %0,3f\n"
comment|/* if (tmp==0) goto 3;                     */
literal|"mov   %3,%0\n"
comment|/* tmp=newval;                             */
literal|"stq_c %0,%1\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %0,2f\n"
comment|/* if (ret==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
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
specifier|register
name|void
operator|*
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldq_l %0,%1\n"
comment|/* ret=*ptr;                               */
literal|"cmpeq %0,%2,%0\n"
comment|/* if (ret==expected) tmp=0; else tmp=1;   */
literal|"beq   %0,3f\n"
comment|/* if (tmp==0) goto 3;                     */
literal|"mov   %3,%0\n"
comment|/* tmp=newval;                             */
literal|"stq_c %0,%1\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %0,2f\n"
comment|/* if (ret==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
literal|"mb\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
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
specifier|register
name|void
operator|*
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"mb\n"
literal|"1:\n"
literal|"ldq_l %0,%1\n"
comment|/* ret=*ptr;                               */
literal|"cmpeq %0,%2,%0\n"
comment|/* if (ret==expected) tmp=0; else tmp=1;   */
literal|"beq   %0,3f\n"
comment|/* if (tmp==0) goto 3;                     */
literal|"mov   %3,%0\n"
comment|/* tmp=newval;                             */
literal|"stq_c %0,%1\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %0,2f\n"
comment|/* if (ret==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
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
specifier|register
name|T
operator|*
name|old
block|,
operator|*
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldq_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"mov   %3,%1\n"
comment|/* tmp=newval;                             */
literal|"stq_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|T
operator|*
name|old
block|,
operator|*
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldq_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"mov   %3,%1\n"
comment|/* tmp=newval;                             */
literal|"stq_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
literal|"mb\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|T
operator|*
name|old
block|,
operator|*
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"mb\n"
literal|"1:\n"
literal|"ldq_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"mov   %3,%1\n"
comment|/* tmp=newval;                             */
literal|"stq_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp==0) goto 2;                     */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|old
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
specifier|register
name|T
operator|*
name|old
block|,
operator|*
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldq_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"addq  %0,%3,%1\n"
comment|/* tmp=old+value;                          */
literal|"stq_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp == 0) goto 2;                   */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|old
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
specifier|register
name|T
operator|*
name|old
block|,
operator|*
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"1:\n"
literal|"ldq_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"addq  %0,%3,%1\n"
comment|/* tmp=old+value;                          */
literal|"stq_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp == 0) goto 2;                   */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
literal|"mb\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|old
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
specifier|register
name|T
operator|*
name|old
block|,
operator|*
name|tmp
block|;
name|asm
specifier|volatile
operator|(
literal|"mb\n"
literal|"1:\n"
literal|"ldq_l %0,%2\n"
comment|/* old=*ptr;                               */
literal|"addq  %0,%3,%1\n"
comment|/* tmp=old+value;                          */
literal|"stq_c %1,%2\n"
comment|/* if ((*ptr=tmp)!=tmp) tmp=0; else tmp=1; */
literal|"beq   %1,2f\n"
comment|/* if (tmp == 0) goto 2;                   */
literal|"br    3f\n"
comment|/* goto 3;                                 */
literal|"2: br 1b\n"
comment|/* goto 1;                                 */
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|old
operator|)
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// !Q_CC_GNU
end_comment
begin_extern
extern|extern
literal|"C"
block|{
name|Q_CORE_EXPORT
name|int
name|q_atomic_test_and_set_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|expected
parameter_list|,
name|int
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_test_and_set_acquire_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|expected
parameter_list|,
name|int
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_test_and_set_release_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|expected
parameter_list|,
name|int
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_test_and_set_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|expected
parameter_list|,
name|void
modifier|*
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_increment
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_decrement
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_set_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
modifier|*
name|q_atomic_set_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_fetch_and_add_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_fetch_and_add_acquire_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_fetch_and_add_release_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
block|}
end_extern
begin_comment
comment|// extern "C"
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
return|return
name|q_atomic_increment
argument_list|(
operator|&
name|_q_value
argument_list|)
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
name|q_atomic_decrement
argument_list|(
operator|&
name|_q_value
argument_list|)
operator|!=
literal|0
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
name|q_atomic_test_and_set_int
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
operator|!=
literal|0
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
name|q_atomic_test_and_set_acquire_int
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
operator|!=
literal|0
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
name|q_atomic_test_and_set_release_int
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
operator|!=
literal|0
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
name|q_atomic_set_int
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
name|q_atomic_fetch_and_store_acquire_int
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
name|q_atomic_fetch_and_store_release_int
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
name|q_atomic_fetch_and_add_int
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
name|q_atomic_fetch_and_add_acquire_int
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
name|q_atomic_fetch_and_add_release_int
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
name|q_atomic_test_and_set_ptr
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
operator|!=
literal|0
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
name|q_atomic_test_and_set_acquire_ptr
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
operator|!=
literal|0
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
name|q_atomic_test_and_set_release_ptr
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
operator|!=
literal|0
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
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|q_atomic_set_ptr
argument_list|(
operator|&
name|_q_value
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
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|q_atomic_fetch_and_store_acquire_ptr
argument_list|(
operator|&
name|_q_value
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
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|q_atomic_fetch_and_store_release_ptr
argument_list|(
operator|&
name|_q_value
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
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|q_atomic_fetch_and_add_ptr
argument_list|(
operator|&
name|_q_value
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
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|q_atomic_fetch_and_add_acquire_ptr
argument_list|(
operator|&
name|_q_value
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
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|q_atomic_fetch_and_add_release_ptr
argument_list|(
operator|&
name|_q_value
argument_list|,
name|newValue
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_CC_GNU
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
name|testAndSetAcquire
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
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
name|fetchAndStoreAcquire
argument_list|(
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
return|return
name|fetchAndAddAcquire
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
return|return
name|testAndSetAcquire
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
name|fetchAndStoreAcquire
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
name|fetchAndAddAcquire
argument_list|(
name|valueToAdd
argument_list|)
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
comment|// QATOMIC_ALPHA_H
end_comment
end_unit
