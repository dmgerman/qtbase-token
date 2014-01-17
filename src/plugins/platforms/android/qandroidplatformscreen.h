begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDPLATFORMSCREEN_H
end_ifndef
begin_define
DECL|macro|QANDROIDPLATFORMSCREEN_H
define|#
directive|define
name|QANDROIDPLATFORMSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QWaitCondition>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qjni_p.h>
end_include
begin_include
include|#
directive|include
file|"androidsurfaceclient.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAndroidPlatformWindow
name|class
name|QAndroidPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAndroidPlatformBackingStore
name|class
name|QAndroidPlatformBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
DECL|variable|QPlatformScreen
name|class
name|QAndroidPlatformScreen
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformScreen
decl_stmt|,
name|public
name|AndroidSurfaceClient
block|{
name|Q_OBJECT
name|public
range|:
name|QAndroidPlatformScreen
argument_list|()
decl_stmt|;
operator|~
name|QAndroidPlatformScreen
argument_list|()
expr_stmt|;
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
specifier|inline
name|QWindow
operator|*
name|topWindow
argument_list|()
specifier|const
expr_stmt|;
name|QWindow
modifier|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
comment|// compositor api
name|void
name|addWindow
parameter_list|(
name|QAndroidPlatformWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|removeWindow
parameter_list|(
name|QAndroidPlatformWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|raise
parameter_list|(
name|QAndroidPlatformWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|lower
parameter_list|(
name|QAndroidPlatformWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|scheduleUpdate
parameter_list|()
function_decl|;
name|void
name|topWindowChanged
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
function_decl|;
name|public
name|slots
range|:
name|void
name|setDirty
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
decl_stmt|;
name|void
name|setPhysicalSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|protected
label|:
typedef|typedef
name|QList
operator|<
name|QAndroidPlatformWindow
operator|*
operator|>
name|WindowStackType
expr_stmt|;
name|WindowStackType
name|m_windowStack
decl_stmt|;
name|QRegion
name|m_repaintRegion
decl_stmt|;
name|QTimer
name|m_redrawTimer
decl_stmt|;
name|QRect
name|m_geometry
decl_stmt|;
name|int
name|m_depth
decl_stmt|;
name|QImage
operator|::
name|Format
name|m_format
expr_stmt|;
name|QSizeF
name|m_physicalSize
decl_stmt|;
name|private
label|:
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
expr_stmt|;
name|void
name|surfaceChanged
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
name|surface
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
function_decl|;
name|private
name|slots
range|:
name|void
name|doRedraw
argument_list|()
decl_stmt|;
name|private
label|:
name|int
name|m_id
init|=
operator|-
literal|1
decl_stmt|;
name|QJNIObjectPrivate
name|m_surface
decl_stmt|;
name|jobject
name|m_bitmap
init|=
name|nullptr
decl_stmt|;
name|QWaitCondition
name|m_surfaceWaitCondition
decl_stmt|;
name|int
name|m_bitmapStride
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|m_bitmapWidth
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|m_bitmapHeight
init|=
operator|-
literal|1
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
