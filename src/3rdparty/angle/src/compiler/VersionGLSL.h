begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_VERSIONGLSL_H_
end_ifndef
begin_define
DECL|macro|COMPILER_VERSIONGLSL_H_
define|#
directive|define
name|COMPILER_VERSIONGLSL_H_
end_define
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_comment
comment|// Traverses the intermediate tree to return the minimum GLSL version
end_comment
begin_comment
comment|// required to legally access all built-in features used in the shader.
end_comment
begin_comment
comment|// GLSL 1.1 which is mandated by OpenGL 2.0 provides:
end_comment
begin_comment
comment|//   - #version and #extension to declare version and extensions.
end_comment
begin_comment
comment|//   - built-in functions refract, exp, and log.
end_comment
begin_comment
comment|//   - updated step() to compare x< edge instead of x<= edge.
end_comment
begin_comment
comment|// GLSL 1.2 which is mandated by OpenGL 2.1 provides:
end_comment
begin_comment
comment|//   - many changes to reduce differences when compared to the ES specification.
end_comment
begin_comment
comment|//   - invariant keyword and its support.
end_comment
begin_comment
comment|//   - c++ style name hiding rules.
end_comment
begin_comment
comment|//   - built-in variable gl_PointCoord for fragment shaders.
end_comment
begin_comment
comment|//   - matrix constructors taking matrix as argument.
end_comment
begin_comment
comment|//   - array as "out" function parameters
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TVersionGLSL
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|TVersionGLSL
argument_list|(
argument|ShShaderType type
argument_list|)
block|;
comment|// Returns 120 if the following is used the shader:
comment|// - "invariant",
comment|// - "gl_PointCoord",
comment|// - matrix/matrix constructors
comment|// - array "out" parameters
comment|// Else 110 is returned.
name|int
name|getVersion
argument_list|()
block|{
return|return
name|mVersion
return|;
block|}
name|virtual
name|void
name|visitSymbol
argument_list|(
name|TIntermSymbol
operator|*
argument_list|)
block|;
name|virtual
name|void
name|visitConstantUnion
argument_list|(
name|TIntermConstantUnion
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitBinary
argument_list|(
name|Visit
argument_list|,
name|TIntermBinary
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitUnary
argument_list|(
name|Visit
argument_list|,
name|TIntermUnary
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitSelection
argument_list|(
name|Visit
argument_list|,
name|TIntermSelection
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitAggregate
argument_list|(
name|Visit
argument_list|,
name|TIntermAggregate
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitLoop
argument_list|(
name|Visit
argument_list|,
name|TIntermLoop
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visitBranch
argument_list|(
name|Visit
argument_list|,
name|TIntermBranch
operator|*
argument_list|)
block|;
name|protected
operator|:
name|void
name|updateVersion
argument_list|(
argument|int version
argument_list|)
block|;
name|private
operator|:
name|ShShaderType
name|mShaderType
block|;
name|int
name|mVersion
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_VERSIONGLSL_H_
end_comment
end_unit
