begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtconcurrentexception.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qshareddata.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!      \class QtConcurrent::Exception     \brief The Exception class provides a base class for exceptions that can transferred across threads.     \since 4.4      Qt Concurrent supports throwing and catching exceptions across thread     boundaries, provided that the exception inherit from QtConcurrent::Exception     and implement two helper functions:      \snippet doc/src/snippets/code/src_corelib_concurrent_qtconcurrentexception.cpp 0      QtConcurrent::Exception subclasses must be thrown by value and     caught by reference:      \snippet doc/src/snippets/code/src_corelib_concurrent_qtconcurrentexception.cpp 1      If you throw an exception that is not a subclass of QtConcurrent::Exception,     the Qt Concurrent functions will throw a QtConcurrent::UnhandledException     in the receiver thread.      When using QFuture, transferred exceptions will be thrown when calling the following functions:     \list     \o QFuture::waitForFinished()     \o QFuture::result()     \o QFuture::resultAt()     \o QFuture::results()     \endlist */
end_comment
begin_comment
comment|/*!     \fn QtConcurrent::Exception::raise() const      In your QtConcurrent::Exception subclass, reimplement raise() like this:          \snippet doc/src/snippets/code/src_corelib_concurrent_qtconcurrentexception.cpp 2 */
end_comment
begin_comment
comment|/*!     \fn QtConcurrent::Exception::clone() const     In your QtConcurrent::Exception subclass, reimplement clone() like this:          \snippet doc/src/snippets/code/src_corelib_concurrent_qtconcurrentexception.cpp 3 */
end_comment
begin_comment
comment|/*!      \class QtConcurrent::UnhandledException      \brief The UnhandledException class represents an unhandled exception in a worker thread.     \since 4.4      If a worker thread throws an exception that is not a subclass of QtConcurrent::Exception,     the Qt Concurrent functions will throw a QtConcurrent::UnhandledException     on the receiver thread side.      Inheriting from this class is not supported. */
end_comment
begin_comment
comment|/*!     \fn QtConcurrent::UnhandledException::raise() const     \internal */
end_comment
begin_comment
comment|/*!     \fn QtConcurrent::UnhandledException::clone() const     \internal */
end_comment
begin_namespace
DECL|namespace|QtConcurrent
namespace|namespace
name|QtConcurrent
block|{
DECL|function|raise
name|void
name|Exception
operator|::
name|raise
parameter_list|()
specifier|const
block|{
name|Exception
name|e
init|=
operator|*
name|this
decl_stmt|;
throw|throw
name|e
throw|;
block|}
DECL|function|clone
name|Exception
modifier|*
name|Exception
operator|::
name|clone
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|Exception
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
DECL|function|raise
name|void
name|UnhandledException
operator|::
name|raise
parameter_list|()
specifier|const
block|{
name|UnhandledException
name|e
init|=
operator|*
name|this
decl_stmt|;
throw|throw
name|e
throw|;
block|}
DECL|function|clone
name|Exception
modifier|*
name|UnhandledException
operator|::
name|clone
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|UnhandledException
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
ifndef|#
directive|ifndef
name|qdoc
DECL|namespace|internal
namespace|namespace
name|internal
block|{
DECL|class|Base
class|class
name|Base
super|:
specifier|public
name|QSharedData
block|{
public|public:
DECL|function|Base
name|Base
parameter_list|(
name|Exception
modifier|*
name|exception
parameter_list|)
member_init_list|:
name|exception
argument_list|(
name|exception
argument_list|)
member_init_list|,
name|hasThrown
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|~Base
name|~
name|Base
parameter_list|()
block|{
operator|delete
name|exception
expr_stmt|;
block|}
DECL|member|exception
name|Exception
modifier|*
name|exception
decl_stmt|;
DECL|member|hasThrown
name|bool
name|hasThrown
decl_stmt|;
block|}
class|;
DECL|function|ExceptionHolder
name|ExceptionHolder
operator|::
name|ExceptionHolder
parameter_list|(
name|Exception
modifier|*
name|exception
parameter_list|)
member_init_list|:
name|base
argument_list|(
operator|new
name|Base
argument_list|(
name|exception
argument_list|)
argument_list|)
block|{}
DECL|function|ExceptionHolder
name|ExceptionHolder
operator|::
name|ExceptionHolder
parameter_list|(
specifier|const
name|ExceptionHolder
modifier|&
name|other
parameter_list|)
member_init_list|:
name|base
argument_list|(
name|other
operator|.
name|base
argument_list|)
block|{}
DECL|function|operator =
name|void
name|ExceptionHolder
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|ExceptionHolder
modifier|&
name|other
parameter_list|)
block|{
name|base
operator|=
name|other
operator|.
name|base
expr_stmt|;
block|}
DECL|function|~ExceptionHolder
name|ExceptionHolder
operator|::
name|~
name|ExceptionHolder
parameter_list|()
block|{}
DECL|function|exception
name|Exception
modifier|*
name|ExceptionHolder
operator|::
name|exception
parameter_list|()
specifier|const
block|{
return|return
name|base
operator|->
name|exception
return|;
block|}
DECL|function|setException
name|void
name|ExceptionStore
operator|::
name|setException
parameter_list|(
specifier|const
name|Exception
modifier|&
name|e
parameter_list|)
block|{
if|if
condition|(
name|hasException
argument_list|()
operator|==
literal|false
condition|)
name|exceptionHolder
operator|=
name|ExceptionHolder
argument_list|(
name|e
operator|.
name|clone
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|hasException
name|bool
name|ExceptionStore
operator|::
name|hasException
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|exceptionHolder
operator|.
name|exception
argument_list|()
operator|!=
literal|0
operator|)
return|;
block|}
DECL|function|exception
name|ExceptionHolder
name|ExceptionStore
operator|::
name|exception
parameter_list|()
block|{
return|return
name|exceptionHolder
return|;
block|}
DECL|function|throwPossibleException
name|void
name|ExceptionStore
operator|::
name|throwPossibleException
parameter_list|()
block|{
if|if
condition|(
name|hasException
argument_list|()
condition|)
block|{
name|exceptionHolder
operator|.
name|base
operator|->
name|hasThrown
operator|=
literal|true
expr_stmt|;
name|exceptionHolder
operator|.
name|exception
argument_list|()
operator|->
name|raise
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|hasThrown
name|bool
name|ExceptionStore
operator|::
name|hasThrown
parameter_list|()
specifier|const
block|{
return|return
name|exceptionHolder
operator|.
name|base
operator|->
name|hasThrown
return|;
block|}
block|}
comment|// namespace internal
endif|#
directive|endif
comment|//qdoc
block|}
end_namespace
begin_comment
comment|// namespace QtConcurrent
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_EXCEPTIONS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONCURRENT
end_comment
end_unit
