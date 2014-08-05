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
comment|// UtilsHLSL.h:
end_comment
begin_comment
comment|//   Utility methods for GLSL to HLSL translation.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TRANSLATOR_UTILSHLSL_H_
end_ifndef
begin_define
DECL|macro|TRANSLATOR_UTILSHLSL_H_
define|#
directive|define
name|TRANSLATOR_UTILSHLSL_H_
end_define
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Types.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_decl_stmt
name|namespace
name|sh
block|{
name|TString
name|TextureString
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
name|TString
name|SamplerString
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
comment|// Prepends an underscore to avoid naming clashes
name|TString
name|Decorate
parameter_list|(
specifier|const
name|TString
modifier|&
name|string
parameter_list|)
function_decl|;
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
function_decl|;
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
function_decl|;
name|TString
name|DecoratePrivate
parameter_list|(
specifier|const
name|TString
modifier|&
name|privateText
parameter_list|)
function_decl|;
name|TString
name|TypeString
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
name|TString
name|StructNameString
parameter_list|(
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|)
function_decl|;
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
function_decl|;
name|TString
name|InterpolationString
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
function_decl|;
name|TString
name|QualifierString
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TRANSLATOR_UTILSHLSL_H_
end_comment
end_unit
