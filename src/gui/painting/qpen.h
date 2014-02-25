begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPEN_H
end_ifndef
begin_define
DECL|macro|QPEN_H
define|#
directive|define
name|QPEN_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qbrush.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPenPrivate
name|class
name|QPenPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBrush
name|class
name|QBrush
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPen
name|class
name|QPen
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QPen
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QPen
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPen
block|{
name|public
label|:
name|QPen
argument_list|()
expr_stmt|;
name|QPen
argument_list|(
name|Qt
operator|::
name|PenStyle
argument_list|)
expr_stmt|;
name|QPen
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
expr_stmt|;
name|QPen
argument_list|(
argument|const QBrush&brush
argument_list|,
argument|qreal width
argument_list|,
argument|Qt::PenStyle s = Qt::SolidLine
argument_list|,
argument|Qt::PenCapStyle c = Qt::SquareCap
argument_list|,
argument|Qt::PenJoinStyle j = Qt::BevelJoin
argument_list|)
empty_stmt|;
name|QPen
argument_list|(
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
expr_stmt|;
operator|~
name|QPen
argument_list|()
expr_stmt|;
name|QPen
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QPen
operator|&
name|pen
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QPen
argument_list|(
name|QPen
operator|&&
name|other
argument_list|)
operator|:
name|d
argument_list|(
argument|other.d
argument_list|)
block|{
name|other
operator|.
name|d
operator|=
literal|0
block|; }
specifier|inline
name|QPen
operator|&
name|operator
operator|=
operator|(
name|QPen
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QPen
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|Qt
operator|::
name|PenStyle
name|style
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStyle
argument_list|(
name|Qt
operator|::
name|PenStyle
argument_list|)
decl_stmt|;
name|QVector
operator|<
name|qreal
operator|>
name|dashPattern
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDashPattern
argument_list|(
specifier|const
name|QVector
operator|<
name|qreal
operator|>
operator|&
name|pattern
argument_list|)
decl_stmt|;
name|qreal
name|dashOffset
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDashOffset
parameter_list|(
name|qreal
name|doffset
parameter_list|)
function_decl|;
name|qreal
name|miterLimit
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMiterLimit
parameter_list|(
name|qreal
name|limit
parameter_list|)
function_decl|;
name|qreal
name|widthF
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWidthF
parameter_list|(
name|qreal
name|width
parameter_list|)
function_decl|;
name|int
name|width
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWidth
parameter_list|(
name|int
name|width
parameter_list|)
function_decl|;
name|QColor
name|color
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
name|QBrush
name|brush
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBrush
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
name|bool
name|isSolid
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|PenCapStyle
name|capStyle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCapStyle
argument_list|(
name|Qt
operator|::
name|PenCapStyle
name|pcs
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|PenJoinStyle
name|joinStyle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setJoinStyle
argument_list|(
name|Qt
operator|::
name|PenJoinStyle
name|pcs
argument_list|)
decl_stmt|;
name|bool
name|isCosmetic
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCosmetic
parameter_list|(
name|bool
name|cosmetic
parameter_list|)
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPen
operator|&
name|p
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPen
operator|&
name|p
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|operator
operator|==
operator|(
name|p
operator|)
operator|)
return|;
block|}
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDetached
parameter_list|()
function_decl|;
name|private
label|:
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QPen
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QPen
operator|&
operator|)
expr_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
name|class
name|QPenPrivate
modifier|*
name|d
decl_stmt|;
name|public
label|:
typedef|typedef
name|QPenPrivate
modifier|*
name|DataPtr
typedef|;
specifier|inline
name|DataPtr
modifier|&
name|data_ptr
parameter_list|()
block|{
return|return
name|d
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QPen
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QPen
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPEN_H
end_comment
end_unit
