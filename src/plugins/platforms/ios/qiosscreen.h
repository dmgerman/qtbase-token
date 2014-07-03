begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
expr_stmt|;
name|QRect
name|availableGeometry
argument_list|()
specifier|const
expr_stmt|;
name|int
name|depth
argument_list|()
specifier|const
expr_stmt|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
expr_stmt|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
expr_stmt|;
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|devicePixelRatio
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
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOrientationUpdateMask
argument_list|(
name|Qt
operator|::
name|ScreenOrientations
name|mask
argument_list|)
decl_stmt|;
name|UIScreen
operator|*
name|uiScreen
argument_list|()
specifier|const
expr_stmt|;
name|void
name|updateProperties
parameter_list|()
function_decl|;
name|void
name|layoutWindows
parameter_list|()
function_decl|;
name|public
name|slots
range|:
name|void
name|updateStatusBarVisibility
argument_list|()
decl_stmt|;
name|private
label|:
name|UIScreen
modifier|*
name|m_uiScreen
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
name|m_unscaledDpi
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
