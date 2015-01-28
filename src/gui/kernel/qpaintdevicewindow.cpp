begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpaintdevicewindow_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPaintDeviceWindow     \inmodule QtGui     \since 5.4     \brief Convenience subclass of QWindow that is also a QPaintDevice.      QPaintDeviceWindow is like a regular QWindow, with the added functionality     of being a paint device too. Whenever the content needs to be updated,     the virtual paintEvent() function is called. Subclasses, that reimplement     this function, can then simply open a QPainter on the window.      \note This class cannot directly be used in applications. It rather serves     as a base for subclasses like QOpenGLWindow.      \sa QOpenGLWindow */
comment|/*!     Marks the entire window as dirty and schedules a repaint.      \note Subsequent calls to this function before the next paint     event will get ignored. */
DECL|function|update
name|void
name|QPaintDeviceWindow
operator|::
name|update
parameter_list|()
block|{
name|update
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Marks the \a rect of the window as dirty and schedules a repaint.      \note Subsequent calls to this function before the next paint     event will get ignored. */
end_comment
begin_function
DECL|function|update
name|void
name|QPaintDeviceWindow
operator|::
name|update
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPaintDeviceWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|dirtyRegion
operator|+=
name|rect
expr_stmt|;
name|requestUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Marks the \a region of the window as dirty and schedules a repaint.      \note Subsequent calls to this function before the next paint     event will get ignored. */
end_comment
begin_function
DECL|function|update
name|void
name|QPaintDeviceWindow
operator|::
name|update
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPaintDeviceWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|dirtyRegion
operator|+=
name|region
expr_stmt|;
name|requestUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Handles paint events passed in the \a event parameter.      The default implementation does nothing. Reimplement this function to     perform painting. If necessary, the dirty area is retrievable from     the \a event. */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QPaintDeviceWindow
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
comment|// Do nothing
block|}
end_function
begin_comment
comment|/*!   \internal  */
end_comment
begin_function
DECL|function|metric
name|int
name|QPaintDeviceWindow
operator|::
name|metric
parameter_list|(
name|PaintDeviceMetric
name|metric
parameter_list|)
specifier|const
block|{
name|QScreen
modifier|*
name|screen
init|=
name|this
operator|->
name|screen
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|screen
operator|&&
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
condition|)
name|screen
operator|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|PdmWidth
case|:
return|return
name|width
argument_list|()
return|;
case|case
name|PdmWidthMM
case|:
if|if
condition|(
name|screen
condition|)
return|return
name|width
argument_list|()
operator|*
name|screen
operator|->
name|physicalSize
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
return|;
break|break;
case|case
name|PdmHeight
case|:
return|return
name|height
argument_list|()
return|;
case|case
name|PdmHeightMM
case|:
if|if
condition|(
name|screen
condition|)
return|return
name|height
argument_list|()
operator|*
name|screen
operator|->
name|physicalSize
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
return|;
break|break;
case|case
name|PdmDpiX
case|:
if|if
condition|(
name|screen
condition|)
return|return
name|qRound
argument_list|(
name|screen
operator|->
name|logicalDotsPerInchX
argument_list|()
argument_list|)
return|;
break|break;
case|case
name|PdmDpiY
case|:
if|if
condition|(
name|screen
condition|)
return|return
name|qRound
argument_list|(
name|screen
operator|->
name|logicalDotsPerInchY
argument_list|()
argument_list|)
return|;
break|break;
case|case
name|PdmPhysicalDpiX
case|:
if|if
condition|(
name|screen
condition|)
return|return
name|qRound
argument_list|(
name|screen
operator|->
name|physicalDotsPerInchX
argument_list|()
argument_list|)
return|;
break|break;
case|case
name|PdmPhysicalDpiY
case|:
if|if
condition|(
name|screen
condition|)
return|return
name|qRound
argument_list|(
name|screen
operator|->
name|physicalDotsPerInchY
argument_list|()
argument_list|)
return|;
break|break;
case|case
name|PdmDevicePixelRatio
case|:
if|if
condition|(
name|screen
condition|)
return|return
name|screen
operator|->
name|devicePixelRatio
argument_list|()
return|;
break|break;
default|default:
break|break;
block|}
return|return
name|QPaintDevice
operator|::
name|metric
argument_list|(
name|metric
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal  */
end_comment
begin_function
DECL|function|exposeEvent
name|void
name|QPaintDeviceWindow
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
name|exposeEvent
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|exposeEvent
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
name|QPaintDeviceWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|isExposed
argument_list|()
condition|)
block|{
name|d
operator|->
name|markWindowAsDirty
argument_list|()
expr_stmt|;
comment|// Do not rely on exposeEvent->region() as it has some issues for the
comment|// time being, namely that it is sometimes in local coordinates,
comment|// sometimes relative to the parent, depending on the platform plugin.
comment|// We require local coords here.
name|d
operator|->
name|doFlush
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   \internal  */
end_comment
begin_function
DECL|function|event
name|bool
name|QPaintDeviceWindow
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPaintDeviceWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|UpdateRequest
condition|)
block|{
if|if
condition|(
name|handle
argument_list|()
condition|)
comment|// platform window may be gone when the window is closed during app exit
name|d
operator|->
name|handleUpdateEvent
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|QWindow
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal  */
end_comment
begin_constructor
DECL|function|QPaintDeviceWindow
name|QPaintDeviceWindow
operator|::
name|QPaintDeviceWindow
parameter_list|(
name|QPaintDeviceWindowPrivate
modifier|&
name|dd
parameter_list|,
name|QWindow
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWindow
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   \internal  */
end_comment
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QPaintDeviceWindow
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
