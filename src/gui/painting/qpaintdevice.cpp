begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpaintdevice.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
name|QPaintDevice
operator|::
name|QPaintDevice
parameter_list|()
name|Q_DECL_NOEXCEPT
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
DECL|function|initPainter
name|void
name|QPaintDevice
operator|::
name|initPainter
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
elseif|else
if|if
condition|(
name|m
operator|==
name|PdmDevicePixelRatio
condition|)
block|{
return|return
literal|1
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
