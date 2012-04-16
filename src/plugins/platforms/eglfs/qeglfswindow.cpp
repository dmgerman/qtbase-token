begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSWindow
name|QEglFSWindow
operator|::
name|QEglFSWindow
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|w
argument_list|)
block|{
specifier|static
name|int
name|serialNo
init|=
literal|0
decl_stmt|;
name|m_winid
operator|=
operator|++
name|serialNo
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglWindow %p: %p 0x%x\n"
argument_list|,
name|this
argument_list|,
name|w
argument_list|,
name|uint
argument_list|(
name|m_winid
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowFullScreen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setGeometry
name|void
name|QEglFSWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
parameter_list|)
block|{
comment|// We only support full-screen windows
name|QRect
name|rect
argument_list|(
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWindowState
name|Qt
operator|::
name|WindowState
name|QEglFSWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowState
name|state
parameter_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|WindowFullScreen
return|;
block|}
end_function
begin_function
DECL|function|winId
name|WId
name|QEglFSWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
return|return
name|m_winid
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
