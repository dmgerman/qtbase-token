begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBCURSOR_H
end_ifndef
begin_define
DECL|macro|QXCBCURSOR_H
define|#
directive|define
name|QXCBCURSOR_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformCursor>
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbObject
name|class
name|QXcbCursor
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformCursor
block|{
name|public
label|:
name|QXcbCursor
argument_list|(
name|QXcbConnection
operator|*
name|conn
argument_list|,
name|QXcbScreen
operator|*
name|screen
argument_list|)
expr_stmt|;
operator|~
name|QXcbCursor
argument_list|()
expr_stmt|;
name|void
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|,
name|QWindow
modifier|*
name|widget
parameter_list|)
function_decl|;
name|QPoint
name|pos
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
function_decl|;
name|private
label|:
name|xcb_cursor_t
name|createFontCursor
parameter_list|(
name|int
name|cshape
parameter_list|)
function_decl|;
name|xcb_cursor_t
name|createBitmapCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|)
function_decl|;
name|xcb_cursor_t
name|createNonStandardCursor
parameter_list|(
name|int
name|cshape
parameter_list|)
function_decl|;
name|QXcbScreen
modifier|*
name|m_screen
decl_stmt|;
name|QMap
operator|<
name|int
operator|,
name|xcb_cursor_t
operator|>
name|m_shapeCursorMap
expr_stmt|;
name|QMap
operator|<
name|qint64
operator|,
name|xcb_cursor_t
operator|>
name|m_bitmapCursorMap
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
