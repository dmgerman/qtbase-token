begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_TRANSLATOR_VERSIONGLSL_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_VERSIONGLSL_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_VERSIONGLSL_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Pragma.h"
end_include
begin_decl_stmt
DECL|variable|GLSL_VERSION_110
specifier|static
specifier|const
name|int
name|GLSL_VERSION_110
init|=
literal|110
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_120
specifier|static
specifier|const
name|int
name|GLSL_VERSION_120
init|=
literal|120
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_130
specifier|static
specifier|const
name|int
name|GLSL_VERSION_130
init|=
literal|130
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_140
specifier|static
specifier|const
name|int
name|GLSL_VERSION_140
init|=
literal|140
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_150
specifier|static
specifier|const
name|int
name|GLSL_VERSION_150
init|=
literal|150
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_330
specifier|static
specifier|const
name|int
name|GLSL_VERSION_330
init|=
literal|330
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_400
specifier|static
specifier|const
name|int
name|GLSL_VERSION_400
init|=
literal|400
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_410
specifier|static
specifier|const
name|int
name|GLSL_VERSION_410
init|=
literal|410
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_420
specifier|static
specifier|const
name|int
name|GLSL_VERSION_420
init|=
literal|420
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_430
specifier|static
specifier|const
name|int
name|GLSL_VERSION_430
init|=
literal|430
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_440
specifier|static
specifier|const
name|int
name|GLSL_VERSION_440
init|=
literal|440
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLSL_VERSION_450
specifier|static
specifier|const
name|int
name|GLSL_VERSION_450
init|=
literal|450
decl_stmt|;
end_decl_stmt
begin_function_decl
name|int
name|ShaderOutputTypeToGLSLVersion
parameter_list|(
name|ShShaderOutput
name|output
parameter_list|)
function_decl|;
end_function_decl
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
begin_comment
comment|// TODO: ES3 equivalent versions of GLSL
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
argument|sh::GLenum type
argument_list|,
argument|const TPragma&pragma
argument_list|,
argument|ShShaderOutput output
argument_list|)
block|;
comment|// If output is core profile, returns 150.
comment|// If output is legacy profile,
comment|//   Returns 120 if the following is used the shader:
comment|//   - "invariant",
comment|//   - "gl_PointCoord",
comment|//   - matrix/matrix constructors
comment|//   - array "out" parameters
comment|//   Else 110 is returned.
name|int
name|getVersion
argument_list|()
specifier|const
block|{
return|return
name|mVersion
return|;
block|}
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *
argument_list|)
name|override
block|;
name|bool
name|visitAggregate
argument_list|(
argument|Visit
argument_list|,
argument|TIntermAggregate *
argument_list|)
name|override
block|;
name|private
operator|:
name|void
name|ensureVersionIsAtLeast
argument_list|(
argument|int version
argument_list|)
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
comment|// COMPILER_TRANSLATOR_VERSIONGLSL_H_
end_comment
end_unit
