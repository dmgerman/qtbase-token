begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 MIPS Technologies, www.mips.com, author Damir Tatalovic<dtatalovic@mips.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDRAWHELPER_MIPS_DSP_P_H
end_ifndef
begin_define
DECL|macro|QDRAWHELPER_MIPS_DSP_P_H
define|#
directive|define
name|QDRAWHELPER_MIPS_DSP_P_H
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
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_MIPS_DSP
argument_list|)
specifier|extern
literal|"C"
name|void
name|qt_memfill32_asm_mips_dsp
argument_list|(
argument|quint32 *dest
argument_list|,
argument|quint32 value
argument_list|,
argument|int count
argument_list|)
expr_stmt|;
end_expr_stmt
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_SourceOver_asm_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_solid_DestinationOver_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_solid_Source_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_DestinationOver_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_solid_SourceIn_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_SourceIn_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_solid_DestinationIn_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|a
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_DestinationIn_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_DestinationOut_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_solid_SourceAtop_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_SourceAtop_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_solid_DestinationAtop_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_DestinationAtop_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_solid_XOR_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_XOR_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_solid_SourceOut_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_SourceOut_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|comp_func_Source_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|qt_blend_argb32_on_argb32_mips_dsp_asm_x2
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|void
name|qt_blend_argb32_on_argb32_const_alpha_256_mips_dsp_asm
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|uint
modifier|*
name|destfetchARGB32_asm_mips_dsp
parameter_list|(
name|uint
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_extern
begin_extern
extern|extern
literal|"C"
name|uint
modifier|*
name|qt_destStoreARGB32_asm_mips_dsp
parameter_list|(
name|uint
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_extern
begin_function_decl
name|void
name|qt_blend_argb32_on_argb32_mips_dsp
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
name|qt_blend_rgb32_on_rgb32_mips_dsp
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
name|comp_func_Source_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|uint
modifier|*
name|QT_FASTCALL
name|qt_destFetchARGB32_mips_dsp
parameter_list|(
name|uint
modifier|*
name|buffer
parameter_list|,
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
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|qt_destStoreARGB32_mips_dsp
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
specifier|const
name|uint
modifier|*
name|buffer
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_Source_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_SourceOver_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_DestinationOver_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_SourceOver_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_DestinationOver_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_DestinationOver_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_SourceIn_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_SourceIn_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_DestinationIn_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_DestinationIn_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_DestinationOut_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_DestinationOut_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_SourceAtop_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_SourceAtop_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_DestinationAtop_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_DestinationAtop_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_XOR_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_solid_SourceOut_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|color
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_SourceOut_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QT_FASTCALL
name|comp_func_XOR_mips_dsp
parameter_list|(
name|uint
modifier|*
name|dest
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|,
name|uint
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_COMPILER_SUPPORTS_MIPS_DSP
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_COMPILER_SUPPORTS_MIPS_DSPR2
end_ifdef
begin_extern
extern|extern
literal|"C"
name|void
name|qConvertRgb16To32_asm_mips_dspr2
parameter_list|(
name|quint32
modifier|*
name|dest
parameter_list|,
specifier|const
name|quint16
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_COMPILER_SUPPORTS_MIPS_DSPR2
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDRAWHELPER_MIPS_DSP_P_H
end_comment
end_unit
