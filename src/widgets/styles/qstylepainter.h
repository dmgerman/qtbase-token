begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTYLEPAINTER_H
end_ifndef
begin_define
DECL|macro|QSTYLEPAINTER_H
define|#
directive|define
name|QSTYLEPAINTER_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qpainter.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyle.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QStylePainter
range|:
name|public
name|QPainter
block|{
name|public
operator|:
specifier|inline
name|QStylePainter
argument_list|()
operator|:
name|QPainter
argument_list|()
block|,
name|widget
argument_list|(
literal|0
argument_list|)
block|,
name|wstyle
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|explicit
name|QStylePainter
argument_list|(
argument|QWidget *w
argument_list|)
block|{
name|begin
argument_list|(
name|w
argument_list|,
name|w
argument_list|)
block|; }
specifier|inline
name|QStylePainter
argument_list|(
argument|QPaintDevice *pd
argument_list|,
argument|QWidget *w
argument_list|)
block|{
name|begin
argument_list|(
name|pd
argument_list|,
name|w
argument_list|)
block|; }
specifier|inline
name|bool
name|begin
argument_list|(
argument|QWidget *w
argument_list|)
block|{
return|return
name|begin
argument_list|(
name|w
argument_list|,
name|w
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|begin
argument_list|(
argument|QPaintDevice *pd
argument_list|,
argument|QWidget *w
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|w
argument_list|,
literal|"QStylePainter::QStylePainter"
argument_list|,
literal|"Widget must be non-zero"
argument_list|)
block|;
name|widget
operator|=
name|w
block|;
name|wstyle
operator|=
name|w
operator|->
name|style
argument_list|()
block|;
return|return
name|QPainter
operator|::
name|begin
argument_list|(
name|pd
argument_list|)
return|;
block|}
block|;
specifier|inline
name|void
name|drawPrimitive
argument_list|(
argument|QStyle::PrimitiveElement pe
argument_list|,
argument|const QStyleOption&opt
argument_list|)
block|;
specifier|inline
name|void
name|drawControl
argument_list|(
argument|QStyle::ControlElement ce
argument_list|,
argument|const QStyleOption&opt
argument_list|)
block|;
specifier|inline
name|void
name|drawComplexControl
argument_list|(
argument|QStyle::ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex&opt
argument_list|)
block|;
specifier|inline
name|void
name|drawItemText
argument_list|(
argument|const QRect&r
argument_list|,
argument|int flags
argument_list|,
argument|const QPalette&pal
argument_list|,
argument|bool enabled
argument_list|,
argument|const QString&text
argument_list|,
argument|QPalette::ColorRole textRole = QPalette::NoRole
argument_list|)
block|;
specifier|inline
name|void
name|drawItemPixmap
argument_list|(
argument|const QRect&r
argument_list|,
argument|int flags
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
block|;
specifier|inline
name|QStyle
operator|*
name|style
argument_list|()
specifier|const
block|{
return|return
name|wstyle
return|;
block|}
name|private
operator|:
name|QWidget
operator|*
name|widget
block|;
name|QStyle
operator|*
name|wstyle
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QStylePainter
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|drawPrimitive
name|void
name|QStylePainter
operator|::
name|drawPrimitive
argument_list|(
argument|QStyle::PrimitiveElement pe
argument_list|,
argument|const QStyleOption&opt
argument_list|)
block|{
name|wstyle
operator|->
name|drawPrimitive
argument_list|(
name|pe
argument_list|,
operator|&
name|opt
argument_list|,
name|this
argument_list|,
name|widget
argument_list|)
block|; }
DECL|function|drawControl
name|void
name|QStylePainter
operator|::
name|drawControl
argument_list|(
argument|QStyle::ControlElement ce
argument_list|,
argument|const QStyleOption&opt
argument_list|)
block|{
name|wstyle
operator|->
name|drawControl
argument_list|(
name|ce
argument_list|,
operator|&
name|opt
argument_list|,
name|this
argument_list|,
name|widget
argument_list|)
block|; }
DECL|function|drawComplexControl
name|void
name|QStylePainter
operator|::
name|drawComplexControl
argument_list|(
argument|QStyle::ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex&opt
argument_list|)
block|{
name|wstyle
operator|->
name|drawComplexControl
argument_list|(
name|cc
argument_list|,
operator|&
name|opt
argument_list|,
name|this
argument_list|,
name|widget
argument_list|)
block|; }
DECL|function|drawItemText
name|void
name|QStylePainter
operator|::
name|drawItemText
argument_list|(
argument|const QRect&r
argument_list|,
argument|int flags
argument_list|,
argument|const QPalette&pal
argument_list|,
argument|bool enabled
argument_list|,
argument|const QString&text
argument_list|,
argument|QPalette::ColorRole textRole
argument_list|)
block|{
name|wstyle
operator|->
name|drawItemText
argument_list|(
name|this
argument_list|,
name|r
argument_list|,
name|flags
argument_list|,
name|pal
argument_list|,
name|enabled
argument_list|,
name|text
argument_list|,
name|textRole
argument_list|)
block|; }
DECL|function|drawItemPixmap
name|void
name|QStylePainter
operator|::
name|drawItemPixmap
argument_list|(
argument|const QRect&r
argument_list|,
argument|int flags
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
block|{
name|wstyle
operator|->
name|drawItemPixmap
argument_list|(
name|this
argument_list|,
name|r
argument_list|,
name|flags
argument_list|,
name|pixmap
argument_list|)
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTYLEPAINTER_H
end_comment
end_unit
