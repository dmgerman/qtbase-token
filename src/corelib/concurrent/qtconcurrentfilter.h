begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_FILTER_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_FILTER_H
define|#
directive|define
name|QTCONCURRENT_FILTER_H
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
file|<QtCore/qtconcurrentfilterkernel.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtconcurrentfunctionwrappers.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifdef|#
directive|ifdef
name|qdoc
name|namespace
name|QtConcurrent
decl_stmt|{      QFuture<void> filter(Sequence&sequence
operator|,
decl_stmt|FilterFunction filterFunction
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|T
operator|>
name|filtered
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|FilterFunction filterFunction
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|T
operator|>
name|filtered
argument_list|(
argument|ConstIterator begin
argument_list|,
argument|ConstIterator end
argument_list|,
argument|FilterFunction filterFunction
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|T
operator|>
name|filteredReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|FilterFunction filterFunction
argument_list|,
argument|ReduceFunction reduceFunction
argument_list|,
argument|QtConcurrent::ReduceOptions reduceOptions = UnorderedReduce | SequentialReduce
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|T
operator|>
name|filteredReduced
argument_list|(
argument|ConstIterator begin
argument_list|,
argument|ConstIterator end
argument_list|,
argument|FilterFunction filterFunction
argument_list|,
argument|ReduceFunction reduceFunction
argument_list|,
argument|QtConcurrent::ReduceOptions reduceOptions = UnorderedReduce | SequentialReduce
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|blockingFilter
parameter_list|(
name|Sequence
modifier|&
name|sequence
parameter_list|,
name|FilterFunction
name|filterFunction
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|>
name|Sequence
name|blockingFiltered
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|FilterFunction filterFunction
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|>
name|Sequence
name|blockingFiltered
argument_list|(
argument|ConstIterator begin
argument_list|,
argument|ConstIterator end
argument_list|,
argument|FilterFunction filterFunction
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|blockingFilteredReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|FilterFunction filterFunction
argument_list|,
argument|ReduceFunction reduceFunction
argument_list|,
argument|QtConcurrent::ReduceOptions reduceOptions = UnorderedReduce | SequentialReduce
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|blockingFilteredReduced
argument_list|(
argument|ConstIterator begin
argument_list|,
argument|ConstIterator end
argument_list|,
argument|FilterFunction filterFunction
argument_list|,
argument|ReduceFunction reduceFunction
argument_list|,
argument|QtConcurrent::ReduceOptions reduceOptions = UnorderedReduce | SequentialReduce
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|// namespace QtConcurrent
end_comment
begin_else
else|#
directive|else
end_else
begin_macro
unit|namespace
name|QtConcurrent
end_macro
begin_block
block|{
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|ThreadEngineStarter
operator|<
name|void
operator|>
name|filterInternal
argument_list|(
argument|Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|)
block|{
typedef|typedef
name|typename
name|Sequence
operator|::
name|const_iterator
name|Iterator
expr_stmt|;
typedef|typedef
name|FilterKernel
operator|<
name|Sequence
operator|,
name|KeepFunctor
operator|,
name|ReduceFunctor
operator|>
name|KernelType
expr_stmt|;
return|return
name|startThreadEngine
argument_list|(
argument|new KernelType(sequence, keep, reduce)
argument_list|)
return|;
block|}
end_block
begin_comment
comment|// filter() on sequences
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|>
name|QFuture
operator|<
name|void
operator|>
name|filter
argument_list|(
argument|Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|)
block|{
return|return
name|filterInternal
argument_list|(
name|sequence
argument_list|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
argument_list|)
argument_list|,
name|QtPrivate
operator|::
name|PushBackWrapper
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// filteredReduced() on sequences
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|ResultType
operator|,
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|QFuture
operator|<
name|ResultType
operator|>
name|filteredReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startFilteredReduced
operator|<
name|ResultType
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
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
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
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
name|filteredReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startFilteredReduced
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
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
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
end_expr_stmt
begin_comment
comment|// filteredReduced() on iterators
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|ResultType
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|QFuture
operator|<
name|ResultType
operator|>
name|filteredReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startFilteredReduced
operator|<
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
name|keep
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
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
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
name|filteredReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startFilteredReduced
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
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
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
end_expr_stmt
begin_comment
comment|// filtered() on sequences
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|>
name|QFuture
operator|<
name|typename
name|Sequence
operator|::
name|value_type
operator|>
name|filtered
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|)
block|{
return|return
name|startFiltered
argument_list|(
name|sequence
argument_list|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// filtered() on iterators
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
operator|>
name|QFuture
operator|<
name|typename
name|qValueType
operator|<
name|Iterator
operator|>
operator|::
name|value_type
operator|>
name|filtered
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor keep
argument_list|)
block|{
return|return
name|startFiltered
argument_list|(
name|begin
argument_list|,
name|end
argument_list|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// blocking filter() on sequences
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|>
name|void
name|blockingFilter
argument_list|(
argument|Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|)
block|{
name|filterInternal
argument_list|(
name|sequence
argument_list|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
argument_list|)
argument_list|,
name|QtPrivate
operator|::
name|PushBackWrapper
argument_list|()
argument_list|)
operator|.
name|startBlocking
argument_list|()
block|; }
comment|// blocking filteredReduced() on sequences
name|template
operator|<
name|typename
name|ResultType
operator|,
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|ResultType
name|blockingFilteredReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startFilteredReduced
operator|<
name|ResultType
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
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
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
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
name|blockingFilteredReduced
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|blockingFilteredReduced
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
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
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
end_expr_stmt
begin_comment
comment|// blocking filteredReduced() on iterators
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|ResultType
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
operator|,
name|typename
name|ReduceFunctor
operator|>
name|ResultType
name|blockingFilteredReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startFilteredReduced
operator|<
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
name|keep
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
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
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
name|blockingFilteredReduced
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor keep
argument_list|,
argument|ReduceFunctor reduce
argument_list|,
argument|ReduceOptions options = ReduceOptions(UnorderedReduce | SequentialReduce)
argument_list|)
block|{
return|return
name|startFilteredReduced
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
operator|(
name|begin
operator|,
name|end
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
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
end_expr_stmt
begin_comment
comment|// blocking filtered() on sequences
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Sequence
operator|,
name|typename
name|KeepFunctor
operator|>
name|Sequence
name|blockingFiltered
argument_list|(
argument|const Sequence&sequence
argument_list|,
argument|KeepFunctor keep
argument_list|)
block|{
return|return
name|startFilteredReduced
operator|<
name|Sequence
operator|>
operator|(
name|sequence
operator|,
name|QtPrivate
operator|::
name|createFunctionWrapper
argument_list|(
name|keep
argument_list|)
operator|,
name|QtPrivate
operator|::
name|PushBackWrapper
argument_list|()
operator|,
name|OrderedReduce
operator|)
operator|.
name|startBlocking
argument_list|()
return|;
block|}
end_expr_stmt
begin_comment
comment|// blocking filtered() on iterators
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|OutputSequence
operator|,
name|typename
name|Iterator
operator|,
name|typename
name|KeepFunctor
operator|>
name|OutputSequence
name|blockingFiltered
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|KeepFunctor keep
argument_list|)
block|{
return|return
name|startFilteredReduced
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
name|keep
argument_list|)
operator|,
name|QtPrivate
operator|::
name|PushBackWrapper
argument_list|()
operator|,
name|OrderedReduce
operator|)
operator|.
name|startBlocking
argument_list|()
return|;
block|}
end_expr_stmt
begin_comment
unit|}
comment|// namespace QtConcurrent
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// qdoc
end_comment
begin_macro
unit|QT_END_NAMESPACE
name|QT_END_HEADER
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
