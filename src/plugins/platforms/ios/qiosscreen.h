begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIOSSCREEN_H
end_ifndef
begin_define
DECL|macro|QIOSSCREEN_H
define|#
directive|define
name|QIOSSCREEN_H
end_define
begin_include
include|#
directive|include
file|<UIKit/UIKit.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_decl_stmt
unit|@
DECL|variable|QIOSOrientationListener
name|class
name|QIOSOrientationListener
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QObject
name|class
name|QIOSScreen
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformScreen
block|{
name|Q_OBJECT
name|public
range|:
name|QIOSScreen
argument_list|(
name|UIScreen
operator|*
name|screen
argument_list|)
decl_stmt|;
operator|~
name|QIOSScreen
argument_list|()
expr_stmt|;
name|QRect
name|geometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QRect
name|availableGeometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|int
name|depth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setOrientationUpdateMask
argument_list|(
name|Qt
operator|::
name|ScreenOrientations
name|mask
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|UIScreen
operator|*
name|uiScreen
argument_list|()
specifier|const
expr_stmt|;
name|UIWindow
operator|*
name|uiWindow
argument_list|()
specifier|const
expr_stmt|;
name|void
name|updateProperties
parameter_list|()
function_decl|;
name|private
label|:
name|UIScreen
modifier|*
name|m_uiScreen
decl_stmt|;
name|UIWindow
modifier|*
name|m_uiWindow
decl_stmt|;
name|QRect
name|m_geometry
decl_stmt|;
name|QRect
name|m_availableGeometry
decl_stmt|;
name|int
name|m_depth
decl_stmt|;
name|uint
name|m_physicalDpi
decl_stmt|;
name|QSizeF
name|m_physicalSize
decl_stmt|;
name|QIOSOrientationListener
modifier|*
name|m_orientationListener
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
