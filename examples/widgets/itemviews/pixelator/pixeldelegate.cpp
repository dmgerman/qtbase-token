begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"pixeldelegate.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|PixelDelegate
name|PixelDelegate
operator|::
name|PixelDelegate
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractItemDelegate
argument_list|(
name|parent
argument_list|)
block|{
name|pixelSize
operator|=
literal|12
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|paint
name|void
name|PixelDelegate
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
comment|//! [2]
if|if
condition|(
name|option
operator|.
name|state
operator|&
name|QStyle
operator|::
name|State_Selected
condition|)
name|painter
operator|->
name|fillRect
argument_list|(
name|option
operator|.
name|rect
argument_list|,
name|option
operator|.
name|palette
operator|.
name|highlight
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [3]
name|int
name|size
init|=
name|qMin
argument_list|(
name|option
operator|.
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|option
operator|.
name|rect
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
comment|//! [3] //! [4]
name|int
name|brightness
init|=
name|index
operator|.
name|model
argument_list|()
operator|->
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|double
name|radius
init|=
operator|(
name|size
operator|/
literal|2.0
operator|)
operator|-
operator|(
name|brightness
operator|/
literal|255.0
operator|*
name|size
operator|/
literal|2.0
operator|)
decl_stmt|;
if|if
condition|(
name|radius
operator|==
literal|0.0
condition|)
return|return;
comment|//! [4]
comment|//! [5]
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
comment|//! [5] //! [6]
name|painter
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|//! [6] //! [7]
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
comment|//! [7] //! [8]
if|if
condition|(
name|option
operator|.
name|state
operator|&
name|QStyle
operator|::
name|State_Selected
condition|)
comment|//! [8] //! [9]
name|painter
operator|->
name|setBrush
argument_list|(
name|option
operator|.
name|palette
operator|.
name|highlightedText
argument_list|()
argument_list|)
expr_stmt|;
else|else
comment|//! [2]
name|painter
operator|->
name|setBrush
argument_list|(
name|option
operator|.
name|palette
operator|.
name|text
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [9]
comment|//! [10]
name|painter
operator|->
name|drawEllipse
argument_list|(
name|QRectF
argument_list|(
name|option
operator|.
name|rect
operator|.
name|x
argument_list|()
operator|+
name|option
operator|.
name|rect
operator|.
name|width
argument_list|()
operator|/
literal|2
operator|-
name|radius
argument_list|,
name|option
operator|.
name|rect
operator|.
name|y
argument_list|()
operator|+
name|option
operator|.
name|rect
operator|.
name|height
argument_list|()
operator|/
literal|2
operator|-
name|radius
argument_list|,
literal|2
operator|*
name|radius
argument_list|,
literal|2
operator|*
name|radius
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|PixelDelegate
operator|::
name|sizeHint
parameter_list|(
specifier|const
name|QStyleOptionViewItem
modifier|&
comment|/* option */
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
comment|/* index */
parameter_list|)
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|pixelSize
argument_list|,
name|pixelSize
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|setPixelSize
name|void
name|PixelDelegate
operator|::
name|setPixelSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|pixelSize
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
end_unit
