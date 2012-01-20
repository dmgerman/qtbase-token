begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"qeglproperties_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglcontext_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|// Initialize a property block.
DECL|function|QEglProperties
name|QEglProperties
operator|::
name|QEglProperties
parameter_list|()
block|{
name|props
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QEglProperties
name|QEglProperties
operator|::
name|QEglProperties
parameter_list|(
name|EGLConfig
name|cfg
parameter_list|)
block|{
name|props
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|name
init|=
literal|0x3020
init|;
name|name
operator|<=
literal|0x304F
condition|;
operator|++
name|name
control|)
block|{
name|EGLint
name|value
decl_stmt|;
if|if
condition|(
name|name
operator|!=
name|EGL_NONE
operator|&&
name|eglGetConfigAttrib
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
name|cfg
argument_list|,
name|name
argument_list|,
operator|&
name|value
argument_list|)
condition|)
name|setValue
argument_list|(
name|name
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
name|eglGetError
argument_list|()
expr_stmt|;
comment|// Clear the error state.
block|}
end_constructor
begin_comment
comment|// Fetch the current value associated with a property.
end_comment
begin_function
DECL|function|value
name|int
name|QEglProperties
operator|::
name|value
parameter_list|(
name|int
name|name
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
operator|(
name|props
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|)
condition|;
name|index
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|props
index|[
name|index
index|]
operator|==
name|name
condition|)
return|return
name|props
index|[
name|index
operator|+
literal|1
index|]
return|;
block|}
comment|// If the attribute has not been explicitly set, return the EGL default
comment|// The following defaults were taken from the EGL 1.4 spec:
switch|switch
condition|(
name|name
condition|)
block|{
case|case
name|EGL_BUFFER_SIZE
case|:
return|return
literal|0
return|;
case|case
name|EGL_RED_SIZE
case|:
return|return
literal|0
return|;
case|case
name|EGL_GREEN_SIZE
case|:
return|return
literal|0
return|;
case|case
name|EGL_BLUE_SIZE
case|:
return|return
literal|0
return|;
case|case
name|EGL_ALPHA_SIZE
case|:
return|return
literal|0
return|;
ifdef|#
directive|ifdef
name|EGL_LUMINANCE_SIZE
case|case
name|EGL_LUMINANCE_SIZE
case|:
return|return
literal|0
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_ALPHA_MASK_SIZE
case|case
name|EGL_ALPHA_MASK_SIZE
case|:
return|return
literal|0
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_BIND_TO_TEXTURE_RGB
case|case
name|EGL_BIND_TO_TEXTURE_RGB
case|:
return|return
name|EGL_DONT_CARE
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_BIND_TO_TEXTURE_RGBA
case|case
name|EGL_BIND_TO_TEXTURE_RGBA
case|:
return|return
name|EGL_DONT_CARE
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_COLOR_BUFFER_TYPE
case|case
name|EGL_COLOR_BUFFER_TYPE
case|:
return|return
name|EGL_RGB_BUFFER
return|;
endif|#
directive|endif
case|case
name|EGL_CONFIG_CAVEAT
case|:
return|return
name|EGL_DONT_CARE
return|;
case|case
name|EGL_CONFIG_ID
case|:
return|return
name|EGL_DONT_CARE
return|;
case|case
name|EGL_DEPTH_SIZE
case|:
return|return
literal|0
return|;
case|case
name|EGL_LEVEL
case|:
return|return
literal|0
return|;
case|case
name|EGL_NATIVE_RENDERABLE
case|:
return|return
name|EGL_DONT_CARE
return|;
case|case
name|EGL_NATIVE_VISUAL_TYPE
case|:
return|return
name|EGL_DONT_CARE
return|;
case|case
name|EGL_MAX_SWAP_INTERVAL
case|:
return|return
name|EGL_DONT_CARE
return|;
case|case
name|EGL_MIN_SWAP_INTERVAL
case|:
return|return
name|EGL_DONT_CARE
return|;
ifdef|#
directive|ifdef
name|EGL_RENDERABLE_TYPE
case|case
name|EGL_RENDERABLE_TYPE
case|:
return|return
name|EGL_OPENGL_ES_BIT
return|;
endif|#
directive|endif
case|case
name|EGL_SAMPLE_BUFFERS
case|:
return|return
literal|0
return|;
case|case
name|EGL_SAMPLES
case|:
return|return
literal|0
return|;
case|case
name|EGL_STENCIL_SIZE
case|:
return|return
literal|0
return|;
case|case
name|EGL_SURFACE_TYPE
case|:
return|return
name|EGL_WINDOW_BIT
return|;
case|case
name|EGL_TRANSPARENT_TYPE
case|:
return|return
name|EGL_NONE
return|;
case|case
name|EGL_TRANSPARENT_RED_VALUE
case|:
return|return
name|EGL_DONT_CARE
return|;
case|case
name|EGL_TRANSPARENT_GREEN_VALUE
case|:
return|return
name|EGL_DONT_CARE
return|;
case|case
name|EGL_TRANSPARENT_BLUE_VALUE
case|:
return|return
name|EGL_DONT_CARE
return|;
ifdef|#
directive|ifdef
name|EGL_VERSION_1_3
case|case
name|EGL_CONFORMANT
case|:
return|return
literal|0
return|;
case|case
name|EGL_MATCH_NATIVE_PIXMAP
case|:
return|return
name|EGL_NONE
return|;
endif|#
directive|endif
case|case
name|EGL_MAX_PBUFFER_HEIGHT
case|:
case|case
name|EGL_MAX_PBUFFER_WIDTH
case|:
case|case
name|EGL_MAX_PBUFFER_PIXELS
case|:
case|case
name|EGL_NATIVE_VISUAL_ID
case|:
case|case
name|EGL_NONE
case|:
comment|// Attribute does not affect config selection.
return|return
name|EGL_DONT_CARE
return|;
default|default:
comment|// Attribute is unknown in EGL<= 1.4.
return|return
name|EGL_DONT_CARE
return|;
block|}
block|}
end_function
begin_comment
comment|// Set the value associated with a property, replacing an existing
end_comment
begin_comment
comment|// value if there is one.
end_comment
begin_function
DECL|function|setValue
name|void
name|QEglProperties
operator|::
name|setValue
parameter_list|(
name|int
name|name
parameter_list|,
name|int
name|value
parameter_list|)
block|{
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
operator|(
name|props
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|)
condition|;
name|index
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|props
index|[
name|index
index|]
operator|==
name|name
condition|)
block|{
name|props
index|[
name|index
operator|+
literal|1
index|]
operator|=
name|value
expr_stmt|;
return|return;
block|}
block|}
name|props
index|[
name|props
operator|.
name|size
argument_list|()
operator|-
literal|1
index|]
operator|=
name|name
expr_stmt|;
name|props
operator|.
name|append
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|props
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Remove a property value.  Returns false if the property is not present.
end_comment
begin_function
DECL|function|removeValue
name|bool
name|QEglProperties
operator|::
name|removeValue
parameter_list|(
name|int
name|name
parameter_list|)
block|{
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
operator|(
name|props
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|)
condition|;
name|index
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|props
index|[
name|index
index|]
operator|==
name|name
condition|)
block|{
while|while
condition|(
operator|(
name|index
operator|+
literal|2
operator|)
operator|<
name|props
operator|.
name|size
argument_list|()
condition|)
block|{
name|props
index|[
name|index
index|]
operator|=
name|props
index|[
name|index
operator|+
literal|2
index|]
expr_stmt|;
operator|++
name|index
expr_stmt|;
block|}
name|props
operator|.
name|resize
argument_list|(
name|props
operator|.
name|size
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setDeviceType
name|void
name|QEglProperties
operator|::
name|setDeviceType
parameter_list|(
name|int
name|devType
parameter_list|)
block|{
if|if
condition|(
name|devType
operator|==
name|QInternal
operator|::
name|Pixmap
operator|||
name|devType
operator|==
name|QInternal
operator|::
name|Image
condition|)
name|setValue
argument_list|(
name|EGL_SURFACE_TYPE
argument_list|,
name|EGL_PIXMAP_BIT
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|devType
operator|==
name|QInternal
operator|::
name|Pbuffer
condition|)
name|setValue
argument_list|(
name|EGL_SURFACE_TYPE
argument_list|,
name|EGL_PBUFFER_BIT
argument_list|)
expr_stmt|;
else|else
name|setValue
argument_list|(
name|EGL_SURFACE_TYPE
argument_list|,
name|EGL_WINDOW_BIT
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Sets the red, green, blue, and alpha sizes based on a pixel format.
end_comment
begin_comment
comment|// Normally used to match a configuration request to the screen format.
end_comment
begin_function
DECL|function|setPixelFormat
name|void
name|QEglProperties
operator|::
name|setPixelFormat
parameter_list|(
name|QImage
operator|::
name|Format
name|pixelFormat
parameter_list|)
block|{
name|int
name|red
decl_stmt|,
name|green
decl_stmt|,
name|blue
decl_stmt|,
name|alpha
decl_stmt|;
switch|switch
condition|(
name|pixelFormat
condition|)
block|{
case|case
name|QImage
operator|::
name|Format_RGB32
case|:
case|case
name|QImage
operator|::
name|Format_RGB888
case|:
name|red
operator|=
name|green
operator|=
name|blue
operator|=
literal|8
expr_stmt|;
name|alpha
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_ARGB32
case|:
case|case
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
case|:
name|red
operator|=
name|green
operator|=
name|blue
operator|=
name|alpha
operator|=
literal|8
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_RGB16
case|:
name|red
operator|=
literal|5
expr_stmt|;
name|green
operator|=
literal|6
expr_stmt|;
name|blue
operator|=
literal|5
expr_stmt|;
name|alpha
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_ARGB8565_Premultiplied
case|:
name|red
operator|=
literal|5
expr_stmt|;
name|green
operator|=
literal|6
expr_stmt|;
name|blue
operator|=
literal|5
expr_stmt|;
name|alpha
operator|=
literal|8
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_RGB666
case|:
name|red
operator|=
name|green
operator|=
name|blue
operator|=
literal|6
expr_stmt|;
name|alpha
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_ARGB6666_Premultiplied
case|:
name|red
operator|=
name|green
operator|=
name|blue
operator|=
name|alpha
operator|=
literal|6
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_RGB555
case|:
name|red
operator|=
name|green
operator|=
name|blue
operator|=
literal|5
expr_stmt|;
name|alpha
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_ARGB8555_Premultiplied
case|:
name|red
operator|=
name|green
operator|=
name|blue
operator|=
literal|5
expr_stmt|;
name|alpha
operator|=
literal|8
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_RGB444
case|:
name|red
operator|=
name|green
operator|=
name|blue
operator|=
literal|4
expr_stmt|;
name|alpha
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|QImage
operator|::
name|Format_ARGB4444_Premultiplied
case|:
name|red
operator|=
name|green
operator|=
name|blue
operator|=
name|alpha
operator|=
literal|4
expr_stmt|;
break|break;
default|default:
name|qWarning
argument_list|()
operator|<<
literal|"QEglProperties::setPixelFormat(): Unsupported pixel format"
expr_stmt|;
name|red
operator|=
name|green
operator|=
name|blue
operator|=
name|alpha
operator|=
literal|1
expr_stmt|;
break|break;
block|}
name|setValue
argument_list|(
name|EGL_RED_SIZE
argument_list|,
name|red
argument_list|)
expr_stmt|;
name|setValue
argument_list|(
name|EGL_GREEN_SIZE
argument_list|,
name|green
argument_list|)
expr_stmt|;
name|setValue
argument_list|(
name|EGL_BLUE_SIZE
argument_list|,
name|blue
argument_list|)
expr_stmt|;
name|setValue
argument_list|(
name|EGL_ALPHA_SIZE
argument_list|,
name|alpha
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setRenderableType
name|void
name|QEglProperties
operator|::
name|setRenderableType
parameter_list|(
name|QEgl
operator|::
name|API
name|api
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|EGL_RENDERABLE_TYPE
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
if|if
condition|(
name|api
operator|==
name|QEgl
operator|::
name|OpenGL
condition|)
name|setValue
argument_list|(
name|EGL_RENDERABLE_TYPE
argument_list|,
name|EGL_OPENGL_ES2_BIT
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|QT_OPENGL_ES
argument_list|)
if|if
condition|(
name|api
operator|==
name|QEgl
operator|::
name|OpenGL
condition|)
name|setValue
argument_list|(
name|EGL_RENDERABLE_TYPE
argument_list|,
name|EGL_OPENGL_ES_BIT
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|EGL_OPENGL_BIT
argument_list|)
if|if
condition|(
name|api
operator|==
name|QEgl
operator|::
name|OpenGL
condition|)
name|setValue
argument_list|(
name|EGL_RENDERABLE_TYPE
argument_list|,
name|EGL_OPENGL_BIT
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_OPENVG_BIT
if|if
condition|(
name|api
operator|==
name|QEgl
operator|::
name|OpenVG
condition|)
name|setValue
argument_list|(
name|EGL_RENDERABLE_TYPE
argument_list|,
name|EGL_OPENVG_BIT
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|api
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// Reduce the complexity of a configuration request to ask for less
end_comment
begin_comment
comment|// because the previous request did not result in success.  Returns
end_comment
begin_comment
comment|// true if the complexity was reduced, or false if no further
end_comment
begin_comment
comment|// reductions in complexity are possible.
end_comment
begin_function
DECL|function|reduceConfiguration
name|bool
name|QEglProperties
operator|::
name|reduceConfiguration
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|EGL_SWAP_BEHAVIOR
if|if
condition|(
name|value
argument_list|(
name|EGL_SWAP_BEHAVIOR
argument_list|)
operator|!=
name|EGL_DONT_CARE
condition|)
name|removeValue
argument_list|(
name|EGL_SWAP_BEHAVIOR
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
comment|// For OpenVG, we sometimes try to create a surface using a pre-multiplied format. If we can't
comment|// find a config which supports pre-multiplied formats, remove the flag on the surface type:
name|EGLint
name|surfaceType
init|=
name|value
argument_list|(
name|EGL_SURFACE_TYPE
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
name|setValue
argument_list|(
name|EGL_SURFACE_TYPE
argument_list|,
name|surfaceType
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
endif|#
directive|endif
comment|// EGL chooses configs with the highest color depth over
comment|// those with smaller (but faster) lower color depths. One
comment|// way around this is to set EGL_BUFFER_SIZE to 16, which
comment|// trumps the others. Of course, there may not be a 16-bit
comment|// config available, so it's the first restraint we remove.
if|if
condition|(
name|value
argument_list|(
name|EGL_BUFFER_SIZE
argument_list|)
operator|==
literal|16
condition|)
block|{
name|removeValue
argument_list|(
name|EGL_BUFFER_SIZE
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|removeValue
argument_list|(
name|EGL_SAMPLE_BUFFERS
argument_list|)
condition|)
block|{
name|removeValue
argument_list|(
name|EGL_SAMPLES
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|removeValue
argument_list|(
name|EGL_ALPHA_SIZE
argument_list|)
condition|)
block|{
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
if|if
condition|(
name|removeValue
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGBA
argument_list|)
condition|)
name|setValue
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|true
return|;
block|}
if|if
condition|(
name|removeValue
argument_list|(
name|EGL_STENCIL_SIZE
argument_list|)
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|removeValue
argument_list|(
name|EGL_DEPTH_SIZE
argument_list|)
condition|)
return|return
literal|true
return|;
ifdef|#
directive|ifdef
name|EGL_BIND_TO_TEXTURE_RGB
if|if
condition|(
name|removeValue
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|)
condition|)
return|return
literal|true
return|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|addTag
specifier|static
name|void
name|addTag
parameter_list|(
name|QString
modifier|&
name|str
parameter_list|,
specifier|const
name|QString
modifier|&
name|tag
parameter_list|)
block|{
name|int
name|lastnl
init|=
name|str
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1String
argument_list|(
literal|"\n"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|lastnl
operator|==
operator|-
literal|1
condition|)
name|lastnl
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|str
operator|.
name|length
argument_list|()
operator|-
name|lastnl
operator|)
operator|>=
literal|50
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"\n   "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|tag
expr_stmt|;
block|}
end_function
begin_comment
comment|// Convert a property list to a string suitable for debug output.
end_comment
begin_function
DECL|function|toString
name|QString
name|QEglProperties
operator|::
name|toString
parameter_list|()
specifier|const
block|{
name|QString
name|str
decl_stmt|;
name|int
name|val
decl_stmt|;
name|val
operator|=
name|value
argument_list|(
name|EGL_CONFIG_ID
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"id="
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|EGL_RENDERABLE_TYPE
name|val
operator|=
name|value
argument_list|(
name|EGL_RENDERABLE_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"type="
argument_list|)
expr_stmt|;
name|QStringList
name|types
decl_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_OPENGL_ES_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"es1"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|EGL_OPENGL_ES2_BIT
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_OPENGL_ES2_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"es2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_OPENGL_BIT
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_OPENGL_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"gl"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_OPENVG_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"vg"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
operator|~
literal|7
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
name|str
operator|+=
name|types
operator|.
name|join
argument_list|(
name|QLatin1String
argument_list|(
literal|","
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"type=any"
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"type=es1"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|int
name|red
init|=
name|value
argument_list|(
name|EGL_RED_SIZE
argument_list|)
decl_stmt|;
name|int
name|green
init|=
name|value
argument_list|(
name|EGL_GREEN_SIZE
argument_list|)
decl_stmt|;
name|int
name|blue
init|=
name|value
argument_list|(
name|EGL_BLUE_SIZE
argument_list|)
decl_stmt|;
name|int
name|alpha
init|=
name|value
argument_list|(
name|EGL_ALPHA_SIZE
argument_list|)
decl_stmt|;
name|int
name|bufferSize
init|=
name|value
argument_list|(
name|EGL_BUFFER_SIZE
argument_list|)
decl_stmt|;
if|if
condition|(
name|bufferSize
operator|==
operator|(
name|red
operator|+
name|green
operator|+
name|blue
operator|+
name|alpha
operator|)
condition|)
name|bufferSize
operator|=
literal|0
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" rgba="
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|red
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|green
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|blue
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|alpha
argument_list|)
expr_stmt|;
if|if
condition|(
name|bufferSize
operator|!=
literal|0
condition|)
block|{
comment|// Only report buffer size if different than r+g+b+a.
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" buffer-size="
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|bufferSize
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|EGL_COLOR_BUFFER_TYPE
name|val
operator|=
name|value
argument_list|(
name|EGL_COLOR_BUFFER_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
name|EGL_LUMINANCE_BUFFER
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" color-buffer-type=luminance"
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
operator|&&
name|val
operator|!=
name|EGL_RGB_BUFFER
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" color-buffer-type="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|,
literal|16
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|val
operator|=
name|value
argument_list|(
name|EGL_DEPTH_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
literal|0
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" depth="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_STENCIL_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
literal|0
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" stencil="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_SURFACE_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" surface-type="
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|types
decl_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_WINDOW_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"window"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_PIXMAP_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"pixmap"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_PBUFFER_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"pbuffer"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|EGL_VG_COLORSPACE_LINEAR_BIT
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_VG_COLORSPACE_LINEAR_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"vg-colorspace-linear"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
if|if
condition|(
operator|(
name|val
operator|&
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
operator|)
operator|!=
literal|0
condition|)
name|types
operator|+=
name|QLatin1String
argument_list|(
literal|"vg-alpha-format-pre"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|val
operator|&
operator|~
operator|(
name|EGL_WINDOW_BIT
operator||
name|EGL_PIXMAP_BIT
operator||
name|EGL_PBUFFER_BIT
ifdef|#
directive|ifdef
name|EGL_VG_COLORSPACE_LINEAR_BIT
operator||
name|EGL_VG_COLORSPACE_LINEAR_BIT
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
operator||
name|EGL_VG_ALPHA_FORMAT_PRE_BIT
endif|#
directive|endif
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|types
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
name|str
operator|+=
name|types
operator|.
name|join
argument_list|(
name|QLatin1String
argument_list|(
literal|","
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_CONFIG_CAVEAT
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" caveat="
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
name|EGL_NONE
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"none"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|val
operator|==
name|EGL_SLOW_CONFIG
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"slow"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|val
operator|==
name|EGL_NON_CONFORMANT_CONFIG
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"non-conformant"
argument_list|)
expr_stmt|;
else|else
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|,
literal|16
argument_list|)
expr_stmt|;
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_LEVEL
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
literal|0
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" level="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
name|int
name|width
decl_stmt|,
name|height
decl_stmt|,
name|pixels
decl_stmt|;
name|width
operator|=
name|value
argument_list|(
name|EGL_MAX_PBUFFER_WIDTH
argument_list|)
expr_stmt|;
name|height
operator|=
name|value
argument_list|(
name|EGL_MAX_PBUFFER_HEIGHT
argument_list|)
expr_stmt|;
name|pixels
operator|=
name|value
argument_list|(
name|EGL_MAX_PBUFFER_PIXELS
argument_list|)
expr_stmt|;
if|if
condition|(
name|height
operator|!=
name|EGL_DONT_CARE
operator|||
name|width
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" max-pbuffer-size="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|'x'
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|height
argument_list|)
expr_stmt|;
if|if
condition|(
name|pixels
operator|!=
operator|(
name|width
operator|*
name|height
operator|)
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" max-pbuffer-pixels="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|pixels
argument_list|)
expr_stmt|;
block|}
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_NATIVE_RENDERABLE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
if|if
condition|(
name|val
condition|)
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" native-renderable=true"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" native-renderable=false"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_NATIVE_VISUAL_ID
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" visual-id="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_NATIVE_VISUAL_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" visual-type="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|EGL_PRESERVED_RESOURCES
name|val
operator|=
name|value
argument_list|(
name|EGL_PRESERVED_RESOURCES
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
if|if
condition|(
name|val
condition|)
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" preserved-resources=true"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" preserved-resources=false"
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|val
operator|=
name|value
argument_list|(
name|EGL_SAMPLES
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
literal|0
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" samples="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_SAMPLE_BUFFERS
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
literal|0
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" sample-buffers="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
name|val
operator|=
name|value
argument_list|(
name|EGL_TRANSPARENT_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
name|EGL_TRANSPARENT_RGB
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" transparent-rgb="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|value
argument_list|(
name|EGL_TRANSPARENT_RED_VALUE
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|value
argument_list|(
name|EGL_TRANSPARENT_GREEN_VALUE
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|value
argument_list|(
name|EGL_TRANSPARENT_BLUE_VALUE
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|)
operator|&&
name|defined
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGBA
argument_list|)
name|val
operator|=
name|value
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|)
expr_stmt|;
name|int
name|val2
init|=
name|value
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGBA
argument_list|)
decl_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
operator|||
name|val2
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" bind-texture="
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
name|EGL_TRUE
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"rgb"
argument_list|)
expr_stmt|;
else|else
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"no-rgb"
argument_list|)
expr_stmt|;
if|if
condition|(
name|val2
operator|==
name|EGL_TRUE
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|",rgba"
argument_list|)
expr_stmt|;
else|else
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|",no-rgba"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_MIN_SWAP_INTERVAL
name|val
operator|=
name|value
argument_list|(
name|EGL_MIN_SWAP_INTERVAL
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" min-swap-interval="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_MIN_SWAP_INTERVAL
name|val
operator|=
name|value
argument_list|(
name|EGL_MAX_SWAP_INTERVAL
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" max-swap-interval="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_LUMINANCE_SIZE
name|val
operator|=
name|value
argument_list|(
name|EGL_LUMINANCE_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
literal|0
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" luminance="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_ALPHA_MASK_SIZE
name|val
operator|=
name|value
argument_list|(
name|EGL_ALPHA_MASK_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
literal|0
condition|)
block|{
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" alpha-mask="
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EGL_CONFORMANT
name|val
operator|=
name|value
argument_list|(
name|EGL_CONFORMANT
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|val
condition|)
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" conformant=true"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|addTag
argument_list|(
name|str
argument_list|,
name|QLatin1String
argument_list|(
literal|" conformant=false"
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|str
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
