begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLPAINTDEVICE_H
end_ifndef
begin_define
DECL|macro|QOPENGLPAINTDEVICE_H
define|#
directive|define
name|QOPENGLPAINTDEVICE_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QtGui module.  This header file may change from
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
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglcontext.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLPaintDevicePrivate
name|class
name|QOpenGLPaintDevicePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLPaintDevice
range|:
name|public
name|QPaintDevice
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLPaintDevice
argument_list|)
name|public
operator|:
name|explicit
name|QOpenGLPaintDevice
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|QOpenGLPaintDevice
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|virtual
operator|~
name|QOpenGLPaintDevice
argument_list|()
block|;
name|int
name|devType
argument_list|()
specifier|const
block|{
return|return
name|QInternal
operator|::
name|OpenGL
return|;
block|}
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|QOpenGLContext
operator|*
name|context
argument_list|()
specifier|const
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|qreal
name|dotsPerMeterX
argument_list|()
specifier|const
block|;
name|qreal
name|dotsPerMeterY
argument_list|()
specifier|const
block|;
name|void
name|setDotsPerMeterX
argument_list|(
name|qreal
argument_list|)
block|;
name|void
name|setDotsPerMeterY
argument_list|(
name|qreal
argument_list|)
block|;
name|void
name|setPaintFlipped
argument_list|(
argument|bool flipped
argument_list|)
block|;
name|bool
name|paintFlipped
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|QPaintDevice::PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLPaintDevice
argument_list|)
name|QScopedPointer
operator|<
name|QOpenGLPaintDevicePrivate
operator|>
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGLPAINTDEVICE_H
end_comment
end_unit
