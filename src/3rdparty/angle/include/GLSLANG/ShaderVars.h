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
comment|// ShaderVars.h:
end_comment
begin_comment
comment|//  Types to represent GL variables (varyings, uniforms, etc)
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GLSLANG_SHADERVARS_H_
end_ifndef
begin_define
DECL|macro|GLSLANG_SHADERVARS_H_
define|#
directive|define
name|GLSLANG_SHADERVARS_H_
end_define
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_comment
comment|// Assume ShaderLang.h is included before ShaderVars.h, for sh::GLenum
end_comment
begin_comment
comment|// Note: make sure to increment ANGLE_SH_VERSION when changing ShaderVars.h
end_comment
begin_decl_stmt
name|namespace
name|sh
block|{
comment|// Varying interpolation qualifier, see section 4.3.9 of the ESSL 3.00.4 spec
enum|enum
name|InterpolationType
block|{
name|INTERPOLATION_SMOOTH
block|,
name|INTERPOLATION_CENTROID
block|,
name|INTERPOLATION_FLAT
block|}
enum|;
comment|// Validate link& SSO consistency of interpolation qualifiers
name|COMPILER_EXPORT
name|bool
name|InterpolationTypesMatch
parameter_list|(
name|InterpolationType
name|a
parameter_list|,
name|InterpolationType
name|b
parameter_list|)
function_decl|;
comment|// Uniform block layout qualifier, see section 4.3.8.3 of the ESSL 3.00.4 spec
enum|enum
name|BlockLayoutType
block|{
name|BLOCKLAYOUT_STANDARD
block|,
name|BLOCKLAYOUT_PACKED
block|,
name|BLOCKLAYOUT_SHARED
block|}
enum|;
comment|// Base class for all variables defined in shaders, including Varyings, Uniforms, etc
comment|// Note: we must override the copy constructor and assignment operator so we can
comment|// work around excessive GCC binary bloating:
comment|// See https://code.google.com/p/angleproject/issues/detail?id=697
struct|struct
name|COMPILER_EXPORT
name|ShaderVariable
block|{
name|ShaderVariable
argument_list|()
expr_stmt|;
name|ShaderVariable
argument_list|(
argument|GLenum typeIn
argument_list|,
argument|unsigned int arraySizeIn
argument_list|)
empty_stmt|;
operator|~
name|ShaderVariable
argument_list|()
expr_stmt|;
name|ShaderVariable
argument_list|(
specifier|const
name|ShaderVariable
operator|&
name|other
argument_list|)
expr_stmt|;
name|ShaderVariable
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ShaderVariable
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|isArray
argument_list|()
specifier|const
block|{
return|return
name|arraySize
operator|>
literal|0
return|;
block|}
name|unsigned
name|int
name|elementCount
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|max
argument_list|(
literal|1u
argument_list|,
name|arraySize
argument_list|)
return|;
block|}
name|bool
name|isStruct
argument_list|()
specifier|const
block|{
return|return
operator|!
name|fields
operator|.
name|empty
argument_list|()
return|;
block|}
comment|// All of the shader's variables are described using nested data
comment|// structures. This is needed in order to disambiguate similar looking
comment|// types, such as two structs containing the same fields, but in
comment|// different orders. "findInfoByMappedName" provides an easy query for
comment|// users to dive into the data structure and fetch the unique variable
comment|// instance corresponding to a dereferencing chain of the top-level
comment|// variable.
comment|// Given a mapped name like 'a[0].b.c[0]', return the ShaderVariable
comment|// that defines 'c' in |leafVar|, and the original name 'A[0].B.C[0]'
comment|// in |originalName|, based on the assumption that |this| defines 'a'.
comment|// If no match is found, return false.
name|bool
name|findInfoByMappedName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|mappedFullName
argument_list|,
specifier|const
name|ShaderVariable
operator|*
operator|*
name|leafVar
argument_list|,
name|std
operator|::
name|string
operator|*
name|originalFullName
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isBuiltIn
argument_list|()
specifier|const
block|{
return|return
name|name
operator|.
name|compare
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|"gl_"
argument_list|)
operator|==
literal|0
return|;
block|}
name|GLenum
name|type
decl_stmt|;
name|GLenum
name|precision
decl_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
name|std
operator|::
name|string
name|mappedName
expr_stmt|;
name|unsigned
name|int
name|arraySize
decl_stmt|;
name|bool
name|staticUse
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|ShaderVariable
operator|>
name|fields
expr_stmt|;
name|std
operator|::
name|string
name|structName
expr_stmt|;
name|protected
label|:
name|bool
name|isSameVariableAtLinkTime
argument_list|(
specifier|const
name|ShaderVariable
operator|&
name|other
argument_list|,
name|bool
name|matchPrecision
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ShaderVariable
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ShaderVariable
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
block|}
struct|;
name|struct
name|COMPILER_EXPORT
name|Uniform
range|:
name|public
name|ShaderVariable
block|{
name|Uniform
argument_list|()
block|;
operator|~
name|Uniform
argument_list|()
block|;
name|Uniform
argument_list|(
specifier|const
name|Uniform
operator|&
name|other
argument_list|)
block|;
name|Uniform
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Uniform
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Uniform
operator|&
name|other
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Uniform
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
comment|// Decide whether two uniforms are the same at shader link time,
comment|// assuming one from vertex shader and the other from fragment shader.
comment|// See GLSL ES Spec 3.00.3, sec 4.3.5.
name|bool
name|isSameUniformAtLinkTime
argument_list|(
argument|const Uniform&other
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|// An interface variable is a variable which passes data between the GL data structures and the
comment|// shader execution: either vertex shader inputs or fragment shader outputs. These variables can
comment|// have integer locations to pass back to the GL API.
name|struct
name|COMPILER_EXPORT
name|InterfaceVariable
range|:
name|public
name|ShaderVariable
block|{
name|InterfaceVariable
argument_list|()
block|;
operator|~
name|InterfaceVariable
argument_list|()
block|;
name|InterfaceVariable
argument_list|(
specifier|const
name|InterfaceVariable
operator|&
name|other
argument_list|)
block|;
name|InterfaceVariable
operator|&
name|operator
operator|=
operator|(
specifier|const
name|InterfaceVariable
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|InterfaceVariable
operator|&
name|other
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|InterfaceVariable
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|int
name|location
block|; }
decl_stmt|;
name|struct
name|COMPILER_EXPORT
name|Attribute
range|:
name|public
name|InterfaceVariable
block|{
name|Attribute
argument_list|()
block|;
operator|~
name|Attribute
argument_list|()
block|;
name|Attribute
argument_list|(
specifier|const
name|Attribute
operator|&
name|other
argument_list|)
block|;
name|Attribute
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Attribute
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Attribute
operator|&
name|other
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Attribute
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
expr|}
block|;  struct
name|COMPILER_EXPORT
name|OutputVariable
operator|:
name|public
name|InterfaceVariable
block|{
name|OutputVariable
argument_list|()
block|;
operator|~
name|OutputVariable
argument_list|()
block|;
name|OutputVariable
argument_list|(
specifier|const
name|OutputVariable
operator|&
name|other
argument_list|)
block|;
name|OutputVariable
operator|&
name|operator
operator|=
operator|(
specifier|const
name|OutputVariable
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|OutputVariable
operator|&
name|other
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|OutputVariable
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
expr|}
block|;  struct
name|COMPILER_EXPORT
name|InterfaceBlockField
operator|:
name|public
name|ShaderVariable
block|{
name|InterfaceBlockField
argument_list|()
block|;
operator|~
name|InterfaceBlockField
argument_list|()
block|;
name|InterfaceBlockField
argument_list|(
specifier|const
name|InterfaceBlockField
operator|&
name|other
argument_list|)
block|;
name|InterfaceBlockField
operator|&
name|operator
operator|=
operator|(
specifier|const
name|InterfaceBlockField
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|InterfaceBlockField
operator|&
name|other
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|InterfaceBlockField
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
comment|// Decide whether two InterfaceBlock fields are the same at shader
comment|// link time, assuming one from vertex shader and the other from
comment|// fragment shader.
comment|// See GLSL ES Spec 3.00.3, sec 4.3.7.
name|bool
name|isSameInterfaceBlockFieldAtLinkTime
argument_list|(
argument|const InterfaceBlockField&other
argument_list|)
specifier|const
block|;
name|bool
name|isRowMajorLayout
block|; }
block|;  struct
name|COMPILER_EXPORT
name|Varying
operator|:
name|public
name|ShaderVariable
block|{
name|Varying
argument_list|()
block|;
operator|~
name|Varying
argument_list|()
block|;
name|Varying
argument_list|(
specifier|const
name|Varying
operator|&
name|otherg
argument_list|)
block|;
name|Varying
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Varying
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Varying
operator|&
name|other
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Varying
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
comment|// Decide whether two varyings are the same at shader link time,
comment|// assuming one from vertex shader and the other from fragment shader.
comment|// Invariance needs to match only in ESSL1. Relevant spec sections:
comment|// GLSL ES 3.00.4, sections 4.6.1 and 4.3.9.
comment|// GLSL ES 1.00.17, section 4.6.4.
name|bool
name|isSameVaryingAtLinkTime
argument_list|(
argument|const Varying&other
argument_list|,
argument|int shaderVersion
argument_list|)
specifier|const
block|;
comment|// Deprecated version of isSameVaryingAtLinkTime, which assumes ESSL1.
name|bool
name|isSameVaryingAtLinkTime
argument_list|(
argument|const Varying&other
argument_list|)
specifier|const
block|;
name|InterpolationType
name|interpolation
block|;
name|bool
name|isInvariant
block|; }
block|;  struct
name|COMPILER_EXPORT
name|InterfaceBlock
block|{
name|InterfaceBlock
argument_list|()
block|;
operator|~
name|InterfaceBlock
argument_list|()
block|;
name|InterfaceBlock
argument_list|(
specifier|const
name|InterfaceBlock
operator|&
name|other
argument_list|)
block|;
name|InterfaceBlock
operator|&
name|operator
operator|=
operator|(
specifier|const
name|InterfaceBlock
operator|&
name|other
operator|)
block|;
comment|// Fields from blocks with non-empty instance names are prefixed with the block name.
name|std
operator|::
name|string
name|fieldPrefix
argument_list|()
specifier|const
block|;
name|std
operator|::
name|string
name|name
block|;
name|std
operator|::
name|string
name|mappedName
block|;
name|std
operator|::
name|string
name|instanceName
block|;
name|unsigned
name|int
name|arraySize
block|;
name|BlockLayoutType
name|layout
block|;
name|bool
name|isRowMajorLayout
block|;
name|bool
name|staticUse
block|;
name|std
operator|::
name|vector
operator|<
name|InterfaceBlockField
operator|>
name|fields
block|; }
block|;  }
end_decl_stmt
begin_comment
comment|// namespace sh
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// GLSLANG_SHADERVARS_H_
end_comment
end_unit
