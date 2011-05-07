begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOMMONSTYLE_H
end_ifndef
begin_define
DECL|macro|QCOMMONSTYLE_H
define|#
directive|define
name|QCOMMONSTYLE_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qstyle.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QCommonStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QCommonStyle
range|:
name|public
name|QStyle
block|{
name|Q_OBJECT
name|public
operator|:
name|QCommonStyle
argument_list|()
block|;
operator|~
name|QCommonStyle
argument_list|()
block|;
name|void
name|drawPrimitive
argument_list|(
argument|PrimitiveElement pe
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|drawControl
argument_list|(
argument|ControlElement element
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
block|;
name|QRect
name|subElementRect
argument_list|(
argument|SubElement r
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|drawComplexControl
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
block|;
name|SubControl
name|hitTestComplexControl
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|const QPoint&pt
argument_list|,
argument|const QWidget *w =
literal|0
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
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
block|;
name|QSize
name|sizeFromContents
argument_list|(
argument|ContentsType ct
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|pixelMetric
argument_list|(
argument|PixelMetric m
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|styleHint
argument_list|(
argument|StyleHint sh
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|,
argument|QStyleHintReturn *shret =
literal|0
argument_list|)
specifier|const
block|;
name|QPixmap
name|standardPixmap
argument_list|(
argument|StandardPixmap sp
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|QPixmap
name|generatedIconPixmap
argument_list|(
argument|QIcon::Mode iconMode
argument_list|,
argument|const QPixmap&pixmap
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|void
name|polish
argument_list|(
name|QPalette
operator|&
argument_list|)
block|;
name|void
name|polish
argument_list|(
name|QApplication
operator|*
name|app
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
block|;
name|void
name|unpolish
argument_list|(
name|QApplication
operator|*
name|application
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|QIcon
name|standardIconImplementation
argument_list|(
argument|StandardPixmap standardIcon
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QCommonStyle
argument_list|(
name|QCommonStylePrivate
operator|&
name|dd
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QCommonStyle
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QCommonStyle
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOMMONSTYLE_H
end_comment
end_unit
