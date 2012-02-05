begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SVGALIBPAINTENGINE_H
end_ifndef
begin_define
DECL|macro|SVGALIBPAINTENGINE_H
define|#
directive|define
name|SVGALIBPAINTENGINE_H
end_define
begin_comment
comment|//! [0]
end_comment
begin_include
include|#
directive|include
file|<private/qpaintengine_raster_p.h>
end_include
begin_decl_stmt
name|class
name|SvgalibPaintEngine
range|:
name|public
name|QRasterPaintEngine
block|{
name|public
operator|:
name|SvgalibPaintEngine
argument_list|(
name|QPaintDevice
operator|*
name|device
argument_list|)
block|;
operator|~
name|SvgalibPaintEngine
argument_list|()
block|;
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|device
argument_list|)
block|;
name|bool
name|end
argument_list|()
block|;
name|void
name|updateState
argument_list|()
block|;
name|void
name|drawRects
argument_list|(
argument|const QRect *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|private
operator|:
name|void
name|setClip
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|void
name|updateClip
argument_list|()
block|;
name|QPen
name|pen
block|;
name|bool
name|simplePen
block|;
name|QBrush
name|brush
block|;
name|bool
name|simpleBrush
block|;
name|QTransform
name|matrix
block|;
name|bool
name|simpleMatrix
block|;
name|QRegion
name|clip
block|;
name|bool
name|clipEnabled
block|;
name|bool
name|simpleClip
block|;
name|bool
name|opaque
block|;
name|bool
name|aliased
block|;
name|bool
name|sourceOver
block|;
name|QPaintDevice
operator|*
name|device
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SVGALIBPAINTENGINE_H
end_comment
end_unit
