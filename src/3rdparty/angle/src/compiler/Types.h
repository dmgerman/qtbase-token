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
name|_TYPES_INCLUDED
end_ifndef
begin_define
DECL|macro|_TYPES_INCLUDED
define|#
directive|define
name|_TYPES_INCLUDED
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"compiler/BaseTypes.h"
end_include
begin_include
include|#
directive|include
file|"compiler/Common.h"
end_include
begin_include
include|#
directive|include
file|"compiler/debug.h"
end_include
begin_struct_decl
struct_decl|struct
name|TPublicType
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|TType
name|class
name|TType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TField
block|{
name|public
label|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
expr_stmt|;
name|TField
argument_list|(
name|TType
operator|*
name|type
argument_list|,
name|TString
operator|*
name|name
argument_list|)
operator|:
name|mType
argument_list|(
name|type
argument_list|)
operator|,
name|mName
argument_list|(
argument|name
argument_list|)
block|{}
comment|// TODO(alokp): We should only return const type.
comment|// Fix it by tweaking grammar.
name|TType
operator|*
name|type
argument_list|()
block|{
return|return
name|mType
return|;
block|}
specifier|const
name|TType
operator|*
name|type
argument_list|()
specifier|const
block|{
return|return
name|mType
return|;
block|}
specifier|const
name|TString
operator|&
name|name
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mName
return|;
block|}
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TField
argument_list|)
expr_stmt|;
name|TType
modifier|*
name|mType
decl_stmt|;
name|TString
modifier|*
name|mName
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|typedef|TFieldList
typedef|typedef
name|TVector
operator|<
name|TField
operator|*
operator|>
name|TFieldList
expr_stmt|;
end_typedef
begin_function
DECL|function|NewPoolTFieldList
specifier|inline
name|TFieldList
modifier|*
name|NewPoolTFieldList
parameter_list|()
block|{
name|void
modifier|*
name|memory
init|=
name|GetGlobalPoolAllocator
argument_list|()
operator|->
name|allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|TFieldList
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|new
argument_list|(
argument|memory
argument_list|)
name|TFieldList
return|;
block|}
end_function
begin_decl_stmt
name|class
name|TStructure
block|{
name|public
label|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
expr_stmt|;
name|TStructure
argument_list|(
name|TString
operator|*
name|name
argument_list|,
name|TFieldList
operator|*
name|fields
argument_list|)
operator|:
name|mName
argument_list|(
name|name
argument_list|)
operator|,
name|mFields
argument_list|(
name|fields
argument_list|)
operator|,
name|mObjectSize
argument_list|(
literal|0
argument_list|)
operator|,
name|mDeepestNesting
argument_list|(
literal|0
argument_list|)
block|{     }
specifier|const
name|TString
operator|&
name|name
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mName
return|;
block|}
specifier|const
name|TFieldList
operator|&
name|fields
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mFields
return|;
block|}
specifier|const
name|TString
operator|&
name|mangledName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mMangledName
operator|.
name|empty
argument_list|()
condition|)
name|mMangledName
operator|=
name|buildMangledName
argument_list|()
expr_stmt|;
return|return
name|mMangledName
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|size_t
name|objectSize
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mObjectSize
operator|==
literal|0
condition|)
name|mObjectSize
operator|=
name|calculateObjectSize
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|mObjectSize
return|;
end_return
begin_expr_stmt
unit|};
name|int
name|deepestNesting
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mDeepestNesting
operator|==
literal|0
condition|)
name|mDeepestNesting
operator|=
name|calculateDeepestNesting
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|mDeepestNesting
return|;
end_return
begin_macro
unit|}     bool
name|containsArrays
argument_list|()
end_macro
begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TStructure
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|TString
name|buildMangledName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|size_t
name|calculateObjectSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|calculateDeepestNesting
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|TString
modifier|*
name|mName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TFieldList
modifier|*
name|mFields
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|TString
name|mMangledName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|size_t
name|mObjectSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|int
name|mDeepestNesting
decl_stmt|;
end_decl_stmt
begin_comment
unit|};
comment|//
end_comment
begin_comment
comment|// Base class for things that have a type.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TType
block|{
name|public
label|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
expr_stmt|;
name|TType
argument_list|()
block|{}
name|TType
argument_list|(
argument|TBasicType t
argument_list|,
argument|TPrecision p
argument_list|,
argument|TQualifier q = EvqTemporary
argument_list|,
argument|int s =
literal|1
argument_list|,
argument|bool m = false
argument_list|,
argument|bool a = false
argument_list|)
block|:
name|type
argument_list|(
name|t
argument_list|)
operator|,
name|precision
argument_list|(
name|p
argument_list|)
operator|,
name|qualifier
argument_list|(
name|q
argument_list|)
operator|,
name|size
argument_list|(
name|s
argument_list|)
operator|,
name|matrix
argument_list|(
name|m
argument_list|)
operator|,
name|array
argument_list|(
name|a
argument_list|)
operator|,
name|arraySize
argument_list|(
literal|0
argument_list|)
operator|,
name|structure
argument_list|(
literal|0
argument_list|)
block|{     }
name|explicit
name|TType
argument_list|(
specifier|const
name|TPublicType
operator|&
name|p
argument_list|)
expr_stmt|;
name|TType
argument_list|(
argument|TStructure* userDef
argument_list|,
argument|TPrecision p = EbpUndefined
argument_list|)
block|:
name|type
argument_list|(
name|EbtStruct
argument_list|)
operator|,
name|precision
argument_list|(
name|p
argument_list|)
operator|,
name|qualifier
argument_list|(
name|EvqTemporary
argument_list|)
operator|,
name|size
argument_list|(
literal|1
argument_list|)
operator|,
name|matrix
argument_list|(
name|false
argument_list|)
operator|,
name|array
argument_list|(
name|false
argument_list|)
operator|,
name|arraySize
argument_list|(
literal|0
argument_list|)
operator|,
name|structure
argument_list|(
argument|userDef
argument_list|)
block|{     }
name|TBasicType
name|getBasicType
argument_list|()
specifier|const
block|{
return|return
name|type
return|;
block|}
name|void
name|setBasicType
parameter_list|(
name|TBasicType
name|t
parameter_list|)
block|{
name|type
operator|=
name|t
expr_stmt|;
block|}
name|TPrecision
name|getPrecision
argument_list|()
specifier|const
block|{
return|return
name|precision
return|;
block|}
name|void
name|setPrecision
parameter_list|(
name|TPrecision
name|p
parameter_list|)
block|{
name|precision
operator|=
name|p
expr_stmt|;
block|}
name|TQualifier
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|qualifier
return|;
block|}
name|void
name|setQualifier
parameter_list|(
name|TQualifier
name|q
parameter_list|)
block|{
name|qualifier
operator|=
name|q
expr_stmt|;
block|}
comment|// One-dimensional size of single instance type
name|int
name|getNominalSize
argument_list|()
specifier|const
block|{
return|return
name|size
return|;
block|}
name|void
name|setNominalSize
parameter_list|(
name|int
name|s
parameter_list|)
block|{
name|size
operator|=
name|s
expr_stmt|;
block|}
comment|// Full size of single instance of type
name|size_t
name|getObjectSize
argument_list|()
specifier|const
expr_stmt|;
name|int
name|elementRegisterCount
argument_list|()
specifier|const
block|{
if|if
condition|(
name|structure
condition|)
block|{
specifier|const
name|TFieldList
modifier|&
name|fields
init|=
name|getStruct
argument_list|()
operator|->
name|fields
argument_list|()
decl_stmt|;
name|int
name|registerCount
init|=
literal|0
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|fields
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|registerCount
operator|+=
name|fields
index|[
name|i
index|]
operator|->
name|type
argument_list|()
operator|->
name|totalRegisterCount
argument_list|()
expr_stmt|;
block|}
return|return
name|registerCount
return|;
block|}
elseif|else
if|if
condition|(
name|isMatrix
argument_list|()
condition|)
block|{
return|return
name|getNominalSize
argument_list|()
return|;
block|}
else|else
block|{
return|return
literal|1
return|;
block|}
block|}
name|int
name|totalRegisterCount
argument_list|()
specifier|const
block|{
if|if
condition|(
name|array
condition|)
block|{
return|return
name|arraySize
operator|*
name|elementRegisterCount
argument_list|()
return|;
block|}
else|else
block|{
return|return
name|elementRegisterCount
argument_list|()
return|;
block|}
block|}
name|bool
name|isMatrix
argument_list|()
specifier|const
block|{
return|return
name|matrix
operator|?
name|true
operator|:
name|false
return|;
block|}
name|void
name|setMatrix
parameter_list|(
name|bool
name|m
parameter_list|)
block|{
name|matrix
operator|=
name|m
expr_stmt|;
block|}
name|bool
name|isArray
argument_list|()
specifier|const
block|{
return|return
name|array
operator|?
name|true
operator|:
name|false
return|;
block|}
name|int
name|getArraySize
argument_list|()
specifier|const
block|{
return|return
name|arraySize
return|;
block|}
name|void
name|setArraySize
parameter_list|(
name|int
name|s
parameter_list|)
block|{
name|array
operator|=
name|true
expr_stmt|;
name|arraySize
operator|=
name|s
expr_stmt|;
block|}
name|void
name|clearArrayness
parameter_list|()
block|{
name|array
operator|=
name|false
expr_stmt|;
name|arraySize
operator|=
literal|0
expr_stmt|;
block|}
name|bool
name|isVector
argument_list|()
specifier|const
block|{
return|return
name|size
operator|>
literal|1
operator|&&
operator|!
name|matrix
return|;
block|}
name|bool
name|isScalar
argument_list|()
specifier|const
block|{
return|return
name|size
operator|==
literal|1
operator|&&
operator|!
name|matrix
operator|&&
operator|!
name|structure
return|;
block|}
name|TStructure
operator|*
name|getStruct
argument_list|()
specifier|const
block|{
return|return
name|structure
return|;
block|}
name|void
name|setStruct
parameter_list|(
name|TStructure
modifier|*
name|s
parameter_list|)
block|{
name|structure
operator|=
name|s
expr_stmt|;
block|}
specifier|const
name|TString
operator|&
name|getMangledName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mangled
operator|.
name|empty
argument_list|()
condition|)
block|{
name|mangled
operator|=
name|buildMangledName
argument_list|()
expr_stmt|;
name|mangled
operator|+=
literal|';'
expr_stmt|;
block|}
return|return
name|mangled
return|;
block|}
name|bool
name|sameElementType
argument_list|(
specifier|const
name|TType
operator|&
name|right
argument_list|)
decl|const
block|{
return|return
name|type
operator|==
name|right
operator|.
name|type
operator|&&
name|size
operator|==
name|right
operator|.
name|size
operator|&&
name|matrix
operator|==
name|right
operator|.
name|matrix
operator|&&
name|structure
operator|==
name|right
operator|.
name|structure
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|TType
operator|&
name|right
operator|)
specifier|const
block|{
return|return
name|type
operator|==
name|right
operator|.
name|type
operator|&&
name|size
operator|==
name|right
operator|.
name|size
operator|&&
name|matrix
operator|==
name|right
operator|.
name|matrix
operator|&&
name|array
operator|==
name|right
operator|.
name|array
operator|&&
operator|(
operator|!
name|array
operator|||
name|arraySize
operator|==
name|right
operator|.
name|arraySize
operator|)
operator|&&
name|structure
operator|==
name|right
operator|.
name|structure
return|;
comment|// don't check the qualifier, it's not ever what's being sought after
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|TType
operator|&
name|right
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|right
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|TType
operator|&
name|right
operator|)
specifier|const
block|{
if|if
condition|(
name|type
operator|!=
name|right
operator|.
name|type
condition|)
return|return
name|type
operator|<
name|right
operator|.
name|type
return|;
if|if
condition|(
name|size
operator|!=
name|right
operator|.
name|size
condition|)
return|return
name|size
operator|<
name|right
operator|.
name|size
return|;
if|if
condition|(
name|matrix
operator|!=
name|right
operator|.
name|matrix
condition|)
return|return
name|matrix
operator|<
name|right
operator|.
name|matrix
return|;
if|if
condition|(
name|array
operator|!=
name|right
operator|.
name|array
condition|)
return|return
name|array
operator|<
name|right
operator|.
name|array
return|;
if|if
condition|(
name|arraySize
operator|!=
name|right
operator|.
name|arraySize
condition|)
return|return
name|arraySize
operator|<
name|right
operator|.
name|arraySize
return|;
if|if
condition|(
name|structure
operator|!=
name|right
operator|.
name|structure
condition|)
return|return
name|structure
operator|<
name|right
operator|.
name|structure
return|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|const
name|char
operator|*
name|getBasicString
argument_list|()
specifier|const
block|{
return|return
operator|::
name|getBasicString
argument_list|(
name|type
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|char
operator|*
name|getPrecisionString
argument_list|()
specifier|const
block|{
return|return
operator|::
name|getPrecisionString
argument_list|(
name|precision
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|char
operator|*
name|getQualifierString
argument_list|()
specifier|const
block|{
return|return
operator|::
name|getQualifierString
argument_list|(
name|qualifier
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|TString
name|getCompleteString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// If this type is a struct, returns the deepest struct nesting of
end_comment
begin_comment
comment|// any field in the struct. For example:
end_comment
begin_comment
comment|//   struct nesting1 {
end_comment
begin_comment
comment|//     vec4 position;
end_comment
begin_comment
comment|//   };
end_comment
begin_comment
comment|//   struct nesting2 {
end_comment
begin_comment
comment|//     nesting1 field1;
end_comment
begin_comment
comment|//     vec4 field2;
end_comment
begin_comment
comment|//   };
end_comment
begin_comment
comment|// For type "nesting2", this method would return 2 -- the number
end_comment
begin_comment
comment|// of structures through which indirection must occur to reach the
end_comment
begin_comment
comment|// deepest field (nesting2.field1.position).
end_comment
begin_expr_stmt
name|int
name|getDeepestStructNesting
argument_list|()
specifier|const
block|{
return|return
name|structure
operator|?
name|structure
operator|->
name|deepestNesting
argument_list|()
operator|:
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isStructureContainingArrays
argument_list|()
specifier|const
block|{
return|return
name|structure
operator|?
name|structure
operator|->
name|containsArrays
argument_list|()
operator|:
name|false
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|TString
name|buildMangledName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|TBasicType
name|type
range|:
literal|6
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TPrecision
name|precision
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TQualifier
name|qualifier
range|:
literal|7
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|size
range|:
literal|8
decl_stmt|;
end_decl_stmt
begin_comment
comment|// size of vector or matrix, not size of array
end_comment
begin_decl_stmt
name|unsigned
name|int
name|matrix
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|unsigned
name|int
name|array
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|arraySize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TStructure
modifier|*
name|structure
decl_stmt|;
end_decl_stmt
begin_comment
comment|// 0 unless this is a struct
end_comment
begin_decl_stmt
name|mutable
name|TString
name|mangled
decl_stmt|;
end_decl_stmt
begin_comment
unit|};
comment|//
end_comment
begin_comment
comment|// This is a workaround for a problem with the yacc stack,  It can't have
end_comment
begin_comment
comment|// types that it thinks have non-trivial constructors.  It should
end_comment
begin_comment
comment|// just be used while recognizing the grammar, not anything else.  Pointers
end_comment
begin_comment
comment|// could be used, but also trying to avoid lots of memory management overhead.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Not as bad as it looks, there is no actual assumption that the fields
end_comment
begin_comment
comment|// match up or are name the same or anything like that.
end_comment
begin_comment
comment|//
end_comment
begin_struct
DECL|struct|TPublicType
struct|struct
name|TPublicType
block|{
DECL|member|type
name|TBasicType
name|type
decl_stmt|;
DECL|member|qualifier
name|TQualifier
name|qualifier
decl_stmt|;
DECL|member|precision
name|TPrecision
name|precision
decl_stmt|;
DECL|member|size
name|int
name|size
decl_stmt|;
comment|// size of vector or matrix, not size of array
DECL|member|matrix
name|bool
name|matrix
decl_stmt|;
DECL|member|array
name|bool
name|array
decl_stmt|;
DECL|member|arraySize
name|int
name|arraySize
decl_stmt|;
DECL|member|userDef
name|TType
modifier|*
name|userDef
decl_stmt|;
DECL|member|line
name|TSourceLoc
name|line
decl_stmt|;
DECL|function|setBasic
name|void
name|setBasic
parameter_list|(
name|TBasicType
name|bt
parameter_list|,
name|TQualifier
name|q
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|ln
parameter_list|)
block|{
name|type
operator|=
name|bt
expr_stmt|;
name|qualifier
operator|=
name|q
expr_stmt|;
name|precision
operator|=
name|EbpUndefined
expr_stmt|;
name|size
operator|=
literal|1
expr_stmt|;
name|matrix
operator|=
name|false
expr_stmt|;
name|array
operator|=
name|false
expr_stmt|;
name|arraySize
operator|=
literal|0
expr_stmt|;
name|userDef
operator|=
literal|0
expr_stmt|;
name|line
operator|=
name|ln
expr_stmt|;
block|}
DECL|function|setAggregate
name|void
name|setAggregate
parameter_list|(
name|int
name|s
parameter_list|,
name|bool
name|m
init|=
name|false
parameter_list|)
block|{
name|size
operator|=
name|s
expr_stmt|;
name|matrix
operator|=
name|m
expr_stmt|;
block|}
DECL|function|setArray
name|void
name|setArray
parameter_list|(
name|bool
name|a
parameter_list|,
name|int
name|s
init|=
literal|0
parameter_list|)
block|{
name|array
operator|=
name|a
expr_stmt|;
name|arraySize
operator|=
name|s
expr_stmt|;
block|}
DECL|function|isStructureContainingArrays
name|bool
name|isStructureContainingArrays
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|userDef
condition|)
block|{
return|return
name|false
return|;
block|}
return|return
name|userDef
operator|->
name|isStructureContainingArrays
argument_list|()
return|;
block|}
end_struct
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// _TYPES_INCLUDED_
end_comment
end_unit
