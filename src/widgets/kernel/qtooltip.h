begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTOOLTIP_H
end_ifndef
begin_define
DECL|macro|QTOOLTIP_H
define|#
directive|define
name|QTOOLTIP_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|class
name|Q_WIDGETS_EXPORT
name|QToolTip
decl_stmt|{     QToolTip(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_label
name|public
label|:
end_label
begin_function_decl
specifier|static
name|void
name|showText
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|w
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|showText
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|static
specifier|inline
name|void
name|hideText
parameter_list|()
block|{
name|showText
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function_decl
specifier|static
name|bool
name|isVisible
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|text
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QPalette
name|palette
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|setPalette
parameter_list|(
specifier|const
name|QPalette
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QFont
name|font
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TOOLTIP
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
comment|// QTOOLTIP_H
end_comment
end_unit
