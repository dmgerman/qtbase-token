begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENWFDOUTPUTBUFFER_H
end_ifndef
begin_define
DECL|macro|QOPENWFDOUTPUTBUFFER_H
define|#
directive|define
name|QOPENWFDOUTPUTBUFFER_H
end_define
begin_include
include|#
directive|include
file|"qopenwfdport.h"
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_decl_stmt
name|class
name|QOpenWFDOutputBuffer
block|{
name|public
label|:
name|QOpenWFDOutputBuffer
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|QOpenWFDPort
operator|*
name|port
argument_list|)
expr_stmt|;
operator|~
name|QOpenWFDOutputBuffer
argument_list|()
expr_stmt|;
name|void
name|bindToCurrentFbo
parameter_list|()
function_decl|;
name|bool
name|isAvailable
argument_list|()
specifier|const
block|{
return|return
name|mAvailable
return|;
block|}
name|void
name|setAvailable
parameter_list|(
name|bool
name|available
parameter_list|)
block|{
name|mAvailable
operator|=
name|available
expr_stmt|;
block|}
name|WFDSource
name|wfdSource
argument_list|()
specifier|const
block|{
return|return
name|mWfdSource
return|;
block|}
name|private
label|:
name|QOpenWFDPort
modifier|*
name|mPort
decl_stmt|;
name|WFDSource
name|mWfdSource
decl_stmt|;
name|GLuint
name|mRbo
decl_stmt|;
name|EGLImageKHR
name|mEglImage
decl_stmt|;
name|struct
name|gbm_bo
modifier|*
name|mGbm_buffer
decl_stmt|;
name|bool
name|mAvailable
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENWFDOUTPUTBUFFER_H
end_comment
end_unit
