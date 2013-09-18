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
name|_CONSTANT_UNION_INCLUDED_
end_ifndef
begin_define
DECL|macro|_CONSTANT_UNION_INCLUDED_
define|#
directive|define
name|_CONSTANT_UNION_INCLUDED_
end_define
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_decl_stmt
name|class
name|ConstantUnion
block|{
name|public
label|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
expr_stmt|;
name|ConstantUnion
argument_list|()
block|{
name|iConst
operator|=
literal|0
expr_stmt|;
name|type
operator|=
name|EbtVoid
expr_stmt|;
block|}
name|void
name|setIConst
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|iConst
operator|=
name|i
expr_stmt|;
name|type
operator|=
name|EbtInt
expr_stmt|;
block|}
name|void
name|setFConst
parameter_list|(
name|float
name|f
parameter_list|)
block|{
name|fConst
operator|=
name|f
expr_stmt|;
name|type
operator|=
name|EbtFloat
expr_stmt|;
block|}
name|void
name|setBConst
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|bConst
operator|=
name|b
expr_stmt|;
name|type
operator|=
name|EbtBool
expr_stmt|;
block|}
name|int
name|getIConst
parameter_list|()
block|{
return|return
name|iConst
return|;
block|}
name|float
name|getFConst
parameter_list|()
block|{
return|return
name|fConst
return|;
block|}
name|bool
name|getBConst
parameter_list|()
block|{
return|return
name|bConst
return|;
block|}
name|int
name|getIConst
argument_list|()
specifier|const
block|{
return|return
name|iConst
return|;
block|}
name|float
name|getFConst
argument_list|()
specifier|const
block|{
return|return
name|fConst
return|;
block|}
name|bool
name|getBConst
argument_list|()
specifier|const
block|{
return|return
name|bConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|int
name|i
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|iConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|float
name|f
operator|)
specifier|const
block|{
return|return
name|f
operator|==
name|fConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|bool
name|b
operator|)
specifier|const
block|{
return|return
name|b
operator|==
name|bConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
if|if
condition|(
name|constant
operator|.
name|type
operator|!=
name|type
condition|)
return|return
name|false
return|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
return|return
name|constant
operator|.
name|iConst
operator|==
name|iConst
return|;
case|case
name|EbtFloat
case|:
return|return
name|constant
operator|.
name|fConst
operator|==
name|fConst
return|;
case|case
name|EbtBool
case|:
return|return
name|constant
operator|.
name|bConst
operator|==
name|bConst
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
end_decl_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|int
name|i
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|float
name|f
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|f
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|bool
name|b
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|b
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|constant
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|>
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
return|return
name|iConst
operator|>
name|constant
operator|.
name|iConst
return|;
case|case
name|EbtFloat
case|:
return|return
name|fConst
operator|>
name|constant
operator|.
name|fConst
return|;
default|default:
return|return
name|false
return|;
comment|// Invalid operation, handled at semantic analysis
block|}
end_expr_stmt
begin_expr_stmt
unit|}      bool
name|operator
operator|<
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
return|return
name|iConst
operator|<
name|constant
operator|.
name|iConst
return|;
case|case
name|EbtFloat
case|:
return|return
name|fConst
operator|<
name|constant
operator|.
name|fConst
return|;
default|default:
return|return
name|false
return|;
comment|// Invalid operation, handled at semantic analysis
block|}
end_expr_stmt
begin_expr_stmt
unit|}      ConstantUnion
name|operator
operator|+
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|+
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|returnValue
operator|.
name|setFConst
argument_list|(
name|fConst
operator|+
name|constant
operator|.
name|fConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      ConstantUnion
name|operator
operator|-
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|-
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|returnValue
operator|.
name|setFConst
argument_list|(
name|fConst
operator|-
name|constant
operator|.
name|fConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_macro
unit|}      ConstantUnion
name|operator
end_macro
begin_expr_stmt
operator|*
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|*
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|returnValue
operator|.
name|setFConst
argument_list|(
name|fConst
operator|*
name|constant
operator|.
name|fConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      ConstantUnion
name|operator
operator|%
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|%
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      ConstantUnion
name|operator
operator|>>
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|>>
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      ConstantUnion
name|operator
operator|<<
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|<<
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_decl_stmt
unit|}      ConstantUnion
name|operator
modifier|&
argument_list|(
specifier|const
name|ConstantUnion
operator|&
name|constant
argument_list|)
decl|const
block|{
name|ConstantUnion
name|returnValue
decl_stmt|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|&
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
return|return
name|returnValue
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|ConstantUnion
name|operator
operator||
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator||
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_macro
unit|}      ConstantUnion
name|operator
end_macro
begin_expr_stmt
operator|^
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|^
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      ConstantUnion
name|operator
operator|&&
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtBool
case|:
name|returnValue
operator|.
name|setBConst
argument_list|(
name|bConst
operator|&&
name|constant
operator|.
name|bConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      ConstantUnion
name|operator
operator|||
operator|(
specifier|const
name|ConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|ConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtBool
case|:
name|returnValue
operator|.
name|setBConst
argument_list|(
name|bConst
operator|||
name|constant
operator|.
name|bConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_macro
unit|}      TBasicType
name|getType
argument_list|()
end_macro
begin_expr_stmt
specifier|const
block|{
return|return
name|type
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_union
union|union
block|{
name|int
name|iConst
decl_stmt|;
comment|// used for ivec, scalar ints
name|bool
name|bConst
decl_stmt|;
comment|// used for bvec, scalar bools
name|float
name|fConst
decl_stmt|;
comment|// used for vec, mat, scalar floats
block|}
union|;
end_union
begin_decl_stmt
name|TBasicType
name|type
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// _CONSTANT_UNION_INCLUDED_
end_comment
end_unit
