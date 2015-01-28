begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSGLCONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSGLCONTEXT_H
define|#
directive|define
name|QWINDOWSGLCONTEXT_H
end_define
begin_include
include|#
directive|include
file|"array.h"
end_include
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_enum
DECL|enum|QWindowsGLFormatFlags
enum|enum
name|QWindowsGLFormatFlags
block|{
DECL|enumerator|QWindowsGLDirectRendering
name|QWindowsGLDirectRendering
init|=
literal|0x1
block|,
DECL|enumerator|QWindowsGLOverlay
name|QWindowsGLOverlay
init|=
literal|0x2
block|,
DECL|enumerator|QWindowsGLRenderToPixmap
name|QWindowsGLRenderToPixmap
init|=
literal|0x4
block|,
DECL|enumerator|QWindowsGLAccumBuffer
name|QWindowsGLAccumBuffer
init|=
literal|0x8
block|}
enum|;
end_enum
begin_comment
comment|// Additional format information for Windows.
end_comment
begin_struct
DECL|struct|QWindowsOpenGLAdditionalFormat
struct|struct
name|QWindowsOpenGLAdditionalFormat
block|{
DECL|function|QWindowsOpenGLAdditionalFormat
name|QWindowsOpenGLAdditionalFormat
argument_list|(
argument|unsigned formatFlagsIn =
literal|0
argument_list|,
argument|unsigned pixmapDepthIn =
literal|0
argument_list|)
block|:
name|formatFlags
argument_list|(
name|formatFlagsIn
argument_list|)
operator|,
name|pixmapDepth
argument_list|(
argument|pixmapDepthIn
argument_list|)
block|{ }
DECL|member|formatFlags
name|unsigned
name|formatFlags
expr_stmt|;
comment|// QWindowsGLFormatFlags.
DECL|member|pixmapDepth
name|unsigned
name|pixmapDepth
decl_stmt|;
comment|// for QWindowsGLRenderToPixmap
block|}
struct|;
end_struct
begin_comment
comment|// Per-window data for active OpenGL contexts.
end_comment
begin_struct
DECL|struct|QOpenGLContextData
struct|struct
name|QOpenGLContextData
block|{
DECL|function|QOpenGLContextData
name|QOpenGLContextData
argument_list|(
argument|HGLRC r
argument_list|,
argument|HWND h
argument_list|,
argument|HDC d
argument_list|)
block|:
name|renderingContext
argument_list|(
name|r
argument_list|)
operator|,
name|hwnd
argument_list|(
name|h
argument_list|)
operator|,
name|hdc
argument_list|(
argument|d
argument_list|)
block|{}
DECL|function|QOpenGLContextData
name|QOpenGLContextData
argument_list|()
operator|:
name|renderingContext
argument_list|(
literal|0
argument_list|)
operator|,
name|hwnd
argument_list|(
literal|0
argument_list|)
operator|,
name|hdc
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|renderingContext
name|HGLRC
name|renderingContext
expr_stmt|;
DECL|member|hwnd
name|HWND
name|hwnd
decl_stmt|;
DECL|member|hdc
name|HDC
name|hdc
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|QOpenGLStaticContext
name|class
name|QOpenGLStaticContext
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QWindowsOpenGLContextFormat
struct|struct
name|QWindowsOpenGLContextFormat
block|{
name|QWindowsOpenGLContextFormat
argument_list|()
expr_stmt|;
specifier|static
name|QWindowsOpenGLContextFormat
name|current
parameter_list|()
function_decl|;
name|void
name|apply
argument_list|(
name|QSurfaceFormat
operator|*
name|format
argument_list|)
decl|const
decl_stmt|;
DECL|member|profile
name|QSurfaceFormat
operator|::
name|OpenGLContextProfile
name|profile
expr_stmt|;
DECL|member|version
name|int
name|version
decl_stmt|;
comment|//! majorVersion<<8 + minorVersion
DECL|member|options
name|QSurfaceFormat
operator|::
name|FormatOptions
name|options
expr_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QWindowsOpenGLContextFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_struct
DECL|struct|QWindowsOpengl32DLL
struct|struct
name|QWindowsOpengl32DLL
block|{
name|bool
name|init
parameter_list|(
name|bool
name|softwareRendering
parameter_list|)
function_decl|;
DECL|function|moduleHandle
name|void
operator|*
name|moduleHandle
argument_list|()
specifier|const
block|{
return|return
name|m_lib
return|;
block|}
DECL|function|moduleIsNotOpengl32
name|bool
name|moduleIsNotOpengl32
argument_list|()
specifier|const
block|{
return|return
name|m_nonOpengl32
return|;
block|}
comment|// Wrappers. Always use these instead of SwapBuffers/wglSwapBuffers/etc.
name|BOOL
name|swapBuffers
parameter_list|(
name|HDC
name|dc
parameter_list|)
function_decl|;
name|BOOL
name|setPixelFormat
parameter_list|(
name|HDC
name|dc
parameter_list|,
name|int
name|pf
parameter_list|,
specifier|const
name|PIXELFORMATDESCRIPTOR
modifier|*
name|pfd
parameter_list|)
function_decl|;
comment|// WGL
DECL|member|wglCreateContext
name|HGLRC
function_decl|(
name|WINAPI
modifier|*
name|wglCreateContext
function_decl|)
parameter_list|(
name|HDC
name|dc
parameter_list|)
function_decl|;
DECL|member|wglDeleteContext
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|wglDeleteContext
function_decl|)
parameter_list|(
name|HGLRC
name|context
parameter_list|)
function_decl|;
DECL|member|wglGetCurrentContext
name|HGLRC
function_decl|(
name|WINAPI
modifier|*
name|wglGetCurrentContext
function_decl|)
parameter_list|()
function_decl|;
DECL|member|wglGetCurrentDC
name|HDC
function_decl|(
name|WINAPI
modifier|*
name|wglGetCurrentDC
function_decl|)
parameter_list|()
function_decl|;
DECL|member|wglGetProcAddress
name|PROC
function_decl|(
name|WINAPI
modifier|*
name|wglGetProcAddress
function_decl|)
parameter_list|(
name|LPCSTR
name|name
parameter_list|)
function_decl|;
DECL|member|wglMakeCurrent
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|wglMakeCurrent
function_decl|)
parameter_list|(
name|HDC
name|dc
parameter_list|,
name|HGLRC
name|context
parameter_list|)
function_decl|;
DECL|member|wglShareLists
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|wglShareLists
function_decl|)
parameter_list|(
name|HGLRC
name|context1
parameter_list|,
name|HGLRC
name|context2
parameter_list|)
function_decl|;
comment|// GL1+GLES2 common
DECL|member|glBindTexture
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glBindTexture
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLuint
name|texture
parameter_list|)
function_decl|;
DECL|member|glBlendFunc
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glBlendFunc
function_decl|)
parameter_list|(
name|GLenum
name|sfactor
parameter_list|,
name|GLenum
name|dfactor
parameter_list|)
function_decl|;
DECL|member|glClear
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glClear
function_decl|)
parameter_list|(
name|GLbitfield
name|mask
parameter_list|)
function_decl|;
DECL|member|glClearColor
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glClearColor
function_decl|)
parameter_list|(
name|GLclampf
name|red
parameter_list|,
name|GLclampf
name|green
parameter_list|,
name|GLclampf
name|blue
parameter_list|,
name|GLclampf
name|alpha
parameter_list|)
function_decl|;
DECL|member|glClearStencil
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glClearStencil
function_decl|)
parameter_list|(
name|GLint
name|s
parameter_list|)
function_decl|;
DECL|member|glColorMask
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glColorMask
function_decl|)
parameter_list|(
name|GLboolean
name|red
parameter_list|,
name|GLboolean
name|green
parameter_list|,
name|GLboolean
name|blue
parameter_list|,
name|GLboolean
name|alpha
parameter_list|)
function_decl|;
DECL|member|glCopyTexImage2D
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glCopyTexImage2D
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLenum
name|internalformat
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLint
name|border
parameter_list|)
function_decl|;
DECL|member|glCopyTexSubImage2D
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glCopyTexSubImage2D
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
DECL|member|glCullFace
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glCullFace
function_decl|)
parameter_list|(
name|GLenum
name|mode
parameter_list|)
function_decl|;
DECL|member|glDeleteTextures
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glDeleteTextures
function_decl|)
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|textures
parameter_list|)
function_decl|;
DECL|member|glDepthFunc
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glDepthFunc
function_decl|)
parameter_list|(
name|GLenum
name|func
parameter_list|)
function_decl|;
DECL|member|glDepthMask
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glDepthMask
function_decl|)
parameter_list|(
name|GLboolean
name|flag
parameter_list|)
function_decl|;
DECL|member|glDisable
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glDisable
function_decl|)
parameter_list|(
name|GLenum
name|cap
parameter_list|)
function_decl|;
DECL|member|glDrawArrays
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glDrawArrays
function_decl|)
parameter_list|(
name|GLenum
name|mode
parameter_list|,
name|GLint
name|first
parameter_list|,
name|GLsizei
name|count
parameter_list|)
function_decl|;
DECL|member|glDrawElements
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glDrawElements
function_decl|)
parameter_list|(
name|GLenum
name|mode
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|indices
parameter_list|)
function_decl|;
DECL|member|glEnable
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glEnable
function_decl|)
parameter_list|(
name|GLenum
name|cap
parameter_list|)
function_decl|;
DECL|member|glFinish
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glFinish
function_decl|)
parameter_list|()
function_decl|;
DECL|member|glFlush
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glFlush
function_decl|)
parameter_list|()
function_decl|;
DECL|member|glFrontFace
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glFrontFace
function_decl|)
parameter_list|(
name|GLenum
name|mode
parameter_list|)
function_decl|;
DECL|member|glGenTextures
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glGenTextures
function_decl|)
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|textures
parameter_list|)
function_decl|;
DECL|member|glGetBooleanv
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glGetBooleanv
function_decl|)
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLboolean
modifier|*
name|params
parameter_list|)
function_decl|;
DECL|member|glGetError
name|GLenum
function_decl|(
name|APIENTRY
modifier|*
name|glGetError
function_decl|)
parameter_list|()
function_decl|;
DECL|member|glGetFloatv
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glGetFloatv
function_decl|)
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
DECL|member|glGetIntegerv
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glGetIntegerv
function_decl|)
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
DECL|member|glGetString
specifier|const
name|GLubyte
modifier|*
function_decl|(
name|APIENTRY
modifier|*
name|glGetString
function_decl|)
parameter_list|(
name|GLenum
name|name
parameter_list|)
function_decl|;
DECL|member|glGetTexParameterfv
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glGetTexParameterfv
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
DECL|member|glGetTexParameteriv
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glGetTexParameteriv
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
DECL|member|glHint
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glHint
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|mode
parameter_list|)
function_decl|;
DECL|member|glIsEnabled
name|GLboolean
function_decl|(
name|APIENTRY
modifier|*
name|glIsEnabled
function_decl|)
parameter_list|(
name|GLenum
name|cap
parameter_list|)
function_decl|;
DECL|member|glIsTexture
name|GLboolean
function_decl|(
name|APIENTRY
modifier|*
name|glIsTexture
function_decl|)
parameter_list|(
name|GLuint
name|texture
parameter_list|)
function_decl|;
DECL|member|glLineWidth
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glLineWidth
function_decl|)
parameter_list|(
name|GLfloat
name|width
parameter_list|)
function_decl|;
DECL|member|glPixelStorei
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glPixelStorei
function_decl|)
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint
name|param
parameter_list|)
function_decl|;
DECL|member|glPolygonOffset
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glPolygonOffset
function_decl|)
parameter_list|(
name|GLfloat
name|factor
parameter_list|,
name|GLfloat
name|units
parameter_list|)
function_decl|;
DECL|member|glReadPixels
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glReadPixels
function_decl|)
parameter_list|(
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
DECL|member|glScissor
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glScissor
function_decl|)
parameter_list|(
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
DECL|member|glStencilFunc
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glStencilFunc
function_decl|)
parameter_list|(
name|GLenum
name|func
parameter_list|,
name|GLint
name|ref
parameter_list|,
name|GLuint
name|mask
parameter_list|)
function_decl|;
DECL|member|glStencilMask
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glStencilMask
function_decl|)
parameter_list|(
name|GLuint
name|mask
parameter_list|)
function_decl|;
DECL|member|glStencilOp
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glStencilOp
function_decl|)
parameter_list|(
name|GLenum
name|fail
parameter_list|,
name|GLenum
name|zfail
parameter_list|,
name|GLenum
name|zpass
parameter_list|)
function_decl|;
DECL|member|glTexImage2D
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glTexImage2D
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|internalformat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLint
name|border
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
DECL|member|glTexParameterf
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glTexParameterf
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLfloat
name|param
parameter_list|)
function_decl|;
DECL|member|glTexParameterfv
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glTexParameterfv
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
DECL|member|glTexParameteri
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glTexParameteri
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
name|param
parameter_list|)
function_decl|;
DECL|member|glTexParameteriv
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glTexParameteriv
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
specifier|const
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
DECL|member|glTexSubImage2D
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glTexSubImage2D
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
DECL|member|glViewport
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glViewport
function_decl|)
parameter_list|(
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
comment|// GL only
DECL|member|glClearDepth
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glClearDepth
function_decl|)
parameter_list|(
name|GLdouble
name|depth
parameter_list|)
function_decl|;
DECL|member|glDepthRange
name|void
function_decl|(
name|APIENTRY
modifier|*
name|glDepthRange
function_decl|)
parameter_list|(
name|GLdouble
name|zNear
parameter_list|,
name|GLdouble
name|zFar
parameter_list|)
function_decl|;
DECL|member|private
name|private
label|:
name|void
modifier|*
name|resolve
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
DECL|member|m_lib
name|HMODULE
name|m_lib
decl_stmt|;
DECL|member|m_nonOpengl32
name|bool
name|m_nonOpengl32
decl_stmt|;
comment|// For Mesa llvmpipe shipped with a name other than opengl32.dll
DECL|member|wglSwapBuffers
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|wglSwapBuffers
function_decl|)
parameter_list|(
name|HDC
name|dc
parameter_list|)
function_decl|;
DECL|member|wglSetPixelFormat
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|wglSetPixelFormat
function_decl|)
parameter_list|(
name|HDC
name|dc
parameter_list|,
name|int
name|pf
parameter_list|,
specifier|const
name|PIXELFORMATDESCRIPTOR
modifier|*
name|pfd
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QOpenGLStaticContext
range|:
name|public
name|QWindowsStaticOpenGLContext
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLStaticContext
argument_list|)
name|QOpenGLStaticContext
argument_list|()
block|;
name|public
operator|:
expr|enum
name|Extensions
block|{
name|SampleBuffers
operator|=
literal|0x1
block|}
block|;
typedef|typedef
name|bool
argument_list|(
argument|APIENTRY *WglGetPixelFormatAttribIVARB
argument_list|)
operator|(
name|HDC
name|hdc
expr|,
name|int
name|iPixelFormat
expr|,
name|int
name|iLayerPlane
expr|,
name|uint
name|nAttributes
expr|,
specifier|const
name|int
operator|*
name|piAttributes
expr|,
name|int
operator|*
name|piValues
operator|)
expr_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|bool
function_decl|(
name|APIENTRY
modifier|*
name|WglChoosePixelFormatARB
function_decl|)
parameter_list|(
name|HDC
name|hdc
parameter_list|,
specifier|const
name|int
modifier|*
name|piAttribList
parameter_list|,
specifier|const
name|float
modifier|*
name|pfAttribFList
parameter_list|,
name|uint
name|nMaxFormats
parameter_list|,
name|int
modifier|*
name|piFormats
parameter_list|,
name|UINT
modifier|*
name|nNumFormats
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|HGLRC
function_decl|(
name|APIENTRY
modifier|*
name|WglCreateContextAttribsARB
function_decl|)
parameter_list|(
name|HDC
parameter_list|,
name|HGLRC
parameter_list|,
specifier|const
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|APIENTRY
modifier|*
name|WglSwapInternalExt
function_decl|)
parameter_list|(
name|int
name|interval
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|int
function_decl|(
name|APIENTRY
modifier|*
name|WglGetSwapInternalExt
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef
begin_expr_stmt
name|bool
name|hasExtensions
argument_list|()
specifier|const
block|{
return|return
name|wglGetPixelFormatAttribIVARB
operator|&&
name|wglChoosePixelFormatARB
operator|&&
name|wglCreateContextAttribsARB
return|;
block|}
end_expr_stmt
begin_function_decl
specifier|static
name|QOpenGLStaticContext
modifier|*
name|create
parameter_list|(
name|bool
name|softwareRendering
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QByteArray
name|getGlString
parameter_list|(
name|unsigned
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QWindowsOpenGLContext
modifier|*
name|createContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|void
operator|*
name|moduleHandle
argument_list|()
specifier|const
block|{
return|return
name|opengl32
operator|.
name|moduleHandle
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QOpenGLContext
operator|::
name|OpenGLModuleType
name|moduleType
argument_list|()
specifier|const
block|{
return|return
name|QOpenGLContext
operator|::
name|LibGL
return|;
block|}
end_expr_stmt
begin_comment
comment|// For a regular opengl32.dll report the ThreadedOpenGL capability.
end_comment
begin_comment
comment|// For others, which are likely to be software-only, don't.
end_comment
begin_expr_stmt
name|bool
name|supportsThreadedOpenGL
argument_list|()
specifier|const
block|{
return|return
operator|!
name|opengl32
operator|.
name|moduleIsNotOpengl32
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|const
name|QByteArray
name|vendor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QByteArray
name|renderer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QByteArray
name|extensionNames
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|unsigned
name|extensions
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QWindowsOpenGLContextFormat
name|defaultFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|WglGetPixelFormatAttribIVARB
name|wglGetPixelFormatAttribIVARB
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|WglChoosePixelFormatARB
name|wglChoosePixelFormatARB
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|WglCreateContextAttribsARB
name|wglCreateContextAttribsARB
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|WglSwapInternalExt
name|wglSwapInternalExt
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|WglGetSwapInternalExt
name|wglGetSwapInternalExt
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QWindowsOpengl32DLL
name|opengl32
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QOpenGLStaticContext
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QWindowsGLContext
range|:
name|public
name|QWindowsOpenGLContext
block|{
name|public
operator|:
name|explicit
name|QWindowsGLContext
argument_list|(
name|QOpenGLStaticContext
operator|*
name|staticContext
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
operator|~
name|QWindowsGLContext
argument_list|()
block|;
name|bool
name|isSharing
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_context
operator|->
name|shareHandle
argument_list|()
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_renderingContext
operator|&&
operator|!
name|m_lost
return|;
block|}
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_obtainedFormat
return|;
block|}
name|void
name|swapBuffers
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|makeCurrent
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|doneCurrent
argument_list|()
name|Q_DECL_OVERRIDE
block|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|GL_Proc
function_decl|)
parameter_list|()
function_decl|;
name|QFunctionPointer
name|getProcAddress
argument_list|(
argument|const QByteArray&procName
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|HGLRC
name|renderingContext
argument_list|()
specifier|const
block|{
return|return
name|m_renderingContext
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|void
operator|*
name|nativeContext
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_renderingContext
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
specifier|inline
name|void
name|releaseDCs
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|updateObtainedParams
parameter_list|(
name|HDC
name|hdc
parameter_list|,
name|int
modifier|*
name|obtainedSwapInterval
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QOpenGLStaticContext
modifier|*
name|m_staticContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QOpenGLContext
modifier|*
name|m_context
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSurfaceFormat
name|m_obtainedFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|HGLRC
name|m_renderingContext
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Array
operator|<
name|QOpenGLContextData
operator|>
name|m_windowContexts
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|PIXELFORMATDESCRIPTOR
name|m_obtainedPixelFormatDescriptor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_pixelFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_extensionsUsed
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_swapInterval
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_ownsContext
decl_stmt|;
end_decl_stmt
begin_function_decl
name|GLenum
function_decl|(
name|APIENTRY
modifier|*
name|m_getGraphicsResetStatus
function_decl|)
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|m_lost
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSGLCONTEXT_H
end_comment
end_unit
