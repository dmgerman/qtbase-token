begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIODEVICE_P_H
end_ifndef
begin_define
DECL|macro|QIODEVICE_P_H
define|#
directive|define
name|QIODEVICE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of QIODevice. This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qiodevice.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbytearray.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qobjectdefs.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"private/qringbuffer_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QIODEVICE_BUFFERSIZE
DECL|macro|QIODEVICE_BUFFERSIZE
define|#
directive|define
name|QIODEVICE_BUFFERSIZE
value|Q_INT64_C(16384)
endif|#
directive|endif
comment|// This is QIODevice's read buffer, optimized for read(), isEmpty() and getChar()
name|class
name|QIODevicePrivateLinearBuffer
block|{
name|public
label|:
name|QIODevicePrivateLinearBuffer
argument_list|(
name|int
argument_list|)
operator|:
name|len
argument_list|(
literal|0
argument_list|)
operator|,
name|first
argument_list|(
literal|0
argument_list|)
operator|,
name|buf
argument_list|(
literal|0
argument_list|)
operator|,
name|capacity
argument_list|(
literal|0
argument_list|)
block|{     }
operator|~
name|QIODevicePrivateLinearBuffer
argument_list|()
block|{
name|delete
index|[]
name|buf
block|;     }
name|void
name|clear
argument_list|()
block|{
name|len
operator|=
literal|0
block|;
name|delete
index|[]
name|buf
block|;
name|buf
operator|=
literal|0
block|;
name|first
operator|=
name|buf
block|;
name|capacity
operator|=
literal|0
block|;     }
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|len
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|len
operator|==
literal|0
return|;
block|}
name|void
name|skip
parameter_list|(
name|int
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|>=
name|len
condition|)
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|len
operator|-=
name|n
expr_stmt|;
name|first
operator|+=
name|n
expr_stmt|;
block|}
block|}
name|int
name|getChar
parameter_list|()
block|{
if|if
condition|(
name|len
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|int
name|ch
init|=
name|uchar
argument_list|(
operator|*
name|first
argument_list|)
decl_stmt|;
name|len
operator|--
expr_stmt|;
name|first
operator|++
expr_stmt|;
return|return
name|ch
return|;
block|}
name|int
name|read
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|int
name|r
init|=
name|qMin
argument_list|(
name|size
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|target
argument_list|,
name|first
argument_list|,
name|r
argument_list|)
expr_stmt|;
name|len
operator|-=
name|r
expr_stmt|;
name|first
operator|+=
name|r
expr_stmt|;
return|return
name|r
return|;
block|}
name|int
name|peek
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|int
name|r
init|=
name|qMin
argument_list|(
name|size
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|target
argument_list|,
name|first
argument_list|,
name|r
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
name|char
modifier|*
name|reserve
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|makeSpace
argument_list|(
name|size
operator|+
name|len
argument_list|,
name|freeSpaceAtEnd
argument_list|)
expr_stmt|;
name|char
modifier|*
name|writePtr
init|=
name|first
operator|+
name|len
decl_stmt|;
name|len
operator|+=
name|size
expr_stmt|;
return|return
name|writePtr
return|;
block|}
name|void
name|chop
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|>=
name|len
condition|)
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|len
operator|-=
name|size
expr_stmt|;
block|}
block|}
name|QByteArray
name|readAll
parameter_list|()
block|{
name|QByteArray
name|retVal
argument_list|(
name|first
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|clear
argument_list|()
expr_stmt|;
return|return
name|retVal
return|;
block|}
name|int
name|readLine
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|int
name|r
init|=
name|qMin
argument_list|(
name|size
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|char
modifier|*
name|eol
init|=
name|static_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|memchr
argument_list|(
name|first
argument_list|,
literal|'\n'
argument_list|,
name|r
argument_list|)
operator|)
decl_stmt|;
if|if
condition|(
name|eol
condition|)
name|r
operator|=
literal|1
operator|+
operator|(
name|eol
operator|-
name|first
operator|)
expr_stmt|;
name|memcpy
argument_list|(
name|target
argument_list|,
name|first
argument_list|,
name|r
argument_list|)
expr_stmt|;
name|len
operator|-=
name|r
expr_stmt|;
name|first
operator|+=
name|r
expr_stmt|;
return|return
name|int
argument_list|(
name|r
argument_list|)
return|;
block|}
name|bool
name|canReadLine
argument_list|()
specifier|const
block|{
return|return
name|memchr
argument_list|(
name|first
argument_list|,
literal|'\n'
argument_list|,
name|len
argument_list|)
return|;
block|}
name|void
name|ungetChar
parameter_list|(
name|char
name|c
parameter_list|)
block|{
if|if
condition|(
name|first
operator|==
name|buf
condition|)
block|{
comment|// underflow, the existing valid data needs to move to the end of the (potentially bigger) buffer
name|makeSpace
argument_list|(
name|len
operator|+
literal|1
argument_list|,
name|freeSpaceAtStart
argument_list|)
expr_stmt|;
block|}
name|first
operator|--
expr_stmt|;
name|len
operator|++
expr_stmt|;
operator|*
name|first
operator|=
name|c
expr_stmt|;
block|}
name|void
name|ungetBlock
parameter_list|(
specifier|const
name|char
modifier|*
name|block
parameter_list|,
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
operator|(
name|first
operator|-
name|buf
operator|)
operator|<
name|size
condition|)
block|{
comment|// underflow, the existing valid data needs to move to the end of the (potentially bigger) buffer
name|makeSpace
argument_list|(
name|len
operator|+
name|size
argument_list|,
name|freeSpaceAtStart
argument_list|)
expr_stmt|;
block|}
name|first
operator|-=
name|size
expr_stmt|;
name|len
operator|+=
name|size
expr_stmt|;
name|memcpy
argument_list|(
name|first
argument_list|,
name|block
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
name|private
label|:
enum|enum
name|FreeSpacePos
block|{
name|freeSpaceAtStart
block|,
name|freeSpaceAtEnd
block|}
enum|;
name|void
name|makeSpace
parameter_list|(
name|size_t
name|required
parameter_list|,
name|FreeSpacePos
name|where
parameter_list|)
block|{
name|size_t
name|newCapacity
init|=
name|qMax
argument_list|(
name|capacity
argument_list|,
name|size_t
argument_list|(
name|QIODEVICE_BUFFERSIZE
argument_list|)
argument_list|)
decl_stmt|;
while|while
condition|(
name|newCapacity
operator|<
name|required
condition|)
name|newCapacity
operator|*=
literal|2
expr_stmt|;
specifier|const
name|size_t
name|moveOffset
init|=
operator|(
name|where
operator|==
name|freeSpaceAtEnd
operator|)
condition|?
literal|0
else|:
name|newCapacity
operator|-
name|size_t
argument_list|(
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
name|newCapacity
operator|>
name|capacity
condition|)
block|{
comment|// allocate more space
name|char
modifier|*
name|newBuf
init|=
name|new
name|char
index|[
name|newCapacity
index|]
decl_stmt|;
name|memmove
argument_list|(
name|newBuf
operator|+
name|moveOffset
argument_list|,
name|first
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|delete
index|[]
name|buf
decl_stmt|;
name|buf
operator|=
name|newBuf
expr_stmt|;
name|capacity
operator|=
name|newCapacity
expr_stmt|;
block|}
else|else
block|{
comment|// shift any existing data to make space
name|memmove
argument_list|(
name|buf
operator|+
name|moveOffset
argument_list|,
name|first
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
name|first
operator|=
name|buf
operator|+
name|moveOffset
expr_stmt|;
block|}
name|private
label|:
comment|// length of the unread data
name|int
name|len
decl_stmt|;
comment|// start of the unread data
name|char
modifier|*
name|first
decl_stmt|;
comment|// the allocated buffer
name|char
modifier|*
name|buf
decl_stmt|;
comment|// allocated buffer size
name|size_t
name|capacity
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QIODevicePrivate
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
range|:
name|public
name|QObjectPrivate
endif|#
directive|endif
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QIODevice
argument_list|)
name|public
operator|:
name|QIODevicePrivate
argument_list|()
block|;
name|virtual
operator|~
name|QIODevicePrivate
argument_list|()
block|;
name|QIODevice
operator|::
name|OpenMode
name|openMode
block|;
name|QString
name|errorString
block|;
name|QIODevicePrivateLinearBuffer
name|buffer
block|;
name|qint64
name|pos
block|;
name|qint64
name|devicePos
block|;
comment|// these three are for fast position updates during read, avoiding isSequential test
name|qint64
name|seqDumpPos
block|;
name|qint64
operator|*
name|pPos
block|;
name|qint64
operator|*
name|pDevicePos
block|;
name|bool
name|baseReadLineDataCalled
block|;
name|bool
name|firstRead
block|;
name|virtual
name|bool
name|putCharHelper
argument_list|(
argument|char c
argument_list|)
block|;      enum
name|AccessMode
block|{
name|Unset
block|,
name|Sequential
block|,
name|RandomAccess
block|}
block|;
name|mutable
name|AccessMode
name|accessMode
block|;
specifier|inline
name|bool
name|isSequential
argument_list|()
specifier|const
block|{
if|if
condition|(
name|accessMode
operator|==
name|Unset
condition|)
name|accessMode
operator|=
name|q_func
argument_list|()
operator|->
name|isSequential
argument_list|()
operator|?
name|Sequential
operator|:
name|RandomAccess
expr_stmt|;
return|return
name|accessMode
operator|==
name|Sequential
return|;
block|}
end_decl_stmt
begin_function_decl
name|virtual
name|qint64
name|peek
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|QByteArray
name|peek
parameter_list|(
name|qint64
name|maxSize
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_QOBJECT
end_ifdef
begin_decl_stmt
name|QIODevice
modifier|*
name|q_ptr
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIODEVICE_P_H
end_comment
end_unit
