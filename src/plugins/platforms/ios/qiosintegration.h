begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINTEGRATION_UIKIT_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINTEGRATION_UIKIT_H
define|#
directive|define
name|QPLATFORMINTEGRATION_UIKIT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|"qiosapplicationstate.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformIntegration
name|class
name|QIOSIntegration
range|:
name|public
name|QPlatformIntegration
decl_stmt|,
name|public
name|QPlatformNativeInterface
block|{
name|public
label|:
name|QIOSIntegration
argument_list|()
expr_stmt|;
operator|~
name|QIOSIntegration
argument_list|()
expr_stmt|;
name|bool
name|hasCapability
argument_list|(
name|Capability
name|cap
argument_list|)
decl|const
decl_stmt|;
name|QPlatformWindow
modifier|*
name|createPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
decl_stmt|;
name|QPlatformBackingStore
modifier|*
name|createPlatformBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
decl_stmt|;
name|QPlatformOpenGLContext
modifier|*
name|createPlatformOpenGLContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl|const
decl_stmt|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
expr_stmt|;
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|styleHint
argument_list|(
name|StyleHint
name|hint
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|themeNames
argument_list|()
specifier|const
expr_stmt|;
name|QPlatformTheme
modifier|*
name|createPlatformTheme
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
specifier|const
expr_stmt|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
expr_stmt|;
name|void
modifier|*
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|QTouchDevice
modifier|*
name|touchDevice
parameter_list|()
function_decl|;
name|private
label|:
name|QPlatformFontDatabase
modifier|*
name|m_fontDatabase
decl_stmt|;
name|QPlatformInputContext
modifier|*
name|m_inputContext
decl_stmt|;
name|QPlatformScreen
modifier|*
name|m_screen
decl_stmt|;
name|QTouchDevice
modifier|*
name|m_touchDevice
decl_stmt|;
name|QIOSApplicationState
name|m_applicationState
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
