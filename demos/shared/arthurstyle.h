begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ARTHURSTYLE_H
end_ifndef
begin_define
DECL|macro|ARTHURSTYLE_H
define|#
directive|define
name|ARTHURSTYLE_H
end_define
begin_include
include|#
directive|include
file|<QWindowsStyle>
end_include
begin_decl_stmt
name|QT_USE_NAMESPACE
name|class
name|ArthurStyle
range|:
name|public
name|QWindowsStyle
block|{
name|public
operator|:
name|ArthurStyle
argument_list|()
block|;
name|void
name|drawHoverRect
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|void
name|drawPrimitive
argument_list|(
argument|PrimitiveElement element
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
comment|//     void drawControl(ControlElement element, const QStyleOption *option,
comment|//                      QPainter *painter, const QWidget *widget) const;
name|void
name|drawComplexControl
argument_list|(
argument|ComplexControl control
argument_list|,
argument|const QStyleOptionComplex *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QSize
name|sizeFromContents
argument_list|(
argument|ContentsType type
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QSize&size
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QRect
name|subElementRect
argument_list|(
argument|SubElement element
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QRect
name|subControlRect
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|SubControl sc
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
comment|//     SubControl hitTestComplexControl(ComplexControl control, const QStyleOptionComplex *option,
comment|// 				     const QPoint&pos, const QWidget *widget = 0) const;
name|int
name|pixelMetric
argument_list|(
argument|PixelMetric metric
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|polish
argument_list|(
name|QPalette
operator|&
name|palette
argument_list|)
block|;
name|void
name|polish
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|unpolish
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
