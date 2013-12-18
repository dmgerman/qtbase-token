begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsurface.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QSurface     \inmodule QtGui     \since 5.0     \brief The QSurface class is an abstraction of renderable surfaces in Qt.      The size of the surface is accessible with the size() function. The rendering     specific attributes of the surface are accessible through the format() function.  */
comment|/*!     \enum QSurface::SurfaceClass      The SurfaceClass enum describes the actual subclass of the surface.      \value Window The surface is an instance of QWindow.     \value Offscreen The surface is an instance of QOffscreenSurface.  */
comment|/*!     \enum QSurface::SurfaceType      The SurfaceType enum describes what type of surface this is.      \value RasterSurface The surface is is composed of pixels and can be rendered to using     a software rasterizer like Qt's raster paint engine.     \value OpenGLSurface The surface is an OpenGL compatible surface and can be used     in conjunction with QOpenGLContext.     \value RasterGLSurface The surface can be rendered to using a software rasterizer,     and also supports OpenGL. This surface type is intended for internal Qt use, and     requires the use of private API.  */
comment|/*!     \fn QSurfaceFormat QSurface::format() const      Returns the format of the surface.  */
comment|/*!   Returns true if the surface is OpenGL compatible and can be used in   conjunction with QOpenGLContext; otherwise returns false.    \since 5.3 */
DECL|function|supportsOpenGL
name|bool
name|QSurface
operator|::
name|supportsOpenGL
parameter_list|()
specifier|const
block|{
name|SurfaceType
name|type
init|=
name|surfaceType
argument_list|()
decl_stmt|;
return|return
name|type
operator|==
name|OpenGLSurface
operator|||
name|type
operator|==
name|RasterGLSurface
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QPlatformSurface *QSurface::surfaceHandle() const      Returns a handle to the platform-specific implementation of the surface.  */
end_comment
begin_comment
comment|/*!     \fn SurfaceType QSurface::surfaceType() const      Returns the type of the surface.  */
end_comment
begin_comment
comment|/*!     \fn QSize QSurface::size() const      Returns the size of the surface in pixels.  */
end_comment
begin_comment
comment|/*!     Creates a surface with the given \a type. */
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
begin_comment
comment|/*!     Destroys the surface. */
end_comment
begin_destructor
DECL|function|~QSurface
name|QSurface
operator|::
name|~
name|QSurface
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!    Returns the surface class of this surface.  */
end_comment
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
