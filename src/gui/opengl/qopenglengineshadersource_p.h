begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QOPENGL_ENGINE_SHADER_SOURCE_H
end_ifndef
begin_define
DECL|macro|QOPENGL_ENGINE_SHADER_SOURCE_H
define|#
directive|define
name|QOPENGL_ENGINE_SHADER_SOURCE_H
end_define
begin_include
include|#
directive|include
file|"qopenglengineshadermanager_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|qopenglslMainVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainVertexShader
init|=
literal|"\n\     void setPosition(); \n\     void main(void) \n\     { \n\         setPosition(); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainWithTexCoordsVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainWithTexCoordsVertexShader
init|=
literal|"\n\     attribute highp   vec2      textureCoordArray; \n\     varying   highp   vec2      textureCoords; \n\     void setPosition(); \n\     void main(void) \n\     { \n\         setPosition(); \n\         textureCoords = textureCoordArray; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainWithTexCoordsAndOpacityVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainWithTexCoordsAndOpacityVertexShader
init|=
literal|"\n\     attribute highp   vec2      textureCoordArray; \n\     attribute lowp    float     opacityArray; \n\     varying   highp   vec2      textureCoords; \n\     varying   lowp    float     opacity; \n\     void setPosition(); \n\     void main(void) \n\     { \n\         setPosition(); \n\         textureCoords = textureCoordArray; \n\         opacity = opacityArray; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// NOTE: We let GL do the perspective correction so texture lookups in the fragment
end_comment
begin_comment
comment|//       shader are also perspective corrected.
end_comment
begin_decl_stmt
DECL|variable|qopenglslPositionOnlyVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslPositionOnlyVertexShader
init|=
literal|"\n\     attribute highp   vec2      vertexCoordsArray; \n\     attribute highp   vec3      pmvMatrix1; \n\     attribute highp   vec3      pmvMatrix2; \n\     attribute highp   vec3      pmvMatrix3; \n\     void setPosition(void) \n\     { \n\         highp mat3 pmvMatrix = mat3(pmvMatrix1, pmvMatrix2, pmvMatrix3); \n\         vec3 transformedPos = pmvMatrix * vec3(vertexCoordsArray.xy, 1.0); \n\         gl_Position = vec4(transformedPos.xy, 0.0, transformedPos.z); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslComplexGeometryPositionOnlyVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslComplexGeometryPositionOnlyVertexShader
init|=
literal|"\n\     uniform highp mat3 matrix; \n\     attribute highp vec2 vertexCoordsArray; \n\     void setPosition(void) \n\     { \n\       gl_Position = vec4(matrix * vec3(vertexCoordsArray, 1), 1);\n\     } \n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslUntransformedPositionVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslUntransformedPositionVertexShader
init|=
literal|"\n\     attribute highp   vec4      vertexCoordsArray; \n\     void setPosition(void) \n\     { \n\         gl_Position = vertexCoordsArray; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Pattern Brush - This assumes the texture size is 8x8 and thus, the inverted size is 0.125
end_comment
begin_decl_stmt
DECL|variable|qopenglslPositionWithPatternBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslPositionWithPatternBrushVertexShader
init|=
literal|"\n\     attribute highp   vec2      vertexCoordsArray; \n\     attribute highp   vec3      pmvMatrix1; \n\     attribute highp   vec3      pmvMatrix2; \n\     attribute highp   vec3      pmvMatrix3; \n\     uniform   mediump vec2      halfViewportSize; \n\     uniform   highp   vec2      invertedTextureSize; \n\     uniform   highp   mat3      brushTransform; \n\     varying   highp   vec2      patternTexCoords; \n\     void setPosition(void) \n\     { \n\         highp mat3 pmvMatrix = mat3(pmvMatrix1, pmvMatrix2, pmvMatrix3); \n\         vec3 transformedPos = pmvMatrix * vec3(vertexCoordsArray.xy, 1.0); \n\         gl_Position.xy = transformedPos.xy / transformedPos.z; \n\         mediump vec2 viewportCoords = (gl_Position.xy + 1.0) * halfViewportSize; \n\         mediump vec3 hTexCoords = brushTransform * vec3(viewportCoords, 1.0); \n\         mediump float invertedHTexCoordsZ = 1.0 / hTexCoords.z; \n\         gl_Position = vec4(gl_Position.xy * invertedHTexCoordsZ, 0.0, invertedHTexCoordsZ); \n\         patternTexCoords.xy = (hTexCoords.xy * 0.125) * invertedHTexCoordsZ; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslAffinePositionWithPatternBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslAffinePositionWithPatternBrushVertexShader
init|=
name|qopenglslPositionWithPatternBrushVertexShader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslPatternBrushSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslPatternBrushSrcFragmentShader
init|=
literal|"\n\     uniform           sampler2D brushTexture; \n\     uniform   lowp    vec4      patternColor; \n\     varying   highp   vec2      patternTexCoords;\n\     lowp vec4 srcPixel() \n\     { \n\         return patternColor * (1.0 - texture2D(brushTexture, patternTexCoords).r); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Linear Gradient Brush
end_comment
begin_decl_stmt
DECL|variable|qopenglslPositionWithLinearGradientBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslPositionWithLinearGradientBrushVertexShader
init|=
literal|"\n\     attribute highp   vec2      vertexCoordsArray; \n\     attribute highp   vec3      pmvMatrix1; \n\     attribute highp   vec3      pmvMatrix2; \n\     attribute highp   vec3      pmvMatrix3; \n\     uniform   mediump vec2      halfViewportSize; \n\     uniform   highp   vec3      linearData; \n\     uniform   highp   mat3      brushTransform; \n\     varying   mediump float     index; \n\     void setPosition() \n\     { \n\         highp mat3 pmvMatrix = mat3(pmvMatrix1, pmvMatrix2, pmvMatrix3); \n\         vec3 transformedPos = pmvMatrix * vec3(vertexCoordsArray.xy, 1.0); \n\         gl_Position.xy = transformedPos.xy / transformedPos.z; \n\         mediump vec2 viewportCoords = (gl_Position.xy + 1.0) * halfViewportSize; \n\         mediump vec3 hTexCoords = brushTransform * vec3(viewportCoords, 1); \n\         mediump float invertedHTexCoordsZ = 1.0 / hTexCoords.z; \n\         gl_Position = vec4(gl_Position.xy * invertedHTexCoordsZ, 0.0, invertedHTexCoordsZ); \n\         index = (dot(linearData.xy, hTexCoords.xy) * linearData.z) * invertedHTexCoordsZ; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslAffinePositionWithLinearGradientBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslAffinePositionWithLinearGradientBrushVertexShader
init|=
name|qopenglslPositionWithLinearGradientBrushVertexShader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslLinearGradientBrushSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslLinearGradientBrushSrcFragmentShader
init|=
literal|"\n\     uniform           sampler2D brushTexture; \n\     varying   mediump float     index; \n\     lowp vec4 srcPixel() \n\     { \n\         mediump vec2 val = vec2(index, 0.5); \n\         return texture2D(brushTexture, val); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Conical Gradient Brush
end_comment
begin_decl_stmt
DECL|variable|qopenglslPositionWithConicalGradientBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslPositionWithConicalGradientBrushVertexShader
init|=
literal|"\n\     attribute highp   vec2      vertexCoordsArray; \n\     attribute highp   vec3      pmvMatrix1; \n\     attribute highp   vec3      pmvMatrix2; \n\     attribute highp   vec3      pmvMatrix3; \n\     uniform   mediump vec2      halfViewportSize; \n\     uniform   highp   mat3      brushTransform; \n\     varying   highp   vec2      A; \n\     void setPosition(void) \n\     { \n\         highp mat3 pmvMatrix = mat3(pmvMatrix1, pmvMatrix2, pmvMatrix3); \n\         vec3 transformedPos = pmvMatrix * vec3(vertexCoordsArray.xy, 1.0); \n\         gl_Position.xy = transformedPos.xy / transformedPos.z; \n\         mediump vec2  viewportCoords = (gl_Position.xy + 1.0) * halfViewportSize; \n\         mediump vec3 hTexCoords = brushTransform * vec3(viewportCoords, 1); \n\         mediump float invertedHTexCoordsZ = 1.0 / hTexCoords.z; \n\         gl_Position = vec4(gl_Position.xy * invertedHTexCoordsZ, 0.0, invertedHTexCoordsZ); \n\         A = hTexCoords.xy * invertedHTexCoordsZ; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslAffinePositionWithConicalGradientBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslAffinePositionWithConicalGradientBrushVertexShader
init|=
name|qopenglslPositionWithConicalGradientBrushVertexShader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslConicalGradientBrushSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslConicalGradientBrushSrcFragmentShader
init|=
literal|"\n\     #define INVERSE_2PI 0.1591549430918953358 \n\     uniform           sampler2D brushTexture; \n\     uniform   mediump float     angle; \n\     varying   highp   vec2      A; \n\     lowp vec4 srcPixel() \n\     { \n\         highp float t; \n\         if (abs(A.y) == abs(A.x)) \n\             t = (atan(-A.y + 0.002, A.x) + angle) * INVERSE_2PI; \n\         else \n\             t = (atan(-A.y, A.x) + angle) * INVERSE_2PI; \n\         return texture2D(brushTexture, vec2(t - floor(t), 0.5)); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Radial Gradient Brush
end_comment
begin_decl_stmt
DECL|variable|qopenglslPositionWithRadialGradientBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslPositionWithRadialGradientBrushVertexShader
init|=
literal|"\n\     attribute highp   vec2      vertexCoordsArray;\n\     attribute highp   vec3      pmvMatrix1; \n\     attribute highp   vec3      pmvMatrix2; \n\     attribute highp   vec3      pmvMatrix3; \n\     uniform   mediump vec2      halfViewportSize; \n\     uniform   highp   mat3      brushTransform; \n\     uniform   highp   vec2      fmp; \n\     uniform   highp   vec3      bradius; \n\     varying   highp   float     b; \n\     varying   highp   vec2      A; \n\     void setPosition(void) \n\     {\n\         highp mat3 pmvMatrix = mat3(pmvMatrix1, pmvMatrix2, pmvMatrix3); \n\         vec3 transformedPos = pmvMatrix * vec3(vertexCoordsArray.xy, 1.0); \n\         gl_Position.xy = transformedPos.xy / transformedPos.z; \n\         mediump vec2 viewportCoords = (gl_Position.xy + 1.0) * halfViewportSize; \n\         mediump vec3 hTexCoords = brushTransform * vec3(viewportCoords, 1); \n\         mediump float invertedHTexCoordsZ = 1.0 / hTexCoords.z; \n\         gl_Position = vec4(gl_Position.xy * invertedHTexCoordsZ, 0.0, invertedHTexCoordsZ); \n\         A = hTexCoords.xy * invertedHTexCoordsZ; \n\         b = bradius.x + 2.0 * dot(A, fmp); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslAffinePositionWithRadialGradientBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslAffinePositionWithRadialGradientBrushVertexShader
init|=
name|qopenglslPositionWithRadialGradientBrushVertexShader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslRadialGradientBrushSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslRadialGradientBrushSrcFragmentShader
init|=
literal|"\n\     uniform           sampler2D brushTexture; \n\     uniform   highp   float     fmp2_m_radius2; \n\     uniform   highp   float     inverse_2_fmp2_m_radius2; \n\     uniform   highp   float     sqrfr; \n\     varying   highp   float     b; \n\     varying   highp   vec2      A; \n\     uniform   highp   vec3      bradius; \n\     lowp vec4 srcPixel() \n\     { \n\         highp float c = sqrfr-dot(A, A); \n\         highp float det = b*b - 4.0*fmp2_m_radius2*c; \n\         lowp vec4 result = vec4(0.0); \n\         if (det>= 0.0) { \n\             highp float detSqrt = sqrt(det); \n\             highp float w = max((-b - detSqrt) * inverse_2_fmp2_m_radius2, (-b + detSqrt) * inverse_2_fmp2_m_radius2); \n\             if (bradius.y + w * bradius.z>= 0.0) \n\                 result = texture2D(brushTexture, vec2(w, 0.5)); \n\         } \n\         return result; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Texture Brush
end_comment
begin_decl_stmt
DECL|variable|qopenglslPositionWithTextureBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslPositionWithTextureBrushVertexShader
init|=
literal|"\n\     attribute highp   vec2      vertexCoordsArray; \n\     attribute highp   vec3      pmvMatrix1; \n\     attribute highp   vec3      pmvMatrix2; \n\     attribute highp   vec3      pmvMatrix3; \n\     uniform   mediump vec2      halfViewportSize; \n\     uniform   highp   vec2      invertedTextureSize; \n\     uniform   highp   mat3      brushTransform; \n\     varying   highp   vec2      brushTextureCoords; \n\     void setPosition(void) \n\     { \n\         highp mat3 pmvMatrix = mat3(pmvMatrix1, pmvMatrix2, pmvMatrix3); \n\         vec3 transformedPos = pmvMatrix * vec3(vertexCoordsArray.xy, 1.0); \n\         gl_Position.xy = transformedPos.xy / transformedPos.z; \n\         mediump vec2 viewportCoords = (gl_Position.xy + 1.0) * halfViewportSize; \n\         mediump vec3 hTexCoords = brushTransform * vec3(viewportCoords, 1); \n\         mediump float invertedHTexCoordsZ = 1.0 / hTexCoords.z; \n\         gl_Position = vec4(gl_Position.xy * invertedHTexCoordsZ, 0.0, invertedHTexCoordsZ); \n\         brushTextureCoords.xy = (hTexCoords.xy * invertedTextureSize) * gl_Position.w; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslAffinePositionWithTextureBrushVertexShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslAffinePositionWithTextureBrushVertexShader
init|=
name|qopenglslPositionWithTextureBrushVertexShader
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_comment
comment|// OpenGL ES does not support GL_REPEAT wrap modes for NPOT textures. So instead,
end_comment
begin_comment
comment|// we emulate GL_REPEAT by only taking the fractional part of the texture coords.
end_comment
begin_comment
comment|// TODO: Special case POT textures which don't need this emulation
end_comment
begin_decl_stmt
DECL|variable|qopenglslTextureBrushSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslTextureBrushSrcFragmentShader
init|=
literal|"\n\     varying highp   vec2      brushTextureCoords; \n\     uniform         sampler2D brushTexture; \n\     lowp vec4 srcPixel() { \n\         return texture2D(brushTexture, fract(brushTextureCoords)); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|qopenglslTextureBrushSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslTextureBrushSrcFragmentShader
init|=
literal|"\n\     varying   highp   vec2      brushTextureCoords; \n\     uniform           sampler2D brushTexture; \n\     lowp vec4 srcPixel() \n\     { \n\         return texture2D(brushTexture, brushTextureCoords); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|qopenglslTextureBrushSrcWithPatternFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslTextureBrushSrcWithPatternFragmentShader
init|=
literal|"\n\     varying   highp   vec2      brushTextureCoords; \n\     uniform   lowp    vec4      patternColor; \n\     uniform           sampler2D brushTexture; \n\     lowp vec4 srcPixel() \n\     { \n\         return patternColor * (1.0 - texture2D(brushTexture, brushTextureCoords).r); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Solid Fill Brush
end_comment
begin_decl_stmt
DECL|variable|qopenglslSolidBrushSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslSolidBrushSrcFragmentShader
init|=
literal|"\n\     uniform   lowp    vec4      fragmentColor; \n\     lowp vec4 srcPixel() \n\     { \n\         return fragmentColor; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslImageSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslImageSrcFragmentShader
init|=
literal|"\n\     varying   highp   vec2      textureCoords; \n\     uniform           sampler2D imageTexture; \n\     lowp vec4 srcPixel() \n\     { \n"
literal|"return texture2D(imageTexture, textureCoords); \n"
literal|"}\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslCustomSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslCustomSrcFragmentShader
init|=
literal|"\n\     varying   highp   vec2      textureCoords; \n\     uniform           sampler2D imageTexture; \n\     lowp vec4 srcPixel() \n\     { \n\         return customShader(imageTexture, textureCoords); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslImageSrcWithPatternFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslImageSrcWithPatternFragmentShader
init|=
literal|"\n\     varying   highp   vec2      textureCoords; \n\     uniform   lowp    vec4      patternColor; \n\     uniform           sampler2D imageTexture; \n\     lowp vec4 srcPixel() \n\     { \n\         return patternColor * (1.0 - texture2D(imageTexture, textureCoords).r); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslNonPremultipliedImageSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslNonPremultipliedImageSrcFragmentShader
init|=
literal|"\n\     varying   highp   vec2      textureCoords; \n\     uniform          sampler2D imageTexture; \n\     lowp vec4 srcPixel() \n\     { \n\         lowp vec4 sample = texture2D(imageTexture, textureCoords); \n\         sample.rgb = sample.rgb * sample.a; \n\         return sample; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslShockingPinkSrcFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslShockingPinkSrcFragmentShader
init|=
literal|"\n\     lowp vec4 srcPixel() \n\     { \n\         return vec4(0.98, 0.06, 0.75, 1.0); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader_ImageArrays
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader_ImageArrays
init|=
literal|"\n\     varying   lowp    float     opacity; \n\     lowp vec4 srcPixel(); \n\     void main() \n\     { \n\         gl_FragColor = srcPixel() * opacity; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader_CMO
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader_CMO
init|=
literal|"\n\     uniform   lowp    float     globalOpacity; \n\     lowp vec4 srcPixel(); \n\     lowp vec4 applyMask(lowp vec4); \n\     lowp vec4 compose(lowp vec4); \n\     void main() \n\     { \n\         gl_FragColor = applyMask(compose(srcPixel()*globalOpacity))); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader_CM
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader_CM
init|=
literal|"\n\     lowp vec4 srcPixel(); \n\     lowp vec4 applyMask(lowp vec4); \n\     lowp vec4 compose(lowp vec4); \n\     void main() \n\     { \n\         gl_FragColor = applyMask(compose(srcPixel())); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader_MO
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader_MO
init|=
literal|"\n\     uniform   lowp    float     globalOpacity; \n\     lowp vec4 srcPixel(); \n\     lowp vec4 applyMask(lowp vec4); \n\     void main() \n\     { \n\         gl_FragColor = applyMask(srcPixel()*globalOpacity); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader_M
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader_M
init|=
literal|"\n\     lowp vec4 srcPixel(); \n\     lowp vec4 applyMask(lowp vec4); \n\     void main() \n\     { \n\         gl_FragColor = applyMask(srcPixel()); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader_CO
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader_CO
init|=
literal|"\n\     uniform   lowp    float     globalOpacity; \n\     lowp vec4 srcPixel(); \n\     lowp vec4 compose(lowp vec4); \n\     void main() \n\     { \n\         gl_FragColor = compose(srcPixel()*globalOpacity); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader_C
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader_C
init|=
literal|"\n\     lowp vec4 srcPixel(); \n\     lowp vec4 compose(lowp vec4); \n\     void main() \n\     { \n\         gl_FragColor = compose(srcPixel()); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader_O
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader_O
init|=
literal|"\n\     uniform   lowp    float     globalOpacity; \n\     lowp vec4 srcPixel(); \n\     void main() \n\     { \n\         gl_FragColor = srcPixel()*globalOpacity; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMainFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMainFragmentShader
init|=
literal|"\n\     lowp vec4 srcPixel(); \n\     void main() \n\     { \n\         gl_FragColor = srcPixel(); \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslMaskFragmentShader
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslMaskFragmentShader
init|=
literal|"\n\     varying   highp   vec2      textureCoords;\n\     uniform           sampler2D maskTexture;\n\     lowp vec4 applyMask(lowp vec4 src) \n\     {\n\         lowp vec4 mask = texture2D(maskTexture, textureCoords); \n\         return src * mask.a; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// For source over with subpixel antialiasing, the final color is calculated per component as follows
end_comment
begin_comment
comment|// (.a is alpha component, .c is red, green or blue component):
end_comment
begin_comment
comment|// alpha = src.a * mask.c * opacity
end_comment
begin_comment
comment|// dest.c = dest.c * (1 - alpha) + src.c * alpha
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// In the first pass, calculate: dest.c = dest.c * (1 - alpha) with blend funcs: zero, 1 - source color
end_comment
begin_comment
comment|// In the second pass, calculate: dest.c = dest.c + src.c * alpha with blend funcs: one, one
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// If source is a solid color (src is constant), only the first pass is needed, with blend funcs: constant, 1 - source color
end_comment
begin_comment
comment|// For source composition with subpixel antialiasing, the final color is calculated per component as follows:
end_comment
begin_comment
comment|// alpha = src.a * mask.c * opacity
end_comment
begin_comment
comment|// dest.c = dest.c * (1 - mask.c) + src.c * alpha
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
DECL|variable|qopenglslRgbMaskFragmentShaderPass1
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslRgbMaskFragmentShaderPass1
init|=
literal|"\n\     varying   highp   vec2      textureCoords;\n\     uniform           sampler2D maskTexture;\n\     lowp vec4 applyMask(lowp vec4 src) \n\     { \n\         lowp vec4 mask = texture2D(maskTexture, textureCoords); \n\         return src.a * mask; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qopenglslRgbMaskFragmentShaderPass2
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qopenglslRgbMaskFragmentShaderPass2
init|=
literal|"\n\     varying   highp   vec2      textureCoords;\n\     uniform           sampler2D maskTexture;\n\     lowp vec4 applyMask(lowp vec4 src) \n\     { \n\         lowp vec4 mask = texture2D(maskTexture, textureCoords); \n\         return src * mask; \n\     }\n"
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*     Left to implement:         RgbMaskFragmentShader,         RgbMaskWithGammaFragmentShader,          MultiplyCompositionModeFragmentShader,         ScreenCompositionModeFragmentShader,         OverlayCompositionModeFragmentShader,         DarkenCompositionModeFragmentShader,         LightenCompositionModeFragmentShader,         ColorDodgeCompositionModeFragmentShader,         ColorBurnCompositionModeFragmentShader,         HardLightCompositionModeFragmentShader,         SoftLightCompositionModeFragmentShader,         DifferenceCompositionModeFragmentShader,         ExclusionCompositionModeFragmentShader, */
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// GLGC_SHADER_SOURCE_H
end_comment
end_unit
