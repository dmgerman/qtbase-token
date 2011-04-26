begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QLibrary>
end_include
begin_include
include|#
directive|include
file|<QGLFormat>
end_include
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowContext>
end_include
begin_include
include|#
directive|include
file|"qglxintegration.h"
end_include
begin_include
include|#
directive|include
file|"qglxconvenience.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
end_if
begin_include
include|#
directive|include
file|<dlfcn.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QGLXContext
name|QGLXContext
operator|::
name|QGLXContext
parameter_list|(
name|Window
name|window
parameter_list|,
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QWindowFormat
modifier|&
name|format
parameter_list|)
member_init_list|:
name|QPlatformGLContext
argument_list|()
member_init_list|,
name|m_screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_drawable
argument_list|(
operator|(
name|Drawable
operator|)
name|window
argument_list|)
member_init_list|,
name|m_context
argument_list|(
literal|0
argument_list|)
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QWindowContext
modifier|*
name|shareContext
init|=
name|format
operator|.
name|sharedContext
argument_list|()
decl_stmt|;
name|GLXContext
name|shareGlxContext
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|shareContext
condition|)
name|shareGlxContext
operator|=
cast|static_cast
argument_list|<
specifier|const
name|QGLXContext
operator|*
argument_list|>
argument_list|(
name|shareContext
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|glxContext
argument_list|()
expr_stmt|;
name|GLXFBConfig
name|config
init|=
name|qglx_findConfig
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|screen
operator|->
name|screenNumber
argument_list|()
argument_list|,
name|format
argument_list|)
decl_stmt|;
name|m_context
operator|=
name|glXCreateNewContext
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|config
argument_list|,
name|GLX_RGBA_TYPE
argument_list|,
name|shareGlxContext
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|m_windowFormat
operator|=
name|qglx_platformWindowFromGLXFBConfig
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|screen
argument_list|)
argument_list|,
name|config
argument_list|,
name|m_context
argument_list|)
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QGLXContext
name|QGLXContext
operator|::
name|QGLXContext
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
name|Drawable
name|drawable
parameter_list|,
name|GLXContext
name|context
parameter_list|)
member_init_list|:
name|QPlatformGLContext
argument_list|()
member_init_list|,
name|m_screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_drawable
argument_list|(
name|drawable
argument_list|)
member_init_list|,
name|m_context
argument_list|(
name|context
argument_list|)
block|{  }
end_constructor
begin_destructor
DECL|function|~QGLXContext
name|QGLXContext
operator|::
name|~
name|QGLXContext
parameter_list|()
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_context
condition|)
name|glXDestroyContext
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|m_context
argument_list|)
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|makeCurrent
name|void
name|QGLXContext
operator|::
name|makeCurrent
parameter_list|()
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
name|QPlatformGLContext
operator|::
name|makeCurrent
argument_list|()
expr_stmt|;
name|glXMakeCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|m_drawable
argument_list|,
name|m_context
argument_list|)
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QGLXContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
name|QPlatformGLContext
operator|::
name|doneCurrent
argument_list|()
expr_stmt|;
name|glXMakeCurrent
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QGLXContext
operator|::
name|swapBuffers
parameter_list|()
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
name|glXSwapBuffers
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|m_drawable
argument_list|)
expr_stmt|;
name|doneCurrent
argument_list|()
expr_stmt|;
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getProcAddress
name|void
modifier|*
name|QGLXContext
operator|::
name|getProcAddress
parameter_list|(
specifier|const
name|QString
modifier|&
name|procName
parameter_list|)
block|{
name|Q_XCB_NOOP
argument_list|(
name|m_screen
operator|->
name|connection
argument_list|()
argument_list|)
expr_stmt|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|qt_glXGetProcAddressARB
function_decl|)
parameter_list|(
specifier|const
name|GLubyte
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|qt_glXGetProcAddressARB
name|glXGetProcAddressARB
init|=
literal|0
decl_stmt|;
specifier|static
name|bool
name|resolved
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|resolved
operator|&&
operator|!
name|glXGetProcAddressARB
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|glXGetProcAddressARB
condition|)
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|glxExt
init|=
name|QByteArray
argument_list|(
name|glXGetClientString
argument_list|(
name|DISPLAY_FROM_XCB
argument_list|(
name|m_screen
argument_list|)
argument_list|,
name|GLX_EXTENSIONS
argument_list|)
argument_list|)
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
if|if
condition|(
name|glxExt
operator|.
name|contains
argument_list|(
literal|"GLX_ARB_get_proc_address"
argument_list|)
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
name|void
modifier|*
name|handle
init|=
name|dlopen
argument_list|(
name|NULL
argument_list|,
name|RTLD_LAZY
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
condition|)
block|{
name|glXGetProcAddressARB
operator|=
operator|(
name|qt_glXGetProcAddressARB
operator|)
name|dlsym
argument_list|(
name|handle
argument_list|,
literal|"glXGetProcAddressARB"
argument_list|)
expr_stmt|;
name|dlclose
argument_list|(
name|handle
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|glXGetProcAddressARB
condition|)
endif|#
directive|endif
block|{
specifier|extern
specifier|const
name|QString
name|qt_gl_library_name
argument_list|()
decl_stmt|;
comment|//                QLibrary lib(qt_gl_library_name());
name|QLibrary
name|lib
argument_list|(
name|QLatin1String
argument_list|(
literal|"GL"
argument_list|)
argument_list|)
decl_stmt|;
name|glXGetProcAddressARB
operator|=
operator|(
name|qt_glXGetProcAddressARB
operator|)
name|lib
operator|.
name|resolve
argument_list|(
literal|"glXGetProcAddressARB"
argument_list|)
expr_stmt|;
block|}
block|}
name|resolved
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|glXGetProcAddressARB
condition|)
return|return
literal|0
return|;
return|return
name|glXGetProcAddressARB
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|GLubyte
operator|*
argument_list|>
argument_list|(
name|procName
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|windowFormat
name|QWindowFormat
name|QGLXContext
operator|::
name|windowFormat
parameter_list|()
specifier|const
block|{
return|return
name|m_windowFormat
return|;
block|}
end_function
end_unit
