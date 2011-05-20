begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QSize
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
name|QSize
name|m_physicalSize
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
name|QPixmapData
operator|*
name|createPixmapData
argument_list|(
argument|QPixmapData::PixelType type
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
name|QWindowSurface
operator|*
name|createWindowSurface
argument_list|(
argument|QWindow *widget
argument_list|,
argument|WId winId
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|screens
argument_list|()
specifier|const
block|{
return|return
name|mScreens
return|;
block|}
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
name|QPlatformEventLoopIntegration
operator|*
name|createEventLoopIntegration
argument_list|()
specifier|const
block|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|mScreens
block|;
name|QPlatformFontDatabase
operator|*
name|mFontDb
block|;
name|QCocoaAutoReleasePool
operator|*
name|mPool
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
