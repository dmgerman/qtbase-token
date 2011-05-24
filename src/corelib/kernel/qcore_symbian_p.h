begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCORE_SYMBIAN_P_H
end_ifndef
begin_define
DECL|macro|QCORE_SYMBIAN_P_H
define|#
directive|define
name|QCORE_SYMBIAN_P_H
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
comment|// of other Qt classes.  This header file may change from version to
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
file|<e32std.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qrect.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<f32file.h>
end_include
begin_include
include|#
directive|include
file|<es_sock.h>
end_include
begin_define
DECL|macro|QT_LSTRING2
define|#
directive|define
name|QT_LSTRING2
parameter_list|(
name|x
parameter_list|)
value|L##x
end_define
begin_define
DECL|macro|QT_LSTRING
define|#
directive|define
name|QT_LSTRING
parameter_list|(
name|x
parameter_list|)
value|QT_LSTRING2(x)
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LIBINFIX
argument_list|)
end_if
begin_define
DECL|macro|QT_LIBINFIX_UNICODE
define|#
directive|define
name|QT_LIBINFIX_UNICODE
value|QT_LSTRING(QT_LIBINFIX)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_LIBINFIX_UNICODE
define|#
directive|define
name|QT_LIBINFIX_UNICODE
value|L""
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|Q_CORE_EXPORT
name|HBufC
modifier|*
name|qt_QString2HBufC
parameter_list|(
specifier|const
name|QString
modifier|&
name|aString
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QString
name|qt_TDesC2QString
parameter_list|(
specifier|const
name|TDesC
modifier|&
name|aDescriptor
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|qt_TDes2QString
specifier|inline
name|QString
name|qt_TDes2QString
parameter_list|(
specifier|const
name|TDes
modifier|&
name|aDescriptor
parameter_list|)
block|{
return|return
name|qt_TDesC2QString
argument_list|(
name|aDescriptor
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_TSize2QSize
specifier|static
specifier|inline
name|QSize
name|qt_TSize2QSize
parameter_list|(
specifier|const
name|TSize
modifier|&
name|ts
parameter_list|)
block|{
return|return
name|QSize
argument_list|(
name|ts
operator|.
name|iWidth
argument_list|,
name|ts
operator|.
name|iHeight
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_QSize2TSize
specifier|static
specifier|inline
name|TSize
name|qt_QSize2TSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|qs
parameter_list|)
block|{
return|return
name|TSize
argument_list|(
name|qs
operator|.
name|width
argument_list|()
argument_list|,
name|qs
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_TRect2QRect
specifier|static
specifier|inline
name|QRect
name|qt_TRect2QRect
parameter_list|(
specifier|const
name|TRect
modifier|&
name|tr
parameter_list|)
block|{
return|return
name|QRect
argument_list|(
name|tr
operator|.
name|iTl
operator|.
name|iX
argument_list|,
name|tr
operator|.
name|iTl
operator|.
name|iY
argument_list|,
name|tr
operator|.
name|Width
argument_list|()
argument_list|,
name|tr
operator|.
name|Height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_QRect2TRect
specifier|static
specifier|inline
name|TRect
name|qt_QRect2TRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|qr
parameter_list|)
block|{
return|return
name|TRect
argument_list|(
name|TPoint
argument_list|(
name|qr
operator|.
name|left
argument_list|()
argument_list|,
name|qr
operator|.
name|top
argument_list|()
argument_list|)
argument_list|,
name|TSize
argument_list|(
name|qr
operator|.
name|width
argument_list|()
argument_list|,
name|qr
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// Returned TPtrC is valid as long as the given parameter is valid and unmodified
end_comment
begin_function
DECL|function|qt_QString2TPtrC
specifier|static
specifier|inline
name|TPtrC
name|qt_QString2TPtrC
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
block|{
return|return
name|TPtrC16
argument_list|(
name|static_cast
operator|<
specifier|const
name|TUint16
operator|*
operator|>
operator|(
name|string
operator|.
name|utf16
argument_list|()
operator|)
argument_list|,
name|string
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \internal     This class is a wrapper around the Symbian HBufC descriptor class.     It makes sure that the heap allocated HBufC class is freed when it is     destroyed. */
end_comment
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QHBufC
block|{
name|public
label|:
name|QHBufC
argument_list|()
expr_stmt|;
name|QHBufC
argument_list|(
specifier|const
name|QHBufC
operator|&
name|src
argument_list|)
expr_stmt|;
name|QHBufC
argument_list|(
name|HBufC
operator|*
name|src
argument_list|)
expr_stmt|;
name|QHBufC
argument_list|(
specifier|const
name|QString
operator|&
name|src
argument_list|)
expr_stmt|;
operator|~
name|QHBufC
argument_list|()
expr_stmt|;
specifier|inline
name|operator
name|HBufC
modifier|*
parameter_list|()
block|{
return|return
name|m_hBufC
return|;
block|}
specifier|inline
name|operator
specifier|const
name|HBufC
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|m_hBufC
return|;
block|}
specifier|inline
name|HBufC
modifier|*
name|data
parameter_list|()
block|{
return|return
name|m_hBufC
return|;
block|}
specifier|inline
specifier|const
name|HBufC
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|m_hBufC
return|;
block|}
specifier|inline
name|HBufC
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
return|return
operator|*
name|m_hBufC
return|;
block|}
specifier|inline
specifier|const
name|HBufC
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|m_hBufC
return|;
block|}
specifier|inline
name|HBufC
operator|*
name|operator
operator|->
expr|(
block|)
block|{
return|return
name|m_hBufC
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|HBufC
operator|*
name|operator
operator|->
expr|(
end_expr_stmt
begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|m_hBufC
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QHBufC
operator|&
name|param
operator|)
specifier|const
block|{
return|return
name|data
argument_list|()
operator|==
name|param
operator|.
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QHBufC
operator|&
name|param
operator|)
specifier|const
block|{
return|return
name|data
argument_list|()
operator|!=
name|param
operator|.
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|HBufC
modifier|*
name|m_hBufC
decl_stmt|;
end_decl_stmt
begin_function
unit|};
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
name|TUid
name|uid
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|uid
operator|.
name|iUid
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// S60 version specific function ordinals that can be resolved
end_comment
begin_enum
DECL|enum|S60PluginFuncOrdinals
enum|enum
name|S60PluginFuncOrdinals
block|{
DECL|enumerator|S60Plugin_TimeFormatL
name|S60Plugin_TimeFormatL
init|=
literal|1
block|,
DECL|enumerator|S60Plugin_GetTimeFormatSpec
name|S60Plugin_GetTimeFormatSpec
init|=
literal|2
block|,
DECL|enumerator|S60Plugin_GetLongDateFormatSpec
name|S60Plugin_GetLongDateFormatSpec
init|=
literal|3
block|,
DECL|enumerator|S60Plugin_GetShortDateFormatSpec
name|S60Plugin_GetShortDateFormatSpec
init|=
literal|4
block|,
DECL|enumerator|S60Plugin_LocalizedDirectoryName
name|S60Plugin_LocalizedDirectoryName
init|=
literal|5
block|,
DECL|enumerator|S60Plugin_GetSystemDrive
name|S60Plugin_GetSystemDrive
init|=
literal|6
block|}
enum|;
end_enum
begin_function_decl
name|Q_CORE_EXPORT
name|TLibraryFunction
name|qt_resolveS60PluginFunc
parameter_list|(
name|int
name|ordinal
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|RFs
modifier|&
name|qt_s60GetRFs
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|RSocketServ
modifier|&
name|qt_symbianGetSocketServer
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// Defined in qlocale_symbian.cpp.
end_comment
begin_function_decl
name|Q_CORE_EXPORT
name|QByteArray
name|qt_symbianLocaleName
parameter_list|(
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|R
operator|>
expr|struct
DECL|struct|QScopedPointerRCloser
name|QScopedPointerRCloser
block|{
DECL|function|cleanup
specifier|static
specifier|inline
name|void
name|cleanup
argument_list|(
argument|R *rPointer
argument_list|)
block|{
comment|// Enforce a complete type.
comment|// If you get a compile error here, read the section on forward declared
comment|// classes in the QScopedPointer documentation.
typedef|typedef
name|char
name|IsIncompleteType
index|[
sizeof|sizeof
argument_list|(
name|R
argument_list|)
operator|?
literal|1
operator|:
operator|-
literal|1
index|]
typedef|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|IsIncompleteType
argument_list|)
block|;
if|if
condition|(
name|rPointer
condition|)
name|rPointer
operator|->
name|Close
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_comment
unit|};
comment|//Wrapper for RSocket so it can be used as a key in QHash or QMap
end_comment
begin_decl_stmt
name|class
name|QHashableSocket
range|:
name|public
name|RSocket
block|{
name|public
operator|:
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QHashableSocket
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|SubSessionHandle
argument_list|()
operator|==
name|other
operator|.
name|SubSessionHandle
argument_list|()
operator|&&
name|Session
argument_list|()
operator|.
name|Handle
argument_list|()
operator|==
name|other
operator|.
name|Session
argument_list|()
operator|.
name|Handle
argument_list|()
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QHashableSocket
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|Session
argument_list|()
operator|.
name|Handle
argument_list|()
operator|==
name|other
operator|.
name|Session
argument_list|()
operator|.
name|Handle
argument_list|()
condition|)
return|return
name|SubSessionHandle
argument_list|()
operator|<
name|other
operator|.
name|SubSessionHandle
argument_list|()
return|;
return|return
name|Session
argument_list|()
operator|.
name|Handle
argument_list|()
operator|<
name|other
operator|.
name|Session
argument_list|()
operator|.
name|Handle
argument_list|()
return|;
block|}
end_decl_stmt
begin_function_decl
unit|};
name|uint
name|qHash
parameter_list|(
specifier|const
name|RSubSessionBase
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*!   \internal   This class exists in QtCore for the benefit of QSocketNotifier, which uses integer   file descriptors in its public API.   So we need a way to map between int and RSocket.   Additionally, it is used to host the global RSocketServ session */
end_comment
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSymbianSocketManager
block|{
name|public
label|:
name|QSymbianSocketManager
argument_list|()
expr_stmt|;
operator|~
name|QSymbianSocketManager
argument_list|()
expr_stmt|;
comment|/*!       \internal       \return handle to the socket server     */
name|RSocketServ
modifier|&
name|getSocketServer
parameter_list|()
function_decl|;
comment|/*!       \internal       Adds a symbian socket to the global map       \param an open socket       \return pseudo file descriptor, -1 if out of resources     */
name|int
name|addSocket
parameter_list|(
specifier|const
name|RSocket
modifier|&
name|sock
parameter_list|)
function_decl|;
comment|/*!       \internal       Removes a symbian socket from the global map       \param an open socket       \return true if the socket was in the map     */
name|bool
name|removeSocket
parameter_list|(
specifier|const
name|RSocket
modifier|&
name|sock
parameter_list|)
function_decl|;
comment|/*!       \internal       Get pseudo file descriptor for a socket       \param an open socket       \return integer handle, or -1 if not in map     */
name|int
name|lookupSocket
argument_list|(
specifier|const
name|RSocket
operator|&
name|sock
argument_list|)
decl|const
decl_stmt|;
comment|/*!       \internal       Get socket for a pseudo file descriptor       \param an open socket fd       \param sock (out) socket handle       \return true on success or false if not in map     */
name|bool
name|lookupSocket
argument_list|(
name|int
name|fd
argument_list|,
name|RSocket
operator|&
name|sock
argument_list|)
decl|const
decl_stmt|;
comment|/*!       \internal       Set the default connection to use for new sockets       \param an open connection     */
name|void
name|setDefaultConnection
parameter_list|(
name|RConnection
modifier|*
name|con
parameter_list|)
function_decl|;
comment|/*!       \internal       Get the default connection to use for new sockets       \return the connection, or null pointer if there is none set     */
name|RConnection
operator|*
name|defaultConnection
argument_list|()
specifier|const
expr_stmt|;
comment|/*!       \internal       Gets a reference to the singleton socket manager     */
specifier|static
name|QSymbianSocketManager
modifier|&
name|instance
parameter_list|()
function_decl|;
name|private
label|:
name|int
name|allocateSocket
parameter_list|()
function_decl|;
specifier|const
specifier|static
name|int
name|max_sockets
init|=
literal|0x20000
decl_stmt|;
comment|//covers all TCP and UDP ports, probably run out of memory first
specifier|const
specifier|static
name|int
name|socket_offset
init|=
literal|0x40000000
decl_stmt|;
comment|//hacky way of separating sockets from file descriptors
name|int
name|iNextSocket
decl_stmt|;
name|QHash
operator|<
name|QHashableSocket
operator|,
name|int
operator|>
name|socketMap
expr_stmt|;
name|QHash
operator|<
name|int
operator|,
name|RSocket
operator|>
name|reverseSocketMap
expr_stmt|;
name|mutable
name|QMutex
name|iMutex
decl_stmt|;
name|RSocketServ
name|iSocketServ
decl_stmt|;
name|RConnection
modifier|*
name|iDefaultConnection
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QCORE_SYMBIAN_P_H
end_comment
end_unit
