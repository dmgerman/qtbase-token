begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd and/or its subsidiary(-ies). ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QWindow
name|window
decl_stmt|;
name|window
operator|.
name|setSurfaceType
argument_list|(
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|window
operator|.
name|create
argument_list|()
expr_stmt|;
name|QOpenGLContext
name|context
decl_stmt|;
name|context
operator|.
name|create
argument_list|()
expr_stmt|;
name|QPlatformNativeInterface
modifier|*
name|ni
init|=
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"EGLDisplay"
operator|<<
name|ni
operator|->
name|nativeResourceForWindow
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"egldisplay"
argument_list|)
argument_list|,
operator|&
name|window
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"EGLContext"
operator|<<
name|ni
operator|->
name|nativeResourceForContext
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"eglcontext"
argument_list|)
argument_list|,
operator|&
name|context
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"EGLConfig"
operator|<<
name|ni
operator|->
name|nativeResourceForContext
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"eglconfig"
argument_list|)
argument_list|,
operator|&
name|context
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"GLXContext"
operator|<<
name|ni
operator|->
name|nativeResourceForContext
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glxcontext"
argument_list|)
argument_list|,
operator|&
name|context
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"GLXConfig"
operator|<<
name|ni
operator|->
name|nativeResourceForContext
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"glxconfig"
argument_list|)
argument_list|,
operator|&
name|context
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
