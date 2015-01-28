begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_MAP_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_MAP_H
define|#
directive|define
name|QTCONCURRENT_MAP_H
end_define
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrent_global.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentmapkernel.h>
end_include
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentreducekernel.h>
end_include
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentfunctionwrappers.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|Q_QDOC
name|namespace
name|QtConcurrent
block|{
name|QFuture
operator|<
name|void
operator|>
name|map
argument_list|(
argument|Sequence&sequence
argument_list|,
argument|MapFunction function
argument_list|)
expr_stmt|;
name|QFuture
operator|<
name|void
operator|>
name|map
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunction function
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|T
operator|>
name|mapped
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunction function
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|T
operator|>
name|mapped
argument_list|(
argument|ConstIterator begin
argument_list|,
argument|ConstIterator end
argument_list|,
argument|MapFunction function
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|T
operator|>
name|mappedReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunction function
argument_list|,
argument|ReduceFunction function
argument_list|,
argument|QtConcurrent::ReduceOptions options = UnorderedReduce | SequentialReduce
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|T
operator|>
name|mappedReduced
argument_list|(
argument|ConstIterator begin
argument_list|,
argument|ConstIterator end
argument_list|,
argument|MapFunction function
argument_list|,
argument|ReduceFunction function
argument_list|,
argument|QtConcurrent::ReduceOptions options = UnorderedReduce | SequentialReduce
argument_list|)
expr_stmt|;
name|void
name|blockingMap
parameter_list|(
name|Sequence
modifier|&
name|sequence
parameter_list|,
name|MapFunction
name|function
parameter_list|)
function_decl|;
name|void
name|blockingMap
parameter_list|(
name|Iterator
name|begin
parameter_list|,
name|Iterator
name|end
parameter_list|,
name|MapFunction
name|function
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|blockingMapped
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunction function
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|blockingMapped
argument_list|(
argument|ConstIterator begin
argument_list|,
argument|ConstIterator end
argument_list|,
argument|MapFunction function
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|blockingMappedReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunction function
argument_list|,
argument|ReduceFunction function
argument_list|,
argument|QtConcurrent::ReduceOptions options = UnorderedReduce | SequentialReduce
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|blockingMappedReduced
argument_list|(
argument|ConstIterator begin
argument_list|,
argument|ConstIterator end
argument_list|,
argument|MapFunction function
argument_list|,
argument|ReduceFunction function
argument_list|,
argument|QtConcurrent::ReduceOptions options = UnorderedReduce | SequentialReduce
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace QtConcurrent
end_comment
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|namespace
name|QtConcurrent
block|{
comment|// map() on sequences
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|MapFunctor
operator|>
name|QFuture
operator|<
name|void
operator|>
name|map
argument_list|(
argument|Sequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
return|return
name|startMap
argument_list|(
name|sequence
operator|.
name|begin
argument_list|()
argument_list|,
name|sequence
operator|.
name|end
argument_list|()
argument_list|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
argument_list|)
return|;
block|}
comment|// map() on iterators
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|>
name|QFuture
operator|<
name|void
operator|>
name|map
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
return|return
name|startMap
argument_list|(
name|begin
argument_list|,
name|end
argument_list|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
argument_list|)
return|;
block|}
comment|// mappedReduced() for sequences.
name|template
operator|<
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
name|QFuture
operator|<
name|ResultType
operator|>
name|mappedReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startMappedReduced
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|,
name|ResultType
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|reduce
argument_list|)
operator|,
name|options
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|QFuture
operator|<
name|typename
name|QtPrivate
operator|::
name|ReduceResultType
operator|<
name|ReduceFunctor
operator|>
operator|::
name|ResultType
operator|>
name|mappedReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startMappedReduced
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|,
name|typename
name|QtPrivate
operator|::
name|ReduceResultType
operator|<
name|ReduceFunctor
operator|>
operator|::
name|ResultType
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|reduce
argument_list|)
operator|,
name|options
operator|)
return|;
block|}
comment|// mappedReduced() for iterators
name|template
operator|<
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
name|QFuture
operator|<
name|ResultType
operator|>
name|mappedReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startMappedReduced
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|,
name|ResultType
operator|>
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|reduce
argument_list|)
operator|,
name|options
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|QFuture
operator|<
name|typename
name|QtPrivate
operator|::
name|ReduceResultType
operator|<
name|ReduceFunctor
operator|>
operator|::
name|ResultType
operator|>
name|mappedReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startMappedReduced
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|,
name|typename
name|QtPrivate
operator|::
name|ReduceResultType
operator|<
name|ReduceFunctor
operator|>
operator|::
name|ResultType
operator|>
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|reduce
argument_list|)
operator|,
name|options
operator|)
return|;
block|}
comment|// mapped() for sequences
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|MapFunctor
operator|>
name|QFuture
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|>
name|mapped
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
return|return
name|startMapped
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|)
return|;
block|}
comment|// mapped() for iterator ranges.
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|>
name|QFuture
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|>
name|mapped
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
return|return
name|startMapped
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|>
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|)
return|;
block|}
comment|// blockingMap() for sequences
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|MapFunctor
operator|>
name|void
name|blockingMap
argument_list|(
argument|Sequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
name|startMap
argument_list|(
name|sequence
operator|.
name|begin
argument_list|()
argument_list|,
name|sequence
operator|.
name|end
argument_list|()
argument_list|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
argument_list|)
operator|.
name|startBlocking
argument_list|()
block|; }
comment|// blockingMap() for iterator ranges
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|>
name|void
name|blockingMap
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
name|startMap
argument_list|(
name|begin
argument_list|,
name|end
argument_list|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
argument_list|)
operator|.
name|startBlocking
argument_list|()
block|; }
comment|// blockingMappedReduced() for sequences
name|template
operator|<
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
name|ResultType
name|blockingMappedReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|QtConcurrent
operator|::
name|startMappedReduced
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|,
name|ResultType
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|reduce
argument_list|)
operator|,
name|options
operator|)
operator|.
name|startBlocking
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|,
name|typename
name|Sequence
operator|>
name|typename
name|QtPrivate
operator|::
name|ReduceResultType
operator|<
name|ReduceFunctor
operator|>
operator|::
name|ResultType
name|blockingMappedReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|QtConcurrent
operator|::
name|startMappedReduced
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|,
name|typename
name|QtPrivate
operator|::
name|ReduceResultType
operator|<
name|ReduceFunctor
operator|>
operator|::
name|ResultType
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|reduce
argument_list|)
operator|,
name|options
operator|)
operator|.
name|startBlocking
argument_list|()
return|;
block|}
comment|// blockingMappedReduced() for iterator ranges
name|template
operator|<
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
name|ResultType
name|blockingMappedReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|QtConcurrent::ReduceOptions options = QtConcurrent::ReduceOptions(QtConcurrent::UnorderedReduce | QtConcurrent::SequentialReduce)
argument_list|)
block|{
return|return
name|QtConcurrent
operator|::
name|startMappedReduced
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|,
name|ResultType
operator|>
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|reduce
argument_list|)
operator|,
name|options
operator|)
operator|.
name|startBlocking
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|typename
name|QtPrivate
operator|::
name|ReduceResultType
operator|<
name|ReduceFunctor
operator|>
operator|::
name|ResultType
name|blockingMappedReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|QtConcurrent::ReduceOptions options = QtConcurrent::ReduceOptions(QtConcurrent::UnorderedReduce | QtConcurrent::SequentialReduce)
argument_list|)
block|{
return|return
name|QtConcurrent
operator|::
name|startMappedReduced
operator|<
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|void
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
operator|,
name|typename
name|QtPrivate
operator|::
name|ReduceResultType
operator|<
name|ReduceFunctor
operator|>
operator|::
name|ResultType
operator|>
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|reduce
argument_list|)
operator|,
name|options
operator|)
operator|.
name|startBlocking
argument_list|()
return|;
block|}
comment|// mapped() for sequences with a different putput sequence type.
name|template
operator|<
name|typename
name|OutputSequence
operator|,
name|typename
name|InputSequence
operator|,
name|typename
name|MapFunctor
operator|>
name|OutputSequence
name|blockingMapped
argument_list|(
argument|const InputSequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
return|return
name|blockingMappedReduced
operator|<
name|OutputSequence
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|PushBackWrapper
argument_list|()
operator|,
name|QtConcurrent
operator|::
name|OrderedReduce
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|MapFunctor
operator|,
name|typename
name|InputSequence
operator|>
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|InputSequence
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
name|blockingMapped
argument_list|(
argument|const InputSequence&sequence
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
typedef|typedef
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|InputSequence
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
name|OutputSequence
expr_stmt|;
return|return
name|blockingMappedReduced
operator|<
name|OutputSequence
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|PushBackWrapper
argument_list|()
operator|,
name|QtConcurrent
operator|::
name|OrderedReduce
operator|)
return|;
block|}
end_decl_stmt
begin_comment
comment|// mapped()  for iterator ranges
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|>
name|Sequence
name|blockingMapped
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
return|return
name|blockingMappedReduced
operator|<
name|Sequence
operator|>
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|PushBackWrapper
argument_list|()
operator|,
name|QtConcurrent
operator|::
name|OrderedReduce
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|MapFunctor
operator|>
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|Iterator
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
name|blockingMapped
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|MapFunctor map
argument_list|)
block|{
typedef|typedef
name|typename
name|QtPrivate
operator|::
name|MapResultType
operator|<
name|Iterator
operator|,
name|MapFunctor
operator|>
operator|::
name|ResultType
name|OutputSequence
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|blockingMappedReduced
operator|<
name|OutputSequence
operator|>
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|map
argument_list|)
operator|,
name|QtPrivate
operator|::
name|PushBackWrapper
argument_list|()
operator|,
name|QtConcurrent
operator|::
name|OrderedReduce
operator|)
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
comment|// Q_QDOC
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
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
