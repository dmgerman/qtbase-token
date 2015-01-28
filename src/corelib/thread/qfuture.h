begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUTURE_H
end_ifndef
begin_define
DECL|macro|QFUTURE_H
define|#
directive|define
name|QFUTURE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qfutureinterface.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|template
operator|<
name|typename
name|T
operator|>
DECL|variable|QFutureWatcher
name|class
name|QFutureWatcher
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|QFutureWatcher
operator|<
name|void
operator|>
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QFuture
block|{
name|public
operator|:
name|QFuture
argument_list|()
operator|:
name|d
argument_list|(
argument|QFutureInterface<T>::canceledResult()
argument_list|)
block|{ }
name|explicit
name|QFuture
argument_list|(
name|QFutureInterface
operator|<
name|T
operator|>
operator|*
name|p
argument_list|)
comment|// internal
operator|:
name|d
argument_list|(
argument|*p
argument_list|)
block|{ }
name|QFuture
argument_list|(
specifier|const
name|QFuture
operator|&
name|other
argument_list|)
operator|:
name|d
argument_list|(
argument|other.d
argument_list|)
block|{ }
operator|~
name|QFuture
argument_list|()
block|{ }
specifier|inline
name|QFuture
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QFuture
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFuture
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|d
operator|==
name|other
operator|.
name|d
operator|)
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFuture
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|d
operator|!=
name|other
operator|.
name|d
operator|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|cancel
parameter_list|()
block|{
name|d
operator|.
name|cancel
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|isCanceled
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isCanceled
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setPaused
parameter_list|(
name|bool
name|paused
parameter_list|)
block|{
name|d
operator|.
name|setPaused
argument_list|(
name|paused
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|isPaused
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isPaused
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
name|void
name|pause
parameter_list|()
block|{
name|setPaused
argument_list|(
name|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|resume
parameter_list|()
block|{
name|setPaused
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|togglePaused
parameter_list|()
block|{
name|d
operator|.
name|togglePaused
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|isStarted
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isStarted
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isFinished
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isFinished
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isRunning
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isRunning
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|resultCount
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|resultCount
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|progressValue
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|progressValue
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|progressMinimum
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|progressMinimum
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|progressMaximum
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|progressMaximum
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QString
name|progressText
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|progressText
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
name|void
name|waitForFinished
parameter_list|()
block|{
name|d
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|T
name|result
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|inline
name|T
name|resultAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|isResultReadyAt
argument_list|(
name|int
name|resultIndex
argument_list|)
decl|const
block|{
return|return
name|d
operator|.
name|isResultReadyAt
argument_list|(
name|resultIndex
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|operator
name|T
argument_list|()
specifier|const
block|{
return|return
name|result
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|T
operator|>
name|results
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|results
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|class
name|const_iterator
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|bidirectional_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|qptrdiff
name|difference_type
typedef|;
typedef|typedef
name|T
name|value_type
typedef|;
typedef|typedef
specifier|const
name|T
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|T
modifier|&
name|reference
typedef|;
specifier|inline
name|const_iterator
argument_list|()
block|{}
specifier|inline
name|const_iterator
argument_list|(
argument|QFuture const * const _future
argument_list|,
argument|int _index
argument_list|)
operator|:
name|future
argument_list|(
name|_future
argument_list|)
operator|,
name|index
argument_list|(
argument|_index
argument_list|)
block|{}
specifier|inline
name|const_iterator
argument_list|(
specifier|const
name|const_iterator
operator|&
name|o
argument_list|)
operator|:
name|future
argument_list|(
name|o
operator|.
name|future
argument_list|)
operator|,
name|index
argument_list|(
argument|o.index
argument_list|)
block|{}
specifier|inline
name|const_iterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
block|{
name|future
operator|=
name|o
operator|.
name|future
block|;
name|index
operator|=
name|o
operator|.
name|index
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
specifier|const
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|future
operator|->
name|d
operator|.
name|resultReference
argument_list|(
name|index
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|future
operator|->
name|d
operator|.
name|resultPointer
argument_list|(
name|index
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|index
operator|==
operator|-
literal|1
operator|&&
name|other
operator|.
name|index
operator|==
operator|-
literal|1
condition|)
comment|// comparing end != end?
return|return
name|false
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|other
operator|.
name|index
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|future
operator|->
name|isRunning
argument_list|()
operator|||
operator|(
name|index
operator|<
name|future
operator|->
name|resultCount
argument_list|()
operator|)
operator|)
return|;
end_if
begin_return
return|return
operator|(
name|index
operator|!=
name|other
operator|.
name|index
operator|)
return|;
end_return
begin_expr_stmt
unit|}          inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|!=
operator|(
name|o
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|index
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|const_iterator
name|r
operator|=
operator|*
name|this
block|;
operator|++
name|index
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|index
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|const_iterator
name|r
operator|=
operator|*
name|this
block|;
operator|--
name|index
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|+
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|future
argument_list|,
name|index
operator|+
name|j
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|-
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|future
argument_list|,
name|index
operator|-
name|j
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|+=
operator|(
name|int
name|j
operator|)
block|{
name|index
operator|+=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|-=
operator|(
name|int
name|j
operator|)
block|{
name|index
operator|-=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QFuture
specifier|const
modifier|*
name|future
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|index
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|friend
name|class
name|const_iterator
decl_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|const_iterator
name|ConstIterator
typedef|;
end_typedef
begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|const_iterator
name|constBegin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|const_iterator
name|constEnd
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|friend
name|class
name|QFutureWatcher
operator|<
name|T
operator|>
expr_stmt|;
end_expr_stmt
begin_label
name|public
label|:
end_label
begin_comment
comment|// Warning: the d pointer is not documented and is considered private.
end_comment
begin_expr_stmt
name|mutable
name|QFutureInterface
operator|<
name|T
operator|>
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
DECL|member|operator
specifier|inline
name|QFuture
operator|<
name|T
operator|>
operator|&
name|QFuture
operator|<
name|T
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|QFuture
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|d
operator|=
name|other
operator|.
name|d
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|QFuture
operator|<
name|T
operator|>
operator|::
name|result
argument_list|()
specifier|const
block|{
name|d
operator|.
name|waitForResult
argument_list|(
literal|0
argument_list|)
block|;
return|return
name|d
operator|.
name|resultReference
argument_list|(
literal|0
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
specifier|inline
name|T
name|QFuture
operator|<
name|T
operator|>
operator|::
name|resultAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
name|d
operator|.
name|waitForResult
argument_list|(
name|index
argument_list|)
block|;
return|return
name|d
operator|.
name|resultReference
argument_list|(
name|index
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
specifier|inline
name|QFuture
operator|<
name|T
operator|>
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|future
argument_list|()
block|{
return|return
name|QFuture
operator|<
name|T
operator|>
operator|(
name|this
operator|)
return|;
block|}
end_expr_stmt
begin_macro
name|Q_DECLARE_SEQUENTIAL_ITERATOR
argument_list|(
argument|Future
argument_list|)
end_macro
begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|QFuture
operator|<
name|void
operator|>
block|{
name|public
operator|:
name|QFuture
argument_list|()
operator|:
name|d
argument_list|(
argument|QFutureInterface<void>::canceledResult()
argument_list|)
block|{ }
name|explicit
name|QFuture
argument_list|(
name|QFutureInterfaceBase
operator|*
name|p
argument_list|)
comment|// internal
operator|:
name|d
argument_list|(
argument|*p
argument_list|)
block|{ }
name|QFuture
argument_list|(
specifier|const
name|QFuture
operator|&
name|other
argument_list|)
operator|:
name|d
argument_list|(
argument|other.d
argument_list|)
block|{ }
operator|~
name|QFuture
argument_list|()
block|{ }
name|QFuture
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QFuture
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFuture
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|d
operator|==
name|other
operator|.
name|d
operator|)
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFuture
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|d
operator|!=
name|other
operator|.
name|d
operator|)
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_CC_XLC
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
argument_list|(
specifier|const
name|QFuture
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
operator|:
name|d
argument_list|(
argument|other.d
argument_list|)
block|{ }
name|template
operator|<
name|typename
name|T
operator|>
name|QFuture
operator|<
name|void
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QFuture
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|d
operator|=
name|other
operator|.
name|d
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|void
name|cancel
parameter_list|()
block|{
name|d
operator|.
name|cancel
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|isCanceled
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isCanceled
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setPaused
parameter_list|(
name|bool
name|paused
parameter_list|)
block|{
name|d
operator|.
name|setPaused
argument_list|(
name|paused
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|isPaused
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isPaused
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
name|void
name|pause
parameter_list|()
block|{
name|setPaused
argument_list|(
name|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|resume
parameter_list|()
block|{
name|setPaused
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|togglePaused
parameter_list|()
block|{
name|d
operator|.
name|togglePaused
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|isStarted
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isStarted
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isFinished
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isFinished
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isRunning
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isRunning
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|resultCount
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|resultCount
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|progressValue
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|progressValue
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|progressMinimum
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|progressMinimum
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|progressMaximum
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|progressMaximum
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QString
name|progressText
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|progressText
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
name|void
name|waitForFinished
parameter_list|()
block|{
name|d
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|friend
name|class
name|QFutureWatcher
operator|<
name|void
operator|>
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QFUTURE_TEST
end_ifdef
begin_label
name|public
label|:
end_label
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|mutable
name|QFutureInterfaceBase
name|d
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
specifier|inline
name|QFuture
operator|<
name|void
operator|>
operator|&
name|QFuture
operator|<
name|void
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|QFuture
operator|<
name|void
operator|>
operator|&
name|other
operator|)
block|{
name|d
operator|=
name|other
operator|.
name|d
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFuture
operator|<
name|void
operator|>
name|QFutureInterface
operator|<
name|void
operator|>
operator|::
name|future
argument_list|()
block|{
return|return
name|QFuture
operator|<
name|void
operator|>
operator|(
name|this
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
name|QFuture
operator|<
name|void
operator|>
name|qToVoidFuture
argument_list|(
argument|const QFuture<T>&future
argument_list|)
block|{
return|return
name|QFuture
operator|<
name|void
operator|>
operator|(
name|future
operator|.
name|d
operator|)
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QFUTURE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFUTURE_H
end_comment
end_unit
