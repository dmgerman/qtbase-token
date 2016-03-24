begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Debug.h: Defines debug state used for GL_KHR_debug
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_DEBUG_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_DEBUG_H_
define|#
directive|define
name|LIBANGLE_DEBUG_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|<deque>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|LabeledObject
block|{
name|public
label|:
name|virtual
operator|~
name|LabeledObject
argument_list|()
block|{}
name|virtual
name|void
name|setLabel
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|label
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|std
operator|::
name|string
operator|&
name|getLabel
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|class
name|Debug
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|Debug
argument_list|()
block|;
name|void
name|setMaxLoggedMessages
argument_list|(
argument|GLuint maxLoggedMessages
argument_list|)
block|;
name|void
name|setOutputEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isOutputEnabled
argument_list|()
specifier|const
block|;
name|void
name|setOutputSynchronous
argument_list|(
argument|bool synchronous
argument_list|)
block|;
name|bool
name|isOutputSynchronous
argument_list|()
specifier|const
block|;
name|void
name|setCallback
argument_list|(
argument|GLDEBUGPROCKHR callback
argument_list|,
argument|const void *userParam
argument_list|)
block|;
name|GLDEBUGPROCKHR
name|getCallback
argument_list|()
specifier|const
block|;
specifier|const
name|void
operator|*
name|getUserParam
argument_list|()
specifier|const
block|;
name|void
name|insertMessage
argument_list|(
argument|GLenum source
argument_list|,
argument|GLenum type
argument_list|,
argument|GLuint id
argument_list|,
argument|GLenum severity
argument_list|,
argument|const std::string&message
argument_list|)
block|;
name|void
name|insertMessage
argument_list|(
argument|GLenum source
argument_list|,
argument|GLenum type
argument_list|,
argument|GLuint id
argument_list|,
argument|GLenum severity
argument_list|,
argument|std::string&&message
argument_list|)
block|;
name|void
name|setMessageControl
argument_list|(
argument|GLenum source
argument_list|,
argument|GLenum type
argument_list|,
argument|GLenum severity
argument_list|,
argument|std::vector<GLuint>&&ids
argument_list|,
argument|bool enabled
argument_list|)
block|;
name|size_t
name|getMessages
argument_list|(
argument|GLuint count
argument_list|,
argument|GLsizei bufSize
argument_list|,
argument|GLenum *sources
argument_list|,
argument|GLenum *types
argument_list|,
argument|GLuint *ids
argument_list|,
argument|GLenum *severities
argument_list|,
argument|GLsizei *lengths
argument_list|,
argument|GLchar *messageLog
argument_list|)
block|;
name|size_t
name|getNextMessageLength
argument_list|()
specifier|const
block|;
name|size_t
name|getMessageCount
argument_list|()
specifier|const
block|;
name|void
name|pushGroup
argument_list|(
argument|GLenum source
argument_list|,
argument|GLuint id
argument_list|,
argument|std::string&&message
argument_list|)
block|;
name|void
name|popGroup
argument_list|()
block|;
name|size_t
name|getGroupStackDepth
argument_list|()
specifier|const
block|;
name|private
operator|:
name|bool
name|isMessageEnabled
argument_list|(
argument|GLenum source
argument_list|,
argument|GLenum type
argument_list|,
argument|GLuint id
argument_list|,
argument|GLenum severity
argument_list|)
specifier|const
block|;
name|void
name|pushDefaultGroup
argument_list|()
block|;      struct
name|Message
block|{
name|GLenum
name|source
block|;
name|GLenum
name|type
block|;
name|GLuint
name|id
block|;
name|GLenum
name|severity
block|;
name|std
operator|::
name|string
name|message
block|;     }
block|;      struct
name|Control
block|{
name|GLenum
name|source
block|;
name|GLenum
name|type
block|;
name|GLenum
name|severity
block|;
name|std
operator|::
name|vector
operator|<
name|GLuint
operator|>
name|ids
block|;
name|bool
name|enabled
block|;     }
block|;      struct
name|Group
block|{
name|GLenum
name|source
block|;
name|GLuint
name|id
block|;
name|std
operator|::
name|string
name|message
block|;
name|std
operator|::
name|vector
operator|<
name|Control
operator|>
name|controls
block|;     }
block|;
name|bool
name|mOutputEnabled
block|;
name|GLDEBUGPROCKHR
name|mCallbackFunction
block|;
specifier|const
name|void
operator|*
name|mCallbackUserParam
block|;
name|std
operator|::
name|deque
operator|<
name|Message
operator|>
name|mMessages
block|;
name|GLuint
name|mMaxLoggedMessages
block|;
name|bool
name|mOutputSynchronous
block|;
name|std
operator|::
name|vector
operator|<
name|Group
operator|>
name|mGroups
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace gl
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_DEBUG_H_
end_comment
end_unit
