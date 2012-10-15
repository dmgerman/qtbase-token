begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
name|_SHHANDLE_INCLUDED_
end_ifndef
begin_define
DECL|macro|_SHHANDLE_INCLUDED_
define|#
directive|define
name|_SHHANDLE_INCLUDED_
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|// Machine independent part of the compiler private objects
end_comment
begin_comment
comment|// sent as ShHandle to the driver.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This should not be included by driver code.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_include
include|#
directive|include
file|"compiler/BuiltInFunctionEmulator.h"
end_include
begin_include
include|#
directive|include
file|"compiler/ExtensionBehavior.h"
end_include
begin_include
include|#
directive|include
file|"compiler/InfoSink.h"
end_include
begin_include
include|#
directive|include
file|"compiler/SymbolTable.h"
end_include
begin_include
include|#
directive|include
file|"compiler/VariableInfo.h"
end_include
begin_decl_stmt
DECL|variable|LongNameMap
name|class
name|LongNameMap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TCompiler
name|class
name|TCompiler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TDependencyGraph
name|class
name|TDependencyGraph
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// Helper function to identify specs that are based on the WebGL spec,
end_comment
begin_comment
comment|// like the CSS Shaders spec.
end_comment
begin_comment
comment|//
end_comment
begin_function_decl
name|bool
name|isWebGLBasedSpec
parameter_list|(
name|ShShaderSpec
name|spec
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//
end_comment
begin_comment
comment|// The base class used to back handles returned to the driver.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TShHandleBase
block|{
name|public
label|:
name|TShHandleBase
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|TShHandleBase
argument_list|()
expr_stmt|;
name|virtual
name|TCompiler
modifier|*
name|getAsCompiler
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
name|protected
label|:
comment|// Memory allocator. Allocates and tracks memory required by the compiler.
comment|// Deallocates all memory when compiler is destructed.
name|TPoolAllocator
name|allocator
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// The base class for the machine dependent compiler to derive from
end_comment
begin_comment
comment|// for managing object code from the compile.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TCompiler
range|:
name|public
name|TShHandleBase
block|{
name|public
operator|:
name|TCompiler
argument_list|(
argument|ShShaderType type
argument_list|,
argument|ShShaderSpec spec
argument_list|)
block|;
name|virtual
operator|~
name|TCompiler
argument_list|()
block|;
name|virtual
name|TCompiler
operator|*
name|getAsCompiler
argument_list|()
block|{
return|return
name|this
return|;
block|}
name|bool
name|Init
argument_list|(
specifier|const
name|ShBuiltInResources
operator|&
name|resources
argument_list|)
block|;
name|bool
name|compile
argument_list|(
argument|const char* const shaderStrings[]
argument_list|,
argument|const int numStrings
argument_list|,
argument|int compileOptions
argument_list|)
block|;
comment|// Get results of the last compilation.
name|TInfoSink
operator|&
name|getInfoSink
argument_list|()
block|{
return|return
name|infoSink
return|;
block|}
specifier|const
name|TVariableInfoList
operator|&
name|getAttribs
argument_list|()
specifier|const
block|{
return|return
name|attribs
return|;
block|}
specifier|const
name|TVariableInfoList
operator|&
name|getUniforms
argument_list|()
specifier|const
block|{
return|return
name|uniforms
return|;
block|}
name|int
name|getMappedNameMaxLength
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|ShShaderType
name|getShaderType
argument_list|()
specifier|const
block|{
return|return
name|shaderType
return|;
block|}
name|ShShaderSpec
name|getShaderSpec
argument_list|()
specifier|const
block|{
return|return
name|shaderSpec
return|;
block|}
comment|// Initialize symbol-table with built-in symbols.
name|bool
name|InitBuiltInSymbolTable
argument_list|(
specifier|const
name|ShBuiltInResources
operator|&
name|resources
argument_list|)
block|;
comment|// Clears the results from the previous compilation.
name|void
name|clearResults
argument_list|()
block|;
comment|// Return true if function recursion is detected.
name|bool
name|detectRecursion
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|)
block|;
comment|// Rewrites a shader's intermediate tree according to the CSS Shaders spec.
name|void
name|rewriteCSSShader
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|)
block|;
comment|// Returns true if the given shader does not exceed the minimum
comment|// functionality mandated in GLSL 1.0 spec Appendix A.
name|bool
name|validateLimitations
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|)
block|;
comment|// Collect info for all attribs and uniforms.
name|void
name|collectAttribsUniforms
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|)
block|;
comment|// Map long variable names into shorter ones.
name|void
name|mapLongVariableNames
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|)
block|;
comment|// Translate to object code.
name|virtual
name|void
name|translate
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|)
operator|=
literal|0
block|;
comment|// Returns true if, after applying the packing rules in the GLSL 1.017 spec
comment|// Appendix A, section 7, the shader does not use too many uniforms.
name|bool
name|enforcePackingRestrictions
argument_list|()
block|;
comment|// Returns true if the shader passes the restrictions that aim to prevent timing attacks.
name|bool
name|enforceTimingRestrictions
argument_list|(
argument|TIntermNode* root
argument_list|,
argument|bool outputGraph
argument_list|)
block|;
comment|// Returns true if the shader does not use samplers.
name|bool
name|enforceVertexShaderTimingRestrictions
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|)
block|;
comment|// Returns true if the shader does not use sampler dependent values to affect control
comment|// flow or in operations whose time can depend on the input values.
name|bool
name|enforceFragmentShaderTimingRestrictions
argument_list|(
specifier|const
name|TDependencyGraph
operator|&
name|graph
argument_list|)
block|;
comment|// Get built-in extensions with default behavior.
specifier|const
name|TExtensionBehavior
operator|&
name|getExtensionBehavior
argument_list|()
specifier|const
block|;
specifier|const
name|BuiltInFunctionEmulator
operator|&
name|getBuiltInFunctionEmulator
argument_list|()
specifier|const
block|;
name|private
operator|:
name|ShShaderType
name|shaderType
block|;
name|ShShaderSpec
name|shaderSpec
block|;
name|int
name|maxUniformVectors
block|;
comment|// Built-in symbol table for the given language, spec, and resources.
comment|// It is preserved from compile-to-compile.
name|TSymbolTable
name|symbolTable
block|;
comment|// Built-in extensions with default behavior.
name|TExtensionBehavior
name|extensionBehavior
block|;
name|BuiltInFunctionEmulator
name|builtInFunctionEmulator
block|;
comment|// Results of compilation.
name|TInfoSink
name|infoSink
block|;
comment|// Output sink.
name|TVariableInfoList
name|attribs
block|;
comment|// Active attributes in the compiled shader.
name|TVariableInfoList
name|uniforms
block|;
comment|// Active uniforms in the compiled shader.
comment|// Cached copy of the ref-counted singleton.
name|LongNameMap
operator|*
name|longNameMap
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// This is the interface between the machine independent code
end_comment
begin_comment
comment|// and the machine dependent code.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// The machine dependent code should derive from the classes
end_comment
begin_comment
comment|// above. Then Construct*() and Delete*() will create and
end_comment
begin_comment
comment|// destroy the machine dependent objects, which contain the
end_comment
begin_comment
comment|// above machine independent information.
end_comment
begin_comment
comment|//
end_comment
begin_function_decl
name|TCompiler
modifier|*
name|ConstructCompiler
parameter_list|(
name|ShShaderType
name|type
parameter_list|,
name|ShShaderSpec
name|spec
parameter_list|,
name|ShShaderOutput
name|output
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|DeleteCompiler
parameter_list|(
name|TCompiler
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _SHHANDLE_INCLUDED_
end_comment
end_unit
