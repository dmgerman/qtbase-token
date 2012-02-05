begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCSSUTIL_P_H
end_ifndef
begin_define
DECL|macro|QCSSUTIL_P_H
define|#
directive|define
name|QCSSUTIL_P_H
end_define
begin_include
include|#
directive|include
file|"QtCore/qglobal.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CSSPARSER
end_ifndef
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
file|"private/qcssparser_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsize.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|void
name|qDrawEdge
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
name|qreal
name|x1
argument_list|,
name|qreal
name|y1
argument_list|,
name|qreal
name|x2
argument_list|,
name|qreal
name|y2
argument_list|,
name|qreal
name|dw1
argument_list|,
name|qreal
name|dw2
argument_list|,
name|QCss
operator|::
name|Edge
name|edge
argument_list|,
name|QCss
operator|::
name|BorderStyle
name|style
argument_list|,
name|QBrush
name|c
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|void
name|qDrawRoundedCorners
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
name|qreal
name|x1
argument_list|,
name|qreal
name|y1
argument_list|,
name|qreal
name|x2
argument_list|,
name|qreal
name|y2
argument_list|,
specifier|const
name|QSizeF
operator|&
name|r1
argument_list|,
specifier|const
name|QSizeF
operator|&
name|r2
argument_list|,
name|QCss
operator|::
name|Edge
name|edge
argument_list|,
name|QCss
operator|::
name|BorderStyle
name|s
argument_list|,
name|QBrush
name|c
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|void
name|Q_GUI_EXPORT
name|qDrawBorder
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
specifier|const
name|QCss
operator|::
name|BorderStyle
operator|*
name|styles
argument_list|,
specifier|const
name|int
operator|*
name|borders
argument_list|,
specifier|const
name|QBrush
operator|*
name|colors
argument_list|,
specifier|const
name|QSize
operator|*
name|radii
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|extern
name|void
name|Q_GUI_EXPORT
name|qNormalizeRadii
parameter_list|(
specifier|const
name|QRect
modifier|&
name|br
parameter_list|,
specifier|const
name|QSize
modifier|*
name|radii
parameter_list|,
name|QSize
modifier|*
name|tlr
parameter_list|,
name|QSize
modifier|*
name|trr
parameter_list|,
name|QSize
modifier|*
name|blr
parameter_list|,
name|QSize
modifier|*
name|brr
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_CSSPARSER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCSSUTIL_P_H
end_comment
end_unit
