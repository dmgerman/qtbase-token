begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINTEGRATION_COCOA_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINTEGRATION_COCOA_H
define|#
directive|define
name|QPLATFORMINTEGRATION_COCOA_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|"qcocoaautoreleasepool.h"
end_include
begin_include
include|#
directive|include
file|"qcocoacursor.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformIntegration>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QCocoaScreen
argument_list|(
argument|int screenIndex
argument_list|)
block|;
operator|~
name|QCocoaScreen
argument_list|()
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|{
return|return
name|m_geometry
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|m_depth
return|;
block|}
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|{
return|return
name|m_physicalSize
return|;
block|}
name|public
operator|:
name|NSScreen
operator|*
name|m_screen
block|;
name|QRect
name|m_geometry
block|;
name|int
name|m_depth
block|;
name|QImage
operator|::
name|Format
name|m_format
block|;
name|QSizeF
name|m_physicalSize
block|;
name|QCocoaCursor
operator|*
name|m_cursor
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
name|QCocoaIntegration
argument_list|()
block|;
operator|~
name|QCocoaIntegration
argument_list|()
block|;
name|bool
name|hasCapability
argument_list|(
argument|QPlatformIntegration::Capability cap
argument_list|)
specifier|const
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
block|;
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *widget
argument_list|)
specifier|const
block|;
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
argument_list|()
specifier|const
block|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|;
name|QPlatformAccessibility
operator|*
name|accessibility
argument_list|()
specifier|const
block|;
name|QPlatformTheme
operator|*
name|platformTheme
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QPlatformFontDatabase
operator|>
name|mFontDb
block|;
name|QAbstractEventDispatcher
operator|*
name|mEventDispatcher
block|;
name|QScopedPointer
operator|<
name|QPlatformAccessibility
operator|>
name|mAccessibility
block|;
name|QScopedPointer
operator|<
name|QPlatformTheme
operator|>
name|mPlatformTheme
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
end_unit
