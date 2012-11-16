begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMACSTYLE_MAC_P_H
end_ifndef
begin_define
DECL|macro|QMACSTYLE_MAC_P_H
define|#
directive|define
name|QMACSTYLE_MAC_P_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qcommonstyle.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_MAC
argument_list|)
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionButton
name|class
name|QStyleOptionButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMacStylePrivate
name|class
name|QMacStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMacStyle
range|:
name|public
name|QCommonStyle
block|{
name|Q_OBJECT
name|public
operator|:
name|QMacStyle
argument_list|()
block|;
name|virtual
operator|~
name|QMacStyle
argument_list|()
block|;
name|void
name|polish
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|void
name|unpolish
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|void
name|polish
argument_list|(
name|QApplication
operator|*
argument_list|)
block|;
name|void
name|unpolish
argument_list|(
name|QApplication
operator|*
argument_list|)
block|;
name|void
name|polish
argument_list|(
name|QPalette
operator|&
name|pal
argument_list|)
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
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|pixelMetric
argument_list|(
argument|PixelMetric pm
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|QPalette
name|standardPalette
argument_list|()
specifier|const
block|;
name|virtual
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
block|;      enum
name|FocusRectPolicy
block|{
name|FocusEnabled
block|,
name|FocusDisabled
block|,
name|FocusDefault
block|}
block|;
specifier|static
name|void
name|setFocusRectPolicy
argument_list|(
argument|QWidget *w
argument_list|,
argument|FocusRectPolicy policy
argument_list|)
block|;
specifier|static
name|FocusRectPolicy
name|focusRectPolicy
argument_list|(
specifier|const
name|QWidget
operator|*
name|w
argument_list|)
block|;      enum
name|WidgetSizePolicy
block|{
name|SizeSmall
block|,
name|SizeLarge
block|,
name|SizeMini
block|,
name|SizeDefault
block|}
block|;
specifier|static
name|void
name|setWidgetSizePolicy
argument_list|(
argument|const QWidget *w
argument_list|,
argument|WidgetSizePolicy policy
argument_list|)
block|;
specifier|static
name|WidgetSizePolicy
name|widgetSizePolicy
argument_list|(
specifier|const
name|QWidget
operator|*
name|w
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
operator|=
literal|0
argument_list|)
block|;
name|QPixmap
name|standardPixmap
argument_list|(
argument|StandardPixmap sp
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
block|;
name|virtual
name|void
name|drawItemText
argument_list|(
argument|QPainter *p
argument_list|,
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
argument|QPalette::ColorRole textRole  = QPalette::NoRole
argument_list|)
specifier|const
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
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
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QMacStyle
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMacStyle
argument_list|)
name|friend
name|bool
name|qt_mac_buttonIsRenderedFlat
argument_list|(
specifier|const
name|QPushButton
operator|*
name|pushButton
argument_list|,
specifier|const
name|QStyleOptionButton
operator|*
name|option
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_MAC
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMACSTYLE_MAC_P_H
end_comment
end_unit
