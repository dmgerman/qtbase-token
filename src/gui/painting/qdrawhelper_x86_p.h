begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDRAWHELPER_X86_P_H
end_ifndef
begin_define
DECL|macro|QDRAWHELPER_X86_P_H
define|#
directive|define
name|QDRAWHELPER_X86_P_H
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
file|<private/qdrawhelper_p.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_COMPILER_SUPPORTS_SSE2
name|void
name|qt_memfill32_sse2
parameter_list|(
name|quint32
modifier|*
name|dest
parameter_list|,
name|quint32
name|value
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_memfill16_sse2
parameter_list|(
name|quint16
modifier|*
name|dest
parameter_list|,
name|quint16
name|value
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_bitmapblit32_sse2
parameter_list|(
name|QRasterBuffer
modifier|*
name|rasterBuffer
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|quint32
name|color
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|stride
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_bitmapblit16_sse2
parameter_list|(
name|QRasterBuffer
modifier|*
name|rasterBuffer
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|quint32
name|color
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|stride
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_blend_argb32_on_argb32_sse2
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_blend_rgb32_on_rgb32_sse2
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|extern
name|CompositionFunction
name|qt_functionForMode_SSE2
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|CompositionFunctionSolid
name|qt_functionForModeSolid_SSE2
index|[]
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_COMPILER_SUPPORTS_SSE2
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_COMPILER_SUPPORTS_AVX
end_ifdef
begin_function_decl
name|void
name|qt_memfill32_avx
parameter_list|(
name|quint32
modifier|*
name|dest
parameter_list|,
name|quint32
name|value
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_memfill16_avx
parameter_list|(
name|quint16
modifier|*
name|dest
parameter_list|,
name|quint16
name|value
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_bitmapblit32_avx
parameter_list|(
name|QRasterBuffer
modifier|*
name|rasterBuffer
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|quint32
name|color
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|stride
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_bitmapblit16_avx
parameter_list|(
name|QRasterBuffer
modifier|*
name|rasterBuffer
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|quint32
name|color
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|stride
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_blend_argb32_on_argb32_avx
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_blend_rgb32_on_rgb32_avx
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_COMPILER_SUPPORTS_AVX
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_COMPILER_SUPPORTS_IWMMXT
end_ifdef
begin_function_decl
name|void
name|qt_blend_color_argb_iwmmxt
parameter_list|(
name|int
name|count
parameter_list|,
specifier|const
name|QSpan
modifier|*
name|spans
parameter_list|,
name|void
modifier|*
name|userData
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|extern
name|CompositionFunction
name|qt_functionForMode_IWMMXT
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|CompositionFunctionSolid
name|qt_functionForModeSolid_IWMMXT
index|[]
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|numCompositionFunctions
specifier|static
specifier|const
name|int
name|numCompositionFunctions
init|=
literal|33
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDRAWHELPER_X86_P_H
end_comment
end_unit
