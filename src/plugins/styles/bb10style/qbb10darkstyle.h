begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2014 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBB10DARKSTYLE_H
end_ifndef
begin_define
DECL|macro|QBB10DARKSTYLE_H
define|#
directive|define
name|QBB10DARKSTYLE_H
end_define
begin_include
include|#
directive|include
file|"qpixmapstyle.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QBB10DarkStyle
range|:
name|public
name|QPixmapStyle
block|{
name|Q_OBJECT
name|public
operator|:
name|QBB10DarkStyle
argument_list|()
block|;
operator|~
name|QBB10DarkStyle
argument_list|()
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
name|polish
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QPalette
name|standardPalette
argument_list|()
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
argument|const QWidget *widget
argument_list|)
specifier|const
block|; }
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
comment|// QBB10DARKSTYLE_H
end_comment
end_unit
