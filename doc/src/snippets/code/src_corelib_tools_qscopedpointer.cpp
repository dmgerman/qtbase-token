begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|myFunction
name|void
name|myFunction
parameter_list|(
name|bool
name|useSubClass
parameter_list|)
block|{
name|MyClass
modifier|*
name|p
init|=
name|useSubClass
condition|?
operator|new
name|MyClass
argument_list|()
else|:
operator|new
name|MySubClass
decl_stmt|;
name|QIODevice
modifier|*
name|device
init|=
name|handsOverOwnership
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_value
operator|>
literal|3
condition|)
block|{
operator|delete
name|p
expr_stmt|;
operator|delete
name|device
expr_stmt|;
return|return;
block|}
try|try
block|{
name|process
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
catch|catch
parameter_list|(
modifier|...
parameter_list|)
block|{
operator|delete
name|p
expr_stmt|;
operator|delete
name|device
expr_stmt|;
throw|throw;
block|}
operator|delete
name|p
expr_stmt|;
operator|delete
name|device
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|myFunction
name|void
name|myFunction
parameter_list|(
name|bool
name|useSubClass
parameter_list|)
block|{
comment|// assuming that MyClass has a virtual destructor
name|QScopedPointer
argument_list|<
name|MyClass
argument_list|>
name|p
argument_list|(
name|useSubClass
condition|?
operator|new
name|MyClass
argument_list|()
else|:
operator|new
name|MySubClass
argument_list|)
decl_stmt|;
name|QScopedPointer
argument_list|<
name|QIODevice
argument_list|>
name|device
argument_list|(
name|handsOverOwnership
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_value
operator|>
literal|3
condition|)
return|return;
name|process
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|p
specifier|const
name|QWidget
modifier|*
specifier|const
name|p
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// is equivalent to:
end_comment
begin_decl_stmt
specifier|const
name|QScopedPointer
argument_list|<
specifier|const
name|QWidget
argument_list|>
name|p
argument_list|(
operator|new
name|QWidget
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|p
name|QWidget
modifier|*
specifier|const
name|p
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// is equivalent to:
end_comment
begin_decl_stmt
specifier|const
name|QScopedPointer
argument_list|<
name|QWidget
argument_list|>
name|p
argument_list|(
operator|new
name|QWidget
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|p
specifier|const
name|QWidget
modifier|*
name|p
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// is equivalent to:
end_comment
begin_decl_stmt
name|QScopedPointer
argument_list|<
specifier|const
name|QWidget
argument_list|>
name|p
argument_list|(
operator|new
name|QWidget
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_if
if|if
condition|(
name|scopedPointer
condition|)
block|{
operator|...
block|}
end_if
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_class_decl
class_decl|class
name|MyPrivateClass
class_decl|;
end_class_decl
begin_comment
comment|// forward declare MyPrivateClass
end_comment
begin_class
DECL|class|MyClass
class|class
name|MyClass
block|{
private|private:
DECL|member|privatePtr
name|QScopedPointer
argument_list|<
name|MyPrivateClass
argument_list|>
name|privatePtr
decl_stmt|;
comment|// QScopedPointer to forward declared class
public|public:
name|MyClass
parameter_list|()
constructor_decl|;
comment|// OK
DECL|function|~MyClass
specifier|inline
name|~
name|MyClass
parameter_list|()
block|{}
comment|// VIOLATION - Destructor must not be inline
private|private:
name|Q_DISABLE_COPY
argument_list|(
argument|MyClass
argument_list|)
comment|// OK - copy constructor and assignment operators
comment|// are now disabled, so the compiler won't implicitely
comment|// generate them.
block|}
class|;
end_class
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|// this QScopedPointer deletes its data using the delete[] operator:
end_comment
begin_decl_stmt
name|QScopedPointer
argument_list|<
name|int
argument_list|,
name|QScopedPointerArrayDeleter
argument_list|<
name|int
argument_list|>
argument_list|>
name|arrayPointer
argument_list|(
operator|new
name|int
index|[
literal|42
index|]
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// this QScopedPointer frees its data using free():
end_comment
begin_decl_stmt
name|QScopedPointer
argument_list|<
name|int
argument_list|,
name|QScopedPointerPodDeleter
argument_list|>
name|podPointer
argument_list|(
cast|reinterpret_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
name|malloc
argument_list|(
literal|42
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// this struct calls "myCustomDeallocator" to delete the pointer
end_comment
begin_struct
DECL|struct|ScopedPointerCustomDeleter
struct|struct
name|ScopedPointerCustomDeleter
block|{
DECL|function|cleanup
specifier|static
specifier|inline
name|void
name|cleanup
parameter_list|(
name|MyCustomClass
modifier|*
name|pointer
parameter_list|)
block|{
name|myCustomDeallocator
argument_list|(
name|pointer
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_comment
comment|// QScopedPointer using a custom deleter:
end_comment
begin_decl_stmt
name|QScopedPointer
argument_list|<
name|MyCustomClass
argument_list|,
name|ScopedPointerCustomDeleter
argument_list|>
name|customPointer
argument_list|(
operator|new
name|MyCustomClass
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [5]
end_comment
end_unit
