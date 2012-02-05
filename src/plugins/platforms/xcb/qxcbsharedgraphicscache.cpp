begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_USE_XCB_SHARED_GRAPHICS_CACHE
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qxcbsharedgraphicscache.h"
end_include
begin_include
include|#
directive|include
file|"qxcbsharedbuffermanager.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedmemory.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qscreen.h>
end_include
begin_define
DECL|macro|GL_GLEXT_PROTOTYPES
define|#
directive|define
name|GL_GLEXT_PROTOTYPES
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
end_include
begin_define
DECL|macro|SHAREDGRAPHICSCACHE_DEBUG
define|#
directive|define
name|SHAREDGRAPHICSCACHE_DEBUG
value|1
end_define
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QXcbSharedGraphicsCache
name|QXcbSharedGraphicsCache
operator|::
name|QXcbSharedGraphicsCache
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QPlatformSharedGraphicsCache
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_bufferManager
argument_list|(
operator|new
name|QXcbSharedBufferManager
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|requestItems
name|void
name|QXcbSharedGraphicsCache
operator|::
name|requestItems
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|cacheId
parameter_list|,
specifier|const
name|QVector
argument_list|<
name|quint32
argument_list|>
modifier|&
name|itemIds
parameter_list|)
block|{
name|m_bufferManager
operator|->
name|beginSharedBufferAction
argument_list|(
name|cacheId
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|quint32
argument_list|>
name|itemsForRequest
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
name|itemIds
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|itemsForRequest
operator|.
name|insert
argument_list|(
name|itemIds
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|m_bufferManager
operator|->
name|requestItems
argument_list|(
name|itemsForRequest
argument_list|)
expr_stmt|;
name|m_bufferManager
operator|->
name|endSharedBufferAction
argument_list|()
expr_stmt|;
name|processPendingItems
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertItems
name|void
name|QXcbSharedGraphicsCache
operator|::
name|insertItems
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|cacheId
parameter_list|,
specifier|const
name|QVector
argument_list|<
name|quint32
argument_list|>
modifier|&
name|itemIds
parameter_list|,
specifier|const
name|QVector
argument_list|<
name|QImage
argument_list|>
modifier|&
name|items
parameter_list|)
block|{
name|m_bufferManager
operator|->
name|beginSharedBufferAction
argument_list|(
name|cacheId
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|quint32
argument_list|>
name|itemsForRequest
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
name|itemIds
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QImage
name|image
init|=
name|items
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|m_bufferManager
operator|->
name|insertItem
argument_list|(
name|itemIds
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|image
operator|.
name|bits
argument_list|()
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|image
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|itemsForRequest
operator|.
name|insert
argument_list|(
name|itemIds
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// ### To avoid loops, we could check missing items here and notify the client
name|m_bufferManager
operator|->
name|requestItems
argument_list|(
name|itemsForRequest
argument_list|)
expr_stmt|;
name|m_bufferManager
operator|->
name|endSharedBufferAction
argument_list|()
expr_stmt|;
name|processPendingItems
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ensureCacheInitialized
name|void
name|QXcbSharedGraphicsCache
operator|::
name|ensureCacheInitialized
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|cacheId
parameter_list|,
name|BufferType
name|bufferType
parameter_list|,
name|PixelFormat
name|pixelFormat
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|cacheId
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|bufferType
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|pixelFormat
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|releaseItems
name|void
name|QXcbSharedGraphicsCache
operator|::
name|releaseItems
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|cacheId
parameter_list|,
specifier|const
name|QVector
argument_list|<
name|quint32
argument_list|>
modifier|&
name|itemIds
parameter_list|)
block|{
name|m_bufferManager
operator|->
name|beginSharedBufferAction
argument_list|(
name|cacheId
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|quint32
argument_list|>
name|itemsToRelease
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
name|itemIds
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|itemsToRelease
operator|.
name|insert
argument_list|(
name|itemIds
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|m_bufferManager
operator|->
name|releaseItems
argument_list|(
name|itemsToRelease
argument_list|)
expr_stmt|;
name|m_bufferManager
operator|->
name|endSharedBufferAction
argument_list|()
expr_stmt|;
name|processPendingItems
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|serializeBuffer
name|void
name|QXcbSharedGraphicsCache
operator|::
name|serializeBuffer
parameter_list|(
name|void
modifier|*
name|bufferId
parameter_list|,
name|QByteArray
modifier|*
name|serializedData
parameter_list|,
name|int
modifier|*
name|fileDescriptor
parameter_list|)
specifier|const
block|{
name|QXcbSharedBufferManager
operator|::
name|Buffer
modifier|*
name|buffer
init|=
cast|reinterpret_cast
argument_list|<
name|QXcbSharedBufferManager
operator|::
name|Buffer
operator|*
argument_list|>
argument_list|(
name|bufferId
argument_list|)
decl_stmt|;
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|int
argument_list|>
name|bufferName
init|=
name|m_bufferManager
operator|->
name|serializeBuffer
argument_list|(
name|buffer
operator|->
name|buffer
argument_list|)
decl_stmt|;
operator|*
name|serializedData
operator|=
name|bufferName
operator|.
name|first
expr_stmt|;
operator|*
name|fileDescriptor
operator|=
name|bufferName
operator|.
name|second
expr_stmt|;
block|}
end_function
begin_function
DECL|function|textureIdForBuffer
name|GLuint
name|QXcbSharedGraphicsCache
operator|::
name|textureIdForBuffer
parameter_list|(
name|void
modifier|*
name|bufferId
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|SHAREDGRAPHICSCACHE_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|"QXcbSharedGraphicsCache::textureIdForBuffer"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QXcbSharedBufferManager
operator|::
name|Buffer
modifier|*
name|buffer
init|=
cast|reinterpret_cast
argument_list|<
name|QXcbSharedBufferManager
operator|::
name|Buffer
operator|*
argument_list|>
argument_list|(
name|bufferId
argument_list|)
decl_stmt|;
if|if
condition|(
name|buffer
operator|->
name|textureId
operator|==
literal|0
condition|)
block|{
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|buffer
operator|->
name|textureId
argument_list|)
expr_stmt|;
if|if
condition|(
name|buffer
operator|->
name|textureId
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QXcbSharedGraphicsCache::textureIdForBuffer: Failed to generate texture (gl error: 0x%x)"
argument_list|,
name|glGetError
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|buffer
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_LINEAR
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_LINEAR
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
block|}
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|buffer
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_ALPHA
argument_list|,
name|buffer
operator|->
name|width
argument_list|,
name|buffer
operator|->
name|height
argument_list|,
literal|0
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|buffer
operator|->
name|buffer
operator|->
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|buffer
operator|->
name|textureId
return|;
block|}
end_function
begin_function
DECL|function|referenceBuffer
name|void
name|QXcbSharedGraphicsCache
operator|::
name|referenceBuffer
parameter_list|(
name|void
modifier|*
name|bufferId
parameter_list|)
block|{
name|QXcbSharedBufferManager
operator|::
name|Buffer
modifier|*
name|buffer
init|=
cast|reinterpret_cast
argument_list|<
name|QXcbSharedBufferManager
operator|::
name|Buffer
operator|*
argument_list|>
argument_list|(
name|bufferId
argument_list|)
decl_stmt|;
name|buffer
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_function
begin_function
DECL|function|dereferenceBuffer
name|bool
name|QXcbSharedGraphicsCache
operator|::
name|dereferenceBuffer
parameter_list|(
name|void
modifier|*
name|bufferId
parameter_list|)
block|{
name|QXcbSharedBufferManager
operator|::
name|Buffer
modifier|*
name|buffer
init|=
cast|reinterpret_cast
argument_list|<
name|QXcbSharedBufferManager
operator|::
name|Buffer
operator|*
argument_list|>
argument_list|(
name|bufferId
argument_list|)
decl_stmt|;
if|if
condition|(
name|buffer
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|buffer
operator|->
name|textureId
operator|!=
literal|0
condition|)
block|{
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|buffer
operator|->
name|textureId
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|textureId
operator|=
literal|0
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|processPendingItems
name|void
name|QXcbSharedGraphicsCache
operator|::
name|processPendingItems
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|SHAREDGRAPHICSCACHE_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|"QXcbSharedGraphicsCache::processPendingItems"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|{
name|QXcbSharedBufferManager
operator|::
name|PendingItemIds
name|pendingMissingItems
init|=
name|m_bufferManager
operator|->
name|pendingItemsMissing
argument_list|()
decl_stmt|;
name|QXcbSharedBufferManager
operator|::
name|PendingItemIds
operator|::
name|const_iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|pendingMissingItems
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|pendingMissingItems
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QVector
argument_list|<
name|quint32
argument_list|>
name|missingItems
decl_stmt|;
specifier|const
name|QSet
argument_list|<
name|quint32
argument_list|>
modifier|&
name|items
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|QSet
argument_list|<
name|quint32
argument_list|>
operator|::
name|const_iterator
name|itemIt
decl_stmt|;
for|for
control|(
name|itemIt
operator|=
name|items
operator|.
name|constBegin
argument_list|()
init|;
name|itemIt
operator|!=
name|items
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|itemIt
control|)
name|missingItems
operator|.
name|append
argument_list|(
operator|*
name|itemIt
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SHAREDGRAPHICSCACHE_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|"QXcbSharedGraphicsCache::processPendingItems: %d missing items"
argument_list|,
name|missingItems
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|missingItems
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|itemsMissing
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|,
name|missingItems
argument_list|)
emit|;
block|}
block|}
block|{
name|QXcbSharedBufferManager
operator|::
name|PendingItemIds
name|pendingInvalidatedItems
init|=
name|m_bufferManager
operator|->
name|pendingItemsInvalidated
argument_list|()
decl_stmt|;
name|QXcbSharedBufferManager
operator|::
name|PendingItemIds
operator|::
name|const_iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|pendingInvalidatedItems
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|pendingInvalidatedItems
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QVector
argument_list|<
name|quint32
argument_list|>
name|invalidatedItems
decl_stmt|;
specifier|const
name|QSet
argument_list|<
name|quint32
argument_list|>
modifier|&
name|items
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|QSet
argument_list|<
name|quint32
argument_list|>
operator|::
name|const_iterator
name|itemIt
decl_stmt|;
for|for
control|(
name|itemIt
operator|=
name|items
operator|.
name|constBegin
argument_list|()
init|;
name|itemIt
operator|!=
name|items
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|itemIt
control|)
name|invalidatedItems
operator|.
name|append
argument_list|(
operator|*
name|itemIt
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SHAREDGRAPHICSCACHE_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|"QXcbSharedGraphicsCache::processPendingItems: %d invalidated items"
argument_list|,
name|invalidatedItems
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|invalidatedItems
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|itemsInvalidated
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|,
name|invalidatedItems
argument_list|)
emit|;
block|}
block|}
block|{
name|QXcbSharedBufferManager
operator|::
name|PendingItemIds
name|pendingReadyItems
init|=
name|m_bufferManager
operator|->
name|pendingItemsReady
argument_list|()
decl_stmt|;
name|QXcbSharedBufferManager
operator|::
name|PendingItemIds
operator|::
name|const_iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|pendingReadyItems
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|pendingReadyItems
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QHash
argument_list|<
name|QXcbSharedBufferManager
operator|::
name|Buffer
operator|*
argument_list|,
name|ReadyItem
argument_list|>
name|readyItemsForBuffer
decl_stmt|;
specifier|const
name|QSet
argument_list|<
name|quint32
argument_list|>
modifier|&
name|items
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|QByteArray
name|cacheId
init|=
name|it
operator|.
name|key
argument_list|()
decl_stmt|;
name|QSet
argument_list|<
name|quint32
argument_list|>
operator|::
name|const_iterator
name|itemIt
decl_stmt|;
for|for
control|(
name|itemIt
operator|=
name|items
operator|.
name|constBegin
argument_list|()
init|;
name|itemIt
operator|!=
name|items
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|itemIt
control|)
block|{
name|QXcbSharedBufferManager
operator|::
name|Buffer
modifier|*
name|buffer
decl_stmt|;
name|int
name|x
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|y
init|=
operator|-
literal|1
decl_stmt|;
name|m_bufferManager
operator|->
name|getBufferForItem
argument_list|(
name|cacheId
argument_list|,
operator|*
name|itemIt
argument_list|,
operator|&
name|buffer
argument_list|,
operator|&
name|x
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
name|readyItemsForBuffer
index|[
name|buffer
index|]
operator|.
name|itemIds
operator|.
name|append
argument_list|(
operator|*
name|itemIt
argument_list|)
expr_stmt|;
name|readyItemsForBuffer
index|[
name|buffer
index|]
operator|.
name|positions
operator|.
name|append
argument_list|(
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QHash
argument_list|<
name|QXcbSharedBufferManager
operator|::
name|Buffer
operator|*
argument_list|,
name|ReadyItem
argument_list|>
operator|::
name|iterator
name|readyItemIt
init|=
name|readyItemsForBuffer
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|readyItemIt
operator|!=
name|readyItemsForBuffer
operator|.
name|end
argument_list|()
condition|)
block|{
name|QXcbSharedBufferManager
operator|::
name|Buffer
modifier|*
name|buffer
init|=
name|readyItemIt
operator|.
name|key
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|readyItemIt
operator|.
name|value
argument_list|()
operator|.
name|itemIds
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|SHAREDGRAPHICSCACHE_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|"QXcbSharedGraphicsCache::processPendingItems: %d ready items"
argument_list|,
name|readyItemIt
operator|.
name|value
argument_list|()
operator|.
name|itemIds
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
emit|emit
name|itemsAvailable
argument_list|(
name|cacheId
argument_list|,
name|buffer
argument_list|,
name|QSize
argument_list|(
name|buffer
operator|->
name|width
argument_list|,
name|buffer
operator|->
name|height
argument_list|)
argument_list|,
name|readyItemIt
operator|.
name|value
argument_list|()
operator|.
name|itemIds
argument_list|,
name|readyItemIt
operator|.
name|value
argument_list|()
operator|.
name|positions
argument_list|)
emit|;
block|}
operator|++
name|readyItemIt
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_USE_XCB_SHARED_GRAPHICS_CACHE
end_comment
end_unit
