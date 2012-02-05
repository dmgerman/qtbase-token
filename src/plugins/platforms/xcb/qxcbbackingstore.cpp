begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qxcbconnection.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|<xcb/shm.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb_image.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/shm.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QXcbShmImage
class|class
name|QXcbShmImage
super|:
specifier|public
name|QXcbObject
block|{
public|public:
name|QXcbShmImage
parameter_list|(
name|QXcbScreen
modifier|*
name|connection
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|uint
name|depth
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|)
constructor_decl|;
DECL|function|~QXcbShmImage
name|~
name|QXcbShmImage
parameter_list|()
block|{
name|destroy
argument_list|()
expr_stmt|;
block|}
DECL|function|image
name|QImage
modifier|*
name|image
parameter_list|()
block|{
return|return
operator|&
name|m_qimage
return|;
block|}
DECL|function|size
name|QSize
name|size
parameter_list|()
specifier|const
block|{
return|return
name|m_qimage
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|put
parameter_list|(
name|xcb_window_t
name|window
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|dst
parameter_list|,
specifier|const
name|QRect
modifier|&
name|source
parameter_list|)
function_decl|;
name|void
name|preparePaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
private|private:
name|void
name|destroy
parameter_list|()
function_decl|;
DECL|member|m_shm_info
name|xcb_shm_segment_info_t
name|m_shm_info
decl_stmt|;
DECL|member|m_xcb_image
name|xcb_image_t
modifier|*
name|m_xcb_image
decl_stmt|;
DECL|member|m_qimage
name|QImage
name|m_qimage
decl_stmt|;
DECL|member|m_gc
name|xcb_gcontext_t
name|m_gc
decl_stmt|;
DECL|member|m_gc_window
name|xcb_window_t
name|m_gc_window
decl_stmt|;
DECL|member|m_dirty
name|QRegion
name|m_dirty
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QXcbShmImage
name|QXcbShmImage
operator|::
name|QXcbShmImage
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|uint
name|depth
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|)
member_init_list|:
name|QXcbObject
argument_list|(
name|screen
operator|->
name|connection
argument_list|()
argument_list|)
member_init_list|,
name|m_gc
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_gc_window
argument_list|(
literal|0
argument_list|)
block|{
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
name|m_xcb_image
operator|=
name|xcb_image_create_native
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|XCB_IMAGE_FORMAT_Z_PIXMAP
argument_list|,
name|depth
argument_list|,
literal|0
argument_list|,
operator|~
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
specifier|const
name|int
name|segmentSize
init|=
name|m_xcb_image
operator|->
name|stride
operator|*
name|m_xcb_image
operator|->
name|height
decl_stmt|;
if|if
condition|(
operator|!
name|segmentSize
condition|)
return|return;
name|int
name|id
init|=
name|shmget
argument_list|(
name|IPC_PRIVATE
argument_list|,
name|segmentSize
argument_list|,
name|IPC_CREAT
operator||
literal|0777
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"QXcbShmImage: shmget() failed (%d) for size %d (%dx%d)"
argument_list|,
name|errno
argument_list|,
name|segmentSize
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|m_shm_info
operator|.
name|shmid
operator|=
name|id
expr_stmt|;
name|m_shm_info
operator|.
name|shmaddr
operator|=
name|m_xcb_image
operator|->
name|data
operator|=
operator|(
name|quint8
operator|*
operator|)
name|shmat
argument_list|(
name|m_shm_info
operator|.
name|shmid
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_shm_info
operator|.
name|shmseg
operator|=
name|xcb_generate_id
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|xcb_query_extension_reply_t
modifier|*
name|shm_reply
init|=
name|xcb_get_extension_data
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
operator|&
name|xcb_shm_id
argument_list|)
decl_stmt|;
name|bool
name|shm_present
init|=
name|shm_reply
operator|!=
name|NULL
operator|&&
name|shm_reply
operator|->
name|present
decl_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|shm_present
condition|)
name|error
operator|=
name|xcb_request_check
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|xcb_shm_attach_checked
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|m_shm_info
operator|.
name|shmseg
argument_list|,
name|m_shm_info
operator|.
name|shmid
argument_list|,
literal|false
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|shm_present
operator|||
name|error
condition|)
block|{
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|shmdt
argument_list|(
name|m_shm_info
operator|.
name|shmaddr
argument_list|)
expr_stmt|;
name|shmctl
argument_list|(
name|m_shm_info
operator|.
name|shmid
argument_list|,
name|IPC_RMID
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_shm_info
operator|.
name|shmaddr
operator|=
literal|0
expr_stmt|;
name|m_xcb_image
operator|->
name|data
operator|=
operator|(
name|uint8_t
operator|*
operator|)
name|malloc
argument_list|(
name|segmentSize
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|shmctl
argument_list|(
name|m_shm_info
operator|.
name|shmid
argument_list|,
name|IPC_RMID
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"QXcbBackingStore: Error while marking the shared memory segment to be destroyed"
expr_stmt|;
block|}
name|m_qimage
operator|=
name|QImage
argument_list|(
operator|(
name|uchar
operator|*
operator|)
name|m_xcb_image
operator|->
name|data
argument_list|,
name|m_xcb_image
operator|->
name|width
argument_list|,
name|m_xcb_image
operator|->
name|height
argument_list|,
name|m_xcb_image
operator|->
name|stride
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|destroy
name|void
name|QXcbShmImage
operator|::
name|destroy
parameter_list|()
block|{
specifier|const
name|int
name|segmentSize
init|=
name|m_xcb_image
condition|?
operator|(
name|m_xcb_image
operator|->
name|stride
operator|*
name|m_xcb_image
operator|->
name|height
operator|)
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|segmentSize
operator|&&
name|m_shm_info
operator|.
name|shmaddr
condition|)
name|Q_XCB_CALL
argument_list|(
name|xcb_shm_detach
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|m_shm_info
operator|.
name|shmseg
argument_list|)
argument_list|)
expr_stmt|;
name|xcb_image_destroy
argument_list|(
name|m_xcb_image
argument_list|)
expr_stmt|;
if|if
condition|(
name|segmentSize
condition|)
block|{
if|if
condition|(
name|m_shm_info
operator|.
name|shmaddr
condition|)
block|{
name|shmdt
argument_list|(
name|m_shm_info
operator|.
name|shmaddr
argument_list|)
expr_stmt|;
name|shmctl
argument_list|(
name|m_shm_info
operator|.
name|shmid
argument_list|,
name|IPC_RMID
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|free
argument_list|(
name|m_xcb_image
operator|->
name|data
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_gc
condition|)
name|Q_XCB_CALL
argument_list|(
name|xcb_free_gc
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|m_gc
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|put
name|void
name|QXcbShmImage
operator|::
name|put
parameter_list|(
name|xcb_window_t
name|window
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|target
parameter_list|,
specifier|const
name|QRect
modifier|&
name|source
parameter_list|)
block|{
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_gc_window
operator|!=
name|window
condition|)
block|{
if|if
condition|(
name|m_gc
condition|)
name|Q_XCB_CALL
argument_list|(
name|xcb_free_gc
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|m_gc
argument_list|)
argument_list|)
expr_stmt|;
name|m_gc
operator|=
name|xcb_generate_id
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
expr_stmt|;
name|Q_XCB_CALL
argument_list|(
name|xcb_create_gc
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|m_gc
argument_list|,
name|window
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|m_gc_window
operator|=
name|window
expr_stmt|;
block|}
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_shm_info
operator|.
name|shmaddr
condition|)
block|{
name|xcb_image_shm_put
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|window
argument_list|,
name|m_gc
argument_list|,
name|m_xcb_image
argument_list|,
name|m_shm_info
argument_list|,
name|source
operator|.
name|x
argument_list|()
argument_list|,
name|source
operator|.
name|y
argument_list|()
argument_list|,
name|target
operator|.
name|x
argument_list|()
argument_list|,
name|target
operator|.
name|y
argument_list|()
argument_list|,
name|source
operator|.
name|width
argument_list|()
argument_list|,
name|source
operator|.
name|height
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// If we upload the whole image in a single chunk, the result might be
comment|// larger than the server's maximum request size and stuff breaks.
comment|// To work around that, we upload the image in chunks where each chunk
comment|// is small enough for a single request.
name|int
name|src_x
init|=
name|source
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|src_y
init|=
name|source
operator|.
name|y
argument_list|()
decl_stmt|;
name|int
name|target_x
init|=
name|target
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|target_y
init|=
name|target
operator|.
name|y
argument_list|()
decl_stmt|;
name|int
name|width
init|=
name|source
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|height
init|=
name|source
operator|.
name|height
argument_list|()
decl_stmt|;
comment|// We must make sure that each request is not larger than max_req_size.
comment|// Each request takes req_size + m_xcb_image->stride * height bytes.
name|uint32_t
name|max_req_size
init|=
name|xcb_get_maximum_request_length
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
decl_stmt|;
name|uint32_t
name|req_size
init|=
sizeof|sizeof
argument_list|(
name|xcb_put_image_request_t
argument_list|)
decl_stmt|;
name|int
name|rows_per_put
init|=
operator|(
name|max_req_size
operator|-
name|req_size
operator|)
operator|/
name|m_xcb_image
operator|->
name|stride
decl_stmt|;
comment|// This assert could trigger if a single row has more pixels than fit in
comment|// a single PutImage request. However, max_req_size is guaranteed to be
comment|// at least 16384 bytes. That should be enough for quite large images.
name|Q_ASSERT
argument_list|(
name|rows_per_put
operator|>
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
name|height
operator|>
literal|0
condition|)
block|{
name|int
name|rows
init|=
name|std
operator|::
name|min
argument_list|(
name|height
argument_list|,
name|rows_per_put
argument_list|)
decl_stmt|;
name|xcb_image_t
modifier|*
name|subimage
init|=
name|xcb_image_subimage
argument_list|(
name|m_xcb_image
argument_list|,
name|src_x
argument_list|,
name|src_y
argument_list|,
name|width
argument_list|,
name|rows
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|xcb_image_put
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|window
argument_list|,
name|m_gc
argument_list|,
name|subimage
argument_list|,
name|target_x
argument_list|,
name|target_y
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xcb_image_destroy
argument_list|(
name|subimage
argument_list|)
expr_stmt|;
name|src_y
operator|+=
name|rows
expr_stmt|;
name|target_y
operator|+=
name|rows
expr_stmt|;
name|height
operator|-=
name|rows
expr_stmt|;
block|}
block|}
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
name|m_dirty
operator|=
name|m_dirty
operator||
name|source
expr_stmt|;
name|xcb_flush
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|preparePaint
name|void
name|QXcbShmImage
operator|::
name|preparePaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
comment|// to prevent X from reading from the image region while we're writing to it
if|if
condition|(
name|m_dirty
operator|.
name|intersects
argument_list|(
name|region
argument_list|)
condition|)
block|{
name|connection
argument_list|()
operator|->
name|sync
argument_list|()
expr_stmt|;
name|m_dirty
operator|=
name|QRegion
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|QXcbBackingStore
name|QXcbBackingStore
operator|::
name|QXcbBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
member_init_list|,
name|m_image
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_syncingResize
argument_list|(
literal|false
argument_list|)
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|setConnection
argument_list|(
name|screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QXcbBackingStore
name|QXcbBackingStore
operator|::
name|~
name|QXcbBackingStore
parameter_list|()
block|{
operator|delete
name|m_image
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QXcbBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
name|m_image
operator|->
name|image
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QXcbBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|m_image
operator|->
name|preparePaint
argument_list|(
name|region
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|if (m_image->image()->hasAlphaChannel()) {         QPainter p(m_image->image());         p.setCompositionMode(QPainter::CompositionMode_Source);         const QVector<QRect> rects = region.rects();         const QColor blank = Qt::transparent;         for (QVector<QRect>::const_iterator it = rects.begin(); it != rects.end(); ++it) {             p.fillRect(*it, blank);         }     }
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QXcbBackingStore
operator|::
name|endPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|flush
name|void
name|QXcbBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_image
operator|||
name|m_image
operator|->
name|size
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QSize
name|imageSize
init|=
name|m_image
operator|->
name|size
argument_list|()
decl_stmt|;
name|QRegion
name|clipped
init|=
name|region
decl_stmt|;
name|clipped
operator|&=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|window
operator|->
name|width
argument_list|()
argument_list|,
name|window
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|clipped
operator|&=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|imageSize
operator|.
name|width
argument_list|()
argument_list|,
name|imageSize
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|translated
argument_list|(
operator|-
name|offset
argument_list|)
expr_stmt|;
name|QRect
name|bounds
init|=
name|clipped
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
if|if
condition|(
name|bounds
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
name|QXcbWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QXcbWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|clipped
operator|.
name|rects
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
name|rects
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|m_image
operator|->
name|put
argument_list|(
name|platformWindow
operator|->
name|xcb_window
argument_list|()
argument_list|,
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|topLeft
argument_list|()
argument_list|,
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|translated
argument_list|(
name|offset
argument_list|)
argument_list|)
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_syncingResize
condition|)
block|{
name|xcb_flush
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
expr_stmt|;
name|connection
argument_list|()
operator|->
name|sync
argument_list|()
expr_stmt|;
name|m_syncingResize
operator|=
literal|false
expr_stmt|;
name|platformWindow
operator|->
name|updateSyncRequestCounter
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QXcbBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{
if|if
condition|(
name|m_image
operator|&&
name|size
operator|==
name|m_image
operator|->
name|size
argument_list|()
condition|)
return|return;
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
name|QXcbScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|window
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QPlatformWindow
modifier|*
name|pw
init|=
name|window
argument_list|()
operator|->
name|handle
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|pw
condition|)
block|{
name|window
argument_list|()
operator|->
name|create
argument_list|()
expr_stmt|;
name|pw
operator|=
name|window
argument_list|()
operator|->
name|handle
argument_list|()
expr_stmt|;
block|}
name|QXcbWindow
modifier|*
name|win
init|=
cast|static_cast
argument_list|<
name|QXcbWindow
operator|*
argument_list|>
argument_list|(
name|pw
argument_list|)
decl_stmt|;
operator|delete
name|m_image
expr_stmt|;
name|m_image
operator|=
operator|new
name|QXcbShmImage
argument_list|(
name|screen
argument_list|,
name|size
argument_list|,
name|win
operator|->
name|depth
argument_list|()
argument_list|,
name|win
operator|->
name|imageFormat
argument_list|()
argument_list|)
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|connection
argument_list|()
argument_list|)
expr_stmt|;
name|m_syncingResize
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function_decl
specifier|extern
name|void
name|qt_scrollRectInImage
parameter_list|(
name|QImage
modifier|&
name|img
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|scroll
name|bool
name|QXcbBackingStore
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_image
operator|||
name|m_image
operator|->
name|image
argument_list|()
operator|->
name|isNull
argument_list|()
condition|)
return|return
literal|false
return|;
name|m_image
operator|->
name|preparePaint
argument_list|(
name|area
argument_list|)
expr_stmt|;
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|area
operator|.
name|rects
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
name|rects
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qt_scrollRectInImage
argument_list|(
operator|*
name|m_image
operator|->
name|image
argument_list|()
argument_list|,
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
