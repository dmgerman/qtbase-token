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
begin_comment
comment|// UtilsHLSL.cpp:
end_comment
begin_comment
comment|//   Utility methods for GLSL to HLSL translation.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/UtilsHLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/StructureHLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/SymbolTable.h"
end_include
begin_namespace
DECL|namespace|sh
namespace|namespace
name|sh
block|{
DECL|function|SamplerString
name|TString
name|SamplerString
parameter_list|(
specifier|const
name|TBasicType
name|type
parameter_list|)
block|{
if|if
condition|(
name|IsShadowSampler
argument_list|(
name|type
argument_list|)
condition|)
block|{
return|return
literal|"SamplerComparisonState"
return|;
block|}
else|else
block|{
return|return
literal|"SamplerState"
return|;
block|}
block|}
DECL|function|SamplerString
name|TString
name|SamplerString
parameter_list|(
name|HLSLTextureSamplerGroup
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|>=
name|HLSL_COMPARISON_SAMPLER_GROUP_BEGIN
operator|&&
name|type
operator|<=
name|HLSL_COMPARISON_SAMPLER_GROUP_END
condition|)
block|{
return|return
literal|"SamplerComparisonState"
return|;
block|}
else|else
block|{
return|return
literal|"SamplerState"
return|;
block|}
block|}
DECL|function|TextureGroup
name|HLSLTextureSamplerGroup
name|TextureGroup
parameter_list|(
specifier|const
name|TBasicType
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtSampler2D
case|:
return|return
name|HLSL_TEXTURE_2D
return|;
case|case
name|EbtSamplerCube
case|:
return|return
name|HLSL_TEXTURE_CUBE
return|;
case|case
name|EbtSamplerExternalOES
case|:
return|return
name|HLSL_TEXTURE_2D
return|;
case|case
name|EbtSampler2DArray
case|:
return|return
name|HLSL_TEXTURE_2D_ARRAY
return|;
case|case
name|EbtSampler3D
case|:
return|return
name|HLSL_TEXTURE_3D
return|;
case|case
name|EbtISampler2D
case|:
return|return
name|HLSL_TEXTURE_2D_INT4
return|;
case|case
name|EbtISampler3D
case|:
return|return
name|HLSL_TEXTURE_3D_INT4
return|;
case|case
name|EbtISamplerCube
case|:
return|return
name|HLSL_TEXTURE_2D_ARRAY_INT4
return|;
case|case
name|EbtISampler2DArray
case|:
return|return
name|HLSL_TEXTURE_2D_ARRAY_INT4
return|;
case|case
name|EbtUSampler2D
case|:
return|return
name|HLSL_TEXTURE_2D_UINT4
return|;
case|case
name|EbtUSampler3D
case|:
return|return
name|HLSL_TEXTURE_3D_UINT4
return|;
case|case
name|EbtUSamplerCube
case|:
return|return
name|HLSL_TEXTURE_2D_ARRAY_UINT4
return|;
case|case
name|EbtUSampler2DArray
case|:
return|return
name|HLSL_TEXTURE_2D_ARRAY_UINT4
return|;
case|case
name|EbtSampler2DShadow
case|:
return|return
name|HLSL_TEXTURE_2D_COMPARISON
return|;
case|case
name|EbtSamplerCubeShadow
case|:
return|return
name|HLSL_TEXTURE_CUBE_COMPARISON
return|;
case|case
name|EbtSampler2DArrayShadow
case|:
return|return
name|HLSL_TEXTURE_2D_ARRAY_COMPARISON
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|HLSL_TEXTURE_UNKNOWN
return|;
block|}
DECL|function|TextureString
name|TString
name|TextureString
parameter_list|(
specifier|const
name|HLSLTextureSamplerGroup
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|HLSL_TEXTURE_2D
case|:
return|return
literal|"Texture2D"
return|;
case|case
name|HLSL_TEXTURE_CUBE
case|:
return|return
literal|"TextureCube"
return|;
case|case
name|HLSL_TEXTURE_2D_ARRAY
case|:
return|return
literal|"Texture2DArray"
return|;
case|case
name|HLSL_TEXTURE_3D
case|:
return|return
literal|"Texture3D"
return|;
case|case
name|HLSL_TEXTURE_2D_INT4
case|:
return|return
literal|"Texture2D<int4>"
return|;
case|case
name|HLSL_TEXTURE_3D_INT4
case|:
return|return
literal|"Texture3D<int4>"
return|;
case|case
name|HLSL_TEXTURE_2D_ARRAY_INT4
case|:
return|return
literal|"Texture2DArray<int4>"
return|;
case|case
name|HLSL_TEXTURE_2D_UINT4
case|:
return|return
literal|"Texture2D<uint4>"
return|;
case|case
name|HLSL_TEXTURE_3D_UINT4
case|:
return|return
literal|"Texture3D<uint4>"
return|;
case|case
name|HLSL_TEXTURE_2D_ARRAY_UINT4
case|:
return|return
literal|"Texture2DArray<uint4>"
return|;
case|case
name|HLSL_TEXTURE_2D_COMPARISON
case|:
return|return
literal|"Texture2D"
return|;
case|case
name|HLSL_TEXTURE_CUBE_COMPARISON
case|:
return|return
literal|"TextureCube"
return|;
case|case
name|HLSL_TEXTURE_2D_ARRAY_COMPARISON
case|:
return|return
literal|"Texture2DArray"
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|"<unknown texture type>"
return|;
block|}
DECL|function|TextureString
name|TString
name|TextureString
parameter_list|(
specifier|const
name|TBasicType
name|type
parameter_list|)
block|{
return|return
name|TextureString
argument_list|(
name|TextureGroup
argument_list|(
name|type
argument_list|)
argument_list|)
return|;
block|}
DECL|function|TextureGroupSuffix
name|TString
name|TextureGroupSuffix
parameter_list|(
specifier|const
name|HLSLTextureSamplerGroup
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|HLSL_TEXTURE_2D
case|:
return|return
literal|"2D"
return|;
case|case
name|HLSL_TEXTURE_CUBE
case|:
return|return
literal|"Cube"
return|;
case|case
name|HLSL_TEXTURE_2D_ARRAY
case|:
return|return
literal|"2DArray"
return|;
case|case
name|HLSL_TEXTURE_3D
case|:
return|return
literal|"3D"
return|;
case|case
name|HLSL_TEXTURE_2D_INT4
case|:
return|return
literal|"2D_int4_"
return|;
case|case
name|HLSL_TEXTURE_3D_INT4
case|:
return|return
literal|"3D_int4_"
return|;
case|case
name|HLSL_TEXTURE_2D_ARRAY_INT4
case|:
return|return
literal|"2DArray_int4_"
return|;
case|case
name|HLSL_TEXTURE_2D_UINT4
case|:
return|return
literal|"2D_uint4_"
return|;
case|case
name|HLSL_TEXTURE_3D_UINT4
case|:
return|return
literal|"3D_uint4_"
return|;
case|case
name|HLSL_TEXTURE_2D_ARRAY_UINT4
case|:
return|return
literal|"2DArray_uint4_"
return|;
case|case
name|HLSL_TEXTURE_2D_COMPARISON
case|:
return|return
literal|"2D_comparison"
return|;
case|case
name|HLSL_TEXTURE_CUBE_COMPARISON
case|:
return|return
literal|"Cube_comparison"
return|;
case|case
name|HLSL_TEXTURE_2D_ARRAY_COMPARISON
case|:
return|return
literal|"2DArray_comparison"
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|"<unknown texture type>"
return|;
block|}
DECL|function|TextureGroupSuffix
name|TString
name|TextureGroupSuffix
parameter_list|(
specifier|const
name|TBasicType
name|type
parameter_list|)
block|{
return|return
name|TextureGroupSuffix
argument_list|(
name|TextureGroup
argument_list|(
name|type
argument_list|)
argument_list|)
return|;
block|}
DECL|function|TextureTypeSuffix
name|TString
name|TextureTypeSuffix
parameter_list|(
specifier|const
name|TBasicType
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtISamplerCube
case|:
return|return
literal|"Cube_int4_"
return|;
case|case
name|EbtUSamplerCube
case|:
return|return
literal|"Cube_uint4_"
return|;
default|default:
comment|// All other types are identified by their group suffix
return|return
name|TextureGroupSuffix
argument_list|(
name|type
argument_list|)
return|;
block|}
block|}
DECL|function|DecorateUniform
name|TString
name|DecorateUniform
parameter_list|(
specifier|const
name|TString
modifier|&
name|string
parameter_list|,
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtSamplerExternalOES
condition|)
block|{
return|return
literal|"ex_"
operator|+
name|string
return|;
block|}
return|return
name|Decorate
argument_list|(
name|string
argument_list|)
return|;
block|}
DECL|function|DecorateField
name|TString
name|DecorateField
parameter_list|(
specifier|const
name|TString
modifier|&
name|string
parameter_list|,
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|)
block|{
if|if
condition|(
name|structure
operator|.
name|name
argument_list|()
operator|.
name|compare
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|"gl_"
argument_list|)
operator|!=
literal|0
condition|)
block|{
return|return
name|Decorate
argument_list|(
name|string
argument_list|)
return|;
block|}
return|return
name|string
return|;
block|}
DECL|function|DecoratePrivate
name|TString
name|DecoratePrivate
parameter_list|(
specifier|const
name|TString
modifier|&
name|privateText
parameter_list|)
block|{
return|return
literal|"dx_"
operator|+
name|privateText
return|;
block|}
DECL|function|Decorate
name|TString
name|Decorate
parameter_list|(
specifier|const
name|TString
modifier|&
name|string
parameter_list|)
block|{
if|if
condition|(
name|string
operator|.
name|compare
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|"gl_"
argument_list|)
operator|!=
literal|0
condition|)
block|{
return|return
literal|"_"
operator|+
name|string
return|;
block|}
return|return
name|string
return|;
block|}
DECL|function|DecorateIfNeeded
name|TString
name|DecorateIfNeeded
parameter_list|(
specifier|const
name|TName
modifier|&
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
operator|.
name|isInternal
argument_list|()
condition|)
block|{
return|return
name|name
operator|.
name|getString
argument_list|()
return|;
block|}
else|else
block|{
return|return
name|Decorate
argument_list|(
name|name
operator|.
name|getString
argument_list|()
argument_list|)
return|;
block|}
block|}
DECL|function|DecorateFunctionIfNeeded
name|TString
name|DecorateFunctionIfNeeded
parameter_list|(
specifier|const
name|TName
modifier|&
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
operator|.
name|isInternal
argument_list|()
condition|)
block|{
return|return
name|TFunction
operator|::
name|unmangleName
argument_list|(
name|name
operator|.
name|getString
argument_list|()
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|Decorate
argument_list|(
name|TFunction
operator|::
name|unmangleName
argument_list|(
name|name
operator|.
name|getString
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
block|}
DECL|function|TypeString
name|TString
name|TypeString
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
specifier|const
name|TStructure
modifier|*
name|structure
init|=
name|type
operator|.
name|getStruct
argument_list|()
decl_stmt|;
if|if
condition|(
name|structure
condition|)
block|{
specifier|const
name|TString
modifier|&
name|typeName
init|=
name|structure
operator|->
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
name|typeName
operator|!=
literal|""
condition|)
block|{
return|return
name|StructNameString
argument_list|(
operator|*
name|structure
argument_list|)
return|;
block|}
else|else
comment|// Nameless structure, define in place
block|{
return|return
name|StructureHLSL
operator|::
name|defineNameless
argument_list|(
operator|*
name|structure
argument_list|)
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|isMatrix
argument_list|()
condition|)
block|{
name|int
name|cols
init|=
name|type
operator|.
name|getCols
argument_list|()
decl_stmt|;
name|int
name|rows
init|=
name|type
operator|.
name|getRows
argument_list|()
decl_stmt|;
return|return
literal|"float"
operator|+
name|str
argument_list|(
name|cols
argument_list|)
operator|+
literal|"x"
operator|+
name|str
argument_list|(
name|rows
argument_list|)
return|;
block|}
else|else
block|{
switch|switch
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
condition|)
block|{
case|case
name|EbtFloat
case|:
switch|switch
condition|(
name|type
operator|.
name|getNominalSize
argument_list|()
condition|)
block|{
case|case
literal|1
case|:
return|return
literal|"float"
return|;
case|case
literal|2
case|:
return|return
literal|"float2"
return|;
case|case
literal|3
case|:
return|return
literal|"float3"
return|;
case|case
literal|4
case|:
return|return
literal|"float4"
return|;
block|}
case|case
name|EbtInt
case|:
switch|switch
condition|(
name|type
operator|.
name|getNominalSize
argument_list|()
condition|)
block|{
case|case
literal|1
case|:
return|return
literal|"int"
return|;
case|case
literal|2
case|:
return|return
literal|"int2"
return|;
case|case
literal|3
case|:
return|return
literal|"int3"
return|;
case|case
literal|4
case|:
return|return
literal|"int4"
return|;
block|}
case|case
name|EbtUInt
case|:
switch|switch
condition|(
name|type
operator|.
name|getNominalSize
argument_list|()
condition|)
block|{
case|case
literal|1
case|:
return|return
literal|"uint"
return|;
case|case
literal|2
case|:
return|return
literal|"uint2"
return|;
case|case
literal|3
case|:
return|return
literal|"uint3"
return|;
case|case
literal|4
case|:
return|return
literal|"uint4"
return|;
block|}
case|case
name|EbtBool
case|:
switch|switch
condition|(
name|type
operator|.
name|getNominalSize
argument_list|()
condition|)
block|{
case|case
literal|1
case|:
return|return
literal|"bool"
return|;
case|case
literal|2
case|:
return|return
literal|"bool2"
return|;
case|case
literal|3
case|:
return|return
literal|"bool3"
return|;
case|case
literal|4
case|:
return|return
literal|"bool4"
return|;
block|}
case|case
name|EbtVoid
case|:
return|return
literal|"void"
return|;
case|case
name|EbtSampler2D
case|:
case|case
name|EbtISampler2D
case|:
case|case
name|EbtUSampler2D
case|:
case|case
name|EbtSampler2DArray
case|:
case|case
name|EbtISampler2DArray
case|:
case|case
name|EbtUSampler2DArray
case|:
return|return
literal|"sampler2D"
return|;
case|case
name|EbtSamplerCube
case|:
case|case
name|EbtISamplerCube
case|:
case|case
name|EbtUSamplerCube
case|:
return|return
literal|"samplerCUBE"
return|;
case|case
name|EbtSamplerExternalOES
case|:
return|return
literal|"sampler2D"
return|;
default|default:
break|break;
block|}
block|}
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|"<unknown type>"
return|;
block|}
DECL|function|StructNameString
name|TString
name|StructNameString
parameter_list|(
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|)
block|{
if|if
condition|(
name|structure
operator|.
name|name
argument_list|()
operator|.
name|empty
argument_list|()
condition|)
block|{
return|return
literal|""
return|;
block|}
comment|// For structures at global scope we use a consistent
comment|// translation so that we can link between shader stages.
if|if
condition|(
name|structure
operator|.
name|atGlobalScope
argument_list|()
condition|)
block|{
return|return
name|Decorate
argument_list|(
name|structure
operator|.
name|name
argument_list|()
argument_list|)
return|;
block|}
return|return
literal|"ss"
operator|+
name|str
argument_list|(
name|structure
operator|.
name|uniqueId
argument_list|()
argument_list|)
operator|+
literal|"_"
operator|+
name|structure
operator|.
name|name
argument_list|()
return|;
block|}
DECL|function|QualifiedStructNameString
name|TString
name|QualifiedStructNameString
parameter_list|(
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|,
name|bool
name|useHLSLRowMajorPacking
parameter_list|,
name|bool
name|useStd140Packing
parameter_list|)
block|{
if|if
condition|(
name|structure
operator|.
name|name
argument_list|()
operator|==
literal|""
condition|)
block|{
return|return
literal|""
return|;
block|}
name|TString
name|prefix
init|=
literal|""
decl_stmt|;
comment|// Structs packed with row-major matrices in HLSL are prefixed with "rm"
comment|// GLSL column-major maps to HLSL row-major, and the converse is true
if|if
condition|(
name|useStd140Packing
condition|)
block|{
name|prefix
operator|+=
literal|"std_"
expr_stmt|;
block|}
if|if
condition|(
name|useHLSLRowMajorPacking
condition|)
block|{
name|prefix
operator|+=
literal|"rm_"
expr_stmt|;
block|}
return|return
name|prefix
operator|+
name|StructNameString
argument_list|(
name|structure
argument_list|)
return|;
block|}
DECL|function|InterpolationString
name|TString
name|InterpolationString
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
block|{
switch|switch
condition|(
name|qualifier
condition|)
block|{
case|case
name|EvqVaryingIn
case|:
return|return
literal|""
return|;
case|case
name|EvqFragmentIn
case|:
return|return
literal|""
return|;
case|case
name|EvqSmoothIn
case|:
return|return
literal|"linear"
return|;
case|case
name|EvqFlatIn
case|:
return|return
literal|"nointerpolation"
return|;
case|case
name|EvqCentroidIn
case|:
return|return
literal|"centroid"
return|;
case|case
name|EvqVaryingOut
case|:
return|return
literal|""
return|;
case|case
name|EvqVertexOut
case|:
return|return
literal|""
return|;
case|case
name|EvqSmoothOut
case|:
return|return
literal|"linear"
return|;
case|case
name|EvqFlatOut
case|:
return|return
literal|"nointerpolation"
return|;
case|case
name|EvqCentroidOut
case|:
return|return
literal|"centroid"
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|""
return|;
block|}
DECL|function|QualifierString
name|TString
name|QualifierString
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
block|{
switch|switch
condition|(
name|qualifier
condition|)
block|{
case|case
name|EvqIn
case|:
return|return
literal|"in"
return|;
case|case
name|EvqOut
case|:
return|return
literal|"inout"
return|;
comment|// 'out' results in an HLSL error if not all fields are written, for GLSL it's undefined
case|case
name|EvqInOut
case|:
return|return
literal|"inout"
return|;
case|case
name|EvqConstReadOnly
case|:
return|return
literal|"const"
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|""
return|;
block|}
DECL|function|HLSLTextureCoordsCount
name|int
name|HLSLTextureCoordsCount
parameter_list|(
specifier|const
name|TBasicType
name|samplerType
parameter_list|)
block|{
switch|switch
condition|(
name|samplerType
condition|)
block|{
case|case
name|EbtSampler2D
case|:
return|return
literal|2
return|;
case|case
name|EbtSampler3D
case|:
return|return
literal|3
return|;
case|case
name|EbtSamplerCube
case|:
return|return
literal|3
return|;
case|case
name|EbtSampler2DArray
case|:
return|return
literal|3
return|;
case|case
name|EbtISampler2D
case|:
return|return
literal|2
return|;
case|case
name|EbtISampler3D
case|:
return|return
literal|3
return|;
case|case
name|EbtISamplerCube
case|:
return|return
literal|3
return|;
case|case
name|EbtISampler2DArray
case|:
return|return
literal|3
return|;
case|case
name|EbtUSampler2D
case|:
return|return
literal|2
return|;
case|case
name|EbtUSampler3D
case|:
return|return
literal|3
return|;
case|case
name|EbtUSamplerCube
case|:
return|return
literal|3
return|;
case|case
name|EbtUSampler2DArray
case|:
return|return
literal|3
return|;
case|case
name|EbtSampler2DShadow
case|:
return|return
literal|2
return|;
case|case
name|EbtSamplerCubeShadow
case|:
return|return
literal|3
return|;
case|case
name|EbtSampler2DArrayShadow
case|:
return|return
literal|3
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
block|}
end_namespace
end_unit
