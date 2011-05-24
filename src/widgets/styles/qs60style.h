begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QS60STYLE_H
end_ifndef
begin_define
DECL|macro|QS60STYLE_H
define|#
directive|define
name|QS60STYLE_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qcommonstyle.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
comment|//Public custom pixel metrics values.
comment|//These can be used to fetch custom pixel metric value from outside QS60Style.
decl|enum
block|{
name|PM_FrameCornerWidth
operator|=
name|QStyle
operator|::
name|PM_CustomBase
operator|+
literal|1
operator|,
name|PM_FrameCornerHeight
operator|,
name|PM_BoldLineWidth
operator|,
name|PM_ThinLineWidth
operator|,
name|PM_MessageBoxHeight
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QS60StylePrivate
name|class
name|QS60StylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QS60Style
range|:
name|public
name|QCommonStyle
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QS60Style
argument_list|)
name|public
operator|:
name|QS60Style
argument_list|()
block|;
operator|~
name|QS60Style
argument_list|()
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
name|QRect
name|subControlRect
argument_list|(
argument|ComplexControl control
argument_list|,
argument|const QStyleOptionComplex *option
argument_list|,
argument|SubControl scontrol
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|QRect
name|subElementRect
argument_list|(
argument|SubElement element
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
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
name|polish
argument_list|(
name|QApplication
operator|*
name|application
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
ifndef|#
directive|ifndef
name|Q_NO_USING_KEYWORD
name|using
name|QCommonStyle
operator|::
name|polish
block|;
endif|#
directive|endif
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
specifier|static
name|QStringList
name|partKeys
argument_list|()
block|;
specifier|static
name|QStringList
name|colorListKeys
argument_list|()
block|;
name|void
name|setS60Theme
argument_list|(
specifier|const
name|QHash
operator|<
name|QString
argument_list|,
name|QPicture
operator|>
operator|&
name|parts
argument_list|,
specifier|const
name|QHash
operator|<
name|QPair
operator|<
name|QString
argument_list|,
name|int
operator|>
argument_list|,
name|QColor
operator|>
operator|&
name|colors
argument_list|)
block|;
name|bool
name|loadS60ThemeFromBlob
argument_list|(
specifier|const
name|QString
operator|&
name|blobFile
argument_list|)
block|;
name|bool
name|saveS60ThemeToBlob
argument_list|(
argument|const QString&blobFile
argument_list|)
specifier|const
block|;
endif|#
directive|endif
comment|// !Q_OS_SYMBIAN
name|protected
name|Q_SLOTS
operator|:
name|QIcon
name|standardIconImplementation
argument_list|(
argument|StandardPixmap standardIcon
argument_list|,
argument|const QStyleOption * option =
literal|0
argument_list|,
argument|const QWidget * widget =
literal|0
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
block|;
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
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QS60Style
argument_list|)
name|friend
name|class
name|QStyleFactory
block|;
name|friend
name|class
name|QApplicationPrivate
block|; }
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
comment|// QS60STYLE_H
end_comment
end_unit
