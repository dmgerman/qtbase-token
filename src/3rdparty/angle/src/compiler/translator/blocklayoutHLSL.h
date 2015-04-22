begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// blocklayout.h:
end_comment
begin_comment
comment|//   Methods and classes related to uniform layout and packing in GLSL and HLSL.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_BLOCKLAYOUTHLSL_H_
end_ifndef
begin_define
DECL|macro|COMMON_BLOCKLAYOUTHLSL_H_
define|#
directive|define
name|COMMON_BLOCKLAYOUTHLSL_H_
end_define
begin_include
include|#
directive|include
file|<cstddef>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"blocklayout.h"
end_include
begin_include
include|#
directive|include
file|<GLSLANG/ShaderLang.h>
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
comment|// Block layout packed according to the D3D9 or default D3D10+ register packing rules
comment|// See http://msdn.microsoft.com/en-us/library/windows/desktop/bb509632(v=vs.85).aspx
comment|// The strategy should be ENCODE_LOOSE for D3D9 constant blocks, and ENCODE_PACKED
comment|// for everything else (D3D10+ constant blocks and all attributes/varyings).
name|class
name|COMPILER_EXPORT
name|HLSLBlockEncoder
range|:
name|public
name|BlockLayoutEncoder
block|{
name|public
operator|:
expr|enum
name|HLSLBlockEncoderStrategy
block|{
name|ENCODE_PACKED
block|,
name|ENCODE_LOOSE
block|}
block|;
name|HLSLBlockEncoder
argument_list|(
argument|HLSLBlockEncoderStrategy strategy
argument_list|)
block|;
name|virtual
name|void
name|enterAggregateType
argument_list|()
block|;
name|virtual
name|void
name|exitAggregateType
argument_list|()
block|;
name|void
name|skipRegisters
argument_list|(
argument|unsigned int numRegisters
argument_list|)
block|;
name|bool
name|isPacked
argument_list|()
specifier|const
block|{
return|return
name|mEncoderStrategy
operator|==
name|ENCODE_PACKED
return|;
block|}
name|void
name|setTransposeMatrices
argument_list|(
argument|bool enabled
argument_list|)
block|{
name|mTransposeMatrices
operator|=
name|enabled
block|; }
specifier|static
name|HLSLBlockEncoderStrategy
name|GetStrategyFor
argument_list|(
argument|ShShaderOutput outputType
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|getBlockLayoutInfo
argument_list|(
argument|GLenum type
argument_list|,
argument|unsigned int arraySize
argument_list|,
argument|bool isRowMajorMatrix
argument_list|,
argument|int *arrayStrideOut
argument_list|,
argument|int *matrixStrideOut
argument_list|)
block|;
name|virtual
name|void
name|advanceOffset
argument_list|(
argument|GLenum type
argument_list|,
argument|unsigned int arraySize
argument_list|,
argument|bool isRowMajorMatrix
argument_list|,
argument|int arrayStride
argument_list|,
argument|int matrixStride
argument_list|)
block|;
name|HLSLBlockEncoderStrategy
name|mEncoderStrategy
block|;
name|bool
name|mTransposeMatrices
block|; }
decl_stmt|;
comment|// This method returns the number of used registers for a ShaderVariable. It is dependent on the HLSLBlockEncoder
comment|// class to count the number of used registers in a struct (which are individually packed according to the same rules).
name|COMPILER_EXPORT
name|unsigned
name|int
name|HLSLVariableRegisterCount
parameter_list|(
specifier|const
name|Varying
modifier|&
name|variable
parameter_list|,
name|bool
name|transposeMatrices
parameter_list|)
function_decl|;
name|COMPILER_EXPORT
name|unsigned
name|int
name|HLSLVariableRegisterCount
parameter_list|(
specifier|const
name|Uniform
modifier|&
name|variable
parameter_list|,
name|ShShaderOutput
name|outputType
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMMON_BLOCKLAYOUTHLSL_H_
end_comment
end_unit
