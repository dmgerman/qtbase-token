begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOBJECT_H
end_ifndef
begin_define
DECL|macro|QOBJECT_H
define|#
directive|define
name|QOBJECT_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_INCLUDE_COMPAT
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimerEvent
name|class
name|QTimerEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QChildEvent
name|class
name|QChildEvent
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QMetaObject
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObjectPrivate
name|class
name|QObjectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QThread
name|class
name|QThread
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_decl_stmt
DECL|variable|QRegExp
name|class
name|QRegExp
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_USERDATA
end_ifndef
begin_decl_stmt
DECL|variable|QObjectUserData
name|class
name|QObjectUserData
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|QObjectList
typedef|typedef
name|QList
operator|<
name|QObject
operator|*
operator|>
name|QObjectList
expr_stmt|;
end_typedef
begin_decl_stmt
name|Q_CORE_EXPORT
name|void
name|qt_qFindChildren_helper
argument_list|(
specifier|const
name|QObject
operator|*
name|parent
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QRegExp
operator|*
name|re
argument_list|,
specifier|const
name|QMetaObject
operator|&
name|mo
argument_list|,
name|QList
operator|<
name|void
operator|*
operator|>
operator|*
name|list
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|Q_CORE_EXPORT
name|QObject
modifier|*
name|qt_qFindChild_helper
parameter_list|(
specifier|const
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QMetaObject
modifier|&
name|mo
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
if|#
directive|if
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|Q_CORE_EXPORT
endif|#
directive|endif
name|QObjectData
block|{
name|public
label|:
name|virtual
operator|~
name|QObjectData
argument_list|()
operator|=
literal|0
expr_stmt|;
name|QObject
modifier|*
name|q_ptr
decl_stmt|;
name|QObject
modifier|*
name|parent
decl_stmt|;
name|QObjectList
name|children
decl_stmt|;
name|uint
name|isWidget
range|:
literal|1
decl_stmt|;
name|uint
name|pendTimer
range|:
literal|1
decl_stmt|;
name|uint
name|blockSig
range|:
literal|1
decl_stmt|;
name|uint
name|wasDeleted
range|:
literal|1
decl_stmt|;
name|uint
name|ownObjectName
range|:
literal|1
decl_stmt|;
name|uint
name|sendChildEvents
range|:
literal|1
decl_stmt|;
name|uint
name|receiveChildEvents
range|:
literal|1
decl_stmt|;
name|uint
name|inEventHandler
range|:
literal|1
decl_stmt|;
comment|//only used if QT_JAMBI_BUILD
name|uint
name|inThreadChangeEvent
range|:
literal|1
decl_stmt|;
name|uint
name|hasGuards
range|:
literal|1
decl_stmt|;
comment|//true iff there is one or more QPointer attached to this object
name|uint
name|unused
range|:
literal|22
decl_stmt|;
name|int
name|postedEvents
decl_stmt|;
name|QMetaObject
modifier|*
name|metaObject
decl_stmt|;
comment|// assert dynamic
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
name|QString
name|objectName
name|READ
name|objectName
name|WRITE
name|setObjectName
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
name|QObject
argument_list|)
name|public
range|:
name|Q_INVOKABLE
name|explicit
name|QObject
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|QObject
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|bool
name|eventFilter
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|QEvent
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|qdoc
specifier|static
name|QString
name|tr
parameter_list|(
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
init|=
literal|0
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|static
name|QString
name|trUtf8
parameter_list|(
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
init|=
literal|0
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|virtual
specifier|const
name|QMetaObject
operator|*
name|metaObject
argument_list|()
specifier|const
expr_stmt|;
specifier|static
specifier|const
name|QMetaObject
name|staticMetaObject
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_TRANSLATION
specifier|static
name|QString
name|tr
parameter_list|(
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|sourceText
argument_list|)
return|;
block|}
specifier|static
name|QString
name|tr
parameter_list|(
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
init|=
literal|0
parameter_list|)
block|{
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|sourceText
argument_list|)
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
specifier|static
name|QString
name|trUtf8
parameter_list|(
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|sourceText
argument_list|)
return|;
block|}
specifier|static
name|QString
name|trUtf8
parameter_list|(
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
init|=
literal|0
parameter_list|)
block|{
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|sourceText
argument_list|)
return|;
block|}
endif|#
directive|endif
endif|#
directive|endif
comment|//QT_NO_TRANSLATION
name|QString
name|objectName
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setObjectName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isWidgetType
argument_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|isWidget
return|;
block|}
specifier|inline
name|bool
name|signalsBlocked
argument_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|blockSig
return|;
block|}
name|bool
name|blockSignals
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|QThread
operator|*
name|thread
argument_list|()
specifier|const
expr_stmt|;
name|void
name|moveToThread
parameter_list|(
name|QThread
modifier|*
name|thread
parameter_list|)
function_decl|;
name|int
name|startTimer
parameter_list|(
name|int
name|interval
parameter_list|)
function_decl|;
name|void
name|killTimer
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|findChild
argument_list|(
argument|const QString&aName = QString()
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|>
operator|(
name|qt_qFindChild_helper
argument_list|(
name|this
argument_list|,
name|aName
argument_list|,
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
operator|->
name|staticMetaObject
argument_list|)
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QList
operator|<
name|T
operator|>
name|findChildren
argument_list|(
argument|const QString&aName = QString()
argument_list|)
specifier|const
block|{
name|QList
operator|<
name|T
operator|>
name|list
block|;
expr|union
block|{
name|QList
operator|<
name|T
operator|>
operator|*
name|typedList
block|;
name|QList
operator|<
name|void
operator|*
operator|>
operator|*
name|voidList
block|;         }
name|u
block|;
name|u
operator|.
name|typedList
operator|=
operator|&
name|list
block|;
name|qt_qFindChildren_helper
argument_list|(
name|this
argument_list|,
name|aName
argument_list|,
literal|0
argument_list|,
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
operator|->
name|staticMetaObject
argument_list|,
name|u
operator|.
name|voidList
argument_list|)
block|;
return|return
name|list
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QList
operator|<
name|T
operator|>
name|findChildren
argument_list|(
argument|const QRegExp&re
argument_list|)
specifier|const
block|{
name|QList
operator|<
name|T
operator|>
name|list
block|;
expr|union
block|{
name|QList
operator|<
name|T
operator|>
operator|*
name|typedList
block|;
name|QList
operator|<
name|void
operator|*
operator|>
operator|*
name|voidList
block|;         }
name|u
block|;
name|u
operator|.
name|typedList
operator|=
operator|&
name|list
block|;
name|qt_qFindChildren_helper
argument_list|(
name|this
argument_list|,
name|QString
argument_list|()
argument_list|,
operator|&
name|re
argument_list|,
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
operator|->
name|staticMetaObject
argument_list|,
name|u
operator|.
name|voidList
argument_list|)
block|;
return|return
name|list
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|QT3_SUPPORT
name|QObject
modifier|*
name|child
argument_list|(
specifier|const
name|char
operator|*
name|objName
argument_list|,
specifier|const
name|char
operator|*
name|inheritsClass
operator|=
literal|0
argument_list|,
name|bool
name|recursiveSearch
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
name|QT3_SUPPORT
name|QObjectList
name|queryList
argument_list|(
specifier|const
name|char
operator|*
name|inheritsClass
operator|=
literal|0
argument_list|,
specifier|const
name|char
operator|*
name|objName
operator|=
literal|0
argument_list|,
name|bool
name|regexpMatch
operator|=
name|true
argument_list|,
name|bool
name|recursiveSearch
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
specifier|inline
specifier|const
name|QObjectList
operator|&
name|children
argument_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|children
return|;
block|}
name|void
name|setParent
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
name|void
name|installEventFilter
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
name|void
name|removeEventFilter
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|bool
name|connect
argument_list|(
specifier|const
name|QObject
operator|*
name|sender
argument_list|,
specifier|const
name|char
operator|*
name|signal
argument_list|,
specifier|const
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|,
name|Qt
operator|::
name|ConnectionType
operator|=
ifdef|#
directive|ifdef
name|qdoc
name|Qt
operator|::
name|AutoConnection
else|#
directive|else
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|Qt
operator|::
name|AutoCompatConnection
else|#
directive|else
name|Qt
operator|::
name|AutoConnection
endif|#
directive|endif
endif|#
directive|endif
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|connect
argument_list|(
specifier|const
name|QObject
operator|*
name|sender
argument_list|,
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|,
specifier|const
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|QMetaMethod
operator|&
name|method
argument_list|,
name|Qt
operator|::
name|ConnectionType
name|type
operator|=
ifdef|#
directive|ifdef
name|qdoc
name|Qt
operator|::
name|AutoConnection
else|#
directive|else
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|Qt
operator|::
name|AutoCompatConnection
else|#
directive|else
name|Qt
operator|::
name|AutoConnection
endif|#
directive|endif
endif|#
directive|endif
argument_list|)
decl_stmt|;
specifier|inline
name|bool
name|connect
argument_list|(
specifier|const
name|QObject
operator|*
name|sender
argument_list|,
specifier|const
name|char
operator|*
name|signal
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|,
name|Qt
operator|::
name|ConnectionType
name|type
operator|=
ifdef|#
directive|ifdef
name|qdoc
name|Qt
operator|::
name|AutoConnection
else|#
directive|else
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|Qt
operator|::
name|AutoCompatConnection
else|#
directive|else
name|Qt
operator|::
name|AutoConnection
endif|#
directive|endif
endif|#
directive|endif
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
specifier|const
name|char
modifier|*
name|signal
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
function_decl|;
specifier|static
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
specifier|const
name|QMetaMethod
modifier|&
name|signal
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|QMetaMethod
modifier|&
name|member
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|disconnect
parameter_list|(
specifier|const
name|char
modifier|*
name|signal
init|=
literal|0
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|member
init|=
literal|0
parameter_list|)
block|{
return|return
name|disconnect
argument_list|(
name|this
argument_list|,
name|signal
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
init|=
literal|0
parameter_list|)
block|{
return|return
name|disconnect
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|)
return|;
block|}
name|void
name|dumpObjectTree
parameter_list|()
function_decl|;
name|void
name|dumpObjectInfo
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_PROPERTIES
name|bool
name|setProperty
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|QVariant
name|property
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|dynamicPropertyNames
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_PROPERTIES
ifndef|#
directive|ifndef
name|QT_NO_USERDATA
specifier|static
name|uint
name|registerUserData
parameter_list|()
function_decl|;
name|void
name|setUserData
parameter_list|(
name|uint
name|id
parameter_list|,
name|QObjectUserData
modifier|*
name|data
parameter_list|)
function_decl|;
name|QObjectUserData
modifier|*
name|userData
argument_list|(
name|uint
name|id
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
comment|// QT_NO_USERDATA
name|Q_SIGNALS
label|:
name|void
name|destroyed
parameter_list|(
name|QObject
modifier|*
init|=
literal|0
parameter_list|)
function_decl|;
name|public
label|:
specifier|inline
name|QObject
operator|*
name|parent
argument_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|parent
return|;
block|}
specifier|inline
name|bool
name|inherits
argument_list|(
specifier|const
name|char
operator|*
name|classname
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|QObject
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|qt_metacast
argument_list|(
name|classname
argument_list|)
operator|!=
literal|0
return|;
block|}
name|public
name|Q_SLOTS
range|:
name|void
name|deleteLater
argument_list|()
decl_stmt|;
name|protected
label|:
name|QObject
operator|*
name|sender
argument_list|()
specifier|const
expr_stmt|;
name|int
name|senderSignalIndex
argument_list|()
specifier|const
expr_stmt|;
name|int
name|receivers
argument_list|(
specifier|const
name|char
operator|*
name|signal
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|childEvent
parameter_list|(
name|QChildEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|customEvent
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|connectNotify
parameter_list|(
specifier|const
name|char
modifier|*
name|signal
parameter_list|)
function_decl|;
name|virtual
name|void
name|disconnectNotify
parameter_list|(
specifier|const
name|char
modifier|*
name|signal
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
label|:
name|QT3_SUPPORT_CONSTRUCTOR
name|QObject
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
specifier|inline
name|QT3_SUPPORT
name|void
name|insertChild
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|)
block|{
if|if
condition|(
name|o
condition|)
name|o
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QT3_SUPPORT
name|void
name|removeChild
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|)
block|{
if|if
condition|(
name|o
condition|)
name|o
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QT3_SUPPORT
name|bool
name|isA
argument_list|(
specifier|const
name|char
operator|*
name|classname
argument_list|)
decl|const
block|{
return|return
name|qstrcmp
argument_list|(
name|classname
argument_list|,
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
operator|==
literal|0
return|;
block|}
specifier|inline
name|QT3_SUPPORT
specifier|const
name|char
operator|*
name|className
argument_list|()
specifier|const
block|{
return|return
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
return|;
block|}
specifier|inline
name|QT3_SUPPORT
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
name|objectName
argument_list|()
operator|.
name|latin1_helper
argument_list|()
return|;
block|}
specifier|inline
name|QT3_SUPPORT
specifier|const
name|char
modifier|*
name|name
argument_list|(
specifier|const
name|char
operator|*
name|defaultName
argument_list|)
decl|const
block|{
name|QString
name|s
init|=
name|objectName
argument_list|()
decl_stmt|;
return|return
name|s
operator|.
name|isEmpty
argument_list|()
condition|?
name|defaultName
else|:
name|s
operator|.
name|latin1_helper
argument_list|()
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|void
name|setName
parameter_list|(
specifier|const
name|char
modifier|*
name|aName
parameter_list|)
block|{
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
name|aName
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
specifier|inline
name|QT3_SUPPORT
name|bool
name|checkConnectArgs
parameter_list|(
specifier|const
name|char
modifier|*
name|signal
parameter_list|,
specifier|const
name|QObject
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
return|return
name|QMetaObject
operator|::
name|checkConnectArgs
argument_list|(
name|signal
argument_list|,
name|member
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|QT3_SUPPORT
name|QByteArray
name|normalizeSignalSlot
parameter_list|(
specifier|const
name|char
modifier|*
name|signalSlot
parameter_list|)
block|{
return|return
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
name|signalSlot
argument_list|)
return|;
block|}
endif|#
directive|endif
name|protected
label|:
name|QObject
argument_list|(
name|QObjectPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
expr_stmt|;
name|protected
label|:
name|QScopedPointer
operator|<
name|QObjectData
operator|>
name|d_ptr
expr_stmt|;
specifier|static
specifier|const
name|QMetaObject
name|staticQtMetaObject
decl_stmt|;
name|friend
struct_decl|struct
name|QMetaObject
struct_decl|;
name|friend
name|class
name|QApplication
decl_stmt|;
name|friend
name|class
name|QApplicationPrivate
decl_stmt|;
name|friend
name|class
name|QCoreApplication
decl_stmt|;
name|friend
name|class
name|QCoreApplicationPrivate
decl_stmt|;
name|friend
name|class
name|QWidget
decl_stmt|;
name|friend
name|class
name|QThreadData
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QObject
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_reregisterTimers(void *)
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|connect
specifier|inline
name|bool
name|QObject
operator|::
name|connect
argument_list|(
argument|const QObject *asender
argument_list|,
argument|const char *asignal
argument_list|,
argument|const char *amember
argument_list|,
argument|Qt::ConnectionType atype
argument_list|)
specifier|const
block|{
return|return
name|connect
argument_list|(
name|asender
argument_list|,
name|asignal
argument_list|,
name|this
argument_list|,
name|amember
argument_list|,
name|atype
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_USERDATA
end_ifndef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QObjectUserData
block|{
name|public
label|:
name|virtual
operator|~
name|QObjectUserData
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|qdoc
end_ifdef
begin_function_decl
name|T
name|qFindChild
parameter_list|(
specifier|const
name|QObject
modifier|*
name|o
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QList
operator|<
name|T
operator|>
name|qFindChildren
argument_list|(
specifier|const
name|QObject
operator|*
name|oobj
argument_list|,
specifier|const
name|QString
operator|&
name|name
operator|=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|T
operator|>
name|qFindChildren
argument_list|(
specifier|const
name|QObject
operator|*
name|o
argument_list|,
specifier|const
name|QRegExp
operator|&
name|re
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_DEPRECATED
end_ifdef
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qFindChild
specifier|inline
name|QT_DEPRECATED
name|T
name|qFindChild
argument_list|(
argument|const QObject *o
argument_list|,
argument|const QString&name = QString()
argument_list|)
block|{
return|return
name|o
operator|->
name|findChild
operator|<
name|T
operator|>
operator|(
name|name
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
DECL|function|qFindChildren
specifier|inline
name|QT_DEPRECATED
name|QList
operator|<
name|T
operator|>
name|qFindChildren
argument_list|(
argument|const QObject *o
argument_list|,
argument|const QString&name = QString()
argument_list|)
block|{
return|return
name|o
operator|->
name|findChildren
operator|<
name|T
operator|>
operator|(
name|name
operator|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qFindChildren
specifier|inline
name|QT_DEPRECATED
name|QList
operator|<
name|T
operator|>
name|qFindChildren
argument_list|(
argument|const QObject *o
argument_list|,
argument|const QRegExp&re
argument_list|)
block|{
return|return
name|o
operator|->
name|findChildren
operator|<
name|T
operator|>
operator|(
name|re
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_DEPRECATED
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|qobject_cast
specifier|inline
name|T
name|qobject_cast
argument_list|(
argument|QObject *object
argument_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_QOBJECT_CHECK
argument_list|)
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
name|object
operator|)
operator|->
name|qt_check_for_QOBJECT_macro
argument_list|(
operator|*
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
name|object
operator|)
argument_list|)
block|;
endif|#
directive|endif
return|return
name|static_cast
operator|<
name|T
operator|>
operator|(
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
name|object
operator|)
operator|->
name|staticMetaObject
operator|.
name|cast
argument_list|(
name|object
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|qobject_cast
specifier|inline
name|T
name|qobject_cast
argument_list|(
argument|const QObject *object
argument_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_QOBJECT_CHECK
argument_list|)
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
name|object
operator|)
operator|->
name|qt_check_for_QOBJECT_macro
argument_list|(
operator|*
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
name|const_cast
operator|<
name|QObject
operator|*
operator|>
operator|(
name|object
operator|)
operator|)
argument_list|)
block|;
endif|#
directive|endif
return|return
name|static_cast
operator|<
name|T
operator|>
operator|(
name|reinterpret_cast
operator|<
name|T
operator|>
operator|(
name|object
operator|)
operator|->
name|staticMetaObject
operator|.
name|cast
argument_list|(
name|object
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qobject_interface_iid
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
specifier|const
name|char
operator|*
name|qobject_interface_iid
argument_list|()
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_MOC_RUN
end_ifndef
begin_define
DECL|macro|Q_DECLARE_INTERFACE
define|#
directive|define
name|Q_DECLARE_INTERFACE
parameter_list|(
name|IFace
parameter_list|,
name|IId
parameter_list|)
define|\
value|template<> inline const char *qobject_interface_iid<IFace *>() \     { return IId; } \     template<> inline IFace *qobject_cast<IFace *>(QObject *object) \     { return reinterpret_cast<IFace *>((object ? object->qt_metacast(IId) : 0)); } \     template<> inline IFace *qobject_cast<IFace *>(const QObject *object) \     { return reinterpret_cast<IFace *>((object ? const_cast<QObject *>(object)->qt_metacast(IId) : 0)); }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_MOC_RUN
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QObject
operator|*
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOBJECT_H
end_comment
end_unit
