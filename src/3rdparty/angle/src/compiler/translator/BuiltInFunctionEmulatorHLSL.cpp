begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/translator/BuiltInFunctionEmulatorHLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/SymbolTable.h"
end_include
begin_function
DECL|function|InitBuiltInFunctionEmulatorForHLSL
name|void
name|InitBuiltInFunctionEmulatorForHLSL
parameter_list|(
name|BuiltInFunctionEmulator
modifier|*
name|emu
parameter_list|)
block|{
name|TType
name|float1
argument_list|(
name|EbtFloat
argument_list|)
decl_stmt|;
name|TType
name|float2
argument_list|(
name|EbtFloat
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|TType
name|float3
argument_list|(
name|EbtFloat
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|TType
name|float4
argument_list|(
name|EbtFloat
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpMod
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"float webgl_mod_emu(float x, float y)\n"
literal|"{\n"
literal|"    return x - y * floor(x / y);\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpMod
argument_list|,
name|float2
argument_list|,
name|float2
argument_list|,
literal|"float2 webgl_mod_emu(float2 x, float2 y)\n"
literal|"{\n"
literal|"    return x - y * floor(x / y);\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpMod
argument_list|,
name|float2
argument_list|,
name|float1
argument_list|,
literal|"float2 webgl_mod_emu(float2 x, float y)\n"
literal|"{\n"
literal|"    return x - y * floor(x / y);\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpMod
argument_list|,
name|float3
argument_list|,
name|float3
argument_list|,
literal|"float3 webgl_mod_emu(float3 x, float3 y)\n"
literal|"{\n"
literal|"    return x - y * floor(x / y);\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpMod
argument_list|,
name|float3
argument_list|,
name|float1
argument_list|,
literal|"float3 webgl_mod_emu(float3 x, float y)\n"
literal|"{\n"
literal|"    return x - y * floor(x / y);\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpMod
argument_list|,
name|float4
argument_list|,
name|float4
argument_list|,
literal|"float4 webgl_mod_emu(float4 x, float4 y)\n"
literal|"{\n"
literal|"    return x - y * floor(x / y);\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpMod
argument_list|,
name|float4
argument_list|,
name|float1
argument_list|,
literal|"float4 webgl_mod_emu(float4 x, float y)\n"
literal|"{\n"
literal|"    return x - y * floor(x / y);\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpFaceForward
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"float webgl_faceforward_emu(float N, float I, float Nref)\n"
literal|"{\n"
literal|"    if(dot(Nref, I)>= 0)\n"
literal|"    {\n"
literal|"        return -N;\n"
literal|"    }\n"
literal|"    else\n"
literal|"    {\n"
literal|"        return N;\n"
literal|"    }\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpFaceForward
argument_list|,
name|float2
argument_list|,
name|float2
argument_list|,
name|float2
argument_list|,
literal|"float2 webgl_faceforward_emu(float2 N, float2 I, float2 Nref)\n"
literal|"{\n"
literal|"    if(dot(Nref, I)>= 0)\n"
literal|"    {\n"
literal|"        return -N;\n"
literal|"    }\n"
literal|"    else\n"
literal|"    {\n"
literal|"        return N;\n"
literal|"    }\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpFaceForward
argument_list|,
name|float3
argument_list|,
name|float3
argument_list|,
name|float3
argument_list|,
literal|"float3 webgl_faceforward_emu(float3 N, float3 I, float3 Nref)\n"
literal|"{\n"
literal|"    if(dot(Nref, I)>= 0)\n"
literal|"    {\n"
literal|"        return -N;\n"
literal|"    }\n"
literal|"    else\n"
literal|"    {\n"
literal|"        return N;\n"
literal|"    }\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpFaceForward
argument_list|,
name|float4
argument_list|,
name|float4
argument_list|,
name|float4
argument_list|,
literal|"float4 webgl_faceforward_emu(float4 N, float4 I, float4 Nref)\n"
literal|"{\n"
literal|"    if(dot(Nref, I)>= 0)\n"
literal|"    {\n"
literal|"        return -N;\n"
literal|"    }\n"
literal|"    else\n"
literal|"    {\n"
literal|"        return N;\n"
literal|"    }\n"
literal|"}\n"
literal|"\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAtan
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"float webgl_atan_emu(float y, float x)\n"
literal|"{\n"
literal|"    if(x == 0&& y == 0) x = 1;\n"
comment|// Avoid producing a NaN
literal|"    return atan2(y, x);\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAtan
argument_list|,
name|float2
argument_list|,
name|float2
argument_list|,
literal|"float2 webgl_atan_emu(float2 y, float2 x)\n"
literal|"{\n"
literal|"    if(x[0] == 0&& y[0] == 0) x[0] = 1;\n"
literal|"    if(x[1] == 0&& y[1] == 0) x[1] = 1;\n"
literal|"    return float2(atan2(y[0], x[0]), atan2(y[1], x[1]));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAtan
argument_list|,
name|float3
argument_list|,
name|float3
argument_list|,
literal|"float3 webgl_atan_emu(float3 y, float3 x)\n"
literal|"{\n"
literal|"    if(x[0] == 0&& y[0] == 0) x[0] = 1;\n"
literal|"    if(x[1] == 0&& y[1] == 0) x[1] = 1;\n"
literal|"    if(x[2] == 0&& y[2] == 0) x[2] = 1;\n"
literal|"    return float3(atan2(y[0], x[0]), atan2(y[1], x[1]), atan2(y[2], x[2]));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAtan
argument_list|,
name|float4
argument_list|,
name|float4
argument_list|,
literal|"float4 webgl_atan_emu(float4 y, float4 x)\n"
literal|"{\n"
literal|"    if(x[0] == 0&& y[0] == 0) x[0] = 1;\n"
literal|"    if(x[1] == 0&& y[1] == 0) x[1] = 1;\n"
literal|"    if(x[2] == 0&& y[2] == 0) x[2] = 1;\n"
literal|"    if(x[3] == 0&& y[3] == 0) x[3] = 1;\n"
literal|"    return float4(atan2(y[0], x[0]), atan2(y[1], x[1]), atan2(y[2], x[2]), atan2(y[3], x[3]));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAsinh
argument_list|,
name|float1
argument_list|,
literal|"float webgl_asinh_emu(in float x) {\n"
literal|"    return log(x + sqrt(pow(x, 2.0) + 1.0));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAsinh
argument_list|,
name|float2
argument_list|,
literal|"float2 webgl_asinh_emu(in float2 x) {\n"
literal|"    return log(x + sqrt(pow(x, 2.0) + 1.0));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAsinh
argument_list|,
name|float3
argument_list|,
literal|"float3 webgl_asinh_emu(in float3 x) {\n"
literal|"    return log(x + sqrt(pow(x, 2.0) + 1.0));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAsinh
argument_list|,
name|float4
argument_list|,
literal|"float4 webgl_asinh_emu(in float4 x) {\n"
literal|"    return log(x + sqrt(pow(x, 2.0) + 1.0));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAcosh
argument_list|,
name|float1
argument_list|,
literal|"float webgl_acosh_emu(in float x) {\n"
literal|"    return log(x + sqrt(x + 1.0) * sqrt(x - 1.0));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAcosh
argument_list|,
name|float2
argument_list|,
literal|"float2 webgl_acosh_emu(in float2 x) {\n"
literal|"    return log(x + sqrt(x + 1.0) * sqrt(x - 1.0));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAcosh
argument_list|,
name|float3
argument_list|,
literal|"float3 webgl_acosh_emu(in float3 x) {\n"
literal|"    return log(x + sqrt(x + 1.0) * sqrt(x - 1.0));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAcosh
argument_list|,
name|float4
argument_list|,
literal|"float4 webgl_acosh_emu(in float4 x) {\n"
literal|"    return log(x + sqrt(x + 1.0) * sqrt(x - 1.0));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAtanh
argument_list|,
name|float1
argument_list|,
literal|"float webgl_atanh_emu(in float x) {\n"
literal|"    return 0.5 * log((1.0 + x) / (1.0 - x));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAtanh
argument_list|,
name|float2
argument_list|,
literal|"float2 webgl_atanh_emu(in float2 x) {\n"
literal|"    return 0.5 * log((1.0 + x) / (1.0 - x));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAtanh
argument_list|,
name|float3
argument_list|,
literal|"float3 webgl_atanh_emu(in float3 x) {\n"
literal|"    return 0.5 * log((1.0 + x) / (1.0 - x));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpAtanh
argument_list|,
name|float4
argument_list|,
literal|"float4 webgl_atanh_emu(in float4 x) {\n"
literal|"    return 0.5 * log((1.0 + x) / (1.0 - x));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpRoundEven
argument_list|,
name|float1
argument_list|,
literal|"float webgl_roundEven_emu(in float x) {\n"
literal|"    return (frac(x) == 0.5&& trunc(x) % 2.0 == 0.0) ? trunc(x) : round(x);\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpRoundEven
argument_list|,
name|float2
argument_list|,
literal|"float2 webgl_roundEven_emu(in float2 x) {\n"
literal|"    float2 v;\n"
literal|"    v[0] = (frac(x[0]) == 0.5&& trunc(x[0]) % 2.0 == 0.0) ? trunc(x[0]) : round(x[0]);\n"
literal|"    v[1] = (frac(x[1]) == 0.5&& trunc(x[1]) % 2.0 == 0.0) ? trunc(x[1]) : round(x[1]);\n"
literal|"    return v;\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpRoundEven
argument_list|,
name|float3
argument_list|,
literal|"float3 webgl_roundEven_emu(in float3 x) {\n"
literal|"    float3 v;\n"
literal|"    v[0] = (frac(x[0]) == 0.5&& trunc(x[0]) % 2.0 == 0.0) ? trunc(x[0]) : round(x[0]);\n"
literal|"    v[1] = (frac(x[1]) == 0.5&& trunc(x[1]) % 2.0 == 0.0) ? trunc(x[1]) : round(x[1]);\n"
literal|"    v[2] = (frac(x[2]) == 0.5&& trunc(x[2]) % 2.0 == 0.0) ? trunc(x[2]) : round(x[2]);\n"
literal|"    return v;\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpRoundEven
argument_list|,
name|float4
argument_list|,
literal|"float4 webgl_roundEven_emu(in float4 x) {\n"
literal|"    float4 v;\n"
literal|"    v[0] = (frac(x[0]) == 0.5&& trunc(x[0]) % 2.0 == 0.0) ? trunc(x[0]) : round(x[0]);\n"
literal|"    v[1] = (frac(x[1]) == 0.5&& trunc(x[1]) % 2.0 == 0.0) ? trunc(x[1]) : round(x[1]);\n"
literal|"    v[2] = (frac(x[2]) == 0.5&& trunc(x[2]) % 2.0 == 0.0) ? trunc(x[2]) : round(x[2]);\n"
literal|"    v[3] = (frac(x[3]) == 0.5&& trunc(x[3]) % 2.0 == 0.0) ? trunc(x[3]) : round(x[3]);\n"
literal|"    return v;\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpPackSnorm2x16
argument_list|,
name|float2
argument_list|,
literal|"int webgl_toSnorm(in float x) {\n"
literal|"    return int(round(clamp(x, -1.0, 1.0) * 32767.0));\n"
literal|"}\n"
literal|"\n"
literal|"uint webgl_packSnorm2x16_emu(in float2 v) {\n"
literal|"    int x = webgl_toSnorm(v.x);\n"
literal|"    int y = webgl_toSnorm(v.y);\n"
literal|"    return (asuint(y)<< 16) | (asuint(x)& 0xffffu);\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpPackUnorm2x16
argument_list|,
name|float2
argument_list|,
literal|"uint webgl_toUnorm(in float x) {\n"
literal|"    return uint(round(clamp(x, 0.0, 1.0) * 65535.0));\n"
literal|"}\n"
literal|"\n"
literal|"uint webgl_packUnorm2x16_emu(in float2 v) {\n"
literal|"    uint x = webgl_toUnorm(v.x);\n"
literal|"    uint y = webgl_toUnorm(v.y);\n"
literal|"    return (y<< 16) | x;\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpPackHalf2x16
argument_list|,
name|float2
argument_list|,
literal|"uint webgl_packHalf2x16_emu(in float2 v) {\n"
literal|"    uint x = f32tof16(v.x);\n"
literal|"    uint y = f32tof16(v.y);\n"
literal|"    return (y<< 16) | x;\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|TType
name|uint1
argument_list|(
name|EbtUInt
argument_list|)
decl_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpUnpackSnorm2x16
argument_list|,
name|uint1
argument_list|,
literal|"float webgl_fromSnorm(in uint x) {\n"
literal|"    int xi = asint(x& 0x7fffu) - asint(x& 0x8000u);\n"
literal|"    return clamp(float(xi) / 32767.0, -1.0, 1.0);\n"
literal|"}\n"
literal|"\n"
literal|"float2 webgl_unpackSnorm2x16_emu(in uint u) {\n"
literal|"    uint y = (u>> 16);\n"
literal|"    uint x = u;\n"
literal|"    return float2(webgl_fromSnorm(x), webgl_fromSnorm(y));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpUnpackUnorm2x16
argument_list|,
name|uint1
argument_list|,
literal|"float webgl_fromUnorm(in uint x) {\n"
literal|"    return float(x) / 65535.0;\n"
literal|"}\n"
literal|"\n"
literal|"float2 webgl_unpackUnorm2x16_emu(in uint u) {\n"
literal|"    uint y = (u>> 16);\n"
literal|"    uint x = u& 0xffffu;\n"
literal|"    return float2(webgl_fromUnorm(x), webgl_fromUnorm(y));\n"
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
literal|"float2 webgl_unpackHalf2x16_emu(in uint u) {\n"
literal|"    uint y = (u>> 16);\n"
literal|"    uint x = u& 0xffffu;\n"
literal|"    return float2(f16tof32(x), f16tof32(y));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
comment|// The matrix resulting from outer product needs to be transposed
comment|// (matrices are stored as transposed to simplify element access in HLSL).
comment|// So the function should return transpose(c * r) where c is a column vector
comment|// and r is a row vector. This can be simplified by using the following
comment|// formula:
comment|//   transpose(c * r) = transpose(r) * transpose(c)
comment|// transpose(r) and transpose(c) are in a sense free, since to get the
comment|// transpose of r, we simply can build a column matrix out of the original
comment|// vector instead of a row matrix.
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float2
argument_list|,
name|float2
argument_list|,
literal|"float2x2 webgl_outerProduct_emu(in float2 c, in float2 r) {\n"
literal|"    return mul(float2x1(r), float1x2(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float3
argument_list|,
name|float3
argument_list|,
literal|"float3x3 webgl_outerProduct_emu(in float3 c, in float3 r) {\n"
literal|"    return mul(float3x1(r), float1x3(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float4
argument_list|,
name|float4
argument_list|,
literal|"float4x4 webgl_outerProduct_emu(in float4 c, in float4 r) {\n"
literal|"    return mul(float4x1(r), float1x4(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float3
argument_list|,
name|float2
argument_list|,
literal|"float2x3 webgl_outerProduct_emu(in float3 c, in float2 r) {\n"
literal|"    return mul(float2x1(r), float1x3(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float2
argument_list|,
name|float3
argument_list|,
literal|"float3x2 webgl_outerProduct_emu(in float2 c, in float3 r) {\n"
literal|"    return mul(float3x1(r), float1x2(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float4
argument_list|,
name|float2
argument_list|,
literal|"float2x4 webgl_outerProduct_emu(in float4 c, in float2 r) {\n"
literal|"    return mul(float2x1(r), float1x4(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float2
argument_list|,
name|float4
argument_list|,
literal|"float4x2 webgl_outerProduct_emu(in float2 c, in float4 r) {\n"
literal|"    return mul(float4x1(r), float1x2(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float4
argument_list|,
name|float3
argument_list|,
literal|"float3x4 webgl_outerProduct_emu(in float4 c, in float3 r) {\n"
literal|"    return mul(float3x1(r), float1x4(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpOuterProduct
argument_list|,
name|float3
argument_list|,
name|float4
argument_list|,
literal|"float4x3 webgl_outerProduct_emu(in float3 c, in float4 r) {\n"
literal|"    return mul(float4x1(r), float1x3(c));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|TType
name|mat2
argument_list|(
name|EbtFloat
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|TType
name|mat3
argument_list|(
name|EbtFloat
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|TType
name|mat4
argument_list|(
name|EbtFloat
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
decl_stmt|;
comment|// Remember here that the parameter matrix is actually the transpose
comment|// of the matrix that we're trying to invert, and the resulting matrix
comment|// should also be the transpose of the inverse.
comment|// When accessing the parameter matrix with m[a][b] it can be thought of so
comment|// that a is the column and b is the row of the matrix that we're inverting.
comment|// We calculate the inverse as the adjugate matrix divided by the
comment|// determinant of the matrix being inverted. However, as the result needs
comment|// to be transposed, we actually use of the transpose of the adjugate matrix
comment|// which happens to be the cofactor matrix. That's stored in "cof".
comment|// We don't need to care about divide-by-zero since results are undefined
comment|// for singular or poorly-conditioned matrices.
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpInverse
argument_list|,
name|mat2
argument_list|,
literal|"float2x2 webgl_inverse_emu(in float2x2 m) {\n"
literal|"    float2x2 cof = { m[1][1], -m[0][1], -m[1][0], m[0][0] };\n"
literal|"    return cof / determinant(transpose(m));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
comment|// cofAB is the cofactor for column A and row B.
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpInverse
argument_list|,
name|mat3
argument_list|,
literal|"float3x3 webgl_inverse_emu(in float3x3 m) {\n"
literal|"    float cof00 = m[1][1] * m[2][2] - m[2][1] * m[1][2];\n"
literal|"    float cof01 = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]);\n"
literal|"    float cof02 = m[1][0] * m[2][1] - m[2][0] * m[1][1];\n"
literal|"    float cof10 = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]);\n"
literal|"    float cof11 = m[0][0] * m[2][2] - m[2][0] * m[0][2];\n"
literal|"    float cof12 = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]);\n"
literal|"    float cof20 = m[0][1] * m[1][2] - m[1][1] * m[0][2];\n"
literal|"    float cof21 = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);\n"
literal|"    float cof22 = m[0][0] * m[1][1] - m[1][0] * m[0][1];\n"
literal|"    float3x3 cof = { cof00, cof10, cof20, cof01, cof11, cof21, cof02, cof12, cof22 };\n"
literal|"    return cof / determinant(transpose(m));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpInverse
argument_list|,
name|mat4
argument_list|,
literal|"float4x4 webgl_inverse_emu(in float4x4 m) {\n"
literal|"    float cof00 = m[1][1] * m[2][2] * m[3][3] + m[2][1] * m[3][2] * m[1][3] + m[3][1] * m[1][2] * m[2][3]"
literal|" - m[1][1] * m[3][2] * m[2][3] - m[2][1] * m[1][2] * m[3][3] - m[3][1] * m[2][2] * m[1][3];\n"
literal|"    float cof01 = -(m[1][0] * m[2][2] * m[3][3] + m[2][0] * m[3][2] * m[1][3] + m[3][0] * m[1][2] * m[2][3]"
literal|" - m[1][0] * m[3][2] * m[2][3] - m[2][0] * m[1][2] * m[3][3] - m[3][0] * m[2][2] * m[1][3]);\n"
literal|"    float cof02 = m[1][0] * m[2][1] * m[3][3] + m[2][0] * m[3][1] * m[1][3] + m[3][0] * m[1][1] * m[2][3]"
literal|" - m[1][0] * m[3][1] * m[2][3] - m[2][0] * m[1][1] * m[3][3] - m[3][0] * m[2][1] * m[1][3];\n"
literal|"    float cof03 = -(m[1][0] * m[2][1] * m[3][2] + m[2][0] * m[3][1] * m[1][2] + m[3][0] * m[1][1] * m[2][2]"
literal|" - m[1][0] * m[3][1] * m[2][2] - m[2][0] * m[1][1] * m[3][2] - m[3][0] * m[2][1] * m[1][2]);\n"
literal|"    float cof10 = -(m[0][1] * m[2][2] * m[3][3] + m[2][1] * m[3][2] * m[0][3] + m[3][1] * m[0][2] * m[2][3]"
literal|" - m[0][1] * m[3][2] * m[2][3] - m[2][1] * m[0][2] * m[3][3] - m[3][1] * m[2][2] * m[0][3]);\n"
literal|"    float cof11 = m[0][0] * m[2][2] * m[3][3] + m[2][0] * m[3][2] * m[0][3] + m[3][0] * m[0][2] * m[2][3]"
literal|" - m[0][0] * m[3][2] * m[2][3] - m[2][0] * m[0][2] * m[3][3] - m[3][0] * m[2][2] * m[0][3];\n"
literal|"    float cof12 = -(m[0][0] * m[2][1] * m[3][3] + m[2][0] * m[3][1] * m[0][3] + m[3][0] * m[0][1] * m[2][3]"
literal|" - m[0][0] * m[3][1] * m[2][3] - m[2][0] * m[0][1] * m[3][3] - m[3][0] * m[2][1] * m[0][3]);\n"
literal|"    float cof13 = m[0][0] * m[2][1] * m[3][2] + m[2][0] * m[3][1] * m[0][2] + m[3][0] * m[0][1] * m[2][2]"
literal|" - m[0][0] * m[3][1] * m[2][2] - m[2][0] * m[0][1] * m[3][2] - m[3][0] * m[2][1] * m[0][2];\n"
literal|"    float cof20 = m[0][1] * m[1][2] * m[3][3] + m[1][1] * m[3][2] * m[0][3] + m[3][1] * m[0][2] * m[1][3]"
literal|" - m[0][1] * m[3][2] * m[1][3] - m[1][1] * m[0][2] * m[3][3] - m[3][1] * m[1][2] * m[0][3];\n"
literal|"    float cof21 = -(m[0][0] * m[1][2] * m[3][3] + m[1][0] * m[3][2] * m[0][3] + m[3][0] * m[0][2] * m[1][3]"
literal|" - m[0][0] * m[3][2] * m[1][3] - m[1][0] * m[0][2] * m[3][3] - m[3][0] * m[1][2] * m[0][3]);\n"
literal|"    float cof22 = m[0][0] * m[1][1] * m[3][3] + m[1][0] * m[3][1] * m[0][3] + m[3][0] * m[0][1] * m[1][3]"
literal|" - m[0][0] * m[3][1] * m[1][3] - m[1][0] * m[0][1] * m[3][3] - m[3][0] * m[1][1] * m[0][3];\n"
literal|"    float cof23 = -(m[0][0] * m[1][1] * m[3][2] + m[1][0] * m[3][1] * m[0][2] + m[3][0] * m[0][1] * m[1][2]"
literal|" - m[0][0] * m[3][1] * m[1][2] - m[1][0] * m[0][1] * m[3][2] - m[3][0] * m[1][1] * m[0][2]);\n"
literal|"    float cof30 = -(m[0][1] * m[1][2] * m[2][3] + m[1][1] * m[2][2] * m[0][3] + m[2][1] * m[0][2] * m[1][3]"
literal|" - m[0][1] * m[2][2] * m[1][3] - m[1][1] * m[0][2] * m[2][3] - m[2][1] * m[1][2] * m[0][3]);\n"
literal|"    float cof31 = m[0][0] * m[1][2] * m[2][3] + m[1][0] * m[2][2] * m[0][3] + m[2][0] * m[0][2] * m[1][3]"
literal|" - m[0][0] * m[2][2] * m[1][3] - m[1][0] * m[0][2] * m[2][3] - m[2][0] * m[1][2] * m[0][3];\n"
literal|"    float cof32 = -(m[0][0] * m[1][1] * m[2][3] + m[1][0] * m[2][1] * m[0][3] + m[2][0] * m[0][1] * m[1][3]"
literal|" - m[0][0] * m[2][1] * m[1][3] - m[1][0] * m[0][1] * m[2][3] - m[2][0] * m[1][1] * m[0][3]);\n"
literal|"    float cof33 = m[0][0] * m[1][1] * m[2][2] + m[1][0] * m[2][1] * m[0][2] + m[2][0] * m[0][1] * m[1][2]"
literal|" - m[0][0] * m[2][1] * m[1][2] - m[1][0] * m[0][1] * m[2][2] - m[2][0] * m[1][1] * m[0][2];\n"
literal|"    float4x4 cof = { cof00, cof10, cof20, cof30, cof01, cof11, cof21, cof31,"
literal|" cof02, cof12, cof22, cof32, cof03, cof13, cof23, cof33 };\n"
literal|"    return cof / determinant(transpose(m));\n"
literal|"}\n"
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
