begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGL_CUSTOM_SHADER_STAGE_H
end_ifndef
begin_define
DECL|macro|QOPENGL_CUSTOM_SHADER_STAGE_H
define|#
directive|define
name|QOPENGL_CUSTOM_SHADER_STAGE_H
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
file|<QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QtGlobal>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLCustomShaderStagePrivate
name|class
name|QOpenGLCustomShaderStagePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLCustomShaderStage
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLCustomShaderStage
argument_list|)
name|public
label|:
name|QOpenGLCustomShaderStage
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QOpenGLCustomShaderStage
argument_list|()
expr_stmt|;
name|virtual
name|void
name|setUniforms
parameter_list|(
name|QOpenGLShaderProgram
modifier|*
parameter_list|)
block|{}
name|void
name|setUniformsDirty
parameter_list|()
function_decl|;
name|bool
name|setOnPainter
parameter_list|(
name|QPainter
modifier|*
parameter_list|)
function_decl|;
name|void
name|removeFromPainter
parameter_list|(
name|QPainter
modifier|*
parameter_list|)
function_decl|;
name|QByteArray
name|source
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInactive
parameter_list|()
function_decl|;
name|protected
label|:
name|void
name|setSource
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
name|private
label|:
name|QOpenGLCustomShaderStagePrivate
modifier|*
name|d_ptr
decl_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLCustomShaderStage
argument_list|)
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
end_unit
