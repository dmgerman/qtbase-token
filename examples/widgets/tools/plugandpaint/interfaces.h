begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|INTERFACES_H
end_ifndef
begin_define
DECL|macro|INTERFACES_H
define|#
directive|define
name|INTERFACES_H
end_define
begin_include
include|#
directive|include
file|<QtPlugin>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainterPath
name|class
name|QPainterPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|BrushInterface
block|{
name|public
label|:
name|virtual
operator|~
name|BrushInterface
argument_list|()
block|{}
name|virtual
name|QStringList
name|brushes
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QRect
name|mousePress
parameter_list|(
specifier|const
name|QString
modifier|&
name|brush
parameter_list|,
name|QPainter
modifier|&
name|painter
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QRect
name|mouseMove
parameter_list|(
specifier|const
name|QString
modifier|&
name|brush
parameter_list|,
name|QPainter
modifier|&
name|painter
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|oldPos
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|newPos
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QRect
name|mouseRelease
parameter_list|(
specifier|const
name|QString
modifier|&
name|brush
parameter_list|,
name|QPainter
modifier|&
name|painter
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
init|=
literal|0
function_decl|;
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
begin_decl_stmt
name|class
name|ShapeInterface
block|{
name|public
label|:
name|virtual
operator|~
name|ShapeInterface
argument_list|()
block|{}
name|virtual
name|QStringList
name|shapes
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QPainterPath
name|generateShape
parameter_list|(
specifier|const
name|QString
modifier|&
name|shape
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|class
name|FilterInterface
block|{
name|public
label|:
name|virtual
operator|~
name|FilterInterface
argument_list|()
block|{}
name|virtual
name|QStringList
name|filters
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QImage
name|filterImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//! [3] //! [4]
DECL|macro|BrushInterface_iid
define|#
directive|define
name|BrushInterface_iid
value|"org.qt-project.Qt.Examples.PlugAndPaint.BrushInterface"
name|Q_DECLARE_INTERFACE
argument_list|(
name|BrushInterface
argument_list|,
name|BrushInterface_iid
argument_list|)
comment|//! [3]
DECL|macro|ShapeInterface_iid
define|#
directive|define
name|ShapeInterface_iid
value|"org.qt-project.Qt.Examples.PlugAndPaint.ShapeInterface"
name|Q_DECLARE_INTERFACE
argument_list|(
name|ShapeInterface
argument_list|,
name|ShapeInterface_iid
argument_list|)
comment|//! [5]
DECL|macro|FilterInterface_iid
define|#
directive|define
name|FilterInterface_iid
value|"org.qt-project.Qt.Examples.PlugAndPaint.FilterInterface"
name|Q_DECLARE_INTERFACE
argument_list|(
name|FilterInterface
argument_list|,
name|FilterInterface_iid
argument_list|)
comment|//! [4] //! [5]
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
