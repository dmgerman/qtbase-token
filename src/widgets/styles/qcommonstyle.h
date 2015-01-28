begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QT_BEGIN_NAMESPACE
DECL|variable|QCommonStylePrivate
name|class
name|QCommonStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|QIcon
name|standardIcon
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|int
name|layoutSpacing
argument_list|(
argument|QSizePolicy::ControlType control1
argument_list|,
argument|QSizePolicy::ControlType control2
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|const QStyleOption *option =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|polish
argument_list|(
argument|QPalette&
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|polish
argument_list|(
argument|QApplication *app
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|polish
argument_list|(
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|unpolish
argument_list|(
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|unpolish
argument_list|(
argument|QApplication *application
argument_list|)
name|Q_DECL_OVERRIDE
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
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_removeAnimation()
argument_list|)
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOMMONSTYLE_H
end_comment
end_unit
