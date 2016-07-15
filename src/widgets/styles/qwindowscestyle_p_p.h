begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSCESTYLE_P_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSCESTYLE_P_P_H
define|#
directive|define
name|QWINDOWSCESTYLE_P_P_H
end_define
begin_include
include|#
directive|include
file|"qwindowscestyle_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qwindowsstyle_p_p.h>
end_include
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBrush
name|class
name|QBrush
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Private class
end_comment
begin_decl_stmt
name|class
name|QWindowsCEStylePrivate
range|:
name|public
name|QWindowsStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QWindowsCEStyle
argument_list|)
name|public
operator|:
specifier|inline
name|QWindowsCEStylePrivate
argument_list|()
block|{ }
specifier|static
name|void
name|drawWinCEButton
argument_list|(
argument|QPainter *p
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|const QPalette&pal
argument_list|,
argument|bool sunken = false
argument_list|,
argument|const QBrush *fill =
literal|0
argument_list|)
block|;
specifier|static
name|void
name|drawWinCEButton
argument_list|(
argument|QPainter *p
argument_list|,
argument|const QRect&r
argument_list|,
argument|const QPalette&pal
argument_list|,
argument|bool sunken = false
argument_list|,
argument|const QBrush *fill =
literal|0
argument_list|)
block|;
specifier|static
name|void
name|drawWinCEPanel
argument_list|(
argument|QPainter *p
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|const QPalette&pal
argument_list|,
argument|bool sunken = false
argument_list|,
argument|const QBrush *fill =
literal|0
argument_list|)
block|;
specifier|static
name|void
name|drawWinCEPanel
argument_list|(
argument|QPainter *p
argument_list|,
argument|const QRect&r
argument_list|,
argument|const QPalette&pal
argument_list|,
argument|bool sunken = false
argument_list|,
argument|const QBrush *fill =
literal|0
argument_list|)
block|;
specifier|static
name|void
name|drawWinShades
argument_list|(
argument|QPainter *p
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|const QColor&c1
argument_list|,
argument|const QColor&c2
argument_list|,
argument|const QColor&c3
argument_list|,
argument|const QColor&c4
argument_list|,
argument|const QBrush *fill
argument_list|)
block|;
specifier|static
name|void
name|drawWinCEShades
argument_list|(
argument|QPainter *p
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|const QColor&c1
argument_list|,
argument|const QColor&c2
argument_list|,
argument|const QColor&c3
argument_list|,
argument|const QColor&c4
argument_list|,
argument|const QBrush *fill
argument_list|)
block|;
specifier|static
name|void
name|drawWinCEShadesSunken
argument_list|(
argument|QPainter *p
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|const QColor&c1
argument_list|,
argument|const QColor&c2
argument_list|,
argument|const QColor&c3
argument_list|,
argument|const QColor&c4
argument_list|,
argument|const QBrush *fill
argument_list|)
block|;     }
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
comment|//QWINDOWSCESTYLE_P_P_H
end_comment
end_unit
