begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwinrteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtinputcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtservices.h"
end_include
begin_include
include|#
directive|include
file|"qwinrteglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qwinrttheme.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.core.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.viewmanagement.h>
end_include
begin_include
include|#
directive|include
file|<Windows.ApplicationModel.core.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|Core
namespace|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWinRTIntegration
name|QWinRTIntegration
operator|::
name|QWinRTIntegration
parameter_list|()
member_init_list|:
name|m_success
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_fontDatabase
argument_list|(
operator|new
name|QWinRTFontDatabase
argument_list|)
member_init_list|,
name|m_services
argument_list|(
operator|new
name|QWinRTServices
argument_list|)
block|{
name|m_screen
operator|=
operator|new
name|QWinRTScreen
expr_stmt|;
name|screenAdded
argument_list|(
name|m_screen
argument_list|)
expr_stmt|;
name|m_success
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWinRTIntegration
name|QWinRTIntegration
operator|::
name|~
name|QWinRTIntegration
parameter_list|()
block|{
name|Windows
operator|::
name|Foundation
operator|::
name|Uninitialize
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QWinRTIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QWinRTEventDispatcher
return|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QWinRTIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
case|case
name|OpenGL
case|:
case|case
name|ApplicationState
case|:
return|return
literal|true
return|;
case|case
name|NonFullScreenWindows
case|:
return|return
literal|false
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QWinRTIntegration
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
return|return
name|QWinRTTheme
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWinRTWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWinRTBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|QWinRTScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QWinRTScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
operator|new
name|QWinRTEGLContext
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|,
name|context
operator|->
name|handle
argument_list|()
argument_list|,
name|screen
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|screen
operator|->
name|eglSurface
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QWinRTIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_fontDatabase
return|;
block|}
end_function
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QWinRTIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
return|return
name|m_screen
operator|->
name|inputContext
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QWinRTIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|m_services
return|;
block|}
end_function
begin_function
DECL|function|queryKeyboardModifiers
name|Qt
operator|::
name|KeyboardModifiers
name|QWinRTIntegration
operator|::
name|queryKeyboardModifiers
parameter_list|()
specifier|const
block|{
return|return
name|m_screen
operator|->
name|keyboardModifiers
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|themeNames
name|QStringList
name|QWinRTIntegration
operator|::
name|themeNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QLatin1String
argument_list|(
literal|"winrt"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformTheme
name|QPlatformTheme
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"winrt"
argument_list|)
condition|)
return|return
operator|new
name|QWinRTTheme
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
