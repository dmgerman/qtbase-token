begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCREENVNC_P_H
end_ifndef
begin_define
DECL|macro|QSCREENVNC_P_H
define|#
directive|define
name|QSCREENVNC_P_H
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
comment|// of the QLibrary class.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|"qvncintegration.h"
end_include
begin_include
include|#
directive|include
file|"qvnccursor.h"
end_include
begin_define
DECL|macro|QT_NO_QWS_CURSOR
define|#
directive|define
name|QT_NO_QWS_CURSOR
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_VNC
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedmemory.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qtcpsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qtcpserver.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVNCServer
name|class
name|QVNCServer
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_CURSOR
end_ifndef
begin_decl_stmt
name|class
name|QVNCCursor
range|:
name|public
name|QProxyScreenCursor
block|{
name|public
operator|:
name|QVNCCursor
argument_list|(
name|QVNCScreen
operator|*
name|s
argument_list|)
block|;
operator|~
name|QVNCCursor
argument_list|()
block|;
name|void
name|hide
argument_list|()
block|;
name|void
name|show
argument_list|()
block|;
name|void
name|set
argument_list|(
argument|const QImage&image
argument_list|,
argument|int hotx
argument_list|,
argument|int hoty
argument_list|)
block|;
name|void
name|move
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|private
operator|:
name|void
name|setDirty
argument_list|(
argument|const QRect&r
argument_list|)
specifier|const
block|;
name|QVNCScreen
operator|*
name|screen
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QVNCClientCursor
range|:
name|public
name|QProxyScreenCursor
block|{
name|public
operator|:
name|QVNCClientCursor
argument_list|(
name|QVNCServer
operator|*
name|s
argument_list|)
block|;
operator|~
name|QVNCClientCursor
argument_list|()
block|;
name|void
name|set
argument_list|(
argument|const QImage&image
argument_list|,
argument|int hotx
argument_list|,
argument|int hoty
argument_list|)
block|;
name|void
name|write
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QVNCServer
operator|*
name|server
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_CURSOR
end_comment
begin_define
DECL|macro|MAP_TILE_SIZE
define|#
directive|define
name|MAP_TILE_SIZE
value|16
end_define
begin_define
DECL|macro|MAP_WIDTH
define|#
directive|define
name|MAP_WIDTH
value|1280 / MAP_TILE_SIZE
end_define
begin_define
DECL|macro|MAP_HEIGHT
define|#
directive|define
name|MAP_HEIGHT
value|1024 / MAP_TILE_SIZE
end_define
begin_decl_stmt
name|class
name|QVNCDirtyMap
block|{
name|public
label|:
name|QVNCDirtyMap
argument_list|(
name|QVNCScreen
operator|*
name|screen
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QVNCDirtyMap
argument_list|()
expr_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
name|bool
name|dirty
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|setDirty
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|bool
name|force
init|=
name|false
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|setClean
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
name|int
name|bytesPerPixel
decl_stmt|;
name|int
name|numDirty
decl_stmt|;
name|int
name|mapWidth
decl_stmt|;
name|int
name|mapHeight
decl_stmt|;
name|protected
label|:
name|uchar
modifier|*
name|map
decl_stmt|;
name|QVNCScreen
modifier|*
name|screen
decl_stmt|;
name|uchar
modifier|*
name|buffer
decl_stmt|;
name|int
name|bufferWidth
decl_stmt|;
name|int
name|bufferHeight
decl_stmt|;
name|int
name|bufferStride
decl_stmt|;
name|int
name|numTiles
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QVNCDirtyMapOptimized
operator|:
name|public
name|QVNCDirtyMap
block|{
name|public
operator|:
name|QVNCDirtyMapOptimized
argument_list|(
name|QVNCScreen
operator|*
name|screen
argument_list|)
operator|:
name|QVNCDirtyMap
argument_list|(
argument|screen
argument_list|)
block|{}
operator|~
name|QVNCDirtyMapOptimized
argument_list|()
block|{}
name|void
name|setDirty
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|bool force = false
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QRfbRect
block|{
name|public
label|:
name|QRfbRect
argument_list|()
block|{}
name|QRfbRect
argument_list|(
argument|quint16 _x
argument_list|,
argument|quint16 _y
argument_list|,
argument|quint16 _w
argument_list|,
argument|quint16 _h
argument_list|)
block|{
name|x
operator|=
name|_x
expr_stmt|;
name|y
operator|=
name|_y
expr_stmt|;
name|w
operator|=
name|_w
expr_stmt|;
name|h
operator|=
name|_h
expr_stmt|;
block|}
name|void
name|read
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|void
name|write
argument_list|(
name|QTcpSocket
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
name|quint16
name|x
decl_stmt|;
name|quint16
name|y
decl_stmt|;
name|quint16
name|w
decl_stmt|;
name|quint16
name|h
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRfbPixelFormat
block|{
name|public
label|:
specifier|static
name|int
name|size
parameter_list|()
block|{
return|return
literal|16
return|;
block|}
name|void
name|read
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|void
name|write
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|int
name|bitsPerPixel
decl_stmt|;
name|int
name|depth
decl_stmt|;
name|bool
name|bigEndian
decl_stmt|;
name|bool
name|trueColor
decl_stmt|;
name|int
name|redBits
decl_stmt|;
name|int
name|greenBits
decl_stmt|;
name|int
name|blueBits
decl_stmt|;
name|int
name|redShift
decl_stmt|;
name|int
name|greenShift
decl_stmt|;
name|int
name|blueShift
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRfbServerInit
block|{
name|public
label|:
name|QRfbServerInit
argument_list|()
block|{
name|name
operator|=
literal|0
expr_stmt|;
block|}
operator|~
name|QRfbServerInit
argument_list|()
block|{
name|delete
index|[]
name|name
block|; }
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|QRfbPixelFormat
operator|::
name|size
argument_list|()
operator|+
literal|8
operator|+
name|strlen
argument_list|(
name|name
argument_list|)
return|;
block|}
name|void
name|setName
parameter_list|(
specifier|const
name|char
modifier|*
name|n
parameter_list|)
function_decl|;
name|void
name|read
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|void
name|write
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|quint16
name|width
decl_stmt|;
name|quint16
name|height
decl_stmt|;
name|QRfbPixelFormat
name|format
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRfbSetEncodings
block|{
name|public
label|:
name|bool
name|read
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|quint16
name|count
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRfbFrameBufferUpdateRequest
block|{
name|public
label|:
name|bool
name|read
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|char
name|incremental
decl_stmt|;
name|QRfbRect
name|rect
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRfbKeyEvent
block|{
name|public
label|:
name|bool
name|read
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|char
name|down
decl_stmt|;
name|int
name|keycode
decl_stmt|;
name|int
name|unicode
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRfbPointerEvent
block|{
name|public
label|:
name|bool
name|read
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|Qt
operator|::
name|MouseButtons
name|buttons
expr_stmt|;
enum|enum
block|{
name|WheelNone
block|,
name|WheelUp
block|,
name|WheelDown
block|,
name|WheelLeft
block|,
name|WheelRight
block|}
name|wheelDirection
enum|;
name|quint16
name|x
decl_stmt|;
name|quint16
name|y
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRfbClientCutText
block|{
name|public
label|:
name|bool
name|read
parameter_list|(
name|QTcpSocket
modifier|*
name|s
parameter_list|)
function_decl|;
name|quint32
name|length
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QVNCScreenPrivate
range|:
name|public
name|QObject
block|{
name|public
operator|:
name|QVNCScreenPrivate
argument_list|(
argument|QVNCScreen *parent
argument_list|,
argument|int screenId
argument_list|)
block|;
operator|~
name|QVNCScreenPrivate
argument_list|()
block|;
name|void
name|setDirty
argument_list|(
argument|const QRect&rect
argument_list|,
argument|bool force = false
argument_list|)
block|;
name|void
name|configure
argument_list|()
block|;
name|qreal
name|dpiX
block|;
name|qreal
name|dpiY
block|;
name|bool
name|doOnScreenSurface
block|;
name|QVNCDirtyMap
operator|*
name|dirty
block|;
name|int
name|refreshRate
block|;
name|QVNCServer
operator|*
name|vncServer
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_QWS_MULTIPROCESS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SHAREDMEMORY
argument_list|)
name|QSharedMemory
name|shm
block|;
endif|#
directive|endif
name|QVNCScreen
operator|*
name|q_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QRfbEncoder
block|{
name|public
label|:
name|QRfbEncoder
argument_list|(
name|QVNCServer
operator|*
name|s
argument_list|)
operator|:
name|server
argument_list|(
argument|s
argument_list|)
block|{}
name|virtual
operator|~
name|QRfbEncoder
argument_list|()
block|{}
name|virtual
name|void
name|write
argument_list|()
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|QVNCServer
modifier|*
name|server
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRfbRawEncoder
range|:
name|public
name|QRfbEncoder
block|{
name|public
operator|:
name|QRfbRawEncoder
argument_list|(
name|QVNCServer
operator|*
name|s
argument_list|)
operator|:
name|QRfbEncoder
argument_list|(
argument|s
argument_list|)
block|{}
name|void
name|write
argument_list|()
block|;
name|private
operator|:
name|QByteArray
name|buffer
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QRfbHextileEncoder
name|template
operator|<
name|class
name|SRC
operator|>
name|class
name|QRfbHextileEncoder
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|SRC
operator|>
name|class
name|QRfbSingleColorHextile
block|{
name|public
operator|:
name|QRfbSingleColorHextile
argument_list|(
name|QRfbHextileEncoder
operator|<
name|SRC
operator|>
operator|*
name|e
argument_list|)
operator|:
name|encoder
argument_list|(
argument|e
argument_list|)
block|{}
name|bool
name|read
argument_list|(
argument|const uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int stride
argument_list|)
block|;
name|void
name|write
argument_list|(
argument|QTcpSocket *socket
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QRfbHextileEncoder
operator|<
name|SRC
operator|>
operator|*
name|encoder
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|SRC
operator|>
name|class
name|QRfbDualColorHextile
block|{
name|public
operator|:
name|QRfbDualColorHextile
argument_list|(
name|QRfbHextileEncoder
operator|<
name|SRC
operator|>
operator|*
name|e
argument_list|)
operator|:
name|encoder
argument_list|(
argument|e
argument_list|)
block|{}
name|bool
name|read
argument_list|(
argument|const uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int stride
argument_list|)
block|;
name|void
name|write
argument_list|(
argument|QTcpSocket *socket
argument_list|)
specifier|const
block|;
name|private
operator|:
expr|struct
name|Rect
block|{
name|quint8
name|xy
block|;
name|quint8
name|wh
block|;     }
name|Q_PACKED
name|rects
index|[
literal|8
operator|*
literal|16
index|]
block|;
name|quint8
name|numRects
block|;
name|QRfbHextileEncoder
operator|<
name|SRC
operator|>
operator|*
name|encoder
block|;
name|private
operator|:
specifier|inline
name|int
name|lastx
argument_list|()
specifier|const
block|{
return|return
name|rectx
argument_list|(
name|numRects
argument_list|)
return|;
block|}
specifier|inline
name|int
name|lasty
argument_list|()
specifier|const
block|{
return|return
name|recty
argument_list|(
name|numRects
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|int
name|rectx
argument_list|(
name|int
name|r
argument_list|)
decl|const
block|{
return|return
name|rects
index|[
name|r
index|]
operator|.
name|xy
operator|>>
literal|4
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|recty
argument_list|(
name|int
name|r
argument_list|)
decl|const
block|{
return|return
name|rects
index|[
name|r
index|]
operator|.
name|xy
operator|&
literal|0x0f
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|width
argument_list|(
name|int
name|r
argument_list|)
decl|const
block|{
return|return
operator|(
name|rects
index|[
name|r
index|]
operator|.
name|wh
operator|>>
literal|4
operator|)
operator|+
literal|1
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|height
argument_list|(
name|int
name|r
argument_list|)
decl|const
block|{
return|return
operator|(
name|rects
index|[
name|r
index|]
operator|.
name|wh
operator|&
literal|0x0f
operator|)
operator|+
literal|1
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|void
name|setX
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|x
parameter_list|)
block|{
name|rects
index|[
name|r
index|]
operator|.
name|xy
operator|=
operator|(
name|x
operator|<<
literal|4
operator|)
operator||
operator|(
name|rects
index|[
name|r
index|]
operator|.
name|xy
operator|&
literal|0x0f
operator|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setY
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|rects
index|[
name|r
index|]
operator|.
name|xy
operator|=
operator|(
name|rects
index|[
name|r
index|]
operator|.
name|xy
operator|&
literal|0xf0
operator|)
operator||
name|y
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setWidth
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|width
parameter_list|)
block|{
name|rects
index|[
name|r
index|]
operator|.
name|wh
operator|=
operator|(
operator|(
name|width
operator|-
literal|1
operator|)
operator|<<
literal|4
operator|)
operator||
operator|(
name|rects
index|[
name|r
index|]
operator|.
name|wh
operator|&
literal|0x0f
operator|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setHeight
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|rects
index|[
name|r
index|]
operator|.
name|wh
operator|=
operator|(
name|rects
index|[
name|r
index|]
operator|.
name|wh
operator|&
literal|0xf0
operator|)
operator||
operator|(
name|height
operator|-
literal|1
operator|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setWidth
parameter_list|(
name|int
name|width
parameter_list|)
block|{
name|setWidth
argument_list|(
name|numRects
argument_list|,
name|width
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setHeight
parameter_list|(
name|int
name|height
parameter_list|)
block|{
name|setHeight
argument_list|(
name|numRects
argument_list|,
name|height
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setX
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|setX
argument_list|(
name|numRects
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setY
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|setY
argument_list|(
name|numRects
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|next
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|SRC
operator|>
name|class
name|QRfbMultiColorHextile
block|{
name|public
operator|:
name|QRfbMultiColorHextile
argument_list|(
name|QRfbHextileEncoder
operator|<
name|SRC
operator|>
operator|*
name|e
argument_list|)
operator|:
name|encoder
argument_list|(
argument|e
argument_list|)
block|{}
name|bool
name|read
argument_list|(
argument|const uchar *data
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int stride
argument_list|)
block|;
name|void
name|write
argument_list|(
argument|QTcpSocket *socket
argument_list|)
specifier|const
block|;
name|private
operator|:
specifier|inline
name|quint8
operator|*
name|rect
argument_list|(
argument|int r
argument_list|)
block|{
return|return
name|rects
operator|.
name|data
argument_list|()
operator|+
name|r
operator|*
operator|(
name|bpp
operator|+
literal|2
operator|)
return|;
block|}
specifier|inline
specifier|const
name|quint8
operator|*
name|rect
argument_list|(
argument|int r
argument_list|)
specifier|const
block|{
return|return
name|rects
operator|.
name|constData
argument_list|()
operator|+
name|r
operator|*
operator|(
name|bpp
operator|+
literal|2
operator|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setX
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|x
parameter_list|)
block|{
name|quint8
modifier|*
name|ptr
init|=
name|rect
argument_list|(
name|r
argument_list|)
operator|+
name|bpp
decl_stmt|;
operator|*
name|ptr
operator|=
operator|(
name|x
operator|<<
literal|4
operator|)
operator||
operator|(
operator|*
name|ptr
operator|&
literal|0x0f
operator|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setY
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|quint8
modifier|*
name|ptr
init|=
name|rect
argument_list|(
name|r
argument_list|)
operator|+
name|bpp
decl_stmt|;
operator|*
name|ptr
operator|=
operator|(
operator|*
name|ptr
operator|&
literal|0xf0
operator|)
operator||
name|y
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|setColor
parameter_list|(
name|SRC
name|color
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|inline
name|int
name|rectx
argument_list|(
name|int
name|r
argument_list|)
decl|const
block|{
specifier|const
name|quint8
modifier|*
name|ptr
init|=
name|rect
argument_list|(
name|r
argument_list|)
operator|+
name|bpp
decl_stmt|;
return|return
operator|*
name|ptr
operator|>>
literal|4
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|recty
argument_list|(
name|int
name|r
argument_list|)
decl|const
block|{
specifier|const
name|quint8
modifier|*
name|ptr
init|=
name|rect
argument_list|(
name|r
argument_list|)
operator|+
name|bpp
decl_stmt|;
return|return
operator|*
name|ptr
operator|&
literal|0x0f
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|void
name|setWidth
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|width
parameter_list|)
block|{
name|quint8
modifier|*
name|ptr
init|=
name|rect
argument_list|(
name|r
argument_list|)
operator|+
name|bpp
operator|+
literal|1
decl_stmt|;
operator|*
name|ptr
operator|=
operator|(
operator|(
name|width
operator|-
literal|1
operator|)
operator|<<
literal|4
operator|)
operator||
operator|(
operator|*
name|ptr
operator|&
literal|0x0f
operator|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setHeight
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|quint8
modifier|*
name|ptr
init|=
name|rect
argument_list|(
name|r
argument_list|)
operator|+
name|bpp
operator|+
literal|1
decl_stmt|;
operator|*
name|ptr
operator|=
operator|(
operator|*
name|ptr
operator|&
literal|0xf0
operator|)
operator||
operator|(
name|height
operator|-
literal|1
operator|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|bool
name|beginRect
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|endRect
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
specifier|const
name|int
name|maxRectsSize
init|=
literal|16
operator|*
literal|16
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QVarLengthArray
operator|<
name|quint8
operator|,
name|maxRectsSize
operator|>
name|rects
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|quint8
name|bpp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint8
name|numRects
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QRfbHextileEncoder
operator|<
name|SRC
operator|>
operator|*
name|encoder
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|SRC
operator|>
name|class
name|QRfbHextileEncoder
operator|:
name|public
name|QRfbEncoder
block|{
name|public
operator|:
name|QRfbHextileEncoder
argument_list|(
name|QVNCServer
operator|*
name|s
argument_list|)
block|;
name|void
name|write
argument_list|()
block|;
name|private
operator|:
expr|enum
name|SubEncoding
block|{
name|Raw
operator|=
literal|1
block|,
name|BackgroundSpecified
operator|=
literal|2
block|,
name|ForegroundSpecified
operator|=
literal|4
block|,
name|AnySubrects
operator|=
literal|8
block|,
name|SubrectsColoured
operator|=
literal|16
block|}
block|;
name|QByteArray
name|buffer
block|;
name|QRfbSingleColorHextile
operator|<
name|SRC
operator|>
name|singleColorHextile
block|;
name|QRfbDualColorHextile
operator|<
name|SRC
operator|>
name|dualColorHextile
block|;
name|QRfbMultiColorHextile
operator|<
name|SRC
operator|>
name|multiColorHextile
block|;
name|SRC
name|bg
block|;
name|SRC
name|fg
block|;
name|bool
name|newBg
block|;
name|bool
name|newFg
block|;
name|friend
name|class
name|QRfbSingleColorHextile
operator|<
name|SRC
operator|>
block|;
name|friend
name|class
name|QRfbDualColorHextile
operator|<
name|SRC
operator|>
block|;
name|friend
name|class
name|QRfbMultiColorHextile
operator|<
name|SRC
operator|>
block|; }
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QVNCServer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QVNCServer
argument_list|(
name|QVNCScreen
operator|*
name|screen
argument_list|)
block|;
name|QVNCServer
argument_list|(
argument|QVNCScreen *screen
argument_list|,
argument|int id
argument_list|)
block|;
operator|~
name|QVNCServer
argument_list|()
block|;
name|void
name|setDirty
argument_list|()
block|;
name|void
name|setDirtyCursor
argument_list|()
block|{
name|dirtyCursor
operator|=
name|true
block|;
name|setDirty
argument_list|()
block|; }
specifier|inline
name|bool
name|isConnected
argument_list|()
specifier|const
block|{
return|return
name|state
operator|==
name|Connected
return|;
block|}
specifier|inline
name|void
name|setRefreshRate
argument_list|(
argument|int rate
argument_list|)
block|{
name|refreshRate
operator|=
name|rate
block|; }
expr|enum
name|ClientMsg
block|{
name|SetPixelFormat
operator|=
literal|0
block|,
name|FixColourMapEntries
operator|=
literal|1
block|,
name|SetEncodings
operator|=
literal|2
block|,
name|FramebufferUpdateRequest
operator|=
literal|3
block|,
name|KeyEvent
operator|=
literal|4
block|,
name|PointerEvent
operator|=
literal|5
block|,
name|ClientCutText
operator|=
literal|6
block|}
block|;      enum
name|ServerMsg
block|{
name|FramebufferUpdate
operator|=
literal|0
block|,
name|SetColourMapEntries
operator|=
literal|1
block|}
block|;
name|void
name|convertPixels
argument_list|(
argument|char *dst
argument_list|,
argument|const char *src
argument_list|,
argument|int count
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|clientBytesPerPixel
argument_list|()
specifier|const
block|{
return|return
name|pixelFormat
operator|.
name|bitsPerPixel
operator|/
literal|8
return|;
block|}
specifier|inline
name|QVNCScreen
operator|*
name|screen
argument_list|()
specifier|const
block|{
return|return
name|qvnc_screen
return|;
block|}
specifier|inline
name|QVNCDirtyMap
operator|*
name|dirtyMap
argument_list|()
specifier|const
block|{
return|return
name|qvnc_screen
operator|->
name|dirtyMap
argument_list|()
return|;
block|}
specifier|inline
name|QTcpSocket
operator|*
name|clientSocket
argument_list|()
specifier|const
block|{
return|return
name|client
return|;
block|}
name|QImage
operator|*
name|screenImage
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|doPixelConversion
argument_list|()
specifier|const
block|{
return|return
name|needConversion
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_QWS_CURSOR
specifier|inline
name|bool
name|hasClientCursor
argument_list|()
specifier|const
block|{
return|return
name|qvnc_cursor
operator|!=
literal|0
return|;
block|}
endif|#
directive|endif
name|void
name|setCursor
argument_list|(
argument|QVNCCursor * c
argument_list|)
block|{
name|cursor
operator|=
name|c
block|; }
name|private
operator|:
name|void
name|setPixelFormat
argument_list|()
block|;
name|void
name|setEncodings
argument_list|()
block|;
name|void
name|frameBufferUpdateRequest
argument_list|()
block|;
name|void
name|pointerEvent
argument_list|()
block|;
name|void
name|keyEvent
argument_list|()
block|;
name|void
name|clientCutText
argument_list|()
block|;
name|bool
name|pixelConversionNeeded
argument_list|()
specifier|const
block|;
name|private
name|slots
operator|:
name|void
name|newConnection
argument_list|()
block|;
name|void
name|readClient
argument_list|()
block|;
name|void
name|checkUpdate
argument_list|()
block|;
name|void
name|discardClient
argument_list|()
block|;
name|private
operator|:
name|void
name|init
argument_list|(
argument|uint port
argument_list|)
block|;     enum
name|ClientState
block|{
name|Unconnected
block|,
name|Protocol
block|,
name|Init
block|,
name|Connected
block|}
block|;
name|QTimer
operator|*
name|timer
block|;
name|QTcpServer
operator|*
name|serverSocket
block|;
name|QTcpSocket
operator|*
name|client
block|;
name|ClientState
name|state
block|;
name|quint8
name|msgType
block|;
name|bool
name|handleMsg
block|;
name|QRfbPixelFormat
name|pixelFormat
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|keymod
block|;
name|Qt
operator|::
name|MouseButtons
name|buttons
block|;
name|int
name|encodingsPending
block|;
name|int
name|cutTextPending
block|;
name|uint
name|supportCopyRect
operator|:
literal|1
block|;
name|uint
name|supportRRE
operator|:
literal|1
block|;
name|uint
name|supportCoRRE
operator|:
literal|1
block|;
name|uint
name|supportHextile
operator|:
literal|1
block|;
name|uint
name|supportZRLE
operator|:
literal|1
block|;
name|uint
name|supportCursor
operator|:
literal|1
block|;
name|uint
name|supportDesktopSize
operator|:
literal|1
block|;
name|bool
name|wantUpdate
block|;
name|bool
name|sameEndian
block|;
name|bool
name|needConversion
block|;
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
name|bool
name|swapBytes
block|;
endif|#
directive|endif
name|bool
name|dirtyCursor
block|;
name|int
name|refreshRate
block|;
name|QVNCScreen
operator|*
name|qvnc_screen
block|;
ifndef|#
directive|ifndef
name|QT_NO_QWS_CURSOR
name|QVNCClientCursor
operator|*
name|qvnc_cursor
block|;
endif|#
directive|endif
name|QRfbEncoder
operator|*
name|encoder
block|;
name|QVNCCursor
operator|*
name|cursor
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_VNC
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCREENVNC_P_H
end_comment
end_unit
