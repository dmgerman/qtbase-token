begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"glinfo.h"
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/QGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/QGLWidget>
end_include
begin_if
if|#
directive|if
name|QT_VERSION
operator|>
literal|0x050000
end_if
begin_if
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050400
end_if
begin_include
include|#
directive|include
file|<QtWidgets/QOpenGLWidget>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLWindow>
end_include
begin_else
else|#
directive|else
end_else
begin_comment
comment|// 5.4
end_comment
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// 5.0..5.4
end_comment
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTimer>
end_include
begin_namespace
DECL|namespace|QtDiag
namespace|namespace
name|QtDiag
block|{
if|#
directive|if
name|QT_VERSION
operator|>
literal|0x050000
DECL|function|getGlString
specifier|static
name|QString
name|getGlString
parameter_list|(
specifier|const
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|,
name|GLenum
name|name
parameter_list|)
block|{
if|if
condition|(
specifier|const
name|GLubyte
modifier|*
name|p
init|=
name|ctx
operator|->
name|functions
argument_list|()
operator|->
name|glGetString
argument_list|(
name|name
argument_list|)
condition|)
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
DECL|function|glInfo
specifier|static
name|QString
name|glInfo
parameter_list|(
specifier|const
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|)
block|{
return|return
name|getGlString
argument_list|(
name|ctx
argument_list|,
name|GL_VENDOR
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
operator|+
name|getGlString
argument_list|(
name|ctx
argument_list|,
name|GL_RENDERER
argument_list|)
return|;
block|}
DECL|function|glInfo
specifier|static
name|QString
name|glInfo
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|ctx
parameter_list|)
block|{
return|return
name|glInfo
argument_list|(
name|ctx
operator|->
name|contextHandle
argument_list|()
argument_list|)
return|;
block|}
DECL|function|glInfo
name|QString
name|glInfo
parameter_list|(
specifier|const
name|QObject
modifier|*
name|o
parameter_list|)
block|{
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050400
if|if
condition|(
name|o
operator|->
name|isWindowType
argument_list|()
condition|)
block|{
if|if
condition|(
specifier|const
name|QOpenGLWindow
modifier|*
name|oglw
init|=
name|qobject_cast
argument_list|<
specifier|const
name|QOpenGLWindow
operator|*
argument_list|>
argument_list|(
name|o
argument_list|)
condition|)
return|return
name|glInfo
argument_list|(
name|oglw
operator|->
name|context
argument_list|()
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
endif|#
directive|endif
comment|// 5.4
if|if
condition|(
name|o
operator|->
name|isWidgetType
argument_list|()
condition|)
block|{
if|if
condition|(
specifier|const
name|QGLWidget
modifier|*
name|g
init|=
name|qobject_cast
argument_list|<
specifier|const
name|QGLWidget
operator|*
argument_list|>
argument_list|(
name|o
argument_list|)
condition|)
return|return
name|glInfo
argument_list|(
name|g
operator|->
name|context
argument_list|()
argument_list|)
return|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050400
if|if
condition|(
specifier|const
name|QOpenGLWidget
modifier|*
name|g
init|=
name|qobject_cast
argument_list|<
specifier|const
name|QOpenGLWidget
operator|*
argument_list|>
argument_list|(
name|o
argument_list|)
condition|)
return|return
name|glInfo
argument_list|(
name|g
operator|->
name|context
argument_list|()
argument_list|)
return|;
endif|#
directive|endif
comment|// 5.4
block|}
return|return
name|QString
argument_list|()
return|;
block|}
else|#
directive|else
comment|// Qt4:
specifier|static
name|QString
name|getGlString
parameter_list|(
name|GLenum
name|name
parameter_list|)
block|{
if|if
condition|(
specifier|const
name|GLubyte
modifier|*
name|p
init|=
name|glGetString
argument_list|(
name|name
argument_list|)
condition|)
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
name|QString
name|glInfo
parameter_list|(
specifier|const
name|QObject
modifier|*
parameter_list|)
block|{
return|return
name|getGlString
argument_list|(
name|GL_VENDOR
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
operator|+
name|getGlString
argument_list|(
name|GL_RENDERER
argument_list|)
return|;
block|}
endif|#
directive|endif
block|}
end_namespace
begin_comment
comment|// namespace QtDiag
end_comment
end_unit
