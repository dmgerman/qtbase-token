begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2011 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/BuiltInFunctionEmulator.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/BuiltInFunctionEmulatorGLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Cache.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/SymbolTable.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/VersionGLSL.h"
end_include
begin_function
DECL|function|InitBuiltInFunctionEmulatorForGLSLWorkarounds
name|void
name|InitBuiltInFunctionEmulatorForGLSLWorkarounds
parameter_list|(
name|BuiltInFunctionEmulator
modifier|*
name|emu
parameter_list|,
name|sh
operator|::
name|GLenum
name|shaderType
parameter_list|)
block|{
comment|// we use macros here instead of function definitions to work around more GLSL
comment|// compiler bugs, in particular on NVIDIA hardware on Mac OSX. Macros are
comment|// problematic because if the argument has side-effects they will be repeatedly
comment|// evaluated. This is unlikely to show up in real shaders, but is something to
comment|// consider.
specifier|const
name|TType
modifier|*
name|float1
init|=
name|TCache
operator|::
name|getType
argument_list|(
name|EbtFloat
argument_list|)
decl_stmt|;
specifier|const
name|TType
modifier|*
name|float2
init|=
name|TCache
operator|::
name|getType
argument_list|(
name|EbtFloat
argument_list|,
literal|2
argument_list|)
decl_stmt|;
specifier|const
name|TType
modifier|*
name|float3
init|=
name|TCache
operator|::
name|getType
argument_list|(
name|EbtFloat
argument_list|,
literal|3
argument_list|)
decl_stmt|;
specifier|const
name|TType
modifier|*
name|float4
init|=
name|TCache
operator|::
name|getType
argument_list|(
name|EbtFloat
argument_list|,
literal|4
argument_list|)
decl_stmt|;
if|if
condition|(
name|shaderType
operator|==
name|GL_FRAGMENT_SHADER
condition|)
block|{
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpCos
argument_list|,
name|float1
argument_list|,
literal|"webgl_emu_precision float webgl_cos_emu(webgl_emu_precision float a) { return cos(a); }"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpCos
argument_list|,
name|float2
argument_list|,
literal|"webgl_emu_precision vec2 webgl_cos_emu(webgl_emu_precision vec2 a) { return cos(a); }"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpCos
argument_list|,
name|float3
argument_list|,
literal|"webgl_emu_precision vec3 webgl_cos_emu(webgl_emu_precision vec3 a) { return cos(a); }"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpCos
argument_list|,
name|float4
argument_list|,
literal|"webgl_emu_precision vec4 webgl_cos_emu(webgl_emu_precision vec4 a) { return cos(a); }"
argument_list|)
expr_stmt|;
block|}
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpDistance
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_distance_emu(x, y) ((x)>= (y) ? (x) - (y) : (y) - (x))"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpDot
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_dot_emu(x, y) ((x) * (y))"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpLength
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_length_emu(x) ((x)>= 0.0 ? (x) : -(x))"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpNormalize
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_normalize_emu(x) ((x) == 0.0 ? 0.0 : ((x)> 0.0 ? 1.0 : -1.0))"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpReflect
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_reflect_emu(I, N) ((I) - 2.0 * (N) * (I) * (N))"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Emulate built-in functions missing from GLSL 1.30 and higher
end_comment
begin_function
DECL|function|InitBuiltInFunctionEmulatorForGLSLMissingFunctions
name|void
name|InitBuiltInFunctionEmulatorForGLSLMissingFunctions
parameter_list|(
name|BuiltInFunctionEmulator
modifier|*
name|emu
parameter_list|,
name|sh
operator|::
name|GLenum
name|shaderType
parameter_list|,
name|int
name|targetGLSLVersion
parameter_list|)
block|{
comment|// Emulate packSnorm2x16, packHalf2x16, unpackSnorm2x16, and unpackHalf2x16 (GLSL 4.20)
comment|// by using floatBitsToInt, floatBitsToUint, intBitsToFloat, and uintBitsToFloat (GLSL 3.30).
if|if
condition|(
name|targetGLSLVersion
operator|>=
name|GLSL_VERSION_330
operator|&&
name|targetGLSLVersion
operator|<
name|GLSL_VERSION_420
condition|)
block|{
specifier|const
name|TType
modifier|*
name|float2
init|=
name|TCache
operator|::
name|getType
argument_list|(
name|EbtFloat
argument_list|,
literal|2
argument_list|)
decl_stmt|;
specifier|const
name|TType
modifier|*
name|uint1
init|=
name|TCache
operator|::
name|getType
argument_list|(
name|EbtUInt
argument_list|)
decl_stmt|;
comment|// clang-format off
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpPackSnorm2x16
argument_list|,
name|float2
argument_list|,
literal|"uint webgl_packSnorm2x16_emu(vec2 v)\n"
literal|"{\n"
literal|"    #if defined(GL_ARB_shading_language_packing)\n"
literal|"        return packSnorm2x16(v);\n"
literal|"    #else\n"
literal|"        int x = int(round(clamp(v.x, -1.0, 1.0) * 32767.0));\n"
literal|"        int y = int(round(clamp(v.y, -1.0, 1.0) * 32767.0));\n"
literal|"        return uint((y<< 16) | (x& 0xFFFF));\n"
literal|"    #endif\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpUnpackSnorm2x16
argument_list|,
name|uint1
argument_list|,
literal|"#if !defined(GL_ARB_shading_language_packing)\n"
literal|"    float webgl_fromSnorm(uint x)\n"
literal|"    {\n"
literal|"        int xi = (int(x)& 0x7FFF) - (int(x)& 0x8000);\n"
literal|"        return clamp(float(xi) / 32767.0, -1.0, 1.0);\n"
literal|"    }\n"
literal|"#endif\n"
literal|"\n"
literal|"vec2 webgl_unpackSnorm2x16_emu(uint u)\n"
literal|"{\n"
literal|"    #if defined(GL_ARB_shading_language_packing)\n"
literal|"        return unpackSnorm2x16(u);\n"
literal|"    #else\n"
literal|"        uint y = (u>> 16);\n"
literal|"        uint x = u;\n"
literal|"        return vec2(webgl_fromSnorm(x), webgl_fromSnorm(y));\n"
literal|"    #endif\n"
literal|"}\n"
argument_list|)
expr_stmt|;
comment|// Functions uint webgl_f32tof16(float val) and float webgl_f16tof32(uint val) are
comment|// based on the OpenGL redbook Appendix Session "Floating-Point Formats Used in OpenGL".
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpPackHalf2x16
argument_list|,
name|float2
argument_list|,
literal|"#if !defined(GL_ARB_shading_language_packing)\n"
literal|"    uint webgl_f32tof16(float val)\n"
literal|"    {\n"
literal|"        uint f32 = floatBitsToUint(val);\n"
literal|"        uint f16 = 0u;\n"
literal|"        uint sign = (f32>> 16)& 0x8000u;\n"
literal|"        int exponent = int((f32>> 23)& 0xFFu) - 127;\n"
literal|"        uint mantissa = f32& 0x007FFFFFu;\n"
literal|"        if (exponent == 128)\n"
literal|"        {\n"
literal|"            // Infinity or NaN\n"
literal|"            // NaN bits that are masked out by 0x3FF get discarded.\n"
literal|"            // This can turn some NaNs to infinity, but this is allowed by the spec.\n"
literal|"            f16 = sign | (0x1Fu<< 10);\n"
literal|"            f16 |= (mantissa& 0x3FFu);\n"
literal|"        }\n"
literal|"        else if (exponent> 15)\n"
literal|"        {\n"
literal|"            // Overflow - flush to Infinity\n"
literal|"            f16 = sign | (0x1Fu<< 10);\n"
literal|"        }\n"
literal|"        else if (exponent> -15)\n"
literal|"        {\n"
literal|"            // Representable value\n"
literal|"            exponent += 15;\n"
literal|"            mantissa>>= 13;\n"
literal|"            f16 = sign | uint(exponent<< 10) | mantissa;\n"
literal|"        }\n"
literal|"        else\n"
literal|"        {\n"
literal|"            f16 = sign;\n"
literal|"        }\n"
literal|"        return f16;\n"
literal|"    }\n"
literal|"#endif\n"
literal|"\n"
literal|"uint webgl_packHalf2x16_emu(vec2 v)\n"
literal|"{\n"
literal|"    #if defined(GL_ARB_shading_language_packing)\n"
literal|"        return packHalf2x16(v);\n"
literal|"    #else\n"
literal|"        uint x = webgl_f32tof16(v.x);\n"
literal|"        uint y = webgl_f32tof16(v.y);\n"
literal|"        return (y<< 16) | x;\n"
literal|"    #endif\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpUnpackHalf2x16
argument_list|,
name|uint1
argument_list|,
literal|"#if !defined(GL_ARB_shading_language_packing)\n"
literal|"    float webgl_f16tof32(uint val)\n"
literal|"    {\n"
literal|"        uint sign = (val& 0x8000u)<< 16;\n"
literal|"        int exponent = int((val& 0x7C00u)>> 10);\n"
literal|"        uint mantissa = val& 0x03FFu;\n"
literal|"        float f32 = 0.0;\n"
literal|"        if(exponent == 0)\n"
literal|"        {\n"
literal|"            if (mantissa != 0u)\n"
literal|"            {\n"
literal|"                const float scale = 1.0 / (1<< 24);\n"
literal|"                f32 = scale * mantissa;\n"
literal|"            }\n"
literal|"        }\n"
literal|"        else if (exponent == 31)\n"
literal|"        {\n"
literal|"            return uintBitsToFloat(sign | 0x7F800000u | mantissa);\n"
literal|"        }\n"
literal|"        else\n"
literal|"        {\n"
literal|"            exponent -= 15;\n"
literal|"            float scale;\n"
literal|"            if(exponent< 0)\n"
literal|"            {\n"
literal|"                scale = 1.0 / (1<< -exponent);\n"
literal|"            }\n"
literal|"            else\n"
literal|"            {\n"
literal|"                scale = 1<< exponent;\n"
literal|"            }\n"
literal|"            float decimal = 1.0 + float(mantissa) / float(1<< 10);\n"
literal|"            f32 = scale * decimal;\n"
literal|"        }\n"
literal|"\n"
literal|"        if (sign != 0u)\n"
literal|"        {\n"
literal|"            f32 = -f32;\n"
literal|"        }\n"
literal|"\n"
literal|"        return f32;\n"
literal|"    }\n"
literal|"#endif\n"
literal|"\n"
literal|"vec2 webgl_unpackHalf2x16_emu(uint u)\n"
literal|"{\n"
literal|"    #if defined(GL_ARB_shading_language_packing)\n"
literal|"        return unpackHalf2x16(u);\n"
literal|"    #else\n"
literal|"        uint y = (u>> 16);\n"
literal|"        uint x = u& 0xFFFFu;\n"
literal|"        return vec2(webgl_f16tof32(x), webgl_f16tof32(y));\n"
literal|"    #endif\n"
literal|"}\n"
argument_list|)
expr_stmt|;
comment|// clang-format on
block|}
block|}
end_function
end_unit
