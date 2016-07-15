begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGTKSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QGTKSTYLE_P_H
define|#
directive|define
name|QGTKSTYLE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<private/qwindowsstyle_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPalette>
end_include
begin_include
include|#
directive|include
file|<QtGui/QFont>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFileDialog>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_GTK
argument_list|)
DECL|variable|QPainterPath
name|class
name|QPainterPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGtkStylePrivate
name|class
name|QGtkStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGtkStyle
range|:
name|public
name|QCommonStyle
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGtkStyle
argument_list|)
name|public
operator|:
name|QGtkStyle
argument_list|()
block|;
name|QGtkStyle
argument_list|(
name|QGtkStylePrivate
operator|&
name|dd
argument_list|)
block|;
operator|~
name|QGtkStyle
argument_list|()
block|;
name|QPalette
name|standardPalette
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
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
argument|const QWidget *widget
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawControl
argument_list|(
argument|ControlElement control
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
argument|const QWidget *widget
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawItemText
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|,
argument|int alignment
argument_list|,
argument|const QPalette&pal
argument_list|,
argument|bool enabled
argument_list|,
argument|const QString& text
argument_list|,
argument|QPalette::ColorRole textRole
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|int
name|styleHint
argument_list|(
argument|StyleHint hint
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget
argument_list|,
argument|QStyleHintReturn *returnData
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QStyle
operator|::
name|SubControl
name|hitTestComplexControl
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|const QPoint&pt
argument_list|,
argument|const QWidget *w
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QRect
name|subControlRect
argument_list|(
argument|ComplexControl control
argument_list|,
argument|const QStyleOptionComplex *option
argument_list|,
argument|SubControl subControl
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QRect
name|subElementRect
argument_list|(
argument|SubElement sr
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|const QWidget *w
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|QIcon
name|standardIcon
argument_list|(
argument|StandardPixmap standardIcon
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
name|QPixmap
name|standardPixmap
argument_list|(
argument|StandardPixmap sp
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget
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
name|void
name|polish
argument_list|(
argument|QWidget *widget
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
argument|QPalette&palette
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
argument|QApplication *app
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|bool
name|getGConfBool
argument_list|(
argument|const QString&key
argument_list|,
argument|bool fallback =
literal|0
argument_list|)
block|;
specifier|static
name|QString
name|getGConfString
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|fallback
operator|=
name|QString
argument_list|()
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//!defined(QT_NO_STYLE_QGTK)
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QGTKSTYLE_P_H
end_comment
end_unit
