begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbuffer.h"
end_include
begin_include
include|#
directive|include
file|"private/qiodevice_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/** QBufferPrivate **/
end_comment
begin_class
DECL|class|QBufferPrivate
class|class
name|QBufferPrivate
super|:
specifier|public
name|QIODevicePrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QBuffer
parameter_list|)
specifier|public
private|:
DECL|function|QBufferPrivate
name|QBufferPrivate
parameter_list|()
member_init_list|:
name|buf
argument_list|(
literal|0
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
member_init_list|,
name|writtenSinceLastEmit
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|signalConnectionCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|signalsEmitted
argument_list|(
literal|false
argument_list|)
endif|#
directive|endif
block|{ }
DECL|function|~QBufferPrivate
name|~
name|QBufferPrivate
parameter_list|()
block|{ }
DECL|member|buf
name|QByteArray
modifier|*
name|buf
decl_stmt|;
DECL|member|defaultBuf
name|QByteArray
name|defaultBuf
decl_stmt|;
DECL|member|ioIndex
name|int
name|ioIndex
decl_stmt|;
specifier|virtual
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
specifier|virtual
name|QByteArray
name|peek
parameter_list|(
name|qint64
name|maxSize
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
comment|// private slots
name|void
name|_q_emitSignals
parameter_list|()
function_decl|;
DECL|member|writtenSinceLastEmit
name|qint64
name|writtenSinceLastEmit
decl_stmt|;
DECL|member|signalConnectionCount
name|int
name|signalConnectionCount
decl_stmt|;
DECL|member|signalsEmitted
name|bool
name|signalsEmitted
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_function
DECL|function|_q_emitSignals
name|void
name|QBufferPrivate
operator|::
name|_q_emitSignals
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|bytesWritten
argument_list|(
name|writtenSinceLastEmit
argument_list|)
emit|;
name|writtenSinceLastEmit
operator|=
literal|0
expr_stmt|;
emit|emit
name|q
operator|->
name|readyRead
argument_list|()
emit|;
name|signalsEmitted
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|peek
name|qint64
name|QBufferPrivate
operator|::
name|peek
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
block|{
name|qint64
name|readBytes
init|=
name|qMin
argument_list|(
name|maxSize
argument_list|,
cast|static_cast
argument_list|<
name|qint64
argument_list|>
argument_list|(
name|buf
operator|->
name|size
argument_list|()
argument_list|)
operator|-
name|pos
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|data
argument_list|,
name|buf
operator|->
name|constData
argument_list|()
operator|+
name|pos
argument_list|,
name|readBytes
argument_list|)
expr_stmt|;
return|return
name|readBytes
return|;
block|}
end_function
begin_function
DECL|function|peek
name|QByteArray
name|QBufferPrivate
operator|::
name|peek
parameter_list|(
name|qint64
name|maxSize
parameter_list|)
block|{
name|qint64
name|readBytes
init|=
name|qMin
argument_list|(
name|maxSize
argument_list|,
cast|static_cast
argument_list|<
name|qint64
argument_list|>
argument_list|(
name|buf
operator|->
name|size
argument_list|()
argument_list|)
operator|-
name|pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|==
literal|0
operator|&&
name|maxSize
operator|>=
name|buf
operator|->
name|size
argument_list|()
condition|)
return|return
operator|*
name|buf
return|;
return|return
name|QByteArray
argument_list|(
name|buf
operator|->
name|constData
argument_list|()
operator|+
name|pos
argument_list|,
name|readBytes
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QBuffer     \reentrant     \brief The QBuffer class provides a QIODevice interface for a QByteArray.      \ingroup io      QBuffer allows you to access a QByteArray using the QIODevice     interface. The QByteArray is treated just as a standard random-accessed     file. Example:      \snippet doc/src/snippets/buffer/buffer.cpp 0      By default, an internal QByteArray buffer is created for you when     you create a QBuffer. You can access this buffer directly by     calling buffer(). You can also use QBuffer with an existing     QByteArray by calling setBuffer(), or by passing your array to     QBuffer's constructor.      Call open() to open the buffer. Then call write() or     putChar() to write to the buffer, and read(), readLine(),     readAll(), or getChar() to read from it. size() returns the     current size of the buffer, and you can seek to arbitrary     positions in the buffer by calling seek(). When you are done with     accessing the buffer, call close().      The following code snippet shows how to write data to a     QByteArray using QDataStream and QBuffer:      \snippet doc/src/snippets/buffer/buffer.cpp 1      Effectively, we convert the application's QPalette into a byte     array. Here's how to read the data from the QByteArray:      \snippet doc/src/snippets/buffer/buffer.cpp 2      QTextStream and QDataStream also provide convenience constructors     that take a QByteArray and that create a QBuffer behind the     scenes.      QBuffer emits readyRead() when new data has arrived in the     buffer. By connecting to this signal, you can use QBuffer to     store temporary data before processing it. For example, you can     pass the buffer to QFtp when downloading a file from an FTP     server. Whenever a new payload of data has been downloaded,     readyRead() is emitted, and you can process the data that just     arrived. QBuffer also emits bytesWritten() every time new data     has been written to the buffer.      \sa QFile, QDataStream, QTextStream, QByteArray */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_QOBJECT
end_ifdef
begin_constructor
DECL|function|QBuffer
name|QBuffer
operator|::
name|QBuffer
parameter_list|()
member_init_list|:
name|QIODevice
argument_list|(
operator|*
operator|new
name|QBufferPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|buf
operator|=
operator|&
name|d
operator|->
name|defaultBuf
expr_stmt|;
name|d
operator|->
name|ioIndex
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QBuffer
name|QBuffer
operator|::
name|QBuffer
parameter_list|(
name|QByteArray
modifier|*
name|buf
parameter_list|)
member_init_list|:
name|QIODevice
argument_list|(
operator|*
operator|new
name|QBufferPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|buf
operator|=
name|buf
condition|?
name|buf
else|:
operator|&
name|d
operator|->
name|defaultBuf
expr_stmt|;
name|d
operator|->
name|ioIndex
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|defaultBuf
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_else
else|#
directive|else
end_else
begin_comment
comment|/*!     Constructs an empty buffer with the given \a parent. You can call     setData() to fill the buffer with data, or you can open it in     write mode and use write().      \sa open() */
end_comment
begin_constructor
DECL|function|QBuffer
name|QBuffer
operator|::
name|QBuffer
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QIODevice
argument_list|(
operator|*
operator|new
name|QBufferPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|buf
operator|=
operator|&
name|d
operator|->
name|defaultBuf
expr_stmt|;
name|d
operator|->
name|ioIndex
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QBuffer that uses the QByteArray pointed to by \a     byteArray as its internal buffer, and with the given \a parent.     The caller is responsible for ensuring that \a byteArray remains     valid until the QBuffer is destroyed, or until setBuffer() is     called to change the buffer. QBuffer doesn't take ownership of     the QByteArray.      If you open the buffer in write-only mode or read-write mode and     write something into the QBuffer, \a byteArray will be modified.      Example:      \snippet doc/src/snippets/buffer/buffer.cpp 3      \sa open(), setBuffer(), setData() */
end_comment
begin_constructor
DECL|function|QBuffer
name|QBuffer
operator|::
name|QBuffer
parameter_list|(
name|QByteArray
modifier|*
name|byteArray
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QIODevice
argument_list|(
operator|*
operator|new
name|QBufferPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|buf
operator|=
name|byteArray
condition|?
name|byteArray
else|:
operator|&
name|d
operator|->
name|defaultBuf
expr_stmt|;
name|d
operator|->
name|defaultBuf
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|ioIndex
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Destroys the buffer. */
end_comment
begin_destructor
DECL|function|~QBuffer
name|QBuffer
operator|::
name|~
name|QBuffer
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Makes QBuffer uses the QByteArray pointed to by \a     byteArray as its internal buffer. The caller is responsible for     ensuring that \a byteArray remains valid until the QBuffer is     destroyed, or until setBuffer() is called to change the buffer.     QBuffer doesn't take ownership of the QByteArray.      Does nothing if isOpen() is true.      If you open the buffer in write-only mode or read-write mode and     write something into the QBuffer, \a byteArray will be modified.      Example:      \snippet doc/src/snippets/buffer/buffer.cpp 4      If \a byteArray is 0, the buffer creates its own internal     QByteArray to work on. This byte array is initially empty.      \sa buffer(), setData(), open() */
end_comment
begin_function
DECL|function|setBuffer
name|void
name|QBuffer
operator|::
name|setBuffer
parameter_list|(
name|QByteArray
modifier|*
name|byteArray
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|isOpen
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QBuffer::setBuffer: Buffer is open"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|byteArray
condition|)
block|{
name|d
operator|->
name|buf
operator|=
name|byteArray
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|buf
operator|=
operator|&
name|d
operator|->
name|defaultBuf
expr_stmt|;
block|}
name|d
operator|->
name|defaultBuf
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|ioIndex
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns a reference to the QBuffer's internal buffer. You can use     it to modify the QByteArray behind the QBuffer's back.      \sa setBuffer(), data() */
end_comment
begin_function
DECL|function|buffer
name|QByteArray
modifier|&
name|QBuffer
operator|::
name|buffer
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
return|return
operator|*
name|d
operator|->
name|buf
return|;
block|}
end_function
begin_comment
comment|/*!     \overload      This is the same as data(). */
end_comment
begin_function
DECL|function|buffer
specifier|const
name|QByteArray
modifier|&
name|QBuffer
operator|::
name|buffer
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBuffer
argument_list|)
expr_stmt|;
return|return
operator|*
name|d
operator|->
name|buf
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the data contained in the buffer.      This is the same as buffer().      \sa setData(), setBuffer() */
end_comment
begin_function
DECL|function|data
specifier|const
name|QByteArray
modifier|&
name|QBuffer
operator|::
name|data
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBuffer
argument_list|)
expr_stmt|;
return|return
operator|*
name|d
operator|->
name|buf
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the contents of the internal buffer to be \a data. This is     the same as assigning \a data to buffer().      Does nothing if isOpen() is true.      \sa setBuffer() */
end_comment
begin_function
DECL|function|setData
name|void
name|QBuffer
operator|::
name|setData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|isOpen
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QBuffer::setData: Buffer is open"
argument_list|)
expr_stmt|;
return|return;
block|}
operator|*
name|d
operator|->
name|buf
operator|=
name|data
expr_stmt|;
name|d
operator|->
name|ioIndex
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QBuffer::setData(const char *data, int size)      \overload      Sets the contents of the internal buffer to be the first \a size     bytes of \a data. */
end_comment
begin_comment
comment|/*!    \reimp */
end_comment
begin_function
DECL|function|open
name|bool
name|QBuffer
operator|::
name|open
parameter_list|(
name|OpenMode
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Append
operator|)
operator|==
name|Append
condition|)
name|flags
operator||=
name|WriteOnly
expr_stmt|;
name|setOpenMode
argument_list|(
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|isReadable
argument_list|()
operator|||
name|isWritable
argument_list|()
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFile::open: File access not specified"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|(
name|flags
operator|&
name|QIODevice
operator|::
name|Truncate
operator|)
operator|==
name|QIODevice
operator|::
name|Truncate
condition|)
block|{
name|d
operator|->
name|buf
operator|->
name|resize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|flags
operator|&
name|QIODevice
operator|::
name|Append
operator|)
operator|==
name|QIODevice
operator|::
name|Append
condition|)
comment|// append to end of buffer
name|seek
argument_list|(
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|close
name|void
name|QBuffer
operator|::
name|close
parameter_list|()
block|{
name|QIODevice
operator|::
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|pos
name|qint64
name|QBuffer
operator|::
name|pos
parameter_list|()
specifier|const
block|{
return|return
name|QIODevice
operator|::
name|pos
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|size
name|qint64
name|QBuffer
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBuffer
argument_list|)
expr_stmt|;
return|return
name|qint64
argument_list|(
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|seek
name|bool
name|QBuffer
operator|::
name|seek
parameter_list|(
name|qint64
name|pos
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|>
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
operator|&&
name|isWritable
argument_list|()
condition|)
block|{
if|if
condition|(
name|seek
argument_list|(
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
argument_list|)
condition|)
block|{
specifier|const
name|qint64
name|gapSize
init|=
name|pos
operator|-
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|write
argument_list|(
name|QByteArray
argument_list|(
name|gapSize
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|!=
name|gapSize
condition|)
block|{
name|qWarning
argument_list|(
literal|"QBuffer::seek: Unable to fill gap"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
else|else
block|{
return|return
literal|false
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|pos
operator|>
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
operator|||
name|pos
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QBuffer::seek: Invalid pos: %d"
argument_list|,
name|int
argument_list|(
name|pos
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|d
operator|->
name|ioIndex
operator|=
name|int
argument_list|(
name|pos
argument_list|)
expr_stmt|;
return|return
name|QIODevice
operator|::
name|seek
argument_list|(
name|pos
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|atEnd
name|bool
name|QBuffer
operator|::
name|atEnd
parameter_list|()
specifier|const
block|{
return|return
name|QIODevice
operator|::
name|atEnd
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!    \reimp */
end_comment
begin_function
DECL|function|canReadLine
name|bool
name|QBuffer
operator|::
name|canReadLine
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isOpen
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|buf
operator|->
name|indexOf
argument_list|(
literal|'\n'
argument_list|,
name|int
argument_list|(
name|pos
argument_list|()
argument_list|)
argument_list|)
operator|!=
operator|-
literal|1
operator|||
name|QIODevice
operator|::
name|canReadLine
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|readData
name|qint64
name|QBuffer
operator|::
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|len
operator|=
name|qMin
argument_list|(
name|len
argument_list|,
name|qint64
argument_list|(
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
argument_list|)
operator|-
name|d
operator|->
name|ioIndex
argument_list|)
operator|)
operator|<=
literal|0
condition|)
return|return
name|qint64
argument_list|(
literal|0
argument_list|)
return|;
name|memcpy
argument_list|(
name|data
argument_list|,
name|d
operator|->
name|buf
operator|->
name|constData
argument_list|()
operator|+
name|d
operator|->
name|ioIndex
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|d
operator|->
name|ioIndex
operator|+=
name|int
argument_list|(
name|len
argument_list|)
expr_stmt|;
return|return
name|len
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|writeData
name|qint64
name|QBuffer
operator|::
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBuffer
argument_list|)
expr_stmt|;
name|int
name|extraBytes
init|=
name|d
operator|->
name|ioIndex
operator|+
name|len
operator|-
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|extraBytes
operator|>
literal|0
condition|)
block|{
comment|// overflow
name|int
name|newSize
init|=
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
operator|+
name|extraBytes
decl_stmt|;
name|d
operator|->
name|buf
operator|->
name|resize
argument_list|(
name|newSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|buf
operator|->
name|size
argument_list|()
operator|!=
name|newSize
condition|)
block|{
comment|// could not resize
name|qWarning
argument_list|(
literal|"QBuffer::writeData: Memory allocation error"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
name|memcpy
argument_list|(
name|d
operator|->
name|buf
operator|->
name|data
argument_list|()
operator|+
name|d
operator|->
name|ioIndex
argument_list|,
operator|(
name|uchar
operator|*
operator|)
name|data
argument_list|,
name|int
argument_list|(
name|len
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|ioIndex
operator|+=
name|int
argument_list|(
name|len
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|d
operator|->
name|writtenSinceLastEmit
operator|+=
name|len
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|signalConnectionCount
operator|&&
operator|!
name|d
operator|->
name|signalsEmitted
operator|&&
operator|!
name|signalsBlocked
argument_list|()
condition|)
block|{
name|d
operator|->
name|signalsEmitted
operator|=
literal|true
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"_q_emitSignals"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|len
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_comment
comment|/*!     \reimp     \internal */
end_comment
begin_function
DECL|function|connectNotify
name|void
name|QBuffer
operator|::
name|connectNotify
parameter_list|(
specifier|const
name|char
modifier|*
name|signal
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|signal
operator|+
literal|1
argument_list|,
literal|"readyRead()"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|signal
operator|+
literal|1
argument_list|,
literal|"bytesWritten(qint64)"
argument_list|)
operator|==
literal|0
condition|)
name|d_func
argument_list|()
operator|->
name|signalConnectionCount
operator|++
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp     \internal */
end_comment
begin_function
DECL|function|disconnectNotify
name|void
name|QBuffer
operator|::
name|disconnectNotify
parameter_list|(
specifier|const
name|char
modifier|*
name|signal
parameter_list|)
block|{
if|if
condition|(
operator|!
name|signal
operator|||
name|strcmp
argument_list|(
name|signal
operator|+
literal|1
argument_list|,
literal|"readyRead()"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|signal
operator|+
literal|1
argument_list|,
literal|"bytesWritten(qint64)"
argument_list|)
operator|==
literal|0
condition|)
name|d_func
argument_list|()
operator|->
name|signalConnectionCount
operator|--
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_include
include|#
directive|include
file|"moc_qbuffer.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
end_unit
