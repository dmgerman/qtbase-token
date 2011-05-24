begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenVG module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVGIMAGEPOOL_P_H
end_ifndef
begin_define
DECL|macro|QVGIMAGEPOOL_P_H
define|#
directive|define
name|QVGIMAGEPOOL_P_H
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
file|"qvg.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVGPixmapData
name|class
name|QVGPixmapData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVGImagePoolPrivate
name|class
name|QVGImagePoolPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENVG_EXPORT
name|QVGImagePool
block|{
name|public
label|:
name|QVGImagePool
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QVGImagePool
argument_list|()
expr_stmt|;
specifier|static
name|QVGImagePool
modifier|*
name|instance
parameter_list|()
function_decl|;
comment|// This function can be used from system-specific graphics system
comment|// plugins to alter the image allocation strategy.
specifier|static
name|void
name|setImagePool
parameter_list|(
name|QVGImagePool
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|// Create a new VGImage from the pool with the specified parameters
comment|// that is not associated with a pixmap.  The VGImage is returned to
comment|// the pool when releaseImage() is called.
comment|//
comment|// This function will call reclaimSpace() when vgCreateImage() fails.
comment|//
comment|// This function is typically called when allocating temporary
comment|// VGImage's for pixmap filters.  The "keepData" object will not
comment|// be reclaimed if reclaimSpace() needs to be called.
name|virtual
name|VGImage
name|createTemporaryImage
parameter_list|(
name|VGImageFormat
name|format
parameter_list|,
name|VGint
name|width
parameter_list|,
name|VGint
name|height
parameter_list|,
name|VGbitfield
name|allowedQuality
parameter_list|,
name|QVGPixmapData
modifier|*
name|keepData
init|=
literal|0
parameter_list|)
function_decl|;
comment|// Create a new VGImage with the specified parameters and associate
comment|// it with "data".  The QVGPixmapData will be notified when the
comment|// VGImage needs to be reclaimed by the pool.
comment|//
comment|// This function will call reclaimSpace() when vgCreateImage() fails.
name|virtual
name|VGImage
name|createImageForPixmap
parameter_list|(
name|VGImageFormat
name|format
parameter_list|,
name|VGint
name|width
parameter_list|,
name|VGint
name|height
parameter_list|,
name|VGbitfield
name|allowedQuality
parameter_list|,
name|QVGPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Create a permanent VGImage with the specified parameters.
comment|// If there is insufficient space for the vgCreateImage call,
comment|// then this function will call reclaimSpace() and try again.
comment|//
comment|// The caller is responsible for calling vgDestroyImage()
comment|// when it no longer needs the VGImage, as the image is not
comment|// recorded in the image pool.
comment|//
comment|// This function is typically used for pattern brushes where
comment|// the OpenVG engine is responsible for managing the lifetime
comment|// of the VGImage, destroying it automatically when the brush
comment|// is no longer in use.
name|virtual
name|VGImage
name|createPermanentImage
parameter_list|(
name|VGImageFormat
name|format
parameter_list|,
name|VGint
name|width
parameter_list|,
name|VGint
name|height
parameter_list|,
name|VGbitfield
name|allowedQuality
parameter_list|)
function_decl|;
comment|// Release a VGImage that is no longer required.
name|virtual
name|void
name|releaseImage
parameter_list|(
name|QVGPixmapData
modifier|*
name|data
parameter_list|,
name|VGImage
name|image
parameter_list|)
function_decl|;
comment|// Notify the pool that a QVGPixmapData object is using
comment|// an image again.  This allows the pool to move the image
comment|// within a least-recently-used list of QVGPixmapData objects.
name|virtual
name|void
name|useImage
parameter_list|(
name|QVGPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Notify the pool that the VGImage's associated with a
comment|// QVGPixmapData are being detached from the pool.  The caller
comment|// will become responsible for calling vgDestroyImage().
name|virtual
name|void
name|detachImage
parameter_list|(
name|QVGPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Reclaim space for an image allocation with the specified parameters.
comment|// Returns true if space was reclaimed, or false if there is no
comment|// further space that can be reclaimed.  The "data" parameter
comment|// indicates the pixmap that is trying to obtain space which should
comment|// not itself be reclaimed.
name|virtual
name|bool
name|reclaimSpace
parameter_list|(
name|VGImageFormat
name|format
parameter_list|,
name|VGint
name|width
parameter_list|,
name|VGint
name|height
parameter_list|,
name|QVGPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Hibernate the image pool because the context is about to be
comment|// destroyed.  All VGImage's left in the pool should be released.
name|virtual
name|void
name|hibernate
parameter_list|()
function_decl|;
name|protected
label|:
comment|// Helper functions for managing the LRU list of QVGPixmapData objects.
name|void
name|moveToHeadOfLRU
parameter_list|(
name|QVGPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
name|removeFromLRU
parameter_list|(
name|QVGPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
name|QVGPixmapData
modifier|*
name|pixmapLRU
parameter_list|()
function_decl|;
name|private
label|:
name|QScopedPointer
operator|<
name|QVGImagePoolPrivate
operator|>
name|d_ptr
expr_stmt|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QVGImagePool
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QVGImagePool
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
