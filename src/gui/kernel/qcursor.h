begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCURSOR_H
end_ifndef
begin_define
DECL|macro|QCURSOR_H
define|#
directive|define
name|QCURSOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QVariant
decl_stmt|;
comment|/*   ### The fake cursor has to go first with old qdoc. */
ifdef|#
directive|ifdef
name|QT_NO_CURSOR
name|class
name|Q_GUI_EXPORT
name|QCursor
decl_stmt|{ public:     static QPoint pos(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_function_decl
specifier|static
name|void
name|setPos
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
specifier|static
name|void
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
name|setPos
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QCursor
argument_list|()
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CURSOR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_decl_stmt
DECL|variable|QCursorData
name|class
name|QCursorData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBitmap
name|class
name|QBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_if
begin_function_decl
name|void
name|qt_mac_set_cursor
parameter_list|(
specifier|const
name|QCursor
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_function_decl
specifier|extern
name|void
name|qt_symbian_show_pointer_sprite
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|void
name|qt_symbian_hide_pointer_sprite
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|void
name|qt_symbian_set_pointer_sprite
parameter_list|(
specifier|const
name|QCursor
modifier|&
name|cursor
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|void
name|qt_symbian_move_cursor_sprite
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QCursor
block|{
name|public
label|:
name|QCursor
argument_list|()
expr_stmt|;
name|QCursor
argument_list|(
argument|Qt::CursorShape shape
argument_list|)
empty_stmt|;
name|QCursor
argument_list|(
argument|const QBitmap&bitmap
argument_list|,
argument|const QBitmap&mask
argument_list|,
argument|int hotX=-
literal|1
argument_list|,
argument|int hotY=-
literal|1
argument_list|)
empty_stmt|;
name|QCursor
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|int hotX=-
literal|1
argument_list|,
argument|int hotY=-
literal|1
argument_list|)
empty_stmt|;
name|QCursor
argument_list|(
specifier|const
name|QCursor
operator|&
name|cursor
argument_list|)
expr_stmt|;
operator|~
name|QCursor
argument_list|()
expr_stmt|;
name|QCursor
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QCursor
operator|&
name|cursor
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QCursor
modifier|&
name|operator
init|=
operator|(
name|QCursor
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|CursorShape
name|shape
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setShape
argument_list|(
name|Qt
operator|::
name|CursorShape
name|newShape
argument_list|)
decl_stmt|;
specifier|const
name|QBitmap
operator|*
name|bitmap
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QBitmap
operator|*
name|mask
argument_list|()
specifier|const
expr_stmt|;
name|QPixmap
name|pixmap
argument_list|()
specifier|const
expr_stmt|;
name|QPoint
name|hotSpot
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QPoint
name|pos
parameter_list|()
function_decl|;
specifier|static
name|void
name|setPos
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
specifier|inline
specifier|static
name|void
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
name|setPos
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|qdoc
name|HCURSOR_or_HANDLE
name|handle
parameter_list|()
function_decl|const;
name|QCursor
argument_list|(
argument|HCURSOR cursor
argument_list|)
empty_stmt|;
name|QCursor
argument_list|(
argument|Qt::HANDLE cursor
argument_list|)
empty_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|qdoc
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
name|HCURSOR
name|handle
parameter_list|()
function_decl|const;
name|QCursor
argument_list|(
argument|HCURSOR cursor
argument_list|)
empty_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|QCursor
argument_list|(
argument|Qt::HANDLE cursor
argument_list|)
empty_stmt|;
specifier|static
name|int
name|x11Screen
parameter_list|()
function_decl|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_QPA
argument_list|)
name|int
name|handle
argument_list|()
specifier|const
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|private
label|:
name|QCursorData
modifier|*
name|d
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|friend
name|void
modifier|*
name|qt_mac_nsCursorForQCursor
parameter_list|(
specifier|const
name|QCursor
modifier|&
name|c
parameter_list|)
function_decl|;
name|friend
name|void
name|qt_mac_set_cursor
parameter_list|(
specifier|const
name|QCursor
modifier|*
name|c
parameter_list|)
function_decl|;
name|friend
name|void
name|qt_mac_updateCursorWithWidgetUnderMouse
parameter_list|(
name|QWidget
modifier|*
name|widgetUnderMouse
parameter_list|)
function_decl|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|friend
name|void
name|qt_symbian_show_pointer_sprite
parameter_list|()
function_decl|;
name|friend
name|void
name|qt_symbian_hide_pointer_sprite
parameter_list|()
function_decl|;
name|friend
name|void
name|qt_symbian_set_pointer_sprite
parameter_list|(
specifier|const
name|QCursor
modifier|&
name|cursor
parameter_list|)
function_decl|;
name|friend
name|void
name|qt_symbian_move_cursor_sprite
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_comment
comment|// CursorShape is defined in X11/X.h
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|CursorShape
end_ifdef
begin_define
DECL|macro|X_CursorShape
define|#
directive|define
name|X_CursorShape
value|CursorShape
end_define
begin_undef
DECL|macro|CursorShape
undef|#
directive|undef
name|CursorShape
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|QCursorShape
typedef|typedef
name|Qt
operator|::
name|CursorShape
name|QCursorShape
expr_stmt|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|X_CursorShape
end_ifdef
begin_define
DECL|macro|CursorShape
define|#
directive|define
name|CursorShape
value|X_CursorShape
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QCursor stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|outS
operator|,
specifier|const
name|QCursor
operator|&
name|cursor
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|inS
operator|,
name|QCursor
operator|&
name|cursor
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CURSOR
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
comment|// QCURSOR_H
end_comment
end_unit
