begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDDRMSURFACE_H
end_ifndef
begin_define
DECL|macro|QWAYLANDDRMSURFACE_H
define|#
directive|define
name|QWAYLANDDRMSURFACE_H
end_define
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qwindowsurface_p.h>
end_include
begin_decl_stmt
DECL|variable|QGLFramebufferObject
name|class
name|QGLFramebufferObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWaylandGLWindowSurface
range|:
name|public
name|QWindowSurface
block|{
name|public
operator|:
name|QWaylandGLWindowSurface
argument_list|(
name|QWidget
operator|*
name|window
argument_list|)
block|;
operator|~
name|QWaylandGLWindowSurface
argument_list|()
block|;
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
argument_list|)
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|;
name|void
name|flush
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|void
name|resize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|private
operator|:
name|QWaylandDisplay
operator|*
name|mDisplay
block|;
name|QGLFramebufferObject
operator|*
name|mPaintDevice
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDDRMSURFACE_H
end_comment
end_unit
