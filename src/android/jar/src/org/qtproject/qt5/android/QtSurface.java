begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the Android port of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_package
DECL|package|org.qtproject.qt5.android
package|package
name|org
operator|.
name|qtproject
operator|.
name|qt5
operator|.
name|android
package|;
end_package
begin_import
import|import
name|android
operator|.
name|app
operator|.
name|Activity
import|;
end_import
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|Context
import|;
end_import
begin_import
import|import
name|android
operator|.
name|graphics
operator|.
name|PixelFormat
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|GestureDetector
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|MotionEvent
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|SurfaceHolder
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|SurfaceView
import|;
end_import
begin_import
import|import
name|java
operator|.
name|lang
operator|.
name|reflect
operator|.
name|Constructor
import|;
end_import
begin_import
import|import
name|java
operator|.
name|lang
operator|.
name|reflect
operator|.
name|Method
import|;
end_import
begin_class
DECL|class|QtSurface
specifier|public
class|class
name|QtSurface
extends|extends
name|SurfaceView
implements|implements
name|SurfaceHolder
operator|.
name|Callback
block|{
DECL|field|m_gestureDetector
specifier|private
name|GestureDetector
name|m_gestureDetector
decl_stmt|;
DECL|field|m_accessibilityDelegate
specifier|private
name|Object
name|m_accessibilityDelegate
init|=
literal|null
decl_stmt|;
DECL|method|QtSurface
specifier|public
name|QtSurface
parameter_list|(
name|Context
name|context
parameter_list|,
name|int
name|id
parameter_list|,
name|boolean
name|onTop
parameter_list|,
name|int
name|imageDepth
parameter_list|)
block|{
name|super
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|setFocusable
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setFocusableInTouchMode
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setZOrderMediaOverlay
argument_list|(
name|onTop
argument_list|)
expr_stmt|;
name|getHolder
argument_list|()
operator|.
name|addCallback
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|imageDepth
operator|==
literal|16
condition|)
name|getHolder
argument_list|()
operator|.
name|setFormat
argument_list|(
name|PixelFormat
operator|.
name|RGB_565
argument_list|)
expr_stmt|;
else|else
name|getHolder
argument_list|()
operator|.
name|setFormat
argument_list|(
name|PixelFormat
operator|.
name|RGBA_8888
argument_list|)
expr_stmt|;
if|if
condition|(
name|android
operator|.
name|os
operator|.
name|Build
operator|.
name|VERSION
operator|.
name|SDK_INT
operator|<
literal|11
condition|)
name|getHolder
argument_list|()
operator|.
name|setType
argument_list|(
name|SurfaceHolder
operator|.
name|SURFACE_TYPE_GPU
argument_list|)
expr_stmt|;
name|setId
argument_list|(
name|id
argument_list|)
expr_stmt|;
name|m_gestureDetector
operator|=
operator|new
name|GestureDetector
argument_list|(
name|context
argument_list|,
operator|new
name|GestureDetector
operator|.
name|SimpleOnGestureListener
argument_list|()
block|{
specifier|public
name|void
name|onLongPress
parameter_list|(
name|MotionEvent
name|event
parameter_list|)
block|{
name|QtNative
operator|.
name|longPress
argument_list|(
name|getId
argument_list|()
argument_list|,
operator|(
name|int
operator|)
name|event
operator|.
name|getX
argument_list|()
argument_list|,
operator|(
name|int
operator|)
name|event
operator|.
name|getY
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
name|m_gestureDetector
operator|.
name|setIsLongpressEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
annotation|@
name|Override
DECL|method|surfaceCreated
specifier|public
name|void
name|surfaceCreated
parameter_list|(
name|SurfaceHolder
name|holder
parameter_list|)
block|{     }
annotation|@
name|Override
DECL|method|surfaceChanged
specifier|public
name|void
name|surfaceChanged
parameter_list|(
name|SurfaceHolder
name|holder
parameter_list|,
name|int
name|format
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
if|if
condition|(
name|width
operator|<
literal|1
operator|||
name|height
operator|<
literal|1
condition|)
return|return;
name|QtNative
operator|.
name|setSurface
argument_list|(
name|getId
argument_list|()
argument_list|,
name|holder
operator|.
name|getSurface
argument_list|()
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
block|}
annotation|@
name|Override
DECL|method|surfaceDestroyed
specifier|public
name|void
name|surfaceDestroyed
parameter_list|(
name|SurfaceHolder
name|holder
parameter_list|)
block|{
name|QtNative
operator|.
name|setSurface
argument_list|(
name|getId
argument_list|()
argument_list|,
literal|null
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
annotation|@
name|Override
DECL|method|onTouchEvent
specifier|public
name|boolean
name|onTouchEvent
parameter_list|(
name|MotionEvent
name|event
parameter_list|)
block|{
name|QtNative
operator|.
name|sendTouchEvent
argument_list|(
name|event
argument_list|,
name|getId
argument_list|()
argument_list|)
expr_stmt|;
name|m_gestureDetector
operator|.
name|onTouchEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
annotation|@
name|Override
DECL|method|onTrackballEvent
specifier|public
name|boolean
name|onTrackballEvent
parameter_list|(
name|MotionEvent
name|event
parameter_list|)
block|{
name|QtNative
operator|.
name|sendTrackballEvent
argument_list|(
name|event
argument_list|,
name|getId
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
end_class
end_unit
