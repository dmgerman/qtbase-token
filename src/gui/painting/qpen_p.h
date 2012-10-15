begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPEN_P_H
end_ifndef
begin_define
DECL|macro|QPEN_P_H
define|#
directive|define
name|QPEN_P_H
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
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QPenPrivate
block|{
name|public
label|:
name|QPenPrivate
argument_list|(
argument|const QBrush&brush
argument_list|,
argument|qreal width
argument_list|,
argument|Qt::PenStyle
argument_list|,
argument|Qt::PenCapStyle
argument_list|,
argument|Qt::PenJoinStyle _joinStyle
argument_list|,
argument|bool defaultWidth = true
argument_list|)
empty_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|qreal
name|width
decl_stmt|;
name|QBrush
name|brush
decl_stmt|;
name|Qt
operator|::
name|PenStyle
name|style
expr_stmt|;
name|Qt
operator|::
name|PenCapStyle
name|capStyle
expr_stmt|;
name|Qt
operator|::
name|PenJoinStyle
name|joinStyle
expr_stmt|;
name|mutable
name|QVector
operator|<
name|qreal
operator|>
name|dashPattern
expr_stmt|;
name|qreal
name|dashOffset
decl_stmt|;
name|qreal
name|miterLimit
decl_stmt|;
name|uint
name|cosmetic
range|:
literal|1
decl_stmt|;
name|uint
name|defaultWidth
range|:
literal|1
decl_stmt|;
comment|// default-constructed width? used for cosmetic pen compatibility
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
begin_comment
comment|// QPEN_P_H
end_comment
end_unit
