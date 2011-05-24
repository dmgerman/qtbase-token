begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformglcontext_qpa.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QThreadStorage>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_class
DECL|class|QPlatformGLThreadContext
class|class
name|QPlatformGLThreadContext
block|{
public|public:
DECL|function|~QPlatformGLThreadContext
name|~
name|QPlatformGLThreadContext
parameter_list|()
block|{
if|if
condition|(
name|context
condition|)
name|context
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
DECL|member|context
name|QPlatformGLContext
modifier|*
name|context
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|qplatformgl_context_storage
specifier|static
name|QThreadStorage
argument_list|<
name|QPlatformGLThreadContext
modifier|*
argument_list|>
name|qplatformgl_context_storage
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|QPlatformGLContextPrivate
class|class
name|QPlatformGLContextPrivate
block|{
public|public:
DECL|function|QPlatformGLContextPrivate
name|QPlatformGLContextPrivate
parameter_list|()
member_init_list|:
name|qGLContextHandle
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|~QPlatformGLContextPrivate
specifier|virtual
name|~
name|QPlatformGLContextPrivate
parameter_list|()
block|{
comment|//do not delete the QGLContext handle here as it is deleted in
comment|//QWidgetPrivate::deleteTLSysExtra()
block|}
DECL|member|qGLContextHandle
name|void
modifier|*
name|qGLContextHandle
decl_stmt|;
DECL|member|qGLContextDeleteFunction
name|void
function_decl|(
modifier|*
name|qGLContextDeleteFunction
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
DECL|member|staticSharedContext
specifier|static
name|QPlatformGLContext
modifier|*
name|staticSharedContext
decl_stmt|;
specifier|static
name|void
name|setCurrentContext
parameter_list|(
name|QPlatformGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|staticSharedContext
name|QPlatformGLContext
modifier|*
name|QPlatformGLContextPrivate
operator|::
name|staticSharedContext
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|setCurrentContext
name|void
name|QPlatformGLContextPrivate
operator|::
name|setCurrentContext
parameter_list|(
name|QPlatformGLContext
modifier|*
name|context
parameter_list|)
block|{
name|QPlatformGLThreadContext
modifier|*
name|threadContext
init|=
name|qplatformgl_context_storage
operator|.
name|localData
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|threadContext
condition|)
block|{
if|if
condition|(
operator|!
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"No QTLS available. currentContext wont work"
argument_list|)
expr_stmt|;
return|return;
block|}
name|threadContext
operator|=
operator|new
name|QPlatformGLThreadContext
expr_stmt|;
name|qplatformgl_context_storage
operator|.
name|setLocalData
argument_list|(
name|threadContext
argument_list|)
expr_stmt|;
block|}
name|threadContext
operator|->
name|context
operator|=
name|context
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the last context which called makeCurrent. This function is thread aware. */
end_comment
begin_function
DECL|function|currentContext
specifier|const
name|QPlatformGLContext
modifier|*
name|QPlatformGLContext
operator|::
name|currentContext
parameter_list|()
block|{
name|QPlatformGLThreadContext
modifier|*
name|threadContext
init|=
name|qplatformgl_context_storage
operator|.
name|localData
argument_list|()
decl_stmt|;
if|if
condition|(
name|threadContext
condition|)
block|{
return|return
name|threadContext
operator|->
name|context
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     All subclasses needs to specify the platformWindow. It can be a null window. */
end_comment
begin_constructor
DECL|function|QPlatformGLContext
name|QPlatformGLContext
operator|::
name|QPlatformGLContext
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPlatformGLContextPrivate
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   If this is the current context for the thread, doneCurrent is called */
end_comment
begin_destructor
DECL|function|~QPlatformGLContext
name|QPlatformGLContext
operator|::
name|~
name|QPlatformGLContext
parameter_list|()
block|{
if|if
condition|(
name|QPlatformGLContext
operator|::
name|currentContext
argument_list|()
operator|==
name|this
condition|)
block|{
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Reimplement in subclass to do makeCurrent on native GL context */
end_comment
begin_function
DECL|function|makeCurrent
name|void
name|QPlatformGLContext
operator|::
name|makeCurrent
parameter_list|()
block|{
name|QPlatformGLContextPrivate
operator|::
name|setCurrentContext
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Reimplement in subclass to release current context.     Typically this is calling makeCurrent with 0 "surface" */
end_comment
begin_function
DECL|function|doneCurrent
name|void
name|QPlatformGLContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|QPlatformGLContextPrivate
operator|::
name|setCurrentContext
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*   internal: Needs to have a pointer to qGLContext. But since this is in QtGui we cant   have any type information. */
end_comment
begin_function
DECL|function|qGLContextHandle
name|void
modifier|*
name|QPlatformGLContext
operator|::
name|qGLContextHandle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformGLContext
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|qGLContextHandle
return|;
block|}
end_function
begin_function
DECL|function|setQGLContextHandle
name|void
name|QPlatformGLContext
operator|::
name|setQGLContextHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|void
function_decl|(
modifier|*
name|qGLContextDeleteFunction
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformGLContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|qGLContextHandle
operator|=
name|handle
expr_stmt|;
name|d
operator|->
name|qGLContextDeleteFunction
operator|=
name|qGLContextDeleteFunction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteQGLContext
name|void
name|QPlatformGLContext
operator|::
name|deleteQGLContext
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPlatformGLContext
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|qGLContextDeleteFunction
operator|&&
name|d
operator|->
name|qGLContextHandle
condition|)
block|{
name|d
operator|->
name|qGLContextDeleteFunction
argument_list|(
name|d
operator|->
name|qGLContextHandle
argument_list|)
expr_stmt|;
name|d
operator|->
name|qGLContextDeleteFunction
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|qGLContextHandle
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \class QPlatformGLContext     \since 4.8     \internal     \preliminary     \ingroup qpa      \brief The QPlatformGLContext class provides an abstraction for native GL contexts.      In QPA the way to support OpenGL or OpenVG or other technologies that requires a native GL     context is through the QPlatformGLContext wrapper.      There is no factory function for QPlatformGLContexts, but rather only one accessor function.     The only place to retrieve a QPlatformGLContext from is through a QPlatformWindow.      The context which is current for a specific thread can be collected by the currentContext()     function. This is how QPlatformGLContext also makes it possible to use the QtOpenGL module     withhout using QGLWidget. When using QGLContext::currentContext(), it will ask     QPlatformGLContext for the currentContext. Then a corresponding QGLContext will be returned,     which maps to the QPlatformGLContext. */
end_comment
begin_comment
comment|/*! \fn void QPlatformGLContext::swapBuffers()     Reimplement in subclass to native swap buffers calls */
end_comment
begin_comment
comment|/*! \fn void *QPlatformGLContext::getProcAddress(const QString&procName)     Reimplement in subclass to native getProcAddr calls.      Note: its convenient to use qPrintable(const QString&str) to get the const char * pointer */
end_comment
begin_comment
comment|/*! \fn QPlatformWindowFormat QPlatformGLContext::platformWindowFormat() const     QWidget has the function qplatformWindowFormat(). That function is for the application     programmer to request the format of the window and the context that he wants.      Reimplement this function in a subclass to indicate what format the glContext actually has. */
end_comment
end_unit
