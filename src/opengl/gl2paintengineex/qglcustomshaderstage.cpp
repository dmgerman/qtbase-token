begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglcustomshaderstage_p.h"
end_include
begin_include
include|#
directive|include
file|"qglengineshadermanager_p.h"
end_include
begin_include
include|#
directive|include
file|"qpaintengineex_opengl2_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qpainter_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QGLCustomShaderStagePrivate
class|class
name|QGLCustomShaderStagePrivate
block|{
public|public:
DECL|function|QGLCustomShaderStagePrivate
name|QGLCustomShaderStagePrivate
parameter_list|()
member_init_list|:
name|m_manager
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|m_manager
name|QPointer
argument_list|<
name|QGLEngineShaderManager
argument_list|>
name|m_manager
decl_stmt|;
DECL|member|m_source
name|QByteArray
name|m_source
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QGLCustomShaderStage
name|QGLCustomShaderStage
operator|::
name|QGLCustomShaderStage
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QGLCustomShaderStagePrivate
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QGLCustomShaderStage
name|QGLCustomShaderStage
operator|::
name|~
name|QGLCustomShaderStage
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLCustomShaderStage
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_manager
condition|)
block|{
name|d
operator|->
name|m_manager
operator|->
name|removeCustomStage
argument_list|()
expr_stmt|;
name|d
operator|->
name|m_manager
operator|->
name|sharedShaders
operator|->
name|cleanupCustomStage
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|setUniformsDirty
name|void
name|QGLCustomShaderStage
operator|::
name|setUniformsDirty
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLCustomShaderStage
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_manager
condition|)
name|d
operator|->
name|m_manager
operator|->
name|setDirty
argument_list|()
expr_stmt|;
comment|// ### Probably a bit overkill!
block|}
end_function
begin_function
DECL|function|setOnPainter
name|bool
name|QGLCustomShaderStage
operator|::
name|setOnPainter
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLCustomShaderStage
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|paintEngine
argument_list|()
operator|->
name|type
argument_list|()
operator|!=
name|QPaintEngine
operator|::
name|OpenGL2
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLCustomShaderStage::setOnPainter() - paint engine not OpenGL2"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|d
operator|->
name|m_manager
condition|)
name|qWarning
argument_list|(
literal|"Custom shader is already set on a painter"
argument_list|)
expr_stmt|;
name|QGL2PaintEngineEx
modifier|*
name|engine
init|=
cast|static_cast
argument_list|<
name|QGL2PaintEngineEx
operator|*
argument_list|>
argument_list|(
name|p
operator|->
name|paintEngine
argument_list|()
argument_list|)
decl_stmt|;
name|d
operator|->
name|m_manager
operator|=
name|QGL2PaintEngineExPrivate
operator|::
name|shaderManagerForEngine
argument_list|(
name|engine
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|m_manager
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_manager
operator|->
name|setCustomStage
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|removeFromPainter
name|void
name|QGLCustomShaderStage
operator|::
name|removeFromPainter
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLCustomShaderStage
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|paintEngine
argument_list|()
operator|->
name|type
argument_list|()
operator|!=
name|QPaintEngine
operator|::
name|OpenGL2
condition|)
return|return;
name|QGL2PaintEngineEx
modifier|*
name|engine
init|=
cast|static_cast
argument_list|<
name|QGL2PaintEngineEx
operator|*
argument_list|>
argument_list|(
name|p
operator|->
name|paintEngine
argument_list|()
argument_list|)
decl_stmt|;
name|d
operator|->
name|m_manager
operator|=
name|QGL2PaintEngineExPrivate
operator|::
name|shaderManagerForEngine
argument_list|(
name|engine
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|m_manager
argument_list|)
expr_stmt|;
comment|// Just set the stage to null, don't call removeCustomStage().
comment|// This should leave the program in a compiled/linked state
comment|// if the next custom shader stage is this one again.
name|d
operator|->
name|m_manager
operator|->
name|setCustomStage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_manager
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|source
name|QByteArray
name|QGLCustomShaderStage
operator|::
name|source
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLCustomShaderStage
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|m_source
return|;
block|}
end_function
begin_comment
comment|// Called by the shader manager if another custom shader is attached or
end_comment
begin_comment
comment|// the manager is deleted
end_comment
begin_function
DECL|function|setInactive
name|void
name|QGLCustomShaderStage
operator|::
name|setInactive
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLCustomShaderStage
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_manager
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSource
name|void
name|QGLCustomShaderStage
operator|::
name|setSource
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|s
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLCustomShaderStage
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_source
operator|=
name|s
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
