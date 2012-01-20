begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QFont>
end_include
begin_include
include|#
directive|include
file|<QBrush>
end_include
begin_include
include|#
directive|include
file|"mymodel.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_constructor
DECL|function|MyModel
name|MyModel
operator|::
name|MyModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTableModel
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|rowCount
name|int
name|MyModel
operator|::
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
comment|/*parent */
parameter_list|)
specifier|const
block|{
return|return
literal|2
return|;
block|}
end_function
begin_function
DECL|function|columnCount
name|int
name|MyModel
operator|::
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
comment|/*parent */
parameter_list|)
specifier|const
block|{
return|return
literal|3
return|;
block|}
end_function
begin_comment
comment|//! [Quoting ModelView Tutorial]
end_comment
begin_comment
comment|// mymodel.cpp
end_comment
begin_function
DECL|function|data
name|QVariant
name|MyModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
name|int
name|row
init|=
name|index
operator|.
name|row
argument_list|()
decl_stmt|;
name|int
name|col
init|=
name|index
operator|.
name|column
argument_list|()
decl_stmt|;
comment|// generate a log message when this method gets called
name|qDebug
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"row %1, col%2, role %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|row
argument_list|)
operator|.
name|arg
argument_list|(
name|col
argument_list|)
operator|.
name|arg
argument_list|(
name|role
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|role
condition|)
block|{
case|case
name|Qt
operator|::
name|DisplayRole
case|:
if|if
condition|(
name|row
operator|==
literal|0
operator|&&
name|col
operator|==
literal|1
condition|)
return|return
name|QString
argument_list|(
literal|"<--left"
argument_list|)
return|;
if|if
condition|(
name|row
operator|==
literal|1
operator|&&
name|col
operator|==
literal|1
condition|)
return|return
name|QString
argument_list|(
literal|"right-->"
argument_list|)
return|;
return|return
name|QString
argument_list|(
literal|"Row%1, Column%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|row
operator|+
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|col
operator|+
literal|1
argument_list|)
return|;
break|break;
case|case
name|Qt
operator|::
name|FontRole
case|:
if|if
condition|(
name|row
operator|==
literal|0
operator|&&
name|col
operator|==
literal|0
condition|)
comment|//change font only for cell(0,0)
block|{
name|QFont
name|boldFont
decl_stmt|;
name|boldFont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
name|boldFont
return|;
block|}
break|break;
case|case
name|Qt
operator|::
name|BackgroundRole
case|:
if|if
condition|(
name|row
operator|==
literal|1
operator|&&
name|col
operator|==
literal|2
condition|)
comment|//change background only for cell(1,2)
block|{
name|QBrush
name|redBackground
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
decl_stmt|;
return|return
name|redBackground
return|;
block|}
break|break;
case|case
name|Qt
operator|::
name|TextAlignmentRole
case|:
if|if
condition|(
name|row
operator|==
literal|1
operator|&&
name|col
operator|==
literal|1
condition|)
comment|//change text alignment only for cell(1,1)
block|{
return|return
name|Qt
operator|::
name|AlignRight
operator|+
name|Qt
operator|::
name|AlignVCenter
return|;
block|}
break|break;
case|case
name|Qt
operator|::
name|CheckStateRole
case|:
if|if
condition|(
name|row
operator|==
literal|1
operator|&&
name|col
operator|==
literal|0
condition|)
comment|//add a checkbox to cell(1,0)
block|{
return|return
name|Qt
operator|::
name|Checked
return|;
block|}
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [Quoting ModelView Tutorial]
end_comment
end_unit
