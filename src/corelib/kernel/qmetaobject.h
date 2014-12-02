begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 Olivier Goffart<ogoffart@woboq.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETAOBJECT_H
end_ifndef
begin_define
DECL|macro|QMETAOBJECT_H
define|#
directive|define
name|QMETAOBJECT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|Q_METAMETHOD_INVOKE_MAX_ARGS
define|#
directive|define
name|Q_METAMETHOD_INVOKE_MAX_ARGS
value|10
end_define
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMetaMethod
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
specifier|inline
name|QMetaMethod
argument_list|()
operator|:
name|mobj
argument_list|(
literal|0
argument_list|)
operator|,
name|handle
argument_list|(
literal|0
argument_list|)
block|{}
name|QByteArray
name|methodSignature
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|name
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|typeName
argument_list|()
specifier|const
expr_stmt|;
name|int
name|returnType
argument_list|()
specifier|const
expr_stmt|;
name|int
name|parameterCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|parameterType
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|void
name|getParameterTypes
argument_list|(
name|int
operator|*
name|types
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|parameterTypes
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|parameterNames
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|tag
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|Access
block|{
name|Private
block|,
name|Protected
block|,
name|Public
block|}
enum|;
name|Access
name|access
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|MethodType
block|{
name|Method
block|,
name|Signal
block|,
name|Slot
block|,
name|Constructor
block|}
enum|;
name|MethodType
name|methodType
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|Attributes
block|{
name|Compatibility
init|=
literal|0x1
block|,
name|Cloned
init|=
literal|0x2
block|,
name|Scriptable
init|=
literal|0x4
block|}
enum|;
name|int
name|attributes
argument_list|()
specifier|const
expr_stmt|;
name|int
name|methodIndex
argument_list|()
specifier|const
expr_stmt|;
name|int
name|revision
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|QMetaObject
operator|*
name|enclosingMetaObject
argument_list|()
specifier|const
block|{
return|return
name|mobj
return|;
block|}
name|bool
name|invoke
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|Qt
operator|::
name|ConnectionType
name|connectionType
argument_list|,
name|QGenericReturnArgument
name|returnValue
argument_list|,
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|bool
name|invoke
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|QGenericReturnArgument
name|returnValue
argument_list|,
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
decl|const
block|{
return|return
name|invoke
argument_list|(
name|object
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|returnValue
argument_list|,
name|val0
argument_list|,
name|val1
argument_list|,
name|val2
argument_list|,
name|val3
argument_list|,
name|val4
argument_list|,
name|val5
argument_list|,
name|val6
argument_list|,
name|val7
argument_list|,
name|val8
argument_list|,
name|val9
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|invoke
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|Qt
operator|::
name|ConnectionType
name|connectionType
argument_list|,
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
decl|const
block|{
return|return
name|invoke
argument_list|(
name|object
argument_list|,
name|connectionType
argument_list|,
name|QGenericReturnArgument
argument_list|()
argument_list|,
name|val0
argument_list|,
name|val1
argument_list|,
name|val2
argument_list|,
name|val3
argument_list|,
name|val4
argument_list|,
name|val5
argument_list|,
name|val6
argument_list|,
name|val7
argument_list|,
name|val8
argument_list|,
name|val9
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|invoke
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
decl|const
block|{
return|return
name|invoke
argument_list|(
name|object
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|QGenericReturnArgument
argument_list|()
argument_list|,
name|val0
argument_list|,
name|val1
argument_list|,
name|val2
argument_list|,
name|val3
argument_list|,
name|val4
argument_list|,
name|val5
argument_list|,
name|val6
argument_list|,
name|val7
argument_list|,
name|val8
argument_list|,
name|val9
argument_list|)
return|;
block|}
name|bool
name|invokeOnGadget
argument_list|(
name|void
operator|*
name|gadget
argument_list|,
name|QGenericReturnArgument
name|returnValue
argument_list|,
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|bool
name|invokeOnGadget
argument_list|(
name|void
operator|*
name|gadget
argument_list|,
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
decl|const
block|{
return|return
name|invokeOnGadget
argument_list|(
name|gadget
argument_list|,
name|QGenericReturnArgument
argument_list|()
argument_list|,
name|val0
argument_list|,
name|val1
argument_list|,
name|val2
argument_list|,
name|val3
argument_list|,
name|val4
argument_list|,
name|val5
argument_list|,
name|val6
argument_list|,
name|val7
argument_list|,
name|val8
argument_list|,
name|val9
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|mobj
operator|!=
literal|0
return|;
block|}
ifdef|#
directive|ifdef
name|Q_QDOC
specifier|static
name|QMetaMethod
name|fromSignal
parameter_list|(
name|PointerToMemberFunction
name|signal
parameter_list|)
function_decl|;
else|#
directive|else
name|template
operator|<
name|typename
name|Func
operator|>
specifier|static
specifier|inline
name|QMetaMethod
name|fromSignal
argument_list|(
argument|Func signal
argument_list|)
block|{
typedef|typedef
name|QtPrivate
operator|::
name|FunctionPointer
operator|<
name|Func
operator|>
name|SignalType
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|QtPrivate::HasQ_OBJECT_Macro<typename SignalType::Object>::Value
argument_list|,
literal|"No Q_OBJECT in the class with the signal"
argument_list|)
expr_stmt|;
return|return
name|fromSignalImpl
argument_list|(
operator|&
name|SignalType
operator|::
name|Object
operator|::
name|staticMetaObject
argument_list|,
name|reinterpret_cast
operator|<
name|void
operator|*
operator|*
operator|>
operator|(
operator|&
name|signal
operator|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_comment
comment|// signature() has been renamed to methodSignature() in Qt 5.
end_comment
begin_comment
comment|// Warning, that function returns a QByteArray; check the life time if
end_comment
begin_comment
comment|// you convert to char*.
end_comment
begin_decl_stmt
name|char
modifier|*
name|signature
argument_list|(
expr|struct
name|renamedInQt5_warning_checkTheLifeTime
operator|*
operator|=
literal|0
argument_list|)
name|Q_DECL_EQ_DELETE
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|QMetaMethod
name|fromSignalImpl
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|const
name|QMetaObject
modifier|*
name|mobj
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|handle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QMetaMethodPrivate
decl_stmt|;
end_decl_stmt
begin_macro
name|friend
end_macro
begin_struct_decl
struct_decl|struct
name|QMetaObject
struct_decl|;
end_struct_decl
begin_macro
name|friend
end_macro
begin_struct_decl
struct_decl|struct
name|QMetaObjectPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
name|friend
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMetaMethod
operator|&
name|m1
operator|,
specifier|const
name|QMetaMethod
operator|&
name|m2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMetaMethod
operator|&
name|m1
operator|,
specifier|const
name|QMetaMethod
operator|&
name|m2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMetaMethod
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMetaMethod
operator|&
name|m1
operator|,
specifier|const
name|QMetaMethod
operator|&
name|m2
operator|)
block|{
return|return
name|m1
operator|.
name|mobj
operator|==
name|m2
operator|.
name|mobj
operator|&&
name|m1
operator|.
name|handle
operator|==
name|m2
operator|.
name|handle
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMetaMethod
operator|&
name|m1
operator|,
specifier|const
name|QMetaMethod
operator|&
name|m2
operator|)
block|{
return|return
operator|!
operator|(
name|m1
operator|==
name|m2
operator|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMetaEnum
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
specifier|inline
name|QMetaEnum
argument_list|()
operator|:
name|mobj
argument_list|(
literal|0
argument_list|)
operator|,
name|handle
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isFlag
argument_list|()
specifier|const
expr_stmt|;
name|int
name|keyCount
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|key
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|value
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|char
operator|*
name|scope
argument_list|()
specifier|const
expr_stmt|;
name|int
name|keyToValue
argument_list|(
specifier|const
name|char
operator|*
name|key
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|char
modifier|*
name|valueToKey
argument_list|(
name|int
name|value
argument_list|)
decl|const
decl_stmt|;
name|int
name|keysToValue
argument_list|(
specifier|const
name|char
operator|*
name|keys
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|valueToKeys
argument_list|(
name|int
name|value
argument_list|)
decl|const
decl_stmt|;
specifier|inline
specifier|const
name|QMetaObject
operator|*
name|enclosingMetaObject
argument_list|()
specifier|const
block|{
return|return
name|mobj
return|;
block|}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|name
argument_list|()
operator|!=
literal|0
return|;
block|}
name|private
label|:
specifier|const
name|QMetaObject
modifier|*
name|mobj
decl_stmt|;
name|uint
name|handle
decl_stmt|;
name|friend
struct_decl|struct
name|QMetaObject
struct_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMetaEnum
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMetaProperty
block|{
name|public
label|:
name|QMetaProperty
argument_list|()
expr_stmt|;
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|typeName
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
operator|::
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|int
name|userType
argument_list|()
specifier|const
expr_stmt|;
name|int
name|propertyIndex
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReadable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isWritable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isResettable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDesignable
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isScriptable
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isStored
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isEditable
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isUser
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isConstant
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isFinal
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isFlagType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isEnumType
argument_list|()
specifier|const
expr_stmt|;
name|QMetaEnum
name|enumerator
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasNotifySignal
argument_list|()
specifier|const
expr_stmt|;
name|QMetaMethod
name|notifySignal
argument_list|()
specifier|const
expr_stmt|;
name|int
name|notifySignalIndex
argument_list|()
specifier|const
expr_stmt|;
name|int
name|revision
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|read
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
argument_list|)
decl|const
decl_stmt|;
name|bool
name|write
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl|const
decl_stmt|;
name|bool
name|reset
argument_list|(
name|QObject
operator|*
name|obj
argument_list|)
decl|const
decl_stmt|;
name|QVariant
name|readOnGadget
argument_list|(
specifier|const
name|void
operator|*
name|gadget
argument_list|)
decl|const
decl_stmt|;
name|bool
name|writeOnGadget
argument_list|(
name|void
operator|*
name|gadget
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl|const
decl_stmt|;
name|bool
name|resetOnGadget
argument_list|(
name|void
operator|*
name|gadget
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasStdCppSet
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|isReadable
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|QMetaObject
operator|*
name|enclosingMetaObject
argument_list|()
specifier|const
block|{
return|return
name|mobj
return|;
block|}
name|private
label|:
name|int
name|registerPropertyType
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mobj
decl_stmt|;
name|uint
name|handle
decl_stmt|;
name|int
name|idx
decl_stmt|;
name|QMetaEnum
name|menum
decl_stmt|;
name|friend
struct_decl|struct
name|QMetaObject
struct_decl|;
name|friend
struct_decl|struct
name|QMetaObjectPrivate
struct_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMetaClassInfo
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
specifier|inline
name|QMetaClassInfo
argument_list|()
operator|:
name|mobj
argument_list|(
literal|0
argument_list|)
operator|,
name|handle
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|value
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|QMetaObject
operator|*
name|enclosingMetaObject
argument_list|()
specifier|const
block|{
return|return
name|mobj
return|;
block|}
name|private
label|:
specifier|const
name|QMetaObject
modifier|*
name|mobj
decl_stmt|;
name|uint
name|handle
decl_stmt|;
name|friend
struct_decl|struct
name|QMetaObject
struct_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMetaClassInfo
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMETAOBJECT_H
end_comment
end_unit
