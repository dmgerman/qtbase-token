begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENWFDSCREEN_H
end_ifndef
begin_define
DECL|macro|QOPENWFDSCREEN_H
define|#
directive|define
name|QOPENWFDSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|"qopenwfdoutputbuffer.h"
end_include
begin_include
include|#
directive|include
file|<WF/wfd.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVarLengthArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLinkedList>
end_include
begin_define
DECL|macro|BUFFER_NUM
define|#
directive|define
name|BUFFER_NUM
value|4
end_define
begin_decl_stmt
DECL|variable|QOpenWFDPort
name|class
name|QOpenWFDPort
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenWFDScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QOpenWFDScreen
argument_list|(
name|QOpenWFDPort
operator|*
name|port
argument_list|)
block|;
operator|~
name|QOpenWFDScreen
argument_list|()
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|;
name|QOpenWFDPort
operator|*
name|port
argument_list|()
specifier|const
block|;
name|void
name|swapBuffers
argument_list|()
block|;
name|void
name|bindFramebuffer
argument_list|()
block|;
name|void
name|pipelineBindSourceComplete
argument_list|()
block|;
name|private
operator|:
name|void
name|setStagedBackBuffer
argument_list|(
argument|int bufferIndex
argument_list|)
block|;
name|void
name|commitStagedOutputBuffer
argument_list|()
block|;
name|int
name|nextAvailableRenderBuffer
argument_list|()
specifier|const
block|;
name|QOpenWFDPort
operator|*
name|mPort
block|;
name|GLuint
name|mFbo
block|;
name|QVarLengthArray
operator|<
name|QOpenWFDOutputBuffer
operator|*
block|,
name|BUFFER_NUM
operator|>
name|mOutputBuffers
block|;
name|int
name|mCurrentRenderBufferIndex
block|;
name|int
name|mStagedBackBufferIndex
block|;
name|int
name|mCommitedBackBufferIndex
block|;
name|int
name|mBackBufferIndex
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
