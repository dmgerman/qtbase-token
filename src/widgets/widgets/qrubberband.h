begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRUBBERBAND_H
end_ifndef
begin_define
DECL|macro|QRUBBERBAND_H
define|#
directive|define
name|QRUBBERBAND_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
DECL|variable|QRubberBandPrivate
name|class
name|QRubberBandPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionRubberBand
name|class
name|QStyleOptionRubberBand
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QRubberBand
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Shape
block|{
name|Line
block|,
name|Rectangle
block|}
block|;
name|explicit
name|QRubberBand
argument_list|(
name|Shape
argument_list|,
name|QWidget
operator|*
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QRubberBand
argument_list|()
block|;
name|Shape
name|shape
argument_list|()
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
block|;
specifier|inline
name|void
name|setGeometry
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
specifier|inline
name|void
name|move
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
specifier|inline
name|void
name|move
argument_list|(
argument|const QPoint&p
argument_list|)
block|{
name|move
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
block|; }
specifier|inline
name|void
name|resize
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|{
name|setGeometry
argument_list|(
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
block|; }
specifier|inline
name|void
name|resize
argument_list|(
argument|const QSize&s
argument_list|)
block|{
name|resize
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|,
name|s
operator|.
name|height
argument_list|()
argument_list|)
block|; }
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|changeEvent
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|showEvent
argument_list|(
argument|QShowEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|moveEvent
argument_list|(
argument|QMoveEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionRubberBand *option
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QRubberBand
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|setGeometry
specifier|inline
name|void
name|QRubberBand
operator|::
name|setGeometry
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|,
argument|int aw
argument_list|,
argument|int ah
argument_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|aw
argument_list|,
name|ah
argument_list|)
argument_list|)
block|; }
DECL|function|move
specifier|inline
name|void
name|QRubberBand
operator|::
name|move
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
block|{
name|setGeometry
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
block|; }
endif|#
directive|endif
comment|// QT_NO_RUBBERBAND
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QRUBBERBAND_H
end_comment
end_unit
