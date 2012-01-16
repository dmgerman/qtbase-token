begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qvolatileimage_p.h"
end_include
begin_include
include|#
directive|include
file|"qvolatileimagedata_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpaintengine_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qplatformpixmap_qpa.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QVolatileImagePaintEnginePrivate
class|class
name|QVolatileImagePaintEnginePrivate
super|:
specifier|public
name|QRasterPaintEnginePrivate
block|{
public|public:
DECL|function|QVolatileImagePaintEnginePrivate
name|QVolatileImagePaintEnginePrivate
parameter_list|()
block|{ }
DECL|member|img
name|QVolatileImage
modifier|*
name|img
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QVolatileImagePaintEngine
class|class
name|QVolatileImagePaintEngine
super|:
specifier|public
name|QRasterPaintEngine
block|{
name|Q_DECLARE_PRIVATE
parameter_list|(
name|QVolatileImagePaintEngine
parameter_list|)
specifier|public
private|:
name|QVolatileImagePaintEngine
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|,
name|QVolatileImage
modifier|*
name|img
parameter_list|)
constructor_decl|;
name|bool
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|)
function_decl|;
name|bool
name|end
parameter_list|()
function_decl|;
name|void
name|drawPixmap
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|)
function_decl|;
name|void
name|drawPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sr
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QVolatileImage
name|QVolatileImage
operator|::
name|QVolatileImage
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QVolatileImageData
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QVolatileImage
name|QVolatileImage
operator|::
name|QVolatileImage
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QVolatileImageData
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|format
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QVolatileImage
name|QVolatileImage
operator|::
name|QVolatileImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|sourceImage
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QVolatileImageData
argument_list|(
name|sourceImage
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QVolatileImage
name|QVolatileImage
operator|::
name|QVolatileImage
parameter_list|(
name|void
modifier|*
name|nativeImage
parameter_list|,
name|void
modifier|*
name|nativeMask
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QVolatileImageData
argument_list|(
name|nativeImage
argument_list|,
name|nativeMask
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|// Need non-inline, non-autogenerated copy ctor, dtor, op= to keep the
end_comment
begin_comment
comment|// fwd declared QSharedData working.
end_comment
begin_constructor
DECL|function|QVolatileImage
name|QVolatileImage
operator|::
name|QVolatileImage
parameter_list|(
specifier|const
name|QVolatileImage
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QVolatileImage
name|QVolatileImage
operator|::
name|~
name|QVolatileImage
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|operator =
name|QVolatileImage
modifier|&
name|QVolatileImage
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QVolatileImage
modifier|&
name|rhs
parameter_list|)
block|{
name|d
operator|=
name|rhs
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|isNull
name|bool
name|QVolatileImage
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|isNull
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QVolatileImage
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|format
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|width
name|int
name|QVolatileImage
operator|::
name|width
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|width
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|height
name|int
name|QVolatileImage
operator|::
name|height
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|height
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|bytesPerLine
name|int
name|QVolatileImage
operator|::
name|bytesPerLine
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|bytesPerLine
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|byteCount
name|int
name|QVolatileImage
operator|::
name|byteCount
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|byteCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QVolatileImage
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|depth
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|hasAlphaChannel
name|bool
name|QVolatileImage
operator|::
name|hasAlphaChannel
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|hasAlphaChannel
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|beginDataAccess
name|void
name|QVolatileImage
operator|::
name|beginDataAccess
parameter_list|()
specifier|const
block|{
name|d
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endDataAccess
name|void
name|QVolatileImage
operator|::
name|endDataAccess
parameter_list|(
name|bool
name|readOnly
parameter_list|)
specifier|const
block|{
name|d
operator|->
name|endDataAccess
argument_list|(
name|readOnly
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Access to pixel data via bits() or constBits() should be guarded by   begin/endDataAccess().  */
end_comment
begin_function
DECL|function|bits
name|uchar
modifier|*
name|QVolatileImage
operator|::
name|bits
parameter_list|()
block|{
return|return
name|d
operator|->
name|image
operator|.
name|bits
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|constBits
specifier|const
name|uchar
modifier|*
name|QVolatileImage
operator|::
name|constBits
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|image
operator|.
name|constBits
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|ensureFormat
name|bool
name|QVolatileImage
operator|::
name|ensureFormat
parameter_list|(
name|QImage
operator|::
name|Format
name|format
parameter_list|)
block|{
return|return
name|d
operator|->
name|ensureFormat
argument_list|(
name|format
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   This will always perform a copy of the pixel data.  */
end_comment
begin_function
DECL|function|toImage
name|QImage
name|QVolatileImage
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
name|d
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
name|QImage
name|newImage
init|=
name|d
operator|->
name|image
operator|.
name|copy
argument_list|()
decl_stmt|;
comment|// no sharing allowed
name|d
operator|->
name|endDataAccess
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
name|newImage
return|;
block|}
end_function
begin_comment
comment|/*!   Returns a reference to the image that is potentially using some native   buffer internally. Access to the image's pixel data should be guarded by   begin/endDataAccess(). Use it when there is a need for QImage APIs not provided   by this class. The returned QImage must never be shared or assigned to.   */
end_comment
begin_function
DECL|function|imageRef
name|QImage
modifier|&
name|QVolatileImage
operator|::
name|imageRef
parameter_list|()
comment|// non-const, in order to cause a detach
block|{
name|d
operator|->
name|ensureImage
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|image
return|;
block|}
end_function
begin_function
DECL|function|duplicateNativeImage
name|void
modifier|*
name|QVolatileImage
operator|::
name|duplicateNativeImage
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|duplicateNativeImage
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fill
name|void
name|QVolatileImage
operator|::
name|fill
parameter_list|(
name|uint
name|pixelValue
parameter_list|)
block|{
name|beginDataAccess
argument_list|()
expr_stmt|;
name|imageRef
argument_list|()
operator|.
name|fill
argument_list|(
name|pixelValue
argument_list|)
expr_stmt|;
name|endDataAccess
argument_list|()
expr_stmt|;
name|d
operator|->
name|ensureImage
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copyFrom
name|void
name|QVolatileImage
operator|::
name|copyFrom
parameter_list|(
name|QVolatileImage
modifier|*
name|source
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
name|source
operator|->
name|isNull
argument_list|()
condition|)
block|{
return|return;
block|}
name|QRect
name|r
init|=
name|rect
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|r
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|source
operator|->
name|width
argument_list|()
argument_list|,
name|source
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|source
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
name|QImage
modifier|&
name|srcImgRef
argument_list|(
name|source
operator|->
name|imageRef
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|srcbpl
init|=
name|srcImgRef
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
name|int
name|srcbpp
init|=
name|srcImgRef
operator|.
name|depth
argument_list|()
operator|/
literal|8
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|sptr
init|=
name|srcImgRef
operator|.
name|constBits
argument_list|()
operator|+
name|r
operator|.
name|y
argument_list|()
operator|*
name|srcbpl
decl_stmt|;
name|beginDataAccess
argument_list|()
expr_stmt|;
name|QImage
modifier|&
name|dstImgRef
argument_list|(
name|imageRef
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|dstbpl
init|=
name|dstImgRef
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
name|uchar
modifier|*
name|dptr
init|=
name|dstImgRef
operator|.
name|bits
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|r
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
name|qMemCopy
argument_list|(
name|dptr
argument_list|,
name|sptr
operator|+
name|r
operator|.
name|x
argument_list|()
operator|*
name|srcbpp
argument_list|,
name|r
operator|.
name|width
argument_list|()
operator|*
name|srcbpp
argument_list|)
expr_stmt|;
name|sptr
operator|+=
name|srcbpl
expr_stmt|;
name|dptr
operator|+=
name|dstbpl
expr_stmt|;
block|}
name|endDataAccess
argument_list|()
expr_stmt|;
name|source
operator|->
name|endDataAccess
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     To be called from the PlatformPixmap's paintEngine().   */
end_comment
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QVolatileImage
operator|::
name|paintEngine
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|pengine
condition|)
block|{
name|d
operator|->
name|pengine
operator|=
operator|new
name|QVolatileImagePaintEngine
argument_list|(
operator|&
name|imageRef
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
return|return
name|d
operator|->
name|pengine
return|;
block|}
end_function
begin_constructor
DECL|function|QVolatileImagePaintEngine
name|QVolatileImagePaintEngine
operator|::
name|QVolatileImagePaintEngine
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|,
name|QVolatileImage
modifier|*
name|img
parameter_list|)
member_init_list|:
name|QRasterPaintEngine
argument_list|(
operator|*
operator|(
operator|new
name|QVolatileImagePaintEnginePrivate
operator|)
argument_list|,
name|device
argument_list|)
block|{
name|Q_D
argument_list|(
name|QVolatileImagePaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|img
operator|=
name|img
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|begin
name|bool
name|QVolatileImagePaintEngine
operator|::
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QVolatileImagePaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|img
operator|->
name|beginDataAccess
argument_list|()
expr_stmt|;
return|return
name|QRasterPaintEngine
operator|::
name|begin
argument_list|(
name|device
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|end
name|bool
name|QVolatileImagePaintEngine
operator|::
name|end
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QVolatileImagePaintEngine
argument_list|)
expr_stmt|;
name|bool
name|ret
init|=
name|QRasterPaintEngine
operator|::
name|end
argument_list|()
decl_stmt|;
name|d
operator|->
name|img
operator|->
name|endDataAccess
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|// For non-RasterClass pixmaps drawPixmap() would call toImage() which is slow in
end_comment
begin_comment
comment|// our case. Therefore drawPixmap() is rerouted to drawImage().
end_comment
begin_function
DECL|function|drawPixmap
name|void
name|QVolatileImagePaintEngine
operator|::
name|drawPixmap
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|)
block|{
name|QRasterPaintEngine
operator|::
name|drawPixmap
argument_list|(
name|p
argument_list|,
name|pm
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawPixmap
name|void
name|QVolatileImagePaintEngine
operator|::
name|drawPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sr
parameter_list|)
block|{
name|QRasterPaintEngine
operator|::
name|drawPixmap
argument_list|(
name|r
argument_list|,
name|pm
argument_list|,
name|sr
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
