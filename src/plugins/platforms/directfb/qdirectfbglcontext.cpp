begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfbglcontext.h"
end_include
begin_include
include|#
directive|include
file|<directfbgl.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QDirectFbGLContext
name|QDirectFbGLContext
operator|::
name|QDirectFbGLContext
parameter_list|(
name|IDirectFBGL
modifier|*
name|glContext
parameter_list|)
member_init_list|:
name|m_dfbGlContext
argument_list|(
name|glContext
argument_list|)
block|{
name|DFBResult
name|result
decl_stmt|;
name|DFBGLAttributes
name|glAttribs
decl_stmt|;
name|result
operator|=
name|m_dfbGlContext
operator|->
name|GetAttributes
argument_list|(
name|glContext
argument_list|,
operator|&
name|glAttribs
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|DFB_OK
condition|)
block|{
name|m_windowFormat
operator|.
name|setDepthBufferSize
argument_list|(
name|glAttribs
operator|.
name|depth_size
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setStencilBufferSize
argument_list|(
name|glAttribs
operator|.
name|stencil_size
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setRedBufferSize
argument_list|(
name|glAttribs
operator|.
name|red_size
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setGreenBufferSize
argument_list|(
name|glAttribs
operator|.
name|green_size
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setBlueBufferSize
argument_list|(
name|glAttribs
operator|.
name|blue_size
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setAlphaBufferSize
argument_list|(
name|glAttribs
operator|.
name|alpha_size
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setAccumBufferSize
argument_list|(
name|glAttribs
operator|.
name|accum_red_size
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setAlpha
argument_list|(
name|glAttribs
operator|.
name|accum_alpha_size
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setDoubleBuffer
argument_list|(
name|glAttribs
operator|.
name|double_buffer
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|.
name|setStereo
argument_list|(
name|glAttribs
operator|.
name|stereo
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|makeCurrent
name|void
name|QDirectFbGLContext
operator|::
name|makeCurrent
parameter_list|()
block|{
name|QPlatformOpenGLContext
operator|::
name|makeCurrent
argument_list|()
expr_stmt|;
name|m_dfbGlContext
operator|->
name|Lock
argument_list|(
name|m_dfbGlContext
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QDirectFbGLContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|QPlatformOpenGLContext
operator|::
name|doneCurrent
argument_list|()
expr_stmt|;
name|m_dfbGlContext
operator|->
name|Unlock
argument_list|(
name|m_dfbGlContext
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getProcAddress
name|void
modifier|*
name|QDirectFbGLContext
operator|::
name|getProcAddress
parameter_list|(
specifier|const
name|QString
modifier|&
name|procName
parameter_list|)
block|{
name|void
modifier|*
name|proc
decl_stmt|;
name|DFBResult
name|result
init|=
name|m_dfbGlContext
operator|->
name|GetProcAddress
argument_list|(
name|m_dfbGlContext
argument_list|,
name|qPrintable
argument_list|(
name|procName
argument_list|)
argument_list|,
operator|&
name|proc
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
name|DFB_OK
condition|)
return|return
name|proc
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QDirectFbGLContext
operator|::
name|swapBuffers
parameter_list|()
block|{
comment|//    m_dfbGlContext->Unlock(m_dfbGlContext); //maybe not in doneCurrent()
name|qDebug
argument_list|()
operator|<<
literal|"Swap buffers"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformWindowFormat
name|QPlatformWindowFormat
name|QDirectFbGLContext
operator|::
name|platformWindowFormat
parameter_list|()
specifier|const
block|{
return|return
name|m_windowFormat
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
