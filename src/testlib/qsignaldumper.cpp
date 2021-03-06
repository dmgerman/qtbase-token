begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qsignaldumper_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestlog_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qmetaobject_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|function|qPrintMessage
specifier|inline
specifier|static
name|void
name|qPrintMessage
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
block|{
name|QTestLog
operator|::
name|info
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|Q_GLOBAL_STATIC
argument_list|(
argument|QList<QByteArray>
argument_list|,
argument|ignoreClasses
argument_list|)
DECL|member|iLevel
specifier|static
name|int
name|iLevel
init|=
literal|0
decl_stmt|;
DECL|member|ignoreLevel
specifier|static
name|int
name|ignoreLevel
init|=
literal|0
decl_stmt|;
DECL|enumerator|IndentSpacesCount
enum|enum
block|{
name|IndentSpacesCount
init|=
literal|4
block|}
enum|;
DECL|function|qSignalDumperCallback
specifier|static
name|void
name|qSignalDumperCallback
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
name|signal_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|caller
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|argv
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|argv
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|caller
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|mo
argument_list|)
expr_stmt|;
name|QMetaMethod
name|member
init|=
name|QMetaObjectPrivate
operator|::
name|signal
argument_list|(
name|mo
argument_list|,
name|signal_index
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|member
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|&&
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|contains
argument_list|(
name|mo
operator|->
name|className
argument_list|()
argument_list|)
condition|)
block|{
operator|++
name|QTest
operator|::
name|ignoreLevel
expr_stmt|;
return|return;
block|}
name|QByteArray
name|str
decl_stmt|;
name|str
operator|.
name|fill
argument_list|(
literal|' '
argument_list|,
name|QTest
operator|::
name|iLevel
operator|++
operator|*
name|QTest
operator|::
name|IndentSpacesCount
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|"Signal: "
expr_stmt|;
name|str
operator|+=
name|mo
operator|->
name|className
argument_list|()
expr_stmt|;
name|str
operator|+=
literal|'('
expr_stmt|;
name|QString
name|objname
init|=
name|caller
operator|->
name|objectName
argument_list|()
decl_stmt|;
name|str
operator|+=
name|objname
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|objname
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
literal|' '
expr_stmt|;
name|str
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|quintptr
argument_list|(
name|caller
argument_list|)
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|") "
expr_stmt|;
name|str
operator|+=
name|member
operator|.
name|name
argument_list|()
expr_stmt|;
name|str
operator|+=
literal|" ("
expr_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|args
init|=
name|member
operator|.
name|parameterTypes
argument_list|()
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
name|args
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QByteArray
modifier|&
name|arg
init|=
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|typeId
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|.
name|endsWith
argument_list|(
literal|'*'
argument_list|)
operator|||
name|arg
operator|.
name|endsWith
argument_list|(
literal|'&'
argument_list|)
condition|)
block|{
name|str
operator|+=
literal|'('
expr_stmt|;
name|str
operator|+=
name|arg
expr_stmt|;
name|str
operator|+=
literal|')'
expr_stmt|;
if|if
condition|(
name|arg
operator|.
name|endsWith
argument_list|(
literal|'&'
argument_list|)
condition|)
name|str
operator|+=
literal|'@'
expr_stmt|;
name|quintptr
name|addr
init|=
name|quintptr
argument_list|(
operator|*
cast|reinterpret_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
argument_list|)
decl_stmt|;
name|str
operator|.
name|append
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|addr
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|typeId
operator|!=
name|QMetaType
operator|::
name|UnknownType
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|typeId
operator|!=
name|QMetaType
operator|::
name|Void
argument_list|)
expr_stmt|;
comment|// void parameter => metaobject is corrupt
name|str
operator|.
name|append
argument_list|(
name|arg
argument_list|)
operator|.
name|append
argument_list|(
literal|'('
argument_list|)
operator|.
name|append
argument_list|(
name|QVariant
argument_list|(
name|typeId
argument_list|,
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
operator|.
name|append
argument_list|(
literal|')'
argument_list|)
expr_stmt|;
block|}
name|str
operator|.
name|append
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|str
operator|.
name|endsWith
argument_list|(
literal|", "
argument_list|)
condition|)
name|str
operator|.
name|chop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|str
operator|.
name|append
argument_list|(
literal|')'
argument_list|)
expr_stmt|;
name|qPrintMessage
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
DECL|function|qSignalDumperCallbackSlot
specifier|static
name|void
name|qSignalDumperCallbackSlot
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
name|method_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|caller
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|argv
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|argv
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|caller
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|mo
argument_list|)
expr_stmt|;
name|QMetaMethod
name|member
init|=
name|mo
operator|->
name|method
argument_list|(
name|method_index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|member
operator|.
name|isValid
argument_list|()
condition|)
return|return;
if|if
condition|(
name|QTest
operator|::
name|ignoreLevel
operator|||
operator|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|&&
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|contains
argument_list|(
name|mo
operator|->
name|className
argument_list|()
argument_list|)
operator|)
condition|)
return|return;
name|QByteArray
name|str
decl_stmt|;
name|str
operator|.
name|fill
argument_list|(
literal|' '
argument_list|,
name|QTest
operator|::
name|iLevel
operator|*
name|QTest
operator|::
name|IndentSpacesCount
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|"Slot: "
expr_stmt|;
name|str
operator|+=
name|mo
operator|->
name|className
argument_list|()
expr_stmt|;
name|str
operator|+=
literal|'('
expr_stmt|;
name|QString
name|objname
init|=
name|caller
operator|->
name|objectName
argument_list|()
decl_stmt|;
name|str
operator|+=
name|objname
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|objname
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
literal|' '
expr_stmt|;
name|str
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|quintptr
argument_list|(
name|caller
argument_list|)
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|") "
expr_stmt|;
name|str
operator|+=
name|member
operator|.
name|methodSignature
argument_list|()
expr_stmt|;
name|qPrintMessage
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
DECL|function|qSignalDumperCallbackEndSignal
specifier|static
name|void
name|qSignalDumperCallbackEndSignal
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
comment|/*signal_index*/
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|caller
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|caller
operator|->
name|metaObject
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|&&
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|contains
argument_list|(
name|caller
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
condition|)
block|{
operator|--
name|QTest
operator|::
name|ignoreLevel
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|QTest
operator|::
name|ignoreLevel
operator|>=
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
operator|--
name|QTest
operator|::
name|iLevel
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|QTest
operator|::
name|iLevel
operator|>=
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
begin_function
DECL|function|startDump
name|void
name|QSignalDumper
operator|::
name|startDump
parameter_list|()
block|{
specifier|static
name|QSignalSpyCallbackSet
name|set
init|=
block|{
name|QTest
operator|::
name|qSignalDumperCallback
block|,
name|QTest
operator|::
name|qSignalDumperCallbackSlot
block|,
name|QTest
operator|::
name|qSignalDumperCallbackEndSignal
block|,
literal|0
block|}
decl_stmt|;
name|qt_register_signal_spy_callbacks
argument_list|(
name|set
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endDump
name|void
name|QSignalDumper
operator|::
name|endDump
parameter_list|()
block|{
specifier|static
name|QSignalSpyCallbackSet
name|nset
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|qt_register_signal_spy_callbacks
argument_list|(
name|nset
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ignoreClass
name|void
name|QSignalDumper
operator|::
name|ignoreClass
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|klass
parameter_list|)
block|{
if|if
condition|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
condition|)
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|append
argument_list|(
name|klass
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearIgnoredClasses
name|void
name|QSignalDumper
operator|::
name|clearIgnoredClasses
parameter_list|()
block|{
if|if
condition|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
condition|)
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
