begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLCONVENIENCE_H
end_ifndef
begin_define
DECL|macro|QEGLCONVENIENCE_H
define|#
directive|define
name|QEGLCONVENIENCE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|QVector
operator|<
name|EGLint
operator|>
name|q_createConfigAttributesFromFormat
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|q_reduceConfigAttributes
argument_list|(
name|QVector
operator|<
name|EGLint
operator|>
operator|*
name|configAttributes
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
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
init|=
name|false
parameter_list|,
name|int
name|surfaceType
init|=
name|EGL_WINDOW_BIT
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
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
function_decl|;
end_function_decl
begin_function_decl
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
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QEGLCONVENIENCE_H
end_comment
end_unit
