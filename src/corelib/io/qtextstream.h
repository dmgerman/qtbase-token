begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTSTREAM_H
end_ifndef
begin_define
DECL|macro|QTEXTSTREAM_H
define|#
directive|define
name|QTEXTSTREAM_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qchar.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Status
end_ifdef
begin_error
error|#
directive|error
error|qtextstream.h must be included before any header file that defines Status
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QTextCodec
decl_stmt|;
DECL|variable|QTextDecoder
name|class
name|QTextDecoder
decl_stmt|;
DECL|variable|QTextStreamPrivate
name|class
name|QTextStreamPrivate
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QTextStream
comment|// text stream class
decl_stmt|{     Q_DECLARE_PRIVATE(QTextStream
end_function
begin_label
unit|)
name|public
label|:
end_label
begin_enum
enum|enum
name|RealNumberNotation
block|{
name|SmartNotation
block|,
name|FixedNotation
block|,
name|ScientificNotation
block|}
enum|;
end_enum
begin_enum
enum|enum
name|FieldAlignment
block|{
name|AlignLeft
block|,
name|AlignRight
block|,
name|AlignCenter
block|,
name|AlignAccountingStyle
block|}
enum|;
end_enum
begin_enum
enum|enum
name|Status
block|{
name|Ok
block|,
name|ReadPastEnd
block|,
name|ReadCorruptData
block|,
name|WriteFailed
block|}
enum|;
end_enum
begin_enum
enum|enum
name|NumberFlag
block|{
name|ShowBase
init|=
literal|0x1
block|,
name|ForcePoint
init|=
literal|0x2
block|,
name|ForceSign
init|=
literal|0x4
block|,
name|UppercaseBase
init|=
literal|0x8
block|,
name|UppercaseDigits
init|=
literal|0x10
block|}
enum|;
end_enum
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|NumberFlags
argument_list|,
argument|NumberFlag
argument_list|)
end_macro
begin_expr_stmt
name|QTextStream
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|explicit
name|QTextStream
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|explicit
name|QTextStream
argument_list|(
name|FILE
operator|*
name|fileHandle
argument_list|,
name|QIODevice
operator|::
name|OpenMode
name|openMode
operator|=
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|explicit
name|QTextStream
argument_list|(
name|QString
operator|*
name|string
argument_list|,
name|QIODevice
operator|::
name|OpenMode
name|openMode
operator|=
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|explicit
name|QTextStream
argument_list|(
name|QByteArray
operator|*
name|array
argument_list|,
name|QIODevice
operator|::
name|OpenMode
name|openMode
operator|=
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|explicit
name|QTextStream
argument_list|(
specifier|const
name|QByteArray
operator|&
name|array
argument_list|,
name|QIODevice
operator|::
name|OpenMode
name|openMode
operator|=
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|virtual
operator|~
name|QTextStream
argument_list|()
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_function_decl
name|void
name|setCodec
parameter_list|(
name|QTextCodec
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setCodec
parameter_list|(
specifier|const
name|char
modifier|*
name|codecName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QTextCodec
operator|*
name|codec
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setAutoDetectUnicode
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|autoDetectUnicode
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setGenerateByteOrderMark
parameter_list|(
name|bool
name|generate
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|generateByteOrderMark
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|setLocale
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|locale
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QLocale
name|locale
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|setString
argument_list|(
name|QString
operator|*
name|string
argument_list|,
name|QIODevice
operator|::
name|OpenMode
name|openMode
operator|=
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QString
operator|*
name|string
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Status
name|status
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setStatus
parameter_list|(
name|Status
name|status
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resetStatus
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|atEnd
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|reset
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|flush
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|seek
parameter_list|(
name|qint64
name|pos
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|qint64
name|pos
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|skipWhiteSpace
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|readLine
parameter_list|(
name|qint64
name|maxlen
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|readAll
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|read
parameter_list|(
name|qint64
name|maxlen
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setFieldAlignment
parameter_list|(
name|FieldAlignment
name|alignment
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|FieldAlignment
name|fieldAlignment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPadChar
parameter_list|(
name|QChar
name|ch
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QChar
name|padChar
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFieldWidth
parameter_list|(
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|fieldWidth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setNumberFlags
parameter_list|(
name|NumberFlags
name|flags
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|NumberFlags
name|numberFlags
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setIntegerBase
parameter_list|(
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|integerBase
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setRealNumberNotation
parameter_list|(
name|RealNumberNotation
name|notation
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|RealNumberNotation
name|realNumberNotation
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setRealNumberPrecision
parameter_list|(
name|int
name|precision
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|realNumberPrecision
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|QChar
operator|&
name|ch
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|char
operator|&
name|ch
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|signed
name|short
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|unsigned
name|short
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|signed
name|int
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|unsigned
name|int
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|signed
name|long
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|unsigned
name|long
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|qlonglong
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|qulonglong
operator|&
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|float
operator|&
name|f
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|double
operator|&
name|f
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|QString
operator|&
name|s
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|QByteArray
operator|&
name|array
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|char
operator|*
name|c
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|QBool
name|b
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|QChar
name|ch
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|char
name|ch
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|signed
name|short
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|short
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|signed
name|int
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|int
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|signed
name|long
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|long
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|qlonglong
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|qulonglong
name|i
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|float
name|f
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|double
name|f
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QString
operator|&
name|s
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QByteArray
operator|&
name|array
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|c
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|void
operator|*
name|ptr
operator|)
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QTextStream
argument_list|)
end_macro
begin_expr_stmt
name|QScopedPointer
operator|<
name|QTextStreamPrivate
operator|>
name|d_ptr
expr_stmt|;
end_expr_stmt
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QTextStream::NumberFlags
argument_list|)
end_macro
begin_comment
comment|/*****************************************************************************   QTextStream manipulators  *****************************************************************************/
end_comment
begin_typedef
DECL|typedef|QTextStreamFunction
typedef|typedef
name|QTextStream
modifier|&
function_decl|(
modifier|*
name|QTextStreamFunction
function_decl|)
parameter_list|(
name|QTextStream
modifier|&
parameter_list|)
function_decl|;
end_typedef
begin_comment
DECL|typedef|QTextStreamFunction
comment|// manipulator function
end_comment
begin_typedef
DECL|typedef|QTSMFI
typedef|typedef
name|void
argument_list|(
name|QTextStream
operator|::
operator|*
name|QTSMFI
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_typedef
begin_comment
DECL|typedef|QTSMFI
comment|// manipulator w/int argument
end_comment
begin_typedef
DECL|typedef|QTSMFC
typedef|typedef
name|void
argument_list|(
name|QTextStream
operator|::
operator|*
name|QTSMFC
argument_list|)
argument_list|(
name|QChar
argument_list|)
expr_stmt|;
end_typedef
begin_comment
DECL|typedef|QTSMFC
comment|// manipulator w/QChar argument
end_comment
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTextStreamManipulator
block|{
name|public
label|:
name|QTextStreamManipulator
argument_list|(
argument|QTSMFI m
argument_list|,
argument|int a
argument_list|)
block|{
name|mf
operator|=
name|m
expr_stmt|;
name|mc
operator|=
literal|0
expr_stmt|;
name|arg
operator|=
name|a
expr_stmt|;
block|}
name|QTextStreamManipulator
argument_list|(
argument|QTSMFC m
argument_list|,
argument|QChar c
argument_list|)
block|{
name|mf
operator|=
literal|0
expr_stmt|;
name|mc
operator|=
name|m
expr_stmt|;
name|ch
operator|=
name|c
expr_stmt|;
name|arg
operator|=
operator|-
literal|1
expr_stmt|;
block|}
name|void
name|exec
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
block|{
if|if
condition|(
name|mf
condition|)
block|{
operator|(
name|s
operator|.*
name|mf
operator|)
operator|(
name|arg
operator|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|s
operator|.*
name|mc
operator|)
operator|(
name|ch
operator|)
expr_stmt|;
block|}
block|}
name|private
label|:
name|QTSMFI
name|mf
decl_stmt|;
comment|// QTextStream member function
name|QTSMFC
name|mc
decl_stmt|;
comment|// QTextStream member function
name|int
name|arg
decl_stmt|;
comment|// member function argument
name|QChar
name|ch
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QTextStream
operator|&
name|operator
operator|>>
operator|(
name|QTextStream
operator|&
name|s
operator|,
name|QTextStreamFunction
name|f
operator|)
block|{
return|return
call|(
modifier|*
name|f
call|)
argument_list|(
name|s
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|QTextStream
operator|&
name|s
operator|,
name|QTextStreamFunction
name|f
operator|)
block|{
return|return
call|(
modifier|*
name|f
call|)
argument_list|(
name|s
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QTextStream
operator|&
name|operator
operator|<<
operator|(
name|QTextStream
operator|&
name|s
operator|,
name|QTextStreamManipulator
name|m
operator|)
block|{
name|m
operator|.
name|exec
argument_list|(
name|s
argument_list|)
block|;
return|return
name|s
return|;
block|}
end_expr_stmt
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|bin
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|oct
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|dec
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|hex
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|showbase
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|forcesign
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|forcepoint
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|noshowbase
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|noforcesign
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|noforcepoint
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|uppercasebase
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|uppercasedigits
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|lowercasebase
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|lowercasedigits
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|fixed
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|scientific
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|left
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|right
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|center
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|endl
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|flush
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|reset
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|bom
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QTextStream
modifier|&
name|ws
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|qSetFieldWidth
specifier|inline
name|QTextStreamManipulator
name|qSetFieldWidth
parameter_list|(
name|int
name|width
parameter_list|)
block|{
name|QTSMFI
name|func
init|=
operator|&
name|QTextStream
operator|::
name|setFieldWidth
decl_stmt|;
return|return
name|QTextStreamManipulator
argument_list|(
name|func
argument_list|,
name|width
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSetPadChar
specifier|inline
name|QTextStreamManipulator
name|qSetPadChar
parameter_list|(
name|QChar
name|ch
parameter_list|)
block|{
name|QTSMFC
name|func
init|=
operator|&
name|QTextStream
operator|::
name|setPadChar
decl_stmt|;
return|return
name|QTextStreamManipulator
argument_list|(
name|func
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSetRealNumberPrecision
specifier|inline
name|QTextStreamManipulator
name|qSetRealNumberPrecision
parameter_list|(
name|int
name|precision
parameter_list|)
block|{
name|QTSMFI
name|func
init|=
operator|&
name|QTextStream
operator|::
name|setRealNumberPrecision
decl_stmt|;
return|return
name|QTextStreamManipulator
argument_list|(
name|func
argument_list|,
name|precision
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTSTREAM_H
end_comment
end_unit
