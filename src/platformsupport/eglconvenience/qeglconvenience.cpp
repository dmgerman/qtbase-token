begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|"qeglconvenience_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|q_createConfigAttributesFromFormat
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|q_createConfigAttributesFromFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|int
name|redSize
init|=
name|format
operator|.
name|redBufferSize
argument_list|()
decl_stmt|;
name|int
name|greenSize
init|=
name|format
operator|.
name|greenBufferSize
argument_list|()
decl_stmt|;
name|int
name|blueSize
init|=
name|format
operator|.
name|blueBufferSize
argument_list|()
decl_stmt|;
name|int
name|alphaSize
init|=
name|format
operator|.
name|alphaBufferSize
argument_list|()
decl_stmt|;
name|int
name|depthSize
init|=
name|format
operator|.
name|depthBufferSize
argument_list|()
decl_stmt|;
name|int
name|stencilSize
init|=
name|format
operator|.
name|stencilBufferSize
argument_list|()
decl_stmt|;
name|int
name|sampleCount
init|=
name|format
operator|.
name|samples
argument_list|()
decl_stmt|;
comment|// We want to make sure 16-bit configs are chosen over 32-bit configs as they will provide
comment|// the best performance. The EGL config selection algorithm is a bit stange in this regard:
comment|// The selection criteria for EGL_BUFFER_SIZE is "AtLeast", so we can't use it to discard
comment|// 32-bit configs completely from the selection. So it then comes to the sorting algorithm.
comment|// The red/green/blue sizes have a sort priority of 3, so they are sorted by first. The sort
comment|// order is special and described as "by larger _total_ number of color bits.". So EGL will
comment|// put 32-bit configs in the list before the 16-bit configs. However, the spec also goes on
comment|// to say "If the requested number of bits in attrib_list for a particular component is 0,
comment|// then the number of bits for that component is not considered". This part of the spec also
comment|// seems to imply that setting the red/green/blue bits to zero means none of the components
comment|// are considered and EGL disregards the entire sorting rule. It then looks to the next
comment|// highest priority rule, which is EGL_BUFFER_SIZE. Despite the selection criteria being
comment|// "AtLeast" for EGL_BUFFER_SIZE, it's sort order is "smaller" meaning 16-bit configs are
comment|// put in the list before 32-bit configs. So, to make sure 16-bit is preffered over 32-bit,
comment|// we must set the red/green/blue sizes to zero. This has an unfortunate consequence that
comment|// if the application sets the red/green/blue size to 5/6/5 on the QSurfaceFormat,
comment|// they will probably get a 32-bit config, even when there's an RGB565 config available.
comment|//    // Now normalize the values so -1 becomes 0
comment|//    redSize   = redSize> 0 ? redSize   : 0;
comment|//    greenSize = greenSize> 0 ? greenSize : 0;
comment|//    blueSize  = blueSize> 0 ? blueSize  : 0;
comment|//    alphaSize = alphaSize> 0 ? alphaSize : 0;
comment|//    depthSize = depthSize> 0 ? depthSize : 0;
comment|//    stencilSize = stencilSize> 0 ? stencilSize : 0;
comment|//    sampleCount = sampleCount> 0 ? sampleCount : 0;
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|configAttributes
decl_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|EGL_RED_SIZE
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|redSize
operator|>
literal|0
condition|?
name|redSize
else|:
literal|0
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|EGL_GREEN_SIZE
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|greenSize
operator|>
literal|0
condition|?
name|greenSize
else|:
literal|0
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|EGL_BLUE_SIZE
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|blueSize
operator|>
literal|0
condition|?
name|blueSize
else|:
literal|0
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|EGL_ALPHA_SIZE
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|alphaSize
operator|>
literal|0
condition|?
name|alphaSize
else|:
literal|0
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|EGL_DEPTH_SIZE
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|depthSize
operator|>
literal|0
condition|?
name|depthSize
else|:
literal|0
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|EGL_STENCIL_SIZE
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|stencilSize
operator|>
literal|0
condition|?
name|stencilSize
else|:
literal|0
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|EGL_SAMPLES
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|sampleCount
operator|>
literal|0
condition|?
name|sampleCount
else|:
literal|0
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|EGL_SAMPLE_BUFFERS
argument_list|)
expr_stmt|;
name|configAttributes
operator|.
name|append
argument_list|(
name|sampleCount
operator|>
literal|0
argument_list|)
expr_stmt|;
return|return
name|configAttributes
return|;
block|}
end_function
begin_function
DECL|function|q_reduceConfigAttributes
name|bool
name|q_reduceConfigAttributes
parameter_list|(
name|QVector
argument_list|<
name|EGLint
argument_list|>
modifier|*
name|configAttributes
parameter_list|)
block|{
name|int
name|i
init|=
operator|-
literal|1
decl_stmt|;
comment|// Reduce the complexity of a configuration request to ask for less
comment|// because the previous request did not result in success.  Returns
comment|// true if the complexity was reduced, or false if no further
comment|// reductions in complexity are possible.
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_SWAP_BEHAVIOR
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
name|configAttributes
operator|->
name|remove
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
comment|// For OpenVG, we sometimes try to create a surface using a pre-multiplied format. If we can't
comment|// find a config which supports pre-multiplied formats, remove the flag on the surface type:
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_SURFACE_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
name|EGLint
name|surfaceType
init|=
name|configAttributes
operator|->
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|surfaceType
operator|&
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
condition|)
block|{
name|surfaceType
operator|^=
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
expr_stmt|;
name|configAttributes
operator|->
name|replace
argument_list|(
name|i
operator|+
literal|1
argument_list|,
name|surfaceType
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
endif|#
directive|endif
comment|// EGL chooses configs with the highest color depth over
comment|// those with smaller (but faster) lower color depths. One
comment|// way around this is to set EGL_BUFFER_SIZE to 16, which
comment|// trumps the others. Of course, there may not be a 16-bit
comment|// config available, so it's the first restraint we remove.
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_BUFFER_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|configAttributes
operator|->
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|==
literal|16
condition|)
block|{
name|configAttributes
operator|->
name|remove
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_SAMPLES
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
name|EGLint
name|value
init|=
name|configAttributes
operator|->
name|value
argument_list|(
name|i
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|value
operator|>
literal|1
condition|)
name|configAttributes
operator|->
name|replace
argument_list|(
name|i
operator|+
literal|1
argument_list|,
name|qMin
argument_list|(
name|EGLint
argument_list|(
literal|16
argument_list|)
argument_list|,
name|value
operator|/
literal|2
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|configAttributes
operator|->
name|remove
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_SAMPLE_BUFFERS
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
name|configAttributes
operator|->
name|remove
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_ALPHA_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
name|configAttributes
operator|->
name|remove
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGBA
argument_list|)
operator|&&
name|defined
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|)
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGBA
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
name|configAttributes
operator|->
name|replace
argument_list|(
name|i
argument_list|,
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|)
expr_stmt|;
name|configAttributes
operator|->
name|replace
argument_list|(
name|i
operator|+
literal|1
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
literal|true
return|;
block|}
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_STENCIL_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|configAttributes
operator|->
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|>
literal|1
condition|)
name|configAttributes
operator|->
name|replace
argument_list|(
name|i
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|configAttributes
operator|->
name|remove
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_DEPTH_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|configAttributes
operator|->
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|>
literal|1
condition|)
name|configAttributes
operator|->
name|replace
argument_list|(
name|i
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|configAttributes
operator|->
name|remove
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
ifdef|#
directive|ifdef
name|EGL_BIND_TO_TEXTURE_RGB
name|i
operator|=
name|configAttributes
operator|->
name|indexOf
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
block|{
name|configAttributes
operator|->
name|remove
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|q_configFromGLFormat
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
parameter_list|,
name|int
name|surfaceType
parameter_list|)
block|{
name|EGLConfig
name|cfg
init|=
literal|0
decl_stmt|;
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|configureAttributes
init|=
name|q_createConfigAttributesFromFormat
argument_list|(
name|format
argument_list|)
decl_stmt|;
name|configureAttributes
operator|.
name|append
argument_list|(
name|EGL_SURFACE_TYPE
argument_list|)
expr_stmt|;
name|configureAttributes
operator|.
name|append
argument_list|(
name|surfaceType
argument_list|)
expr_stmt|;
name|configureAttributes
operator|.
name|append
argument_list|(
name|EGL_RENDERABLE_TYPE
argument_list|)
expr_stmt|;
name|configureAttributes
operator|.
name|append
argument_list|(
name|format
operator|.
name|majorVersion
argument_list|()
operator|==
literal|1
condition|?
name|EGL_OPENGL_ES_BIT
else|:
name|EGL_OPENGL_ES2_BIT
argument_list|)
expr_stmt|;
name|configureAttributes
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
do|do
block|{
comment|// Get the number of matching configurations for this set of properties.
name|EGLint
name|matching
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|eglChooseConfig
argument_list|(
name|display
argument_list|,
name|configureAttributes
operator|.
name|constData
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|matching
argument_list|)
operator|||
operator|!
name|matching
condition|)
continue|continue;
comment|// If we want the best pixel format, then return the first
comment|// matching configuration.
if|if
condition|(
name|highestPixelFormat
condition|)
block|{
name|eglChooseConfig
argument_list|(
name|display
argument_list|,
name|configureAttributes
operator|.
name|constData
argument_list|()
argument_list|,
operator|&
name|cfg
argument_list|,
literal|1
argument_list|,
operator|&
name|matching
argument_list|)
expr_stmt|;
if|if
condition|(
name|matching
operator|<
literal|1
condition|)
continue|continue;
return|return
name|cfg
return|;
block|}
comment|// Fetch all of the matching configurations and find the
comment|// first that matches the pixel format we wanted.
name|int
name|i
init|=
name|configureAttributes
operator|.
name|indexOf
argument_list|(
name|EGL_RED_SIZE
argument_list|)
decl_stmt|;
name|int
name|confAttrRed
init|=
name|configureAttributes
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
decl_stmt|;
name|i
operator|=
name|configureAttributes
operator|.
name|indexOf
argument_list|(
name|EGL_GREEN_SIZE
argument_list|)
expr_stmt|;
name|int
name|confAttrGreen
init|=
name|configureAttributes
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
decl_stmt|;
name|i
operator|=
name|configureAttributes
operator|.
name|indexOf
argument_list|(
name|EGL_BLUE_SIZE
argument_list|)
expr_stmt|;
name|int
name|confAttrBlue
init|=
name|configureAttributes
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
decl_stmt|;
name|i
operator|=
name|configureAttributes
operator|.
name|indexOf
argument_list|(
name|EGL_ALPHA_SIZE
argument_list|)
expr_stmt|;
name|int
name|confAttrAlpha
init|=
name|i
operator|==
operator|-
literal|1
condition|?
literal|0
else|:
name|configureAttributes
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
decl_stmt|;
name|EGLint
name|size
init|=
name|matching
decl_stmt|;
name|EGLConfig
modifier|*
name|configs
init|=
operator|new
name|EGLConfig
index|[
name|size
index|]
decl_stmt|;
name|eglChooseConfig
argument_list|(
name|display
argument_list|,
name|configureAttributes
operator|.
name|constData
argument_list|()
argument_list|,
name|configs
argument_list|,
name|size
argument_list|,
operator|&
name|matching
argument_list|)
expr_stmt|;
for|for
control|(
name|EGLint
name|index
init|=
literal|0
init|;
name|index
operator|<
name|size
condition|;
operator|++
name|index
control|)
block|{
name|EGLint
name|red
decl_stmt|,
name|green
decl_stmt|,
name|blue
decl_stmt|,
name|alpha
decl_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|configs
index|[
name|index
index|]
argument_list|,
name|EGL_RED_SIZE
argument_list|,
operator|&
name|red
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|configs
index|[
name|index
index|]
argument_list|,
name|EGL_GREEN_SIZE
argument_list|,
operator|&
name|green
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|configs
index|[
name|index
index|]
argument_list|,
name|EGL_BLUE_SIZE
argument_list|,
operator|&
name|blue
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|configs
index|[
name|index
index|]
argument_list|,
name|EGL_ALPHA_SIZE
argument_list|,
operator|&
name|alpha
argument_list|)
expr_stmt|;
if|if
condition|(
name|red
operator|==
name|confAttrRed
operator|&&
name|green
operator|==
name|confAttrGreen
operator|&&
name|blue
operator|==
name|confAttrBlue
operator|&&
operator|(
name|confAttrAlpha
operator|==
literal|0
operator|||
name|alpha
operator|==
name|confAttrAlpha
operator|)
condition|)
block|{
name|cfg
operator|=
name|configs
index|[
name|index
index|]
expr_stmt|;
operator|delete
index|[]
name|configs
expr_stmt|;
return|return
name|cfg
return|;
block|}
block|}
operator|delete
index|[]
name|configs
expr_stmt|;
block|}
do|while
condition|(
name|q_reduceConfigAttributes
argument_list|(
operator|&
name|configureAttributes
argument_list|)
condition|)
do|;
name|qWarning
argument_list|(
literal|"Cant find EGLConfig, returning null config"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|q_glFormatFromConfig
name|QSurfaceFormat
name|q_glFormatFromConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
specifier|const
name|EGLConfig
name|config
parameter_list|)
block|{
name|QSurfaceFormat
name|format
decl_stmt|;
name|EGLint
name|redSize
init|=
literal|0
decl_stmt|;
name|EGLint
name|greenSize
init|=
literal|0
decl_stmt|;
name|EGLint
name|blueSize
init|=
literal|0
decl_stmt|;
name|EGLint
name|alphaSize
init|=
literal|0
decl_stmt|;
name|EGLint
name|depthSize
init|=
literal|0
decl_stmt|;
name|EGLint
name|stencilSize
init|=
literal|0
decl_stmt|;
name|EGLint
name|sampleCount
init|=
literal|0
decl_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|EGL_RED_SIZE
argument_list|,
operator|&
name|redSize
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|EGL_GREEN_SIZE
argument_list|,
operator|&
name|greenSize
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|EGL_BLUE_SIZE
argument_list|,
operator|&
name|blueSize
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|EGL_ALPHA_SIZE
argument_list|,
operator|&
name|alphaSize
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|EGL_DEPTH_SIZE
argument_list|,
operator|&
name|depthSize
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|EGL_STENCIL_SIZE
argument_list|,
operator|&
name|stencilSize
argument_list|)
expr_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|EGL_SAMPLES
argument_list|,
operator|&
name|sampleCount
argument_list|)
expr_stmt|;
name|format
operator|.
name|setRedBufferSize
argument_list|(
name|redSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setGreenBufferSize
argument_list|(
name|greenSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setBlueBufferSize
argument_list|(
name|blueSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setAlphaBufferSize
argument_list|(
name|alphaSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setDepthBufferSize
argument_list|(
name|depthSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setStencilBufferSize
argument_list|(
name|stencilSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setSamples
argument_list|(
name|sampleCount
argument_list|)
expr_stmt|;
name|format
operator|.
name|setStereo
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// EGL doesn't support stereo buffers
comment|// Clear the EGL error state because some of the above may
comment|// have errored out because the attribute is not applicable
comment|// to the surface type.  Such errors don't matter.
name|eglGetError
argument_list|()
expr_stmt|;
return|return
name|format
return|;
block|}
end_function
begin_function
DECL|function|q_hasEglExtension
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
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|extensions
init|=
name|QByteArray
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|eglQueryString
argument_list|(
name|display
argument_list|,
name|EGL_EXTENSIONS
argument_list|)
argument_list|)
argument_list|)
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
return|return
name|extensions
operator|.
name|contains
argument_list|(
name|extensionName
argument_list|)
return|;
block|}
end_function
begin_struct
DECL|struct|AttrInfo
DECL|member|attr
DECL|member|name
struct|struct
name|AttrInfo
block|{
name|EGLint
name|attr
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|attrs
specifier|static
name|struct
name|AttrInfo
name|attrs
index|[]
init|=
block|{
block|{
name|EGL_BUFFER_SIZE
block|,
literal|"EGL_BUFFER_SIZE"
block|}
block|,
block|{
name|EGL_ALPHA_SIZE
block|,
literal|"EGL_ALPHA_SIZE"
block|}
block|,
block|{
name|EGL_BLUE_SIZE
block|,
literal|"EGL_BLUE_SIZE"
block|}
block|,
block|{
name|EGL_GREEN_SIZE
block|,
literal|"EGL_GREEN_SIZE"
block|}
block|,
block|{
name|EGL_RED_SIZE
block|,
literal|"EGL_RED_SIZE"
block|}
block|,
block|{
name|EGL_DEPTH_SIZE
block|,
literal|"EGL_DEPTH_SIZE"
block|}
block|,
block|{
name|EGL_STENCIL_SIZE
block|,
literal|"EGL_STENCIL_SIZE"
block|}
block|,
block|{
name|EGL_CONFIG_CAVEAT
block|,
literal|"EGL_CONFIG_CAVEAT"
block|}
block|,
block|{
name|EGL_CONFIG_ID
block|,
literal|"EGL_CONFIG_ID"
block|}
block|,
block|{
name|EGL_LEVEL
block|,
literal|"EGL_LEVEL"
block|}
block|,
block|{
name|EGL_MAX_PBUFFER_HEIGHT
block|,
literal|"EGL_MAX_PBUFFER_HEIGHT"
block|}
block|,
block|{
name|EGL_MAX_PBUFFER_PIXELS
block|,
literal|"EGL_MAX_PBUFFER_PIXELS"
block|}
block|,
block|{
name|EGL_MAX_PBUFFER_WIDTH
block|,
literal|"EGL_MAX_PBUFFER_WIDTH"
block|}
block|,
block|{
name|EGL_NATIVE_RENDERABLE
block|,
literal|"EGL_NATIVE_RENDERABLE"
block|}
block|,
block|{
name|EGL_NATIVE_VISUAL_ID
block|,
literal|"EGL_NATIVE_VISUAL_ID"
block|}
block|,
block|{
name|EGL_NATIVE_VISUAL_TYPE
block|,
literal|"EGL_NATIVE_VISUAL_TYPE"
block|}
block|,
block|{
name|EGL_SAMPLES
block|,
literal|"EGL_SAMPLES"
block|}
block|,
block|{
name|EGL_SAMPLE_BUFFERS
block|,
literal|"EGL_SAMPLE_BUFFERS"
block|}
block|,
block|{
name|EGL_SURFACE_TYPE
block|,
literal|"EGL_SURFACE_TYPE"
block|}
block|,
block|{
name|EGL_TRANSPARENT_TYPE
block|,
literal|"EGL_TRANSPARENT_TYPE"
block|}
block|,
block|{
name|EGL_TRANSPARENT_BLUE_VALUE
block|,
literal|"EGL_TRANSPARENT_BLUE_VALUE"
block|}
block|,
block|{
name|EGL_TRANSPARENT_GREEN_VALUE
block|,
literal|"EGL_TRANSPARENT_GREEN_VALUE"
block|}
block|,
block|{
name|EGL_TRANSPARENT_RED_VALUE
block|,
literal|"EGL_TRANSPARENT_RED_VALUE"
block|}
block|,
block|{
name|EGL_BIND_TO_TEXTURE_RGB
block|,
literal|"EGL_BIND_TO_TEXTURE_RGB"
block|}
block|,
block|{
name|EGL_BIND_TO_TEXTURE_RGBA
block|,
literal|"EGL_BIND_TO_TEXTURE_RGBA"
block|}
block|,
block|{
name|EGL_MIN_SWAP_INTERVAL
block|,
literal|"EGL_MIN_SWAP_INTERVAL"
block|}
block|,
block|{
name|EGL_MAX_SWAP_INTERVAL
block|,
literal|"EGL_MAX_SWAP_INTERVAL"
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|q_printEglConfig
name|void
name|q_printEglConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLConfig
name|config
parameter_list|)
block|{
name|EGLint
name|index
decl_stmt|;
for|for
control|(
name|index
operator|=
literal|0
init|;
name|attrs
index|[
name|index
index|]
operator|.
name|attr
operator|!=
operator|-
literal|1
condition|;
operator|++
name|index
control|)
block|{
name|EGLint
name|value
decl_stmt|;
if|if
condition|(
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|attrs
index|[
name|index
index|]
operator|.
name|attr
argument_list|,
operator|&
name|value
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"\t%s: %d\n"
argument_list|,
name|attrs
index|[
name|index
index|]
operator|.
name|name
argument_list|,
operator|(
name|int
operator|)
name|value
argument_list|)
expr_stmt|;
block|}
block|}
name|qWarning
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
