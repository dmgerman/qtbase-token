begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// ProgramImpl.h: Defines the abstract rx::ProgramImpl class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_PROGRAMIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_PROGRAMIMPL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_PROGRAMIMPL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/BinaryStream.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Constants.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Program.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Shader.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
struct|struct
name|LinkResult
block|{
name|LinkResult
argument_list|(
argument|bool linkSuccess
argument_list|,
argument|const gl::Error&error
argument_list|)
block|:
name|linkSuccess
argument_list|(
name|linkSuccess
argument_list|)
operator|,
name|error
argument_list|(
argument|error
argument_list|)
block|{}
name|bool
name|linkSuccess
expr_stmt|;
name|gl
operator|::
name|Error
name|error
expr_stmt|;
block|}
struct|;
name|class
name|ProgramImpl
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|ProgramImpl
argument_list|(
specifier|const
name|gl
operator|::
name|Program
operator|::
name|Data
operator|&
name|data
argument_list|)
operator|:
name|mData
argument_list|(
argument|data
argument_list|)
block|{}
name|virtual
operator|~
name|ProgramImpl
argument_list|()
block|{}
name|virtual
name|LinkResult
name|load
argument_list|(
name|gl
operator|::
name|InfoLog
operator|&
name|infoLog
argument_list|,
name|gl
operator|::
name|BinaryInputStream
operator|*
name|stream
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|save
argument_list|(
name|gl
operator|::
name|BinaryOutputStream
operator|*
name|stream
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setBinaryRetrievableHint
argument_list|(
argument|bool retrievable
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|LinkResult
name|link
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|,
name|gl
operator|::
name|InfoLog
operator|&
name|infoLog
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|GLboolean
name|validate
argument_list|(
specifier|const
name|gl
operator|::
name|Caps
operator|&
name|caps
argument_list|,
name|gl
operator|::
name|InfoLog
operator|*
name|infoLog
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform1fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform1iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform2iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform3iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform4iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform1uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform2uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform3uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniform4uiv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLuint *v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix2x3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix3x2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix2x4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix4x2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix3x4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setUniformMatrix4x3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat *value
argument_list|)
operator|=
literal|0
block|;
comment|// TODO: synchronize in syncState when dirty bits exist.
name|virtual
name|void
name|setUniformBlockBinding
argument_list|(
argument|GLuint uniformBlockIndex
argument_list|,
argument|GLuint uniformBlockBinding
argument_list|)
operator|=
literal|0
block|;
comment|// May only be called after a successful link operation.
comment|// Return false for inactive blocks.
name|virtual
name|bool
name|getUniformBlockSize
argument_list|(
argument|const std::string&blockName
argument_list|,
argument|size_t *sizeOut
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// May only be called after a successful link operation.
comment|// Returns false for inactive members.
name|virtual
name|bool
name|getUniformBlockMemberInfo
argument_list|(
argument|const std::string&memberUniformName
argument_list|,
argument|sh::BlockMemberInfo *memberInfoOut
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|protected
operator|:
specifier|const
name|gl
operator|::
name|Program
operator|::
name|Data
operator|&
name|mData
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_PROGRAMIMPL_H_
end_comment
end_unit
