begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
