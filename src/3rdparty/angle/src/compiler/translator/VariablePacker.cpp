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
begin_include
include|#
directive|include
file|"compiler/translator/VariablePacker.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_function
DECL|function|GetNumComponentsPerRow
name|int
name|VariablePacker
operator|::
name|GetNumComponentsPerRow
parameter_list|(
name|sh
operator|::
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT4
case|:
case|case
name|GL_FLOAT_MAT2
case|:
case|case
name|GL_FLOAT_MAT2x4
case|:
case|case
name|GL_FLOAT_MAT3x4
case|:
case|case
name|GL_FLOAT_MAT4x2
case|:
case|case
name|GL_FLOAT_MAT4x3
case|:
case|case
name|GL_FLOAT_VEC4
case|:
case|case
name|GL_INT_VEC4
case|:
case|case
name|GL_BOOL_VEC4
case|:
case|case
name|GL_UNSIGNED_INT_VEC4
case|:
return|return
literal|4
return|;
case|case
name|GL_FLOAT_MAT3
case|:
case|case
name|GL_FLOAT_MAT2x3
case|:
case|case
name|GL_FLOAT_MAT3x2
case|:
case|case
name|GL_FLOAT_VEC3
case|:
case|case
name|GL_INT_VEC3
case|:
case|case
name|GL_BOOL_VEC3
case|:
case|case
name|GL_UNSIGNED_INT_VEC3
case|:
return|return
literal|3
return|;
case|case
name|GL_FLOAT_VEC2
case|:
case|case
name|GL_INT_VEC2
case|:
case|case
name|GL_BOOL_VEC2
case|:
case|case
name|GL_UNSIGNED_INT_VEC2
case|:
return|return
literal|2
return|;
default|default:
name|ASSERT
argument_list|(
name|gl
operator|::
name|VariableComponentCount
argument_list|(
name|type
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
end_function
begin_function
DECL|function|GetNumRows
name|int
name|VariablePacker
operator|::
name|GetNumRows
parameter_list|(
name|sh
operator|::
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT4
case|:
case|case
name|GL_FLOAT_MAT2x4
case|:
case|case
name|GL_FLOAT_MAT3x4
case|:
case|case
name|GL_FLOAT_MAT4x3
case|:
case|case
name|GL_FLOAT_MAT4x2
case|:
return|return
literal|4
return|;
case|case
name|GL_FLOAT_MAT3
case|:
case|case
name|GL_FLOAT_MAT2x3
case|:
case|case
name|GL_FLOAT_MAT3x2
case|:
return|return
literal|3
return|;
case|case
name|GL_FLOAT_MAT2
case|:
return|return
literal|2
return|;
default|default:
name|ASSERT
argument_list|(
name|gl
operator|::
name|VariableRowCount
argument_list|(
name|type
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
end_function
begin_struct
DECL|struct|TVariableInfoComparer
struct|struct
name|TVariableInfoComparer
block|{
DECL|function|operator ()
name|bool
name|operator
name|()
parameter_list|(
specifier|const
name|sh
operator|::
name|ShaderVariable
modifier|&
name|lhs
parameter_list|,
specifier|const
name|sh
operator|::
name|ShaderVariable
modifier|&
name|rhs
parameter_list|)
specifier|const
block|{
name|int
name|lhsSortOrder
init|=
name|gl
operator|::
name|VariableSortOrder
argument_list|(
name|lhs
operator|.
name|type
argument_list|)
decl_stmt|;
name|int
name|rhsSortOrder
init|=
name|gl
operator|::
name|VariableSortOrder
argument_list|(
name|rhs
operator|.
name|type
argument_list|)
decl_stmt|;
if|if
condition|(
name|lhsSortOrder
operator|!=
name|rhsSortOrder
condition|)
block|{
return|return
name|lhsSortOrder
operator|<
name|rhsSortOrder
return|;
block|}
comment|// Sort by largest first.
return|return
name|lhs
operator|.
name|arraySize
operator|>
name|rhs
operator|.
name|arraySize
return|;
block|}
block|}
struct|;
end_struct
begin_function
DECL|function|makeColumnFlags
name|unsigned
name|VariablePacker
operator|::
name|makeColumnFlags
parameter_list|(
name|int
name|column
parameter_list|,
name|int
name|numComponentsPerRow
parameter_list|)
block|{
return|return
operator|(
operator|(
name|kColumnMask
operator|<<
operator|(
name|kNumColumns
operator|-
name|numComponentsPerRow
operator|)
operator|)
operator|&
name|kColumnMask
operator|)
operator|>>
name|column
return|;
block|}
end_function
begin_function
DECL|function|fillColumns
name|void
name|VariablePacker
operator|::
name|fillColumns
parameter_list|(
name|int
name|topRow
parameter_list|,
name|int
name|numRows
parameter_list|,
name|int
name|column
parameter_list|,
name|int
name|numComponentsPerRow
parameter_list|)
block|{
name|unsigned
name|columnFlags
init|=
name|makeColumnFlags
argument_list|(
name|column
argument_list|,
name|numComponentsPerRow
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|r
init|=
literal|0
init|;
name|r
operator|<
name|numRows
condition|;
operator|++
name|r
control|)
block|{
name|int
name|row
init|=
name|topRow
operator|+
name|r
decl_stmt|;
name|ASSERT
argument_list|(
operator|(
name|rows_
index|[
name|row
index|]
operator|&
name|columnFlags
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|rows_
index|[
name|row
index|]
operator||=
name|columnFlags
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|searchColumn
name|bool
name|VariablePacker
operator|::
name|searchColumn
parameter_list|(
name|int
name|column
parameter_list|,
name|int
name|numRows
parameter_list|,
name|int
modifier|*
name|destRow
parameter_list|,
name|int
modifier|*
name|destSize
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|destRow
argument_list|)
expr_stmt|;
for|for
control|(
init|;
name|topNonFullRow_
operator|<
name|maxRows_
operator|&&
name|rows_
index|[
name|topNonFullRow_
index|]
operator|==
name|kColumnMask
condition|;
operator|++
name|topNonFullRow_
control|)
block|{     }
for|for
control|(
init|;
name|bottomNonFullRow_
operator|>=
literal|0
operator|&&
name|rows_
index|[
name|bottomNonFullRow_
index|]
operator|==
name|kColumnMask
condition|;
operator|--
name|bottomNonFullRow_
control|)
block|{     }
if|if
condition|(
name|bottomNonFullRow_
operator|-
name|topNonFullRow_
operator|+
literal|1
operator|<
name|numRows
condition|)
block|{
return|return
literal|false
return|;
block|}
name|unsigned
name|columnFlags
init|=
name|makeColumnFlags
argument_list|(
name|column
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|int
name|topGoodRow
init|=
literal|0
decl_stmt|;
name|int
name|smallestGoodTop
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|smallestGoodSize
init|=
name|maxRows_
operator|+
literal|1
decl_stmt|;
name|int
name|bottomRow
init|=
name|bottomNonFullRow_
operator|+
literal|1
decl_stmt|;
name|bool
name|found
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|row
init|=
name|topNonFullRow_
init|;
name|row
operator|<=
name|bottomRow
condition|;
operator|++
name|row
control|)
block|{
name|bool
name|rowEmpty
init|=
name|row
operator|<
name|bottomRow
condition|?
operator|(
operator|(
name|rows_
index|[
name|row
index|]
operator|&
name|columnFlags
operator|)
operator|==
literal|0
operator|)
else|:
literal|false
decl_stmt|;
if|if
condition|(
name|rowEmpty
condition|)
block|{
if|if
condition|(
operator|!
name|found
condition|)
block|{
name|topGoodRow
operator|=
name|row
expr_stmt|;
name|found
operator|=
literal|true
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|found
condition|)
block|{
name|int
name|size
init|=
name|row
operator|-
name|topGoodRow
decl_stmt|;
if|if
condition|(
name|size
operator|>=
name|numRows
operator|&&
name|size
operator|<
name|smallestGoodSize
condition|)
block|{
name|smallestGoodSize
operator|=
name|size
expr_stmt|;
name|smallestGoodTop
operator|=
name|topGoodRow
expr_stmt|;
block|}
block|}
name|found
operator|=
literal|false
expr_stmt|;
block|}
block|}
if|if
condition|(
name|smallestGoodTop
operator|<
literal|0
condition|)
block|{
return|return
literal|false
return|;
block|}
operator|*
name|destRow
operator|=
name|smallestGoodTop
expr_stmt|;
if|if
condition|(
name|destSize
condition|)
block|{
operator|*
name|destSize
operator|=
name|smallestGoodSize
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|VarT
parameter_list|>
DECL|function|CheckVariablesWithinPackingLimits
name|bool
name|VariablePacker
operator|::
name|CheckVariablesWithinPackingLimits
parameter_list|(
name|unsigned
name|int
name|maxVectors
parameter_list|,
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|VarT
argument_list|>
modifier|&
name|in_variables
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|maxVectors
operator|>
literal|0
argument_list|)
expr_stmt|;
name|maxRows_
operator|=
name|maxVectors
expr_stmt|;
name|topNonFullRow_
operator|=
literal|0
expr_stmt|;
name|bottomNonFullRow_
operator|=
name|maxRows_
operator|-
literal|1
expr_stmt|;
name|std
operator|::
name|vector
argument_list|<
name|VarT
argument_list|>
name|variables
argument_list|(
name|in_variables
argument_list|)
decl_stmt|;
comment|// Check whether each variable fits in the available vectors.
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|variables
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|sh
operator|::
name|ShaderVariable
modifier|&
name|variable
init|=
name|variables
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|variable
operator|.
name|elementCount
argument_list|()
operator|>
name|maxVectors
operator|/
name|GetNumRows
argument_list|(
name|variable
operator|.
name|type
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
block|}
comment|// As per GLSL 1.017 Appendix A, Section 7 variables are packed in specific
comment|// order by type, then by size of array, largest first.
name|std
operator|::
name|sort
argument_list|(
name|variables
operator|.
name|begin
argument_list|()
argument_list|,
name|variables
operator|.
name|end
argument_list|()
argument_list|,
name|TVariableInfoComparer
argument_list|()
argument_list|)
expr_stmt|;
name|rows_
operator|.
name|clear
argument_list|()
expr_stmt|;
name|rows_
operator|.
name|resize
argument_list|(
name|maxVectors
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Packs the 4 column variables.
name|size_t
name|ii
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|ii
operator|<
name|variables
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
specifier|const
name|sh
operator|::
name|ShaderVariable
modifier|&
name|variable
init|=
name|variables
index|[
name|ii
index|]
decl_stmt|;
if|if
condition|(
name|GetNumComponentsPerRow
argument_list|(
name|variable
operator|.
name|type
argument_list|)
operator|!=
literal|4
condition|)
block|{
break|break;
block|}
name|topNonFullRow_
operator|+=
name|GetNumRows
argument_list|(
name|variable
operator|.
name|type
argument_list|)
operator|*
name|variable
operator|.
name|elementCount
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|topNonFullRow_
operator|>
name|maxRows_
condition|)
block|{
return|return
literal|false
return|;
block|}
comment|// Packs the 3 column variables.
name|int
name|num3ColumnRows
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|ii
operator|<
name|variables
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
specifier|const
name|sh
operator|::
name|ShaderVariable
modifier|&
name|variable
init|=
name|variables
index|[
name|ii
index|]
decl_stmt|;
if|if
condition|(
name|GetNumComponentsPerRow
argument_list|(
name|variable
operator|.
name|type
argument_list|)
operator|!=
literal|3
condition|)
block|{
break|break;
block|}
name|num3ColumnRows
operator|+=
name|GetNumRows
argument_list|(
name|variable
operator|.
name|type
argument_list|)
operator|*
name|variable
operator|.
name|elementCount
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|topNonFullRow_
operator|+
name|num3ColumnRows
operator|>
name|maxRows_
condition|)
block|{
return|return
literal|false
return|;
block|}
name|fillColumns
argument_list|(
name|topNonFullRow_
argument_list|,
name|num3ColumnRows
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// Packs the 2 column variables.
name|int
name|top2ColumnRow
init|=
name|topNonFullRow_
operator|+
name|num3ColumnRows
decl_stmt|;
name|int
name|twoColumnRowsAvailable
init|=
name|maxRows_
operator|-
name|top2ColumnRow
decl_stmt|;
name|int
name|rowsAvailableInColumns01
init|=
name|twoColumnRowsAvailable
decl_stmt|;
name|int
name|rowsAvailableInColumns23
init|=
name|twoColumnRowsAvailable
decl_stmt|;
for|for
control|(
init|;
name|ii
operator|<
name|variables
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
specifier|const
name|sh
operator|::
name|ShaderVariable
modifier|&
name|variable
init|=
name|variables
index|[
name|ii
index|]
decl_stmt|;
if|if
condition|(
name|GetNumComponentsPerRow
argument_list|(
name|variable
operator|.
name|type
argument_list|)
operator|!=
literal|2
condition|)
block|{
break|break;
block|}
name|int
name|numRows
init|=
name|GetNumRows
argument_list|(
name|variable
operator|.
name|type
argument_list|)
operator|*
name|variable
operator|.
name|elementCount
argument_list|()
decl_stmt|;
if|if
condition|(
name|numRows
operator|<=
name|rowsAvailableInColumns01
condition|)
block|{
name|rowsAvailableInColumns01
operator|-=
name|numRows
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|numRows
operator|<=
name|rowsAvailableInColumns23
condition|)
block|{
name|rowsAvailableInColumns23
operator|-=
name|numRows
expr_stmt|;
block|}
else|else
block|{
return|return
literal|false
return|;
block|}
block|}
name|int
name|numRowsUsedInColumns01
init|=
name|twoColumnRowsAvailable
operator|-
name|rowsAvailableInColumns01
decl_stmt|;
name|int
name|numRowsUsedInColumns23
init|=
name|twoColumnRowsAvailable
operator|-
name|rowsAvailableInColumns23
decl_stmt|;
name|fillColumns
argument_list|(
name|top2ColumnRow
argument_list|,
name|numRowsUsedInColumns01
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|fillColumns
argument_list|(
name|maxRows_
operator|-
name|numRowsUsedInColumns23
argument_list|,
name|numRowsUsedInColumns23
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Packs the 1 column variables.
for|for
control|(
init|;
name|ii
operator|<
name|variables
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
specifier|const
name|sh
operator|::
name|ShaderVariable
modifier|&
name|variable
init|=
name|variables
index|[
name|ii
index|]
decl_stmt|;
name|ASSERT
argument_list|(
literal|1
operator|==
name|GetNumComponentsPerRow
argument_list|(
name|variable
operator|.
name|type
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|numRows
init|=
name|GetNumRows
argument_list|(
name|variable
operator|.
name|type
argument_list|)
operator|*
name|variable
operator|.
name|elementCount
argument_list|()
decl_stmt|;
name|int
name|smallestColumn
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|smallestSize
init|=
name|maxRows_
operator|+
literal|1
decl_stmt|;
name|int
name|topRow
init|=
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|kNumColumns
condition|;
operator|++
name|column
control|)
block|{
name|int
name|row
init|=
literal|0
decl_stmt|;
name|int
name|size
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|searchColumn
argument_list|(
name|column
argument_list|,
name|numRows
argument_list|,
operator|&
name|row
argument_list|,
operator|&
name|size
argument_list|)
condition|)
block|{
if|if
condition|(
name|size
operator|<
name|smallestSize
condition|)
block|{
name|smallestSize
operator|=
name|size
expr_stmt|;
name|smallestColumn
operator|=
name|column
expr_stmt|;
name|topRow
operator|=
name|row
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|smallestColumn
operator|<
literal|0
condition|)
block|{
return|return
literal|false
return|;
block|}
name|fillColumns
argument_list|(
name|topRow
argument_list|,
name|numRows
argument_list|,
name|smallestColumn
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|variables
operator|.
name|size
argument_list|()
operator|==
name|ii
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|// Instantiate all possible variable packings
end_comment
begin_function_decl
specifier|template
name|bool
name|VariablePacker
operator|::
name|CheckVariablesWithinPackingLimits
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|ShaderVariable
argument_list|>
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|template
name|bool
name|VariablePacker
operator|::
name|CheckVariablesWithinPackingLimits
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Attribute
argument_list|>
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|template
name|bool
name|VariablePacker
operator|::
name|CheckVariablesWithinPackingLimits
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Uniform
argument_list|>
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|template
name|bool
name|VariablePacker
operator|::
name|CheckVariablesWithinPackingLimits
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Varying
argument_list|>
modifier|&
parameter_list|)
function_decl|;
end_function_decl
end_unit
