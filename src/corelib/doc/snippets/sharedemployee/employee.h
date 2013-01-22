begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EMPLOYEE_H
end_ifndef
begin_define
DECL|macro|EMPLOYEE_H
define|#
directive|define
name|EMPLOYEE_H
end_define
begin_comment
comment|//! [0]
end_comment
begin_include
include|#
directive|include
file|<QSharedData>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_decl_stmt
name|class
name|EmployeeData
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|EmployeeData
argument_list|()
operator|:
name|id
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
name|EmployeeData
argument_list|(
specifier|const
name|EmployeeData
operator|&
name|other
argument_list|)
operator|:
name|QSharedData
argument_list|(
name|other
argument_list|)
block|,
name|id
argument_list|(
name|other
operator|.
name|id
argument_list|)
block|,
name|name
argument_list|(
argument|other.name
argument_list|)
block|{ }
operator|~
name|EmployeeData
argument_list|()
block|{ }
name|int
name|id
block|;
name|QString
name|name
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Employee
block|{
name|public
label|:
comment|//! [1]
name|Employee
argument_list|()
block|{
name|d
operator|=
name|new
name|EmployeeData
expr_stmt|;
block|}
comment|//! [1] //! [2]
name|Employee
argument_list|(
argument|int id
argument_list|,
argument|QString name
argument_list|)
block|{
name|d
operator|=
name|new
name|EmployeeData
expr_stmt|;
name|setId
argument_list|(
name|id
argument_list|)
expr_stmt|;
name|setName
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
comment|//! [2] //! [7]
name|Employee
argument_list|(
specifier|const
name|Employee
operator|&
name|other
argument_list|)
operator|:
name|d
argument_list|(
argument|other.d
argument_list|)
block|{      }
comment|//! [7]
comment|//! [3]
name|void
name|setId
argument_list|(
argument|int id
argument_list|)
block|{
name|d
operator|->
name|id
operator|=
name|id
block|; }
comment|//! [3] //! [4]
name|void
name|setName
argument_list|(
argument|QString name
argument_list|)
block|{
name|d
operator|->
name|name
operator|=
name|name
block|; }
comment|//! [4]
comment|//! [5]
name|int
name|id
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|id
return|;
block|}
comment|//! [5] //! [6]
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|name
return|;
block|}
comment|//! [6]
name|private
label|:
name|QSharedDataPointer
operator|<
name|EmployeeData
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
