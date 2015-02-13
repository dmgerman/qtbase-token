begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|STARRATING_H
end_ifndef
begin_define
DECL|macro|STARRATING_H
define|#
directive|define
name|STARRATING_H
end_define
begin_include
include|#
directive|include
file|<QMetaType>
end_include
begin_include
include|#
directive|include
file|<QPointF>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|StarRating
block|{
name|public
label|:
enum|enum
name|EditMode
block|{
name|Editable
block|,
name|ReadOnly
block|}
enum|;
name|explicit
name|StarRating
parameter_list|(
name|int
name|starCount
init|=
literal|1
parameter_list|,
name|int
name|maxStarCount
init|=
literal|5
parameter_list|)
function_decl|;
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
specifier|const
name|QPalette
operator|&
name|palette
argument_list|,
name|EditMode
name|mode
argument_list|)
decl|const
decl_stmt|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
expr_stmt|;
name|int
name|starCount
argument_list|()
specifier|const
block|{
return|return
name|myStarCount
return|;
block|}
name|int
name|maxStarCount
argument_list|()
specifier|const
block|{
return|return
name|myMaxStarCount
return|;
block|}
name|void
name|setStarCount
parameter_list|(
name|int
name|starCount
parameter_list|)
block|{
name|myStarCount
operator|=
name|starCount
expr_stmt|;
block|}
name|void
name|setMaxStarCount
parameter_list|(
name|int
name|maxStarCount
parameter_list|)
block|{
name|myMaxStarCount
operator|=
name|maxStarCount
expr_stmt|;
block|}
name|private
label|:
name|QPolygonF
name|starPolygon
decl_stmt|;
name|QPolygonF
name|diamondPolygon
decl_stmt|;
name|int
name|myStarCount
decl_stmt|;
name|int
name|myMaxStarCount
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|StarRating
argument_list|)
end_macro
begin_comment
comment|//! [1]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
