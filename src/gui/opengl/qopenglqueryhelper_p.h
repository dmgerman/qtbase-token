begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB). ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLQUERYHELPER_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLQUERYHELPER_P_H
define|#
directive|define
name|QOPENGLQUERYHELPER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// Helper class used by QOpenGLTimerQuery and later will be used by
comment|// QOpenGLOcclusionQuery
name|class
name|QOpenGLQueryHelper
block|{
name|public
label|:
name|QOpenGLQueryHelper
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
operator|:
name|GetQueryObjectuiv
argument_list|(
literal|0
argument_list|)
operator|,
name|GetQueryObjectiv
argument_list|(
literal|0
argument_list|)
operator|,
name|GetQueryiv
argument_list|(
literal|0
argument_list|)
operator|,
name|EndQuery
argument_list|(
literal|0
argument_list|)
operator|,
name|BeginQuery
argument_list|(
literal|0
argument_list|)
operator|,
name|IsQuery
argument_list|(
literal|0
argument_list|)
operator|,
name|DeleteQueries
argument_list|(
literal|0
argument_list|)
operator|,
name|GenQueries
argument_list|(
literal|0
argument_list|)
operator|,
name|GetInteger64v
argument_list|(
literal|0
argument_list|)
operator|,
name|GetQueryObjectui64v
argument_list|(
literal|0
argument_list|)
operator|,
name|GetQueryObjecti64v
argument_list|(
literal|0
argument_list|)
operator|,
name|QueryCounter
argument_list|(
literal|0
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
block|;
comment|// Core in OpenGL>=1.5
name|GetQueryObjectuiv
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLuint
argument_list|,
name|GLenum
argument_list|,
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glGetQueryObjectuiv"
argument_list|)
operator|)
block|;
name|GetQueryObjectiv
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLuint
argument_list|,
name|GLenum
argument_list|,
name|GLint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glGetQueryObjectiv"
argument_list|)
operator|)
block|;
name|GetQueryiv
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLenum
argument_list|,
name|GLenum
argument_list|,
name|GLint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glGetQueryiv"
argument_list|)
operator|)
block|;
name|EndQuery
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLenum
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glEndQuery"
argument_list|)
operator|)
block|;
name|BeginQuery
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLenum
argument_list|,
name|GLuint
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glBeginQuery"
argument_list|)
operator|)
block|;
name|IsQuery
operator|=
name|reinterpret_cast
operator|<
name|GLboolean
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLuint
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glIsQuery"
argument_list|)
operator|)
block|;
name|DeleteQueries
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLsizei
argument_list|,
specifier|const
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glDeleteQueries"
argument_list|)
operator|)
block|;
name|GenQueries
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLsizei
argument_list|,
name|GLuint
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glGenQueries"
argument_list|)
operator|)
block|;
comment|// Core in OpenGL>=3.2
name|GetInteger64v
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLenum
argument_list|,
name|GLint64
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glGetInteger64v"
argument_list|)
operator|)
block|;
comment|// Core in OpenGL>=3.3 / ARB_timer_query
name|GetQueryObjectui64v
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLuint
argument_list|,
name|GLenum
argument_list|,
name|GLuint64
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glGetQueryObjectui64v"
argument_list|)
operator|)
block|;
name|GetQueryObjecti64v
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLuint
argument_list|,
name|GLenum
argument_list|,
name|GLint64
operator|*
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glGetQueryObjecti64v"
argument_list|)
operator|)
block|;
name|QueryCounter
operator|=
name|reinterpret_cast
operator|<
name|void
argument_list|(
name|QOPENGLF_APIENTRYP
argument_list|)
argument_list|(
name|GLuint
argument_list|,
name|GLenum
argument_list|)
operator|>
operator|(
name|context
operator|->
name|getProcAddress
argument_list|(
literal|"glQueryCounter"
argument_list|)
operator|)
block|;     }
specifier|inline
name|void
name|glGetQueryObjectuiv
argument_list|(
argument|GLuint id
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLuint *params
argument_list|)
block|{
name|GetQueryObjectuiv
argument_list|(
name|id
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;     }
specifier|inline
name|void
name|glGetQueryObjectiv
argument_list|(
argument|GLuint id
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|{
name|GetQueryObjectiv
argument_list|(
name|id
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;     }
specifier|inline
name|void
name|glGetQueryiv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|{
name|GetQueryiv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|;     }
specifier|inline
name|void
name|glEndQuery
argument_list|(
argument|GLenum target
argument_list|)
block|{
name|EndQuery
argument_list|(
name|target
argument_list|)
block|;     }
specifier|inline
name|void
name|glBeginQuery
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint id
argument_list|)
block|{
name|BeginQuery
argument_list|(
name|target
argument_list|,
name|id
argument_list|)
block|;     }
specifier|inline
name|GLboolean
name|glIsQuery
argument_list|(
argument|GLuint id
argument_list|)
block|{
return|return
name|IsQuery
argument_list|(
name|id
argument_list|)
return|;
block|}
specifier|inline
name|void
name|glDeleteQueries
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|ids
parameter_list|)
block|{
name|DeleteQueries
argument_list|(
name|n
argument_list|,
name|ids
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|glGenQueries
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|ids
parameter_list|)
block|{
name|GenQueries
argument_list|(
name|n
argument_list|,
name|ids
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|glGetInteger64v
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint64
modifier|*
name|params
parameter_list|)
block|{
name|GetInteger64v
argument_list|(
name|pname
argument_list|,
name|params
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|glGetQueryObjectui64v
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLuint64
modifier|*
name|params
parameter_list|)
block|{
name|GetQueryObjectui64v
argument_list|(
name|id
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|glGetQueryObjecti64v
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint64
modifier|*
name|params
parameter_list|)
block|{
name|GetQueryObjecti64v
argument_list|(
name|id
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|glQueryCounter
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|target
parameter_list|)
block|{
name|QueryCounter
argument_list|(
name|id
argument_list|,
name|target
argument_list|)
expr_stmt|;
block|}
name|private
label|:
comment|// Core in OpenGL>=1.5
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GetQueryObjectuiv
function_decl|)
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLuint
modifier|*
name|params
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GetQueryObjectiv
function_decl|)
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GetQueryiv
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|EndQuery
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|BeginQuery
function_decl|)
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLuint
name|id
parameter_list|)
function_decl|;
name|GLboolean
function_decl|(
name|QOPENGLF_APIENTRYP
name|IsQuery
function_decl|)
parameter_list|(
name|GLuint
name|id
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|DeleteQueries
function_decl|)
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|ids
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GenQueries
function_decl|)
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|ids
parameter_list|)
function_decl|;
comment|// Core in OpenGL>=3.2
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GetInteger64v
function_decl|)
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint64
modifier|*
name|params
parameter_list|)
function_decl|;
comment|// Core in OpenGL>=3.3 and provided by ARB_timer_query
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GetQueryObjectui64v
function_decl|)
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLuint64
modifier|*
name|params
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|GetQueryObjecti64v
function_decl|)
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint64
modifier|*
name|params
parameter_list|)
function_decl|;
name|void
function_decl|(
name|QOPENGLF_APIENTRYP
name|QueryCounter
function_decl|)
parameter_list|(
name|GLuint
name|id
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGLQUERYHELPER_P_H
end_comment
end_unit
