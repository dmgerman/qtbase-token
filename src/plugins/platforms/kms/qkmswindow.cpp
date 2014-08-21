begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qkmswindow.h"
end_include
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QKmsWindow
name|QKmsWindow
operator|::
name|QKmsWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformWindow
argument_list|)
expr_stmt|;
name|m_screen
operator|=
name|QPlatformScreen
operator|::
name|platformScreenForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
name|QKmsScreen
operator|*
argument_list|>
argument_list|(
name|m_screen
argument_list|)
operator|->
name|initializeWithFormat
argument_list|(
name|window
operator|->
name|requestedFormat
argument_list|()
argument_list|)
expr_stmt|;
name|setGeometry
argument_list|(
name|d
operator|->
name|rect
argument_list|)
expr_stmt|;
comment|// rect is set to window->geometry() in base ctor
block|}
end_constructor
begin_function
DECL|function|setGeometry
name|void
name|QKmsWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
comment|// All windows must be fullscreen
name|QRect
name|fullscreenRect
init|=
name|m_screen
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|rect
operator|!=
name|fullscreenRect
condition|)
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|fullscreenRect
argument_list|)
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|fullscreenRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
