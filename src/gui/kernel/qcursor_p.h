begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCURSOR_P_H
end_ifndef
begin_define
DECL|macro|QCURSOR_P_H
define|#
directive|define
name|QCURSOR_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of a number of Qt sources files.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"QtCore/qatomic.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qnamespace.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpixmap.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBitmap
name|class
name|QBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCursorData
block|{
name|public
label|:
name|QCursorData
argument_list|(
argument|Qt::CursorShape s = Qt::ArrowCursor
argument_list|)
empty_stmt|;
operator|~
name|QCursorData
argument_list|()
expr_stmt|;
specifier|static
name|void
name|initialize
parameter_list|()
function_decl|;
specifier|static
name|void
name|cleanup
parameter_list|()
function_decl|;
name|QAtomicInt
name|ref
decl_stmt|;
name|Qt
operator|::
name|CursorShape
name|cshape
expr_stmt|;
name|QBitmap
modifier|*
name|bm
decl_stmt|,
modifier|*
name|bmm
decl_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
name|short
name|hx
decl_stmt|,
name|hy
decl_stmt|;
name|int
name|id
decl_stmt|;
specifier|static
name|bool
name|initialized
decl_stmt|;
name|void
name|update
parameter_list|()
function_decl|;
specifier|static
name|QCursorData
modifier|*
name|setBitmap
parameter_list|(
specifier|const
name|QBitmap
modifier|&
name|bitmap
parameter_list|,
specifier|const
name|QBitmap
modifier|&
name|mask
parameter_list|,
name|int
name|hotX
parameter_list|,
name|int
name|hotY
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
specifier|extern
name|QCursorData
modifier|*
name|qt_cursorTable
index|[
name|Qt
operator|::
name|LastCursor
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt
begin_comment
comment|// qcursor.cpp
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCURSOR_P_H
end_comment
end_unit
