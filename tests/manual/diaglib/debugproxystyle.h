begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DEBUGPROXYSTYLE_H
end_ifndef
begin_define
DECL|macro|DEBUGPROXYSTYLE_H
define|#
directive|define
name|DEBUGPROXYSTYLE_H
end_define
begin_include
include|#
directive|include
file|<QProxyStyle>
end_include
begin_decl_stmt
name|namespace
name|QtDiag
block|{
name|class
name|DebugProxyStyle
range|:
name|public
name|QProxyStyle
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|DebugProxyStyle
argument_list|(
name|QStyle
operator|*
name|style
argument_list|)
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
name|void
name|drawControl
argument_list|(
argument|ControlElement element
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
name|void
name|drawComplexControl
argument_list|(
argument|ComplexControl control
argument_list|,
argument|const QStyleOptionComplex *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|drawItemPixmap
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|,
argument|int alignment
argument_list|,
argument|const QPixmap&pixmap
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
name|QRect
name|itemTextRect
argument_list|(
argument|const QFontMetrics&fm
argument_list|,
argument|const QRect&r
argument_list|,
argument|int flags
argument_list|,
argument|bool enabled
argument_list|,
argument|const QString&text
argument_list|)
specifier|const
block|;
name|QRect
name|itemPixmapRect
argument_list|(
argument|const QRect&r
argument_list|,
argument|int flags
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
specifier|const
block|;
name|int
name|pixelMetric
argument_list|(
argument|PixelMetric metric
argument_list|,
argument|const QStyleOption *option =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|QPixmap
name|standardPixmap
argument_list|(
argument|StandardPixmap standardPixmap
argument_list|,
argument|const QStyleOption *opt
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
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace QtDiag
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DEBUGPROXYSTYLE_H
end_comment
end_unit
