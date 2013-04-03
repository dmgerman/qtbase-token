begin_unit
begin_comment
comment|/*  * Copyright (C) 2012 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY APPLE, INC. ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE, INC. OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment
begin_include
include|#
directive|include
file|"third_party/compiler/ArrayBoundsClamper.h"
end_include
begin_comment
comment|// The built-in 'clamp' instruction only accepts floats and returns a float.  I
end_comment
begin_comment
comment|// iterated a few times with our driver team who examined the output from our
end_comment
begin_comment
comment|// compiler - they said the multiple casts generates more code than a single
end_comment
begin_comment
comment|// function call.  An inline ternary operator might have been better, but since
end_comment
begin_comment
comment|// the index value might be an expression itself, we'd have to make temporary
end_comment
begin_comment
comment|// variables to avoid evaluating the expression multiple times.  And making
end_comment
begin_comment
comment|// temporary variables was difficult because ANGLE would then need to make more
end_comment
begin_comment
comment|// brutal changes to the expression tree.
end_comment
begin_decl_stmt
DECL|variable|kIntClampBegin
specifier|const
name|char
modifier|*
name|kIntClampBegin
init|=
literal|"// BEGIN: Generated code for array bounds clamping\n\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|kIntClampEnd
specifier|const
name|char
modifier|*
name|kIntClampEnd
init|=
literal|"// END: Generated code for array bounds clamping\n\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|kIntClampDefinition
specifier|const
name|char
modifier|*
name|kIntClampDefinition
init|=
literal|"int webgl_int_clamp(int value, int minValue, int maxValue) { return ((value< minValue) ? minValue : ((value> maxValue) ? maxValue : value)); }\n\n"
decl_stmt|;
end_decl_stmt
begin_namespace
namespace|namespace
block|{
DECL|class|ArrayBoundsClamperMarker
class|class
name|ArrayBoundsClamperMarker
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|ArrayBoundsClamperMarker
name|ArrayBoundsClamperMarker
parameter_list|()
member_init_list|:
name|mNeedsClamp
argument_list|(
literal|false
argument_list|)
block|{    }
DECL|function|visitBinary
specifier|virtual
name|bool
name|visitBinary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBinary
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpIndexIndirect
condition|)
block|{
name|TIntermTyped
modifier|*
name|left
init|=
name|node
operator|->
name|getLeft
argument_list|()
decl_stmt|;
if|if
condition|(
name|left
operator|->
name|isArray
argument_list|()
operator|||
name|left
operator|->
name|isVector
argument_list|()
operator|||
name|left
operator|->
name|isMatrix
argument_list|()
condition|)
block|{
name|node
operator|->
name|setAddIndexClamp
argument_list|()
expr_stmt|;
name|mNeedsClamp
operator|=
literal|true
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
DECL|function|GetNeedsClamp
name|bool
name|GetNeedsClamp
parameter_list|()
block|{
return|return
name|mNeedsClamp
return|;
block|}
private|private:
DECL|member|mNeedsClamp
name|bool
name|mNeedsClamp
decl_stmt|;
block|}
class|;
block|}
end_namespace
begin_comment
comment|// anonymous namespace
end_comment
begin_constructor
DECL|function|ArrayBoundsClamper
name|ArrayBoundsClamper
operator|::
name|ArrayBoundsClamper
parameter_list|()
member_init_list|:
name|mClampingStrategy
argument_list|(
name|SH_CLAMP_WITH_CLAMP_INTRINSIC
argument_list|)
member_init_list|,
name|mArrayBoundsClampDefinitionNeeded
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|SetClampingStrategy
name|void
name|ArrayBoundsClamper
operator|::
name|SetClampingStrategy
parameter_list|(
name|ShArrayIndexClampingStrategy
name|clampingStrategy
parameter_list|)
block|{
name|mClampingStrategy
operator|=
name|clampingStrategy
expr_stmt|;
block|}
end_function
begin_function
DECL|function|MarkIndirectArrayBoundsForClamping
name|void
name|ArrayBoundsClamper
operator|::
name|MarkIndirectArrayBoundsForClamping
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|root
argument_list|)
expr_stmt|;
name|ArrayBoundsClamperMarker
name|clamper
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|clamper
argument_list|)
expr_stmt|;
if|if
condition|(
name|clamper
operator|.
name|GetNeedsClamp
argument_list|()
condition|)
block|{
name|SetArrayBoundsClampDefinitionNeeded
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|OutputClampingFunctionDefinition
name|void
name|ArrayBoundsClamper
operator|::
name|OutputClampingFunctionDefinition
parameter_list|(
name|TInfoSinkBase
modifier|&
name|out
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|mArrayBoundsClampDefinitionNeeded
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|mClampingStrategy
operator|!=
name|SH_CLAMP_WITH_USER_DEFINED_INT_CLAMP_FUNCTION
condition|)
block|{
return|return;
block|}
name|out
operator|<<
name|kIntClampBegin
operator|<<
name|kIntClampDefinition
operator|<<
name|kIntClampEnd
expr_stmt|;
block|}
end_function
end_unit
