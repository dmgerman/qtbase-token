begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qdrawhelper_x86_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_HAVE_3DNOW
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_HAVE_SSE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qdrawhelper_sse_p.h>
end_include
begin_include
include|#
directive|include
file|<mm3dnow.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QSSE3DNOWIntrinsics
struct|struct
name|QSSE3DNOWIntrinsics
super|:
specifier|public
name|QSSEIntrinsics
block|{
DECL|function|end
specifier|static
specifier|inline
name|void
name|end
parameter_list|()
block|{
name|_m_femms
argument_list|()
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|qt_functionForModeSolid_SSE3DNOW
name|CompositionFunctionSolid
name|qt_functionForModeSolid_SSE3DNOW
index|[
name|numCompositionFunctions
index|]
init|=
block|{
name|comp_func_solid_SourceOver
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_DestinationOver
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_Clear
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_Source
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
literal|0
block|,
name|comp_func_solid_SourceIn
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_DestinationIn
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_SourceOut
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_DestinationOut
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_SourceAtop
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_DestinationAtop
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_solid_XOR
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|// svg 1.2 modes
name|rasterop_solid_SourceOrDestination
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|rasterop_solid_SourceAndDestination
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|rasterop_solid_SourceXorDestination
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSourceAndNotDestination
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSourceOrNotDestination
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSourceXorDestination
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSource
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|rasterop_solid_NotSourceAndDestination
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|rasterop_solid_SourceAndNotDestination
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_functionForMode_SSE3DNOW
name|CompositionFunction
name|qt_functionForMode_SSE3DNOW
index|[
name|numCompositionFunctions
index|]
init|=
block|{
name|comp_func_SourceOver
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_DestinationOver
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_Clear
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_Source
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_Destination
block|,
name|comp_func_SourceIn
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_DestinationIn
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_SourceOut
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_DestinationOut
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_SourceAtop
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_DestinationAtop
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_XOR
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
block|,
name|comp_func_Plus
block|,
name|comp_func_Multiply
block|,
name|comp_func_Screen
block|,
name|comp_func_Overlay
block|,
name|comp_func_Darken
block|,
name|comp_func_Lighten
block|,
name|comp_func_ColorDodge
block|,
name|comp_func_ColorBurn
block|,
name|comp_func_HardLight
block|,
name|comp_func_SoftLight
block|,
name|comp_func_Difference
block|,
name|comp_func_Exclusion
block|,
name|rasterop_SourceOrDestination
block|,
name|rasterop_SourceAndDestination
block|,
name|rasterop_SourceXorDestination
block|,
name|rasterop_NotSourceAndNotDestination
block|,
name|rasterop_NotSourceOrNotDestination
block|,
name|rasterop_NotSourceXorDestination
block|,
name|rasterop_NotSource
block|,
name|rasterop_NotSourceAndDestination
block|,
name|rasterop_SourceAndNotDestination
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_blend_color_argb_sse3dnow
name|void
name|qt_blend_color_argb_sse3dnow
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
block|{
name|qt_blend_color_argb_x86
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
argument_list|(
name|count
argument_list|,
name|spans
argument_list|,
name|userData
argument_list|,
operator|(
name|CompositionFunctionSolid
operator|*
operator|)
name|qt_functionForModeSolid_SSE3DNOW
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_memfill32_sse3dnow
name|void
name|qt_memfill32_sse3dnow
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
block|{
return|return
name|qt_memfill32_sse_template
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
argument_list|(
name|dest
argument_list|,
name|value
argument_list|,
name|count
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_bitmapblit16_sse3dnow
name|void
name|qt_bitmapblit16_sse3dnow
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
block|{
return|return
name|qt_bitmapblit16_sse_template
argument_list|<
name|QSSE3DNOWIntrinsics
argument_list|>
argument_list|(
name|rasterBuffer
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|color
argument_list|,
name|src
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|stride
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_HAVE_3DNOW&& QT_HAVE_SSE
end_comment
end_unit
