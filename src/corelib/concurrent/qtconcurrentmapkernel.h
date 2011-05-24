begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_MAPKERNEL_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_MAPKERNEL_H
define|#
directive|define
name|QTCONCURRENT_MAPKERNEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qtconcurrentiteratekernel.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtconcurrentreducekernel.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifndef|#
directive|ifndef
name|qdoc
name|namespace
name|QtConcurrent
decl_stmt|{
comment|// map kernel, works with both parallel-for and parallel-while
decl_stmt|template<typename Iterator
operator|,
decl_stmt|typename MapFunctor> class MapKernel : public IterateKernel<Iterator
operator|,
decl_stmt|void>
block|{
name|MapFunctor
name|map
decl_stmt|;
name|public
label|:
typedef|typedef
name|void
name|ReturnType
typedef|;
name|MapKernel
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor _map
argument_list|)
block|:
name|IterateKernel
operator|<
name|Iterator
operator|,
name|void
operator|>
operator|(
name|begin
operator|,
name|end
operator|)
operator|,
name|map
argument_list|(
argument|_map
argument_list|)
block|{ }
name|bool
name|runIteration
argument_list|(
argument|Iterator it
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
block|{
name|map
argument_list|(
operator|*
name|it
argument_list|)
block|;
return|return
name|false
return|;
block|}
name|bool
name|runIterations
parameter_list|(
name|Iterator
name|sequenceBeginIterator
parameter_list|,
name|int
name|beginIndex
parameter_list|,
name|int
name|endIndex
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
name|Iterator
name|it
init|=
name|sequenceBeginIterator
decl_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
name|beginIndex
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|beginIndex
init|;
name|i
operator|<
name|endIndex
condition|;
operator|++
name|i
control|)
block|{
name|runIteration
argument_list|(
name|it
argument_list|,
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|ReducedResultType
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|,
name|typename
name|Reducer
operator|=
name|ReduceKernel
operator|<
name|ReduceFunctor
operator|,
name|ReducedResultType
operator|,
name|typename
name|MapFunctor
operator|::
name|result_type
operator|>
expr|>
name|class
name|MappedReducedKernel
operator|:
name|public
name|IterateKernel
operator|<
name|Iterator
operator|,
name|ReducedResultType
operator|>
block|{
name|ReducedResultType
name|reducedResult
block|;
name|MapFunctor
name|map
block|;
name|ReduceFunctor
name|reduce
block|;
name|Reducer
name|reducer
block|;
name|public
operator|:
typedef|typedef
name|ReducedResultType
name|ReturnType
typedef|;
name|MappedReducedKernel
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor _map
argument_list|,
argument|ReduceFunctor _reduce
argument_list|,
argument|ReduceOptions reduceOptions
argument_list|)
operator|:
name|IterateKernel
operator|<
name|Iterator
operator|,
name|ReducedResultType
operator|>
operator|(
name|begin
operator|,
name|end
operator|)
operator|,
name|reducedResult
argument_list|()
operator|,
name|map
argument_list|(
name|_map
argument_list|)
operator|,
name|reduce
argument_list|(
name|_reduce
argument_list|)
operator|,
name|reducer
argument_list|(
argument|reduceOptions
argument_list|)
block|{ }
name|MappedReducedKernel
argument_list|(
argument|ReducedResultType initialValue
argument_list|,
argument|MapFunctor _map
argument_list|,
argument|ReduceFunctor _reduce
argument_list|)
operator|:
name|reducedResult
argument_list|(
name|initialValue
argument_list|)
operator|,
name|map
argument_list|(
name|_map
argument_list|)
operator|,
name|reduce
argument_list|(
argument|_reduce
argument_list|)
block|{ }
name|bool
name|runIteration
argument_list|(
argument|Iterator it
argument_list|,
argument|int index
argument_list|,
argument|ReducedResultType *
argument_list|)
block|{
name|IntermediateResults
operator|<
name|typename
name|MapFunctor
operator|::
name|result_type
operator|>
name|results
block|;
name|results
operator|.
name|begin
operator|=
name|index
block|;
name|results
operator|.
name|end
operator|=
name|index
operator|+
literal|1
block|;
name|results
operator|.
name|vector
operator|.
name|append
argument_list|(
name|map
argument_list|(
operator|*
name|it
argument_list|)
argument_list|)
block|;
name|reducer
operator|.
name|runReduce
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|,
name|results
argument_list|)
block|;
return|return
name|false
return|;
block|}
end_expr_stmt
begin_function
name|bool
name|runIterations
parameter_list|(
name|Iterator
name|sequenceBeginIterator
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|ReducedResultType
modifier|*
parameter_list|)
block|{
name|IntermediateResults
operator|<
name|typename
name|MapFunctor
operator|::
name|result_type
operator|>
name|results
expr_stmt|;
name|results
operator|.
name|begin
operator|=
name|begin
expr_stmt|;
name|results
operator|.
name|end
operator|=
name|end
expr_stmt|;
name|results
operator|.
name|vector
operator|.
name|reserve
argument_list|(
name|end
operator|-
name|begin
argument_list|)
expr_stmt|;
name|Iterator
name|it
init|=
name|sequenceBeginIterator
decl_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
name|begin
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|begin
init|;
name|i
operator|<
name|end
condition|;
operator|++
name|i
control|)
block|{
name|results
operator|.
name|vector
operator|.
name|append
argument_list|(
name|map
argument_list|(
operator|*
operator|(
name|it
operator|)
argument_list|)
argument_list|)
expr_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|reducer
operator|.
name|runReduce
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|,
name|results
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function
begin_function
name|void
name|finish
parameter_list|()
block|{
name|reducer
operator|.
name|finish
argument_list|(
name|reduce
argument_list|,
name|reducedResult
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|bool
name|shouldThrottleThread
parameter_list|()
block|{
return|return
name|IterateKernel
operator|<
name|Iterator
operator|,
name|ReducedResultType
operator|>
operator|::
name|shouldThrottleThread
argument_list|()
operator|||
name|reducer
operator|.
name|shouldThrottle
argument_list|()
return|;
block|}
end_function
begin_function
name|bool
name|shouldStartThread
parameter_list|()
block|{
return|return
name|IterateKernel
operator|<
name|Iterator
operator|,
name|ReducedResultType
operator|>
operator|::
name|shouldStartThread
argument_list|()
operator|&&
name|reducer
operator|.
name|shouldStartThread
argument_list|()
return|;
block|}
end_function
begin_typedef
typedef|typedef
name|ReducedResultType
name|ResultType
typedef|;
end_typedef
begin_function
name|ReducedResultType
modifier|*
name|result
parameter_list|()
block|{
return|return
operator|&
name|reducedResult
return|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|>
name|class
name|MappedEachKernel
operator|:
name|public
name|IterateKernel
operator|<
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|::
name|result_type
operator|>
block|{
name|MapFunctor
name|map
block|;
typedef|typedef
name|typename
name|MapFunctor
operator|::
name|result_type
name|T
expr_stmt|;
name|public
operator|:
end_expr_stmt
begin_typedef
typedef|typedef
name|T
name|ReturnType
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
name|ResultType
typedef|;
end_typedef
begin_macro
name|MappedEachKernel
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor _map
argument_list|)
end_macro
begin_expr_stmt
unit|:
name|IterateKernel
operator|<
name|Iterator
operator|,
name|T
operator|>
operator|(
name|begin
operator|,
name|end
operator|)
operator|,
name|map
argument_list|(
argument|_map
argument_list|)
block|{ }
name|bool
name|runIteration
argument_list|(
argument|Iterator it
argument_list|,
argument|int
argument_list|,
argument|T *result
argument_list|)
block|{
operator|*
name|result
operator|=
name|map
argument_list|(
operator|*
name|it
argument_list|)
block|;
return|return
name|true
return|;
block|}
end_expr_stmt
begin_function
name|bool
name|runIterations
parameter_list|(
name|Iterator
name|sequenceBeginIterator
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|,
name|T
modifier|*
name|results
parameter_list|)
block|{
name|Iterator
name|it
init|=
name|sequenceBeginIterator
decl_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
name|begin
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|begin
init|;
name|i
operator|<
name|end
condition|;
operator|++
name|i
control|)
block|{
name|runIteration
argument_list|(
name|it
argument_list|,
name|i
argument_list|,
name|results
operator|+
operator|(
name|i
operator|-
name|begin
operator|)
argument_list|)
expr_stmt|;
name|advance
argument_list|(
name|it
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|Functor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|void
operator|>
name|startMap
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|Functor functor
argument_list|)
block|{
return|return
name|startThreadEngine
argument_list|(
argument|new MapKernel<Iterator
argument_list|,
argument|Functor>(begin, end, functor)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|Functor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|T
operator|>
name|startMapped
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|Functor functor
argument_list|)
block|{
return|return
name|startThreadEngine
argument_list|(
argument|new MappedEachKernel<Iterator
argument_list|,
argument|Functor>(begin, end, functor)
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|/*     The SequnceHolder class is used to hold a reference to the     sequence we are working on. */
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|Base
operator|,
name|typename
name|Functor
operator|>
expr|struct
name|SequenceHolder1
operator|:
name|public
name|Base
block|{
name|SequenceHolder1
argument_list|(
argument|const Sequence&_sequence
argument_list|,
argument|Functor functor
argument_list|)
operator|:
name|Base
argument_list|(
name|_sequence
operator|.
name|begin
argument_list|()
argument_list|,
name|_sequence
operator|.
name|end
argument_list|()
argument_list|,
name|functor
argument_list|)
block|,
name|sequence
argument_list|(
argument|_sequence
argument_list|)
block|{ }
name|Sequence
name|sequence
block|;
name|void
name|finish
argument_list|()
block|{
name|Base
operator|::
name|finish
argument_list|()
block|;
comment|// Clear the sequence to make sure all temporaries are destroyed
comment|// before finished is signaled.
name|sequence
operator|=
name|Sequence
argument_list|()
block|;     }
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Sequence
operator|,
name|typename
name|Functor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|T
operator|>
name|startMapped
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|Functor functor
argument_list|)
block|{
typedef|typedef
name|SequenceHolder1
operator|<
name|Sequence
operator|,
name|MappedEachKernel
operator|<
name|typename
name|Sequence
operator|::
name|const_iterator
operator|,
name|Functor
operator|>
operator|,
name|Functor
operator|>
name|SequenceHolderType
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|startThreadEngine
argument_list|(
argument|new SequenceHolderType(sequence, functor)
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|IntermediateType
operator|,
name|typename
name|ResultType
operator|,
name|typename
name|Sequence
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|ResultType
operator|>
name|startMappedReduced
argument_list|(
argument|const Sequence& sequence
argument_list|,
argument|MapFunctor mapFunctor
argument_list|,
argument|ReduceFunctor reduceFunctor
argument_list|,
argument|ReduceOptions options
argument_list|)
block|{
typedef|typedef
name|typename
name|Sequence
operator|::
name|const_iterator
name|Iterator
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|ReduceKernel
operator|<
name|ReduceFunctor
operator|,
name|ResultType
operator|,
name|IntermediateType
operator|>
name|Reducer
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|MappedReducedKernel
operator|<
name|ResultType
operator|,
name|Iterator
operator|,
name|MapFunctor
operator|,
name|ReduceFunctor
operator|,
name|Reducer
operator|>
name|MappedReduceType
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|SequenceHolder2
operator|<
name|Sequence
operator|,
name|MappedReduceType
operator|,
name|MapFunctor
operator|,
name|ReduceFunctor
operator|>
name|SequenceHolderType
expr_stmt|;
end_typedef
begin_return
return|return
name|startThreadEngine
argument_list|(
argument|new SequenceHolderType(sequence, mapFunctor, reduceFunctor, options)
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|IntermediateType
operator|,
name|typename
name|ResultType
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|ResultType
operator|>
name|startMappedReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor mapFunctor
argument_list|,
argument|ReduceFunctor reduceFunctor
argument_list|,
argument|ReduceOptions options
argument_list|)
block|{
typedef|typedef
name|ReduceKernel
operator|<
name|ReduceFunctor
operator|,
name|ResultType
operator|,
name|IntermediateType
operator|>
name|Reducer
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|MappedReducedKernel
operator|<
name|ResultType
operator|,
name|Iterator
operator|,
name|MapFunctor
operator|,
name|ReduceFunctor
operator|,
name|Reducer
operator|>
name|MappedReduceType
expr_stmt|;
end_typedef
begin_return
return|return
name|startThreadEngine
argument_list|(
argument|new MappedReduceType(begin, end, mapFunctor, reduceFunctor, options)
argument_list|)
return|;
end_return
begin_comment
unit|}  }
comment|// namespace QtConcurrent
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//qdoc
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
comment|// QT_NO_CONCURRENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
