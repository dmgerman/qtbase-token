begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenwfdwindow.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdscreen.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_constructor
DECL|function|QOpenWFDWindow
name|QOpenWFDWindow
operator|::
name|QOpenWFDWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
block|{
name|QPlatformScreen
modifier|*
name|platformScreen
init|=
name|QPlatformScreen
operator|::
name|platformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|mPort
operator|=
cast|static_cast
argument_list|<
name|QOpenWFDScreen
operator|*
argument_list|>
argument_list|(
name|platformScreen
argument_list|)
operator|->
name|port
argument_list|()
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|,
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|mPort
operator|->
name|screen
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|port
name|QOpenWFDPort
modifier|*
name|QOpenWFDWindow
operator|::
name|port
parameter_list|()
specifier|const
block|{
return|return
name|mPort
return|;
block|}
end_function
end_unit
