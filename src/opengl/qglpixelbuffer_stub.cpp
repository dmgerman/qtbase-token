begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qglpixelbuffer.h"
end_include
begin_include
include|#
directive|include
file|"qglpixelbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<private/qgl_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|init
name|bool
name|QGLPixelBufferPrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QGLFormat
modifier|&
name|f
parameter_list|,
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|shareWidget
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|cleanup
name|bool
name|QGLPixelBufferPrivate
operator|::
name|cleanup
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|bindToDynamicTexture
name|bool
name|QGLPixelBuffer
operator|::
name|bindToDynamicTexture
parameter_list|(
name|GLuint
name|texture_id
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|texture_id
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|releaseFromDynamicTexture
name|void
name|QGLPixelBuffer
operator|::
name|releaseFromDynamicTexture
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|generateDynamicTexture
name|GLuint
name|QGLPixelBuffer
operator|::
name|generateDynamicTexture
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|hasOpenGLPbuffers
name|bool
name|QGLPixelBuffer
operator|::
name|hasOpenGLPbuffers
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
