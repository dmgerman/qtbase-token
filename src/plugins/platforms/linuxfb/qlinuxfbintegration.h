begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSYSTEM_LINUXFB_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSYSTEM_LINUXFB_H
define|#
directive|define
name|QGRAPHICSSYSTEM_LINUXFB_H
end_define
begin_include
include|#
directive|include
file|<QPlatformIntegration>
end_include
begin_include
include|#
directive|include
file|"../fb_base/fb_base.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QLinuxFbScreen
range|:
name|public
name|QFbScreen
block|{
name|Q_OBJECT
name|public
operator|:
name|QLinuxFbScreen
argument_list|(
argument|uchar * d
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|int lstep
argument_list|,
argument|QImage::Format screenFormat
argument_list|)
block|;
name|void
name|setGeometry
argument_list|(
argument|QRect rect
argument_list|)
block|;
name|void
name|setFormat
argument_list|(
argument|QImage::Format format
argument_list|)
block|;
name|public
name|slots
operator|:
name|QRegion
name|doRedraw
argument_list|()
block|;
name|private
operator|:
name|QImage
operator|*
name|mFbScreenImage
block|;
name|uchar
operator|*
name|data
block|;
name|int
name|bytesPerLine
block|;
name|QPainter
operator|*
name|compositePainter
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLinuxFbIntegrationPrivate
name|class
name|QLinuxFbIntegrationPrivate
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|fb_cmap
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|fb_var_screeninfo
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|fb_fix_screeninfo
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QLinuxFbIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
name|QLinuxFbIntegration
argument_list|()
block|;
operator|~
name|QLinuxFbIntegration
argument_list|()
block|;
name|bool
name|hasCapability
argument_list|(
argument|QPlatformIntegration::Capability cap
argument_list|)
specifier|const
block|;
name|QPlatformPixmap
operator|*
name|createPlatformPixmap
argument_list|(
argument|QPlatformPixmap::PixelType type
argument_list|)
specifier|const
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWidget *widget
argument_list|,
argument|WId WinId
argument_list|)
specifier|const
block|;
name|QWindowSurface
operator|*
name|createWindowSurface
argument_list|(
argument|QWidget *widget
argument_list|,
argument|WId WinId
argument_list|)
specifier|const
block|;
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
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
name|private
operator|:
name|QLinuxFbScreen
operator|*
name|mPrimaryScreen
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|mScreens
block|;
name|QLinuxFbIntegrationPrivate
operator|*
name|d_ptr
block|;      enum
name|PixelType
block|{
name|NormalPixel
block|,
name|BGRPixel
block|}
block|;
name|QRgb
name|screenclut
index|[
literal|256
index|]
block|;
name|int
name|screencols
block|;
name|uchar
operator|*
name|data
block|;
name|QImage
operator|::
name|Format
name|screenFormat
block|;
name|int
name|w
block|;
name|int
name|lstep
block|;
name|int
name|h
block|;
name|int
name|d
block|;
name|PixelType
name|pixeltype
block|;
name|bool
name|grayscale
block|;
name|int
name|dw
block|;
name|int
name|dh
block|;
name|int
name|size
block|;
comment|// Screen size
name|int
name|mapsize
block|;
comment|// Total mapped memory
name|int
name|displayId
block|;
name|int
name|physWidth
block|;
name|int
name|physHeight
block|;
name|bool
name|canaccel
block|;
name|int
name|dataoffset
block|;
name|int
name|cacheStart
block|;
name|bool
name|connect
argument_list|(
specifier|const
name|QString
operator|&
name|displaySpec
argument_list|)
block|;
name|bool
name|initDevice
argument_list|()
block|;
name|void
name|setPixelFormat
argument_list|(
expr|struct
name|fb_var_screeninfo
argument_list|)
block|;
name|void
name|createPalette
argument_list|(
name|fb_cmap
operator|&
name|cmap
argument_list|,
name|fb_var_screeninfo
operator|&
name|vinfo
argument_list|,
name|fb_fix_screeninfo
operator|&
name|finfo
argument_list|)
block|;
name|void
name|blank
argument_list|(
argument|bool on
argument_list|)
block|;
name|QPlatformFontDatabase
operator|*
name|fontDb
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
