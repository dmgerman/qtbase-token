begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSURFACEFORMAT_H
end_ifndef
begin_define
DECL|macro|QSURFACEFORMAT_H
define|#
directive|define
name|QSURFACEFORMAT_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QOpenGLContext
decl_stmt|;
DECL|variable|QSurfaceFormatPrivate
name|class
name|QSurfaceFormatPrivate
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QSurfaceFormat
decl_stmt|{ public:     enum FormatOption
block|{
name|StereoBuffers
operator|=
literal|0x0001
operator|,
name|DebugContext
operator|=
literal|0x0002
operator|,
name|DeprecatedFunctions
operator|=
literal|0x0004
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_FLAGS
argument_list|(
name|FormatOptions
argument_list|,
name|FormatOption
argument_list|)
expr|enum
name|SwapBehavior
block|{
name|DefaultSwapBehavior
block|,
name|SingleBuffer
block|,
name|DoubleBuffer
block|,
name|TripleBuffer
block|}
expr_stmt|;
end_expr_stmt
begin_enum
enum|enum
name|OpenGLContextProfile
block|{
name|NoProfile
block|,
name|CoreProfile
block|,
name|CompatibilityProfile
block|}
enum|;
end_enum
begin_expr_stmt
name|QSurfaceFormat
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
name|QSurfaceFormat
argument_list|(
argument|FormatOptions options
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QSurfaceFormat
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QSurfaceFormat
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSurfaceFormat
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|~
name|QSurfaceFormat
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDepthBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|depthBufferSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setStencilBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|stencilBufferSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setRedBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|redBufferSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setGreenBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|greenBufferSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setBlueBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|blueBufferSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setAlphaBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|alphaBufferSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setSamples
parameter_list|(
name|int
name|numSamples
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|samples
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setSwapBehavior
parameter_list|(
name|SwapBehavior
name|behavior
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|SwapBehavior
name|swapBehavior
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|hasAlpha
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setProfile
parameter_list|(
name|OpenGLContextProfile
name|profile
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|OpenGLContextProfile
name|profile
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setMajorVersion
parameter_list|(
name|int
name|majorVersion
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|majorVersion
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setMinorVersion
parameter_list|(
name|int
name|minorVersion
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|minorVersion
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|stereo
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setStereo
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
name|opt
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
name|opt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QSurfaceFormatPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|detach
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|friend
name|Q_GUI_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSurfaceFormat
operator|&
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
name|Q_GUI_EXPORT
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSurfaceFormat
operator|&
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|friend
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
name|Q_GUI_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSurfaceFormat
operator|&
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSurfaceFormat
operator|&
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QSurfaceFormat::FormatOptions
argument_list|)
end_macro
begin_expr_stmt
DECL|function|stereo
specifier|inline
name|bool
name|QSurfaceFormat
operator|::
name|stereo
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|StereoBuffers
argument_list|)
return|;
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
comment|//QSURFACEFORMAT_H
end_comment
end_unit
