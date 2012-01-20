begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLSHADERCACHE_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLSHADERCACHE_P_H
define|#
directive|define
name|QOPENGLSHADERCACHE_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_MEEGO_EXPERIMENTAL_SHADERCACHE
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qopenglshadercache_meego_p.h"
end_include
begin_else
else|#
directive|else
end_else
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QOpenGLShaderProgram
decl_stmt|;
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
name|class
name|CachedShader
decl_stmt|{ public:
specifier|inline
namespace|CachedShader(const
name|QByteArray
namespace|&
operator|,
namespace|const
name|QByteArray
namespace|&
end_function
begin_block
unit|)
block|{}
end_block
begin_function
specifier|inline
name|bool
name|isCached
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|load
parameter_list|(
name|QOpenGLShaderProgram
modifier|*
parameter_list|,
name|QOpenGLContext
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|store
parameter_list|(
name|QOpenGLShaderProgram
modifier|*
parameter_list|,
name|QOpenGLContext
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
