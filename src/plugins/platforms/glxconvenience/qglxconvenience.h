begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLXCONVENIENCE_H
end_ifndef
begin_define
DECL|macro|QGLXCONVENIENCE_H
define|#
directive|define
name|QGLXCONVENIENCE_H
end_define
begin_include
include|#
directive|include
file|<QPlatformWindowFormat>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_function_decl
name|XVisualInfo
modifier|*
name|qglx_findVisualInfo
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|int
name|screen
parameter_list|,
specifier|const
name|QPlatformWindowFormat
modifier|&
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|GLXFBConfig
name|qglx_findConfig
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|int
name|screen
parameter_list|,
specifier|const
name|QPlatformWindowFormat
modifier|&
name|format
parameter_list|,
name|int
name|drawableBit
init|=
name|GLX_WINDOW_BIT
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QPlatformWindowFormat
name|qglx_platformWindowFromGLXFBConfig
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|GLXFBConfig
name|config
parameter_list|,
name|GLXContext
name|context
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QVector
operator|<
name|int
operator|>
name|qglx_buildSpec
argument_list|(
argument|const QPlatformWindowFormat&format
argument_list|,
argument|int drawableBit = GLX_WINDOW_BIT
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPlatformWindowFormat
name|qglx_reducePlatformWindowFormat
parameter_list|(
specifier|const
name|QPlatformWindowFormat
modifier|&
name|format
parameter_list|,
name|bool
modifier|*
name|reduced
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLXCONVENIENCE_H
end_comment
end_unit
