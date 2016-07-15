begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsurface.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QSurface     \inmodule QtGui     \since 5.0     \brief The QSurface class is an abstraction of renderable surfaces in Qt.      The size of the surface is accessible with the size() function. The rendering     specific attributes of the surface are accessible through the format() function.  */
end_comment
begin_comment
comment|/*!     \enum QSurface::SurfaceClass      The SurfaceClass enum describes the actual subclass of the surface.      \value Window The surface is an instance of QWindow.  */
end_comment
begin_comment
comment|/*!     \enum QSurface::SurfaceType      The SurfaceType enum describes what type of surface the.      \value RasterSurface The surface is is composed of pixels and can be rendered to using     a software rasterizer like Qt's raster paint engine.     \value OpenGLSurface The surface is an OpenGL compatible surface and can be used     in conjunction with QOpenGLContext.  */
end_comment
begin_comment
comment|/*!     QSize QSurface::size() const      Returns the size of the surface in pixels.  */
end_comment
begin_constructor
DECL|function|QSurface
name|QSurface
operator|::
name|QSurface
parameter_list|(
name|SurfaceClass
name|type
parameter_list|)
member_init_list|:
name|m_type
argument_list|(
name|type
argument_list|)
member_init_list|,
name|m_reserved
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QSurface
name|QSurface
operator|::
name|~
name|QSurface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|surfaceClass
name|QSurface
operator|::
name|SurfaceClass
name|QSurface
operator|::
name|surfaceClass
parameter_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
