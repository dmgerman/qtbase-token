begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENWFDNATIVEINTERFACE_H
end_ifndef
begin_define
DECL|macro|QOPENWFDNATIVEINTERFACE_H
define|#
directive|define
name|QOPENWFDNATIVEINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<WF/wfdplatform.h>
end_include
begin_decl_stmt
DECL|variable|QOpenWFDScreen
name|class
name|QOpenWFDScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenWFDNativeInterface
range|:
name|public
name|QPlatformNativeInterface
block|{
name|public
operator|:
expr|enum
name|ResourceType
block|{
name|WFDDevice
block|,
name|EglDisplay
block|,
name|EglContext
block|,
name|WFDPort
block|,
name|WFDPipeline
block|}
block|;
name|void
operator|*
name|nativeResourceForContext
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resourceString
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
name|void
operator|*
name|nativeResourceForWindow
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resourceString
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|WFDHandle
name|wfdDeviceForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
operator|*
name|eglDisplayForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|WFDHandle
name|wfdPortForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|WFDHandle
name|wfdPipelineForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
operator|*
name|eglContextForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
name|private
operator|:
specifier|static
name|QOpenWFDScreen
operator|*
name|qPlatformScreenForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENWFDNATIVEINTERFACE_H
end_comment
end_unit
