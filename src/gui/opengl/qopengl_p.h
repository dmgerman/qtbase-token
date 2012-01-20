begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGL_P_H
end_ifndef
begin_define
DECL|macro|QOPENGL_P_H
define|#
directive|define
name|QOPENGL_P_H
end_define
begin_include
include|#
directive|include
file|<qopengl.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<qthreadstorage.h>
end_include
begin_include
include|#
directive|include
file|<qcache.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QOpenGLExtensionMatcher
block|{
name|public
label|:
name|QOpenGLExtensionMatcher
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
expr_stmt|;
name|QOpenGLExtensionMatcher
argument_list|()
expr_stmt|;
name|bool
name|match
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
decl|const
block|{
name|int
name|str_length
init|=
name|qstrlen
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|str
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|str_length
operator|>
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|str
index|[
name|str_length
operator|-
literal|1
index|]
operator|!=
literal|' '
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_offsets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|extension
init|=
name|m_extensions
operator|.
name|constData
argument_list|()
operator|+
name|m_offsets
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|qstrncmp
argument_list|(
name|extension
argument_list|,
name|str
argument_list|,
name|str_length
argument_list|)
operator|==
literal|0
operator|&&
name|extension
index|[
name|str_length
index|]
operator|==
literal|' '
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|private
label|:
name|void
name|init
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|QByteArray
name|m_extensions
decl_stmt|;
name|QVector
operator|<
name|int
operator|>
name|m_offsets
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGL_H
end_comment
end_unit
