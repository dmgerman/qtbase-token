begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTIMER_H
end_ifndef
begin_define
DECL|macro|QTIMER_H
define|#
directive|define
name|QTIMER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qbasictimer.h>
end_include
begin_comment
comment|// conceptual inheritance
end_comment
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QTimer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool singleShot READ isSingleShot WRITE setSingleShot
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int interval READ interval WRITE setInterval
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int remainingTime READ remainingTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TimerType timerType READ timerType WRITE setTimerType
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool active READ isActive
argument_list|)
name|public
operator|:
name|explicit
name|QTimer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QTimer
argument_list|()
block|;
specifier|inline
name|bool
name|isActive
argument_list|()
specifier|const
block|{
return|return
name|id
operator|>=
literal|0
return|;
block|}
name|int
name|timerId
argument_list|()
specifier|const
block|{
return|return
name|id
return|;
block|}
name|void
name|setInterval
argument_list|(
argument|int msec
argument_list|)
block|;
name|int
name|interval
argument_list|()
specifier|const
block|{
return|return
name|inter
return|;
block|}
name|int
name|remainingTime
argument_list|()
specifier|const
block|;
name|void
name|setTimerType
argument_list|(
argument|Qt::TimerType atype
argument_list|)
block|{
name|this
operator|->
name|type
operator|=
name|atype
block|; }
name|Qt
operator|::
name|TimerType
name|timerType
argument_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|TimerType
argument_list|(
name|type
argument_list|)
return|;
block|}
specifier|inline
name|void
name|setSingleShot
argument_list|(
argument|bool singleShot
argument_list|)
block|;
specifier|inline
name|bool
name|isSingleShot
argument_list|()
specifier|const
block|{
return|return
name|single
return|;
block|}
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|const QObject *receiver
argument_list|,
argument|const char *member
argument_list|)
block|;
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|const QObject *receiver
argument_list|,
argument|const char *member
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_QDOC
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|const QObject *receiver
argument_list|,
argument|PointerToMemberFunction method
argument_list|)
block|;
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|const QObject *receiver
argument_list|,
argument|PointerToMemberFunction method
argument_list|)
block|;
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Functor functor
argument_list|)
block|;
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|Functor functor
argument_list|)
block|;
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|const QObject *context
argument_list|,
argument|Functor functor
argument_list|)
block|;
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|const QObject *context
argument_list|,
argument|Functor functor
argument_list|)
block|;
else|#
directive|else
comment|// singleShot to a QObject slot
name|template
operator|<
name|typename
name|Func1
operator|>
specifier|static
specifier|inline
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|const typename QtPrivate::FunctionPointer<Func1>::Object *receiver
argument_list|,
argument|Func1 slot
argument_list|)
block|{
name|singleShot
argument_list|(
name|msec
argument_list|,
name|msec
operator|>=
literal|2000
operator|?
name|Qt
operator|::
name|CoarseTimer
operator|:
name|Qt
operator|::
name|PreciseTimer
argument_list|,
name|receiver
argument_list|,
name|slot
argument_list|)
block|;     }
name|template
operator|<
name|typename
name|Func1
operator|>
specifier|static
specifier|inline
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|const typename QtPrivate::FunctionPointer<Func1>::Object *receiver
argument_list|,
argument|Func1 slot
argument_list|)
block|{
typedef|typedef
name|QtPrivate
operator|::
name|FunctionPointer
operator|<
name|Func1
operator|>
name|SlotType
expr_stmt|;
comment|//compilation error if the slot has arguments.
name|Q_STATIC_ASSERT_X
argument_list|(
name|int
argument_list|(
name|SlotType
operator|::
name|ArgumentCount
argument_list|)
operator|==
literal|0
argument_list|,
literal|"The slot must not have any arguments."
argument_list|)
block|;
name|singleShotImpl
argument_list|(
argument|msec
argument_list|,
argument|timerType
argument_list|,
argument|receiver
argument_list|,
argument|new QtPrivate::QSlotObject<Func1
argument_list|,
argument|typename SlotType::Arguments
argument_list|,
argument|void>(slot)
argument_list|)
block|;     }
comment|// singleShot to a functor or function pointer (without context)
name|template
operator|<
name|typename
name|Func1
operator|>
specifier|static
specifier|inline
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Func1 slot
argument_list|)
block|{
name|singleShot
argument_list|(
name|msec
argument_list|,
name|msec
operator|>=
literal|2000
operator|?
name|Qt
operator|::
name|CoarseTimer
operator|:
name|Qt
operator|::
name|PreciseTimer
argument_list|,
name|Q_NULLPTR
argument_list|,
name|slot
argument_list|)
block|;     }
name|template
operator|<
name|typename
name|Func1
operator|>
specifier|static
specifier|inline
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|Func1 slot
argument_list|)
block|{
name|singleShot
argument_list|(
name|msec
argument_list|,
name|timerType
argument_list|,
name|Q_NULLPTR
argument_list|,
name|slot
argument_list|)
block|;     }
comment|// singleShot to a functor or function pointer (with context)
name|template
operator|<
name|typename
name|Func1
operator|>
specifier|static
specifier|inline
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
operator|!
name|QtPrivate
operator|::
name|FunctionPointer
operator|<
name|Func1
operator|>
operator|::
name|IsPointerToMemberFunction
operator|&&
operator|!
name|QtPrivate
operator|::
name|is_same
operator|<
specifier|const
name|char
operator|*
decl_stmt|,
name|Func1
decl|>::
name|value
decl_stmt|,
name|void
decl|>::
name|Type
name|singleShot
argument_list|(
name|int
name|msec
argument_list|,
name|QObject
operator|*
name|context
argument_list|,
name|Func1
name|slot
argument_list|)
block|{
name|singleShot
argument_list|(
name|msec
argument_list|,
name|msec
operator|>=
literal|2000
condition|?
name|Qt
operator|::
name|CoarseTimer
else|:
name|Qt
operator|::
name|PreciseTimer
argument_list|,
name|context
argument_list|,
name|slot
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Func1
operator|>
specifier|static
specifier|inline
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
operator|!
name|QtPrivate
operator|::
name|FunctionPointer
operator|<
name|Func1
operator|>
operator|::
name|IsPointerToMemberFunction
operator|&&
operator|!
name|QtPrivate
operator|::
name|is_same
operator|<
specifier|const
name|char
operator|*
operator|,
name|Func1
operator|>
operator|::
name|value
operator|,
name|void
operator|>
operator|::
name|Type
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|QObject *context
argument_list|,
argument|Func1 slot
argument_list|)
block|{
comment|//compilation error if the slot has arguments.
typedef|typedef
name|QtPrivate
operator|::
name|FunctionPointer
operator|<
name|Func1
operator|>
name|SlotType
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
name|int
argument_list|(
name|SlotType
operator|::
name|ArgumentCount
argument_list|)
operator|<=
literal|0
argument_list|,
literal|"The slot must not have any arguments."
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|singleShotImpl
argument_list|(
argument|msec
argument_list|,
argument|timerType
argument_list|,
argument|context
argument_list|,
argument|new QtPrivate::QFunctorSlotObject<Func1
argument_list|,
literal|0
argument_list|,
argument|typename QtPrivate::List_Left<void
argument_list|,
literal|0
argument|>::Value
argument_list|,
argument|void>(slot)
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_label
unit|public
name|Q_SLOTS
label|:
end_label
begin_function_decl
name|void
name|start
parameter_list|(
name|int
name|msec
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|start
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|stop
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|void
name|timeout
parameter_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QPrivateSignal
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_function_decl
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QTimer
argument_list|)
end_macro
begin_function
specifier|inline
name|int
name|startTimer
parameter_list|(
name|int
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
specifier|inline
name|void
name|killTimer
parameter_list|(
name|int
parameter_list|)
block|{}
end_function
begin_decl_stmt
specifier|static
name|void
name|singleShotImpl
argument_list|(
name|int
name|msec
argument_list|,
name|Qt
operator|::
name|TimerType
name|timerType
argument_list|,
specifier|const
name|QObject
operator|*
name|receiver
argument_list|,
name|QtPrivate
operator|::
name|QSlotObjectBase
operator|*
name|slotObj
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|id
decl_stmt|,
name|inter
decl_stmt|,
name|del
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|single
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|nulltimer
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|type
range|:
literal|2
decl_stmt|;
end_decl_stmt
begin_comment
comment|// reserved : 28
end_comment
begin_expr_stmt
unit|};
DECL|function|setSingleShot
specifier|inline
name|void
name|QTimer
operator|::
name|setSingleShot
argument_list|(
argument|bool asingleShot
argument_list|)
block|{
name|single
operator|=
name|asingleShot
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QOBJECT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTIMER_H
end_comment
end_unit
