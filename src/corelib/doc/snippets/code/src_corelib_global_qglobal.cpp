begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_class
DECL|class|MyClass
class|class
name|MyClass
block|{
public|public:
DECL|enum|Option
enum|enum
name|Option
block|{
DECL|enumerator|NoOptions
name|NoOptions
init|=
literal|0x0
block|,
DECL|enumerator|ShowTabs
name|ShowTabs
init|=
literal|0x1
block|,
DECL|enumerator|ShowAll
name|ShowAll
init|=
literal|0x2
block|,
DECL|enumerator|SqueezeBlank
name|SqueezeBlank
init|=
literal|0x4
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Options
argument_list|,
argument|Option
argument_list|)
operator|...
block|}
class|;
end_class
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|MyClass::Options
argument_list|)
end_macro
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [meta-object flags]
end_comment
begin_macro
name|Q_FLAG
argument_list|(
argument|Options
argument_list|)
end_macro
begin_comment
comment|//! [meta-object flags]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_typedef
DECL|typedef|Flags
typedef|typedef
name|QFlags
argument_list|<
name|Enum
argument_list|>
name|Flags
typedef|;
end_typedef
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|myValue
name|int
name|myValue
init|=
literal|10
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|minValue
name|int
name|minValue
init|=
literal|2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|maxValue
name|int
name|maxValue
init|=
literal|6
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|boundedValue
name|int
name|boundedValue
init|=
name|qBound
argument_list|(
name|minValue
argument_list|,
name|myValue
argument_list|,
name|maxValue
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// boundedValue == 6
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_if
if|if
condition|(
operator|!
name|driver
argument_list|()
operator|->
name|isOpen
argument_list|()
operator|||
name|driver
argument_list|()
operator|->
name|isOpenError
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSqlQuery::exec: database not open"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_if
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|value
name|qint64
name|value
init|=
name|Q_INT64_C
argument_list|(
literal|932838457459459
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|value
name|quint64
name|value
init|=
name|Q_UINT64_C
argument_list|(
literal|932838457459459
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function_decl
name|void
name|myMsgHandler
parameter_list|(
name|QtMsgType
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|value
name|qint64
name|value
init|=
name|Q_INT64_C
argument_list|(
literal|932838457459459
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|value
name|quint64
name|value
init|=
name|Q_UINT64_C
argument_list|(
literal|932838457459459
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|absoluteValue
name|int
name|absoluteValue
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|myValue
name|int
name|myValue
init|=
operator|-
literal|4
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|absoluteValue
operator|=
name|qAbs
argument_list|(
name|myValue
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// absoluteValue == 4
end_comment
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|valueA
name|qreal
name|valueA
init|=
literal|2.3
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|valueB
name|qreal
name|valueB
init|=
literal|2.7
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|roundedValueA
name|int
name|roundedValueA
init|=
name|qRound
argument_list|(
name|valueA
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// roundedValueA = 2
end_comment
begin_decl_stmt
DECL|variable|roundedValueB
name|int
name|roundedValueB
init|=
name|qRound
argument_list|(
name|valueB
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// roundedValueB = 3
end_comment
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
DECL|variable|valueA
name|qreal
name|valueA
init|=
literal|42949672960.3
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|valueB
name|qreal
name|valueB
init|=
literal|42949672960.7
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|roundedValueA
name|qint64
name|roundedValueA
init|=
name|qRound64
argument_list|(
name|valueA
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// roundedValueA = 42949672960
end_comment
begin_decl_stmt
DECL|variable|roundedValueB
name|qint64
name|roundedValueB
init|=
name|qRound64
argument_list|(
name|valueB
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// roundedValueB = 42949672961
end_comment
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
DECL|variable|myValue
name|int
name|myValue
init|=
literal|6
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|yourValue
name|int
name|yourValue
init|=
literal|4
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|minValue
name|int
name|minValue
init|=
name|qMin
argument_list|(
name|myValue
argument_list|,
name|yourValue
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// minValue == yourValue
end_comment
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
DECL|variable|myValue
name|int
name|myValue
init|=
literal|6
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|yourValue
name|int
name|yourValue
init|=
literal|4
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|maxValue
name|int
name|maxValue
init|=
name|qMax
argument_list|(
name|myValue
argument_list|,
name|yourValue
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// maxValue == myValue
end_comment
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_decl_stmt
DECL|variable|myValue
name|int
name|myValue
init|=
literal|10
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|minValue
name|int
name|minValue
init|=
literal|2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|maxValue
name|int
name|maxValue
init|=
literal|6
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|boundedValue
name|int
name|boundedValue
init|=
name|qBound
argument_list|(
name|minValue
argument_list|,
name|myValue
argument_list|,
name|maxValue
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// boundedValue == 6
end_comment
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_if
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x040100
end_if
begin_decl_stmt
DECL|variable|icon
name|QIcon
name|icon
init|=
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_TrashIcon
argument_list|)
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|pixmap
name|QPixmap
name|pixmap
init|=
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_TrashIcon
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QIcon
name|icon
parameter_list|(
name|pixmap
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|// File: div.cpp
end_comment
begin_include
include|#
directive|include
file|<QtGlobal>
end_include
begin_function
DECL|function|divide
name|int
name|divide
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|b
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
name|a
operator|/
name|b
return|;
block|}
end_function
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_label
name|ASSERT
label|:
end_label
begin_expr_stmt
literal|"b != 0"
name|in
name|file
name|div
operator|.
name|cpp
operator|,
name|line
literal|7
comment|//! [18]
comment|//! [19]
comment|// File: div.cpp
include|#
directive|include
file|<QtGlobal>
DECL|function|divide
name|int
name|divide
argument_list|(
argument|int a
argument_list|,
argument|int b
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|b
operator|!=
literal|0
argument_list|,
literal|"divide"
argument_list|,
literal|"division by zero"
argument_list|)
block|;
return|return
name|a
operator|/
name|b
return|;
block|}
end_expr_stmt
begin_comment
comment|//! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_decl_stmt
DECL|variable|divide
name|ASSERT
name|failure
name|in
name|divide
range|:
literal|"division by zero"
decl_stmt|,
name|file
name|div
operator|.
name|cpp
decl_stmt|,
name|line
decl|7
comment|//! [20]
comment|//! [21]
DECL|variable|a
name|int
modifier|*
name|a
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_CHECK_PTR
argument_list|(
name|a
operator|=
operator|new
name|int
index|[
literal|80
index|]
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// WRONG!
end_comment
begin_expr_stmt
name|a
operator|=
operator|new
operator|(
name|nothrow
operator|)
name|int
index|[
literal|80
index|]
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Right
end_comment
begin_expr_stmt
DECL|variable|a
name|Q_CHECK_PTR
argument_list|(
name|a
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_function
template|template
parameter_list|<
name|typename
name|TInputType
parameter_list|>
DECL|function|myMin
specifier|const
name|TInputType
modifier|&
name|myMin
parameter_list|(
specifier|const
name|TInputType
modifier|&
name|value1
parameter_list|,
specifier|const
name|TInputType
modifier|&
name|value2
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"was called with value1:"
operator|<<
name|value1
operator|<<
literal|"value2:"
operator|<<
name|value2
expr_stmt|;
if|if
condition|(
name|value1
operator|<
name|value2
condition|)
return|return
name|value1
return|;
else|else
return|return
name|value2
return|;
block|}
end_function
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_function
DECL|function|myMessageOutput
name|void
name|myMessageOutput
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|QMessageLogContext
modifier|&
name|context
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
block|{
name|QByteArray
name|localMsg
init|=
name|msg
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QtDebugMsg
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Debug: %s (%s:%u, %s)\n"
argument_list|,
name|localMsg
operator|.
name|constData
argument_list|()
argument_list|,
name|context
operator|.
name|file
argument_list|,
name|context
operator|.
name|line
argument_list|,
name|context
operator|.
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtInfoMsg
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Info: %s (%s:%u, %s)\n"
argument_list|,
name|localMsg
operator|.
name|constData
argument_list|()
argument_list|,
name|context
operator|.
name|file
argument_list|,
name|context
operator|.
name|line
argument_list|,
name|context
operator|.
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtWarningMsg
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning: %s (%s:%u, %s)\n"
argument_list|,
name|localMsg
operator|.
name|constData
argument_list|()
argument_list|,
name|context
operator|.
name|file
argument_list|,
name|context
operator|.
name|line
argument_list|,
name|context
operator|.
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtCriticalMsg
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Critical: %s (%s:%u, %s)\n"
argument_list|,
name|localMsg
operator|.
name|constData
argument_list|()
argument_list|,
name|context
operator|.
name|file
argument_list|,
name|context
operator|.
name|line
argument_list|,
name|context
operator|.
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtFatalMsg
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Fatal: %s (%s:%u, %s)\n"
argument_list|,
name|localMsg
operator|.
name|constData
argument_list|()
argument_list|,
name|context
operator|.
name|file
argument_list|,
name|context
operator|.
name|line
argument_list|,
name|context
operator|.
name|function
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|qInstallMessageHandler
argument_list|(
name|myMessageOutput
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
operator|...
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_expr_stmt
name|qDebug
argument_list|(
literal|"Items in list: %d"
argument_list|,
name|myList
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_expr_stmt
DECL|variable|i
name|qDebug
argument_list|()
operator|<<
literal|"Brush:"
operator|<<
name|myQBrush
operator|<<
literal|"Other value:"
operator|<<
name|i
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [25]
end_comment
begin_comment
comment|//! [qInfo_printf]
end_comment
begin_expr_stmt
name|qInfo
argument_list|(
literal|"Items in list: %d"
argument_list|,
name|myList
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [qInfo_printf]
end_comment
begin_comment
comment|//! [qInfo_stream]
end_comment
begin_expr_stmt
DECL|variable|i
name|qInfo
argument_list|()
operator|<<
literal|"Brush:"
operator|<<
name|myQBrush
operator|<<
literal|"Other value:"
operator|<<
name|i
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [qInfo_stream]
end_comment
begin_comment
comment|//! [26]
end_comment
begin_function
DECL|function|f
name|void
name|f
parameter_list|(
name|int
name|c
parameter_list|)
block|{
if|if
condition|(
name|c
operator|>
literal|200
condition|)
name|qWarning
argument_list|(
literal|"f: bad argument, c == %d"
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [26]
end_comment
begin_comment
comment|//! [27]
end_comment
begin_expr_stmt
name|qWarning
argument_list|()
operator|<<
literal|"Brush:"
operator|<<
name|myQBrush
operator|<<
literal|"Other value:"
DECL|variable|i
operator|<<
name|i
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [27]
end_comment
begin_comment
comment|//! [28]
end_comment
begin_function
DECL|function|load
name|void
name|load
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|exists
argument_list|()
condition|)
name|qCritical
argument_list|(
literal|"File '%s' does not exist!"
argument_list|,
name|qUtf8Printable
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [28]
end_comment
begin_comment
comment|//! [29]
end_comment
begin_expr_stmt
name|qCritical
argument_list|()
operator|<<
literal|"Brush:"
operator|<<
name|myQBrush
operator|<<
literal|"Other value:"
DECL|variable|i
operator|<<
name|i
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [29]
end_comment
begin_comment
comment|//! [30]
end_comment
begin_function
DECL|function|divide
name|int
name|divide
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
if|if
condition|(
name|b
operator|==
literal|0
condition|)
comment|// program error
name|qFatal
argument_list|(
literal|"divide: cannot divide by zero"
argument_list|)
expr_stmt|;
return|return
name|a
operator|/
name|b
return|;
block|}
end_function
begin_comment
comment|//! [30]
end_comment
begin_comment
comment|//! [31]
end_comment
begin_forever
forever|forever
block|{
operator|...
block|}
end_forever
begin_comment
comment|//! [31]
end_comment
begin_comment
comment|//! [32]
end_comment
begin_expr_stmt
name|CONFIG
operator|+=
name|no_keywords
comment|//! [32]
comment|//! [33]
name|CONFIG
operator|+=
name|no_keywords
comment|//! [33]
comment|//! [34]
name|QString
name|FriendlyConversation
operator|::
name|greeting
operator|(
name|int
name|type
operator|)
block|{
specifier|static
specifier|const
name|char
operator|*
name|greeting_strings
index|[]
operator|=
block|{
name|QT_TR_NOOP
argument_list|(
literal|"Hello"
argument_list|)
block|,
name|QT_TR_NOOP
argument_list|(
literal|"Goodbye"
argument_list|)
block|}
block|;
return|return
name|tr
argument_list|(
name|greeting_strings
index|[
name|type
index|]
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|//! [34]
end_comment
begin_comment
comment|//! [35]
end_comment
begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|greeting_strings
index|[]
init|=
block|{
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"FriendlyConversation"
argument_list|,
literal|"Hello"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"FriendlyConversation"
argument_list|,
literal|"Goodbye"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|greeting
name|QString
name|FriendlyConversation
operator|::
name|greeting
parameter_list|(
name|int
name|type
parameter_list|)
block|{
return|return
name|tr
argument_list|(
name|greeting_strings
index|[
name|type
index|]
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|global_greeting
name|QString
name|global_greeting
parameter_list|(
name|int
name|type
parameter_list|)
block|{
return|return
name|qApp
operator|->
name|translate
argument_list|(
literal|"FriendlyConversation"
argument_list|,
name|greeting_strings
index|[
name|type
index|]
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [35]
end_comment
begin_comment
comment|//! [36]
end_comment
begin_expr_stmt
specifier|static
block|{
specifier|const
name|char
operator|*
name|source
block|;
specifier|const
name|char
operator|*
name|comment
block|; }
name|greeting_strings
index|[]
operator|=
block|{
name|QT_TRANSLATE_NOOP3
argument_list|(
literal|"FriendlyConversation"
argument_list|,
literal|"Hello"
argument_list|,
literal|"A really friendly hello"
argument_list|)
block|,
name|QT_TRANSLATE_NOOP3
argument_list|(
literal|"FriendlyConversation"
argument_list|,
literal|"Goodbye"
argument_list|,
literal|"A really friendly goodbye"
argument_list|)
block|}
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|greeting
name|QString
name|FriendlyConversation
operator|::
name|greeting
parameter_list|(
name|int
name|type
parameter_list|)
block|{
return|return
name|tr
argument_list|(
name|greeting_strings
index|[
name|type
index|]
operator|.
name|source
argument_list|,
name|greeting_strings
index|[
name|type
index|]
operator|.
name|comment
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|global_greeting
name|QString
name|global_greeting
parameter_list|(
name|int
name|type
parameter_list|)
block|{
return|return
name|qApp
operator|->
name|translate
argument_list|(
literal|"FriendlyConversation"
argument_list|,
name|greeting_strings
index|[
name|type
index|]
operator|.
name|source
argument_list|,
name|greeting_strings
index|[
name|type
index|]
operator|.
name|comment
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [36]
end_comment
begin_comment
comment|//! [qttrid]
end_comment
begin_comment
comment|//% "%n fooish bar(s) found.\n"
end_comment
begin_comment
comment|//% "Do you want to continue?"
end_comment
begin_decl_stmt
DECL|variable|text
name|QString
name|text
init|=
name|qtTrId
argument_list|(
literal|"qtn_foo_bar"
argument_list|,
name|n
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [qttrid]
end_comment
begin_comment
comment|//! [qttrid_noop]
end_comment
begin_decl_stmt
DECL|variable|ids
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|ids
index|[]
init|=
block|{
comment|//% "This is the first text."
name|QT_TRID_NOOP
argument_list|(
literal|"qtn_1st_text"
argument_list|)
block|,
comment|//% "This is the second text."
name|QT_TRID_NOOP
argument_list|(
literal|"qtn_2nd_text"
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|addLabels
name|void
name|TheClass
operator|::
name|addLabels
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|ids
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
operator|new
name|QLabel
argument_list|(
name|qtTrId
argument_list|(
name|ids
index|[
name|i
index|]
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [qttrid_noop]
end_comment
begin_comment
comment|//! [37]
end_comment
begin_expr_stmt
name|qWarning
argument_list|(
literal|"%s: %s"
argument_list|,
name|qUtf8Printable
argument_list|(
name|key
argument_list|)
argument_list|,
name|qUtf8Printable
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [37]
end_comment
begin_comment
comment|//! [qUtf16Printable]
end_comment
begin_expr_stmt
name|qWarning
argument_list|(
literal|"%ls: %ls"
argument_list|,
name|qUtf16Printable
argument_list|(
name|key
argument_list|)
argument_list|,
name|qUtf16Printable
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [qUtf16Printable]
end_comment
begin_comment
comment|//! [38]
end_comment
begin_struct
DECL|struct|Point2D
struct|struct
name|Point2D
block|{
DECL|member|x
name|int
name|x
decl_stmt|;
DECL|member|y
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|Point2D
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [38]
end_comment
begin_comment
comment|//! [39]
end_comment
begin_class
DECL|class|Point2D
class|class
name|Point2D
block|{
public|public:
DECL|function|Point2D
name|Point2D
parameter_list|()
block|{
name|data
operator|=
operator|new
name|int
index|[
literal|2
index|]
expr_stmt|;
block|}
DECL|function|Point2D
name|Point2D
parameter_list|(
specifier|const
name|Point2D
modifier|&
name|other
parameter_list|)
block|{
operator|...
block|}
DECL|function|~Point2D
name|~
name|Point2D
parameter_list|()
block|{
operator|delete
index|[]
name|data
expr_stmt|;
block|}
DECL|function|operator =
name|Point2D
modifier|&
name|operator
name|=
parameter_list|(
specifier|const
name|Point2D
modifier|&
name|other
parameter_list|)
block|{
operator|...
block|}
DECL|function|x
name|int
name|x
parameter_list|()
specifier|const
block|{
return|return
name|data
index|[
literal|0
index|]
return|;
block|}
DECL|function|y
name|int
name|y
parameter_list|()
specifier|const
block|{
return|return
name|data
index|[
literal|1
index|]
return|;
block|}
private|private:
DECL|member|data
name|int
modifier|*
name|data
decl_stmt|;
block|}
class|;
end_class
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|Point2D
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [39]
end_comment
begin_comment
comment|//! [40]
end_comment
begin_if
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
end_if
begin_expr_stmt
operator|...
endif|#
directive|endif
operator|or
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
operator|...
endif|#
directive|endif
comment|//! [40]
comment|//! [41]
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
operator|...
endif|#
directive|endif
comment|//! [41]
comment|//! [42]
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
operator|...
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [42]
end_comment
begin_comment
comment|//! [begin namespace macro]
end_comment
begin_namespace
DECL|namespace|QT_NAMESPACE
namespace|namespace
name|QT_NAMESPACE
block|{
comment|//! [begin namespace macro]
comment|//! [end namespace macro]
block|}
end_namespace
begin_comment
comment|//! [end namespace macro]
end_comment
begin_comment
comment|//! [43]
end_comment
begin_class
DECL|class|MyClass
class|class
name|MyClass
super|:
specifier|public
name|QObject
block|{
private|private:
name|Q_DISABLE_COPY
argument_list|(
argument|MyClass
argument_list|)
block|}
class|;
end_class
begin_comment
comment|//! [43]
end_comment
begin_comment
comment|//! [44]
end_comment
begin_class
DECL|class|MyClass
class|class
name|MyClass
super|:
specifier|public
name|QObject
block|{
private|private:
name|MyClass
parameter_list|(
specifier|const
name|MyClass
modifier|&
parameter_list|)
constructor_decl|;
name|MyClass
modifier|&
name|operator
name|=
parameter_list|(
specifier|const
name|MyClass
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [44]
end_comment
begin_comment
comment|//! [45]
end_comment
begin_decl_stmt
DECL|variable|w
name|QWidget
name|w
init|=
name|QWidget
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [45]
end_comment
begin_comment
comment|//! [46]
end_comment
begin_comment
comment|// Instead of comparing with 0.0
end_comment
begin_expr_stmt
name|qFuzzyCompare
argument_list|(
literal|0.0
argument_list|,
literal|1.0e-200
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// This will return false
end_comment
begin_comment
comment|// Compare adding 1 to both values will fix the problem
end_comment
begin_expr_stmt
name|qFuzzyCompare
argument_list|(
literal|1
operator|+
literal|0.0
argument_list|,
literal|1
operator|+
literal|1.0e-200
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// This will return true
end_comment
begin_comment
comment|//! [46]
end_comment
begin_comment
comment|//! [47]
end_comment
begin_function_decl
name|CApaApplication
modifier|*
name|myApplicationFactory
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//! [47]
end_comment
begin_comment
comment|//! [49]
end_comment
begin_function_decl
name|void
name|myMessageHandler
parameter_list|(
name|QtMsgType
parameter_list|,
specifier|const
name|QMessageLogContext
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [49]
end_comment
begin_comment
comment|//! [50]
end_comment
begin_class
DECL|class|B
class|class
name|B
block|{
operator|...
block|}
class|;
end_class
begin_class
DECL|class|C
class|class
name|C
block|{
operator|...
block|}
class|;
end_class
begin_class
DECL|class|D
class|class
name|D
block|{
operator|...
block|}
class|;
end_class
begin_struct
DECL|struct|A
struct|struct
name|A
super|:
specifier|public
name|B
block|{
DECL|member|c
name|C
name|c
decl_stmt|;
DECL|member|d
name|D
name|d
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|//! [50]
end_comment
begin_comment
comment|//! [51]
end_comment
begin_class
DECL|class|QTypeInfo
template|template
parameter_list|<>
class|class
name|QTypeInfo
argument_list|<
name|A
argument_list|>
super|:
specifier|public
name|QTypeInfoMerger
argument_list|<
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|>
block|{
block|}
class|;
end_class
begin_comment
comment|//! [51]
end_comment
begin_comment
comment|//! [qlikely]
end_comment
begin_comment
comment|// the condition inside the "if" will be successful most of the times
end_comment
begin_for
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|365
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|isWorkingDay
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
block|{
operator|...
block|}
operator|...
block|}
end_for
begin_comment
comment|//! [qlikely]
end_comment
begin_comment
comment|//! [qunlikely]
end_comment
begin_function
DECL|function|readConfiguration
name|bool
name|readConfiguration
parameter_list|(
specifier|const
name|QFile
modifier|&
name|file
parameter_list|)
block|{
comment|// We expect to be asked to read an existing file
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|file
operator|.
name|exists
argument_list|()
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"File not found"
expr_stmt|;
return|return
literal|false
return|;
block|}
operator|...
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [qunlikely]
end_comment
begin_comment
comment|//! [qunreachable-enum]
end_comment
begin_enum
DECL|enum|Shapes
enum|enum
name|Shapes
block|{
DECL|enumerator|Rectangle
name|Rectangle
block|,
DECL|enumerator|Triangle
name|Triangle
block|,
DECL|enumerator|Circle
name|Circle
block|,
DECL|enumerator|NumShapes
name|NumShapes
block|}
enum|;
end_enum
begin_comment
comment|//! [qunreachable-enum]
end_comment
begin_comment
comment|//! [qunreachable-switch]
end_comment
begin_switch
switch|switch
condition|(
name|shape
condition|)
block|{
case|case
name|Rectangle
case|:
return|return
name|rectangle
argument_list|()
return|;
case|case
name|Triangle
case|:
return|return
name|triangle
argument_list|()
return|;
case|case
name|Circle
case|:
return|return
name|circle
argument_list|()
return|;
case|case
name|NumShapes
case|:
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
break|break;
block|}
end_switch
begin_comment
comment|//! [qunreachable-switch]
end_comment
begin_comment
comment|//! [qt-version-check]
end_comment
begin_include
include|#
directive|include
file|<QtGlobal>
end_include
begin_if
if|#
directive|if
operator|(
name|QT_VERSION
operator|>=
name|QT_VERSION_CHECK
argument_list|(
literal|5
operator|,
literal|0
operator|,
literal|0
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [qt-version-check]
end_comment
end_unit
