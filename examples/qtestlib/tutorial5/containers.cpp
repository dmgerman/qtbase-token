begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// This file contains benchmarks for comparing QVector against std::vector
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
comment|// T is the item type
class|class
DECL|class|UseCases
name|UseCases
block|{
public|public:
DECL|function|~UseCases
specifier|virtual
name|~
name|UseCases
parameter_list|()
block|{}
comment|// Use case: Insert \a size items into the vector.
specifier|virtual
name|void
name|insert
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|=
literal|0
function_decl|;
comment|// Use case: Lookup \a size items from the vector.
specifier|virtual
name|void
name|lookup
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|=
literal|0
function_decl|;
block|}
class|;
end_class
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|f
name|T
modifier|*
name|f
parameter_list|(
name|T
modifier|*
name|ts
parameter_list|)
comment|// dummy function to prevent code from being optimized away by the compiler
block|{
return|return
name|ts
return|;
block|}
end_function
begin_comment
comment|// This subclass implements the use cases using QVector as efficiently as possible.
end_comment
begin_class
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
class|class
DECL|class|UseCases_QVector
name|UseCases_QVector
super|:
specifier|public
name|UseCases
argument_list|<
name|T
argument_list|>
block|{
DECL|function|insert
name|void
name|insert
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|QVector
argument_list|<
name|T
argument_list|>
name|v
decl_stmt|;
name|T
name|t
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|lookup
name|void
name|lookup
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|QVector
argument_list|<
name|T
argument_list|>
name|v
decl_stmt|;
name|T
name|t
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|T
modifier|*
name|ts
init|=
operator|new
name|T
index|[
name|size
index|]
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
name|ts
index|[
name|i
index|]
operator|=
name|v
operator|.
name|value
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|f
argument_list|<
name|T
argument_list|>
argument_list|(
name|ts
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|ts
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|// This subclass implements the use cases using std::vector as efficiently as possible.
end_comment
begin_class
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
class|class
DECL|class|UseCases_stdvector
name|UseCases_stdvector
super|:
specifier|public
name|UseCases
argument_list|<
name|T
argument_list|>
block|{
DECL|function|insert
name|void
name|insert
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|std
operator|::
name|vector
argument_list|<
name|T
argument_list|>
name|v
decl_stmt|;
name|T
name|t
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|push_back
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|lookup
name|void
name|lookup
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|std
operator|::
name|vector
argument_list|<
name|T
argument_list|>
name|v
decl_stmt|;
name|T
name|t
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
name|v
operator|.
name|push_back
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|T
modifier|*
name|ts
init|=
operator|new
name|T
index|[
name|size
index|]
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
name|ts
index|[
name|i
index|]
operator|=
name|v
index|[
name|i
index|]
expr_stmt|;
block|}
name|f
argument_list|<
name|T
argument_list|>
argument_list|(
name|ts
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|ts
expr_stmt|;
block|}
block|}
class|;
end_class
begin_struct
DECL|struct|Large
struct|struct
name|Large
block|{
comment|// A "large" item type
DECL|member|x
name|int
name|x
index|[
literal|1000
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|// Symbian devices typically have limited memory
end_comment
begin_define
DECL|macro|LARGE_MAX_SIZE
define|#
directive|define
name|LARGE_MAX_SIZE
value|20000
end_define
begin_class
DECL|class|tst_vector_vs_std
class|class
name|tst_vector_vs_std
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_vector_vs_std
name|tst_vector_vs_std
parameter_list|()
block|{
name|useCases_QVector_int
operator|=
operator|new
name|UseCases_QVector
argument_list|<
name|int
argument_list|>
expr_stmt|;
name|useCases_stdvector_int
operator|=
operator|new
name|UseCases_stdvector
argument_list|<
name|int
argument_list|>
expr_stmt|;
name|useCases_QVector_Large
operator|=
operator|new
name|UseCases_QVector
argument_list|<
name|Large
argument_list|>
expr_stmt|;
name|useCases_stdvector_Large
operator|=
operator|new
name|UseCases_stdvector
argument_list|<
name|Large
argument_list|>
expr_stmt|;
block|}
private|private:
DECL|member|useCases_QVector_int
name|UseCases
argument_list|<
name|int
argument_list|>
modifier|*
name|useCases_QVector_int
decl_stmt|;
DECL|member|useCases_stdvector_int
name|UseCases
argument_list|<
name|int
argument_list|>
modifier|*
name|useCases_stdvector_int
decl_stmt|;
DECL|member|useCases_QVector_Large
name|UseCases
argument_list|<
name|Large
argument_list|>
modifier|*
name|useCases_QVector_Large
decl_stmt|;
DECL|member|useCases_stdvector_Large
name|UseCases
argument_list|<
name|Large
argument_list|>
modifier|*
name|useCases_stdvector_Large
decl_stmt|;
private|private
name|slots
private|:
name|void
name|insert_int_data
parameter_list|()
function_decl|;
name|void
name|insert_int
parameter_list|()
function_decl|;
name|void
name|insert_Large_data
parameter_list|()
function_decl|;
name|void
name|insert_Large
parameter_list|()
function_decl|;
name|void
name|lookup_int_data
parameter_list|()
function_decl|;
name|void
name|lookup_int
parameter_list|()
function_decl|;
name|void
name|lookup_Large_data
parameter_list|()
function_decl|;
name|void
name|lookup_Large
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|insert_int_data
name|void
name|tst_vector_vs_std
operator|::
name|insert_int_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useStd"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|size
init|=
literal|10
init|;
name|size
operator|<
literal|20000
condition|;
name|size
operator|+=
literal|100
control|)
block|{
specifier|const
name|QByteArray
name|sizeString
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"std::vector-int--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|true
operator|<<
name|size
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"QVector-int--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|false
operator|<<
name|size
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|insert_int
name|void
name|tst_vector_vs_std
operator|::
name|insert_int
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useStd
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|useStd
condition|)
name|useCases_stdvector_int
operator|->
name|insert
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|else
name|useCases_QVector_int
operator|->
name|insert
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insert_Large_data
name|void
name|tst_vector_vs_std
operator|::
name|insert_Large_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useStd"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|size
init|=
literal|10
init|;
name|size
operator|<
name|LARGE_MAX_SIZE
condition|;
name|size
operator|+=
literal|100
control|)
block|{
specifier|const
name|QByteArray
name|sizeString
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"std::vector-Large--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|true
operator|<<
name|size
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"QVector-Large--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|false
operator|<<
name|size
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|insert_Large
name|void
name|tst_vector_vs_std
operator|::
name|insert_Large
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useStd
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|useStd
condition|)
name|useCases_stdvector_Large
operator|->
name|insert
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|else
name|useCases_QVector_Large
operator|->
name|insert
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|lookup_int_data
name|void
name|tst_vector_vs_std
operator|::
name|lookup_int_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useStd"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|size
init|=
literal|10
init|;
name|size
operator|<
literal|20000
condition|;
name|size
operator|+=
literal|100
control|)
block|{
specifier|const
name|QByteArray
name|sizeString
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"std::vector-int--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|true
operator|<<
name|size
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"QVector-int--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|false
operator|<<
name|size
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|lookup_int
name|void
name|tst_vector_vs_std
operator|::
name|lookup_int
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useStd
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|useStd
condition|)
name|useCases_stdvector_int
operator|->
name|lookup
argument_list|(
name|size
argument_list|)
expr_stmt|;
comment|// Create a std::vector and run the benchmark.
else|else
name|useCases_QVector_int
operator|->
name|lookup
argument_list|(
name|size
argument_list|)
expr_stmt|;
comment|// Create a QVector and run the benchmark.
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|lookup_Large_data
name|void
name|tst_vector_vs_std
operator|::
name|lookup_Large_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useStd"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|size
init|=
literal|10
init|;
name|size
operator|<
name|LARGE_MAX_SIZE
condition|;
name|size
operator|+=
literal|100
control|)
block|{
specifier|const
name|QByteArray
name|sizeString
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"std::vector-Large--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|true
operator|<<
name|size
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
operator|(
literal|"QVector-Large--"
operator|+
name|sizeString
operator|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
literal|false
operator|<<
name|size
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lookup_Large
name|void
name|tst_vector_vs_std
operator|::
name|lookup_Large
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useStd
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|useStd
condition|)
name|useCases_stdvector_Large
operator|->
name|lookup
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|else
name|useCases_QVector_Large
operator|->
name|lookup
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_vector_vs_std
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
