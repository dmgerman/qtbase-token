begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSLAYOUTSTYLEINFO_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSLAYOUTSTYLEINFO_P_H
define|#
directive|define
name|QGRAPHICSLAYOUTSTYLEINFO_P_H
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
file|<QtGui/private/qabstractlayoutstyleinfo_p.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyleoption.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStyle
name|class
name|QStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsLayoutPrivate
name|class
name|QGraphicsLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGraphicsLayoutStyleInfo
range|:
name|public
name|QAbstractLayoutStyleInfo
block|{
name|public
operator|:
name|QGraphicsLayoutStyleInfo
argument_list|(
specifier|const
name|QGraphicsLayoutPrivate
operator|*
name|layout
argument_list|)
block|;
operator|~
name|QGraphicsLayoutStyleInfo
argument_list|()
block|;
name|virtual
name|qreal
name|combinedLayoutSpacing
argument_list|(
argument|QLayoutPolicy::ControlTypes controls1
argument_list|,
argument|QLayoutPolicy::ControlTypes controls2
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qreal
name|perItemSpacing
argument_list|(
argument|QLayoutPolicy::ControlType control1
argument_list|,
argument|QLayoutPolicy::ControlType control2
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qreal
name|spacing
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qreal
name|windowMargin
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|invalidate
argument_list|()
name|Q_DECL_OVERRIDE
block|{
name|m_style
operator|=
literal|0
block|;
name|QAbstractLayoutStyleInfo
operator|::
name|invalidate
argument_list|()
block|;     }
name|virtual
name|bool
name|hasChangedCore
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
name|QStyle
operator|*
name|s
operator|=
name|m_style
block|;
comment|// Note that style() will change m_style
return|return
name|s
operator|!=
name|style
argument_list|()
return|;
block|}
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
name|QStyle
operator|*
name|style
argument_list|()
specifier|const
block|;
name|private
operator|:
specifier|const
name|QGraphicsLayoutPrivate
operator|*
name|m_layout
block|;
name|mutable
name|QStyle
operator|*
name|m_style
block|;
name|QStyleOption
name|m_styleOption
block|;
name|QWidget
operator|*
name|m_widget
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
comment|// QGRAPHICSLAYOUTSTYLEINFO_P_H
end_comment
end_unit
