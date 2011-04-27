begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FRAGMENTPROGRAMS_P_H
end_ifndef
begin_define
DECL|macro|FRAGMENTPROGRAMS_P_H
define|#
directive|define
name|FRAGMENTPROGRAMS_P_H
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
begin_enum
DECL|enum|FragmentVariable
enum|enum
name|FragmentVariable
block|{
DECL|enumerator|VAR_BRUSH_TEXTURE
name|VAR_BRUSH_TEXTURE
block|,
DECL|enumerator|VAR_LINEAR
name|VAR_LINEAR
block|,
DECL|enumerator|VAR_INV_MATRIX_M1
name|VAR_INV_MATRIX_M1
block|,
DECL|enumerator|VAR_INV_MASK_SIZE
name|VAR_INV_MASK_SIZE
block|,
DECL|enumerator|VAR_INV_MATRIX_M2
name|VAR_INV_MATRIX_M2
block|,
DECL|enumerator|VAR_PORTERDUFF_AB
name|VAR_PORTERDUFF_AB
block|,
DECL|enumerator|VAR_MASK_CHANNEL
name|VAR_MASK_CHANNEL
block|,
DECL|enumerator|VAR_ELLIPSE_OFFSET
name|VAR_ELLIPSE_OFFSET
block|,
DECL|enumerator|VAR_PORTERDUFF_XYZ
name|VAR_PORTERDUFF_XYZ
block|,
DECL|enumerator|VAR_INV_DST_SIZE
name|VAR_INV_DST_SIZE
block|,
DECL|enumerator|VAR_MASK_TEXTURE
name|VAR_MASK_TEXTURE
block|,
DECL|enumerator|VAR_DST_TEXTURE
name|VAR_DST_TEXTURE
block|,
DECL|enumerator|VAR_PALETTE
name|VAR_PALETTE
block|,
DECL|enumerator|VAR_MASK_OFFSET
name|VAR_MASK_OFFSET
block|,
DECL|enumerator|VAR_INV_BRUSH_TEXTURE_SIZE
name|VAR_INV_BRUSH_TEXTURE_SIZE
block|,
DECL|enumerator|VAR_FMP2_M_RADIUS2
name|VAR_FMP2_M_RADIUS2
block|,
DECL|enumerator|VAR_FMP
name|VAR_FMP
block|,
DECL|enumerator|VAR_INV_MATRIX_M0
name|VAR_INV_MATRIX_M0
block|,
DECL|enumerator|VAR_ANGLE
name|VAR_ANGLE
block|}
enum|;
end_enum
begin_enum
DECL|enum|FragmentBrushType
enum|enum
name|FragmentBrushType
block|{
DECL|enumerator|FRAGMENT_PROGRAM_BRUSH_SOLID
name|FRAGMENT_PROGRAM_BRUSH_SOLID
block|,
DECL|enumerator|FRAGMENT_PROGRAM_BRUSH_RADIAL
name|FRAGMENT_PROGRAM_BRUSH_RADIAL
block|,
DECL|enumerator|FRAGMENT_PROGRAM_BRUSH_CONICAL
name|FRAGMENT_PROGRAM_BRUSH_CONICAL
block|,
DECL|enumerator|FRAGMENT_PROGRAM_BRUSH_LINEAR
name|FRAGMENT_PROGRAM_BRUSH_LINEAR
block|,
DECL|enumerator|FRAGMENT_PROGRAM_BRUSH_TEXTURE
name|FRAGMENT_PROGRAM_BRUSH_TEXTURE
block|,
DECL|enumerator|FRAGMENT_PROGRAM_BRUSH_PATTERN
name|FRAGMENT_PROGRAM_BRUSH_PATTERN
block|}
enum|;
end_enum
begin_enum
DECL|enum|FragmentCompositionModeType
enum|enum
name|FragmentCompositionModeType
block|{
DECL|enumerator|COMPOSITION_MODES_SIMPLE_PORTER_DUFF
name|COMPOSITION_MODES_SIMPLE_PORTER_DUFF
block|,
DECL|enumerator|COMPOSITION_MODES_MULTIPLY
name|COMPOSITION_MODES_MULTIPLY
block|,
DECL|enumerator|COMPOSITION_MODES_SCREEN
name|COMPOSITION_MODES_SCREEN
block|,
DECL|enumerator|COMPOSITION_MODES_OVERLAY
name|COMPOSITION_MODES_OVERLAY
block|,
DECL|enumerator|COMPOSITION_MODES_DARKEN
name|COMPOSITION_MODES_DARKEN
block|,
DECL|enumerator|COMPOSITION_MODES_LIGHTEN
name|COMPOSITION_MODES_LIGHTEN
block|,
DECL|enumerator|COMPOSITION_MODES_COLORDODGE
name|COMPOSITION_MODES_COLORDODGE
block|,
DECL|enumerator|COMPOSITION_MODES_COLORBURN
name|COMPOSITION_MODES_COLORBURN
block|,
DECL|enumerator|COMPOSITION_MODES_HARDLIGHT
name|COMPOSITION_MODES_HARDLIGHT
block|,
DECL|enumerator|COMPOSITION_MODES_SOFTLIGHT
name|COMPOSITION_MODES_SOFTLIGHT
block|,
DECL|enumerator|COMPOSITION_MODES_DIFFERENCE
name|COMPOSITION_MODES_DIFFERENCE
block|,
DECL|enumerator|COMPOSITION_MODES_EXCLUSION
name|COMPOSITION_MODES_EXCLUSION
block|,
DECL|enumerator|COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
name|COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_MULTIPLY_NOMASK
name|COMPOSITION_MODES_MULTIPLY_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_SCREEN_NOMASK
name|COMPOSITION_MODES_SCREEN_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_OVERLAY_NOMASK
name|COMPOSITION_MODES_OVERLAY_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_DARKEN_NOMASK
name|COMPOSITION_MODES_DARKEN_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_LIGHTEN_NOMASK
name|COMPOSITION_MODES_LIGHTEN_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_COLORDODGE_NOMASK
name|COMPOSITION_MODES_COLORDODGE_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_COLORBURN_NOMASK
name|COMPOSITION_MODES_COLORBURN_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_HARDLIGHT_NOMASK
name|COMPOSITION_MODES_HARDLIGHT_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_SOFTLIGHT_NOMASK
name|COMPOSITION_MODES_SOFTLIGHT_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_DIFFERENCE_NOMASK
name|COMPOSITION_MODES_DIFFERENCE_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODES_EXCLUSION_NOMASK
name|COMPOSITION_MODES_EXCLUSION_NOMASK
block|,
DECL|enumerator|COMPOSITION_MODE_BLEND_MODE_MASK
name|COMPOSITION_MODE_BLEND_MODE_MASK
block|,
DECL|enumerator|COMPOSITION_MODE_BLEND_MODE_NOMASK
name|COMPOSITION_MODE_BLEND_MODE_NOMASK
block|}
enum|;
end_enum
begin_enum
DECL|enum|FragmentMaskType
enum|enum
name|FragmentMaskType
block|{
DECL|enumerator|FRAGMENT_PROGRAM_MASK_TRAPEZOID_AA
name|FRAGMENT_PROGRAM_MASK_TRAPEZOID_AA
block|,
DECL|enumerator|FRAGMENT_PROGRAM_MASK_ELLIPSE_AA
name|FRAGMENT_PROGRAM_MASK_ELLIPSE_AA
block|}
enum|;
end_enum
begin_decl_stmt
DECL|variable|num_fragment_variables
specifier|static
specifier|const
name|unsigned
name|int
name|num_fragment_variables
init|=
literal|19
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|num_fragment_brushes
specifier|static
specifier|const
name|unsigned
name|int
name|num_fragment_brushes
init|=
literal|6
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|num_fragment_composition_modes
specifier|static
specifier|const
name|unsigned
name|int
name|num_fragment_composition_modes
init|=
literal|26
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|num_fragment_masks
specifier|static
specifier|const
name|unsigned
name|int
name|num_fragment_masks
init|=
literal|2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_MASK_TRAPEZOID_AA
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_MASK_TRAPEZOID_AA
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[1] = { { 0.5, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"ADD R3.z, fragment.position.x, c[0].x;\n"
literal|"ADD R0.y, fragment.position, -c[0].x;\n"
literal|"MAX R4.x, fragment.texcoord[0].y, R0.y;\n"
literal|"ADD R0.x, fragment.position.y, c[0];\n"
literal|"MIN R3.w, R0.x, fragment.texcoord[0].x;\n"
literal|"ADD R2.z, fragment.position.x, -c[0].x;\n"
literal|"MOV R2.w, R3.z;\n"
literal|"MOV R0.yw, R4.x;\n"
literal|"MOV R0.xz, R3.w;\n"
literal|"MAD R0, fragment.texcoord[1].xxzz, R0, fragment.texcoord[1].yyww;\n"
literal|"MAD R0.zw, fragment.position.x, c[0].y, -R0;\n"
literal|"MOV R2.x, R0;\n"
literal|"MOV R2.y, R0.z;\n"
literal|"MOV R1.w, R0;\n"
literal|"MOV R1.z, R0.y;\n"
literal|"MIN R1.xy, R2, R1.zwzw;\n"
literal|"SGE R0.xy, R1.zwzw, R2;\n"
literal|"ADD R0.zw, -fragment.texcoord[0], -fragment.texcoord[0];\n"
literal|"MAD R3.xy, R0, R0.zwzw, fragment.texcoord[0].zwzw;\n"
literal|"ADD R0, -R1.xxyy, R2.zwzw;\n"
literal|"MAD R0, R0, R3.xxyy, R4.x;\n"
literal|"ADD R3.xy, R0.ywzw, R0.xzzw;\n"
literal|"ADD R4.zw, R3.w, -R0.xyxz;\n"
literal|"ADD R0.zw, -R4.x, R0.xyyw;\n"
literal|"ADD R0.xy, R3.z, -R1;\n"
literal|"MAX R1.zw, R2.xyxy, R1;\n"
literal|"MUL R0.xy, R0, R0.zwzw;\n"
literal|"MAD R3.xy, -R3, c[0].x, R3.w;\n"
literal|"ADD R2.w, R3.z, -R2.z;\n"
literal|"MUL R2.xy, R3, R2.w;\n"
literal|"ADD R2.w, R3, -R4.x;\n"
literal|"ADD R3.xy, -R2.z, R1.zwzw;\n"
literal|"MUL R3.xy, R4.zwzw, R3;\n"
literal|"ADD R4.zw, R1.xyxy, R1;\n"
literal|"MAD R0.zw, R4, c[0].x, -R2.z;\n"
literal|"MAD R0.xy, -R0, c[0].x, R2.w;\n"
literal|"MAD R4.zw, R0, R2.w, -R0.xyxy;\n"
literal|"SGE R0.zw, R3.z, R1;\n"
literal|"MAD R0.xy, R0.zwzw, R4.zwzw, R0;\n"
literal|"MAD R3.xy, R3, c[0].x, -R2;\n"
literal|"MAD R0.zw, R0, R3.xyxy, R2.xyxy;\n"
literal|"ADD R2.xy, R0.zwzw, -R0;\n"
literal|"SGE R0.zw, R2.z, R1.xyxy;\n"
literal|"MAD R0.xy, R0.zwzw, R2, R0;\n"
literal|"SGE R0.zw, R1, R2.z;\n"
literal|"ADD R0.xy, R0, -R2.w;\n"
literal|"SGE R1.xy, R3.z, R1;\n"
literal|"MAD R0.xy, R1, R0, R2.w;\n"
literal|"MAD R0.x, -R0, R0.z, R2.w;\n"
literal|"SGE R0.z, R3.w, R4.x;\n"
literal|"MAD R0.x, -R0.y, R0.w, R0;\n"
literal|"MUL result.color, R0.x, R0.z;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_MASK_ELLIPSE_AA
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_MASK_ELLIPSE_AA
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..3],\n"
literal|"		{ -2, 1, -0.5, 2 },\n"
literal|"		{ 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"ADD R0.xy, fragment.position, c[3];\n"
literal|"MUL R1.xyz, R0.y, c[1];\n"
literal|"MAD R0.xyz, R0.x, c[0], R1;\n"
literal|"ADD R0.xyz, R0, c[2];\n"
literal|"RCP R2.z, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R2.z;\n"
literal|"MUL R2.xy, R0.zwzw, fragment.texcoord[0];\n"
literal|"MOV R1.xy, c[0];\n"
literal|"MOV R1.zw, c[1].xyxy;\n"
literal|"MOV R0.x, c[0].z;\n"
literal|"MOV R0.y, c[1].z;\n"
literal|"MAD R0, R0.zzww, -R0.xyxy, R1.xzyw;\n"
literal|"MUL R1.xy, R2, fragment.texcoord[0];\n"
literal|"MUL R0, R2.z, R0;\n"
literal|"MUL R1.xy, R1, c[4].x;\n"
literal|"MUL R1.zw, R1.xyxy, R0.xyxz;\n"
literal|"MUL R0.zw, R1.xyxy, R0.xyyw;\n"
literal|"ADD R0.y, R0.z, R0.w;\n"
literal|"ADD R0.x, R1.z, R1.w;\n"
literal|"MUL R0.xy, R0, R0;\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, R2.xyxy, R2.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"ADD R0.y, -R0.z, c[4];\n"
literal|"RSQ R0.x, R0.x;\n"
literal|"MAD_SAT R0.x, R0, R0.y, -c[4].z;\n"
literal|"MUL R0.y, -R0.x, c[4].w;\n"
literal|"ADD R0.y, R0, c[5].x;\n"
literal|"MUL R0.x, R0, R0;\n"
literal|"MUL result.color, R0.x, R0.y;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xy, fragment.position, c[3];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.xyz, R0, c[0].y;\n"
literal|"MUL R2.xyz, fragment.color.primary.w, R1;\n"
literal|"MUL R1.xyz, fragment.color.primary, c[0].x;\n"
literal|"MAD R2.xyz, R0.w, R1, R2;\n"
literal|"ADD R3.xy, fragment.position, c[4];\n"
literal|"ADD R1.w, -R0, c[6].x;\n"
literal|"MUL R1.xyz, fragment.color.primary, c[1].y;\n"
literal|"MAD R2.xyz, R1.w, R1, R2;\n"
literal|"MUL R1.xyz, R0, c[1].z;\n"
literal|"ADD R2.w, -fragment.color.primary, c[6].x;\n"
literal|"MAD R2.xyz, R2.w, R1, R2;\n"
literal|"MUL R1.z, R0.w, R2.w;\n"
literal|"MUL R1.x, fragment.color.primary.w, R0.w;\n"
literal|"MUL R1.y, fragment.color.primary.w, R1.w;\n"
literal|"DP3 R2.w, R1, c[1];\n"
literal|"MUL R3.xy, R3, c[2];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[5];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_MULTIPLY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_MULTIPLY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -R0.w, c[4];\n"
literal|"MUL R1.xyz, fragment.color.primary, R1.x;\n"
literal|"MAD R1.xyz, fragment.color.primary, R0, R1;\n"
literal|"ADD R1.w, -fragment.color.primary, c[4].x;\n"
literal|"MAD R2.xyz, R0, R1.w, R1;\n"
literal|"ADD R1.z, fragment.color.primary.w, R0.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SCREEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SCREEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[4] = { program.local[0..3] };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"ADD R2, fragment.color.primary, R0;\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"MAD R2, -fragment.color.primary, R0, R2;\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_OVERLAY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_OVERLAY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R1, R0, texture[0], 2D;\n"
literal|"ADD R0.w, -R1, c[4].y;\n"
literal|"MUL R3.xyz, fragment.color.primary, R0.w;\n"
literal|"ADD R2.xyz, fragment.color.primary.w, -fragment.color.primary;\n"
literal|"ADD R0.xyz, R1.w, -R1;\n"
literal|"MUL R0.xyz, R0, R2;\n"
literal|"MUL R0.xyz, R0, c[4].x;\n"
literal|"MAD R0.xyz, fragment.color.primary.w, R1.w, -R0;\n"
literal|"MAD R0.xyz, fragment.color.primary, R0.w, R0;\n"
literal|"MUL R2.xyz, fragment.color.primary, R1;\n"
literal|"MAD R2.xyz, R2, c[4].x, R3;\n"
literal|"ADD R0.w, -fragment.color.primary, c[4].y;\n"
literal|"MAD R3.xyz, R1, R0.w, R0;\n"
literal|"MAD R2.xyz, R1, R0.w, R2;\n"
literal|"MUL R0.xyz, R1, c[4].x;\n"
literal|"SGE R0.xyz, R0, R1.w;\n"
literal|"ADD R3.xyz, R3, -R2;\n"
literal|"MAD R2.xyz, R0, R3, R2;\n"
literal|"ADD R0.z, fragment.color.primary.w, R1.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[2];\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[3];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DARKEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DARKEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R2.xyz, fragment.color.primary.w, R0;\n"
literal|"MUL R1.xyz, fragment.color.primary, R0.w;\n"
literal|"MIN R1.xyz, R1, R2;\n"
literal|"ADD R1.w, -R0, c[4].x;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"ADD R1.w, -fragment.color.primary, c[4].x;\n"
literal|"MAD R2.xyz, R0, R1.w, R1;\n"
literal|"ADD R1.z, fragment.color.primary.w, R0.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_LIGHTEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_LIGHTEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R2.xyz, fragment.color.primary.w, R0;\n"
literal|"MUL R1.xyz, fragment.color.primary, R0.w;\n"
literal|"MAX R1.xyz, R1, R2;\n"
literal|"ADD R1.w, -R0, c[4].x;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"ADD R1.w, -fragment.color.primary, c[4].x;\n"
literal|"MAD R2.xyz, R0, R1.w, R1;\n"
literal|"ADD R1.z, fragment.color.primary.w, R0.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORDODGE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORDODGE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -fragment.color.primary.w, c[4];\n"
literal|"MAX R1.y, fragment.color.primary.w, c[4];\n"
literal|"MUL R2.xyz, R0, R1.x;\n"
literal|"ADD R1.w, -R0, c[4].x;\n"
literal|"MAD R3.xyz, fragment.color.primary, R1.w, R2;\n"
literal|"RCP R1.y, R1.y;\n"
literal|"MAD R1.xyz, -fragment.color.primary, R1.y, c[4].x;\n"
literal|"MAX R1.xyz, R1, c[4].y;\n"
literal|"MUL R2.xyz, fragment.color.primary.w, R0;\n"
literal|"MUL R1.w, fragment.color.primary, R0;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"RCP R1.y, R1.y;\n"
literal|"RCP R1.z, R1.z;\n"
literal|"MAD R1.xyz, R2, R1, R3;\n"
literal|"MAD R3.xyz, fragment.color.primary.w, R0.w, R3;\n"
literal|"MAD R2.xyz, fragment.color.primary, R0.w, R2;\n"
literal|"ADD R3.xyz, R3, -R1;\n"
literal|"SGE R2.xyz, R2, R1.w;\n"
literal|"MAD R2.xyz, R2, R3, R1;\n"
literal|"ADD R1.z, fragment.color.primary.w, R0.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORBURN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORBURN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.w, -R0, c[4].x;\n"
literal|"MUL R1.xyz, fragment.color.primary.w, R0;\n"
literal|"MAD R2.xyz, fragment.color.primary, R0.w, R1;\n"
literal|"MAD R1.xyz, -fragment.color.primary.w, R0.w, R2;\n"
literal|"MUL R3.xyz, fragment.color.primary.w, R1;\n"
literal|"MAX R1.xyz, fragment.color.primary, c[4].y;\n"
literal|"ADD R2.w, -fragment.color.primary, c[4].x;\n"
literal|"MUL R4.xyz, fragment.color.primary, R1.w;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"RCP R1.y, R1.y;\n"
literal|"RCP R1.z, R1.z;\n"
literal|"MAD R3.xyz, R3, R1, R4;\n"
literal|"MUL R1.xyz, R0, R2.w;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"MAD R3.xyz, R0, R2.w, R3;\n"
literal|"MUL R1.w, fragment.color.primary, R0;\n"
literal|"ADD R3.xyz, R3, -R1;\n"
literal|"SGE R2.xyz, R2, R1.w;\n"
literal|"MAD R2.xyz, R2, R3, R1;\n"
literal|"ADD R1.z, fragment.color.primary.w, R0.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_HARDLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_HARDLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R1, R0, texture[0], 2D;\n"
literal|"ADD R0.w, -R1, c[4].y;\n"
literal|"MUL R3.xyz, fragment.color.primary, R0.w;\n"
literal|"ADD R2.xyz, fragment.color.primary.w, -fragment.color.primary;\n"
literal|"ADD R0.xyz, R1.w, -R1;\n"
literal|"MUL R0.xyz, R0, R2;\n"
literal|"MUL R0.xyz, R0, c[4].x;\n"
literal|"MAD R0.xyz, fragment.color.primary.w, R1.w, -R0;\n"
literal|"MAD R0.xyz, fragment.color.primary, R0.w, R0;\n"
literal|"MUL R2.xyz, fragment.color.primary, R1;\n"
literal|"MAD R2.xyz, R2, c[4].x, R3;\n"
literal|"ADD R0.w, -fragment.color.primary, c[4].y;\n"
literal|"MAD R3.xyz, R1, R0.w, R0;\n"
literal|"MAD R2.xyz, R1, R0.w, R2;\n"
literal|"MUL R0.xyz, fragment.color.primary, c[4].x;\n"
literal|"SGE R0.xyz, R0, fragment.color.primary.w;\n"
literal|"ADD R3.xyz, R3, -R2;\n"
literal|"MAD R2.xyz, R0, R3, R2;\n"
literal|"ADD R0.z, fragment.color.primary.w, R1.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[2];\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[3];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SOFTLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SOFTLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..3],\n"
literal|"		{ 1, 2, 9.9999997e-006, 4 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MAX R1.x, R0.w, c[4].z;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MUL R2.xyz, R0, R1.x;\n"
literal|"MAD R1.xyz, R2, c[5].x, -c[5].y;\n"
literal|"MAD R3.xyz, R2, R1, c[5].z;\n"
literal|"MAD R1.xyz, fragment.color.primary, c[4].y, -fragment.color.primary.w;\n"
literal|"MUL R4.xyz, R0.w, R1;\n"
literal|"MUL R5.xyz, R4, R3;\n"
literal|"RSQ R1.w, R2.x;\n"
literal|"RSQ R2.w, R2.z;\n"
literal|"RCP R3.x, R1.w;\n"
literal|"RSQ R1.w, R2.y;\n"
literal|"MUL R5.xyz, R2, R5;\n"
literal|"RCP R3.z, R2.w;\n"
literal|"RCP R3.y, R1.w;\n"
literal|"ADD R3.xyz, -R2, R3;\n"
literal|"MUL R3.xyz, R4, R3;\n"
literal|"ADD R2.xyz, -R2, c[4].x;\n"
literal|"MAD R1.xyz, R1, R2, fragment.color.primary.w;\n"
literal|"MUL R2.xyz, fragment.color.primary, c[4].y;\n"
literal|"MAD R4.xyz, fragment.color.primary.w, R0, R5;\n"
literal|"MAD R3.xyz, fragment.color.primary.w, R0, R3;\n"
literal|"ADD R5.xyz, R3, -R4;\n"
literal|"MUL R3.xyz, R0, c[4].w;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MAD R3.xyz, R3, R5, R4;\n"
literal|"MAD R3.xyz, -R0, R1, R3;\n"
literal|"MUL R1.xyz, R0, R1;\n"
literal|"SGE R2.xyz, R2, fragment.color.primary.w;\n"
literal|"MAD R2.xyz, R2, R3, R1;\n"
literal|"ADD R1.x, -R0.w, c[4];\n"
literal|"MAD R2.xyz, fragment.color.primary, R1.x, R2;\n"
literal|"ADD R1.x, -fragment.color.primary.w, c[4];\n"
literal|"MAD R2.xyz, R0, R1.x, R2;\n"
literal|"ADD R1.z, fragment.color.primary.w, R0.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DIFFERENCE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DIFFERENCE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.xyz, fragment.color.primary, R0;\n"
literal|"MUL R3.xyz, fragment.color.primary.w, R0;\n"
literal|"MUL R2.xyz, fragment.color.primary, R0.w;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"MAD R2.xyz, -R2, c[4].x, R1;\n"
literal|"ADD R1.z, fragment.color.primary.w, R0.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_EXCLUSION
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_EXCLUSION
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[1];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.xyz, fragment.color.primary.w, R0;\n"
literal|"MAD R2.xyz, fragment.color.primary, R0.w, R1;\n"
literal|"MUL R1.xyz, fragment.color.primary, R0;\n"
literal|"MAD R1.xyz, -R1, c[4].x, R2;\n"
literal|"ADD R1.w, -R0, c[4].y;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"ADD R1.w, -fragment.color.primary, c[4].y;\n"
literal|"MAD R2.xyz, R0, R1.w, R1;\n"
literal|"ADD R1.z, fragment.color.primary.w, R0.w;\n"
literal|"MAD R2.w, -fragment.color.primary, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[2];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[3];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[4] = { program.local[0..2],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[2];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.xyz, R0, c[0].y;\n"
literal|"MUL R2.xyz, fragment.color.primary.w, R1;\n"
literal|"MUL R1.xyz, fragment.color.primary, c[0].x;\n"
literal|"MAD R2.xyz, R0.w, R1, R2;\n"
literal|"MUL R0.xyz, R0, c[1].z;\n"
literal|"ADD R1.w, -R0, c[3].x;\n"
literal|"MUL R1.xyz, fragment.color.primary, c[1].y;\n"
literal|"MAD R1.xyz, R1.w, R1, R2;\n"
literal|"ADD R2.x, -fragment.color.primary.w, c[3];\n"
literal|"MAD result.color.xyz, R2.x, R0, R1;\n"
literal|"MUL R0.x, fragment.color.primary.w, R0.w;\n"
literal|"MUL R0.z, R0.w, R2.x;\n"
literal|"MUL R0.y, fragment.color.primary.w, R1.w;\n"
literal|"DP3 result.color.w, R0, c[1];\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_MULTIPLY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_MULTIPLY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -R0.w, c[1];\n"
literal|"MUL R1.xyz, fragment.color.primary, R1.x;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"MAD R1.xyz, fragment.color.primary, R0, R1;\n"
literal|"ADD R2.x, -fragment.color.primary.w, c[1];\n"
literal|"MAD result.color.xyz, R0, R2.x, R1;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SCREEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SCREEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[1] = { program.local[0] };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1, fragment.color.primary, R0;\n"
literal|"MAD result.color, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_OVERLAY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_OVERLAY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.w, -R0, c[1].y;\n"
literal|"ADD R2.xyz, fragment.color.primary.w, -fragment.color.primary;\n"
literal|"ADD R1.xyz, R0.w, -R0;\n"
literal|"MUL R1.xyz, R1, R2;\n"
literal|"MUL R1.xyz, R1, c[1].x;\n"
literal|"MAD R1.xyz, fragment.color.primary.w, R0.w, -R1;\n"
literal|"MUL R3.xyz, fragment.color.primary, R1.w;\n"
literal|"MUL R2.xyz, fragment.color.primary, R0;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"ADD R1.w, -fragment.color.primary, c[1].y;\n"
literal|"MAD R2.xyz, R2, c[1].x, R3;\n"
literal|"MAD R2.xyz, R0, R1.w, R2;\n"
literal|"MAD R1.xyz, R0, R1.w, R1;\n"
literal|"MUL R0.xyz, R0, c[1].x;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"ADD R1.xyz, R1, -R2;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD result.color.xyz, R0, R1, R2;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DARKEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DARKEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R2.xyz, fragment.color.primary.w, R0;\n"
literal|"MUL R1.xyz, fragment.color.primary, R0.w;\n"
literal|"MIN R1.xyz, R1, R2;\n"
literal|"ADD R1.w, -R0, c[1].x;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"ADD R2.x, -fragment.color.primary.w, c[1];\n"
literal|"MAD result.color.xyz, R0, R2.x, R1;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_LIGHTEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_LIGHTEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R2.xyz, fragment.color.primary.w, R0;\n"
literal|"MUL R1.xyz, fragment.color.primary, R0.w;\n"
literal|"MAX R1.xyz, R1, R2;\n"
literal|"ADD R1.w, -R0, c[1].x;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"ADD R2.x, -fragment.color.primary.w, c[1];\n"
literal|"MAD result.color.xyz, R0, R2.x, R1;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORDODGE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORDODGE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MAX R1.y, fragment.color.primary.w, c[1];\n"
literal|"RCP R2.x, R1.y;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -fragment.color.primary.w, c[1];\n"
literal|"MUL R1.xyz, R0, R1.x;\n"
literal|"ADD R1.w, -R0, c[1].x;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"MAD R2.xyz, -fragment.color.primary, R2.x, c[1].x;\n"
literal|"MAX R2.xyz, R2, c[1].y;\n"
literal|"MUL R0.xyz, fragment.color.primary.w, R0;\n"
literal|"MUL R1.w, fragment.color.primary, R0;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R0, R2, R1;\n"
literal|"MAD R1.xyz, fragment.color.primary.w, R0.w, R1;\n"
literal|"MAD R0.xyz, fragment.color.primary, R0.w, R0;\n"
literal|"SGE R0.xyz, R0, R1.w;\n"
literal|"ADD R1.xyz, R1, -R2;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"MAD result.color.xyz, R0, R1, R2;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORBURN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORBURN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.xyz, fragment.color.primary.w, R0;\n"
literal|"MAD R2.xyz, fragment.color.primary, R0.w, R1;\n"
literal|"MAD R1.xyz, -fragment.color.primary.w, R0.w, R2;\n"
literal|"MUL R3.xyz, fragment.color.primary.w, R1;\n"
literal|"MAX R1.xyz, fragment.color.primary, c[1].y;\n"
literal|"ADD R1.w, -R0, c[1].x;\n"
literal|"MUL R4.xyz, fragment.color.primary, R1.w;\n"
literal|"ADD R2.w, -fragment.color.primary, c[1].x;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"RCP R1.y, R1.y;\n"
literal|"RCP R1.z, R1.z;\n"
literal|"MAD R1.xyz, R3, R1, R4;\n"
literal|"MUL R3.xyz, R0, R2.w;\n"
literal|"MAD R0.xyz, R0, R2.w, R1;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R3;\n"
literal|"MUL R1.w, fragment.color.primary, R0;\n"
literal|"SGE R2.xyz, R2, R1.w;\n"
literal|"ADD R0.xyz, R0, -R1;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"MAD result.color.xyz, R2, R0, R1;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_HARDLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_HARDLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.w, -R0, c[1].y;\n"
literal|"ADD R2.xyz, fragment.color.primary.w, -fragment.color.primary;\n"
literal|"ADD R1.xyz, R0.w, -R0;\n"
literal|"MUL R1.xyz, R1, R2;\n"
literal|"MUL R1.xyz, R1, c[1].x;\n"
literal|"MAD R1.xyz, fragment.color.primary.w, R0.w, -R1;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"MUL R3.xyz, fragment.color.primary, R1.w;\n"
literal|"MUL R2.xyz, fragment.color.primary, R0;\n"
literal|"ADD R1.w, -fragment.color.primary, c[1].y;\n"
literal|"MAD R2.xyz, R2, c[1].x, R3;\n"
literal|"MAD R2.xyz, R0, R1.w, R2;\n"
literal|"MAD R0.xyz, R0, R1.w, R1;\n"
literal|"ADD R1.xyz, R0, -R2;\n"
literal|"MUL R0.xyz, fragment.color.primary, c[1].x;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"SGE R0.xyz, R0, fragment.color.primary.w;\n"
literal|"MAD result.color.xyz, R0, R1, R2;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SOFTLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SOFTLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[3] = { program.local[0],\n"
literal|"		{ 1, 2, 9.9999997e-006, 4 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MAX R1.x, R0.w, c[1].z;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MUL R2.xyz, R0, R1.x;\n"
literal|"MAD R1.xyz, R2, c[2].x, -c[2].y;\n"
literal|"MAD R3.xyz, R2, R1, c[2].z;\n"
literal|"MAD R1.xyz, fragment.color.primary, c[1].y, -fragment.color.primary.w;\n"
literal|"MUL R4.xyz, R0.w, R1;\n"
literal|"MUL R5.xyz, R4, R3;\n"
literal|"RSQ R1.w, R2.x;\n"
literal|"RCP R3.x, R1.w;\n"
literal|"RSQ R2.w, R2.z;\n"
literal|"RSQ R1.w, R2.y;\n"
literal|"MUL R5.xyz, R2, R5;\n"
literal|"RCP R3.z, R2.w;\n"
literal|"RCP R3.y, R1.w;\n"
literal|"ADD R3.xyz, -R2, R3;\n"
literal|"MUL R3.xyz, R4, R3;\n"
literal|"ADD R2.xyz, -R2, c[1].x;\n"
literal|"MAD R1.xyz, R1, R2, fragment.color.primary.w;\n"
literal|"MUL R2.xyz, fragment.color.primary, c[1].y;\n"
literal|"MAD R4.xyz, fragment.color.primary.w, R0, R5;\n"
literal|"MAD R3.xyz, fragment.color.primary.w, R0, R3;\n"
literal|"ADD R5.xyz, R3, -R4;\n"
literal|"MUL R3.xyz, R0, c[1].w;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MAD R3.xyz, R3, R5, R4;\n"
literal|"MAD R3.xyz, -R0, R1, R3;\n"
literal|"MUL R1.xyz, R0, R1;\n"
literal|"SGE R2.xyz, R2, fragment.color.primary.w;\n"
literal|"MAD R2.xyz, R2, R3, R1;\n"
literal|"ADD R1.x, -R0.w, c[1];\n"
literal|"MAD R2.xyz, fragment.color.primary, R1.x, R2;\n"
literal|"ADD R1.x, fragment.color.primary.w, R0.w;\n"
literal|"ADD R1.y, -fragment.color.primary.w, c[1].x;\n"
literal|"MAD result.color.xyz, R0, R1.y, R2;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DIFFERENCE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DIFFERENCE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R2.xyz, fragment.color.primary.w, R0;\n"
literal|"MUL R1.xyz, fragment.color.primary, R0.w;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"MIN R1.xyz, R1, R2;\n"
literal|"ADD R0.xyz, fragment.color.primary, R0;\n"
literal|"MAD result.color.xyz, -R1, c[1].x, R0;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_EXCLUSION_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_EXCLUSION_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[2] = { program.local[0],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xy, fragment.position, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.xyz, fragment.color.primary.w, R0;\n"
literal|"MAD R2.xyz, fragment.color.primary, R0.w, R1;\n"
literal|"MUL R1.xyz, fragment.color.primary, R0;\n"
literal|"MAD R1.xyz, -R1, c[1].x, R2;\n"
literal|"ADD R1.w, -R0, c[1].y;\n"
literal|"MAD R1.xyz, fragment.color.primary, R1.w, R1;\n"
literal|"ADD R1.w, fragment.color.primary, R0;\n"
literal|"ADD R2.x, -fragment.color.primary.w, c[1].y;\n"
literal|"MAD result.color.xyz, R0, R2.x, R1;\n"
literal|"MAD result.color.w, -fragment.color.primary, R0, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODE_BLEND_MODE_MASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODE_BLEND_MODE_MASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[3] = { program.local[0..2] };\n"
literal|"TEMP R0;\n"
literal|"ADD R0.xy, fragment.position, c[1];\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"DP4 R0.x, R0, c[2];\n"
literal|"MUL result.color, fragment.color.primary, R0.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODE_BLEND_MODE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODE_BLEND_MODE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"MOV result.color, fragment.color.primary;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[12] = { program.local[0..10],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[11].x;\n"
literal|"MUL R0.z, R0, c[11].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.x, R0.x;\n"
literal|"RCP R0.z, R0.x;\n"
literal|"ADD R1.x, -R0.y, R0.z;\n"
literal|"MOV R0.x, c[11];\n"
literal|"MUL R0.z, R0.x, c[1].x;\n"
literal|"RCP R1.y, R0.z;\n"
literal|"MUL R0.xy, fragment.position, c[8];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R2.xyz, R0, c[5].y;\n"
literal|"MUL R3.xyz, R1.w, R2;\n"
literal|"MUL R2.xyz, R1, c[5].x;\n"
literal|"MAD R2.xyz, R0.w, R2, R3;\n"
literal|"ADD R3.xy, fragment.position, c[9];\n"
literal|"ADD R2.w, -R0, c[11].z;\n"
literal|"MUL R1.xyz, R1, c[6].y;\n"
literal|"MAD R2.xyz, R2.w, R1, R2;\n"
literal|"MUL R1.xyz, R0, c[6].z;\n"
literal|"ADD R3.z, -R1.w, c[11];\n"
literal|"MAD R2.xyz, R3.z, R1, R2;\n"
literal|"MUL R1.y, R1.w, R2.w;\n"
literal|"MUL R1.x, R1.w, R0.w;\n"
literal|"MUL R1.z, R0.w, R3;\n"
literal|"DP3 R2.w, R1, c[6];\n"
literal|"MUL R3.xy, R3, c[7];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[10];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_MULTIPLY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_MULTIPLY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.x, R0.x;\n"
literal|"RCP R0.z, R0.x;\n"
literal|"ADD R1.x, -R0.y, R0.z;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.z, R0.x, c[1].x;\n"
literal|"RCP R1.y, R0.z;\n"
literal|"MUL R0.xy, fragment.position, c[6];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"ADD R2.x, -R0.w, c[9].z;\n"
literal|"MUL R2.xyz, R1, R2.x;\n"
literal|"MAD R1.xyz, R1, R0, R2;\n"
literal|"ADD R2.x, -R1.w, c[9].z;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[7];\n"
literal|"MUL R1.xy, R1, c[5];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[8];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SCREEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SCREEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.z, R0.y, R0.y, -R0;\n"
literal|"ADD R3.xy, fragment.position, c[7];\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RSQ R0.z, R0.z;\n"
literal|"RCP R0.x, R0.z;\n"
literal|"RCP R0.z, R0.w;\n"
literal|"ADD R0.x, -R0.y, R0;\n"
literal|"MUL R0.z, R0.x, R0;\n"
literal|"TEX R1, R0.z, texture[2], 1D;\n"
literal|"MUL R0.xy, fragment.position, c[6];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R2, R1, R0;\n"
literal|"MAD R2, -R1, R0, R2;\n"
literal|"MUL R3.xy, R3, c[5];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[8];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_OVERLAY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_OVERLAY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.z, R0.y, R0.y, -R0;\n"
literal|"MUL R1.xy, fragment.position, c[6];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RSQ R0.z, R0.z;\n"
literal|"RCP R0.x, R0.z;\n"
literal|"ADD R2.w, -R1, c[9].z;\n"
literal|"RCP R0.z, R0.w;\n"
literal|"ADD R0.x, -R0.y, R0;\n"
literal|"MUL R0.x, R0, R0.z;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[9].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, -R0.w, c[9].z;\n"
literal|"MAD R3.xyz, R3, c[9].x, R4;\n"
literal|"MAD R3.xyz, R1, R2.x, R3;\n"
literal|"MAD R0.xyz, R1, R2.x, R0;\n"
literal|"MUL R2.xyz, R1, c[9].x;\n"
literal|"ADD R0.xyz, R0, -R3;\n"
literal|"SGE R2.xyz, R2, R1.w;\n"
literal|"MAD R2.xyz, R2, R0, R3;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[7];\n"
literal|"MUL R0.xy, R0, c[5];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[8];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DARKEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DARKEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.z, -R0.y, R0;\n"
literal|"RCP R0.w, R0.x;\n"
literal|"MUL R1.x, R0.z, R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[6];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[9].z;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[9].z;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[7];\n"
literal|"MUL R1.xy, R1, c[5];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[8];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_LIGHTEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_LIGHTEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.z, -R0.y, R0;\n"
literal|"RCP R0.w, R0.x;\n"
literal|"MUL R1.x, R0.z, R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[6];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[9].z;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[9].z;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[7];\n"
literal|"MUL R1.xy, R1, c[5];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[8];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORDODGE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORDODGE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.z, R0.y, R0.y, -R0;\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RSQ R0.z, R0.z;\n"
literal|"RCP R0.x, R0.z;\n"
literal|"RCP R0.z, R0.w;\n"
literal|"ADD R0.x, -R0.y, R0;\n"
literal|"MUL R0.x, R0, R0.z;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MAX R1.x, R0.w, c[9].w;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MAD R1.xyz, -R0, R1.x, c[9].z;\n"
literal|"MAX R2.xyz, R1, c[9].w;\n"
literal|"MUL R1.xy, fragment.position, c[6];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[9].z;\n"
literal|"MUL R3.xyz, R1, R2.w;\n"
literal|"ADD R2.w, -R1, c[9].z;\n"
literal|"MAD R4.xyz, R0, R2.w, R3;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"MAD R0.xyz, R0, R1.w, R3;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R3, R2, R4;\n"
literal|"MAD R4.xyz, R0.w, R1.w, R4;\n"
literal|"ADD R4.xyz, R4, -R2;\n"
literal|"MAD R2.xyz, R0, R4, R2;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[7];\n"
literal|"MUL R0.xy, R0, c[5];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[8];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORBURN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORBURN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.x, -R0.y, R0.z;\n"
literal|"RCP R0.y, R0.w;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[6].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, R0.y;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"MAD R2.xyz, -R0.w, R1.w, R3;\n"
literal|"MUL R4.xyz, R0.w, R2;\n"
literal|"MAX R2.xyz, R0, c[9].w;\n"
literal|"ADD R2.w, -R1, c[9].z;\n"
literal|"MUL R5.xyz, R0, R2.w;\n"
literal|"ADD R3.w, -R0, c[9].z;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R1, R3.w;\n"
literal|"MAD R0.xyz, R0, R2.w, R4;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"MAD R2.xyz, R1, R3.w, R2;\n"
literal|"ADD R2.xyz, R2, -R0;\n"
literal|"SGE R3.xyz, R3, R2.w;\n"
literal|"MAD R2.xyz, R3, R2, R0;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[7];\n"
literal|"MUL R0.xy, R0, c[5];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[8];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_HARDLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_HARDLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.z, R0.y, R0.y, -R0;\n"
literal|"MUL R1.xy, fragment.position, c[6];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RSQ R0.z, R0.z;\n"
literal|"RCP R0.x, R0.z;\n"
literal|"ADD R2.w, -R1, c[9].z;\n"
literal|"RCP R0.z, R0.w;\n"
literal|"ADD R0.x, -R0.y, R0;\n"
literal|"MUL R0.x, R0, R0.z;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[9].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"ADD R2.w, -R0, c[9].z;\n"
literal|"MAD R3.xyz, R3, c[9].x, R4;\n"
literal|"MUL R0.xyz, R0, c[9].x;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD R3.xyz, R1, R2.w, R3;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.xyz, R2, -R3;\n"
literal|"MAD R2.xyz, R0, R2, R3;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[7];\n"
literal|"MUL R0.xy, R0, c[5];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[8];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SOFTLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SOFTLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1, 9.9999997e-006 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.z, c[9];\n"
literal|"MUL R0.x, R0, c[9];\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[6].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MAD R0.y, R0.x, R0.x, -R0;\n"
literal|"RSQ R0.y, R0.y;\n"
literal|"RCP R0.y, R0.y;\n"
literal|"ADD R0.y, -R0.x, R0;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"MAX R0.z, R1.w, c[9].w;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R3.xyz, R1, R0.z;\n"
literal|"MAD R4.xyz, R3, c[10].x, -c[10].y;\n"
literal|"RCP R0.x, R0.x;\n"
literal|"MUL R0.x, R0.y, R0;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MAD R2.xyz, R0, c[9].x, -R0.w;\n"
literal|"MAD R4.xyz, R3, R4, c[10].z;\n"
literal|"MUL R5.xyz, R1.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[9].z;\n"
literal|"MAD R2.xyz, R2, R3, R0.w;\n"
literal|"MUL R3.xyz, R0, c[9].x;\n"
literal|"MAD R5.xyz, R0.w, R1, R6;\n"
literal|"MAD R4.xyz, R0.w, R1, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R1, c[9].y;\n"
literal|"SGE R4.xyz, R4, R1.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R1, R2, R4;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MUL R2.xyz, R1, R2;\n"
literal|"ADD R2.w, -R1, c[9].z;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R0.x, -R0.w, c[9].z;\n"
literal|"MAD R2.xyz, R1, R0.x, R2;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[7];\n"
literal|"MUL R0.xy, R0, c[5];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[8];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DIFFERENCE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DIFFERENCE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.z, -R0.y, R0;\n"
literal|"RCP R0.w, R0.x;\n"
literal|"MUL R1.x, R0.z, R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[6];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"ADD R2.xyz, R1, R0;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R1.xyz, R1, R0.w;\n"
literal|"MIN R1.xyz, R1, R3;\n"
literal|"MAD R2.xyz, -R1, c[9].x, R2;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[7];\n"
literal|"MUL R1.xy, R1, c[5];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[8];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_EXCLUSION
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_EXCLUSION
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..8],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[9].x;\n"
literal|"MUL R0.z, R0, c[9].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[9];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.z, -R0.y, R0;\n"
literal|"RCP R0.w, R0.x;\n"
literal|"MUL R1.x, R0.z, R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[6];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R2.xyz, R1.w, R0;\n"
literal|"MAD R3.xyz, R1, R0.w, R2;\n"
literal|"MUL R2.xyz, R1, R0;\n"
literal|"MAD R2.xyz, -R2, c[9].x, R3;\n"
literal|"ADD R2.w, -R0, c[9].z;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[9].z;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[7];\n"
literal|"MUL R1.xy, R1, c[5];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[8];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[8].x;\n"
literal|"MUL R0.z, R0, c[8].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.x, R0.x;\n"
literal|"RCP R0.z, R0.x;\n"
literal|"ADD R0.y, -R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[7].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R2.xyz, R1, c[5].y;\n"
literal|"MOV R0.x, c[8];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"RCP R0.x, R0.x;\n"
literal|"MUL R0.x, R0.y, R0;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R3.xyz, R0.w, R2;\n"
literal|"MUL R2.xyz, R0, c[5].x;\n"
literal|"MAD R2.xyz, R1.w, R2, R3;\n"
literal|"ADD R2.w, -R1, c[8].z;\n"
literal|"MUL R0.xyz, R0, c[6].y;\n"
literal|"MAD R0.xyz, R2.w, R0, R2;\n"
literal|"ADD R2.x, -R0.w, c[8].z;\n"
literal|"MUL R1.xyz, R1, c[6].z;\n"
literal|"MAD result.color.xyz, R2.x, R1, R0;\n"
literal|"MUL R0.x, R0.w, R1.w;\n"
literal|"MUL R0.z, R1.w, R2.x;\n"
literal|"MUL R0.y, R0.w, R2.w;\n"
literal|"DP3 result.color.w, R0, c[6];\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_MULTIPLY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_MULTIPLY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.x, R0.x;\n"
literal|"RCP R0.z, R0.x;\n"
literal|"ADD R0.y, -R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"RCP R0.x, R0.x;\n"
literal|"MUL R0.x, R0.y, R0;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"ADD R2.x, -R1.w, c[6].z;\n"
literal|"MUL R2.xyz, R0, R2.x;\n"
literal|"MAD R0.xyz, R0, R1, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[6].z;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SCREEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SCREEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.x, -R0.y, R0.z;\n"
literal|"RCP R0.y, R0.w;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"ADD R2, R0, R1;\n"
literal|"MAD result.color, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_OVERLAY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_OVERLAY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.z, R0.y, R0.y, -R0;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RSQ R0.z, R0.z;\n"
literal|"RCP R0.x, R0.z;\n"
literal|"ADD R2.w, -R1, c[6].z;\n"
literal|"RCP R0.z, R0.w;\n"
literal|"ADD R0.x, -R0.y, R0;\n"
literal|"MUL R0.x, R0, R0.z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[6].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R3.xyz, R0, R2.w;\n"
literal|"MUL R0.xyz, R0, R1;\n"
literal|"ADD R2.w, -R0, c[6].z;\n"
literal|"MAD R0.xyz, R0, c[6].x, R3;\n"
literal|"MAD R0.xyz, R1, R2.w, R0;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MUL R1.xyz, R1, c[6].x;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R2.xyz, R2, -R0;\n"
literal|"SGE R1.xyz, R1, R1.w;\n"
literal|"MAD result.color.xyz, R1, R2, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DARKEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DARKEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.x, -R0.y, R0.z;\n"
literal|"RCP R0.y, R0.w;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[6].z;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[6].z;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_LIGHTEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_LIGHTEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.x, -R0.y, R0.z;\n"
literal|"RCP R0.y, R0.w;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[6].z;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[6].z;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORDODGE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORDODGE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.z, R0.y, R0.y, -R0;\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RSQ R0.z, R0.z;\n"
literal|"RCP R0.x, R0.z;\n"
literal|"RCP R0.z, R0.w;\n"
literal|"ADD R0.x, -R0.y, R0;\n"
literal|"MUL R0.x, R0, R0.z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MAX R1.x, R0.w, c[6].w;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MAD R1.xyz, -R0, R1.x, c[6].z;\n"
literal|"MAX R2.xyz, R1, c[6].w;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[6].z;\n"
literal|"MUL R3.xyz, R1, R2.w;\n"
literal|"ADD R2.w, -R1, c[6].z;\n"
literal|"MAD R3.xyz, R0, R2.w, R3;\n"
literal|"MUL R1.xyz, R0.w, R1;\n"
literal|"MAD R0.xyz, R0, R1.w, R1;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R1, R2, R3;\n"
literal|"MAD R3.xyz, R0.w, R1.w, R3;\n"
literal|"ADD R1.x, R0.w, R1.w;\n"
literal|"ADD R3.xyz, R3, -R2;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"MAD result.color.xyz, R0, R3, R2;\n"
literal|"MAD result.color.w, -R0, R1, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORBURN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORBURN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.x, -R0.y, R0.z;\n"
literal|"RCP R0.y, R0.w;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"ADD R2.w, -R1, c[6].z;\n"
literal|"MAD R2.xyz, -R0.w, R1.w, R3;\n"
literal|"MUL R4.xyz, R0.w, R2;\n"
literal|"MAX R2.xyz, R0, c[6].w;\n"
literal|"MUL R5.xyz, R0, R2.w;\n"
literal|"ADD R3.w, -R0, c[6].z;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R1, R3.w;\n"
literal|"MAD R1.xyz, R1, R3.w, R2;\n"
literal|"MAD R0.xyz, R0, R2.w, R4;\n"
literal|"MUL R2.x, R0.w, R1.w;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R1.xyz, R1, -R0;\n"
literal|"SGE R2.xyz, R3, R2.x;\n"
literal|"MAD result.color.xyz, R2, R1, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_HARDLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_HARDLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.z, R0.y, R0.y, -R0;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RSQ R0.z, R0.z;\n"
literal|"RCP R0.x, R0.z;\n"
literal|"ADD R2.w, -R1, c[6].z;\n"
literal|"RCP R0.z, R0.w;\n"
literal|"ADD R0.x, -R0.y, R0;\n"
literal|"MUL R0.x, R0, R0.z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[6].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.w, -R0, c[6].z;\n"
literal|"MUL R0.xyz, R0, c[6].x;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MAD R3.xyz, R3, c[6].x, R4;\n"
literal|"MAD R1.xyz, R1, R2.w, R3;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R2.xyz, R2, -R1;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD result.color.xyz, R0, R2, R1;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SOFTLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SOFTLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1, 9.9999997e-006 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.z, c[6];\n"
literal|"MUL R0.x, R0, c[6];\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MAD R0.y, R0.x, R0.x, -R0;\n"
literal|"RSQ R0.y, R0.y;\n"
literal|"RCP R0.y, R0.y;\n"
literal|"ADD R0.y, -R0.x, R0;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"MAX R0.z, R1.w, c[6].w;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R3.xyz, R1, R0.z;\n"
literal|"MAD R4.xyz, R3, c[7].x, -c[7].y;\n"
literal|"RCP R0.x, R0.x;\n"
literal|"MUL R0.x, R0.y, R0;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MAD R2.xyz, R0, c[6].x, -R0.w;\n"
literal|"MAD R4.xyz, R3, R4, c[7].z;\n"
literal|"MUL R5.xyz, R1.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[6].z;\n"
literal|"MAD R2.xyz, R2, R3, R0.w;\n"
literal|"MUL R3.xyz, R0, c[6].x;\n"
literal|"MAD R5.xyz, R0.w, R1, R6;\n"
literal|"MAD R4.xyz, R0.w, R1, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R1, c[6].y;\n"
literal|"SGE R4.xyz, R4, R1.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R1, R2, R4;\n"
literal|"MUL R2.xyz, R1, R2;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"ADD R2.w, -R1, c[6].z;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R0.x, R0.w, R1.w;\n"
literal|"ADD R0.y, -R0.w, c[6].z;\n"
literal|"MAD result.color.xyz, R1, R0.y, R2;\n"
literal|"MAD result.color.w, -R0, R1, R0.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DIFFERENCE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DIFFERENCE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.x, -R0.y, R0.z;\n"
literal|"RCP R0.y, R0.w;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"ADD R0.xyz, R0, R1;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R1.x, R0.w, R1.w;\n"
literal|"MAD result.color.xyz, -R2, c[6].x, R0;\n"
literal|"MAD result.color.w, -R0, R1, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_EXCLUSION_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_EXCLUSION_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..5],\n"
literal|"		{ 2, 4, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.x, c[6].x;\n"
literal|"MUL R0.z, R0, c[6].y;\n"
literal|"MAD R0.x, R0.y, R0.y, -R0.z;\n"
literal|"RSQ R0.z, R0.x;\n"
literal|"MOV R0.x, c[6];\n"
literal|"MUL R0.w, R0.x, c[1].x;\n"
literal|"RCP R0.z, R0.z;\n"
literal|"ADD R0.x, -R0.y, R0.z;\n"
literal|"RCP R0.y, R0.w;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"MUL R2.xyz, R0, R1;\n"
literal|"MAD R2.xyz, -R2, c[6].x, R3;\n"
literal|"ADD R2.w, -R1, c[6].z;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[6].z;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODE_BLEND_MODE_MASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODE_BLEND_MODE_MASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2, 4 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.z, c[8];\n"
literal|"MUL R0.x, R0, c[8];\n"
literal|"MAD R0.y, R0.x, R0.x, -R0;\n"
literal|"RSQ R0.y, R0.y;\n"
literal|"RCP R0.y, R0.y;\n"
literal|"ADD R1.x, -R0, R0.y;\n"
literal|"MOV R0.x, c[8];\n"
literal|"MUL R0.x, R0, c[1];\n"
literal|"RCP R1.y, R0.x;\n"
literal|"ADD R0.zw, fragment.position.xyxy, c[6].xyxy;\n"
literal|"MUL R0.zw, R0, c[5].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"DP4 R1.y, R0, c[7];\n"
literal|"TEX R0, R1, texture[1], 1D;\n"
literal|"MUL result.color, R0, R1.y;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODE_BLEND_MODE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODE_BLEND_MODE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2, 4 } };\n"
literal|"TEMP R0;\n"
literal|"MUL R0.xyz, fragment.position.y, c[3];\n"
literal|"MAD R0.xyz, fragment.position.x, c[2], R0;\n"
literal|"ADD R0.xyz, R0, c[4];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.xyxy;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.z, R0, R0.w;\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, -R0, c[1].x;\n"
literal|"MUL R0.y, R0.z, c[5];\n"
literal|"MUL R0.x, R0, c[5];\n"
literal|"MAD R0.z, R0.x, R0.x, -R0.y;\n"
literal|"MOV R0.y, c[5].x;\n"
literal|"RSQ R0.z, R0.z;\n"
literal|"MUL R0.w, R0.y, c[1].x;\n"
literal|"RCP R0.y, R0.z;\n"
literal|"RCP R0.z, R0.w;\n"
literal|"ADD R0.x, -R0, R0.y;\n"
literal|"MUL R0.x, R0, R0.z;\n"
literal|"TEX result.color, R0, texture[0], 1D;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[13] = { program.local[0..9],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[10].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[11].x, c[11].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[11];\n"
literal|"MAD R1.z, R1, R1.y, c[11].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[12].x;\n"
literal|"MAD R1.y, R1.z, R1, c[12];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[10].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[10].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R1.x, R0, c[10];\n"
literal|"FLR R1.y, R1.x;\n"
literal|"MUL R0.xy, fragment.position, c[7];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, R1, -R1.y;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R2.xyz, R0, c[4].y;\n"
literal|"MUL R3.xyz, R1.w, R2;\n"
literal|"MUL R2.xyz, R1, c[4].x;\n"
literal|"MAD R2.xyz, R0.w, R2, R3;\n"
literal|"ADD R3.xy, fragment.position, c[8];\n"
literal|"ADD R2.w, -R0, c[12].z;\n"
literal|"MUL R1.xyz, R1, c[5].y;\n"
literal|"MAD R2.xyz, R2.w, R1, R2;\n"
literal|"MUL R1.xyz, R0, c[5].z;\n"
literal|"ADD R3.z, -R1.w, c[12];\n"
literal|"MAD R2.xyz, R3.z, R1, R2;\n"
literal|"MUL R1.y, R1.w, R2.w;\n"
literal|"MUL R1.x, R1.w, R0.w;\n"
literal|"MUL R1.z, R0.w, R3;\n"
literal|"DP3 R2.w, R1, c[5];\n"
literal|"MUL R3.xy, R3, c[6];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[9];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_MULTIPLY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_MULTIPLY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[9].x, c[9].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[9];\n"
literal|"MAD R1.z, R1, R1.y, c[9].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[10].x;\n"
literal|"MAD R1.y, R1.z, R1, c[10];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[8].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[8].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R1.x, R0, c[8];\n"
literal|"FLR R1.y, R1.x;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, R1, -R1.y;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"ADD R2.x, -R0.w, c[10].z;\n"
literal|"MUL R2.xyz, R1, R2.x;\n"
literal|"MAD R1.xyz, R1, R0, R2;\n"
literal|"ADD R2.x, -R1.w, c[10].z;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SCREEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SCREEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ADD R3.xy, fragment.position, c[6];\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[9].x, c[9].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[9];\n"
literal|"MAD R1.z, R1, R1.y, c[9].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[10].x;\n"
literal|"MAD R1.y, R1.z, R1, c[10];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[8].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[8].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[8];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.z, R0.x, -R0.y;\n"
literal|"TEX R1, R0.z, texture[2], 1D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R2, R1, R0;\n"
literal|"MAD R2, -R1, R0, R2;\n"
literal|"MUL R3.xy, R3, c[4];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_OVERLAY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_OVERLAY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8];\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[8].y, c[8];\n"
literal|"MAD R1.z, R1, R1.y, -c[8].w;\n"
literal|"MAD R1.z, R1, R1.y, c[9].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[9].y;\n"
literal|"MAD R1.y, R1.z, R1, c[9].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[9].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[10].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[10].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[10];\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[10].z;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, -R0.w, c[10].w;\n"
literal|"MAD R3.xyz, R3, c[10].z, R4;\n"
literal|"MAD R3.xyz, R1, R2.x, R3;\n"
literal|"MAD R0.xyz, R1, R2.x, R0;\n"
literal|"MUL R2.xyz, R1, c[10].z;\n"
literal|"ADD R0.xyz, R0, -R3;\n"
literal|"SGE R2.xyz, R2, R1.w;\n"
literal|"MAD R2.xyz, R2, R0, R3;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DARKEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DARKEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[9].x, c[9].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[9];\n"
literal|"MAD R1.z, R1, R1.y, c[9].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[10].x;\n"
literal|"MAD R1.y, R1.z, R1, c[10];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[8].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[8].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.z, R0.x, c[8].x;\n"
literal|"FLR R0.w, R0.z;\n"
literal|"ADD R1.x, R0.z, -R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[10].z;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[10].z;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_LIGHTEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_LIGHTEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[9].x, c[9].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[9];\n"
literal|"MAD R1.z, R1, R1.y, c[9].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[10].x;\n"
literal|"MAD R1.y, R1.z, R1, c[10];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[8].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[8].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.z, R0.x, c[8].x;\n"
literal|"FLR R0.w, R0.z;\n"
literal|"ADD R1.x, R0.z, -R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[10].z;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[10].z;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORDODGE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORDODGE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8];\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[8].y, c[8];\n"
literal|"MAD R1.z, R1, R1.y, -c[8].w;\n"
literal|"MAD R1.z, R1, R1.y, c[9].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[9].y;\n"
literal|"MAD R1.y, R1.z, R1, c[9].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[9].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[10].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[10].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MAX R1.x, R0.w, c[10].w;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MAD R1.xyz, -R0, R1.x, c[10].z;\n"
literal|"MAX R2.xyz, R1, c[10].w;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[10].z;\n"
literal|"MUL R3.xyz, R1, R2.w;\n"
literal|"ADD R2.w, -R1, c[10].z;\n"
literal|"MAD R4.xyz, R0, R2.w, R3;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"MAD R0.xyz, R0, R1.w, R3;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R3, R2, R4;\n"
literal|"MAD R4.xyz, R0.w, R1.w, R4;\n"
literal|"ADD R4.xyz, R4, -R2;\n"
literal|"MAD R2.xyz, R0, R4, R2;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORBURN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORBURN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.w, R0.x;\n"
literal|"ABS R0.z, R0.y;\n"
literal|"ADD R0.z, R0, -R0.w;\n"
literal|"ADD R1.x, R0.y, c[8];\n"
literal|"ABS R0.z, R0;\n"
literal|"CMP R0.y, -R0.z, R0, R1.x;\n"
literal|"ABS R0.z, -R0.y;\n"
literal|"MAX R1.x, R0.w, R0.z;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.w, R0.z;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[8].y, c[8];\n"
literal|"MAD R1.z, R1, R1.y, -c[8].w;\n"
literal|"MAD R1.z, R1, R1.y, c[9].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[9].y;\n"
literal|"MAD R1.y, R1.z, R1, c[9].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[9].w;\n"
literal|"ADD R0.z, -R0.w, R0;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[10].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[10].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"MAD R2.xyz, -R0.w, R1.w, R3;\n"
literal|"MUL R4.xyz, R0.w, R2;\n"
literal|"MAX R2.xyz, R0, c[10].w;\n"
literal|"ADD R2.w, -R1, c[10].z;\n"
literal|"ADD R3.w, -R0, c[10].z;\n"
literal|"MUL R5.xyz, R0, R2.w;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R1, R3.w;\n"
literal|"MAD R0.xyz, R0, R2.w, R4;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"MAD R2.xyz, R1, R3.w, R2;\n"
literal|"ADD R2.xyz, R2, -R0;\n"
literal|"SGE R3.xyz, R3, R2.w;\n"
literal|"MAD R2.xyz, R3, R2, R0;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_HARDLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_HARDLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8];\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[8].y, c[8];\n"
literal|"MAD R1.z, R1, R1.y, -c[8].w;\n"
literal|"MAD R1.z, R1, R1.y, c[9].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[9].y;\n"
literal|"MAD R1.y, R1.z, R1, c[9].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[9].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[10].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[10].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[10];\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[10].z;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"ADD R2.w, -R0, c[10];\n"
literal|"MAD R3.xyz, R3, c[10].z, R4;\n"
literal|"MUL R0.xyz, R0, c[10].z;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD R3.xyz, R1, R2.w, R3;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.xyz, R2, -R3;\n"
literal|"MAD R2.xyz, R0, R2, R3;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SOFTLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SOFTLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[13] = { program.local[0..7],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 1, 2 },\n"
literal|"		{ 9.9999997e-006, 4, 16, 12 },\n"
literal|"		{ 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.w, R0.x;\n"
literal|"ABS R0.z, R0.y;\n"
literal|"ADD R0.z, R0, -R0.w;\n"
literal|"ADD R1.x, R0.y, c[8];\n"
literal|"ABS R0.z, R0;\n"
literal|"CMP R0.y, -R0.z, R0, R1.x;\n"
literal|"ABS R0.z, -R0.y;\n"
literal|"MAX R1.x, R0.w, R0.z;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.w, R0.z;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[8].y, c[8];\n"
literal|"MAD R1.z, R1, R1.y, -c[8].w;\n"
literal|"MAD R1.z, R1, R1.y, c[9].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[9].y;\n"
literal|"MAD R1.y, R1.z, R1, c[9].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[9].w;\n"
literal|"ADD R0.z, -R0.w, R0;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[10].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MAX R0.z, R1.w, c[11].x;\n"
literal|"RCP R2.x, R0.z;\n"
literal|"MUL R3.xyz, R1, R2.x;\n"
literal|"MAD R4.xyz, R3, c[11].z, -c[11].w;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[10].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MAD R2.xyz, R0, c[10].w, -R0.w;\n"
literal|"MAD R4.xyz, R3, R4, c[12].x;\n"
literal|"MUL R5.xyz, R1.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[10].z;\n"
literal|"MAD R2.xyz, R2, R3, R0.w;\n"
literal|"MUL R3.xyz, R0, c[10].w;\n"
literal|"MAD R5.xyz, R0.w, R1, R6;\n"
literal|"MAD R4.xyz, R0.w, R1, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R1, c[11].y;\n"
literal|"SGE R4.xyz, R4, R1.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R1, R2, R4;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MUL R2.xyz, R1, R2;\n"
literal|"ADD R2.w, -R1, c[10].z;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R0.x, -R0.w, c[10].z;\n"
literal|"MAD R2.xyz, R1, R0.x, R2;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DIFFERENCE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DIFFERENCE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[9].x, c[9].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[9];\n"
literal|"MAD R1.z, R1, R1.y, c[9].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[10].x;\n"
literal|"MAD R1.y, R1.z, R1, c[10];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[8].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[8].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.z, R0.x, c[8].x;\n"
literal|"FLR R0.w, R0.z;\n"
literal|"ADD R1.x, R0.z, -R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"ADD R2.xyz, R1, R0;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R1.xyz, R1, R0.w;\n"
literal|"MIN R1.xyz, R1, R3;\n"
literal|"MAD R2.xyz, -R1, c[10].z, R2;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_EXCLUSION
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_EXCLUSION
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..7],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[8].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[9].x, c[9].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[9];\n"
literal|"MAD R1.z, R1, R1.y, c[9].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[10].x;\n"
literal|"MAD R1.y, R1.z, R1, c[10];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[8].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[8].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.z, R0.x, c[8].x;\n"
literal|"FLR R0.w, R0.z;\n"
literal|"ADD R1.x, R0.z, -R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R2.xyz, R1.w, R0;\n"
literal|"MAD R3.xyz, R1, R0.w, R2;\n"
literal|"MUL R2.xyz, R1, R0;\n"
literal|"MAD R2.xyz, -R2, c[10].z, R3;\n"
literal|"ADD R2.w, -R0, c[10];\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[10].w;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..6],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[7].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[8].x, c[8].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[8];\n"
literal|"MAD R1.z, R1, R1.y, c[8].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[9].x;\n"
literal|"MAD R1.y, R1.z, R1, c[9];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[7].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[7].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[6].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R2.xyz, R1, c[4].y;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[7];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R3.xyz, R0.w, R2;\n"
literal|"MUL R2.xyz, R0, c[4].x;\n"
literal|"MAD R2.xyz, R1.w, R2, R3;\n"
literal|"ADD R2.w, -R1, c[9].z;\n"
literal|"MUL R0.xyz, R0, c[5].y;\n"
literal|"MAD R0.xyz, R2.w, R0, R2;\n"
literal|"ADD R2.x, -R0.w, c[9].z;\n"
literal|"MUL R1.xyz, R1, c[5].z;\n"
literal|"MAD result.color.xyz, R2.x, R1, R0;\n"
literal|"MUL R0.x, R0.w, R1.w;\n"
literal|"MUL R0.z, R1.w, R2.x;\n"
literal|"MUL R0.y, R0.w, R2.w;\n"
literal|"DP3 result.color.w, R0, c[5];\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_MULTIPLY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_MULTIPLY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[6].x, c[6].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[6];\n"
literal|"MAD R1.z, R1, R1.y, c[6].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[7].x;\n"
literal|"MAD R1.y, R1.z, R1, c[7];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[5].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[5].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[5];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"ADD R2.x, -R1.w, c[7].z;\n"
literal|"MUL R2.xyz, R0, R2.x;\n"
literal|"MAD R0.xyz, R0, R1, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[7].z;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SCREEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SCREEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[6].x, c[6].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[6];\n"
literal|"MAD R1.z, R1, R1.y, c[6].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[7].x;\n"
literal|"MAD R1.y, R1.z, R1, c[7];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[5].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[5].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[5];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"ADD R2, R0, R1;\n"
literal|"MAD result.color, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_OVERLAY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_OVERLAY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5];\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[5].y, c[5];\n"
literal|"MAD R1.z, R1, R1.y, -c[5].w;\n"
literal|"MAD R1.z, R1, R1.y, c[6].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[6].y;\n"
literal|"MAD R1.y, R1.z, R1, c[6].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[6].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[7].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[7].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[7];\n"
literal|"MUL R2.xyz, R2, c[7].z;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R3.xyz, R0, R2.w;\n"
literal|"MUL R0.xyz, R0, R1;\n"
literal|"ADD R2.w, -R0, c[7];\n"
literal|"MAD R0.xyz, R0, c[7].z, R3;\n"
literal|"MAD R0.xyz, R1, R2.w, R0;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MUL R1.xyz, R1, c[7].z;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R2.xyz, R2, -R0;\n"
literal|"SGE R1.xyz, R1, R1.w;\n"
literal|"MAD result.color.xyz, R1, R2, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DARKEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DARKEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[6].x, c[6].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[6];\n"
literal|"MAD R1.z, R1, R1.y, c[6].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[7].x;\n"
literal|"MAD R1.y, R1.z, R1, c[7];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[5].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[5].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[5];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[7].z;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[7].z;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_LIGHTEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_LIGHTEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[6].x, c[6].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[6];\n"
literal|"MAD R1.z, R1, R1.y, c[6].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[7].x;\n"
literal|"MAD R1.y, R1.z, R1, c[7];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[5].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[5].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[5];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[7].z;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[7].z;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORDODGE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORDODGE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5];\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[5].y, c[5];\n"
literal|"MAD R1.z, R1, R1.y, -c[5].w;\n"
literal|"MAD R1.z, R1, R1.y, c[6].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[6].y;\n"
literal|"MAD R1.y, R1.z, R1, c[6].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[6].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[7].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[7].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MAX R1.x, R0.w, c[7].w;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MAD R1.xyz, -R0, R1.x, c[7].z;\n"
literal|"MAX R2.xyz, R1, c[7].w;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[7].z;\n"
literal|"MUL R3.xyz, R1, R2.w;\n"
literal|"ADD R2.w, -R1, c[7].z;\n"
literal|"MAD R3.xyz, R0, R2.w, R3;\n"
literal|"MUL R1.xyz, R0.w, R1;\n"
literal|"MAD R0.xyz, R0, R1.w, R1;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R1, R2, R3;\n"
literal|"MAD R3.xyz, R0.w, R1.w, R3;\n"
literal|"ADD R1.x, R0.w, R1.w;\n"
literal|"ADD R3.xyz, R3, -R2;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"MAD result.color.xyz, R0, R3, R2;\n"
literal|"MAD result.color.w, -R0, R1, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORBURN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORBURN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.w, R0.x;\n"
literal|"ABS R0.z, R0.y;\n"
literal|"ADD R0.z, R0, -R0.w;\n"
literal|"ADD R1.x, R0.y, c[5];\n"
literal|"ABS R0.z, R0;\n"
literal|"CMP R0.y, -R0.z, R0, R1.x;\n"
literal|"ABS R0.z, -R0.y;\n"
literal|"MAX R1.x, R0.w, R0.z;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.w, R0.z;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[5].y, c[5];\n"
literal|"MAD R1.z, R1, R1.y, -c[5].w;\n"
literal|"MAD R1.z, R1, R1.y, c[6].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[6].y;\n"
literal|"MAD R1.y, R1.z, R1, c[6].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[6].w;\n"
literal|"ADD R0.z, -R0.w, R0;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[7].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[7].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"ADD R2.w, -R1, c[7].z;\n"
literal|"MAD R2.xyz, -R0.w, R1.w, R3;\n"
literal|"MUL R4.xyz, R0.w, R2;\n"
literal|"MAX R2.xyz, R0, c[7].w;\n"
literal|"MUL R5.xyz, R0, R2.w;\n"
literal|"ADD R3.w, -R0, c[7].z;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R1, R3.w;\n"
literal|"MAD R1.xyz, R1, R3.w, R2;\n"
literal|"MAD R0.xyz, R0, R2.w, R4;\n"
literal|"MUL R2.x, R0.w, R1.w;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R1.xyz, R1, -R0;\n"
literal|"SGE R2.xyz, R3, R2.x;\n"
literal|"MAD result.color.xyz, R2, R1, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_HARDLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_HARDLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5];\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[5].y, c[5];\n"
literal|"MAD R1.z, R1, R1.y, -c[5].w;\n"
literal|"MAD R1.z, R1, R1.y, c[6].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[6].y;\n"
literal|"MAD R1.y, R1.z, R1, c[6].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[6].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[7].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[7].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[7];\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[7].z;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.w, -R0, c[7];\n"
literal|"MUL R0.xyz, R0, c[7].z;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MAD R3.xyz, R3, c[7].z, R4;\n"
literal|"MAD R1.xyz, R1, R2.w, R3;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R2.xyz, R2, -R1;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD result.color.xyz, R0, R2, R1;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SOFTLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SOFTLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..4],\n"
literal|"		{ 0.0020000001, -0.01348047, 0.05747731, 0.1212391 },\n"
literal|"		{ 0.1956359, 0.33299461, 0.99999559, 1.570796 },\n"
literal|"		{ 3.141593, 0.15915494, 1, 2 },\n"
literal|"		{ 9.9999997e-006, 4, 16, 12 },\n"
literal|"		{ 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.w, R0.x;\n"
literal|"ABS R0.z, R0.y;\n"
literal|"ADD R0.z, R0, -R0.w;\n"
literal|"ADD R1.x, R0.y, c[5];\n"
literal|"ABS R0.z, R0;\n"
literal|"CMP R0.y, -R0.z, R0, R1.x;\n"
literal|"ABS R0.z, -R0.y;\n"
literal|"MAX R1.x, R0.w, R0.z;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.w, R0.z;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[5].y, c[5];\n"
literal|"MAD R1.z, R1, R1.y, -c[5].w;\n"
literal|"MAD R1.z, R1, R1.y, c[6].x;\n"
literal|"MAD R1.z, R1, R1.y, -c[6].y;\n"
literal|"MAD R1.y, R1.z, R1, c[6].z;\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[6].w;\n"
literal|"ADD R0.z, -R0.w, R0;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[7].x;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MAX R0.z, R1.w, c[8].x;\n"
literal|"RCP R2.x, R0.z;\n"
literal|"MUL R3.xyz, R1, R2.x;\n"
literal|"MAD R4.xyz, R3, c[8].z, -c[8].w;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[7].y;\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MAD R2.xyz, R0, c[7].w, -R0.w;\n"
literal|"MAD R4.xyz, R3, R4, c[9].x;\n"
literal|"MUL R5.xyz, R1.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[7].z;\n"
literal|"MAD R2.xyz, R2, R3, R0.w;\n"
literal|"MUL R3.xyz, R0, c[7].w;\n"
literal|"MAD R5.xyz, R0.w, R1, R6;\n"
literal|"MAD R4.xyz, R0.w, R1, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R1, c[8].y;\n"
literal|"SGE R4.xyz, R4, R1.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R1, R2, R4;\n"
literal|"MUL R2.xyz, R1, R2;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"ADD R2.w, -R1, c[7].z;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R0.x, R0.w, R1.w;\n"
literal|"ADD R0.y, -R0.w, c[7].z;\n"
literal|"MAD result.color.xyz, R1, R0.y, R2;\n"
literal|"MAD result.color.w, -R0, R1, R0.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DIFFERENCE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DIFFERENCE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[6].x, c[6].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[6];\n"
literal|"MAD R1.z, R1, R1.y, c[6].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[7].x;\n"
literal|"MAD R1.y, R1.z, R1, c[7];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[5].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[5].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[5];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"ADD R0.xyz, R0, R1;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R1.x, R0.w, R1.w;\n"
literal|"MAD result.color.xyz, -R2, c[7].z, R0;\n"
literal|"MAD result.color.w, -R0, R1, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_EXCLUSION_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_EXCLUSION_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..4],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559, 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[5].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[6].x, c[6].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[6];\n"
literal|"MAD R1.z, R1, R1.y, c[6].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[7].x;\n"
literal|"MAD R1.y, R1.z, R1, c[7];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[5].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[5].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[5];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"MUL R2.xyz, R0, R1;\n"
literal|"MAD R2.xyz, -R2, c[7].z, R3;\n"
literal|"ADD R2.w, -R1, c[7];\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[7].w;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODE_BLEND_MODE_MASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODE_BLEND_MODE_MASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..6],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[7].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[8].x, c[8].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[8];\n"
literal|"MAD R1.z, R1, R1.y, c[8].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[9].x;\n"
literal|"MAD R1.y, R1.z, R1, c[9];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R1.y, -R1.x, c[7].w;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[7].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R1.x, R0, c[7];\n"
literal|"FLR R1.y, R1.x;\n"
literal|"ADD R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"MUL R0.xy, R0.zwzw, c[4];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, R1, -R1.y;\n"
literal|"DP4 R1.y, R0, c[6];\n"
literal|"TEX R0, R1, texture[1], 1D;\n"
literal|"MUL result.color, R0, R1.y;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODE_BLEND_MODE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODE_BLEND_MODE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..3],\n"
literal|"		{ 0.15915494, 0.0020000001, 3.141593, 1.570796 },\n"
literal|"		{ -0.01348047, 0.05747731, 0.1212391, 0.1956359 },\n"
literal|"		{ 0.33299461, 0.99999559 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"ABS R0.z, R0.x;\n"
literal|"ABS R0.w, R0.y;\n"
literal|"ADD R0.w, R0, -R0.z;\n"
literal|"ADD R1.x, R0.y, c[4].y;\n"
literal|"ABS R0.w, R0;\n"
literal|"CMP R0.y, -R0.w, R0, R1.x;\n"
literal|"ABS R0.w, -R0.y;\n"
literal|"MAX R1.x, R0.z, R0.w;\n"
literal|"RCP R1.y, R1.x;\n"
literal|"MIN R1.x, R0.z, R0.w;\n"
literal|"MUL R1.x, R1, R1.y;\n"
literal|"MUL R1.y, R1.x, R1.x;\n"
literal|"MAD R1.z, R1.y, c[5].x, c[5].y;\n"
literal|"MAD R1.z, R1, R1.y, -c[5];\n"
literal|"MAD R1.z, R1, R1.y, c[5].w;\n"
literal|"MAD R1.z, R1, R1.y, -c[6].x;\n"
literal|"MAD R1.y, R1.z, R1, c[6];\n"
literal|"MUL R1.x, R1.y, R1;\n"
literal|"ADD R0.z, -R0, R0.w;\n"
literal|"ADD R1.y, -R1.x, c[4].w;\n"
literal|"CMP R0.z, -R0, R1.y, R1.x;\n"
literal|"ADD R0.w, -R0.z, c[4].z;\n"
literal|"CMP R0.x, R0, R0.w, R0.z;\n"
literal|"CMP R0.x, -R0.y, -R0, R0;\n"
literal|"ADD R0.x, R0, c[0];\n"
literal|"MUL R0.x, R0, c[4];\n"
literal|"FLR R0.y, R0.x;\n"
literal|"ADD R0.x, R0, -R0.y;\n"
literal|"TEX result.color, R0, texture[0], 1D;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..9],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, c[0].xyxy;\n"
literal|"ADD R1.x, R0.z, R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[7];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.x, R1, c[0].z;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R2.xyz, R0, c[4].y;\n"
literal|"MUL R3.xyz, R1.w, R2;\n"
literal|"MUL R2.xyz, R1, c[4].x;\n"
literal|"MAD R2.xyz, R0.w, R2, R3;\n"
literal|"ADD R3.xy, fragment.position, c[8];\n"
literal|"ADD R2.w, -R0, c[10].x;\n"
literal|"MUL R1.xyz, R1, c[5].y;\n"
literal|"MAD R2.xyz, R2.w, R1, R2;\n"
literal|"MUL R1.xyz, R0, c[5].z;\n"
literal|"ADD R3.z, -R1.w, c[10].x;\n"
literal|"MAD R2.xyz, R3.z, R1, R2;\n"
literal|"MUL R1.y, R1.w, R2.w;\n"
literal|"MUL R1.x, R1.w, R0.w;\n"
literal|"MUL R1.z, R0.w, R3;\n"
literal|"DP3 R2.w, R1, c[5];\n"
literal|"MUL R3.xy, R3, c[6];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[9];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_MULTIPLY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_MULTIPLY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, c[0].xyxy;\n"
literal|"ADD R1.x, R0.z, R0.w;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.x, R1, c[0].z;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"ADD R2.x, -R0.w, c[8];\n"
literal|"MUL R2.xyz, R1, R2.x;\n"
literal|"MAD R1.xyz, R1, R0, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SCREEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SCREEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..7] };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.z, R0.x, c[0];\n"
literal|"ADD R3.xy, fragment.position, c[6];\n"
literal|"TEX R1, R0.z, texture[2], 1D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R2, R1, R0;\n"
literal|"MAD R2, -R1, R0, R2;\n"
literal|"MUL R3.xy, R3, c[4];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_OVERLAY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_OVERLAY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[8].y;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[8].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, -R0.w, c[8].y;\n"
literal|"MAD R3.xyz, R3, c[8].x, R4;\n"
literal|"MAD R3.xyz, R1, R2.x, R3;\n"
literal|"MAD R0.xyz, R1, R2.x, R0;\n"
literal|"MUL R2.xyz, R1, c[8].x;\n"
literal|"ADD R0.xyz, R0, -R3;\n"
literal|"SGE R2.xyz, R2, R1.w;\n"
literal|"MAD R2.xyz, R2, R0, R3;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DARKEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DARKEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.z, R0.x, R0.y;\n"
literal|"MUL R1.x, R0.z, c[0].z;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_LIGHTEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_LIGHTEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.z, R0.x, R0.y;\n"
literal|"MUL R1.x, R0.z, c[0].z;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORDODGE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORDODGE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MAX R1.x, R0.w, c[8].y;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MAD R2.xyz, -R0, R1.x, c[8].x;\n"
literal|"MAX R2.xyz, R2, c[8].y;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MUL R3.xyz, R1, R2.w;\n"
literal|"ADD R2.w, -R1, c[8].x;\n"
literal|"MAD R4.xyz, R0, R2.w, R3;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"MAD R0.xyz, R0, R1.w, R3;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R3, R2, R4;\n"
literal|"MAD R4.xyz, R0.w, R1.w, R4;\n"
literal|"ADD R4.xyz, R4, -R2;\n"
literal|"MAD R2.xyz, R0, R4, R2;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORBURN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORBURN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"MAD R2.xyz, -R0.w, R1.w, R3;\n"
literal|"MUL R4.xyz, R0.w, R2;\n"
literal|"MAX R2.xyz, R0, c[8].y;\n"
literal|"ADD R2.w, -R1, c[8].x;\n"
literal|"MUL R5.xyz, R0, R2.w;\n"
literal|"ADD R3.w, -R0, c[8].x;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R1, R3.w;\n"
literal|"MAD R0.xyz, R0, R2.w, R4;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"MAD R2.xyz, R1, R3.w, R2;\n"
literal|"ADD R2.xyz, R2, -R0;\n"
literal|"SGE R3.xyz, R3, R2.w;\n"
literal|"MAD R2.xyz, R3, R2, R0;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_HARDLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_HARDLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[8].y;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[8].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"ADD R2.w, -R0, c[8].y;\n"
literal|"MAD R3.xyz, R3, c[8].x, R4;\n"
literal|"MUL R0.xyz, R0, c[8].x;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD R3.xyz, R1, R2.w, R3;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.xyz, R2, -R3;\n"
literal|"MAD R2.xyz, R0, R2, R3;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SOFTLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SOFTLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..7],\n"
literal|"		{ 1, 2, 9.9999997e-006, 4 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MAX R0.z, R1.w, c[8];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R3.xyz, R1, R0.z;\n"
literal|"MAD R2.xyz, R3, c[9].x, -c[9].y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[2], 1D;\n"
literal|"MAD R4.xyz, R3, R2, c[9].z;\n"
literal|"MAD R2.xyz, R0, c[8].y, -R0.w;\n"
literal|"MUL R5.xyz, R1.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[8].x;\n"
literal|"MAD R2.xyz, R2, R3, R0.w;\n"
literal|"MUL R3.xyz, R0, c[8].y;\n"
literal|"MAD R5.xyz, R0.w, R1, R6;\n"
literal|"MAD R4.xyz, R0.w, R1, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R1, c[8].w;\n"
literal|"SGE R4.xyz, R4, R1.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R1, R2, R4;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MUL R2.xyz, R1, R2;\n"
literal|"ADD R2.w, -R1, c[8].x;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R0.x, -R0.w, c[8];\n"
literal|"MAD R2.xyz, R1, R0.x, R2;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DIFFERENCE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DIFFERENCE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.z, R0.x, R0.y;\n"
literal|"MUL R1.x, R0.z, c[0].z;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"ADD R2.xyz, R1, R0;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R1.xyz, R1, R0.w;\n"
literal|"MIN R1.xyz, R1, R3;\n"
literal|"MAD R2.xyz, -R1, c[8].x, R2;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_EXCLUSION
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_EXCLUSION
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.z, R0.x, R0.y;\n"
literal|"MUL R1.x, R0.z, c[0].z;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 1D;\n"
literal|"MUL R2.xyz, R1.w, R0;\n"
literal|"MAD R3.xyz, R1, R0.w, R2;\n"
literal|"MUL R2.xyz, R1, R0;\n"
literal|"MAD R2.xyz, -R2, c[8].x, R3;\n"
literal|"ADD R2.w, -R0, c[8].y;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8].y;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..6],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[6].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R2.xyz, R1, c[4].y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R3.xyz, R0.w, R2;\n"
literal|"MUL R2.xyz, R0, c[4].x;\n"
literal|"MAD R2.xyz, R1.w, R2, R3;\n"
literal|"ADD R2.w, -R1, c[7].x;\n"
literal|"MUL R0.xyz, R0, c[5].y;\n"
literal|"MAD R0.xyz, R2.w, R0, R2;\n"
literal|"ADD R2.x, -R0.w, c[7];\n"
literal|"MUL R1.xyz, R1, c[5].z;\n"
literal|"MAD result.color.xyz, R2.x, R1, R0;\n"
literal|"MUL R0.x, R0.w, R1.w;\n"
literal|"MUL R0.z, R1.w, R2.x;\n"
literal|"MUL R0.y, R0.w, R2.w;\n"
literal|"DP3 result.color.w, R0, c[5];\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_MULTIPLY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_MULTIPLY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"ADD R2.x, -R1.w, c[5];\n"
literal|"MUL R2.xyz, R0, R2.x;\n"
literal|"MAD R0.xyz, R0, R1, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[5].x;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SCREEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SCREEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..4] };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"ADD R2, R0, R1;\n"
literal|"MAD result.color, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_OVERLAY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_OVERLAY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[5].y;\n"
literal|"MUL R2.xyz, R2, c[5].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R3.xyz, R0, R2.w;\n"
literal|"MUL R0.xyz, R0, R1;\n"
literal|"ADD R2.w, -R0, c[5].y;\n"
literal|"MAD R0.xyz, R0, c[5].x, R3;\n"
literal|"MAD R0.xyz, R1, R2.w, R0;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MUL R1.xyz, R1, c[5].x;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R2.xyz, R2, -R0;\n"
literal|"SGE R1.xyz, R1, R1.w;\n"
literal|"MAD result.color.xyz, R1, R2, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DARKEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DARKEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[5].x;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_LIGHTEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_LIGHTEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[5].x;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORDODGE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORDODGE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MAX R1.x, R0.w, c[5].y;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MAD R3.xyz, -R0, R1.x, c[5].x;\n"
literal|"MAX R3.xyz, R3, c[5].y;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.x, -R0.w, c[5];\n"
literal|"MUL R2.xyz, R1, R2.x;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R1.xyz, R0.w, R1;\n"
literal|"MAD R0.xyz, R0, R1.w, R1;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"RCP R3.x, R3.x;\n"
literal|"RCP R3.y, R3.y;\n"
literal|"RCP R3.z, R3.z;\n"
literal|"MAD R3.xyz, R1, R3, R2;\n"
literal|"MAD R2.xyz, R0.w, R1.w, R2;\n"
literal|"ADD R1.x, R0.w, R1.w;\n"
literal|"ADD R2.xyz, R2, -R3;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"MAD result.color.xyz, R0, R2, R3;\n"
literal|"MAD result.color.w, -R0, R1, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORBURN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORBURN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R2.xyz, -R0.w, R1.w, R3;\n"
literal|"MUL R4.xyz, R0.w, R2;\n"
literal|"MAX R2.xyz, R0, c[5].y;\n"
literal|"MUL R5.xyz, R0, R2.w;\n"
literal|"ADD R3.w, -R0, c[5].x;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R1, R3.w;\n"
literal|"MAD R1.xyz, R1, R3.w, R2;\n"
literal|"MAD R0.xyz, R0, R2.w, R4;\n"
literal|"MUL R2.x, R0.w, R1.w;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R1.xyz, R1, -R0;\n"
literal|"SGE R2.xyz, R3, R2.x;\n"
literal|"MAD result.color.xyz, R2, R1, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_HARDLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_HARDLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[5].y;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[5].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"MUL R0.xyz, R0, c[5].x;\n"
literal|"ADD R2.w, -R0, c[5].y;\n"
literal|"MAD R3.xyz, R3, c[5].x, R4;\n"
literal|"MAD R3.xyz, R1, R2.w, R3;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R1.xyz, R1, -R3;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD result.color.xyz, R0, R1, R3;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SOFTLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SOFTLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..4],\n"
literal|"		{ 1, 2, 9.9999997e-006, 4 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MAX R0.z, R1.w, c[5];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R3.xyz, R1, R0.z;\n"
literal|"MAD R2.xyz, R3, c[6].x, -c[6].y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MAD R4.xyz, R3, R2, c[6].z;\n"
literal|"MAD R2.xyz, R0, c[5].y, -R0.w;\n"
literal|"MUL R5.xyz, R1.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[5].x;\n"
literal|"MAD R2.xyz, R2, R3, R0.w;\n"
literal|"MUL R3.xyz, R0, c[5].y;\n"
literal|"MAD R5.xyz, R0.w, R1, R6;\n"
literal|"MAD R4.xyz, R0.w, R1, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R1, c[5].w;\n"
literal|"SGE R4.xyz, R4, R1.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R1, R2, R4;\n"
literal|"MUL R2.xyz, R1, R2;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R0.x, R0.w, R1.w;\n"
literal|"ADD R0.y, -R0.w, c[5].x;\n"
literal|"MAD result.color.xyz, R1, R0.y, R2;\n"
literal|"MAD result.color.w, -R0, R1, R0.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DIFFERENCE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DIFFERENCE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"ADD R0.xyz, R0, R1;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R1.x, R0.w, R1.w;\n"
literal|"MAD result.color.xyz, -R2, c[5].x, R0;\n"
literal|"MAD result.color.w, -R0, R1, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_EXCLUSION_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_EXCLUSION_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX R0, R0, texture[1], 1D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"MUL R2.xyz, R0, R1;\n"
literal|"MAD R2.xyz, -R2, c[5].x, R3;\n"
literal|"ADD R2.w, -R1, c[5].y;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[5];\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODE_BLEND_MODE_MASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODE_BLEND_MODE_MASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..6] };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.z;\n"
literal|"MUL R0.zw, R0, c[0].xyxy;\n"
literal|"ADD R1.x, R0.z, R0.w;\n"
literal|"ADD R0.xy, fragment.position, c[5];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"DP4 R1.y, R0, c[6];\n"
literal|"MUL R1.x, R1, c[0].z;\n"
literal|"TEX R0, R1, texture[1], 1D;\n"
literal|"MUL result.color, R0, R1.y;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODE_BLEND_MODE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODE_BLEND_MODE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[4] = { program.local[0..3] };\n"
literal|"TEMP R0;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"ADD R0.x, R0, R0.y;\n"
literal|"MUL R0.x, R0, c[0].z;\n"
literal|"TEX result.color, R0, texture[0], 1D;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..9],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R1.xyz, R0, c[3];\n"
literal|"RCP R0.z, R1.z;\n"
literal|"MUL R1.xy, R1, R0.z;\n"
literal|"MUL R0.xy, fragment.position, c[7];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[2], 2D;\n"
literal|"MUL R2.xyz, R0, c[4].y;\n"
literal|"MUL R3.xyz, R1.w, R2;\n"
literal|"MUL R2.xyz, R1, c[4].x;\n"
literal|"MAD R2.xyz, R0.w, R2, R3;\n"
literal|"ADD R3.xy, fragment.position, c[8];\n"
literal|"ADD R2.w, -R0, c[10].x;\n"
literal|"MUL R1.xyz, R1, c[5].y;\n"
literal|"MAD R2.xyz, R2.w, R1, R2;\n"
literal|"MUL R1.xyz, R0, c[5].z;\n"
literal|"ADD R3.z, -R1.w, c[10].x;\n"
literal|"MAD R2.xyz, R3.z, R1, R2;\n"
literal|"MUL R1.y, R1.w, R2.w;\n"
literal|"MUL R1.x, R1.w, R0.w;\n"
literal|"MUL R1.z, R0.w, R3;\n"
literal|"DP3 R2.w, R1, c[5];\n"
literal|"MUL R3.xy, R3, c[6];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[9];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_MULTIPLY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_MULTIPLY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R1.xyz, R0, c[3];\n"
literal|"RCP R0.z, R1.z;\n"
literal|"MUL R1.xy, R1, R0.z;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1, R1, texture[2], 2D;\n"
literal|"ADD R2.x, -R0.w, c[8];\n"
literal|"MUL R2.xyz, R1, R2.x;\n"
literal|"MAD R1.xyz, R1, R0, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SCREEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SCREEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..7] };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, c[0].xyxy;\n"
literal|"ADD R3.xy, fragment.position, c[6];\n"
literal|"TEX R1, R0.zwzw, texture[2], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R2, R1, R0;\n"
literal|"MAD R2, -R1, R0, R2;\n"
literal|"MUL R3.xy, R3, c[4];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_OVERLAY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_OVERLAY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[2], 2D;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[8].y;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[8].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, -R0.w, c[8].y;\n"
literal|"MAD R3.xyz, R3, c[8].x, R4;\n"
literal|"MAD R3.xyz, R1, R2.x, R3;\n"
literal|"MAD R0.xyz, R1, R2.x, R0;\n"
literal|"MUL R2.xyz, R1, c[8].x;\n"
literal|"ADD R0.xyz, R0, -R3;\n"
literal|"SGE R2.xyz, R2, R1.w;\n"
literal|"MAD R2.xyz, R2, R0, R3;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DARKEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DARKEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.z;\n"
literal|"MUL R1.xy, R0.zwzw, c[0];\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 2D;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_LIGHTEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_LIGHTEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.z;\n"
literal|"MUL R1.xy, R0.zwzw, c[0];\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 2D;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORDODGE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORDODGE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[2], 2D;\n"
literal|"MAX R1.x, R0.w, c[8].y;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MAD R2.xyz, -R0, R1.x, c[8].x;\n"
literal|"MAX R2.xyz, R2, c[8].y;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MUL R3.xyz, R1, R2.w;\n"
literal|"ADD R2.w, -R1, c[8].x;\n"
literal|"MAD R4.xyz, R0, R2.w, R3;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"MAD R0.xyz, R0, R1.w, R3;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R3, R2, R4;\n"
literal|"MAD R4.xyz, R0.w, R1.w, R4;\n"
literal|"ADD R4.xyz, R4, -R2;\n"
literal|"MAD R2.xyz, R0, R4, R2;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORBURN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORBURN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[2], 2D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"MAD R2.xyz, -R0.w, R1.w, R3;\n"
literal|"MUL R4.xyz, R0.w, R2;\n"
literal|"MAX R2.xyz, R0, c[8].y;\n"
literal|"ADD R2.w, -R1, c[8].x;\n"
literal|"MUL R5.xyz, R0, R2.w;\n"
literal|"ADD R3.w, -R0, c[8].x;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R1, R3.w;\n"
literal|"MAD R0.xyz, R0, R2.w, R4;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"MAD R2.xyz, R1, R3.w, R2;\n"
literal|"ADD R2.xyz, R2, -R0;\n"
literal|"SGE R3.xyz, R3, R2.w;\n"
literal|"MAD R2.xyz, R3, R2, R0;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_HARDLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_HARDLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[2], 2D;\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[8].y;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[8].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"ADD R2.w, -R0, c[8].y;\n"
literal|"MAD R3.xyz, R3, c[8].x, R4;\n"
literal|"MUL R0.xyz, R0, c[8].x;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD R3.xyz, R1, R2.w, R3;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.xyz, R2, -R3;\n"
literal|"MAD R2.xyz, R0, R2, R3;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SOFTLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SOFTLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..7],\n"
literal|"		{ 1, 2, 9.9999997e-006, 4 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MUL R1.xy, fragment.position, c[5];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MAX R0.w, R1, c[8].z;\n"
literal|"RCP R0.w, R0.w;\n"
literal|"MUL R3.xyz, R1, R0.w;\n"
literal|"MAD R2.xyz, R3, c[9].x, -c[9].y;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[2], 2D;\n"
literal|"MAD R4.xyz, R3, R2, c[9].z;\n"
literal|"MAD R2.xyz, R0, c[8].y, -R0.w;\n"
literal|"MUL R5.xyz, R1.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[8].x;\n"
literal|"MAD R2.xyz, R2, R3, R0.w;\n"
literal|"MUL R3.xyz, R0, c[8].y;\n"
literal|"MAD R5.xyz, R0.w, R1, R6;\n"
literal|"MAD R4.xyz, R0.w, R1, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R1, c[8].w;\n"
literal|"SGE R4.xyz, R4, R1.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R1, R2, R4;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MUL R2.xyz, R1, R2;\n"
literal|"ADD R2.w, -R1, c[8].x;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R0.x, -R0.w, c[8];\n"
literal|"MAD R2.xyz, R1, R0.x, R2;\n"
literal|"ADD R0.z, R0.w, R1.w;\n"
literal|"MAD R2.w, -R0, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[6];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R2, -R1;\n"
literal|"DP4 R0.x, R0, c[7];\n"
literal|"MAD result.color, R0.x, R2, R1;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DIFFERENCE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DIFFERENCE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.z;\n"
literal|"MUL R1.xy, R0.zwzw, c[0];\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 2D;\n"
literal|"ADD R2.xyz, R1, R0;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R1.xyz, R1, R0.w;\n"
literal|"MIN R1.xyz, R1, R3;\n"
literal|"MAD R2.xyz, -R1, c[8].x, R2;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_EXCLUSION
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_EXCLUSION
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.z;\n"
literal|"MUL R1.xy, R0.zwzw, c[0];\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"TEX R1, R1, texture[2], 2D;\n"
literal|"MUL R2.xyz, R1.w, R0;\n"
literal|"MAD R3.xyz, R1, R0.w, R2;\n"
literal|"MUL R2.xyz, R1, R0;\n"
literal|"MAD R2.xyz, -R2, c[8].x, R3;\n"
literal|"ADD R2.w, -R0, c[8].y;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8].y;\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..6],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R1.xy, fragment.position, c[6];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MUL R2.xyz, R1, c[4].y;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MUL R3.xyz, R0.w, R2;\n"
literal|"MUL R2.xyz, R0, c[4].x;\n"
literal|"MAD R2.xyz, R1.w, R2, R3;\n"
literal|"ADD R2.w, -R1, c[7].x;\n"
literal|"MUL R0.xyz, R0, c[5].y;\n"
literal|"MAD R0.xyz, R2.w, R0, R2;\n"
literal|"ADD R2.x, -R0.w, c[7];\n"
literal|"MUL R1.xyz, R1, c[5].z;\n"
literal|"MAD result.color.xyz, R2.x, R1, R0;\n"
literal|"MUL R0.x, R0.w, R1.w;\n"
literal|"MUL R0.z, R1.w, R2.x;\n"
literal|"MUL R0.y, R0.w, R2.w;\n"
literal|"DP3 result.color.w, R0, c[5];\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_MULTIPLY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_MULTIPLY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2.x, -R1.w, c[5];\n"
literal|"MUL R2.xyz, R0, R2.x;\n"
literal|"MAD R0.xyz, R0, R1, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[5].x;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SCREEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SCREEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..4] };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"ADD R2, R0, R1;\n"
literal|"MAD result.color, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_OVERLAY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_OVERLAY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[5].y;\n"
literal|"MUL R2.xyz, R2, c[5].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R3.xyz, R0, R2.w;\n"
literal|"MUL R0.xyz, R0, R1;\n"
literal|"ADD R2.w, -R0, c[5].y;\n"
literal|"MAD R0.xyz, R0, c[5].x, R3;\n"
literal|"MAD R0.xyz, R1, R2.w, R0;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MUL R1.xyz, R1, c[5].x;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R2.xyz, R2, -R0;\n"
literal|"SGE R1.xyz, R1, R1.w;\n"
literal|"MAD result.color.xyz, R1, R2, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DARKEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DARKEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[5].x;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_LIGHTEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_LIGHTEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[5].x;\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORDODGE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORDODGE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MAX R1.x, R0.w, c[5].y;\n"
literal|"RCP R1.x, R1.x;\n"
literal|"MAD R3.xyz, -R0, R1.x, c[5].x;\n"
literal|"MAX R3.xyz, R3, c[5].y;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.x, -R0.w, c[5];\n"
literal|"MUL R2.xyz, R1, R2.x;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R1.xyz, R0.w, R1;\n"
literal|"MAD R0.xyz, R0, R1.w, R1;\n"
literal|"MUL R2.w, R0, R1;\n"
literal|"RCP R3.x, R3.x;\n"
literal|"RCP R3.y, R3.y;\n"
literal|"RCP R3.z, R3.z;\n"
literal|"MAD R3.xyz, R1, R3, R2;\n"
literal|"MAD R2.xyz, R0.w, R1.w, R2;\n"
literal|"ADD R1.x, R0.w, R1.w;\n"
literal|"ADD R2.xyz, R2, -R3;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"MAD result.color.xyz, R0, R2, R3;\n"
literal|"MAD result.color.w, -R0, R1, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORBURN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORBURN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R2.xyz, -R0.w, R1.w, R3;\n"
literal|"MUL R4.xyz, R0.w, R2;\n"
literal|"MAX R2.xyz, R0, c[5].y;\n"
literal|"MUL R5.xyz, R0, R2.w;\n"
literal|"ADD R3.w, -R0, c[5].x;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R1, R3.w;\n"
literal|"MAD R1.xyz, R1, R3.w, R2;\n"
literal|"MAD R0.xyz, R0, R2.w, R4;\n"
literal|"MUL R2.x, R0.w, R1.w;\n"
literal|"ADD R2.w, R0, R1;\n"
literal|"ADD R1.xyz, R1, -R0;\n"
literal|"SGE R2.xyz, R3, R2.x;\n"
literal|"MAD result.color.xyz, R2, R1, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_HARDLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_HARDLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[5].y;\n"
literal|"ADD R3.xyz, R0.w, -R0;\n"
literal|"ADD R2.xyz, R1.w, -R1;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[5].x;\n"
literal|"MAD R2.xyz, R0.w, R1.w, -R2;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R4.xyz, R0, R2.w;\n"
literal|"MUL R3.xyz, R0, R1;\n"
literal|"MUL R0.xyz, R0, c[5].x;\n"
literal|"ADD R2.w, -R0, c[5].y;\n"
literal|"MAD R3.xyz, R3, c[5].x, R4;\n"
literal|"MAD R3.xyz, R1, R2.w, R3;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R1.xyz, R1, -R3;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD result.color.xyz, R0, R1, R3;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SOFTLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SOFTLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..4],\n"
literal|"		{ 1, 2, 9.9999997e-006, 4 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MUL R1.xy, fragment.position, c[4];\n"
literal|"TEX R1, R1, texture[0], 2D;\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MAX R0.w, R1, c[5].z;\n"
literal|"RCP R0.w, R0.w;\n"
literal|"MUL R3.xyz, R1, R0.w;\n"
literal|"MAD R2.xyz, R3, c[6].x, -c[6].y;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MAD R4.xyz, R3, R2, c[6].z;\n"
literal|"MAD R2.xyz, R0, c[5].y, -R0.w;\n"
literal|"MUL R5.xyz, R1.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[5].x;\n"
literal|"MAD R2.xyz, R2, R3, R0.w;\n"
literal|"MUL R3.xyz, R0, c[5].y;\n"
literal|"MAD R5.xyz, R0.w, R1, R6;\n"
literal|"MAD R4.xyz, R0.w, R1, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R1, c[5].w;\n"
literal|"SGE R4.xyz, R4, R1.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R1, R2, R4;\n"
literal|"MUL R2.xyz, R1, R2;\n"
literal|"SGE R3.xyz, R3, R0.w;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R0.x, R0.w, R1.w;\n"
literal|"ADD R0.y, -R0.w, c[5].x;\n"
literal|"MAD result.color.xyz, R1, R0.y, R2;\n"
literal|"MAD result.color.w, -R0, R1, R0.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DIFFERENCE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DIFFERENCE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MUL R2.xyz, R0, R1.w;\n"
literal|"MUL R3.xyz, R0.w, R1;\n"
literal|"ADD R0.xyz, R0, R1;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R1.x, R0.w, R1.w;\n"
literal|"MAD result.color.xyz, -R2, c[5].x, R0;\n"
literal|"MAD result.color.w, -R0, R1, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_EXCLUSION_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_EXCLUSION_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 2, 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R1, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0, R0, texture[1], 2D;\n"
literal|"MUL R2.xyz, R0.w, R1;\n"
literal|"MAD R3.xyz, R0, R1.w, R2;\n"
literal|"MUL R2.xyz, R0, R1;\n"
literal|"MAD R2.xyz, -R2, c[5].x, R3;\n"
literal|"ADD R2.w, -R1, c[5].y;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R0.w, R1.w;\n"
literal|"ADD R2.y, -R0.w, c[5];\n"
literal|"MAD result.color.xyz, R1, R2.y, R0;\n"
literal|"MAD result.color.w, -R0, R1, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODE_BLEND_MODE_MASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODE_BLEND_MODE_MASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..6] };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R1.xyz, R0, c[3];\n"
literal|"RCP R0.z, R1.z;\n"
literal|"MUL R1.xy, R1, R0.z;\n"
literal|"ADD R0.xy, fragment.position, c[5];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"DP4 R1.z, R0, c[6];\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R0, R1, texture[1], 2D;\n"
literal|"MUL result.color, R0, R1.z;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODE_BLEND_MODE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODE_BLEND_MODE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[4] = { program.local[0..3] };\n"
literal|"TEMP R0;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX result.color, R0, texture[0], 2D;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[11] = { program.local[0..9],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, c[0].xyxy;\n"
literal|"TEX R1.x, R0.zwzw, texture[2], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[7];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -R1, c[10];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R2.xyz, R0, c[4].y;\n"
literal|"MUL R3.xyz, R1.w, R2;\n"
literal|"MUL R2.xyz, R1, c[4].x;\n"
literal|"MAD R2.xyz, R0.w, R2, R3;\n"
literal|"ADD R3.xy, fragment.position, c[8];\n"
literal|"ADD R2.w, -R0, c[10].x;\n"
literal|"MUL R1.xyz, R1, c[5].y;\n"
literal|"MAD R2.xyz, R2.w, R1, R2;\n"
literal|"MUL R1.xyz, R0, c[5].z;\n"
literal|"ADD R3.z, -R1.w, c[10].x;\n"
literal|"MAD R2.xyz, R3.z, R1, R2;\n"
literal|"MUL R1.y, R1.w, R2.w;\n"
literal|"MUL R1.x, R1.w, R0.w;\n"
literal|"MUL R1.z, R0.w, R3;\n"
literal|"DP3 R2.w, R1, c[5];\n"
literal|"MUL R3.xy, R3, c[6];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[9];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_MULTIPLY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_MULTIPLY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, c[0].xyxy;\n"
literal|"TEX R1.x, R0.zwzw, texture[2], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -R1, c[8];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"ADD R2.x, -R0.w, c[8];\n"
literal|"MUL R2.xyz, R1, R2.x;\n"
literal|"MAD R1.xyz, R1, R0, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SCREEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SCREEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[2], 2D;\n"
literal|"ADD R0.z, -R0.x, c[8].x;\n"
literal|"ADD R3.xy, fragment.position, c[6];\n"
literal|"MUL R1, fragment.color.primary, R0.z;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R2, R1, R0;\n"
literal|"MAD R2, -R1, R0, R2;\n"
literal|"MUL R3.xy, R3, c[4];\n"
literal|"TEX R1, R3, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_OVERLAY
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_OVERLAY
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[2], 2D;\n"
literal|"ADD R0.x, -R0, c[8];\n"
literal|"MUL R1, fragment.color.primary, R0.x;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"ADD R3.xyz, R1.w, -R1;\n"
literal|"ADD R2.xyz, R0.w, -R0;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[8].y;\n"
literal|"MAD R2.xyz, R1.w, R0.w, -R2;\n"
literal|"MUL R4.xyz, R1, R2.w;\n"
literal|"MUL R3.xyz, R1, R0;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R3.xyz, R3, c[8].y, R4;\n"
literal|"MAD R3.xyz, R0, R2.x, R3;\n"
literal|"MAD R1.xyz, R0, R2.x, R1;\n"
literal|"MUL R2.xyz, R0, c[8].y;\n"
literal|"ADD R1.xyz, R1, -R3;\n"
literal|"SGE R2.xyz, R2, R0.w;\n"
literal|"MAD R2.xyz, R2, R1, R3;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DARKEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DARKEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R1.x, R0, texture[2], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -R1, c[8];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_LIGHTEN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_LIGHTEN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R1.x, R0, texture[2], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -R1, c[8];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORDODGE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORDODGE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[2], 2D;\n"
literal|"ADD R0.x, -R0, c[8];\n"
literal|"MUL R1, fragment.color.primary, R0.x;\n"
literal|"MAX R0.x, R1.w, c[8].y;\n"
literal|"RCP R0.x, R0.x;\n"
literal|"MAD R2.xyz, -R1, R0.x, c[8].x;\n"
literal|"MAX R2.xyz, R2, c[8].y;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R2.w, -R1, c[8].x;\n"
literal|"MUL R3.xyz, R0, R2.w;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R4.xyz, R1, R2.w, R3;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.w, R1, R0;\n"
literal|"MAD R1.xyz, R1, R0.w, R3;\n"
literal|"SGE R1.xyz, R1, R2.w;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R3, R2, R4;\n"
literal|"MAD R4.xyz, R1.w, R0.w, R4;\n"
literal|"ADD R4.xyz, R4, -R2;\n"
literal|"MAD R2.xyz, R1, R4, R2;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORBURN
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORBURN
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[2], 2D;\n"
literal|"ADD R1.x, -R0, c[8];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R2.xyz, R1.w, R0;\n"
literal|"MAD R3.xyz, R1, R0.w, R2;\n"
literal|"MAD R2.xyz, -R1.w, R0.w, R3;\n"
literal|"MUL R4.xyz, R1.w, R2;\n"
literal|"MAX R2.xyz, R1, c[8].y;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MUL R5.xyz, R1, R2.w;\n"
literal|"ADD R3.w, -R1, c[8].x;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R0, R3.w;\n"
literal|"MAD R1.xyz, R1, R2.w, R4;\n"
literal|"MUL R2.w, R1, R0;\n"
literal|"MAD R2.xyz, R0, R3.w, R2;\n"
literal|"ADD R2.xyz, R2, -R1;\n"
literal|"SGE R3.xyz, R3, R2.w;\n"
literal|"MAD R2.xyz, R3, R2, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_HARDLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_HARDLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[2], 2D;\n"
literal|"ADD R0.x, -R0, c[8];\n"
literal|"MUL R1, fragment.color.primary, R0.x;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[5].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"ADD R3.xyz, R1.w, -R1;\n"
literal|"ADD R2.xyz, R0.w, -R0;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[8].y;\n"
literal|"MAD R2.xyz, R1.w, R0.w, -R2;\n"
literal|"MUL R4.xyz, R1, R2.w;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MUL R3.xyz, R1, R0;\n"
literal|"ADD R2.w, -R1, c[8].x;\n"
literal|"MAD R3.xyz, R3, c[8].y, R4;\n"
literal|"MUL R1.xyz, R1, c[8].y;\n"
literal|"SGE R1.xyz, R1, R1.w;\n"
literal|"MAD R3.xyz, R0, R2.w, R3;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.xyz, R2, -R3;\n"
literal|"MAD R2.xyz, R1, R2, R3;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SOFTLIGHT
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SOFTLIGHT
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[10] = { program.local[0..7],\n"
literal|"		{ 1, 2, 9.9999997e-006, 4 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R1.xyz, R0, c[3];\n"
literal|"RCP R1.z, R1.z;\n"
literal|"MUL R1.xy, R1, R1.z;\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1.x, R1, texture[2], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MAX R1.z, R0.w, c[8];\n"
literal|"RCP R1.z, R1.z;\n"
literal|"MUL R3.xyz, R0, R1.z;\n"
literal|"MAD R2.xyz, R3, c[9].x, -c[9].y;\n"
literal|"ADD R1.x, -R1, c[8];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MAD R4.xyz, R3, R2, c[9].z;\n"
literal|"MAD R2.xyz, R1, c[8].y, -R1.w;\n"
literal|"MUL R5.xyz, R0.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[8].x;\n"
literal|"MAD R2.xyz, R2, R3, R1.w;\n"
literal|"MUL R3.xyz, R1, c[8].y;\n"
literal|"MAD R5.xyz, R1.w, R0, R6;\n"
literal|"MAD R4.xyz, R1.w, R0, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R0, c[8].w;\n"
literal|"SGE R4.xyz, R4, R0.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R0, R2, R4;\n"
literal|"SGE R3.xyz, R3, R1.w;\n"
literal|"MUL R2.xyz, R0, R2;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"ADD R1.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R1.x, R2;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DIFFERENCE
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DIFFERENCE
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R1.x, R0, texture[2], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"ADD R1.x, -R1, c[8];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"ADD R2.xyz, R1, R0;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R1.xyz, R1, R0.w;\n"
literal|"MIN R1.xyz, R1, R3;\n"
literal|"MAD R2.xyz, -R1, c[8].y, R2;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_EXCLUSION
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_EXCLUSION
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[9] = { program.local[0..7],\n"
literal|"		{ 1, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R1.x, R0, texture[2], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[5];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R1.x, -R1, c[8];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R2.xyz, R1.w, R0;\n"
literal|"MAD R3.xyz, R1, R0.w, R2;\n"
literal|"MUL R2.xyz, R1, R0;\n"
literal|"MAD R2.xyz, -R2, c[8].y, R3;\n"
literal|"ADD R2.w, -R0, c[8].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, -R1.w, c[8];\n"
literal|"MAD R2.xyz, R0, R2.x, R1;\n"
literal|"ADD R1.z, R1.w, R0.w;\n"
literal|"MAD R2.w, -R1, R0, R1.z;\n"
literal|"ADD R1.xy, fragment.position, c[6];\n"
literal|"MUL R1.xy, R1, c[4];\n"
literal|"TEX R1, R1, texture[1], 2D;\n"
literal|"ADD R2, R2, -R0;\n"
literal|"DP4 R1.x, R1, c[7];\n"
literal|"MAD result.color, R1.x, R2, R0;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..6],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R1.x, R0, texture[1], 2D;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[6].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R2.xyz, R0, c[4].y;\n"
literal|"ADD R1.x, -R1, c[7];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R3.xyz, R1.w, R2;\n"
literal|"MUL R2.xyz, R1, c[4].x;\n"
literal|"MUL R0.xyz, R0, c[5].z;\n"
literal|"MAD R2.xyz, R0.w, R2, R3;\n"
literal|"ADD R2.w, -R0, c[7].x;\n"
literal|"MUL R1.xyz, R1, c[5].y;\n"
literal|"MAD R1.xyz, R2.w, R1, R2;\n"
literal|"ADD R2.x, -R1.w, c[7];\n"
literal|"MAD result.color.xyz, R2.x, R0, R1;\n"
literal|"MUL R0.x, R1.w, R0.w;\n"
literal|"MUL R0.z, R0.w, R2.x;\n"
literal|"MUL R0.y, R1.w, R2.w;\n"
literal|"DP3 result.color.w, R0, c[5];\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_MULTIPLY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_MULTIPLY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R1.x, R0, texture[1], 2D;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R1.x, -R1, c[5];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"ADD R2.x, -R0.w, c[5];\n"
literal|"MUL R2.xyz, R1, R2.x;\n"
literal|"MAD R1.xyz, R1, R0, R2;\n"
literal|"ADD R2.x, R1.w, R0.w;\n"
literal|"ADD R2.y, -R1.w, c[5].x;\n"
literal|"MAD result.color.xyz, R0, R2.y, R1;\n"
literal|"MAD result.color.w, -R1, R0, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SCREEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SCREEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R1.x, -R0, c[5];\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"ADD R2, R1, R0;\n"
literal|"MAD result.color, -R1, R0, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_OVERLAY_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_OVERLAY_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R0.x, -R0, c[5];\n"
literal|"MUL R1, fragment.color.primary, R0.x;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R3.xyz, R1.w, -R1;\n"
literal|"ADD R2.xyz, R0.w, -R0;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[5].x;\n"
literal|"MUL R2.xyz, R2, c[5].y;\n"
literal|"MAD R2.xyz, R1.w, R0.w, -R2;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MUL R3.xyz, R1, R2.w;\n"
literal|"MUL R1.xyz, R1, R0;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R1.xyz, R1, c[5].y, R3;\n"
literal|"MAD R1.xyz, R0, R2.w, R1;\n"
literal|"MAD R2.xyz, R0, R2.w, R2;\n"
literal|"MUL R0.xyz, R0, c[5].y;\n"
literal|"ADD R2.w, R1, R0;\n"
literal|"ADD R2.xyz, R2, -R1;\n"
literal|"SGE R0.xyz, R0, R0.w;\n"
literal|"MAD result.color.xyz, R0, R2, R1;\n"
literal|"MAD result.color.w, -R1, R0, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DARKEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DARKEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R1.x, -R0, c[5];\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[5].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, R1.w, R0.w;\n"
literal|"ADD R2.y, -R1.w, c[5].x;\n"
literal|"MAD result.color.xyz, R0, R2.y, R1;\n"
literal|"MAD result.color.w, -R1, R0, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_LIGHTEN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_LIGHTEN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R1.x, -R0, c[5];\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MAX R2.xyz, R2, R3;\n"
literal|"ADD R2.w, -R0, c[5].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, R1.w, R0.w;\n"
literal|"ADD R2.y, -R1.w, c[5].x;\n"
literal|"MAD result.color.xyz, R0, R2.y, R1;\n"
literal|"MAD result.color.w, -R1, R0, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORDODGE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORDODGE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 1e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R0.x, -R0, c[5];\n"
literal|"MUL R1, fragment.color.primary, R0.x;\n"
literal|"MAX R0.x, R1.w, c[5].y;\n"
literal|"RCP R0.x, R0.x;\n"
literal|"MAD R3.xyz, -R1, R0.x, c[5].x;\n"
literal|"MAX R3.xyz, R3, c[5].y;\n"
literal|"MUL R0.xy, fragment.position, c[4];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"ADD R2.x, -R1.w, c[5];\n"
literal|"MUL R2.xyz, R0, R2.x;\n"
literal|"ADD R2.w, -R0, c[5].x;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MUL R0.xyz, R1.w, R0;\n"
literal|"RCP R3.x, R3.x;\n"
literal|"RCP R3.y, R3.y;\n"
literal|"RCP R3.z, R3.z;\n"
literal|"MAD R3.xyz, R0, R3, R2;\n"
literal|"MAD R0.xyz, R1, R0.w, R0;\n"
literal|"MAD R2.xyz, R1.w, R0.w, R2;\n"
literal|"MUL R2.w, R1, R0;\n"
literal|"ADD R1.x, R1.w, R0.w;\n"
literal|"ADD R2.xyz, R2, -R3;\n"
literal|"SGE R0.xyz, R0, R2.w;\n"
literal|"MAD result.color.xyz, R0, R2, R3;\n"
literal|"MAD result.color.w, -R1, R0, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORBURN_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORBURN_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 9.9999997e-006 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R1.x, -R0, c[5];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R2.xyz, R1.w, R0;\n"
literal|"MAD R3.xyz, R1, R0.w, R2;\n"
literal|"ADD R2.w, -R0, c[5].x;\n"
literal|"MAD R2.xyz, -R1.w, R0.w, R3;\n"
literal|"MUL R4.xyz, R1.w, R2;\n"
literal|"MAX R2.xyz, R1, c[5].y;\n"
literal|"MUL R5.xyz, R1, R2.w;\n"
literal|"ADD R3.w, -R1, c[5].x;\n"
literal|"RCP R2.x, R2.x;\n"
literal|"RCP R2.y, R2.y;\n"
literal|"RCP R2.z, R2.z;\n"
literal|"MAD R2.xyz, R4, R2, R5;\n"
literal|"MUL R4.xyz, R0, R3.w;\n"
literal|"MAD R0.xyz, R0, R3.w, R2;\n"
literal|"MAD R1.xyz, R1, R2.w, R4;\n"
literal|"MUL R2.x, R1.w, R0.w;\n"
literal|"ADD R2.w, R1, R0;\n"
literal|"ADD R0.xyz, R0, -R1;\n"
literal|"SGE R2.xyz, R3, R2.x;\n"
literal|"MAD result.color.xyz, R2, R0, R1;\n"
literal|"MAD result.color.w, -R1, R0, R2;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_HARDLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_HARDLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R0.x, -R0, c[5];\n"
literal|"MUL R1, fragment.color.primary, R0.x;\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"ADD R2.w, -R0, c[5].x;\n"
literal|"ADD R3.xyz, R1.w, -R1;\n"
literal|"ADD R2.xyz, R0.w, -R0;\n"
literal|"MUL R2.xyz, R2, R3;\n"
literal|"MUL R2.xyz, R2, c[5].y;\n"
literal|"MAD R2.xyz, R1.w, R0.w, -R2;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"MUL R4.xyz, R1, R2.w;\n"
literal|"MUL R3.xyz, R1, R0;\n"
literal|"MUL R1.xyz, R1, c[5].y;\n"
literal|"ADD R2.w, -R1, c[5].x;\n"
literal|"MAD R3.xyz, R3, c[5].y, R4;\n"
literal|"MAD R3.xyz, R0, R2.w, R3;\n"
literal|"MAD R0.xyz, R0, R2.w, R2;\n"
literal|"ADD R2.x, R1.w, R0.w;\n"
literal|"ADD R0.xyz, R0, -R3;\n"
literal|"SGE R1.xyz, R1, R1.w;\n"
literal|"MAD result.color.xyz, R1, R0, R3;\n"
literal|"MAD result.color.w, -R1, R0, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SOFTLIGHT_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SOFTLIGHT_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[7] = { program.local[0..4],\n"
literal|"		{ 1, 2, 9.9999997e-006, 4 },\n"
literal|"		{ 16, 12, 3 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"TEMP R4;\n"
literal|"TEMP R5;\n"
literal|"TEMP R6;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R1.xyz, R0, c[3];\n"
literal|"RCP R1.z, R1.z;\n"
literal|"MUL R1.xy, R1, R1.z;\n"
literal|"MUL R1.xy, R1, c[0];\n"
literal|"TEX R1.x, R1, texture[1], 2D;\n"
literal|"MUL R0.xy, fragment.position, c[4];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"MAX R1.z, R0.w, c[5];\n"
literal|"RCP R1.z, R1.z;\n"
literal|"MUL R3.xyz, R0, R1.z;\n"
literal|"MAD R2.xyz, R3, c[6].x, -c[6].y;\n"
literal|"ADD R1.x, -R1, c[5];\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MAD R4.xyz, R3, R2, c[6].z;\n"
literal|"MAD R2.xyz, R1, c[5].y, -R1.w;\n"
literal|"MUL R5.xyz, R0.w, R2;\n"
literal|"MUL R6.xyz, R5, R4;\n"
literal|"RSQ R2.w, R3.x;\n"
literal|"RCP R4.x, R2.w;\n"
literal|"RSQ R2.w, R3.y;\n"
literal|"RSQ R3.w, R3.z;\n"
literal|"RCP R4.y, R2.w;\n"
literal|"RCP R4.z, R3.w;\n"
literal|"ADD R4.xyz, -R3, R4;\n"
literal|"MUL R6.xyz, R3, R6;\n"
literal|"MUL R4.xyz, R5, R4;\n"
literal|"ADD R3.xyz, -R3, c[5].x;\n"
literal|"MAD R2.xyz, R2, R3, R1.w;\n"
literal|"MUL R3.xyz, R1, c[5].y;\n"
literal|"MAD R5.xyz, R1.w, R0, R6;\n"
literal|"MAD R4.xyz, R1.w, R0, R4;\n"
literal|"ADD R6.xyz, R4, -R5;\n"
literal|"MUL R4.xyz, R0, c[5].w;\n"
literal|"SGE R4.xyz, R4, R0.w;\n"
literal|"MAD R4.xyz, R4, R6, R5;\n"
literal|"MAD R4.xyz, -R0, R2, R4;\n"
literal|"MUL R2.xyz, R0, R2;\n"
literal|"SGE R3.xyz, R3, R1.w;\n"
literal|"MAD R2.xyz, R3, R4, R2;\n"
literal|"ADD R2.w, -R0, c[5].x;\n"
literal|"MAD R2.xyz, R1, R2.w, R2;\n"
literal|"ADD R1.x, R1.w, R0.w;\n"
literal|"ADD R1.y, -R1.w, c[5].x;\n"
literal|"MAD result.color.xyz, R0, R1.y, R2;\n"
literal|"MAD result.color.w, -R1, R0, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DIFFERENCE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DIFFERENCE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R1.x, -R0, c[5];\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R3.xyz, R1.w, R0;\n"
literal|"MUL R2.xyz, R1, R0.w;\n"
literal|"ADD R0.xyz, R1, R0;\n"
literal|"MIN R2.xyz, R2, R3;\n"
literal|"ADD R1.x, R1.w, R0.w;\n"
literal|"MAD result.color.xyz, -R2, c[5].y, R0;\n"
literal|"MAD result.color.w, -R1, R0, R1.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_EXCLUSION_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_EXCLUSION_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[6] = { program.local[0..4],\n"
literal|"		{ 1, 2 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"TEMP R2;\n"
literal|"TEMP R3;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[1], 2D;\n"
literal|"ADD R1.x, -R0, c[5];\n"
literal|"MUL R0.zw, fragment.position.xyxy, c[4].xyxy;\n"
literal|"TEX R0, R0.zwzw, texture[0], 2D;\n"
literal|"MUL R1, fragment.color.primary, R1.x;\n"
literal|"MUL R2.xyz, R1.w, R0;\n"
literal|"MAD R3.xyz, R1, R0.w, R2;\n"
literal|"MUL R2.xyz, R1, R0;\n"
literal|"MAD R2.xyz, -R2, c[5].y, R3;\n"
literal|"ADD R2.w, -R0, c[5].x;\n"
literal|"MAD R1.xyz, R1, R2.w, R2;\n"
literal|"ADD R2.x, R1.w, R0.w;\n"
literal|"ADD R2.y, -R1.w, c[5].x;\n"
literal|"MAD result.color.xyz, R0, R2.y, R1;\n"
literal|"MAD result.color.w, -R1, R0, R2.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODE_BLEND_MODE_MASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODE_BLEND_MODE_MASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[8] = { program.local[0..6],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"TEMP R1;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.zw, R0.xyxy, R0.z;\n"
literal|"MUL R0.zw, R0, c[0].xyxy;\n"
literal|"TEX R1.x, R0.zwzw, texture[1], 2D;\n"
literal|"ADD R0.xy, fragment.position, c[5];\n"
literal|"MUL R0.xy, R0, c[4];\n"
literal|"TEX R0, R0, texture[0], 2D;\n"
literal|"DP4 R1.y, R0, c[6];\n"
literal|"ADD R1.x, -R1, c[7];\n"
literal|"MUL R0, fragment.color.primary, R1.x;\n"
literal|"MUL result.color, R0, R1.y;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODE_BLEND_MODE_NOMASK
specifier|static
specifier|const
name|char
modifier|*
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODE_BLEND_MODE_NOMASK
init|=
literal|"!!ARBfp1.0\n"
literal|"PARAM c[5] = { program.local[0..3],\n"
literal|"		{ 1 } };\n"
literal|"TEMP R0;\n"
literal|"MUL R0.xyz, fragment.position.y, c[2];\n"
literal|"MAD R0.xyz, fragment.position.x, c[1], R0;\n"
literal|"ADD R0.xyz, R0, c[3];\n"
literal|"RCP R0.z, R0.z;\n"
literal|"MUL R0.xy, R0, R0.z;\n"
literal|"MUL R0.xy, R0, c[0];\n"
literal|"TEX R0.x, R0, texture[0], 2D;\n"
literal|"ADD R0.x, -R0, c[4];\n"
literal|"MUL result.color, fragment.color.primary, R0.x;\n"
literal|"END\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mask_fragment_program_sources
specifier|static
specifier|const
name|char
modifier|*
name|mask_fragment_program_sources
index|[
name|num_fragment_masks
index|]
init|=
block|{
name|FragmentProgram_FRAGMENT_PROGRAM_MASK_TRAPEZOID_AA
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_MASK_ELLIPSE_AA
block|, }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|painter_fragment_program_sources
specifier|static
specifier|const
name|char
modifier|*
name|painter_fragment_program_sources
index|[
name|num_fragment_brushes
index|]
index|[
name|num_fragment_composition_modes
index|]
init|=
block|{
block|{
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_MULTIPLY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SCREEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_OVERLAY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DARKEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_LIGHTEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORDODGE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORBURN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_HARDLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SOFTLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DIFFERENCE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_EXCLUSION
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_MULTIPLY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SCREEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_OVERLAY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DARKEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_LIGHTEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORDODGE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_COLORBURN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_HARDLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_SOFTLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_DIFFERENCE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODES_EXCLUSION_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODE_BLEND_MODE_MASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_SOLID_COMPOSITION_MODE_BLEND_MODE_NOMASK
block|,     }
block|,
block|{
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_MULTIPLY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SCREEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_OVERLAY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DARKEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_LIGHTEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORDODGE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORBURN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_HARDLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SOFTLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DIFFERENCE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_EXCLUSION
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_MULTIPLY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SCREEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_OVERLAY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DARKEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_LIGHTEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORDODGE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_COLORBURN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_HARDLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_SOFTLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_DIFFERENCE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODES_EXCLUSION_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODE_BLEND_MODE_MASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_RADIAL_COMPOSITION_MODE_BLEND_MODE_NOMASK
block|,     }
block|,
block|{
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_MULTIPLY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SCREEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_OVERLAY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DARKEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_LIGHTEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORDODGE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORBURN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_HARDLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SOFTLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DIFFERENCE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_EXCLUSION
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_MULTIPLY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SCREEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_OVERLAY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DARKEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_LIGHTEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORDODGE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_COLORBURN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_HARDLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_SOFTLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_DIFFERENCE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODES_EXCLUSION_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODE_BLEND_MODE_MASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_CONICAL_COMPOSITION_MODE_BLEND_MODE_NOMASK
block|,     }
block|,
block|{
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_MULTIPLY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SCREEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_OVERLAY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DARKEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_LIGHTEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORDODGE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORBURN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_HARDLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SOFTLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DIFFERENCE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_EXCLUSION
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_MULTIPLY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SCREEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_OVERLAY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DARKEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_LIGHTEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORDODGE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_COLORBURN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_HARDLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_SOFTLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_DIFFERENCE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODES_EXCLUSION_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODE_BLEND_MODE_MASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_LINEAR_COMPOSITION_MODE_BLEND_MODE_NOMASK
block|,     }
block|,
block|{
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_MULTIPLY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SCREEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_OVERLAY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DARKEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_LIGHTEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORDODGE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORBURN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_HARDLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SOFTLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DIFFERENCE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_EXCLUSION
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_MULTIPLY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SCREEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_OVERLAY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DARKEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_LIGHTEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORDODGE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_COLORBURN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_HARDLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_SOFTLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_DIFFERENCE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODES_EXCLUSION_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODE_BLEND_MODE_MASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_TEXTURE_COMPOSITION_MODE_BLEND_MODE_NOMASK
block|,     }
block|,
block|{
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SIMPLE_PORTER_DUFF
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_MULTIPLY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SCREEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_OVERLAY
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DARKEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_LIGHTEN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORDODGE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORBURN
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_HARDLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SOFTLIGHT
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DIFFERENCE
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_EXCLUSION
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SIMPLE_PORTER_DUFF_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_MULTIPLY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SCREEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_OVERLAY_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DARKEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_LIGHTEN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORDODGE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_COLORBURN_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_HARDLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_SOFTLIGHT_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_DIFFERENCE_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODES_EXCLUSION_NOMASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODE_BLEND_MODE_MASK
block|,
name|FragmentProgram_FRAGMENT_PROGRAM_BRUSH_PATTERN_COMPOSITION_MODE_BLEND_MODE_NOMASK
block|,     }
block|, }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|painter_variable_locations
specifier|static
name|int
name|painter_variable_locations
index|[
name|num_fragment_brushes
index|]
index|[
name|num_fragment_composition_modes
index|]
index|[
name|num_fragment_variables
index|]
init|=
block|{
block|{
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|3
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,     }
block|,
block|{
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|7
block|,
literal|4
block|,
literal|5
block|,
literal|10
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|8
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|9
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
literal|5
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|7
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|5
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|6
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|, }
block|,     }
block|,
block|{
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|6
block|,
literal|3
block|,
literal|4
block|,
literal|9
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|7
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|6
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|, }
block|,     }
block|,
block|{
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
literal|3
block|,
literal|4
block|,
literal|9
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|7
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|8
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|6
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|5
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,     }
block|,
block|{
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|6
block|,
literal|3
block|,
literal|4
block|,
literal|9
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|7
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|8
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|6
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,     }
block|,
block|{
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|6
block|,
literal|3
block|,
literal|4
block|,
literal|9
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|7
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|8
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|2
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|7
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|6
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|6
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|4
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|3
block|,
operator|-
literal|1
block|,
literal|6
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|5
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
literal|0
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|, }
block|,     }
block|, }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mask_variable_locations
specifier|static
name|int
name|mask_variable_locations
index|[
name|num_fragment_masks
index|]
index|[
name|num_fragment_variables
index|]
init|=
block|{
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|, }
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|3
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|, }
block|, }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
