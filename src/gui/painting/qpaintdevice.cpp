begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpaintdevice.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QPaintDevice
name|QPaintDevice
operator|::
name|QPaintDevice
parameter_list|()
block|{
name|reserved
operator|=
literal|0
expr_stmt|;
name|painters
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QPaintDevice
name|QPaintDevice
operator|::
name|~
name|QPaintDevice
parameter_list|()
block|{
if|if
condition|(
name|paintingActive
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QPaintDevice: Cannot destroy paint device that is being "
literal|"painted"
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|init
name|void
name|QPaintDevice
operator|::
name|init
parameter_list|(
name|QPainter
modifier|*
parameter_list|)
specifier|const
block|{ }
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|redirected
name|QPaintDevice
modifier|*
name|QPaintDevice
operator|::
name|redirected
parameter_list|(
name|QPoint
modifier|*
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|sharedPainter
name|QPainter
modifier|*
name|QPaintDevice
operator|::
name|sharedPainter
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_paint_device_metric
name|Q_GUI_EXPORT
name|int
name|qt_paint_device_metric
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
name|device
parameter_list|,
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|metric
parameter_list|)
block|{
return|return
name|device
operator|->
name|metric
argument_list|(
name|metric
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|metric
name|int
name|QPaintDevice
operator|::
name|metric
parameter_list|(
name|PaintDeviceMetric
name|m
parameter_list|)
specifier|const
block|{
name|qWarning
argument_list|(
literal|"QPaintDevice::metrics: Device has no metric information"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
name|PdmDpiX
condition|)
block|{
return|return
literal|72
return|;
block|}
elseif|else
if|if
condition|(
name|m
operator|==
name|PdmDpiY
condition|)
block|{
return|return
literal|72
return|;
block|}
elseif|else
if|if
condition|(
name|m
operator|==
name|PdmNumColors
condition|)
block|{
comment|// FIXME: does this need to be a real value?
return|return
literal|256
return|;
block|}
else|else
block|{
name|qDebug
argument_list|(
literal|"Unrecognised metric %d!"
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
