begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QEglFSX11Hooks
class|class
name|QEglFSX11Hooks
super|:
specifier|public
name|QEglFSHooks
block|{
public|public:
specifier|virtual
name|void
name|platformInit
parameter_list|()
function_decl|;
specifier|virtual
name|void
name|platformDestroy
parameter_list|()
function_decl|;
specifier|virtual
name|EGLNativeDisplayType
name|platformDisplay
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|QSize
name|screenSize
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|EGLNativeWindowType
name|createNativeWindow
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
specifier|virtual
name|void
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
specifier|virtual
name|bool
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|display
specifier|static
name|Display
modifier|*
name|display
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|platformInit
name|void
name|QEglFSX11Hooks
operator|::
name|platformInit
parameter_list|()
block|{
name|display
operator|=
name|XOpenDisplay
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|display
condition|)
name|qFatal
argument_list|(
literal|"Could not open display"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDestroy
name|void
name|QEglFSX11Hooks
operator|::
name|platformDestroy
parameter_list|()
block|{
name|XCloseDisplay
argument_list|(
name|display
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEglFSX11Hooks
operator|::
name|platformDisplay
parameter_list|()
specifier|const
block|{
return|return
name|display
return|;
block|}
end_function
begin_function
DECL|function|screenSize
name|QSize
name|QEglFSX11Hooks
operator|::
name|screenSize
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|env
init|=
name|qgetenv
argument_list|(
literal|"EGLFS_X11_SIZE"
argument_list|)
operator|.
name|split
argument_list|(
literal|'x'
argument_list|)
decl_stmt|;
if|if
condition|(
name|env
operator|.
name|length
argument_list|()
operator|!=
literal|2
condition|)
return|return
name|QSize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
return|;
return|return
name|QSize
argument_list|(
name|env
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|env
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSX11Hooks
operator|::
name|createNativeWindow
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|Window
name|root
init|=
name|DefaultRootWindow
argument_list|(
name|display
argument_list|)
decl_stmt|;
name|XSetWindowAttributes
name|swa
decl_stmt|;
name|memset
argument_list|(
operator|&
name|swa
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|swa
argument_list|)
argument_list|)
expr_stmt|;
name|Window
name|win
init|=
name|XCreateWindow
argument_list|(
name|display
argument_list|,
name|root
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
name|CopyFromParent
argument_list|,
name|InputOutput
argument_list|,
name|CopyFromParent
argument_list|,
name|CWEventMask
argument_list|,
operator|&
name|swa
argument_list|)
decl_stmt|;
name|XMapWindow
argument_list|(
name|display
argument_list|,
name|win
argument_list|)
expr_stmt|;
name|XStoreName
argument_list|(
name|display
argument_list|,
name|win
argument_list|,
literal|"EGLFS"
argument_list|)
expr_stmt|;
return|return
name|win
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSX11Hooks
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|XDestroyWindow
argument_list|(
name|display
argument_list|,
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSX11Hooks
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|cap
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|eglFSX11Hooks
specifier|static
name|QEglFSX11Hooks
name|eglFSX11Hooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|platformHooks
name|QEglFSHooks
modifier|*
name|platformHooks
init|=
operator|&
name|eglFSX11Hooks
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
