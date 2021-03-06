begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|class
name|Q_WIDGETS_EXPORT
name|QToolTip
block|{
name|QToolTip
argument_list|()
name|Q_DECL_EQ_DELETE
expr_stmt|;
name|public
label|:
comment|// ### Qt 6 - merge the three showText functions below
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
name|Q_NULLPTR
parameter_list|)
function_decl|;
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
parameter_list|,
name|int
name|msecShowTime
parameter_list|)
function_decl|;
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
specifier|static
name|bool
name|isVisible
parameter_list|()
function_decl|;
specifier|static
name|QString
name|text
parameter_list|()
function_decl|;
specifier|static
name|QPalette
name|palette
parameter_list|()
function_decl|;
specifier|static
name|void
name|setPalette
parameter_list|(
specifier|const
name|QPalette
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|QFont
name|font
parameter_list|()
function_decl|;
specifier|static
name|void
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TOOLTIP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTOOLTIP_H
end_comment
end_unit
