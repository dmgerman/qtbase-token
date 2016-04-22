begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLCONVENIENCE_H
end_ifndef
begin_define
DECL|macro|QEGLCONVENIENCE_H
define|#
directive|define
name|QEGLCONVENIENCE_H
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
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSizeF>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qt_egl_p.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|QVector
operator|<
name|EGLint
operator|>
name|q_createConfigAttributesFromFormat
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|q_reduceConfigAttributes
argument_list|(
name|QVector
operator|<
name|EGLint
operator|>
operator|*
name|configAttributes
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|EGLConfig
name|q_configFromGLFormat
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|bool
name|highestPixelFormat
init|=
name|false
parameter_list|,
name|int
name|surfaceType
init|=
name|EGL_WINDOW_BIT
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QSurfaceFormat
name|q_glFormatFromConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
specifier|const
name|EGLConfig
name|config
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|referenceFormat
init|=
name|QSurfaceFormat
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|q_hasEglExtension
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
specifier|const
name|char
modifier|*
name|extensionName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|q_printEglConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLConfig
name|config
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_function_decl
name|QSizeF
name|q_physicalScreenSizeFromFb
parameter_list|(
name|int
name|framebufferDevice
parameter_list|,
specifier|const
name|QSize
modifier|&
name|screenSize
init|=
name|QSize
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QSize
name|q_screenSizeFromFb
parameter_list|(
name|int
name|framebufferDevice
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|q_screenDepthFromFb
parameter_list|(
name|int
name|framebufferDevice
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|qreal
name|q_refreshRateFromFb
parameter_list|(
name|int
name|framebufferDevice
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QEglConfigChooser
block|{
name|public
label|:
name|QEglConfigChooser
argument_list|(
argument|EGLDisplay display
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|QEglConfigChooser
argument_list|()
expr_stmt|;
name|EGLDisplay
name|display
argument_list|()
specifier|const
block|{
return|return
name|m_display
return|;
block|}
name|void
name|setSurfaceType
parameter_list|(
name|EGLint
name|surfaceType
parameter_list|)
block|{
name|m_surfaceType
operator|=
name|surfaceType
expr_stmt|;
block|}
name|EGLint
name|surfaceType
argument_list|()
specifier|const
block|{
return|return
name|m_surfaceType
return|;
block|}
name|void
name|setSurfaceFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|m_format
operator|=
name|format
expr_stmt|;
block|}
name|QSurfaceFormat
name|surfaceFormat
argument_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
name|void
name|setIgnoreColorChannels
parameter_list|(
name|bool
name|ignore
parameter_list|)
block|{
name|m_ignore
operator|=
name|ignore
expr_stmt|;
block|}
name|bool
name|ignoreColorChannels
argument_list|()
specifier|const
block|{
return|return
name|m_ignore
return|;
block|}
name|EGLConfig
name|chooseConfig
parameter_list|()
function_decl|;
name|protected
label|:
name|virtual
name|bool
name|filterConfig
argument_list|(
name|EGLConfig
name|config
argument_list|)
decl|const
decl_stmt|;
name|QSurfaceFormat
name|m_format
decl_stmt|;
name|EGLDisplay
name|m_display
decl_stmt|;
name|EGLint
name|m_surfaceType
decl_stmt|;
name|bool
name|m_ignore
decl_stmt|;
name|int
name|m_confAttrRed
decl_stmt|;
name|int
name|m_confAttrGreen
decl_stmt|;
name|int
name|m_confAttrBlue
decl_stmt|;
name|int
name|m_confAttrAlpha
decl_stmt|;
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
comment|//QEGLCONVENIENCE_H
end_comment
end_unit
