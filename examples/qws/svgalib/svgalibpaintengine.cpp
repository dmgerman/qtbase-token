begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"svgalibpaintengine.h"
end_include
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_include
include|#
directive|include
file|<vga.h>
end_include
begin_include
include|#
directive|include
file|<vgagl.h>
end_include
begin_constructor
DECL|function|SvgalibPaintEngine
name|SvgalibPaintEngine
operator|::
name|SvgalibPaintEngine
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|)
member_init_list|:
name|QRasterPaintEngine
argument_list|(
name|device
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~SvgalibPaintEngine
name|SvgalibPaintEngine
operator|::
name|~
name|SvgalibPaintEngine
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|begin
name|bool
name|SvgalibPaintEngine
operator|::
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|dev
parameter_list|)
block|{
name|device
operator|=
name|dev
expr_stmt|;
name|pen
operator|=
name|Qt
operator|::
name|NoPen
expr_stmt|;
name|simplePen
operator|=
literal|true
expr_stmt|;
name|brush
operator|=
name|Qt
operator|::
name|NoBrush
expr_stmt|;
name|simpleBrush
operator|=
literal|true
expr_stmt|;
name|matrix
operator|=
name|QTransform
argument_list|()
expr_stmt|;
name|simpleMatrix
operator|=
literal|true
expr_stmt|;
name|setClip
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|device
operator|->
name|width
argument_list|()
argument_list|,
name|device
operator|->
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|opaque
operator|=
literal|true
expr_stmt|;
name|aliased
operator|=
literal|true
expr_stmt|;
name|sourceOver
operator|=
literal|true
expr_stmt|;
return|return
name|QRasterPaintEngine
operator|::
name|begin
argument_list|(
name|dev
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|end
name|bool
name|SvgalibPaintEngine
operator|::
name|end
parameter_list|()
block|{
name|gl_setclippingwindow
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|device
operator|->
name|width
argument_list|()
operator|-
literal|1
argument_list|,
name|device
operator|->
name|height
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|QRasterPaintEngine
operator|::
name|end
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|updateState
name|void
name|SvgalibPaintEngine
operator|::
name|updateState
parameter_list|()
block|{
name|QRasterPaintEngineState
modifier|*
name|s
init|=
name|state
argument_list|()
decl_stmt|;
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyTransform
condition|)
block|{
name|matrix
operator|=
name|s
operator|->
name|matrix
expr_stmt|;
name|simpleMatrix
operator|=
operator|(
name|matrix
operator|.
name|m12
argument_list|()
operator|==
literal|0
operator|&&
name|matrix
operator|.
name|m21
argument_list|()
operator|==
literal|0
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyPen
condition|)
block|{
name|pen
operator|=
name|s
operator|->
name|pen
expr_stmt|;
name|simplePen
operator|=
operator|(
name|pen
operator|.
name|width
argument_list|()
operator|==
literal|0
operator|||
name|pen
operator|.
name|widthF
argument_list|()
operator|<=
literal|1
operator|)
operator|&&
operator|(
name|pen
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|NoPen
operator|||
name|pen
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|SolidLine
operator|)
operator|&&
operator|(
name|pen
operator|.
name|color
argument_list|()
operator|.
name|alpha
argument_list|()
operator|==
literal|255
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyBrush
condition|)
block|{
name|brush
operator|=
name|s
operator|->
name|brush
expr_stmt|;
name|simpleBrush
operator|=
operator|(
name|brush
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|SolidPattern
operator|||
name|brush
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|NoBrush
operator|)
operator|&&
operator|(
name|brush
operator|.
name|color
argument_list|()
operator|.
name|alpha
argument_list|()
operator|==
literal|255
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyClipRegion
condition|)
name|setClip
argument_list|(
name|s
operator|->
name|clipRegion
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyClipEnabled
condition|)
block|{
name|clipEnabled
operator|=
name|s
operator|->
name|isClipEnabled
argument_list|()
expr_stmt|;
name|updateClip
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyClipPath
condition|)
block|{
name|setClip
argument_list|(
name|QRegion
argument_list|()
argument_list|)
expr_stmt|;
name|simpleClip
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyCompositionMode
condition|)
block|{
specifier|const
name|QPainter
operator|::
name|CompositionMode
name|m
init|=
name|s
operator|->
name|composition_mode
decl_stmt|;
name|sourceOver
operator|=
operator|(
name|m
operator|==
name|QPainter
operator|::
name|CompositionMode_SourceOver
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyOpacity
condition|)
name|opaque
operator|=
operator|(
name|s
operator|->
name|opacity
operator|==
literal|256
operator|)
expr_stmt|;
if|if
condition|(
name|s
operator|->
name|dirty
operator|&
name|DirtyHints
condition|)
name|aliased
operator|=
operator|!
operator|(
name|s
operator|->
name|flags
operator|.
name|antialiased
operator|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|setClip
name|void
name|SvgalibPaintEngine
operator|::
name|setClip
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
if|if
condition|(
name|region
operator|.
name|isEmpty
argument_list|()
condition|)
name|clip
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|device
operator|->
name|width
argument_list|()
argument_list|,
name|device
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|clip
operator|=
name|matrix
operator|.
name|map
argument_list|(
name|region
argument_list|)
operator|&
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|device
operator|->
name|width
argument_list|()
argument_list|,
name|device
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|clipEnabled
operator|=
literal|true
expr_stmt|;
name|updateClip
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|updateClip
name|void
name|SvgalibPaintEngine
operator|::
name|updateClip
parameter_list|()
block|{
name|QRegion
name|clipRegion
init|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|device
operator|->
name|width
argument_list|()
argument_list|,
name|device
operator|->
name|height
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|systemClip
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|clipRegion
operator|&=
name|systemClip
argument_list|()
expr_stmt|;
if|if
condition|(
name|clipEnabled
condition|)
name|clipRegion
operator|&=
name|clip
expr_stmt|;
name|simpleClip
operator|=
operator|(
name|clipRegion
operator|.
name|rects
argument_list|()
operator|.
name|size
argument_list|()
operator|<=
literal|1
operator|)
expr_stmt|;
specifier|const
name|QRect
name|r
init|=
name|clipRegion
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|gl_setclippingwindow
argument_list|(
name|r
operator|.
name|left
argument_list|()
argument_list|,
name|r
operator|.
name|top
argument_list|()
argument_list|,
name|r
operator|.
name|x
argument_list|()
operator|+
name|r
operator|.
name|width
argument_list|()
argument_list|,
name|r
operator|.
name|y
argument_list|()
operator|+
name|r
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|drawRects
name|void
name|SvgalibPaintEngine
operator|::
name|drawRects
parameter_list|(
specifier|const
name|QRect
modifier|*
name|rects
parameter_list|,
name|int
name|rectCount
parameter_list|)
block|{
specifier|const
name|bool
name|canAccelerate
init|=
name|simplePen
operator|&&
name|simpleBrush
operator|&&
name|simpleMatrix
operator|&&
name|simpleClip
operator|&&
name|opaque
operator|&&
name|aliased
operator|&&
name|sourceOver
decl_stmt|;
if|if
condition|(
operator|!
name|canAccelerate
condition|)
block|{
name|QRasterPaintEngine
operator|::
name|drawRects
argument_list|(
name|rects
argument_list|,
name|rectCount
argument_list|)
expr_stmt|;
return|return;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rectCount
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QRect
name|r
init|=
name|matrix
operator|.
name|mapRect
argument_list|(
name|rects
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|brush
operator|!=
name|Qt
operator|::
name|NoBrush
condition|)
block|{
name|gl_fillbox
argument_list|(
name|r
operator|.
name|left
argument_list|()
argument_list|,
name|r
operator|.
name|top
argument_list|()
argument_list|,
name|r
operator|.
name|width
argument_list|()
argument_list|,
name|r
operator|.
name|height
argument_list|()
argument_list|,
name|brush
operator|.
name|color
argument_list|()
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pen
operator|!=
name|Qt
operator|::
name|NoPen
condition|)
block|{
specifier|const
name|int
name|c
init|=
name|pen
operator|.
name|color
argument_list|()
operator|.
name|rgba
argument_list|()
decl_stmt|;
name|gl_hline
argument_list|(
name|r
operator|.
name|left
argument_list|()
argument_list|,
name|r
operator|.
name|top
argument_list|()
argument_list|,
name|r
operator|.
name|right
argument_list|()
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|gl_hline
argument_list|(
name|r
operator|.
name|left
argument_list|()
argument_list|,
name|r
operator|.
name|bottom
argument_list|()
argument_list|,
name|r
operator|.
name|right
argument_list|()
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|gl_line
argument_list|(
name|r
operator|.
name|left
argument_list|()
argument_list|,
name|r
operator|.
name|top
argument_list|()
argument_list|,
name|r
operator|.
name|left
argument_list|()
argument_list|,
name|r
operator|.
name|bottom
argument_list|()
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|gl_line
argument_list|(
name|r
operator|.
name|right
argument_list|()
argument_list|,
name|r
operator|.
name|top
argument_list|()
argument_list|,
name|r
operator|.
name|right
argument_list|()
argument_list|,
name|r
operator|.
name|bottom
argument_list|()
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
