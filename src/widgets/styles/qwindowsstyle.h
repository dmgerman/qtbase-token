begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSSTYLE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSSTYLE_H
define|#
directive|define
name|QWINDOWSSTYLE_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qcommonstyle.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_WINDOWS
argument_list|)
name|class
name|QWindowsStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QWindowsStyle
range|:
name|public
name|QCommonStyle
block|{
name|Q_OBJECT
name|public
operator|:
name|QWindowsStyle
argument_list|()
block|;
operator|~
name|QWindowsStyle
argument_list|()
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
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|unpolish
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|polish
argument_list|(
name|QPalette
operator|&
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
argument|PixelMetric pm
argument_list|,
argument|const QStyleOption *option =
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
argument|StyleHint hint
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|,
argument|QStyleHintReturn *returnData =
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
name|protected
name|Q_SLOTS
operator|:
name|QIcon
name|standardIconImplementation
argument_list|(
argument|StandardPixmap standardIcon
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
block|;
name|QWindowsStyle
argument_list|(
name|QWindowsStylePrivate
operator|&
name|dd
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsStyle
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWindowsStyle
argument_list|)
name|void
operator|*
name|reserved
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_WINDOWS
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
comment|// QWINDOWSSTYLE_H
end_comment
end_unit
