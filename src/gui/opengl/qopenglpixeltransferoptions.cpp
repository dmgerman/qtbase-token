begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglpixeltransferoptions.h"
end_include
begin_include
include|#
directive|include
file|<QSharedData>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!  * \class QOpenGLPixelTransferOptions  *  * \brief The QOpenGLPixelTransferOptions class describes the pixel storage  * modes that affect the unpacking of pixels during texture upload.  */
end_comment
begin_comment
comment|/*!  * \fn QOpenGLPixelTransferOptions& QOpenGLPixelTransferOptions::operator=(QOpenGLPixelTransferOptions&&other)  * \internal  */
end_comment
begin_comment
comment|/*!  * \fn void QOpenGLPixelTransferOptions::swap(QOpenGLPixelTransferOptions&other)  * \internal  */
end_comment
begin_class
DECL|class|QOpenGLPixelTransferOptionsData
class|class
name|QOpenGLPixelTransferOptionsData
super|:
specifier|public
name|QSharedData
block|{
public|public:
DECL|function|QOpenGLPixelTransferOptionsData
name|QOpenGLPixelTransferOptionsData
parameter_list|()
member_init_list|:
name|alignment
argument_list|(
literal|4
argument_list|)
member_init_list|,
name|skipImages
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|skipRows
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|skipPixels
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|imageHeight
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|rowLength
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|lsbFirst
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|swapBytes
argument_list|(
literal|false
argument_list|)
block|{}
DECL|member|alignment
name|int
name|alignment
decl_stmt|;
DECL|member|skipImages
name|int
name|skipImages
decl_stmt|;
DECL|member|skipRows
name|int
name|skipRows
decl_stmt|;
DECL|member|skipPixels
name|int
name|skipPixels
decl_stmt|;
DECL|member|imageHeight
name|int
name|imageHeight
decl_stmt|;
DECL|member|rowLength
name|int
name|rowLength
decl_stmt|;
DECL|member|lsbFirst
name|bool
name|lsbFirst
decl_stmt|;
DECL|member|swapBytes
name|bool
name|swapBytes
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!  * Constructs a new QOpenGLPixelTransferOptions instance with the default settings.  */
end_comment
begin_constructor
DECL|function|QOpenGLPixelTransferOptions
name|QOpenGLPixelTransferOptions
operator|::
name|QOpenGLPixelTransferOptions
parameter_list|()
member_init_list|:
name|data
argument_list|(
operator|new
name|QOpenGLPixelTransferOptionsData
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!  * \internal  */
end_comment
begin_constructor
DECL|function|QOpenGLPixelTransferOptions
name|QOpenGLPixelTransferOptions
operator|::
name|QOpenGLPixelTransferOptions
parameter_list|(
specifier|const
name|QOpenGLPixelTransferOptions
modifier|&
name|rhs
parameter_list|)
member_init_list|:
name|data
argument_list|(
name|rhs
operator|.
name|data
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!  * \internal  */
end_comment
begin_function
DECL|function|operator =
name|QOpenGLPixelTransferOptions
modifier|&
name|QOpenGLPixelTransferOptions
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QOpenGLPixelTransferOptions
modifier|&
name|rhs
parameter_list|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
name|data
operator|.
name|operator
name|=
parameter_list|(
name|rhs
operator|.
name|data
parameter_list|)
function_decl|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!  * Destructor.  */
end_comment
begin_destructor
DECL|function|~QOpenGLPixelTransferOptions
name|QOpenGLPixelTransferOptions
operator|::
name|~
name|QOpenGLPixelTransferOptions
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!  * Sets the \a alignment requirements for each pixel row. Corresponds to \c GL_UNPACK_ALIGNMENT.  * The default value is 4, as specified by OpenGL.  */
end_comment
begin_function
DECL|function|setAlignment
name|void
name|QOpenGLPixelTransferOptions
operator|::
name|setAlignment
parameter_list|(
name|int
name|alignment
parameter_list|)
block|{
name|data
operator|->
name|alignment
operator|=
name|alignment
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \return the current alignment requirement for each pixel row.  */
end_comment
begin_function
DECL|function|alignment
name|int
name|QOpenGLPixelTransferOptions
operator|::
name|alignment
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|->
name|alignment
return|;
block|}
end_function
begin_comment
comment|/*!  * Sets the number of images that are skipped to \a skipImages.  * Corresponds to \c GL_UNPACK_SKIP_IMAGES. Equivalent to incrementing the pointer  * passed to QOpenGLTexture::setData(). The default value is 0.  */
end_comment
begin_function
DECL|function|setSkipImages
name|void
name|QOpenGLPixelTransferOptions
operator|::
name|setSkipImages
parameter_list|(
name|int
name|skipImages
parameter_list|)
block|{
name|data
operator|->
name|skipImages
operator|=
name|skipImages
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \return the number of images that are skipped.  */
end_comment
begin_function
DECL|function|skipImages
name|int
name|QOpenGLPixelTransferOptions
operator|::
name|skipImages
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|->
name|skipImages
return|;
block|}
end_function
begin_comment
comment|/*!  * Sets the number of rows that are skipped to \a skipRows.  * Corresponds to \c GL_UNPACK_SKIP_ROWS. Equivalent to incrementing the pointer  * passed to QOpenGLTexture::setData(). The default value is 0.  */
end_comment
begin_function
DECL|function|setSkipRows
name|void
name|QOpenGLPixelTransferOptions
operator|::
name|setSkipRows
parameter_list|(
name|int
name|skipRows
parameter_list|)
block|{
name|data
operator|->
name|skipRows
operator|=
name|skipRows
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \return the number of rows that are skipped.  */
end_comment
begin_function
DECL|function|skipRows
name|int
name|QOpenGLPixelTransferOptions
operator|::
name|skipRows
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|->
name|skipRows
return|;
block|}
end_function
begin_comment
comment|/*!  * Sets the number of pixels that are skipped to \a skipPixels.  * Corresponds to \c GL_UNPACK_SKIP_PIXELS. Equivalent to incrementing the pointer  * passed to QOpenGLTexture::setData(). The default value is 0.  */
end_comment
begin_function
DECL|function|setSkipPixels
name|void
name|QOpenGLPixelTransferOptions
operator|::
name|setSkipPixels
parameter_list|(
name|int
name|skipPixels
parameter_list|)
block|{
name|data
operator|->
name|skipPixels
operator|=
name|skipPixels
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \return the number of pixels that are skipped.  */
end_comment
begin_function
DECL|function|skipPixels
name|int
name|QOpenGLPixelTransferOptions
operator|::
name|skipPixels
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|->
name|skipPixels
return|;
block|}
end_function
begin_comment
comment|/*!  * Sets the image height for 3D textures to \a imageHeight.  * Corresponds to \c GL_UNPACK_IMAGE_HEIGHT.  * The default value is 0.  */
end_comment
begin_function
DECL|function|setImageHeight
name|void
name|QOpenGLPixelTransferOptions
operator|::
name|setImageHeight
parameter_list|(
name|int
name|imageHeight
parameter_list|)
block|{
name|data
operator|->
name|imageHeight
operator|=
name|imageHeight
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \return the currently set image height.  */
end_comment
begin_function
DECL|function|imageHeight
name|int
name|QOpenGLPixelTransferOptions
operator|::
name|imageHeight
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|->
name|imageHeight
return|;
block|}
end_function
begin_comment
comment|/*!  * Sets the number of pixels in a row to \a rowLength.  * Corresponds to \c GL_UNPACK_ROW_LENGTH.  * The default value is 0.  */
end_comment
begin_function
DECL|function|setRowLength
name|void
name|QOpenGLPixelTransferOptions
operator|::
name|setRowLength
parameter_list|(
name|int
name|rowLength
parameter_list|)
block|{
name|data
operator|->
name|rowLength
operator|=
name|rowLength
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \return the currently set row length.  */
end_comment
begin_function
DECL|function|rowLength
name|int
name|QOpenGLPixelTransferOptions
operator|::
name|rowLength
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|->
name|rowLength
return|;
block|}
end_function
begin_comment
comment|/*!  * \a lsbFirst specifies if bits within a byte are ordered from least to most significat.  * The default value is \c false, meaning that the first bit in each byte is the  * most significant one. This is significant for bitmap data only.  * Corresponds to \c GL_UNPACK_LSB_FIRST.  */
end_comment
begin_function
DECL|function|setLeastSignificantByteFirst
name|void
name|QOpenGLPixelTransferOptions
operator|::
name|setLeastSignificantByteFirst
parameter_list|(
name|bool
name|lsbFirst
parameter_list|)
block|{
name|data
operator|->
name|lsbFirst
operator|=
name|lsbFirst
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \return \c true if bits within a byte are ordered from least to most significant.  */
end_comment
begin_function
DECL|function|isLeastSignificantBitFirst
name|bool
name|QOpenGLPixelTransferOptions
operator|::
name|isLeastSignificantBitFirst
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|->
name|lsbFirst
return|;
block|}
end_function
begin_comment
comment|/*!  * \a swapBytes specifies if the byte ordering for multibyte components is reversed.  * The default value is \c false.  * Corresponds to \c GL_UNPACK_SWAP_BYTES.  */
end_comment
begin_function
DECL|function|setSwapBytesEnabled
name|void
name|QOpenGLPixelTransferOptions
operator|::
name|setSwapBytesEnabled
parameter_list|(
name|bool
name|swapBytes
parameter_list|)
block|{
name|data
operator|->
name|swapBytes
operator|=
name|swapBytes
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \return \c true if the byte ordering for multibyte components is reversed.  */
end_comment
begin_function
DECL|function|isSwapBytesEnabled
name|bool
name|QOpenGLPixelTransferOptions
operator|::
name|isSwapBytesEnabled
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|->
name|swapBytes
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
