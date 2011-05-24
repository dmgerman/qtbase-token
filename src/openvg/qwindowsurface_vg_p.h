begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenVG module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSURFACE_VG_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSURFACE_VG_P_H
define|#
directive|define
name|QWINDOWSURFACE_VG_P_H
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
file|<QtGui/private/qwindowsurface_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EGL
argument_list|)
DECL|variable|QVGEGLWindowSurfacePrivate
name|class
name|QVGEGLWindowSurfacePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowSurface
name|class
name|Q_OPENVG_EXPORT
name|QVGWindowSurface
range|:
name|public
name|QWindowSurface
decl_stmt|,
name|public
name|QPaintDevice
block|{
name|public
label|:
name|QVGWindowSurface
argument_list|(
name|QWidget
operator|*
name|window
argument_list|)
expr_stmt|;
name|QVGWindowSurface
argument_list|(
name|QWidget
operator|*
name|window
argument_list|,
name|QVGEGLWindowSurfacePrivate
operator|*
name|d
argument_list|)
expr_stmt|;
operator|~
name|QVGWindowSurface
argument_list|()
expr_stmt|;
name|QPaintDevice
modifier|*
name|paintDevice
parameter_list|()
function_decl|;
name|void
name|flush
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
function_decl|;
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|bool
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
function_decl|;
name|void
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|void
name|endPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
expr_stmt|;
name|WindowSurfaceFeatures
name|features
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|int
name|metric
argument_list|(
name|PaintDeviceMetric
name|metric
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|QVGEGLWindowSurfacePrivate
modifier|*
name|d_ptr
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSURFACE_VG_P_H
end_comment
end_unit
