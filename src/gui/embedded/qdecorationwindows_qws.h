begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDECORATIONWINDOWS_QWS_H
end_ifndef
begin_define
DECL|macro|QDECORATIONWINDOWS_QWS_H
define|#
directive|define
name|QDECORATIONWINDOWS_QWS_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qdecorationdefault_qws.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_QWS_DECORATION_WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_PLUGIN
argument_list|)
name|class
name|Q_GUI_EXPORT
name|QDecorationWindows
range|:
name|public
name|QDecorationDefault
block|{
name|public
operator|:
name|QDecorationWindows
argument_list|()
block|;
name|virtual
operator|~
name|QDecorationWindows
argument_list|()
block|;
name|QRegion
name|region
argument_list|(
argument|const QWidget *widget
argument_list|,
argument|const QRect&rect
argument_list|,
argument|int decorationRegion = All
argument_list|)
block|;
name|bool
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|,
argument|int decorationRegion = All
argument_list|,
argument|DecorationState state = Normal
argument_list|)
block|;
name|protected
operator|:
name|void
name|paintButton
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|,
argument|int buttonRegion
argument_list|,
argument|DecorationState state
argument_list|,
argument|const QPalette&pal
argument_list|)
block|;
specifier|const
name|char
operator|*
operator|*
name|xpmForRegion
argument_list|(
argument|int reg
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_DECORATION_WINDOWS
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
comment|// QDECORATIONWINDOWS_QWS_H
end_comment
end_unit
