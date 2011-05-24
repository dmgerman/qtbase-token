begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenVG module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSURFACE_VGEGL_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSURFACE_VGEGL_P_H
define|#
directive|define
name|QWINDOWSURFACE_VGEGL_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|<QtGui/private/qwindowsurface_p.h>
end_include
begin_include
include|#
directive|include
file|"qvg_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtGui/private/qeglcontext_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowSurface
name|class
name|QWindowSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENVG_EXPORT
name|QVGEGLWindowSurfacePrivate
block|{
name|public
label|:
name|QVGEGLWindowSurfacePrivate
argument_list|(
name|QWindowSurface
operator|*
name|win
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QVGEGLWindowSurfacePrivate
argument_list|()
expr_stmt|;
name|QVGPaintEngine
modifier|*
name|paintEngine
parameter_list|()
function_decl|;
name|virtual
name|QEglContext
modifier|*
name|ensureContext
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|beginPaint
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|endPaint
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
name|QImage
modifier|*
name|image
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|VGImage
name|surfaceImage
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QSize
name|surfaceSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|supportsStaticContents
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|scroll
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
specifier|const
name|QRegion
modifier|&
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{
return|return
name|false
return|;
block|}
name|private
label|:
name|QVGPaintEngine
modifier|*
name|engine
decl_stmt|;
name|protected
label|:
name|QWindowSurface
modifier|*
name|winSurface
decl_stmt|;
name|void
name|destroyPaintEngine
parameter_list|()
function_decl|;
name|QSize
name|windowSurfaceSize
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|EGL_OPENVG_IMAGE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QVG_NO_SINGLE_CONTEXT
argument_list|)
end_if
begin_define
DECL|macro|QVG_VGIMAGE_BACKBUFFERS
define|#
directive|define
name|QVG_VGIMAGE_BACKBUFFERS
value|1
end_define
begin_decl_stmt
name|class
name|Q_OPENVG_EXPORT
name|QVGEGLWindowSurfaceVGImage
range|:
name|public
name|QVGEGLWindowSurfacePrivate
block|{
name|public
operator|:
name|QVGEGLWindowSurfaceVGImage
argument_list|(
name|QWindowSurface
operator|*
name|win
argument_list|)
block|;
name|virtual
operator|~
name|QVGEGLWindowSurfaceVGImage
argument_list|()
block|;
name|QEglContext
operator|*
name|ensureContext
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|beginPaint
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|endPaint
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
name|QImage
operator|*
name|image
argument_list|)
block|;
name|VGImage
name|surfaceImage
argument_list|()
specifier|const
block|;
name|QSize
name|surfaceSize
argument_list|()
specifier|const
block|{
return|return
name|size
return|;
block|}
name|protected
operator|:
name|QEglContext
operator|*
name|context
block|;
name|VGImage
name|backBuffer
block|;
name|EGLSurface
name|backBufferSurface
block|;
name|bool
name|recreateBackBuffer
block|;
name|bool
name|isPaintingActive
block|;
name|QSize
name|size
block|;
name|EGLSurface
name|windowSurface
block|;
name|EGLSurface
name|mainSurface
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// EGL_OPENVG_IMAGE
end_comment
begin_decl_stmt
name|class
name|Q_OPENVG_EXPORT
name|QVGEGLWindowSurfaceDirect
range|:
name|public
name|QVGEGLWindowSurfacePrivate
block|{
name|public
operator|:
name|QVGEGLWindowSurfaceDirect
argument_list|(
name|QWindowSurface
operator|*
name|win
argument_list|)
block|;
name|virtual
operator|~
name|QVGEGLWindowSurfaceDirect
argument_list|()
block|;
name|QEglContext
operator|*
name|ensureContext
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|beginPaint
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|endPaint
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
name|QImage
operator|*
name|image
argument_list|)
block|;
name|QSize
name|surfaceSize
argument_list|()
specifier|const
block|{
return|return
name|size
return|;
block|}
name|bool
name|supportsStaticContents
argument_list|()
specifier|const
block|;
name|bool
name|scroll
argument_list|(
argument|QWidget *widget
argument_list|,
argument|const QRegion& area
argument_list|,
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|protected
operator|:
name|QEglContext
operator|*
name|context
block|;
name|QSize
name|size
block|;
name|bool
name|isPaintingActive
block|;
name|bool
name|needToSwap
block|;
name|EGLSurface
name|windowSurface
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
comment|// !QT_NO_EGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSURFACE_VGEGL_P_H
end_comment
end_unit
