begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmeegointegration.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QDBusConnection>
end_include
begin_include
include|#
directive|include
file|<QDBusArgument>
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowsysteminterface.h>
end_include
begin_constructor
DECL|function|QMeeGoIntegration
name|QMeeGoIntegration
operator|::
name|QMeeGoIntegration
parameter_list|()
member_init_list|:
name|screenTopEdge
argument_list|(
name|QStringLiteral
argument_list|(
literal|"com.nokia.SensorService"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Screen.TopEdge"
argument_list|)
argument_list|)
block|{
name|connect
argument_list|(
operator|&
name|screenTopEdge
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|QVariant
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateScreenOrientation
argument_list|(
name|QVariant
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|updateScreenOrientation
argument_list|(
name|screenTopEdge
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMeeGoIntegration
name|QMeeGoIntegration
operator|::
name|~
name|QMeeGoIntegration
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|updateScreenOrientation
name|void
name|QMeeGoIntegration
operator|::
name|updateScreenOrientation
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|topEdgeValue
parameter_list|)
block|{
name|QString
name|edge
init|=
name|topEdgeValue
operator|.
name|toString
argument_list|()
decl_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
init|=
name|Qt
operator|::
name|PrimaryOrientation
decl_stmt|;
comment|// ### FIXME: This isn't perfect. We should obey the video_route (tv connected) and
comment|// the keyboard slider.
if|if
condition|(
name|edge
operator|==
name|QLatin1String
argument_list|(
literal|"top"
argument_list|)
condition|)
name|orientation
operator|=
name|Qt
operator|::
name|LandscapeOrientation
expr_stmt|;
elseif|else
if|if
condition|(
name|edge
operator|==
name|QLatin1String
argument_list|(
literal|"left"
argument_list|)
condition|)
name|orientation
operator|=
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
elseif|else
if|if
condition|(
name|edge
operator|==
name|QLatin1String
argument_list|(
literal|"right"
argument_list|)
condition|)
name|orientation
operator|=
name|Qt
operator|::
name|InvertedPortraitOrientation
expr_stmt|;
elseif|else
if|if
condition|(
name|edge
operator|==
name|QLatin1String
argument_list|(
literal|"bottom"
argument_list|)
condition|)
name|orientation
operator|=
name|Qt
operator|::
name|InvertedLandscapeOrientation
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenOrientationChange
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
argument_list|,
name|orientation
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
