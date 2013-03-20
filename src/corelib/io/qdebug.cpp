begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_DEBUG
end_ifdef
begin_undef
DECL|macro|QT_NO_DEBUG
undef|#
directive|undef
name|QT_NO_DEBUG
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|qDebug
end_ifdef
begin_undef
DECL|macro|qDebug
undef|#
directive|undef
name|qDebug
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|<private/qtextstream_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// This file is needed to force compilation of QDebug into the kernel library.
end_comment
begin_comment
comment|/*!     \class QDebug     \inmodule QtCore     \ingroup shared      \brief The QDebug class provides an output stream for debugging information.      QDebug is used whenever the developer needs to write out debugging or tracing     information to a device, file, string or console.      \section1 Basic Use      In the common case, it is useful to call the qDebug() function to obtain a     default QDebug object to use for writing debugging information.      \snippet qdebug/qdebugsnippet.cpp 1      This constructs a QDebug object using the constructor that accepts a QtMsgType     value of QtDebugMsg. Similarly, the qWarning(), qCritical() and qFatal()     functions also return QDebug objects for the corresponding message types.      The class also provides several constructors for other situations, including     a constructor that accepts a QFile or any other QIODevice subclass that is     used to write debugging information to files and other devices. The constructor     that accepts a QString is used to write to a string for display or serialization.      \section1 Writing Custom Types to a Stream      Many standard types can be written to QDebug objects, and Qt provides support for     most Qt value types. To add support for custom types, you need to implement a     streaming operator, as in the following example:      \snippet qdebug/qdebugsnippet.cpp 0      This is described in the \l{Debugging Techniques} and     \l{Creating Custom Qt Types#Making the Type Printable}{Creating Custom Qt Types}     documents. */
end_comment
begin_comment
comment|/*!     \fn QDebug::QDebug(QIODevice *device)      Constructs a debug stream that writes to the given \a device. */
end_comment
begin_comment
comment|/*!     \fn QDebug::QDebug(QString *string)      Constructs a debug stream that writes to the given \a string. */
end_comment
begin_comment
comment|/*!     \fn QDebug::QDebug(QtMsgType type)      Constructs a debug stream that writes to the handler for the message type specified by \a type. */
end_comment
begin_comment
comment|/*!     \fn QDebug::QDebug(const QDebug&other)      Constructs a copy of the \a other debug stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator=(const QDebug&other)      Assigns the \a other debug stream to this stream and returns a reference to     this stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug::~QDebug()      Flushes any pending data to be written and destroys the debug stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug::swap(QDebug&other)     \since 5.0      Swaps this debug stream instance with \a other. This function is     very fast and never fails. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::space()      Writes a space character to the debug stream and returns a reference to     the stream.      The stream remembers that automatic insertion of spaces is     enabled for future writes.      \sa nospace(), maybeSpace() */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::nospace()      Disables automatic insertion of spaces and returns a reference to the stream.      \sa space(), maybeSpace() */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::maybeSpace()      Writes a space character to the debug stream, depending on the current     setting for automatic insertion of spaces, and returns a reference to the stream.      \sa space(), nospace() */
end_comment
begin_comment
comment|/*!     \fn bool QDebug::autoInsertSpaces() const      Returns true if this QDebug instance will automatically insert spaces     between writes.      \since 5.0      \sa QDebugStateSaver */
end_comment
begin_comment
comment|/*!     \fn void QDebug::setAutoInsertSpaces(bool b)      Enables automatic insertion of spaces between writes if \a b is true; otherwise     automatic insertion of spaces is disabled.      \since 5.0      \sa QDebugStateSaver */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(QChar t)      Writes the character, \a t, to the stream and returns a reference to the     stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(bool t)      Writes the boolean value, \a t, to the stream and returns a reference to the     stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(char t)      Writes the character, \a t, to the stream and returns a reference to the     stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(signed short i)      Writes the signed short integer, \a i, to the stream and returns a reference     to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(unsigned short i)      Writes then unsigned short integer, \a i, to the stream and returns a     reference to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(signed int i)      Writes the signed integer, \a i, to the stream and returns a reference     to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(unsigned int i)      Writes then unsigned integer, \a i, to the stream and returns a reference to     the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(signed long l)      Writes the signed long integer, \a l, to the stream and returns a reference     to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(unsigned long l)      Writes then unsigned long integer, \a l, to the stream and returns a reference     to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(qint64 i)      Writes the signed 64-bit integer, \a i, to the stream and returns a reference     to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(quint64 i)      Writes then unsigned 64-bit integer, \a i, to the stream and returns a     reference to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(float f)      Writes the 32-bit floating point number, \a f, to the stream and returns a     reference to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(double f)      Writes the 64-bit floating point number, \a f, to the stream and returns a     reference to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(const char *s)      Writes the '\\0'-terminated string, \a s, to the stream and returns a     reference to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(const QString&s)      Writes the string, \a s, to the stream and returns a reference to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(const QStringRef&s)      Writes the string reference, \a s, to the stream and returns a reference to     the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(QLatin1String s)      Writes the Latin1-encoded string, \a s, to the stream and returns a reference     to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(const QByteArray&b)      Writes the byte array, \a b, to the stream and returns a reference to the     stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(const void *p)      Writes a pointer, \a p, to the stream and returns a reference to the stream. */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(QTextStreamFunction f)     \internal */
end_comment
begin_comment
comment|/*!     \fn QDebug&QDebug::operator<<(QTextStreamManipulator m)     \internal */
end_comment
begin_comment
comment|/*!     \class QDebugStateSaver      \brief Convenience class for custom QDebug operators      Saves the settings used by QDebug, and restores them upon destruction.      The automatic insertion of spaces between writes is one of the settings     that QDebugStateSaver stores for the duration of the current block.      The settings of the internal QTextStream are also saved and restored,     so that using<< hex in a QDebug operator doesn't affect other QDebug     operators.      \since 5.1 */
end_comment
begin_class
DECL|class|QDebugStateSaverPrivate
class|class
name|QDebugStateSaverPrivate
block|{
public|public:
DECL|function|QDebugStateSaverPrivate
name|QDebugStateSaverPrivate
parameter_list|(
name|QDebug
modifier|&
name|dbg
parameter_list|)
member_init_list|:
name|m_dbg
argument_list|(
name|dbg
argument_list|)
member_init_list|,
name|m_spaces
argument_list|(
name|dbg
operator|.
name|autoInsertSpaces
argument_list|()
argument_list|)
member_init_list|,
name|m_streamParams
argument_list|(
name|dbg
operator|.
name|stream
operator|->
name|ts
operator|.
name|d_ptr
operator|->
name|params
argument_list|)
block|{     }
DECL|function|restoreState
name|void
name|restoreState
parameter_list|()
block|{
name|m_dbg
operator|.
name|setAutoInsertSpaces
argument_list|(
name|m_spaces
argument_list|)
expr_stmt|;
name|m_dbg
operator|.
name|stream
operator|->
name|ts
operator|.
name|d_ptr
operator|->
name|params
operator|=
name|m_streamParams
expr_stmt|;
block|}
DECL|member|m_dbg
name|QDebug
modifier|&
name|m_dbg
decl_stmt|;
comment|// QDebug state
DECL|member|m_spaces
specifier|const
name|bool
name|m_spaces
decl_stmt|;
comment|// QTextStream state
DECL|member|m_streamParams
specifier|const
name|QTextStreamPrivate
operator|::
name|Params
name|m_streamParams
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Creates a QDebugStateSaver instance, which saves the settings     currently used by \a dbg.      \sa QDebug::setAutoInsertSpaces(), QDebug::autoInsertSpaces() */
end_comment
begin_constructor
DECL|function|QDebugStateSaver
name|QDebugStateSaver
operator|::
name|QDebugStateSaver
parameter_list|(
name|QDebug
modifier|&
name|dbg
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QDebugStateSaverPrivate
argument_list|(
name|dbg
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroyes a QDebugStateSaver instance, which restores the settings     used by \a dbg when the QDebugStateSaver instance was created.      \sa QDebug::setAutoInsertSpaces(), QDebug::autoInsertSpaces() */
end_comment
begin_destructor
DECL|function|~QDebugStateSaver
name|QDebugStateSaver
operator|::
name|~
name|QDebugStateSaver
parameter_list|()
block|{
name|d
operator|->
name|restoreState
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
