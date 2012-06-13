begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSWINDOW_H
end_ifndef
begin_define
DECL|macro|QEGLFSWINDOW_H
define|#
directive|define
name|QEGLFSWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qeglfsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfsscreen.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QEglFSWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|QEglFSWindow
argument_list|(
name|QWindow
operator|*
name|w
argument_list|)
block|;
operator|~
name|QEglFSWindow
argument_list|()
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
block|;
name|Qt
operator|::
name|WindowState
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|;
name|EGLSurface
name|surface
argument_list|()
specifier|const
block|{
return|return
name|m_surface
return|;
block|}
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|void
name|create
argument_list|()
block|;
name|void
name|destroy
argument_list|()
block|;
name|private
operator|:
name|WId
name|m_winid
block|;
name|EGLSurface
name|m_surface
block|;
name|EGLNativeWindowType
name|m_window
block|;
name|QSurfaceFormat
name|m_format
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEGLFSWINDOW_H
end_comment
end_unit
