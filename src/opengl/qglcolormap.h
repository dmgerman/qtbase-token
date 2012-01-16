begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLCOLORMAP_H
end_ifndef
begin_define
DECL|macro|QGLCOLORMAP_H
define|#
directive|define
name|QGLCOLORMAP_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|OpenGL
parameter_list|)
name|class
name|Q_OPENGL_EXPORT
name|QGLColormap
decl_stmt|{ public:     QGLColormap(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QGLColormap
argument_list|(
specifier|const
name|QGLColormap
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QGLColormap
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QGLColormap
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QGLColormap
operator|&
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|detach
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setEntries
parameter_list|(
name|int
name|count
parameter_list|,
specifier|const
name|QRgb
modifier|*
name|colors
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setEntry
parameter_list|(
name|int
name|idx
parameter_list|,
name|QRgb
name|color
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setEntry
parameter_list|(
name|int
name|idx
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QRgb
name|entryRgb
argument_list|(
name|int
name|idx
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QColor
name|entryColor
argument_list|(
name|int
name|idx
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|find
argument_list|(
name|QRgb
name|color
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|findNearest
argument_list|(
name|QRgb
name|color
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
block|{
return|return
name|d
operator|?
name|d
operator|->
name|cmapHandle
operator|:
literal|0
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|void
name|setHandle
argument_list|(
name|Qt
operator|::
name|HANDLE
name|ahandle
argument_list|)
block|{
name|d
operator|->
name|cmapHandle
operator|=
name|ahandle
expr_stmt|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_struct
struct|struct
name|QGLColormapData
block|{
name|QBasicAtomicInt
name|ref
decl_stmt|;
name|QVector
operator|<
name|QRgb
operator|>
operator|*
name|cells
expr_stmt|;
name|Qt
operator|::
name|HANDLE
name|cmapHandle
expr_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|QGLColormapData
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|struct
name|QGLColormapData
name|shared_null
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|cleanup
parameter_list|(
name|QGLColormapData
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|detach_helper
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|friend
name|class
name|QGLWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QGLWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
DECL|function|detach
specifier|inline
name|void
name|QGLColormap
operator|::
name|detach
argument_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach_helper
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLCOLORMAP_H
end_comment
end_unit
