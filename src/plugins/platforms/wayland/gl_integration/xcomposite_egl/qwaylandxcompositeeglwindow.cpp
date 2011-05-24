begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandxcompositeeglwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_constructor
DECL|function|QWaylandXCompositeEGLWindow
name|QWaylandXCompositeEGLWindow
operator|::
name|QWaylandXCompositeEGLWindow
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|,
name|QWaylandXCompositeEGLIntegration
modifier|*
name|glxIntegration
parameter_list|)
member_init_list|:
name|QWaylandWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mGlxIntegration
argument_list|(
name|glxIntegration
argument_list|)
member_init_list|,
name|mContext
argument_list|(
literal|0
argument_list|)
block|{  }
end_constructor
begin_function
DECL|function|windowType
name|QWaylandWindow
operator|::
name|WindowType
name|QWaylandXCompositeEGLWindow
operator|::
name|windowType
parameter_list|()
specifier|const
block|{
comment|//yeah. this type needs a new name
return|return
name|QWaylandWindow
operator|::
name|Egl
return|;
block|}
end_function
begin_function
DECL|function|glContext
name|QPlatformGLContext
modifier|*
name|QWaylandXCompositeEGLWindow
operator|::
name|glContext
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mContext
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"creating glcontext;"
expr_stmt|;
name|QWaylandXCompositeEGLWindow
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QWaylandXCompositeEGLWindow
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|mContext
operator|=
operator|new
name|QWaylandXCompositeEGLContext
argument_list|(
name|mGlxIntegration
argument_list|,
name|that
argument_list|)
expr_stmt|;
block|}
return|return
name|mContext
return|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QWaylandXCompositeEGLWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QWaylandWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
if|if
condition|(
name|mContext
condition|)
block|{
name|mContext
operator|->
name|geometryChanged
argument_list|()
expr_stmt|;
block|}
block|}
end_function
end_unit
