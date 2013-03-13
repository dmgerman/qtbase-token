begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGL_H
end_ifndef
begin_define
DECL|macro|QOPENGL_H
define|#
directive|define
name|QOPENGL_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_comment
comment|// Note: Mac OSX is a "controlled platform" for OpenGL ABI so we
end_comment
begin_comment
comment|// use the system provided headers there. Controlled means that the
end_comment
begin_comment
comment|// headers always match the actual driver implementation so there
end_comment
begin_comment
comment|// is no possibility of drivers exposing additional functionality
end_comment
begin_comment
comment|// from the system headers. Also it means that the vendor can
end_comment
begin_comment
comment|// (and does) make different choices about some OpenGL types. For
end_comment
begin_comment
comment|// e.g. Apple uses void* for GLhandleARB whereas other platforms
end_comment
begin_comment
comment|// use unsigned int.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// For the "uncontrolled" Windows and Linux platforms we use the
end_comment
begin_comment
comment|// official Khronos headers. On these platforms this gives
end_comment
begin_comment
comment|// access to additional functionality the drivers may expose but
end_comment
begin_comment
comment|// which the system headers do not.
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<OpenGLES/ES2/gl.h>
end_include
begin_include
include|#
directive|include
file|<OpenGLES/ES2/glext.h>
end_include
begin_comment
comment|/*    OES_EGL_image_external is not included in the Apple provided    system headers yet, but we define the missing typedef so that    the qopenglextensions.cpp code will magically work once Apple    include the extension in their drivers. */
end_comment
begin_typedef
DECL|typedef|GLeglImageOES
typedef|typedef
name|void
modifier|*
name|GLeglImageOES
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_comment
comment|// "uncontrolled" platforms
end_comment
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_comment
comment|/*    Some GLES2 implementations (like the one on Harmattan) are missing the    typedef for GLchar. Work around it here by adding it. The Kkronos headers    specify GLChar as a typedef to char, so if an implementation already    provides it, then this doesn't do any harm. */
end_comment
begin_typedef
DECL|typedef|GLchar
typedef|typedef
name|char
name|GLchar
typedef|;
end_typedef
begin_include
include|#
directive|include
file|<QtGui/qopengles2ext.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|GL_DOUBLE
end_ifndef
begin_define
DECL|macro|GL_DOUBLE
define|#
directive|define
name|GL_DOUBLE
value|GL_FLOAT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GLdouble
end_ifndef
begin_typedef
DECL|typedef|GLdouble
typedef|typedef
name|GLfloat
name|GLdouble
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_MAC
end_comment
begin_else
else|#
directive|else
end_else
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<OpenGL/gl.h>
end_include
begin_if
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_7
end_if
begin_define
DECL|macro|GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
define|#
directive|define
name|GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
end_define
begin_include
include|#
directive|include
file|<OpenGL/gl3.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<OpenGL/glext.h>
end_include
begin_else
else|#
directive|else
end_else
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|GL_GLEXT_LEGACY
define|#
directive|define
name|GL_GLEXT_LEGACY
end_define
begin_comment
DECL|macro|GL_GLEXT_LEGACY
comment|// Prevents GL/gl.h form #including system glext.h
end_comment
begin_include
include|#
directive|include
file|<GL/gl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglext.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_MAC
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Desktops, apart from Mac OS X prior to 10.7 can support OpenGL 3
end_comment
begin_comment
comment|// and desktops apart from Mac can support OpenGL 4
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_7
operator|)
end_if
begin_define
DECL|macro|QT_OPENGL_3
define|#
directive|define
name|QT_OPENGL_3
end_define
begin_define
DECL|macro|QT_OPENGL_3_2
define|#
directive|define
name|QT_OPENGL_3_2
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_define
DECL|macro|QT_OPENGL_4
define|#
directive|define
name|QT_OPENGL_4
end_define
begin_define
DECL|macro|QT_OPENGL_4_3
define|#
directive|define
name|QT_OPENGL_4_3
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// When all else fails we provide sensible fallbacks - this is needed to
end_comment
begin_comment
comment|// allow compilation on OS X 10.6
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_comment
comment|// OS X 10.6 doesn't define these which are needed below
end_comment
begin_comment
comment|// OS X 10.7 and later defien them in gl3.h
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|APIENTRY
end_ifndef
begin_define
DECL|macro|APIENTRY
define|#
directive|define
name|APIENTRY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|APIENTRYP
end_ifndef
begin_define
DECL|macro|APIENTRYP
define|#
directive|define
name|APIENTRYP
value|APIENTRY *
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GLAPI
end_ifndef
begin_define
DECL|macro|GLAPI
define|#
directive|define
name|GLAPI
value|extern
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// This block is copied from glext.h and defines the types needed by
end_comment
begin_comment
comment|// a few extension classes.
end_comment
begin_include
include|#
directive|include
file|<stddef.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|GL_VERSION_2_0
end_ifndef
begin_comment
comment|/* GL type for program/shader text */
end_comment
begin_typedef
DECL|typedef|GLchar
typedef|typedef
name|char
name|GLchar
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_VERSION_1_5
end_ifndef
begin_comment
comment|/* GL types for handling large vertex buffer objects */
end_comment
begin_typedef
DECL|typedef|GLintptr
typedef|typedef
name|ptrdiff_t
name|GLintptr
typedef|;
end_typedef
begin_typedef
DECL|typedef|GLsizeiptr
typedef|typedef
name|ptrdiff_t
name|GLsizeiptr
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_ARB_vertex_buffer_object
end_ifndef
begin_comment
comment|/* GL types for handling large vertex buffer objects */
end_comment
begin_typedef
DECL|typedef|GLintptrARB
typedef|typedef
name|ptrdiff_t
name|GLintptrARB
typedef|;
end_typedef
begin_typedef
DECL|typedef|GLsizeiptrARB
typedef|typedef
name|ptrdiff_t
name|GLsizeiptrARB
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_ARB_shader_objects
end_ifndef
begin_comment
comment|/* GL types for program/shader text and shader object handles */
end_comment
begin_typedef
DECL|typedef|GLcharARB
typedef|typedef
name|char
name|GLcharARB
typedef|;
end_typedef
begin_typedef
DECL|typedef|GLhandleARB
typedef|typedef
name|unsigned
name|int
name|GLhandleARB
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* GL type for "half" precision (s10e5) float data in host memory */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GL_ARB_half_float_pixel
end_ifndef
begin_typedef
DECL|typedef|GLhalfARB
typedef|typedef
name|unsigned
name|short
name|GLhalfARB
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_NV_half_float
end_ifndef
begin_typedef
DECL|typedef|GLhalfNV
typedef|typedef
name|unsigned
name|short
name|GLhalfNV
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GLEXT_64_TYPES_DEFINED
end_ifndef
begin_comment
comment|/* This code block is duplicated in glxext.h, so must be protected */
end_comment
begin_define
DECL|macro|GLEXT_64_TYPES_DEFINED
define|#
directive|define
name|GLEXT_64_TYPES_DEFINED
end_define
begin_comment
comment|/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
end_comment
begin_comment
comment|/* (as used in the GL_EXT_timer_query extension). */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if
begin_include
include|#
directive|include
file|<inttypes.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|||
name|defined
argument_list|(
name|__digital__
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<inttypes.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_LP64
argument_list|)
end_if
begin_typedef
DECL|typedef|int64_t
typedef|typedef
name|long
name|int
name|int64_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint64_t
typedef|typedef
name|unsigned
name|long
name|int
name|uint64_t
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|int64_t
typedef|typedef
name|long
name|long
name|int
name|int64_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint64_t
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|uint64_t
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __arch64__ */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __STDC__ */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<inttypes.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__SCO__
argument_list|)
operator|||
name|defined
argument_list|(
name|__USLC__
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__UNIXOS2__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SOL64__
argument_list|)
end_elif
begin_typedef
DECL|typedef|int32_t
typedef|typedef
name|long
name|int
name|int32_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|int64_t
typedef|typedef
name|long
name|long
name|int
name|int64_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint64_t
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|uint64_t
typedef|;
end_typedef
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif
begin_typedef
DECL|typedef|int32_t
typedef|typedef
name|__int32
name|int32_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|int64_t
typedef|typedef
name|__int64
name|int64_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint64_t
typedef|typedef
name|unsigned
name|__int64
name|uint64_t
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Fallback if nothing above works */
end_comment
begin_include
include|#
directive|include
file|<inttypes.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_EXT_timer_query
end_ifndef
begin_typedef
DECL|typedef|GLint64EXT
typedef|typedef
name|int64_t
name|GLint64EXT
typedef|;
end_typedef
begin_typedef
DECL|typedef|GLuint64EXT
typedef|typedef
name|uint64_t
name|GLuint64EXT
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_ARB_sync
end_ifndef
begin_typedef
DECL|typedef|GLint64
typedef|typedef
name|int64_t
name|GLint64
typedef|;
end_typedef
begin_typedef
DECL|typedef|GLuint64
typedef|typedef
name|uint64_t
name|GLuint64
typedef|;
end_typedef
begin_typedef
DECL|typedef|GLsync
typedef|typedef
name|struct
name|__GLsync
modifier|*
name|GLsync
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_ARB_cl_event
end_ifndef
begin_comment
comment|/* These incomplete types let us declare types compatible with OpenCL's cl_context and cl_event */
end_comment
begin_struct_decl
struct_decl|struct
name|_cl_context
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|_cl_event
struct_decl|;
end_struct_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_ARB_debug_output
end_ifndef
begin_typedef
DECL|typedef|GLDEBUGPROCARB
typedef|typedef
name|void
function_decl|(
name|APIENTRY
modifier|*
name|GLDEBUGPROCARB
function_decl|)
parameter_list|(
name|GLenum
name|source
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLenum
name|severity
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|message
parameter_list|,
name|GLvoid
modifier|*
name|userParam
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_AMD_debug_output
end_ifndef
begin_typedef
DECL|typedef|GLDEBUGPROCAMD
typedef|typedef
name|void
function_decl|(
name|APIENTRY
modifier|*
name|GLDEBUGPROCAMD
function_decl|)
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|category
parameter_list|,
name|GLenum
name|severity
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|message
parameter_list|,
name|GLvoid
modifier|*
name|userParam
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_KHR_debug
end_ifndef
begin_typedef
DECL|typedef|GLDEBUGPROC
typedef|typedef
name|void
function_decl|(
name|APIENTRY
modifier|*
name|GLDEBUGPROC
function_decl|)
parameter_list|(
name|GLenum
name|source
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLenum
name|severity
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|message
parameter_list|,
name|GLvoid
modifier|*
name|userParam
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_NV_vdpau_interop
end_ifndef
begin_typedef
DECL|typedef|GLvdpauSurfaceNV
typedef|typedef
name|GLintptr
name|GLvdpauSurfaceNV
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// End of block copied from glext.h
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Types that aren't defined in all system's gl.h files.
end_comment
begin_typedef
DECL|typedef|qopengl_GLintptr
typedef|typedef
name|ptrdiff_t
name|qopengl_GLintptr
typedef|;
end_typedef
begin_typedef
DECL|typedef|qopengl_GLsizeiptr
typedef|typedef
name|ptrdiff_t
name|qopengl_GLsizeiptr
typedef|;
end_typedef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|APIENTRY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QOPENGLF_APIENTRY
argument_list|)
end_if
begin_define
DECL|macro|QOPENGLF_APIENTRY
define|#
directive|define
name|QOPENGLF_APIENTRY
value|APIENTRY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLF_APIENTRYP
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|QOPENGLF_APIENTRY
end_ifdef
begin_define
DECL|macro|QOPENGLF_APIENTRYP
define|#
directive|define
name|QOPENGLF_APIENTRYP
value|QOPENGLF_APIENTRY *
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QOPENGLF_APIENTRY
define|#
directive|define
name|QOPENGLF_APIENTRY
end_define
begin_define
DECL|macro|QOPENGLF_APIENTRYP
define|#
directive|define
name|QOPENGLF_APIENTRYP
value|*
end_define
begin_endif
endif|#
directive|endif
end_endif
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
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGL_H
end_comment
end_unit
