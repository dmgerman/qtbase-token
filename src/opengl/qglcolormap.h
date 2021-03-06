begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|<QtOpenGL/qtopenglglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_OPENGL_EXPORT
name|QGLColormap
block|{
name|public
label|:
name|QGLColormap
argument_list|()
expr_stmt|;
name|QGLColormap
argument_list|(
specifier|const
name|QGLColormap
operator|&
argument_list|)
expr_stmt|;
operator|~
name|QGLColormap
argument_list|()
expr_stmt|;
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
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
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
name|QRgb
name|entryRgb
argument_list|(
name|int
name|idx
argument_list|)
decl|const
decl_stmt|;
name|QColor
name|entryColor
argument_list|(
name|int
name|idx
argument_list|)
decl|const
decl_stmt|;
name|int
name|find
argument_list|(
name|QRgb
name|color
argument_list|)
decl|const
decl_stmt|;
name|int
name|findNearest
argument_list|(
name|QRgb
name|color
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
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
name|Q_NULLPTR
return|;
block|}
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
name|private
label|:
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
name|QGLColormapData
modifier|*
name|d
decl_stmt|;
specifier|static
name|struct
name|QGLColormapData
name|shared_null
decl_stmt|;
specifier|static
name|void
name|cleanup
parameter_list|(
name|QGLColormapData
modifier|*
name|x
parameter_list|)
function_decl|;
name|void
name|detach_helper
parameter_list|()
function_decl|;
name|friend
name|class
name|QGLWidget
decl_stmt|;
name|friend
name|class
name|QGLWidgetPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLCOLORMAP_H
end_comment
end_unit
