begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function_decl
name|U
name|function
parameter_list|(
specifier|const
name|T
modifier|&
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|scaled
name|QImage
name|scaled
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
return|return
name|image
operator|.
name|scaled
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|thumbnails
name|QFuture
argument_list|<
name|QImage
argument_list|>
name|thumbnails
init|=
name|QtConcurrent
operator|::
name|mapped
argument_list|(
name|images
argument_list|,
name|scaled
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function_decl
name|U
name|function
parameter_list|(
name|T
modifier|&
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|scale
name|void
name|scale
parameter_list|(
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|image
operator|=
name|image
operator|.
name|scaled
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|future
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
init|=
name|QtConcurrent
operator|::
name|map
argument_list|(
name|images
argument_list|,
name|scale
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
name|V
name|function
argument_list|(
name|T
operator|&
name|result
argument_list|,
specifier|const
name|U
operator|&
name|intermediate
argument_list|)
comment|//! [4]
comment|//! [5]
DECL|function|addToCollage
name|void
name|addToCollage
argument_list|(
name|QImage
operator|&
name|collage
argument_list|,
specifier|const
name|QImage
operator|&
name|thumbnail
argument_list|)
argument_list|{
name|QPainter
name|p
argument_list|(
operator|&
name|collage
argument_list|)
argument_list|;
specifier|static
name|QPoint
name|offset
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|;
name|p
operator|.
name|drawImage
argument_list|(
name|offset
argument_list|,
name|thumbnail
argument_list|)
argument_list|;
name|offset
operator|+=
operator|...
argument_list|; }
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|collage
name|QFuture
argument_list|<
name|QImage
argument_list|>
name|collage
init|=
name|QtConcurrent
operator|::
name|mappedReduced
argument_list|(
name|images
argument_list|,
name|scaled
argument_list|,
name|addToCollage
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|thumbnails
name|QFuture
argument_list|<
name|QImage
argument_list|>
name|thumbnails
init|=
name|QtConcurrent
operator|::
name|mapped
argument_list|(
name|images
operator|.
name|constBegin
argument_list|()
argument_list|,
name|images
operator|.
name|constEnd
argument_list|()
argument_list|,
name|scaled
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// map in-place only works on non-const iterators
end_comment
begin_decl_stmt
DECL|variable|future
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
init|=
name|QtConcurrent
operator|::
name|map
argument_list|(
name|images
operator|.
name|begin
argument_list|()
argument_list|,
name|images
operator|.
name|end
argument_list|()
argument_list|,
name|scale
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|collage
name|QFuture
argument_list|<
name|QImage
argument_list|>
name|collage
init|=
name|QtConcurrent
operator|::
name|mappedReduced
argument_list|(
name|images
operator|.
name|constBegin
argument_list|()
argument_list|,
name|images
operator|.
name|constEnd
argument_list|()
argument_list|,
name|scaled
argument_list|,
name|addToCollage
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_comment
comment|// each call blocks until the entire operation is finished
end_comment
begin_decl_stmt
DECL|variable|future
name|QList
argument_list|<
name|QImage
argument_list|>
name|future
init|=
name|QtConcurrent
operator|::
name|blockingMapped
argument_list|(
name|images
argument_list|,
name|scaled
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QtConcurrent
operator|::
name|blockingMap
argument_list|(
name|images
argument_list|,
name|scale
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|collage
name|QImage
name|collage
init|=
name|QtConcurrent
operator|::
name|blockingMappedReduced
argument_list|(
name|images
argument_list|,
name|scaled
argument_list|,
name|addToCollage
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|// squeeze all strings in a QStringList
end_comment
begin_decl_stmt
DECL|variable|strings
name|QStringList
name|strings
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|squeezedStrings
name|QFuture
argument_list|<
name|void
argument_list|>
name|squeezedStrings
init|=
name|QtConcurrent
operator|::
name|map
argument_list|(
name|strings
argument_list|,
operator|&
name|QString
operator|::
name|squeeze
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// swap the rgb values of all pixels on a list of images
end_comment
begin_decl_stmt
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|bgrImages
name|QFuture
argument_list|<
name|QImage
argument_list|>
name|bgrImages
init|=
name|QtConcurrent
operator|::
name|mapped
argument_list|(
name|images
argument_list|,
operator|&
name|QImage
operator|::
name|rgbSwapped
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// create a set of the lengths of all strings in a list
end_comment
begin_decl_stmt
DECL|variable|strings
name|QStringList
name|strings
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|wordLengths
name|QFuture
argument_list|<
name|QSet
argument_list|<
name|int
argument_list|>
argument_list|>
name|wordLengths
init|=
name|QtConcurrent
operator|::
name|mappedReduced
argument_list|(
name|string
argument_list|,
operator|&
name|QString
operator|::
name|length
argument_list|,
operator|&
name|QSet
argument_list|<
name|int
argument_list|>
operator|::
name|insert
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|// can mix normal functions and member functions with QtConcurrent::mappedReduced()
end_comment
begin_comment
comment|// compute the average length of a list of strings
end_comment
begin_function_decl
specifier|extern
name|void
name|computeAverage
parameter_list|(
name|int
modifier|&
name|average
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|strings
name|QStringList
name|strings
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|averageWordLength
name|QFuture
argument_list|<
name|int
argument_list|>
name|averageWordLength
init|=
name|QtConcurrent
operator|::
name|mappedReduced
argument_list|(
name|strings
argument_list|,
operator|&
name|QString
operator|::
name|length
argument_list|,
name|computeAverage
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// create a set of the color distribution of all images in a list
end_comment
begin_function_decl
specifier|extern
name|int
name|colorDistribution
parameter_list|(
specifier|const
name|QImage
modifier|&
name|string
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|totalColorDistribution
name|QFuture
argument_list|<
name|QSet
argument_list|<
name|int
argument_list|>
argument_list|>
name|totalColorDistribution
init|=
name|QtConcurrent
operator|::
name|mappedReduced
argument_list|(
name|images
argument_list|,
name|colorDistribution
argument_list|,
name|QSet
argument_list|<
name|int
argument_list|>
operator|::
name|insert
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function_decl
name|QImage
name|QImage
operator|::
name|scaledToWidth
parameter_list|(
name|int
name|width
parameter_list|,
name|Qt
operator|::
name|TransformationMode
parameter_list|)
specifier|const
function_decl|;
end_function_decl
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_macro
name|std
end_macro
begin_expr_stmt
operator|::
name|bind
operator|(
operator|&
name|QImage
operator|::
name|scaledToWidth
operator|,
literal|100
operator|,
name|Qt
operator|::
name|SmoothTransformation
operator|)
comment|//! [11]
comment|//! [12]
name|QImage
name|scaledToWith
argument_list|(
argument|const QImage&image
argument_list|)
comment|//! [12]
comment|//! [13]
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
operator|=
operator|...
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|thumbnails
name|QFuture
argument_list|<
name|QImage
argument_list|>
name|thumbnails
init|=
name|QtConcurrent
operator|::
name|mapped
argument_list|(
name|images
argument_list|,
name|std
operator|::
name|bind
argument_list|(
operator|&
name|QImage
operator|::
name|scaledToWidth
argument_list|,
literal|100
argument_list|,
name|Qt
operator|::
name|SmoothTransformation
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_struct
DECL|struct|Scaled
struct|struct
name|Scaled
block|{
DECL|function|Scaled
name|Scaled
parameter_list|(
name|int
name|size
parameter_list|)
member_init_list|:
name|m_size
argument_list|(
name|size
argument_list|)
block|{ }
DECL|typedef|result_type
typedef|typedef
name|QImage
name|result_type
typedef|;
DECL|function|operator ()
name|QImage
name|operator
name|()
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
return|return
name|image
operator|.
name|scaled
argument_list|(
name|m_size
argument_list|,
name|m_size
argument_list|)
return|;
block|}
DECL|member|m_size
name|int
name|m_size
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|images
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|thumbnails
name|QFuture
argument_list|<
name|QImage
argument_list|>
name|thumbnails
init|=
name|QtConcurrent
operator|::
name|mapped
argument_list|(
name|images
argument_list|,
name|Scaled
argument_list|(
literal|100
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [14]
end_comment
end_unit
