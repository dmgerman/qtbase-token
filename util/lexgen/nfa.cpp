begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"nfa.h"
end_include
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_function
DECL|function|createSingleInputNFA
name|NFA
name|NFA
operator|::
name|createSingleInputNFA
parameter_list|(
name|InputType
name|input
parameter_list|)
block|{
name|NFA
name|result
decl_stmt|;
name|result
operator|.
name|initialize
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|result
operator|.
name|initialState
argument_list|,
name|input
argument_list|,
name|result
operator|.
name|finalState
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|createSymbolNFA
name|NFA
name|NFA
operator|::
name|createSymbolNFA
parameter_list|(
specifier|const
name|QString
modifier|&
name|symbol
parameter_list|)
block|{
name|NFA
name|result
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
name|Epsilon
argument_list|)
decl_stmt|;
name|result
operator|.
name|states
index|[
name|result
operator|.
name|finalState
index|]
operator|.
name|symbol
operator|=
name|symbol
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|NFA
operator|::
name|initialize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|states
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|states
operator|.
name|fill
argument_list|(
name|State
argument_list|()
argument_list|)
expr_stmt|;
name|initialState
operator|=
literal|0
expr_stmt|;
name|finalState
operator|=
name|size
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addTransition
name|void
name|NFA
operator|::
name|addTransition
parameter_list|(
name|int
name|from
parameter_list|,
name|InputType
name|input
parameter_list|,
name|int
name|to
parameter_list|)
block|{
name|assertValidState
argument_list|(
name|from
argument_list|)
expr_stmt|;
name|assertValidState
argument_list|(
name|to
argument_list|)
expr_stmt|;
name|states
index|[
name|from
index|]
operator|.
name|transitions
operator|.
name|insertMulti
argument_list|(
name|input
argument_list|,
name|to
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copyFrom
name|void
name|NFA
operator|::
name|copyFrom
parameter_list|(
specifier|const
name|NFA
modifier|&
name|other
parameter_list|,
name|int
name|baseState
parameter_list|)
block|{
name|assertValidState
argument_list|(
name|baseState
argument_list|)
expr_stmt|;
name|assertValidState
argument_list|(
name|baseState
operator|+
name|other
operator|.
name|states
operator|.
name|count
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|other
operator|.
name|states
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|State
name|s
init|=
name|other
operator|.
name|states
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
for|for
control|(
name|TransitionMap
operator|::
name|Iterator
name|it
init|=
name|s
operator|.
name|transitions
operator|.
name|begin
argument_list|()
init|,
name|end
init|=
name|s
operator|.
name|transitions
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
operator|*
name|it
operator|+=
name|baseState
expr_stmt|;
name|states
index|[
name|baseState
operator|+
name|i
index|]
operator|=
name|s
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|initializeFromPair
name|void
name|NFA
operator|::
name|initializeFromPair
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|,
specifier|const
name|NFA
modifier|&
name|b
parameter_list|,
name|int
modifier|*
name|initialA
parameter_list|,
name|int
modifier|*
name|finalA
parameter_list|,
name|int
modifier|*
name|initialB
parameter_list|,
name|int
modifier|*
name|finalB
parameter_list|)
block|{
name|initialize
argument_list|(
name|a
operator|.
name|states
operator|.
name|count
argument_list|()
operator|+
name|b
operator|.
name|states
operator|.
name|count
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
name|int
name|baseIdxA
init|=
literal|1
decl_stmt|;
name|int
name|baseIdxB
init|=
literal|1
operator|+
name|a
operator|.
name|states
operator|.
name|count
argument_list|()
decl_stmt|;
operator|*
name|initialA
operator|=
name|a
operator|.
name|initialState
operator|+
name|baseIdxA
expr_stmt|;
operator|*
name|finalA
operator|=
name|a
operator|.
name|finalState
operator|+
name|baseIdxA
expr_stmt|;
operator|*
name|initialB
operator|=
name|b
operator|.
name|initialState
operator|+
name|baseIdxB
expr_stmt|;
operator|*
name|finalB
operator|=
name|b
operator|.
name|finalState
operator|+
name|baseIdxB
expr_stmt|;
name|copyFrom
argument_list|(
name|a
argument_list|,
name|baseIdxA
argument_list|)
expr_stmt|;
name|copyFrom
argument_list|(
name|b
argument_list|,
name|baseIdxB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createAlternatingNFA
name|NFA
name|NFA
operator|::
name|createAlternatingNFA
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|,
specifier|const
name|NFA
modifier|&
name|b
parameter_list|)
block|{
name|NFA
name|result
decl_stmt|;
name|int
name|newInitialA
decl_stmt|,
name|newFinalA
decl_stmt|,
name|newInitialB
decl_stmt|,
name|newFinalB
decl_stmt|;
name|result
operator|.
name|initializeFromPair
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
operator|&
name|newInitialA
argument_list|,
operator|&
name|newFinalA
argument_list|,
operator|&
name|newInitialB
argument_list|,
operator|&
name|newFinalB
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|result
operator|.
name|initialState
argument_list|,
name|Epsilon
argument_list|,
name|newInitialA
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|result
operator|.
name|initialState
argument_list|,
name|Epsilon
argument_list|,
name|newInitialB
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|newFinalA
argument_list|,
name|Epsilon
argument_list|,
name|result
operator|.
name|finalState
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|newFinalB
argument_list|,
name|Epsilon
argument_list|,
name|result
operator|.
name|finalState
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|createConcatenatingNFA
name|NFA
name|NFA
operator|::
name|createConcatenatingNFA
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|,
specifier|const
name|NFA
modifier|&
name|b
parameter_list|)
block|{
name|NFA
name|result
decl_stmt|;
name|int
name|initialA
decl_stmt|,
name|finalA
decl_stmt|,
name|initialB
decl_stmt|,
name|finalB
decl_stmt|;
name|result
operator|.
name|initializeFromPair
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
operator|&
name|initialA
argument_list|,
operator|&
name|finalA
argument_list|,
operator|&
name|initialB
argument_list|,
operator|&
name|finalB
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|result
operator|.
name|initialState
argument_list|,
name|Epsilon
argument_list|,
name|initialA
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|finalA
argument_list|,
name|Epsilon
argument_list|,
name|initialB
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|finalB
argument_list|,
name|Epsilon
argument_list|,
name|result
operator|.
name|finalState
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|createOptionalNFA
name|NFA
name|NFA
operator|::
name|createOptionalNFA
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|)
block|{
name|NFA
name|result
decl_stmt|;
name|result
operator|.
name|initialize
argument_list|(
name|a
operator|.
name|states
operator|.
name|count
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
name|int
name|baseIdxA
init|=
literal|1
decl_stmt|;
name|int
name|initialA
init|=
name|a
operator|.
name|initialState
operator|+
name|baseIdxA
decl_stmt|;
name|int
name|finalA
init|=
name|a
operator|.
name|finalState
operator|+
name|baseIdxA
decl_stmt|;
name|result
operator|.
name|copyFrom
argument_list|(
name|a
argument_list|,
name|baseIdxA
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|result
operator|.
name|initialState
argument_list|,
name|Epsilon
argument_list|,
name|initialA
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|result
operator|.
name|initialState
argument_list|,
name|Epsilon
argument_list|,
name|result
operator|.
name|finalState
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|finalA
argument_list|,
name|Epsilon
argument_list|,
name|initialA
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|finalA
argument_list|,
name|Epsilon
argument_list|,
name|result
operator|.
name|finalState
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|createStringNFA
name|NFA
name|NFA
operator|::
name|createStringNFA
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|str
parameter_list|)
block|{
name|NFA
name|result
decl_stmt|;
foreach|foreach
control|(
name|char
name|c
decl|,
name|str
control|)
block|{
name|NFA
name|ch
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
name|c
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|=
name|ch
expr_stmt|;
else|else
name|result
operator|=
name|NFA
operator|::
name|createConcatenatingNFA
argument_list|(
name|result
argument_list|,
name|ch
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|createSetNFA
name|NFA
name|NFA
operator|::
name|createSetNFA
parameter_list|(
specifier|const
name|QSet
argument_list|<
name|InputType
argument_list|>
modifier|&
name|set
parameter_list|)
block|{
name|NFA
name|result
decl_stmt|;
name|result
operator|.
name|initialize
argument_list|(
name|set
operator|.
name|count
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
name|int
name|state
init|=
literal|1
decl_stmt|;
for|for
control|(
name|QSet
argument_list|<
name|InputType
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|set
operator|.
name|constBegin
argument_list|()
init|,
name|end
init|=
name|set
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
operator|,
operator|++
name|state
control|)
block|{
name|result
operator|.
name|addTransition
argument_list|(
name|result
operator|.
name|initialState
argument_list|,
name|Epsilon
argument_list|,
name|state
argument_list|)
expr_stmt|;
name|result
operator|.
name|addTransition
argument_list|(
name|state
argument_list|,
operator|*
name|it
argument_list|,
name|result
operator|.
name|finalState
argument_list|)
expr_stmt|;
block|}
comment|/*     foreach (InputType input, set) {         NFA ch = NFA::createSingleInputNFA(input);         if (result.isEmpty())             result = ch;         else             result = NFA::createAlternatingNFA(result, ch);     }     */
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|createZeroOrOneNFA
name|NFA
name|NFA
operator|::
name|createZeroOrOneNFA
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|)
block|{
name|NFA
name|epsilonNFA
init|=
name|createSingleInputNFA
argument_list|(
name|Epsilon
argument_list|)
decl_stmt|;
return|return
name|NFA
operator|::
name|createAlternatingNFA
argument_list|(
name|a
argument_list|,
name|epsilonNFA
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|applyQuantity
name|NFA
name|NFA
operator|::
name|applyQuantity
parameter_list|(
specifier|const
name|NFA
modifier|&
name|a
parameter_list|,
name|int
name|minOccurrences
parameter_list|,
name|int
name|maxOccurrences
parameter_list|)
block|{
name|NFA
name|result
init|=
name|a
decl_stmt|;
name|NFA
name|epsilonNFA
init|=
name|createSingleInputNFA
argument_list|(
name|Epsilon
argument_list|)
decl_stmt|;
if|if
condition|(
name|minOccurrences
operator|==
literal|0
condition|)
block|{
name|result
operator|=
name|NFA
operator|::
name|createAlternatingNFA
argument_list|(
name|result
argument_list|,
name|epsilonNFA
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|minOccurrences
operator|--
expr_stmt|;
block|}
name|maxOccurrences
operator|--
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|minOccurrences
condition|;
operator|++
name|i
control|)
name|result
operator|=
name|NFA
operator|::
name|createConcatenatingNFA
argument_list|(
name|result
argument_list|,
name|a
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|minOccurrences
init|;
name|i
operator|<
name|maxOccurrences
condition|;
operator|++
name|i
control|)
name|result
operator|=
name|NFA
operator|::
name|createConcatenatingNFA
argument_list|(
name|result
argument_list|,
name|NFA
operator|::
name|createAlternatingNFA
argument_list|(
name|a
argument_list|,
name|epsilonNFA
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|debug
name|void
name|NFA
operator|::
name|debug
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"NFA has"
operator|<<
name|states
operator|.
name|count
argument_list|()
operator|<<
literal|"states"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"initial state is"
operator|<<
name|initialState
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"final state is"
operator|<<
name|finalState
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|states
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|State
modifier|&
name|s
init|=
name|states
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
for|for
control|(
name|TransitionMap
operator|::
name|ConstIterator
name|it
init|=
name|s
operator|.
name|transitions
operator|.
name|constBegin
argument_list|()
init|,
name|end
init|=
name|s
operator|.
name|transitions
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
name|qDebug
argument_list|()
operator|<<
literal|"transition from state"
operator|<<
name|i
operator|<<
literal|"to"
operator|<<
name|it
operator|.
name|value
argument_list|()
operator|<<
literal|"through"
operator|<<
operator|(
name|it
operator|.
name|key
argument_list|()
operator|==
name|Epsilon
condition|?
name|QString
argument_list|(
literal|"Epsilon"
argument_list|)
else|:
name|QString
argument_list|(
name|char
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|)
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|s
operator|.
name|symbol
operator|.
name|isEmpty
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"State"
operator|<<
name|i
operator|<<
literal|"leads to symbol"
operator|<<
name|s
operator|.
name|symbol
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// helper
end_comment
begin_typedef
DECL|typedef|DFAState
typedef|typedef
name|QSet
argument_list|<
name|int
argument_list|>
name|DFAState
typedef|;
end_typedef
begin_comment
comment|// that's a bad hash, but it's good enough for us
end_comment
begin_comment
comment|// and it allows us to use the nice QHash API :)
end_comment
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|DFAState
modifier|&
name|state
parameter_list|)
block|{
name|uint
name|val
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|int
name|s
decl|,
name|state
control|)
name|val
operator||=
name|qHash
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|val
return|;
block|}
end_function
begin_function
DECL|function|toDFA
name|DFA
name|NFA
operator|::
name|toDFA
parameter_list|()
specifier|const
block|{
name|DFA
name|result
decl_stmt|;
name|result
operator|.
name|reserve
argument_list|(
name|states
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|symbolReferenceCounts
decl_stmt|;
block|{
name|QSet
argument_list|<
name|int
argument_list|>
name|symbolStates
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|states
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
name|states
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|symbol
operator|.
name|isEmpty
argument_list|()
condition|)
name|symbolStates
operator|.
name|insert
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|epsilonStates
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|states
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|State
modifier|&
name|s
init|=
name|states
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
for|for
control|(
name|TransitionMap
operator|::
name|ConstIterator
name|transition
init|=
name|s
operator|.
name|transitions
operator|.
name|constBegin
argument_list|()
init|,
name|end
init|=
name|s
operator|.
name|transitions
operator|.
name|constEnd
argument_list|()
init|;
name|transition
operator|!=
name|end
condition|;
operator|++
name|transition
control|)
if|if
condition|(
name|transition
operator|.
name|key
argument_list|()
operator|==
name|Epsilon
operator|&&
name|symbolStates
operator|.
name|contains
argument_list|(
name|transition
operator|.
name|value
argument_list|()
argument_list|)
condition|)
name|epsilonStates
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|states
operator|.
name|at
argument_list|(
name|transition
operator|.
name|value
argument_list|()
argument_list|)
operator|.
name|symbol
argument_list|)
expr_stmt|;
block|}
name|int
name|lastCount
decl_stmt|;
do|do
block|{
name|lastCount
operator|=
name|epsilonStates
operator|.
name|count
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|states
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|State
modifier|&
name|s
init|=
name|states
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
for|for
control|(
name|TransitionMap
operator|::
name|ConstIterator
name|transition
init|=
name|s
operator|.
name|transitions
operator|.
name|constBegin
argument_list|()
init|,
name|end
init|=
name|s
operator|.
name|transitions
operator|.
name|constEnd
argument_list|()
init|;
name|transition
operator|!=
name|end
condition|;
operator|++
name|transition
control|)
if|if
condition|(
name|transition
operator|.
name|key
argument_list|()
operator|==
name|Epsilon
operator|&&
name|epsilonStates
operator|.
name|contains
argument_list|(
name|transition
operator|.
name|value
argument_list|()
argument_list|)
condition|)
name|epsilonStates
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|epsilonStates
operator|.
name|value
argument_list|(
name|transition
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
name|lastCount
operator|!=
name|epsilonStates
operator|.
name|count
argument_list|()
condition|)
do|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|states
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|State
modifier|&
name|s
init|=
name|states
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
for|for
control|(
name|TransitionMap
operator|::
name|ConstIterator
name|transition
init|=
name|s
operator|.
name|transitions
operator|.
name|constBegin
argument_list|()
init|,
name|end
init|=
name|s
operator|.
name|transitions
operator|.
name|constEnd
argument_list|()
init|;
name|transition
operator|!=
name|end
condition|;
operator|++
name|transition
control|)
block|{
if|if
condition|(
name|transition
operator|.
name|key
argument_list|()
operator|==
name|Epsilon
condition|)
continue|continue;
if|if
condition|(
name|symbolStates
operator|.
name|contains
argument_list|(
name|transition
operator|.
name|value
argument_list|()
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|symbol
init|=
name|states
operator|.
name|at
argument_list|(
name|transition
operator|.
name|value
argument_list|()
argument_list|)
operator|.
name|symbol
decl_stmt|;
name|symbolReferenceCounts
index|[
name|symbol
index|]
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|epsilonStates
operator|.
name|contains
argument_list|(
name|transition
operator|.
name|value
argument_list|()
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|symbol
init|=
name|epsilonStates
operator|.
name|value
argument_list|(
name|transition
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
name|symbolReferenceCounts
index|[
name|symbol
index|]
operator|++
expr_stmt|;
block|}
block|}
block|}
comment|/*         for (QHash<QString, int>::ConstIterator symIt = symbolReferenceCounts.constBegin(), symEnd = symbolReferenceCounts.constEnd();              symIt != symEnd; ++symIt)             qDebug()<< "symbol"<< symIt.key()<< "is reached"<< symIt.value()<< "times";             */
block|}
name|QSet
argument_list|<
name|InputType
argument_list|>
name|validInput
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|State
modifier|&
name|s
decl|,
name|states
control|)
for|for
control|(
name|TransitionMap
operator|::
name|ConstIterator
name|it
init|=
name|s
operator|.
name|transitions
operator|.
name|constBegin
argument_list|()
init|,
name|end
init|=
name|s
operator|.
name|transitions
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
if|if
condition|(
name|it
operator|.
name|key
argument_list|()
operator|!=
name|Epsilon
condition|)
name|validInput
operator|.
name|insert
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|)
expr_stmt|;
comment|// A DFA state can consist of multiple NFA states.
comment|// the dfaStateMap maps from these to the actual
comment|// state index within the resulting DFA vector
name|QHash
argument_list|<
name|DFAState
argument_list|,
name|int
argument_list|>
name|dfaStateMap
decl_stmt|;
name|QStack
argument_list|<
name|DFAState
argument_list|>
name|pendingDFAStates
decl_stmt|;
name|DFAState
name|startState
init|=
name|epsilonClosure
argument_list|(
name|QSet
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
name|initialState
argument_list|)
decl_stmt|;
name|result
operator|.
name|resize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|dfaStateMap
operator|.
name|insert
argument_list|(
name|startState
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pendingDFAStates
operator|.
name|push
argument_list|(
name|startState
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|pendingDFAStates
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|DFAState
name|state
init|=
name|pendingDFAStates
operator|.
name|pop
argument_list|()
decl_stmt|;
comment|//        qDebug()<< "processing"<< state<< "from the stack of pending states";
foreach|foreach
control|(
name|InputType
name|input
decl|,
name|validInput
control|)
block|{
name|QSet
argument_list|<
name|int
argument_list|>
name|reachableStates
decl_stmt|;
foreach|foreach
control|(
name|int
name|nfaState
decl|,
name|state
control|)
block|{
specifier|const
name|TransitionMap
modifier|&
name|transitions
init|=
name|states
operator|.
name|at
argument_list|(
name|nfaState
argument_list|)
operator|.
name|transitions
decl_stmt|;
name|TransitionMap
operator|::
name|ConstIterator
name|it
init|=
name|transitions
operator|.
name|find
argument_list|(
name|input
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|transitions
operator|.
name|constEnd
argument_list|()
operator|&&
name|it
operator|.
name|key
argument_list|()
operator|==
name|input
condition|)
block|{
name|reachableStates
operator|.
name|insert
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
block|}
if|if
condition|(
name|reachableStates
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
comment|//            qDebug()<< "can reach"<< reachableStates<< "from input"<< char(input);
name|QSet
argument_list|<
name|int
argument_list|>
name|closure
init|=
name|epsilonClosure
argument_list|(
name|reachableStates
argument_list|)
decl_stmt|;
comment|//            qDebug()<< "closure is"<< closure;
if|if
condition|(
operator|!
name|dfaStateMap
operator|.
name|contains
argument_list|(
name|closure
argument_list|)
condition|)
block|{
name|int
name|dfaState
init|=
name|result
operator|.
name|count
argument_list|()
decl_stmt|;
name|result
operator|.
name|append
argument_list|(
name|State
argument_list|()
argument_list|)
expr_stmt|;
name|QString
name|symbol
decl_stmt|;
name|int
name|refCount
init|=
name|INT_MAX
decl_stmt|;
foreach|foreach
control|(
name|int
name|nfaState
decl|,
name|closure
control|)
if|if
condition|(
operator|!
name|states
operator|.
name|at
argument_list|(
name|nfaState
argument_list|)
operator|.
name|symbol
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|//                        qDebug()<< "closure also contains symbol"<< states.at(nfaState).symbol;
name|QString
name|candidate
init|=
name|states
operator|.
name|at
argument_list|(
name|nfaState
argument_list|)
operator|.
name|symbol
decl_stmt|;
name|int
name|candidateRefCount
init|=
name|symbolReferenceCounts
operator|.
name|value
argument_list|(
name|candidate
argument_list|,
name|INT_MAX
argument_list|)
decl_stmt|;
if|if
condition|(
name|candidateRefCount
operator|<
name|refCount
condition|)
block|{
name|refCount
operator|=
name|candidateRefCount
expr_stmt|;
name|symbol
operator|=
name|candidate
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|symbol
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|.
name|last
argument_list|()
operator|.
name|symbol
operator|=
name|symbol
expr_stmt|;
name|dfaStateMap
operator|.
name|insert
argument_list|(
name|closure
argument_list|,
name|dfaState
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|pendingDFAStates
operator|.
name|contains
argument_list|(
name|closure
argument_list|)
argument_list|)
expr_stmt|;
name|pendingDFAStates
operator|.
name|prepend
argument_list|(
name|closure
argument_list|)
expr_stmt|;
block|}
name|result
index|[
name|dfaStateMap
operator|.
name|value
argument_list|(
name|state
argument_list|)
index|]
operator|.
name|transitions
operator|.
name|insert
argument_list|(
name|input
argument_list|,
name|dfaStateMap
operator|.
name|value
argument_list|(
name|closure
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|epsilonClosure
name|QSet
argument_list|<
name|int
argument_list|>
name|NFA
operator|::
name|epsilonClosure
parameter_list|(
specifier|const
name|QSet
argument_list|<
name|int
argument_list|>
modifier|&
name|initialClosure
parameter_list|)
specifier|const
block|{
name|QSet
argument_list|<
name|int
argument_list|>
name|closure
init|=
name|initialClosure
decl_stmt|;
name|closure
operator|.
name|reserve
argument_list|(
name|closure
operator|.
name|count
argument_list|()
operator|*
literal|4
argument_list|)
expr_stmt|;
name|QStack
argument_list|<
name|int
argument_list|>
name|stateStack
decl_stmt|;
name|stateStack
operator|.
name|resize
argument_list|(
name|closure
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|qCopy
argument_list|(
name|closure
operator|.
name|constBegin
argument_list|()
argument_list|,
name|closure
operator|.
name|constEnd
argument_list|()
argument_list|,
name|stateStack
operator|.
name|begin
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|stateStack
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|int
name|t
init|=
name|stateStack
operator|.
name|pop
argument_list|()
decl_stmt|;
specifier|const
name|TransitionMap
modifier|&
name|transitions
init|=
name|states
operator|.
name|at
argument_list|(
name|t
argument_list|)
operator|.
name|transitions
decl_stmt|;
name|TransitionMap
operator|::
name|ConstIterator
name|it
init|=
name|transitions
operator|.
name|find
argument_list|(
name|Epsilon
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|transitions
operator|.
name|constEnd
argument_list|()
operator|&&
name|it
operator|.
name|key
argument_list|()
operator|==
name|Epsilon
condition|)
block|{
specifier|const
name|int
name|u
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|closure
operator|.
name|contains
argument_list|(
name|u
argument_list|)
condition|)
block|{
name|closure
operator|.
name|insert
argument_list|(
name|u
argument_list|)
expr_stmt|;
name|stateStack
operator|.
name|push
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
operator|++
name|it
expr_stmt|;
block|}
block|}
return|return
name|closure
return|;
block|}
end_function
begin_function
DECL|function|setTerminationSymbol
name|void
name|NFA
operator|::
name|setTerminationSymbol
parameter_list|(
specifier|const
name|QString
modifier|&
name|symbol
parameter_list|)
block|{
name|states
index|[
name|finalState
index|]
operator|.
name|symbol
operator|=
name|symbol
expr_stmt|;
block|}
end_function
begin_function
DECL|function|debug
name|void
name|DFA
operator|::
name|debug
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
literal|"DFA has"
operator|<<
name|count
argument_list|()
operator|<<
literal|"states"
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|State
modifier|&
name|s
init|=
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
operator|.
name|transitions
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"State"
operator|<<
name|i
operator|<<
literal|"has no transitions"
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|TransitionMap
operator|::
name|ConstIterator
name|it
init|=
name|s
operator|.
name|transitions
operator|.
name|constBegin
argument_list|()
init|,
name|end
init|=
name|s
operator|.
name|transitions
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
name|qDebug
argument_list|()
operator|<<
literal|"transition from state"
operator|<<
name|i
operator|<<
literal|"to"
operator|<<
name|it
operator|.
name|value
argument_list|()
operator|<<
literal|"through"
operator|<<
operator|(
name|it
operator|.
name|key
argument_list|()
operator|==
name|Epsilon
condition|?
name|QString
argument_list|(
literal|"Epsilon"
argument_list|)
else|:
name|QString
argument_list|(
name|char
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|)
argument_list|)
operator|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|s
operator|.
name|symbol
operator|.
name|isEmpty
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"State"
operator|<<
name|i
operator|<<
literal|"leads to symbol"
operator|<<
name|s
operator|.
name|symbol
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|minimize
name|DFA
name|DFA
operator|::
name|minimize
parameter_list|()
specifier|const
block|{
name|QVector
argument_list|<
name|bool
argument_list|>
name|inequivalentStates
argument_list|(
name|count
argument_list|()
operator|*
name|count
argument_list|()
argument_list|)
decl_stmt|;
name|inequivalentStates
operator|.
name|fill
argument_list|(
literal|false
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|i
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|i
operator|!=
name|j
operator|&&
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|symbol
operator|!=
name|at
argument_list|(
name|j
argument_list|)
operator|.
name|symbol
condition|)
name|inequivalentStates
index|[
name|i
operator|*
name|count
argument_list|()
operator|+
name|j
index|]
operator|=
literal|true
expr_stmt|;
block|}
name|bool
name|done
decl_stmt|;
do|do
block|{
name|done
operator|=
literal|true
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|count
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|i
operator|==
name|j
condition|)
continue|continue;
if|if
condition|(
name|inequivalentStates
index|[
name|i
operator|*
name|count
argument_list|()
operator|+
name|j
index|]
condition|)
continue|continue;
if|if
condition|(
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|transitions
operator|.
name|keys
argument_list|()
operator|!=
name|at
argument_list|(
name|j
argument_list|)
operator|.
name|transitions
operator|.
name|keys
argument_list|()
condition|)
block|{
name|inequivalentStates
index|[
name|i
operator|*
name|count
argument_list|()
operator|+
name|j
index|]
operator|=
literal|true
expr_stmt|;
name|done
operator|=
literal|false
expr_stmt|;
continue|continue;
block|}
foreach|foreach
control|(
name|InputType
name|a
decl|,
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|transitions
operator|.
name|keys
argument_list|()
control|)
block|{
name|int
name|r
init|=
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|transitions
operator|.
name|value
argument_list|(
name|a
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|r
operator|==
operator|-
literal|1
condition|)
continue|continue;
name|int
name|s
init|=
name|at
argument_list|(
name|j
argument_list|)
operator|.
name|transitions
operator|.
name|value
argument_list|(
name|a
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
operator|==
operator|-
literal|1
condition|)
continue|continue;
if|if
condition|(
name|inequivalentStates
index|[
name|r
operator|*
name|count
argument_list|()
operator|+
name|s
index|]
operator|||
name|r
operator|==
name|s
condition|)
block|{
name|inequivalentStates
index|[
name|i
operator|*
name|count
argument_list|()
operator|+
name|j
index|]
operator|=
literal|true
expr_stmt|;
name|done
operator|=
literal|false
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
do|while
condition|(
operator|!
name|done
condition|)
do|;
name|QHash
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|statesToEliminate
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|i
condition|;
operator|++
name|j
control|)
if|if
condition|(
operator|!
name|inequivalentStates
index|[
name|i
operator|*
name|count
argument_list|()
operator|+
name|j
index|]
condition|)
block|{
name|statesToEliminate
operator|.
name|insertMulti
argument_list|(
name|i
argument_list|,
name|j
argument_list|)
expr_stmt|;
block|}
comment|/*     qDebug()<< "states to eliminiate:"<< statesToEliminate.count();;     qDebug()<< "merging"<< statesToEliminate;     debug();     */
return|return
operator|*
name|this
return|;
block|}
end_function
end_unit
